// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bonesetup/bone_setup.cpp
// Functions: 12
// ============================================================

#include "bonesetup\bone_setup.h"

//------------------------------------------------------------------------------
// Address: 0x0059F620
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0059F6B0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x0059F860
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0059FA30
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0059FC60
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0059FE20
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x0059FE30
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_99;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_99;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_98:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: v37,
        s: v35,
        boneMask: v54);
      goto LABEL_99;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        goto LABEL_99;
      }
      if ( anim_3wayblend.m_pParent == nullptr || anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_98;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_98;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_99;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_99;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      pos2,
      s,
      boneMask);
    goto LABEL_99;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_99;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_99;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_99:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x005A0810
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A0850
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A0940
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x005A0960
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v18; // [esp+50h] [ebp-108Ch] BYREF
  float v19; // [esp+10C4h] [ebp-18h]
  Vector *v20; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v21; // [esp+10CCh] [ebp-10h]
  _DWORD v22[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v22[0] = a2;
  v22[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v19 = flWeight;
    else
      v19 = 1.0;
  }
  else
  {
    v19 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v20 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v20 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    v21 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v21 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v21 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v21 = nullptr;
      }
      if ( ((unsigned __int8)v21 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(v19),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v18);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v18,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v20, q: v21, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v20,
           q: v21,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v20,
        q: v21,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = this->m_boneMask;
      *(float *)&s = v19;
      SlerpBones(
        a1: COERCE_FLOAT(v22),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v21,
        pos2: v20,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v21);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: v19);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: v19, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v18.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&v18.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A0CB0
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0066B330
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0066B3C0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x0066B570
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0066B740
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066B970
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066BB30
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x0066BB40
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x0066C520
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0066C560
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (__m128i *)pos, src: (const __m128i *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (__m128i *)q, src: (const __m128i *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066C650
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x0066C670
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066C9C0
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace elementviewer

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x0049E5E0
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049E670
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x0049E820
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049E9F0
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049EC20
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049EDE0
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x0049EDF0
// Name: void DoAxisInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoAxisInterpBone(float ebp0@<ebp>, mstudiobone_t *pbones, int ibone, CBoneAccessor *bonetoworld)
{
  int procindex; // esi
  matrix3x4a_t *m_pBones; // edx
  int *p_parent; // edi
  int v7; // ecx
  matrix3x4a_t *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  const Quaternion *v12; // edx
  const Quaternion *v13; // eax
  float *v14; // edi
  const Quaternion *v15; // ecx
  float *v16; // esi
  float v17; // xmm0_4
  float v18; // xmm0_4
  _BYTE v19[12]; // [esp+18h] [ebp-9Ch] BYREF
  matrix3x4a_t bonematrix; // [esp+24h] [ebp-90h] BYREF
  Quaternion tmp; // [esp+54h] [ebp-60h] BYREF
  Quaternion v; // [esp+64h] [ebp-50h] BYREF
  mstudiobone_t *v23; // [esp+74h] [ebp-40h]
  float v24; // [esp+78h] [ebp-3Ch] BYREF
  float v25; // [esp+7Ch] [ebp-38h]
  float v26; // [esp+80h] [ebp-34h]
  Vector control; // [esp+84h] [ebp-30h]
  Vector *p1; // [esp+90h] [ebp-24h]
  const Quaternion *t; // [esp+94h] [ebp-20h]
  float a2; // [esp+98h] [ebp-1Ch] BYREF
  float a1; // [esp+9Ch] [ebp-18h]
  Quaternion *q3; // [esp+A0h] [ebp-14h]
  Vector p; // [esp+A4h] [ebp-10h]
  float retaddr; // [esp+B4h] [ebp+0h]

  p.y = ebp0;
  p.z = retaddr;
  procindex = pbones[ibone].procindex;
  v23 = &pbones[ibone];
  if ( procindex != 0 )
    procindex += (int)&pbones[ibone];
  m_pBones = bonetoworld->m_pBones;
  p_parent = &pbones[*(_DWORD *)procindex].parent;
  v7 = *(_DWORD *)(procindex + 4);
  v8 = &m_pBones[*(_DWORD *)procindex];
  if ( *p_parent == -1 )
  {
    v11 = v8->m_flMatVal[0][v7];
    v24 = v11;
    v10 = v8->m_flMatVal[1][*(_DWORD *)(procindex + 4)];
    v25 = v10;
    v9 = v8->m_flMatVal[2][*(_DWORD *)(procindex + 4)];
    v26 = v9;
  }
  else
  {
    v.y = v8->m_flMatVal[0][v7];
    v.z = v8->m_flMatVal[1][v7];
    v.w = v8->m_flMatVal[2][v7];
    VectorIRotate(in1: &v.y, in2: &m_pBones[*p_parent], out: &v24);
    v9 = v26;
    v10 = v25;
    v11 = v24;
  }
  *(float *)&p1 = v11;
  control.z = v10;
  p.x = v9;
  if ( v11 < 0.0 )
  {
    v11 = -v11;
    *(float *)&p1 = v11;
    v12 = (const Quaternion *)(procindex + 96);
    LODWORD(control.x) = procindex + 20;
  }
  else
  {
    v12 = (const Quaternion *)(procindex + 80);
    LODWORD(control.x) = procindex + 8;
  }
  if ( v10 < 0.0 )
  {
    v10 = -v10;
    control.z = v10;
    v13 = (const Quaternion *)(procindex + 128);
    v14 = (float *)(procindex + 44);
  }
  else
  {
    v13 = (const Quaternion *)(procindex + 112);
    v14 = (float *)(procindex + 32);
  }
  if ( v9 < 0.0 )
  {
    v15 = (const Quaternion *)(procindex + 160);
    v9 = -v9;
    p.x = v9;
    t = (const Quaternion *)(procindex + 160);
    v16 = (float *)(procindex + 68);
  }
  else
  {
    v15 = (const Quaternion *)(procindex + 144);
    t = (const Quaternion *)(procindex + 144);
    v16 = (float *)(procindex + 56);
  }
  v17 = v10 + v11;
  if ( v17 <= 0.0 )
  {
    QuaternionSlerp(p: v15, q: v15, t: 0.0, qt: (Quaternion *)&tmp.y);
    a2 = *v16;
    a1 = v16[1];
    v18 = v16[2];
  }
  else
  {
    control.y = 1.0 / (float)(v17 + v9);
    QuaternionSlerp(p: v13, q: v12, t: v11 / v17, qt: (Quaternion *)&bonematrix.m_flMatVal[2][1]);
    p.x = control.y * p.x;
    QuaternionSlerp(p: (const Quaternion *)&bonematrix.m_flMatVal[2][1], q: t, t: p.x, qt: (Quaternion *)&tmp.y);
    a2 = *(float *)LODWORD(control.x) * (float)(control.y * *(float *)&p1);
    a1 = *(float *)(LODWORD(control.x) + 4) * (float)(control.y * *(float *)&p1);
    *(float *)&q3 = *(float *)(LODWORD(control.x) + 8) * (float)(control.y * *(float *)&p1);
    a2 = (float)((float)(control.y * control.z) * *v14) + a2;
    a1 = (float)(v14[1] * (float)(control.y * control.z)) + a1;
    *(float *)&q3 = (float)(v14[2] * (float)(control.y * control.z)) + *(float *)&q3;
    a2 = (float)(p.x * *v16) + a2;
    a1 = (float)(v16[1] * p.x) + a1;
    v18 = (float)(v16[2] * p.x) + *(float *)&q3;
  }
  *(float *)&q3 = v18;
  QuaternionMatrix(q: (Quaternion *)&tmp.y, pos: (const Vector *)&a2, matrix: (matrix3x4_t *)v19);
  ConcatTransforms(
    in1: &bonetoworld->m_pBones[v23->parent],
    in2: (const matrix3x4_t *)v19,
    out: &bonetoworld->m_pBones[ibone]);
}

//------------------------------------------------------------------------------
// Address: 0x0049F0E0
// Name: void DoAimAtBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DoAimAtBone(
        float a1@<ebp>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld,
        CStudioHdr *pStudioHdr)
{
  mstudiobone_t *v5; // esi
  int procindex; // eax
  char *v7; // esi
  const mstudioattachment_t *v8; // eax
  float v9; // xmm3_4
  __int128 v10; // xmm4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  __int128 v20; // xmm6
  float v21; // xmm3_4
  double v22; // xmm0_8
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  __int128 v41; // xmm4
  float v42; // xmm5_4
  _BYTE v43[12]; // [esp+18h] [ebp-1CCh] BYREF
  matrix3x4a_t boneLocalToWorld; // [esp+24h] [ebp-1C0h] BYREF
  matrix3x4a_t parentSpace; // [esp+54h] [ebp-190h] BYREF
  matrix3x4a_t aimRotationMatrix; // [esp+84h] [ebp-160h] BYREF
  matrix3x4a_t bonematrix; // [esp+B4h] [ebp-130h] BYREF
  matrix3x4a_t aimAtSpace; // [esp+E4h] [ebp-100h] BYREF
  matrix3x4a_t boneMatrix; // [esp+114h] [ebp-D0h] BYREF
  Quaternion boneRotation; // [esp+14Ch] [ebp-98h] BYREF
  Quaternion upRotation; // [esp+15Ch] [ebp-88h] BYREF
  Quaternion aimRotation; // [esp+16Ch] [ebp-78h] BYREF
  Vector tmp_pUp; // [esp+17Ch] [ebp-68h] BYREF
  Vector aimAtWorldPosition; // [esp+188h] [ebp-5Ch] BYREF
  float v55; // [esp+194h] [ebp-50h]
  __int128 aimWorldPosition; // [esp+198h] [ebp-4Ch] OVERLAPPED BYREF
  __int128 tmp_pParentUp; // [esp+1A8h] [ebp-3Ch] OVERLAPPED
  Vector pUp; // [esp+1B8h] [ebp-2Ch]
  float v59; // [esp+1C4h] [ebp-20h]
  Vector pParentUp; // [esp+1C8h] [ebp-1Ch] BYREF
  float v61; // [esp+1D4h] [ebp-10h]
  Vector axis; // [esp+1D8h] [ebp-Ch]
  float retaddr; // [esp+1E4h] [ebp+0h]

  axis.x = a1;
  axis.y = retaddr;
  v5 = &pBones[iBone];
  procindex = v5->procindex;
  LODWORD(aimAtWorldPosition.x) = v5;
  if ( procindex != 0 )
  {
    v7 = (char *)v5 + procindex;
    if ( v7 != nullptr )
    {
      MatrixCopy(in: &bonetoworld->m_pBones[*(_DWORD *)v7], out: (matrix3x4a_t *)&boneLocalToWorld.m_flMatVal[2][1]);
      VectorTransform(
        in1: (const float *)v7 + 8,
        in2: (matrix3x4a_t *)&boneLocalToWorld.m_flMatVal[2][1],
        out: &aimAtWorldPosition.y);
      if ( pStudioHdr != nullptr )
      {
        v8 = CStudioHdr::pAttachment(this: pStudioHdr, i: *((_DWORD *)v7 + 1));
        ConcatTransforms(
          in1: &bonetoworld->m_pBones[v8->localbone],
          in2: &v8->local,
          out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
      }
      else
      {
        MatrixCopy(in: &bonetoworld->m_pBones[*((_DWORD *)v7 + 1)], out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
      }
      MatrixGetColumn(in: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1], column: 3, out: &tmp_pUp);
      QuaternionAngles(
        q: (const Quaternion *)(LODWORD(aimAtWorldPosition.x) + 44),
        angles: (RadianEuler *)((char *)&aimWorldPosition + 4));
      AngleMatrix(
        angles: (const RadianEuler *)((char *)&aimWorldPosition + 4),
        position: (const Vector *)(v7 + 32),
        matrix: (matrix3x4a_t *)&aimRotationMatrix.m_flMatVal[2][1]);
      ConcatTransforms_Aligned(
        m0: &bonetoworld->m_pBones[*(_DWORD *)v7],
        m1: (matrix3x4a_t *)&aimRotationMatrix.m_flMatVal[2][1],
        out: (matrix3x4a_t *)v43);
      v9 = (float)((float)((float)((float)(tmp_pUp.x - aimAtWorldPosition.y) * (float)(tmp_pUp.x - aimAtWorldPosition.y))
                         + 0.00000011920929)
                 + (float)((float)(tmp_pUp.y - aimAtWorldPosition.z) * (float)(tmp_pUp.y - aimAtWorldPosition.z)))
         + (float)((float)(tmp_pUp.z - v55) * (float)(tmp_pUp.z - v55));
      v10 = 0;
      *(float *)&v10 = 1.0 / fsqrt(v9);
      aimWorldPosition = v10;
      v11 = (float)(3.0 - (float)((float)(*(float *)&aimWorldPosition * v9) * *(float *)&aimWorldPosition))
          * (float)(*(float *)&aimWorldPosition * 0.5);
      v12 = (float)(tmp_pUp.x - aimAtWorldPosition.y) * v11;
      v13 = (float)(tmp_pUp.z - v55) * v11;
      v14 = (float)(tmp_pUp.y - aimAtWorldPosition.z) * v11;
      pParentUp.y = (float)(v13 * *((float *)v7 + 3)) - (float)(v14 * *((float *)v7 + 4));
      v15 = (float)(*((float *)v7 + 4) * v12) - (float)(*((float *)v7 + 2) * v13);
      v59 = v13;
      pParentUp.z = v15;
      v16 = *((float *)v7 + 2);
      v17 = *((float *)v7 + 3);
      pUp.y = v12;
      pUp.z = v14;
      v18 = (float)(v16 * v14) - (float)(v17 * v12);
      v19 = (float)((float)((float)(pParentUp.y * pParentUp.y) + 0.00000011920929) + (float)(v15 * v15))
          + (float)(v18 * v18);
      v20 = 0;
      *(float *)&v20 = 1.0 / fsqrt(v19);
      aimWorldPosition = v20;
      v21 = (float)(3.0 - (float)((float)(*(float *)&aimWorldPosition * v19) * *(float *)&aimWorldPosition))
          * (float)(*(float *)&aimWorldPosition * 0.5);
      pParentUp.y = pParentUp.y * v21;
      pParentUp.z = v15 * v21;
      v61 = v18 * v21;
      v22 = (float)((float)((float)(v14 * *((float *)v7 + 3)) + (float)(*((float *)v7 + 2) * v12))
                  + (float)(v59 * *((float *)v7 + 4)));
      __libm_sse2_acos();
      *(float *)&v22 = v22;
      AxisAngleQuaternion(
        axis: (Vector *)&pParentUp.y,
        angle: *(float *)&v22 * 57.29578,
        q: (Quaternion *)&upRotation.y);
      if ( (float)(1.0
                 - COERCE_FLOAT(
                     COERCE_UNSIGNED_INT(
                       (float)((float)(*((float *)v7 + 6) * *((float *)v7 + 3))
                             + (float)(*((float *)v7 + 2) * *((float *)v7 + 5)))
                     + (float)(*((float *)v7 + 7) * *((float *)v7 + 4)))
                   & _mask__AbsFloat_)) <= 0.00000011920929 )
      {
        QuaternionMatrix(
          q: (Quaternion *)&upRotation.y,
          pos: (Vector *)&aimAtWorldPosition.y,
          matrix: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1]);
      }
      else
      {
        QuaternionMatrix(q: (Quaternion *)&upRotation.y, matrix: (matrix3x4a_t *)&parentSpace.m_flMatVal[2][1]);
        VectorRotate(
          in1: (const float *)v7 + 5,
          in2: (matrix3x4a_t *)&parentSpace.m_flMatVal[2][1],
          out: &aimRotation.y);
        v23 = (float)((float)(aimRotation.z * pUp.z) + (float)(aimRotation.y * pUp.y)) + (float)(aimRotation.w * v59);
        v24 = aimRotation.y - (float)(v23 * pUp.y);
        v25 = aimRotation.z - (float)(pUp.z * v23);
        v26 = aimRotation.w - (float)(v59 * v23);
        v27 = (float)((float)((float)(v24 * v24) + 0.00000011920929) + (float)(v25 * v25)) + (float)(v26 * v26);
        *(float *)&tmp_pParentUp = 1.0 / fsqrt(v27);
        v28 = (float)(3.0 - (float)((float)(*(float *)&tmp_pParentUp * v27) * *(float *)&tmp_pParentUp))
            * (float)(*(float *)&tmp_pParentUp * 0.5);
        *((float *)&tmp_pParentUp + 1) = v24 * v28;
        *((float *)&tmp_pParentUp + 2) = v25 * v28;
        *((float *)&tmp_pParentUp + 3) = v26 * v28;
        VectorRotate(in1: (const float *)v7 + 5, in2: (const matrix3x4_t *)v43, out: (float *)&aimWorldPosition + 1);
        v29 = (float)((float)(*((float *)&aimWorldPosition + 2) * pUp.z)
                    + (float)(*((float *)&aimWorldPosition + 1) * pUp.y))
            + (float)(*((float *)&aimWorldPosition + 3) * v59);
        v30 = *((float *)&aimWorldPosition + 1) - (float)(v29 * pUp.y);
        v31 = *((float *)&aimWorldPosition + 3) - (float)(v59 * v29);
        v32 = *((float *)&aimWorldPosition + 2) - (float)(pUp.z * v29);
        v33 = (float)((float)((float)(v30 * v30) + 0.00000011920929) + (float)(v32 * v32)) + (float)(v31 * v31);
        pUp.x = 1.0 / fsqrt(v33);
        v34 = (float)(3.0 - (float)((float)(pUp.x * v33) * pUp.x)) * (float)(pUp.x * 0.5);
        pUp.y = v30 * v34;
        pUp.z = v32 * v34;
        v59 = v31 * v34;
        v35 = (float)((float)((float)(v32 * v34) * *((float *)&tmp_pParentUp + 2))
                    + (float)((float)(v30 * v34) * *((float *)&tmp_pParentUp + 1)))
            + (float)((float)(v31 * v34) * *((float *)&tmp_pParentUp + 3));
        if ( (float)(1.0 - COERCE_FLOAT(LODWORD(v35) & _mask__AbsFloat_)) <= 0.00000011920929 )
        {
          v36 = 0.0;
          v39 = *((float *)&tmp_pParentUp + 2);
          v38 = *((float *)&tmp_pParentUp + 3);
          v37 = *((float *)&tmp_pParentUp + 1);
        }
        else
        {
          __libm_sse2_acos();
          v36 = v35;
          v37 = (float)(v59 * *((float *)&tmp_pParentUp + 2)) - (float)(pUp.z * *((float *)&tmp_pParentUp + 3));
          v38 = (float)(pUp.z * *((float *)&tmp_pParentUp + 1)) - (float)(*((float *)&tmp_pParentUp + 2) * pUp.y);
          v39 = (float)(*((float *)&tmp_pParentUp + 3) * pUp.y) - (float)(v59 * *((float *)&tmp_pParentUp + 1));
        }
        v40 = (float)((float)((float)(v37 * v37) + 0.00000011920929) + (float)(v39 * v39)) + (float)(v38 * v38);
        v41 = 0;
        *(float *)&v41 = 1.0 / fsqrt(v40);
        tmp_pParentUp = v41;
        v42 = (float)(3.0 - (float)((float)(*(float *)&v41 * v40) * *(float *)&tmp_pParentUp))
            * (float)(*(float *)&tmp_pParentUp * 0.5);
        pParentUp.y = v42 * v37;
        pParentUp.z = v39 * v42;
        v61 = v38 * v42;
        AxisAngleQuaternion(axis: (Vector *)&pParentUp.y, angle: v36 * 57.29578, q: (Quaternion *)&boneRotation.y);
        QuaternionMult(
          p: (Quaternion *)&boneRotation.y,
          q: (Quaternion *)&upRotation.y,
          qt: (Quaternion *)&boneMatrix.m_flMatVal[2][3]);
        QuaternionMatrix(
          q: (const Quaternion *)&boneMatrix.m_flMatVal[2][3],
          pos: (Vector *)&aimAtWorldPosition.y,
          matrix: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1]);
      }
      MatrixCopy(in: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1], out: &bonetoworld->m_pBones[iBone]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F790
// Name: void DoTwistBones(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoTwistBones(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v6; // eax
  int procindex; // esi
  char *v8; // esi
  int v9; // eax
  matrix3x4a_t *m_pBones; // ecx
  int v11; // edi
  const matrix3x4a_t *v12; // edi
  bool v13; // sf
  _DWORD *v14; // eax
  int v15; // edi
  void *v16; // esp
  unsigned int v17; // edi
  void *v18; // esp
  void *v19; // esp
  int v20; // ecx
  Quaternion *v21; // edi
  _QWORD *p_x; // edx
  char *v23; // eax
  double v24; // st7
  char *v25; // edi
  _DWORD v26[4]; // [esp-E0h] [ebp-ECh] BYREF
  matrix3x4a_t v27; // [esp-D0h] [ebp-DCh] BYREF
  matrix3x4a_t v28; // [esp-A0h] [ebp-ACh] BYREF
  matrix3x4_t v29; // [esp-70h] [ebp-7Ch] BYREF
  RadianEuler v30; // [esp-3Ch] [ebp-48h] BYREF
  Quaternion v31; // [esp-30h] [ebp-3Ch] BYREF
  Quaternion *v32; // [esp-14h] [ebp-20h]
  const matrix3x4a_t *v33; // [esp-10h] [ebp-1Ch]
  const float *v34; // [esp-Ch] [ebp-18h]
  const Quaternion *v35; // [esp-8h] [ebp-14h]
  const Quaternion *v36; // [esp-4h] [ebp-10h]
  int i; // [esp+0h] [ebp-Ch]
  void *v38; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  i = a1;
  v38 = retaddr;
  v6 = &pBones[iBone];
  v26[1] = a3;
  procindex = v6->procindex;
  v26[0] = a2;
  if ( procindex != 0 )
  {
    v8 = (char *)v6 + procindex;
    if ( v8 != nullptr )
    {
      v9 = *((_DWORD *)v8 + 4);
      m_pBones = bonetoworld->m_pBones;
      v11 = v9;
      v9 *= 216;
      v12 = &m_pBones[v11];
      v13 = *(int *)((char *)&pBones->parent + v9) < 0;
      v14 = (int *)((char *)&pBones->parent + v9);
      v33 = v12;
      if ( v13 )
      {
        MatrixQuaternion(mat: v12, q: &v31);
      }
      else
      {
        MatrixInvert(in: &m_pBones[*v14], out: &v29);
        ConcatTransforms_Aligned(m0: (const matrix3x4a_t *)&v29, m1: v12, out: &v28);
        MatrixQuaternion(mat: &v28, q: &v31);
      }
      MatrixInvert(in: v12, out: &v29);
      ConcatTransforms_Aligned(
        m0: (const matrix3x4a_t *)&v29,
        m1: &bonetoworld->m_pBones[*((_DWORD *)v8 + 9)],
        out: &v27);
      v15 = *((_DWORD *)v8 + 10);
      v16 = alloca(4 * v15);
      v17 = (16 * v15 + 15) & 0xFFFFFFF0;
      v34 = (const float *)v26;
      v18 = alloca(v17);
      v36 = (const Quaternion *)v26;
      v19 = alloca(v17);
      v20 = 0;
      v21 = (Quaternion *)v26;
      v32 = (Quaternion *)v26;
      if ( *((int *)v8 + 10) > 0 )
      {
        p_x = (_QWORD *)&v36->x;
        v35 = nullptr;
        do
        {
          v23 = (char *)v35 + *((_DWORD *)v8 + 11);
          v24 = *(float *)&v8[(_DWORD)v23 + 4];
          v35 = (const Quaternion *)((char *)v35 + 36);
          v34[v20] = v24;
          *p_x = *(_QWORD *)&v8[(_DWORD)v23 + 20];
          p_x[1] = *(_QWORD *)&v8[(_DWORD)v23 + 28];
          ++v20;
          p_x += 2;
        }
        while ( v20 < *((_DWORD *)v8 + 10) );
        v21 = v32;
      }
      _V_memcpy(dest: v21, src: v36, count: 16 * *((_DWORD *)v8 + 10));
      ComputeTwistBones(
        pqTwists: v21,
        nCount: *((_DWORD *)v8 + 10),
        bInverse: *v8,
        vUp: (const Vector *)(v8 + 4),
        qParent: &v31,
        mChild: &v27,
        qBaseInv: (const Quaternion *)(v8 + 20),
        pflWeights: v34,
        pqTwistBinds: v36);
      v34 = nullptr;
      if ( *((int *)v8 + 10) > 0 )
      {
        v36 = nullptr;
        v35 = v21;
        do
        {
          v25 = (char *)v36 + *((_DWORD *)v8 + 11);
          QuaternionAngles(q: v35, angles: &v30);
          AngleMatrix(angles: &v30, position: (const Vector *)&v8[(_DWORD)v25 + 8], matrix: &v29);
          ConcatTransforms_Aligned(
            m0: v33,
            m1: (const matrix3x4a_t *)&v29,
            out: &bonetoworld->m_pBones[*(_DWORD *)&v8[(_DWORD)v25]]);
          v36 = (const Quaternion *)((char *)v36 + 36);
          ++v35;
          v34 = (const float *)((char *)v34 + 1);
        }
        while ( (int)v34 < *((_DWORD *)v8 + 10) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049F9A0
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x004A0380
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A03C0
// Name: void DoQuatInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoQuatInterpBone(float a1@<ebp>, mstudiobone_t *pbones, int ibone, CBoneAccessor *bonetoworld)
{
  int v4; // edx
  mstudiobone_t *v5; // eax
  int procindex; // esi
  _DWORD *v7; // esi
  int *p_parent; // ecx
  int v9; // edi
  long double v10; // st7
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // ecx
  float v15; // xmm0_4
  const Quaternion *v16; // edi
  matrix3x4a_t *v17; // [esp-24h] [ebp-184h]
  _DWORD v18[3]; // [esp-Ch] [ebp-16Ch]
  float weight[32]; // [esp+0h] [ebp-160h] BYREF
  matrix3x4a_t controlmatrix; // [esp+80h] [ebp-E0h] BYREF
  matrix3x4a_t tmpmatrix; // [esp+B0h] [ebp-B0h] BYREF
  matrix3x4a_t bonematrix; // [esp+E0h] [ebp-80h] BYREF
  Quaternion src; // [esp+110h] [ebp-50h] BYREF
  float v24; // [esp+120h] [ebp-40h]
  float *p_x; // [esp+124h] [ebp-3Ch]
  mstudiobone_t *v26; // [esp+128h] [ebp-38h]
  float s; // [esp+12Ch] [ebp-34h] BYREF
  float v28; // [esp+130h] [ebp-30h]
  float v29; // [esp+134h] [ebp-2Ch]
  Vector pos; // [esp+138h] [ebp-28h] BYREF
  Quaternion quat; // [esp+144h] [ebp-1Ch]
  float dot; // [esp+154h] [ebp-Ch]
  float scale; // [esp+158h] [ebp-8h]
  float retaddr; // [esp+160h] [ebp+0h]

  dot = a1;
  scale = retaddr;
  v4 = ibone;
  v5 = &pbones[ibone];
  procindex = v5->procindex;
  v26 = v5;
  if ( procindex != 0 )
  {
    v7 = (int *)((char *)&v5->sznameindex + procindex);
    if ( v7 != nullptr )
    {
      p_parent = &pbones[*v7].parent;
      if ( *p_parent != -1 )
      {
        v17 = &bonetoworld->m_pBones[*p_parent];
        quat.z = 0.0;
        MatrixInvert(in: v17, out: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1]);
        ConcatTransforms_Aligned(
          m0: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1],
          m1: &bonetoworld->m_pBones[*v7],
          out: (matrix3x4a_t *)&weight[29]);
        MatrixAngles(
          matrix: (const matrix3x4_t *)&weight[29],
          q: (Quaternion *)&bonematrix.m_flMatVal[2][1],
          pos: (Vector *)&s);
        v9 = 0;
        if ( (int)v7[1] <= 0 )
        {
          z = quat.z;
        }
        else
        {
          quat.w = 0.0;
          do
          {
            v10 = fabs(
                    QuaternionDotProduct(
                      p: (const Quaternion *)((char *)v7 + LODWORD(quat.w) + v7[2] + 4),
                      q: (const Quaternion *)&bonematrix.m_flMatVal[2][1]));
            quat.y = v10;
            if ( v10 >= -1.0 )
            {
              y = quat.y;
              if ( quat.y > 1.0 )
                y = 1.0;
            }
            else
            {
              y = -1.0;
            }
            __libm_sse2_acos();
            v12 = 1.0 - (float)((float)(y * 2.0) * *(float *)((char *)v7 + LODWORD(quat.w) + v7[2]));
            *(float *)&v18[v9] = v12;
            if ( v12 < 0.0 )
              v12 = 0.0;
            LODWORD(quat.w) += 48;
            *(float *)&v18[v9] = v12;
            z = v12 + quat.z;
            ++v9;
            quat.z = z;
          }
          while ( v9 < v7[1] );
        }
        if ( z <= 0.001 )
        {
          QuaternionAngles(q: (const Quaternion *)((char *)v7 + v7[2] + 32), angles: (RadianEuler *)&src.y);
          AngleMatrix(
            angles: (const RadianEuler *)&src.y,
            position: (const Vector *)((char *)v7 + v7[2] + 20),
            matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
          ConcatTransforms(
            in1: &bonetoworld->m_pBones[v26->parent],
            in2: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
            out: &bonetoworld->m_pBones[ibone]);
          return;
        }
        v14 = 0.0;
        quat.z = 1.0 / z;
        memset(&pos, 0, sizeof(pos));
        quat.x = 0.0;
        s = 0.0;
        v28 = 0.0;
        v29 = 0.0;
        quat.y = 0.0;
        if ( (int)v7[1] > 0 )
        {
          quat.w = 0.0;
          do
          {
            v15 = *(float *)&v18[LODWORD(v14)];
            if ( v15 != 0.0 )
            {
              v16 = (const Quaternion *)((char *)v7 + LODWORD(quat.w) + v7[2]);
              v24 = v15 * quat.z;
              p_x = &v16[2].x;
              QuaternionAlign(p: v16 + 2, q: (const Quaternion *)&pos, qt: (Quaternion *)&pos);
              pos.x = (float)(*p_x * v24) + pos.x;
              pos.y = (float)(v16[2].y * v24) + pos.y;
              v14 = quat.y;
              pos.z = (float)(v16[2].z * v24) + pos.z;
              quat.x = (float)(v16[2].w * v24) + quat.x;
              s = (float)(v16[1].y * v24) + s;
              v28 = (float)(v16[1].z * v24) + v28;
              v29 = (float)(v16[1].w * v24) + v29;
            }
            LODWORD(quat.w) += 48;
            ++LODWORD(v14);
            quat.y = v14;
          }
          while ( SLODWORD(v14) < v7[1] );
        }
        QuaternionMatrix(
          q: (const Quaternion *)&pos,
          pos: (const Vector *)&s,
          matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
        v5 = v26;
        v4 = ibone;
      }
    }
  }
  ConcatTransforms_Aligned(
    m0: &bonetoworld->m_pBones[v5->parent],
    m1: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
    out: &bonetoworld->m_pBones[v4]);
}

//------------------------------------------------------------------------------
// Address: 0x004A0730
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0820
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x004A0840
// Name: void CalcBoneAdj(class CStudioHdr const __near *,class Vector __near * const,class Quaternion __near * const,float const __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcBoneAdj(
        const CStudioHdr *pStudioHdr,
        Vector *pos,
        Quaternion *q,
        const float *controllers,
        int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  Vector *p_y; // eax
  const Quaternion *v13; // [esp+8h] [ebp-34h]
  Quaternion *v14; // [esp+Ch] [ebp-30h]
  Quaternion q0; // [esp+1Ch] [ebp-20h] BYREF
  RadianEuler a0; // [esp+2Ch] [ebp-10h] BYREF
  int j; // [esp+38h] [ebp-4h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  v6 = 0;
  for ( j = 0; j < m_pStudioHdr->numbonecontrollers; ++j )
  {
    v7 = v6 + m_pStudioHdr->bonecontrollerindex;
    v8 = *(int *)((char *)&m_pStudioHdr->id + v7);
    v9 = (char *)m_pStudioHdr + v7;
    if ( (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v8]) != 0 )
    {
      v10 = controllers[*((_DWORD *)v9 + 5)];
      if ( v10 >= 0.0 )
      {
        if ( v10 > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = 0.0;
      }
      v11 = (float)((float)(1.0 - v10) * *((float *)v9 + 2)) + (float)(*((float *)v9 + 3) * v10);
      switch ( *((_DWORD *)v9 + 1) & 0x3FFFF )
      {
        case 1:
          p_y = &pos[v8];
          goto LABEL_15;
        case 2:
          p_y = (Vector *)&pos[v8].y;
          goto LABEL_15;
        case 4:
          p_y = (Vector *)&pos[v8].z;
LABEL_15:
          p_y->x = p_y->x + v11;
          break;
        case 8:
          a0.x = v11 * 0.0174532925199433;
          a0.y = 0.0;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x10:
          a0.x = 0.0;
          a0.y = v11 * 0.0174532925199433;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x20:
          a0.x = 0.0;
          a0.y = 0.0;
          a0.z = v11 * 0.0174532925199433;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
LABEL_9:
          QuaternionSM(s: 1.0, p: &q0, q: v13, qt: v14);
          break;
        default:
          break;
      }
    }
    m_pStudioHdr = pStudioHdr->m_pStudioHdr;
    v6 += 56;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0A40
// Name: bool CalcProceduralBone(class CStudioHdr const __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CalcProceduralBone@<al>(int a1@<edi>, CStudioHdr *pStudioHdr, int iBone, CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v4; // eax
  bool result; // al
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v4 = (mstudiobone_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->boneindex);
  if ( (pStudioHdr->m_boneFlags.m_Memory.m_pMemory[iBone] & 4) == 0 )
    return false;
  switch ( v4[iBone].proctype )
  {
    case 1:
      DoAxisInterpBone(ebp0: COERCE_FLOAT(&savedregs), pbones: v4, ibone: iBone, bonetoworld);
      goto $LN2_24;
    case 2:
      DoQuatInterpBone(a1: COERCE_FLOAT(&savedregs), pbones: v4, ibone: iBone, bonetoworld);
      return true;
    case 3:
      DoAimAtBone(a1: COERCE_FLOAT(&savedregs), pBones: v4, iBone, bonetoworld, pStudioHdr: nullptr);
      return true;
    case 4:
      DoAimAtBone(a1: COERCE_FLOAT(&savedregs), pBones: v4, iBone, bonetoworld, pStudioHdr);
      return true;
    case 6:
      DoTwistBones(a1: (int)&savedregs, a2: a1, a3: v4[iBone].proctype - 1, pBones: v4, iBone, bonetoworld);
      return true;
    case 7:
$LN2_24:
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A0B00
// Name: public: void IBoneSetup::CalcBoneAdj(class Vector __near * const,class Quaternion __near * const,float const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcBoneAdj(IBoneSetup *this, Vector *pos, Quaternion *q, const float *controllers)
{
  CalcBoneAdj(
    pStudioHdr: this->m_pBoneSetup->m_pStudioHdr,
    pos,
    q,
    controllers,
    boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x004A0B30
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A0E80
// Name: public: void CBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::CalcAutoplaySequences(
        CBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CIKContext *v5; // esi
  int v6; // ebx
  const CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v9; // ecx
  int v10; // esi
  const studiohdr_t *v11; // ecx
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  double v14; // st7
  float v15; // [esp+0h] [ebp-28h]
  int count; // [esp+1Ch] [ebp-Ch]
  float cycle; // [esp+20h] [ebp-8h]
  unsigned __int16 *pList; // [esp+24h] [ebp-4h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v5 = pIKContext;
  v6 = 0;
  if ( pIKContext != nullptr )
    CIKContext::AddAutoplayLocks(this: pIKContext, pos, q);
  m_pStudioHdr = this->m_pStudioHdr;
  pList = nullptr;
  count = studiohdr_t::GetAutoplayList(this: m_pStudioHdr->m_pStudioHdr, pOut: &pList);
  if ( count > 0 )
  {
    do
    {
      v9 = (CStudioHdr *)this->m_pStudioHdr;
      v10 = pList[v6];
      if ( this->m_pStudioHdr->m_pVModel != nullptr )
      {
        v13 = CStudioHdr::pSeqdesc_Internal(this: v9, i: pList[v6]);
      }
      else
      {
        v11 = v9->m_pStudioHdr;
        v12 = pList[v6];
        if ( v10 >= v11->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v11 + 212 * v12 + v11->localseqindex);
      }
      if ( (v13->flags & 8) != 0 )
      {
        v14 = Studio_CPS(
                pStudioHdr: this->m_pStudioHdr,
                seqdesc: v13,
                iSequence: v10,
                poseParameter: this->m_flPoseParameter)
            * flRealTime;
        cycle = v14;
        v15 = v14 - (double)(int)cycle;
        CBoneSetup::AccumulatePose(
          this,
          a2: (int)&savedregs,
          pos,
          q,
          sequence: v10,
          cycle: v15,
          flWeight: 1.0,
          flTime: flRealTime,
          pIKContext);
      }
      ++v6;
    }
    while ( v6 < count );
    v5 = pIKContext;
  }
  if ( v5 != nullptr )
    CIKContext::SolveAutoplayLocks(this: v5, pos, q);
}

//------------------------------------------------------------------------------
// Address: 0x004A0F80
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

//------------------------------------------------------------------------------
// Address: 0x004A0FD0
// Name: public: void IBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcAutoplaySequences(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CBoneSetup::CalcAutoplaySequences(this: this->m_pBoneSetup, pos, q, flRealTime, pIKContext);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1019A1A0
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019A230
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        mstudioseqdesc_t *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int v23; // [esp+4h] [ebp-8h]
  int x3; // [esp+8h] [ebp-4h]
  int *pAnimIndicesa; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      x3 = 1;
      v8 = pWeight;
      v10 = 0;
      v23 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    v23 = 1;
    v8 = pWeight;
    v7 = 0;
    x3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      v23 = 0;
      x3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    v23 = 1;
    x3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pAnimIndicesa = (int *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pAnimIndicesa = (int *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  pAnimIndices->baseptr = *(__int16 *)((char *)&seqdesc->baseptr
                                     + 2 * ((_DWORD)pAnimIndicesa + v14 * seqdesc->groupsize[0])
                                     + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = x3 + i1;
  pAnimIndices->szlabelindex = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + v23;
  if ( i0 + v23 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices->szactivitynameindex = *(__int16 *)((char *)&seqdesc->baseptr
                                                 + 2 * v20
                                                 + 2 * v19 * seqdesc->groupsize[0]
                                                 + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x1019A3E0
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019A5B0
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int i; // [esp+Ch] [ebp-14h]
  int v28; // [esp+10h] [ebp-10h]
  float v29; // [esp+14h] [ebp-Ch]
  float v30; // [esp+1Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  v28 = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( i = 0; ; i += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = i + 24;
      if ( ++v28 >= v9->numautolayers )
        return;
    }
    v29 = cycle;
    v30 = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(this, pos, q, sequence: v26, cycle: v29, flWeight: v30, flTime, pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    v30 = v16;
    if ( (v25 & 0x4000) == 0 )
      v29 = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A7E0
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int v23; // [esp+8h] [ebp-8h]
  float v24; // [esp+Ch] [ebp-4h]
  float layerCycle; // [esp+20h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    v23 = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++v23 >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      v24 = v13;
      layerCycle = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(this, pos, q, sequence: v22, cycle: v24, flWeight: layerCycle, flTime, pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerCycle = v19;
      v24 = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019A9A0
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    operator delete(p: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x1019A9B0
// Name: void DoAxisInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoAxisInterpBone(float a1@<ebp>, mstudiobone_t *pbones, int ibone, CBoneAccessor *bonetoworld)
{
  const Quaternion *procindex; // esi
  matrix3x4a_t *m_pBones; // edx
  int *p_parent; // edi
  float y; // ecx
  matrix3x4a_t *v8; // eax
  float z; // xmm2_4
  float v10; // xmm0_4
  float x; // xmm1_4
  const Quaternion *v12; // edx
  const Quaternion *v13; // eax
  float *p_w; // edi
  const Quaternion *v15; // ecx
  float *p_y; // esi
  float v17; // xmm0_4
  float v18; // xmm0_4
  matrix3x4_t v19; // [esp+18h] [ebp-9Ch] BYREF
  matrix3x4a_t bonematrix; // [esp+48h] [ebp-6Ch] BYREF
  Quaternion tmp; // [esp+78h] [ebp-3Ch] BYREF
  Quaternion v; // [esp+88h] [ebp-2Ch]
  Vector v23; // [esp+98h] [ebp-1Ch] BYREF
  float v24; // [esp+A4h] [ebp-10h]
  Vector control; // [esp+A8h] [ebp-Ch]
  Vector *p1; // [esp+B4h] [ebp+0h]

  control.x = a1;
  LODWORD(control.y) = p1;
  procindex = (const Quaternion *)pbones[ibone].procindex;
  LODWORD(bonematrix.m_flMatVal[2][3]) = &pbones[ibone];
  if ( procindex != nullptr )
    procindex = (const Quaternion *)((char *)&pbones[ibone] + (_DWORD)procindex);
  m_pBones = bonetoworld->m_pBones;
  p_parent = &pbones[LODWORD(procindex->x)].parent;
  y = procindex->y;
  v8 = &m_pBones[LODWORD(procindex->x)];
  if ( *p_parent == -1 )
  {
    x = v8->m_flMatVal[0][LODWORD(y)];
    tmp.x = x;
    v10 = v8->m_flMatVal[1][LODWORD(procindex->y)];
    tmp.y = v10;
    z = v8->m_flMatVal[2][LODWORD(procindex->y)];
    tmp.z = z;
  }
  else
  {
    bonematrix.m_flMatVal[2][0] = v8->m_flMatVal[0][LODWORD(y)];
    bonematrix.m_flMatVal[2][1] = v8->m_flMatVal[1][LODWORD(y)];
    bonematrix.m_flMatVal[2][2] = v8->m_flMatVal[2][LODWORD(y)];
    VectorIRotate(in1: bonematrix.m_flMatVal[2], in2: &m_pBones[*p_parent], out: &tmp.x);
    z = tmp.z;
    v10 = tmp.y;
    x = tmp.x;
  }
  v.z = x;
  v.y = v10;
  v24 = z;
  if ( x < 0.0 )
  {
    x = -x;
    v.z = x;
    v12 = procindex + 6;
    LODWORD(tmp.w) = &procindex[1].y;
  }
  else
  {
    v12 = procindex + 5;
    LODWORD(tmp.w) = &procindex->z;
  }
  if ( v10 < 0.0 )
  {
    v10 = -v10;
    v.y = v10;
    v13 = procindex + 8;
    p_w = &procindex[2].w;
  }
  else
  {
    v13 = procindex + 7;
    p_w = &procindex[2].x;
  }
  if ( z < 0.0 )
  {
    v15 = procindex + 10;
    z = -z;
    v24 = z;
    LODWORD(v.w) = &procindex[10];
    p_y = &procindex[4].y;
  }
  else
  {
    v15 = procindex + 9;
    LODWORD(v.w) = &procindex[9];
    p_y = &procindex[3].z;
  }
  v17 = v10 + x;
  if ( v17 <= 0.0 )
  {
    QuaternionSlerp(p: v15, q: v15, t: 0.0, qt: (Quaternion *)bonematrix.m_flMatVal[1]);
    v23.x = *p_y;
    v23.y = p_y[1];
    v18 = p_y[2];
  }
  else
  {
    v.x = 1.0 / (float)(v17 + z);
    QuaternionSlerp(p: v13, q: v12, t: x / v17, qt: (Quaternion *)&bonematrix);
    v24 = v.x * v24;
    QuaternionSlerp(
      p: (const Quaternion *)&bonematrix,
      q: (const Quaternion *)LODWORD(v.w),
      t: v24,
      qt: (Quaternion *)bonematrix.m_flMatVal[1]);
    v23.x = *(float *)LODWORD(tmp.w) * (float)(v.x * v.z);
    v23.y = *(float *)(LODWORD(tmp.w) + 4) * (float)(v.x * v.z);
    v23.z = *(float *)(LODWORD(tmp.w) + 8) * (float)(v.x * v.z);
    v23.x = (float)((float)(v.x * v.y) * *p_w) + v23.x;
    v23.y = (float)(p_w[1] * (float)(v.x * v.y)) + v23.y;
    v23.z = (float)(p_w[2] * (float)(v.x * v.y)) + v23.z;
    v23.x = (float)(v24 * *p_y) + v23.x;
    v23.y = (float)(p_y[1] * v24) + v23.y;
    v18 = (float)(p_y[2] * v24) + v23.z;
  }
  v23.z = v18;
  QuaternionMatrix(q: (const Quaternion *)bonematrix.m_flMatVal[1], pos: &v23, matrix: &v19);
  ConcatTransforms(
    in1: &bonetoworld->m_pBones[*(_DWORD *)(LODWORD(bonematrix.m_flMatVal[2][3]) + 4)],
    in2: &v19,
    out: &bonetoworld->m_pBones[ibone]);
}

//------------------------------------------------------------------------------
// Address: 0x1019ACA0
// Name: void DoAimAtBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DoAimAtBone(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld,
        CStudioHdr *pStudioHdr)
{
  mstudiobone_t *v7; // esi
  int procindex; // eax
  char *v9; // esi
  const mstudioattachment_t *v10; // eax
  float v11; // xmm3_4
  __int128 v12; // xmm4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  __int128 v22; // xmm6
  float v23; // xmm3_4
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  __int128 v43; // xmm4
  float v44; // xmm5_4
  _BYTE v45[12]; // [esp+4h] [ebp-1E0h]
  matrix3x4a_t v46; // [esp+18h] [ebp-1CCh] BYREF
  matrix3x4a_t boneLocalToWorld; // [esp+48h] [ebp-19Ch] BYREF
  matrix3x4a_t parentSpace; // [esp+78h] [ebp-16Ch] BYREF
  matrix3x4a_t aimRotationMatrix; // [esp+A8h] [ebp-13Ch] BYREF
  matrix3x4a_t bonematrix; // [esp+D8h] [ebp-10Ch] BYREF
  matrix3x4a_t aimAtSpace; // [esp+108h] [ebp-DCh] BYREF
  matrix3x4a_t boneMatrix; // [esp+138h] [ebp-ACh] BYREF
  Quaternion boneRotation; // [esp+170h] [ebp-74h] BYREF
  Quaternion upRotation; // [esp+180h] [ebp-64h] BYREF
  _BYTE aimRotation[40]; // [esp+190h] [ebp-54h] OVERLAPPED BYREF
  float v56; // [esp+1B8h] [ebp-2Ch]
  Vector aimWorldPosition; // [esp+1BCh] [ebp-28h]
  Vector tmp_pParentUp; // [esp+1CCh] [ebp-18h] BYREF
  int v59; // [esp+1D8h] [ebp-Ch]
  int pUp; // [esp+1DCh] [ebp-8h] OVERLAPPED
  int pUp_8; // [esp+1E4h] [ebp+0h]

  v59 = a1;
  pUp = pUp_8;
  *(_DWORD *)&v45[8] = a3;
  v7 = &pBones[iBone];
  *(_DWORD *)&v45[4] = a2;
  procindex = v7->procindex;
  LODWORD(upRotation.z) = v7;
  if ( procindex != 0 )
  {
    v9 = (char *)v7 + procindex;
    if ( v9 != nullptr )
    {
      MatrixCopy(in: &bonetoworld->m_pBones[*(_DWORD *)v9], out: &boneLocalToWorld);
      VectorTransform(in1: (const float *)v9 + 8, in2: &boneLocalToWorld, out: &upRotation.w);
      if ( pStudioHdr != nullptr )
      {
        v10 = CStudioHdr::pAttachment(this: pStudioHdr, i: *((_DWORD *)v9 + 1));
        ConcatTransforms(in1: &bonetoworld->m_pBones[v10->localbone], in2: &v10->local, out: &bonematrix);
      }
      else
      {
        MatrixCopy(in: &bonetoworld->m_pBones[*((_DWORD *)v9 + 1)], out: &bonematrix);
      }
      MatrixGetColumn(in: &bonematrix, column: 3, out: (Vector *)&boneRotation.w);
      QuaternionAngles(q: (const Quaternion *)(LODWORD(upRotation.z) + 44), angles: (RadianEuler *)&aimRotation[12]);
      AngleMatrix(
        angles: (const RadianEuler *)&aimRotation[12],
        position: (const Vector *)(v9 + 32),
        matrix: &aimRotationMatrix);
      ConcatTransforms_Aligned(m0: &bonetoworld->m_pBones[*(_DWORD *)v9], m1: &aimRotationMatrix, out: &v46);
      v11 = (float)((float)((float)((float)(boneRotation.w - upRotation.w) * (float)(boneRotation.w - upRotation.w))
                          + 0.00000011920929)
                  + (float)((float)(upRotation.x - *(float *)aimRotation) * (float)(upRotation.x - *(float *)aimRotation)))
          + (float)((float)(upRotation.y - *(float *)&aimRotation[4]) * (float)(upRotation.y - *(float *)&aimRotation[4]));
      v12 = 0;
      *(float *)&v12 = 1.0 / fsqrt(v11);
      *(_OWORD *)&aimRotation[8] = v12;
      v13 = (float)(3.0 - (float)((float)(*(float *)&aimRotation[8] * v11) * *(float *)&aimRotation[8]))
          * (float)(*(float *)&aimRotation[8] * 0.5);
      v14 = (float)(boneRotation.w - upRotation.w) * v13;
      v15 = (float)(upRotation.y - *(float *)&aimRotation[4]) * v13;
      v16 = (float)(upRotation.x - *(float *)aimRotation) * v13;
      tmp_pParentUp.x = (float)(v15 * *((float *)v9 + 3)) - (float)(v16 * *((float *)v9 + 4));
      v17 = (float)(*((float *)v9 + 4) * v14) - (float)(*((float *)v9 + 2) * v15);
      aimWorldPosition.z = v15;
      tmp_pParentUp.y = v17;
      v18 = *((float *)v9 + 2);
      v19 = *((float *)v9 + 3);
      aimWorldPosition.x = v14;
      aimWorldPosition.y = v16;
      v20 = (float)(v18 * v16) - (float)(v19 * v14);
      v21 = (float)((float)((float)(tmp_pParentUp.x * tmp_pParentUp.x) + 0.00000011920929) + (float)(v17 * v17))
          + (float)(v20 * v20);
      v22 = 0;
      *(float *)&v22 = 1.0 / fsqrt(v21);
      *(_OWORD *)&aimRotation[8] = v22;
      v23 = (float)(3.0 - (float)((float)(*(float *)&aimRotation[8] * v21) * *(float *)&aimRotation[8]))
          * (float)(*(float *)&aimRotation[8] * 0.5);
      tmp_pParentUp.x = tmp_pParentUp.x * v23;
      tmp_pParentUp.y = v17 * v23;
      tmp_pParentUp.z = v20 * v23;
      *(_DWORD *)v45 = &boneMatrix.m_flMatVal[2][2];
      v24 = (float)((float)((float)(v16 * *((float *)v9 + 3)) + (float)(*((float *)v9 + 2) * v14))
                  + (float)(aimWorldPosition.z * *((float *)v9 + 4)));
      __libm_sse2_acos(x: *(long double *)v45);
      *(float *)&v24 = v24;
      AxisAngleQuaternion(axis: &tmp_pParentUp, angle: *(float *)&v24 * 57.29578, q: *(Quaternion **)v45);
      if ( (float)(1.0
                 - COERCE_FLOAT(
                     COERCE_UNSIGNED_INT(
                       (float)((float)(*((float *)v9 + 6) * *((float *)v9 + 3))
                             + (float)(*((float *)v9 + 2) * *((float *)v9 + 5)))
                     + (float)(*((float *)v9 + 7) * *((float *)v9 + 4)))
                   & _mask__AbsFloat_)) <= 0.00000011920929 )
      {
        QuaternionMatrix(
          q: (const Quaternion *)&boneMatrix.m_flMatVal[2][2],
          pos: (const Vector *)&upRotation.w,
          matrix: &aimAtSpace);
      }
      else
      {
        QuaternionMatrix(q: (const Quaternion *)&boneMatrix.m_flMatVal[2][2], matrix: &parentSpace);
        VectorRotate(in1: (const float *)v9 + 5, in2: &parentSpace, out: &boneRotation.x);
        v25 = (float)((float)(boneRotation.y * aimWorldPosition.y) + (float)(boneRotation.x * aimWorldPosition.x))
            + (float)(boneRotation.z * aimWorldPosition.z);
        v26 = boneRotation.x - (float)(v25 * aimWorldPosition.x);
        v27 = boneRotation.y - (float)(aimWorldPosition.y * v25);
        v28 = boneRotation.z - (float)(aimWorldPosition.z * v25);
        v29 = (float)((float)((float)(v26 * v26) + 0.00000011920929) + (float)(v27 * v27)) + (float)(v28 * v28);
        *(float *)&aimRotation[24] = 1.0 / fsqrt(v29);
        v30 = (float)(3.0 - (float)((float)(*(float *)&aimRotation[24] * v29) * *(float *)&aimRotation[24]))
            * (float)(*(float *)&aimRotation[24] * 0.5);
        *(float *)&aimRotation[28] = v26 * v30;
        *(float *)&aimRotation[32] = v27 * v30;
        *(float *)&aimRotation[36] = v28 * v30;
        VectorRotate(in1: (const float *)v9 + 5, in2: &v46, out: (float *)&aimRotation[12]);
        v31 = (float)((float)(*(float *)&aimRotation[16] * aimWorldPosition.y)
                    + (float)(*(float *)&aimRotation[12] * aimWorldPosition.x))
            + (float)(*(float *)&aimRotation[20] * aimWorldPosition.z);
        v32 = *(float *)&aimRotation[12] - (float)(v31 * aimWorldPosition.x);
        v33 = *(float *)&aimRotation[20] - (float)(aimWorldPosition.z * v31);
        v34 = *(float *)&aimRotation[16] - (float)(aimWorldPosition.y * v31);
        v35 = (float)((float)((float)(v32 * v32) + 0.00000011920929) + (float)(v34 * v34)) + (float)(v33 * v33);
        v56 = 1.0 / fsqrt(v35);
        v36 = (float)(3.0 - (float)((float)(v56 * v35) * v56)) * (float)(v56 * 0.5);
        aimWorldPosition.x = v32 * v36;
        aimWorldPosition.y = v34 * v36;
        aimWorldPosition.z = v33 * v36;
        v37 = (float)((float)((float)(v34 * v36) * *(float *)&aimRotation[32])
                    + (float)((float)(v32 * v36) * *(float *)&aimRotation[28]))
            + (float)((float)(v33 * v36) * *(float *)&aimRotation[36]);
        if ( (float)(1.0 - COERCE_FLOAT(LODWORD(v37) & _mask__AbsFloat_)) <= 0.00000011920929 )
        {
          v38 = 0.0;
          v41 = *(float *)&aimRotation[32];
          v40 = *(float *)&aimRotation[36];
          v39 = *(float *)&aimRotation[28];
        }
        else
        {
          __libm_sse2_acos(x: *(long double *)&v45[4]);
          v38 = v37;
          v39 = (float)(aimWorldPosition.z * *(float *)&aimRotation[32])
              - (float)(aimWorldPosition.y * *(float *)&aimRotation[36]);
          v40 = (float)(aimWorldPosition.y * *(float *)&aimRotation[28])
              - (float)(*(float *)&aimRotation[32] * aimWorldPosition.x);
          v41 = (float)(*(float *)&aimRotation[36] * aimWorldPosition.x)
              - (float)(aimWorldPosition.z * *(float *)&aimRotation[28]);
        }
        v42 = (float)((float)((float)(v39 * v39) + 0.00000011920929) + (float)(v41 * v41)) + (float)(v40 * v40);
        v43 = 0;
        *(float *)&v43 = 1.0 / fsqrt(v42);
        *(_OWORD *)&aimRotation[24] = v43;
        v44 = (float)(3.0 - (float)((float)(*(float *)&v43 * v42) * *(float *)&aimRotation[24]))
            * (float)(*(float *)&aimRotation[24] * 0.5);
        tmp_pParentUp.x = v44 * v39;
        tmp_pParentUp.y = v41 * v44;
        tmp_pParentUp.z = v40 * v44;
        AxisAngleQuaternion(axis: &tmp_pParentUp, angle: v38 * 57.29578, q: (Quaternion *)&boneMatrix.m_flMatVal[1][2]);
        QuaternionMult(
          p: (const Quaternion *)&boneMatrix.m_flMatVal[1][2],
          q: (const Quaternion *)&boneMatrix.m_flMatVal[2][2],
          qt: (Quaternion *)&boneMatrix.m_flMatVal[0][2]);
        QuaternionMatrix(
          q: (const Quaternion *)&boneMatrix.m_flMatVal[0][2],
          pos: (const Vector *)&upRotation.w,
          matrix: &aimAtSpace);
      }
      MatrixCopy(in: &aimAtSpace, out: &bonetoworld->m_pBones[iBone]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B350
// Name: void DoTwistBones(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoTwistBones(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v6; // eax
  int procindex; // esi
  char *v8; // esi
  int v9; // eax
  matrix3x4a_t *m_pBones; // ecx
  int v11; // edi
  const matrix3x4a_t *v12; // edi
  bool v13; // sf
  _DWORD *v14; // eax
  int v15; // edi
  void *v16; // esp
  unsigned int v17; // edi
  void *v18; // esp
  void *v19; // esp
  int v20; // ecx
  Quaternion *v21; // edi
  _QWORD *p_x; // edx
  char *v23; // eax
  double v24; // st7
  char *v25; // edi
  _DWORD v26[4]; // [esp-E0h] [ebp-ECh] BYREF
  matrix3x4a_t v27; // [esp-D0h] [ebp-DCh] BYREF
  matrix3x4a_t v28; // [esp-A0h] [ebp-ACh] BYREF
  matrix3x4_t v29; // [esp-70h] [ebp-7Ch] BYREF
  RadianEuler v30; // [esp-3Ch] [ebp-48h] BYREF
  Quaternion v31; // [esp-30h] [ebp-3Ch] BYREF
  Quaternion *v32; // [esp-14h] [ebp-20h]
  const matrix3x4a_t *v33; // [esp-10h] [ebp-1Ch]
  const float *v34; // [esp-Ch] [ebp-18h]
  const Quaternion *v35; // [esp-8h] [ebp-14h]
  const Quaternion *v36; // [esp-4h] [ebp-10h]
  int i; // [esp+0h] [ebp-Ch]
  void *v38; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  i = a1;
  v38 = retaddr;
  v6 = &pBones[iBone];
  v26[1] = a3;
  procindex = v6->procindex;
  v26[0] = a2;
  if ( procindex != 0 )
  {
    v8 = (char *)v6 + procindex;
    if ( v8 != nullptr )
    {
      v9 = *((_DWORD *)v8 + 4);
      m_pBones = bonetoworld->m_pBones;
      v11 = v9;
      v9 *= 216;
      v12 = &m_pBones[v11];
      v13 = *(int *)((char *)&pBones->parent + v9) < 0;
      v14 = (int *)((char *)&pBones->parent + v9);
      v33 = v12;
      if ( v13 )
      {
        MatrixQuaternion(mat: v12, q: &v31);
      }
      else
      {
        MatrixInvert(in: &m_pBones[*v14], out: &v29);
        ConcatTransforms_Aligned(m0: (const matrix3x4a_t *)&v29, m1: v12, out: &v28);
        MatrixQuaternion(mat: &v28, q: &v31);
      }
      MatrixInvert(in: v12, out: &v29);
      ConcatTransforms_Aligned(
        m0: (const matrix3x4a_t *)&v29,
        m1: &bonetoworld->m_pBones[*((_DWORD *)v8 + 9)],
        out: &v27);
      v15 = *((_DWORD *)v8 + 10);
      v16 = alloca(4 * v15);
      v17 = (16 * v15 + 15) & 0xFFFFFFF0;
      v34 = (const float *)v26;
      v18 = alloca(v17);
      v36 = (const Quaternion *)v26;
      v19 = alloca(v17);
      v20 = 0;
      v21 = (Quaternion *)v26;
      v32 = (Quaternion *)v26;
      if ( *((int *)v8 + 10) > 0 )
      {
        p_x = (_QWORD *)&v36->x;
        v35 = nullptr;
        do
        {
          v23 = (char *)v35 + *((_DWORD *)v8 + 11);
          v24 = *(float *)&v8[(_DWORD)v23 + 4];
          v35 = (const Quaternion *)((char *)v35 + 36);
          v34[v20] = v24;
          *p_x = *(_QWORD *)&v8[(_DWORD)v23 + 20];
          p_x[1] = *(_QWORD *)&v8[(_DWORD)v23 + 28];
          ++v20;
          p_x += 2;
        }
        while ( v20 < *((_DWORD *)v8 + 10) );
        v21 = v32;
      }
      _V_memcpy(dest: v21, src: v36, count: 16 * *((_DWORD *)v8 + 10));
      ComputeTwistBones(
        pqTwists: v21,
        nCount: *((_DWORD *)v8 + 10),
        bInverse: *v8,
        vUp: (const Vector *)(v8 + 4),
        qParent: &v31,
        mChild: &v27,
        qBaseInv: (const Quaternion *)(v8 + 20),
        pflWeights: v34,
        pqTwistBinds: v36);
      v34 = nullptr;
      if ( *((int *)v8 + 10) > 0 )
      {
        v36 = nullptr;
        v35 = v21;
        do
        {
          v25 = (char *)v36 + *((_DWORD *)v8 + 11);
          QuaternionAngles(q: v35, angles: &v30);
          AngleMatrix(angles: &v30, position: (const Vector *)&v8[(_DWORD)v25 + 8], matrix: &v29);
          ConcatTransforms_Aligned(
            m0: v33,
            m1: (const matrix3x4a_t *)&v29,
            out: &bonetoworld->m_pBones[*(_DWORD *)&v8[(_DWORD)v25]]);
          v36 = (const Quaternion *)((char *)v36 + 36);
          ++v35;
          v34 = (const float *)((char *)v34 + 1);
        }
        while ( (int)v34 < *((_DWORD *)v8 + 10) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B560
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        Quaternion *sequence,
        float cycle,
        const float *poseParameter,
        Vector *boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  Quaternion *NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  Quaternion *v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  Quaternion *v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float v45; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+8h] [ebp-4Ch]
  Vector *v54; // [esp+10h] [ebp-44h]
  int pAnimIndices[2]; // [esp+20h] [ebp-34h] BYREF
  int animation; // [esp+28h] [ebp-2Ch]
  float pWeight; // [esp+2Ch] [ebp-28h] BYREF
  float s; // [esp+30h] [ebp-24h]
  float v59; // [esp+34h] [ebp-20h]
  Quaternion *v60; // [esp+38h] [ebp-1Ch]
  Vector *v61; // [esp+3Ch] [ebp-18h]
  float flSetting; // [esp+40h] [ebp-14h] BYREF
  int iAnimIndices[3]; // [esp+44h] [ebp-10h] BYREF
  __int16 weight_3; // [esp+53h] [ebp-1h] OVERLAPPED BYREF
  int v65; // [esp+5Ch] [ebp+8h]
  int s0; // [esp+68h] [ebp+14h]
  int s0a; // [esp+68h] [ebp+14h]
  Quaternion *v68; // [esp+6Ch] [ebp+18h]
  Quaternion *v69; // [esp+6Ch] [ebp+18h]
  Quaternion *v70; // [esp+6Ch] [ebp+18h]
  Quaternion *v71; // [esp+6Ch] [ebp+18h]
  Quaternion *v72; // [esp+6Ch] [ebp+18h]
  float pos2; // [esp+70h] [ebp+1Ch]

  LOBYTE(weight_3) = 1;
  iAnimIndices[2] = (int)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( iAnimIndices[2] == 0 )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      iAnimIndices[2] = ((unsigned int)v9 + 19) & 0xFFFFFFF0;
    }
    else
    {
      iAnimIndices[2] = 0;
    }
    if ( (iAnimIndices[2] & 0xF) != 0 )
      __debugbreak();
  }
  iAnimIndices[1] = (int)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( iAnimIndices[1] == 0 )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      iAnimIndices[1] = ((unsigned int)v10 + 19) & 0xFFFFFFF0;
    }
    else
    {
      iAnimIndices[1] = 0;
    }
    if ( (iAnimIndices[1] & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v61 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v60 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v60 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v60 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v60 = nullptr;
    }
    if ( ((unsigned __int8)v60 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = (Quaternion *)CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = (Quaternion *)pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = (int)sequence;
  if ( (int)sequence >= (int)NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  iAnimIndices[0] = 0;
  flSetting = 0.0;
  v65 = Studio_LocalPoseParameter(
          pStudioHdr,
          poseParameter,
          seqdesc,
          iSequence: v15,
          iLocalIndex: 0,
          flSetting: (float *)iAnimIndices);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, &flSetting);
  flags = seqdesc->flags;
  v68 = (Quaternion *)v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = (int)v68;
    pos2 = v20;
    cycle = v20 - (double)(int)pos2;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = (int)v68;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( *(float *)iAnimIndices >= 0.001 )
  {
    if ( *(float *)iAnimIndices > 0.999 )
    {
      if ( flSetting < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: v65 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: (int)v68);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, (int)boneMask);
          goto LABEL_99;
        }
        goto LABEL_53;
      }
      if ( flSetting > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, (int)boneMask);
        goto LABEL_99;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, (int)boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: (int)&v68->x + 1);
      CalcAnimation(
        pStudioHdr,
        pos: (Vector *)iAnimIndices[2],
        q: (Quaternion *)iAnimIndices[1],
        seqdesc,
        sequence: v15,
        animation: v40,
        cycle,
        (int)boneMask);
      v35 = flSetting;
      v36 = (const QuaternionAligned *)iAnimIndices[1];
      v54 = boneMask;
      v37 = (Vector *)iAnimIndices[2];
LABEL_98:
      BlendBones(
        a1: COERCE_FLOAT((__int16 *)((char *)&weight_3 + 1)),
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: v37,
        s: v35,
        boneMask: (int)v54);
      goto LABEL_99;
    }
    if ( flSetting >= 0.001 )
    {
      if ( flSetting > 0.999 )
      {
        v71 = (Quaternion *)(v18 + 1);
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: v65, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, (int)boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: (int)v71);
        CalcAnimation(
          pStudioHdr,
          pos: (Vector *)iAnimIndices[2],
          q: (Quaternion *)iAnimIndices[1],
          seqdesc,
          sequence: v15,
          animation: v47,
          cycle,
          (int)boneMask);
        BlendBones(
          a1: COERCE_FLOAT((__int16 *)((char *)&weight_3 + 1)),
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)iAnimIndices[1],
          pos2: (Vector *)iAnimIndices[2],
          s: *(float *)iAnimIndices,
          (int)boneMask);
        goto LABEL_99;
      }
      if ( anim_3wayblend.m_pParent == nullptr || anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: v65, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, (int)boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: (int)v68);
        CalcAnimation(
          pStudioHdr,
          pos: (Vector *)iAnimIndices[2],
          q: (Quaternion *)iAnimIndices[1],
          seqdesc,
          sequence: v15,
          animation: v49,
          cycle,
          (int)boneMask);
        BlendBones(
          a1: COERCE_FLOAT((__int16 *)((char *)&weight_3 + 1)),
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)iAnimIndices[1],
          pos2: (Vector *)iAnimIndices[2],
          s: *(float *)iAnimIndices,
          (int)boneMask);
        v72 = (Quaternion *)((char *)&v68->x + 1);
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: v65, y: (int)v72);
        CalcAnimation(
          pStudioHdr,
          pos: (Vector *)iAnimIndices[2],
          q: (Quaternion *)iAnimIndices[1],
          seqdesc,
          sequence: v15,
          animation: v50,
          cycle,
          (int)boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: v65 + 1, y: (int)v72);
        CalcAnimation(pStudioHdr, pos: v61, q: v60, seqdesc, sequence: v15, animation: v51, cycle, (int)boneMask);
        BlendBones(
          a1: COERCE_FLOAT((__int16 *)((char *)&weight_3 + 1)),
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)iAnimIndices[1],
          pos1: (Vector *)iAnimIndices[2],
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v60,
          pos2: v61,
          s: *(float *)iAnimIndices,
          (int)boneMask);
LABEL_75:
        v35 = flSetting;
        v36 = (const QuaternionAligned *)iAnimIndices[1];
        v54 = boneMask;
        v37 = (Vector *)iAnimIndices[2];
        goto LABEL_98;
      }
      Calc3WayBlendIndices(
        i0: v65,
        i1: v18,
        s0: *(float *)iAnimIndices,
        s1: flSetting,
        seqdesc,
        (mstudioseqdesc_t *)pAnimIndices,
        &pWeight);
      if ( s >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: pAnimIndices[0], cycle: v21, (int)boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: (Vector *)iAnimIndices[2],
          q: (Quaternion *)iAnimIndices[1],
          seqdesc,
          sequence: v15,
          animation: pAnimIndices[1],
          cycle,
          (int)boneMask);
        BlendBones(
          a1: COERCE_FLOAT((__int16 *)((char *)&weight_3 + 1)),
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)iAnimIndices[1],
          pos2: (Vector *)iAnimIndices[2],
          s: s / (float)(pWeight + s),
          (int)boneMask);
        CalcAnimation(pStudioHdr, pos: v61, q: v60, seqdesc, sequence: v15, animation, cycle, (int)boneMask);
        v35 = v59;
        v36 = (const QuaternionAligned *)v60;
        v54 = boneMask;
        v37 = v61;
        goto LABEL_98;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: pAnimIndices[0], cycle: v21, (int)boneMask);
      CalcAnimation(
        pStudioHdr,
        pos: (Vector *)iAnimIndices[2],
        q: (Quaternion *)iAnimIndices[1],
        seqdesc,
        sequence: v15,
        animation,
        cycle,
        (int)boneMask);
      v45 = v59 / (float)(pWeight + v59);
    }
    else
    {
      s0a = v65 + 1;
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: v65 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: v65, y: (int)v68);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, (int)boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - *(float *)iAnimIndices, boneMask);
        goto LABEL_99;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: v65, i1: (int)v68) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: s0a, y: (int)v68);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, (int)boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: *(float *)iAnimIndices, boneMask);
        goto LABEL_99;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: v65, y: (int)v68);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, (int)boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: s0a, y: (int)v68);
      CalcAnimation(
        pStudioHdr,
        pos: (Vector *)iAnimIndices[2],
        q: (Quaternion *)iAnimIndices[1],
        seqdesc,
        sequence: v15,
        animation: v44,
        cycle,
        (int)boneMask);
      v45 = *(float *)iAnimIndices;
    }
    BlendBones(
      a1: COERCE_FLOAT((__int16 *)((char *)&weight_3 + 1)),
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)iAnimIndices[1],
      pos2: (Vector *)iAnimIndices[2],
      s: v45,
      (int)boneMask);
    goto LABEL_99;
  }
  if ( flSetting >= 0.001 )
  {
    if ( flSetting > 0.999 )
    {
      v69 = (Quaternion *)v65;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( v65 >= v26 )
        v69 = (Quaternion *)(v26 - 1);
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * ((_DWORD)v69 + v26 * v27) + seqdesc->animindexindex),
        cycle: v21,
        (int)boneMask);
      goto LABEL_99;
    }
    v29 = seqdesc->groupsize[0];
    s0 = v65;
    if ( v65 >= v29 )
      s0 = v29 - 1;
    v30 = seqdesc->groupsize[1];
    if ( (int)v68 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * s0 + 2 * seqdesc->groupsize[0] * v18 + seqdesc->animindexindex),
      cycle: v21,
      (int)boneMask);
    v31 = v68;
    v70 = (Quaternion *)v65;
    v32 = seqdesc->groupsize[0];
    v33 = (int)&v31->x + 1;
    if ( v65 >= v32 )
      v70 = (Quaternion *)(v32 - 1);
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: (Vector *)iAnimIndices[2],
      q: (Quaternion *)iAnimIndices[1],
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * ((_DWORD)v70 + v32 * v33) + seqdesc->animindexindex),
      cycle,
      (int)boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: v65, i1: v18) )
  {
LABEL_53:
    LOBYTE(weight_3) = 0;
    goto LABEL_99;
  }
  v23 = seqdesc->groupsize[0];
  v24 = v68;
  if ( v65 >= v23 )
    v65 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( (int)v68 >= v25 )
    v24 = (Quaternion *)(v25 - 1);
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * v65 + 2 * seqdesc->groupsize[0] * (_DWORD)v24 + seqdesc->animindexindex),
    cycle,
    (int)boneMask);
