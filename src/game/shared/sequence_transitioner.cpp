// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/sequence_transitioner.cpp
// Functions: 2
// ============================================================

#include "game\shared\sequence_transitioner.h"

//------------------------------------------------------------------------------
// Address: 0x1016A440
// Name: public: void CSequenceTransitioner::CheckForSequenceChange(class CStudioHdr __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequenceTransitioner::CheckForSequenceChange(
        CSequenceTransitioner *this,
        CStudioHdr *hdr,
        int nCurSequence,
        bool bForceNewSequence,
        bool bInterpolate)
{
  C_AnimationLayer *v6; // edi
  CStudioHdr *v7; // ecx
  int NumSeq_Internal; // eax
  mstudioseqdesc_t *v9; // ebx
  float fadeouttime; // xmm0_4

  if ( hdr != nullptr )
  {
    if ( this->m_animationQueue.m_Size == 0 )
    {
      CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertBefore(
        this: &this->m_animationQueue,
        elem: 0);
      C_AnimationLayer::SetOwner(this: this->m_animationQueue.m_Memory.m_pMemory, pOverlay: nullptr);
    }
    v6 = &this->m_animationQueue.m_Memory.m_pMemory[this->m_animationQueue.m_Size - 1];
    if ( v6->m_flLayerAnimtime != 0.0 && (v6->m_nSequence.m_Val != nCurSequence || bForceNewSequence) )
    {
      if ( nCurSequence < 0
        || ((v7 = hdr, hdr->m_pVModel != nullptr)
          ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: hdr), v7 = hdr)
          : (CStudioHdr *)(NumSeq_Internal = hdr->m_pStudioHdr->numlocalseq),
            nCurSequence >= NumSeq_Internal
         || ((v9 = CStudioHdr::pSeqdesc(this: v7, iSequence: nCurSequence))->flags & 2) != 0
         || !bInterpolate) )
      {
        this->m_animationQueue.m_Size = 0;
      }
      else
      {
        fadeouttime = CStudioHdr::pSeqdesc(this: hdr, iSequence: v6->m_nSequence.m_Val)->fadeouttime;
        if ( v9->fadeintime <= fadeouttime )
          fadeouttime = v9->fadeintime;
        v6->m_flLayerFadeOuttime = fadeouttime;
      }
      CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertBefore(
        this: &this->m_animationQueue,
        elem: this->m_animationQueue.m_Size);
      v6 = &this->m_animationQueue.m_Memory.m_pMemory[this->m_animationQueue.m_Size - 1];
      C_AnimationLayer::SetOwner(this: v6, pOverlay: nullptr);
    }
    C_AnimationLayer::SetSequence(this: v6, nSequence: -1);
    v6->m_flLayerAnimtime = 0.0;
    v6->m_flLayerFadeOuttime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016A540
