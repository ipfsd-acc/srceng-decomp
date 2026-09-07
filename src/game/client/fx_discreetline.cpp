// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_discreetline.cpp
// Functions: 4
// ============================================================

#include "game\client\fx_discreetline.h"

//------------------------------------------------------------------------------
// Address: 0x1026A340
// Name: public: virtual bool CFXDiscreetLine::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFXDiscreetLine::IsActive(CFXDiscreetLine *this)
{
  return this->m_fLife > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1026A380
// Name: public: virtual void CFXDiscreetLine::Update(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFXDiscreetLine::Update(CFXDiscreetLine *this, long double frametime)
{
  float v2; // xmm1_4

  v2 = this->m_fStartTime + frametime;
  this->m_fStartTime = v2;
  this->m_fLife = this->m_fLife - frametime;
}

//------------------------------------------------------------------------------
// Address: 0x1026A3C0
// Name: public: CFXDiscreetLine::CFXDiscreetLine(char const __near *,class Vector const __near &,class Vector const __near &,float,float,float,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFXDiscreetLine *__thiscall CFXDiscreetLine::CFXDiscreetLine(
        CFXDiscreetLine *this,
        const char *name,
        const Vector *start,
        const Vector *direction,
        float velocity,
        float length,
        float clipLength,
        float scale,
        float life,
        const char *shader)
{
  IMaterial *v11; // eax

  CClientSideEffect::CClientSideEffect(this, name);
  this->__vftable = (CFXDiscreetLine_vtbl *)&CFXDiscreetLine::`vftable';
  if ( materials != nullptr )
  {
    v11 = materials->FindMaterial(this: materials, a2: shader, a3: "ClientEffect textures", a4: 1, a5: 0);
    this->m_pMaterial = v11;
    v11->IncrementReferenceCount(this: v11);
    this->m_vecOrigin = *start;
    this->m_vecDirection = *direction;
    this->m_fVelocity = velocity;
    this->m_fClipLength = clipLength;
    this->m_fScale = scale;
    this->m_fLife = life;
    this->m_fStartTime = 0.0;
    this->m_fLength = length;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026A4B0
// Name: public: virtual void CFXDiscreetLine::Draw(double)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CFXDiscreetLine::Draw(
        CFXDiscreetLine *this@<ecx>,
        float a2@<ebx>,
        float a3@<edi>,
        int a4@<esi>,
        long double frametime)
{
  float v6; // xmm6_4
  float m_fLength; // xmm1_4
  float v8; // xmm7_4
  float m_fClipLength; // xmm0_4
  float v10; // xmm0_4
  float z; // xmm2_4
  float v12; // xmm0_4
  float y; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  const Vector *v20; // eax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  int v24; // eax
  int v25; // ebx
  const Vector *v26; // eax
  const Vector *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  int (__thiscall *v31)(int, int, _DWORD, _DWORD, _DWORD); // edx
  IMesh *v32; // edi
  float *m_pCurrPosition; // eax
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float *v37; // eax
  unsigned int v38; // esi
  float v39; // xmm1_4
  float *v40; // eax
  float v41; // xmm2_4
  float *v42; // eax
  float v43; // xmm1_4
  float *v44; // eax
  float v45; // xmm2_4
  float *v46; // eax
  float *v47; // eax
  float v48; // xmm2_4
  float v49; // xmm0_4
  float *v50; // eax
  float *v51; // eax
  float v52; // xmm3_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float *v55; // eax
  unsigned int v56; // esi
  float v57; // xmm1_4
  float *v58; // eax
  float v59; // xmm2_4
  float *v60; // eax
  float v61; // xmm1_4
  float *v62; // eax
  float v63; // xmm2_4
  float *v64; // eax
  float *v65; // eax
  float v66; // xmm0_4
  float v67; // xmm2_4
  float *v68; // eax
  float v69; // xmm2_4
  float *v70; // eax
  float v71; // xmm3_4
  float v72; // xmm1_4
  float *v73; // eax
  float m_fScale; // xmm3_4
  float v75; // xmm1_4
  float *v76; // eax
  float v77; // xmm2_4
  float *v78; // eax
  float v79; // xmm3_4
  float v80; // xmm1_4
  float *v81; // eax
  float v82; // xmm2_4
  float *v83; // eax
  float v84; // xmm2_4
  float *v85; // eax
  float v86; // xmm3_4
  float v87; // xmm1_4
  float *v88; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-224h] BYREF
  float v92; // [esp+1F4h] [ebp-3Ch]
  Vector lineDir; // [esp+1F8h] [ebp-38h]
  float flAlpha; // [esp+204h] [ebp-2Ch]
  float fOffset; // [esp+208h] [ebp-28h]
  Vector vecEnd; // [esp+20Ch] [ebp-24h]
  Vector vecStart; // [esp+218h] [ebp-18h]
  Vector cross; // [esp+224h] [ebp-Ch] BYREF
  float flScale_4; // [esp+23Ch] [ebp+Ch]
  float flScale_4a; // [esp+23Ch] [ebp+Ch]
  float flScale_4b; // [esp+23Ch] [ebp+Ch]

  ((void (__thiscall *)(CFXDiscreetLine *, _DWORD, _DWORD, int))this->Update)(
    a1: this,
    a2: LODWORD(frametime),
    a3: HIDWORD(frametime),
    a4);
  v6 = this->m_fStartTime * this->m_fVelocity;
  m_fLength = this->m_fLength;
  v8 = v6 - m_fLength;
  if ( v6 < 0.0 )
    v6 = 0.0;
  if ( v8 < 0.0 )
    v8 = 0.0;
  if ( v6 != 0.0 || v8 != 0.0 )
  {
    m_fClipLength = this->m_fClipLength;
    if ( m_fClipLength != 0.0 )
    {
      if ( m_fClipLength <= v6 )
        v6 = this->m_fClipLength;
      if ( m_fClipLength <= v8 )
        v8 = this->m_fClipLength;
    }
    v10 = fabs(v6 - v8);
    if ( m_fLength == 0.0 )
      m_fLength = 0.0099999998;
    z = this->m_vecDirection.z;
    v12 = v10 / m_fLength;
    y = this->m_vecDirection.y;
    fOffset = v12;
    v14 = (float)(this->m_vecDirection.x * v6) + this->m_vecOrigin.x;
    v15 = (float)(y * v6) + this->m_vecOrigin.y;
    v16 = (float)(z * v6) + this->m_vecOrigin.z;
    v17 = (float)(this->m_vecDirection.x * v8) + this->m_vecOrigin.x;
    v18 = (float)(y * v8) + this->m_vecOrigin.y;
    v19 = (float)(z * v8) + this->m_vecOrigin.z;
    cross.y = a2;
    vecEnd.x = v14;
    vecEnd.y = v15;
    vecEnd.z = v16;
    cross.x = a3;
    vecStart.x = v17;
    vecStart.y = v18;
    vecStart.z = v19;
    lineDir.x = v14 - v17;
    lineDir.y = v15 - v18;
    lineDir.z = v16 - v19;
    v20 = CurrentViewOrigin();
    v21 = v15 - v20->y;
    v22 = v16 - v20->z;
    v23 = v14 - v20->x;
    cross.x = (float)(v22 * lineDir.y) - (float)(v21 * lineDir.z);
    cross.y = (float)(lineDir.z * v23) - (float)(v22 * lineDir.x);
    cross.z = (float)(v21 * lineDir.x) - (float)(lineDir.y * v23);
    VectorNormalize(vec: &cross);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v24 = ((int (__thiscall *)(IMaterialSystem *, _DWORD, _DWORD, _DWORD))materials->GetRenderContext)(
            a1: materials,
            a2: LODWORD(cross.x),
            a3: LODWORD(cross.y),
            a4: LODWORD(cross.z));
    v25 = v24;
    if ( v24 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 8))(a1: v24);
    if ( tracer_extra.m_pParent != nullptr && tracer_extra.m_pParent->m_Value.m_nValue != 0 )
    {
      flScale_4 = (float)ScreenWidth() * 0.5;
      v26 = CurrentViewOrigin();
      lineDir.x = vecStart.x - v26->x;
      lineDir.y = vecStart.y - v26->y;
      lineDir.z = vecStart.z - v26->z;
      v27 = CurrentViewForward();
      v28 = (float)((float)(v27->y * lineDir.y) + (float)(v27->x * lineDir.x)) + (float)(v27->z * lineDir.z);
      v29 = (float)(this->m_fScale * flScale_4) / v28;
      if ( v29 >= 0.5 )
      {
        v30 = 1.0;
        flScale_4a = this->m_fScale;
      }
      else
      {
        v30 = (float)((float)((float)(v29 - 0.25) * 0.69999999) * 0.5714286) + 0.30000001;
        if ( v30 >= 0.25 )
        {
          if ( v30 > 1.0 )
            v30 = 1.0;
          flScale_4a = (float)(v28 * 0.5) / flScale_4;
        }
        else
        {
          v30 = 0.25;
          flScale_4a = (float)(v28 * 0.5) / flScale_4;
        }
      }
      v31 = *(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v25 + 228);
      LODWORD(cross.z) = this->m_pMaterial;
      flAlpha = v30;
      v32 = (IMesh *)v31(a1: v25, a2: 1, a3: 0, a4: 0, a5: LODWORD(cross.z));
      meshBuilder.m_pMesh = v32;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      v32->SetPrimitiveType(this: v32, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 8, a3: 12, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v32->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 12;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v32,
        nMaxVertexCount: 8,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v34 = flAlpha * 255.0;
      v35 = (float)(COERCE_FLOAT(LODWORD(flScale_4a) ^ _mask__NegFloat_) * cross.y) + vecStart.y;
      LODWORD(v92) = LODWORD(flScale_4a) ^ _mask__NegFloat_;
      v36 = (float)(COERCE_FLOAT(LODWORD(flScale_4a) ^ _mask__NegFloat_) * cross.z) + vecStart.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(COERCE_FLOAT(LODWORD(flScale_4a) ^ _mask__NegFloat_)
                                                           * cross.x)
                                                   + vecStart.x;
      m_pCurrPosition[1] = v35;
      m_pCurrPosition[2] = v36;
      v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v37[1] = 0.0;
      v38 = (unsigned __int8)(int)v34 | (((unsigned __int8)(int)v34 | (((int)v34 | 0xFFFFFF00) << 8)) << 8);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v38;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v39 = cross.y;
      v40 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v41 = cross.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(cross.x * flScale_4a) + vecStart.x;
      v40[1] = (float)(v39 * flScale_4a) + vecStart.y;
      v40[2] = (float)(v41 * flScale_4a) + vecStart.z;
      v42 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v42[1] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v38;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v43 = cross.y;
      v44 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v45 = cross.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(cross.x * flScale_4a) + vecEnd.x;
      v44[1] = (float)(v43 * flScale_4a) + vecEnd.y;
      v44[2] = (float)(v45 * flScale_4a) + vecEnd.z;
      v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v46[1] = fOffset;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v38;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v47 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v48 = (float)(v92 * cross.y) + vecEnd.y;
      v49 = (float)(v92 * cross.z) + vecEnd.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v92 * cross.x) + vecEnd.x;
      v47[1] = v48;
      v47[2] = v49;
      v50 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v50[1] = fOffset;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v38;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v51 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v52 = flAlpha * 64.0;
      flScale_4b = flScale_4a * 2.0;
      v53 = (float)(COERCE_FLOAT(LODWORD(flScale_4b) ^ _mask__NegFloat_) * cross.y) + vecStart.y;
      LODWORD(v92) = LODWORD(flScale_4b) ^ _mask__NegFloat_;
      v54 = (float)(COERCE_FLOAT(LODWORD(flScale_4b) ^ _mask__NegFloat_) * cross.z) + vecStart.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(COERCE_FLOAT(LODWORD(flScale_4b) ^ _mask__NegFloat_)
                                                           * cross.x)
                                                   + vecStart.x;
      v51[1] = v53;
      v51[2] = v54;
      v55 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v55[1] = 0.0;
      v56 = (unsigned __int8)(int)v52 | (((unsigned __int8)(int)v52 | (((int)v52 | 0xFFFFFF00) << 8)) << 8);
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v56;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v57 = cross.y;
      v58 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v59 = cross.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(cross.x * flScale_4b) + vecStart.x;
      v58[1] = (float)(v57 * flScale_4b) + vecStart.y;
      v58[2] = (float)(v59 * flScale_4b) + vecStart.z;
      v60 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v60[1] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v56;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v61 = cross.y;
      v62 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v63 = cross.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(cross.x * flScale_4b) + vecEnd.x;
      v62[1] = (float)(v61 * flScale_4b) + vecEnd.y;
      v62[2] = (float)(v63 * flScale_4b) + vecEnd.z;
      v64 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v64[1] = fOffset;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v56;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v65 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v66 = (float)(v92 * cross.z) + vecEnd.z;
      v67 = (float)(v92 * cross.y) + vecEnd.y;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v92 * cross.x) + vecEnd.x;
      v65[1] = v67;
      v65[2] = v66;
      v68 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v68[1] = fOffset;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v56;
    }
    else
    {
      v32 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, IMaterial *))(*(_DWORD *)v25 + 228))(
                       a1: v25,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: this->m_pMaterial);
      meshBuilder.m_pMesh = v32;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      v32->SetPrimitiveType(this: v32, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v32->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v32,
        nMaxVertexCount: 4,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      v69 = cross.y;
      v70 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v71 = cross.z;
      LODWORD(v72) = LODWORD(this->m_fScale) ^ _mask__NegFloat_;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v72 * cross.x) + vecStart.x;
      v70[1] = (float)(v69 * v72) + vecStart.y;
      v70[2] = (float)(v71 * v72) + vecStart.z;
      v73 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v73[1] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      m_fScale = this->m_fScale;
      v75 = cross.y;
      v76 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v77 = cross.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(m_fScale * cross.x) + vecStart.x;
      v76[1] = (float)(v75 * m_fScale) + vecStart.y;
      v76[2] = (float)(v77 * m_fScale) + vecStart.z;
      v78 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v78[1] = 0.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v79 = this->m_fScale;
      v80 = cross.y;
      v81 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v82 = cross.z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v79 * cross.x) + vecEnd.x;
      v81[1] = (float)(v80 * v79) + vecEnd.y;
      v81[2] = (float)(v82 * v79) + vecEnd.z;
      v83 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v83[1] = fOffset;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v84 = cross.y;
      v85 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v86 = cross.z;
      LODWORD(v87) = LODWORD(this->m_fScale) ^ _mask__NegFloat_;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v87 * cross.x) + vecEnd.x;
      v85[1] = (float)(v84 * v87) + vecEnd.y;
      v85[2] = (float)(v86 * v87) + vecEnd.z;
      v88 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v88[1] = fOffset;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
    }
    *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = cross;
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
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v32->Draw_2(this: v32, a2: -1, a3: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v25 + 12))(a1: v25);
    (*(void (__thiscall **)(int))(*(_DWORD *)v25 + 4))(a1: v25);
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
}