LABEL_99:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)iAnimIndices[2]);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)iAnimIndices[1]);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v60);
  return weight_3;
}

//------------------------------------------------------------------------------
// Address: 0x1019BF40
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019BF80
// Name: void DoQuatInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoQuatInterpBone(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pbones,
        int ibone,
        CBoneAccessor *bonetoworld)
{
  int v6; // edx
  mstudiobone_t *v7; // eax
  int procindex; // esi
  _DWORD *v9; // esi
  int *p_parent; // ecx
  int v11; // edi
  long double v12; // st7
  float y; // xmm0_4
  float v14; // xmm0_4
  float z; // xmm0_4
  float v16; // ecx
  float v17; // xmm0_4
  const Quaternion *v18; // edi
  matrix3x4a_t *v19; // [esp-24h] [ebp-184h]
  long double v20; // [esp-1Ch] [ebp-17Ch]
  _DWORD v21[3]; // [esp-Ch] [ebp-16Ch]
  float weight[32]; // [esp+0h] [ebp-160h] BYREF
  matrix3x4a_t controlmatrix; // [esp+80h] [ebp-E0h] BYREF
  matrix3x4a_t tmpmatrix; // [esp+B0h] [ebp-B0h] BYREF
  matrix3x4a_t bonematrix; // [esp+E0h] [ebp-80h] BYREF
  Quaternion src; // [esp+110h] [ebp-50h] BYREF
  float v27; // [esp+120h] [ebp-40h]
  float *p_x; // [esp+124h] [ebp-3Ch]
  mstudiobone_t *v29; // [esp+128h] [ebp-38h]
  float s; // [esp+12Ch] [ebp-34h] BYREF
  float v31; // [esp+130h] [ebp-30h]
  float v32; // [esp+134h] [ebp-2Ch]
  Vector pos; // [esp+138h] [ebp-28h] BYREF
  Quaternion quat; // [esp+144h] [ebp-1Ch]
  float dot; // [esp+154h] [ebp-Ch]
  float scale; // [esp+158h] [ebp-8h]
  float retaddr; // [esp+160h] [ebp+0h]

  dot = a1;
  scale = retaddr;
  v6 = ibone;
  v7 = &pbones[ibone];
  HIDWORD(v20) = a3;
  procindex = v7->procindex;
  LODWORD(v20) = a2;
  v29 = v7;
  if ( procindex != 0 )
  {
    v9 = (int *)((char *)&v7->sznameindex + procindex);
    if ( v9 != nullptr )
    {
      p_parent = &pbones[*v9].parent;
      if ( *p_parent != -1 )
      {
        v19 = &bonetoworld->m_pBones[*p_parent];
        quat.z = 0.0;
        MatrixInvert(in: v19, out: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1]);
        ConcatTransforms_Aligned(
          m0: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1],
          m1: &bonetoworld->m_pBones[*v9],
          out: (matrix3x4a_t *)&weight[29]);
        MatrixAngles(
          matrix: (const matrix3x4_t *)&weight[29],
          q: (Quaternion *)&bonematrix.m_flMatVal[2][1],
          pos: (Vector *)&s);
        v11 = 0;
        if ( (int)v9[1] <= 0 )
        {
          z = quat.z;
        }
        else
        {
          quat.w = 0.0;
          do
          {
            v12 = fabs(
                    QuaternionDotProduct(
                      p: (const Quaternion *)((char *)v9 + LODWORD(quat.w) + v9[2] + 4),
                      q: (const Quaternion *)&bonematrix.m_flMatVal[2][1]));
            quat.y = v12;
            if ( v12 >= -1.0 )
            {
              y = quat.y;
              if ( quat.y > 1.0 )
                y = 1.0;
            }
            else
            {
              y = -1.0;
            }
            __libm_sse2_acos(x: v20);
            v14 = 1.0 - (float)((float)(y * 2.0) * *(float *)((char *)v9 + LODWORD(quat.w) + v9[2]));
            *(float *)&v21[v11] = v14;
            if ( v14 < 0.0 )
              v14 = 0.0;
            LODWORD(quat.w) += 48;
            *(float *)&v21[v11] = v14;
            z = v14 + quat.z;
            ++v11;
            quat.z = z;
          }
          while ( v11 < v9[1] );
        }
        if ( z <= 0.001 )
        {
          QuaternionAngles(q: (const Quaternion *)((char *)v9 + v9[2] + 32), angles: (RadianEuler *)&src.y);
          AngleMatrix(
            angles: (const RadianEuler *)&src.y,
            position: (const Vector *)((char *)v9 + v9[2] + 20),
            matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
          ConcatTransforms(
            in1: &bonetoworld->m_pBones[v29->parent],
            in2: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
            out: &bonetoworld->m_pBones[ibone]);
          return;
        }
        v16 = 0.0;
        quat.z = 1.0 / z;
        memset(&pos, 0, sizeof(pos));
        quat.x = 0.0;
        s = 0.0;
        v31 = 0.0;
        v32 = 0.0;
        quat.y = 0.0;
        if ( (int)v9[1] > 0 )
        {
          quat.w = 0.0;
          do
          {
            v17 = *(float *)&v21[LODWORD(v16)];
            if ( v17 != 0.0 )
            {
              v18 = (const Quaternion *)((char *)v9 + LODWORD(quat.w) + v9[2]);
              v27 = v17 * quat.z;
              p_x = &v18[2].x;
              QuaternionAlign(p: v18 + 2, q: (const Quaternion *)&pos, qt: (Quaternion *)&pos);
              pos.x = (float)(*p_x * v27) + pos.x;
              pos.y = (float)(v18[2].y * v27) + pos.y;
              v16 = quat.y;
              pos.z = (float)(v18[2].z * v27) + pos.z;
              quat.x = (float)(v18[2].w * v27) + quat.x;
              s = (float)(v18[1].y * v27) + s;
              v31 = (float)(v18[1].z * v27) + v31;
              v32 = (float)(v18[1].w * v27) + v32;
            }
            LODWORD(quat.w) += 48;
            ++LODWORD(v16);
            quat.y = v16;
          }
          while ( SLODWORD(v16) < v9[1] );
        }
        QuaternionMatrix(
          q: (const Quaternion *)&pos,
          pos: (const Vector *)&s,
          matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
        v7 = v29;
        v6 = ibone;
      }
    }
  }
  ConcatTransforms_Aligned(
    m0: &bonetoworld->m_pBones[v7->parent],
    m1: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
    out: &bonetoworld->m_pBones[v6]);
}

