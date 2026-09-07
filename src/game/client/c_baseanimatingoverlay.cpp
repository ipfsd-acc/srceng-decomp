// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baseanimatingoverlay.cpp
// Functions: 41
// ============================================================

#include "game\client\c_baseanimatingoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x10033710
// Name: public: void C_AnimationLayer::SetOwner(class C_BaseAnimatingOverlay __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AnimationLayer::SetOwner(C_AnimationLayer *this, C_BaseAnimatingOverlay *pOverlay)
{
  this->m_pOwner = pOverlay;
}

//------------------------------------------------------------------------------
// Address: 0x10033720
// Name: public: void C_AnimationLayer::SetOrder(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AnimationLayer::SetOrder(C_AnimationLayer *this, int order)
{
  C_BaseAnimatingOverlay *m_pOwner; // ecx
  int m_nOrder; // eax

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
  {
    m_nOrder = this->m_nOrder;
    if ( m_nOrder != order && (m_nOrder == 15 || order == 15) )
      C_BaseEntity::InvalidatePhysicsRecursive(this: m_pOwner, nChangeFlags: 16);
    this->m_nOrder = order;
  }
  else
  {
    this->m_nOrder = order;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033760
// Name: void RecvProxy_OrderChanged(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_OrderChanged(const CRecvProxyData *pData, _DWORD *pStruct)
{
  int m_Int; // esi
  C_BaseEntity *v3; // ecx
  int v4; // eax

  m_Int = pData->m_Value.m_Int;
  v3 = (C_BaseEntity *)pStruct[8];
  if ( v3 != nullptr )
  {
    v4 = pStruct[2];
    if ( v4 != m_Int && (v4 == 15 || m_Int == 15) )
      C_BaseEntity::InvalidatePhysicsRecursive(this: v3, nChangeFlags: 16);
  }
  pStruct[2] = m_Int;
}

//------------------------------------------------------------------------------
// Address: 0x100337A0
// Name: private: virtual class ClientClass __near * C_BaseAnimatingOverlay::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseAnimatingOverlay::GetClientClass(C_BaseAnimatingOverlay *this)
{
  return &__g_C_BaseAnimatingOverlayClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10033840
// Name: public: virtual struct datamap_t __near * C_BaseAnimatingOverlay::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseAnimatingOverlay::GetPredDescMap(C_BaseAnimatingOverlay *this)
{
  return &C_BaseAnimatingOverlay::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10033850
// Name: public: void C_AnimationLayer::SetWeight(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AnimationLayer::SetWeight(C_AnimationLayer *this, float flWeight)
{
  C_BaseAnimatingOverlay *m_pOwner; // ecx
  float m_Val; // xmm0_4

  m_pOwner = this->m_pOwner;
  if ( m_pOwner == nullptr )
    goto LABEL_6;
  m_Val = this->m_flWeight.m_Val;
  if ( m_Val != flWeight && (m_Val == 0.0 || flWeight == 0.0) )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this: m_pOwner, nChangeFlags: 16);
LABEL_6:
    this->m_flWeight.m_Val = flWeight;
    return;
  }
  this->m_flWeight.m_Val = flWeight;
}

//------------------------------------------------------------------------------
// Address: 0x100338B0
// Name: void RecvProxy_WeightChanged(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_WeightChanged(const CRecvProxyData *pData, float *pStruct)
{
  float m_Float; // xmm0_4
  C_BaseEntity *v3; // ecx
  float v4; // xmm1_4

  m_Float = pData->m_Value.m_Float;
  v3 = *((C_BaseEntity **)pStruct + 8);
  if ( v3 != nullptr )
  {
    v4 = pStruct[5];
    if ( v4 != m_Float && (v4 == 0.0 || m_Float == 0.0) )
      C_BaseEntity::InvalidatePhysicsRecursive(this: v3, nChangeFlags: 16);
  }
  pStruct[5] = m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x10033910
// Name: public: int C_BaseAnimatingOverlay::GetNumAnimOverlays(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseAnimatingOverlay::GetNumAnimOverlays(C_BaseAnimatingOverlay *this)
{
  return this->m_AnimOverlay.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100339D0
// Name: public: void C_AnimationLayer::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AnimationLayer::Reset(C_AnimationLayer *this)
{
  C_BaseAnimatingOverlay *m_pOwner; // ecx
  int v3; // edx

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
  {
    v3 = 0;
    if ( this->m_nSequence.m_Val != 0 || this->m_flWeight.m_Val != 0.0 )
      v3 = 16;
    if ( this->m_flCycle.m_Val != 0.0 )
      v3 |= 8u;
    if ( v3 != 0 )
      C_BaseEntity::InvalidatePhysicsRecursive(this: m_pOwner, nChangeFlags: v3);
  }
  this->m_nSequence.m_Val = 0;
  this->m_flPrevCycle.m_Val = 0.0;
  this->m_flWeight.m_Val = 0.0;
  this->m_flPlaybackRate.m_Val = 0.0;
  this->m_flCycle.m_Val = 0.0;
  this->m_flLayerAnimtime = 0.0;
  this->m_flLayerFadeOuttime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10033A40
// Name: public: void C_AnimationLayer::SetSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AnimationLayer::SetSequence(C_AnimationLayer *this, int nSequence)
{
  C_BaseAnimatingOverlay *m_pOwner; // ecx

  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr )
  {
    if ( this->m_nSequence.m_Val != nSequence )
      C_BaseEntity::InvalidatePhysicsRecursive(this: m_pOwner, nChangeFlags: 16);
    this->m_nSequence.m_Val = nSequence;
  }
  else
  {
    this->m_nSequence.m_Val = nSequence;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033A80
// Name: public: void C_AnimationLayer::SetCycle(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_AnimationLayer::SetCycle(C_AnimationLayer *this, float flCycle)
{
  float v2; // xmm0_4
  C_BaseAnimatingOverlay *m_pOwner; // ecx

  v2 = flCycle;
  m_pOwner = this->m_pOwner;
  if ( m_pOwner != nullptr && this->m_flCycle.m_Val != flCycle )
  {
    C_BaseEntity::InvalidatePhysicsRecursive(this: m_pOwner, nChangeFlags: 8);
    v2 = flCycle;
  }
  this->m_flCycle.m_Val = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10033AC0
// Name: void RecvProxy_SequenceChanged(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_SequenceChanged(const CRecvProxyData *pData, _DWORD *pStruct)
{
  int m_Int; // esi
  C_BaseEntity *v3; // ecx

  m_Int = pData->m_Value.m_Int;
  v3 = (C_BaseEntity *)pStruct[8];
  if ( v3 != nullptr && pStruct[3] != m_Int )
    C_BaseEntity::InvalidatePhysicsRecursive(this: v3, nChangeFlags: 16);
  pStruct[3] = m_Int;
}

//------------------------------------------------------------------------------
// Address: 0x10033AF0
// Name: void RecvProxy_CycleChanged(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_CycleChanged(const CRecvProxyData *pData, float *pStruct)
{
  float m_Float; // xmm0_4
  C_BaseEntity *v3; // ecx

  m_Float = pData->m_Value.m_Float;
  v3 = *((C_BaseEntity **)pStruct + 8);
  if ( v3 != nullptr && pStruct[7] != m_Float )
    C_BaseEntity::InvalidatePhysicsRecursive(this: v3, nChangeFlags: 8);
  pStruct[7] = m_Float;
}

//------------------------------------------------------------------------------
// Address: 0x10033C00
// Name: public: class C_AnimationLayer __near * C_BaseAnimatingOverlay::GetAnimOverlay(int)
// Source: json
//------------------------------------------------------------------------------
C_AnimationLayer *__thiscall C_BaseAnimatingOverlay::GetAnimOverlay(C_BaseAnimatingOverlay *this, int i)
{
  return &this->m_AnimOverlay.m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10033C20
// Name: public: virtual void C_BaseAnimatingOverlay::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimatingOverlay::GetRenderBounds(C_BaseAnimatingOverlay *this, Vector *theMins, Vector *theMaxs)
{
  CStudioHdr *v5; // esi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  double x; // xmm0_8
  float y; // xmm1_4
  float v12; // xmm0_4
  double v13; // xmm0_8
  double v14; // xmm1_8
  float z; // xmm1_4
  float v16; // xmm0_4
  double v17; // xmm0_8
  double v18; // xmm1_8
  float v19; // xmm0_4
  double v20; // xmm0_8
  float v21; // xmm1_4
  float v22; // xmm0_4
  double v23; // xmm0_8
  double v24; // xmm1_8
  float v25; // xmm1_4
  float v26; // xmm0_4
  double v27; // xmm0_8
  double v28; // xmm1_8
  CStudioHdr *v29; // [esp+Ch] [ebp-8h]
  int v30; // [esp+10h] [ebp-4h]
  int nSequences; // [esp+1Ch] [ebp+8h]

  C_BaseAnimating::GetRenderBounds(this, theMins, theMaxs);
  if ( !C_BaseAnimating::IsRagdoll(this: (C_BaseAnimatingOverlay *)((char *)this - 4)) )
  {
    if ( *(_DWORD *)&this->m_nOldMuzzleFlashParity == 0 && this->GetClientThinkable(this) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: (C_BaseAnimatingOverlay *)((char *)this - 4));
    v5 = *(CStudioHdr **)&this->m_nOldMuzzleFlashParity;
    v29 = v5;
    if ( v5 != nullptr && v5->m_pStudioHdr != nullptr && CStudioHdr::SequencesAvailable(this: v5) )
    {
      nSequences = v5->m_pVModel != nullptr ? CStudioHdr::GetNumSeq_Internal(this: v5) : v5->m_pStudioHdr->numlocalseq;
      v6 = 0;
      if ( this->m_AnimOverlay.m_Memory.m_nGrowSize > 0 )
      {
        v7 = 0;
        v30 = 0;
        do
        {
          v8 = *((_DWORD *)&this->m_vecRenderOriginOverride + 3) + v7;
          if ( *(float *)(v8 + 20) > 0.0 && *(_DWORD *)(v8 + 8) != 15 && *(_DWORD *)(v8 + 12) < nSequences )
          {
            v9 = CStudioHdr::pSeqdesc(this: v29, iSequence: *(_DWORD *)(v8 + 12));
            x = v9->bbmin.x;
            if ( x > theMins->x )
              x = theMins->x;
            y = theMins->y;
            v12 = x;
            theMins->x = v12;
            v13 = v9->bbmin.y;
            v14 = y;
            if ( v13 > v14 )
              v13 = v14;
            z = theMins->z;
            v16 = v13;
            theMins->y = v16;
            v17 = v9->bbmin.z;
            v18 = z;
            if ( v17 > v18 )
              v17 = v18;
            v19 = v17;
            theMins->z = v19;
            v20 = v9->bbmax.x;
            if ( v20 < theMaxs->x )
              v20 = theMaxs->x;
            v21 = theMaxs->y;
            v22 = v20;
            theMaxs->x = v22;
            v23 = v9->bbmax.y;
            v24 = v21;
            if ( v23 < v24 )
              v23 = v24;
            v25 = theMaxs->z;
            v26 = v23;
            theMaxs->y = v26;
            v27 = v9->bbmax.z;
            v28 = v25;
            if ( v27 < v28 )
              v27 = v28;
            theMaxs->z = v27;
          }
          ++v6;
          v7 = v30 + 40;
          v30 += 40;
        }
        while ( v6 < this->m_AnimOverlay.m_Memory.m_nGrowSize );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033DF0
// Name: public: virtual class CStudioHdr __near * C_BaseAnimatingOverlay::OnNewModel(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall C_BaseAnimatingOverlay::OnNewModel(C_BaseAnimatingOverlay *this)
{
  CStudioHdr *result; // eax
  int v3; // edx
  int v4; // ebx
  C_AnimationLayer *m_pMemory; // esi
  C_BaseEntity *m_pOwner; // ecx
  C_AnimationLayer *v7; // esi
  CStudioHdr *hdr; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  result = C_BaseAnimating::OnNewModel(this);
  v3 = 0;
  hdr = result;
  i = 0;
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
      m_pOwner = m_pMemory[v4].m_pOwner;
      v7 = &m_pMemory[v4];
      if ( m_pOwner != nullptr )
      {
        if ( v7->m_nSequence.m_Val != 0 || v7->m_flWeight.m_Val != 0.0 )
          v3 = 16;
        if ( v7->m_flCycle.m_Val != 0.0 )
          v3 |= 8u;
        if ( v3 != 0 )
          C_BaseEntity::InvalidatePhysicsRecursive(this: m_pOwner, nChangeFlags: v3);
      }
      v3 = 0;
      v7->m_nSequence.m_Val = 0;
      v7->m_flPrevCycle.m_Val = 0.0;
      v7->m_flWeight.m_Val = 0.0;
      v7->m_flPlaybackRate.m_Val = 0.0;
      v7->m_flCycle.m_Val = 0.0;
      v7->m_flLayerAnimtime = 0.0;
      v7->m_flLayerFadeOuttime = 0.0;
      this->m_AnimOverlay.m_Memory.m_pMemory[v4++].m_nOrder = 15;
      ++i;
    }
    while ( i < this->m_AnimOverlay.m_Size );
    return hdr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100342F0
// Name: public: virtual bool C_BaseAnimatingOverlay::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseAnimatingOverlay::Interpolate(C_BaseAnimatingOverlay *this, float flCurrentTime)
{
  int v3; // edi
  char v4; // bl
  int *p_m_nInvalidatePhysicsBits; // eax
  int m_Size; // edx

  v3 = 0;
  v4 = C_BaseAnimating::Interpolate(this, flCurrentTime);
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    p_m_nInvalidatePhysicsBits = &this->m_AnimOverlay.m_Memory.m_pMemory->m_nInvalidatePhysicsBits;
    m_Size = this->m_AnimOverlay.m_Size;
    do
    {
      if ( *p_m_nInvalidatePhysicsBits != 0 )
        v3 |= *p_m_nInvalidatePhysicsBits;
      p_m_nInvalidatePhysicsBits += 10;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 != 0 )
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: v3);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100346A0
// Name: class C_AnimationLayer LoopingLerp(float,class C_AnimationLayer __near &,class C_AnimationLayer __near &)
// Source: json
//------------------------------------------------------------------------------
C_AnimationLayer *__cdecl LoopingLerp(
        C_AnimationLayer *result,
        float flPercent,
        C_AnimationLayer *from,
        C_AnimationLayer *to)
{
  C_AnimationLayer *v4; // eax
  float m_Val; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4

  v4 = result;
  result->m_pOwner = nullptr;
  result->m_nInvalidatePhysicsBits = 0;
  result->m_nSequence.m_Val = 0;
  result->m_flPrevCycle.m_Val = 0.0;
  result->m_flWeight.m_Val = 0.0;
  result->m_flPlaybackRate.m_Val = 0.0;
  result->m_flCycle.m_Val = 0.0;
  result->m_flLayerAnimtime = 0.0;
  result->m_flLayerFadeOuttime = 0.0;
  result->m_nSequence.m_Val = to->m_nSequence.m_Val;
  m_Val = to->m_flCycle.m_Val;
  v6 = from->m_flCycle.m_Val;
  if ( fabs(m_Val - v6) >= 0.5 )
  {
    if ( m_Val <= v6 )
      m_Val = m_Val + 1.0;
    else
      v6 = v6 + 1.0;
  }
  v7 = (float)((float)((float)(1.0 - flPercent) * v6) + (float)(m_Val * flPercent))
     - (float)(int)(float)((float)((float)(1.0 - flPercent) * v6) + (float)(m_Val * flPercent));
  if ( v7 < 0.0 )
    v7 = v7 + 1.0;
  result->m_flCycle.m_Val = v7;
  result->m_flPrevCycle.m_Val = to->m_flPrevCycle.m_Val;
  result->m_flWeight.m_Val = (float)((float)(to->m_flWeight.m_Val - from->m_flWeight.m_Val) * flPercent)
                           + from->m_flWeight.m_Val;
  result->m_nOrder = to->m_nOrder;
  result->m_flLayerAnimtime = to->m_flLayerAnimtime;
  result->m_flLayerFadeOuttime = to->m_flLayerFadeOuttime;
  result->m_pOwner = to->m_pOwner;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10034790
// Name: class C_AnimationLayer LoopingLerp_Hermite(class C_AnimationLayer const __near &,float,class C_AnimationLayer __near &,class C_AnimationLayer __near &,class C_AnimationLayer __near &)
// Source: json
//------------------------------------------------------------------------------
C_AnimationLayer *__cdecl LoopingLerp_Hermite(
        C_AnimationLayer *result,
        const C_AnimationLayer *current,
        float flPercent,
        C_AnimationLayer *prev,
        C_AnimationLayer *from,
        C_AnimationLayer *to)
{
  int v6; // edi
  C_AnimationLayer *v7; // eax

  result->m_pOwner = nullptr;
  result->m_nInvalidatePhysicsBits = 0;
  result->m_nSequence.m_Val = 0;
  result->m_flPrevCycle.m_Val = 0.0;
  result->m_flWeight.m_Val = 0.0;
  result->m_flPlaybackRate.m_Val = 0.0;
  result->m_flCycle.m_Val = 0.0;
  result->m_flLayerAnimtime = 0.0;
  result->m_flLayerFadeOuttime = 0.0;
  result->m_nSequence.m_Val = to->m_nSequence.m_Val;
  result->m_flCycle.m_Val = LoopingLerp_Hermite<float>(
                              __formal: current->m_flCycle.m_Val,
                              t: flPercent,
                              p0: prev->m_flCycle.m_Val,
                              p1: from->m_flCycle.m_Val,
                              p2: to->m_flCycle.m_Val);
  result->m_flPrevCycle.m_Val = to->m_flPrevCycle.m_Val;
  result->m_flWeight.m_Val = (float)((float)(to->m_flWeight.m_Val - from->m_flWeight.m_Val) * flPercent)
                           + from->m_flWeight.m_Val;
  result->m_nOrder = to->m_nOrder;
  result->m_flLayerAnimtime = to->m_flLayerAnimtime;
  result->m_flLayerFadeOuttime = to->m_flLayerFadeOuttime;
  result->m_pOwner = to->m_pOwner;
  v6 = 0;
  if ( result->m_nSequence.m_Val != current->m_nSequence.m_Val
    || (result->m_flWeight.m_Val == 0.0) != (current->m_flWeight.m_Val == 0.0) )
  {
    v6 = 48;
  }
  if ( result->m_flCycle.m_Val != current->m_flCycle.m_Val )
    v6 |= 8u;
  v7 = result;
  if ( result->m_nOrder != current->m_nOrder )
    v6 |= 0x10u;
  result->m_nInvalidatePhysicsBits = v6;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100348C0
// Name: class C_AnimationLayer Lerp_Hermite(class C_AnimationLayer const __near &,float,class C_AnimationLayer const __near &,class C_AnimationLayer const __near &,class C_AnimationLayer const __near &)
// Source: json
//------------------------------------------------------------------------------
C_AnimationLayer *__cdecl Lerp_Hermite(
        C_AnimationLayer *result,
        const C_AnimationLayer *current,
        float flPercent,
        const C_AnimationLayer *prev,
        const C_AnimationLayer *from,
        const C_AnimationLayer *to)
{
  int v6; // edi
  C_AnimationLayer *v7; // eax

  result->m_pOwner = nullptr;
  result->m_nInvalidatePhysicsBits = 0;
  result->m_nSequence.m_Val = 0;
  result->m_flPrevCycle.m_Val = 0.0;
  result->m_flWeight.m_Val = 0.0;
  result->m_flPlaybackRate.m_Val = 0.0;
  result->m_flCycle.m_Val = 0.0;
  result->m_flLayerAnimtime = 0.0;
  result->m_flLayerFadeOuttime = 0.0;
  result->m_nSequence.m_Val = to->m_nSequence.m_Val;
  result->m_flCycle.m_Val = Lerp_Hermite<float>(
                              __formal: &current->m_flCycle.m_Val,
                              t: flPercent,
                              p0: &prev->m_flCycle.m_Val,
                              p1: &from->m_flCycle.m_Val,
                              p2: &to->m_flCycle.m_Val);
  result->m_flPrevCycle.m_Val = to->m_flPrevCycle.m_Val;
  result->m_flWeight.m_Val = (float)((float)(to->m_flWeight.m_Val - from->m_flWeight.m_Val) * flPercent)
                           + from->m_flWeight.m_Val;
  result->m_nOrder = to->m_nOrder;
  result->m_flLayerAnimtime = to->m_flLayerAnimtime;
  result->m_flLayerFadeOuttime = to->m_flLayerFadeOuttime;
  result->m_pOwner = to->m_pOwner;
  v6 = 0;
  if ( result->m_nSequence.m_Val != current->m_nSequence.m_Val
    || (result->m_flWeight.m_Val == 0.0) != (current->m_flWeight.m_Val == 0.0) )
  {
    v6 = 48;
  }
  if ( result->m_flCycle.m_Val != current->m_flCycle.m_Val )
    v6 |= 8u;
  v7 = result;
  if ( result->m_nOrder != current->m_nOrder )
    v6 |= 0x10u;
  result->m_nInvalidatePhysicsBits = v6;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100349D0
// Name: private: void C_BaseAnimatingOverlay::CheckForLayerChanges(class CStudioHdr __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BaseAnimatingOverlay::CheckForLayerChanges(
        C_BaseAnimatingOverlay *this@<ecx>,
        float a2@<ebx>,
        CStudioHdr *hdr,
        float currentTime)
{
  C_BaseAnimatingOverlay *v4; // esi
  int v5; // edi
  char *v6; // eax
  int v7; // ecx
  int v8; // edx
  float *v9; // ecx
  float v10; // xmm0_4
  float *v11; // edi
  int v12; // ecx
  int v13; // edx
  float *v14; // ecx
  float *v15; // ebx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int m_nValue; // esi
  int v20; // eax
  const studiohdr_t *m_pStudioHdr; // edx
  int v22; // ecx
  mstudioseqdesc_t *v23; // eax
  int v24; // eax
  const studiohdr_t *v25; // ecx
  mstudioseqdesc_t *v26; // eax
  C_AnimationLayer *v27; // edx
  int m_Val; // eax
  const studiohdr_t *v29; // ecx
  mstudioseqdesc_t *v30; // eax
  C_BaseAnimating *v31; // ebx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  C_AnimationLayer *v35; // eax
  C_AnimationLayer *v36; // eax
  const char *v37; // esi
  CInterpolatedVarArrayBase<C_AnimationLayer,0>::CInterpolationInfo pInfo; // [esp+2Ch] [ebp-3Ch] BYREF
  float *m_flOverlayPrevEventCycle; // [esp+40h] [ebp-28h]
  float num; // [esp+44h] [ebp-24h]
  float t2; // [esp+48h] [ebp-20h]
  float t1; // [esp+4Ch] [ebp-1Ch]
  float t0; // [esp+50h] [ebp-18h]
  C_BaseAnimating *v45; // [esp+54h] [ebp-14h]
  int v46; // [esp+58h] [ebp-10h]
  int i; // [esp+5Ch] [ebp-Ch]
  C_AnimationLayer *pPrev2; // [esp+60h] [ebp-8h]
  CDisableRangeChecks disableRangeChecks; // [esp+66h] [ebp-2h] BYREF
  CDisableRangeChecks v50; // [esp+67h] [ebp-1h] BYREF

  v4 = this;
  v45 = this;
  CDisableRangeChecks::CDisableRangeChecks(this: &disableRangeChecks);
  v5 = 0;
  i = 0;
  if ( v4->m_iv_AnimOverlay.m_Size > 0 )
  {
    v46 = 0;
    m_flOverlayPrevEventCycle = v4->m_flOverlayPrevEventCycle;
    while ( 1 )
    {
      CDisableRangeChecks::CDisableRangeChecks(this: &v50);
      CInterpolatedVarArrayBase<C_AnimationLayer,0>::GetInterpolationInfo(
        this: (CInterpolatedVarArrayBase<C_AnimationLayer,0> *)((char *)v4->m_iv_AnimOverlay.m_Memory.m_pMemory + v5),
        &pInfo,
        currentTime,
        interpolation_amount: *(float *)((char *)&v4->m_iv_AnimOverlay.m_Memory.m_pMemory->m_InterpolationAmount + v5),
        pNoMoreChanges: nullptr);
      v6 = (char *)v4->m_iv_AnimOverlay.m_Memory.m_pMemory + v5;
      if ( pInfo.newer < 0 || pInfo.newer >= *((unsigned __int16 *)v6 + 8) )
      {
        v10 = 0.0;
        t0 = 0.0;
        v11 = nullptr;
      }
      else
      {
        v7 = pInfo.newer + *((unsigned __int16 *)v6 + 7);
        v8 = *((unsigned __int16 *)v6 + 6);
        if ( v7 >= v8 )
          v7 -= v8;
        v9 = (float *)(*((_DWORD *)v6 + 2) + 44 * v7);
        t0 = *v9;
        v10 = 0.0;
        v11 = v9 + 1;
      }
      if ( pInfo.older < 0 || pInfo.older >= *((unsigned __int16 *)v6 + 8) )
      {
        t1 = 0.0;
        v15 = nullptr;
      }
      else
      {
        v12 = pInfo.older + *((unsigned __int16 *)v6 + 7);
        v13 = *((unsigned __int16 *)v6 + 6);
        if ( v12 >= v13 )
          v12 -= v13;
        v14 = (float *)(*((_DWORD *)v6 + 2) + 44 * v12);
        t1 = *v14;
        v15 = v14 + 1;
      }
      if ( pInfo.oldest < 0 || pInfo.oldest >= *((unsigned __int16 *)v6 + 8) )
      {
        pPrev2 = nullptr;
      }
      else
      {
        v16 = pInfo.oldest + *((unsigned __int16 *)v6 + 7);
        v17 = *((unsigned __int16 *)v6 + 6);
        if ( v16 >= v17 )
          v16 -= v17;
        v18 = *((_DWORD *)v6 + 2) + 44 * v16;
        v10 = *(float *)v18;
        pPrev2 = (C_AnimationLayer *)(v18 + 4);
      }
      t2 = v10;
      if ( v11 != nullptr && v15 != nullptr && *((_DWORD *)v11 + 3) != *((_DWORD *)v15 + 3) )
        break;
      CDisableRangeChecks::~CDisableRangeChecks(this: &v50);
LABEL_65:
      ++m_flOverlayPrevEventCycle;
      v46 += 44;
      if ( ++i >= v4->m_iv_AnimOverlay.m_Size )
        goto LABEL_66;
      v5 = v46;
    }
    if ( r_sequence_debug.m_pParent != nullptr )
      m_nValue = r_sequence_debug.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue == ((int (__thiscall *)(IClientNetworkable *, _DWORD))v45->entindex)(
                       a1: &v45->IClientNetworkable,
                       a2: LODWORD(a2)) )
    {
      v20 = *((_DWORD *)v11 + 3);
      if ( hdr->m_pVModel != nullptr )
      {
        v23 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: *((_DWORD *)v11 + 3));
      }
      else
      {
        m_pStudioHdr = hdr->m_pStudioHdr;
        v22 = *((_DWORD *)v11 + 3);
        if ( v20 < 0 || v20 >= m_pStudioHdr->numlocalseq )
          v22 = 0;
        v23 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v22 + m_pStudioHdr->localseqindex);
      }
      DevMsgRT(
        pMsg: "(%7.4f : %30s : %5.3f : %4.2f : %1d)\n",
        t0,
        (const char *)v23 + v23->szlabelindex,
        v11[7],
        v11[5],
        i);
      v24 = *((_DWORD *)v15 + 3);
      if ( hdr->m_pVModel != nullptr )
      {
        v26 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: *((_DWORD *)v15 + 3));
      }
      else
      {
        v25 = hdr->m_pStudioHdr;
        if ( v24 < 0 || v24 >= v25->numlocalseq )
          v24 = 0;
        v26 = (mstudioseqdesc_t *)((char *)v25 + 212 * v24 + v25->localseqindex);
      }
      DevMsgRT(
        pMsg: "(%7.4f : %30s : %5.3f : %4.2f : %1d)\n",
        t1,
        (const char *)v26 + v26->szlabelindex,
        v15[7],
        v15[5],
        i);
      v27 = pPrev2;
      if ( pPrev2 == nullptr )
      {
LABEL_50:
        v15[3] = v11[3];
        v15[7] = v11[4];
        v15[5] = v11[5];
        if ( v27 == nullptr )
        {
          v31 = v45;
          goto LABEL_63;
        }
        num = 0.0;
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(t0 - t1) & _mask__AbsFloat_) > 0.001 )
          num = (float)(t2 - t1) / (float)(t0 - t1);
        v31 = v45;
        v27->m_nSequence.m_Val = (int)v11[3];
        if ( (unsigned __int8)C_BaseAnimating::IsSequenceLooping(
                                this: v31,
                                pStudioHdr: hdr,
                                iSequence: *((_DWORD *)v11 + 3)) != 0 )
        {
          v32 = v11[7];
          v33 = v11[4];
          if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v32 - v33) & _mask__AbsFloat_) >= 0.5 )
          {
            if ( v32 <= v33 )
              v32 = v32 + 1.0;
            else
              v33 = v33 + 1.0;
          }
          v34 = (float)((float)((float)(1.0 - num) * v33) + (float)(v32 * num))
              - (float)(int)(float)((float)((float)(1.0 - num) * v33) + (float)(v32 * num));
          if ( v34 < 0.0 )
          {
            v35 = pPrev2;
            pPrev2->m_flCycle.m_Val = v34 + 1.0;
            v35->m_flWeight.m_Val = v11[5];
LABEL_63:
            v37 = &v31[1].m_iClassname[v46];
            **((_BYTE **)v37 + 8) = C_BaseAnimating::IsSequenceLooping(
                                      this: v31,
                                      pStudioHdr: hdr,
                                      iSequence: *((_DWORD *)v11 + 3));
            a2 = currentTime;
            (*(void (**)(void))(*(_DWORD *)&v31[1].m_iClassname[v46] + 24))();
            *m_flOverlayPrevEventCycle = v11[4] - 0.01;
            CDisableRangeChecks::~CDisableRangeChecks(this: &v50);
            v4 = (C_BaseAnimatingOverlay *)v45;
            goto LABEL_65;
          }
        }
        else
        {
          v34 = (float)((float)(v11[7] - v11[4]) * num) + v11[4];
        }
        v36 = pPrev2;
        pPrev2->m_flCycle.m_Val = v34;
        v36->m_flWeight.m_Val = v11[5];
        goto LABEL_63;
      }
      m_Val = pPrev2->m_nSequence.m_Val;
      if ( hdr->m_pVModel != nullptr )
      {
        v30 = CStudioHdr::pSeqdesc_Internal(this: hdr, i: pPrev2->m_nSequence.m_Val);
        v27 = pPrev2;
      }
      else
      {
        v29 = hdr->m_pStudioHdr;
        if ( m_Val < 0 || m_Val >= v29->numlocalseq )
          m_Val = 0;
        v30 = (mstudioseqdesc_t *)((char *)v29 + 212 * m_Val + v29->localseqindex);
      }
      DevMsgRT(
        pMsg: "(%7.4f : %30s : %5.3f : %4.2f : %1d)\n",
        t2,
        (const char *)v30 + v30->szlabelindex,
        v27->m_flCycle.m_Val,
        v27->m_flWeight.m_Val,
        i);
    }
    v27 = pPrev2;
    goto LABEL_50;
  }
LABEL_66:
  CDisableRangeChecks::~CDisableRangeChecks(this: &disableRangeChecks);
}

//------------------------------------------------------------------------------
// Address: 0x10034E60
// Name: public: virtual void C_BaseAnimatingOverlay::AccumulateLayers(class IBoneSetup __near &,class Vector __near * const,class Quaternion __near * const,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimatingOverlay::AccumulateLayers(
        C_BaseAnimatingOverlay *this,
        IBoneSetup *boneSetup,
        Vector *pos,
        Quaternion *q,
        float currentTime)
{
  IBoneSetup *v5; // edi
  float v7; // ebx
  int v8; // edi
  char *v9; // edi
  int v10; // eax
  bool v11; // zf
  int *v12; // eax
  C_BaseEntity *v13; // ecx
  CStudioHdr *StudioHdr; // eax
  CStudioHdr *v15; // eax
  int v16; // eax
  int v17; // edi
  C_AnimationLayer *m_pMemory; // edx
  unsigned int v19; // edi
  int m_Val; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  float v22; // xmm0_4
  int m_nValue; // ebx
  int v24; // edi
  CStudioHdr *v25; // eax
  const studiohdr_t *v26; // eax
  int v27; // edx
  mstudioseqdesc_t *v28; // eax
  int layer[15]; // [esp+2Ch] [ebp-50h] BYREF
  bool isLooping[4]; // [esp+68h] [ebp-14h]
  int nSequences; // [esp+6Ch] [ebp-10h]
  int j; // [esp+70h] [ebp-Ch]
  float fWeight; // [esp+74h] [ebp-8h]
  float fCycle; // [esp+78h] [ebp-4h]

  v5 = boneSetup;
  C_BaseEntity::PerformCustomPhysics(
    (vgui::MenuButton *)this,
    tx0: (int)boneSetup,
    ty0: (int)pos,
    tx1: (int)q,
    ty1: SLODWORD(currentTime));
  v7 = 0.0;
  layer[0] = 15;
  layer[1] = 15;
  layer[2] = 15;
  layer[3] = 15;
  layer[4] = 15;
  layer[5] = 15;
  layer[6] = 15;
  layer[7] = 15;
  layer[8] = 15;
  layer[9] = 15;
  layer[10] = 15;
  layer[11] = 15;
  layer[12] = 15;
  layer[13] = 15;
  layer[14] = 15;
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    v8 = 0;
    j = 0;
    do
    {
      v9 = (char *)this->m_AnimOverlay.m_Memory.m_pMemory + v8;
      v10 = *((_DWORD *)v9 + 2);
      if ( v10 < 15 )
      {
        v11 = layer[v10] == 15;
        v12 = &layer[v10];
        if ( v11 )
        {
          *(float *)v12 = v7;
        }
        else
        {
          v13 = *((C_BaseEntity **)v9 + 8);
          if ( v13 != nullptr && *((_DWORD *)v9 + 2) != 15 )
            C_BaseEntity::InvalidatePhysicsRecursive(this: v13, nChangeFlags: 16);
          *((_DWORD *)v9 + 2) = 15;
        }
      }
      ++LODWORD(v7);
      v8 = j + 40;
      j += 40;
    }
    while ( SLODWORD(v7) < this->m_AnimOverlay.m_Size );
    v5 = boneSetup;
  }
  StudioHdr = IBoneSetup::GetStudioHdr(this: v5);
  C_BaseAnimatingOverlay::CheckForLayerChanges(this, a2: v7, hdr: StudioHdr, currentTime);
  v15 = IBoneSetup::GetStudioHdr(this: v5);
  if ( v15->m_pVModel != nullptr )
    nSequences = CStudioHdr::GetNumSeq_Internal(this: v15);
  else
    nSequences = v15->m_pStudioHdr->numlocalseq;
  v16 = 0;
  j = 0;
  do
  {
    v17 = layer[v16];
    if ( v17 < this->m_AnimOverlay.m_Size )
    {
      m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
      v19 = v17;
      if ( m_pMemory[v19].m_nSequence.m_Val < nSequences )
      {
        fWeight = m_pMemory[v19].m_flWeight.m_Val;
        if ( fWeight > 0.0 )
        {
          v11 = this->m_pStudioHdr == nullptr;
          m_Val = m_pMemory[v19].m_nSequence.m_Val;
          fCycle = m_pMemory[v19].m_flCycle.m_Val;
          if ( v11 && this->GetModel(this: &this->IClientRenderable) != nullptr )
            C_BaseAnimating::LockStudioHdr(this);
          m_pStudioHdr = this->m_pStudioHdr;
          if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
            m_pStudioHdr = nullptr;
          isLooping[0] = C_BaseAnimating::IsSequenceLooping(this, pStudioHdr: m_pStudioHdr, iSequence: m_Val);
          fCycle = C_BaseAnimating::ClampCycle(this, flCycle: fCycle, isLooping: isLooping[0]);
          v22 = fWeight;
          if ( fWeight > 1.0 )
          {
            v22 = 1.0;
            fWeight = 1.0;
          }
          IBoneSetup::AccumulatePose(
            this: boneSetup,
            pos,
            q,
            sequence: this->m_AnimOverlay.m_Memory.m_pMemory[v19].m_nSequence.m_Val,
            cycle: fCycle,
            flWeight: v22,
            flTime: currentTime,
            pIKContext: this->m_pIk);
          if ( r_sequence_debug.m_pParent != nullptr )
            m_nValue = r_sequence_debug.m_pParent->m_Value.m_nValue;
          else
            m_nValue = 0;
          if ( m_nValue == this->entindex(this: &this->IClientNetworkable) )
          {
            v24 = this->m_AnimOverlay.m_Memory.m_pMemory[v19].m_nSequence.m_Val;
            v25 = IBoneSetup::GetStudioHdr(this: boneSetup);
            if ( v25->m_pVModel != nullptr )
            {
              v28 = CStudioHdr::pSeqdesc_Internal(this: v25, i: v24);
            }
            else
            {
              v26 = v25->m_pStudioHdr;
              v27 = v24;
              if ( v24 < 0 || v24 >= v26->numlocalseq )
                v27 = 0;
              v28 = (mstudioseqdesc_t *)((char *)v26 + 212 * v27 + v26->localseqindex);
            }
            DevMsgRT(
              pMsg: "%8.4f : %30s : %5.3f : %4.2f : %1d\n",
              currentTime,
              (const char *)v28 + v28->szlabelindex,
              fCycle,
              fWeight,
              layer[j]);
          }
        }
      }
    }
    v16 = j + 1;
    j = v16;
  }
  while ( v16 < 15 );
}

//------------------------------------------------------------------------------
// Address: 0x10035130
// Name: public: virtual void C_BaseAnimatingOverlay::DoAnimationEvents(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimatingOverlay::DoAnimationEvents(C_BaseAnimatingOverlay *this, CStudioHdr *pStudioHdr)
{
  IMDLCache *v2; // edi
  CStudioHdr *v4; // ebx
  C_AnimationLayer *v5; // edx
  int m_Val; // ecx
  const studiohdr_t *m_pStudioHdr; // edx
  int v8; // eax
  mstudioseqdesc_t *v9; // edi
  C_AnimationLayer *v10; // ecx
  char v11; // bl
  float v12; // xmm0_4
  float v13; // xmm1_4
  mstudioevent_for_client_server_t *EventIndexForSequence; // eax
  int *p_type; // edi
  C_BaseAnimatingOverlay_vtbl *v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  $E963F8FE9DC1729540139F392D973E98 *v20; // edi
  int v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  bool v24; // al
  float v25; // xmm0_4
  int event_highword; // eax
  C_BaseAnimatingOverlay_vtbl *v27; // ebx
  int v28; // eax
  int v29; // eax
  mstudioevent_for_client_server_t *pevent; // [esp+10h] [ebp-20h]
  int j; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  int ia; // [esp+18h] [ebp-18h]
  int nSequences; // [esp+1Ch] [ebp-14h]
  IMDLCache *cacheCriticalSection; // [esp+20h] [ebp-10h]
  mstudioseqdesc_t *seqdesc; // [esp+24h] [ebp-Ch]
  int v37; // [esp+28h] [ebp-8h]
  float *m_flOverlayPrevEventCycle; // [esp+2Ch] [ebp-4h]

  v2 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v4 = pStudioHdr;
  if ( pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: pStudioHdr)
    && (pStudioHdr->m_pVModel != nullptr
      ? (nSequences = CStudioHdr::GetNumSeq_Internal(this: pStudioHdr))
      : (nSequences = pStudioHdr->m_pStudioHdr->numlocalseq),
        C_BaseAnimating::DoAnimationEvents(this, pStudioHdr),
        C_BaseAnimatingOverlay::CheckForLayerChanges(
          this,
          a2: *(float *)&pStudioHdr,
          hdr: pStudioHdr,
          currentTime: *(float *)(gpGlobals.m_Index + 12)),
        j = 0,
        this->m_AnimOverlay.m_Size > 0) )
  {
    v37 = 0;
    m_flOverlayPrevEventCycle = this->m_flOverlayPrevEventCycle;
LABEL_8:
    v5 = &this->m_AnimOverlay.m_Memory.m_pMemory[v37];
    m_Val = v5->m_nSequence.m_Val;
    if ( m_Val >= nSequences || v5->m_flWeight.m_Val == 0.0 || v5->m_nOrder == 15 )
      goto LABEL_57;
    if ( v4->m_pVModel != nullptr )
    {
      seqdesc = CStudioHdr::pSeqdesc_Internal(this: v4, i: v5->m_nSequence.m_Val);
      v9 = seqdesc;
    }
    else
    {
      m_pStudioHdr = v4->m_pStudioHdr;
      v8 = m_Val;
      if ( m_Val < 0 || m_Val >= m_pStudioHdr->numlocalseq )
        v8 = 0;
      v9 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v8 + m_pStudioHdr->localseqindex);
      seqdesc = v9;
    }
    if ( v9->numevents == 0 )
      goto LABEL_56;
    v10 = &this->m_AnimOverlay.m_Memory.m_pMemory[v37];
    if ( v10->m_flCycle.m_Val == *m_flOverlayPrevEventCycle )
      goto LABEL_56;
    v11 = 0;
    if ( (unsigned __int8)C_BaseAnimating::IsSequenceLooping(this, iSequence: v10->m_nSequence.m_Val) == 0 )
      goto LABEL_24;
    v12 = *m_flOverlayPrevEventCycle;
    if ( *m_flOverlayPrevEventCycle <= 0.0 )
      goto LABEL_24;
    v13 = this->m_AnimOverlay.m_Memory.m_pMemory[v37].m_flCycle.m_Val;
    if ( v12 < v13 )
      goto LABEL_24;
    if ( (float)(v12 - v13) > 0.5 )
    {
      v11 = 1;
LABEL_24:
      EventIndexForSequence = GetEventIndexForSequence(seqdesc: v9);
      pevent = EventIndexForSequence;
      if ( v11 == 0 )
        goto LABEL_36;
      i = 0;
      if ( v9->numevents <= 0 )
        goto LABEL_35;
      p_type = &EventIndexForSequence->type;
      while ( 1 )
      {
        if ( (*p_type & 0x400) != 0 )
        {
          if ( (*p_type & 0x10) != 0 )
            goto LABEL_31;
        }
        else if ( *(p_type - 1) >= 5000 )
        {
LABEL_31:
          if ( *m_flOverlayPrevEventCycle < *((float *)p_type - 2) )
          {
            v16 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
            v17 = mstudioevent_for_client_server_t::Event(this: (mstudioevent_for_client_server_t *)(p_type - 2));
            v18 = ((int (__thiscall *)(C_BaseAnimatingOverlay *, int, int *))v16->GetAbsAngles)(
                    a1: this,
                    a2: v17,
                    a3: p_type + 1);
            v19 = ((int (__thiscall *)(C_BaseAnimatingOverlay *, int))this->GetAbsOrigin)(a1: this, a2: v18);
            ((void (__thiscall *)(C_BaseAnimatingOverlay *, int))v16->FireEvent)(a1: this, a2: v19);
          }
        }
        p_type += 20;
        if ( ++i >= seqdesc->numevents )
        {
          EventIndexForSequence = pevent;
          v9 = seqdesc;
LABEL_35:
          *m_flOverlayPrevEventCycle = -0.0099999998;
LABEL_36:
          ia = 0;
          if ( v9->numevents > 0 )
          {
            v20 = &EventIndexForSequence->___u1;
            do
            {
              v21 = *(_DWORD *)&v20[2]._event_highword;
              if ( (v21 & 0x400) != 0 )
              {
                if ( (v21 & 0x10) != 0 )
                  goto LABEL_42;
              }
              else if ( *(int *)&v20->_event_highword >= 5000 )
              {
LABEL_42:
                v22 = *m_flOverlayPrevEventCycle;
                v23 = this->m_AnimOverlay.m_Memory.m_pMemory[v37].m_flCycle.m_Val;
                v24 = *m_flOverlayPrevEventCycle > v23 || v22 == 0.0;
                v25 = *(float *)&v20[-2]._event_highword;
                if ( (v25 > v22 || v24 && v25 == 0.0) && v23 >= v25 )
                {
                  if ( (*(_DWORD *)&v20[2]._event_highword & 0x400) != 0 )
                    event_highword = v20->_event_highword;
                  else
                    event_highword = *(_DWORD *)&v20->_event_highword;
                  v27 = this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
                  v28 = ((int (__thiscall *)(C_BaseAnimatingOverlay *, int, $E963F8FE9DC1729540139F392D973E98 *))this->GetAbsAngles)(
                          a1: this,
                          a2: event_highword,
                          a3: &v20[4]);
                  v29 = ((int (__thiscall *)(C_BaseAnimatingOverlay *, int))this->GetAbsOrigin)(a1: this, a2: v28);
                  ((void (__thiscall *)(C_BaseAnimatingOverlay *, int))v27->FireEvent)(a1: this, a2: v29);
                }
              }
              v20 += 40;
              ++ia;
            }
            while ( ia < seqdesc->numevents );
          }
          v4 = pStudioHdr;
          *m_flOverlayPrevEventCycle = this->m_AnimOverlay.m_Memory.m_pMemory[v37].m_flCycle.m_Val;
LABEL_56:
          v2 = cacheCriticalSection;
LABEL_57:
          ++m_flOverlayPrevEventCycle;
          ++v37;
          if ( ++j >= this->m_AnimOverlay.m_Size )
            goto LABEL_58;
          goto LABEL_8;
        }
      }
    }
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
  else
  {
LABEL_58:
    v2->EndLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035B20
// Name: public: C_BaseAnimatingOverlay::C_BaseAnimatingOverlay(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseAnimatingOverlay *__thiscall C_BaseAnimatingOverlay::C_BaseAnimatingOverlay(C_BaseAnimatingOverlay *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimatingOverlay_vtbl *)&C_BaseAnimatingOverlay::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseAnimatingOverlay::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseAnimatingOverlay::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseAnimatingOverlay::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseAnimatingOverlay::`vftable';
  this->m_AnimOverlay.m_Memory.m_pMemory = nullptr;
  this->m_AnimOverlay.m_Memory.m_nAllocationCount = 0;
  this->m_AnimOverlay.m_Memory.m_nGrowSize = 0;
  this->m_AnimOverlay.m_Size = 0;
  this->m_AnimOverlay.m_pElements = nullptr;
  this->m_iv_AnimOverlay.m_Memory.m_pMemory = nullptr;
  this->m_iv_AnimOverlay.m_Memory.m_nAllocationCount = 0;
  this->m_iv_AnimOverlay.m_Memory.m_nGrowSize = 0;
  this->m_iv_AnimOverlay.m_Size = 0;
  this->m_iv_AnimOverlay.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035B90
// Name: public: virtual C_BaseAnimatingOverlay::~C_BaseAnimatingOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimatingOverlay::~C_BaseAnimatingOverlay(C_BaseAnimatingOverlay *this)
{
  CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>>::Purge(this: &this->m_iv_AnimOverlay);
  if ( this->m_iv_AnimOverlay.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_iv_AnimOverlay.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_iv_AnimOverlay.m_Memory.m_pMemory);
      this->m_iv_AnimOverlay.m_Memory.m_pMemory = nullptr;
    }
    this->m_iv_AnimOverlay.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_AnimOverlay);
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10035E30
// Name: public: void C_BaseAnimatingOverlay::SetNumAnimOverlays(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimatingOverlay::SetNumAnimOverlays(C_BaseAnimatingOverlay *this, int num)
{
  int m_Size; // eax
  int v4; // ebx
  C_AnimationLayer *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  C_AnimationLayer *v7; // eax

  m_Size = this->m_AnimOverlay.m_Size;
  if ( m_Size >= num )
  {
    if ( m_Size > num )
    {
      CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::RemoveMultiple(
        this: &this->m_AnimOverlay,
        elem: num,
        num: m_Size - num);
      C_BaseEntity::InvalidatePhysicsRecursive(this, nChangeFlags: 16);
    }
  }
  else if ( num - m_Size > 0 )
  {
    v4 = num - m_Size;
    do
    {
      --v4;
      this->m_AnimOverlay.m_Memory.m_pMemory[CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertBefore(
                                               this: &this->m_AnimOverlay,
                                               elem: this->m_AnimOverlay.m_Size)].m_pOwner = this;
    }
    while ( v4 != 0 );
  }
  if ( this->m_AnimOverlay.m_Memory.m_nAllocationCount < 15 && this->m_AnimOverlay.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_AnimOverlay.m_Memory.m_nAllocationCount = 15;
    m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (C_AnimationLayer *)((int (__stdcall *)(C_AnimationLayer *, int))v6->Realloc_2)(a1: m_pMemory, a2: 600);
    else
      v7 = (C_AnimationLayer *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 600);
    this->m_AnimOverlay.m_Memory.m_pMemory = v7;
  }
  this->m_AnimOverlay.m_pElements = this->m_AnimOverlay.m_Memory.m_pMemory;
  memset(
    dst: (int)&this->m_AnimOverlay.m_Memory.m_pMemory[this->m_AnimOverlay.m_Size],
    value: nullptr,
    count: 40 * (this->m_AnimOverlay.m_Memory.m_nAllocationCount - this->m_AnimOverlay.m_Size));
}

//------------------------------------------------------------------------------
// Address: 0x10036740
// Name: void ResizeAnimationLayerCallback(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResizeAnimationLayerCallback(char *pStruct, int offsetToUtlVector, int len)
{
  int v3; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // eax
  bool v12; // zf
  int v13; // edi
  int v14; // eax
  int v15; // ebx
  IInterpolatedVar *v16; // edi
  void *v17; // edx
  void *v18; // eax
  int v19; // ecx
  int v20; // eax
  unsigned int v21; // [esp-4h] [ebp-14h]
  int diff; // [esp+8h] [ebp-8h]
  int diffa; // [esp+8h] [ebp-8h]
  int v24; // [esp+Ch] [ebp-4h]
  int v25; // [esp+Ch] [ebp-4h]

  v3 = len;
  v4 = *((_DWORD *)pStruct + 817);
  diff = len - v4;
  if ( len != v4 )
  {
    v5 = 0;
    if ( v4 > 0 )
    {
      v6 = 0;
      do
      {
        C_BaseEntity::RemoveVar(
          this: (C_BaseEntity *)pStruct,
          data: (void *)(v6 + *((_DWORD *)pStruct + 814)),
          bAssert: true);
        ++v5;
        v6 += 40;
      }
      while ( v5 < *((_DWORD *)pStruct + 817) );
    }
    C_BaseEntity::InvalidatePhysicsRecursive(this: (C_BaseEntity *)pStruct, nChangeFlags: 16);
    if ( diff <= 0 )
    {
      v13 = len;
      v14 = *((_DWORD *)pStruct + 817) + diff - len;
      if ( v14 > 0 && diff < 0 )
        _V_memmove(
          dest: (void *)(*((_DWORD *)pStruct + 814) + 40 * len),
          src: (const void *)(*((_DWORD *)pStruct + 814) + 40 * (len - diff)),
          count: 40 * v14);
      *((_DWORD *)pStruct + 817) += diff;
      CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>>::RemoveMultiple(
        this: (CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int> > *)(pStruct + 3276),
        elem: len,
        num: -diff);
    }
    else
    {
      v24 = diff;
      do
      {
        v7 = *((_DWORD *)pStruct + 817);
        v8 = *((_DWORD *)pStruct + 815);
        if ( v7 + 1 > v8 )
          CUtlMemory<SaveRestoreBlockHeader_t,int>::Grow(
            this: (CUtlMemory<C_AnimationLayer,int> *)(pStruct + 3256),
            num: v7 - v8 + 1);
        ++*((_DWORD *)pStruct + 817);
        v9 = *((_DWORD *)pStruct + 814);
        v10 = *((_DWORD *)pStruct + 817) - v7 - 1;
        *((_DWORD *)pStruct + 818) = v9;
        if ( v10 > 0 )
          _V_memmove(dest: (void *)(v9 + 40 * v7 + 40), src: (const void *)(v9 + 40 * v7), count: 40 * v10);
        v11 = (_DWORD *)(40 * v7 + *((_DWORD *)pStruct + 814));
        if ( v11 != nullptr )
        {
          v11[8] = 0;
          v11[9] = 0;
          v11[3] = 0;
          v11[4] = 0;
          v11[5] = 0;
          v11[6] = 0;
          v11[7] = 0;
          *v11 = 0;
          v11[1] = 0;
        }
        v12 = v24-- == 1;
        *(_DWORD *)(*((_DWORD *)pStruct + 814) + 40 * v7 + 32) = pStruct;
      }
      while ( !v12 );
      CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int>>::InsertMultipleBefore(
        this: (CUtlVector<CInterpolatedVar<C_AnimationLayer>,CUtlMemory<CInterpolatedVar<C_AnimationLayer>,int> > *)(pStruct + 3276),
        elem: *((_DWORD *)pStruct + 822),
        num: diff);
      v13 = len;
    }
    v15 = 0;
    if ( v13 > 0 )
    {
      diffa = 0;
      v25 = 0;
      do
      {
        v16 = (IInterpolatedVar *)(v25 + *((_DWORD *)pStruct + 819));
        v16->SetDebugName(this: v16, a2: s_m_iv_AnimOverlayNames[v15]);
        C_BaseEntity::AddVar(
          this: (C_BaseEntity *)pStruct,
          data: (void *)(diffa + *((_DWORD *)pStruct + 814)),
          watcher: v16,
          type: 1,
          bSetup: true);
        v25 += 44;
        ++v15;
        diffa += 40;
      }
      while ( v15 < len );
    }
    v3 = len;
  }
  if ( *((_DWORD *)pStruct + 815) < v3 && *((int *)pStruct + 816) >= 0 )
  {
    v17 = *((void **)pStruct + 814);
    *((_DWORD *)pStruct + 815) = v3;
    v21 = 40 * v3;
    if ( v17 != nullptr )
      v18 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v17, a3: v21);
    else
      v18 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v21);
    *((_DWORD *)pStruct + 814) = v18;
  }
  v19 = *((_DWORD *)pStruct + 814);
  v20 = *((_DWORD *)pStruct + 817);
  *((_DWORD *)pStruct + 818) = v19;
  memset(dst: v19 + 40 * v20, value: nullptr, count: 40 * (*((_DWORD *)pStruct + 815) - v20));
}

//------------------------------------------------------------------------------
// Address: 0x1003F9C0
// Name: class QAngle Lerp_Hermite<class QAngle>(class QAngle const __near &,float,class QAngle const __near &,class QAngle const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
QAngle *__cdecl Lerp_Hermite<QAngle>(
        QAngle *result,
        const QAngle *__formal,
        float t,
        const QAngle *p0,
        const QAngle *p1,
        const QAngle *p2)
{
  float z; // ecx
  Quaternion qt; // [esp+Ch] [ebp-3Ch] BYREF
  Quaternion outQuat; // [esp+1Ch] [ebp-2Ch] BYREF
  Quaternion q; // [esp+2Ch] [ebp-1Ch] BYREF
  QAngle angles; // [esp+3Ch] [ebp-Ch] BYREF

  if ( p2->x == p1->x && p2->y == p1->y && p2->z == p1->z )
  {
    z = p1->z;
    *(_QWORD *)&result->x = *(_QWORD *)&p1->x;
    result->z = z;
    return result;
  }
  else
  {
    AngleQuaternion(angles: p1, &outQuat);
    AngleQuaternion(angles: p2, outQuat: &q);
    QuaternionSlerp(p: &outQuat, &q, t, &qt);
    QuaternionAngles(q: &qt, &angles);
    *result = angles;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10410840
// Name: DT_Animationlayer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Animationlayer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Animationlayer::g_RecvTable);
  return atexit(func: DT_Animationlayer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410860
// Name: DT_Animationlayer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Animationlayer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Animationlayer::ignored>();
  DT_Animationlayer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410870
// Name: DT_OverlayVars::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_OverlayVars::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_OverlayVars::g_RecvTable);
  return atexit(func: DT_OverlayVars::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410890
// Name: DT_OverlayVars::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_OverlayVars::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_OverlayVars::ignored>();
  DT_OverlayVars::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104108C0
// Name: DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseAnimatingOverlay::g_RecvTable);
  return atexit(func: DT_BaseAnimatingOverlay::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104108E0
// Name: DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseAnimatingOverlay::ignored>();
  DT_BaseAnimatingOverlay::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104108F0
// Name: C_BaseAnimatingOverlay_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseAnimatingOverlay_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseAnimatingOverlay::m_PredMap.dataNumFields = 1;
  C_BaseAnimatingOverlay::m_PredMap.dataDesc = (typedescription_t *)&unk_105FCB58;
}

//------------------------------------------------------------------------------
// Address: 0x1042FB60
// Name: DT_Animationlayer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Animationlayer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Animationlayer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB70
// Name: DT_OverlayVars::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_OverlayVars::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_OverlayVars::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FB80
// Name: DT_BaseAnimatingOverlay::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseAnimatingOverlay::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseAnimatingOverlay::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10035BF0
// Name: _C_BaseAnimatingOverlay_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseAnimatingOverlay_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimatingOverlay *v2; // eax
  C_BaseAnimatingOverlay *v3; // eax
  C_BaseAnimatingOverlay *v4; // esi

  v2 = (C_BaseAnimatingOverlay *)C_BaseEntity::operator new(stAllocateBlock: 0xD20u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseAnimatingOverlay::C_BaseAnimatingOverlay(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104108A0
// Name: _dynamic_initializer_for____g_C_BaseAnimatingOverlayClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseAnimatingOverlayClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseAnimatingOverlayClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseAnimatingOverlayClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410910
// Name: _dynamic_initializer_for____g_C_BaseCombatCharacterClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseCombatCharacterClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseCombatCharacterClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseCombatCharacterClientClass;
  return result;
}
