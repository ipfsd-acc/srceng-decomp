// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlsl_to_glsl/dx9asmtogl.cpp
// Functions: 36
// ============================================================

#include "utils\hlsl_to_glsl\dx9asmtogl.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: void PrintToBuf(char __near *,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void PrintToBuf(char *pOut, int nOutSize, const char *pFormat, ...)
{
  unsigned int v3; // kr00_4
  va_list params; // [esp+18h] [ebp+14h] BYREF

  va_start(params, pFormat);
  v3 = strlen(pOut);
  V_vsnprintf(pDest: &pOut[v3], maxLen: nOutSize - v3, pFormat, params);
}

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: int GetNumSwizzleComponents(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetNumSwizzleComponents(char *pParam)
{
  unsigned int v1; // eax
  unsigned int v2; // esi
  unsigned int v3; // eax
  unsigned int v4; // eax

  strrchr(string: (unsigned __int8 *)pParam, chr: 0x2Eu);
  v2 = v1;
  if ( v1 != 0
    && (strrchr(string: (unsigned __int8 *)pParam, chr: 0x29u), v3 < v2)
    && (strrchr(string: (unsigned __int8 *)pParam, chr: 0x5Du), v4 < v2) )
  {
    return strlen((const char *)(v2 + 1));
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100010A0
// Name: char GetSwizzleComponent(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetSwizzleComponent(char *pParam, int n)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax
  signed int v6; // eax

  strrchr(string: (unsigned __int8 *)pParam, chr: 0x2Eu);
  v3 = v2;
  if ( v2 == 0 )
    return g_szDefaultSwizzle[n];
  strrchr(string: (unsigned __int8 *)pParam, chr: 0x29u);
  if ( v4 >= v3 )
    return g_szDefaultSwizzle[n];
  strrchr(string: (unsigned __int8 *)pParam, chr: 0x5Du);
  if ( v5 >= v3 )
    return g_szDefaultSwizzle[n];
  v6 = strlen((const char *)(v3 + 1));
  if ( n >= v6 )
    return *(_BYTE *)(v6 + v3);
  else
    return *(_BYTE *)(v3 + 1 + n);
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: void ReplaceParamName(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReplaceParamName(char *pSrc, const char *pNewParamName, char *pOut, int nOutLen)
{
  const char *v4; // eax
  const char *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax

  V_strncpy(pDest: pOut, pSrc: pNewParamName, maxLen: nOutLen);
  strrchr(string: (unsigned __int8 *)pSrc, chr: 0x2Eu);
  v5 = v4;
  if ( v4 != nullptr )
  {
    strrchr(string: (unsigned __int8 *)pSrc, chr: 0x29u);
    if ( v6 < (unsigned int)v5 )
    {
      strrchr(string: (unsigned __int8 *)pSrc, chr: 0x5Du);
      if ( v7 < (unsigned int)v5 )
        V_strncat(pDest: pOut, pSrc: v5, destBufferSize: nOutLen, max_chars_to_copy: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: void GetParamNameWithoutSwizzle(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetParamNameWithoutSwizzle(char *pParam, char *pOut, int nOutLen)
{
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  signed int v7; // eax
  unsigned int v8; // edi

  strrchr(string: (unsigned __int8 *)pParam, chr: 0x2Eu);
  v4 = v3;
  if ( v3 != 0
    && (strrchr(string: (unsigned __int8 *)pParam, chr: 0x29u), v5 < v4)
    && (strrchr(string: (unsigned __int8 *)pParam, chr: 0x5Du), v6 < v4) )
  {
    v7 = v4 - (_DWORD)pParam;
    v8 = nOutLen - 1;
    if ( nOutLen - 1 >= v7 )
      v8 = v7;
    memcpy(dst: (unsigned __int8 *)pOut, src: (unsigned __int8 *)pParam, count: v8);
    pOut[v8] = 0;
  }
  else
  {
    V_strncpy(pDest: pOut, pSrc: pParam, maxLen: nOutLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: D3DToGL::D3DToGL(void)
// Source: json
//------------------------------------------------------------------------------
D3DToGL *__thiscall D3DToGL::D3DToGL(D3DToGL *this)
{
  this->m_bIncludeEndStatement = true;
  *(_WORD *)&this->m_bAddHexCodeComments = 0;
  this->m_bGeneratingDebugText = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: private: void D3DToGL::OpenIntrinsic(unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::OpenIntrinsic(D3DToGL *this, unsigned int inst, char *buff, int nBufLen)
{
  switch ( inst )
  {
    case 7u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "inversesqrt( ");
      break;
    case 8u:
    case 9u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "dot( ");
      break;
    case 0xAu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "min( ");
      break;
    case 0xBu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "max( ");
      break;
    case 0xCu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "lessThan( ");
      break;
    case 0xDu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "greaterThan( ");
      break;
    case 0xEu:
    case 0x4Eu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "exp( ");
      break;
    case 0xFu:
    case 0x4Fu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "log( ");
      break;
    case 0x10u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "lit( ");
      break;
    case 0x11u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "dst( ");
      break;
    case 0x12u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "mix( ");
      break;
    case 0x13u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "fract( ");
      break;
    case 0x14u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "m4x4");
      break;
    case 0x20u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "pow( ");
      break;
    case 0x21u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "cross( ");
      break;
    case 0x22u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "sign( ");
      break;
    case 0x23u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "abs( ");
      break;
    case 0x24u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "normalize( ");
      break;
    case 0x25u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "sincos( ");
      break;
    case 0x40u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texcoord");
      break;
    case 0x41u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "kill( ");
      break;
    case 0x42u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "TEX");
      break;
    case 0x51u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "DEF");
      break;
    case 0x57u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texdepth");
      break;
    case 0x58u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "CMP");
      break;
    case 0x5Du:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texldd");
      break;
    case 0x5Fu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texldl");
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100015D0
// Name: private: void D3DToGL::PrintOpcode(unsigned int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::PrintOpcode(D3DToGL *this, unsigned int inst, char *buff, int nBufLen)
{
  switch ( inst )
  {
    case 0u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "NOP");
      break;
    case 1u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "MOV");
      break;
    case 2u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "ADD");
      break;
    case 3u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "SUB");
      break;
    case 4u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "MAD");
      break;
    case 5u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "MUL");
      break;
    case 6u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "RCP");
      break;
    case 7u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "RSQ");
      break;
    case 8u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "DP3");
      break;
    case 9u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "DP4");
      break;
    case 0xAu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "MIN");
      break;
    case 0xBu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "MAX");
      break;
    case 0xCu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "SLT");
      break;
    case 0xDu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "SGE");
      break;
    case 0xEu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "EX2");
      break;
    case 0xFu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "LG2");
      break;
    case 0x10u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "LIT");
      break;
    case 0x11u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "DST");
      break;
    case 0x12u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "LRP");
      break;
    case 0x13u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "FRC");
      break;
    case 0x14u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "m4x4");
      break;
    case 0x1Fu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "DCL");
      break;
    case 0x20u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "POW");
      break;
    case 0x21u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "XPD");
      break;
    case 0x22u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "SGN");
      break;
    case 0x23u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "ABS");
      break;
    case 0x24u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "NRM");
      break;
    case 0x25u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "SCS");
      break;
    case 0x2Eu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "ARL");
      break;
    case 0x40u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texcoord");
      break;
    case 0x41u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "KIL");
      break;
    case 0x42u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "TEX");
      break;
    case 0x4Eu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "EXP");
      break;
    case 0x4Fu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "LOG");
      break;
    case 0x51u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "DEF");
      break;
    case 0x57u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texdepth");
      break;
    case 0x58u:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "CMP");
      break;
    case 0x5Du:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texldd");
      break;
    case 0x5Fu:
      V_snprintf(pDest: buff, maxLen: nBufLen, pFormat: "texldl");
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001AC0
// Name: private: void D3DToGL::PrintParameterToString(unsigned int,unsigned int,char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::PrintParameterToString(
        D3DToGL *this,
        unsigned int dwToken,
        unsigned int dwSourceOrDest,
        char *pRegisterName,
        unsigned int nBufLen,
        bool bForceScalarSource)
{
  unsigned int v7; // esi
  unsigned int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // esi
  char buff[32]; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned int dwSrcModifier; // [esp+2Ch] [ebp-Ch]
  D3DToGL *v17; // [esp+30h] [ebp-8h]
  bool bAllowSwizzle; // [esp+36h] [ebp-2h]
  bool bAllowWriteMask; // [esp+37h] [ebp-1h]
  unsigned int dwYSwizzle; // [esp+40h] [ebp+8h]
  unsigned int dwZSwizzle; // [esp+44h] [ebp+Ch]
  unsigned int dwWSwizzle; // [esp+4Ch] [ebp+14h]

  v17 = this;
  bAllowWriteMask = true;
  bAllowSwizzle = true;
  v7 = dwToken & 0x7FF;
  dwSrcModifier = 0;
  V_snprintf(pDest: pRegisterName, maxLen: nBufLen, pFormat: str);
  if ( dwSourceOrDest != 0 )
  {
    if ( dwSourceOrDest == 1 )
    {
      v8 = dwToken & 0xF000000;
      dwSrcModifier = dwToken & 0xF000000;
      if ( (dwToken & 0xF000000) != 0 )
      {
        if ( v8 > 0x8000000 )
        {
          switch ( v8 )
          {
            case 0xB000000u:
              if ( v17->m_bGLSL )
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "abs(");
              break;
            case 0xC000000u:
              if ( v17->m_bGLSL )
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "-abs(");
              break;
            case 0xD000000u:
              strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "!");
              break;
            default:
              break;
          }
          goto LABEL_26;
        }
        if ( v8 == 0x8000000 )
          goto LABEL_15;
        if ( v8 > 0x5000000 )
        {
          if ( v8 == 100663296 )
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "1-");
          goto LABEL_26;
        }
        if ( v8 == 83886080 || v8 == 0x1000000 || v8 == 50331648 )
LABEL_15:
          strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "-");
      }
    }
  }
  else
  {
    if ( (dwToken & 0x100000) != 0 && !v17->m_bGLSL )
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "_SAT");
    if ( !v17->m_bGLSL )
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: " ");
  }
LABEL_26:
  switch ( (dwToken & 0x1800 | (dwToken >> 20) & 0x700) >> 8 )
  {
    case 0u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "r%d", v7);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      v17->m_dwTempUsageMask |= 1 << dwToken;
      goto LABEL_88;
    case 1u:
      if ( v17->m_bVertexShader || dwSourceOrDest == 1 || v17->m_bGLSL )
      {
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "v%d", v7);
        goto LABEL_87;
      }
      v9 = "v0 = fragment.color";
      if ( (dwToken & 0x7FF) != 0 )
        v9 = "v1 = fragment.color.secondary";
      V_snprintf(pDest: buff, maxLen: 32, pFormat: v9);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      bAllowWriteMask = false;
      goto LABEL_88;
    case 2u:
      if ( v17->m_bConstantRegisterDefined[v7] )
      {
        if ( v17->m_bGLSL )
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "c%d", v7);
        else
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "d%d", v7);
        goto LABEL_39;
      }
      if ( (dwToken & 0x2000) != 0 )
      {
        ++v17->m_pdwNextToken;
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "c[a0.x + %d]", v7);
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
        v17->m_bConstantRegisterReferenced[v7] = true;
        bAllowSwizzle = false;
      }
      else
      {
        if ( v17->m_bGLSL )
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "%s_c%d", v17->m_pVSPSConstantPrefix, v7);
        else
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "c[%d]", v7);
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
        v17->m_bConstantRegisterReferenced[v7] = true;
      }
      goto LABEL_88;
    case 3u:
      if ( v17->m_bVertexShader )
      {
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "a%d.x", v7);
        bAllowSwizzle = false;
        bAllowWriteMask = false;