//------------------------------------------------------------------------------
// Address: 0x1019C2F0
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C3E0
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x1019C400
// Name: bool CalcProceduralBone(class CStudioHdr const __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CalcProceduralBone@<al>(int a1@<edi>, CStudioHdr *pStudioHdr, int iBone, CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v4; // eax
  int v5; // esi
  bool result; // al
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v4 = (mstudiobone_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->boneindex);
  if ( (pStudioHdr->m_boneFlags.m_Memory.m_pMemory[iBone] & 4) == 0 )
    return false;
  v5 = v4[iBone].proctype - 1;
  switch ( v4[iBone].proctype )
  {
    case 1:
      DoAxisInterpBone(a1: COERCE_FLOAT(&savedregs), pbones: v4, ibone: iBone, bonetoworld);
      goto $LN2_40;
    case 2:
      DoQuatInterpBone(a1: COERCE_FLOAT(&savedregs), a2: a1, a3: v5, pbones: v4, ibone: iBone, bonetoworld);
      return true;
    case 3:
      DoAimAtBone(a1: (int)&savedregs, a2: a1, a3: v5, pBones: v4, iBone, bonetoworld, pStudioHdr: nullptr);
      return true;
    case 4:
      DoAimAtBone(a1: (int)&savedregs, a2: a1, a3: v5, pBones: v4, iBone, bonetoworld, pStudioHdr);
      return true;
    case 6:
      DoTwistBones(a1: (int)&savedregs, a2: a1, a3: v5, pBones: v4, iBone, bonetoworld);
      return true;
    case 7:
$LN2_40:
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C4C0
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        Quaternion *sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  long double v10; // rdi
  Quaternion *v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *v14; // ecx
  CIKContext *v15; // ecx
  __int64 v16; // [esp+Ch] [ebp-10A4h]
  CIKContext v17; // [esp+24h] [ebp-108Ch] BYREF
  float v18; // [esp+1098h] [ebp-18h]
  Vector *v19; // [esp+109Ch] [ebp-14h]
  QuaternionAligned *v20; // [esp+10A0h] [ebp-10h]
  _DWORD v21[3]; // [esp+10A4h] [ebp-Ch] BYREF
  int vars0; // [esp+10B0h] [ebp+0h]

  v21[0] = a2;
  v21[1] = vars0;
  v9 = alloca(4232);
  HIDWORD(v10) = this;
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v18 = flWeight;
    else
      v18 = 1.0;
  }
  else
  {
    v18 = 0.0;
  }
  v11 = sequence;
  if ( (int)sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( *(_DWORD *)(HIDWORD(v10) + 12) != 0 )
      (*(void (__stdcall **)(_DWORD, CIKContext *, Vector *, QuaternionAligned *, Quaternion *, _DWORD, _DWORD, _DWORD, float, _DWORD))(**(_DWORD **)(HIDWORD(v10) + 12) + 4))(
        a1: *(_DWORD *)HIDWORD(v10),
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: *(_DWORD *)(HIDWORD(v10) + 8),
        a8: *(_DWORD *)(HIDWORD(v10) + 4),
        a9: COERCE_FLOAT(LODWORD(v18)),
        a10: LODWORD(flTime));
    v14 = *(CStudioHdr **)HIDWORD(v10);
    if ( *(_DWORD *)(*(_DWORD *)HIDWORD(v10) + 4) != 0 )
    {
      LODWORD(v10) = CStudioHdr::pSeqdesc_Internal(this: v14, i: (int)sequence);
    }
    else
    {
      if ( (int)sequence >= v14->m_pStudioHdr->numlocalseq )
        v11 = nullptr;
      LODWORD(v10) = (char *)v14->m_pStudioHdr + 212 * (_DWORD)v11 + v14->m_pStudioHdr->localseqindex;
    }
    CIKContext::CIKContext(this: &v17);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    }
    if ( (*(_DWORD *)(LODWORD(v10) + 12) & 0x200) != 0 )
      InitPose(
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        pos: v19,
        q: v20,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
    if ( CalcPoseSingle(
           pStudioHdr: *(CStudioHdr **)HIDWORD(v10),
           pos: v19,
           q: v20,
           seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
           sequence,
           cycle,
           poseParameter: *(const float **)(HIDWORD(v10) + 8),
           boneMask: *(Vector **)(HIDWORD(v10) + 4),
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this: (CBoneSetup *)HIDWORD(v10),
        pos: v19,
        q: v20,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        (int)sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(v16) = *(_DWORD *)(HIDWORD(v10) + 4);
      *(float *)&v16 = v18;
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: v10,
        pStudioHdr: *(const virtualgroup_t **)HIDWORD(v10),
        q1: q,
        pos1: pos,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        (int)sequence,
        q2: v20,
        pos2: v19,
        s: v16);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v15 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        iSequence: (int)sequence,
        flCycle: cycle,
        poseParameters: *(const float **)(HIDWORD(v10) + 8),
        flWeight: v18);
      v15 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(
      this: (CBoneSetup *)HIDWORD(v10),
      pos,
      q,
      seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
      (int)sequence,
      cycle,
      flWeight: v18,
      flTime,
      pIKContext: v15);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C810
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        Quaternion *sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  float var10; // [esp+0h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&var10,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00435330
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004353C0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x00435570
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00435740
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435970
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00435B30
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x00435B40
// Name: void DoAxisInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoAxisInterpBone(float ebp0@<ebp>, mstudiobone_t *pbones, int ibone, CBoneAccessor *bonetoworld)
{
  int procindex; // esi
  matrix3x4a_t *m_pBones; // edx
  int *p_parent; // edi
  int v7; // ecx
  matrix3x4a_t *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  const Quaternion *v12; // edx
  const Quaternion *v13; // eax
  float *v14; // edi
  const Quaternion *v15; // ecx
  float *v16; // esi
  float v17; // xmm0_4
  float v18; // xmm0_4
  _BYTE v19[12]; // [esp+18h] [ebp-9Ch] BYREF
  matrix3x4a_t bonematrix; // [esp+24h] [ebp-90h] BYREF
  Quaternion tmp; // [esp+54h] [ebp-60h] BYREF
  Quaternion v; // [esp+64h] [ebp-50h] BYREF
  mstudiobone_t *v23; // [esp+74h] [ebp-40h]
  float v24; // [esp+78h] [ebp-3Ch] BYREF
  float v25; // [esp+7Ch] [ebp-38h]
  float v26; // [esp+80h] [ebp-34h]
  Vector control; // [esp+84h] [ebp-30h]
  Vector *p1; // [esp+90h] [ebp-24h]
  const Quaternion *t; // [esp+94h] [ebp-20h]
  float a2; // [esp+98h] [ebp-1Ch] BYREF
  float a1; // [esp+9Ch] [ebp-18h]
  Quaternion *q3; // [esp+A0h] [ebp-14h]
  Vector p; // [esp+A4h] [ebp-10h]
  float retaddr; // [esp+B4h] [ebp+0h]

  p.y = ebp0;
  p.z = retaddr;
  procindex = pbones[ibone].procindex;
  v23 = &pbones[ibone];
  if ( procindex != 0 )
    procindex += (int)&pbones[ibone];
  m_pBones = bonetoworld->m_pBones;
  p_parent = &pbones[*(_DWORD *)procindex].parent;
  v7 = *(_DWORD *)(procindex + 4);
  v8 = &m_pBones[*(_DWORD *)procindex];
  if ( *p_parent == -1 )
  {
    v11 = v8->m_flMatVal[0][v7];
    v24 = v11;
    v10 = v8->m_flMatVal[1][*(_DWORD *)(procindex + 4)];
    v25 = v10;
    v9 = v8->m_flMatVal[2][*(_DWORD *)(procindex + 4)];
    v26 = v9;
  }
  else
  {
    v.y = v8->m_flMatVal[0][v7];
    v.z = v8->m_flMatVal[1][v7];
    v.w = v8->m_flMatVal[2][v7];
    VectorIRotate(in1: &v.y, in2: &m_pBones[*p_parent], out: &v24);
    v9 = v26;
    v10 = v25;
    v11 = v24;
  }
  *(float *)&p1 = v11;
  control.z = v10;
  p.x = v9;
  if ( v11 < 0.0 )
  {
    v11 = -v11;
    *(float *)&p1 = v11;
    v12 = (const Quaternion *)(procindex + 96);
    LODWORD(control.x) = procindex + 20;
  }
  else
  {
    v12 = (const Quaternion *)(procindex + 80);
    LODWORD(control.x) = procindex + 8;
  }
  if ( v10 < 0.0 )
  {
    v10 = -v10;
    control.z = v10;
    v13 = (const Quaternion *)(procindex + 128);
    v14 = (float *)(procindex + 44);
  }
  else
  {
    v13 = (const Quaternion *)(procindex + 112);
    v14 = (float *)(procindex + 32);
  }
  if ( v9 < 0.0 )
  {
    v15 = (const Quaternion *)(procindex + 160);
    v9 = -v9;
    p.x = v9;
    t = (const Quaternion *)(procindex + 160);
    v16 = (float *)(procindex + 68);
  }
  else
  {
    v15 = (const Quaternion *)(procindex + 144);
    t = (const Quaternion *)(procindex + 144);
    v16 = (float *)(procindex + 56);
  }
  v17 = v10 + v11;
  if ( v17 <= 0.0 )
  {
    QuaternionSlerp(p: v15, q: v15, t: 0.0, qt: (Quaternion *)&tmp.y);
    a2 = *v16;
    a1 = v16[1];
    v18 = v16[2];
  }
  else
  {
    control.y = 1.0 / (float)(v17 + v9);
    QuaternionSlerp(p: v13, q: v12, t: v11 / v17, qt: (Quaternion *)&bonematrix.m_flMatVal[2][1]);
    p.x = control.y * p.x;
    QuaternionSlerp(p: (const Quaternion *)&bonematrix.m_flMatVal[2][1], q: t, t: p.x, qt: (Quaternion *)&tmp.y);
    a2 = *(float *)LODWORD(control.x) * (float)(control.y * *(float *)&p1);
    a1 = *(float *)(LODWORD(control.x) + 4) * (float)(control.y * *(float *)&p1);
    *(float *)&q3 = *(float *)(LODWORD(control.x) + 8) * (float)(control.y * *(float *)&p1);
    a2 = (float)((float)(control.y * control.z) * *v14) + a2;
    a1 = (float)(v14[1] * (float)(control.y * control.z)) + a1;
    *(float *)&q3 = (float)(v14[2] * (float)(control.y * control.z)) + *(float *)&q3;
    a2 = (float)(p.x * *v16) + a2;
    a1 = (float)(v16[1] * p.x) + a1;
    v18 = (float)(v16[2] * p.x) + *(float *)&q3;
  }
  *(float *)&q3 = v18;
  QuaternionMatrix(q: (Quaternion *)&tmp.y, pos: (const Vector *)&a2, matrix: (matrix3x4_t *)v19);
  ConcatTransforms(
    in1: &bonetoworld->m_pBones[v23->parent],
    in2: (const matrix3x4_t *)v19,
    out: &bonetoworld->m_pBones[ibone]);
}

//------------------------------------------------------------------------------
// Address: 0x00435E30
// Name: void DoAimAtBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DoAimAtBone(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld,
        CStudioHdr *pStudioHdr)
{
  mstudiobone_t *v7; // esi
  int procindex; // eax
  char *v9; // esi
  const mstudioattachment_t *v10; // eax
  float v11; // xmm3_4
  __int128 v12; // xmm4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  __int128 v22; // xmm6
  float v23; // xmm3_4
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  __int128 v43; // xmm4
  float v44; // xmm5_4
  _BYTE v45[12]; // [esp+4h] [ebp-1E0h]
  _BYTE v46[12]; // [esp+18h] [ebp-1CCh] BYREF
  matrix3x4a_t boneLocalToWorld; // [esp+24h] [ebp-1C0h] BYREF
  matrix3x4a_t parentSpace; // [esp+54h] [ebp-190h] BYREF
  matrix3x4a_t aimRotationMatrix; // [esp+84h] [ebp-160h] BYREF
  matrix3x4a_t bonematrix; // [esp+B4h] [ebp-130h] BYREF
  matrix3x4a_t aimAtSpace; // [esp+E4h] [ebp-100h] BYREF
  matrix3x4a_t boneMatrix; // [esp+114h] [ebp-D0h] BYREF
  Quaternion boneRotation; // [esp+14Ch] [ebp-98h] BYREF
  Quaternion upRotation; // [esp+15Ch] [ebp-88h] BYREF
  Quaternion aimRotation; // [esp+16Ch] [ebp-78h] BYREF
  Vector tmp_pUp; // [esp+17Ch] [ebp-68h] BYREF
  Vector aimAtWorldPosition; // [esp+188h] [ebp-5Ch] BYREF
  float v58; // [esp+194h] [ebp-50h]
  __int128 aimWorldPosition; // [esp+198h] [ebp-4Ch] OVERLAPPED BYREF
  __int128 tmp_pParentUp; // [esp+1A8h] [ebp-3Ch] OVERLAPPED
  Vector pUp; // [esp+1B8h] [ebp-2Ch]
  float v62; // [esp+1C4h] [ebp-20h]
  Vector pParentUp; // [esp+1C8h] [ebp-1Ch] BYREF
  float v64; // [esp+1D4h] [ebp-10h]
  Vector axis; // [esp+1D8h] [ebp-Ch]
  float retaddr; // [esp+1E4h] [ebp+0h]

  axis.x = a1;
  axis.y = retaddr;
  *(_DWORD *)&v45[8] = a3;
  v7 = &pBones[iBone];
  *(_DWORD *)&v45[4] = a2;
  procindex = v7->procindex;
  LODWORD(aimAtWorldPosition.x) = v7;
  if ( procindex != 0 )
  {
    v9 = (char *)v7 + procindex;
    if ( v9 != nullptr )
    {
      MatrixCopy(in: &bonetoworld->m_pBones[*(_DWORD *)v9], out: (matrix3x4a_t *)&boneLocalToWorld.m_flMatVal[2][1]);
      VectorTransform(
        in1: (const float *)v9 + 8,
        in2: (matrix3x4a_t *)&boneLocalToWorld.m_flMatVal[2][1],
        out: &aimAtWorldPosition.y);
      if ( pStudioHdr != nullptr )
      {
        v10 = CStudioHdr::pAttachment(this: pStudioHdr, i: *((_DWORD *)v9 + 1));
        ConcatTransforms(
          in1: &bonetoworld->m_pBones[v10->localbone],
          in2: &v10->local,
          out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
      }
      else
      {
        MatrixCopy(in: &bonetoworld->m_pBones[*((_DWORD *)v9 + 1)], out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
      }
      MatrixGetColumn(in: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1], column: 3, out: &tmp_pUp);
      QuaternionAngles(
        q: (const Quaternion *)(LODWORD(aimAtWorldPosition.x) + 44),
        angles: (RadianEuler *)((char *)&aimWorldPosition + 4));
      AngleMatrix(
        angles: (const RadianEuler *)((char *)&aimWorldPosition + 4),
        position: (const Vector *)(v9 + 32),
        matrix: (matrix3x4a_t *)&aimRotationMatrix.m_flMatVal[2][1]);
      ConcatTransforms_Aligned(
        m0: &bonetoworld->m_pBones[*(_DWORD *)v9],
        m1: (matrix3x4a_t *)&aimRotationMatrix.m_flMatVal[2][1],
        out: (matrix3x4a_t *)v46);
      v11 = (float)((float)((float)((float)(tmp_pUp.x - aimAtWorldPosition.y) * (float)(tmp_pUp.x - aimAtWorldPosition.y))
                          + 0.00000011920929)
                  + (float)((float)(tmp_pUp.y - aimAtWorldPosition.z) * (float)(tmp_pUp.y - aimAtWorldPosition.z)))
          + (float)((float)(tmp_pUp.z - v58) * (float)(tmp_pUp.z - v58));
      v12 = 0;
      *(float *)&v12 = 1.0 / fsqrt(v11);
      aimWorldPosition = v12;
      v13 = (float)(3.0 - (float)((float)(*(float *)&aimWorldPosition * v11) * *(float *)&aimWorldPosition))
          * (float)(*(float *)&aimWorldPosition * 0.5);
      v14 = (float)(tmp_pUp.x - aimAtWorldPosition.y) * v13;
      v15 = (float)(tmp_pUp.z - v58) * v13;
      v16 = (float)(tmp_pUp.y - aimAtWorldPosition.z) * v13;
      pParentUp.y = (float)(v15 * *((float *)v9 + 3)) - (float)(v16 * *((float *)v9 + 4));
      v17 = (float)(*((float *)v9 + 4) * v14) - (float)(*((float *)v9 + 2) * v15);
      v62 = v15;
      pParentUp.z = v17;
      v18 = *((float *)v9 + 2);
      v19 = *((float *)v9 + 3);
      pUp.y = v14;
      pUp.z = v16;
      v20 = (float)(v18 * v16) - (float)(v19 * v14);
      v21 = (float)((float)((float)(pParentUp.y * pParentUp.y) + 0.00000011920929) + (float)(v17 * v17))
          + (float)(v20 * v20);
      v22 = 0;
      *(float *)&v22 = 1.0 / fsqrt(v21);
      aimWorldPosition = v22;
      v23 = (float)(3.0 - (float)((float)(*(float *)&aimWorldPosition * v21) * *(float *)&aimWorldPosition))
          * (float)(*(float *)&aimWorldPosition * 0.5);
      pParentUp.y = pParentUp.y * v23;
      pParentUp.z = v17 * v23;
      v64 = v20 * v23;
      *(_DWORD *)v45 = &upRotation.y;
      v24 = (float)((float)((float)(v16 * *((float *)v9 + 3)) + (float)(*((float *)v9 + 2) * v14))
                  + (float)(v62 * *((float *)v9 + 4)));
      __libm_sse2_acos(x: *(long double *)v45);
      *(float *)&v24 = v24;
      AxisAngleQuaternion(axis: (Vector *)&pParentUp.y, angle: *(float *)&v24 * 57.29578, q: *(Quaternion **)v45);
      if ( (float)(1.0
                 - COERCE_FLOAT(
                     COERCE_UNSIGNED_INT(
                       (float)((float)(*((float *)v9 + 6) * *((float *)v9 + 3))
                             + (float)(*((float *)v9 + 2) * *((float *)v9 + 5)))
                     + (float)(*((float *)v9 + 7) * *((float *)v9 + 4)))
                   & _mask__AbsFloat_)) <= 0.00000011920929 )
      {
        QuaternionMatrix(
          q: (Quaternion *)&upRotation.y,
          pos: (Vector *)&aimAtWorldPosition.y,
          matrix: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1]);
      }
      else
      {
        QuaternionMatrix(q: (Quaternion *)&upRotation.y, matrix: (matrix3x4a_t *)&parentSpace.m_flMatVal[2][1]);
        VectorRotate(
          in1: (const float *)v9 + 5,
          in2: (matrix3x4a_t *)&parentSpace.m_flMatVal[2][1],
          out: &aimRotation.y);
        v25 = (float)((float)(aimRotation.z * pUp.z) + (float)(aimRotation.y * pUp.y)) + (float)(aimRotation.w * v62);
        v26 = aimRotation.y - (float)(v25 * pUp.y);
        v27 = aimRotation.z - (float)(pUp.z * v25);
        v28 = aimRotation.w - (float)(v62 * v25);
        v29 = (float)((float)((float)(v26 * v26) + 0.00000011920929) + (float)(v27 * v27)) + (float)(v28 * v28);
        *(float *)&tmp_pParentUp = 1.0 / fsqrt(v29);
        v30 = (float)(3.0 - (float)((float)(*(float *)&tmp_pParentUp * v29) * *(float *)&tmp_pParentUp))
            * (float)(*(float *)&tmp_pParentUp * 0.5);
        *((float *)&tmp_pParentUp + 1) = v26 * v30;
        *((float *)&tmp_pParentUp + 2) = v27 * v30;
        *((float *)&tmp_pParentUp + 3) = v28 * v30;
        VectorRotate(in1: (const float *)v9 + 5, in2: (const matrix3x4_t *)v46, out: (float *)&aimWorldPosition + 1);
        v31 = (float)((float)(*((float *)&aimWorldPosition + 2) * pUp.z)
                    + (float)(*((float *)&aimWorldPosition + 1) * pUp.y))
            + (float)(*((float *)&aimWorldPosition + 3) * v62);
        v32 = *((float *)&aimWorldPosition + 1) - (float)(v31 * pUp.y);
        v33 = *((float *)&aimWorldPosition + 3) - (float)(v62 * v31);
        v34 = *((float *)&aimWorldPosition + 2) - (float)(pUp.z * v31);
        v35 = (float)((float)((float)(v32 * v32) + 0.00000011920929) + (float)(v34 * v34)) + (float)(v33 * v33);
        pUp.x = 1.0 / fsqrt(v35);
        v36 = (float)(3.0 - (float)((float)(pUp.x * v35) * pUp.x)) * (float)(pUp.x * 0.5);
        pUp.y = v32 * v36;
        pUp.z = v34 * v36;
        v62 = v33 * v36;
        v37 = (float)((float)((float)(v34 * v36) * *((float *)&tmp_pParentUp + 2))
                    + (float)((float)(v32 * v36) * *((float *)&tmp_pParentUp + 1)))
            + (float)((float)(v33 * v36) * *((float *)&tmp_pParentUp + 3));
        if ( (float)(1.0 - COERCE_FLOAT(LODWORD(v37) & _mask__AbsFloat_)) <= 0.00000011920929 )
        {
          v38 = 0.0;
          v41 = *((float *)&tmp_pParentUp + 2);
          v40 = *((float *)&tmp_pParentUp + 3);
          v39 = *((float *)&tmp_pParentUp + 1);
        }
        else
        {
          __libm_sse2_acos(x: *(long double *)&v45[4]);
          v38 = v37;
          v39 = (float)(v62 * *((float *)&tmp_pParentUp + 2)) - (float)(pUp.z * *((float *)&tmp_pParentUp + 3));
          v40 = (float)(pUp.z * *((float *)&tmp_pParentUp + 1)) - (float)(*((float *)&tmp_pParentUp + 2) * pUp.y);
          v41 = (float)(*((float *)&tmp_pParentUp + 3) * pUp.y) - (float)(v62 * *((float *)&tmp_pParentUp + 1));
        }
        v42 = (float)((float)((float)(v39 * v39) + 0.00000011920929) + (float)(v41 * v41)) + (float)(v40 * v40);
        v43 = 0;
        *(float *)&v43 = 1.0 / fsqrt(v42);
        tmp_pParentUp = v43;
        v44 = (float)(3.0 - (float)((float)(*(float *)&v43 * v42) * *(float *)&tmp_pParentUp))
            * (float)(*(float *)&tmp_pParentUp * 0.5);
        pParentUp.y = v44 * v39;
        pParentUp.z = v41 * v44;
        v64 = v40 * v44;
        AxisAngleQuaternion(axis: (Vector *)&pParentUp.y, angle: v38 * 57.29578, q: (Quaternion *)&boneRotation.y);
        QuaternionMult(
          p: (Quaternion *)&boneRotation.y,
          q: (Quaternion *)&upRotation.y,
          qt: (Quaternion *)&boneMatrix.m_flMatVal[2][3]);
        QuaternionMatrix(
          q: (const Quaternion *)&boneMatrix.m_flMatVal[2][3],
          pos: (Vector *)&aimAtWorldPosition.y,
          matrix: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1]);
      }
      MatrixCopy(in: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1], out: &bonetoworld->m_pBones[iBone]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004364E0
// Name: void DoTwistBones(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoTwistBones(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v6; // eax
  int procindex; // esi
  char *v8; // esi
  int v9; // eax
  matrix3x4a_t *m_pBones; // ecx
  int v11; // edi
  const matrix3x4a_t *v12; // edi
  bool v13; // sf
  _DWORD *v14; // eax
  int v15; // edi
  void *v16; // esp
  unsigned int v17; // edi
  void *v18; // esp
  void *v19; // esp
  int v20; // ecx
  Quaternion *v21; // edi
  _QWORD *p_x; // edx
  char *v23; // eax
  double v24; // st7
  char *v25; // edi
  _DWORD v26[4]; // [esp-E0h] [ebp-ECh] BYREF
  matrix3x4a_t v27; // [esp-D0h] [ebp-DCh] BYREF
  matrix3x4a_t v28; // [esp-A0h] [ebp-ACh] BYREF
  matrix3x4_t v29; // [esp-70h] [ebp-7Ch] BYREF
  RadianEuler v30; // [esp-3Ch] [ebp-48h] BYREF
  Quaternion v31; // [esp-30h] [ebp-3Ch] BYREF
  Quaternion *v32; // [esp-14h] [ebp-20h]
  const matrix3x4a_t *v33; // [esp-10h] [ebp-1Ch]
  const float *v34; // [esp-Ch] [ebp-18h]
  const Quaternion *v35; // [esp-8h] [ebp-14h]
  const Quaternion *v36; // [esp-4h] [ebp-10h]
  int i; // [esp+0h] [ebp-Ch]
  void *v38; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  i = a1;
  v38 = retaddr;
  v6 = &pBones[iBone];
  v26[1] = a3;
  procindex = v6->procindex;
  v26[0] = a2;
  if ( procindex != 0 )
  {
    v8 = (char *)v6 + procindex;
    if ( v8 != nullptr )
    {
      v9 = *((_DWORD *)v8 + 4);
      m_pBones = bonetoworld->m_pBones;
      v11 = v9;
      v9 *= 216;
      v12 = &m_pBones[v11];
      v13 = *(int *)((char *)&pBones->parent + v9) < 0;
      v14 = (int *)((char *)&pBones->parent + v9);
      v33 = v12;
      if ( v13 )
      {
        MatrixQuaternion(mat: v12, q: &v31);
      }
      else
      {
        MatrixInvert(in: &m_pBones[*v14], out: &v29);
        ConcatTransforms_Aligned(m0: (const matrix3x4a_t *)&v29, m1: v12, out: &v28);
        MatrixQuaternion(mat: &v28, q: &v31);
      }
      MatrixInvert(in: v12, out: &v29);
      ConcatTransforms_Aligned(
        m0: (const matrix3x4a_t *)&v29,
        m1: &bonetoworld->m_pBones[*((_DWORD *)v8 + 9)],
        out: &v27);
      v15 = *((_DWORD *)v8 + 10);
      v16 = alloca(4 * v15);
      v17 = (16 * v15 + 15) & 0xFFFFFFF0;
      v34 = (const float *)v26;
      v18 = alloca(v17);
      v36 = (const Quaternion *)v26;
      v19 = alloca(v17);
      v20 = 0;
      v21 = (Quaternion *)v26;
      v32 = (Quaternion *)v26;
      if ( *((int *)v8 + 10) > 0 )
      {
        p_x = (_QWORD *)&v36->x;
        v35 = nullptr;
        do
        {
          v23 = (char *)v35 + *((_DWORD *)v8 + 11);
          v24 = *(float *)&v8[(_DWORD)v23 + 4];
          v35 = (const Quaternion *)((char *)v35 + 36);
          v34[v20] = v24;
          *p_x = *(_QWORD *)&v8[(_DWORD)v23 + 20];
          p_x[1] = *(_QWORD *)&v8[(_DWORD)v23 + 28];
          ++v20;
          p_x += 2;
        }
        while ( v20 < *((_DWORD *)v8 + 10) );
        v21 = v32;
      }
      _V_memcpy(dest: v21, src: v36, count: 16 * *((_DWORD *)v8 + 10));
      ComputeTwistBones(
        pqTwists: v21,
        nCount: *((_DWORD *)v8 + 10),
        bInverse: *v8,
        vUp: (const Vector *)(v8 + 4),
        qParent: &v31,
        mChild: &v27,
        qBaseInv: (const Quaternion *)(v8 + 20),
        pflWeights: v34,
        pqTwistBinds: v36);
      v34 = nullptr;
      if ( *((int *)v8 + 10) > 0 )
      {
        v36 = nullptr;
        v35 = v21;
        do
        {
          v25 = (char *)v36 + *((_DWORD *)v8 + 11);
          QuaternionAngles(q: v35, angles: &v30);
          AngleMatrix(angles: &v30, position: (const Vector *)&v8[(_DWORD)v25 + 8], matrix: &v29);
          ConcatTransforms_Aligned(
            m0: v33,
            m1: (const matrix3x4a_t *)&v29,
            out: &bonetoworld->m_pBones[*(_DWORD *)&v8[(_DWORD)v25]]);
          v36 = (const Quaternion *)((char *)v36 + 36);
          ++v35;
          v34 = (const float *)((char *)v34 + 1);
        }
        while ( (int)v34 < *((_DWORD *)v8 + 10) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004366F0
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_99;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_99;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_98:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: v37,
        s: v35,
        boneMask: v54);
      goto LABEL_99;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        goto LABEL_99;
      }
      if ( anim_3wayblend.m_pParent == nullptr || anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_98;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_98;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_99;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_99;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      pos2,
      s,
      boneMask);
    goto LABEL_99;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_99;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_99;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_99:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x004370D0
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437110
// Name: void DoQuatInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoQuatInterpBone(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pbones,
        int ibone,
        CBoneAccessor *bonetoworld)
{
  int v6; // edx
  mstudiobone_t *v7; // eax
  int procindex; // esi
  _DWORD *v9; // esi
  int *p_parent; // ecx
  int v11; // edi
  long double v12; // st7
  float y; // xmm0_4
  float v14; // xmm0_4
  float z; // xmm0_4
  float v16; // ecx
  float v17; // xmm0_4
  const Quaternion *v18; // edi
  matrix3x4a_t *v19; // [esp-24h] [ebp-184h]
  long double v20; // [esp-1Ch] [ebp-17Ch]
  _DWORD v21[3]; // [esp-Ch] [ebp-16Ch]
  float weight[32]; // [esp+0h] [ebp-160h] BYREF
  matrix3x4a_t controlmatrix; // [esp+80h] [ebp-E0h] BYREF
  matrix3x4a_t tmpmatrix; // [esp+B0h] [ebp-B0h] BYREF
  matrix3x4a_t bonematrix; // [esp+E0h] [ebp-80h] BYREF
  Quaternion src; // [esp+110h] [ebp-50h] BYREF
  float v27; // [esp+120h] [ebp-40h]
  float *p_x; // [esp+124h] [ebp-3Ch]
  mstudiobone_t *v29; // [esp+128h] [ebp-38h]
  float s; // [esp+12Ch] [ebp-34h] BYREF
  float v31; // [esp+130h] [ebp-30h]
  float v32; // [esp+134h] [ebp-2Ch]
  Vector pos; // [esp+138h] [ebp-28h] BYREF
  Quaternion quat; // [esp+144h] [ebp-1Ch]
  float dot; // [esp+154h] [ebp-Ch]
  float scale; // [esp+158h] [ebp-8h]
  float retaddr; // [esp+160h] [ebp+0h]

  dot = a1;
  scale = retaddr;
  v6 = ibone;
  v7 = &pbones[ibone];
  HIDWORD(v20) = a3;
  procindex = v7->procindex;
  LODWORD(v20) = a2;
  v29 = v7;
  if ( procindex != 0 )
  {
    v9 = (int *)((char *)&v7->sznameindex + procindex);
    if ( v9 != nullptr )
    {
      p_parent = &pbones[*v9].parent;
      if ( *p_parent != -1 )
      {
        v19 = &bonetoworld->m_pBones[*p_parent];
        quat.z = 0.0;
        MatrixInvert(in: v19, out: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1]);
        ConcatTransforms_Aligned(
          m0: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1],
          m1: &bonetoworld->m_pBones[*v9],
          out: (matrix3x4a_t *)&weight[29]);
        MatrixAngles(
          matrix: (const matrix3x4_t *)&weight[29],
          q: (Quaternion *)&bonematrix.m_flMatVal[2][1],
          pos: (Vector *)&s);
        v11 = 0;
        if ( (int)v9[1] <= 0 )
        {
          z = quat.z;
        }
        else
        {
          quat.w = 0.0;
          do
          {
            v12 = fabs(
                    QuaternionDotProduct(
                      p: (const Quaternion *)((char *)v9 + LODWORD(quat.w) + v9[2] + 4),
                      q: (const Quaternion *)&bonematrix.m_flMatVal[2][1]));
            quat.y = v12;
            if ( v12 >= -1.0 )
            {
              y = quat.y;
              if ( quat.y > 1.0 )
                y = 1.0;
            }
            else
            {
              y = -1.0;
            }
            __libm_sse2_acos(x: v20);
            v14 = 1.0 - (float)((float)(y * 2.0) * *(float *)((char *)v9 + LODWORD(quat.w) + v9[2]));
            *(float *)&v21[v11] = v14;
            if ( v14 < 0.0 )
              v14 = 0.0;
            LODWORD(quat.w) += 48;
            *(float *)&v21[v11] = v14;
            z = v14 + quat.z;
            ++v11;
            quat.z = z;
          }
          while ( v11 < v9[1] );
        }
        if ( z <= 0.001 )
        {
          QuaternionAngles(q: (const Quaternion *)((char *)v9 + v9[2] + 32), angles: (RadianEuler *)&src.y);
          AngleMatrix(
            angles: (const RadianEuler *)&src.y,
            position: (const Vector *)((char *)v9 + v9[2] + 20),
            matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
          ConcatTransforms(
            in1: &bonetoworld->m_pBones[v29->parent],
            in2: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
            out: &bonetoworld->m_pBones[ibone]);
          return;
        }
        v16 = 0.0;
        quat.z = 1.0 / z;
        memset(&pos, 0, sizeof(pos));
        quat.x = 0.0;
        s = 0.0;
        v31 = 0.0;
        v32 = 0.0;
        quat.y = 0.0;
        if ( (int)v9[1] > 0 )
        {
          quat.w = 0.0;
          do
          {
            v17 = *(float *)&v21[LODWORD(v16)];
            if ( v17 != 0.0 )
            {
              v18 = (const Quaternion *)((char *)v9 + LODWORD(quat.w) + v9[2]);
              v27 = v17 * quat.z;
              p_x = &v18[2].x;
              QuaternionAlign(p: v18 + 2, q: (const Quaternion *)&pos, qt: (Quaternion *)&pos);
              pos.x = (float)(*p_x * v27) + pos.x;
              pos.y = (float)(v18[2].y * v27) + pos.y;
              v16 = quat.y;
              pos.z = (float)(v18[2].z * v27) + pos.z;
              quat.x = (float)(v18[2].w * v27) + quat.x;
              s = (float)(v18[1].y * v27) + s;
              v31 = (float)(v18[1].z * v27) + v31;
              v32 = (float)(v18[1].w * v27) + v32;
            }
            LODWORD(quat.w) += 48;
            ++LODWORD(v16);
            quat.y = v16;
          }
          while ( SLODWORD(v16) < v9[1] );
        }
        QuaternionMatrix(
          q: (const Quaternion *)&pos,
          pos: (const Vector *)&s,
          matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
        v7 = v29;
        v6 = ibone;
      }
    }
  }
  ConcatTransforms_Aligned(
    m0: &bonetoworld->m_pBones[v7->parent],
    m1: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
    out: &bonetoworld->m_pBones[v6]);
}

//------------------------------------------------------------------------------
// Address: 0x00437480
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437570
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x00437590
// Name: void CalcBoneAdj(class CStudioHdr const __near *,class Vector __near * const,class Quaternion __near * const,float const __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcBoneAdj(
        const CStudioHdr *pStudioHdr,
        Vector *pos,
        Quaternion *q,
        const float *controllers,
        int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  Vector *p_y; // eax
  const Quaternion *v13; // [esp+8h] [ebp-34h]
  Quaternion *v14; // [esp+Ch] [ebp-30h]
  Quaternion q0; // [esp+1Ch] [ebp-20h] BYREF
  RadianEuler a0; // [esp+2Ch] [ebp-10h] BYREF
  int j; // [esp+38h] [ebp-4h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  v6 = 0;
  for ( j = 0; j < m_pStudioHdr->numbonecontrollers; ++j )
  {
    v7 = v6 + m_pStudioHdr->bonecontrollerindex;
    v8 = *(int *)((char *)&m_pStudioHdr->id + v7);
    v9 = (char *)m_pStudioHdr + v7;
    if ( (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v8]) != 0 )
    {
      v10 = controllers[*((_DWORD *)v9 + 5)];
      if ( v10 >= 0.0 )
      {
        if ( v10 > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = 0.0;
      }
      v11 = (float)((float)(1.0 - v10) * *((float *)v9 + 2)) + (float)(*((float *)v9 + 3) * v10);
      switch ( *((_DWORD *)v9 + 1) & 0x3FFFF )
      {
        case 1:
          p_y = &pos[v8];
          goto LABEL_15;
        case 2:
          p_y = (Vector *)&pos[v8].y;
          goto LABEL_15;
        case 4:
          p_y = (Vector *)&pos[v8].z;
LABEL_15:
          p_y->x = p_y->x + v11;
          break;
        case 8:
          a0.x = v11 * 0.0174532925199433;
          a0.y = 0.0;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x10:
          a0.x = 0.0;
          a0.y = v11 * 0.0174532925199433;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x20:
          a0.x = 0.0;
          a0.y = 0.0;
          a0.z = v11 * 0.0174532925199433;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
LABEL_9:
          QuaternionSM(s: 1.0, p: &q0, q: v13, qt: v14);
          break;
        default:
          break;
      }
    }
    m_pStudioHdr = pStudioHdr->m_pStudioHdr;
    v6 += 56;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437790
// Name: bool CalcProceduralBone(class CStudioHdr const __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CalcProceduralBone@<al>(int a1@<edi>, CStudioHdr *pStudioHdr, int iBone, CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v4; // eax
  int v5; // esi
  bool result; // al
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v4 = (mstudiobone_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->boneindex);
  if ( (pStudioHdr->m_boneFlags.m_Memory.m_pMemory[iBone] & 4) == 0 )
    return false;
  v5 = v4[iBone].proctype - 1;
  switch ( v4[iBone].proctype )
  {
    case 1:
      DoAxisInterpBone(ebp0: COERCE_FLOAT(&savedregs), pbones: v4, ibone: iBone, bonetoworld);
      goto $LN2_5;
    case 2:
      DoQuatInterpBone(a1: COERCE_FLOAT(&savedregs), a2: a1, a3: v5, pbones: v4, ibone: iBone, bonetoworld);
      return true;
    case 3:
      DoAimAtBone(a1: COERCE_FLOAT(&savedregs), a2: a1, a3: v5, pBones: v4, iBone, bonetoworld, pStudioHdr: nullptr);
      return true;
    case 4:
      DoAimAtBone(a1: COERCE_FLOAT(&savedregs), a2: a1, a3: v5, pBones: v4, iBone, bonetoworld, pStudioHdr);
      return true;
    case 6:
      DoTwistBones(a1: (int)&savedregs, a2: a1, a3: v5, pBones: v4, iBone, bonetoworld);
      return true;
    case 7:
$LN2_5:
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437850
// Name: public: void IBoneSetup::CalcBoneAdj(class Vector __near * const,class Quaternion __near * const,float const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcBoneAdj(IBoneSetup *this, Vector *pos, Quaternion *q, const float *controllers)
{
  CalcBoneAdj(
    pStudioHdr: this->m_pBoneSetup->m_pStudioHdr,
    pos,
    q,
    controllers,
    boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x00437880
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  long double v10; // rdi
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *v14; // ecx
  CIKContext *v15; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float v18; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  HIDWORD(v10) = this;
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v18 = flWeight;
    else
      v18 = 1.0;
  }
  else
  {
    v18 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( *(_DWORD *)(HIDWORD(v10) + 12) != 0 )
      (*(void (__stdcall **)(_DWORD, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, _DWORD, _DWORD, float, _DWORD))(**(_DWORD **)(HIDWORD(v10) + 12) + 4))(
        a1: *(_DWORD *)HIDWORD(v10),
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: *(_DWORD *)(HIDWORD(v10) + 8),
        a8: *(_DWORD *)(HIDWORD(v10) + 4),
        a9: COERCE_FLOAT(LODWORD(v18)),
        a10: LODWORD(flTime));
    v14 = *(CStudioHdr **)HIDWORD(v10);
    if ( *(_DWORD *)(*(_DWORD *)HIDWORD(v10) + 4) != 0 )
    {
      LODWORD(v10) = CStudioHdr::pSeqdesc_Internal(this: v14, i: sequence);
    }
    else
    {
      if ( sequence >= v14->m_pStudioHdr->numlocalseq )
        v11 = 0;
      LODWORD(v10) = (char *)v14->m_pStudioHdr + 212 * v11 + v14->m_pStudioHdr->localseqindex;
    }
    CIKContext::CIKContext(this: &v17);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    }
    if ( (*(_DWORD *)(LODWORD(v10) + 12) & 0x200) != 0 )
      InitPose(
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        pos: v19,
        q: v20,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
    if ( CalcPoseSingle(
           pStudioHdr: *(CStudioHdr **)HIDWORD(v10),
           pos: v19,
           q: v20,
           seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
           sequence,
           cycle,
           poseParameter: *(const float **)(HIDWORD(v10) + 8),
           boneMask: *(_DWORD *)(HIDWORD(v10) + 4),
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this: (CBoneSetup *)HIDWORD(v10),
        pos: v19,
        q: v20,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = *(_DWORD *)(HIDWORD(v10) + 4);
      *(float *)&s = v18;
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: v10,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        q1: q,
        pos1: pos,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        sequence,
        q2: v20,
        pos2: v19,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v15 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: *(const float **)(HIDWORD(v10) + 8),
        flWeight: v18);
      v15 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(
      this: (CBoneSetup *)HIDWORD(v10),
      pos,
      q,
      seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
      sequence,
      cycle,
      flWeight: v18,
      flTime,
      pIKContext: v15);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437BD0
// Name: public: void CBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::CalcAutoplaySequences(
        CBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CIKContext *v5; // esi
  int v6; // ebx
  const CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v9; // ecx
  int v10; // esi
  const studiohdr_t *v11; // ecx
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  double v14; // st7
  float v15; // [esp+0h] [ebp-28h]
  int count; // [esp+1Ch] [ebp-Ch]
  float cycle; // [esp+20h] [ebp-8h]
  unsigned __int16 *pList; // [esp+24h] [ebp-4h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v5 = pIKContext;
  v6 = 0;
  if ( pIKContext != nullptr )
    CIKContext::AddAutoplayLocks(this: pIKContext, pos, q);
  m_pStudioHdr = this->m_pStudioHdr;
  pList = nullptr;
  count = studiohdr_t::GetAutoplayList(this: (studiohdr_t *)m_pStudioHdr->m_pStudioHdr, pOut: &pList);
  if ( count > 0 )
  {
    do
    {
      v9 = (CStudioHdr *)this->m_pStudioHdr;
      v10 = pList[v6];
      if ( this->m_pStudioHdr->m_pVModel != nullptr )
      {
        v13 = CStudioHdr::pSeqdesc_Internal(this: v9, i: pList[v6]);
      }
      else
      {
        v11 = v9->m_pStudioHdr;
        v12 = pList[v6];
        if ( v10 >= v11->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v11 + 212 * v12 + v11->localseqindex);
      }
      if ( (v13->flags & 8) != 0 )
      {
        v14 = Studio_CPS(
                pStudioHdr: this->m_pStudioHdr,
                seqdesc: v13,
                iSequence: v10,
                poseParameter: this->m_flPoseParameter)
            * flRealTime;
        cycle = v14;
        v15 = v14 - (double)(int)cycle;
        CBoneSetup::AccumulatePose(
          this,
          a2: (int)&savedregs,
          pos,
          q,
          sequence: v10,
          cycle: v15,
          flWeight: 1.0,
          flTime: flRealTime,
          pIKContext);
      }
      ++v6;
    }
    while ( v6 < count );
    v5 = pIKContext;
  }
  if ( v5 != nullptr )
    CIKContext::SolveAutoplayLocks(this: v5, pos, q);
}

//------------------------------------------------------------------------------
// Address: 0x00437CD0
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

//------------------------------------------------------------------------------
// Address: 0x00437D20
// Name: public: void IBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcAutoplaySequences(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CBoneSetup::CalcAutoplaySequences(this: this->m_pBoneSetup, pos, q, flRealTime, pIKContext);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005E74C0
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E7550
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x005E7700
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005E78D0
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E7B00
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E7CC0
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x005E86B0
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005E86F0
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E87E0
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x005E8800
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v18; // [esp+50h] [ebp-108Ch] BYREF
  float v19; // [esp+10C4h] [ebp-18h]
  Vector *v20; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v21; // [esp+10CCh] [ebp-10h]
  _DWORD v22[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v22[0] = a2;
  v22[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v19 = flWeight;
    else
      v19 = 1.0;
  }
  else
  {
    v19 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v20 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v20 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    v21 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v21 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v21 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v21 = nullptr;
      }
      if ( ((unsigned __int8)v21 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(v19),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v18);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v18,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v20, q: v21, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v20,
           q: v21,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v20,
        q: v21,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = this->m_boneMask;
      *(float *)&s = v19;
      SlerpBones(
        a1: COERCE_FLOAT(v22),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v21,
        pos2: v20,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v21);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: v19);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: v19, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v18.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v18.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E8B50
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace mdlcompile

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004A6A20
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004A6AB0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x004A6C60
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A6E30
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7060
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7220
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x004A7230
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x004A7C10
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004A7C50
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (__m128i *)pos, src: (const __m128i *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (__m128i *)q, src: (const __m128i *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A7D40
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x004A7DC0
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A8110
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00558900
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00558990
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x00558B40
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00558D10
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00558F40
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00559100
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x00559110
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x00559AF0
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00559B30
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (__m128i *)pos, src: (const __m128i *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (__m128i *)q, src: (const __m128i *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00559C20
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x00559C40
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00559F90
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0056E920
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0056E9B0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x0056EB60
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056ED30
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056EF60
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056F120
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x0056F130
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x0056FB10
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056FB50
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056FC40
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x0056FC60
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056FFB0
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0069A100
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0069A190
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x0069A340
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0069A510
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0069A740
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0069A900
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x0069A910
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x0069B2F0
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0069B330
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (__m128i *)pos, src: (const __m128i *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (__m128i *)q, src: (const __m128i *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0069B420
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x0069B440
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0069B790
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005708F0
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00570980
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x00570B30
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00570D00
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00570F30
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005710F0
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x00571100
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x00571AE0
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00571B20
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00571C10
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x00571C30
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00571F80
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005E0370
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x005E0400
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x005E05B0
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005E0780
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E09B0
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0B70
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x005E1560
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005E15A0
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1690
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x005E16B0
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v18; // [esp+50h] [ebp-108Ch] BYREF
  float v19; // [esp+10C4h] [ebp-18h]
  Vector *v20; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v21; // [esp+10CCh] [ebp-10h]
  _DWORD v22[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v22[0] = a2;
  v22[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v19 = flWeight;
    else
      v19 = 1.0;
  }
  else
  {
    v19 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v20 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v20 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    v21 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v21 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v21 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v21 = nullptr;
      }
      if ( ((unsigned __int8)v21 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(v19),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v18);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v18,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v20, q: v21, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v20,
           q: v21,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v20,
        q: v21,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = this->m_boneMask;
      *(float *)&s = v19;
      SlerpBones(
        a1: COERCE_FLOAT(v22),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v21,
        pos2: v20,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v21);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: v19);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: v19, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v18.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&v18.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1A00
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0056E360
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0056E3F0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x0056E5A0
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056E770
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056E9A0
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056EB70
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_98;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_98;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_97:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: (__m128 *)v37,
        s: v35,
        boneMask: v54);
      goto LABEL_98;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        goto LABEL_98;
      }
      if ( anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: (__m128 *)v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_97;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          (__m128 *)pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_97;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_98;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_98;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      (__m128 *)pos2,
      s,
      boneMask);
    goto LABEL_98;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_98;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_98;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_98:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x0056F550
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056F590
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056F680
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x0056F6A0
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float s; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      s = flWeight;
    else
      s = 1.0;
  }
  else
  {
    s = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(s),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v17);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v19, q: v20, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v19,
           q: v20,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v19,
        q: v20,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v20,
        pos2: v19,
        s,
        boneMask: this->m_boneMask);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: s);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: s, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: v15, pos, q);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056F9F0
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006AADC0
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x006AAE50
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x006AB000
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006AB1D0
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AB400
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AB5C0
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x006AB5D0
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_99;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_99;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_98:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: v37,
        s: v35,
        boneMask: v54);
      goto LABEL_99;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        goto LABEL_99;
      }
      if ( anim_3wayblend.m_pParent == nullptr || anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_98;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_98;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_99;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_99;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      pos2,
      s,
      boneMask);
    goto LABEL_99;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_99;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_99;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_99:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x006ABFB0
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006ABFF0
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (__m128i *)pos, src: (const __m128i *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (__m128i *)q, src: (const __m128i *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AC0E0
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x006AC100
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  long double v10; // rdi
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *v14; // ecx
  CIKContext *v15; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float v18; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  HIDWORD(v10) = this;
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v18 = flWeight;
    else
      v18 = 1.0;
  }
  else
  {
    v18 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( *(_DWORD *)(HIDWORD(v10) + 12) != 0 )
      (*(void (__stdcall **)(_DWORD, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, _DWORD, _DWORD, float, _DWORD))(**(_DWORD **)(HIDWORD(v10) + 12) + 4))(
        a1: *(_DWORD *)HIDWORD(v10),
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: *(_DWORD *)(HIDWORD(v10) + 8),
        a8: *(_DWORD *)(HIDWORD(v10) + 4),
        a9: COERCE_FLOAT(LODWORD(v18)),
        a10: LODWORD(flTime));
    v14 = *(CStudioHdr **)HIDWORD(v10);
    if ( *(_DWORD *)(*(_DWORD *)HIDWORD(v10) + 4) != 0 )
    {
      LODWORD(v10) = CStudioHdr::pSeqdesc_Internal(this: v14, i: sequence);
    }
    else
    {
      if ( sequence >= v14->m_pStudioHdr->numlocalseq )
        v11 = 0;
      LODWORD(v10) = (char *)v14->m_pStudioHdr + 212 * v11 + v14->m_pStudioHdr->localseqindex;
    }
    CIKContext::CIKContext(this: &v17);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    }
    if ( (*(_DWORD *)(LODWORD(v10) + 12) & 0x200) != 0 )
      InitPose(
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        pos: v19,
        q: v20,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
    if ( CalcPoseSingle(
           pStudioHdr: *(CStudioHdr **)HIDWORD(v10),
           pos: v19,
           q: v20,
           seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
           sequence,
           cycle,
           poseParameter: *(const float **)(HIDWORD(v10) + 8),
           boneMask: *(_DWORD *)(HIDWORD(v10) + 4),
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this: (CBoneSetup *)HIDWORD(v10),
        pos: v19,
        q: v20,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = *(_DWORD *)(HIDWORD(v10) + 4);
      *(float *)&s = v18;
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: v10,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        q1: q,
        pos1: pos,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        sequence,
        q2: v20,
        pos2: v19,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v15 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: *(const float **)(HIDWORD(v10) + 8),
        flWeight: v18);
      v15 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(
      this: (CBoneSetup *)HIDWORD(v10),
      pos,
      q,
      seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
      sequence,
      cycle,
      flWeight: v18,
      flTime,
      pIKContext: v15);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v17.m_ikLock);
    CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AC450
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

} // namespace vmap

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102AEE60
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102AEEF0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x102AF0A0
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF2D0
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF490
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    C_BaseEntity::operator delete(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x102AF4A0
// Name: public: class CStudioHdr __near * IBoneSetup::GetStudioHdr(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall IBoneSetup::GetStudioHdr(IBoneSetup *this)
{
  return (CStudioHdr *)this->m_pBoneSetup->m_pStudioHdr;
}

//------------------------------------------------------------------------------
// Address: 0x102AF4B0
// Name: void CalcBoneDerivatives(class Vector __near &,class Vector __near &,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcBoneDerivatives(
        Vector *velocity,
        Vector *angVel,
        const matrix3x4_t *prev,
        const matrix3x4_t *current,
        float dt)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  QAngle startAngles; // [esp+0h] [ebp-34h] BYREF
  QAngle endAngles; // [esp+Ch] [ebp-28h] BYREF
  Vector deltaAxis; // [esp+18h] [ebp-1Ch] BYREF
  Vector startPosition; // [esp+24h] [ebp-10h]
  float scale; // [esp+30h] [ebp-4h]

  scale = 1.0;
  if ( dt > 0.0 )
    scale = 1.0 / dt;
  MatrixAngles(src: (const VMatrix *)prev, vAngles: &startAngles);
  startPosition.x = prev->m_flMatVal[0][3];
  startPosition.y = prev->m_flMatVal[1][3];
  startPosition.z = prev->m_flMatVal[2][3];
  MatrixAngles(src: (const VMatrix *)current, vAngles: &endAngles);
  v5 = (float)(current->m_flMatVal[1][3] - startPosition.y) * scale;
  v6 = (float)(current->m_flMatVal[2][3] - startPosition.z) * scale;
  velocity->x = (float)(current->m_flMatVal[0][3] - startPosition.x) * scale;
  velocity->y = v5;
  velocity->z = v6;
  RotationDeltaAxisAngle(srcAngles: &startAngles, destAngles: &endAngles, &deltaAxis, deltaAngle: &dt);
  v7 = dt * scale;
  angVel->x = deltaAxis.x * (float)(dt * scale);
  angVel->y = v7 * deltaAxis.y;
  angVel->z = deltaAxis.z * v7;
}

//------------------------------------------------------------------------------
// Address: 0x102AF5C0
// Name: void DoAxisInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoAxisInterpBone(float ebp0@<ebp>, mstudiobone_t *pbones, int ibone, CBoneAccessor *bonetoworld)
{
  int procindex; // esi
  matrix3x4a_t *m_pBones; // edx
  int *p_parent; // edi
  int v7; // ecx
  matrix3x4a_t *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  const Quaternion *v12; // edx
  const Quaternion *v13; // eax
  float *v14; // edi
  const Quaternion *v15; // ecx
  float *v16; // esi
  float v17; // xmm0_4
  float v18; // xmm0_4
  _BYTE v19[12]; // [esp+18h] [ebp-9Ch] BYREF
  matrix3x4a_t bonematrix; // [esp+24h] [ebp-90h] BYREF
  Quaternion tmp; // [esp+54h] [ebp-60h] BYREF
  Quaternion v; // [esp+64h] [ebp-50h] BYREF
  mstudiobone_t *v23; // [esp+74h] [ebp-40h]
  float v24; // [esp+78h] [ebp-3Ch] BYREF
  float v25; // [esp+7Ch] [ebp-38h]
  float v26; // [esp+80h] [ebp-34h]
  Vector control; // [esp+84h] [ebp-30h]
  Vector *p1; // [esp+90h] [ebp-24h]
  const Quaternion *t; // [esp+94h] [ebp-20h]
  float a2; // [esp+98h] [ebp-1Ch] BYREF
  float a1; // [esp+9Ch] [ebp-18h]
  Quaternion *q3; // [esp+A0h] [ebp-14h]
  Vector p; // [esp+A4h] [ebp-10h]
  float retaddr; // [esp+B4h] [ebp+0h]

  p.y = ebp0;
  p.z = retaddr;
  procindex = pbones[ibone].procindex;
  v23 = &pbones[ibone];
  if ( procindex != 0 )
    procindex += (int)&pbones[ibone];
  m_pBones = bonetoworld->m_pBones;
  p_parent = &pbones[*(_DWORD *)procindex].parent;
  v7 = *(_DWORD *)(procindex + 4);
  v8 = &m_pBones[*(_DWORD *)procindex];
  if ( *p_parent == -1 )
  {
    v11 = v8->m_flMatVal[0][v7];
    v24 = v11;
    v10 = v8->m_flMatVal[1][*(_DWORD *)(procindex + 4)];
    v25 = v10;
    v9 = v8->m_flMatVal[2][*(_DWORD *)(procindex + 4)];
    v26 = v9;
  }
  else
  {
    v.y = v8->m_flMatVal[0][v7];
    v.z = v8->m_flMatVal[1][v7];
    v.w = v8->m_flMatVal[2][v7];
    VectorIRotate(in1: &v.y, in2: &m_pBones[*p_parent], out: &v24);
    v9 = v26;
    v10 = v25;
    v11 = v24;
  }
  *(float *)&p1 = v11;
  control.z = v10;
  p.x = v9;
  if ( v11 < 0.0 )
  {
    v11 = -v11;
    *(float *)&p1 = v11;
    v12 = (const Quaternion *)(procindex + 96);
    LODWORD(control.x) = procindex + 20;
  }
  else
  {
    v12 = (const Quaternion *)(procindex + 80);
    LODWORD(control.x) = procindex + 8;
  }
  if ( v10 < 0.0 )
  {
    v10 = -v10;
    control.z = v10;
    v13 = (const Quaternion *)(procindex + 128);
    v14 = (float *)(procindex + 44);
  }
  else
  {
    v13 = (const Quaternion *)(procindex + 112);
    v14 = (float *)(procindex + 32);
  }
  if ( v9 < 0.0 )
  {
    v15 = (const Quaternion *)(procindex + 160);
    v9 = -v9;
    p.x = v9;
    t = (const Quaternion *)(procindex + 160);
    v16 = (float *)(procindex + 68);
  }
  else
  {
    v15 = (const Quaternion *)(procindex + 144);
    t = (const Quaternion *)(procindex + 144);
    v16 = (float *)(procindex + 56);
  }
  v17 = v10 + v11;
  if ( v17 <= 0.0 )
  {
    QuaternionSlerp(p: v15, q: v15, t: 0.0, qt: (Quaternion *)&tmp.y);
    a2 = *v16;
    a1 = v16[1];
    v18 = v16[2];
  }
  else
  {
    control.y = 1.0 / (float)(v17 + v9);
    QuaternionSlerp(p: v13, q: v12, t: v11 / v17, qt: (Quaternion *)&bonematrix.m_flMatVal[2][1]);
    p.x = control.y * p.x;
    QuaternionSlerp(p: (const Quaternion *)&bonematrix.m_flMatVal[2][1], q: t, t: p.x, qt: (Quaternion *)&tmp.y);
    a2 = *(float *)LODWORD(control.x) * (float)(control.y * *(float *)&p1);
    a1 = *(float *)(LODWORD(control.x) + 4) * (float)(control.y * *(float *)&p1);
    *(float *)&q3 = *(float *)(LODWORD(control.x) + 8) * (float)(control.y * *(float *)&p1);
    a2 = (float)((float)(control.y * control.z) * *v14) + a2;
    a1 = (float)(v14[1] * (float)(control.y * control.z)) + a1;
    *(float *)&q3 = (float)(v14[2] * (float)(control.y * control.z)) + *(float *)&q3;
    a2 = (float)(p.x * *v16) + a2;
    a1 = (float)(v16[1] * p.x) + a1;
    v18 = (float)(v16[2] * p.x) + *(float *)&q3;
  }
  *(float *)&q3 = v18;
  QuaternionMatrix(q: (Quaternion *)&tmp.y, pos: (const Vector *)&a2, matrix: (matrix3x4_t *)v19);
  ConcatTransforms(
    in1: &bonetoworld->m_pBones[v23->parent],
    in2: (const matrix3x4_t *)v19,
    out: &bonetoworld->m_pBones[ibone]);
}

//------------------------------------------------------------------------------
// Address: 0x102AF8B0
// Name: void DoAimAtBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall DoAimAtBone(
        float a1@<ebp>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld,
        CStudioHdr *pStudioHdr)
{
  mstudiobone_t *v5; // esi
  int procindex; // eax
  char *v7; // esi
  const mstudioattachment_t *v8; // eax
  float v9; // xmm3_4
  __int128 v10; // xmm4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  __int128 v20; // xmm6
  float v21; // xmm3_4
  double v22; // xmm0_8
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm6_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  __int128 v41; // xmm4
  float v42; // xmm5_4
  _BYTE v43[12]; // [esp+18h] [ebp-1CCh] BYREF
  matrix3x4a_t boneLocalToWorld; // [esp+24h] [ebp-1C0h] BYREF
  matrix3x4a_t parentSpace; // [esp+54h] [ebp-190h] BYREF
  matrix3x4a_t aimRotationMatrix; // [esp+84h] [ebp-160h] BYREF
  matrix3x4a_t bonematrix; // [esp+B4h] [ebp-130h] BYREF
  matrix3x4a_t aimAtSpace; // [esp+E4h] [ebp-100h] BYREF
  matrix3x4a_t boneMatrix; // [esp+114h] [ebp-D0h] BYREF
  Quaternion boneRotation; // [esp+14Ch] [ebp-98h] BYREF
  Quaternion upRotation; // [esp+15Ch] [ebp-88h] BYREF
  Quaternion aimRotation; // [esp+16Ch] [ebp-78h] BYREF
  Vector tmp_pUp; // [esp+17Ch] [ebp-68h] BYREF
  Vector aimAtWorldPosition; // [esp+188h] [ebp-5Ch] BYREF
  float v55; // [esp+194h] [ebp-50h]
  __int128 aimWorldPosition; // [esp+198h] [ebp-4Ch] OVERLAPPED BYREF
  __int128 tmp_pParentUp; // [esp+1A8h] [ebp-3Ch] OVERLAPPED
  Vector pUp; // [esp+1B8h] [ebp-2Ch]
  float v59; // [esp+1C4h] [ebp-20h]
  Vector pParentUp; // [esp+1C8h] [ebp-1Ch] BYREF
  float v61; // [esp+1D4h] [ebp-10h]
  Vector axis; // [esp+1D8h] [ebp-Ch]
  float retaddr; // [esp+1E4h] [ebp+0h]

  axis.x = a1;
  axis.y = retaddr;
  v5 = &pBones[iBone];
  procindex = v5->procindex;
  LODWORD(aimAtWorldPosition.x) = v5;
  if ( procindex != 0 )
  {
    v7 = (char *)v5 + procindex;
    if ( v7 != nullptr )
    {
      MatrixCopy(in: &bonetoworld->m_pBones[*(_DWORD *)v7], out: (matrix3x4a_t *)&boneLocalToWorld.m_flMatVal[2][1]);
      VectorTransform(
        in1: (const float *)v7 + 8,
        in2: (matrix3x4a_t *)&boneLocalToWorld.m_flMatVal[2][1],
        out: &aimAtWorldPosition.y);
      if ( pStudioHdr != nullptr )
      {
        v8 = CStudioHdr::pAttachment(this: pStudioHdr, i: *((_DWORD *)v7 + 1));
        ConcatTransforms(
          in1: &bonetoworld->m_pBones[v8->localbone],
          in2: &v8->local,
          out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
      }
      else
      {
        MatrixCopy(in: &bonetoworld->m_pBones[*((_DWORD *)v7 + 1)], out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
      }
      MatrixGetColumn(in: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1], column: 3, out: &tmp_pUp);
      QuaternionAngles(
        q: (const Quaternion *)(LODWORD(aimAtWorldPosition.x) + 44),
        angles: (RadianEuler *)((char *)&aimWorldPosition + 4));
      AngleMatrix(
        angles: (const RadianEuler *)((char *)&aimWorldPosition + 4),
        position: (const Vector *)(v7 + 32),
        matrix: (matrix3x4a_t *)&aimRotationMatrix.m_flMatVal[2][1]);
      ConcatTransforms_Aligned(
        m0: &bonetoworld->m_pBones[*(_DWORD *)v7],
        m1: (matrix3x4a_t *)&aimRotationMatrix.m_flMatVal[2][1],
        out: (matrix3x4a_t *)v43);
      v9 = (float)((float)((float)((float)(tmp_pUp.x - aimAtWorldPosition.y) * (float)(tmp_pUp.x - aimAtWorldPosition.y))
                         + 0.00000011920929)
                 + (float)((float)(tmp_pUp.y - aimAtWorldPosition.z) * (float)(tmp_pUp.y - aimAtWorldPosition.z)))
         + (float)((float)(tmp_pUp.z - v55) * (float)(tmp_pUp.z - v55));
      v10 = 0;
      *(float *)&v10 = 1.0 / fsqrt(v9);
      aimWorldPosition = v10;
      v11 = (float)(3.0 - (float)((float)(*(float *)&aimWorldPosition * v9) * *(float *)&aimWorldPosition))
          * (float)(*(float *)&aimWorldPosition * 0.5);
      v12 = (float)(tmp_pUp.x - aimAtWorldPosition.y) * v11;
      v13 = (float)(tmp_pUp.z - v55) * v11;
      v14 = (float)(tmp_pUp.y - aimAtWorldPosition.z) * v11;
      pParentUp.y = (float)(v13 * *((float *)v7 + 3)) - (float)(v14 * *((float *)v7 + 4));
      v15 = (float)(*((float *)v7 + 4) * v12) - (float)(*((float *)v7 + 2) * v13);
      v59 = v13;
      pParentUp.z = v15;
      v16 = *((float *)v7 + 2);
      v17 = *((float *)v7 + 3);
      pUp.y = v12;
      pUp.z = v14;
      v18 = (float)(v16 * v14) - (float)(v17 * v12);
      v19 = (float)((float)((float)(pParentUp.y * pParentUp.y) + 0.00000011920929) + (float)(v15 * v15))
          + (float)(v18 * v18);
      v20 = 0;
      *(float *)&v20 = 1.0 / fsqrt(v19);
      aimWorldPosition = v20;
      v21 = (float)(3.0 - (float)((float)(*(float *)&aimWorldPosition * v19) * *(float *)&aimWorldPosition))
          * (float)(*(float *)&aimWorldPosition * 0.5);
      pParentUp.y = pParentUp.y * v21;
      pParentUp.z = v15 * v21;
      v61 = v18 * v21;
      v22 = (float)((float)((float)(v14 * *((float *)v7 + 3)) + (float)(*((float *)v7 + 2) * v12))
                  + (float)(v59 * *((float *)v7 + 4)));
      __libm_sse2_acos();
      *(float *)&v22 = v22;
      AxisAngleQuaternion(
        axis: (Vector *)&pParentUp.y,
        angle: *(float *)&v22 * 57.29578,
        q: (Quaternion *)&upRotation.y);
      if ( (float)(1.0
                 - COERCE_FLOAT(
                     COERCE_UNSIGNED_INT(
                       (float)((float)(*((float *)v7 + 6) * *((float *)v7 + 3))
                             + (float)(*((float *)v7 + 2) * *((float *)v7 + 5)))
                     + (float)(*((float *)v7 + 7) * *((float *)v7 + 4)))
                   & _mask__AbsFloat_)) <= 0.00000011920929 )
      {
        QuaternionMatrix(
          q: (Quaternion *)&upRotation.y,
          pos: (Vector *)&aimAtWorldPosition.y,
          matrix: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1]);
      }
      else
      {
        QuaternionMatrix(q: (Quaternion *)&upRotation.y, matrix: (matrix3x4a_t *)&parentSpace.m_flMatVal[2][1]);
        VectorRotate(
          in1: (const float *)v7 + 5,
          in2: (matrix3x4a_t *)&parentSpace.m_flMatVal[2][1],
          out: &aimRotation.y);
        v23 = (float)((float)(aimRotation.z * pUp.z) + (float)(aimRotation.y * pUp.y)) + (float)(aimRotation.w * v59);
        v24 = aimRotation.y - (float)(v23 * pUp.y);
        v25 = aimRotation.z - (float)(pUp.z * v23);
        v26 = aimRotation.w - (float)(v59 * v23);
        v27 = (float)((float)((float)(v24 * v24) + 0.00000011920929) + (float)(v25 * v25)) + (float)(v26 * v26);
        *(float *)&tmp_pParentUp = 1.0 / fsqrt(v27);
        v28 = (float)(3.0 - (float)((float)(*(float *)&tmp_pParentUp * v27) * *(float *)&tmp_pParentUp))
            * (float)(*(float *)&tmp_pParentUp * 0.5);
        *((float *)&tmp_pParentUp + 1) = v24 * v28;
        *((float *)&tmp_pParentUp + 2) = v25 * v28;
        *((float *)&tmp_pParentUp + 3) = v26 * v28;
        VectorRotate(in1: (const float *)v7 + 5, in2: (const matrix3x4_t *)v43, out: (float *)&aimWorldPosition + 1);
        v29 = (float)((float)(*((float *)&aimWorldPosition + 2) * pUp.z)
                    + (float)(*((float *)&aimWorldPosition + 1) * pUp.y))
            + (float)(*((float *)&aimWorldPosition + 3) * v59);
        v30 = *((float *)&aimWorldPosition + 1) - (float)(v29 * pUp.y);
        v31 = *((float *)&aimWorldPosition + 3) - (float)(v59 * v29);
        v32 = *((float *)&aimWorldPosition + 2) - (float)(pUp.z * v29);
        v33 = (float)((float)((float)(v30 * v30) + 0.00000011920929) + (float)(v32 * v32)) + (float)(v31 * v31);
        pUp.x = 1.0 / fsqrt(v33);
        v34 = (float)(3.0 - (float)((float)(pUp.x * v33) * pUp.x)) * (float)(pUp.x * 0.5);
        pUp.y = v30 * v34;
        pUp.z = v32 * v34;
        v59 = v31 * v34;
        v35 = (float)((float)((float)(v32 * v34) * *((float *)&tmp_pParentUp + 2))
                    + (float)((float)(v30 * v34) * *((float *)&tmp_pParentUp + 1)))
            + (float)((float)(v31 * v34) * *((float *)&tmp_pParentUp + 3));
        if ( (float)(1.0 - COERCE_FLOAT(LODWORD(v35) & _mask__AbsFloat_)) <= 0.00000011920929 )
        {
          v36 = 0.0;
          v39 = *((float *)&tmp_pParentUp + 2);
          v38 = *((float *)&tmp_pParentUp + 3);
          v37 = *((float *)&tmp_pParentUp + 1);
        }
        else
        {
          __libm_sse2_acos();
          v36 = v35;
          v37 = (float)(v59 * *((float *)&tmp_pParentUp + 2)) - (float)(pUp.z * *((float *)&tmp_pParentUp + 3));
          v38 = (float)(pUp.z * *((float *)&tmp_pParentUp + 1)) - (float)(*((float *)&tmp_pParentUp + 2) * pUp.y);
          v39 = (float)(*((float *)&tmp_pParentUp + 3) * pUp.y) - (float)(v59 * *((float *)&tmp_pParentUp + 1));
        }
        v40 = (float)((float)((float)(v37 * v37) + 0.00000011920929) + (float)(v39 * v39)) + (float)(v38 * v38);
        v41 = 0;
        *(float *)&v41 = 1.0 / fsqrt(v40);
        tmp_pParentUp = v41;
        v42 = (float)(3.0 - (float)((float)(*(float *)&v41 * v40) * *(float *)&tmp_pParentUp))
            * (float)(*(float *)&tmp_pParentUp * 0.5);
        pParentUp.y = v42 * v37;
        pParentUp.z = v39 * v42;
        v61 = v38 * v42;
        AxisAngleQuaternion(axis: (Vector *)&pParentUp.y, angle: v36 * 57.29578, q: (Quaternion *)&boneRotation.y);
        QuaternionMult(
          p: (Quaternion *)&boneRotation.y,
          q: (Quaternion *)&upRotation.y,
          qt: (Quaternion *)&boneMatrix.m_flMatVal[2][3]);
        QuaternionMatrix(
          q: (const Quaternion *)&boneMatrix.m_flMatVal[2][3],
          pos: (Vector *)&aimAtWorldPosition.y,
          matrix: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1]);
      }
      MatrixCopy(in: (matrix3x4a_t *)&aimAtSpace.m_flMatVal[2][1], out: &bonetoworld->m_pBones[iBone]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFF60
// Name: void DoTwistBones(struct mstudiobone_t __near *,int,class CBoneAccessor __near &,class CStudioHdr const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoTwistBones(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        mstudiobone_t *pBones,
        int iBone,
        CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v6; // eax
  int procindex; // esi
  long double v8; // rdi
  int v9; // eax
  matrix3x4a_t *m_pBones; // ecx
  int v11; // edi
  bool v12; // sf
  _DWORD *v13; // eax
  void *v14; // esp
  void *v15; // esp
  void *v16; // esp
  int v17; // ecx
  _QWORD *p_x; // edx
  char *v19; // eax
  double v20; // st7
  _DWORD v21[4]; // [esp-E0h] [ebp-ECh] BYREF
  matrix3x4a_t v22; // [esp-D0h] [ebp-DCh] BYREF
  matrix3x4a_t v23; // [esp-A0h] [ebp-ACh] BYREF
  matrix3x4_t v24; // [esp-70h] [ebp-7Ch] BYREF
  RadianEuler v25; // [esp-3Ch] [ebp-48h] BYREF
  Quaternion v26; // [esp-30h] [ebp-3Ch] BYREF
  _DWORD *v27; // [esp-14h] [ebp-20h]
  const matrix3x4a_t *v28; // [esp-10h] [ebp-1Ch]
  const float *v29; // [esp-Ch] [ebp-18h]
  const Quaternion *v30; // [esp-8h] [ebp-14h]
  const Quaternion *v31; // [esp-4h] [ebp-10h]
  int i; // [esp+0h] [ebp-Ch]
  void *v33; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  i = a1;
  v33 = retaddr;
  v6 = &pBones[iBone];
  v21[1] = a3;
  procindex = v6->procindex;
  v21[0] = a2;
  if ( procindex != 0 )
  {
    HIDWORD(v8) = (char *)v6 + procindex;
    if ( HIDWORD(v8) != 0 )
    {
      v9 = *(_DWORD *)(HIDWORD(v8) + 16);
      m_pBones = bonetoworld->m_pBones;
      v11 = v9;
      v9 *= 216;
      LODWORD(v8) = &m_pBones[v11];
      v12 = *(int *)((char *)&pBones->parent + v9) < 0;
      v13 = (int *)((char *)&pBones->parent + v9);
      v28 = (const matrix3x4a_t *)LODWORD(v8);
      if ( v12 )
      {
        MatrixQuaternion(mat: (const matrix3x4_t *)LODWORD(v8), q: &v26);
      }
      else
      {
        MatrixInvert(in: &m_pBones[*v13], out: &v24);
        ConcatTransforms_Aligned(m0: (const matrix3x4a_t *)&v24, m1: (const matrix3x4a_t *)LODWORD(v8), out: &v23);
        MatrixQuaternion(mat: &v23, q: &v26);
      }
      MatrixInvert(in: (const matrix3x4_t *)LODWORD(v8), out: &v24);
      ConcatTransforms_Aligned(
        m0: (const matrix3x4a_t *)&v24,
        m1: &bonetoworld->m_pBones[*(_DWORD *)(HIDWORD(v8) + 36)],
        out: &v22);
      LODWORD(v8) = *(_DWORD *)(HIDWORD(v8) + 40);
      v14 = alloca(4 * LODWORD(v8));
      LODWORD(v8) = (16 * LODWORD(v8) + 15) & 0xFFFFFFF0;
      v29 = (const float *)v21;
      v15 = alloca(SLODWORD(v8));
      v31 = (const Quaternion *)v21;
      v16 = alloca(SLODWORD(v8));
      v17 = 0;
      LODWORD(v8) = v21;
      v27 = v21;
      if ( *(int *)(HIDWORD(v8) + 40) > 0 )
      {
        p_x = (_QWORD *)&v31->x;
        v30 = nullptr;
        do
        {
          v19 = (char *)v30 + *(_DWORD *)(HIDWORD(v8) + 44);
          v20 = *(float *)&v19[HIDWORD(v8) + 4];
          v30 = (const Quaternion *)((char *)v30 + 36);
          v29[v17] = v20;
          *p_x = *(_QWORD *)&v19[HIDWORD(v8) + 20];
          p_x[1] = *(_QWORD *)&v19[HIDWORD(v8) + 28];
          ++v17;
          p_x += 2;
        }
        while ( v17 < *(_DWORD *)(HIDWORD(v8) + 40) );
        LODWORD(v8) = v27;
      }
      _V_memcpy(dest: (void *)LODWORD(v8), src: v31, count: 16 * *(_DWORD *)(HIDWORD(v8) + 40));
      ComputeTwistBones(
        a1: v8,
        pqTwists: (Quaternion *)LODWORD(v8),
        nCount: *(_DWORD *)(HIDWORD(v8) + 40),
        bInverse: *(_BYTE *)HIDWORD(v8),
        vUp: (const Vector *)(HIDWORD(v8) + 4),
        qParent: &v26,
        mChild: &v22,
        qBaseInv: (const Quaternion *)(HIDWORD(v8) + 20),
        pflWeights: v29,
        pqTwistBinds: v31);
      v29 = nullptr;
      if ( *(int *)(HIDWORD(v8) + 40) > 0 )
      {
        v31 = nullptr;
        v30 = (const Quaternion *)LODWORD(v8);
        do
        {
          LODWORD(v8) = (char *)v31 + *(_DWORD *)(HIDWORD(v8) + 44);
          QuaternionAngles(q: v30, angles: &v25);
          AngleMatrix(angles: &v25, position: (const Vector *)(LODWORD(v8) + HIDWORD(v8) + 8), matrix: &v24);
          ConcatTransforms_Aligned(
            m0: v28,
            m1: (const matrix3x4a_t *)&v24,
            out: &bonetoworld->m_pBones[*(_DWORD *)(LODWORD(v8) + HIDWORD(v8))]);
          v31 = (const Quaternion *)((char *)v31 + 36);
          ++v30;
          v29 = (const float *)((char *)v29 + 1);
        }
        while ( (int)v29 < *(_DWORD *)(HIDWORD(v8) + 40) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0170
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_99;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_99;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_98:
      BlendBones(pStudioHdr, q1: q, pos1: pos, seqdesc, sequence: v15, q2: v36, pos2: v37, s: v35, boneMask: v54);
      goto LABEL_99;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        goto LABEL_99;
      }
      if ( anim_3wayblend.m_pParent == nullptr || anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_98;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_98;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_99;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_99;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      pos2,
      s,
      boneMask);
    goto LABEL_99;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_99;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_99;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_99:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x102B0B50
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B0B90
// Name: void DoQuatInterpBone(struct mstudiobone_t __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall DoQuatInterpBone(float a1@<ebp>, mstudiobone_t *pbones, int ibone, CBoneAccessor *bonetoworld)
{
  int v4; // edx
  mstudiobone_t *v5; // eax
  int procindex; // esi
  _DWORD *v7; // esi
  int *p_parent; // ecx
  int v9; // edi
  long double v10; // st7
  float y; // xmm0_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // ecx
  float v15; // xmm0_4
  const Quaternion *v16; // edi
  matrix3x4a_t *v17; // [esp-24h] [ebp-184h]
  _DWORD v18[3]; // [esp-Ch] [ebp-16Ch]
  float weight[32]; // [esp+0h] [ebp-160h] BYREF
  matrix3x4a_t controlmatrix; // [esp+80h] [ebp-E0h] BYREF
  matrix3x4a_t tmpmatrix; // [esp+B0h] [ebp-B0h] BYREF
  matrix3x4a_t bonematrix; // [esp+E0h] [ebp-80h] BYREF
  Quaternion src; // [esp+110h] [ebp-50h] BYREF
  float v24; // [esp+120h] [ebp-40h]
  float *p_x; // [esp+124h] [ebp-3Ch]
  mstudiobone_t *v26; // [esp+128h] [ebp-38h]
  float s; // [esp+12Ch] [ebp-34h] BYREF
  float v28; // [esp+130h] [ebp-30h]
  float v29; // [esp+134h] [ebp-2Ch]
  Vector pos; // [esp+138h] [ebp-28h] BYREF
  Quaternion quat; // [esp+144h] [ebp-1Ch]
  float dot; // [esp+154h] [ebp-Ch]
  float scale; // [esp+158h] [ebp-8h]
  float retaddr; // [esp+160h] [ebp+0h]

  dot = a1;
  scale = retaddr;
  v4 = ibone;
  v5 = &pbones[ibone];
  procindex = v5->procindex;
  v26 = v5;
  if ( procindex != 0 )
  {
    v7 = (int *)((char *)&v5->sznameindex + procindex);
    if ( v7 != nullptr )
    {
      p_parent = &pbones[*v7].parent;
      if ( *p_parent != -1 )
      {
        v17 = &bonetoworld->m_pBones[*p_parent];
        quat.z = 0.0;
        MatrixInvert(in: v17, out: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1]);
        ConcatTransforms_Aligned(
          m0: (matrix3x4a_t *)&controlmatrix.m_flMatVal[2][1],
          m1: &bonetoworld->m_pBones[*v7],
          out: (matrix3x4a_t *)&weight[29]);
        MatrixAngles(
          matrix: (const matrix3x4_t *)&weight[29],
          q: (Quaternion *)&bonematrix.m_flMatVal[2][1],
          pos: (Vector *)&s);
        v9 = 0;
        if ( (int)v7[1] <= 0 )
        {
          z = quat.z;
        }
        else
        {
          quat.w = 0.0;
          do
          {
            v10 = fabs(
                    QuaternionDotProduct(
                      p: (const Quaternion *)((char *)v7 + LODWORD(quat.w) + v7[2] + 4),
                      q: (const Quaternion *)&bonematrix.m_flMatVal[2][1]));
            quat.y = v10;
            if ( v10 >= -1.0 )
            {
              y = quat.y;
              if ( quat.y > 1.0 )
                y = 1.0;
            }
            else
            {
              y = -1.0;
            }
            __libm_sse2_acos();
            v12 = 1.0 - (float)((float)(y * 2.0) * *(float *)((char *)v7 + LODWORD(quat.w) + v7[2]));
            *(float *)&v18[v9] = v12;
            if ( v12 < 0.0 )
              v12 = 0.0;
            LODWORD(quat.w) += 48;
            *(float *)&v18[v9] = v12;
            z = v12 + quat.z;
            ++v9;
            quat.z = z;
          }
          while ( v9 < v7[1] );
        }
        if ( z <= 0.001 )
        {
          QuaternionAngles(q: (const Quaternion *)((char *)v7 + v7[2] + 32), angles: (RadianEuler *)&src.y);
          AngleMatrix(
            angles: (const RadianEuler *)&src.y,
            position: (const Vector *)((char *)v7 + v7[2] + 20),
            matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
          ConcatTransforms(
            in1: &bonetoworld->m_pBones[v26->parent],
            in2: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
            out: &bonetoworld->m_pBones[ibone]);
          return;
        }
        v14 = 0.0;
        quat.z = 1.0 / z;
        memset((void *)&pos, 0, sizeof(pos));
        quat.x = 0.0;
        s = 0.0;
        v28 = 0.0;
        v29 = 0.0;
        quat.y = 0.0;
        if ( (int)v7[1] > 0 )
        {
          quat.w = 0.0;
          do
          {
            v15 = *(float *)&v18[LODWORD(v14)];
            if ( v15 != 0.0 )
            {
              v16 = (const Quaternion *)((char *)v7 + LODWORD(quat.w) + v7[2]);
              v24 = v15 * quat.z;
              p_x = &v16[2].x;
              QuaternionAlign(p: v16 + 2, q: (const Quaternion *)&pos, qt: (Quaternion *)&pos);
              pos.x = (float)(*p_x * v24) + pos.x;
              pos.y = (float)(v16[2].y * v24) + pos.y;
              v14 = quat.y;
              pos.z = (float)(v16[2].z * v24) + pos.z;
              quat.x = (float)(v16[2].w * v24) + quat.x;
              s = (float)(v16[1].y * v24) + s;
              v28 = (float)(v16[1].z * v24) + v28;
              v29 = (float)(v16[1].w * v24) + v29;
            }
            LODWORD(quat.w) += 48;
            ++LODWORD(v14);
            quat.y = v14;
          }
          while ( SLODWORD(v14) < v7[1] );
        }
        QuaternionMatrix(
          q: (const Quaternion *)&pos,
          pos: (const Vector *)&s,
          matrix: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1]);
        v5 = v26;
        v4 = ibone;
      }
    }
  }
  ConcatTransforms_Aligned(
    m0: &bonetoworld->m_pBones[v5->parent],
    m1: (matrix3x4a_t *)&tmpmatrix.m_flMatVal[2][1],
    out: &bonetoworld->m_pBones[v4]);
}

//------------------------------------------------------------------------------
// Address: 0x102B0F00
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0FF0
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x102B1010
// Name: void CalcBoneAdj(class CStudioHdr const __near *,class Vector __near * const,class Quaternion __near * const,float const __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcBoneAdj(
        const CStudioHdr *pStudioHdr,
        Vector *pos,
        Quaternion *q,
        const float *controllers,
        int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  Vector *p_y; // eax
  const Quaternion *v13; // [esp+8h] [ebp-34h]
  Quaternion *v14; // [esp+Ch] [ebp-30h]
  Quaternion q0; // [esp+1Ch] [ebp-20h] BYREF
  RadianEuler a0; // [esp+2Ch] [ebp-10h] BYREF
  int j; // [esp+38h] [ebp-4h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  v6 = 0;
  for ( j = 0; j < m_pStudioHdr->numbonecontrollers; ++j )
  {
    v7 = v6 + m_pStudioHdr->bonecontrollerindex;
    v8 = *(int *)((char *)&m_pStudioHdr->id + v7);
    v9 = (char *)m_pStudioHdr + v7;
    if ( (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v8]) != 0 )
    {
      v10 = controllers[*((_DWORD *)v9 + 5)];
      if ( v10 >= 0.0 )
      {
        if ( v10 > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = 0.0;
      }
      v11 = (float)((float)(1.0 - v10) * *((float *)v9 + 2)) + (float)(*((float *)v9 + 3) * v10);
      switch ( *((_DWORD *)v9 + 1) & 0x3FFFF )
      {
        case 1:
          p_y = &pos[v8];
          goto LABEL_15;
        case 2:
          p_y = (Vector *)&pos[v8].y;
          goto LABEL_15;
        case 4:
          p_y = (Vector *)&pos[v8].z;
LABEL_15:
          p_y->x = p_y->x + v11;
          break;
        case 8:
          a0.x = v11 * 0.0174532925199433;
          a0.y = 0.0;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x10:
          a0.x = 0.0;
          a0.y = v11 * 0.0174532925199433;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x20:
          a0.x = 0.0;
          a0.y = 0.0;
          a0.z = v11 * 0.0174532925199433;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
LABEL_9:
          QuaternionSM(s: 1.0, p: &q0, q: v13, qt: v14);
          break;
        default:
          break;
      }
    }
    m_pStudioHdr = pStudioHdr->m_pStudioHdr;
    v6 += 56;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B1210
// Name: bool CalcProceduralBone(class CStudioHdr const __near *,int,class CBoneAccessor __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcProceduralBone(const CStudioHdr *pStudioHdr, int iBone, CBoneAccessor *bonetoworld)
{
  mstudiobone_t *v3; // eax
  bool result; // al

  v3 = (mstudiobone_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->boneindex);
  if ( (pStudioHdr->m_boneFlags.m_Memory.m_pMemory[iBone] & 4) == 0 )
    return false;
  switch ( v3[iBone].proctype )
  {
    case 1:
      DoAxisInterpBone(pbones: v3, ibone: iBone, bonetoworld);
      goto $LN2_56;
    case 2:
      DoQuatInterpBone(pbones: v3, ibone: iBone, bonetoworld);
      return true;
    case 3:
      DoAimAtBone(pBones: v3, iBone, bonetoworld, pStudioHdr: nullptr);
      return true;
    case 4:
      DoAimAtBone(pBones: v3, iBone, bonetoworld, pStudioHdr);
      return true;
    case 6:
      DoTwistBones(pBones: v3, iBone, bonetoworld, pStudioHdr);
      return true;
    case 7:
$LN2_56:
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B12D0
// Name: public: void IBoneSetup::CalcBoneAdj(class Vector __near * const,class Quaternion __near * const,float const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcBoneAdj(IBoneSetup *this, Vector *pos, Quaternion *q, const float *controllers)
{
  CalcBoneAdj(
    pStudioHdr: this->m_pBoneSetup->m_pStudioHdr,
    pos,
    q,
    controllers,
    boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x102B1300
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  long double v10; // rdi
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *v14; // ecx
  CIKContext *v15; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v17; // [esp+50h] [ebp-108Ch] BYREF
  float v18; // [esp+10C4h] [ebp-18h]
  Vector *v19; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v20; // [esp+10CCh] [ebp-10h]
  _DWORD v21[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v21[0] = a2;
  v21[1] = retaddr;
  v9 = alloca(4232);
  HIDWORD(v10) = this;
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v18 = flWeight;
    else
      v18 = 1.0;
  }
  else
  {
    v18 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v19 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v19 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v19 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v19 = nullptr;
      }
      if ( ((unsigned __int8)v19 & 0xF) != 0 )
        __debugbreak();
    }
    v20 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v20 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    if ( *(_DWORD *)(HIDWORD(v10) + 12) != 0 )
      (*(void (__stdcall **)(_DWORD, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, _DWORD, _DWORD, float, _DWORD))(**(_DWORD **)(HIDWORD(v10) + 12) + 4))(
        a1: *(_DWORD *)HIDWORD(v10),
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: *(_DWORD *)(HIDWORD(v10) + 8),
        a8: *(_DWORD *)(HIDWORD(v10) + 4),
        a9: COERCE_FLOAT(LODWORD(v18)),
        a10: LODWORD(flTime));
    v14 = *(CStudioHdr **)HIDWORD(v10);
    if ( *(_DWORD *)(*(_DWORD *)HIDWORD(v10) + 4) != 0 )
    {
      LODWORD(v10) = CStudioHdr::pSeqdesc_Internal(this: v14, i: sequence);
    }
    else
    {
      if ( sequence >= v14->m_pStudioHdr->numlocalseq )
        v11 = 0;
      LODWORD(v10) = (char *)v14->m_pStudioHdr + 212 * v11 + v14->m_pStudioHdr->localseqindex;
    }
    CIKContext::CIKContext(this: &v17);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
    {
      CIKContext::Init(
        this: &v17,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
      CIKContext::AddSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    }
    if ( (*(_DWORD *)(LODWORD(v10) + 12) & 0x200) != 0 )
      InitPose(
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        pos: v19,
        q: v20,
        boneMask: *(_DWORD *)(HIDWORD(v10) + 4));
    if ( CalcPoseSingle(
           pStudioHdr: *(CStudioHdr **)HIDWORD(v10),
           pos: v19,
           q: v20,
           seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
           sequence,
           cycle,
           poseParameter: *(const float **)(HIDWORD(v10) + 8),
           boneMask: *(_DWORD *)(HIDWORD(v10) + 4),
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this: (CBoneSetup *)HIDWORD(v10),
        pos: v19,
        q: v20,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = *(_DWORD *)(HIDWORD(v10) + 4);
      *(float *)&s = v18;
      SlerpBones(
        a1: COERCE_FLOAT(v21),
        a2: v10,
        pStudioHdr: *(const CStudioHdr **)HIDWORD(v10),
        q1: q,
        pos1: pos,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        sequence,
        q2: v20,
        pos2: v19,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v19);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    v15 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: *(const float **)(HIDWORD(v10) + 8),
        flWeight: v18);
      v15 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(
      this: (CBoneSetup *)HIDWORD(v10),
      pos,
      q,
      seqdesc: (mstudioseqdesc_t *)LODWORD(v10),
      sequence,
      cycle,
      flWeight: v18,
      flTime,
      pIKContext: v15);
    if ( *(_DWORD *)(LODWORD(v10) + 164) != 0 )
      CIKContext::SolveSequenceLocks(this: &v17, seqdesc: (mstudioseqdesc_t *)LODWORD(v10), pos, q);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v17.m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &v17.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B1650
// Name: public: void CBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::CalcAutoplaySequences(
        CBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CIKContext *v5; // esi
  int v6; // ebx
  const CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v9; // ecx
  int v10; // esi
  const studiohdr_t *v11; // ecx
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  double v14; // st7
  float v15; // [esp+0h] [ebp-28h]
  int count; // [esp+1Ch] [ebp-Ch]
  float cycle; // [esp+20h] [ebp-8h]
  unsigned __int16 *pList; // [esp+24h] [ebp-4h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v5 = pIKContext;
  v6 = 0;
  if ( pIKContext != nullptr )
    CIKContext::AddAutoplayLocks(this: pIKContext, pos, q);
  m_pStudioHdr = this->m_pStudioHdr;
  pList = nullptr;
  count = studiohdr_t::GetAutoplayList(this: m_pStudioHdr->m_pStudioHdr, pOut: &pList);
  if ( count > 0 )
  {
    do
    {
      v9 = (CStudioHdr *)this->m_pStudioHdr;
      v10 = pList[v6];
      if ( this->m_pStudioHdr->m_pVModel != nullptr )
      {
        v13 = CStudioHdr::pSeqdesc_Internal(this: v9, i: pList[v6]);
      }
      else
      {
        v11 = v9->m_pStudioHdr;
        v12 = pList[v6];
        if ( v10 >= v11->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v11 + 212 * v12 + v11->localseqindex);
      }
      if ( (v13->flags & 8) != 0 )
      {
        v14 = Studio_CPS(
                pStudioHdr: this->m_pStudioHdr,
                seqdesc: v13,
                iSequence: v10,
                poseParameter: this->m_flPoseParameter)
            * flRealTime;
        cycle = v14;
        v15 = v14 - (double)(int)cycle;
        CBoneSetup::AccumulatePose(
          this,
          a2: (int)&savedregs,
          pos,
          q,
          sequence: v10,
          cycle: v15,
          flWeight: 1.0,
          flTime: flRealTime,
          pIKContext);
      }
      ++v6;
    }
    while ( v6 < count );
    v5 = pIKContext;
  }
  if ( v5 != nullptr )
    CIKContext::SolveAutoplayLocks(this: v5, pos, q);
}

//------------------------------------------------------------------------------
// Address: 0x102B1750
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

//------------------------------------------------------------------------------
// Address: 0x102B17A0
// Name: public: void IBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcAutoplaySequences(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CBoneSetup::CalcAutoplaySequences(this: this->m_pBoneSetup, pos, q, flRealTime, pIKContext);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10341720
// Name: bool PoseIsAllZeros(class CStudioHdr const __near *,int,struct mstudioseqdesc_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PoseIsAllZeros(CStudioHdr *pStudioHdr, int sequence, mstudioseqdesc_t *seqdesc, int i0, int i1)
{
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  const studiohdr_t *m_pStudioHdr; // esi

  v5 = seqdesc->groupsize[0];
  v6 = i1;
  v7 = i0;
  if ( i0 >= v5 )
    v7 = v5 - 1;
  v8 = seqdesc->groupsize[1];
  if ( i1 >= v8 )
    v6 = v8 - 1;
  v9 = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v7 + 2 * v6 * v5 + seqdesc->animindexindex);
  if ( pStudioHdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::iRelativeAnim_Internal(this: pStudioHdr, baseseq: sequence, relanim: v9);
    if ( pStudioHdr->m_pVModel != nullptr )
      return (CStudioHdr::pAnimdesc_Internal(this: pStudioHdr, i: v9)->flags & 0x20) != 0;
  }
  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  if ( v9 < 0 || v9 >= m_pStudioHdr->numlocalanim )
    v9 = 0;
  return (*(_DWORD *)&m_pStudioHdr->name[100 * v9 + m_pStudioHdr->localanimindex] & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103417B0
// Name: void Calc3WayBlendIndices(int,int,float,float,struct mstudioseqdesc_t const __near &,int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Calc3WayBlendIndices(
        int i0,
        int i1,
        float s0,
        float s1,
        const mstudioseqdesc_t *seqdesc,
        int *pAnimIndices,
        float *pWeight)
{
  int v7; // edi
  float *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // edi
  int v16; // edx
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int v20; // edx
  int v21; // ebx
  int v22; // [esp+0h] [ebp-Ch]
  int x3; // [esp+4h] [ebp-8h]
  int y3; // [esp+8h] [ebp-4h]
  float *pWeighta; // [esp+2Ch] [ebp+20h]

  if ( (((_BYTE)i0 + (_BYTE)i1) & 1) != 0 )
  {
    if ( (float)(s0 + s1) > 1.0 )
    {
      v9 = 1;
      v7 = 1;
      v11 = 1;
      y3 = 1;
      v8 = pWeight;
      v10 = 0;
      x3 = 0;
      *pWeight = 1.0 - s1;
      pWeight[1] = (float)(s0 - 1.0) + s1;
      goto LABEL_9;
    }
    v9 = 0;
    v10 = 1;
    x3 = 1;
    v8 = pWeight;
    v7 = 0;
    y3 = 0;
    *pWeight = s1;
    pWeight[1] = (float)(1.0 - s0) - s1;
  }
  else
  {
    if ( s0 <= s1 )
    {
      v9 = 1;
      v10 = 1;
      v11 = 1;
      v7 = 0;
      x3 = 0;
      y3 = 0;
      v8 = pWeight;
      *pWeight = s0;
      pWeight[1] = s1 - s0;
      goto LABEL_9;
    }
    v7 = 1;
    x3 = 1;
    y3 = 1;
    v8 = pWeight;
    v9 = 0;
    v10 = 0;
    *pWeight = 1.0 - s0;
    pWeight[1] = s0 - s1;
  }
  v11 = 0;
LABEL_9:
  v22 = i1 + v10;
  v12 = seqdesc->groupsize[0];
  pWeighta = (float *)(v9 + i0);
  if ( v9 + i0 >= v12 )
    pWeighta = (float *)(v12 - 1);
  v13 = seqdesc->groupsize[1];
  v14 = v22;
  if ( v22 >= v13 )
    v14 = v13 - 1;
  v15 = i0 + v7;
  v16 = i1 + v11;
  *pAnimIndices = *(__int16 *)((char *)&seqdesc->baseptr
                             + 2 * ((_DWORD)pWeighta + v14 * seqdesc->groupsize[0])
                             + seqdesc->animindexindex);
  if ( v15 >= seqdesc->groupsize[0] )
    v15 = seqdesc->groupsize[0] - 1;
  v17 = seqdesc->groupsize[1];
  if ( v16 >= v17 )
    v16 = v17 - 1;
  v18 = v15 + v16 * seqdesc->groupsize[0];
  v19 = y3 + i1;
  pAnimIndices[1] = *(__int16 *)((char *)&seqdesc->baseptr + 2 * v18 + seqdesc->animindexindex);
  v20 = i0 + x3;
  if ( i0 + x3 >= seqdesc->groupsize[0] )
    v20 = seqdesc->groupsize[0] - 1;
  v21 = seqdesc->groupsize[1];
  if ( v19 >= v21 )
    v19 = v21 - 1;
  pAnimIndices[2] = *(__int16 *)((char *)&seqdesc->baseptr
                               + 2 * v20
                               + 2 * v19 * seqdesc->groupsize[0]
                               + seqdesc->animindexindex);
  if ( v8[1] < 0.001 )
    v8[1] = 0.0;
  v8[2] = (float)(1.0 - *v8) - v8[1];
}

//------------------------------------------------------------------------------
// Address: 0x10341960
// Name: public: struct mstudioseqdesc_t __near & mstudioseqdesc_t::operator=(struct mstudioseqdesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall mstudioseqdesc_t::operator=(mstudioseqdesc_t *this, const mstudioseqdesc_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10341B30
// Name: private: void CBoneSetup::AddSequenceLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddSequenceLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  mstudioseqdesc_t *v9; // edi
  int v10; // esi
  float v12; // xmm5_4
  float v13; // xmm2_4
  __int16 *v14; // esi
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // eax
  int SharedPoseParameter; // eax
  int v19; // edi
  const mstudioposeparamdesc_t *v20; // eax
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  int v25; // eax
  int v26; // eax
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  float layerCycle; // [esp+24h] [ebp-Ch]
  float layerWeight; // [esp+2Ch] [ebp-4h]

  v9 = seqdesc;
  v10 = 0;
  i = 0;
  if ( seqdesc->numautolayers > 0 )
  {
    v12 = flWeight;
    for ( j = 0; ; j += 24 )
    {
      v13 = cycle;
      v14 = (__int16 *)((char *)v9 + v10 + v9->autolayerindex);
      v15 = *((_DWORD *)v14 + 1);
      if ( (v15 & 0x1000) == 0 )
        break;
LABEL_29:
      v10 = j + 24;
      if ( ++i >= v9->numautolayers )
        return;
    }
    layerCycle = cycle;
    layerWeight = v12;
    if ( *((float *)v14 + 2) == *((float *)v14 + 5) )
    {
LABEL_28:
      v26 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      CBoneSetup::AccumulatePose(
        this,
        pos,
        q,
        sequence: v26,
        cycle: layerCycle,
        flWeight: layerWeight,
        flTime,
        pIKContext);
      v12 = flWeight;
      goto LABEL_29;
    }
    v16 = 1.0;
    if ( (v15 & 0x4000) != 0 )
    {
      v17 = CStudioHdr::iRelativeSeq(this: (CStudioHdr *)this->m_pStudioHdr, baseseq: sequence, relseq: *v14);
      SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                              this: (CStudioHdr *)this->m_pStudioHdr,
                              iSequence: v17,
                              iLocalPose: v14[1]);
      v19 = SharedPoseParameter;
      if ( SharedPoseParameter == -1 )
      {
        v13 = 0.0;
      }
      else
      {
        v20 = CStudioHdr::pPoseParameter(this: (CStudioHdr *)this->m_pStudioHdr, i: SharedPoseParameter);
        v13 = (float)((float)(v20->end - v20->start) * (float)this->m_flPoseParameter[v19]) + v20->start;
      }
      v9 = seqdesc;
      v12 = flWeight;
      v16 = 1.0;
    }
    v21 = *((float *)v14 + 2);
    if ( v21 > v13 )
      goto LABEL_29;
    v22 = *((float *)v14 + 5);
    if ( v13 >= v22 )
      goto LABEL_29;
    v23 = *((float *)v14 + 3);
    if ( v23 <= v13 || v21 == v23 )
    {
      v21 = *((float *)v14 + 4);
      if ( v13 <= v21 || v22 == v21 )
        goto LABEL_19;
      v23 = *((float *)v14 + 5);
      v24 = v23 - v13;
    }
    else
    {
      v24 = v13 - v21;
    }
    v16 = v24 / (float)(v23 - v21);
LABEL_19:
    v25 = *((_DWORD *)v14 + 1);
    if ( (v25 & 0x40) != 0 )
      v16 = (float)((float)(v16 * v16) * 3.0) - (float)((float)((float)(v16 * v16) * 2.0) * v16);
    if ( (v25 & 0x80u) == 0 || v13 <= *((float *)v14 + 4) )
    {
      if ( (v25 & 0x200) == 0 )
        v16 = v16 * v12;
    }
    else
    {
      v16 = (float)(v16 * v12) / (float)((float)(1.0 - v12) + (float)(v16 * v12));
    }
    layerWeight = v16;
    if ( (v25 & 0x4000) == 0 )
      layerCycle = (float)(cycle - *((float *)v14 + 2)) / (float)(v22 - *((float *)v14 + 2));
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10341D60
// Name: private: void CBoneSetup::AddLocalLayers(class Vector __near * const,class Quaternion __near * const,struct mstudioseqdesc_t __near &,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::AddLocalLayers(
        CBoneSetup *this,
        Vector *pos,
        Quaternion *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // edx
  float *v16; // ecx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int v22; // eax
  int i; // [esp+1Ch] [ebp-8h]
  float layerCycle; // [esp+20h] [ebp-4h]
  float layerWeight; // [esp+34h] [ebp+10h]

  if ( (seqdesc->flags & 0x200) != 0 )
  {
    v11 = 0;
    i = 0;
    if ( seqdesc->numautolayers > 0 )
    {
      v12 = flWeight;
      v13 = cycle;
      while ( 1 )
      {
        v14 = v11 + seqdesc->autolayerindex;
        v15 = *(int *)((char *)&seqdesc->szlabelindex + v14);
        v16 = (float *)((char *)&seqdesc->baseptr + v14);
        if ( (v15 & 0x1000) != 0 )
          break;
LABEL_24:
        v11 += 24;
        if ( ++i >= seqdesc->numautolayers )
          return;
      }
      v17 = v16[2];
      v18 = v16[5];
      layerCycle = v13;
      layerWeight = v12;
      if ( v17 == v18 )
      {
LABEL_23:
        v22 = CStudioHdr::iRelativeSeq(
                this: (CStudioHdr *)this->m_pStudioHdr,
                baseseq: sequence,
                relseq: *(__int16 *)v16);
        CBoneSetup::AccumulatePose(
          this,
          pos,
          q,
          sequence: v22,
          cycle: layerCycle,
          flWeight: layerWeight,
          flTime,
          pIKContext);
        v13 = cycle;
        v12 = flWeight;
        goto LABEL_24;
      }
      v19 = 1.0;
      if ( v17 > v13 || v13 >= v18 )
        goto LABEL_24;
      v20 = v16[3];
      if ( v20 <= v13 || v17 == v20 )
      {
        v17 = v16[4];
        if ( v13 <= v17 || v18 == v17 )
          goto LABEL_15;
        v20 = v16[5];
        v21 = v20 - v13;
      }
      else
      {
        v21 = v13 - v17;
      }
      v19 = v21 / (float)(v20 - v17);
LABEL_15:
      if ( (v15 & 0x40) != 0 )
        v19 = (float)((float)(v19 * v19) * 3.0) - (float)((float)((float)(v19 * v19) * 2.0) * v19);
      if ( (v15 & 0x80u) == 0 || v13 <= v16[4] )
      {
        if ( (v15 & 0x200) == 0 )
          v19 = v19 * v12;
      }
      else
      {
        v19 = (float)(v19 * v12) / (float)((float)(1.0 - v12) + (float)(v19 * v12));
      }
      layerWeight = v19;
      layerCycle = (float)(v13 - v16[2]) / (float)(v18 - v16[2]);
      goto LABEL_23;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10341F20
// Name: public: IBoneSetup::~IBoneSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::~IBoneSetup(IBoneSetup *this)
{
  if ( this->m_pBoneSetup != nullptr )
    free(pMem: this->m_pBoneSetup);
}

//------------------------------------------------------------------------------
// Address: 0x10341F30
// Name: void CalcBoneDerivatives(class Vector __near &,class Vector __near &,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcBoneDerivatives(
        Vector *velocity,
        Vector *angVel,
        const matrix3x4_t *prev,
        const matrix3x4_t *current,
        float dt)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  QAngle startAngles; // [esp+0h] [ebp-34h] BYREF
  QAngle endAngles; // [esp+Ch] [ebp-28h] BYREF
  Vector deltaAxis; // [esp+18h] [ebp-1Ch] BYREF
  Vector startPosition; // [esp+24h] [ebp-10h]
  float scale; // [esp+30h] [ebp-4h]

  scale = 1.0;
  if ( dt > 0.0 )
    scale = 1.0 / dt;
  MatrixAngles(a1: (int)prev, src: (const VMatrix *)prev, vAngles: &startAngles);
  startPosition.x = prev->m_flMatVal[0][3];
  startPosition.y = prev->m_flMatVal[1][3];
  startPosition.z = prev->m_flMatVal[2][3];
  MatrixAngles(a1: (int)current, src: (const VMatrix *)current, vAngles: &endAngles);
  v5 = (float)(current->m_flMatVal[1][3] - startPosition.y) * scale;
  v6 = (float)(current->m_flMatVal[2][3] - startPosition.z) * scale;
  velocity->x = (float)(current->m_flMatVal[0][3] - startPosition.x) * scale;
  velocity->y = v5;
  velocity->z = v6;
  RotationDeltaAxisAngle(srcAngles: &startAngles, destAngles: &endAngles, &deltaAxis, deltaAngle: &dt);
  v7 = dt * scale;
  angVel->x = deltaAxis.x * (float)(dt * scale);
  angVel->y = v7 * deltaAxis.y;
  angVel->z = deltaAxis.z * v7;
}

//------------------------------------------------------------------------------
// Address: 0x10342040
// Name: bool CalcPoseSingle(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,struct mstudioseqdesc_t __near &,int,float,float const __near * const,int,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CalcPoseSingle(
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        mstudioseqdesc_t *seqdesc,
        int sequence,
        float cycle,
        const float *poseParameter,
        int boneMask,
        float flTime)
{
  void *v9; // eax
  void *v10; // eax
  void *v11; // eax
  void *v12; // eax
  int NumSeq_Internal; // eax
  int v15; // ebx
  const mstudioseqdesc_t *v17; // eax
  int v18; // eax
  int flags; // ecx
  double v20; // st7
  float v21; // xmm4_4
  int SharedPoseParameter; // eax
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  float v35; // xmm0_4
  const QuaternionAligned *v36; // edx
  Vector *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  float s; // xmm0_4
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v53; // [esp+18h] [ebp-4Ch]
  int v54; // [esp+20h] [ebp-44h]
  int iAnimIndices[3]; // [esp+30h] [ebp-34h] BYREF
  float weight[3]; // [esp+3Ch] [ebp-28h] BYREF
  Quaternion *v57; // [esp+48h] [ebp-1Ch]
  Vector *v58; // [esp+4Ch] [ebp-18h]
  float s1; // [esp+50h] [ebp-14h] BYREF
  float s0; // [esp+54h] [ebp-10h] BYREF
  Quaternion *v61; // [esp+58h] [ebp-Ch]
  Vector *pos2; // [esp+5Ch] [ebp-8h]
  bool bResult; // [esp+63h] [ebp-1h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int i0; // [esp+6Ch] [ebp+8h]
  mstudioseqdesc_t *seqdesca; // [esp+78h] [ebp+14h]
  mstudioseqdesc_t *seqdescb; // [esp+78h] [ebp+14h]
  int i1; // [esp+7Ch] [ebp+18h]
  int i1a; // [esp+7Ch] [ebp+18h]
  int i1b; // [esp+7Ch] [ebp+18h]
  int i1c; // [esp+7Ch] [ebp+18h]
  int i1d; // [esp+7Ch] [ebp+18h]
  float cyclea; // [esp+80h] [ebp+1Ch]

  bResult = true;
  pos2 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( pos2 == nullptr )
  {
    v9 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v9 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v9 + 19) & 0xFFFFFFF0) - 4) = v9;
      pos2 = (Vector *)(((unsigned int)v9 + 19) & 0xFFFFFFF0);
    }
    else
    {
      pos2 = nullptr;
    }
    if ( ((unsigned __int8)pos2 & 0xF) != 0 )
      __debugbreak();
  }
  v61 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v61 == nullptr )
  {
    v10 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v10 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v10 + 19) & 0xFFFFFFF0) - 4) = v10;
      v61 = (Quaternion *)(((unsigned int)v10 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v61 = nullptr;
    }
    if ( ((unsigned __int8)v61 & 0xF) != 0 )
      __debugbreak();
  }
  v58 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
  if ( v58 == nullptr )
  {
    v11 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
    if ( v11 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v11 + 19) & 0xFFFFFFF0) - 4) = v11;
      v58 = (Vector *)(((unsigned int)v11 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v58 = nullptr;
    }
    if ( ((unsigned __int8)v58 & 0xF) != 0 )
      __debugbreak();
  }
  v57 = (Quaternion *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
  if ( v57 == nullptr )
  {
    v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
    if ( v12 != nullptr )
    {
      *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
      v57 = (Quaternion *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
    }
    else
    {
      v57 = nullptr;
    }
    if ( ((unsigned __int8)v57 & 0xF) != 0 )
      __debugbreak();
  }
  if ( pStudioHdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr);
  else
    NumSeq_Internal = pStudioHdr->m_pStudioHdr->numlocalseq;
  v15 = sequence;
  if ( sequence >= NumSeq_Internal )
  {
    v15 = 0;
    if ( pStudioHdr->m_pVModel != nullptr )
      v17 = CStudioHdr::pSeqdesc_Internal(this: pStudioHdr, i: 0);
    else
      v17 = (const mstudioseqdesc_t *)((char *)pStudioHdr->m_pStudioHdr + pStudioHdr->m_pStudioHdr->localseqindex);
    mstudioseqdesc_t::operator=(this: seqdesc, __that: v17);
  }
  s0 = 0.0;
  s1 = 0.0;
  i0 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 0, flSetting: &s0);
  v18 = Studio_LocalPoseParameter(pStudioHdr, poseParameter, seqdesc, iSequence: v15, iLocalIndex: 1, flSetting: &s1);
  flags = seqdesc->flags;
  i1 = v18;
  if ( (flags & 0x100) != 0 )
  {
    v20 = Studio_CPS(pStudioHdr, seqdesc, iSequence: v15, poseParameter) * flTime;
    v18 = i1;
    cyclea = v20;
    cycle = v20 - (double)(int)cyclea;
    v21 = cycle;
    goto LABEL_50;
  }
  if ( (flags & 0x80u) != 0 )
  {
    SharedPoseParameter = CStudioHdr::GetSharedPoseParameter(
                            this: pStudioHdr,
                            iSequence: v15,
                            iLocalPose: seqdesc->cycleposeindex);
    if ( SharedPoseParameter == -1 )
      v21 = 0.0;
    else
      v21 = poseParameter[SharedPoseParameter];
    v18 = i1;
LABEL_49:
    cycle = v21;
    goto LABEL_50;
  }
  v21 = cycle;
  if ( cycle < 0.0 || cycle >= 1.0 )
  {
    if ( (flags & 1) != 0 )
    {
      v21 = cycle - (float)(int)cycle;
      cycle = v21;
      if ( v21 >= 0.0 )
        goto LABEL_50;
      v21 = v21 + 1.0;
    }
    else if ( cycle >= 0.0 )
    {
      if ( cycle > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    goto LABEL_49;
  }
LABEL_50:
  if ( s0 >= 0.001 )
  {
    if ( s0 > 0.999 )
    {
      if ( s1 < 0.001 )
      {
        if ( !PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
        {
          v53 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
          CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v53, cycle, boneMask);
          goto LABEL_99;
        }
        goto LABEL_53;
      }
      if ( s1 > 0.999 )
      {
        v38 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v38, cycle: v21, boneMask);
        goto LABEL_99;
      }
      v39 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: v18);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v39, cycle: v21, boneMask);
      v40 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1 + 1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v40, cycle, boneMask);
      v35 = s1;
      v36 = (const QuaternionAligned *)v61;
      v54 = boneMask;
      v37 = pos2;
LABEL_98:
      BlendBones(
        a1: (int)&savedregs,
        a2: (int)pStudioHdr,
        a3: (int)seqdesc,
        pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc,
        sequence: v15,
        q2: v36,
        pos2: v37,
        s: v35,
        boneMask: v54);
      goto LABEL_99;
    }
    if ( s1 >= 0.001 )
    {
      if ( s1 > 0.999 )
      {
        i1c = v18 + 1;
        v46 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18 + 1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v46, cycle: v21, boneMask);
        v47 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1c);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v47, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        goto LABEL_99;
      }
      if ( anim_3wayblend.m_pParent == nullptr || anim_3wayblend.m_pParent->m_Value.m_nValue == 0 )
      {
        v48 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: v18);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v48, cycle: v21, boneMask);
        v49 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v49, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: s0,
          boneMask);
        i1d = i1 + 1;
        v50 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1d);
        CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v50, cycle, boneMask);
        v51 = mstudioseqdesc_t::anim(this: seqdesc, x: i0 + 1, y: i1d);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: v51, cycle, boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: (QuaternionAligned *)v61,
          pos1: pos2,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v57,
          pos2: v58,
          s: s0,
          boneMask);
LABEL_75:
        v35 = s1;
        v36 = (const QuaternionAligned *)v61;
        v54 = boneMask;
        v37 = pos2;
        goto LABEL_98;
      }
      Calc3WayBlendIndices(i0, i1: v18, s0, s1, seqdesc, pAnimIndices: iAnimIndices, pWeight: weight);
      if ( weight[1] >= 0.001 )
      {
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
        CalcAnimation(
          pStudioHdr,
          pos: pos2,
          q: v61,
          seqdesc,
          sequence: v15,
          animation: iAnimIndices[1],
          cycle,
          boneMask);
        BlendBones(
          a1: (int)&savedregs,
          a2: (int)pStudioHdr,
          a3: (int)seqdesc,
          pStudioHdr,
          q1: q,
          pos1: pos,
          seqdesc,
          sequence: v15,
          q2: (const QuaternionAligned *)v61,
          pos2,
          s: weight[1] / (float)(weight[0] + weight[1]),
          boneMask);
        CalcAnimation(pStudioHdr, pos: v58, q: v57, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
        v35 = weight[2];
        v36 = (const QuaternionAligned *)v57;
        v54 = boneMask;
        v37 = v58;
        goto LABEL_98;
      }
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: iAnimIndices[0], cycle: v21, boneMask);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: iAnimIndices[2], cycle, boneMask);
      s = weight[2] / (float)(weight[0] + weight[2]);
    }
    else
    {
      seqdescb = (mstudioseqdesc_t *)(i0 + 1);
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0: i0 + 1, i1: v18) )
      {
        v41 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v41, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: 1.0 - s0, boneMask);
        goto LABEL_99;
      }
      if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1) )
      {
        v42 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
        CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v42, cycle, boneMask);
        ScaleBones(pStudioHdr, q1: q, pos1: pos, sequence: v15, s: s0, boneMask);
        goto LABEL_99;
      }
      v43 = mstudioseqdesc_t::anim(this: seqdesc, x: i0, y: i1);
      CalcAnimation(pStudioHdr, pos, q, seqdesc, sequence: v15, animation: v43, cycle, boneMask);
      v44 = mstudioseqdesc_t::anim(this: seqdesc, x: (int)seqdescb, y: i1);
      CalcAnimation(pStudioHdr, pos: pos2, q: v61, seqdesc, sequence: v15, animation: v44, cycle, boneMask);
      s = s0;
    }
    BlendBones(
      a1: (int)&savedregs,
      a2: (int)pStudioHdr,
      a3: (int)seqdesc,
      pStudioHdr,
      q1: q,
      pos1: pos,
      seqdesc,
      sequence: v15,
      q2: (const QuaternionAligned *)v61,
      pos2,
      s,
      boneMask);
    goto LABEL_99;
  }
  if ( s1 >= 0.001 )
  {
    if ( s1 > 0.999 )
    {
      i1a = i0;
      v26 = seqdesc->groupsize[0];
      v27 = v18 + 1;
      if ( i0 >= v26 )
        i1a = v26 - 1;
      v28 = seqdesc->groupsize[1];
      if ( v27 >= v28 )
        v27 = v28 - 1;
      CalcAnimation(
        pStudioHdr,
        pos,
        q,
        seqdesc,
        sequence: v15,
        animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1a + 2 * v26 * v27 + seqdesc->animindexindex),
        cycle: v21,
        boneMask);
      goto LABEL_99;
    }
    v29 = seqdesc->groupsize[0];
    seqdesca = (mstudioseqdesc_t *)i0;
    if ( i0 >= v29 )
      seqdesca = (mstudioseqdesc_t *)(v29 - 1);
    v30 = seqdesc->groupsize[1];
    if ( i1 >= v30 )
      v18 = v30 - 1;
    CalcAnimation(
      pStudioHdr,
      pos,
      q,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr
                 + 2 * ((_DWORD)seqdesca + seqdesc->groupsize[0] * v18)
                 + seqdesc->animindexindex),
      cycle: v21,
      boneMask);
    v31 = i1;
    i1b = i0;
    v32 = seqdesc->groupsize[0];
    v33 = v31 + 1;
    if ( i0 >= v32 )
      i1b = v32 - 1;
    v34 = seqdesc->groupsize[1];
    if ( v33 >= v34 )
      v33 = v34 - 1;
    CalcAnimation(
      pStudioHdr,
      pos: pos2,
      q: v61,
      seqdesc,
      sequence: v15,
      animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i1b + 2 * v32 * v33 + seqdesc->animindexindex),
      cycle,
      boneMask);
    goto LABEL_75;
  }
  if ( PoseIsAllZeros(pStudioHdr, sequence: v15, seqdesc, i0, i1: v18) )
  {
LABEL_53:
    bResult = false;
    goto LABEL_99;
  }
  v23 = seqdesc->groupsize[0];
  v24 = i1;
  if ( i0 >= v23 )
    i0 = v23 - 1;
  v25 = seqdesc->groupsize[1];
  if ( i1 >= v25 )
    v24 = v25 - 1;
  CalcAnimation(
    pStudioHdr,
    pos,
    q,
    seqdesc,
    sequence: v15,
    animation: *(__int16 *)((char *)&seqdesc->baseptr + 2 * i0 + 2 * seqdesc->groupsize[0] * v24 + seqdesc->animindexindex),
    cycle,
    boneMask);
