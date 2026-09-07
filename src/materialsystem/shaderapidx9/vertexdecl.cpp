// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/vertexdecl.cpp
// Functions: 33
// ============================================================

#include "materialsystem\shaderapidx9\vertexdecl.h"

//------------------------------------------------------------------------------
// Address: 0x1002C4C0
// Name: VertexElementToDeclType
// Source: json
//------------------------------------------------------------------------------
_D3DDECLTYPE __cdecl VertexElementToDeclType(VertexCompressionType_t compressionType)
{
  VertexElement_t element; // ecx
  _D3DDECLTYPE result; // eax

  if ( compressionType == VERTEX_COMPRESSION_ON )
  {
    switch ( element )
    {
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_USERDATA4:
        result = D3DDECLTYPE_UBYTE4;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_BONEWEIGHTS2:
        result = D3DDECLTYPE_SHORT2;
        break;
      default:
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    switch ( element )
    {
      case VERTEX_ELEMENT_POSITION:
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_TANGENT_S:
      case VERTEX_ELEMENT_TANGENT_T:
      case VERTEX_ELEMENT_BONEWEIGHTS3:
      case VERTEX_ELEMENT_USERDATA3:
      case VERTEX_ELEMENT_TEXCOORD3D_0:
      case VERTEX_ELEMENT_TEXCOORD3D_1:
      case VERTEX_ELEMENT_TEXCOORD3D_2:
      case VERTEX_ELEMENT_TEXCOORD3D_3:
      case VERTEX_ELEMENT_TEXCOORD3D_4:
      case VERTEX_ELEMENT_TEXCOORD3D_5:
      case VERTEX_ELEMENT_TEXCOORD3D_6:
      case VERTEX_ELEMENT_TEXCOORD3D_7:
        result = D3DDECLTYPE_FLOAT3;
        break;
      case VERTEX_ELEMENT_POSITION4D:
      case VERTEX_ELEMENT_NORMAL4D:
      case VERTEX_ELEMENT_BONEWEIGHTS4:
      case VERTEX_ELEMENT_USERDATA4:
      case VERTEX_ELEMENT_TEXCOORD4D_0:
      case VERTEX_ELEMENT_TEXCOORD4D_1:
      case VERTEX_ELEMENT_TEXCOORD4D_2:
      case VERTEX_ELEMENT_TEXCOORD4D_3:
      case VERTEX_ELEMENT_TEXCOORD4D_4:
      case VERTEX_ELEMENT_TEXCOORD4D_5:
      case VERTEX_ELEMENT_TEXCOORD4D_6:
      case VERTEX_ELEMENT_TEXCOORD4D_7:
        result = D3DDECLTYPE_FLOAT4;
        break;
      case VERTEX_ELEMENT_COLOR:
      case VERTEX_ELEMENT_SPECULAR:
      case VERTEX_ELEMENT_BONEINDEX:
        result = D3DDECLTYPE_D3DCOLOR;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_USERDATA1:
      case VERTEX_ELEMENT_TEXCOORD1D_0:
      case VERTEX_ELEMENT_TEXCOORD1D_1:
      case VERTEX_ELEMENT_TEXCOORD1D_2:
      case VERTEX_ELEMENT_TEXCOORD1D_3:
      case VERTEX_ELEMENT_TEXCOORD1D_4:
      case VERTEX_ELEMENT_TEXCOORD1D_5:
      case VERTEX_ELEMENT_TEXCOORD1D_6:
      case VERTEX_ELEMENT_TEXCOORD1D_7:
        result = D3DDECLTYPE_FLOAT1;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS2:
      case VERTEX_ELEMENT_USERDATA2:
      case VERTEX_ELEMENT_TEXCOORD2D_0:
      case VERTEX_ELEMENT_TEXCOORD2D_1:
      case VERTEX_ELEMENT_TEXCOORD2D_2:
      case VERTEX_ELEMENT_TEXCOORD2D_3:
      case VERTEX_ELEMENT_TEXCOORD2D_4:
      case VERTEX_ELEMENT_TEXCOORD2D_5:
      case VERTEX_ELEMENT_TEXCOORD2D_6:
      case VERTEX_ELEMENT_TEXCOORD2D_7:
        result = D3DDECLTYPE_FLOAT2;
        break;
      default:
        result = D3DDECLTYPE_UNUSED;
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002C610
// Name: void ComputeVertexSpec(unsigned __int64,struct _D3DVERTEXELEMENT9 __near *,bool,bool,bool,bool,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeVertexSpec(
        unsigned __int64 fmt,
        _D3DVERTEXELEMENT9 *pDecl,
        bool bStaticLit,
        bool bUsingFlex,
        bool bUsingMorph,
        __int16 bUsingPreTessPatch,
        VertexStreamSpec_t *pStreamSpec)
{
  unsigned int v7; // ecx
  int v8; // esi
  int v9; // edx
  int v10; // ecx
  _D3DVERTEXELEMENT9 *v11; // ebx
  unsigned __int16 v12; // di
  VertexCompressionType_t v13; // edx
  VertexElement_t v14; // ecx
  unsigned __int16 VertexElementSize; // ax
  VertexCompressionType_t v16; // edx
  VertexElement_t v17; // ecx
  __int16 v18; // ax
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  __int16 v22; // ax
  unsigned __int16 v23; // cx
  unsigned __int16 v24; // di
  VertexCompressionType_t v25; // edx
  VertexElement_t v26; // ecx
  unsigned __int8 *p_Method; // ecx
  int v28; // eax
  VertexStreamSpec_t *v29; // eax
  int v30; // ebx
  int k; // edi
  int v32; // ebx
  unsigned __int8 v33; // al
  __int16 v34; // ax
  bool v35; // zf
  bool v36; // cl
  __int16 v37; // ax
  int v38; // esi
  VertexStreamSpec_t *v39; // eax
  unsigned int v40; // edi
  int v41; // ebx
  int m; // esi
  int v43; // edx
  int v44; // ebx
  unsigned __int8 v45; // al
  __int16 v46; // ax
  unsigned int iVertexDataElement_high; // [esp+20h] [ebp-24h]
  __int16 pSpecEntry; // [esp+24h] [ebp-20h]
  int pSpecEntrya; // [esp+24h] [ebp-20h]
  VertexStreamSpec_t *pSpecEntryb; // [esp+24h] [ebp-20h]
  VertexStreamSpec_t *pSpecEntryc; // [esp+24h] [ebp-20h]
  unsigned __int64 iVertexDataElement; // [esp+28h] [ebp-1Ch]
  unsigned __int8 *iColorSemanticSlot; // [esp+2Ch] [ebp-18h]
  unsigned __int8 nCoordSize; // [esp+30h] [ebp-14h]
  unsigned __int8 j; // [esp+34h] [ebp-10h]
  __int16 ja; // [esp+34h] [ebp-10h]
  unsigned __int16 jb; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  int ia; // [esp+38h] [ebp-Ch]
  VertexStreamSpec_t *iUniqueStreamSpec; // [esp+3Ch] [ebp-8h]
  int iUniqueStreamSpeca; // [esp+3Ch] [ebp-8h]
  VertexCompressionType_t compressionType; // [esp+40h] [ebp-4h]
  unsigned __int16 offset; // [esp+64h] [ebp+20h]
  unsigned __int16 offseta; // [esp+64h] [ebp+20h]
  int offsetb; // [esp+64h] [ebp+20h]
  unsigned __int16 offsetc; // [esp+64h] [ebp+20h]

  v7 = fmt;
  v8 = 0;
  compressionType = (fmt & 0x400) != 0;
  if ( (_BYTE)bUsingPreTessPatch != 0 )
  {
    pDecl->Type = 1;
    v9 = *(_DWORD *)&declEnd_0.Type;
    *(_DWORD *)&pDecl->Stream = 0;
    *(_WORD *)&pDecl->Method = 0;
    pDecl->UsageIndex = 0;
    pDecl[1].UsageIndex = 0;
    *(_DWORD *)&pDecl[1].Stream = 0x80000;
    *(_WORD *)&pDecl[1].Method = 1280;
    pDecl[1].Type = 3;
    *(_DWORD *)&pDecl[2].Stream = 1572864;
    *(_WORD *)&pDecl[2].Method = 1280;
    pDecl[2].UsageIndex = 1;
    pDecl[2].Type = 3;
    *(_WORD *)&pDecl[3].Method = 0;
    *(_DWORD *)&pDecl[3].Stream = 8;
    pDecl[3].UsageIndex = 1;
    pDecl[3].Type = 3;
    *(_DWORD *)&pDecl[4].Stream = 1048584;
    *(_WORD *)&pDecl[4].Method = 1280;
    pDecl[4].UsageIndex = 2;
    pDecl[4].Type = 3;
    *(_DWORD *)&pDecl[5].Stream = 2097160;
    *(_WORD *)&pDecl[5].Method = 1280;
    pDecl[5].UsageIndex = 3;
    pDecl[5].Type = 3;
    *(_WORD *)&pDecl[6].Method = 0;
    *(_DWORD *)&pDecl[6].Stream = 3145736;
    pDecl[6].UsageIndex = 2;
    pDecl[6].Type = 3;
    *(_DWORD *)&pDecl[7].Stream = 4194312;
    *(_WORD *)&pDecl[7].Method = 1280;
    pDecl[7].UsageIndex = 4;
    pDecl[7].Type = 3;
    *(_DWORD *)&pDecl[8].Stream = 5242888;
    *(_WORD *)&pDecl[8].Method = 1280;
    pDecl[8].UsageIndex = 5;
    pDecl[8].Type = 3;
    *(_WORD *)&pDecl[9].Method = 0;
    *(_DWORD *)&pDecl[9].Stream = 6291464;
    pDecl[9].UsageIndex = 3;
    pDecl[9].Type = 3;
    *(_DWORD *)&pDecl[10].Stream = 7340040;
    *(_WORD *)&pDecl[10].Method = 1280;
    pDecl[10].UsageIndex = 6;
    pDecl[10].Type = 3;
    *(_DWORD *)&pDecl[11].Stream = 8388616;
    *(_WORD *)&pDecl[11].Method = 1280;
    pDecl[11].UsageIndex = 7;
    pDecl[11].Type = 3;
    *(_WORD *)&pDecl[12].Method = 0;
    *(_DWORD *)&pDecl[12].Stream = 9437192;
    pDecl[12].UsageIndex = 4;
    pDecl[12].Type = 3;
    *(_DWORD *)&pDecl[13].Stream = 10485768;
    *(_WORD *)&pDecl[13].Method = 1280;
    pDecl[13].UsageIndex = 8;
    pDecl[13].Type = 3;
    *(_DWORD *)&pDecl[14].Stream = 11534344;
    *(_WORD *)&pDecl[14].Method = 1280;
    pDecl[14].UsageIndex = 9;
    pDecl[14].Type = 3;
    pDecl[15].Type = 0;
    v10 = *(_DWORD *)&declEnd_0.Stream;
    *(_DWORD *)&pDecl[15].Stream = 3;
    *(_WORD *)&pDecl[15].Method = 1280;
    pDecl[15].UsageIndex = 10;
    *(_DWORD *)&pDecl[16].Stream = v10;
    *(_DWORD *)&pDecl[16].Type = v9;
  }
  else
  {
    v11 = pDecl;
    v12 = 0;
    offset = 0;
    if ( (fmt & 1) != 0 )
    {
      pDecl->Stream = 0;
      pDecl->Offset = 0;
      *(_WORD *)&pDecl->Method = 0;
      pDecl->UsageIndex = 0;
      pDecl->Type = VertexElementToDeclType(compressionType);
      VertexElementSize = GetVertexElementSize(element: v14, compressionType: v13);
      v7 = fmt;
      v12 = VertexElementSize;
      offset = VertexElementSize;
      v8 = 1;
    }
    if ( ((__PAIR64__(HIDWORD(fmt), v7) >> 12) & 7) != 0 )
    {
      pDecl[v8].Stream = 0;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8].Type = compressionType != VERTEX_COMPRESSION_ON ? 1 : 6;
      pDecl[v8].Offset = v12;
      *(_WORD *)&pDecl[v8].Method = 256;
      v12 += 4 * (compressionType != VERTEX_COMPRESSION_ON) + 4;
      offset = v12;
      ++v8;
    }
    if ( (v7 & 0x80) != 0 )
    {
      pDecl[v8].Offset = v12;
      v12 += 4;
      pDecl[v8].Stream = 0;
      *(_WORD *)&pDecl[v8].Method = 512;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8].Type = 4;
      offset = v12;
      ++v8;
    }
    pSpecEntry = -1;
    if ( (v7 & 2) != 0 )
    {
      pDecl[v8].Stream = 0;
      pDecl[v8].Offset = v12;
      pSpecEntry = v12;
      *(_WORD *)&pDecl[v8].Method = 768;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8].Type = VertexElementToDeclType(compressionType);
      v18 = GetVertexElementSize(element: v17, compressionType: v16);
      LOBYTE(v7) = fmt;
      v12 += v18;
      offset = v12;
      ++v8;
    }
    if ( (v7 & 4) != 0 )
    {
      pDecl[v8].Offset = v12;
      v12 += 4;
      pDecl[v8].Stream = 0;
      *(_WORD *)&pDecl[v8].Method = 2560;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8].Type = 4;
      offset = v12;
      ++v8;
    }
    if ( (v7 & 8) != 0 )
    {
      pDecl[v8].Offset = v12;
      pDecl[v8].Stream = 0;
      *(_WORD *)&pDecl[v8].Method = 2560;
      pDecl[v8].UsageIndex = 1;
      pDecl[v8].Type = 4;
      offset = v12 + 4;
      ++v8;
    }
    j = 0;
    i = 18;
    iColorSemanticSlot = &pDecl[v8].Method;
    do
    {
      v19 = (fmt >> i) & 7;
      if ( v19 != 0 )
      {
        iUniqueStreamSpec = pStreamSpec;
        if ( pStreamSpec != nullptr )
        {
          while ( iUniqueStreamSpec->iVertexDataElement != 0 )
          {
            if ( iUniqueStreamSpec->iVertexDataElement == (__int64)v19 << i )
            {
              if ( iUniqueStreamSpec->iStreamSpec != STREAM_DEFAULT )
                goto LABEL_32;
              break;
            }
            if ( ++iUniqueStreamSpec == nullptr )
              break;
          }
        }
        *(_WORD *)(iColorSemanticSlot - 3) = offset;
        *(_WORD *)(iColorSemanticSlot - 5) = 0;
        *(_WORD *)iColorSemanticSlot = 1280;
        iColorSemanticSlot[2] = j;
        *(iColorSemanticSlot - 1) = VertexElementToDeclType(compressionType);
        if ( v21 == 1 )
        {
          switch ( v20 )
          {
            case 2:
            case 10:
            case 11:
$LN1068:
              v22 = 4;
              break;
            case 17:
$LN1012:
              v22 = 0;
              break;
            default:
              goto LABEL_26;
          }
        }
        else
        {
LABEL_26:
          switch ( v20 )
          {
            case 0:
            case 2:
            case 6:
            case 7:
            case 12:
            case 16:
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
              v22 = 12;
              break;
            case 1:
            case 3:
            case 13:
            case 17:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
              v22 = 16;
              break;
            case 4:
            case 5:
            case 8:
            case 9:
            case 10:
            case 14:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
              goto $LN1068;
            case 11:
            case 15:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
            case 33:
              v22 = 8;
              break;
            default:
              goto $LN1012;
          }
        }
        offset += v22;
        ++v8;
        iColorSemanticSlot += 8;
      }
LABEL_32:
      ++j;
      i += 3;
    }
    while ( i < 42 );
    v23 = offset;
    if ( (fmt & 0x10) != 0 )
    {
      pDecl[v8].Offset = offset;
      pDecl[v8].Stream = 0;
      *(_WORD *)&pDecl[v8].Method = 1536;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8].Type = 2;
      v23 = offset + 12;
      ++v8;
    }
    if ( (fmt & 0x20) != 0 )
    {
      pDecl[v8].Offset = v23;
      pDecl[v8].Stream = 0;
      *(_WORD *)&pDecl[v8].Method = 1792;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8].Type = 2;
      v23 += 12;
      ++v8;
    }
    if ( ((fmt >> 15) & 7) != 0 )
    {
      pDecl[v8].Stream = 0;
      if ( compressionType == VERTEX_COMPRESSION_ON )
        v23 = pSpecEntry;
      pDecl[v8].Offset = v23;
      *(_WORD *)&pDecl[v8].Method = 1536;
      pDecl[v8].UsageIndex = 0;
      pDecl[v8++].Type = VertexElementToDeclType(compressionType);
    }
    v24 = 0;
    offseta = 0;
    if ( bStaticLit )
    {
      if ( (_S1_4 & 1) == 0 )
      {
        _S1_4 |= 1u;
        ConVarRef::ConVarRef(this: &r_staticlight_streams, pName: "r_staticlight_streams", bIgnoreMissing: true);
      }
      pSpecEntrya = r_staticlight_streams.m_pConVarState->m_Value.m_nValue;
      if ( pSpecEntrya > 0 )
      {
        nCoordSize = VertexElementToDeclType(compressionType);
        ja = GetVertexElementSize(element: v26, compressionType: v25);
        p_Method = &pDecl[v8].Method;
        offsetb = pSpecEntrya;
        v8 += pSpecEntrya;
        v28 = 1;
        do
        {
          *(_WORD *)(p_Method - 5) = 1;
          *(_WORD *)(p_Method - 3) = v24;
          v24 += ja;
          p_Method[2] = v28;
          *(_WORD *)p_Method = 2560;
          *(p_Method - 1) = nCoordSize;
          ++v28;
          p_Method += 8;
          --offsetb;
        }
        while ( offsetb != 0 );
        offseta = v24;
      }
    }
    v29 = pStreamSpec;
    pSpecEntryb = pStreamSpec;
    if ( pStreamSpec != nullptr )
    {
      do
      {
        iVertexDataElement = v29->iVertexDataElement;
        if ( v29->iVertexDataElement == 0 )
          break;
        if ( v29->iStreamSpec == STREAM_SPECULAR1 )
        {
          v30 = 0;
          for ( k = 18; k < 42; k += 3 )
          {
            if ( iVertexDataElement == 2LL << k )
              break;
            ++v30;
          }
          if ( iVertexDataElement != 2LL << (3 * (unsigned __int8)v30 + 18) )
            _Warning(
              a1: " ERROR: Cannot compute vertex spec for fmt 0x%08llX requesting 0x%08llX to be passed on STREAM_SPECULAR1!\n",
              fmt,
              iVertexDataElement);
          pDecl[v8].Offset = offseta;
          pDecl[v8].UsageIndex = v30;
          v32 = v30 + 26;
          pDecl[v8].Stream = 1;
          *(_WORD *)&pDecl[v8].Method = 1280;
          if ( compressionType == VERTEX_COMPRESSION_ON )
          {
            switch ( v32 )
            {
              case 2:
              case 17:
                v33 = 5;
                break;
              case 10:
              case 11:
                v33 = 6;
                break;
              default:
                goto LABEL_60;
            }
          }
          else
          {
LABEL_60:
            switch ( v32 )
            {
              case 0:
              case 2:
              case 6:
              case 7:
              case 12:
              case 16:
              case 34:
              case 35:
              case 36:
              case 37:
              case 38:
              case 39:
              case 40:
              case 41:
                v33 = 2;
                break;
              case 1:
              case 3:
              case 13:
              case 17:
              case 42:
              case 43:
              case 44:
              case 45:
              case 46:
              case 47:
              case 48:
              case 49:
                v33 = 3;
                break;
              case 4:
              case 5:
              case 9:
                v33 = 4;
                break;
              case 10:
              case 14:
              case 18:
              case 19:
              case 20:
              case 21:
              case 22:
              case 23:
              case 24:
              case 25:
                v33 = 0;
                break;
              case 11:
              case 15:
              case 26:
              case 27:
              case 28:
              case 29:
              case 30:
              case 31:
              case 32:
              case 33:
                v33 = 1;
                break;
              default:
                v33 = 17;
                break;
            }
          }
          pDecl[v8].Type = v33;
          if ( compressionType == VERTEX_COMPRESSION_ON )
          {
            switch ( v32 )
            {
              case 2:
              case 10:
              case 11:
$LN1898:
                v34 = 4;
                break;
              case 17:
$LN1842:
                v34 = 0;
                break;
              default:
                goto LABEL_70;
            }
          }
          else
          {
LABEL_70:
            switch ( v32 )
            {
              case 0:
              case 2:
              case 6:
              case 7:
              case 12:
              case 16:
              case 34:
              case 35:
              case 36:
              case 37:
              case 38:
              case 39:
              case 40:
              case 41:
                v34 = 12;
                break;
              case 1:
              case 3:
              case 13:
              case 17:
              case 42:
              case 43:
              case 44:
              case 45:
              case 46:
              case 47:
              case 48:
              case 49:
                v34 = 16;
                break;
              case 4:
              case 5:
              case 8:
              case 9:
              case 10:
              case 14:
              case 18:
              case 19:
              case 20:
              case 21:
              case 22:
              case 23:
              case 24:
              case 25:
                goto $LN1898;
              case 11:
              case 15:
              case 26:
              case 27:
              case 28:
              case 29:
              case 30:
              case 31:
              case 32:
              case 33:
                v34 = 8;
                break;
              default:
                goto $LN1842;
            }
          }
          offseta += v34;
          v29 = pSpecEntryb;
          v11 = pDecl;
          ++v8;
        }
        v35 = &v29[1] == nullptr;
        pSpecEntryb = ++v29;
      }
      while ( !v35 );
    }
    v36 = bUsingFlex && g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92;
    *(_DWORD *)&v11[v8].Stream = 2;
    *(_WORD *)&v11[v8].Method = 0;
    v11[v8].UsageIndex = 1;
    v11[v8].Type = v36 + 2;
    v37 = 12;
    if ( v36 )
      v37 = 16;
    v11[v8 + 1].Offset = v37;
    v11[v8 + 1].Stream = 2;
    *(_WORD *)&v11[v8 + 1].Method = 768;
    v11[v8 + 1].UsageIndex = 1;
    jb = 3;
    v11[v8 + 1].Type = (bUsingFlex ? 0 : compressionType) != VERTEX_COMPRESSION_ON ? 2 : 5;
    v38 = v8 + 2;
    ia = v38;
    if ( bUsingMorph )
    {
      *(_DWORD *)&v11[v38].Stream = 3;
      *(_WORD *)&v11[v38].Method = 0;
      v11[v38].UsageIndex = 2;
      v11[v38++].Type = 0;
      ia = v38;
    }
    for ( iUniqueStreamSpeca = 4; iUniqueStreamSpeca < 8; ++iUniqueStreamSpeca )
    {
      v39 = pStreamSpec;
      ++jb;
      offsetc = 0;
      pSpecEntryc = pStreamSpec;
      if ( pStreamSpec != nullptr )
      {
        do
        {
          v40 = v39->iVertexDataElement;
          iVertexDataElement_high = HIDWORD(v39->iVertexDataElement);
          if ( v39->iVertexDataElement == 0 )
            break;
          if ( v39->iStreamSpec == iUniqueStreamSpeca )
          {
            v41 = 0;
            for ( m = 18; m < 42; m += 3 )
            {
              if ( __PAIR64__(iVertexDataElement_high, v40) == 2LL << m )
                break;
              ++v41;
            }
            if ( __PAIR64__(iVertexDataElement_high, v40) != 2LL << (3 * (unsigned __int8)v41 + 18) )
              _Warning(
                a1: " ERROR: Cannot compute vertex spec for fmt 0x%08llX requesting 0x%08llX to be passed on STREAM%d!\n",
                fmt,
                __PAIR64__(iVertexDataElement_high, v40),
                iUniqueStreamSpeca);
            v43 = ia;
            pDecl[ia].Stream = jb;
            pDecl[ia].UsageIndex = v41;
            v44 = v41 + 26;
            pDecl[ia].Offset = offsetc;
            *(_WORD *)&pDecl[ia].Method = 1280;
            if ( compressionType == VERTEX_COMPRESSION_ON )
            {
              switch ( v44 )
              {
                case 2:
                case 17:
                  v45 = 5;
                  break;
                case 10:
                case 11:
                  v45 = 6;
                  break;
                default:
                  goto LABEL_98;
              }
            }
            else
            {
LABEL_98:
              switch ( v44 )
              {
                case 0:
                case 2:
                case 6:
                case 7:
                case 12:
                case 16:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                  v45 = 2;
                  break;
                case 1:
                case 3:
                case 13:
                case 17:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                  v45 = 3;
                  break;
                case 4:
                case 5:
                case 9:
                  v45 = 4;
                  break;
                case 10:
                case 14:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                  v45 = 0;
                  break;
                case 11:
                case 15:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                  v45 = 1;
                  break;
                default:
                  v45 = 17;
                  break;
              }
            }
            pDecl[ia].Type = v45;
            if ( compressionType == VERTEX_COMPRESSION_ON )
            {
              switch ( v44 )
              {
                case 2:
                case 10:
                case 11:
$LN2609:
                  v46 = 4;
                  break;
                case 17:
$LN2553:
                  v46 = 0;
                  break;
                default:
                  goto LABEL_108;
              }
            }
            else
            {
LABEL_108:
              switch ( v44 )
              {
                case 0:
                case 2:
                case 6:
                case 7:
                case 12:
                case 16:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                  v46 = 12;
                  break;
                case 1:
                case 3:
                case 13:
                case 17:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                case 48:
                case 49:
                  v46 = 16;
                  break;
                case 4:
                case 5:
                case 8:
                case 9:
                case 10:
                case 14:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                  goto $LN2609;
                case 11:
                case 15:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                case 32:
                case 33:
                  v46 = 8;
                  break;
                default:
                  goto $LN2553;
              }
            }
            offsetc += v46;
            v39 = pSpecEntryc;
            v11 = pDecl;
            ++ia;
            v38 = v43 + 1;
          }
          v35 = &v39[1] == nullptr;
          pSpecEntryc = ++v39;
        }
        while ( !v35 );
      }
    }
    v11[v38] = declEnd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D3E0