LABEL_39:
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
        goto LABEL_88;
      }
      if ( dwSourceOrDest != 0 )
      {
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "t%d", v7);
        goto LABEL_39;
      }
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "t%d = fragment.texcoord[%d]", v7, v7);
      bAllowWriteMask = false;
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
LABEL_88:
      if ( dwSourceOrDest == 0 )
      {
        if ( bAllowWriteMask && (dwToken & 0xF0000) != 0xF0000 )
        {
          strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: ".");
          if ( (dwToken & 0x10000) != 0 )
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "x");
          if ( (dwToken & 0x20000) != 0 )
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "y");
          if ( (dwToken & 0x40000) != 0 )
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "z");
          if ( (dwToken & 0x80000) != 0 )
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "w");
        }
        return;
      }
      if ( bAllowSwizzle )
      {
        v12 = dwToken & 0xFF0000;
        if ( (dwToken & 0xFF0000) == 0xE40000 )
        {
          if ( bForceScalarSource )
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: ".x");
        }
        else
        {
          dwYSwizzle = dwToken & 0xC0000;
          v13 = v12 & 0x30000;
          dwZSwizzle = v12 & 0x300000;
          dwWSwizzle = v12 & 0xC00000;
          strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: ".");
          if ( v13 > 0x20000 )
          {
            if ( v13 == 196608 )
              strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "w");
          }
          else if ( v13 == 0x20000 )
          {
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "z");
          }
          else if ( v13 != 0 )
          {
            if ( v13 == 0x10000 )
              strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "y");
          }
          else
          {
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "x");
          }
          if ( !bForceScalarSource )
          {
            v14 = HIWORD(v13);
            if ( v14 != dwYSwizzle >> 18 || v14 != dwZSwizzle >> 20 || v14 != dwWSwizzle >> 22 )
            {
              if ( dwYSwizzle > 0x80000 )
              {
                if ( dwYSwizzle == 786432 )
                  strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "w");
              }
              else if ( dwYSwizzle == 0x80000 )
              {
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "z");
              }
              else if ( dwYSwizzle != 0 )
              {
                if ( dwYSwizzle == 0x40000 )
                  strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "y");
              }
              else
              {
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "x");
              }
              if ( dwZSwizzle > 0x200000 )
              {
                if ( dwZSwizzle == 3145728 )
                  strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "w");
              }
              else if ( dwZSwizzle == 0x200000 )
              {
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "z");
              }
              else if ( dwZSwizzle != 0 )
              {
                if ( dwZSwizzle == 0x100000 )
                  strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "y");
              }
              else
              {
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "x");
              }
              if ( dwWSwizzle > 0x800000 )
              {
                if ( dwWSwizzle == 12582912 )
                  strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "w");
              }
              else if ( dwWSwizzle == 0x800000 )
              {
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "z");
              }
              else if ( dwWSwizzle != 0 )
              {
                if ( dwWSwizzle == 0x400000 )
                  strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "y");
              }
              else
              {
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "x");
              }
            }
          }
        }
      }
      if ( dwSrcModifier == 0 )
        return;
      if ( dwSrcModifier <= 0x8000000 )
      {
        if ( dwSrcModifier != 0x8000000 )
        {
          if ( dwSrcModifier <= 0x4000000 )
          {
            if ( dwSrcModifier != 0x4000000 )
            {
              if ( dwSrcModifier == 0x2000000 || dwSrcModifier == 50331648 )
                strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "_bx2");
              return;
            }
LABEL_154:
            strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "_sgn");
            return;
          }
          if ( dwSrcModifier == 83886080 )
            goto LABEL_154;
          if ( dwSrcModifier != 117440512 )
            return;
        }
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "_x2");
        return;
      }
      if ( dwSrcModifier > 0xB000000 )
      {
        if ( dwSrcModifier != 201326592 )
          return;
      }
      else if ( dwSrcModifier != 184549376 )
      {
        if ( dwSrcModifier == 150994944 )
        {
          strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "_dz");
        }
        else if ( dwSrcModifier == 167772160 )
        {
          strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: "_dw");
        }
        return;
      }
      if ( v17->m_bGLSL )
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: ")");
      return;
    case 4u:
      v10 = "gl_Position";
      if ( !v17->m_bGLSL )
        v10 = "oPos";
      V_snprintf(pDest: buff, maxLen: 32, pFormat: v10, v7);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      v17->m_bDeclareVSOPos = true;
      goto LABEL_88;
    case 5u:
      if ( v17->m_bGLSL )
      {
        if ( (dwToken & 0x7FF) != 0 )
        {
          if ( v7 == 1 )
            V_snprintf(pDest: buff, maxLen: 32, pFormat: "gl_BackColor");
          else
            _Error(a1: "Invalid D3DSPR_ATTROUT index");
        }
        else
        {
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "gl_FrontColor", 0);
        }
      }
      else
      {
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "oD%d", v7);
      }
      goto LABEL_73;
    case 6u:
      if ( v17->m_bVertexShader )
      {
        if ( v17->m_bGLSL )
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "o%d", v7);
        else
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "oT%d", v7);
        v17->m_dwTexCoordOutMask |= 1 << dwToken;
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      }
      else
      {
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "oC%d", v7);
        strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      }
      goto LABEL_88;
    case 7u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "xxx%d", v7);
      goto LABEL_87;
    case 8u:
      if ( v17->m_bGLSL )
      {
        if ( (dwToken & 0x7FF) != 0 )
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "gl_FragColor[%d]", v7);
        else
          V_snprintf(pDest: buff, maxLen: 32, pFormat: "gl_FragColor");
      }
      else
      {
        V_snprintf(pDest: buff, maxLen: 32, pFormat: "oC%d", v7);
      }
LABEL_73:
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      v17->m_bOutputColorRegister[v7] = true;
      goto LABEL_88;
    case 9u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "oDepth");
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      v17->m_bOutputDepthRegister = true;
      goto LABEL_88;
    case 0xAu:
      v11 = "sampler%d";
      if ( !v17->m_bGLSL )
        v11 = "texture[%d]";
      V_snprintf(pDest: buff, maxLen: 32, pFormat: v11, v7);
      goto LABEL_87;
    case 0xBu:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "c%d", v7 + 2048);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    case 0xCu:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "c%d", v7 + 4096);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    case 0xDu:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "c%d", v7 + 6144);
      goto LABEL_87;
    case 0xEu:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "b%d", v7);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    case 0xFu:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "aL%d", v7);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    case 0x10u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "temp_float16_xxx%d", v7);
      goto LABEL_87;
    case 0x11u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "misc%d", v7);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    case 0x12u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "label%d", v7);
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    case 0x13u:
      V_snprintf(pDest: buff, maxLen: 32, pFormat: "p%d", v7);
LABEL_87:
      strcat_s(_Dst: pRegisterName, _SizeInBytes: nBufLen, _Src: buff);
      goto LABEL_88;
    default:
      goto LABEL_88;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002420
// Name: private: void D3DToGL::AddTokenHexCodeToBuffer(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::AddTokenHexCodeToBuffer(D3DToGL *this, char *pBuffer, int nSize, int nLastStrlen)
{
  unsigned int v5; // ebx
  int v6; // edi
  int i; // esi
  unsigned int v8; // kr00_4
  char szHex[512]; // [esp+8h] [ebp-224h] BYREF
  char szTemp[32]; // [esp+208h] [ebp-24h] BYREF
  D3DToGL *v11; // [esp+228h] [ebp-4h]

  v11 = this;
  v5 = strlen(pBuffer);
  if ( v5 != nLastStrlen )
  {
    szHex[0] = 10;
    V_snprintf(pDest: &szHex[1], maxLen: 511, pFormat: "// Hex: ");
    v6 = this->m_pdwNextToken - this->m_pRecordedInputTokenStart;
    if ( v6 > 10 )
      v6 = 10;
    for ( i = 0; i < v6; ++i )
    {
      V_snprintf(pDest: szTemp, maxLen: 32, pFormat: "0x%x ", v11->m_pRecordedInputTokenStart[i]);
      V_strncat(pDest: szHex, pSrc: szTemp, destBufferSize: 0x200u, max_chars_to_copy: -1);
    }
    V_strncat(pDest: szHex, pSrc: "\n", destBufferSize: 0x200u, max_chars_to_copy: -1);
    v8 = strlen(szHex);
    if ( (int)(v8 + v5 + 1) >= nSize )
      _Error(a1: "Buffer overflow writing token hex codes");
    if ( v11->m_bPutHexCodesAfterLines )
    {
      if ( pBuffer[v5 - 1] == 10 )
        pBuffer[v5 - 1] = 0;
      V_strncat(pDest: pBuffer, pSrc: &szHex[1], destBufferSize: nSize, max_chars_to_copy: -1);
    }
    else
    {
      memmove(
        dst: (unsigned __int8 *)&pBuffer[v8 + nLastStrlen],
        src: (unsigned __int8 *)&pBuffer[nLastStrlen],
        count: v5 - nLastStrlen + 1);
      memcpy(dst: (unsigned __int8 *)&pBuffer[nLastStrlen], src: (unsigned __int8 *)szHex, count: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002580
// Name: void PrintToBuf(class CUtlBuffer __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void PrintToBuf(CUtlBuffer *buf, const char *pFormat, ...)
{
  char szTemp[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+410h] [ebp+10h] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest: szTemp, maxLen: 1024, pFormat, params);
  strcat_s(_Dst: (char *)buf->m_Memory.m_pMemory, _SizeInBytes: buf->m_Memory.m_nAllocationCount, _Src: szTemp);
}

//------------------------------------------------------------------------------
// Address: 0x100025C0
// Name: private: void D3DToGL::Handle_SINCOS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_SINCOS(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ecx
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  CUtlBuffer *m_pBufALUCode; // eax
  unsigned int m_nAllocationCount; // edi
  char *m_pMemory; // esi
  char pDestReg[16]; // [esp+8h] [ebp-20h] BYREF
  char pSrc0Reg[16]; // [esp+18h] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  this->m_bNeedsSinCosDeclarations = true;
  v3 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v3,
    dwSourceOrDest: 0,
    pRegisterName: pDestReg,
    nBufLen: 0x10u,
    bForceScalarSource: false);
  v4 = this->m_pdwNextToken;
  v5 = *v4;
  this->m_pdwNextToken = v4 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v5,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc0Reg,
    nBufLen: 0x10u,
    bForceScalarSource: true);
  m_pBufALUCode = this->m_pBufALUCode;
  this->m_pdwNextToken += 2;
  m_nAllocationCount = m_pBufALUCode->m_Memory.m_nAllocationCount;
  m_pMemory = (char *)m_pBufALUCode->m_Memory.m_pMemory;
  strcat_s(_Dst: (char *)m_pBufALUCode->m_Memory.m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MUL SC_TEMP.z, ");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc0Reg);
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", ");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc0Reg);
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ";\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MAD SC_TEMP.xy, SC_TEMP.z, scA, scA.wzyx;\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MAD SC_TEMP.xy, SC_TEMP,   SC_TEMP.z, scB;\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MAD SC_TEMP.xy, SC_TEMP,   SC_TEMP.z, scB.wzyx;\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MUL SC_TEMP.x,  SC_TEMP.x, ");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc0Reg);
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ";\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MUL SC_TEMP.xy, SC_TEMP,   SC_TEMP.x;\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "ADD SC_TEMP.xy, SC_TEMP,   SC_TEMP;\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "ADD SC_TEMP.x, -SC_TEMP.x, scB.z;\n");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MOV");
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pDestReg);
  strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", SC_TEMP;\n");
}

//------------------------------------------------------------------------------
// Address: 0x100026F0
// Name: private: void D3DToGL::Handle_LRP(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_LRP(D3DToGL *this, unsigned int nInstruction)
{
  CUtlBuffer *m_pBufALUCode; // eax
  unsigned int m_nAllocationCount; // ebx
  char *m_pMemory; // edi
  unsigned int *v6; // eax
  unsigned int v7; // ecx
  unsigned int *v8; // eax
  unsigned int v9; // ecx
  unsigned int *v10; // eax
  unsigned int v11; // ecx
  unsigned int *v12; // eax
  unsigned int v13; // ecx
  unsigned int *m_pdwNextToken; // eax
  unsigned int v15; // ecx
  unsigned int *v16; // eax
  unsigned int v17; // ecx
  unsigned int *v18; // eax
  unsigned int v19; // ecx
  unsigned int *v20; // eax
  unsigned int v21; // ecx
  char buff[256]; // [esp+Ch] [ebp-140h] BYREF
  char pSrc1Reg[16]; // [esp+10Ch] [ebp-40h] BYREF
  char pSrc0Reg[16]; // [esp+11Ch] [ebp-30h] BYREF
  char pDestReg[16]; // [esp+12Ch] [ebp-20h] BYREF
  char pSrc2Reg[16]; // [esp+13Ch] [ebp-10h] BYREF

  m_pBufALUCode = this->m_pBufALUCode;
  m_nAllocationCount = m_pBufALUCode->m_Memory.m_nAllocationCount;
  m_pMemory = (char *)m_pBufALUCode->m_Memory.m_pMemory;
  if ( this->m_bVertexShader )
  {
    m_pdwNextToken = this->m_pdwNextToken;
    this->m_bNeedsLerpTemp = true;
    v15 = *m_pdwNextToken;
    this->m_pdwNextToken = m_pdwNextToken + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v15,
      dwSourceOrDest: 0,
      pRegisterName: pDestReg,
      nBufLen: 0x10u,
      bForceScalarSource: false);
    v16 = this->m_pdwNextToken;
    v17 = *v16;
    this->m_pdwNextToken = v16 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v17,
      dwSourceOrDest: 1u,
      pRegisterName: pSrc0Reg,
      nBufLen: 0x10u,
      bForceScalarSource: false);
    v18 = this->m_pdwNextToken;
    v19 = *v18;
    this->m_pdwNextToken = v18 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v19,
      dwSourceOrDest: 1u,
      pRegisterName: pSrc1Reg,
      nBufLen: 0x10u,
      bForceScalarSource: false);
    v20 = this->m_pdwNextToken;
    v21 = *v20;
    this->m_pdwNextToken = v20 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v21,
      dwSourceOrDest: 1u,
      pRegisterName: pSrc2Reg,
      nBufLen: 0x10u,
      bForceScalarSource: false);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "SUB LRP_TEMP, ");
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc1Reg);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", ");
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc2Reg);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ";\n");
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "MAD");
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pDestReg);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", ");
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc0Reg);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", LRP_TEMP, ");
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: pSrc2Reg);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ";\n");
  }
  else
  {
    D3DToGL::PrintOpcode(this, inst: nInstruction, buff, nBufLen: 256);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: buff);
    v6 = this->m_pdwNextToken;
    v7 = *v6;
    this->m_pdwNextToken = v6 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v7,
      dwSourceOrDest: 0,
      pRegisterName: buff,
      nBufLen: 0x100u,
      bForceScalarSource: false);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: buff);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", ");
    v8 = this->m_pdwNextToken;
    v9 = *v8;
    this->m_pdwNextToken = v8 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v9,
      dwSourceOrDest: 1u,
      pRegisterName: buff,
      nBufLen: 0x100u,
      bForceScalarSource: false);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: buff);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", ");
    v10 = this->m_pdwNextToken;
    v11 = *v10;
    this->m_pdwNextToken = v10 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v11,
      dwSourceOrDest: 1u,
      pRegisterName: buff,
      nBufLen: 0x100u,
      bForceScalarSource: false);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: buff);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ", ");
    v12 = this->m_pdwNextToken;
    v13 = *v12;
    this->m_pdwNextToken = v12 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v13,
      dwSourceOrDest: 1u,
      pRegisterName: buff,
      nBufLen: 0x100u,
      bForceScalarSource: false);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: buff);
    strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: ";\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002960
