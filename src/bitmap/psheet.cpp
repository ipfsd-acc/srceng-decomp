// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/psheet.cpp
// Functions: 20
// ============================================================

#include "bitmap\psheet.h"

//------------------------------------------------------------------------------
// Address: 0x004CC6C0
// Name: public: bool CSheetExtended::ValidSheetData(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::ValidSheetData(CSheetExtended *this)
{
  return this->m_pSheetData != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CC6D0
// Name: void SpriteCardVert(class CMeshBuilder __near &,class Vector const __near &,float,struct SheetSequenceSample_t const __near *,struct SequenceSampleTextureCoords_t const __near *,struct SequenceSampleTextureCoords_t const __near *,struct SheetSequenceSample_t const __near *,struct SequenceSampleTextureCoords_t const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpriteCardVert(
        CMeshBuilder *meshBuilder,
        const Vector *vCenter,
        float flRadius,
        const SheetSequenceSample_t *pSample,
        const SequenceSampleTextureCoords_t *pSample0,
        const SequenceSampleTextureCoords_t *pSecondTexture0,
        const SheetSequenceSample_t *pSample1Data,
        const SequenceSampleTextureCoords_t *pSample1,
        float flChannel3U,
        float flChannel3V)
{
  float *m_pCurrPosition; // eax
  float *v11; // edx
  float m_fTop_V0; // xmm0_4
  float m_fRight_U0; // xmm1_4
  float m_fBottom_V0; // xmm2_4
  float m_fTop_V1; // xmm0_4
  float m_fRight_U1; // xmm1_4
  float m_fBottom_V1; // xmm2_4
  float *v18; // edx
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float *v28; // edx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float *v32; // edx
  float *v33; // ecx

  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = vCenter->x;
  m_pCurrPosition[1] = vCenter->y;
  v11 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  m_pCurrPosition[2] = vCenter->z;
  m_fTop_V0 = pSample0->m_fTop_V0;
  m_fRight_U0 = pSample0->m_fRight_U0;
  m_fBottom_V0 = pSample0->m_fBottom_V0;
  *v11 = pSample0->m_fLeft_U0;
  v11[1] = m_fTop_V0;
  v11[2] = m_fRight_U0;
  v11[3] = m_fBottom_V0;
  m_fTop_V1 = pSample0->m_fTop_V1;
  m_fRight_U1 = pSample0->m_fRight_U1;
  m_fBottom_V1 = pSample0->m_fBottom_V1;
  v18 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
  v19 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[2];
  *v18 = pSample0->m_fLeft_U1;
  v18[1] = m_fTop_V1;
  v18[2] = m_fRight_U1;
  v18[3] = m_fBottom_V1;
  *v19 = pSample->m_fBlendFactor;
  v19[1] = 0.0;
  v19[2] = flRadius;
  v19[3] = 0.0;
  v20 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[3];
  *v20 = flChannel3U;
  v20[1] = flChannel3V;
  v21 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[4];
  v22 = pSecondTexture0->m_fTop_V0;
  v23 = pSecondTexture0->m_fRight_U0;
  v24 = pSecondTexture0->m_fBottom_V0;
  *v21 = pSecondTexture0->m_fLeft_U0;
  v21[1] = v22;
  v21[2] = v23;
  v21[3] = v24;
  if ( pSample1 != nullptr )
  {
    v25 = pSample1->m_fTop_V0;
    v26 = pSample1->m_fRight_U0;
    v27 = pSample1->m_fBottom_V0;
    v28 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[5];
    *v28 = pSample1->m_fLeft_U0;
    v28[1] = v25;
    v28[2] = v26;
    v28[3] = v27;
    v29 = pSample1->m_fTop_V1;
    v30 = pSample1->m_fRight_U1;
    v31 = pSample1->m_fBottom_V1;
    v32 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[6];
    v33 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[7];
    *v32 = pSample1->m_fLeft_U1;
    v32[1] = v29;
    v32[2] = v30;
    v32[3] = v31;
    *v33 = pSample1Data->m_fBlendFactor;
    v33[1] = 0.0;
    v33[2] = 0.0;
    v33[3] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC830
// Name: public: static bool CSheetExtended::IsMaterialDualSequence(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSheetExtended::IsMaterialDualSequence(IMaterial *pMat)
{
  IMaterial *v1; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v4; // eax
  int v5; // esi

  v1 = pMat;
  if ( pMat == nullptr )
    return false;
  FindVar = pMat->FindVar;
  HIBYTE(pMat) = 0;
  v4 = (int)FindVar(this: v1, a2: "$DUALSEQUENCE", a3: (bool *)&pMat + 3, a4: true);
  v5 = v4;
  return v4 != 0
      && HIBYTE(pMat) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4) != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 108))(a1: v5) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CC890
// Name: public: static bool CSheetExtended::IsMaterialSeparateAlphaColorMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSheetExtended::IsMaterialSeparateAlphaColorMaterial(IMaterial *pMat)
{
  IMaterial *v1; // esi
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  int v3; // esi
  bool result; // al

  v1 = pMat;
  result = pMat != nullptr
        && CSheetExtended::IsMaterialDualSequence(pMat)
        && (FindVar = v1->FindVar,
            HIBYTE(pMat) = 0,
            (v3 = (int)FindVar(this: v1, a2: "$SEQUENCE_BLEND_MODE", a3: (bool *)&pMat + 3, a4: true)) != 0)
        && HIBYTE(pMat) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 72))(a1: v3) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 108))(a1: v3) == 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CC8F0
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CC990
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CCA00
// Name: public: struct SheetSequenceSample_t const __near * CSheet::GetSampleForSequence(float,float,int,bool)
// Source: json
//------------------------------------------------------------------------------
const SheetSequenceSample_t *__thiscall CSheet::GetSampleForSequence(
        CSheet *this,
        float flAge,
        float flAgeScale,
        int nSequence,
        bool bForceLoop)
{
  CSheet::SheetInfo_t *v5; // ecx
  unsigned int v7; // eax

  v5 = &this->m_SheetInfo.m_Memory.m_pMemory[nSequence];
  if ( v5->m_nNumFrames == 1 )
    return v5->m_pSamples;
  v7 = (__int64)(flAge * flAgeScale);
  if ( (v5->m_SeqFlags & 1) == 0 || bForceLoop )
  {
    v7 &= 0x1FFu;
  }
  else if ( v7 >= 0x1FF )
  {
    return v5->m_pSamples + 511;
  }
  return &v5->m_pSamples[v7];
}