// Name: VertexDeclLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VertexDeclLessFunc(const VertexDeclLookup_t *src1, const VertexDeclLookup_t *src2)
{
  int m_nFlags; // eax
  int v3; // ecx

  m_nFlags = src1->m_nFlags;
  v3 = src2->m_nFlags;
  if ( m_nFlags == v3 )
    return src1->m_VertexFormat < src2->m_VertexFormat;
  else
    return m_nFlags < v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002D4B0
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( i == -1 )
    return dword_10182DF4;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x1002D500
// Name: public: bool CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( m_Parent == -1 )
    return dword_10182DF0 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x1002D5B0
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::FindInsertionPosition(struct VertexDeclLookup_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        const VertexDeclLookup_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D6A0
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NewNode(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  int m_FirstFree; // ecx
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
        this: (CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> *)&this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D760
// Name: public: bool CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x1002D810
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateLeft(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int elem)
{
  int v3; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v9; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v10; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v11; // eax
  int v12; // eax

  v3 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v3 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v3 & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v3 | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
    v8 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  }
  if ( m_Right != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( elem == -1 )
      v11 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v11 = &this->m_Elements.m_pMemory[v7];
    this->m_Elements.m_pMemory[m_Right].m_Parent = v11->m_Parent;
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v12 = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v12].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1002DA10
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateRight(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int elem)
{
  int v3; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v9; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v10; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v11; // eax
  int v12; // eax

  v3 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v3 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v3 & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v3 | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  v8 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( m_Left == -1 )
    v9 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Left];
  if ( v9->m_Right != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( m_Left == -1 )
      v10 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Left];
    this->m_Elements.m_pMemory[v10->m_Right].m_Parent = elem;
    v8 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  }
  if ( m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( elem == -1 )
      v11 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v11 = &this->m_Elements.m_pMemory[v7];
    this->m_Elements.m_pMemory[m_Left].m_Parent = v11->m_Parent;
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    v12 = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v12].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1002DC10
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::Find(struct VertexDeclLookup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Find(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        const VertexDeclLookup_t *search)
{
  int m_Root; // ebx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD00
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FirstInorder(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD90
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NextInorder(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v5; // eax
  int result; // eax
  int *v7; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v8; // ecx
  int m_Parent; // esi
  int v10; // [esp-4h] [ebp-10h]

  v2 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_10182DF0 = -1;
    dword_10182DF4 = -1;
    dword_10182DF8 = 1;
  }
  if ( i == -1 )
    v4 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[i];
  if ( v4->m_Right == -1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( i == -1 )
      v8 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v8 = &this->m_Elements.m_pMemory[i];
    m_Parent = v8->m_Parent;
    if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10182DF0 = -1;
          dword_10182DF4 = -1;
          dword_10182DF8 = 1;
        }
        v10 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
                this,
                i: v10) );
    }
    return m_Parent;
  }
  else
  {
    if ( (v2 & 1) == 0 )
    {
      v2 |= 1u;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v2;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_10182DF0 = -1;
      dword_10182DF4 = -1;
      dword_10182DF8 = 1;
    }
    if ( i == -1 )
      v5 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v5 = &this->m_Elements.m_pMemory[i];
    result = v5->m_Right;
    while ( 1 )
    {
      if ( (v2 & 1) == 0 )
      {
        v2 |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v2;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      v7 = result == -1
         ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v7 == -1 )
        break;
      if ( (v2 & 1) == 0 )
      {
        v2 |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v2;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DF40
// Name: public: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RemoveAll(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10182DF0 = -1;
            dword_10182DF4 = -1;
            dword_10182DF8 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E000
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::InsertRebalance(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int v4; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v5; // eax
  int m_Parent; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v7; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v8; // eax
  int v9; // esi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v10; // eax
  int v11; // ebx
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v18; // esi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v19; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v20; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v23; // esi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_10182DF0 = -1;
        dword_10182DF4 = -1;
        dword_10182DF8 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10182DF0 = -1;
          dword_10182DF4 = -1;
          dword_10182DF8 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10182DF0 = -1;
          dword_10182DF4 = -1;
          dword_10182DF8 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10182DF0 = -1;
            dword_10182DF4 = -1;
            dword_10182DF8 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10182DF0 = -1;
            dword_10182DF4 = -1;
            dword_10182DF8 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10182DF0 = -1;
          dword_10182DF4 = -1;
          dword_10182DF8 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_10182DF0 = -1;
          dword_10182DF4 = -1;
          dword_10182DF8 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10182DF0 = -1;
            dword_10182DF4 = -1;
            dword_10182DF8 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_10182DF0 = -1;
            dword_10182DF4 = -1;
            dword_10182DF8 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002E450
// Name: void ReleaseAllVertexDecl(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseAllVertexDecl()
{
  int i; // esi

  for ( i = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FirstInorder(this: &s_VertexDeclDict);
        i != -1;
        i = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NextInorder(
              this: &s_VertexDeclDict,
              i) )
  {
    s_VertexDeclDict.m_Elements.m_pMemory[i].m_Data.m_pDecl->Release(this: s_VertexDeclDict.m_Elements.m_pMemory[i].m_Data.m_pDecl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E490
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LinkToParent(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E500
// Name: public: CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::~CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::~CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E560
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::Insert(struct VertexDeclLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Insert(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        const VertexDeclLookup_t *insert)
{
  int v3; // edi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NewNode(this);
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v3] != (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-16 )
    m_pMemory[v3].m_Data = *insert;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1002E5E0
// Name: struct IDirect3DVertexDeclaration9 __near * FindOrCreateVertexDecl(unsigned __int64,bool,bool,bool,bool,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IDirect3DVertexDeclaration9 *__cdecl FindOrCreateVertexDecl(
        unsigned __int64 fmt,
        bool bStaticLit,
        bool bUsingFlex,
        bool bUsingMorph,
        __int16 bUsingPreTessPatch,
        VertexStreamSpec_t *pStreamSpec)
{
  int v6; // eax
  D3DDeviceWrapper *v8; // esi
  _D3DVERTEXELEMENT9 decl[32]; // [esp+Ch] [ebp-110h] BYREF
  VertexDeclLookup_t lookup; // [esp+10Ch] [ebp-10h] BYREF

  lookup.m_VertexFormat = fmt;
  lookup.m_nFlags = bStaticLit;
  if ( bUsingMorph )
    lookup.m_nFlags |= 2u;
  if ( bUsingFlex )
    lookup.m_nFlags |= 4u;
  if ( (_BYTE)bUsingPreTessPatch != 0 )
    lookup.m_nFlags |= 8u;
  v6 = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Find(
         this: &s_VertexDeclDict,
         search: &lookup);
  if ( v6 != -1 )
    return s_VertexDeclDict.m_Elements.m_pMemory[v6].m_Data.m_pDecl;
  ComputeVertexSpec(fmt, pDecl: decl, bStaticLit, bUsingFlex, bUsingMorph, bUsingPreTessPatch, pStreamSpec);
  v8 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v8);
  if ( v8->m_pD3DDevice->CreateVertexDeclaration(this: v8->m_pD3DDevice, a2: decl, a3: &lookup.m_pDecl) != 0 )
    _Warning(
      a1: " ERROR: failed to create vertex decl for vertex format %x! You'll probably see messed-up mesh rendering - to diagn"
      "ose, build shaderapidx9.dll in debug.\n",
      (_DWORD)fmt);
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Insert(
    this: &s_VertexDeclDict,
    insert: &lookup);
  return lookup.m_pDecl;
}

//------------------------------------------------------------------------------
// Address: 0x100D6A20
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6B20
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_101A0B40 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_101A0B40;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100D6CA0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_101A0B40 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x100D6D00
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_101A0B40 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100D6D70
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6E60
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D6F60
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D70A0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x100D71A0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7260
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_101A0B40 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_101A0B40 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_101A0B40 = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_101A0B40 = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_101A0B40 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_101A0B40 = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_101A0B40 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_101A0B40 = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_101A0B40 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_101A0B40 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_101A0B40 = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D78F0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D79F0
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7A80
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10029FA0
// Name: protected: void CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CShaderDeviceDx10::InputLayout_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        const CShaderDeviceDx10::InputLayout_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A0B0
// Name: public: unsigned short CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // eax
  unsigned __int16 v5; // cx
  unsigned __int16 index; // di
  int v7; // ebx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v11; // edx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t v12; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    p_m_LastAlloc = &this->m_LastAlloc;
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v12.index = v5;
    index = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v12.index = (v7 > 0) - 1;
        v8 = &v12;
      }
      else
      {
        v8 = CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Next(
               this: (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)&this->m_Elements,
               result: &v12,
               it: (const CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
      }
      index = v8->index;
      if ( v8->index >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = index;
    this->m_pElements = m_pMemory;
    return index;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[m_FirstFree].m_Right;
    this->m_pElements = v11;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A700
// Name: protected: void CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1002A800
// Name: protected: void CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1002A900
// Name: public: unsigned short CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Find(struct CShaderDeviceDx10::InputLayout_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        const CShaderDeviceDx10::InputLayout_t *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1002AA10
// Name: public: unsigned short CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this)
{
  int v1; // ebx
  int result; // eax
  UtlRBTreeLinks_t<unsigned short> *v3; // edx

  v1 = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : &this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( v3->m_Left == 0xFFFF )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
      `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
    }
    if ( (_WORD)result == 0xFFFF )
      result = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AAD0
// Name: public: unsigned short CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int result; // eax
  int v5; // edx
  UtlRBTreeLinks_t<unsigned short> *v6; // ecx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v7; // eax
  int v8; // edx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v9; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v11; // ecx

  v2 = i;
  if ( CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
         this,
         i)->m_Right == 0xFFFF )
  {
    v7 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
           this,
           i);
    v8 = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      result = v7->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v9 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v9 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v9->m_Parent;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v11 = m_Parent == 0xFFFF
          ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[m_Parent];
      if ( v11->m_Right != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v8 & 1) == 0 )
      {
        v8 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v8;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = &this->m_Elements.m_pMemory[(unsigned __int16)result];
    }
  }
  else
  {
    result = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Right;
    v5 = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( v6->m_Left == 0xFFFF )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( (_WORD)result == 0xFFFF )
        result = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002AD60
// Name: public: void CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AE20
// Name: protected: void CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)&`CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B400
// Name: protected: void CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B510
// Name: public: CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::~CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B890
// Name: public: unsigned short CUtlRBTree<struct CShaderDeviceDx10::InputLayout_t,unsigned short,bool (*)(struct CShaderDeviceDx10::InputLayout_t const __near &,struct CShaderDeviceDx10::InputLayout_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Insert(struct CShaderDeviceDx10::InputLayout_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl*)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short> > *this,
        const CShaderDeviceDx10::InputLayout_t *insert)
{
  const CShaderDeviceDx10::InputLayout_t *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 v7[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CShaderDeviceDx10::InputLayout_t,unsigned short,bool (__cdecl *)(CShaderDeviceDx10::InputLayout_t const &,CShaderDeviceDx10::InputLayout_t const &),CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v7[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short> *)-8 )
  {
    *(_QWORD *)&m_pMemory[v4].m_Data.m_pInputLayout = *(_QWORD *)&v2->m_pInputLayout;
    m_pMemory[v4].m_Data.m_VertexFormat = v2->m_VertexFormat;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10033AD0
// Name: VertexElementToDeclType
// Source: json
//------------------------------------------------------------------------------
_D3DDECLTYPE __cdecl VertexElementToDeclType(VertexCompressionType_t compressionType)
{
  VertexElement_t element; // ecx
  _D3DDECLTYPE result; // eax

  if ( compressionType == VERTEX_COMPRESSION_ON )
  {
    switch ( element )
    {
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_USERDATA4:
        result = D3DDECLTYPE_UBYTE4;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_BONEWEIGHTS2:
        result = D3DDECLTYPE_SHORT2;
        break;
      default:
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    switch ( element )
    {
      case VERTEX_ELEMENT_POSITION:
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_TANGENT_S:
      case VERTEX_ELEMENT_TANGENT_T:
      case VERTEX_ELEMENT_BONEWEIGHTS3:
      case VERTEX_ELEMENT_USERDATA3:
      case VERTEX_ELEMENT_TEXCOORD3D_0:
      case VERTEX_ELEMENT_TEXCOORD3D_1:
      case VERTEX_ELEMENT_TEXCOORD3D_2:
      case VERTEX_ELEMENT_TEXCOORD3D_3:
      case VERTEX_ELEMENT_TEXCOORD3D_4:
      case VERTEX_ELEMENT_TEXCOORD3D_5:
      case VERTEX_ELEMENT_TEXCOORD3D_6:
      case VERTEX_ELEMENT_TEXCOORD3D_7:
        result = D3DDECLTYPE_FLOAT3;
        break;
      case VERTEX_ELEMENT_POSITION4D:
      case VERTEX_ELEMENT_NORMAL4D:
      case VERTEX_ELEMENT_BONEWEIGHTS4:
      case VERTEX_ELEMENT_USERDATA4:
      case VERTEX_ELEMENT_TEXCOORD4D_0:
      case VERTEX_ELEMENT_TEXCOORD4D_1:
      case VERTEX_ELEMENT_TEXCOORD4D_2:
      case VERTEX_ELEMENT_TEXCOORD4D_3:
      case VERTEX_ELEMENT_TEXCOORD4D_4:
      case VERTEX_ELEMENT_TEXCOORD4D_5:
      case VERTEX_ELEMENT_TEXCOORD4D_6:
      case VERTEX_ELEMENT_TEXCOORD4D_7:
        result = D3DDECLTYPE_FLOAT4;
        break;
      case VERTEX_ELEMENT_COLOR:
      case VERTEX_ELEMENT_SPECULAR:
      case VERTEX_ELEMENT_BONEINDEX:
        result = D3DDECLTYPE_D3DCOLOR;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_USERDATA1:
      case VERTEX_ELEMENT_TEXCOORD1D_0:
      case VERTEX_ELEMENT_TEXCOORD1D_1:
      case VERTEX_ELEMENT_TEXCOORD1D_2:
      case VERTEX_ELEMENT_TEXCOORD1D_3:
      case VERTEX_ELEMENT_TEXCOORD1D_4:
      case VERTEX_ELEMENT_TEXCOORD1D_5:
      case VERTEX_ELEMENT_TEXCOORD1D_6:
      case VERTEX_ELEMENT_TEXCOORD1D_7:
        result = D3DDECLTYPE_FLOAT1;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS2:
      case VERTEX_ELEMENT_USERDATA2:
      case VERTEX_ELEMENT_TEXCOORD2D_0:
      case VERTEX_ELEMENT_TEXCOORD2D_1:
      case VERTEX_ELEMENT_TEXCOORD2D_2:
      case VERTEX_ELEMENT_TEXCOORD2D_3:
      case VERTEX_ELEMENT_TEXCOORD2D_4:
      case VERTEX_ELEMENT_TEXCOORD2D_5:
      case VERTEX_ELEMENT_TEXCOORD2D_6:
      case VERTEX_ELEMENT_TEXCOORD2D_7:
        result = D3DDECLTYPE_FLOAT2;
        break;
      default:
        result = D3DDECLTYPE_UNUSED;
        break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033C10
// Name: void ComputeVertexSpec(unsigned __int64,struct _D3DVERTEXELEMENT9 __near *,bool,bool,bool,bool,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeVertexSpec(
        unsigned __int64 fmt,
        _D3DVERTEXELEMENT9 *pDecl,
        bool bStaticLit,
        bool bUsingFlex,
        bool bUsingMorph,
        bool bUsingPreTessPatch,
        VertexStreamSpec_t *pStreamSpec)
{
  int v7; // esi
  VertexCompressionType_t v8; // edx
  int v9; // edx
  int v10; // ecx
  int v11; // ebx
  VertexCompressionType_t v12; // edx
  VertexElement_t v13; // ecx
  int VertexElementSize; // eax
  VertexCompressionType_t v15; // edx
  VertexElement_t v16; // ecx
  unsigned __int8 *p_Method; // ebp
  VertexStreamSpec_t *v18; // eax
  VertexCompressionType_t v19; // edx
  VertexElement_t v20; // ecx
  int m_nValue; // ebp
  int v22; // ebx
  VertexCompressionType_t v23; // edx
  VertexElement_t v24; // ecx
  int v25; // eax
  unsigned __int8 *v26; // ecx
  __int16 v27; // dx
  VertexStreamSpec_t *v28; // eax
  unsigned __int8 *v29; // ebp
  unsigned __int8 v30; // bl
  VertexCompressionType_t v31; // edx
  VertexElement_t v32; // ecx
  bool v33; // zf
  bool v34; // al
  int v35; // esi
  unsigned __int16 v36; // cx
  int v37; // esi
  int v38; // ebx
  VertexStreamSpec_t *v39; // eax
  unsigned __int8 *v40; // ebp
  unsigned __int8 v41; // bl
  VertexCompressionType_t v42; // edx
  VertexElement_t v43; // ecx
  VertexCompressionType_t iUniqueStreamSpec; // [esp+8h] [ebp-38h]
  int nCoordSize; // [esp+Ch] [ebp-34h]
  int nCoordSizea; // [esp+Ch] [ebp-34h]
  unsigned __int64 iVertexDataElement; // [esp+10h] [ebp-30h]
  __int16 v48; // [esp+10h] [ebp-30h]
  unsigned __int8 pSpecEntry; // [esp+18h] [ebp-28h]
  int pSpecEntrya; // [esp+18h] [ebp-28h]
  int pSpecEntryb; // [esp+18h] [ebp-28h]
  unsigned __int16 v52; // [esp+1Ch] [ebp-24h]
  unsigned __int8 v53; // [esp+1Ch] [ebp-24h]
  VertexStreamSpec_t *v54; // [esp+1Ch] [ebp-24h]
  VertexStreamSpec_t *v55; // [esp+1Ch] [ebp-24h]
  unsigned __int64 v56; // [esp+20h] [ebp-20h]
  VertexStreamSpec_t *offset; // [esp+5Ch] [ebp+1Ch]
  int offseta; // [esp+5Ch] [ebp+1Ch]
  int offsetb; // [esp+5Ch] [ebp+1Ch]

  v7 = 0;
  if ( (fmt & 0x400) != 0 )
  {
    v8 = VERTEX_COMPRESSION_ON;
    iUniqueStreamSpec = VERTEX_COMPRESSION_ON;
  }
  else
  {
    iUniqueStreamSpec = VERTEX_COMPRESSION_NONE;
    v8 = VERTEX_COMPRESSION_NONE;
  }
  if ( bUsingPreTessPatch )
  {
    pDecl->Method = 0;
    pDecl->Usage = 0;
    pDecl->UsageIndex = 0;
    pDecl->Stream = 0;
    pDecl->Offset = 0;
    pDecl->Type = 1;
    pDecl[1].Stream = 0;
    pDecl[1].Method = 0;
    pDecl[1].Usage = 5;
    pDecl[1].UsageIndex = 0;
    pDecl[1].Type = 3;
    pDecl[1].Offset = 8;
    pDecl[2].Stream = 0;
    pDecl[2].Offset = 24;
    pDecl[2].Method = 0;
    pDecl[2].Usage = 5;
    pDecl[2].UsageIndex = 1;
    pDecl[2].Type = 3;
    pDecl[3].Stream = 8;
    pDecl[3].Offset = 0;
    pDecl[3].Method = 0;
    pDecl[3].Usage = 0;
    pDecl[3].UsageIndex = 1;
    pDecl[3].Type = 3;
    pDecl[4].Stream = 8;
    pDecl[4].Offset = 16;
    pDecl[4].Method = 0;
    pDecl[4].Usage = 5;
    pDecl[4].UsageIndex = 2;
    pDecl[4].Type = 3;
    pDecl[5].Stream = 8;
    pDecl[5].Offset = 32;
    pDecl[5].Method = 0;
    pDecl[5].Usage = 5;
    pDecl[5].UsageIndex = 3;
    pDecl[5].Type = 3;
    pDecl[6].Stream = 8;
    pDecl[6].Offset = 48;
    pDecl[6].Method = 0;
    pDecl[6].Usage = 0;
    pDecl[6].UsageIndex = 2;
    pDecl[6].Type = 3;
    pDecl[7].Stream = 8;
    pDecl[7].Offset = 64;
    pDecl[7].Method = 0;
    pDecl[7].Usage = 5;
    pDecl[7].UsageIndex = 4;
    pDecl[7].Type = 3;
    pDecl[8].Stream = 8;
    pDecl[8].Offset = 80;
    pDecl[8].Method = 0;
    pDecl[8].Usage = 5;
    pDecl[8].UsageIndex = 5;
    pDecl[8].Type = 3;
    pDecl[9].Stream = 8;
    pDecl[9].Offset = 96;
    pDecl[9].Method = 0;
    pDecl[9].Usage = 0;
    pDecl[9].UsageIndex = 3;
    pDecl[9].Type = 3;
    pDecl[10].Stream = 8;
    pDecl[10].Offset = 112;
    pDecl[10].Method = 0;
    pDecl[10].Usage = 5;
    pDecl[10].UsageIndex = 6;
    pDecl[10].Type = 3;
    pDecl[11].Stream = 8;
    pDecl[11].Offset = 128;
    pDecl[11].Method = 0;
    pDecl[11].Usage = 5;
    pDecl[11].UsageIndex = 7;
    pDecl[11].Type = 3;
    pDecl[12].Stream = 8;
    pDecl[12].Offset = 144;
    pDecl[12].Method = 0;
    pDecl[12].Usage = 0;
    pDecl[12].UsageIndex = 4;
    pDecl[12].Type = 3;
    pDecl[13].Stream = 8;
    v9 = *(_DWORD *)&declEnd_0.Type;
    pDecl[13].UsageIndex = 8;
    pDecl[13].Offset = 160;
    pDecl[13].Method = 0;
    pDecl[13].Usage = 5;
    pDecl[13].Type = 3;
    pDecl[14].Stream = 8;
    v10 = *(_DWORD *)&declEnd_0.Stream;
    pDecl[14].Offset = 176;
    pDecl[14].Method = 0;
    pDecl[14].Usage = 5;
    pDecl[14].UsageIndex = 9;
    pDecl[14].Type = 3;
    pDecl[15].Offset = 0;
    pDecl[15].Stream = 3;
    pDecl[15].Method = 0;
    pDecl[15].Usage = 5;
    pDecl[15].UsageIndex = 10;
    pDecl[15].Type = 0;
    *(_DWORD *)&pDecl[16].Stream = v10;
    *(_DWORD *)&pDecl[16].Type = v9;
  }
  else
  {
    v11 = 0;
    if ( (fmt & 1) != 0 )
    {
      pDecl->Stream = 0;
      pDecl->Offset = 0;
      pDecl->Method = 0;
      pDecl->Usage = 0;
      pDecl->UsageIndex = 0;
      pDecl->Type = VertexElementToDeclType(compressionType: v8);
      VertexElementSize = GetVertexElementSize(element: v13, compressionType: v12);
      v8 = iUniqueStreamSpec;
      v11 = VertexElementSize;
      v7 = 1;
    }
    if ( ((fmt >> 12) & 7) != 0 )
    {
      pDecl[v7].Type = v8 != VERTEX_COMPRESSION_ON ? 1 : 6;
      pDecl[v7].Offset = v11;
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 1;
      pDecl[v7].UsageIndex = 0;
      v11 += 4 * (v8 != VERTEX_COMPRESSION_ON) + 4;
      ++v7;
    }
    if ( (fmt & 0x80) != 0 )
    {
      pDecl[v7].Offset = v11;
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 2;
      pDecl[v7].UsageIndex = 0;
      pDecl[v7].Type = 4;
      v11 += 4;
      ++v7;
    }
    v52 = -1;
    if ( (fmt & 2) != 0 )
    {
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].UsageIndex = 0;
      pDecl[v7].Offset = v11;
      v52 = v11;
      pDecl[v7].Usage = 3;
      pDecl[v7].Type = VertexElementToDeclType(compressionType: v8);
      v11 += GetVertexElementSize(element: v16, compressionType: v15);
      ++v7;
    }
    if ( (fmt & 4) != 0 )
    {
      pDecl[v7].Offset = v11;
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 10;
      pDecl[v7].UsageIndex = 0;
      pDecl[v7].Type = 4;
      v11 += 4;
      ++v7;
    }
    if ( (fmt & 8) != 0 )
    {
      pDecl[v7].Offset = v11;
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 10;
      pDecl[v7].UsageIndex = 1;
      pDecl[v7].Type = 4;
      v11 += 4;
      ++v7;
    }
    pSpecEntry = 0;
    nCoordSize = 18;
    p_Method = &pDecl[v7].Method;
    do
    {
      if ( ((fmt >> nCoordSize) & 7) != 0 )
      {
        v18 = pStreamSpec;
        offset = pStreamSpec;
        if ( pStreamSpec != nullptr )
        {
          while ( v18->iVertexDataElement != 0 )
          {
            if ( offset->iVertexDataElement == ((fmt >> nCoordSize) & 7) << nCoordSize )
            {
              if ( offset->iStreamSpec != STREAM_DEFAULT )
                goto LABEL_29;
              break;
            }
            if ( ++offset == nullptr )
              break;
            v18 = offset;
          }
        }
        *(_WORD *)(p_Method - 5) = 0;
        *(_WORD *)(p_Method - 3) = v11;
        *p_Method = 0;
        p_Method[1] = 5;
        p_Method[2] = pSpecEntry;
        *(p_Method - 1) = VertexElementToDeclType(compressionType: iUniqueStreamSpec);
        v11 += GetVertexElementSize(element: v20, compressionType: v19);
        ++v7;
        p_Method += 8;
      }
LABEL_29:
      ++pSpecEntry;
      nCoordSize += 3;
    }
    while ( nCoordSize < 42 );
    if ( (fmt & 0x10) != 0 )
    {
      pDecl[v7].Offset = v11;
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 6;
      pDecl[v7].UsageIndex = 0;
      pDecl[v7].Type = 2;
      LOWORD(v11) = v11 + 12;
      ++v7;
    }
    if ( (fmt & 0x20) != 0 )
    {
      pDecl[v7].Offset = v11;
      pDecl[v7].Stream = 0;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 7;
      pDecl[v7].UsageIndex = 0;
      pDecl[v7].Type = 2;
      LOWORD(v11) = v11 + 12;
      ++v7;
    }
    if ( ((fmt >> 15) & 7) != 0 )
    {
      pDecl[v7].Stream = 0;
      if ( iUniqueStreamSpec == VERTEX_COMPRESSION_ON )
        pDecl[v7].Offset = v52;
      else
        pDecl[v7].Offset = v11;
      pDecl[v7].Method = 0;
      pDecl[v7].Usage = 6;
      pDecl[v7].UsageIndex = 0;
      pDecl[v7++].Type = VertexElementToDeclType(compressionType: iUniqueStreamSpec);
    }
    offseta = 0;
    if ( bStaticLit )
    {
      if ( (_S1_4 & 1) == 0 )
      {
        _S1_4 |= 1u;
        ConVarRef::ConVarRef(this: &r_staticlight_streams, pName: "r_staticlight_streams", bIgnoreMissing: true);
      }
      m_nValue = r_staticlight_streams.m_pConVarState->m_Value.m_nValue;
      v22 = 1;
      if ( m_nValue > 0 )
      {
        v53 = VertexElementToDeclType(compressionType: iUniqueStreamSpec);
        v25 = GetVertexElementSize(element: v24, compressionType: v23);
        v26 = &pDecl[v7].Method;
        v7 += m_nValue;
        do
        {
          v27 = offseta;
          offseta += v25;
          *(_WORD *)(v26 - 3) = v27;
          v26[2] = v22;
          *(_WORD *)(v26 - 5) = 1;
          *v26 = 0;
          v26[1] = 10;
          *(v26 - 1) = v53;
          ++v22;
          v26 += 8;
          --m_nValue;
        }
        while ( m_nValue != 0 );
      }
    }
    v28 = pStreamSpec;
    v54 = pStreamSpec;
    if ( pStreamSpec != nullptr )
    {
      v29 = &pDecl[v7].Method;
      do
      {
        iVertexDataElement = v28->iVertexDataElement;
        if ( v28->iVertexDataElement == 0 )
          break;
        if ( v28->iStreamSpec == STREAM_SPECULAR1 )
        {
          v30 = 0;
          for ( pSpecEntrya = 18; pSpecEntrya < 42; pSpecEntrya += 3 )
          {
            if ( iVertexDataElement == 2LL << pSpecEntrya )
              break;
            ++v30;
          }
          if ( iVertexDataElement != 2LL << (3 * v30 + 18) )
            _Warning(
              a1: " ERROR: Cannot compute vertex spec for fmt 0x%08X requesting 0x%08X to be passed on STREAM_SPECULAR1!\n",
              (_DWORD)fmt,
              HIDWORD(fmt));
          *(_WORD *)(v29 - 5) = 1;
          *(_WORD *)(v29 - 3) = offseta;
          *v29 = 0;
          v29[1] = 5;
          v29[2] = v30;
          *(v29 - 1) = VertexElementToDeclType(compressionType: iUniqueStreamSpec);
          offseta += GetVertexElementSize(element: v32, compressionType: v31);
          v28 = v54;
          ++v7;
          v29 += 8;
        }
        v33 = &v28[1] == nullptr;
        v54 = ++v28;
      }
      while ( !v33 );
    }
    v34 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 92;
    pDecl[v7].Type = v34 + 2;
    pDecl[v7].Stream = 2;
    pDecl[v7].Offset = 0;
    pDecl[v7].Method = 0;
    pDecl[v7].Usage = 0;
    pDecl[v7].UsageIndex = 1;
    v35 = v7 + 1;
    v36 = 12;
    if ( v34 )
      v36 = 16;
    pDecl[v35].Stream = 2;
    pDecl[v35].Offset = v36;
    pDecl[v35].Method = 0;
    pDecl[v35].Usage = 3;
    pDecl[v35].UsageIndex = 1;
    v48 = 3;
    pDecl[v35].Type = (bUsingFlex ? 0 : iUniqueStreamSpec) != VERTEX_COMPRESSION_ON ? 2 : 5;
    v37 = v35 + 1;
    if ( bUsingMorph )
    {
      pDecl[v37].Stream = 3;
      pDecl[v37].Offset = 0;
      pDecl[v37].Method = 0;
      pDecl[v37].Usage = 0;
      pDecl[v37].UsageIndex = 2;
      pDecl[v37++].Type = 0;
    }
    v38 = 4;
    nCoordSizea = 4;
    do
    {
      v39 = pStreamSpec;
      ++v48;
      offsetb = 0;
      v55 = pStreamSpec;
      if ( pStreamSpec != nullptr )
      {
        v40 = &pDecl[v37].Method;
        do
        {
          v56 = v39->iVertexDataElement;
          if ( v39->iVertexDataElement == 0 )
            break;
          if ( v39->iStreamSpec == v38 )
          {
            v41 = 0;
            for ( pSpecEntryb = 18; pSpecEntryb < 42; pSpecEntryb += 3 )
            {
              if ( v56 == 2LL << pSpecEntryb )
                break;
              ++v41;
            }
            if ( v56 != 2LL << (3 * v41 + 18) )
              _Warning(
                a1: " ERROR: Cannot compute vertex spec for fmt 0x%08X requesting 0x%08X to be passed on STREAM%d!\n",
                (_DWORD)fmt,
                HIDWORD(fmt),
                (_DWORD)v56);
            *(_WORD *)(v40 - 3) = offsetb;
            *(_WORD *)(v40 - 5) = v48;
            *v40 = 0;
            v40[1] = 5;
            v40[2] = v41;
            *(v40 - 1) = VertexElementToDeclType(compressionType: iUniqueStreamSpec);
            offsetb += GetVertexElementSize(element: v43, compressionType: v42);
            v39 = v55;
            v38 = nCoordSizea;
            ++v37;
            v40 += 8;
          }
          v33 = &v39[1] == nullptr;
          v55 = ++v39;
        }
        while ( !v33 );
      }
      nCoordSizea = ++v38;
    }
    while ( v38 < 8 );
    pDecl[v37] = declEnd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100344D0
// Name: VertexDeclLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VertexDeclLessFunc(const VertexDeclLookup_t *src1, const VertexDeclLookup_t *src2)
{
  int m_nFlags; // eax
  int v3; // ecx

  m_nFlags = src1->m_nFlags;
  v3 = src2->m_nFlags;
  if ( m_nFlags == v3 )
    return src1->m_VertexFormat < src2->m_VertexFormat;
  else
    return m_nFlags < v3;
}

//------------------------------------------------------------------------------
// Address: 0x100345A0
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100345F0
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LeftChild(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i))(const VertexDeclLookup_t *, const VertexDeclLookup_t *)
{
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc;
  else
    return (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10034640
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<VertexDeclLookup_t,int> *__thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RightChild(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory;
  else
    return (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10034690
// Name: public: bool CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory == (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x10034740
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::FindInsertionPosition(struct VertexDeclLookup_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        const VertexDeclLookup_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034830
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NewNode(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  int m_FirstFree; // ecx
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<CTransitionTable::SnapshotShaderState_t,int>::Grow(
        this: (CUtlMemory<CTransitionTable::SnapshotShaderState_t,int> *)&this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034900
// Name: public: bool CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  int m_Root; // edx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v3; // eax
  int m_Parent; // eax

  m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc == (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x100349B0
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateLeft(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v6; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v7; // eax

  m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Right == -1 )
    v7 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Right];
  if ( v7->m_Left != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LeftChild(
                                         this,
                                         i: m_Right)].m_Parent = elem;
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x10034B20
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateRight(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int elem)
{
  int m_Root; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v6; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v7; // eax

  m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
           | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (m_Root & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[(_DWORD)CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RightChild(
                                         this,
                                         i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10034CA0
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::Find(struct VertexDeclLookup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Find(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        const VertexDeclLookup_t *search)
{
  int m_Root; // ebp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10034D90
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FirstInorder(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this))(const VertexDeclLookup_t *, const VertexDeclLookup_t *)
{
  int m_Root; // ebx
  bool (__cdecl *result)(const VertexDeclLookup_t *, const VertexDeclLookup_t *); // eax
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *v3; // edx

  m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
  result = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))this->m_Root;
  while ( 1 )
  {
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    v3 = result == (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1
       ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
       : (CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
    if ( v3->m_LessFunc == (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1 )
      break;
    if ( (m_Root & 1) == 0 )
    {
      m_Root |= 1u;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
      `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
    }
    if ( result == (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1 )
      result = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc;
    else
      result = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034E20
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
UtlRBTreeNode_t<VertexDeclLookup_t,int> *__thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NextInorder(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v3; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *result; // eax
  int m_Root; // edx
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *v6; // ecx
  int m_Parent; // esi
  int v8; // [esp-4h] [ebp-14h]

  if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
      & 1) == 0 )
  {
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
    `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v8 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)m_Parent;
  }
  else
  {
    result = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RightChild(
               this,
               i);
    m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
    while ( 1 )
    {
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v6 = result == (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1
         ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *)&this->m_Elements.m_pMemory[(_DWORD)result];
      if ( v6->m_LessFunc == (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( result == (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1 )
        result = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc;
      else
        result = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)this->m_Elements.m_pMemory[(_DWORD)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034F70
// Name: public: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RemoveAll(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  int index; // eax
  int v3; // esi
  int v4; // eax

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 >= 0
          && v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LeftChild(
               this,
               i: v3) != (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        if ( ++v3 < 0 || v3 >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
      }
      while ( v3 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034FF0
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::InsertRebalance(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int elem)
{
  int v2; // esi
  int m_Root; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v5; // eax
  int m_Parent; // eax
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *v7; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v8; // eax
  int v9; // esi
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *v10; // eax
  int m_nAllocationCount; // ebp
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v14; // eax
  int m_Right; // eax
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v18; // esi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v19; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v20; // eax
  int m_Left; // eax
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *v22; // ecx
  int v23; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v24; // esi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v25; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
          & 1) == 0 )
      {
        m_Root = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
               | 1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v7 = m_Parent == -1
         ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
         : (CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Elements.m_nGrowSize != 0 )
        break;
      if ( (m_Root & 1) == 0 )
      {
        m_Root |= 1u;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (m_Root & 1) == 0 )
      {
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = m_Root | 1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
        `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
      }
      v10 = v9 == -1
          ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
          : (CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *)&this->m_Elements.m_pMemory[v9];
      m_nAllocationCount = v10->m_Elements.m_nAllocationCount;
      IsLeftChild = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v14 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v16 = m_Right == -1
            ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsRightChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateLeft(
              this,
              elem: v9);
            v17 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v17 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v18 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v18 = &this->m_Elements.m_pMemory[v9];
            v9 = v18->m_Parent;
            if ( (v17 & 1) == 0 )
            {
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v17 | 1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v19 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v19 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v19->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateRight(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      else
      {
        if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
              | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        if ( m_nAllocationCount == -1 )
          v20 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[m_nAllocationCount];
        m_Left = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v13 | 1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
          `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
        }
        v22 = m_Left == -1
            ? &`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel
            : (CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *)&this->m_Elements.m_pMemory[m_Left];
        if ( v22->m_Elements.m_nGrowSize != 0 )
        {
          if ( CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::IsLeftChild(
                 this,
                 i: elem) )
          {
            elem = v9;
            CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateRight(
              this,
              elem: v9);
            v23 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root;
            if ( (`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                & 1) == 0 )
            {
              v23 = `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root
                  | 1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root |= 1u;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v24 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v24 = &this->m_Elements.m_pMemory[v9];
            v9 = v24->m_Parent;
            if ( (v23 & 1) == 0 )
            {
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Root = v23 | 1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_LessFunc = (bool (__cdecl *)(const VertexDeclLookup_t *, const VertexDeclLookup_t *))-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_pMemory = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nAllocationCount = -1;
              `CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel.m_Elements.m_nGrowSize = 1;
            }
            if ( v9 == -1 )
              v25 = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)&`CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Links'::`2'::s_Sentinel;
            else
              v25 = &this->m_Elements.m_pMemory[v9];
            m_nAllocationCount = v25->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RotateLeft(
            this,
            elem: m_nAllocationCount);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[m_nAllocationCount].m_Tag = 0;
          elem = m_nAllocationCount;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035420
// Name: void ReleaseAllVertexDecl(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseAllVertexDecl()
{
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *i; // esi

  for ( i = (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FirstInorder(this: &s_VertexDeclDict);
        i != (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-1;
        i = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NextInorder(
              this: &s_VertexDeclDict,
              (int)i) )
  {
    s_VertexDeclDict.m_Elements.m_pMemory[(_DWORD)i].m_Data.m_pDecl->Release(this: s_VertexDeclDict.m_Elements.m_pMemory[(_DWORD)i].m_Data.m_pDecl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035460
// Name: protected: void CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LinkToParent(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *v4; // eax
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100354D0
// Name: public: CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::~CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::~CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this)
{
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035530
// Name: public: int CUtlRBTree<struct VertexDeclLookup_t,int,bool (*)(struct VertexDeclLookup_t const __near &,struct VertexDeclLookup_t const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct VertexDeclLookup_t,int>,int>>::Insert(struct VertexDeclLookup_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Insert(
        CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl*)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int> > *this,
        const VertexDeclLookup_t *insert)
{
  const VertexDeclLookup_t *v2; // ebx
  int v4; // edi
  UtlRBTreeNode_t<VertexDeclLookup_t,int> *m_pMemory; // edx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    parent: &v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::NewNode(this);
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent: v7,
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<VertexDeclLookup_t,int> *)-16 )
  {
    m_pMemory[v4].m_Data.m_VertexFormat = v2->m_VertexFormat;
    *(_QWORD *)&m_pMemory[v4].m_Data.m_nFlags = *(_QWORD *)&v2->m_nFlags;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100355A0
// Name: struct IDirect3DVertexDeclaration9 __near * FindOrCreateVertexDecl(unsigned __int64,bool,bool,bool,bool,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IDirect3DVertexDeclaration9 *__cdecl FindOrCreateVertexDecl(
        unsigned __int64 fmt,
        bool bStaticLit,
        bool bUsingFlex,
        bool bUsingMorph,
        bool bUsingPreTessPatch,
        VertexStreamSpec_t *pStreamSpec)
{
  int v6; // eax
  D3DDeviceWrapper *v8; // esi
  VertexDeclLookup_t lookup; // [esp+8h] [ebp-114h] BYREF
  _D3DVERTEXELEMENT9 decl[32]; // [esp+18h] [ebp-104h] BYREF

  *(unsigned __int64 *)((char *)&lookup.m_VertexFormat + 4) = fmt;
  lookup.m_pDecl = (IDirect3DVertexDeclaration9 *)bStaticLit;
  if ( bUsingMorph )
    lookup.m_pDecl = (IDirect3DVertexDeclaration9 *)((int)lookup.m_pDecl | 2);
  if ( bUsingFlex )
    lookup.m_pDecl = (IDirect3DVertexDeclaration9 *)((int)lookup.m_pDecl | 4);
  if ( bUsingPreTessPatch )
    lookup.m_pDecl = (IDirect3DVertexDeclaration9 *)((int)lookup.m_pDecl | 8);
  v6 = CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Find(
         this: &s_VertexDeclDict,
         search: (const VertexDeclLookup_t *)((char *)&lookup.m_VertexFormat + 4));
  if ( v6 != -1 )
    return s_VertexDeclDict.m_Elements.m_pMemory[v6].m_Data.m_pDecl;
  ComputeVertexSpec(
    fmt,
    pDecl: (_D3DVERTEXELEMENT9 *)&decl[0].Type,
    bStaticLit,
    bUsingFlex,
    bUsingMorph,
    bUsingPreTessPatch,
    pStreamSpec);
  v8 = Dx9Device();
  D3DDeviceWrapper::Synchronize(this: v8);
  if ( v8->m_pD3DDevice->CreateVertexDeclaration(
         this: v8->m_pD3DDevice,
         a2: (const _D3DVERTEXELEMENT9 *)&decl[0].Type,
         a3: (IDirect3DVertexDeclaration9 **)decl) != 0 )
    _Warning(
      a1: " ERROR: failed to create vertex decl for vertex format %x! You'll probably see messed-up mesh rendering - to diagn"
      "ose, build shaderapidx9.dll in debug.\n",
      (_DWORD)fmt);
  CUtlRBTree<VertexDeclLookup_t,int,bool (__cdecl *)(VertexDeclLookup_t const &,VertexDeclLookup_t const &),CUtlMemory<UtlRBTreeNode_t<VertexDeclLookup_t,int>,int>>::Insert(
    this: &s_VertexDeclDict,
    insert: (const VertexDeclLookup_t *)((char *)&lookup.m_VertexFormat + 4));
  return *(IDirect3DVertexDeclaration9 **)&decl[0].Stream;
}

//------------------------------------------------------------------------------
// Address: 0x1003D150
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // eax
  unsigned __int16 v5; // cx
  unsigned __int16 index; // di
  int v7; // ebx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v11; // edx
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Iterator_t v12; // [esp+6h] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == 0xFFFF )
  {
    p_m_LastAlloc = &this->m_LastAlloc;
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
    {
      v5 = -1;
    }
    else
    {
      v5 = p_m_LastAlloc->index + 1;
    }
    v12.index = v5;
    index = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( p_m_LastAlloc->index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v12.index = (v7 > 0) - 1;
        v8 = &v12;
      }
      else
      {
        v8 = CUtlMemory<UtlRBTreeNode_t<CShaderDeviceDx10::InputLayout_t,unsigned short>,unsigned short>::Next(
               this: &this->m_Elements,
               result: &v12,
               it: &this->m_LastAlloc);
      }
      index = v8->index;
      if ( v8->index >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    p_m_LastAlloc->index = index;
    this->m_pElements = m_pMemory;
    return index;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[m_FirstFree].m_Right;
    this->m_pElements = v11;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D410
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D520
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Right; // bx
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
              this,
              i: elem)->m_Right;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                             this,
                                             i: m_Right)->m_Left;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Right)->m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Right)->m_Left].m_Parent = elem;
  if ( m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                                     this,
                                                     i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else
  {
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Left == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Right;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x1003D620
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 m_Left; // di
  int v4; // ebp
  const UtlRBTreeLinks_t<unsigned short> *v5; // eax

  m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
             this,
             i: elem)->m_Left;
  v4 = elem;
  this->m_Elements.m_pMemory[v4].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                            this,
                                            i: m_Left)->m_Right;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
         this,
         i: m_Left)->m_Right != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                 this,
                                 i: m_Left)->m_Right].m_Parent = elem;
  if ( m_Left != 0xFFFF )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                                    this,
                                                    i: elem)->m_Parent;
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else
  {
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
           this,
           i: v5->m_Parent)->m_Right == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Right = m_Left;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                                   this,
                                   i: elem)->m_Parent].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[v4].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x1003D760
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(int,int,class CUtlSymbolTable::CLess const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *__thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        int growSize,
        int initSize,
        const CUtlSymbolTable::CLess *lessfunc)
{
  this->m_Elements.m_pMemory = nullptr;
  this->m_Elements.m_nAllocationCount = initSize;
  this->m_Elements.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * initSize);
  this->m_Root = -1;
  this->m_FirstFree = -1;
  this->m_NumElements = 0;
  this->m_LastAlloc.index = -1;
  this->m_pElements = this->m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003D7C0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bp
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x1003D8D0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 i; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    i = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
               this,
               i)->m_Left != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(i + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        i = v3;
      }
      while ( v3 != 0xFFFF );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D990
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v5; // ecx
  unsigned __int16 m_Parent; // cx
  UtlRBTreeLinks_t<unsigned short> *v7; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v8; // ecx
  unsigned __int16 v9; // di
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v10; // ecx
  unsigned __int16 v11; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx
  unsigned __int16 v13; // dx
  UtlRBTreeLinks_t<unsigned short> *v14; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v15; // edx
  unsigned __int16 m_Right; // dx
  UtlRBTreeLinks_t<unsigned short> *v17; // ebp
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v18; // edx
  unsigned __int16 v19; // dx
  UtlRBTreeLinks_t<unsigned short> *v20; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v21; // edx
  unsigned __int16 m_Left; // dx
  UtlRBTreeLinks_t<unsigned short> *v23; // ebp
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v24; // edx
  unsigned __int16 v25; // dx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v26; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v5 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v7 = m_Parent == 0xFFFF
         ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v2 == 0xFFFF )
        v8 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v10 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      if ( v9 == 0xFFFF )
        v12 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = &this->m_Elements.m_pMemory[v9];
      v13 = v12->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
      }
      v14 = v13 == 0xFFFF
          ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : &this->m_Elements.m_pMemory[v13];
      if ( v14->m_Left == v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v15 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = &this->m_Elements.m_pMemory[v11];
        m_Right = v15->m_Right;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v17 = m_Right == 0xFFFF
            ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Right];
        if ( v17->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v18 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[elem];
          v19 = v18->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          v20 = v19 == 0xFFFF
              ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
              : &this->m_Elements.m_pMemory[v19];
          if ( v20->m_Right == elem )
          {
            elem = v9;
            CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
              this,
              elem: v9);
            v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        if ( v11 == 0xFFFF )
          v21 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[v11];
        m_Left = v21->m_Left;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
        }
        v23 = m_Left == 0xFFFF
            ? &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
            : &this->m_Elements.m_pMemory[m_Left];
        if ( v23->m_Tag != 0 )
        {
          if ( (v4 & 1) == 0 )
          {
            v4 |= 1u;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( elem == 0xFFFF )
            v24 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[elem];
          v25 = v24->m_Parent;
          if ( (v4 & 1) == 0 )
          {
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
            `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
          }
          if ( v25 == 0xFFFF )
            v26 = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v26 = &this->m_Elements.m_pMemory[v25];
          if ( v26->m_Left == elem )
          {
            elem = v9;
            CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
              this,
              elem: v9);
            v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                   this,
                   i: v9)->m_Parent;
            v11 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
                    this,
                    i: v9)->m_Parent;
          }
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v11);
        }
        else
        {
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Left].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
        }
      }
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003DFC0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E0B0
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E130
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  const CUtlSymbolTable::CStringPoolIndex *v2; // ebx
  unsigned __int16 v4; // di
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned __int16 v7[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = insert;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    parent: v7,
    leftchild: (bool *)&insert);
  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v4,
    parent: v7[0],
    isLeft: (bool)insert);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *v2;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D260
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *__thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)&`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

} // namespace shaderapidx10