// Name: private: void D3DToGL::Handle_TexLDD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_TexLDD(D3DToGL *this, unsigned int nInstruction)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // ecx
  unsigned int *v7; // eax
  unsigned int v8; // ecx
  unsigned int *v9; // eax
  unsigned int v10; // ecx
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  char buff[256]; // [esp+4h] [ebp-100h] BYREF

  D3DToGL::PrintOpcode(this, inst: nInstruction, buff, nBufLen: 256);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  m_pdwNextToken = this->m_pdwNextToken;
  v4 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v4,
    dwSourceOrDest: 0,
    pRegisterName: buff,
    nBufLen: 0x100u,
    bForceScalarSource: false);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: ", ");
  v5 = this->m_pdwNextToken;
  v6 = *v5;
  this->m_pdwNextToken = v5 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v6,
    dwSourceOrDest: 1u,
    pRegisterName: buff,
    nBufLen: 0x100u,
    bForceScalarSource: false);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: ", ");
  v7 = this->m_pdwNextToken;
  v8 = *v7;
  this->m_pdwNextToken = v7 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v8,
    dwSourceOrDest: 1u,
    pRegisterName: buff,
    nBufLen: 0x100u,
    bForceScalarSource: false);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: ", ");
  v9 = this->m_pdwNextToken;
  v10 = *v9;
  this->m_pdwNextToken = v9 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v10,
    dwSourceOrDest: 1u,
    pRegisterName: buff,
    nBufLen: 0x100u,
    bForceScalarSource: false);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: ", ");
  v11 = this->m_pdwNextToken;
  v12 = *v11;
  this->m_pdwNextToken = v11 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v12,
    dwSourceOrDest: 1u,
    pRegisterName: buff,
    nBufLen: 0x100u,
    bForceScalarSource: false);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: ";\n");
}

//------------------------------------------------------------------------------
// Address: 0x10002B60
// Name: private: void D3DToGL::Handle_TexCoord(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_TexCoord(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ecx
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  char buff[256]; // [esp+4h] [ebp-100h] BYREF

  if ( this->m_dwMajorVersion == 1 && this->m_dwMinorVersion == 4 && !this->m_bVertexShader )
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: "texcrd");
  else
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: "texcoord");
  m_pdwNextToken = this->m_pdwNextToken;
  v3 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v3,
    dwSourceOrDest: 0,
    pRegisterName: buff,
    nBufLen: 0x100u,
    bForceScalarSource: false);
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: buff);
  if ( this->m_dwMajorVersion == 1 && this->m_dwMinorVersion == 4 && !this->m_bVertexShader )
  {
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    v4 = this->m_pdwNextToken;
    v5 = *v4;
    this->m_pdwNextToken = v4 + 1;
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v5,
      dwSourceOrDest: 1u,
      pRegisterName: buff,
      nBufLen: 0x100u,
      bForceScalarSource: false);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: buff);
  }
  strcat_s(
    _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
    _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
    _Src: ";\n");
}

//------------------------------------------------------------------------------
// Address: 0x10002C70
// Name: private: void D3DToGL::WriteGLSLCmp(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::WriteGLSLCmp(D3DToGL *this, char *pDestReg, char *pSrc0Reg, char *pSrc1Reg, char *pSrc2Reg)
{
  int v5; // eax
  int i; // edi
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // eax
  signed int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  char *v16; // edx
  signed int v17; // eax
  char v18; // al
  unsigned int v19; // eax
  unsigned int v20; // esi
  unsigned int v21; // eax
  unsigned int v22; // eax
  signed int v23; // esi
  unsigned int v24; // eax
  unsigned int v25; // esi
  unsigned int v26; // eax
  unsigned int v27; // eax
  signed int v28; // eax
  char v29; // al
  unsigned int v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // eax
  unsigned int v33; // eax
  signed int v34; // esi
  unsigned int v35; // eax
  unsigned int v36; // esi
  unsigned int v37; // eax
  unsigned int v38; // eax
  signed int v39; // eax
  char v40; // al
  unsigned int v41; // eax
  unsigned int v42; // esi
  unsigned int v43; // eax
  unsigned int v44; // eax
  signed int v45; // esi
  unsigned int v46; // eax
  unsigned int v47; // esi
  unsigned int v48; // eax
  unsigned int v49; // eax
  signed int v50; // eax
  char v51; // al
  char params[4][256]; // [esp+0h] [ebp-408h] BYREF
  D3DToGL *v53; // [esp+400h] [ebp-8h]
  int nWriteMaskEntries; // [esp+404h] [ebp-4h]

  v53 = this;
  strchr(string: (unsigned __int8 *)pDestReg, chr: 0x2Eu);
  if ( v5 != 0 )
    nWriteMaskEntries = strlen((const char *)(v5 + 1));
  else
    nWriteMaskEntries = 4;
  for ( i = 0; i < nWriteMaskEntries; ++i )
  {
    strrchr(string: (unsigned __int8 *)pDestReg, chr: 0x2Eu);
    v8 = v7;
    if ( v7 != 0
      && (strrchr(string: (unsigned __int8 *)pDestReg, chr: 0x29u), v9 < v8)
      && (strrchr(string: (unsigned __int8 *)pDestReg, chr: 0x5Du), v10 < v8) )
    {
      v11 = v8 - (_DWORD)pDestReg;
      if ( v11 > 255 )
        v11 = 255;
      memcpy(dst: (unsigned __int8 *)params, src: (unsigned __int8 *)pDestReg, count: v11);
      params[0][v11] = 0;
    }
    else
    {
      V_strncpy(pDest: params[0], pSrc: pDestReg, maxLen: 256);
    }
    PrintToBuf(pOut: params[0], nOutSize: 256, pFormat: ".");
    strrchr(string: (unsigned __int8 *)pDestReg, chr: 0x2Eu);
    v13 = v12;
    if ( v12 != 0
      && (strrchr(string: (unsigned __int8 *)pDestReg, chr: 0x29u), v14 < v13)
      && (strrchr(string: (unsigned __int8 *)pDestReg, chr: 0x5Du), v15 < v13) )
    {
      v16 = (char *)(v13 + 1);
      v17 = strlen((const char *)(v13 + 1));
      if ( i >= v17 )
      {
        v18 = *(_BYTE *)(v17 + v13);
        goto LABEL_19;
      }
    }
    else
    {
      v16 = g_szDefaultSwizzle;
    }
    v18 = v16[i];
LABEL_19:
    PrintToBuf(pOut: params[0], nOutSize: 256, pFormat: "%c", v18);
    strrchr(string: (unsigned __int8 *)pSrc0Reg, chr: 0x2Eu);
    v20 = v19;
    if ( v19 != 0
      && (strrchr(string: (unsigned __int8 *)pSrc0Reg, chr: 0x29u), v21 < v20)
      && (strrchr(string: (unsigned __int8 *)pSrc0Reg, chr: 0x5Du), v22 < v20) )
    {
      v23 = v20 - (_DWORD)pSrc0Reg;
      if ( v23 > 255 )
        v23 = 255;
      memcpy(dst: (unsigned __int8 *)params[1], src: (unsigned __int8 *)pSrc0Reg, count: v23);
      params[1][v23] = 0;
    }
    else
    {
      V_strncpy(pDest: params[1], pSrc: pSrc0Reg, maxLen: 256);
    }
    PrintToBuf(pOut: params[1], nOutSize: 256, pFormat: ".");
    strrchr(string: (unsigned __int8 *)pSrc0Reg, chr: 0x2Eu);
    v25 = v24;
    if ( v24 != 0
      && (strrchr(string: (unsigned __int8 *)pSrc0Reg, chr: 0x29u), v26 < v25)
      && (strrchr(string: (unsigned __int8 *)pSrc0Reg, chr: 0x5Du), v27 < v25) )
    {
      v28 = strlen((const char *)(v25 + 1));
      if ( i >= v28 )
        v29 = *(_BYTE *)(v28 + v25);
      else
        v29 = *(_BYTE *)(v25 + 1 + i);
    }
    else
    {
      v29 = g_szDefaultSwizzle[i];
    }
    PrintToBuf(pOut: params[1], nOutSize: 256, pFormat: "%c", v29);
    strrchr(string: (unsigned __int8 *)pSrc1Reg, chr: 0x2Eu);
    v31 = v30;
    if ( v30 != 0
      && (strrchr(string: (unsigned __int8 *)pSrc1Reg, chr: 0x29u), v32 < v31)
      && (strrchr(string: (unsigned __int8 *)pSrc1Reg, chr: 0x5Du), v33 < v31) )
    {
      v34 = v31 - (_DWORD)pSrc1Reg;
      if ( v34 > 255 )
        v34 = 255;
      memcpy(dst: (unsigned __int8 *)params[2], src: (unsigned __int8 *)pSrc1Reg, count: v34);
      params[2][v34] = 0;
    }
    else
    {
      V_strncpy(pDest: params[2], pSrc: pSrc1Reg, maxLen: 256);
    }
    PrintToBuf(pOut: params[2], nOutSize: 256, pFormat: ".");
    strrchr(string: (unsigned __int8 *)pSrc1Reg, chr: 0x2Eu);
    v36 = v35;
    if ( v35 != 0
      && (strrchr(string: (unsigned __int8 *)pSrc1Reg, chr: 0x29u), v37 < v36)
      && (strrchr(string: (unsigned __int8 *)pSrc1Reg, chr: 0x5Du), v38 < v36) )
    {
      v39 = strlen((const char *)(v36 + 1));
      if ( i >= v39 )
        v40 = *(_BYTE *)(v39 + v36);
      else
        v40 = *(_BYTE *)(v36 + 1 + i);
    }
    else
    {
      v40 = g_szDefaultSwizzle[i];
    }
    PrintToBuf(pOut: params[2], nOutSize: 256, pFormat: "%c", v40);
    strrchr(string: (unsigned __int8 *)pSrc2Reg, chr: 0x2Eu);
    v42 = v41;
    if ( v41 != 0
      && (strrchr(string: (unsigned __int8 *)pSrc2Reg, chr: 0x29u), v43 < v42)
      && (strrchr(string: (unsigned __int8 *)pSrc2Reg, chr: 0x5Du), v44 < v42) )
    {
      v45 = v42 - (_DWORD)pSrc2Reg;
      if ( v45 > 255 )
        v45 = 255;
      memcpy(dst: (unsigned __int8 *)params[3], src: (unsigned __int8 *)pSrc2Reg, count: v45);
      params[3][v45] = 0;
    }
    else
    {
      V_strncpy(pDest: params[3], pSrc: pSrc2Reg, maxLen: 256);
    }
    PrintToBuf(pOut: params[3], nOutSize: 256, pFormat: ".");
    strrchr(string: (unsigned __int8 *)pSrc2Reg, chr: 0x2Eu);
    v47 = v46;
    if ( v46 != 0
      && (strrchr(string: (unsigned __int8 *)pSrc2Reg, chr: 0x29u), v48 < v47)
      && (strrchr(string: (unsigned __int8 *)pSrc2Reg, chr: 0x5Du), v49 < v47) )
    {
      v50 = strlen((const char *)(v47 + 1));
      if ( i >= v50 )
        v51 = *(_BYTE *)(v50 + v47);
      else
        v51 = *(_BYTE *)(v47 + 1 + i);
    }
    else
    {
      v51 = g_szDefaultSwizzle[i];
    }
    PrintToBuf(pOut: params[3], nOutSize: 256, pFormat: "%c", v51);
    PrintToBuf(
      buf: v53->m_pBufALUCode,
      pFormat: "%s = ( %s >= 0.0 ) ? %s : %s;\n",
      params[0],
      params[1],
      params[2],
      params[3]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003120
// Name: private: void D3DToGL::WriteGLSLSamplerDefinitions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::WriteGLSLSamplerDefinitions(D3DToGL *this)
{
  int v2; // ebx
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int *m_dwSamplerTypes; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v3 = 0;
  m_dwSamplerTypes = this->m_dwSamplerTypes;
  do
  {
    v4 = *m_dwSamplerTypes;
    if ( *m_dwSamplerTypes != 0 )
    {
      if ( v4 == 2 )
      {
        PrintToBuf(buf: this->m_pBufParamCode, pFormat: "uniform sampler3D sampler%d;\n", v3);
        ++v2;
      }
      else if ( v4 != 3 )
      {
        _Error(a1: "Unknown sampler type.");
      }
    }
    else
    {
      PrintToBuf(buf: this->m_pBufParamCode, pFormat: "uniform sampler2D sampler%d;\n", v3);
      ++v2;
    }
    ++m_dwSamplerTypes;
    ++v3;
  }
  while ( v3 < 0x20 );
  if ( v2 > 0 )
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x100031B0
// Name: private: void D3DToGL::Handle_DeclarativeNonDclOp(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_DeclarativeNonDclOp(D3DToGL *this, unsigned int nInstruction)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v4; // ecx
  char SwizzleComponent; // bl
  char v6; // al
  int v7; // ebx
  int i; // edi
  char szOpcode[128]; // [esp+4h] [ebp-184h] BYREF
  char _Src[128]; // [esp+84h] [ebp-104h] BYREF
  char buff[128]; // [esp+104h] [ebp-84h] BYREF
  char c[4]; // [esp+184h] [ebp-4h]

  m_pdwNextToken = this->m_pdwNextToken;
  v4 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v4,
    dwSourceOrDest: 0,
    pRegisterName: buff,
    nBufLen: 0x80u,
    bForceScalarSource: false);
  if ( this->m_bGLSL && nInstruction == 65 )
  {
    SwizzleComponent = GetSwizzleComponent(pParam: buff, n: 0);
    c[0] = SwizzleComponent;
    c[1] = GetSwizzleComponent(pParam: buff, n: 1);
    v6 = GetSwizzleComponent(pParam: buff, n: 2);
    LOBYTE(nInstruction) = SwizzleComponent;
    v7 = 1;
    if ( c[1] != c[0] )
    {
      BYTE1(nInstruction) = c[1];
      v7 = 2;
    }
    if ( v6 != c[1] && v6 != c[0] )
      *((_BYTE *)&nInstruction + v7++) = v6;
    GetParamNameWithoutSwizzle(pParam: buff, pOut: szOpcode, nOutLen: 256);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "if ( %s.%c < 0.0 ", szOpcode, (char)nInstruction);
    for ( i = 1; i < v7; ++i )
      PrintToBuf(buf: this->m_pBufALUCode, pFormat: "|| %s.%c < 0.0 ", szOpcode, *((char *)&nInstruction + i));
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: ")\n{\n\tdiscard;\n}\n");
  }
  else
  {
    D3DToGL::PrintOpcode(this, inst: nInstruction, buff: _Src, nBufLen: 128);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: buff);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ";\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003350
// Name: private: void D3DToGL::NoteTangentInputUsed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::NoteTangentInputUsed(D3DToGL *this)
{
  const char *v1; // [esp-4h] [ebp-4h]

  if ( !this->m_bTangentInputUsed )
  {
    v1 = g_pTangentAttributeName;
    this->m_bTangentInputUsed = true;
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "attribute vec4 %s;\n", v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003380
// Name: private: void D3DToGL::PrintUsageAndIndexToString(unsigned int,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::PrintUsageAndIndexToString(
        D3DToGL *this,
        unsigned int dwToken,
        char *strUsageUsageIndexName,
        int nBufLen,
        char fSemanticFlags)
{
  unsigned int v5; // eax
  const char *v6; // eax
  bool v7; // zf

  v5 = HIWORD(dwToken) & 0xF;
  switch ( dwToken & 0xF )
  {
    case 0u:
      if ( this->m_bGLSL )
      {
        if ( this->m_bVertexShader )
        {
          if ( (fSemanticFlags & 1) != 0 )
            V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "gl_Position");
          else
            V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "gl_Vertex");
        }
        else
        {
          V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "gl_FragCoord");
        }
      }
      else
      {
        V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "vertex.position");
      }
      break;
    case 1u:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "vertex.attrib[12]");
      break;
    case 2u:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "vertex.attrib[13]");
      break;
    case 3u:
      v6 = "vec4( gl_Normal, 0.0 )";
      if ( !this->m_bGLSL )
        v6 = "vertex.normal";
      goto LABEL_35;
    case 4u:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "_psize");
      break;
    case 5u:
      if ( this->m_bGLSL )
      {
        if ( !this->m_bVertexShader || (fSemanticFlags & 1) != 0 )
          V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "gl_TexCoord[%d]", HIWORD(dwToken) & 0xF);
        else
          V_snprintf(
            pDest: strUsageUsageIndexName,
            maxLen: nBufLen,
            pFormat: "gl_MultiTexCoord%d",
            HIWORD(dwToken) & 0xF);
      }
      else
      {
        V_snprintf(
          pDest: strUsageUsageIndexName,
          maxLen: nBufLen,
          pFormat: "vertex.texcoord[%d]",
          HIWORD(dwToken) & 0xF);
      }
      break;
    case 6u:
      if ( this->m_bGLSL )
      {
        D3DToGL::NoteTangentInputUsed(this);
        V_strncpy(pDest: strUsageUsageIndexName, pSrc: g_pTangentAttributeName, maxLen: nBufLen);
      }
      else
      {
        V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "vertex.attrib[15]");
      }
      break;
    case 7u:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "vertex.attrib[14]");
      break;
    case 0xAu:
      if ( this->m_bGLSL )
      {
        if ( (fSemanticFlags & 1) != 0 )
        {
          v7 = v5 == 0;
          v6 = "gl_BackColor";
          if ( v7 )
            v6 = "gl_FrontColor";
        }
        else
        {
          v7 = v5 == 0;
          v6 = "gl_SecondaryColor";
          if ( v7 )
            v6 = "gl_Color";
        }
      }
      else
      {
        v7 = v5 == 0;
        v6 = "vertex.color.secondary";
        if ( v7 )
          v6 = "vertex.color";
      }