LABEL_99:
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)pos2);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v61);
  CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v58);
  CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v57);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x10342A20
// Name: public: IBoneSetup::IBoneSetup(class CStudioHdr const __near *,int,float const __near * const,class IPoseDebugger __near *)
// Source: json
//------------------------------------------------------------------------------
IBoneSetup *__thiscall IBoneSetup::IBoneSetup(
        IBoneSetup *this,
        const CStudioHdr *pStudioHdr,
        int boneMask,
        const float *poseParameter,
        IPoseDebugger *pPoseDebugger)
{
  CBoneSetup *v6; // eax

  v6 = (CBoneSetup *)operator new(nSize: 0x10u);
  if ( v6 != nullptr )
  {
    v6->m_pStudioHdr = pStudioHdr;
    v6->m_boneMask = boneMask;
    v6->m_flPoseParameter = poseParameter;
    v6->m_pPoseDebugger = pPoseDebugger;
    this->m_pBoneSetup = v6;
  }
  else
  {
    this->m_pBoneSetup = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10342A60
// Name: void InitPose(class CStudioHdr const __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPose(const CStudioHdr *pStudioHdr, Vector *pos, QuaternionAligned *q, int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v7; // ecx
  char *v8; // eax
  char *v9; // edi
  int numbones; // esi
  int *m_pMemory; // ebx
  int v12; // edi
  float *p_z; // ecx
  float *v14; // edx
  int v15; // eax
  double v16; // st7
  float *v17; // eax
  int v18; // xmm0_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int i; // [esp+10h] [ebp+8h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  studiohdr2index = pStudioHdr->m_pStudioHdr->studiohdr2index;
  if ( studiohdr2index != 0
    && (v7 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 4], v8 = (char *)m_pStudioHdr + studiohdr2index, v7 != 0)
    && (v9 = &v8[v7], &v8[v7] != nullptr) )
  {
    numbones = m_pStudioHdr->numbones;
    memcpy(dst: (unsigned __int8 *)pos, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 3)], count: 12 * numbones);
    memcpy(dst: (unsigned __int8 *)q, src: (unsigned __int8 *)&v9[*((_DWORD *)v9 + 4)], count: 16 * numbones);
  }
  else
  {
    i = 0;
    if ( m_pStudioHdr->numbones > 0 )
    {
      m_pMemory = pStudioHdr->m_boneFlags.m_Memory.m_pMemory;
      v12 = 0;
      p_z = &q->z;
      v14 = &pos->z;
      do
      {
        if ( (boneMask & *m_pMemory) != 0 )
        {
          v15 = v12 + m_pStudioHdr->boneindex;
          v16 = *(float *)&m_pStudioHdr->name[v15 + 20];
          v17 = (float *)((char *)&m_pStudioHdr->id + v15);
          *(v14 - 2) = v16;
          *(v14 - 1) = v17[9];
          *v14 = v17[10];
          v18 = *((_DWORD *)v17 + 12);
          v19 = *((_DWORD *)v17 + 13);
          v20 = *((_DWORD *)v17 + 14);
          *(p_z - 2) = v17[11];
          *((_DWORD *)p_z - 1) = v18;
          *(_DWORD *)p_z = v19;
          *((_DWORD *)p_z + 1) = v20;
        }
        ++m_pMemory;
        v12 += 216;
        v14 += 3;
        p_z += 4;
        ++i;
      }
      while ( i < m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10342B50
// Name: public: void IBoneSetup::InitPose(class Vector __near * const,class QuaternionAligned __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::InitPose(IBoneSetup *this, Vector *pos, QuaternionAligned *q)
{
  InitPose(pStudioHdr: this->m_pBoneSetup->m_pStudioHdr, pos, q, boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x10342B70
// Name: void CalcBoneAdj(class CStudioHdr const __near *,class Vector __near * const,class Quaternion __near * const,float const __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcBoneAdj(
        const CStudioHdr *pStudioHdr,
        Vector *pos,
        Quaternion *q,
        const float *controllers,
        int boneMask)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  float v10; // xmm2_4
  float v11; // xmm0_4
  Vector *p_y; // eax
  const Quaternion *v13; // [esp+8h] [ebp-34h]
  Quaternion *v14; // [esp+Ch] [ebp-30h]
  Quaternion q0; // [esp+1Ch] [ebp-20h] BYREF
  RadianEuler a0; // [esp+2Ch] [ebp-10h] BYREF
  int j; // [esp+38h] [ebp-4h]

  m_pStudioHdr = pStudioHdr->m_pStudioHdr;
  v6 = 0;
  for ( j = 0; j < m_pStudioHdr->numbonecontrollers; ++j )
  {
    v7 = v6 + m_pStudioHdr->bonecontrollerindex;
    v8 = *(int *)((char *)&m_pStudioHdr->id + v7);
    v9 = (char *)m_pStudioHdr + v7;
    if ( (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v8]) != 0 )
    {
      v10 = controllers[*((_DWORD *)v9 + 5)];
      if ( v10 >= 0.0 )
      {
        if ( v10 > 1.0 )
          v10 = 1.0;
      }
      else
      {
        v10 = 0.0;
      }
      v11 = (float)((float)(1.0 - v10) * *((float *)v9 + 2)) + (float)(*((float *)v9 + 3) * v10);
      switch ( *((_DWORD *)v9 + 1) & 0x3FFFF )
      {
        case 1:
          p_y = &pos[v8];
          goto LABEL_15;
        case 2:
          p_y = (Vector *)&pos[v8].y;
          goto LABEL_15;
        case 4:
          p_y = (Vector *)&pos[v8].z;
LABEL_15:
          p_y->x = p_y->x + v11;
          break;
        case 8:
          a0.x = v11 * 0.0174532925199433;
          a0.y = 0.0;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x10:
          a0.x = 0.0;
          a0.y = v11 * 0.0174532925199433;
          a0.z = 0.0;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
          goto LABEL_9;
        case 0x20:
          a0.x = 0.0;
          a0.y = 0.0;
          a0.z = v11 * 0.0174532925199433;
          AngleQuaternion(angles: &a0, outQuat: &q0);
          v14 = &q[v8];
          v13 = v14;
LABEL_9:
          QuaternionSM(s: 1.0, p: &q0, q: v13, qt: v14);
          break;
        default:
          break;
      }
    }
    m_pStudioHdr = pStudioHdr->m_pStudioHdr;
    v6 += 56;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10342D70
// Name: void Studio_BuildMatrices(class CStudioHdr const __near *,class QAngle const __near &,class Vector const __near &,class Vector const __near * const,class Quaternion const __near * const,int,float,class matrix3x4a_t __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall Studio_BuildMatrices(
        float a1@<ebp>,
        const CStudioHdr *pStudioHdr,
        const QAngle *angles,
        const Vector *origin,
        const Vector *pos,
        const Quaternion *q,
        int iBone,
        float flScale,
        matrix3x4a_t *bonetoworld,
        int boneMask)
{
  int v10; // eax
  int v11; // esi
  int numbones; // edx
  int *m_pMemory; // ecx
  unsigned int v14; // xmm4_4
  unsigned int v15; // xmm5_4
  int v16; // esi
  int v17; // esi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  float *v21; // ecx
  int v22; // esi
  int v23; // esi
  int v24; // eax
  int chain[256]; // [esp+0h] [ebp-470h] BYREF
  matrix3x4a_t bonematrix; // [esp+400h] [ebp-70h] BYREF
  matrix3x4a_t rotationmatrix; // [esp+430h] [ebp-40h] BYREF
  Vector vecOffset; // [esp+460h] [ebp-10h] BYREF
  float retaddr; // [esp+470h] [ebp+0h]

  vecOffset.y = a1;
  vecOffset.z = retaddr;
  v10 = iBone;
  v11 = 0;
  if ( iBone < -1 || (numbones = pStudioHdr->m_pStudioHdr->numbones, iBone >= numbones) )
  {
    v10 = 0;
    goto LABEL_4;
  }
  if ( iBone != -1 )
  {
LABEL_4:
    m_pMemory = pStudioHdr->m_boneParent.m_Memory.m_pMemory;
    do
    {
      *((_DWORD *)&vecOffset.y + v11 - 284) = v10;
      v10 = m_pMemory[v10];
      ++v11;
    }
    while ( v10 != -1 );
    goto LABEL_6;
  }
  v20 = 0;
  v11 = pStudioHdr->m_pStudioHdr->numbones;
  if ( numbones > 0 )
  {
    v21 = &vecOffset.y + numbones - 285;
    do
      *(_DWORD *)v21-- = v20++;
    while ( v20 < numbones );
  }
LABEL_6:
  AngleMatrix(angles, position: origin, matrix: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
  if ( flScale < 0.99999988 || flScale > 1.0000001 )
  {
    MatrixGetColumn(
      in: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1],
      column: 3,
      out: (Vector *)&rotationmatrix.m_flMatVal[2][1]);
    *(float *)&v14 = origin->y + (float)((float)(rotationmatrix.m_flMatVal[2][2] - origin->y) * flScale);
    *(float *)&v15 = origin->z + (float)((float)(rotationmatrix.m_flMatVal[2][3] - origin->z) * flScale);
    rotationmatrix.m_flMatVal[2][1] = origin->x
                                    + (float)((float)(rotationmatrix.m_flMatVal[2][1] - origin->x) * flScale);
    *(_QWORD *)&rotationmatrix.m_flMatVal[2][2] = __PAIR64__(v15, v14);
    MatrixSetColumn(
      in: (const Vector *)&rotationmatrix.m_flMatVal[2][1],
      column: 3,
      out: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1]);
    bonematrix.m_flMatVal[2][1] = bonematrix.m_flMatVal[2][1] * flScale;
    bonematrix.m_flMatVal[2][2] = bonematrix.m_flMatVal[2][2] * flScale;
    bonematrix.m_flMatVal[2][3] = bonematrix.m_flMatVal[2][3] * flScale;
    rotationmatrix.m_flMatVal[0][1] = rotationmatrix.m_flMatVal[0][1] * flScale;
    rotationmatrix.m_flMatVal[0][2] = rotationmatrix.m_flMatVal[0][2] * flScale;
    rotationmatrix.m_flMatVal[0][3] = rotationmatrix.m_flMatVal[0][3] * flScale;
    rotationmatrix.m_flMatVal[1][1] = rotationmatrix.m_flMatVal[1][1] * flScale;
    rotationmatrix.m_flMatVal[1][2] = rotationmatrix.m_flMatVal[1][2] * flScale;
    rotationmatrix.m_flMatVal[1][3] = rotationmatrix.m_flMatVal[1][3] * flScale;
  }
  if ( ((unsigned __int8)bonetoworld & 0xF) != 0 )
  {
    v16 = v11 - 1;
    for ( LODWORD(vecOffset.x) = v16; v16 >= 0; LODWORD(vecOffset.x) = v16 )
    {
      v17 = *((_DWORD *)&vecOffset.y + v16 - 284);
      if ( (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v17]) != 0 )
      {
        QuaternionMatrix(q: &q[v17], pos: &pos[v17], matrix: (matrix3x4_t *)&chain[253]);
        v18 = pStudioHdr->m_boneParent.m_Memory.m_pMemory[v17];
        v19 = v17;
        if ( v18 == -1 )
          ConcatTransforms(
            in1: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1],
            in2: (const matrix3x4_t *)&chain[253],
            out: &bonetoworld[v19]);
        else
          ConcatTransforms(in1: &bonetoworld[v18], in2: (const matrix3x4_t *)&chain[253], out: &bonetoworld[v19]);
      }
      v16 = LODWORD(vecOffset.x) - 1;
    }
  }
  else
  {
    v22 = v11 - 1;
    for ( LODWORD(vecOffset.x) = v22; v22 >= 0; LODWORD(vecOffset.x) = v22 )
    {
      v23 = *((_DWORD *)&vecOffset.y + v22 - 284);
      if ( (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v23]) != 0 )
      {
        QuaternionMatrix(q: &q[v23], pos: &pos[v23], matrix: (matrix3x4_t *)&chain[253]);
        v24 = pStudioHdr->m_boneParent.m_Memory.m_pMemory[v23];
        if ( v24 == -1 )
          ConcatTransforms_Aligned(
            m0: (matrix3x4a_t *)&bonematrix.m_flMatVal[2][1],
            m1: (const matrix3x4a_t *)&chain[253],
            out: &bonetoworld[v23]);
        else
          ConcatTransforms_Aligned(m0: &bonetoworld[v24], m1: (const matrix3x4a_t *)&chain[253], out: &bonetoworld[v23]);
      }
      v22 = LODWORD(vecOffset.x) - 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10343050
// Name: public: void IBoneSetup::CalcBoneAdj(class Vector __near * const,class Quaternion __near * const,float const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcBoneAdj(IBoneSetup *this, Vector *pos, Quaternion *q, const float *controllers)
{
  CalcBoneAdj(
    pStudioHdr: this->m_pBoneSetup->m_pStudioHdr,
    pos,
    q,
    controllers,
    boneMask: this->m_pBoneSetup->m_boneMask);
}

//------------------------------------------------------------------------------
// Address: 0x10343080
// Name: public: void CBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneSetup::AccumulatePose(
        CBoneSetup *this@<ecx>,
        int a2@<ebp>,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  void *v9; // esp
  int v11; // edi
  void *v12; // eax
  void *v13; // eax
  CStudioHdr *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v15; // edi
  CIKContext *v16; // ecx
  __int64 s; // [esp+38h] [ebp-10A4h]
  CIKContext v18; // [esp+50h] [ebp-108Ch] BYREF
  float v19; // [esp+10C4h] [ebp-18h]
  Vector *v20; // [esp+10C8h] [ebp-14h]
  QuaternionAligned *v21; // [esp+10CCh] [ebp-10h]
  _DWORD v22[3]; // [esp+10D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10DCh] [ebp+0h]

  v22[0] = a2;
  v22[1] = retaddr;
  v9 = alloca(4232);
  if ( cl_use_simd_bones.m_pParent != nullptr
    && cl_use_simd_bones.m_pParent->m_Value.m_nValue != 0
    && ((unsigned __int8)q & 0xF) != 0
    && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
  {
    __debugbreak();
  }
  if ( flWeight >= 0.0 )
  {
    if ( flWeight <= 1.0 )
      v19 = flWeight;
    else
      v19 = 1.0;
  }
  else
  {
    v19 = 0.0;
  }
  v11 = sequence;
  if ( sequence >= 0 )
  {
    v20 = (Vector *)CTSListBase::Pop(this: &g_VectorPool.m_FreeBlocks);
    if ( v20 == nullptr )
    {
      v12 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3091);
      if ( v12 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v12 + 19) & 0xFFFFFFF0) - 4) = v12;
        v20 = (Vector *)(((unsigned int)v12 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v20 = nullptr;
      }
      if ( ((unsigned __int8)v20 & 0xF) != 0 )
        __debugbreak();
    }
    v21 = (QuaternionAligned *)CTSListBase::Pop(this: &g_QuaternionPool.m_FreeBlocks);
    if ( v21 == nullptr )
    {
      v13 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4115);
      if ( v13 != nullptr )
      {
        *(_DWORD *)((((unsigned int)v13 + 19) & 0xFFFFFFF0) - 4) = v13;
        v21 = (QuaternionAligned *)(((unsigned int)v13 + 19) & 0xFFFFFFF0);
      }
      else
      {
        v21 = nullptr;
      }
      if ( ((unsigned __int8)v21 & 0xF) != 0 )
        __debugbreak();
    }
    if ( this->m_pPoseDebugger != nullptr )
      ((void (__stdcall *)(const CStudioHdr *, CIKContext *, Vector *, QuaternionAligned *, int, _DWORD, const float *, int, _DWORD, _DWORD))this->m_pPoseDebugger->AccumulatePose)(
        a1: this->m_pStudioHdr,
        a2: pIKContext,
        a3: pos,
        a4: q,
        a5: sequence,
        a6: LODWORD(cycle),
        a7: this->m_flPoseParameter,
        a8: this->m_boneMask,
        a9: LODWORD(v19),
        a10: LODWORD(flTime));
    m_pStudioHdr = (CStudioHdr *)this->m_pStudioHdr;
    if ( this->m_pStudioHdr->m_pVModel != nullptr )
    {
      v15 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: sequence);
    }
    else
    {
      if ( sequence >= m_pStudioHdr->m_pStudioHdr->numlocalseq )
        v11 = 0;
      v15 = (mstudioseqdesc_t *)((char *)m_pStudioHdr->m_pStudioHdr
                               + 212 * v11
                               + m_pStudioHdr->m_pStudioHdr->localseqindex);
    }
    CIKContext::CIKContext(this: &v18);
    if ( v15->numiklocks != 0 )
    {
      CIKContext::Init(
        this: &v18,
        pStudioHdr: this->m_pStudioHdr,
        angles: &vec3_angle,
        pos: &vec3_origin,
        flTime: 0.0,
        iFramecounter: 0,
        boneMask: this->m_boneMask);
      CIKContext::AddSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    }
    if ( (v15->flags & 0x200) != 0 )
      InitPose(pStudioHdr: this->m_pStudioHdr, pos: v20, q: v21, boneMask: this->m_boneMask);
    if ( CalcPoseSingle(
           pStudioHdr: (CStudioHdr *)this->m_pStudioHdr,
           pos: v20,
           q: v21,
           seqdesc: v15,
           sequence,
           cycle,
           poseParameter: this->m_flPoseParameter,
           boneMask: this->m_boneMask,
           flTime) )
    {
      CBoneSetup::AddLocalLayers(
        this,
        pos: v20,
        q: v21,
        seqdesc: v15,
        sequence,
        cycle,
        flWeight: 1.0,
        flTime,
        pIKContext);
      HIDWORD(s) = this->m_boneMask;
      *(float *)&s = v19;
      SlerpBones(
        a1: COERCE_FLOAT(v22),
        a2: (int)v15,
        a3: (int)this,
        pStudioHdr: this->m_pStudioHdr,
        q1: q,
        pos1: pos,
        seqdesc: v15,
        sequence,
        q2: v21,
        pos2: v20,
        s);
    }
    CTSListBase::Push(this: &g_VectorPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v20);
    CTSListBase::Push(this: &g_QuaternionPool.m_FreeBlocks, pNode: (TSLNodeBase_t *)v21);
    v16 = pIKContext;
    if ( pIKContext != nullptr )
    {
      CIKContext::AddDependencies(
        this: pIKContext,
        seqdesc: v15,
        iSequence: sequence,
        flCycle: cycle,
        poseParameters: this->m_flPoseParameter,
        flWeight: v19);
      v16 = pIKContext;
    }
    CBoneSetup::AddSequenceLayers(this, pos, q, seqdesc: v15, sequence, cycle, flWeight: v19, flTime, pIKContext: v16);
    if ( v15->numiklocks != 0 )
      CIKContext::SolveSequenceLocks(this: &v18, seqdesc: v15, pos, q);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v18.m_ikLock);
    CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: &v18.m_ikChainRule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103433D0