//------------------------------------------------------------------------------
// Address: 0x004CCA90
// Name: public: int CSheetExtended::GetSheetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetExtended::GetSheetSequenceCount(CSheetExtended *this)
{
  CSheet *m_pSheetData; // ecx
  int result; // eax
  int m_Size; // edx
  bool *p_m_bSequenceIsCopyOfAnotherSequence; // ecx

  m_pSheetData = this->m_pSheetData;
  result = 0;
  if ( m_pSheetData != nullptr )
  {
    m_Size = m_pSheetData->m_SheetInfo.m_Size;
    if ( m_Size > 0 )
    {
      p_m_bSequenceIsCopyOfAnotherSequence = &m_pSheetData->m_SheetInfo.m_Memory.m_pMemory->m_bSequenceIsCopyOfAnotherSequence;
      do
      {
        if ( !*p_m_bSequenceIsCopyOfAnotherSequence )
          ++result;
        p_m_bSequenceIsCopyOfAnotherSequence += 12;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CCAC0
// Name: public: int CSheetExtended::GetNthSequenceIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetExtended::GetNthSequenceIndex(CSheetExtended *this, int nSequenceNumber)
{
  CSheet *m_pSheetData; // ecx
  int result; // eax
  int m_Size; // edx
  int v5; // esi
  bool *p_m_bSequenceIsCopyOfAnotherSequence; // ecx

  m_pSheetData = this->m_pSheetData;
  result = 0;
  if ( m_pSheetData != nullptr )
  {
    m_Size = m_pSheetData->m_SheetInfo.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      p_m_bSequenceIsCopyOfAnotherSequence = &m_pSheetData->m_SheetInfo.m_Memory.m_pMemory->m_bSequenceIsCopyOfAnotherSequence;
      do
      {
        if ( !*p_m_bSequenceIsCopyOfAnotherSequence )
        {
          if ( v5 == nSequenceNumber )
            return result;
          ++v5;
        }
        ++result;
        p_m_bSequenceIsCopyOfAnotherSequence += 12;
      }
      while ( result < m_Size );
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CCB00
// Name: public: float CSheetExtended::GetSequenceTimeSpan(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSheetExtended::GetSequenceTimeSpan(CSheetExtended *this, int nSequenceIndex)
{
  CSheet *m_pSheetData; // ecx

  m_pSheetData = this->m_pSheetData;
  if ( m_pSheetData != nullptr )
    return m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_flFrameSpan;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004CCB20
// Name: public: bool CSheetExtended::SequenceHasAlphaData(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::SequenceHasAlphaData(CSheetExtended *this, int nSequenceIndex)
{
  return (this->m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_SeqFlags & 2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CCB40
// Name: public: bool CSheetExtended::SequenceHasColorData(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::SequenceHasColorData(CSheetExtended *this, int nSequenceIndex)
{
  return (this->m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_SeqFlags & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CCB60
// Name: public: void CSheetExtended::DrawSheet(class IMesh __near *,class Vector const __near &,float,int,float,float,bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::DrawSheet(
        CSheetExtended *this,
        IMesh *pMesh,
        const Vector *vCenter,
        float flRadius,
        const SequenceSampleTextureCoords_t *nSheetSequence,
        float flAge,
        float flSheetPreviewSpeed,
        bool bLoopSheetPreview,
        int nSecondarySequence,
        bool bOverrideSpriteCard)
{
  IMaterial *m_pMaterial; // ecx
  const SheetSequenceSample_t *v12; // ebx
  SheetSequenceSample_t *SampleForSequence; // edi
  float *m_pCurrPosition; // eax
  float v15; // xmm2_4
  float z; // xmm0_4
  float *v17; // eax
  float m_fTop_V0; // xmm0_4
  float *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  float *v22; // eax
  float v23; // xmm0_4
  float *v24; // eax
  float v25; // xmm2_4
  float v26; // xmm1_4
  float *v27; // eax
  float m_fBottom_V0; // xmm0_4
  float *v29; // eax
  float v30; // xmm2_4
  float v31; // xmm1_4
  float *v32; // eax
  float v33; // xmm0_4
  int m_nVertexCount; // eax
  void (__thiscall *Draw_2)(IMesh *, int, int); // edx
  CMeshBuilder meshBuilder; // [esp+40h] [ebp-1ECh] BYREF
  CSheetExtended *v37; // [esp+228h] [ebp-4h]
  const SequenceSampleTextureCoords_t *pSample1; // [esp+240h] [ebp+14h]
  bool bSpriteCardMaterial; // [esp+257h] [ebp+2Bh]

  v37 = this;
  if ( bOverrideSpriteCard
    || (m_pMaterial = this->m_Material.m_pMaterial) == nullptr
    || (bSpriteCardMaterial = true, !m_pMaterial->IsSpriteCard(this: m_pMaterial)) )
  {
    bSpriteCardMaterial = false;
  }
  v12 = nullptr;
  if ( this->m_pSheetData != nullptr )
    SampleForSequence = (SheetSequenceSample_t *)CSheet::GetSampleForSequence(
                                                   this: this->m_pSheetData,
                                                   flAge,
                                                   flAgeScale: flSheetPreviewSpeed,
                                                   nSequence: (int)nSheetSequence,
                                                   bForceLoop: bLoopSheetPreview);
  else
    SampleForSequence = &s_DefaultSheetSequence;
  pSample1 = nullptr;
  if ( nSecondarySequence != -1 && CSheetExtended::IsMaterialDualSequence(pMat: v37->m_Material.m_pMaterial) )
  {
    if ( v37->m_pSheetData != nullptr )
      v12 = CSheet::GetSampleForSequence(
              this: v37->m_pSheetData,
              flAge: flAge * 0.1,
              flAgeScale: flSheetPreviewSpeed,
              nSequence: nSecondarySequence,
              bForceLoop: bLoopSheetPreview);
    else
      v12 = &s_DefaultSheetSequence;
    pSample1 = (const SequenceSampleTextureCoords_t *)v12;
  }
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = pMesh;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 0.0,
      flChannel3V: 0.0);
  }
  else
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v15 = vCenter->y + COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_);
    z = vCenter->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) + vCenter->x;
    m_pCurrPosition[1] = v15;
    m_pCurrPosition[2] = z;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    m_fTop_V0 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
    v17[1] = m_fTop_V0;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 1.0,
      flChannel3V: 0.0);
  }
  else
  {
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v20 = vCenter->y + COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_);
    v21 = vCenter->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + flRadius;
    v19[1] = v20;
    v19[2] = v21;
    v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v23 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
    v22[1] = v23;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 1.0,
      flChannel3V: 1.0);
  }
  else
  {
    v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v25 = vCenter->z;
    v26 = vCenter->y + flRadius;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + flRadius;
    v24[1] = v26;
    v24[2] = v25;
    v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    m_fBottom_V0 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
    v27[1] = m_fBottom_V0;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 0.0,
      flChannel3V: 1.0);
  }
  else
  {
    v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v30 = vCenter->z;
    v31 = vCenter->y + flRadius;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) + vCenter->x;
    v29[1] = v31;
    v29[2] = v30;
    v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v33 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
    v32[1] = v33;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  Draw_2 = pMesh->Draw_2;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  Draw_2(this: pMesh, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD060
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD110
// Name: public: CSheet::~CSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheet::~CSheet(CSheet *this)
{
  int v2; // ebx
  int v3; // edi
  CSheet::SheetInfo_t *m_pMemory; // eax
  CSheet::SheetInfo_t *v5; // eax
  CUtlReference<CSheet> *m_pHead; // eax
  CUtlReference<CSheet> *m_pNext; // ecx

  v2 = 0;
  if ( this->m_SheetInfo.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_SheetInfo.m_Memory.m_pMemory;
      if ( m_pMemory[v3].m_pSamples != nullptr && !m_pMemory[v3].m_bSequenceIsCopyOfAnotherSequence )
        free(pMem: m_pMemory[v3].m_pSamples);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SheetInfo.m_Size );
  }
  this->m_SheetInfo.m_Size = 0;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SheetInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SheetInfo.m_Memory.m_pMemory);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_SheetInfo.m_Memory.m_pMemory;
  this->m_SheetInfo.m_pElements = v5;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( this->m_References.m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CD1C0
// Name: public: CSheet::CSheet(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CSheet::CSheet(CSheet *this, CUtlBuffer *buf)
{
  CSheet *v2; // esi
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_SheetInfo; // ebx
  int Int; // eax
  int v5; // edi
  bool v6; // zf
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v7; // eax
  int v8; // eax
  int v9; // edi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v12; // ecx
  int v13; // eax
  int v14; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *j; // eax
  int v17; // eax
  int v18; // edi
  int v19; // esi
  int v20; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v21; // ecx
  int v22; // eax
  int v23; // eax
  int v24; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v25; // edi
  int v26; // eax
  int v27; // esi
  int v28; // esi
  int v29; // ecx
  char *v30; // eax
  float *v31; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v32; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v33; // eax
  int v34; // eax
  int v35; // ecx
  float *v36; // eax
  int v37; // esi
  _DWORD v38[2]; // [esp+20h] [ebp-98D8h] BYREF
  char v39; // [esp+28h] [ebp-98D0h] BYREF
  float pKnotPositions[512]; // [esp+8820h] [ebp-10D8h] BYREF
  float pKnotValues[546]; // [esp+9020h] [ebp-8D8h] BYREF
  float v42; // [esp+98A8h] [ebp-50h] BYREF
  float v43; // [esp+98ACh] [ebp-4Ch] BYREF
  float v44; // [esp+98B0h] [ebp-48h] BYREF
  float v45; // [esp+98B4h] [ebp-44h]
  float v46; // [esp+98B8h] [ebp-40h] BYREF
  float pInterpolationValue; // [esp+98BCh] [ebp-3Ch] BYREF
  float dest; // [esp+98C0h] [ebp-38h] BYREF
  float pValueB; // [esp+98C4h] [ebp-34h] BYREF
  float pValueA; // [esp+98C8h] [ebp-30h] BYREF
  float v51; // [esp+98CCh] [ebp-2Ch] BYREF
  int v52; // [esp+98D0h] [ebp-28h]
  int i; // [esp+98D4h] [ebp-24h]
  int v54; // [esp+98D8h] [ebp-20h]
  float v55; // [esp+98DCh] [ebp-1Ch]
  int v56; // [esp+98E0h] [ebp-18h]
  int v57; // [esp+98E4h] [ebp-14h]
  CSheet *v58; // [esp+98E8h] [ebp-10h]
  int v59; // [esp+98ECh] [ebp-Ch]
  char *v60; // [esp+98F0h] [ebp-8h]
  int nNumValuesinList; // [esp+98F4h] [ebp-4h]
  CUtlBuffer *v62; // [esp+9900h] [ebp+8h]

  v2 = this;
  this->m_References.m_pHead = nullptr;
  p_m_SheetInfo = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_SheetInfo;
  v58 = this;
  this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
  this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  this->m_SheetInfo.m_Memory.m_nGrowSize = 0;
  this->m_SheetInfo.m_Size = 0;
  this->m_SheetInfo.m_pElements = nullptr;
  v54 = CUtlBuffer::GetInt(this: buf) != 0 ? 4 : 1;
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = Int;
  v56 = Int;
  nNumValuesinList = Int;
  if ( Int < 64 )
    nNumValuesinList = 64;
  if ( p_m_SheetInfo->m_nAllocationCount < Int && p_m_SheetInfo->m_nGrowSize >= 0 )
  {
    v6 = p_m_SheetInfo->m_pMemory == nullptr;
    p_m_SheetInfo->m_nAllocationCount = Int;
    if ( v6 )
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * Int);
    else
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: p_m_SheetInfo->m_pMemory,
                                                          a3: 12 * Int);
    p_m_SheetInfo->m_pMemory = v7;
  }
  v8 = nNumValuesinList;
  p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( nNumValuesinList = v8; nNumValuesinList != 0; --nNumValuesinList )
    {
      m_pMemory = p_m_SheetInfo[1].m_pMemory;
      m_nAllocationCount = p_m_SheetInfo->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_m_SheetInfo,
          num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
      ++p_m_SheetInfo[1].m_pMemory;
      v12 = p_m_SheetInfo->m_pMemory;
      v13 = (char *)p_m_SheetInfo[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[(int)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 12 * v13);
      p_m_SheetInfo->m_pMemory[v9].m_Element = nullptr;
      LOBYTE(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      BYTE1(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      HIWORD(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      p_m_SheetInfo->m_pMemory[v9++].m_Next = 0;
    }
    v2 = v58;
    v5 = v56;
  }
  if ( v5 != 0 )
  {
    while ( 1 )
    {
      v56 = v5 - 1;
      v17 = CUtlBuffer::GetInt(this: buf);
      v18 = v17;
      if ( v17 < 0 )
        break;
      if ( v17 >= v2->m_SheetInfo.m_Size )
      {
        do
        {
          v19 = (int)p_m_SheetInfo[1].m_pMemory;
          v20 = p_m_SheetInfo->m_nAllocationCount;
          if ( v19 + 1 > v20 )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: p_m_SheetInfo, num: v19 - v20 + 1);
          ++p_m_SheetInfo[1].m_pMemory;
          v21 = p_m_SheetInfo->m_pMemory;
          v22 = (int)p_m_SheetInfo[1].m_pMemory - v19 - 1;
          p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
          if ( v22 > 0 )
            _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 12 * v22);
          v23 = v19;
          p_m_SheetInfo->m_pMemory[v23].m_Element = nullptr;
          LOBYTE(p_m_SheetInfo->m_pMemory[v23].m_Previous) = 0;
          BYTE1(p_m_SheetInfo->m_pMemory[v23].m_Previous) = 0;
          HIWORD(p_m_SheetInfo->m_pMemory[v23].m_Previous) = 0;
          p_m_SheetInfo->m_pMemory[v23].m_Next = 0;
        }
        while ( v19 < v18 );
      }
      v24 = 3 * v18;
      v25 = p_m_SheetInfo->m_pMemory;
      v24 *= 4;
      v57 = v24;
      *((_BYTE *)&v25->m_Previous + v24) = CUtlBuffer::GetInt(this: buf);
      v26 = CUtlBuffer::GetInt(this: buf);
      *(_WORD *)((char *)&p_m_SheetInfo->m_pMemory->m_Previous + v24 + 2) = v26;
      v27 = v26 != 1 ? 512 : 1;
      nNumValuesinList = v26;
      v52 = v27;
      *(vgui::TreeNode **)((char *)&p_m_SheetInfo->m_pMemory->m_Element + v57) = (vgui::TreeNode *)MemAlloc_Alloc(nSize: 68 * v27);
      CUtlBuffer::GetType<float>(this: buf, &dest);
      v28 = 0;
      v55 = 0.0;
      v59 = 0;
      if ( nNumValuesinList > 0 )
      {
        v45 = 1.0 / (float)(int)dest;
        v60 = &v39;
        do
        {
          CUtlBuffer::GetType<float>(this: buf, dest: &v43);
          v29 = v54;
          v30 = v60;
          pKnotValues[v28] = (float)v28;
          pKnotPositions[v28] = (float)(v45 * v55) * 512.0;
          *((_DWORD *)v30 + 14) = 0;
          if ( v29 > 0 )
          {
            v31 = (float *)v30;
            for ( i = v29; i != 0; --i )
            {
              CUtlBuffer::GetType<float>(this: buf, dest: &v51);
              *(v31 - 2) = v51;
              CUtlBuffer::GetType<float>(this: buf, dest: &v44);
              *(v31 - 1) = v44;
              CUtlBuffer::GetType<float>(this: buf, dest: &v46);
              *v31 = v46;
              CUtlBuffer::GetType<float>(this: buf, dest: &v42);
              v31[1] = v42;
              v31 += 8;
            }
            v29 = v54;
            v28 = v59;
            v30 = v60;
          }
          if ( v29 == 1 )
          {
            *((_QWORD *)v30 + 3) = *((_QWORD *)v30 - 1);
            *((_QWORD *)v30 + 4) = *(_QWORD *)v30;
            *((_QWORD *)v30 + 5) = *((_QWORD *)v30 + 1);
            *((_QWORD *)v30 + 6) = *((_QWORD *)v30 + 2);
          }
          v32 = p_m_SheetInfo->m_pMemory;
          ++v28;
          v55 = v43 + v55;
          *(float *)((char *)&v32->m_Next + v57) = v55;
          v59 = v28;
          v60 = v30 + 68;
        }
        while ( v28 < nNumValuesinList );
      }
      v60 = nullptr;
      if ( v52 > 0 )
      {
        v59 = 0;
        do
        {
          GetInterpolationData(
            pKnotPositions,
            pKnotValues,
            nNumValuesinList,
            nInterpolationRange: 512,
            flPositionToInterpolateAt: (float)(int)v60,
            bWrap: (*((_BYTE *)&p_m_SheetInfo->m_pMemory->m_Previous + v57) & 1) == 0,
            &pValueA,
            &pValueB,
            &pInterpolationValue);
          v33 = p_m_SheetInfo->m_pMemory;
          qmemcpy(&pKnotValues[529], &v38[17 * (int)pValueA], 0x44u);
          qmemcpy(&pKnotValues[512], &v38[17 * (int)pValueB], 0x44u);
          v34 = *(int *)((char *)&v33->m_Element + v57);
          v35 = v59;
          *(float *)(v34 + v59 + 64) = pInterpolationValue;
          *(float *)(v34 + v35) = pKnotValues[529];
          *(float *)(v34 + v35 + 4) = pKnotValues[530];
          *(float *)(v34 + v35 + 8) = pKnotValues[531];
          *(float *)(v34 + v35 + 12) = pKnotValues[532];
          *(float *)(v34 + v35 + 16) = pKnotValues[512];
          *(float *)(v34 + v35 + 20) = pKnotValues[513];
          v36 = (float *)(v35 + v34);
          v36[6] = pKnotValues[514];
          v36[7] = pKnotValues[515];
          v36[8] = pKnotValues[537];
          v36[9] = pKnotValues[538];
          v36[10] = pKnotValues[539];
          v36[11] = pKnotValues[540];
          v36[12] = pKnotValues[520];
          v36[13] = pKnotValues[521];
          v36[14] = pKnotValues[522];
          v36[15] = pKnotValues[523];
          ++v60;
          v59 = v35 + 68;
        }
        while ( (int)v60 < v52 );
      }
      v2 = v58;
      if ( v56 == 0 )
        goto LABEL_18;
      v5 = v56;
    }
    _Warning(a1: "Invalid sequence number (%d)!!!\n", v17);
    return v2;
  }
  else
  {
LABEL_18:
    v14 = 0;
    if ( v2->m_SheetInfo.m_Size <= 0 )
      return v2;
    for ( j = p_m_SheetInfo->m_pMemory; j->m_Element == nullptr; ++j )
    {
      if ( ++v14 >= v2->m_SheetInfo.m_Size )
        return v2;
    }
    if ( v14 == -1 )
    {
      return v2;
    }
    else
    {
      v62 = nullptr;
      v37 = 0;
      do
      {
        if ( p_m_SheetInfo->m_pMemory[v37].m_Element == nullptr )
        {
          p_m_SheetInfo->m_pMemory[v37].m_Element = p_m_SheetInfo->m_pMemory[v14].m_Element;
          LOBYTE(p_m_SheetInfo->m_pMemory[v37].m_Previous) = p_m_SheetInfo->m_pMemory[v14].m_Previous;
          HIWORD(p_m_SheetInfo->m_pMemory[v37].m_Previous) = HIWORD(p_m_SheetInfo->m_pMemory[v14].m_Previous);
          BYTE1(p_m_SheetInfo->m_pMemory[v37].m_Previous) = 1;
        }
        ++v37;
        v62 = (CUtlBuffer *)((char *)v62 + 1);
      }
      while ( (int)v62 < v58->m_SheetInfo.m_Size );
      return v58;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD7A0
// Name: public: CSheetExtended::~CSheetExtended(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::~CSheetExtended(CSheetExtended *this)
{
  CSheet *m_pSheetData; // esi

  m_pSheetData = this->m_pSheetData;
  if ( this->m_pSheetData != nullptr )
  {
    CSheet::~CSheet(this: this->m_pSheetData);
    free(pMem: m_pSheetData);
  }
  CMaterialReference::~CMaterialReference(this: &this->m_Material);
}

//------------------------------------------------------------------------------
// Address: 0x004CD7D0
// Name: private: void CSheetExtended::LoadFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::LoadFromBuffer(CSheetExtended *this, CUtlBuffer *buf)
{
  CSheet *v3; // eax

  v3 = (CSheet *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
    this->m_pSheetData = CSheet::CSheet(this: v3, buf);
  else
    this->m_pSheetData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004CD800
// Name: private: void CSheetExtended::LoadFromMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::LoadFromMaterial(CSheetExtended *this, IMaterial *pMaterial)
{
  IMaterial *v3; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v5; // eax
  int (__thiscall ***v6)(_DWORD); // esi
  int v7; // eax
  int v8; // esi
  unsigned __int8 *v9; // eax
  CUtlBuffer bufLoad; // [esp+4h] [ebp-34h] BYREF
  unsigned int nBytes; // [esp+34h] [ebp-4h] BYREF

  v3 = pMaterial;
  if ( pMaterial != nullptr )
  {
    FindVar = pMaterial->FindVar;
    HIBYTE(pMaterial) = 0;
    v5 = (int)FindVar(this: v3, a2: "$basetexture", a3: (bool *)&pMaterial + 3, a4: true);
    v6 = (int (__thiscall ***)(_DWORD))v5;
    if ( v5 != 0 && HIBYTE(pMaterial) != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 72))(a1: v5) != 0 )
    {
      v7 = (**v6)(a1: v6);
      v8 = v7;
      if ( v7 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 60))(a1: v7) == 0 )
      {
        v9 = (unsigned __int8 *)(*(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v8 + 36))(
                                  a1: v8,
                                  a2: 16,
                                  a3: &nBytes);
        if ( v9 != nullptr )
        {
          CUtlBuffer::CUtlBuffer(this: &bufLoad, pBuffer: v9, nSize: nBytes, nFlags: 8u);
          CSheetExtended::LoadFromBuffer(this, buf: &bufLoad);
          CUtlBuffer::~CUtlBuffer(this: &bufLoad);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD8A0
// Name: public: CSheetExtended::CSheetExtended(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CSheetExtended *__thiscall CSheetExtended::CSheetExtended(CSheetExtended *this, IMaterial *pMaterial)
{
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::Init(this: &this->m_Material, pMaterial);
  this->m_pSheetData = nullptr;
  CSheetExtended::LoadFromMaterial(this, pMaterial);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1029EEB0
// Name: public: bool CSheetExtended::ValidSheetData(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::ValidSheetData(CSheetExtended *this)
{
  return this->m_pSheetData != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1029EEC0
// Name: void SpriteCardVert(class CMeshBuilder __near &,class Vector const __near &,float,struct SheetSequenceSample_t const __near *,struct SequenceSampleTextureCoords_t const __near *,struct SequenceSampleTextureCoords_t const __near *,struct SheetSequenceSample_t const __near *,struct SequenceSampleTextureCoords_t const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpriteCardVert(
        CMeshBuilder *meshBuilder,
        const Vector *vCenter,
        float flRadius,
        const SheetSequenceSample_t *pSample,
        const SequenceSampleTextureCoords_t *pSample0,
        const SequenceSampleTextureCoords_t *pSecondTexture0,
        const SheetSequenceSample_t *pSample1Data,
        const SequenceSampleTextureCoords_t *pSample1,
        float flChannel3U,
        float flChannel3V)
{
  float *m_pCurrPosition; // eax
  float *v11; // edx
  float m_fTop_V0; // xmm0_4
  float m_fRight_U0; // xmm1_4
  float m_fBottom_V0; // xmm2_4
  float m_fTop_V1; // xmm0_4
  float m_fRight_U1; // xmm1_4
  float m_fBottom_V1; // xmm2_4
  float *v18; // edx
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float *v28; // edx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float *v32; // edx
  float *v33; // ecx

  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = vCenter->x;
  m_pCurrPosition[1] = vCenter->y;
  v11 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  m_pCurrPosition[2] = vCenter->z;
  m_fTop_V0 = pSample0->m_fTop_V0;
  m_fRight_U0 = pSample0->m_fRight_U0;
  m_fBottom_V0 = pSample0->m_fBottom_V0;
  *v11 = pSample0->m_fLeft_U0;
  v11[1] = m_fTop_V0;
  v11[2] = m_fRight_U0;
  v11[3] = m_fBottom_V0;
  m_fTop_V1 = pSample0->m_fTop_V1;
  m_fRight_U1 = pSample0->m_fRight_U1;
  m_fBottom_V1 = pSample0->m_fBottom_V1;
  v18 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
  v19 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[2];
  *v18 = pSample0->m_fLeft_U1;
  v18[1] = m_fTop_V1;
  v18[2] = m_fRight_U1;
  v18[3] = m_fBottom_V1;
  *v19 = pSample->m_fBlendFactor;
  v19[1] = 0.0;
  v19[2] = flRadius;
  v19[3] = 0.0;
  v20 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[3];
  *v20 = flChannel3U;
  v20[1] = flChannel3V;
  v21 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[4];
  v22 = pSecondTexture0->m_fTop_V0;
  v23 = pSecondTexture0->m_fRight_U0;
  v24 = pSecondTexture0->m_fBottom_V0;
  *v21 = pSecondTexture0->m_fLeft_U0;
  v21[1] = v22;
  v21[2] = v23;
  v21[3] = v24;
  if ( pSample1 != nullptr )
  {
    v25 = pSample1->m_fTop_V0;
    v26 = pSample1->m_fRight_U0;
    v27 = pSample1->m_fBottom_V0;
    v28 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[5];
    *v28 = pSample1->m_fLeft_U0;
    v28[1] = v25;
    v28[2] = v26;
    v28[3] = v27;
    v29 = pSample1->m_fTop_V1;
    v30 = pSample1->m_fRight_U1;
    v31 = pSample1->m_fBottom_V1;
    v32 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[6];
    v33 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[7];
    *v32 = pSample1->m_fLeft_U1;
    v32[1] = v29;
    v32[2] = v30;
    v32[3] = v31;
    *v33 = pSample1Data->m_fBlendFactor;
    v33[1] = 0.0;
    v33[2] = 0.0;
    v33[3] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029F020
// Name: public: static bool CSheetExtended::IsMaterialDualSequence(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSheetExtended::IsMaterialDualSequence(IMaterial *pMat)
{
  IMaterial *v1; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v4; // eax
  int v5; // esi

  v1 = pMat;
  if ( pMat == nullptr )
    return false;
  FindVar = pMat->FindVar;
  HIBYTE(pMat) = 0;
  v4 = (int)FindVar(this: v1, a2: "$DUALSEQUENCE", a3: (bool *)&pMat + 3, a4: true);
  v5 = v4;
  return v4 != 0
      && HIBYTE(pMat) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4) != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 108))(a1: v5) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1029F080
// Name: public: static bool CSheetExtended::IsMaterialSeparateAlphaColorMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSheetExtended::IsMaterialSeparateAlphaColorMaterial(IMaterial *pMat)
{
  IMaterial *v1; // esi
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  int v3; // esi
  bool result; // al

  v1 = pMat;
  result = pMat != nullptr
        && CSheetExtended::IsMaterialDualSequence(pMat)
        && (FindVar = v1->FindVar,
            HIBYTE(pMat) = 0,
            (v3 = (int)FindVar(this: v1, a2: "$SEQUENCE_BLEND_MODE", a3: (bool *)&pMat + 3, a4: true)) != 0)
        && HIBYTE(pMat) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 72))(a1: v3) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 108))(a1: v3) == 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029F0E0
// Name: public: struct SheetSequenceSample_t const __near * CSheet::GetSampleForSequence(float,float,int,bool)
// Source: json
//------------------------------------------------------------------------------
const SheetSequenceSample_t *__thiscall CSheet::GetSampleForSequence(
        CSheet *this,
        float flAge,
        float flAgeScale,
        int nSequence,
        bool bForceLoop)
{
  CSheet::SheetInfo_t *v5; // ecx
  unsigned int v7; // eax

  v5 = &this->m_SheetInfo.m_Memory.m_pMemory[nSequence];
  if ( v5->m_nNumFrames == 1 )
    return v5->m_pSamples;
  v7 = (__int64)(flAge * flAgeScale);
  if ( (v5->m_SeqFlags & 1) == 0 || bForceLoop )
  {
    v7 &= 0x1FFu;
  }
  else if ( v7 >= 0x1FF )
  {
    return v5->m_pSamples + 511;
  }
  return &v5->m_pSamples[v7];
}

//------------------------------------------------------------------------------
// Address: 0x1029F170
// Name: public: int CSheetExtended::GetSheetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetExtended::GetSheetSequenceCount(CSheetExtended *this)
{
  CSheet *m_pSheetData; // ecx
  int result; // eax
  int m_Size; // edx
  bool *p_m_bSequenceIsCopyOfAnotherSequence; // ecx

  m_pSheetData = this->m_pSheetData;
  result = 0;
  if ( m_pSheetData != nullptr )
  {
    m_Size = m_pSheetData->m_SheetInfo.m_Size;
    if ( m_Size > 0 )
    {
      p_m_bSequenceIsCopyOfAnotherSequence = &m_pSheetData->m_SheetInfo.m_Memory.m_pMemory->m_bSequenceIsCopyOfAnotherSequence;
      do
      {
        if ( !*p_m_bSequenceIsCopyOfAnotherSequence )
          ++result;
        p_m_bSequenceIsCopyOfAnotherSequence += 12;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029F1A0
// Name: public: int CSheetExtended::GetNthSequenceIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetExtended::GetNthSequenceIndex(CSheetExtended *this, int nSequenceNumber)
{
  CSheet *m_pSheetData; // ecx
  int result; // eax
  int m_Size; // edx
  int v5; // esi
  bool *p_m_bSequenceIsCopyOfAnotherSequence; // ecx

  m_pSheetData = this->m_pSheetData;
  result = 0;
  if ( m_pSheetData != nullptr )
  {
    m_Size = m_pSheetData->m_SheetInfo.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      p_m_bSequenceIsCopyOfAnotherSequence = &m_pSheetData->m_SheetInfo.m_Memory.m_pMemory->m_bSequenceIsCopyOfAnotherSequence;
      do
      {
        if ( !*p_m_bSequenceIsCopyOfAnotherSequence )
        {
          if ( v5 == nSequenceNumber )
            return result;
          ++v5;
        }
        ++result;
        p_m_bSequenceIsCopyOfAnotherSequence += 12;
      }
      while ( result < m_Size );
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029F1E0
// Name: public: float CSheetExtended::GetSequenceTimeSpan(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSheetExtended::GetSequenceTimeSpan(CSheetExtended *this, int nSequenceIndex)
{
  CSheet *m_pSheetData; // ecx

  m_pSheetData = this->m_pSheetData;
  if ( m_pSheetData != nullptr )
    return m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_flFrameSpan;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1029F200
// Name: public: bool CSheetExtended::SequenceHasAlphaData(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::SequenceHasAlphaData(CSheetExtended *this, int nSequenceIndex)
{
  return (this->m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_SeqFlags & 2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1029F220
// Name: public: bool CSheetExtended::SequenceHasColorData(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::SequenceHasColorData(CSheetExtended *this, int nSequenceIndex)
{
  return (this->m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_SeqFlags & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1029F240
// Name: public: void CSheetExtended::DrawSheet(class IMesh __near *,class Vector const __near &,float,int,float,float,bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::DrawSheet(
        CSheetExtended *this,
        IMesh *pMesh,
        const Vector *vCenter,
        float flRadius,
        int nSheetSequence,
        __int64 flAge,
        bool bLoopSheetPreview,
        int nSecondarySequence,
        bool bOverrideSpriteCard)
{
  IMaterial *m_pMaterial; // ecx
  const SheetSequenceSample_t *v11; // ebx
  SheetSequenceSample_t *SampleForSequence; // edi
  float *m_pCurrPosition; // eax
  float v14; // xmm2_4
  float z; // xmm0_4
  float *v16; // eax
  float m_fTop_V0; // xmm0_4
  float *v18; // eax
  float v19; // xmm2_4
  float v20; // xmm0_4
  float *v21; // eax
  float v22; // xmm0_4
  float *v23; // eax
  float v24; // xmm2_4
  float v25; // xmm1_4
  float *v26; // eax
  float m_fBottom_V0; // xmm0_4
  float *v28; // eax
  float v29; // xmm2_4
  float v30; // xmm1_4
  float *v31; // eax
  float v32; // xmm0_4
  int m_nVertexCount; // eax
  void (__thiscall *Draw_2)(IMesh *, int, int); // edx
  CMeshBuilder meshBuilder; // [esp+2Ch] [ebp-1ECh] BYREF
  CSheetExtended *v36; // [esp+214h] [ebp-4h]
  const SequenceSampleTextureCoords_t *v37; // [esp+22Ch] [ebp+14h]
  char v38; // [esp+243h] [ebp+2Bh]

  v36 = this;
  if ( bOverrideSpriteCard
    || (m_pMaterial = this->m_Material.m_pMaterial) == nullptr
    || (v38 = 1, !m_pMaterial->IsSpriteCard(this: m_pMaterial)) )
  {
    v38 = 0;
  }
  v11 = nullptr;
  if ( this->m_pSheetData != nullptr )
    SampleForSequence = (SheetSequenceSample_t *)CSheet::GetSampleForSequence(
                                                   this: this->m_pSheetData,
                                                   flAge: *(float *)&flAge,
                                                   flAgeScale: *((float *)&flAge + 1),
                                                   nSequence: nSheetSequence,
                                                   bForceLoop: bLoopSheetPreview);
  else
    SampleForSequence = &s_DefaultSheetSequence_0;
  v37 = nullptr;
  if ( nSecondarySequence != -1 && CSheetExtended::IsMaterialDualSequence(pMat: v36->m_Material.m_pMaterial) )
  {
    if ( v36->m_pSheetData != nullptr )
      v11 = CSheet::GetSampleForSequence(
              this: v36->m_pSheetData,
              flAge: *(float *)&flAge * 0.1,
              flAgeScale: *((float *)&flAge + 1),
              nSequence: nSecondarySequence,
              bForceLoop: bLoopSheetPreview);
    else
      v11 = &s_DefaultSheetSequence_0;
    v37 = (const SequenceSampleTextureCoords_t *)v11;
  }
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = pMesh;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  if ( v38 != 0 )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v11,
      pSample1: v37,
      flChannel3U: 0.0,
      flChannel3V: 0.0);
  }
  else
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v14 = vCenter->y + COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_);
    z = vCenter->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) + vCenter->x;
    m_pCurrPosition[1] = v14;
    m_pCurrPosition[2] = z;
    v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    m_fTop_V0 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
    v16[1] = m_fTop_V0;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( v38 != 0 )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v11,
      pSample1: v37,
      flChannel3U: 1.0,
      flChannel3V: 0.0);
  }
  else
  {
    v18 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v19 = vCenter->y + COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_);
    v20 = vCenter->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + flRadius;
    v18[1] = v19;
    v18[2] = v20;
    v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v22 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
    v21[1] = v22;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( v38 != 0 )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v11,
      pSample1: v37,
      flChannel3U: 1.0,
      flChannel3V: 1.0);
  }
  else
  {
    v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v24 = vCenter->z;
    v25 = vCenter->y + flRadius;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + flRadius;
    v23[1] = v25;
    v23[2] = v24;
    v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    m_fBottom_V0 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
    v26[1] = m_fBottom_V0;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( v38 != 0 )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v11,
      pSample1: v37,
      flChannel3U: 0.0,
      flChannel3V: 1.0);
  }
  else
  {
    v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v29 = vCenter->z;
    v30 = vCenter->y + flRadius;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) + vCenter->x;
    v28[1] = v30;
    v28[2] = v29;
    v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v32 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
    v31[1] = v32;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  Draw_2 = pMesh->Draw_2;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  Draw_2(this: pMesh, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029F740
// Name: public: CSheet::~CSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheet::~CSheet(CSheet *this)
{
  int v2; // ebx
  int v3; // edi
  CSheet::SheetInfo_t *m_pMemory; // eax
  CSheet::SheetInfo_t *v5; // eax
  CUtlReference<CSheet> *m_pHead; // eax
  CUtlReference<CSheet> *m_pNext; // ecx

  v2 = 0;
  if ( this->m_SheetInfo.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_SheetInfo.m_Memory.m_pMemory;
      if ( m_pMemory[v3].m_pSamples != nullptr && !m_pMemory[v3].m_bSequenceIsCopyOfAnotherSequence )
        operator delete(p: m_pMemory[v3].m_pSamples);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SheetInfo.m_Size );
  }
  this->m_SheetInfo.m_Size = 0;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SheetInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SheetInfo.m_Memory.m_pMemory);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_SheetInfo.m_Memory.m_pMemory;
  this->m_SheetInfo.m_pElements = v5;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( this->m_References.m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1029F7F0
// Name: public: CSheet::CSheet(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CSheet::CSheet(CSheet *this, CUtlBuffer *buf)
{
  CSheet *v2; // edi
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_SheetInfo; // ebx
  int Int; // eax
  float v5; // esi
  bool v6; // zf
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v7; // eax
  int v8; // eax
  int v9; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *j; // eax
  int v18; // eax
  int v19; // edi
  int v20; // esi
  int v21; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v22; // ecx
  int v23; // eax
  int v24; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v25; // esi
  int v26; // edi
  int v27; // eax
  int v28; // esi
  int v29; // esi
  float v30; // ecx
  char *v31; // eax
  float *v32; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v33; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v34; // eax
  int v35; // eax
  int v36; // ecx
  _DWORD *v37; // eax
  _DWORD v38[2]; // [esp+20h] [ebp-98D8h] BYREF
  char v39; // [esp+28h] [ebp-98D0h] BYREF
  float v40[5]; // [esp+8820h] [ebp-10D8h] BYREF
  float v41[5]; // [esp+9020h] [ebp-8D8h] BYREF
  _DWORD v42[17]; // [esp+9820h] [ebp-D8h] BYREF
  _DWORD v43[17]; // [esp+9864h] [ebp-94h] BYREF
  float v44; // [esp+98A8h] [ebp-50h] BYREF
  float v45; // [esp+98ACh] [ebp-4Ch] BYREF
  float v46; // [esp+98B0h] [ebp-48h] BYREF
  float v47; // [esp+98B4h] [ebp-44h]
  float v48; // [esp+98B8h] [ebp-40h] BYREF
  float v49; // [esp+98BCh] [ebp-3Ch] BYREF
  float v50; // [esp+98C0h] [ebp-38h] BYREF
  float v51; // [esp+98C4h] [ebp-34h] BYREF
  float v52; // [esp+98C8h] [ebp-30h] BYREF
  float v53; // [esp+98CCh] [ebp-2Ch] BYREF
  int pInterpolationValue; // [esp+98D0h] [ebp-28h]
  float dest; // [esp+98D4h] [ebp-24h]
  int pValueB; // [esp+98D8h] [ebp-20h]
  float pValueA; // [esp+98DCh] [ebp-1Ch]
  int v58; // [esp+98E0h] [ebp-18h]
  int v59; // [esp+98E4h] [ebp-14h]
  CSheet *v60; // [esp+98E8h] [ebp-10h]
  int v61; // [esp+98ECh] [ebp-Ch]
  char *v62; // [esp+98F0h] [ebp-8h]
  int i; // [esp+98F4h] [ebp-4h]
  CUtlBuffer *v64; // [esp+9900h] [ebp+8h]

  v2 = this;
  this->m_References.m_pHead = nullptr;
  p_m_SheetInfo = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_SheetInfo;
  v60 = this;
  this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
  this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  this->m_SheetInfo.m_Memory.m_nGrowSize = 0;
  this->m_SheetInfo.m_Size = 0;
  this->m_SheetInfo.m_pElements = nullptr;
  pValueB = CUtlBuffer::GetInt(this: buf) != 0 ? 4 : 1;
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = *(float *)&Int;
  v58 = Int;
  i = Int;
  if ( Int < 64 )
    i = 64;
  if ( p_m_SheetInfo->m_nAllocationCount < Int && p_m_SheetInfo->m_nGrowSize >= 0 )
  {
    v6 = p_m_SheetInfo->m_pMemory == nullptr;
    p_m_SheetInfo->m_nAllocationCount = Int;
    if ( v6 )
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * Int);
    else
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: p_m_SheetInfo->m_pMemory,
                                                          a3: 12 * Int);
    p_m_SheetInfo->m_pMemory = v7;
  }
  v8 = i;
  p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( i = v8; i != 0; --i )
    {
      m_pMemory = p_m_SheetInfo[1].m_pMemory;
      m_nAllocationCount = p_m_SheetInfo->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_m_SheetInfo,
          num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
      ++p_m_SheetInfo[1].m_pMemory;
      v12 = p_m_SheetInfo->m_pMemory;
      v13 = (char *)p_m_SheetInfo[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[(int)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 12 * v13);
      p_m_SheetInfo->m_pMemory[v9].m_Element = nullptr;
      LOBYTE(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      BYTE1(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      HIWORD(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      p_m_SheetInfo->m_pMemory[v9++].m_Next = 0;
    }
    v5 = *(float *)&v58;
    v2 = v60;
  }
  if ( v5 == 0.0 )
  {
LABEL_18:
    v14 = 0;
    v15 = 0;
    if ( v2->m_SheetInfo.m_Size > 0 )
    {
      for ( j = p_m_SheetInfo->m_pMemory; j->m_Element == nullptr; ++j )
      {
        if ( ++v15 >= v2->m_SheetInfo.m_Size )
          return v2;
      }
      if ( v15 != -1 )
      {
        v64 = nullptr;
        do
        {
          if ( p_m_SheetInfo->m_pMemory[v14].m_Element == nullptr )
          {
            p_m_SheetInfo->m_pMemory[v14].m_Element = p_m_SheetInfo->m_pMemory[v15].m_Element;
            LOBYTE(p_m_SheetInfo->m_pMemory[v14].m_Previous) = p_m_SheetInfo->m_pMemory[v15].m_Previous;
            v2 = v60;
            HIWORD(p_m_SheetInfo->m_pMemory[v14].m_Previous) = HIWORD(p_m_SheetInfo->m_pMemory[v15].m_Previous);
            BYTE1(p_m_SheetInfo->m_pMemory[v14].m_Previous) = 1;
          }
          ++v14;
          v64 = (CUtlBuffer *)((char *)v64 + 1);
        }
        while ( (int)v64 < v2->m_SheetInfo.m_Size );
      }
    }
    return v2;
  }
  else
  {
    while ( 1 )
    {
      v58 = LODWORD(v5) - 1;
      v18 = CUtlBuffer::GetInt(this: buf);
      v19 = v18;
      v61 = v18;
      if ( v18 < 0 )
        break;
      if ( v18 >= v60->m_SheetInfo.m_Size )
      {
        do
        {
          v20 = (int)p_m_SheetInfo[1].m_pMemory;
          v21 = p_m_SheetInfo->m_nAllocationCount;
          if ( v20 + 1 > v21 )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: p_m_SheetInfo, num: v20 - v21 + 1);
          ++p_m_SheetInfo[1].m_pMemory;
          v22 = p_m_SheetInfo->m_pMemory;
          v23 = (int)p_m_SheetInfo[1].m_pMemory - v20 - 1;
          p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
          if ( v23 > 0 )
            _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 12 * v23);
          v24 = v20;
          p_m_SheetInfo->m_pMemory[v24].m_Element = nullptr;
          LOBYTE(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          BYTE1(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          HIWORD(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          p_m_SheetInfo->m_pMemory[v24].m_Next = 0;
        }
        while ( v20 < v19 );
      }
      v25 = p_m_SheetInfo->m_pMemory;
      v26 = v19;
      v59 = v26 * 12;
      LOBYTE(v25[v26].m_Previous) = CUtlBuffer::GetInt(this: buf);
      v27 = CUtlBuffer::GetInt(this: buf);
      HIWORD(p_m_SheetInfo->m_pMemory[v26].m_Previous) = v27;
      v28 = v27 != 1 ? 512 : 1;
      v6 = p_m_SheetInfo->m_pMemory[v26].m_Element == nullptr;
      i = v27;
      pInterpolationValue = v28;
      if ( !v6 )
      {
        _Warning(
          a1: "Invalid particle sheet sequence index.  There are more than one items with a sequence index of %d. We are only"
          " using the last one we found..\n",
          v61);
        operator delete(p: p_m_SheetInfo->m_pMemory[v26].m_Element);
      }
      *(vgui::TreeNode **)((char *)&p_m_SheetInfo->m_pMemory->m_Element + v59) = (vgui::TreeNode *)operator new(nSize: 68 * v28);
      CUtlBuffer::GetType<float>(this: buf, dest: &v50);
      v29 = 0;
      pValueA = 0.0;
      v61 = 0;
      if ( i > 0 )
      {
        v47 = 1.0 / (float)(int)v50;
        v62 = &v39;
        do
        {
          CUtlBuffer::GetType<float>(this: buf, dest: &v45);
          v30 = *(float *)&pValueB;
          v31 = v62;
          v41[v29] = (float)v29;
          v40[v29] = (float)(v47 * pValueA) * 512.0;
          *((_DWORD *)v31 + 14) = 0;
          if ( SLODWORD(v30) > 0 )
          {
            v32 = (float *)v31;
            dest = v30;
            do
            {
              CUtlBuffer::GetType<float>(this: buf, dest: &v53);
              *(v32 - 2) = v53;
              CUtlBuffer::GetType<float>(this: buf, dest: &v46);
              *(v32 - 1) = v46;
              CUtlBuffer::GetType<float>(this: buf, dest: &v48);
              *v32 = v48;
              CUtlBuffer::GetType<float>(this: buf, dest: &v44);
              v32[1] = v44;
              v32 += 8;
              --LODWORD(dest);
            }
            while ( LODWORD(dest) != 0 );
            v29 = v61;
            v30 = *(float *)&pValueB;
            v31 = v62;
          }
          if ( LODWORD(v30) == 1 )
          {
            *((_QWORD *)v31 + 3) = *((_QWORD *)v31 - 1);
            *((_QWORD *)v31 + 4) = *(_QWORD *)v31;
            *((_QWORD *)v31 + 5) = *((_QWORD *)v31 + 1);
            *((_QWORD *)v31 + 6) = *((_QWORD *)v31 + 2);
          }
          v33 = p_m_SheetInfo->m_pMemory;
          ++v29;
          pValueA = v45 + pValueA;
          *(float *)((char *)&v33->m_Next + v59) = pValueA;
          v61 = v29;
          v62 = v31 + 68;
        }
        while ( v29 < i );
      }
      v62 = nullptr;
      if ( pInterpolationValue > 0 )
      {
        v61 = 0;
        do
        {
          GetInterpolationData(
            pKnotPositions: v40,
            pKnotValues: v41,
            nNumValuesinList: i,
            nInterpolationRange: 512,
            flPositionToInterpolateAt: (float)(int)v62,
            bWrap: (*((_BYTE *)&p_m_SheetInfo->m_pMemory->m_Previous + v59) & 1) == 0,
            pValueA: &v52,
            pValueB: &v51,
            pInterpolationValue: &v49);
          v34 = p_m_SheetInfo->m_pMemory;
          qmemcpy(v43, &v38[17 * (int)v52], sizeof(v43));
          qmemcpy(v42, &v38[17 * (int)v51], sizeof(v42));
          v35 = *(int *)((char *)&v34->m_Element + v59);
          v36 = v61;
          *(float *)(v35 + v61 + 64) = v49;
          *(_DWORD *)(v35 + v36) = v43[0];
          *(_DWORD *)(v35 + v36 + 4) = v43[1];
          *(_DWORD *)(v35 + v36 + 8) = v43[2];
          *(_DWORD *)(v35 + v36 + 12) = v43[3];
          *(_DWORD *)(v35 + v36 + 16) = v42[0];
          *(_DWORD *)(v35 + v36 + 20) = v42[1];
          v37 = (_DWORD *)(v36 + v35);
          v37[6] = v42[2];
          v37[7] = v42[3];
          v37[8] = v43[8];
          v37[9] = v43[9];
          v37[10] = v43[10];
          v37[11] = v43[11];
          v37[12] = v42[8];
          v37[13] = v42[9];
          v37[14] = v42[10];
          v37[15] = v42[11];
          ++v62;
          v61 = v36 + 68;
        }
        while ( (int)v62 < pInterpolationValue );
      }
      if ( v58 == 0 )
      {
        v2 = v60;
        goto LABEL_18;
      }
      v5 = *(float *)&v58;
    }
    _Warning(a1: "Invalid sequence number (%d)!!!\n", v18);
    return v60;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029FE10
// Name: public: CSheetExtended::~CSheetExtended(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::~CSheetExtended(CSheetExtended *this)
{
  CSheet *m_pSheetData; // esi

  m_pSheetData = this->m_pSheetData;
  if ( this->m_pSheetData != nullptr )
  {
    CSheet::~CSheet(this: this->m_pSheetData);
    operator delete(p: m_pSheetData);
  }
  CMaterialReference::~CMaterialReference(this: &this->m_Material);
}

//------------------------------------------------------------------------------
// Address: 0x1029FE40
// Name: private: void CSheetExtended::LoadFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::LoadFromBuffer(CSheetExtended *this, CUtlBuffer *buf)
{
  CSheet *v3; // eax

  v3 = (CSheet *)operator new(nSize: 0x18u);
  if ( v3 != nullptr )
    this->m_pSheetData = CSheet::CSheet(this: v3, buf);
  else
    this->m_pSheetData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1029FE70
// Name: private: void CSheetExtended::LoadFromMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::LoadFromMaterial(CSheetExtended *this, IMaterial *pMaterial)
{
  IMaterial *v3; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v5; // eax
  int (__thiscall ***v6)(_DWORD); // esi
  int v7; // eax
  int v8; // esi
  unsigned __int8 *v9; // eax
  CUtlBuffer bufLoad; // [esp+4h] [ebp-34h] BYREF
  unsigned int nBytes; // [esp+34h] [ebp-4h] BYREF

  v3 = pMaterial;
  if ( pMaterial != nullptr )
  {
    FindVar = pMaterial->FindVar;
    HIBYTE(pMaterial) = 0;
    v5 = (int)FindVar(this: v3, a2: "$basetexture", a3: (bool *)&pMaterial + 3, a4: true);
    v6 = (int (__thiscall ***)(_DWORD))v5;
    if ( v5 != 0 && HIBYTE(pMaterial) != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 72))(a1: v5) != 0 )
    {
      v7 = (**v6)(a1: v6);
      v8 = v7;
      if ( v7 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 60))(a1: v7) == 0 )
      {
        v9 = (unsigned __int8 *)(*(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v8 + 36))(
                                  a1: v8,
                                  a2: 16,
                                  a3: &nBytes);
        if ( v9 != nullptr )
        {
          CUtlBuffer::CUtlBuffer(this: &bufLoad, pBuffer: v9, nSize: nBytes, nFlags: 8u);
          CSheetExtended::LoadFromBuffer(this, buf: &bufLoad);
          CUtlBuffer::~CUtlBuffer(this: &bufLoad);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029FF10
// Name: public: CSheetExtended::CSheetExtended(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CSheetExtended *__thiscall CSheetExtended::CSheetExtended(CSheetExtended *this, IMaterial *pMaterial)
{
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::Init(this: &this->m_Material, pMaterial);
  this->m_pSheetData = nullptr;
  CSheetExtended::LoadFromMaterial(this, pMaterial);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00530F50
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00530FF0
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00531060
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00531110
// Name: public: CSheet::~CSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheet::~CSheet(CSheet *this)
{
  int v2; // ebx
  int v3; // edi
  CSheet::SheetInfo_t *m_pMemory; // eax
  CSheet::SheetInfo_t *v5; // eax
  CUtlReference<CSheet> *m_pHead; // eax
  CUtlReference<CSheet> *m_pNext; // ecx

  v2 = 0;
  if ( this->m_SheetInfo.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_SheetInfo.m_Memory.m_pMemory;
      if ( m_pMemory[v3].m_pSamples != nullptr && !m_pMemory[v3].m_bSequenceIsCopyOfAnotherSequence )
        free(pMem: m_pMemory[v3].m_pSamples);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SheetInfo.m_Size );
  }
  this->m_SheetInfo.m_Size = 0;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SheetInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SheetInfo.m_Memory.m_pMemory);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_SheetInfo.m_Memory.m_pMemory;
  this->m_SheetInfo.m_pElements = v5;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( this->m_References.m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
}

} // namespace particle_import

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004E79E0
// Name: public: bool CSheetExtended::ValidSheetData(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::ValidSheetData(CSheetExtended *this)
{
  return this->m_pSheetData != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004E79F0
// Name: void SpriteCardVert(class CMeshBuilder __near &,class Vector const __near &,float,struct SheetSequenceSample_t const __near *,struct SequenceSampleTextureCoords_t const __near *,struct SequenceSampleTextureCoords_t const __near *,struct SheetSequenceSample_t const __near *,struct SequenceSampleTextureCoords_t const __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpriteCardVert(
        CMeshBuilder *meshBuilder,
        const Vector *vCenter,
        float flRadius,
        const SheetSequenceSample_t *pSample,
        const SequenceSampleTextureCoords_t *pSample0,
        const SequenceSampleTextureCoords_t *pSecondTexture0,
        const SheetSequenceSample_t *pSample1Data,
        const SequenceSampleTextureCoords_t *pSample1,
        float flChannel3U,
        float flChannel3V)
{
  float *m_pCurrPosition; // eax
  float *v11; // edx
  float m_fTop_V0; // xmm0_4
  float m_fRight_U0; // xmm1_4
  float m_fBottom_V0; // xmm2_4
  float m_fTop_V1; // xmm0_4
  float m_fRight_U1; // xmm1_4
  float m_fBottom_V1; // xmm2_4
  float *v18; // edx
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float *v28; // edx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float *v32; // edx
  float *v33; // ecx

  m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *m_pCurrPosition = vCenter->x;
  m_pCurrPosition[1] = vCenter->y;
  v11 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  m_pCurrPosition[2] = vCenter->z;
  m_fTop_V0 = pSample0->m_fTop_V0;
  m_fRight_U0 = pSample0->m_fRight_U0;
  m_fBottom_V0 = pSample0->m_fBottom_V0;
  *v11 = pSample0->m_fLeft_U0;
  v11[1] = m_fTop_V0;
  v11[2] = m_fRight_U0;
  v11[3] = m_fBottom_V0;
  m_fTop_V1 = pSample0->m_fTop_V1;
  m_fRight_U1 = pSample0->m_fRight_U1;
  m_fBottom_V1 = pSample0->m_fBottom_V1;
  v18 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
  v19 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[2];
  *v18 = pSample0->m_fLeft_U1;
  v18[1] = m_fTop_V1;
  v18[2] = m_fRight_U1;
  v18[3] = m_fBottom_V1;
  *v19 = pSample->m_fBlendFactor;
  v19[1] = 0.0;
  v19[2] = flRadius;
  v19[3] = 0.0;
  v20 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[3];
  *v20 = flChannel3U;
  v20[1] = flChannel3V;
  v21 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[4];
  v22 = pSecondTexture0->m_fTop_V0;
  v23 = pSecondTexture0->m_fRight_U0;
  v24 = pSecondTexture0->m_fBottom_V0;
  *v21 = pSecondTexture0->m_fLeft_U0;
  v21[1] = v22;
  v21[2] = v23;
  v21[3] = v24;
  if ( pSample1 != nullptr )
  {
    v25 = pSample1->m_fTop_V0;
    v26 = pSample1->m_fRight_U0;
    v27 = pSample1->m_fBottom_V0;
    v28 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[5];
    *v28 = pSample1->m_fLeft_U0;
    v28[1] = v25;
    v28[2] = v26;
    v28[3] = v27;
    v29 = pSample1->m_fTop_V1;
    v30 = pSample1->m_fRight_U1;
    v31 = pSample1->m_fBottom_V1;
    v32 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[6];
    v33 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[7];
    *v32 = pSample1->m_fLeft_U1;
    v32[1] = v29;
    v32[2] = v30;
    v32[3] = v31;
    *v33 = pSample1Data->m_fBlendFactor;
    v33[1] = 0.0;
    v33[2] = 0.0;
    v33[3] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E7B50
// Name: public: static bool CSheetExtended::IsMaterialDualSequence(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSheetExtended::IsMaterialDualSequence(IMaterial *pMat)
{
  IMaterial *v1; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v4; // eax
  int v5; // esi

  v1 = pMat;
  if ( pMat == nullptr )
    return false;
  FindVar = pMat->FindVar;
  HIBYTE(pMat) = 0;
  v4 = (int)FindVar(this: v1, a2: "$DUALSEQUENCE", a3: (bool *)&pMat + 3, a4: true);
  v5 = v4;
  return v4 != 0
      && HIBYTE(pMat) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 72))(a1: v4) != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 108))(a1: v5) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E7BB0
// Name: public: static bool CSheetExtended::IsMaterialSeparateAlphaColorMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CSheetExtended::IsMaterialSeparateAlphaColorMaterial(IMaterial *pMat)
{
  IMaterial *v1; // esi
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  int v3; // esi
  bool result; // al

  v1 = pMat;
  result = pMat != nullptr
        && CSheetExtended::IsMaterialDualSequence(pMat)
        && (FindVar = v1->FindVar,
            HIBYTE(pMat) = 0,
            (v3 = (int)FindVar(this: v1, a2: "$SEQUENCE_BLEND_MODE", a3: (bool *)&pMat + 3, a4: true)) != 0)
        && HIBYTE(pMat) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 72))(a1: v3) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 108))(a1: v3) == 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E7C10
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E7CB0
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  char *v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0.0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  *value = strtod(nptr: pEnd, endptr: &pEnd);
  if ( pEnd == v5 )
    return 0;
  this->m_Get += pEnd - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004E7D20
// Name: public: struct SheetSequenceSample_t const __near * CSheet::GetSampleForSequence(float,float,int,bool)
// Source: json
//------------------------------------------------------------------------------
const SheetSequenceSample_t *__thiscall CSheet::GetSampleForSequence(
        CSheet *this,
        float flAge,
        float flAgeScale,
        int nSequence,
        bool bForceLoop)
{
  CSheet::SheetInfo_t *v5; // ecx
  unsigned int v7; // eax

  v5 = &this->m_SheetInfo.m_Memory.m_pMemory[nSequence];
  if ( v5->m_nNumFrames == 1 )
    return v5->m_pSamples;
  v7 = (__int64)(flAge * flAgeScale);
  if ( (v5->m_SeqFlags & 1) == 0 || bForceLoop )
  {
    v7 &= 0x1FFu;
  }
  else if ( v7 >= 0x1FF )
  {
    return v5->m_pSamples + 511;
  }
  return &v5->m_pSamples[v7];
}

//------------------------------------------------------------------------------
// Address: 0x004E7DB0
// Name: public: int CSheetExtended::GetSheetSequenceCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetExtended::GetSheetSequenceCount(CSheetExtended *this)
{
  CSheet *m_pSheetData; // ecx
  int result; // eax
  int m_Size; // edx
  bool *p_m_bSequenceIsCopyOfAnotherSequence; // ecx

  m_pSheetData = this->m_pSheetData;
  result = 0;
  if ( m_pSheetData != nullptr )
  {
    m_Size = m_pSheetData->m_SheetInfo.m_Size;
    if ( m_Size > 0 )
    {
      p_m_bSequenceIsCopyOfAnotherSequence = &m_pSheetData->m_SheetInfo.m_Memory.m_pMemory->m_bSequenceIsCopyOfAnotherSequence;
      do
      {
        if ( !*p_m_bSequenceIsCopyOfAnotherSequence )
          ++result;
        p_m_bSequenceIsCopyOfAnotherSequence += 12;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E7DE0
// Name: public: int CSheetExtended::GetNthSequenceIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSheetExtended::GetNthSequenceIndex(CSheetExtended *this, int nSequenceNumber)
{
  CSheet *m_pSheetData; // ecx
  int result; // eax
  int m_Size; // edx
  int v5; // esi
  bool *p_m_bSequenceIsCopyOfAnotherSequence; // ecx

  m_pSheetData = this->m_pSheetData;
  result = 0;
  if ( m_pSheetData != nullptr )
  {
    m_Size = m_pSheetData->m_SheetInfo.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      p_m_bSequenceIsCopyOfAnotherSequence = &m_pSheetData->m_SheetInfo.m_Memory.m_pMemory->m_bSequenceIsCopyOfAnotherSequence;
      do
      {
        if ( !*p_m_bSequenceIsCopyOfAnotherSequence )
        {
          if ( v5 == nSequenceNumber )
            return result;
          ++v5;
        }
        ++result;
        p_m_bSequenceIsCopyOfAnotherSequence += 12;
      }
      while ( result < m_Size );
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E7E20
// Name: public: float CSheetExtended::GetSequenceTimeSpan(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSheetExtended::GetSequenceTimeSpan(CSheetExtended *this, int nSequenceIndex)
{
  CSheet *m_pSheetData; // ecx

  m_pSheetData = this->m_pSheetData;
  if ( m_pSheetData != nullptr )
    return m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_flFrameSpan;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004E7E40
// Name: public: bool CSheetExtended::SequenceHasAlphaData(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::SequenceHasAlphaData(CSheetExtended *this, int nSequenceIndex)
{
  return (this->m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_SeqFlags & 2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E7E60
// Name: public: bool CSheetExtended::SequenceHasColorData(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSheetExtended::SequenceHasColorData(CSheetExtended *this, int nSequenceIndex)
{
  return (this->m_pSheetData->m_SheetInfo.m_Memory.m_pMemory[nSequenceIndex].m_SeqFlags & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E7E80
// Name: public: void CSheetExtended::DrawSheet(class IMesh __near *,class Vector const __near &,float,int,float,float,bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::DrawSheet(
        CSheetExtended *this,
        IMesh *pMesh,
        const Vector *vCenter,
        float flRadius,
        const SequenceSampleTextureCoords_t *nSheetSequence,
        float flAge,
        float flSheetPreviewSpeed,
        bool bLoopSheetPreview,
        int nSecondarySequence,
        bool bOverrideSpriteCard)
{
  IMaterial *m_pMaterial; // ecx
  const SheetSequenceSample_t *v12; // ebx
  SheetSequenceSample_t *SampleForSequence; // edi
  float *m_pCurrPosition; // eax
  float v15; // xmm2_4
  float z; // xmm0_4
  float *v17; // eax
  float m_fTop_V0; // xmm0_4
  float *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  float *v22; // eax
  float v23; // xmm0_4
  float *v24; // eax
  float v25; // xmm2_4
  float v26; // xmm1_4
  float *v27; // eax
  float m_fBottom_V0; // xmm0_4
  float *v29; // eax
  float v30; // xmm2_4
  float v31; // xmm1_4
  float *v32; // eax
  float v33; // xmm0_4
  int m_nVertexCount; // eax
  void (__thiscall *Draw_2)(IMesh *, int, int); // edx
  CMeshBuilder meshBuilder; // [esp+40h] [ebp-1ECh] BYREF
  CSheetExtended *v37; // [esp+228h] [ebp-4h]
  const SequenceSampleTextureCoords_t *pSample1; // [esp+240h] [ebp+14h]
  bool bSpriteCardMaterial; // [esp+257h] [ebp+2Bh]

  v37 = this;
  if ( bOverrideSpriteCard
    || (m_pMaterial = this->m_Material.m_pMaterial) == nullptr
    || (bSpriteCardMaterial = true, !m_pMaterial->IsSpriteCard(this: m_pMaterial)) )
  {
    bSpriteCardMaterial = false;
  }
  v12 = nullptr;
  if ( this->m_pSheetData != nullptr )
    SampleForSequence = (SheetSequenceSample_t *)CSheet::GetSampleForSequence(
                                                   this: this->m_pSheetData,
                                                   flAge,
                                                   flAgeScale: flSheetPreviewSpeed,
                                                   nSequence: (int)nSheetSequence,
                                                   bForceLoop: bLoopSheetPreview);
  else
    SampleForSequence = &s_DefaultSheetSequence;
  pSample1 = nullptr;
  if ( nSecondarySequence != -1 && CSheetExtended::IsMaterialDualSequence(pMat: v37->m_Material.m_pMaterial) )
  {
    if ( v37->m_pSheetData != nullptr )
      v12 = CSheet::GetSampleForSequence(
              this: v37->m_pSheetData,
              flAge: flAge * 0.1,
              flAgeScale: flSheetPreviewSpeed,
              nSequence: nSecondarySequence,
              bForceLoop: bLoopSheetPreview);
    else
      v12 = &s_DefaultSheetSequence;
    pSample1 = (const SequenceSampleTextureCoords_t *)v12;
  }
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = pMesh;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 0.0,
      flChannel3V: 0.0);
  }
  else
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v15 = vCenter->y + COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_);
    z = vCenter->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) + vCenter->x;
    m_pCurrPosition[1] = v15;
    m_pCurrPosition[2] = z;
    v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    m_fTop_V0 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
    v17[1] = m_fTop_V0;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 1.0,
      flChannel3V: 0.0);
  }
  else
  {
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v20 = vCenter->y + COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_);
    v21 = vCenter->z;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + flRadius;
    v19[1] = v20;
    v19[2] = v21;
    v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v23 = SampleForSequence->m_TextureCoordData[0].m_fTop_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
    v22[1] = v23;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 1.0,
      flChannel3V: 1.0);
  }
  else
  {
    v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v25 = vCenter->z;
    v26 = vCenter->y + flRadius;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = vCenter->x + flRadius;
    v24[1] = v26;
    v24[2] = v25;
    v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    m_fBottom_V0 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fRight_U0;
    v27[1] = m_fBottom_V0;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( bSpriteCardMaterial )
  {
    SpriteCardVert(
      &meshBuilder,
      vCenter,
      flRadius,
      pSample: SampleForSequence,
      pSample0: SampleForSequence->m_TextureCoordData,
      pSecondTexture0: &SampleForSequence->m_TextureCoordData[1],
      pSample1Data: v12,
      pSample1,
      flChannel3U: 0.0,
      flChannel3V: 1.0);
  }
  else
  {
    v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v30 = vCenter->z;
    v31 = vCenter->y + flRadius;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_) + vCenter->x;
    v29[1] = v31;
    v29[2] = v30;
    v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    v33 = SampleForSequence->m_TextureCoordData[0].m_fBottom_V0;
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = SampleForSequence->m_TextureCoordData[0].m_fLeft_U0;
    v32[1] = v33;
  }
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  Draw_2 = pMesh->Draw_2;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  Draw_2(this: pMesh, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8380
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  char *v3; // edi
  int nIncrement; // [esp+4h] [ebp-8h] BYREF
  char *endptr; // [esp+8h] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) != 0 )
  {
    nIncrement = 128;
    if ( CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    {
      endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
      v3 = endptr;
      *dest = strtod(nptr: endptr, &endptr);
      if ( endptr != v3 )
        this->m_Get += endptr - v3;
    }
    else
    {
      *dest = 0.0;
    }
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8430
// Name: public: CSheet::~CSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheet::~CSheet(CSheet *this)
{
  int v2; // ebx
  int v3; // edi
  CSheet::SheetInfo_t *m_pMemory; // eax
  CSheet::SheetInfo_t *v5; // eax
  CUtlReference<CSheet> *m_pHead; // eax
  CUtlReference<CSheet> *m_pNext; // ecx

  v2 = 0;
  if ( this->m_SheetInfo.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_SheetInfo.m_Memory.m_pMemory;
      if ( m_pMemory[v3].m_pSamples != nullptr && !m_pMemory[v3].m_bSequenceIsCopyOfAnotherSequence )
        free(pMem: m_pMemory[v3].m_pSamples);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SheetInfo.m_Size );
  }
  this->m_SheetInfo.m_Size = 0;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SheetInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SheetInfo.m_Memory.m_pMemory);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_SheetInfo.m_Memory.m_pMemory;
  this->m_SheetInfo.m_pElements = v5;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( this->m_References.m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004E84E0
// Name: public: CSheet::CSheet(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CSheet::CSheet(CSheet *this, CUtlBuffer *buf)
{
  CSheet *v2; // esi
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_SheetInfo; // ebx
  int Int; // eax
  int v5; // edi
  bool v6; // zf
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v7; // eax
  int v8; // eax
  int v9; // edi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v12; // ecx
  int v13; // eax
  int v14; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *j; // eax
  int v17; // eax
  int v18; // edi
  int v19; // esi
  int v20; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v21; // ecx
  int v22; // eax
  int v23; // eax
  int v24; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v25; // edi
  int v26; // eax
  int v27; // esi
  int v28; // esi
  int v29; // ecx
  char *v30; // eax
  float *v31; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v32; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v33; // eax
  int v34; // eax
  int v35; // ecx
  float *v36; // eax
  int v37; // esi
  _DWORD v38[2]; // [esp+20h] [ebp-98D8h] BYREF
  char v39; // [esp+28h] [ebp-98D0h] BYREF
  float pKnotPositions[512]; // [esp+8820h] [ebp-10D8h] BYREF
  float pKnotValues[546]; // [esp+9020h] [ebp-8D8h] BYREF
  float v42; // [esp+98A8h] [ebp-50h] BYREF
  float v43; // [esp+98ACh] [ebp-4Ch] BYREF
  float v44; // [esp+98B0h] [ebp-48h] BYREF
  float v45; // [esp+98B4h] [ebp-44h]
  float v46; // [esp+98B8h] [ebp-40h] BYREF
  float pInterpolationValue; // [esp+98BCh] [ebp-3Ch] BYREF
  float dest; // [esp+98C0h] [ebp-38h] BYREF
  float pValueB; // [esp+98C4h] [ebp-34h] BYREF
  float pValueA; // [esp+98C8h] [ebp-30h] BYREF
  float v51; // [esp+98CCh] [ebp-2Ch] BYREF
  int v52; // [esp+98D0h] [ebp-28h]
  int i; // [esp+98D4h] [ebp-24h]
  int v54; // [esp+98D8h] [ebp-20h]
  float v55; // [esp+98DCh] [ebp-1Ch]
  int v56; // [esp+98E0h] [ebp-18h]
  int v57; // [esp+98E4h] [ebp-14h]
  CSheet *v58; // [esp+98E8h] [ebp-10h]
  int v59; // [esp+98ECh] [ebp-Ch]
  char *v60; // [esp+98F0h] [ebp-8h]
  int nNumValuesinList; // [esp+98F4h] [ebp-4h]
  CUtlBuffer *v62; // [esp+9900h] [ebp+8h]

  v2 = this;
  this->m_References.m_pHead = nullptr;
  p_m_SheetInfo = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_SheetInfo;
  v58 = this;
  this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
  this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  this->m_SheetInfo.m_Memory.m_nGrowSize = 0;
  this->m_SheetInfo.m_Size = 0;
  this->m_SheetInfo.m_pElements = nullptr;
  v54 = CUtlBuffer::GetInt(this: buf) != 0 ? 4 : 1;
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = Int;
  v56 = Int;
  nNumValuesinList = Int;
  if ( Int < 64 )
    nNumValuesinList = 64;
  if ( p_m_SheetInfo->m_nAllocationCount < Int && p_m_SheetInfo->m_nGrowSize >= 0 )
  {
    v6 = p_m_SheetInfo->m_pMemory == nullptr;
    p_m_SheetInfo->m_nAllocationCount = Int;
    if ( v6 )
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * Int);
    else
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: p_m_SheetInfo->m_pMemory,
                                                          a3: 12 * Int);
    p_m_SheetInfo->m_pMemory = v7;
  }
  v8 = nNumValuesinList;
  p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( nNumValuesinList = v8; nNumValuesinList != 0; --nNumValuesinList )
    {
      m_pMemory = p_m_SheetInfo[1].m_pMemory;
      m_nAllocationCount = p_m_SheetInfo->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_m_SheetInfo,
          num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
      ++p_m_SheetInfo[1].m_pMemory;
      v12 = p_m_SheetInfo->m_pMemory;
      v13 = (char *)p_m_SheetInfo[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[(int)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 12 * v13);
      p_m_SheetInfo->m_pMemory[v9].m_Element = nullptr;
      LOBYTE(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      BYTE1(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      HIWORD(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      p_m_SheetInfo->m_pMemory[v9++].m_Next = 0;
    }
    v2 = v58;
    v5 = v56;
  }
  if ( v5 != 0 )
  {
    while ( 1 )
    {
      v56 = v5 - 1;
      v17 = CUtlBuffer::GetInt(this: buf);
      v18 = v17;
      if ( v17 < 0 )
        break;
      if ( v17 >= v2->m_SheetInfo.m_Size )
      {
        do
        {
          v19 = (int)p_m_SheetInfo[1].m_pMemory;
          v20 = p_m_SheetInfo->m_nAllocationCount;
          if ( v19 + 1 > v20 )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: p_m_SheetInfo, num: v19 - v20 + 1);
          ++p_m_SheetInfo[1].m_pMemory;
          v21 = p_m_SheetInfo->m_pMemory;
          v22 = (int)p_m_SheetInfo[1].m_pMemory - v19 - 1;
          p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
          if ( v22 > 0 )
            _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 12 * v22);
          v23 = v19;
          p_m_SheetInfo->m_pMemory[v23].m_Element = nullptr;
          LOBYTE(p_m_SheetInfo->m_pMemory[v23].m_Previous) = 0;
          BYTE1(p_m_SheetInfo->m_pMemory[v23].m_Previous) = 0;
          HIWORD(p_m_SheetInfo->m_pMemory[v23].m_Previous) = 0;
          p_m_SheetInfo->m_pMemory[v23].m_Next = 0;
        }
        while ( v19 < v18 );
      }
      v24 = 3 * v18;
      v25 = p_m_SheetInfo->m_pMemory;
      v24 *= 4;
      v57 = v24;
      *((_BYTE *)&v25->m_Previous + v24) = CUtlBuffer::GetInt(this: buf);
      v26 = CUtlBuffer::GetInt(this: buf);
      *(_WORD *)((char *)&p_m_SheetInfo->m_pMemory->m_Previous + v24 + 2) = v26;
      v27 = v26 != 1 ? 512 : 1;
      nNumValuesinList = v26;
      v52 = v27;
      *(vgui::TreeNode **)((char *)&p_m_SheetInfo->m_pMemory->m_Element + v57) = (vgui::TreeNode *)MemAlloc_Alloc(nSize: 68 * v27);
      CUtlBuffer::GetType<float>(this: buf, &dest);
      v28 = 0;
      v55 = 0.0;
      v59 = 0;
      if ( nNumValuesinList > 0 )
      {
        v45 = 1.0 / (float)(int)dest;
        v60 = &v39;
        do
        {
          CUtlBuffer::GetType<float>(this: buf, dest: &v43);
          v29 = v54;
          v30 = v60;
          pKnotValues[v28] = (float)v28;
          pKnotPositions[v28] = (float)(v45 * v55) * 512.0;
          *((_DWORD *)v30 + 14) = 0;
          if ( v29 > 0 )
          {
            v31 = (float *)v30;
            for ( i = v29; i != 0; --i )
            {
              CUtlBuffer::GetType<float>(this: buf, dest: &v51);
              *(v31 - 2) = v51;
              CUtlBuffer::GetType<float>(this: buf, dest: &v44);
              *(v31 - 1) = v44;
              CUtlBuffer::GetType<float>(this: buf, dest: &v46);
              *v31 = v46;
              CUtlBuffer::GetType<float>(this: buf, dest: &v42);
              v31[1] = v42;
              v31 += 8;
            }
            v29 = v54;
            v28 = v59;
            v30 = v60;
          }
          if ( v29 == 1 )
          {
            *((_QWORD *)v30 + 3) = *((_QWORD *)v30 - 1);
            *((_QWORD *)v30 + 4) = *(_QWORD *)v30;
            *((_QWORD *)v30 + 5) = *((_QWORD *)v30 + 1);
            *((_QWORD *)v30 + 6) = *((_QWORD *)v30 + 2);
          }
          v32 = p_m_SheetInfo->m_pMemory;
          ++v28;
          v55 = v43 + v55;
          *(float *)((char *)&v32->m_Next + v57) = v55;
          v59 = v28;
          v60 = v30 + 68;
        }
        while ( v28 < nNumValuesinList );
      }
      v60 = nullptr;
      if ( v52 > 0 )
      {
        v59 = 0;
        do
        {
          GetInterpolationData(
            pKnotPositions,
            pKnotValues,
            nNumValuesinList,
            nInterpolationRange: 512,
            flPositionToInterpolateAt: (float)(int)v60,
            bWrap: (*((_BYTE *)&p_m_SheetInfo->m_pMemory->m_Previous + v57) & 1) == 0,
            &pValueA,
            &pValueB,
            &pInterpolationValue);
          v33 = p_m_SheetInfo->m_pMemory;
          qmemcpy(&pKnotValues[529], &v38[17 * (int)pValueA], 0x44u);
          qmemcpy(&pKnotValues[512], &v38[17 * (int)pValueB], 0x44u);
          v34 = *(int *)((char *)&v33->m_Element + v57);
          v35 = v59;
          *(float *)(v34 + v59 + 64) = pInterpolationValue;
          *(float *)(v34 + v35) = pKnotValues[529];
          *(float *)(v34 + v35 + 4) = pKnotValues[530];
          *(float *)(v34 + v35 + 8) = pKnotValues[531];
          *(float *)(v34 + v35 + 12) = pKnotValues[532];
          *(float *)(v34 + v35 + 16) = pKnotValues[512];
          *(float *)(v34 + v35 + 20) = pKnotValues[513];
          v36 = (float *)(v35 + v34);
          v36[6] = pKnotValues[514];
          v36[7] = pKnotValues[515];
          v36[8] = pKnotValues[537];
          v36[9] = pKnotValues[538];
          v36[10] = pKnotValues[539];
          v36[11] = pKnotValues[540];
          v36[12] = pKnotValues[520];
          v36[13] = pKnotValues[521];
          v36[14] = pKnotValues[522];
          v36[15] = pKnotValues[523];
          ++v60;
          v59 = v35 + 68;
        }
        while ( (int)v60 < v52 );
      }
      v2 = v58;
      if ( v56 == 0 )
        goto LABEL_18;
      v5 = v56;
    }
    _Warning(a1: "Invalid sequence number (%d)!!!\n", v17);
    return v2;
  }
  else
  {
LABEL_18:
    v14 = 0;
    if ( v2->m_SheetInfo.m_Size <= 0 )
      return v2;
    for ( j = p_m_SheetInfo->m_pMemory; j->m_Element == nullptr; ++j )
    {
      if ( ++v14 >= v2->m_SheetInfo.m_Size )
        return v2;
    }
    if ( v14 == -1 )
    {
      return v2;
    }
    else
    {
      v62 = nullptr;
      v37 = 0;
      do
      {
        if ( p_m_SheetInfo->m_pMemory[v37].m_Element == nullptr )
        {
          p_m_SheetInfo->m_pMemory[v37].m_Element = p_m_SheetInfo->m_pMemory[v14].m_Element;
          LOBYTE(p_m_SheetInfo->m_pMemory[v37].m_Previous) = p_m_SheetInfo->m_pMemory[v14].m_Previous;
          HIWORD(p_m_SheetInfo->m_pMemory[v37].m_Previous) = HIWORD(p_m_SheetInfo->m_pMemory[v14].m_Previous);
          BYTE1(p_m_SheetInfo->m_pMemory[v37].m_Previous) = 1;
        }
        ++v37;
        v62 = (CUtlBuffer *)((char *)v62 + 1);
      }
      while ( (int)v62 < v58->m_SheetInfo.m_Size );
      return v58;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8AC0
// Name: public: CSheetExtended::~CSheetExtended(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::~CSheetExtended(CSheetExtended *this)
{
  CSheet *m_pSheetData; // esi

  m_pSheetData = this->m_pSheetData;
  if ( this->m_pSheetData != nullptr )
  {
    CSheet::~CSheet(this: this->m_pSheetData);
    free(pMem: m_pSheetData);
  }
  CMaterialReference::~CMaterialReference(this: &this->m_Material);
}

//------------------------------------------------------------------------------
// Address: 0x004E8AF0
// Name: private: void CSheetExtended::LoadFromBuffer(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::LoadFromBuffer(CSheetExtended *this, CUtlBuffer *buf)
{
  CSheet *v3; // eax

  v3 = (CSheet *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
    this->m_pSheetData = CSheet::CSheet(this: v3, buf);
  else
    this->m_pSheetData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004E8B20
// Name: private: void CSheetExtended::LoadFromMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheetExtended::LoadFromMaterial(CSheetExtended *this, IMaterial *pMaterial)
{
  IMaterial *v3; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v5; // eax
  int (__thiscall ***v6)(_DWORD); // esi
  int v7; // eax
  int v8; // esi
  const void *v9; // eax
  CUtlBuffer bufLoad; // [esp+4h] [ebp-34h] BYREF
  unsigned int nBytes; // [esp+34h] [ebp-4h] BYREF

  v3 = pMaterial;
  if ( pMaterial != nullptr )
  {
    FindVar = pMaterial->FindVar;
    HIBYTE(pMaterial) = 0;
    v5 = (int)FindVar(this: v3, a2: "$basetexture", a3: (bool *)&pMaterial + 3, a4: true);
    v6 = (int (__thiscall ***)(_DWORD))v5;
    if ( v5 != 0 && HIBYTE(pMaterial) != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 72))(a1: v5) != 0 )
    {
      v7 = (**v6)(a1: v6);
      v8 = v7;
      if ( v7 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 60))(a1: v7) == 0 )
      {
        v9 = (const void *)(*(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v8 + 36))(
                             a1: v8,
                             a2: 16,
                             a3: &nBytes);
        if ( v9 != nullptr )
        {
          CUtlBuffer::CUtlBuffer(this: &bufLoad, pBuffer: v9, nSize: nBytes, nFlags: 8);
          CSheetExtended::LoadFromBuffer(this, buf: &bufLoad);
          CUtlBuffer::~CUtlBuffer(this: &bufLoad);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8BC0
// Name: public: CSheetExtended::CSheetExtended(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CSheetExtended *__thiscall CSheetExtended::CSheetExtended(CSheetExtended *this, IMaterial *pMaterial)
{
  CMaterialReference::CMaterialReference(
    this: &this->m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::Init(this: &this->m_Material, pMaterial);
  this->m_pSheetData = nullptr;
  CSheetExtended::LoadFromMaterial(this, pMaterial);
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00408630
// Name: public: void CByteswap::SwapBufferToTargetEndian<float>(float __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<float>(
        CByteswap *this,
        float *outputBuffer,
        float *inputBuffer,
        int count)
{
  int v4; // ebx
  float *v5; // edi
  float *v6; // eax
  char *v7; // esi
  char v8; // al
  char v9; // cl
  char v10; // dl
  char v11; // al

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          v10 = *(v7 - 1);
          HIWORD(count) = HIWORD(*(_DWORD *)v5);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004086D0
// Name: protected: bool CUtlBuffer::GetTypeText<int>(int __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<int>(CUtlBuffer *this, int *value, unsigned int nRadix)
{
  int v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  int nIncrement; // [esp+8h] [ebp-4h] BYREF

  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
  {
    *value = 0;
    return 0;
  }
  nLength = (int)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = nLength;
  *value = strtol(nptr: (const char *)nLength, endptr: (char **)&nLength, ibase: nRadix);
  if ( nLength == v5 )
    return 0;
  this->m_Get += nLength - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408740
// Name: protected: bool CUtlBuffer::GetTypeText<float>(float __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<float>(CUtlBuffer *this, float *value, int nRadix)
{
  int v5; // esi
  int nLength; // [esp+4h] [ebp-8h] BYREF
  int nIncrement; // [esp+8h] [ebp-4h] BYREF

  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
  {
    *value = 0.0;
    return 0;
  }
  nLength = (int)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = nLength;
  *value = strtod(nptr: (char *)nLength, endptr: (char **)&nLength);
  if ( nLength == v5 )
    return 0;
  this->m_Get += nLength - v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004087B0
// Name: public: void CByteswap::SwapBufferToTargetEndian<int>(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408840
// Name: public: struct SheetSequenceSample_t const __near * CSheet::GetSampleForSequence(float,float,int,bool)
// Source: json
//------------------------------------------------------------------------------
const SheetSequenceSample_t *__thiscall CSheet::GetSampleForSequence(
        CSheet *this,
        float flAge,
        float flAgeScale,
        int nSequence,
        bool bForceLoop)
{
  CSheet::SheetInfo_t *v5; // ecx
  unsigned int v7; // eax

  v5 = &this->m_SheetInfo.m_Memory.m_pMemory[nSequence];
  if ( v5->m_nNumFrames == 1 )
    return v5->m_pSamples;
  v7 = (__int64)(flAge * flAgeScale);
  if ( (v5->m_SeqFlags & 1) == 0 || bForceLoop )
  {
    v7 &= 0x1FFu;
  }
  else if ( v7 >= 0x1FF )
  {
    return v5->m_pSamples + 511;
  }
  return &v5->m_pSamples[v7];
}

//------------------------------------------------------------------------------
// Address: 0x004088D0
// Name: protected: void CUtlBuffer::GetType<float>(float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetType<float>(CUtlBuffer *this, float *dest)
{
  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::GetTypeText<float>(this, value: dest, nRadix: 10);
  }
  else if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    *dest = *(float *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<float>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: dest,
        count: 1);
    this->m_Get += 4;
  }
  else
  {
    *dest = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408930
// Name: protected: void CUtlBuffer::GetTypeBin<int>(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<int>(CUtlBuffer *this, int *dest)
{
  int v3; // eax

  if ( CUtlBuffer::CheckGet(this, nSize: 4) )
  {
    v3 = this->m_Get - this->m_nOffset;
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<int>(
        this: &this->m_Byteswap,
        outputBuffer: dest,
        inputBuffer: (int *)&this->m_Memory.m_pMemory[v3],
        count: 1);
    else
      *dest = *(_DWORD *)&this->m_Memory.m_pMemory[v3];
    this->m_Get += 4;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004089F0
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  int dest; // [esp+4h] [ebp-4h] BYREF

  dest = (int)this;
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::GetTypeText<int>(this, value: &dest, nRadix: 0xAu);
  else
    CUtlBuffer::GetTypeBin<int>(this, &dest);
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x00408A20
// Name: public: CSheet::CSheet(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CSheet::CSheet(CSheet *this, CUtlBuffer *buf)
{
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *p_m_SheetInfo; // esi
  bool v3; // zf
  int v4; // edi
  int v5; // edi
  int v6; // edx
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char *v12; // esi
  int v13; // edi
  int v14; // eax
  CUtlVector<CSheet::SheetInfo_t,CUtlMemory<CSheet::SheetInfo_t,int> > *v15; // esi
  CSheet::SheetInfo_t *v16; // ecx
  int v17; // eax
  int v18; // eax
  bool v19; // cc
  int v20; // eax
  char *v21; // esi
  int v22; // esi
  int v23; // eax
  char *v24; // edi
  int v25; // esi
  char *v26; // esi
  char *v27; // esi
  int v28; // eax
  int v29; // edx
  float v30; // xmm0_4
  unsigned int v31; // eax
  char *v32; // esi
  char *v33; // esi
  float v34; // xmm0_4
  unsigned int v35; // eax
  char *v36; // esi
  char *v37; // esi
  float v38; // xmm0_4
  unsigned int v39; // eax
  char *v40; // esi
  char *v41; // esi
  float v42; // xmm0_4
  unsigned int v43; // eax
  char *v44; // esi
  char *v45; // esi
  float *v46; // eax
  _QWORD *v47; // eax
  float v48; // xmm0_4
  CSheet::SheetInfo_t *v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  char *v53; // edx
  char *v54; // esi
  int v55; // ecx
  int v56; // edi
  double v57; // st7
  double v58; // st7
  int v59; // edi
  double v60; // st7
  float *v61; // edi
  double v62; // st7
  _BYTE *v63; // edi
  CSheet *v64; // ebx
  int v65; // ecx
  int v66; // edi
  CSheet::SheetInfo_t *i; // eax
  CSheet::SheetInfo_t *v69; // edx
  int value; // [esp+20h] [ebp-992Ch] BYREF
  int v71; // [esp+24h] [ebp-9928h]
  int v72; // [esp+28h] [ebp-9924h] BYREF
  int v73; // [esp+2Ch] [ebp-9920h] BYREF
  CSheet *v74; // [esp+30h] [ebp-991Ch]
  int v75; // [esp+34h] [ebp-9918h] BYREF
  int nNumValuesinList; // [esp+38h] [ebp-9914h] BYREF
  int outputBuffer; // [esp+3Ch] [ebp-9910h] BYREF
  int m_Size; // [esp+40h] [ebp-990Ch]
  float *v79; // [esp+44h] [ebp-9908h]
  float v80; // [esp+48h] [ebp-9904h] BYREF
  float inputBuffer; // [esp+4Ch] [ebp-9900h] BYREF
  int dest; // [esp+50h] [ebp-98FCh] BYREF
  float v83; // [esp+54h] [ebp-98F8h] BYREF
  float v84; // [esp+58h] [ebp-98F4h] BYREF
  float v85; // [esp+5Ch] [ebp-98F0h] BYREF
  float v86; // [esp+60h] [ebp-98ECh] BYREF
  int v87; // [esp+64h] [ebp-98E8h] BYREF
  float v88; // [esp+68h] [ebp-98E4h]
  int v89; // [esp+6Ch] [ebp-98E0h]
  char *v90; // [esp+70h] [ebp-98DCh] BYREF
  float v91; // [esp+74h] [ebp-98D8h] BYREF
  char *v92; // [esp+78h] [ebp-98D4h] BYREF
  float src; // [esp+7Ch] [ebp-98D0h] BYREF
  float v94; // [esp+80h] [ebp-98CCh] BYREF
  float v95; // [esp+84h] [ebp-98C8h] BYREF
  char *v96; // [esp+88h] [ebp-98C4h] BYREF
  char *v97; // [esp+8Ch] [ebp-98C0h] BYREF
  char *v98; // [esp+90h] [ebp-98BCh] BYREF
  char *v99; // [esp+94h] [ebp-98B8h] BYREF
  char *v100; // [esp+98h] [ebp-98B4h] BYREF
  char *v101; // [esp+9Ch] [ebp-98B0h] BYREF
  char *endptr; // [esp+A0h] [ebp-98ACh] BYREF
  int nIncrement; // [esp+A4h] [ebp-98A8h] BYREF
  _BYTE *v104; // [esp+A8h] [ebp-98A4h]
  float pValueB; // [esp+ACh] [ebp-98A0h] BYREF
  float pInterpolationValue; // [esp+B0h] [ebp-989Ch] BYREF
  float pValueA; // [esp+B4h] [ebp-9898h] BYREF
  float v108; // [esp+B8h] [ebp-9894h]
  float v109[18]; // [esp+BCh] [ebp-9890h] BYREF
  _BYTE v110[72]; // [esp+104h] [ebp-9848h] BYREF
  float pKnotValues[512]; // [esp+14Ch] [ebp-9800h] BYREF
  float pKnotPositions[512]; // [esp+94Ch] [ebp-9000h] BYREF
  _DWORD v113[8704]; // [esp+114Ch] [ebp-8800h] BYREF

  this->m_References.m_pHead = nullptr;
  p_m_SheetInfo = (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_SheetInfo;
  this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
  this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  this->m_SheetInfo.m_Memory.m_nGrowSize = 0;
  this->m_SheetInfo.m_Size = 0;
  this->m_SheetInfo.m_pElements = nullptr;
  v3 = (buf->m_Flags & 1) == 0;
  v74 = this;
  if ( v3 )
    CUtlBuffer::GetTypeBin<int>(this: buf, &dest);
  else
    CUtlBuffer::GetTypeText<int>(this: buf, value: &dest, nRadix: 0xAu);
  v3 = (buf->m_Flags & 1) == 0;
  v89 = dest != 0 ? 4 : 1;
  if ( v3 )
    CUtlBuffer::GetTypeBin<int>(this: buf, dest: &value);
  else
    CUtlBuffer::GetTypeText<int>(this: buf, &value, nRadix: 0xAu);
  dest = value;
  v4 = value;
  v71 = value;
  if ( value < 64 )
  {
    v4 = 64;
    v71 = 64;
  }
  CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(this: p_m_SheetInfo, num: value);
  if ( v4 > 0 )
  {
    v5 = 0;
    do
    {
      m_nAllocationCount = p_m_SheetInfo->m_Memory.m_nAllocationCount;
      m_Size = p_m_SheetInfo->m_Size;
      v6 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: &p_m_SheetInfo->m_Memory,
          num: m_Size - m_nAllocationCount + 1);
        v6 = m_Size;
      }
      ++p_m_SheetInfo->m_Size;
      m_pMemory = p_m_SheetInfo->m_Memory.m_pMemory;
      v9 = p_m_SheetInfo->m_Size - v6 - 1;
      v3 = p_m_SheetInfo->m_Size - v6 == 1;
      p_m_SheetInfo->m_pElements = p_m_SheetInfo->m_Memory.m_pMemory;
      if ( v9 >= 0 && !v3 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v9);
      p_m_SheetInfo->m_Memory.m_pMemory[v5].m_nDataAllocSize = 0;
      LOBYTE(p_m_SheetInfo->m_Memory.m_pMemory[v5].m_nDataLength) = 0;
      BYTE1(p_m_SheetInfo->m_Memory.m_pMemory[v5].m_nDataLength) = 0;
      HIWORD(p_m_SheetInfo->m_Memory.m_pMemory[v5].m_nDataLength) = 0;
      p_m_SheetInfo->m_Memory.m_pMemory[v5++].m_pData = nullptr;
      --v71;
    }
    while ( v71 != 0 );
  }
  if ( value != 0 )
  {
    do
    {
      --dest;
      if ( (buf->m_Flags & 1) != 0 )
      {
        nIncrement = 128;
        if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, &nIncrement) )
        {
LABEL_23:
          v11 = 0;
          outputBuffer = 0;
          goto LABEL_26;
        }
        endptr = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        v12 = endptr;
        v11 = strtol(nptr: endptr, &endptr, ibase: 0xAu);
        outputBuffer = v11;
        if ( endptr != v12 )
          buf->m_Get += endptr - v12;
      }
      else
      {
        if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
          goto LABEL_23;
        v10 = buf->m_Get - buf->m_nOffset;
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
        {
          CByteswap::SwapBufferToTargetEndian<int>(
            this: &buf->m_Byteswap,
            &outputBuffer,
            inputBuffer: (int *)&buf->m_Memory.m_pMemory[v10],
            count: 1);
          v11 = outputBuffer;
          buf->m_Get += 4;
        }
        else
        {
          v11 = *(_DWORD *)&buf->m_Memory.m_pMemory[v10];
          buf->m_Get += 4;
          outputBuffer = v11;
        }
      }
LABEL_26:
      if ( v11 < 0 )
      {
        _Warning(a1: "Invalid sequence number (%d)!!!\n", v11);
        return v74;
      }
      if ( v11 >= v74->m_SheetInfo.m_Size && outputBuffer > -1 )
      {
        do
        {
          v13 = v74->m_SheetInfo.m_Size;
          v14 = v74->m_SheetInfo.m_Memory.m_nAllocationCount;
          v15 = &v74->m_SheetInfo;
          if ( v13 + 1 > v14 )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
              this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v74->m_SheetInfo,
              num: v13 - v14 + 1);
          ++v15->m_Size;
          v16 = v15->m_Memory.m_pMemory;
          v17 = v15->m_Size - v13 - 1;
          v3 = v15->m_Size - v13 == 1;
          v15->m_pElements = v15->m_Memory.m_pMemory;
          if ( v17 >= 0 && !v3 )
            _V_memmove(dest: &v16[v13 + 1], src: &v16[v13], count: 12 * v17);
          v18 = v13;
          v19 = v13 < outputBuffer;
          v15->m_Memory.m_pMemory[v18].m_pSamples = nullptr;
          v15->m_Memory.m_pMemory[v18].m_SeqFlags = 0;
          v15->m_Memory.m_pMemory[v18].m_bSequenceIsCopyOfAnotherSequence = false;
          v15->m_Memory.m_pMemory[v18].m_nNumFrames = 0;
          v15->m_Memory.m_pMemory[v18].m_flFrameSpan = 0.0;
        }
        while ( v19 );
      }
      if ( (buf->m_Flags & 1) != 0 )
      {
        v75 = 128;
        if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v75) )
        {
LABEL_40:
          v87 = 0;
          goto LABEL_43;
        }
        v98 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        v21 = v98;
        v87 = strtol(nptr: v98, endptr: &v98, ibase: 0xAu);
        if ( v98 != v21 )
          buf->m_Get += v98 - v21;
      }
      else
      {
        if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
          goto LABEL_40;
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
        {
          CByteswap::SwapBufferToTargetEndian<int>(
            this: &buf->m_Byteswap,
            outputBuffer: &v87,
            inputBuffer: (int *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
            count: 1);
          buf->m_Get += 4;
        }
        else
        {
          v20 = *(_DWORD *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
          buf->m_Get += 4;
          v87 = v20;
        }
      }
LABEL_43:
      v22 = 12 * outputBuffer;
      v72 = (int)&v74->m_SheetInfo;
      v74->m_SheetInfo.m_Memory.m_pMemory[v22 / 0xCu].m_SeqFlags = v87;
      v3 = (buf->m_Flags & 1) == 0;
      m_Size = v22;
      if ( v3 )
      {
        if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
          goto LABEL_49;
        if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
        {
          CByteswap::SwapBufferToTargetEndian<int>(
            this: &buf->m_Byteswap,
            outputBuffer: &nNumValuesinList,
            inputBuffer: (int *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
            count: 1);
          v23 = nNumValuesinList;
          buf->m_Get += 4;
        }
        else
        {
          v23 = *(_DWORD *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
          buf->m_Get += 4;
          nNumValuesinList = v23;
        }
      }
      else
      {
        v75 = 128;
        if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v75) )
        {
LABEL_49:
          v23 = 0;
          nNumValuesinList = 0;
          goto LABEL_52;
        }
        v100 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        v24 = v100;
        v23 = strtol(nptr: v100, endptr: &v100, ibase: 0xAu);
        nNumValuesinList = v23;
        if ( v100 != v24 )
          buf->m_Get += v100 - v24;
      }
LABEL_52:
      *(_WORD *)(v22 + *(_DWORD *)v72 + 6) = v23;
      v25 = v23 != 1 ? 512 : 1;
      v75 = v25;
      *(SheetSequenceSample_t **)((char *)&v74->m_SheetInfo.m_Memory.m_pMemory->m_pSamples + m_Size) = (SheetSequenceSample_t *)MemAlloc_Alloc(nSize: 68 * v25);
      if ( (buf->m_Flags & 1) != 0 )
      {
        v72 = 128;
        if ( CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v72) )
        {
          v97 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
          v26 = v97;
          inputBuffer = strtod(nptr: v97, endptr: &v97);
          if ( v97 != v26 )
            buf->m_Get += v97 - v26;
        }
        else
        {
          inputBuffer = 0.0;
        }
      }
      else if ( CUtlBuffer::CheckGet(this: buf, nSize: 4) )
      {
        v3 = (*(_BYTE *)&buf->m_Byteswap & 1) == 0;
        inputBuffer = *(float *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
        if ( !v3 )
          CByteswap::SwapBufferToTargetEndian<float>(
            this: &buf->m_Byteswap,
            outputBuffer: &inputBuffer,
            &inputBuffer,
            count: 1);
        buf->m_Get += 4;
      }
      else
      {
        inputBuffer = 0.0;
      }
      v88 = 0.0;
      v71 = 0;
      if ( nNumValuesinList > 0 )
      {
        v108 = 1.0 / (float)(int)inputBuffer;
        value = (int)v113;
        do
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            v72 = 128;
            if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v72) )
            {
LABEL_70:
              v80 = 0.0;
              goto LABEL_73;
            }
            v90 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            v27 = v90;
            v80 = strtod(nptr: v90, endptr: &v90);
            if ( v90 != v27 )
              buf->m_Get += v90 - v27;
          }
          else
          {
            if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
              goto LABEL_70;
            v3 = (*(_BYTE *)&buf->m_Byteswap & 1) == 0;
            v80 = *(float *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
            if ( !v3 )
              CByteswap::SwapBufferToTargetEndian<float>(
                this: &buf->m_Byteswap,
                outputBuffer: &v80,
                inputBuffer: &v80,
                count: 1);
            buf->m_Get += 4;
          }
LABEL_73:
          v19 = v89 <= 0;
          v28 = v71;
          v29 = value;
          pKnotValues[v71] = (float)v71;
          pKnotPositions[v28] = (float)(v108 * v88) * 512.0;
          *(_DWORD *)(v29 + 64) = 0;
          if ( !v19 )
          {
            v79 = (float *)v29;
            v72 = v89;
            do
            {
              if ( (buf->m_Flags & 1) != 0 )
              {
                v73 = 128;
                if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v73) )
                {
LABEL_83:
                  v84 = 0.0;
                  goto LABEL_86;
                }
                v101 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                v33 = v101;
                v84 = strtod(nptr: v101, endptr: &v101);
                if ( v101 != v33 )
                  buf->m_Get += v101 - v33;
              }
              else
              {
                if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
                  goto LABEL_83;
                v3 = (*(_BYTE *)&buf->m_Byteswap & 1) == 0;
                v30 = *(float *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                v84 = v30;
                if ( !v3 )
                {
                  src = v30;
                  v31 = 0;
                  v32 = (char *)&v84 + 3;
                  do
                    *((_BYTE *)&src + v31++) = *v32--;
                  while ( v31 < 4 );
                  _V_memcpy(dest: &v84, &src, count: 4);
                }
                buf->m_Get += 4;
              }
LABEL_86:
              v3 = (buf->m_Flags & 1) == 0;
              *v79 = v84;
              if ( v3 )
              {
                if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
                  goto LABEL_94;
                v3 = (*(_BYTE *)&buf->m_Byteswap & 1) == 0;
                v34 = *(float *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                v86 = v34;
                if ( !v3 )
                {
                  v95 = v34;
                  v35 = 0;
                  v36 = (char *)&v86 + 3;
                  do
                    *((_BYTE *)&v95 + v35++) = *v36--;
                  while ( v35 < 4 );
                  _V_memcpy(dest: &v86, src: &v95, count: 4);
                }
                buf->m_Get += 4;
              }
              else
              {
                v73 = 128;
                if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v73) )
                {
LABEL_94:
                  v86 = 0.0;
                  goto LABEL_97;
                }
                v99 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                v37 = v99;
                v86 = strtod(nptr: v99, endptr: &v99);
                if ( v99 != v37 )
                  buf->m_Get += v99 - v37;
              }
LABEL_97:
              v3 = (buf->m_Flags & 1) == 0;
              v79[1] = v86;
              if ( v3 )
              {
                if ( !CUtlBuffer::CheckGet(this: buf, nSize: 4) )
                  goto LABEL_105;
                v3 = (*(_BYTE *)&buf->m_Byteswap & 1) == 0;
                v38 = *(float *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                v85 = v38;
                if ( !v3 )
                {
                  v91 = v38;
                  v39 = 0;
                  v40 = (char *)&v85 + 3;
                  do
                    *((_BYTE *)&v91 + v39++) = *v40--;
                  while ( v39 < 4 );
                  _V_memcpy(dest: &v85, src: &v91, count: 4);
                }
                buf->m_Get += 4;
              }
              else
              {
                v73 = 128;
                if ( !CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v73) )
                {
LABEL_105:
                  v85 = 0.0;
                  goto LABEL_108;
                }
                v92 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                v41 = v92;
                v85 = strtod(nptr: v92, endptr: &v92);
                if ( v92 != v41 )
                  buf->m_Get += v92 - v41;
              }
LABEL_108:
              v3 = (buf->m_Flags & 1) == 0;
              v79[2] = v85;
              if ( v3 )
              {
                if ( CUtlBuffer::CheckGet(this: buf, nSize: 4) )
                {
                  v3 = (*(_BYTE *)&buf->m_Byteswap & 1) == 0;
                  v42 = *(float *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                  v83 = v42;
                  if ( !v3 )
                  {
                    v94 = v42;
                    v43 = 0;
                    v44 = (char *)&v83 + 3;
                    do
                      *((_BYTE *)&v94 + v43++) = *v44--;
                    while ( v43 < 4 );
                    _V_memcpy(dest: &v83, src: &v94, count: 4);
                  }
                  buf->m_Get += 4;
                  goto LABEL_119;
                }
              }
              else
              {
                v73 = 128;
                if ( CUtlBuffer::CheckArbitraryPeekGet(this: buf, nOffset: 0, nIncrement: &v73) )
                {
                  v96 = (char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
                  v45 = v96;
                  v83 = strtod(nptr: v96, endptr: &v96);
                  if ( v96 != v45 )
                    buf->m_Get += v96 - v45;
                  goto LABEL_119;
                }
              }
              v83 = 0.0;
LABEL_119:
              v46 = v79;
              v79[3] = v83;
              v3 = v72-- == 1;
              v79 = v46 + 8;
            }
            while ( !v3 );
          }
          v47 = (_QWORD *)value;
          if ( v89 == 1 )
          {
            *(_QWORD *)(value + 32) = *(_QWORD *)value;
            v47[5] = v47[1];
            v47[6] = v47[2];
            v47[7] = v47[3];
          }
          v48 = v80 + v88;
          *(float *)((char *)&v74->m_SheetInfo.m_Memory.m_pMemory->m_flFrameSpan + m_Size) = v80 + v88;
          v19 = v71 + 1 < nNumValuesinList;
          v88 = v48;
          ++v71;
          value = (int)v47 + 68;
        }
        while ( v19 );
      }
      v71 = 0;
      if ( v75 > 0 )
      {
        value = 0;
        do
        {
          GetInterpolationData(
            pKnotPositions,
            pKnotValues,
            nNumValuesinList,
            nInterpolationRange: 512,
            flPositionToInterpolateAt: (float)v71,
            bWrap: (*(&v74->m_SheetInfo.m_Memory.m_pMemory->m_SeqFlags + m_Size) & 1) == 0,
            &pValueA,
            &pValueB,
            &pInterpolationValue);
          qmemcpy(v109, &v113[17 * (int)pValueA], 0x44u);
          v49 = v74->m_SheetInfo.m_Memory.m_pMemory;
          qmemcpy(v110, &v113[17 * (int)pValueB], 0x44u);
          v50 = *(int *)((char *)&v49->m_pSamples + m_Size) + value;
          *(float *)(v50 + 64) = pInterpolationValue;
          v51 = v50 + 4;
          v52 = -v50;
          v73 = (int)&v109[2] + v52;
          v53 = (char *)v109 + v52;
          v54 = (char *)&v109[1] + v52;
          v72 = (int)&v110[v52];
          v104 = &v110[v52 + 8];
          v79 = (float *)&v110[v52 + 4];
          v55 = 0;
          do
          {
            v56 = v73;
            *(float *)(v51 - 4) = v109[v55];
            v55 += 8;
            v57 = *(float *)&v53[v51];
            v51 += 32;
            *(float *)(v51 - 32) = v57;
            *(float *)(v51 - 28) = *(float *)&v54[v51 - 32];
            v58 = *(float *)(v51 + v56 - 32);
            v59 = v72;
            *(float *)(v51 - 24) = v58;
            *(float *)(v51 - 20) = v109[v55 + 10];
            v60 = *(float *)(v51 + v59 - 32);
            v61 = v79;
            *(float *)(v51 - 16) = v60;
            v62 = *(float *)((char *)v61 + v51 - 32);
            v63 = v104;
            *(float *)(v51 - 12) = v62;
            *(float *)(v51 - 8) = *(float *)&v63[v51 - 32];
          }
          while ( v55 < 16 );
          value += 68;
          ++v71;
        }
        while ( v71 < v75 );
      }
    }
    while ( dest != 0 );
  }
  v64 = v74;
  v65 = 0;
  v66 = 0;
  if ( v74->m_SheetInfo.m_Size > 0 )
  {
    for ( i = v74->m_SheetInfo.m_Memory.m_pMemory; i->m_pSamples == nullptr; ++i )
    {
      if ( ++v66 >= v74->m_SheetInfo.m_Size )
        return v74;
    }
    if ( v66 != -1 )
    {
      v75 = 0;
      do
      {
        v69 = v64->m_SheetInfo.m_Memory.m_pMemory;
        if ( v69[v65].m_pSamples == nullptr )
        {
          v69[v65].m_pSamples = v69[v66].m_pSamples;
          v64->m_SheetInfo.m_Memory.m_pMemory[v65].m_SeqFlags = v64->m_SheetInfo.m_Memory.m_pMemory[v66].m_SeqFlags;
          v64->m_SheetInfo.m_Memory.m_pMemory[v65].m_nNumFrames = v64->m_SheetInfo.m_Memory.m_pMemory[v66].m_nNumFrames;
          v64->m_SheetInfo.m_Memory.m_pMemory[v65].m_bSequenceIsCopyOfAnotherSequence = true;
        }
        ++v65;
        v19 = ++v75 < v64->m_SheetInfo.m_Size;
      }
      while ( v19 );
    }
  }
  return v64;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102D99E0
// Name: public: CSheet::~CSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheet::~CSheet(CSheet *this)
{
  int v2; // ebx
  int v3; // edi
  CSheet::SheetInfo_t *m_pMemory; // eax
  CSheet::SheetInfo_t *v5; // eax
  CUtlReference<CSheet> *m_pHead; // eax
  CUtlReference<CSheet> *m_pNext; // ecx

  v2 = 0;
  if ( this->m_SheetInfo.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_SheetInfo.m_Memory.m_pMemory;
      if ( m_pMemory[v3].m_pSamples != nullptr && !m_pMemory[v3].m_bSequenceIsCopyOfAnotherSequence )
        C_BaseEntity::operator delete(pMem: m_pMemory[v3].m_pSamples);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SheetInfo.m_Size );
  }
  this->m_SheetInfo.m_Size = 0;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SheetInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SheetInfo.m_Memory.m_pMemory);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_SheetInfo.m_Memory.m_pMemory;
  this->m_SheetInfo.m_pElements = v5;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( this->m_References.m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D9A90
// Name: public: CSheet::CSheet(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CSheet::CSheet(CSheet *this, CUtlBuffer *buf)
{
  CSheet *v2; // edi
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_SheetInfo; // ebx
  signed int Int; // eax
  signed int v5; // esi
  bool v6; // zf
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v7; // eax
  int v8; // eax
  int v9; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *j; // eax
  signed int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int v21; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v22; // ecx
  int v23; // eax
  int v24; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v25; // esi
  int v26; // edi
  unsigned int v27; // eax
  int v28; // esi
  int v29; // esi
  int v30; // ecx
  char *v31; // eax
  float *v32; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v33; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v34; // eax
  int v35; // eax
  signed int v36; // ecx
  float *v37; // eax
  _DWORD v38[2]; // [esp+20h] [ebp-98D8h] BYREF
  char v39; // [esp+28h] [ebp-98D0h] BYREF
  float pKnotPositions[512]; // [esp+8820h] [ebp-10D8h] BYREF
  float pKnotValues[546]; // [esp+9020h] [ebp-8D8h] BYREF
  float v42; // [esp+98A8h] [ebp-50h] BYREF
  float v43; // [esp+98ACh] [ebp-4Ch] BYREF
  float v44; // [esp+98B0h] [ebp-48h] BYREF
  float v45; // [esp+98B4h] [ebp-44h]
  float v46; // [esp+98B8h] [ebp-40h] BYREF
  float pInterpolationValue; // [esp+98BCh] [ebp-3Ch] BYREF
  float dest; // [esp+98C0h] [ebp-38h] BYREF
  float pValueB; // [esp+98C4h] [ebp-34h] BYREF
  float pValueA; // [esp+98C8h] [ebp-30h] BYREF
  float v51; // [esp+98CCh] [ebp-2Ch] BYREF
  int v52; // [esp+98D0h] [ebp-28h]
  int i; // [esp+98D4h] [ebp-24h]
  int v54; // [esp+98D8h] [ebp-20h]
  float v55; // [esp+98DCh] [ebp-1Ch]
  signed int v56; // [esp+98E0h] [ebp-18h]
  int v57; // [esp+98E4h] [ebp-14h]
  CSheet *v58; // [esp+98E8h] [ebp-10h]
  signed int v59; // [esp+98ECh] [ebp-Ch]
  char *v60; // [esp+98F0h] [ebp-8h]
  int nNumValuesinList; // [esp+98F4h] [ebp-4h]
  CUtlBuffer *v62; // [esp+9900h] [ebp+8h]

  v2 = this;
  this->m_References.m_pHead = nullptr;
  p_m_SheetInfo = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_SheetInfo;
  v58 = this;
  this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
  this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  this->m_SheetInfo.m_Memory.m_nGrowSize = 0;
  this->m_SheetInfo.m_Size = 0;
  this->m_SheetInfo.m_pElements = nullptr;
  v54 = CUtlBuffer::GetInt(this: buf) != 0 ? 4 : 1;
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = Int;
  v56 = Int;
  nNumValuesinList = Int;
  if ( Int < 64 )
    nNumValuesinList = 64;
  if ( p_m_SheetInfo->m_nAllocationCount < Int && p_m_SheetInfo->m_nGrowSize >= 0 )
  {
    v6 = p_m_SheetInfo->m_pMemory == nullptr;
    p_m_SheetInfo->m_nAllocationCount = Int;
    if ( v6 )
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * Int);
    else
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: p_m_SheetInfo->m_pMemory,
                                                          a3: 12 * Int);
    p_m_SheetInfo->m_pMemory = v7;
  }
  v8 = nNumValuesinList;
  p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( nNumValuesinList = v8; nNumValuesinList != 0; --nNumValuesinList )
    {
      m_pMemory = p_m_SheetInfo[1].m_pMemory;
      m_nAllocationCount = p_m_SheetInfo->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_m_SheetInfo,
          num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
      ++p_m_SheetInfo[1].m_pMemory;
      v12 = p_m_SheetInfo->m_pMemory;
      v13 = (char *)p_m_SheetInfo[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v12[(int)m_pMemory + 1],
          src: (unsigned __int8 *)&v12[(_DWORD)m_pMemory],
          count: 12 * v13);
      p_m_SheetInfo->m_pMemory[v9].m_Element = nullptr;
      LOBYTE(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      BYTE1(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      HIWORD(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      p_m_SheetInfo->m_pMemory[v9++].m_Next = 0;
    }
    v5 = v56;
    v2 = v58;
  }
  if ( v5 != 0 )
  {
    while ( 1 )
    {
      v56 = v5 - 1;
      v18 = CUtlBuffer::GetInt(this: buf);
      v19 = v18;
      v59 = v18;
      if ( v18 < 0 )
        break;
      if ( v18 >= v58->m_SheetInfo.m_Size )
      {
        do
        {
          v20 = (int)p_m_SheetInfo[1].m_pMemory;
          v21 = p_m_SheetInfo->m_nAllocationCount;
          if ( v20 + 1 > v21 )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: p_m_SheetInfo, num: v20 - v21 + 1);
          ++p_m_SheetInfo[1].m_pMemory;
          v22 = p_m_SheetInfo->m_pMemory;
          v23 = (int)p_m_SheetInfo[1].m_pMemory - v20 - 1;
          p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
          if ( v23 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v22[v20 + 1], src: (unsigned __int8 *)&v22[v20], count: 12 * v23);
          v24 = v20;
          p_m_SheetInfo->m_pMemory[v24].m_Element = nullptr;
          LOBYTE(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          BYTE1(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          HIWORD(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          p_m_SheetInfo->m_pMemory[v24].m_Next = 0;
        }
        while ( v20 < v19 );
      }
      v25 = p_m_SheetInfo->m_pMemory;
      v26 = v19;
      v57 = v26 * 12;
      LOBYTE(v25[v26].m_Previous) = CUtlBuffer::GetInt(this: buf);
      v27 = CUtlBuffer::GetInt(this: buf);
      HIWORD(p_m_SheetInfo->m_pMemory[v26].m_Previous) = v27;
      v28 = v27 != 1 ? 512 : 1;
      v6 = p_m_SheetInfo->m_pMemory[v26].m_Element == nullptr;
      nNumValuesinList = v27;
      v52 = v28;
      if ( !v6 )
      {
        _Warning(
          a1: "Invalid particle sheet sequence index.  There are more than one items with a sequence index of %d. We are only"
          " using the last one we found..\n",
          v59);
        C_BaseEntity::operator delete(pMem: p_m_SheetInfo->m_pMemory[v26].m_Element);
      }
      *(vgui::TreeNode **)((char *)&p_m_SheetInfo->m_pMemory->m_Element + v57) = (vgui::TreeNode *)MemAlloc_Alloc(nSize: (68 * (unsigned __int64)(unsigned int)v28) >> 32 != 0 ? -1 : 68 * v28);
      CUtlBuffer::GetType<float>(this: buf, &dest);
      v29 = 0;
      v55 = 0.0;
      v59 = 0;
      if ( nNumValuesinList > 0 )
      {
        v45 = 1.0 / (float)(int)dest;
        v60 = &v39;
        do
        {
          CUtlBuffer::GetType<float>(this: buf, dest: &v43);
          v30 = v54;
          v31 = v60;
          pKnotValues[v29] = (float)v29;
          pKnotPositions[v29] = (float)(v45 * v55) * 512.0;
          *((_DWORD *)v31 + 14) = 0;
          if ( v30 > 0 )
          {
            v32 = (float *)v31;
            for ( i = v30; i != 0; --i )
            {
              CUtlBuffer::GetType<float>(this: buf, dest: &v51);
              *(v32 - 2) = v51;
              CUtlBuffer::GetType<float>(this: buf, dest: &v44);
              *(v32 - 1) = v44;
              CUtlBuffer::GetType<float>(this: buf, dest: &v46);
              *v32 = v46;
              CUtlBuffer::GetType<float>(this: buf, dest: &v42);
              v32[1] = v42;
              v32 += 8;
            }
            v29 = v59;
            v30 = v54;
            v31 = v60;
          }
          if ( v30 == 1 )
          {
            *((_QWORD *)v31 + 3) = *((_QWORD *)v31 - 1);
            *((_QWORD *)v31 + 4) = *(_QWORD *)v31;
            *((_QWORD *)v31 + 5) = *((_QWORD *)v31 + 1);
            *((_QWORD *)v31 + 6) = *((_QWORD *)v31 + 2);
          }
          v33 = p_m_SheetInfo->m_pMemory;
          ++v29;
          v55 = v43 + v55;
          *(float *)((char *)&v33->m_Next + v57) = v55;
          v59 = v29;
          v60 = v31 + 68;
        }
        while ( v29 < nNumValuesinList );
      }
      v60 = nullptr;
      if ( v52 > 0 )
      {
        v59 = 0;
        do
        {
          GetInterpolationData(
            pKnotPositions,
            pKnotValues,
            nNumValuesinList,
            nInterpolationRange: 512,
            flPositionToInterpolateAt: (float)(int)v60,
            bWrap: (*((_BYTE *)&p_m_SheetInfo->m_pMemory->m_Previous + v57) & 1) == 0,
            &pValueA,
            &pValueB,
            &pInterpolationValue);
          v34 = p_m_SheetInfo->m_pMemory;
          qmemcpy(&pKnotValues[529], &v38[17 * (int)pValueA], 0x44u);
          qmemcpy(&pKnotValues[512], &v38[17 * (int)pValueB], 0x44u);
          v35 = *(int *)((char *)&v34->m_Element + v57);
          v36 = v59;
          *(float *)(v35 + v59 + 64) = pInterpolationValue;
          *(float *)(v35 + v36) = pKnotValues[529];
          *(float *)(v35 + v36 + 4) = pKnotValues[530];
          *(float *)(v35 + v36 + 8) = pKnotValues[531];
          *(float *)(v35 + v36 + 12) = pKnotValues[532];
          *(float *)(v35 + v36 + 16) = pKnotValues[512];
          *(float *)(v35 + v36 + 20) = pKnotValues[513];
          v37 = (float *)(v36 + v35);
          v37[6] = pKnotValues[514];
          v37[7] = pKnotValues[515];
          v37[8] = pKnotValues[537];
          v37[9] = pKnotValues[538];
          v37[10] = pKnotValues[539];
          v37[11] = pKnotValues[540];
          v37[12] = pKnotValues[520];
          v37[13] = pKnotValues[521];
          v37[14] = pKnotValues[522];
          v37[15] = pKnotValues[523];
          ++v60;
          v59 = v36 + 68;
        }
        while ( (int)v60 < v52 );
      }
      if ( v56 == 0 )
      {
        v2 = v58;
        goto LABEL_18;
      }
      v5 = v56;
    }
    _Warning(a1: "Invalid sequence number (%d)!!!\n", v18);
    return v58;
  }
  else
  {
LABEL_18:
    v14 = 0;
    v15 = 0;
    if ( v2->m_SheetInfo.m_Size > 0 )
    {
      for ( j = p_m_SheetInfo->m_pMemory; j->m_Element == nullptr; ++j )
      {
        if ( ++v15 >= v2->m_SheetInfo.m_Size )
          return v2;
      }
      if ( v15 != -1 )
      {
        v62 = nullptr;
        do
        {
          if ( p_m_SheetInfo->m_pMemory[v14].m_Element == nullptr )
          {
            p_m_SheetInfo->m_pMemory[v14].m_Element = p_m_SheetInfo->m_pMemory[v15].m_Element;
            LOBYTE(p_m_SheetInfo->m_pMemory[v14].m_Previous) = p_m_SheetInfo->m_pMemory[v15].m_Previous;
            v2 = v58;
            HIWORD(p_m_SheetInfo->m_pMemory[v14].m_Previous) = HIWORD(p_m_SheetInfo->m_pMemory[v15].m_Previous);
            BYTE1(p_m_SheetInfo->m_pMemory[v14].m_Previous) = 1;
          }
          ++v14;
          v62 = (CUtlBuffer *)((char *)v62 + 1);
        }
        while ( (int)v62 < v2->m_SheetInfo.m_Size );
      }
    }
    return v2;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1035EAE0
// Name: public: CSheet::~CSheet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSheet::~CSheet(CSheet *this)
{
  int v2; // ebx
  int v3; // edi
  CSheet::SheetInfo_t *m_pMemory; // eax
  CSheet::SheetInfo_t *v5; // eax
  CUtlReference<CSheet> *m_pHead; // eax
  CUtlReference<CSheet> *m_pNext; // ecx

  v2 = 0;
  if ( this->m_SheetInfo.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_SheetInfo.m_Memory.m_pMemory;
      if ( m_pMemory[v3].m_pSamples != nullptr && !m_pMemory[v3].m_bSequenceIsCopyOfAnotherSequence )
        free(pMem: m_pMemory[v3].m_pSamples);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_SheetInfo.m_Size );
  }
  this->m_SheetInfo.m_Size = 0;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SheetInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SheetInfo.m_Memory.m_pMemory);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_SheetInfo.m_Memory.m_pMemory;
  this->m_SheetInfo.m_pElements = v5;
  if ( this->m_SheetInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  }
  m_pHead = this->m_References.m_pHead;
  if ( this->m_References.m_pHead != nullptr )
  {
    do
    {
      m_pNext = m_pHead->m_pNext;
      m_pHead->m_pNext = nullptr;
      m_pHead->m_pPrev = nullptr;
      m_pHead->m_pObject = nullptr;
      m_pHead = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  this->m_References.m_pHead = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1035EB90
// Name: public: CSheet::CSheet(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CSheet::CSheet(CSheet *this, CUtlBuffer *buf)
{
  CSheet *v2; // edi
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *p_m_SheetInfo; // ebx
  signed int Int; // eax
  signed int v5; // esi
  bool v6; // zf
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v7; // eax
  int v8; // eax
  int v9; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *j; // eax
  signed int v18; // eax
  signed int v19; // edi
  int v20; // esi
  int v21; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v22; // ecx
  int v23; // eax
  int v24; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v25; // esi
  int v26; // edi
  unsigned int v27; // eax
  int v28; // esi
  int v29; // esi
  int v30; // ecx
  char *v31; // eax
  float *v32; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v33; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v34; // eax
  int v35; // eax
  signed int v36; // ecx
  float *v37; // eax
  _DWORD v38[2]; // [esp+20h] [ebp-98D8h] BYREF
  char v39; // [esp+28h] [ebp-98D0h] BYREF
  float pKnotPositions[512]; // [esp+8820h] [ebp-10D8h] BYREF
  float pKnotValues[546]; // [esp+9020h] [ebp-8D8h] BYREF
  float v42; // [esp+98A8h] [ebp-50h] BYREF
  float v43; // [esp+98ACh] [ebp-4Ch] BYREF
  float v44; // [esp+98B0h] [ebp-48h] BYREF
  float v45; // [esp+98B4h] [ebp-44h]
  float v46; // [esp+98B8h] [ebp-40h] BYREF
  float pInterpolationValue; // [esp+98BCh] [ebp-3Ch] BYREF
  float dest; // [esp+98C0h] [ebp-38h] BYREF
  float pValueB; // [esp+98C4h] [ebp-34h] BYREF
  float pValueA; // [esp+98C8h] [ebp-30h] BYREF
  float v51; // [esp+98CCh] [ebp-2Ch] BYREF
  int v52; // [esp+98D0h] [ebp-28h]
  int i; // [esp+98D4h] [ebp-24h]
  int v54; // [esp+98D8h] [ebp-20h]
  float v55; // [esp+98DCh] [ebp-1Ch]
  signed int v56; // [esp+98E0h] [ebp-18h]
  int v57; // [esp+98E4h] [ebp-14h]
  CSheet *v58; // [esp+98E8h] [ebp-10h]
  signed int v59; // [esp+98ECh] [ebp-Ch]
  char *v60; // [esp+98F0h] [ebp-8h]
  int nNumValuesinList; // [esp+98F4h] [ebp-4h]
  CUtlBuffer *v62; // [esp+9900h] [ebp+8h]

  v2 = this;
  this->m_References.m_pHead = nullptr;
  p_m_SheetInfo = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_SheetInfo;
  v58 = this;
  this->m_SheetInfo.m_Memory.m_pMemory = nullptr;
  this->m_SheetInfo.m_Memory.m_nAllocationCount = 0;
  this->m_SheetInfo.m_Memory.m_nGrowSize = 0;
  this->m_SheetInfo.m_Size = 0;
  this->m_SheetInfo.m_pElements = nullptr;
  v54 = CUtlBuffer::GetInt(this: buf) != 0 ? 4 : 1;
  Int = CUtlBuffer::GetInt(this: buf);
  v5 = Int;
  v56 = Int;
  nNumValuesinList = Int;
  if ( Int < 64 )
    nNumValuesinList = 64;
  if ( p_m_SheetInfo->m_nAllocationCount < Int && p_m_SheetInfo->m_nGrowSize >= 0 )
  {
    v6 = p_m_SheetInfo->m_pMemory == nullptr;
    p_m_SheetInfo->m_nAllocationCount = Int;
    if ( v6 )
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 12 * Int);
    else
      v7 = (UtlLinkedListElem_t<vgui::TreeNode *,int> *)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: p_m_SheetInfo->m_pMemory,
                                                          a3: 12 * Int);
    p_m_SheetInfo->m_pMemory = v7;
  }
  v8 = nNumValuesinList;
  p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( nNumValuesinList = v8; nNumValuesinList != 0; --nNumValuesinList )
    {
      m_pMemory = p_m_SheetInfo[1].m_pMemory;
      m_nAllocationCount = p_m_SheetInfo->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: p_m_SheetInfo,
          num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
      ++p_m_SheetInfo[1].m_pMemory;
      v12 = p_m_SheetInfo->m_pMemory;
      v13 = (char *)p_m_SheetInfo[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[(int)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 12 * v13);
      p_m_SheetInfo->m_pMemory[v9].m_Element = nullptr;
      LOBYTE(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      BYTE1(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      HIWORD(p_m_SheetInfo->m_pMemory[v9].m_Previous) = 0;
      p_m_SheetInfo->m_pMemory[v9++].m_Next = 0;
    }
    v5 = v56;
    v2 = v58;
  }
  if ( v5 != 0 )
  {
    while ( 1 )
    {
      v56 = v5 - 1;
      v18 = CUtlBuffer::GetInt(this: buf);
      v19 = v18;
      v59 = v18;
      if ( v18 < 0 )
        break;
      if ( v18 >= v58->m_SheetInfo.m_Size )
      {
        do
        {
          v20 = (int)p_m_SheetInfo[1].m_pMemory;
          v21 = p_m_SheetInfo->m_nAllocationCount;
          if ( v20 + 1 > v21 )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(this: p_m_SheetInfo, num: v20 - v21 + 1);
          ++p_m_SheetInfo[1].m_pMemory;
          v22 = p_m_SheetInfo->m_pMemory;
          v23 = (int)p_m_SheetInfo[1].m_pMemory - v20 - 1;
          p_m_SheetInfo[1].m_nAllocationCount = (int)p_m_SheetInfo->m_pMemory;
          if ( v23 > 0 )
            _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 12 * v23);
          v24 = v20;
          p_m_SheetInfo->m_pMemory[v24].m_Element = nullptr;
          LOBYTE(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          BYTE1(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          HIWORD(p_m_SheetInfo->m_pMemory[v24].m_Previous) = 0;
          p_m_SheetInfo->m_pMemory[v24].m_Next = 0;
        }
        while ( v20 < v19 );
      }
      v25 = p_m_SheetInfo->m_pMemory;
      v26 = v19;
      v57 = v26 * 12;
      LOBYTE(v25[v26].m_Previous) = CUtlBuffer::GetInt(this: buf);
      v27 = CUtlBuffer::GetInt(this: buf);
      HIWORD(p_m_SheetInfo->m_pMemory[v26].m_Previous) = v27;
      v28 = v27 != 1 ? 512 : 1;
      v6 = p_m_SheetInfo->m_pMemory[v26].m_Element == nullptr;
      nNumValuesinList = v27;
      v52 = v28;
      if ( !v6 )
      {
        _Warning(
          a1: "Invalid particle sheet sequence index.  There are more than one items with a sequence index of %d. We are only"
          " using the last one we found..\n",
          v59);
        free(pMem: p_m_SheetInfo->m_pMemory[v26].m_Element);
      }
      *(vgui::TreeNode **)((char *)&p_m_SheetInfo->m_pMemory->m_Element + v57) = (vgui::TreeNode *)operator new(nSize: 68 * v28);
      CUtlBuffer::GetType<float>(this: buf, &dest);
      v29 = 0;
      v55 = 0.0;
      v59 = 0;
      if ( nNumValuesinList > 0 )
      {
        v45 = 1.0 / (float)(int)dest;
        v60 = &v39;
        do
        {
          CUtlBuffer::GetType<float>(this: buf, dest: &v43);
          v30 = v54;
          v31 = v60;
          pKnotValues[v29] = (float)v29;
          pKnotPositions[v29] = (float)(v45 * v55) * 512.0;
          *((_DWORD *)v31 + 14) = 0;
          if ( v30 > 0 )
          {
            v32 = (float *)v31;
            for ( i = v30; i != 0; --i )
            {
              CUtlBuffer::GetType<float>(this: buf, dest: &v51);
              *(v32 - 2) = v51;
              CUtlBuffer::GetType<float>(this: buf, dest: &v44);
              *(v32 - 1) = v44;
              CUtlBuffer::GetType<float>(this: buf, dest: &v46);
              *v32 = v46;
              CUtlBuffer::GetType<float>(this: buf, dest: &v42);
              v32[1] = v42;
              v32 += 8;
            }
            v29 = v59;
            v30 = v54;
            v31 = v60;
          }
          if ( v30 == 1 )
          {
            *((_QWORD *)v31 + 3) = *((_QWORD *)v31 - 1);
            *((_QWORD *)v31 + 4) = *(_QWORD *)v31;
            *((_QWORD *)v31 + 5) = *((_QWORD *)v31 + 1);
            *((_QWORD *)v31 + 6) = *((_QWORD *)v31 + 2);
          }
          v33 = p_m_SheetInfo->m_pMemory;
          ++v29;
          v55 = v43 + v55;
          *(float *)((char *)&v33->m_Next + v57) = v55;
          v59 = v29;
          v60 = v31 + 68;
        }
        while ( v29 < nNumValuesinList );
      }
      v60 = nullptr;
      if ( v52 > 0 )
      {
        v59 = 0;
        do
        {
          GetInterpolationData(
            pKnotPositions,
            pKnotValues,
            nNumValuesinList,
            nInterpolationRange: 512,
            flPositionToInterpolateAt: (float)(int)v60,
            bWrap: (*((_BYTE *)&p_m_SheetInfo->m_pMemory->m_Previous + v57) & 1) == 0,
            &pValueA,
            &pValueB,
            &pInterpolationValue);
          v34 = p_m_SheetInfo->m_pMemory;
          qmemcpy(&pKnotValues[529], &v38[17 * (int)pValueA], 0x44u);
          qmemcpy(&pKnotValues[512], &v38[17 * (int)pValueB], 0x44u);
          v35 = *(int *)((char *)&v34->m_Element + v57);
          v36 = v59;
          *(float *)(v35 + v59 + 64) = pInterpolationValue;
          *(float *)(v35 + v36) = pKnotValues[529];
          *(float *)(v35 + v36 + 4) = pKnotValues[530];
          *(float *)(v35 + v36 + 8) = pKnotValues[531];
          *(float *)(v35 + v36 + 12) = pKnotValues[532];
          *(float *)(v35 + v36 + 16) = pKnotValues[512];
          *(float *)(v35 + v36 + 20) = pKnotValues[513];
          v37 = (float *)(v36 + v35);
          v37[6] = pKnotValues[514];
          v37[7] = pKnotValues[515];
          v37[8] = pKnotValues[537];
          v37[9] = pKnotValues[538];
          v37[10] = pKnotValues[539];
          v37[11] = pKnotValues[540];
          v37[12] = pKnotValues[520];
          v37[13] = pKnotValues[521];
          v37[14] = pKnotValues[522];
          v37[15] = pKnotValues[523];
          ++v60;
          v59 = v36 + 68;
        }
        while ( (int)v60 < v52 );
      }
      if ( v56 == 0 )
      {
        v2 = v58;
        goto LABEL_18;
      }
      v5 = v56;
    }
    _Warning(a1: "Invalid sequence number (%d)!!!\n", v18);
    return v58;
  }
  else
  {
LABEL_18:
    v14 = 0;
    v15 = 0;
    if ( v2->m_SheetInfo.m_Size > 0 )
    {
      for ( j = p_m_SheetInfo->m_pMemory; j->m_Element == nullptr; ++j )
      {
        if ( ++v15 >= v2->m_SheetInfo.m_Size )
          return v2;
      }
      if ( v15 != -1 )
      {
        v62 = nullptr;
        do
        {
          if ( p_m_SheetInfo->m_pMemory[v14].m_Element == nullptr )
          {
            p_m_SheetInfo->m_pMemory[v14].m_Element = p_m_SheetInfo->m_pMemory[v15].m_Element;
            LOBYTE(p_m_SheetInfo->m_pMemory[v14].m_Previous) = p_m_SheetInfo->m_pMemory[v15].m_Previous;
            v2 = v58;
            HIWORD(p_m_SheetInfo->m_pMemory[v14].m_Previous) = HIWORD(p_m_SheetInfo->m_pMemory[v15].m_Previous);
            BYTE1(p_m_SheetInfo->m_pMemory[v14].m_Previous) = 1;
          }
          ++v14;
          v62 = (CUtlBuffer *)((char *)v62 + 1);
        }
        while ( (int)v62 < v2->m_SheetInfo.m_Size );
      }
    }
    return v2;
  }
}

} // namespace server
