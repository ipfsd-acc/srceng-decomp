// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxmorphcharacter.cpp
// Functions: 13
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxmorphcharacter.h"

//------------------------------------------------------------------------------
// Address: 0x100D50A0
// Name: public: virtual class GRect<float> GFxConstShapeCharacterDef::GetBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxConstShapeCharacterDef::GetBoundsLocal(float *this, float *a2)
{
  *a2 = *(this + 5);
  a2[1] = *(this + 6);
  a2[2] = *(this + 7);
  a2[3] = *(this + 8);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10157FE0
// Name: public: void GFxMorphCharacterDef::Path::AddForTessellation(class GCompoundShape __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMorphCharacterDef::Path::AddForTessellation(
        GFxMorphCharacterDef::Path *this,
        struct GCompoundShape *a2)
{
  int v3; // ebx
  int v4; // edi

  GCompoundShape::BeginPath(this: (char *)a2, lStyle: (localeinfo_struct *)(*(_DWORD *)this - 1));
  v3 = *((_DWORD *)this + 6);
  if ( v3 != 0 )
  {
    v4 = 0;
    do
    {
      GCompoundShape::AddCurve(
        this: (GCompoundShape *)a2,
        a2: *(float *)(v4 + *((_DWORD *)this + 5)),
        a3: *(float *)(v4 + *((_DWORD *)this + 5) + 4),
        a4: *(float *)(v4 + *((_DWORD *)this + 5) + 8),
        a5: *(float *)(*((_DWORD *)this + 5) + v4 + 12));
      v4 += 16;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158060
// Name: public: virtual void GFxMorphCharacterDef::Tessellate(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMorphCharacterDef::Tessellate(
        GFxMorphCharacterDef *this,
        struct GFxMeshSet *a2,
        char *a3,
        struct GFxDisplayContext *a4,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *a5)
{
  int v6; // ebx
  struct GCompoundShape *v7; // edi
  int v9; // eax
  GFxMorphCharacterDef::Path *v10; // ecx
  float t; // [esp+0h] [ebp-20h]
  float ta; // [esp+0h] [ebp-20h]
  unsigned int v13; // [esp+4h] [ebp-1Ch]
  int v14[4]; // [esp+10h] [ebp-10h] BYREF
  int v15; // [esp+2Ch] [ebp+Ch]
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *v16; // [esp+34h] [ebp+14h]

  v6 = *(_DWORD *)(*((_DWORD *)a4 + 26) + 16);
  v7 = (struct GCompoundShape *)(v6 + 8);
  GCompoundShape::Clear(this: (GCompoundShape *)(v6 + 8));
  GCompoundShape::SetCurveTolerance(this: (long double *)(v6 + 8), t: a3);
  *(_BYTE *)(v6 + 76) = (*((_BYTE *)this + 52) & 8) != 0;
  if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
  {
    t = ((double (__thiscall *)(char *))*(_DWORD *)(*((_DWORD *)this + 4) + 56))(a1: (char *)this + 16);
    GFxMeshSet::SetShapeBounds(a1: (int)this + 20, a2: t);
  }
  if ( a5 != nullptr )
  {
    GFxScale9GridInfo::Compute(this: a5, gy1: v13);
    if ( (*((_BYTE *)this + 52) & 0x10) != 0 )
    {
      ta = ((double (__thiscall *)(char *))*(_DWORD *)(*((_DWORD *)this + 4) + 56))(a1: (char *)this + 16);
      v9 = GFxScale9GridInfo::AdjustBounds(a1: (int)v14, xb1: COERCE_FLOAT((GFxMorphCharacterDef *)((char *)this + 20)));
      GFxMeshSet::SetShapeBounds(a1: v9, a2: ta);
    }
  }
  if ( *((_DWORD *)this + 50) != 0 )
  {
    v15 = 0;
    v16 = *((CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> **)this
          + 50);
    do
    {
      v10 = (GFxMorphCharacterDef::Path *)(*((_DWORD *)this + 49) + v15);
      if ( *((_BYTE *)v10 + 32) != 0 )
      {
        GFxShapeBase::AddShapeToMesh(
          this: (GFxShapeBase *)((char *)this + 16),
          meshSet: a2,
          meshSet_4: v7,
          s9g: a4,
          s9g_4: (struct GFxScale9GridInfo *)a5);
        GCompoundShape::Clear(this: (GCompoundShape *)v7);
      }
      else
      {
        GFxMorphCharacterDef::Path::AddForTessellation(this: v10, a2: v7);
      }
      v15 += 36;
      v16 = (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *)((char *)v16 - 1);
    }
    while ( v16 != nullptr );
  }
  GFxShapeBase::AddShapeToMesh(
    this: (GFxShapeBase *)((char *)this + 16),
    meshSet: a2,
    meshSet_4: v7,
    s9g: a4,
    s9g_4: (struct GFxScale9GridInfo *)a5);
  GCompoundShape::Clear(this: (GCompoundShape *)v7);
  if ( a5 != nullptr && *((_DWORD *)&a5[14].m_pObject + 1) != 0 )
  {
    GFxScale9GridInfo::ComputeImgAdjustMatrices(this: a5, p: v13);
    GFxMeshSet::SetImgAdjustMatrices(a1: &a5[14].m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158190
// Name: public: virtual void GFxMorphCharacterDef::MakeCompoundShape(class GCompoundShape __near *,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMorphCharacterDef::MakeCompoundShape(GFxMorphCharacterDef *this, GCompoundShape *a2, char *t)
{
  int v5; // esi
  GCompoundShape *v6; // [esp+14h] [ebp+8h]

  GCompoundShape::Clear(this: a2);
  GCompoundShape::SetCurveTolerance(this: (long double *)a2, t);
  if ( *((_DWORD *)this + 50) != 0 )
  {
    v5 = 0;
    v6 = *((GCompoundShape **)this + 50);
    do
    {
      GFxMorphCharacterDef::Path::AddForTessellation(
        this: (GFxMorphCharacterDef::Path *)(v5 + *((_DWORD *)this + 49)),
        (struct GCompoundShape *)a2);
      v5 += 36;
      v6 = (GCompoundShape *)((char *)v6 - 1);
    }
    while ( v6 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158270
// Name: public: virtual void GFxMorphCharacterDef::Display(class GFxDisplayContext __near &,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxMorphCharacterDef::Display(
        GFxMorphCharacterDef *this@<ecx>,
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *a2@<edi>,
        int a3@<esi>,
        struct GFxDisplayContext *a4,
        struct GFxCharacter *a5)
{
  struct GFxDisplayContext *v6; // edi
  int v7; // ecx
  float *v8; // eax
  float *v9; // ecx
  double v10; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st6
  int v14; // esi
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // esi
  __int16 v18; // dx
  int v19; // ecx
  int v20; // esi
  unsigned int v21; // edi
  int v22; // ecx
  int v23; // eax
  const struct GFxFillStyle *v24; // esi
  GFxFillStyle *v25; // ecx
  struct GFxFillStyle *v26; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v27; // eax
  GRefCountNTSImpl *v28; // eax
  float *v29; // eax
  struct GFxDisplayContext *v30; // edi
  double MaxScale; // st7
  float *v32; // ecx
  bool v33; // zf
  double v34; // st7
  GRefCountNTSImpl *v35; // eax
  int v36; // edi
  _BOOL2 v37; // dx
  unsigned int v38; // ecx
  double v39; // st7
  double v40; // st7
  int v41; // eax
  int v42; // edx
  int v43; // eax
  int v44; // edi
  GRefCountNTSImpl *v45; // esi
  GRefCountNTSImpl *v46; // ecx
  CFltX4AttributeIterator *v47; // eax
  double v48; // st7
  unsigned int v49; // eax
  unsigned int v50; // eax
  int v51; // esi
  int m_nAttributeID; // ecx
  struct GFxFillStyle *v53; // edx
  GFxMeshSet *v54; // eax
  float *v55; // eax
  int m_nSlices; // ecx
  int (__thiscall *v57)(int, int, GFxMeshSet **, const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *, int); // edx
  GFxMeshSet *v58; // eax
  double v59; // st7
  bool v60; // dl
  GFxMeshSet *v61; // esi
  GRefCountNTSImpl *v62; // edi
  double v63; // st7
  float v64; // [esp+10h] [ebp-280h]
  float v65; // [esp+14h] [ebp-27Ch]
  float v66; // [esp+14h] [ebp-27Ch]
  float v67; // [esp+14h] [ebp-27Ch]
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v68; // [esp+18h] [ebp-278h]
  int v69; // [esp+1Ch] [ebp-274h]
  const CSOAContainer *v70; // [esp+20h] [ebp-270h]
  GFxSwfPathData::PathsIterator v71; // [esp+24h] [ebp-26Ch] BYREF
  int v72; // [esp+28h] [ebp-268h]
  char v73; // [esp+44h] [ebp-24Ch]
  GFxSwfPathData::PathsIterator v74[8]; // [esp+98h] [ebp-1F8h] BYREF
  char v75; // [esp+B8h] [ebp-1D8h]
  CSOAAttributeReference v76; // [esp+10Ch] [ebp-184h] BYREF
  float v77; // [esp+114h] [ebp-17Ch]
  float v78; // [esp+118h] [ebp-178h]
  CSOAAttributeReference v79; // [esp+11Ch] [ebp-174h] BYREF
  int v80; // [esp+124h] [ebp-16Ch] BYREF
  int py; // [esp+128h] [ebp-168h] BYREF
  GFxSwfPathData::PathsIterator v82; // [esp+12Ch] [ebp-164h]
  struct GFxShapeBase *v83; // [esp+130h] [ebp-160h]
  int v84; // [esp+134h] [ebp-15Ch] BYREF
  int px; // [esp+138h] [ebp-158h] BYREF
  int v86; // [esp+13Ch] [ebp-154h]
  CSOAAttributeReferenceBinaryOp<&SubSIMD> v87; // [esp+140h] [ebp-150h] BYREF
  CSOAAttributeReferenceBinaryOp<&SubSIMD> v88; // [esp+150h] [ebp-140h] BYREF
  struct GFxDisplayContext *v89; // [esp+160h] [ebp-130h]
  unsigned int v90; // [esp+164h] [ebp-12Ch]
  int v91; // [esp+168h] [ebp-128h]
  struct GFxFillStyle *v92; // [esp+16Ch] [ebp-124h]
  GRefCountNTSImpl *v93; // [esp+170h] [ebp-120h]
  unsigned int v94; // [esp+174h] [ebp-11Ch]
  char v95; // [esp+179h] [ebp-117h]
  __int16 v96; // [esp+17Ah] [ebp-116h]
  int v97; // [esp+17Ch] [ebp-114h]
  float v98; // [esp+180h] [ebp-110h]
  GFxMeshSet *v99; // [esp+184h] [ebp-10Ch] BYREF
  GRenderer::Cxform v100; // [esp+188h] [ebp-108h] BYREF
  struct GFxDisplayContext *v101; // [esp+1A8h] [ebp-E8h] BYREF
  int v102; // [esp+1ACh] [ebp-E4h]
  int v103; // [esp+1B0h] [ebp-E0h]
  float v104; // [esp+1B4h] [ebp-DCh]
  float v105; // [esp+1B8h] [ebp-D8h]
  float v106; // [esp+1BCh] [ebp-D4h]
  float v107; // [esp+1C0h] [ebp-D0h]
  float v108; // [esp+1C4h] [ebp-CCh]
  float v109; // [esp+1C8h] [ebp-C8h]
  GRenderer::Cxform v110; // [esp+1CCh] [ebp-C4h]
  int v111; // [esp+1ECh] [ebp-A4h]
  int v112; // [esp+1F0h] [ebp-A0h]
  int v113; // [esp+1F4h] [ebp-9Ch]
  GMatrix2D v114; // [esp+1F8h] [ebp-98h] BYREF
  float v115; // [esp+210h] [ebp-80h] BYREF
  float v116; // [esp+214h] [ebp-7Ch]
  float v117; // [esp+218h] [ebp-78h]
  float v118; // [esp+21Ch] [ebp-74h]
  int v119; // [esp+220h] [ebp-70h]
  float v120; // [esp+224h] [ebp-6Ch] BYREF
  float v121; // [esp+228h] [ebp-68h]
  float v122; // [esp+22Ch] [ebp-64h]
  float v123; // [esp+230h] [ebp-60h]
  int v124; // [esp+234h] [ebp-5Ch]
  __int64 v125; // [esp+238h] [ebp-58h] BYREF
  float v126; // [esp+240h] [ebp-50h]
  float v127; // [esp+244h] [ebp-4Ch]
  float v128; // [esp+248h] [ebp-48h]
  float v129; // [esp+24Ch] [ebp-44h]
  float v130; // [esp+250h] [ebp-40h]
  float v131; // [esp+254h] [ebp-3Ch]
  float v132; // [esp+258h] [ebp-38h]
  float v133; // [esp+25Ch] [ebp-34h]
  float v134; // [esp+260h] [ebp-30h]
  float v135; // [esp+264h] [ebp-2Ch]
  float v136; // [esp+268h] [ebp-28h]
  float v137; // [esp+26Ch] [ebp-24h]
  float v138; // [esp+270h] [ebp-20h]
  float v139; // [esp+274h] [ebp-1Ch]
  float v140; // [esp+278h] [ebp-18h]
  float v141; // [esp+27Ch] [ebp-14h]
  float v142; // [esp+280h] [ebp-10h]
  float v143; // [esp+284h] [ebp-Ch]
  float v144; // [esp+288h] [ebp-8h]

  v98 = *((float *)a5 + 7);
  v69 = a3;
  v87.m_opB.m_nAttributeID = (int)a5;
  v68 = a2;
  v6 = a4;
  v7 = *((_DWORD *)a4 + 18);
  v87.m_opB.m_pContainer = *(CSOAContainer **)(*((_DWORD *)a4 + 26) + 20);
  v8 = *((float **)this + 35);
  v91 = v7;
  v9 = *((float **)this + 36);
  v10 = v9[1];
  v89 = a4;
  v11 = (v10 - v8[1]) * v98 + v8[1];
  v12 = v98;
  v77 = v11;
  v78 = (v9[2] - v8[2]) * v98 + v8[2];
  *(float *)&v79.m_pContainer = (v9[3] - v8[3]) * v98 + v8[3];
  v13 = (v9[4] - v8[4]) * v98 + v8[4];
  v83 = (GFxMorphCharacterDef *)((char *)this + 16);
  *(float *)&v79.m_nAttributeID = v13;
  *((float *)this + 5) = v77;
  *((float *)this + 6) = v78;
  *(CSOAAttributeReference *)((char *)this + 28) = v79;
  *((_BYTE *)this + 52) |= 0x10u;
  if ( *((_DWORD *)this + 25) != 0 )
  {
    v14 = 0;
    v97 = *((int *)this + 25);
    do
    {
      v65 = v12;
      GFxFillStyle::SetLerp(
        this: (GFxFillStyle *)(v14 + *((_DWORD *)this + 24)),
        a2: (const struct GFxFillStyle *)(v14 + *((_DWORD *)this + 37)),
        a3: (const struct GFxFillStyle *)(v14 + *((_DWORD *)this + 40)),
        a4: v65);
      v12 = v98;
      v14 += 40;
      --v97;
    }
    while ( *(float *)&v97 != 0.0 );
  }
  v15 = *((_DWORD *)this + 28);
  if ( v15 != 0 )
  {
    v16 = 0;
    v94 = 0;
    v97 = v15;
    while ( 1 )
    {
      v17 = *((_DWORD *)this + 43);
      v18 = *(_WORD *)(v17 + v16 + 16);
      v19 = *((_DWORD *)this + 46);
      v20 = v16 + v17;
      v21 = v16 + *((_DWORD *)this + 27);
      *(_WORD *)(v21 + 16) = v18;
      v22 = v16 + v19;
      v23 = *(unsigned __int16 *)(v22 + 4);
      v99 = (GFxMeshSet *)*(unsigned __int16 *)(v20 + 4);
      *(float *)&v92 = (float)(int)v99;
      v88.m_opB.m_nAttributeID = v22;
      *(float *)&v99 = ((double)v23 - *(float *)&v92) * v12 + *(float *)&v92;
      v99 = (GFxMeshSet *)(int)(*(float *)&v99 + 0.5);
      *(_WORD *)(v21 + 4) = (_WORD)v99;
      v66 = v12;
      *(_DWORD *)(v21 + 8) = GColor::Blend(
                               result: (const CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t *)&v88.m_opB,
                               a2: *(_DWORD *)(v20 + 8),
                               a3: *(_DWORD *)(v22 + 8),
                               f: v66)->m_pBlockHeader;
      v24 = *(const struct GFxFillStyle **)(v20 + 12);
      if ( v24 != nullptr )
      {
        v25 = *(GFxFillStyle **)(v21 + 12);
        v26 = *(struct GFxFillStyle **)(v88.m_opB.m_nAttributeID + 12);
        v92 = v26;
        if ( v25 != nullptr )
        {
          GFxFillStyle::SetLerp(this: v25, a2: v24, a3: v26, a4: v98);
        }
        else
        {
          v99 = (GFxMeshSet *)258;
          v27 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v99);
          if ( v27 != nullptr )
          {
            LOBYTE(v28) = GFxFillStyle::GFxFillStyle(this: v27, a2: v68);
            v93 = v28;
          }
          else
          {
            v93 = nullptr;
          }
          GFxFillStyle::SetLerp(this: (GFxFillStyle *)v93, a2: v24, a3: v92, a4: v98);
          *(_DWORD *)(v21 + 12) = v93;
        }
      }
      v94 += 24;
      --v97;
      if ( *(float *)&v97 == 0.0 )
        break;
      v12 = v98;
      v16 = v94;
    }
    v6 = v89;
  }
  v29 = *((float **)v6 + 1);
  v114.M_[0][0] = *v29;
  v114.M_[0][1] = v29[1];
  v114.M_[0][2] = v29[2];
  v114.M_[1][0] = v29[3];
  v114.M_[1][1] = v29[4];
  v114.M_[1][2] = v29[5];
  GMatrix2D::Prepend(this: &v114, a2: (const struct GMatrix2D *)(v87.m_opB.m_nAttributeID + 68));
  v100 = *(GRenderer::Cxform *)*(_DWORD *)v6;
  GRenderer::Cxform::Concatenate(this: &v100, a2: (const struct GRenderer::Cxform *)(v87.m_opB.m_nAttributeID + 36));
  v30 = v89;
  v99 = *((GFxMeshSet **)v89 + 29);
  MaxScale = GMatrix2D::GetMaxScale(this: (CMaterialDict::MaterialLookup_t *)&v114);
  v32 = nullptr;
  v33 = (*(_BYTE *)(v87.m_opB.m_nAttributeID + 118) & 1) == 0;
  v93 = nullptr;
  *(float *)&v97 = MaxScale * *(float *)&v99;
  v34 = *(float *)&v97;
  *(float *)&v88.m_opB.m_pContainer = 20.0 / *(float *)&v97;
  if ( !v33 )
  {
    v99 = *((GFxMeshSet **)v30 + 29);
    GFxCharacter::CreateScale9Grid(
      a1: v87.m_opB.m_nAttributeID,
      a2: (const CMaterialDict::MissingMaterial_t *)v30,
      result: (const CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)v99);
    v34 = *(float *)&v97;
    v93 = v35;
    v32 = (float *)v35;
  }
  if ( (*(_BYTE *)(v91 + 20) & 0x10) == 0
    || ((v36 = *(_DWORD *)(v91 + 28)) & 0x100) == 0
    || (v36 & 0x200) == 0 && (*((_BYTE *)this + 52) & 1) != 0
    || *(_WORD *)(v87.m_opB.m_nAttributeID + 116) != 0
    || (v33 = *((_DWORD *)v89 + 37) == 0, v95 = 1, !v33) )
  {
    v95 = 0;
  }
  *(float *)&v99 = fabs(v100.M_[3][1]);
  HIBYTE(v96) = *(float *)&v99 >= 1.0;
  v37 = v95 != 0;
  if ( v32 != nullptr )
  {
    LODWORD(v125) = v37;
    *((float *)&v125 + 1) = v98;
    v91 = 84;
    v40 = v32[2];
    v97 = 1;
    v126 = v40;
    v127 = v32[3];
    v128 = v32[4];
    v129 = v32[5];
    v130 = v32[6];
    v131 = v32[7];
    v132 = v32[9];
    v133 = v32[10];
    v134 = v32[12];
    v135 = v32[13];
    v136 = v32[14];
    v137 = v32[15];
    v138 = v32[16];
    v139 = v32[17];
    v140 = v32[18];
    v141 = v32[19];
    v142 = v32[20];
    v143 = v32[21];
    v144 = v32[22];
  }
  else
  {
    if ( v95 != 0 )
    {
      *(float *)&v99 = v34 * 0.8410000205039978;
      *(float *)&v99 = *(float *)&v99 * *(float *)&v99;
      LOWORD(v38) = (unsigned __int8)((unsigned int)v99 >> 23) - 64;
    }
    else
    {
      *(float *)&v99 = v34;
      v38 = ((unsigned int)(unsigned __int8)((unsigned int)v99 >> 23) - 64) >> 1;
    }
    v39 = *(float *)(v91 + 16);
    v91 = 6;
    *(float *)&v99 = v39;
    LOWORD(v125) = v37
                 | (2
                  * (v38
                   | ((unsigned __int16)(((unsigned int)(unsigned __int8)((unsigned int)v99 >> 23) - 64) >> 1) << 8)));
    *(float *)((char *)&v125 + 2) = v98;
    v97 = 2;
  }
  *(float *)&v99 = COERCE_FLOAT(
                     GFxMeshCache::GetMeshSet(
                       a1: v87.m_opB.m_pContainer,
                       a2: v83,
                       a3: v87.m_opB.m_nAttributeID,
                       a4: v97,
                       a5: &v125,
                       a6: v91));
  GFxCharacter::GetActiveBlendMode(this: (CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *)v87.m_opB.m_nAttributeID);
  v42 = *((_DWORD *)this + 25);
  v101 = v89;
  if ( v42 != 0 )
    v102 = *((_DWORD *)this + 24);
  else
    v102 = 0;
  if ( *((_DWORD *)this + 28) != 0 )
    v103 = *((_DWORD *)this + 27);
  else
    v103 = 0;
  v104 = v114.M_[0][0];
  v105 = v114.M_[0][1];
  v106 = v114.M_[0][2];
  v107 = v114.M_[1][0];
  v108 = v114.M_[1][1];
  v109 = v114.M_[1][2];
  v110 = v100;
  v111 = v41;
  v43 = *((_DWORD *)this + 28);
  v44 = 0;
  v112 = v42;
  v113 = v43;
  if ( *(float *)&v99 != 0.0 )
  {
    v45 = v93;
    GFxMeshSet::Display(this: v99, a2: (struct GFxDisplayParams *)&v101, a3: v93 != nullptr);
    if ( v45 == nullptr )
      return;
    v46 = v45;
    goto LABEL_69;
  }
  v47 = *((CFltX4AttributeIterator **)this + 35);
  *(float *)&px = 0.0;
  *(float *)&py = 0.0;
  *(float *)&v80 = 0.0;
  v90 = 0;
  *(float *)&v84 = 0.0;
  v94 = 0;
  v82 = nullptr;
  v88.m_opB.m_nAttributeID = 0;
  *(float *)&v92 = 0.0;
  GFxSwfPathData::PathsIterator::PathsIterator(this: v74, a2: v47);
  GFxSwfPathData::PathsIterator::PathsIterator(this: &v71, a2: *((CFltX4AttributeIterator **)this + 36));
  v48 = v98;
  v87.m_opA.m_pContainer = nullptr;
  v87.m_opA.m_nAttributeID = 0;
  v88.m_opA.m_pContainer = nullptr;
  v88.m_opA.m_nAttributeID = 0;
  v86 = 0;
  while ( v75 != 1 || v73 != 1 )
  {
    if ( v90 == 0 )
    {
      GFxSwfPathData::EdgesIterator::EdgesIterator(this: (IKMeansErrorMetric **)&v76, a2: (IKMeansErrorMetric *)v74);
      v87.m_opA = v76;
      GFxSwfPathData::EdgesIterator::GetEdgesCount(this: &v87);
      v90 = v49;
      GFxSwfPathData::EdgesIterator::GetMoveXY(
        this: (CSOAContainer *)&v87,
        (float *)&px,
        (float *)&py,
        a4: (int)v68,
        a5: v69,
        a6: v70,
        a7: (int)v71,
        a8: v72);
      v48 = v98;
      v82 = v74[5];
      v88.m_opB.m_nAttributeID = (int)v74[6];
      v92 = (struct GFxFillStyle *)v74[7];
    }
    if ( v94 == 0 )
    {
      GFxSwfPathData::EdgesIterator::EdgesIterator(this: (IKMeansErrorMetric **)&v79, a2: (IKMeansErrorMetric *)&v71);
      v88.m_opA = v79;
      GFxSwfPathData::EdgesIterator::GetEdgesCount(this: &v88);
      v94 = v50;
      GFxSwfPathData::EdgesIterator::GetMoveXY(
        this: (CSOAContainer *)&v88,
        px: (float *)&v80,
        py: (float *)&v84,
        a4: (int)v68,
        a5: v69,
        a6: v70,
        a7: (int)v71,
        a8: v72);
      v48 = v98;
    }
    v51 = v86 + *((_DWORD *)this + 49);
    m_nAttributeID = v88.m_opB.m_nAttributeID;
    v53 = v92;
    *(_DWORD *)v51 = v82;
    *(_DWORD *)(v51 + 4) = m_nAttributeID;
    *(_DWORD *)(v51 + 8) = v53;
    v54 = *(GFxMeshSet **)(v51 + 24);
    *(float *)(v51 + 12) = (*(float *)&v80 - *(float *)&px) * v48 + *(float *)&px;
    *(float *)(v51 + 16) = (*(float *)&v84 - *(float *)&py) * v48 + *(float *)&py;
    if ( v54 != nullptr )
    {
      v99 = v54;
      while ( 1 )
      {
        if ( SLOBYTE(v87.m_opA.m_pContainer->m_pAttributePtrs[2]) >= 0 )
        {
          if ( SLOBYTE(v88.m_opA.m_pContainer->m_pAttributePtrs[2]) >= 0 )
          {
            LOBYTE(v124) = 0;
            v123 = 0.0;
            v122 = 0.0;
            v121 = 0.0;
            v120 = 0.0;
            goto LABEL_56;
          }
          GFxSwfPathData::EdgesIterator::GetEdge(
            this: &v88,
            a2: (struct GFxSwfPathData::EdgesIterator::Edge *)&v115,
            a3: true);
          v48 = v98;
          v120 = v115;
          v121 = v116;
          v122 = v117;
          v123 = v118;
          v124 = v119;
        }
        else
        {
          GFxSwfPathData::EdgesIterator::GetEdge(
            this: &v87,
            a2: (struct GFxSwfPathData::EdgesIterator::Edge *)&v120,
            a3: true);
          if ( SLOBYTE(v88.m_opA.m_pContainer->m_pAttributePtrs[2]) >= 0 )
          {
            v48 = v98;
LABEL_56:
            v116 = v121;
            v115 = v120;
            v119 = v124;
            v118 = v123;
            v117 = v122;
            goto LABEL_57;
          }
          GFxSwfPathData::EdgesIterator::GetEdge(
            this: &v88,
            a2: (struct GFxSwfPathData::EdgesIterator::Edge *)&v115,
            a3: true);
          v48 = v98;
        }
LABEL_57:
        v55 = (float *)(v44 + *(_DWORD *)(v51 + 20));
        v44 += 16;
        v33 = v99 == (GFxMeshSet *)1;
        v99 = (GFxMeshSet *)((char *)v99 - 1);
        *v55 = (v115 - v120) * v48 + v120;
        v55[1] = (v116 - v121) * v48 + v121;
        v55[2] = (v117 - v122) * v48 + v122;
        v55[3] = (v118 - v123) * v48 + v123;
        if ( v33 )
        {
          v44 = 0;
          break;
        }
      }
    }
    v86 += 36;
    if ( v90 == v94 )
    {
      v90 = 0;
      v94 = 0;
    }
    else if ( v90 >= v94 )
    {
      v90 -= v94;
      v94 = 0;
    }
    else
    {
      v94 -= v90;
      v90 = 0;
    }
  }
  m_nSlices = v87.m_opB.m_pContainer->m_nSlices;
  v57 = *(int (__thiscall **)(int, int, GFxMeshSet **, const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *, int))(*(_DWORD *)m_nSlices + 40);
  v99 = (GFxMeshSet *)131;
  v58 = (GFxMeshSet *)v57(a1: m_nSlices, a2: 116, a3: &v99, a4: v68, a5: v69);
  if ( v58 != nullptr )
  {
    v59 = *(float *)&v88.m_opB.m_pContainer;
    v60 = *(_WORD *)(v87.m_opB.m_nAttributeID + 116) != 0;
    *(float *)&v88.m_opB.m_pContainer = 0.75 * *(float *)&v88.m_opB.m_pContainer;
    v64 = v59;
    v61 = GFxMeshSet::GFxMeshSet(this: v58, a2: v64, a3: *(float *)&v88.m_opB.m_pContainer, a4: v60, a5: true);
  }
  else
  {
    v61 = nullptr;
  }
  v62 = v93;
  v63 = *((float *)v61 + 2);
  *((_BYTE *)v61 + 23) = HIBYTE(v96);
  v67 = v63;
  (*(void (__thiscall **)(GFxMorphCharacterDef *, GFxMeshSet *, _DWORD))(*(_DWORD *)this + 88))(
    a1: this,
    a2: v61,
    a3: LODWORD(v67));
  GFxMeshSet::SetMeshKey(a1: v61, a2: v97, a3: &v125, a4: v91, a5: v87.m_opB.m_nAttributeID);
  GFxMeshSet::Display(this: v61, a2: (struct GFxDisplayParams *)&v101, a3: v62 != nullptr);
  GFxMeshCache::AddMeshSet(this: (GFxMeshCache *)v87.m_opB.m_pContainer, a2: v83, a3: v61);
  if ( v62 != nullptr )
  {
    v46 = v62;
LABEL_69:
    GRefCountNTSImpl::Release(this: v46);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158D70
// Name: public: virtual void GFxMorphCharacterDef::ComputeBound(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMorphCharacterDef::ComputeBound(_DWORD *this, float *a2)
{
  double v3; // st7
  int v4; // ebx
  double v5; // st4
  double v6; // st5
  double v7; // st3
  double v8; // st4
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  double v12; // st3
  float *v13; // edx
  double v14; // st3
  double v15; // st3
  double v16; // st3
  double v17; // st2
  double v18; // st7
  double v19; // st3
  double v20; // st4
  double v21; // st2
  double v22; // st3
  double v23; // rt1
  double v24; // st3
  double v25; // st4
  double v26; // st3
  double v27; // st3
  double v28; // st3
  double v29; // st2
  double v30; // st4
  double v31; // st4
  double v32; // st5
  double v33; // st3
  double v34; // st4
  double v35; // rt1
  double v36; // st4
  double v37; // st5
  double v38; // st4
  double v39; // st5
  double v40; // st3
  double v41; // st4
  double v42; // rt0
  double v43; // st4
  double v44; // st5
  _DWORD *v45; // [esp+4h] [ebp-14h]
  float v46; // [esp+8h] [ebp-10h]
  float v47; // [esp+8h] [ebp-10h]
  float v48; // [esp+8h] [ebp-10h]
  float v49; // [esp+8h] [ebp-10h]
  float v50; // [esp+8h] [ebp-10h]
  float v51; // [esp+8h] [ebp-10h]
  float v52; // [esp+8h] [ebp-10h]
  int v53; // [esp+Ch] [ebp-Ch]
  int v54; // [esp+10h] [ebp-8h]
  float v55; // [esp+14h] [ebp-4h]
  float v56; // [esp+14h] [ebp-4h]
  float v57; // [esp+14h] [ebp-4h]
  float v58; // [esp+14h] [ebp-4h]
  float v59; // [esp+14h] [ebp-4h]
  float v60; // [esp+14h] [ebp-4h]
  float v61; // [esp+20h] [ebp+8h]
  float v62; // [esp+20h] [ebp+8h]
  float v63; // [esp+20h] [ebp+8h]
  float v64; // [esp+20h] [ebp+8h]
  float v65; // [esp+20h] [ebp+8h]
  float v66; // [esp+20h] [ebp+8h]
  float v67; // [esp+20h] [ebp+8h]
  float v68; // [esp+20h] [ebp+8h]
  float v69; // [esp+20h] [ebp+8h]
  float v70; // [esp+20h] [ebp+8h]
  float v71; // [esp+20h] [ebp+8h]
  float v72; // [esp+20h] [ebp+8h]
  float v73; // [esp+20h] [ebp+8h]
  float v74; // [esp+20h] [ebp+8h]
  float v75; // [esp+20h] [ebp+8h]
  float v76; // [esp+20h] [ebp+8h]
  float v77; // [esp+20h] [ebp+8h]
  float v78; // [esp+20h] [ebp+8h]
  float v79; // [esp+20h] [ebp+8h]
  float v80; // [esp+20h] [ebp+8h]
  float v81; // [esp+20h] [ebp+8h]
  float v82; // [esp+20h] [ebp+8h]
  float v83; // [esp+20h] [ebp+8h]
  float v84; // [esp+20h] [ebp+8h]
  float v85; // [esp+20h] [ebp+8h]
  float v86; // [esp+20h] [ebp+8h]
  float v87; // [esp+20h] [ebp+8h]
  float v88; // [esp+20h] [ebp+8h]
  float v89; // [esp+20h] [ebp+8h]
  float v90; // [esp+20h] [ebp+8h]
  float v91; // [esp+20h] [ebp+8h]
  float v92; // [esp+20h] [ebp+8h]
  float v93; // [esp+20h] [ebp+8h]
  float v94; // [esp+20h] [ebp+8h]
  float v95; // [esp+20h] [ebp+8h]
  float v96; // [esp+20h] [ebp+8h]
  float v97; // [esp+20h] [ebp+8h]
  float v98; // [esp+20h] [ebp+8h]
  float v99; // [esp+20h] [ebp+8h]
  float v100; // [esp+20h] [ebp+8h]

  *a2 = 1.0e10;
  v45 = this;
  a2[1] = 1.0e10;
  a2[2] = -1.0e10;
  a2[3] = -1.0e10;
  if ( *(this + 50) != 0 )
  {
    v3 = 2.0;
    v54 = 0;
    v53 = *(this + 50);
    do
    {
      v4 = v54 + *(this + 49);
      v61 = *(float *)(v4 + 12);
      v55 = *(float *)(v4 + 16);
      v46 = *a2;
      v5 = v61;
      if ( v61 <= (double)v46 )
      {
        v6 = v61;
      }
      else
      {
        v5 = v46;
        v6 = v61;
      }
      v62 = v5;
      *a2 = v62;
      v63 = a2[1];
      v7 = v55;
      if ( v55 <= (double)v63 )
      {
        v8 = v55;
      }
      else
      {
        v7 = v63;
        v8 = v55;
      }
      v64 = v7;
      a2[1] = v64;
      v65 = a2[2];
      if ( v65 <= v6 )
        v65 = v6;
      a2[2] = v65;
      v66 = a2[3];
      if ( v66 <= v8 )
        v66 = v8;
      a2[3] = v66;
      if ( *(_DWORD *)(v4 + 24) != 0 )
      {
        v9 = 0;
        v10 = *(_DWORD *)(v4 + 24);
        while ( 1 )
        {
          v11 = *(_DWORD *)(v4 + 20);
          v12 = *(float *)(v11 + v9);
          v13 = (float *)(v9 + v11);
          v67 = v12;
          v14 = v67;
          v68 = v67 * v3 - v6 - v13[2];
          if ( 0.0 == v68 )
            v15 = -1.0;
          else
            v15 = (v14 - v6) / v68;
          v69 = v15;
          v16 = v69;
          if ( v69 > 0.0 && v16 < 1.0 )
          {
            v70 = *v13;
            v56 = (v70 - v6) * v16 + v6;
            v17 = v13[1];
            v47 = (v17 - v8) * v16 + v8;
            v71 = v70 + (v13[2] - v70) * v16;
            v57 = (v71 - v56) * v16 + v56;
            v72 = v17 + (v13[3] - v17) * v16;
            v18 = v8;
            v48 = v16 * (v72 - v47) + v47;
            v73 = *a2;
            v19 = v57;
            if ( v57 <= (double)v73 )
            {
              v20 = v57;
            }
            else
            {
              v19 = v73;
              v20 = v57;
            }
            v74 = v19;
            *a2 = v74;
            v75 = a2[1];
            v21 = v48;
            if ( v48 <= (double)v75 )
            {
              v22 = v48;
            }
            else
            {
              v21 = v75;
              v22 = v48;
            }
            v76 = v21;
            a2[1] = v76;
            v77 = a2[2];
            if ( v77 > v20 )
              v20 = v77;
            v23 = v22;
            v24 = v20;
            v25 = v23;
            v78 = v24;
            a2[2] = v78;
            v79 = a2[3];
            if ( v79 > v23 )
              v25 = v79;
            v80 = v25;
            a2[3] = v80;
            v8 = v18;
            v3 = 2.0;
          }
          v26 = v13[1];
          v81 = v26 * v3 - v8 - v13[3];
          if ( 0.0 == v81 )
            v27 = -1.0;
          else
            v27 = (v26 - v8) / v81;
          v82 = v27;
          v28 = v82;
          if ( v82 > 0.0 && v28 < 1.0 )
          {
            v83 = *v13;
            v49 = v13[1];
            v58 = v6 + (v83 - v6) * v28;
            v29 = v8 + (v49 - v8) * v28;
            v30 = v49;
            v50 = v29;
            v84 = v83 + (v13[2] - v83) * v28;
            v59 = (v84 - v58) * v28 + v58;
            v85 = v30 + (v13[3] - v30) * v28;
            v51 = v28 * (v85 - v50) + v50;
            v86 = *a2;
            v31 = v59;
            if ( v59 <= (double)v86 )
            {
              v32 = v59;
            }
            else
            {
              v31 = v86;
              v32 = v59;
            }
            v87 = v31;
            *a2 = v87;
            v88 = a2[1];
            v33 = v51;
            if ( v51 <= (double)v88 )
            {
              v34 = v51;
            }
            else
            {
              v33 = v88;
              v34 = v51;
            }
            v89 = v33;
            a2[1] = v89;
            v90 = a2[2];
            if ( v90 > v32 )
              v32 = v90;
            v35 = v34;
            v36 = v32;
            v37 = v35;
            v91 = v36;
            a2[2] = v91;
            v92 = a2[3];
            if ( v92 <= v35 )
              v92 = v37;
            a2[3] = v92;
          }
          v52 = v13[2];
          v60 = v13[3];
          v93 = *a2;
          v38 = v52;
          if ( v52 <= (double)v93 )
          {
            v39 = v52;
          }
          else
          {
            v38 = v93;
            v39 = v52;
          }
          v94 = v38;
          *a2 = v94;
          v95 = a2[1];
          v40 = v60;
          if ( v60 <= (double)v95 )
          {
            v41 = v60;
          }
          else
          {
            v40 = v95;
            v41 = v60;
          }
          v96 = v40;
          a2[1] = v96;
          v97 = a2[2];
          if ( v97 > v39 )
            v39 = v97;
          v42 = v41;
          v43 = v39;
          v44 = v42;
          v98 = v43;
          a2[2] = v98;
          v99 = a2[3];
          if ( v99 > v42 )
            v44 = v99;
          v100 = v44;
          v9 += 16;
          --v10;
          a2[3] = v100;
          if ( v10 == 0 )
            break;
          v6 = v13[2];
          v8 = v13[3];
        }
        this = v45;
      }
      v54 += 36;
      --v53;
    }
    while ( v53 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159220
// Name: private: void GFxMorphCharacterDef::ReadMorphFillStyle(class GFxLoadProcess __near *,enum GFxTagType,class GFxFillStyle __near &,class GFxFillStyle __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFxMorphCharacterDef::ReadMorphFillStyle(unsigned int p, int a2, unsigned __int8 *a3, struct GColor a4)
{
  unsigned int v4; // esi
  int v5; // eax
  int v6; // eax
  unsigned __int8 v7; // cl
  unsigned __int8 *v8; // edi
  unsigned __int8 *Raw; // ebx
  char v10; // al
  unsigned int v11; // eax
  int v12; // edx
  int v13; // eax
  char v14; // cl
  bool v15; // zf
  void *v16; // eax
  int v17; // eax
  void *v18; // eax
  int v19; // eax
  unsigned __int8 *v20; // eax
  unsigned int v21; // ebx
  int v22; // eax
  int v23; // eax
  double v24; // st7
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  double v28; // st7
  int v29; // ecx
  int v30; // edx
  int v31; // eax
  unsigned int v32; // ebx
  unsigned int v33; // ebx
  _cpinfo *v34; // [esp+0h] [ebp-14h]
  int v35; // [esp+Ch] [ebp-8h] BYREF
  int v36; // [esp+10h] [ebp-4h]

  if ( *(_DWORD *)(p + 804) != 0 )
    v4 = *(_DWORD *)(p + 804);
  else
    v4 = p + 40;
  v5 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
  *(_BYTE *)(v4 + 21) = 0;
  if ( v5 < 1 )
    GFxStream::PopulateBuffer1(result: v34);
  v6 = *(_DWORD *)(v4 + 44);
  v7 = *(_BYTE *)(v6 + *(_DWORD *)(v4 + 60));
  v8 = a3;
  Raw = (unsigned __int8 *)a4.Raw;
  *(_DWORD *)(v4 + 44) = v6 + 1;
  *v8 = v7;
  *Raw = v7;
  GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"morph fill style type = 0x%X\n", *v8);
  v10 = *v8;
  if ( *v8 != 0 )
  {
    if ( (v10 & 0x10) != 0 )
    {
      GFxStream::ReadMatrix(this: (GFxStream *)v4, a2: (struct GMatrix2D *)(v8 + 16));
      GFxStream::ReadMatrix(this: (GFxStream *)v4, a2: (struct GMatrix2D *)(Raw + 16));
      v12 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
      *(_BYTE *)(v4 + 21) = 0;
      if ( v12 < 1 )
        GFxStream::PopulateBuffer1(result: v34);
      v13 = *(_DWORD *)(v4 + 44);
      v14 = *(_BYTE *)(v13 + *(_DWORD *)(v4 + 60));
      v15 = a2 == 84;
      HIBYTE(a3) = v14;
      *(_DWORD *)(v4 + 44) = v13 + 1;
      LOBYTE(v36) = 0;
      if ( v15 || *v8 == 19 )
      {
        if ( (v14 & 0x10) != 0 )
          LOBYTE(v36) = 1;
        HIBYTE(a3) = v14 & 0xF;
      }
      v35 = 258;
      v16 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &v35);
      if ( v16 != nullptr )
        v17 = GFxGradientData::GFxGradientData(a1: v16, a2: *v8, a3: HIBYTE(a3), a4: v36);
      else
        v17 = 0;
      *((_DWORD *)v8 + 1) = v17;
      v35 = 258;
      v18 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &v35);
      if ( v18 != nullptr )
        v19 = GFxGradientData::GFxGradientData(a1: v18, a2: *Raw, a3: HIBYTE(a3), a4: v36);
      else
        v19 = 0;
      *((_DWORD *)Raw + 1) = v19;
      if ( *((_DWORD *)v8 + 1) != 0 && v19 != 0 )
      {
        v20 = (unsigned __int8 *)HIBYTE(a3);
        v21 = 0;
        a3 = v20;
        if ( v20 != nullptr )
        {
          do
          {
            GFxGradientRecord::Read(
              this: (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CFuncMemPolicyNone> *)(8 * v21 + *(_DWORD *)(*((_DWORD *)v8 + 1) + 12)),
              p);
            GFxGradientRecord::Read(
              this: (CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CFuncMemPolicyNone> *)(8 * v21++ + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&a4 + 4) + 12)),
              p);
          }
          while ( v21 < (unsigned int)a3 );
          v20 = a3;
        }
        GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"morph fsr: numGradients = %d\n", v20);
        if ( *v8 == 19 )
        {
          v22 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
          *(_BYTE *)(v4 + 21) = 0;
          if ( v22 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v23 = *(_DWORD *)(v4 + 44);
          p = *(__int16 *)(*(_DWORD *)(v4 + 60) + v23);
          v24 = (double)(int)p;
          *(_DWORD *)(v4 + 44) = v23 + 2;
          v25 = *((_DWORD *)v8 + 1);
          *(float *)&p = v24 * 0.00390625;
          *(float *)(v25 + 16) = *(float *)&p;
          v26 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
          *(_BYTE *)(v4 + 21) = 0;
          if ( v26 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v27 = *(_DWORD *)(v4 + 44);
          p = *(__int16 *)(*(_DWORD *)(v4 + 60) + v27);
          v28 = (double)(int)p;
          *(_DWORD *)(v4 + 44) = v27 + 2;
          v29 = *(_DWORD *)(*(_DWORD *)&a4 + 4);
          *(float *)&p = v28 * 0.00390625;
          *(float *)(v29 + 16) = *(float *)&p;
        }
      }
      else
      {
        *v8 = 0;
        *Raw = 0;
      }
    }
    else if ( (v10 & 0x40) != 0 )
    {
      v30 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
      *(_BYTE *)(v4 + 21) = 0;
      if ( v30 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v31 = *(_DWORD *)(v4 + 44);
      v32 = *(unsigned __int16 *)(*(_DWORD *)(v4 + 60) + v31);
      *(_DWORD *)(v4 + 44) = v31 + 2;
      GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"morph fsr BitmapChar = %d\n", v32);
      GFxMovieDataDef::LoadTaskData::GetResourceHandle(
        this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(p + 32),
        phandle: (_DWORD *)v8 + 2,
        rid: v32);
      v33 = a4.Raw;
      GFxResourcePtr<GFxImageResource>::operator=(
        this: (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)(*(_DWORD *)&a4 + 8),
        other: (int)(v8 + 8),
        a3: (const CMorph::MorphSegment_t *)v34);
      GFxStream::ReadMatrix(this: (GFxStream *)v4, a2: (struct GMatrix2D *)(v8 + 16));
      GFxStream::ReadMatrix(this: (GFxStream *)v4, a2: (struct GMatrix2D *)(v33 + 16));
    }
  }
  else
  {
    GFxStream::ReadRgba(this: (GFxStream *)v4, a2: (struct GColor *)&p);
    GFxStream::ReadRgba(this: (GFxStream *)v4, a2: &a4);
    v11 = a4.Raw;
    *((float *)v8 + 1) = *(float *)&p;
    *((_DWORD *)Raw + 1) = v11;
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"morph fill style begin color: ");
    GFxStream::LogParseClass(this: (GFxStream *)v4, a2: (struct GColor)p);
    GFxLogBase<GFxStream>::LogParse(this: (tagBITMAPINFOHEADER *)v4, a2: (int)"morph fill style end color: ");
    GFxStream::LogParseClass(this: (GFxStream *)v4, a2: a4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159580
// Name: public: GFxRenderGenShape::GFxRenderGenShape(void)
// Source: json
//------------------------------------------------------------------------------
GFxRenderGenShape *__thiscall GFxRenderGenShape::GFxRenderGenShape(GFxRenderGenShape *this)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxRenderGenShape::`vftable';
  *((float *)this + 2) = 1.0;
  *((float *)this + 3) = 0.0625;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((float *)this + 15) = 1.0;
  *((float *)this + 16) = 1.0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0x7FFFFFFF;
  *((float *)this + 17) = 0.0;
  *((_DWORD *)this + 14) = -2147483647;
  *((float *)this + 18) = 0.0;
  *((_BYTE *)this + 76) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10159620
// Name: public: virtual bool GFxMorphCharacterDef::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxMorphCharacterDef::DefPointTestLocal(int this, float *a2, GRefCountNTSImpl *a3, float a4)
{
  unsigned int v5; // ebx
  GRefCountNTSImpl *v6; // esi
  GRefCountNTSImpl *v7; // eax
  bool v8; // zf
  int v9; // eax
  GFxRenderGenShape *v11; // eax
  GCompoundShape *v12; // esi
  CMaterialVar *v13; // ecx
  int v14; // ecx
  char v15; // al
  GRefCountNTSImpl *v16; // edi
  char v17; // al
  char v18; // bl
  __int128 y; // [esp+10h] [ebp-40h]
  int v20[4]; // [esp+24h] [ebp-2Ch] BYREF
  float xb1; // [esp+34h] [ebp-1Ch] BYREF
  float v22; // [esp+38h] [ebp-18h]
  float v23; // [esp+3Ch] [ebp-14h]
  float v24; // [esp+40h] [ebp-10h]
  float v25; // [esp+44h] [ebp-Ch]
  float v26; // [esp+48h] [ebp-8h]
  GRefCountNTSImpl *v27; // [esp+4Ch] [ebp-4h]

  v5 = 0;
  v6 = nullptr;
  v27 = nullptr;
  if ( a4 != 0.0 && (*(_BYTE *)(LODWORD(a4) + 118) & 1) != 0 )
  {
    GFxCharacter::CreateScale9Grid(
      a1: SLODWORD(a4),
      a2: (const CMaterialDict::MissingMaterial_t *)this,
      result: COERCE_CONST_CMEMBERFUNCTOR4_CMATRENDERCONTEXTBASE_VOID_THISCALL_IMATRENDERCONTEXT_ITEXTURE_INT_RECT_T_RECT_T_ITEXTURE_INT_RECT_T_RECT_T_CREFCOUNTED1_CFUNCTOR_CREFCOUNTSERVICEDESTRUCT_CREFST_CFUNCMEMPOLICYNONE_(1.0));
    v27 = v7;
    if ( v7 != nullptr )
    {
      GFxScale9GridInfo::Compute(
        this: (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *)v7,
        gy1: DWORD2(y));
      v6 = v27;
    }
    else
    {
      v6 = nullptr;
    }
  }
  v8 = (*(_BYTE *)(this + 52) & 0x10) == 0;
  xb1 = *(float *)(this + 20);
  v22 = *(float *)(this + 24);
  v23 = *(float *)(this + 28);
  v24 = *(float *)(this + 32);
  if ( v8 )
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)(this + 16) + 20))(a1: this + 16, a2: &xb1);
  if ( v6 != nullptr )
  {
    v9 = GFxScale9GridInfo::AdjustBounds(a1: (int)v20, xb1: COERCE_FLOAT(&xb1));
    a4 = *(float *)(v9 + 4);
    v26 = *(float *)(v9 + 8);
    v25 = *(float *)(v9 + 12);
    xb1 = *(float *)v9;
    v22 = a4;
    v23 = v26;
    v24 = v25;
  }
  if ( v23 >= (double)*a2 && xb1 <= (double)*a2 && v24 >= (double)a2[1] && v22 <= (double)a2[1] )
  {
    if ( (_BYTE)a3 == 0 )
    {
      if ( v6 != nullptr )
        GRefCountNTSImpl::Release(this: v6);
      return 1;
    }
    a3 = (GRefCountNTSImpl *)2;
    v11 = (GFxRenderGenShape *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 80, &a3);
    if ( v11 != nullptr )
      a3 = (GRefCountNTSImpl *)GFxRenderGenShape::GFxRenderGenShape(this: v11);
    else
      a3 = nullptr;
    v12 = (GCompoundShape *)&a3[1];
    GCompoundShape::SetCurveTolerance(this: (long double *)&a3[1], t: COERCE_CHAR_(10.0));
    if ( *(_DWORD *)(this + 200) != 0 )
    {
      a4 = 0.0;
      do
      {
        v14 = LODWORD(a4) + *(_DWORD *)(this + 196);
        if ( *(_BYTE *)(v14 + 32) != 0 )
        {
          if ( v27 != nullptr )
          {
            *(_QWORD *)&y = __PAIR64__((unsigned int)v27, (unsigned int)v12);
            GFxShapeBase::ApplyScale9Grid(shape: (CMaterialVar *)v14, sg: y);
          }
          GCompoundShape::PointInShape(this: (wchar_t)v12, x: COERCE__IOBUF_(*a2), y: COERCE_INT_(a2[1]));
          if ( v15 != 0 )
          {
            if ( a3 != nullptr )
              GRefCountNTSImpl::Release(this: a3);
            if ( v27 != nullptr )
            {
              GRefCountNTSImpl::Release(this: v27);
              return 1;
            }
            return 1;
          }
          GCompoundShape::Clear(this: v12);
        }
        else
        {
          GFxMorphCharacterDef::Path::AddForTessellation(
            this: (GFxMorphCharacterDef::Path *)v14,
            a2: (struct GCompoundShape *)v12);
        }
        LODWORD(a4) += 36;
        ++v5;
      }
      while ( v5 < *(_DWORD *)(this + 200) );
    }
    v16 = v27;
    if ( v27 != nullptr )
    {
      *(_QWORD *)&y = __PAIR64__((unsigned int)v27, (unsigned int)v12);
      GFxShapeBase::ApplyScale9Grid(shape: v13, sg: y);
    }
    GCompoundShape::PointInShape(this: (wchar_t)v12, x: COERCE__IOBUF_(*a2), y: COERCE_INT_(a2[1]));
    v18 = v17;
    if ( a3 != nullptr )
      GRefCountNTSImpl::Release(this: a3);
    if ( v16 != nullptr )
      GRefCountNTSImpl::Release(this: v16);
    return v18;
  }
  else
  {
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101599E0
// Name: public: virtual GFxMorphCharacterDef::~GFxMorphCharacterDef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMorphCharacterDef::~GFxMorphCharacterDef(GFxMorphCharacterDef *this)
{
  GFxShapeBase *v2; // ecx
  int v3; // eax
  void (__thiscall ***v4)(_DWORD, _DWORD); // edi
  int v5; // ebx
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, _DWORD); // edi
  int v8; // ebx
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  int v13; // edi
  int v14; // ebx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v15; // [esp+0h] [ebp-Ch]

  v2 = *((GFxShapeBase **)this + 36);
  *(_DWORD *)this = &GFxMorphCharacterDef::`vftable';
  GFxShapeBase::Release(this: v2);
  GFxShapeBase::Release(this: *((GFxShapeBase **)this + 35));
  GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::~GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>(this: (_DWORD *)this + 49);
  v3 = *((_DWORD *)this + 47);
  v4 = (void (__thiscall ***)(_DWORD, _DWORD))(*((_DWORD *)this + 46) + 24 * v3 - 24);
  if ( v3 != 0 )
  {
    v5 = *((_DWORD *)this + 47);
    do
    {
      (**v4)(a1: v4, a2: 0);
      v4 -= 6;
      --v5;
    }
    while ( v5 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 46));
  v6 = *((_DWORD *)this + 44);
  v7 = (void (__thiscall ***)(_DWORD, _DWORD))(*((_DWORD *)this + 43) + 24 * v6 - 24);
  if ( v6 != 0 )
  {
    v8 = *((_DWORD *)this + 44);
    do
    {
      (**v7)(a1: v7, a2: 0);
      v7 -= 6;
      --v8;
    }
    while ( v8 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 43));
  v9 = *((_DWORD *)this + 41);
  v10 = *((_DWORD *)this + 40) + 40 * v9 - 40;
  if ( v9 != 0 )
  {
    v11 = *((_DWORD *)this + 41);
    do
    {
      GFxFillStyle::~GFxFillStyle(result: v15);
      v10 -= 40;
      --v11;
    }
    while ( v11 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 40));
  v12 = *((_DWORD *)this + 38);
  v13 = *((_DWORD *)this + 37) + 40 * v12 - 40;
  if ( v12 != 0 )
  {
    v14 = *((_DWORD *)this + 38);
    do
    {
      GFxFillStyle::~GFxFillStyle(result: v15);
      v13 -= 40;
      --v14;
    }
    while ( v14 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 37));
  GFxShapeWithStyles::~GFxShapeWithStyles(this: (IClientUnknown *)this + 4);
  *(_DWORD *)this = &GFxResource::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10159B20
// Name: public: virtual class GRect<float> GFxMorphCharacterDef::GetRectBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxMorphCharacterDef::GetRectBoundsLocal(void *this, float *a2)
{
  void (__thiscall *v2)(void *, float *); // edx

  v2 = *(void (__thiscall **)(void *, float *))(*(_DWORD *)this + 48);
  *a2 = 0.0;
  a2[1] = 0.0;
  a2[2] = 0.0;
  a2[3] = 0.0;
  v2(a1: this, a2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10159B50
// Name: public: GFxMorphCharacterDef::GFxMorphCharacterDef(void)
// Source: json
//------------------------------------------------------------------------------
GFxMorphCharacterDef *__thiscall GFxMorphCharacterDef::GFxMorphCharacterDef(GFxMorphCharacterDef *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v7; // [esp+Ch] [ebp-8h] BYREF
  int v8; // [esp+10h] [ebp-4h] BYREF

  *(_DWORD *)this = &GFxResource::`vftable';
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0x40000;
  *(_DWORD *)this = &GFxShapeCharacterDef::`vftable';
  GFxShapeWithStyles::GFxShapeWithStyles(this: (int)this + 16, result: (IClientUnknown *)0x1FF8);
  *(_DWORD *)this = &GFxMorphCharacterDef::`vftable';
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 51) = 0;
  v8 = 258;
  v2 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 44, a4: &v8);
  v3 = v2;
  if ( v2 != nullptr )
  {
    GFxShapeBase::GFxShapeBase(this: v2);
    *v3 = &GFxConstShapeNoStyles::`vftable';
    v3[10] = 0;
  }
  else
  {
    v3 = nullptr;
  }
  *((_DWORD *)this + 35) = v3;
  v7 = 258;
  v4 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 44, a4: &v7);
  v5 = v4;
  if ( v4 != nullptr )
  {
    GFxShapeBase::GFxShapeBase(this: v4);
    v5[10] = 0;
    *v5 = &GFxConstShapeNoStyles::`vftable';
    *((_DWORD *)this + 36) = v5;
  }
  else
  {
    *((_DWORD *)this + 36) = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10159CB0
// Name: public: void GFxMorphCharacterDef::Read(class GFxLoadProcess __near *,struct GFxTagInfo const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMorphCharacterDef::Read(_cpinfo *this, GFxAmpMsgHandler *a2, _cpinfo *a3, bool a4)
{
  GFxAmpMsgHandler *v4; // ebx
  GFxStream *RefCount; // esi
  int v7; // eax
  float *v8; // eax
  float *v9; // eax
  int v10; // ecx
  _LUID_AND_ATTRIBUTES *v11; // edx
  _LUID_AND_ATTRIBUTES *p_HighPart; // ecx
  _LUID_AND_ATTRIBUTES *v13; // eax
  int v14; // edx
  _LUID_AND_ATTRIBUTES *v15; // eax
  _LUID_AND_ATTRIBUTES *v16; // ecx
  float v17; // eax
  int v18; // eax
  _LUID_AND_ATTRIBUTES *v19; // eax
  float v20; // ecx
  _cpinfo *v21; // ebx
  unsigned int v22; // eax
  unsigned __int8 *v23; // ebx
  unsigned int v24; // edi
  int v25; // ebx
  GFxFillStyle *v26; // ecx
  unsigned int v27; // eax
  unsigned int v28; // edi
  unsigned int v29; // ebx
  unsigned int MaxCharSize; // edx
  int v31; // ecx
  _LUID_AND_ATTRIBUTES *v32; // eax
  _LUID_AND_ATTRIBUTES *v33; // ecx
  float v34; // eax
  int v35; // eax
  _LUID_AND_ATTRIBUTES *v36; // eax
  float v37; // ecx
  unsigned int v38; // ebx
  int v39; // edi
  unsigned int v40; // ebx
  _cpinfo *v41; // ecx
  int v42; // edi
  int v43; // edi
  int v44; // edx
  int v45; // eax
  int v46; // ecx
  int v47; // ebx
  _LUID_AND_ATTRIBUTES *v48; // eax
  __int16 v49; // cx
  int v50; // edx
  _LUID_AND_ATTRIBUTES *v51; // eax
  __int16 v52; // cx
  _DWORD *v53; // edx
  int v54; // eax
  _LUID_AND_ATTRIBUTES *v55; // ecx
  __int16 v56; // dx
  int v57; // ecx
  _LUID_AND_ATTRIBUTES *v58; // eax
  double v59; // st7
  void **v60; // eax
  void **v61; // eax
  unsigned int v62; // edi
  int v63; // ebx
  unsigned int v64; // eax
  int *v65; // edi
  int v66; // ecx
  int v67; // edx
  _cpinfo *v68; // edi
  unsigned int v69; // esi
  unsigned int v70; // ebx
  GAtomicOpsRawBase::AcquireSync *v71; // edi
  unsigned int v72; // esi
  int v73; // ebx
  int v74; // esi
  IShaderDevice *v75; // ecx
  unsigned int v76; // esi
  unsigned int v77; // edi
  unsigned __int8 *v78; // ebx
  int v79; // esi
  int j; // ebx
  _cpinfo *v81; // esi
  unsigned int EdgesCount; // ebx
  double v83; // st7
  unsigned __int8 *v84; // esi
  int v85; // esi
  ButtonCode_t v86; // esi
  unsigned int v87; // edi
  unsigned int v88; // eax
  int v89; // ecx
  _DWORD *v90; // edi
  _DWORD *m; // eax
  int v92; // eax
  unsigned int v93; // edi
  ButtonCode_t v94; // esi
  float *v95; // eax
  unsigned int v96; // ebx
  unsigned int k; // ecx
  float *v98; // eax
  unsigned int v99; // ecx
  unsigned int v100; // ecx
  float *v101; // eax
  unsigned int v102; // edx
  unsigned int v103; // [esp-10h] [ebp-1C0h]
  CFltX4AttributeIterator *v104; // [esp-4h] [ebp-1B4h]
  unsigned int v105; // [esp-4h] [ebp-1B4h]
  _cpinfo *v106; // [esp+0h] [ebp-1B0h]
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v107; // [esp+0h] [ebp-1B0h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v108; // [esp+0h] [ebp-1B0h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v109; // [esp+0h] [ebp-1B0h]
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v110; // [esp+0h] [ebp-1B0h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v111; // [esp+0h] [ebp-1B0h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v112; // [esp+0h] [ebp-1B0h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v113; // [esp+0h] [ebp-1B0h]
  IKMeansErrorMetric v114; // [esp+Ch] [ebp-1A4h] BYREF
  char v115; // [esp+2Ch] [ebp-184h]
  IKMeansErrorMetric v116; // [esp+80h] [ebp-130h] BYREF
  char v117; // [esp+A0h] [ebp-110h]
  int v118; // [esp+F4h] [ebp-BCh] BYREF
  int v119; // [esp+F8h] [ebp-B8h] BYREF
  float v120; // [esp+FCh] [ebp-B4h]
  float v121; // [esp+100h] [ebp-B0h]
  float v122; // [esp+104h] [ebp-ACh]
  int v123; // [esp+108h] [ebp-A8h] BYREF
  float v124; // [esp+10Ch] [ebp-A4h]
  float v125; // [esp+110h] [ebp-A0h]
  float v126; // [esp+114h] [ebp-9Ch]
  int v127; // [esp+118h] [ebp-98h] BYREF
  float v128; // [esp+11Ch] [ebp-94h]
  float v129; // [esp+120h] [ebp-90h]
  float v130; // [esp+124h] [ebp-8Ch]
  int v131; // [esp+128h] [ebp-88h] BYREF
  float v132; // [esp+12Ch] [ebp-84h]
  float v133; // [esp+130h] [ebp-80h]
  float v134; // [esp+134h] [ebp-7Ch]
  int v135; // [esp+138h] [ebp-78h] BYREF
  int v136; // [esp+13Ch] [ebp-74h]
  GFxAmpMsgHandler *v137; // [esp+140h] [ebp-70h]
  _DWORD *v138; // [esp+144h] [ebp-6Ch] BYREF
  float v139; // [esp+148h] [ebp-68h]
  float v140; // [esp+14Ch] [ebp-64h]
  unsigned int v141; // [esp+150h] [ebp-60h]
  _cpinfo *v142; // [esp+154h] [ebp-5Ch]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *i; // [esp+158h] [ebp-58h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> v144; // [esp+15Ch] [ebp-54h] BYREF
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> v145; // [esp+184h] [ebp-2Ch] BYREF
  _DWORD *v146; // [esp+19Ch] [ebp-14h] BYREF
  int v147; // [esp+1A0h] [ebp-10h]
  int v148; // [esp+1A4h] [ebp-Ch]
  char v149; // [esp+1A8h] [ebp-8h]

  v4 = a2;
  RefCount = (GFxStream *)a2[40].RefCount;
  v142 = this;
  v137 = a2;
  v141 = (unsigned int)a3;
  if ( RefCount == nullptr )
    RefCount = (GFxStream *)&a2[2];
  *(float *)&v127 = 0.0;
  v128 = 0.0;
  v129 = 0.0;
  v130 = 0.0;
  *(float *)&v131 = 0.0;
  v132 = 0.0;
  v133 = 0.0;
  v134 = 0.0;
  *(float *)&v119 = 0.0;
  v120 = 0.0;
  v121 = 0.0;
  v122 = 0.0;
  *(float *)&v123 = 0.0;
  v124 = 0.0;
  v125 = 0.0;
  v126 = 0.0;
  GFxStream::ReadRect(this: RefCount, a2: (int)&v127);
  GFxStream::ReadRect(this: RefCount, a2: (int)&v131);
  if ( *(_DWORD *)v141 == 84 )
  {
    GFxStream::ReadRect(this: RefCount, a2: (int)&v119);
    GFxStream::ReadRect(this: RefCount, a2: (int)&v123);
    v7 = (char *)RefCount[12] - (char *)RefCount[11];
    *((_BYTE *)RefCount + 21) = 0;
    if ( v7 < 1 )
      GFxStream::PopulateBuffer1(result: v106);
    RefCount[11] = (GFxStream)((char *)RefCount[11] + 1);
  }
  else
  {
    v119 = v127;
    v120 = v128;
    v121 = v129;
    v122 = v130;
    v123 = v131;
    v124 = v132;
    v125 = v133;
    v126 = v134;
  }
  v8 = *((float **)this + 35);
  v140 = v128;
  *(float *)&i = v129;
  v139 = v130;
  v8[1] = *(float *)&v127;
  v8[2] = v140;
  v8[3] = *(float *)&i;
  v8[4] = v139;
  v9 = *((float **)this + 36);
  v139 = v132;
  v140 = v133;
  *(float *)&i = v134;
  v9[1] = *(float *)&v131;
  v9[2] = v139;
  v9[3] = v140;
  v9[4] = *(float *)&i;
  (*(void (__thiscall **)(_DWORD, int *))(**((_DWORD **)this + 35) + 8))(a1: *((_DWORD *)this + 35), a2: &v119);
  (*(void (__thiscall **)(_DWORD, int *))(**((_DWORD **)this + 36) + 8))(a1: *((_DWORD *)this + 36), a2: &v123);
  v10 = (char *)RefCount[12] - (char *)RefCount[11];
  *((_BYTE *)RefCount + 21) = 0;
  if ( v10 < 4 )
    GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)4);
  v11 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
  p_HighPart = (_LUID_AND_ATTRIBUTES *)&v11->Luid.HighPart;
  v136 = *((unsigned __int8 *)&(*RefCount[15])[0].Luid.LowPart + (_DWORD)v11)
       | ((*((unsigned __int8 *)&(*RefCount[15])[0].Luid.LowPart + (_DWORD)v11 + 1)
         | ((*((unsigned __int8 *)&v11->Luid.LowPart + (_DWORD)RefCount[15] + 2)
           | (*((unsigned __int8 *)&v11->Luid.LowPart + (_DWORD)RefCount[15] + 3) << 8)) << 8)) << 8);
  v13 = (_LUID_AND_ATTRIBUTES *)RefCount[12];
  v14 = (int)RefCount[13] + (char *)&v11->Luid.HighPart - (char *)v13;
  RefCount[11] = (GFxStream)p_HighPart;
  v138 = (_DWORD *)v14;
  *((_BYTE *)RefCount + 21) = 0;
  if ( (char *)v13 - (char *)p_HighPart < 1 )
    GFxStream::PopulateBuffer1(result: v106);
  v15 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
  v16 = (_LUID_AND_ATTRIBUTES *)((char *)&v15->Luid.LowPart + 1);
  LODWORD(v17) = *((unsigned __int8 *)&(*RefCount[15])[0].Luid.LowPart + (_DWORD)v15);
  RefCount[11] = (GFxStream)v16;
  if ( LODWORD(v17) == 255 )
  {
    v18 = (char *)RefCount[12] - (char *)v16;
    *((_BYTE *)RefCount + 21) = 0;
    if ( v18 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v19 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
    LODWORD(v20) = *(unsigned __int16 *)((char *)&v19->Luid.LowPart + (_DWORD)RefCount[15]);
    RefCount[11] = (GFxStream)((char *)&v19->Luid.LowPart + 2);
    v17 = v20;
  }
  if ( v17 != 0.0 )
  {
    v140 = v17;
    while ( 1 )
    {
      GFxFillStyle::GFxFillStyle(
        this: &v145,
        a2: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)v106);
      GFxFillStyle::GFxFillStyle(this: &v144, a2: v107);
      v103 = (unsigned int)v4;
      v21 = v142;
      GFxMorphCharacterDef::ReadMorphFillStyle(
        p: v103,
        a2: *(_DWORD *)v141,
        a3: (unsigned __int8 *)&v145,
        a4: (struct GColor)&v144);
      v22 = *(_DWORD *)&v21[7].LeadByte[6];
      v23 = &v21[7].LeadByte[2];
      v24 = v22 + 1;
      if ( v22 + 1 >= v22 )
      {
        if ( v24 >= *((_DWORD *)v23 + 2) )
          GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
            this: (GAtomicOpsRawBase::AcquireSync *)v23,
            pheapAddr: v23,
            newCapacity: v24 + (v24 >> 2));
      }
      else
      {
        v25 = *(_DWORD *)v23 + 40 * v22 - 40;
        *(float *)&i = NAN;
        do
        {
          GFxFillStyle::~GFxFillStyle(result: v108);
          v25 -= 40;
          i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)i - 1);
        }
        while ( *(float *)&i != 0.0 );
        v23 = &v142[7].LeadByte[2];
        if ( v24 < *(_DWORD *)&v142[7].LeadByte[10] >> 1 )
          GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
            this: (GAtomicOpsRawBase::AcquireSync *)v23,
            pheapAddr: v23,
            newCapacity: v24);
      }
      v26 = (GFxFillStyle *)(*(_DWORD *)v23 + 40 * v24 - 40);
      *((_DWORD *)v23 + 1) = v24;
      if ( v26 != nullptr )
        GFxFillStyle::GFxFillStyle(this: v26, a2: (const struct GFxFillStyle *)&v145);
      v27 = *(_DWORD *)v142[8].DefaultChar;
      v28 = v27 + 1;
      if ( v27 + 1 >= v27 )
      {
        if ( v28 >= *(_DWORD *)&v142[8].LeadByte[2] )
          GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
            this: (GAtomicOpsRawBase::AcquireSync *)&v142[8],
            pheapAddr: &v142[8],
            newCapacity: v28 + (v28 >> 2));
      }
      else
      {
        v29 = v142[8].MaxCharSize + 40 * v27 - 40;
        *(float *)&i = NAN;
        do
        {
          GFxFillStyle::~GFxFillStyle(result: v108);
          v29 -= 40;
          i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)i - 1);
        }
        while ( *(float *)&i != 0.0 );
        if ( v28 < *(_DWORD *)&v142[8].LeadByte[2] >> 1 )
          GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
            this: (GAtomicOpsRawBase::AcquireSync *)&v142[8],
            pheapAddr: &v142[8],
            newCapacity: v28);
      }
      MaxCharSize = v142[8].MaxCharSize;
      *(_DWORD *)v142[8].DefaultChar = v28;
      if ( MaxCharSize + 40 * v28 != 40 )
        GFxFillStyle::GFxFillStyle(
          this: (GFxFillStyle *)(MaxCharSize + 40 * v28 - 40),
          a2: (const struct GFxFillStyle *)&v144);
      GFxFillStyle::~GFxFillStyle(result: v108);
      GFxFillStyle::~GFxFillStyle(result: v109);
      --LODWORD(v140);
      if ( v140 == 0.0 )
        break;
      v4 = v137;
    }
  }
  v31 = (char *)RefCount[12] - (char *)RefCount[11];
  *((_BYTE *)RefCount + 21) = 0;
  if ( v31 < 1 )
    GFxStream::PopulateBuffer1(result: v106);
  v32 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
  v33 = (_LUID_AND_ATTRIBUTES *)((char *)&v32->Luid.LowPart + 1);
  LODWORD(v34) = *((unsigned __int8 *)&(*RefCount[15])[0].Luid.LowPart + (_DWORD)v32);
  RefCount[11] = (GFxStream)v33;
  if ( LODWORD(v34) == 255 )
  {
    v35 = (char *)RefCount[12] - (char *)v33;
    *((_BYTE *)RefCount + 21) = 0;
    if ( v35 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v36 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
    LODWORD(v37) = *(unsigned __int16 *)((char *)&v36->Luid.LowPart + (_DWORD)RefCount[15]);
    RefCount[11] = (GFxStream)((char *)&v36->Luid.LowPart + 2);
    v34 = v37;
  }
  if ( v34 != 0.0 )
  {
    v140 = v34;
    do
    {
      v38 = *(_DWORD *)&v142[8].LeadByte[10];
      LODWORD(v139) = &v142[8].LeadByte[6];
      GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (int)&v142[8].LeadByte[6],
        a2: &v142[8].LeadByte[6],
        a3: v38 + 1);
      if ( v38 + 1 > v38 )
      {
        v39 = 1;
        i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(*(_DWORD *)LODWORD(v139) + 24 * v38);
        do
        {
          if ( *(float *)&i != 0.0 )
            GFxLineStyle::GFxLineStyle(result: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)v106);
          ++i;
          --v39;
        }
        while ( v39 != 0 );
      }
      v40 = *(_DWORD *)&v142[9].LeadByte[2];
      GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (int)v142[9].DefaultChar,
        a2: v142[9].DefaultChar,
        a3: v40 + 1);
      v41 = v142;
      if ( v40 + 1 > v40 )
      {
        v42 = 1;
        i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(*(_DWORD *)v142[9].DefaultChar + 24 * v40);
        do
        {
          if ( *(float *)&i != 0.0 )
          {
            GFxLineStyle::GFxLineStyle(result: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)v106);
            v41 = v142;
          }
          ++i;
          --v42;
        }
        while ( v42 != 0 );
      }
      v43 = *(_DWORD *)&v41[8].LeadByte[6] + 24 * *(_DWORD *)&v41[8].LeadByte[10] - 24;
      v44 = 3 * *(_DWORD *)&v41[9].LeadByte[2];
      v45 = *(_DWORD *)v41[9].DefaultChar;
      v46 = (char *)RefCount[12] - (char *)RefCount[11];
      v47 = v45 + 8 * v44 - 24;
      *((_BYTE *)RefCount + 21) = 0;
      if ( v46 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v48 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
      v49 = *(_WORD *)((char *)&v48->Luid.LowPart + (_DWORD)RefCount[15]);
      RefCount[11] = (GFxStream)((char *)&v48->Luid.LowPart + 2);
      *(_WORD *)(v43 + 4) = v49;
      v50 = (char *)RefCount[12] - (char *)RefCount[11];
      *((_BYTE *)RefCount + 21) = 0;
      if ( v50 < 2 )
        GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
      v51 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
      v52 = *(_WORD *)((char *)&v51->Luid.LowPart + (_DWORD)RefCount[15]);
      v53 = (_DWORD *)v141;
      RefCount[11] = (GFxStream)((char *)&v51->Luid.LowPart + 2);
      *(_WORD *)(v47 + 4) = v52;
      if ( *v53 == 84 )
      {
        v54 = (char *)RefCount[12] - (char *)RefCount[11];
        *((_BYTE *)RefCount + 21) = 0;
        if ( v54 < 2 )
          GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
        v55 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
        v56 = *(_WORD *)((char *)&v55->Luid.LowPart + (_DWORD)RefCount[15]);
        RefCount[11] = (GFxStream)((char *)&v55->Luid.LowPart + 2);
        *(_WORD *)(v47 + 16) = v56;
        *(_WORD *)(v43 + 16) = v56;
        if ( (v56 & 0x20) != 0 )
        {
          v57 = (char *)RefCount[12] - (char *)RefCount[11];
          *((_BYTE *)RefCount + 21) = 0;
          if ( v57 < 2 )
            GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
          v58 = (_LUID_AND_ATTRIBUTES *)RefCount[11];
          LODWORD(v139) = (unsigned __int16)(*((unsigned __int8 *)&v58->Luid.LowPart + (_DWORD)RefCount[15])
                                           | (*((unsigned __int8 *)&v58->Luid.LowPart + (_DWORD)RefCount[15] + 1) << 8));
          RefCount[11] = (GFxStream)((char *)&v58->Luid.LowPart + 2);
          v139 = (double)SLODWORD(v139) * 0.00390625;
          v59 = v139;
          *(float *)(v47 + 20) = v139;
          *(float *)(v43 + 20) = v59;
        }
      }
      if ( (*(_BYTE *)(v43 + 16) & 8) != 0 )
      {
        GFxFillStyle::GFxFillStyle(
          this: &v144,
          a2: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)v106);
        GFxFillStyle::GFxFillStyle(this: &v145, a2: v110);
        GFxMorphCharacterDef::ReadMorphFillStyle(
          p: (unsigned int)v137,
          a2: *(_DWORD *)v141,
          a3: (unsigned __int8 *)&v144,
          a4: (struct GColor)&v145);
        GFxLineStyle::SetComplexFill(this: (GFxLineStyle *)v43, a2: (const struct GFxFillStyle *)&v144);
        if ( (v144.m_pfnProxied & 0x10) != 0 )
        {
          v118 = *(_DWORD *)(*(_DWORD *)(DWORD1(v144.m_pfnProxied) + 12) + 4);
          v60 = (void **)&v118;
        }
        else
        {
          v60 = (void **)&v138;
        }
        *(_DWORD *)(v43 + 8) = *v60;
        GFxLineStyle::SetComplexFill(this: (GFxLineStyle *)v47, a2: (const struct GFxFillStyle *)&v145);
        if ( (v145.m_pfnProxied & 0x10) != 0 )
        {
          v135 = *(_DWORD *)(*(_DWORD *)(DWORD1(v145.m_pfnProxied) + 12) + 4);
          v61 = (void **)&v135;
        }
        else
        {
          v61 = (void **)&v138;
        }
        *(_DWORD *)(v47 + 8) = *v61;
        GFxFillStyle::~GFxFillStyle(result: v111);
        GFxFillStyle::~GFxFillStyle(result: v112);
      }
      else
      {
        GFxLoadProcess::ReadRgbaTag(pc: (void *)(v43 + 8), a2: *(const unsigned __int8 **)v141);
        GFxLoadProcess::ReadRgbaTag(pc: (void *)(v47 + 8), a2: *(const unsigned __int8 **)v141);
      }
      --LODWORD(v140);
    }
    while ( v140 != 0.0 );
  }
  v62 = (unsigned int)RefCount[13] + (char *)RefCount[11] - (char *)RefCount[12];
  v63 = (int)v138 + v136;
  if ( (unsigned int)v138 + v136 >= v62 )
  {
    GFxLogBase<GFxStream>::LogParseShape(
      this: (tagBITMAPINFOHEADER *)RefCount,
      a2: (int)"GFxMorphCharacterDef, first shape:\n");
    v64 = v63 - v62;
    v65 = (int *)v141;
    GFxConstShapeNoStyles::Read(
      this: (CBitRead *)v142[7].MaxCharSize,
      a2: (_cpinfo *)v141,
      p: v137,
      a4: *(_DWORD *)v141,
      lenInBytes: v64,
      withStyle: false,
      a7: nullptr);
    GFxLogBase<GFxStream>::LogParseShape(
      this: (tagBITMAPINFOHEADER *)RefCount,
      a2: (int)"GFxMorphCharacterDef, second shape:\n");
    GFxStream::SetPosition(this: (IShaderDeviceMgr *)RefCount, pos: v63, a3: (int)v106);
    v66 = v65[2] + v65[3];
    v67 = *v65;
    v68 = v142;
    GFxConstShapeNoStyles::Read(
      this: *(CBitRead **)v142[7].DefaultChar,
      a2: v142,
      p: v137,
      a4: v67,
      lenInBytes: v66 - v63,
      withStyle: false,
      a7: nullptr);
    v69 = *(_DWORD *)&v142[7].LeadByte[6];
    v70 = v68[5].MaxCharSize;
    v71 = (GAtomicOpsRawBase::AcquireSync *)&v68[4].LeadByte[10];
    if ( v69 >= v70 )
    {
      if ( v69 >= *(_DWORD *)&v71[8] )
        GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
          this: v71,
          pheapAddr: v71,
          newCapacity: v69 + (v69 >> 2));
    }
    else
    {
      i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(*(_DWORD *)v71 + 40 * v70 - 40);
      if ( v70 != v69 )
      {
        LODWORD(v140) = v70 - v69;
        do
        {
          GFxFillStyle::~GFxFillStyle(result: v113);
          i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)i - 40);
          --LODWORD(v140);
        }
        while ( v140 != 0.0 );
      }
      if ( v69 < *(_DWORD *)&v71[8] >> 1 )
        GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::Reserve(
          this: v71,
          pheapAddr: v71,
          newCapacity: v69);
    }
    *(_DWORD *)&v71[4] = v69;
    if ( v69 > v70 )
    {
      v72 = v69 - v70;
      for ( i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(*(_DWORD *)v71 + 40 * v70);
            v72 != 0;
            --v72 )
      {
        if ( *(float *)&i != 0.0 )
          GFxFillStyle::GFxFillStyle(this: i, a2: v113);
        i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)i + 40);
      }
    }
    v73 = 0;
    v140 = 0.0;
    if ( *(_DWORD *)&v71[4] != 0 )
    {
      do
      {
        v74 = v73 + *(_DWORD *)v71;
        *(_BYTE *)v74 = *(_BYTE *)(v73 + *(_DWORD *)&v142[7].LeadByte[2]);
        *(_DWORD *)(v74 + 4) = 0;
        if ( *(_DWORD *)(v74 + 8) == 0 )
        {
          v75 = *(IShaderDevice **)(v74 + 12);
          if ( v75 != nullptr )
            GFxResource::Release(this: v75);
        }
        *(_DWORD *)(v74 + 8) = 0;
        *(_DWORD *)(v74 + 12) = 0;
        v73 += 40;
        ++LODWORD(v140);
      }
      while ( LODWORD(v140) < *(_DWORD *)&v71[4] );
    }
    v76 = *(_DWORD *)&v142[8].LeadByte[10];
    v77 = *(_DWORD *)&v142[5].LeadByte[6];
    v78 = &v142[5].LeadByte[2];
    GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (int)&v142[5].LeadByte[2],
      a2: &v142[5].LeadByte[2],
      a3: v76);
    if ( v76 > v77 )
    {
      v79 = v76 - v77;
      for ( j = *(_DWORD *)v78 + 24 * v77; v79 != 0; --v79 )
      {
        if ( j != 0 )
          GFxLineStyle::GFxLineStyle(result: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)v113);
        j += 24;
      }
    }
    v81 = v142;
    v104 = (CFltX4AttributeIterator *)v142[7].MaxCharSize;
    EdgesCount = 0;
    v141 = 0;
    GFxSwfPathData::PathsIterator::PathsIterator(this: (GFxSwfPathData::PathsIterator *)&v116, a2: v104);
    GFxSwfPathData::PathsIterator::PathsIterator(
      this: (GFxSwfPathData::PathsIterator *)&v114,
      a2: *(CFltX4AttributeIterator **)v81[7].DefaultChar);
    GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (int)&v81[9].LeadByte[10],
      a2: &v81[9].LeadByte[10],
      a3: 0);
    v83 = 0.0;
    while ( 1 )
    {
      if ( v117 == 1 && v115 == 1 )
        return;
      *(float *)&v145.m_pObject = v83;
      *((float *)&v145.m_pObject + 1) = v83;
      v146 = nullptr;
      v147 = 0;
      v148 = 0;
      v149 = 0;
      memset((char *)&v145.m_pfnProxied + 4, 0, 12);
      GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)&v146,
        pheapAddr: (ButtonCode_t)&v146,
        newCapacity: 0);
      v84 = &v142[9].LeadByte[10];
      v105 = v142[10].MaxCharSize + 1;
      v147 = 0;
      GArrayDataBase<GFxMorphCharacterDef::Path,GAllocatorLH<GFxMorphCharacterDef::Path,2>,GArrayDefaultPolicy>::ResizeNoConstruct(
        this: (int)&v142[9].LeadByte[10],
        a2: &v142[9].LeadByte[10],
        a3: v105);
      v85 = *(_DWORD *)v84 + 36 * *((_DWORD *)v84 + 1) - 36;
      v135 = v85;
      if ( v85 != 0 )
      {
        *(_DWORD *)v85 = DWORD1(v145.m_pfnProxied);
        *(_QWORD *)(v85 + 4) = *((_QWORD *)&v145.m_pfnProxied + 1);
        *(float *)(v85 + 12) = *(float *)&v145.m_pObject;
        v86 = v85 + 20;
        *(float *)(v86 - 4) = *((float *)&v145.m_pObject + 1);
        *(_DWORD *)v86 = 0;
        *(_DWORD *)(v86 + 4) = 0;
        *(_DWORD *)(v86 + 8) = 0;
        v136 = v147;
        v138 = v146;
        if ( v147 != 0 )
          break;
LABEL_116:
        *(_BYTE *)(v135 + 32) = v149;
      }
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v146);
      if ( EdgesCount == 0 )
      {
        EdgesCount = GFxSwfPathData::PathsIterator::GetEdgesCount(this: (GFxSwfPathData::PathsIterator *)&v116);
        if ( v117 != 1 )
        {
          if ( v117 == 2 )
            GFxSwfPathData::PathsIterator::ReadNextEdge(this: &v116);
          else
            GFxSwfPathData::PathsIterator::SkipComplex(this: &v116);
        }
      }
      if ( v141 == 0 )
      {
        v141 = GFxSwfPathData::PathsIterator::GetEdgesCount(this: (GFxSwfPathData::PathsIterator *)&v114);
        if ( v115 != 1 )
        {
          if ( v115 == 2 )
            GFxSwfPathData::PathsIterator::ReadNextEdge(this: &v114);
          else
            GFxSwfPathData::PathsIterator::SkipComplex(this: &v114);
        }
      }
      v92 = *(_DWORD *)&v142[9].LeadByte[10];
      v93 = *(_DWORD *)(v92 + 36 * v142[10].MaxCharSize - 12);
      v94 = v92 + 36 * v142[10].MaxCharSize - 16;
      if ( EdgesCount == v141 )
      {
        if ( EdgesCount >= v93 )
        {
          if ( EdgesCount >= *(_DWORD *)(v94 + 8) )
            GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
              this: (void **)v94,
              pheapAddr: v94,
              newCapacity: EdgesCount + (EdgesCount >> 2));
        }
        else if ( EdgesCount < *(_DWORD *)(v94 + 8) >> 1 )
        {
          GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v94,
            pheapAddr: v94,
            newCapacity: EdgesCount);
        }
        *(_DWORD *)(v94 + 4) = EdgesCount;
        if ( EdgesCount > v93 && (v95 = (float *)(*(_DWORD *)v94 + 16 * v93), (v96 = EdgesCount - v93) != 0) )
        {
          v83 = 0.0;
          for ( k = v96; k != 0; --k )
          {
            if ( v95 != nullptr )
            {
              *v95 = 0.0;
              v95[1] = 0.0;
              v95[2] = 0.0;
              v95[3] = 0.0;
            }
            v95 += 4;
          }
          EdgesCount = 0;
          v141 = 0;
        }
        else
        {
          v83 = 0.0;
          EdgesCount = 0;
          v141 = 0;
        }
      }
      else if ( EdgesCount >= v141 )
      {
        v100 = v141;
        if ( v141 >= v93 )
        {
          if ( v141 < *(_DWORD *)(v94 + 8) )
            goto LABEL_161;
          GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v94,
            pheapAddr: v94,
            newCapacity: v141 + (v141 >> 2));
        }
        else
        {
          if ( v141 >= *(_DWORD *)(v94 + 8) >> 1 )
            goto LABEL_161;
          GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v94,
            pheapAddr: v94,
            newCapacity: v141);
        }
        v100 = v141;
LABEL_161:
        *(_DWORD *)(v94 + 4) = v100;
        if ( v100 <= v93 || (v101 = (float *)(*(_DWORD *)v94 + 16 * v93), v102 = v100 - v93, v100 == v93) )
        {
          v83 = 0.0;
          EdgesCount -= v100;
          v141 = 0;
        }
        else
        {
          v83 = 0.0;
          do
          {
            if ( v101 != nullptr )
            {
              *v101 = 0.0;
              v101[1] = 0.0;
              v101[2] = 0.0;
              v101[3] = 0.0;
            }
            v101 += 4;
            --v102;
          }
          while ( v102 != 0 );
          EdgesCount -= v100;
          v141 = 0;
        }
      }
      else
      {
        if ( EdgesCount >= v93 )
        {
          if ( EdgesCount >= *(_DWORD *)(v94 + 8) )
            GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
              this: (void **)v94,
              pheapAddr: v94,
              newCapacity: EdgesCount + (EdgesCount >> 2));
        }
        else if ( EdgesCount < *(_DWORD *)(v94 + 8) >> 1 )
        {
          GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
            this: (void **)v94,
            pheapAddr: v94,
            newCapacity: EdgesCount);
        }
        *(_DWORD *)(v94 + 4) = EdgesCount;
        if ( EdgesCount <= v93
          || (v98 = (float *)(*(_DWORD *)v94 + 16 * v93), v99 = EdgesCount - v93, EdgesCount == v93) )
        {
          v141 -= EdgesCount;
          v83 = 0.0;
          EdgesCount = 0;
        }
        else
        {
          v83 = 0.0;
          do
          {
            if ( v98 != nullptr )
            {
              *v98 = 0.0;
              v98[1] = 0.0;
              v98[2] = 0.0;
              v98[3] = 0.0;
            }
            v98 += 4;
            --v99;
          }
          while ( v99 != 0 );
          v141 -= EdgesCount;
          EdgesCount = 0;
        }
      }
    }
    v87 = *(_DWORD *)(v86 + 4);
    v88 = v87 + v147;
    i = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(v87 + v147);
    if ( v87 + v147 >= v87 )
    {
      if ( v88 < *(_DWORD *)(v86 + 8) )
        goto LABEL_112;
      GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v86,
        pheapAddr: v86,
        newCapacity: v88 + (v88 >> 2));
    }
    else
    {
      if ( v88 >= *(_DWORD *)(v86 + 8) >> 1 )
        goto LABEL_112;
      GArrayDataBase<GASValue,GAllocatorLH<GASValue,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v86,
        pheapAddr: v86,
        newCapacity: v88);
    }
    v88 = (unsigned int)i;
LABEL_112:
    v89 = v136;
    v90 = (_DWORD *)(*(_DWORD *)v86 + 16 * v87);
    *(_DWORD *)(v86 + 4) = v88;
    for ( m = v138; v89 != 0; --v89 )
    {
      if ( v90 != nullptr )
      {
        *v90 = *m;
        v90[1] = m[1];
        v90[2] = m[2];
        v90[3] = m[3];
      }
      m += 4;
      v90 += 4;
    }
    goto LABEL_116;
  }
}