// Name: public: void CBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneSetup::CalcAutoplaySequences(
        CBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CIKContext *v5; // esi
  int v6; // ebx
  const CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v9; // ecx
  int v10; // esi
  const studiohdr_t *v11; // ecx
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  double v14; // st7
  float v15; // [esp+0h] [ebp-28h]
  int count; // [esp+1Ch] [ebp-Ch]
  float cycle; // [esp+20h] [ebp-8h]
  unsigned __int16 *pList; // [esp+24h] [ebp-4h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v5 = pIKContext;
  v6 = 0;
  if ( pIKContext != nullptr )
    CIKContext::AddAutoplayLocks(this: pIKContext, pos, q);
  m_pStudioHdr = this->m_pStudioHdr;
  pList = nullptr;
  count = studiohdr_t::GetAutoplayList(this: m_pStudioHdr->m_pStudioHdr, pOut: &pList);
  if ( count > 0 )
  {
    do
    {
      v9 = (CStudioHdr *)this->m_pStudioHdr;
      v10 = pList[v6];
      if ( this->m_pStudioHdr->m_pVModel != nullptr )
      {
        v13 = CStudioHdr::pSeqdesc_Internal(this: v9, i: pList[v6]);
      }
      else
      {
        v11 = v9->m_pStudioHdr;
        v12 = pList[v6];
        if ( v10 >= v11->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v11 + 212 * v12 + v11->localseqindex);
      }
      if ( (v13->flags & 8) != 0 )
      {
        v14 = Studio_CPS(
                pStudioHdr: this->m_pStudioHdr,
                seqdesc: v13,
                iSequence: v10,
                poseParameter: this->m_flPoseParameter)
            * flRealTime;
        cycle = v14;
        v15 = v14 - (double)(int)cycle;
        CBoneSetup::AccumulatePose(
          this,
          a2: (int)&savedregs,
          pos,
          q,
          sequence: v10,
          cycle: v15,
          flWeight: 1.0,
          flTime: flRealTime,
          pIKContext);
      }
      ++v6;
    }
    while ( v6 < count );
    v5 = pIKContext;
  }
  if ( v5 != nullptr )
    CIKContext::SolveAutoplayLocks(this: v5, pos, q);
}

//------------------------------------------------------------------------------
// Address: 0x103434D0
// Name: public: void IBoneSetup::AccumulatePose(class Vector __near * const,class Quaternion __near * const,int,float,float,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::AccumulatePose(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        int sequence,
        float cycle,
        float flWeight,
        float flTime,
        CIKContext *pIKContext)
{
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CBoneSetup::AccumulatePose(
    this: this->m_pBoneSetup,
    a2: (int)&savedregs,
    pos,
    q,
    sequence,
    cycle,
    flWeight,
    flTime,
    pIKContext);
}

//------------------------------------------------------------------------------
// Address: 0x10343520
// Name: public: void IBoneSetup::CalcAutoplaySequences(class Vector __near * const,class Quaternion __near * const,float,class CIKContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IBoneSetup::CalcAutoplaySequences(
        IBoneSetup *this,
        Vector *pos,
        QuaternionAligned *q,
        float flRealTime,
        CIKContext *pIKContext)
{
  CBoneSetup::CalcAutoplaySequences(this: this->m_pBoneSetup, pos, q, flRealTime, pIKContext);
}

} // namespace server