LABEL_35:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: v6);
      break;
    case 0xBu:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "_fog");
      break;
    case 0xCu:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "_depth");
      break;
    case 0xDu:
      V_snprintf(pDest: strUsageUsageIndexName, maxLen: nBufLen, pFormat: "_sample");
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003650
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003690
// Name: private: class CUtlString D3DToGL::GetUsageAndIndexString(unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall D3DToGL::GetUsageAndIndexString(
        D3DToGL *this,
        CUtlString *result,
        unsigned int dwToken,
        char fSemanticFlags)
{
  char szTemp[1024]; // [esp+4h] [ebp-400h] BYREF

  D3DToGL::PrintUsageAndIndexToString(this, dwToken, strUsageUsageIndexName: szTemp, nBufLen: 1024, fSemanticFlags);
  CUtlString::CUtlString(this: result, pString: szTemp);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: private: class CUtlString D3DToGL::FixGLSLSwizzle(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall D3DToGL::FixGLSLSwizzle(
        D3DToGL *this,
        CUtlString *result,
        char *pDestRegisterName,
        char *pSrcRegisterName)
{
  unsigned __int8 *v5; // edi
  signed int NumSwizzleComponents; // esi
  signed int v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // eax
  signed int v12; // eax
  char v13; // al
  int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // eax
  signed int v19; // eax
  char v20; // al
  int v21; // kr00_4
  char s1[5]; // [esp+1h] [ebp-8Dh] BYREF
  char szFixedSrcRegister[128]; // [esp+6h] [ebp-88h] BYREF
  int nSwizzlesInDest; // [esp+86h] [ebp-8h]
  char pSrc[4]; // [esp+8Ah] [ebp-4h] BYREF

  if ( !this->m_bGLSL )
  {
    CUtlString::CUtlString(this: result, pString: pSrcRegisterName);
    return result;
  }
  v5 = (unsigned __int8 *)pDestRegisterName;
  NumSwizzleComponents = GetNumSwizzleComponents(pParam: pDestRegisterName);
  nSwizzlesInDest = NumSwizzleComponents;
  if ( NumSwizzleComponents == 0 )
  {
    nSwizzlesInDest = 4;
    NumSwizzleComponents = 4;
  }
  GetParamNameWithoutSwizzle(pParam: pSrcRegisterName, pOut: szFixedSrcRegister, nOutLen: 128);
  V_strncat(pDest: szFixedSrcRegister, pSrc: ".", destBufferSize: 0x80u, max_chars_to_copy: -1);
  v7 = 0;
  if ( NumSwizzleComponents > 0 )
  {
    while ( 1 )
    {
      strrchr(string: v5, chr: 0x2Eu);
      v9 = v8;
      if ( v8 != 0 && (strrchr(string: v5, chr: 0x29u), v10 < v9) && (strrchr(string: v5, chr: 0x5Du), v11 < v9) )
      {
        v12 = strlen((const char *)(v9 + 1));
        if ( v7 >= v12 )
          v13 = *(_BYTE *)(v12 + v9);
        else
          v13 = *(_BYTE *)(v9 + 1 + v7);
      }
      else
      {
        v13 = g_szDefaultSwizzle[v7];
      }
      switch ( v13 )
      {
        case 'x':
          goto LABEL_23;
        case 'y':
          v14 = 1;
          break;
        case 'z':
          v14 = 2;
          break;
        case 'w':
          v14 = 3;
          break;
        default:
          _Error(a1: "GetSwizzleComponentVectorIndex( '%c' ) - invalid parameter.\n", v13);
LABEL_23:
          v14 = 0;
          break;
      }
      strrchr(string: (unsigned __int8 *)pSrcRegisterName, chr: 0x2Eu);
      v16 = v15;
      if ( v15 != 0
        && (strrchr(string: (unsigned __int8 *)pSrcRegisterName, chr: 0x29u), v17 < v16)
        && (strrchr(string: (unsigned __int8 *)pSrcRegisterName, chr: 0x5Du), v18 < v16) )
      {
        v19 = strlen((const char *)(v16 + 1));
        if ( v14 >= v19 )
          v20 = *(_BYTE *)(v19 + v16);
        else
          v20 = *(_BYTE *)(v16 + 1 + v14);
      }
      else
      {
        v20 = g_szDefaultSwizzle[v14];
      }
      pSrc[0] = v20;
      pSrc[1] = 0;
      V_strncat(pDest: szFixedSrcRegister, pSrc, destBufferSize: 0x80u, max_chars_to_copy: -1);
      if ( ++v7 >= nSwizzlesInDest )
        break;
      v5 = (unsigned __int8 *)pDestRegisterName;
    }
  }
  v21 = strlen(szFixedSrcRegister);
  if ( v21 > 5 && _V_strcmp(s1: &s1[v21], s2: ".xyzw") == 0 )
    s1[v21] = 0;
  CUtlString::CUtlString(this: result, pString: szFixedSrcRegister);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038D0
// Name: private: void D3DToGL::Handle_DEF(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_DEF(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ecx
  const char *v4; // eax
  int i; // edi
  unsigned int *v6; // eax
  double v7; // xmm0_8
  int j; // eax
  int v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int k; // edi
  unsigned int *v13; // eax
  float v14; // ecx
  const char *v15; // eax
  char pRegisterName[1024]; // [esp+14h] [ebp-514h] BYREF
  char szTemp[256]; // [esp+414h] [ebp-114h] BYREF
  CUtlString sParamName; // [esp+514h] [ebp-14h] BYREF
  float fConst; // [esp+524h] [ebp-4h]

  m_pdwNextToken = this->m_pdwNextToken;
  v3 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  this->m_bConstantRegisterDefined[v3 & 0x7FF] = true;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v3,
    dwSourceOrDest: 0,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParamName, pString: pRegisterName);
  if ( this->m_bGLSL )
  {
    v4 = CUtlString::operator char const *(this: &sParamName);
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "vec4 %s = vec4( ", v4);
    for ( i = 0; i < 4; ++i )
    {
      v6 = this->m_pdwNextToken;
      fConst = *(float *)v6;
      v7 = fConst;
      this->m_pdwNextToken = v6 + 1;
      V_snprintf(pDest: szTemp, maxLen: 256, pFormat: "%f", v7);
      for ( j = strlen(szTemp); j >= 2; szTemp[--j] = 0 )
      {
        if ( szTemp[j - 1] != 48 )
          break;
        if ( pRegisterName[j + 1022] == 46 )
          break;
      }
      strchr(string: (unsigned __int8 *)szTemp, chr: 0x2Eu);
      if ( v9 == 0 )
        V_strncat(pDest: szTemp, pSrc: ".0", destBufferSize: 0x100u, max_chars_to_copy: -1);
      v10 = "%s, ";
      if ( i == 3 )
        v10 = "%s";
      PrintToBuf(buf: this->m_pBufParamCode, pFormat: v10, szTemp);
    }
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: " );\n");
  }
  else
  {
    v11 = CUtlString::operator char const *(this: &sParamName);
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "PARAM %s = { ", v11);
    for ( k = 0; k < 4; ++k )
    {
      v13 = this->m_pdwNextToken;
      v14 = *(float *)v13;
      this->m_pdwNextToken = v13 + 1;
      fConst = v14;
      v15 = "%g, ";
      if ( k == 3 )
        v15 = "%g";
      PrintToBuf(buf: this->m_pBufParamCode, pFormat: v15, fConst);
    }
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: " };\n");
  }
  sParamName.m_Storage.m_nActualLength = 0;
  if ( sParamName.m_Storage.m_Memory.m_nGrowSize >= 0 && sParamName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParamName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003AE0
// Name: private: void D3DToGL::Handle_MAD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_MAD(D3DToGL *this, unsigned int nInstruction)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // ecx
  unsigned int *v7; // eax
  unsigned int v8; // ecx
  unsigned int *v9; // eax
  unsigned int v10; // ecx
  char *v11; // eax
  CUtlString *fixed; // eax
  char *v13; // eax
  CUtlString *v14; // eax
  char *v15; // eax
  CUtlString *v16; // eax
  const char *v17; // edi
  const char *v18; // ebx
  const char *v19; // eax
  const char *v20; // edi
  const char *v21; // ebx
  const char *v22; // eax
  char *v23; // [esp-4h] [ebp-560h]
  char *v24; // [esp-4h] [ebp-560h]
  char *v25; // [esp-4h] [ebp-560h]
  char pRegisterName[1024]; // [esp+Ch] [ebp-550h] BYREF
  char buff[256]; // [esp+40Ch] [ebp-150h] BYREF
  CUtlString sParam1; // [esp+50Ch] [ebp-50h] BYREF
  CUtlString sParam4; // [esp+51Ch] [ebp-40h] BYREF
  CUtlString sParam2; // [esp+52Ch] [ebp-30h] BYREF
  CUtlString sParam3; // [esp+53Ch] [ebp-20h] BYREF
  CUtlString result; // [esp+54Ch] [ebp-10h] BYREF
  const char *nInstructiona; // [esp+564h] [ebp+8h]
  const char *nInstructionb; // [esp+564h] [ebp+8h]

  m_pdwNextToken = this->m_pdwNextToken;
  v4 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v4,
    dwSourceOrDest: 0,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam1, pString: pRegisterName);
  v5 = this->m_pdwNextToken;
  v6 = *v5;
  this->m_pdwNextToken = v5 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v6,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam2, pString: pRegisterName);
  v7 = this->m_pdwNextToken;
  v8 = *v7;
  this->m_pdwNextToken = v7 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v8,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam3, pString: pRegisterName);
  v9 = this->m_pdwNextToken;
  v10 = *v9;
  this->m_pdwNextToken = v9 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v10,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam4, pString: pRegisterName);
  if ( this->m_bGLSL )
  {
    v23 = (char *)CUtlString::operator char const *(this: &sParam2);
    v11 = (char *)CUtlString::operator char const *(this: &sParam1);
    fixed = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: v11, pSrcRegisterName: v23);
    CUtlString::operator=(this: &sParam2, src: fixed);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v24 = (char *)CUtlString::operator char const *(this: &sParam3);
    v13 = (char *)CUtlString::operator char const *(this: &sParam1);
    v14 = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: v13, pSrcRegisterName: v24);
    CUtlString::operator=(this: &sParam3, src: v14);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v25 = (char *)CUtlString::operator char const *(this: &sParam4);
    v15 = (char *)CUtlString::operator char const *(this: &sParam1);
    v16 = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: v15, pSrcRegisterName: v25);
    CUtlString::operator=(this: &sParam4, src: v16);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v17 = CUtlString::operator char const *(this: &sParam4);
    v18 = CUtlString::operator char const *(this: &sParam3);
    nInstructiona = CUtlString::operator char const *(this: &sParam2);
    v19 = CUtlString::operator char const *(this: &sParam1);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = %s * %s + %s;\n", v19, nInstructiona, v18, v17);
  }
  else
  {
    D3DToGL::PrintOpcode(this, inst: nInstruction, buff, nBufLen: 256);
    v20 = CUtlString::operator char const *(this: &sParam4);
    v21 = CUtlString::operator char const *(this: &sParam3);
    nInstructionb = CUtlString::operator char const *(this: &sParam2);
    v22 = CUtlString::operator char const *(this: &sParam1);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s%s, %s, %s, %s;\n", buff, v22, nInstructionb, v21, v20);
  }
  sParam4.m_Storage.m_nActualLength = 0;
  if ( sParam4.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam4.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam4.m_Storage.m_Memory.m_pMemory);
      sParam4.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam4.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam3.m_Storage.m_nActualLength = 0;
  if ( sParam3.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam3.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam3.m_Storage.m_Memory.m_pMemory);
      sParam3.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam3.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam2.m_Storage.m_nActualLength = 0;
  if ( sParam2.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam2.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam2.m_Storage.m_Memory.m_pMemory);
      sParam2.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam2.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam1.m_Storage.m_nActualLength = 0;
  if ( sParam1.m_Storage.m_Memory.m_nGrowSize >= 0 && sParam1.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam1.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003DD0
// Name: private: void D3DToGL::HandleBinaryOp_ASM(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::HandleBinaryOp_ASM(D3DToGL *this, unsigned int nInstruction)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // ecx
  unsigned int *v7; // eax
  unsigned int v8; // ecx
  const char *v9; // edi
  const char *v10; // ebx
  const char *v11; // eax
  char pRegisterName[1024]; // [esp+Ch] [ebp-530h] BYREF
  char buff[256]; // [esp+40Ch] [ebp-130h] BYREF
  CUtlString sParam1; // [esp+50Ch] [ebp-30h] BYREF
  CUtlString sParam2; // [esp+51Ch] [ebp-20h] BYREF
  CUtlString sParam3; // [esp+52Ch] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v4 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v4,
    dwSourceOrDest: 0,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam1, pString: pRegisterName);
  v5 = this->m_pdwNextToken;
  v6 = *v5;
  this->m_pdwNextToken = v5 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v6,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam2, pString: pRegisterName);
  v7 = this->m_pdwNextToken;
  v8 = *v7;
  this->m_pdwNextToken = v7 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v8,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam3, pString: pRegisterName);
  D3DToGL::PrintOpcode(this, inst: nInstruction, buff, nBufLen: 256);
  v9 = CUtlString::operator char const *(this: &sParam3);
  v10 = CUtlString::operator char const *(this: &sParam2);
  v11 = CUtlString::operator char const *(this: &sParam1);
  PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s%s, %s, %s;\n", buff, v11, v10, v9);
  sParam3.m_Storage.m_nActualLength = 0;
  if ( sParam3.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam3.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam3.m_Storage.m_Memory.m_pMemory);
      sParam3.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam3.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam2.m_Storage.m_nActualLength = 0;
  if ( sParam2.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam2.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam2.m_Storage.m_Memory.m_pMemory);
      sParam2.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam2.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam1.m_Storage.m_nActualLength = 0;
  if ( sParam1.m_Storage.m_Memory.m_nGrowSize >= 0 && sParam1.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam1.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003F40
// Name: private: void D3DToGL::Handle_CMP(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_CMP(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ecx
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  unsigned int *v6; // eax
  unsigned int v7; // ecx
  unsigned int *v8; // eax
  unsigned int v9; // ecx
  CUtlString *fixed; // eax
  const char *v11; // eax
  CUtlString *v12; // eax
  const char *v13; // eax
  CUtlString *v14; // eax
  const char *v15; // eax
  char pOut[256]; // [esp+4h] [ebp-410h] BYREF
  char szTempVar[256]; // [esp+104h] [ebp-310h] BYREF
  char szDestBase[256]; // [esp+204h] [ebp-210h] BYREF
  char pSrc1Reg[64]; // [esp+304h] [ebp-110h] BYREF
  char pSrc2Reg[64]; // [esp+344h] [ebp-D0h] BYREF
  char pSrc0Reg[64]; // [esp+384h] [ebp-90h] BYREF
  char pDestReg[64]; // [esp+3C4h] [ebp-50h] BYREF
  CUtlString result; // [esp+404h] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v3 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v3,
    dwSourceOrDest: 0,
    pRegisterName: pDestReg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  v4 = this->m_pdwNextToken;
  v5 = *v4;
  this->m_pdwNextToken = v4 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v5,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc0Reg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  v6 = this->m_pdwNextToken;
  v7 = *v6;
  this->m_pdwNextToken = v6 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v7,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc1Reg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  v8 = this->m_pdwNextToken;
  v9 = *v8;
  this->m_pdwNextToken = v8 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v9,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc2Reg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  if ( this->m_bGLSL )
  {
    GetParamNameWithoutSwizzle(pParam: pDestReg, pOut: szDestBase, nOutLen: 256);
    fixed = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: pDestReg, pSrcRegisterName: pSrc0Reg);
    v11 = CUtlString::operator char const *(this: fixed);
    V_strncpy(pDest: pSrc0Reg, pSrc: v11, maxLen: 64);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v12 = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: pDestReg, pSrcRegisterName: pSrc1Reg);
    v13 = CUtlString::operator char const *(this: v12);
    V_strncpy(pDest: pSrc1Reg, pSrc: v13, maxLen: 64);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v14 = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: pDestReg, pSrcRegisterName: pSrc2Reg);
    v15 = CUtlString::operator char const *(this: v14);
    V_strncpy(pDest: pSrc2Reg, pSrc: v15, maxLen: 64);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    GetParamNameWithoutSwizzle(pParam: pDestReg, pOut, nOutLen: 256);
    GetParamNameWithoutSwizzle(pParam: pSrc0Reg, pOut: szTempVar, nOutLen: 256);
    if ( _V_stricmp(s1: pOut, s2: szTempVar) != 0 || (int)GetNumSwizzleComponents(pParam: pDestReg) <= 1 )
    {
      D3DToGL::WriteGLSLCmp(this, pDestReg, pSrc0Reg, pSrc1Reg, pSrc2Reg);
    }
    else
    {
      PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = %s;\n", g_pAtomicTempVarName, szDestBase);
      ReplaceParamName(pSrc: pDestReg, pNewParamName: g_pAtomicTempVarName, pOut: szTempVar, nOutLen: 256);
      D3DToGL::WriteGLSLCmp(this, pDestReg: szTempVar, pSrc0Reg, pSrc1Reg, pSrc2Reg);
      PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = %s;\n", szDestBase, g_pAtomicTempVarName);
      this->m_bUsedAtomicTempVar = true;
    }
  }
  else
  {
    if ( !this->m_bVertexShader )
      strcat_s(
        _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
        _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
        _Src: "*** NOTE: CMP instruction hasn't been verified correct in GL ASM PS code *** ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: "CMP");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pDestReg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc0Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc2Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc1Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ";\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004300
// Name: private: void D3DToGL::Handle_SimpleInstruction(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_SimpleInstruction(D3DToGL *this, unsigned int nInstruction)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // ecx
  char *v7; // eax
  CUtlString *fixed; // eax
  const char *v9; // edi
  const char *v10; // eax
  const char *v11; // edi
  const char *v12; // eax
  const char *v13; // edi
  const char *v14; // eax
  const char *v15; // edi
  const char *v16; // eax
  const char *v17; // edi
  const char *v18; // eax
  const char *v19; // edi
  const char *v20; // eax
  char *v21; // [esp-4h] [ebp-540h]
  char pRegisterName[1024]; // [esp+Ch] [ebp-530h] BYREF
  char buff[256]; // [esp+40Ch] [ebp-130h] BYREF
  CUtlString result; // [esp+50Ch] [ebp-30h] BYREF
  CUtlString sParam1; // [esp+51Ch] [ebp-20h] BYREF
  CUtlString sParam2; // [esp+52Ch] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v4 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v4,
    dwSourceOrDest: 0,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam1, pString: pRegisterName);
  v5 = this->m_pdwNextToken;
  v6 = *v5;
  this->m_pdwNextToken = v5 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v6,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: nInstruction == 46);
  CUtlString::CUtlString(this: &sParam2, pString: pRegisterName);
  v21 = (char *)CUtlString::operator char const *(this: &sParam2);
  v7 = (char *)CUtlString::operator char const *(this: &sParam1);
  fixed = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: v7, pSrcRegisterName: v21);
  CUtlString::operator=(this: &sParam2, src: fixed);
  result.m_Storage.m_nActualLength = 0;
  if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
  if ( this->m_bGLSL )
  {
    switch ( nInstruction )
    {
      case 1u:
        v9 = CUtlString::operator char const *(this: &sParam2);
        v10 = CUtlString::operator char const *(this: &sParam1);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = %s;\n", v10, v9);
        break;
      case 7u:
        v11 = CUtlString::operator char const *(this: &sParam2);
        v12 = CUtlString::operator char const *(this: &sParam1);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = inversesqrt( %s );\n", v12, v11);
        break;
      case 6u:
        v13 = CUtlString::operator char const *(this: &sParam2);
        v14 = CUtlString::operator char const *(this: &sParam1);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = 1.0 / %s;\n", v14, v13);
        break;
      case 0xEu:
        v15 = CUtlString::operator char const *(this: &sParam2);
        v16 = CUtlString::operator char const *(this: &sParam1);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = exp2( %s );\n", v16, v15);
        break;
      case 0x13u:
        v17 = CUtlString::operator char const *(this: &sParam2);
        v18 = CUtlString::operator char const *(this: &sParam1);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = fract( %s );\n", v18, v17);
        break;
      default:
        _Error(a1: "Unsupported instruction");
        break;
    }
  }
  else
  {
    if ( nInstruction == 46 )
      this->m_bDeclareAddressReg = true;
    D3DToGL::PrintOpcode(this, inst: nInstruction, buff, nBufLen: 256);
    v19 = CUtlString::operator char const *(this: &sParam2);
    v20 = CUtlString::operator char const *(this: &sParam1);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s%s, %s;\n", buff, v20, v19);
  }
  sParam2.m_Storage.m_nActualLength = 0;
  if ( sParam2.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam2.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam2.m_Storage.m_Memory.m_pMemory);
      sParam2.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam2.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam1.m_Storage.m_nActualLength = 0;
  if ( sParam1.m_Storage.m_Memory.m_nGrowSize >= 0 && sParam1.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam1.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10004570
// Name: private: void D3DToGL::WriteGLSLOutputVariableAssignments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::WriteGLSLOutputVariableAssignments(D3DToGL *this)
{
  unsigned int v2; // edi
  unsigned int *m_DeclaredOutputs; // ebx
  const char *v4; // eax
  char strUsageUsageIndexName[1024]; // [esp+4h] [ebp-410h] BYREF
  CUtlString sOutputName; // [esp+404h] [ebp-10h] BYREF

  if ( this->m_bVertexShader )
  {
    if ( this->m_bAddHexCodeComments )
      PrintToBuf(
        pOut: this->m_pAttribCode,
        nOutSize: this->m_nAttribCodeBufSize,
        pFormat: "\n// Now we're storing the oN variables from the output dcl_ statements back into their GLSL equivalents.\n");
    v2 = 0;
    m_DeclaredOutputs = this->m_DeclaredOutputs;
    do
    {
      if ( *m_DeclaredOutputs != -1 )
      {
        D3DToGL::PrintUsageAndIndexToString(
          this,
          dwToken: *m_DeclaredOutputs,
          strUsageUsageIndexName,
          nBufLen: 1024,
          fSemanticFlags: 1);
        CUtlString::CUtlString(this: &sOutputName, pString: strUsageUsageIndexName);
        v4 = CUtlString::operator char const *(this: &sOutputName);
        PrintToBuf(pOut: this->m_pAttribCode, nOutSize: this->m_nAttribCodeBufSize, pFormat: "%s = o%d;\n", v4, v2);
        sOutputName.m_Storage.m_nActualLength = 0;
        if ( sOutputName.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( sOutputName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sOutputName.m_Storage.m_Memory.m_pMemory);
            sOutputName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          sOutputName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      ++v2;
      ++m_DeclaredOutputs;
    }
    while ( v2 < 0x20 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004650
// Name: class CUtlString EnsureNumSwizzleComponents(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl EnsureNumSwizzleComponents(CUtlString *result, char *pStr, int nComponents)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax
  signed int v7; // edi
  int i; // edi
  char SwizzleComponent; // al
  char v11; // bl
  int v12; // esi
  char szReg[256]; // [esp+Ch] [ebp-100h] BYREF

  strrchr(string: (unsigned __int8 *)pStr, chr: 0x2Eu);
  v4 = v3;
  if ( v3 != 0
    && (strrchr(string: (unsigned __int8 *)pStr, chr: 0x29u), v5 < v4)
    && (strrchr(string: (unsigned __int8 *)pStr, chr: 0x5Du), v6 < v4) )
  {
    v7 = strlen((const char *)(v4 + 1));
  }
  else
  {
    v7 = 0;
  }
  if ( v7 == nComponents )
  {
    CUtlString::CUtlString(this: result, pString: pStr);
    return result;
  }
  else
  {
    GetParamNameWithoutSwizzle(pParam: pStr, pOut: szReg, nOutLen: 256);
    if ( nComponents != 0 )
    {
      PrintToBuf(pOut: szReg, nOutSize: 256, pFormat: ".");
      if ( v7 <= nComponents )
      {
        if ( v7 != 0 )
        {
          V_strncpy(pDest: szReg, pSrc: pStr, maxLen: 256);
          v11 = pStr[strlen(pStr) - 1];
          if ( v7 < nComponents )
          {
            v12 = nComponents - v7;
            do
            {
              PrintToBuf(pOut: szReg, nOutSize: 256, pFormat: "%c", v11);
              --v12;
            }
            while ( v12 != 0 );
          }
        }
        else if ( nComponents > 0 )
        {
          do
            PrintToBuf(pOut: szReg, nOutSize: 256, pFormat: "%c", g_szDefaultSwizzle[v7++]);
          while ( v7 < nComponents );
        }
      }
      else
      {
        for ( i = 0; i < nComponents; ++i )
        {
          SwizzleComponent = GetSwizzleComponent(pParam: pStr, n: i);
          PrintToBuf(pOut: szReg, nOutSize: 256, pFormat: "%c", SwizzleComponent);
        }
      }
    }
    CUtlString::CUtlString(this: result, pString: szReg);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100047E0
// Name: private: void D3DToGL::Handle_DCL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_DCL(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ebx
  unsigned int v4; // edi
  bool v5; // zf
  unsigned int v6; // edi
  const char *v7; // eax
  char *v8; // eax
  CUtlString *fixed; // eax
  const char *v10; // edi
  const char *v11; // eax
  const char *v12; // edi
  const char *v13; // eax
  int v14; // ebx
  int v15; // edi
  char *v16; // edi
  unsigned int NumSwizzleComponents; // eax
  const char *v18; // eax
  char *v19; // [esp-4h] [ebp-640h]
  char pRegisterName[1024]; // [esp+Ch] [ebp-630h] BYREF
  char szDestRegister[256]; // [esp+40Ch] [ebp-230h] BYREF
  char buff[256]; // [esp+50Ch] [ebp-130h] BYREF
  CUtlString sSrcWithSwizzles; // [esp+60Ch] [ebp-30h] BYREF
  CUtlString sInputThing; // [esp+61Ch] [ebp-20h] BYREF
  CUtlString v25; // [esp+62Ch] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v3 = *m_pdwNextToken++;
  this->m_pdwNextToken = m_pdwNextToken;
  v4 = *m_pdwNextToken;
  v5 = !this->m_bVertexShader;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  if ( v5 )
  {
    if ( (v4 & 0x1800 | (v4 >> 20) & 0x700) == 0xA00 )
    {
      v14 = v3 & 0x78000000;
      v15 = v4 & 0x7FF;
      if ( v14 == 402653184 )
      {
        this->m_dwSamplerTypes[v15] = 1;
      }
      else if ( v14 == 0x20000000 )
      {
        this->m_dwSamplerTypes[v15] = 2;
      }
      else
      {
        this->m_dwSamplerTypes[v15] = 0;
      }
    }
    else if ( this->m_bGLSL )
    {
      D3DToGL::PrintUsageAndIndexToString(
        this,
        dwToken: v3,
        strUsageUsageIndexName: pRegisterName,
        nBufLen: 1024,
        fSemanticFlags: 2);
      CUtlString::CUtlString(this: &sInputThing, pString: pRegisterName);
      D3DToGL::PrintParameterToString(
        this,
        dwToken: v4,
        dwSourceOrDest: 0,
        pRegisterName: szDestRegister,
        nBufLen: 0x100u,
        bForceScalarSource: false);
      GetParamNameWithoutSwizzle(pParam: szDestRegister, pOut: buff, nOutLen: 256);
      v16 = (char *)CUtlString::operator char const *(this: &sInputThing);
      NumSwizzleComponents = GetNumSwizzleComponents(pParam: szDestRegister);
      EnsureNumSwizzleComponents(result: &sSrcWithSwizzles, pStr: v16, nComponents: NumSwizzleComponents);
      v18 = CUtlString::operator char const *(this: &sSrcWithSwizzles);
      PrintToBuf(buf: this->m_pBufALUCode, pFormat: "vec4 %s;\n%s = %s;\n", buff, szDestRegister, v18);
      CUtlString::~CUtlString(this: &sSrcWithSwizzles);
      CUtlString::~CUtlString(this: &sInputThing);
    }
    else
    {
      D3DToGL::PrintParameterToString(
        this,
        dwToken: v4,
        dwSourceOrDest: 0,
        pRegisterName: buff,
        nBufLen: 0x100u,
        bForceScalarSource: false);
      PrintToBuf(pOut: this->m_pAttribCode, nOutSize: this->m_nAttribCodeBufSize, pFormat: "ATTRIB %s;\n", buff);
    }
    return;
  }
  if ( this->m_bGLSL )
  {
    if ( this->m_dwMajorVersion >= 3 && (v4 & 0x1800 | (v4 >> 20) & 0x700) == 0x600 )
    {
      v6 = v4 & 0x7FF;
      if ( v6 >= 0x20 )
        _Error(a1: "Output register number (%d) too high (only %d supported).", v6, 32);
      if ( this->m_DeclaredOutputs[v6] != -1 )
        _Error(a1: "Output dcl_ hit for register #%d more than once!", v6);
      this->m_DeclaredOutputs[v6] = v3;
      if ( this->m_bAddHexCodeComments )
      {
        D3DToGL::GetUsageAndIndexString(this, result: &sSrcWithSwizzles, dwToken: v3, fSemanticFlags: 1);
        v7 = CUtlString::operator char const *(this: &sSrcWithSwizzles);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "// [GL remembering that o%d maps to %s]\n", v6, v7);
        CUtlString::~CUtlString(this: &sSrcWithSwizzles);
      }
      PrintToBuf(buf: this->m_pBufALUCode, pFormat: "vec4 o%d = vec4( 0.0, 0.0, 0.0, 0.0 );\n", v6);
      return;
    }
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v4,
      dwSourceOrDest: 0,
      pRegisterName,
      nBufLen: 0x400u,
      bForceScalarSource: false);
    CUtlString::CUtlString(this: &sInputThing, pString: pRegisterName);
    D3DToGL::PrintUsageAndIndexToString(
      this,
      dwToken: v3,
      strUsageUsageIndexName: pRegisterName,
      nBufLen: 1024,
      fSemanticFlags: 2);
    CUtlString::CUtlString(this: &v25, pString: pRegisterName);
    v19 = (char *)CUtlString::operator char const *(this: &v25);
    v8 = (char *)CUtlString::operator char const *(this: &sInputThing);
    fixed = D3DToGL::FixGLSLSwizzle(this, result: &sSrcWithSwizzles, pDestRegisterName: v8, pSrcRegisterName: v19);
    CUtlString::operator=(this: &v25, src: fixed);
    sSrcWithSwizzles.m_Storage.m_nActualLength = 0;
    if ( sSrcWithSwizzles.m_Storage.m_Memory.m_nGrowSize >= 0
      && sSrcWithSwizzles.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sSrcWithSwizzles.m_Storage.m_Memory.m_pMemory);
    }
    v10 = CUtlString::operator char const *(this: &v25);
    v11 = CUtlString::operator char const *(this: &sInputThing);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "vec4 %s = %s;\n", v11, v10);
    v25.m_Storage.m_nActualLength = 0;
    if ( v25.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25.m_Storage.m_Memory.m_pMemory);
        v25.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v25.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    sInputThing.m_Storage.m_nActualLength = 0;
    if ( sInputThing.m_Storage.m_Memory.m_nGrowSize >= 0 && sInputThing.m_Storage.m_Memory.m_pMemory != nullptr )
LABEL_21:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sInputThing.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    D3DToGL::PrintParameterToString(
      this,
      dwToken: v4,
      dwSourceOrDest: 0,
      pRegisterName,
      nBufLen: 0x400u,
      bForceScalarSource: false);
    CUtlString::CUtlString(this: &sInputThing, pString: pRegisterName);
    D3DToGL::PrintUsageAndIndexToString(
      this,
      dwToken: v3,
      strUsageUsageIndexName: pRegisterName,
      nBufLen: 1024,
      fSemanticFlags: 2);
    CUtlString::CUtlString(this: &v25, pString: pRegisterName);
    v12 = CUtlString::operator char const *(this: &v25);
    v13 = CUtlString::operator char const *(this: &sInputThing);
    PrintToBuf(pOut: this->m_pAttribCode, nOutSize: this->m_nAttribCodeBufSize, pFormat: "ATTRIB%s = %s;\n", v13, v12);
    v25.m_Storage.m_nActualLength = 0;
    if ( v25.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v25.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25.m_Storage.m_Memory.m_pMemory);
        v25.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      v25.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    sInputThing.m_Storage.m_nActualLength = 0;
    if ( sInputThing.m_Storage.m_Memory.m_nGrowSize >= 0 && sInputThing.m_Storage.m_Memory.m_pMemory != nullptr )
      goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C40
// Name: private: void D3DToGL::Handle_DP2ADD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_DP2ADD(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ecx
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  unsigned int *v6; // eax
  unsigned int v7; // ecx
  unsigned int *v8; // eax
  unsigned int v9; // ecx
  const char *v10; // edi
  const char *v11; // eax
  CUtlBuffer *m_pBufALUCode; // [esp-Ch] [ebp-74h]
  char pDestReg[16]; // [esp+8h] [ebp-60h] BYREF
  char pSrc2Reg[16]; // [esp+18h] [ebp-50h] BYREF
  char pSrc1Reg[16]; // [esp+28h] [ebp-40h] BYREF
  char pSrc0Reg[16]; // [esp+38h] [ebp-30h] BYREF
  CUtlString sArg0; // [esp+48h] [ebp-20h] BYREF
  CUtlString sArg1; // [esp+58h] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v3 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v3,
    dwSourceOrDest: 0,
    pRegisterName: pDestReg,
    nBufLen: 0x10u,
    bForceScalarSource: false);
  v4 = this->m_pdwNextToken;
  v5 = *v4;
  this->m_pdwNextToken = v4 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v5,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc0Reg,
    nBufLen: 0x10u,
    bForceScalarSource: false);
  v6 = this->m_pdwNextToken;
  v7 = *v6;
  this->m_pdwNextToken = v6 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v7,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc1Reg,
    nBufLen: 0x10u,
    bForceScalarSource: false);
  v8 = this->m_pdwNextToken;
  v9 = *v8;
  this->m_pdwNextToken = v8 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v9,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc2Reg,
    nBufLen: 0x10u,
    bForceScalarSource: false);
  if ( this->m_bGLSL )
  {
    EnsureNumSwizzleComponents(result: &sArg0, pStr: pSrc0Reg, nComponents: 2);
    EnsureNumSwizzleComponents(result: &sArg1, pStr: pSrc1Reg, nComponents: 2);
    v10 = CUtlString::operator char const *(this: &sArg1);
    v11 = CUtlString::operator char const *(this: &sArg0);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = dot( %s, %s ) + %s;\n", pDestReg, v11, v10, pSrc2Reg);
    sArg1.m_Storage.m_nActualLength = 0;
    if ( sArg1.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( sArg1.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sArg1.m_Storage.m_Memory.m_pMemory);
        sArg1.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      sArg1.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    sArg0.m_Storage.m_nActualLength = 0;
    if ( sArg0.m_Storage.m_Memory.m_nGrowSize >= 0 && sArg0.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sArg0.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    m_pBufALUCode = this->m_pBufALUCode;
    this->m_bNeedsD2AddTemp = true;
    PrintToBuf(buf: m_pBufALUCode, pFormat: "MOV DP2A0, %s;\n", pSrc0Reg);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "MOV DP2A0.z, 1;\n");
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "MOV DP2A1, %s;\n", pSrc1Reg);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "MOV DP2A1.z, %s;\n", pSrc2Reg);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "DP3%s, DP2A0, DP2A1;\n", pDestReg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004DE0
// Name: private: void D3DToGL::Handle_TEX(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_TEX(D3DToGL *this, unsigned int dwToken, bool bIsTexLDL)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v5; // ecx
  unsigned int *v6; // eax
  unsigned int v7; // ecx
  unsigned int *v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // edi
  char SwizzleComponent; // al
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  char szLOD[128]; // [esp+8h] [ebp-158h] BYREF
  char pDestReg[64]; // [esp+88h] [ebp-D8h] BYREF
  char pSrc1Reg[64]; // [esp+C8h] [ebp-98h] BYREF
  char pSrc0Reg[64]; // [esp+108h] [ebp-58h] BYREF
  char szExtra[8]; // [esp+148h] [ebp-18h] BYREF
  CUtlString sCoordVar; // [esp+150h] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v5 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v5,
    dwSourceOrDest: 0,
    pRegisterName: pDestReg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  v6 = this->m_pdwNextToken;
  v7 = *v6;
  this->m_pdwNextToken = v6 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v7,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc0Reg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  v8 = this->m_pdwNextToken;
  v9 = *v8;
  this->m_pdwNextToken = v8 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v9,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc1Reg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  if ( this->m_bGLSL )
  {
    v10 = this->m_dwSamplerTypes[v9 & 0x7FF];
    if ( v10 != 0 )
    {
      if ( v10 == 2 )
      {
        EnsureNumSwizzleComponents(result: &sCoordVar, pStr: pSrc0Reg, nComponents: 3);
        v14 = CUtlString::operator char const *(this: &sCoordVar);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = texture3D( %s, %s );\n", pDestReg, pSrc1Reg, v14);
        CUtlString::~CUtlString(this: &sCoordVar);
      }
      else
      {
        _Error(a1: "TEX instruction: unsupported sampler type used");
      }
    }
    else
    {
      EnsureNumSwizzleComponents(result: &sCoordVar, pStr: pSrc0Reg, nComponents: 2);
      if ( bIsTexLDL )
      {
        GetParamNameWithoutSwizzle(pParam: pSrc0Reg, pOut: szLOD, nOutLen: 128);
        SwizzleComponent = GetSwizzleComponent(pParam: pSrc0Reg, n: 3);
        V_snprintf(pDest: szExtra, maxLen: 8, pFormat: ".%c", SwizzleComponent);
        V_strncat(pDest: szLOD, pSrc: szExtra, destBufferSize: 0x80u, max_chars_to_copy: -1);
        v12 = CUtlString::operator char const *(this: &sCoordVar);
        PrintToBuf(
          buf: this->m_pBufALUCode,
          pFormat: "%s = texture2DLod( %s, %s, %s );\n",
          pDestReg,
          pSrc1Reg,
          v12,
          szLOD);
      }
      else
      {
        v13 = CUtlString::operator char const *(this: &sCoordVar);
        PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = texture2D( %s, %s );\n", pDestReg, pSrc1Reg, v13);
      }
      sCoordVar.m_Storage.m_nActualLength = 0;
      if ( sCoordVar.m_Storage.m_Memory.m_nGrowSize >= 0 && sCoordVar.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sCoordVar.m_Storage.m_Memory.m_pMemory);
    }
  }
  else
  {
    if ( (dwToken & 0xFF0000) == 0x10000 )
    {
      strcat_s(
        _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
        _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
        _Src: "TXP");
    }
    else if ( (dwToken & 0xFF0000) == 0x20000 )
    {
      strcat_s(
        _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
        _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
        _Src: "TXB");
    }
    else
    {
      strcat_s(
        _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
        _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
        _Src: "TEX");
    }
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pDestReg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc0Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc1Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: g_pSamplerStrings[this->m_dwSamplerTypes[dwToken & 0x7FF]]);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ";\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100050F0
// Name: private: void D3DToGL::HandleBinaryOp_GLSL(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::HandleBinaryOp_GLSL(D3DToGL *this, unsigned int nInstruction)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // ecx
  unsigned int *v7; // eax
  unsigned int v8; // ecx
  char *v10; // eax
  CUtlString *v11; // eax
  char *v12; // eax
  CUtlString *v13; // eax
  char *v14; // eax
  CUtlString *fixed; // eax
  char *v16; // eax
  CUtlString *v17; // eax
  const char *v18; // edi
  const char *v19; // ebx
  const char *v20; // ebx
  const char *v21; // edi
  char *v22; // eax
  unsigned int NumSwizzleComponents; // edi
  const char *v24; // ebx
  const char *v25; // eax
  const char *v26; // [esp-10h] [ebp-560h]
  const char *v27; // [esp-10h] [ebp-560h]
  char *v28; // [esp-4h] [ebp-554h]
  char *v29; // [esp-4h] [ebp-554h]
  char pRegisterName[1024]; // [esp+Ch] [ebp-544h] BYREF
  char buff[256]; // [esp+40Ch] [ebp-144h] BYREF
  unsigned int v32; // [esp+50Ch] [ebp-44h]
  CUtlString sParam1; // [esp+510h] [ebp-40h] BYREF
  CUtlString sParam2; // [esp+520h] [ebp-30h] BYREF
  CUtlString sParam3; // [esp+530h] [ebp-20h] BYREF
  CUtlString result; // [esp+540h] [ebp-10h] BYREF
  const char *nInstructiona; // [esp+558h] [ebp+8h]

  m_pdwNextToken = this->m_pdwNextToken;
  v4 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  v32 = v4;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v4,
    dwSourceOrDest: 0,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam1, pString: pRegisterName);
  v5 = this->m_pdwNextToken;
  v6 = *v5;
  this->m_pdwNextToken = v5 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v6,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam2, pString: pRegisterName);
  v7 = this->m_pdwNextToken;
  v8 = *v7;
  this->m_pdwNextToken = v7 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v8,
    dwSourceOrDest: 1u,
    pRegisterName,
    nBufLen: 0x400u,
    bForceScalarSource: false);
  CUtlString::CUtlString(this: &sParam3, pString: pRegisterName);
  if ( nInstruction == 8 )
  {
    v10 = (char *)CUtlString::operator char const *(this: &sParam2);
    v11 = EnsureNumSwizzleComponents(&result, pStr: v10, nComponents: 3);
    CUtlString::operator=(this: &sParam2, src: v11);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v12 = (char *)CUtlString::operator char const *(this: &sParam3);
    v13 = EnsureNumSwizzleComponents(&result, pStr: v12, nComponents: 3);
    CUtlString::operator=(this: &sParam3, src: v13);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
LABEL_18:
    D3DToGL::OpenIntrinsic(this, inst: nInstruction, buff, nBufLen: 256);
    v18 = CUtlString::operator char const *(this: &sParam3);
    v19 = CUtlString::operator char const *(this: &sParam2);
    v26 = CUtlString::operator char const *(this: &sParam1);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = %s%s, %s );\n", v26, buff, v19, v18);
    goto LABEL_25;
  }
  if ( nInstruction != 9 )
  {
    v28 = (char *)CUtlString::operator char const *(this: &sParam2);
    v14 = (char *)CUtlString::operator char const *(this: &sParam1);
    fixed = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: v14, pSrcRegisterName: v28);
    CUtlString::operator=(this: &sParam2, src: fixed);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
    v29 = (char *)CUtlString::operator char const *(this: &sParam3);
    v16 = (char *)CUtlString::operator char const *(this: &sParam1);
    v17 = D3DToGL::FixGLSLSwizzle(this, &result, pDestRegisterName: v16, pSrcRegisterName: v29);
    CUtlString::operator=(this: &sParam3, src: v17);
    result.m_Storage.m_nActualLength = 0;
    if ( result.m_Storage.m_Memory.m_nGrowSize >= 0 && result.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: result.m_Storage.m_Memory.m_pMemory);
  }
  if ( nInstruction != 2 && nInstruction != 3 && nInstruction != 5 )
    goto LABEL_18;
  nInstructiona = CUtlString::operator char const *(this: &sParam3);
  if ( nInstruction == 2 )
  {
    v20 = "+";
  }
  else if ( nInstruction == 3 )
  {
    v20 = "-";
  }
  else
  {
    v20 = "*";
  }
  v21 = CUtlString::operator char const *(this: &sParam2);
  v27 = CUtlString::operator char const *(this: &sParam1);
  PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = %s %s %s;\n", v27, v21, v20, nInstructiona);
