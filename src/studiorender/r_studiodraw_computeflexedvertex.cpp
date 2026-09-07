// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studiodraw_computeflexedvertex.cpp
// Functions: 2
// ============================================================

#include "studiorender\r_studiodraw_computeflexedvertex.h"

//------------------------------------------------------------------------------
// Address: 0x100116A0
// Name: public: void CCachedRenderData::ComputeFlexedVertex_StreamOffset_Optimized(struct studiohdr_t __near *,struct mstudioflex_t __near *,struct mstudiovertanim_t __near *,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::ComputeFlexedVertex_StreamOffset_Optimized(
        CCachedRenderData *this,
        studiohdr_t *pStudioHdr,
        mstudioflex_t *pflex,
        mstudiovertanim_t *pvanim,
        int vertCount,
        float w1,
        float w2,
        float w3,
        float w4)
{
  CCachedRenderData::ComputeFlexedVertex_StreamOffset<mstudiovertanim_t>(
    this,
    pStudioHdr,
    pflex,
    pvanim,
    vertCount,
    w1,
    w2,
    w3,
    w4);
}

//------------------------------------------------------------------------------
// Address: 0x100116F0
// Name: public: void CCachedRenderData::ComputeFlexedVertexWrinkle_StreamOffset_Optimized(struct studiohdr_t __near *,struct mstudioflex_t __near *,struct mstudiovertanim_wrinkle_t __near *,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::ComputeFlexedVertexWrinkle_StreamOffset_Optimized(
        CCachedRenderData *this,
        studiohdr_t *pStudioHdr,
        mstudioflex_t *pflex,
        mstudiovertanim_wrinkle_t *pvanim,
        int vertCount,
        float w1,
        float w2,
        float w3,
        float w4)
{
  CCachedRenderData::ComputeFlexedVertex_StreamOffset<mstudiovertanim_wrinkle_t>(
    this,
    pStudioHdr,
    pflex,
    pvanim,
    vertCount,
    w1,
    w2,
    w3,
    w4);
}
