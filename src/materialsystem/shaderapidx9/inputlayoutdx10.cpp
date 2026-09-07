// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/inputlayoutdx10.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10003870
// Name: CheckShaderSignatureExpectations
// Source: json
//------------------------------------------------------------------------------
char __usercall CheckShaderSignatureExpectations@<al>(
        ID3D10ShaderReflection *pReflection@<esi>,
        const char *pSemantic,
        unsigned int nSemanticIndex)
{
  unsigned int v3; // edi
  _D3D10_SIGNATURE_PARAMETER_DESC paramDesc; // [esp+10h] [ebp-8Ch] BYREF
  _D3D10_SHADER_DESC shaderDesc; // [esp+28h] [ebp-74h] BYREF

  pReflection->GetDesc(this: pReflection, a2: (_D3D10_SHADER_DESC *)&shaderDesc.Creator);
  v3 = 0;
  if ( shaderDesc.OutputParameters == 0 )
    return 0;
  while ( 1 )
  {
    pReflection->GetInputParameterDesc(
      this: pReflection,
      a2: v3,
      a3: (_D3D10_SIGNATURE_PARAMETER_DESC *)&paramDesc.SemanticIndex);
    if ( nSemanticIndex == paramDesc.Register
      && _V_stricmp(s1: pSemantic, s2: (const char *)paramDesc.SemanticIndex) == 0 )
    {
      break;
    }
    if ( ++v3 >= shaderDesc.OutputParameters )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100038F0
// Name: ComputeInputDesc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeInputDesc(
        unsigned __int64 fmt,
        D3D10_INPUT_ELEMENT_DESC *pDecl,
        ID3D10ShaderReflection *pReflection)
{
  DXGI_FORMAT v4; // edx
  DXGI_FORMAT v5; // edx
  DXGI_FORMAT v6; // edx
  int v7; // ecx
  int v9; // eax
  char v10; // al
  int nOffset; // [esp+Ch] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  FieldInfo_t *v15; // [esp+18h] [ebp-4h]
  int fmta; // [esp+20h] [ebp+4h]

  s_pFieldInfo[1].m_nFieldSize = 4 * ((fmt >> 12) & 7);
  s_pVertexDesc[1].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[1].m_nFieldSize);
  v4 = s_pSizeLookup[(fmt >> 15) & 7];
  s_pFieldInfo[16].m_nFieldSize = 4 * ((fmt >> 15) & 7);
  s_pVertexDesc[16].Format = v4;
  s_pFieldInfo[6].m_nFieldSize = 4 * ((fmt >> 18) & 7);
  s_pVertexDesc[6].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[6].m_nFieldSize);
  v5 = s_pSizeLookup[(fmt >> 21) & 7];
  s_pFieldInfo[7].m_nFieldSize = 4 * ((fmt >> 21) & 7);
  s_pVertexDesc[7].Format = v5;
  s_pFieldInfo[8].m_nFieldSize = 4 * (BYTE3(fmt) & 7);
  s_pVertexDesc[8].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[8].m_nFieldSize);
  v6 = s_pSizeLookup[(fmt >> 27) & 7];
  s_pFieldInfo[9].m_nFieldSize = 4 * ((fmt >> 27) & 7);
  s_pVertexDesc[9].Format = v6;
  v7 = 0;
  nOffset = 0;
  i = 0;
  s_pFieldInfo[10].m_nFieldSize = 4 * ((fmt >> 30) & 7);
  s_pVertexDesc[10].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[10].m_nFieldSize);
  s_pFieldInfo[11].m_nFieldSize = 4 * ((HIDWORD(fmt) >> 1) & 7);
  s_pVertexDesc[11].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[11].m_nFieldSize);
  s_pFieldInfo[12].m_nFieldSize = 4 * ((HIDWORD(fmt) >> 4) & 7);
  s_pVertexDesc[12].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[12].m_nFieldSize);
  s_pFieldInfo[13].m_nFieldSize = 4 * ((HIDWORD(fmt) >> 7) & 7);
  s_pVertexDesc[13].Format = *(const DXGI_FORMAT *)((char *)s_pSizeLookup + s_pFieldInfo[13].m_nFieldSize);
  v14 = 0;
  if ( s_pFieldInfo[0].m_pSemanticString != nullptr )
  {
    v9 = 0;
    v15 = s_pFieldInfo;
    fmta = 0;
    while ( (HIDWORD(fmt) & HIDWORD(s_pFieldInfo[v9].m_nFormatMask) | (unsigned int)fmt & s_pFieldInfo[v9].m_nFormatMask) == 0 )
    {
      v10 = CheckShaderSignatureExpectations(
              pReflection,
              pSemantic: v15->m_pSemanticString,
              nSemanticIndex: s_pFieldInfo[v9].m_nSemanticIndex);
      v7 = fmta;
      if ( v10 != 0 )
      {
        *(_QWORD *)&pDecl->SemanticName = *(_QWORD *)((char *)&s_pFallbackVertexDesc[0].SemanticName + fmta);
        *(_QWORD *)&pDecl->Format = *(_QWORD *)((char *)&s_pFallbackVertexDesc[0].Format + fmta);
        *(_QWORD *)&pDecl->AlignedByteOffset = *(_QWORD *)((char *)&s_pFallbackVertexDesc[0].AlignedByteOffset + fmta);
        pDecl->InstanceDataStepRate = *(unsigned int *)((char *)&s_pFallbackVertexDesc[0].InstanceDataStepRate + fmta);
        goto LABEL_7;
      }
LABEL_8:
      v9 = ++v14;
      v7 += 28;
      fmta = v7;
      v15 = &s_pFieldInfo[v14];
      if ( v15->m_pSemanticString == nullptr )
        return nOffset;
    }
    *(_QWORD *)&pDecl->SemanticName = *(_QWORD *)((char *)&s_pVertexDesc[0].SemanticName + v7);
    *(_QWORD *)&pDecl->Format = *(_QWORD *)((char *)&s_pVertexDesc[0].Format + v7);
    *(_QWORD *)&pDecl->AlignedByteOffset = *(_QWORD *)((char *)&s_pVertexDesc[0].AlignedByteOffset + v7);
    pDecl->InstanceDataStepRate = *(unsigned int *)((char *)&s_pVertexDesc[0].InstanceDataStepRate + v7);
    pDecl->AlignedByteOffset = i;
    i += s_pFieldInfo[v9].m_nFieldSize;
LABEL_7:
    ++nOffset;
    ++pDecl;
    goto LABEL_8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10003B90
// Name: struct ID3D10InputLayout __near * CreateInputLayout(unsigned __int64,struct ID3D10ShaderReflection __near *,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ID3D10InputLayout *__cdecl CreateInputLayout(
        unsigned __int64 fmt,
        ID3D10ShaderReflection *pReflection,
        const void *pByteCode,
        unsigned int nByteCodeLen)
{
  unsigned int v4; // eax
  D3D10_INPUT_ELEMENT_DESC pDecl[32]; // [esp+18h] [ebp-384h] BYREF

  v4 = ComputeInputDesc(fmt, pDecl: (D3D10_INPUT_ELEMENT_DESC *)&pDecl[0].SemanticIndex, pReflection);
  if ( g_pShaderDeviceDx10->m_pDevice->CreateInputLayout(
         this: g_pShaderDeviceDx10->m_pDevice,
         a2: (const D3D10_INPUT_ELEMENT_DESC *)&pDecl[0].SemanticIndex,
         a3: v4,
         a4: pByteCode,
         a5: nByteCodeLen,
         a6: (ID3D10InputLayout **)pDecl) >= 0 )
    return (ID3D10InputLayout *)pDecl[0].SemanticName;
  _Warning(a1: "CreateInputLayout::Unable to create input layout for format %X!\n", (_DWORD)fmt);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003C20
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10003C50
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x10003C70
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10003CB0
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10003CD0
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003CE0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