LABEL_25:
  if ( (v32 & 0x100000) != 0 )
  {
    v22 = (char *)CUtlString::operator char const *(this: &sParam1);
    NumSwizzleComponents = GetNumSwizzleComponents(pParam: v22);
    if ( NumSwizzleComponents == 0 )
      NumSwizzleComponents = 4;
    v24 = CUtlString::operator char const *(this: &sParam1);
    v25 = CUtlString::operator char const *(this: &sParam1);
    PrintToBuf(
      buf: this->m_pBufALUCode,
      pFormat: "%s = clamp( %s, %s, %s );\n",
      v25,
      v24,
      g_szVecZeros[NumSwizzleComponents],
      g_szVecOnes[NumSwizzleComponents]);
  }
  sParam3.m_Storage.m_nActualLength = 0;
  if ( sParam3.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam3.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam3.m_Storage.m_Memory.m_pMemory);
      sParam3.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam3.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam2.m_Storage.m_nActualLength = 0;
  if ( sParam2.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParam2.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam2.m_Storage.m_Memory.m_pMemory);
      sParam2.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParam2.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sParam1.m_Storage.m_nActualLength = 0;
  if ( sParam1.m_Storage.m_Memory.m_nGrowSize >= 0 && sParam1.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParam1.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10005460
// Name: private: void D3DToGL::Handle_NRM(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall D3DToGL::Handle_NRM(D3DToGL *this)
{
  unsigned int *m_pdwNextToken; // eax
  unsigned int v3; // ecx
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  const char *v6; // eax
  CUtlBuffer *m_pBufALUCode; // eax
  char pDestReg[64]; // [esp+4h] [ebp-90h] BYREF
  char pSrc0Reg[64]; // [esp+44h] [ebp-50h] BYREF
  CUtlString sSrc; // [esp+84h] [ebp-10h] BYREF

  m_pdwNextToken = this->m_pdwNextToken;
  v3 = *m_pdwNextToken;
  this->m_pdwNextToken = m_pdwNextToken + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v3,
    dwSourceOrDest: 0,
    pRegisterName: pDestReg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  v4 = this->m_pdwNextToken;
  v5 = *v4;
  this->m_pdwNextToken = v4 + 1;
  D3DToGL::PrintParameterToString(
    this,
    dwToken: v5,
    dwSourceOrDest: 1u,
    pRegisterName: pSrc0Reg,
    nBufLen: 0x40u,
    bForceScalarSource: false);
  if ( this->m_bGLSL )
  {
    EnsureNumSwizzleComponents(result: &sSrc, pStr: pSrc0Reg, nComponents: 3);
    v6 = CUtlString::operator char const *(this: &sSrc);
    PrintToBuf(buf: this->m_pBufALUCode, pFormat: "%s = normalize( %s );\n", pDestReg, v6);
    sSrc.m_Storage.m_nActualLength = 0;
    if ( sSrc.m_Storage.m_Memory.m_nGrowSize >= 0 && sSrc.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sSrc.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    m_pBufALUCode = this->m_pBufALUCode;
    this->m_bNeedsNRMTemp = true;
    strcat_s(
      _Dst: (char *)m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: "DP3 NRM_TEMP.w, ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc0Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc0Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ";\nRSQ NRM_TEMP.w, NRM_TEMP.w;\nMUL");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pDestReg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ", NRM_TEMP.w, ");
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: pSrc0Reg);
    strcat_s(
      _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
      _Src: ";\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005600
// Name: public: int D3DToGL::TranslateShader(unsigned int __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DToGL::TranslateShader(D3DToGL *this, unsigned int *code, char *pDisassembledCode, int nBufLen)
{
  CUtlBuffer *v5; // eax
  unsigned int v6; // edi
  CUtlBuffer *v7; // eax
  CUtlBuffer *v8; // eax
  CUtlBuffer *v9; // eax
  bool *m_bConstantRegisterDefined; // eax
  int i; // ecx
  unsigned int v12; // ebx
  const char *v13; // eax
  char *v14; // eax
  bool v15; // zf
  CUtlBuffer *m_pBufParamCode; // edx
  CUtlBuffer *v17; // edx
  unsigned int *m_pdwNextToken; // eax
  unsigned int v19; // ebx
  unsigned int *v20; // ecx
  unsigned int v21; // eax
  CUtlBuffer *v22; // eax
  unsigned int m_nAllocationCount; // ecx
  char *m_pMemory; // edx
  int v25; // edi
  int v26; // ebx
  int v27; // edi
  int v28; // ebx
  CUtlBuffer *v29; // edi
  CUtlBuffer *m_pBufALUCode; // edi
  char buff[256]; // [esp+Ch] [ebp-160h] BYREF
  char outTexCoordBuff[64]; // [esp+10Ch] [ebp-60h] BYREF
  CUtlString sLine; // [esp+14Ch] [ebp-20h] BYREF
  CUtlString sParamName; // [esp+15Ch] [ebp-10h] BYREF
  char *pTempVarStr; // [esp+178h] [ebp+Ch]

  CUtlString::CUtlString(this: &sLine);
  CUtlString::CUtlString(this: &sParamName);
  v5 = (CUtlBuffer *)operator new(nSize: 0x30u);
  v6 = 0;
  if ( v5 != nullptr )
    v7 = CUtlBuffer::CUtlBuffer(this: v5, growSize: 100, initSize: 10000, nFlags: 1);
  else
    v7 = nullptr;
  this->m_pBufParamCode = v7;
  v8 = (CUtlBuffer *)operator new(nSize: 0x30u);
  if ( v8 != nullptr )
    v9 = CUtlBuffer::CUtlBuffer(this: v8, growSize: 100, initSize: 60000, nFlags: 1);
  else
    v9 = nullptr;
  this->m_pBufALUCode = v9;
  this->m_nAttribCodeBufSize = nBufLen;
  this->m_pAttribCode = pDisassembledCode;
  *pDisassembledCode = 0;
  *this->m_pBufParamCode->m_Memory.m_pMemory = 0;
  *this->m_pBufALUCode->m_Memory.m_pMemory = 0;
  m_bConstantRegisterDefined = this->m_bConstantRegisterDefined;
  for ( i = 512; i != 0; --i )
  {
    *(m_bConstantRegisterDefined - 512) = false;
    *m_bConstantRegisterDefined++ = false;
  }
  *(_WORD *)&this->m_bNeedsD2AddTemp = 0;
  *(_WORD *)&this->m_bNeedsLerpTemp = 0;
  this->m_bDeclareAddressReg = false;
  this->m_bDeclareVSOPos = false;
  this->m_dwTexCoordOutMask = 0;
  this->m_bTangentInputUsed = false;
  this->m_dwTempUsageMask = 0;
  *(_DWORD *)this->m_bOutputColorRegister = 0;
  this->m_dwSamplerTypes[0] = 3;
  this->m_dwSamplerTypes[1] = 3;
  this->m_dwSamplerTypes[2] = 3;
  this->m_dwSamplerTypes[3] = 3;
  this->m_dwSamplerTypes[4] = 3;
  this->m_dwSamplerTypes[5] = 3;
  this->m_dwSamplerTypes[6] = 3;
  this->m_dwSamplerTypes[7] = 3;
  this->m_dwSamplerTypes[8] = 3;
  this->m_dwSamplerTypes[9] = 3;
  this->m_dwSamplerTypes[10] = 3;
  this->m_dwSamplerTypes[11] = 3;
  this->m_dwSamplerTypes[12] = 3;
  this->m_dwSamplerTypes[13] = 3;
  this->m_dwSamplerTypes[14] = 3;
  this->m_dwSamplerTypes[15] = 3;
  this->m_dwSamplerTypes[16] = 3;
  this->m_dwSamplerTypes[17] = 3;
  this->m_dwSamplerTypes[18] = 3;
  this->m_dwSamplerTypes[19] = 3;
  this->m_dwSamplerTypes[20] = 3;
  this->m_dwSamplerTypes[21] = 3;
  this->m_dwSamplerTypes[22] = 3;
  this->m_dwSamplerTypes[23] = 3;
  this->m_dwSamplerTypes[24] = 3;
  this->m_dwSamplerTypes[25] = 3;
  this->m_dwSamplerTypes[26] = 3;
  this->m_dwSamplerTypes[27] = 3;
  this->m_dwSamplerTypes[28] = 3;
  this->m_dwSamplerTypes[29] = 3;
  this->m_dwSamplerTypes[30] = 3;
  this->m_dwSamplerTypes[31] = 3;
  this->m_DeclaredOutputs[0] = -1;
  this->m_DeclaredOutputs[1] = -1;
  this->m_DeclaredOutputs[2] = -1;
  this->m_DeclaredOutputs[3] = -1;
  this->m_DeclaredOutputs[4] = -1;
  this->m_DeclaredOutputs[5] = -1;
  this->m_DeclaredOutputs[6] = -1;
  this->m_DeclaredOutputs[7] = -1;
  this->m_DeclaredOutputs[8] = -1;
  this->m_DeclaredOutputs[9] = -1;
  this->m_DeclaredOutputs[10] = -1;
  this->m_DeclaredOutputs[11] = -1;
  this->m_DeclaredOutputs[12] = -1;
  this->m_DeclaredOutputs[13] = -1;
  this->m_DeclaredOutputs[14] = -1;
  this->m_DeclaredOutputs[15] = -1;
  this->m_DeclaredOutputs[16] = -1;
  this->m_DeclaredOutputs[17] = -1;
  this->m_DeclaredOutputs[18] = -1;
  this->m_DeclaredOutputs[19] = -1;
  this->m_DeclaredOutputs[20] = -1;
  this->m_DeclaredOutputs[21] = -1;
  this->m_DeclaredOutputs[22] = -1;
  this->m_DeclaredOutputs[23] = -1;
  this->m_DeclaredOutputs[24] = -1;
  this->m_DeclaredOutputs[25] = -1;
  this->m_DeclaredOutputs[26] = -1;
  this->m_DeclaredOutputs[27] = -1;
  this->m_DeclaredOutputs[28] = -1;
  this->m_DeclaredOutputs[29] = -1;
  this->m_DeclaredOutputs[30] = -1;
  this->m_DeclaredOutputs[31] = -1;
  this->m_pdwNextToken = code;
  this->m_pdwBaseToken = code;
  v12 = *code;
  this->m_pdwNextToken = code + 1;
  this->m_dwMajorVersion = BYTE1(v12);
  this->m_dwMinorVersion = (unsigned __int8)v12;
  v13 = str;
  if ( (v12 & 0xFFFF0000) == 0xFFFF0000 )
  {
    if ( !this->m_bGLSL )
      v13 = "!!ARBfp1.0\n";
    strcat_s(_Dst: this->m_pAttribCode, _SizeInBytes: this->m_nAttribCodeBufSize, _Src: v13);
    this->m_bVertexShader = false;
  }
  else
  {
    if ( !this->m_bGLSL )
      v13 = "!!ARBvp1.0\n";
    strcat_s(_Dst: this->m_pAttribCode, _SizeInBytes: this->m_nAttribCodeBufSize, _Src: v13);
    this->m_bVertexShader = true;
  }
  v14 = "vs";
  if ( !this->m_bVertexShader )
    v14 = "ps";
  v15 = !this->m_bAddHexCodeComments;
  this->m_pVSPSConstantPrefix = v14;
  if ( !v15 )
  {
    m_pBufParamCode = this->m_pBufParamCode;
    this->m_pRecordedInputTokenStart = this->m_pdwNextToken;
    this->m_nRecordedParamCodeStrlen = strlen((const char *)m_pBufParamCode->m_Memory.m_pMemory);
    this->m_nRecordedALUCodeStrlen = strlen((const char *)this->m_pBufALUCode->m_Memory.m_pMemory);
    this->m_nRecordedAttribCodeStrlen = strlen(this->m_pAttribCode);
  }
  if ( v12 != 0xFFFF )
  {
    do
    {
      if ( this->m_bAddHexCodeComments )
      {
        if ( this->m_pdwNextToken > this->m_pRecordedInputTokenStart )
        {
          D3DToGL::AddTokenHexCodeToBuffer(
            this,
            pBuffer: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
            nSize: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
            nLastStrlen: this->m_nRecordedParamCodeStrlen);
          D3DToGL::AddTokenHexCodeToBuffer(
            this,
            pBuffer: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
            nSize: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
            nLastStrlen: this->m_nRecordedALUCodeStrlen);
          D3DToGL::AddTokenHexCodeToBuffer(
            this,
            pBuffer: this->m_pAttribCode,
            nSize: this->m_nAttribCodeBufSize,
            nLastStrlen: this->m_nRecordedAttribCodeStrlen);
        }
        v17 = this->m_pBufParamCode;
        this->m_pRecordedInputTokenStart = this->m_pdwNextToken;
        this->m_nRecordedParamCodeStrlen = strlen((const char *)v17->m_Memory.m_pMemory);
        this->m_nRecordedALUCodeStrlen = strlen((const char *)this->m_pBufALUCode->m_Memory.m_pMemory);
        this->m_nRecordedAttribCodeStrlen = strlen(this->m_pAttribCode);
      }
      m_pdwNextToken = this->m_pdwNextToken;
      v19 = *m_pdwNextToken;
      v20 = m_pdwNextToken + 1;
      v21 = (unsigned __int16)*m_pdwNextToken;
      this->m_pdwNextToken = v20;
      if ( v21 > 0xFFFD )
      {
        if ( v21 == 65534 )
          this->m_pdwNextToken = &v20[HIWORD(v19) & 0xFFF];
      }
      else if ( v21 == 65533 )
      {
$LN64:
        D3DToGL::PrintOpcode(this, inst: v21, buff, nBufLen: 256);
        strcat_s(
          _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
          _Src: buff);
        strcat_s(
          _Dst: (char *)this->m_pBufALUCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufALUCode->m_Memory.m_nAllocationCount,
          _Src: ";\n");
      }
      else
      {
        switch ( v21 )
        {
          case 0u:
          case 0x1Cu:
          case 0x1Du:
          case 0x27u:
          case 0x2Au:
          case 0x2Bu:
          case 0x2Cu:
            goto $LN64;
          case 1u:
          case 6u:
          case 7u:
          case 0xEu:
          case 0xFu:
          case 0x10u:
          case 0x13u:
          case 0x23u:
          case 0x2Eu:
          case 0x4Eu:
          case 0x4Fu:
            D3DToGL::Handle_SimpleInstruction(this, nInstruction: v21);
            break;
          case 2u:
          case 3u:
          case 5u:
          case 8u:
          case 9u:
          case 0xAu:
          case 0xBu:
          case 0xCu:
          case 0xDu:
          case 0x11u:
          case 0x20u:
          case 0x21u:
            if ( this->m_bGLSL )
              D3DToGL::HandleBinaryOp_GLSL(this, nInstruction: v21);
            else
              D3DToGL::HandleBinaryOp_ASM(this, nInstruction: v21);
            break;
          case 4u:
            D3DToGL::Handle_MAD(this, nInstruction: 4u);
            break;
          case 0x12u:
            D3DToGL::Handle_LRP(this, nInstruction: 0x12u);
            break;
          case 0x1Fu:
            D3DToGL::Handle_DCL(this);
            break;
          case 0x24u:
            D3DToGL::Handle_NRM(this);
            break;
          case 0x25u:
            D3DToGL::Handle_SINCOS(this);
            break;
          case 0x40u:
            D3DToGL::Handle_TexCoord(this);
            break;
          case 0x41u:
          case 0x57u:
            D3DToGL::Handle_DeclarativeNonDclOp(this, nInstruction: v21);
            break;
          case 0x42u:
            D3DToGL::Handle_TEX(this, dwToken: v19, bIsTexLDL: false);
            break;
          case 0x51u:
            D3DToGL::Handle_DEF(this);
            break;
          case 0x58u:
            D3DToGL::Handle_CMP(this);
            break;
          case 0x5Au:
            D3DToGL::Handle_DP2ADD(this);
            break;
          case 0x5Du:
            D3DToGL::Handle_TexLDD(this, nInstruction: 0x5Du);
            break;
          case 0x5Fu:
            D3DToGL::Handle_TEX(this, dwToken: 0x5Fu, bIsTexLDL: true);
            break;
          default:
            break;
        }
      }
    }
    while ( v19 != 0xFFFF );
  }
  if ( this->m_bNeedsSinCosDeclarations )
  {
    strcat_s(
      _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
      _Src: "PARAM scA = { 1.55e-6, 2.17e-5, 0.0026042, 2.6e-4 };\n");
    strcat_s(
      _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
      _Src: "PARAM scB = { 0.02083, 0.0625, 1.0, 0.5 };\n");
  }
  if ( this->m_bGLSL )
  {
    do
    {
      if ( this->m_bConstantRegisterReferenced[v6] )
        PrintToBuf(buf: this->m_pBufParamCode, pFormat: "uniform vec4 %s_c%d;\n", this->m_pVSPSConstantPrefix, v6);
      ++v6;
    }
    while ( v6 < 0x200 );
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "\n\n");
    D3DToGL::WriteGLSLSamplerDefinitions(this);
  }
  else
  {
    v22 = this->m_pBufParamCode;
    m_nAllocationCount = v22->m_Memory.m_nAllocationCount;
    m_pMemory = (char *)v22->m_Memory.m_pMemory;
    if ( this->m_bVertexShader )
      strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "PARAM c[256] = { program.local[0..255] };\n");
    else
      strcat_s(_Dst: m_pMemory, _SizeInBytes: m_nAllocationCount, _Src: "PARAM c[32] = { program.local[0..31] };\n");
  }
  if ( this->m_bDeclareAddressReg )
    strcat_s(
      _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
      _Src: "ADDRESS a0;\n");
  pTempVarStr = "TEMP";
  if ( this->m_bGLSL )
    pTempVarStr = "vec4 ";
  v25 = 0;
  v26 = 1;
  do
  {
    if ( (v26 & this->m_dwTempUsageMask) != 0 )
      PrintToBuf(buf: this->m_pBufParamCode, pFormat: "%s r%d;\n", pTempVarStr, v25);
    ++v25;
    v26 = __ROL4__(v26, 1);
  }
  while ( v25 < 32 );
  if ( this->m_bNeedsSinCosDeclarations )
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "%s SC_TEMP;\n", pTempVarStr);
  if ( this->m_bNeedsD2AddTemp )
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "%s DP2A0;\n%s DP2A1;\n", pTempVarStr, pTempVarStr);
  if ( this->m_bNeedsLerpTemp )
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "%s LRP_TEMP;\n", pTempVarStr);
  if ( this->m_bNeedsNRMTemp )
    PrintToBuf(buf: this->m_pBufParamCode, pFormat: "%s NRM_TEMP;\n", pTempVarStr);
  if ( !this->m_bGLSL )
  {
    if ( !this->m_bVertexShader )
    {
      if ( this->m_bOutputColorRegister[1] )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "TEMP oC1;\n");
      if ( this->m_bOutputDepthRegister )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "TEMP oC2;\n");
      if ( this->m_bUsedAtomicTempVar )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "TEMP oC3;\n");
      if ( this->m_bOutputColorRegister[0] )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "OUTPUT oC0 = result.color;\n");
    }
    if ( !this->m_bGLSL )
    {
      if ( this->m_bDeclareVSOPos && this->m_bVertexShader )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "OUTPUT oPos = result.position;\n");
      v27 = 0;
      v28 = 1;
      do
      {
        if ( (v28 & this->m_dwTexCoordOutMask) != 0 )
        {
          V_snprintf(pDest: outTexCoordBuff, maxLen: 64, pFormat: "OUTPUT oT%d = result.texcoord[%d];\n", v27, v27);
          strcat_s(
            _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
            _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
            _Src: outTexCoordBuff);
        }
        ++v27;
        v28 = __ROL4__(v28, 1);
      }
      while ( v27 < 32 );
      if ( this->m_bOutputColorRegister[0] && this->m_bVertexShader )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "OUTPUT oD0 = result.color;\n");
      if ( this->m_bOutputColorRegister[1] && this->m_bVertexShader )
        strcat_s(
          _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
          _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
          _Src: "OUTPUT oD1 = result.color.secondary;\n");
    }
  }
  if ( this->m_bOutputDepthRegister && !this->m_bVertexShader )
    strcat_s(
      _Dst: (char *)this->m_pBufParamCode->m_Memory.m_pMemory,
      _SizeInBytes: this->m_pBufParamCode->m_Memory.m_nAllocationCount,
      _Src: "OUTPUT oDepth = result.depth;\n");
  strcat_s(
    _Dst: this->m_pAttribCode,
    _SizeInBytes: this->m_nAttribCodeBufSize,
    _Src: (const char *)this->m_pBufParamCode->m_Memory.m_pMemory);
  if ( this->m_bGLSL )
  {
    strcat_s(_Dst: this->m_pAttribCode, _SizeInBytes: this->m_nAttribCodeBufSize, _Src: "void main()\n{\n\n");
    if ( this->m_bUsedAtomicTempVar )
      PrintToBuf(
        pOut: this->m_pAttribCode,
        nOutSize: this->m_nAttribCodeBufSize,
        pFormat: "vec4 %s;\n\n",
        g_pAtomicTempVarName);
  }
  else
  {
    strcat_s(_Dst: this->m_pAttribCode, _SizeInBytes: this->m_nAttribCodeBufSize, _Src: "// --- ALU CODE --- //");
  }
  strcat_s(
    _Dst: this->m_pAttribCode,
    _SizeInBytes: this->m_nAttribCodeBufSize,
    _Src: (const char *)this->m_pBufALUCode->m_Memory.m_pMemory);
  if ( this->m_bGLSL )
  {
    D3DToGL::WriteGLSLOutputVariableAssignments(this);
    strcat_s(_Dst: this->m_pAttribCode, _SizeInBytes: this->m_nAttribCodeBufSize, _Src: "\n}\n");
  }
  else if ( this->m_bIncludeEndStatement )
  {
    strcat_s(_Dst: this->m_pAttribCode, _SizeInBytes: this->m_nAttribCodeBufSize, _Src: "END\n");
  }
  v29 = this->m_pBufParamCode;
  if ( v29 != nullptr )
  {
    if ( v29->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v29->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29->m_Memory.m_pMemory);
        v29->m_Memory.m_pMemory = nullptr;
      }
      v29->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v29);
  }
  m_pBufALUCode = this->m_pBufALUCode;
  if ( m_pBufALUCode != nullptr )
  {
    if ( m_pBufALUCode->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pBufALUCode->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pBufALUCode->m_Memory.m_pMemory);
        m_pBufALUCode->m_Memory.m_pMemory = nullptr;
      }
      m_pBufALUCode->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: m_pBufALUCode);
  }
  this->m_pBufALUCode = nullptr;
  this->m_pBufParamCode = nullptr;
  sParamName.m_Storage.m_nActualLength = 0;
  if ( sParamName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( sParamName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sParamName.m_Storage.m_Memory.m_pMemory);
      sParamName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    sParamName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  sLine.m_Storage.m_nActualLength = 0;
  if ( sLine.m_Storage.m_Memory.m_nGrowSize >= 0 && sLine.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sLine.m_Storage.m_Memory.m_pMemory);
  return 0;
}