// Name: public: void CSequenceTransitioner::UpdateCurrent(class CStudioHdr __near *,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequenceTransitioner::UpdateCurrent(
        CSequenceTransitioner *this,
        CStudioHdr *hdr,
        int nCurSequence,
        float flCurCycle,
        float flCurPlaybackRate,
        float flCurTime)
{
  C_AnimationLayer *v7; // edi
  int v8; // edi
  int v9; // ebx
  float m_flLayerFadeOuttime; // xmm0_4
  unsigned __int8 *v11; // ecx
  float flWeight; // xmm0_4

  if ( hdr != nullptr )
  {
    if ( this->m_animationQueue.m_Size == 0 )
    {
      CUtlVector<C_AnimationLayer,CUtlMemory<C_AnimationLayer,int>>::InsertBefore(
        this: &this->m_animationQueue,
        elem: 0);
      C_AnimationLayer::SetOwner(this: this->m_animationQueue.m_Memory.m_pMemory, pOverlay: nullptr);
    }
    v7 = &this->m_animationQueue.m_Memory.m_pMemory[this->m_animationQueue.m_Size - 1];
    C_AnimationLayer::SetSequence(this: v7, nSequence: nCurSequence);
    v7->m_flLayerAnimtime = flCurTime;
    C_AnimationLayer::SetCycle(this: v7, flCycle: flCurCycle);
    v7->m_flPlaybackRate.m_Val = flCurPlaybackRate;
    v8 = 0;
    if ( this->m_animationQueue.m_Size - 1 > 0 )
    {
      v9 = 0;
      do
      {
        m_flLayerFadeOuttime = this->m_animationQueue.m_Memory.m_pMemory[v9].m_flLayerFadeOuttime;
        v11 = (unsigned __int8 *)&this->m_animationQueue.m_Memory.m_pMemory[v9];
        if ( m_flLayerFadeOuttime <= 0.0 )
        {
LABEL_14:
          if ( this->m_animationQueue.m_Size - v8 - 1 > 0 )
            _V_memmove(dest: v11, src: v11 + 40, count: 40 * (this->m_animationQueue.m_Size - v8 - 1));
          --this->m_animationQueue.m_Size;
          continue;
        }
        flWeight = 1.0 - (float)((float)(flCurTime - *(float *)v11) / m_flLayerFadeOuttime);
        if ( flWeight <= 0.0 || flWeight > 1.0 )
        {
          if ( flWeight > 1.0 )
          {
            flWeight = 1.0;
            goto LABEL_11;
          }
        }
        else
        {
          flWeight = (float)((float)(flWeight * 3.0) * flWeight)
                   - (float)((float)((float)(flWeight * 2.0) * flWeight) * flWeight);
        }
        if ( flWeight <= 0.0 )
          goto LABEL_14;
LABEL_11:
        C_AnimationLayer::SetWeight(this: (C_AnimationLayer *)v11, flWeight);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_animationQueue.m_Size - 1 );
    }
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102119F0
// Name: public: void CSequenceTransitioner::CheckForSequenceChange(class CStudioHdr __near *,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequenceTransitioner::CheckForSequenceChange(
        CSequenceTransitioner *this,
        CStudioHdr *hdr,
        int nCurSequence,
        bool bForceNewSequence,
        bool bInterpolate)
{
  int m_Size; // eax
  CAnimationLayer *v7; // esi
  int v8; // ecx
  int NumSeq_Internal; // eax
  mstudioseqdesc_t *v10; // ebx
  float fadeouttime; // xmm0_4
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v13; // eax

  if ( hdr != nullptr )
  {
    if ( this->m_animationQueue.m_Size == 0 )
      CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertBefore(this: &this->m_animationQueue, elem: 0);
    m_Size = this->m_animationQueue.m_Size;
    v7 = &this->m_animationQueue.m_Memory.m_pMemory[m_Size - 1];
    if ( this->m_animationQueue.m_Memory.m_pMemory[m_Size - 1].m_flLayerAnimtime != 0.0 )
    {
      v8 = nCurSequence;
      if ( v7->m_nSequence.m_Value != nCurSequence || bForceNewSequence )
      {
        if ( nCurSequence < 0
          || (hdr->m_pVModel != nullptr
            ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: hdr), v8 = nCurSequence)
            : (NumSeq_Internal = hdr->m_pStudioHdr->numlocalseq),
              v8 >= NumSeq_Internal
           || ((v10 = CStudioHdr::pSeqdesc(this: hdr, iSequence: v8))->flags & 2) != 0
           || !bInterpolate) )
        {
          this->m_animationQueue.m_Size = 0;
        }
        else
        {
          fadeouttime = CStudioHdr::pSeqdesc(this: hdr, iSequence: v7->m_nSequence.m_Value)->fadeouttime;
          if ( v10->fadeintime <= fadeouttime )
            fadeouttime = v10->fadeintime;
          v7->m_flLayerFadeOuttime = fadeouttime;
        }
        CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertBefore(
          this: &this->m_animationQueue,
          elem: this->m_animationQueue.m_Size);
        v7 = &this->m_animationQueue.m_Memory.m_pMemory[this->m_animationQueue.m_Size - 1];
      }
    }
    if ( v7->m_nSequence.m_Value != -1 )
    {
      m_pOwnerEntity = v7->m_pOwnerEntity;
      if ( m_pOwnerEntity != nullptr )
      {
        if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
        }
        else
        {
          v13 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
          if ( v13 != nullptr )
          {
            v13->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v13)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v7->m_nSequence.m_Value = -1;
    }
    v7->m_flLayerAnimtime = 0.0;
    v7->m_flLayerFadeOuttime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211B10
// Name: public: void CSequenceTransitioner::UpdateCurrent(class CStudioHdr __near *,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSequenceTransitioner::UpdateCurrent(
        CSequenceTransitioner *this,
        CStudioHdr *hdr,
        int nCurSequence,
        float flCurCycle,
        float flCurPlaybackRate,
        float flCurTime)
{
  int m_Size; // eax
  CAnimationLayer *v8; // esi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v10; // eax
  CBaseAnimatingOverlay *v11; // eax
  CBaseEdict *v12; // eax
  int v13; // ebx
  CAnimationLayer *v14; // esi
  float m_flLayerFadeOuttime; // xmm0_4
  float v16; // xmm0_4
  CBaseAnimatingOverlay *v17; // eax
  CBaseEdict *v18; // eax
  CStudioHdr *hdra; // [esp+Ch] [ebp+8h]
  float flCurCyclea; // [esp+14h] [ebp+10h]

  if ( hdr != nullptr )
  {
    if ( this->m_animationQueue.m_Size == 0 )
      CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertBefore(this: &this->m_animationQueue, elem: 0);
    m_Size = this->m_animationQueue.m_Size;
    v8 = &this->m_animationQueue.m_Memory.m_pMemory[m_Size - 1];
    if ( this->m_animationQueue.m_Memory.m_pMemory[m_Size - 1].m_nSequence.m_Value != nCurSequence )
    {
      m_pOwnerEntity = v8->m_pOwnerEntity;
      if ( m_pOwnerEntity != nullptr )
      {
        if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
        }
        else
        {
          v10 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
          if ( v10 != nullptr )
          {
            v10->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v10)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v8->m_nSequence.m_Value = nCurSequence;
    }
    v8->m_flLayerAnimtime = flCurTime;
    if ( v8->m_flCycle.m_Value != flCurCycle )
    {
      v11 = v8->m_pOwnerEntity;
      if ( v11 != nullptr )
      {
        if ( v11->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v11->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = &v11->m_Network.m_pPev->CBaseEdict;
          if ( v12 != nullptr )
          {
            v12->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v12)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v8->m_flCycle.m_Value = flCurCycle;
    }
    v8->m_flPlaybackRate = flCurPlaybackRate;
    v13 = 0;
    if ( this->m_animationQueue.m_Size - 1 > 0 )
    {
      hdra = nullptr;
      do
      {
        v14 = (CAnimationLayer *)((char *)this->m_animationQueue.m_Memory.m_pMemory + (unsigned int)hdra);
        m_flLayerFadeOuttime = v14->m_flLayerFadeOuttime;
        if ( m_flLayerFadeOuttime <= 0.0 )
        {
LABEL_35:
          if ( this->m_animationQueue.m_Size - v13 - 1 > 0 )
            _V_memmove(dest: v14, src: &v14[1], count: 76 * (this->m_animationQueue.m_Size - v13 - 1));
          --this->m_animationQueue.m_Size;
          continue;
        }
        v16 = 1.0 - (float)((float)(flCurTime - v14->m_flLayerAnimtime) / m_flLayerFadeOuttime);
        flCurCyclea = v16;
        if ( v16 <= 0.0 || v16 > 1.0 )
        {
          if ( v16 > 1.0 )
          {
            v16 = 1.0;
            flCurCyclea = 1.0;
            goto LABEL_25;
          }
        }
        else
        {
          v16 = (float)((float)(v16 * 3.0) * v16) - (float)((float)((float)(v16 * 2.0) * v16) * v16);
          flCurCyclea = v16;
        }
        if ( v16 <= 0.0 )
          goto LABEL_35;
LABEL_25:
        if ( v14->m_flWeight.m_Value == v16 )
          goto LABEL_34;
        v17 = v14->m_pOwnerEntity;
        if ( v17 == nullptr )
          goto LABEL_33;
        if ( !v17->m_Network.m_TimerEvent.m_bRegistered )
        {
          v18 = &v17->m_Network.m_pPev->CBaseEdict;
          if ( v18 != nullptr )
          {
            v18->m_fStateFlags |= 0x101u;
            v16 = flCurCyclea;
            CBaseEdict::GetChangeAccessor(this: v18)->m_iChangeInfoSerialNumber = 0;
          }
LABEL_33:
          v14->m_flWeight.m_Value = v16;
LABEL_34:
          ++v13;
          hdra = (CStudioHdr *)((char *)hdra + 76);
          continue;
        }
        *((_BYTE *)&v17->m_Network + 76) |= 1u;
        ++v13;
        hdra = (CStudioHdr *)((char *)hdra + 76);
        v14->m_flWeight.m_Value = v16;
      }
      while ( v13 < this->m_animationQueue.m_Size - 1 );
    }
  }
}

} // namespace server
