// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/baseanimatingoverlay.cpp
// Functions: 57
// ============================================================

#include "game\server\baseanimatingoverlay.h"

//------------------------------------------------------------------------------
// Address: 0x1009F040
// Name: public: virtual struct datamap_t __near * CBaseAnimatingOverlay::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseAnimatingOverlay::GetDataDescMap(CBaseAnimatingOverlay *this)
{
  return &CBaseAnimatingOverlay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1009F250
// Name: public: void CAnimationLayer::DispatchAnimEvents(class CBaseAnimating __near *,class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimationLayer::DispatchAnimEvents(
        CAnimationLayer *this,
        CBaseAnimating *eventHandler,
        CBaseAnimating *pOwner)
{
  CStudioHdr *m_pStudioHdr; // ebx
  int v5; // eax
  int m_Value; // ecx
  const studiohdr_t *v7; // edx
  int v8; // eax
  mstudioseqdesc_t *v9; // eax
  double v10; // st7
  bool v11; // zf
  float v12; // xmm0_4
  int v13; // ecx
  int i; // edi
  bool v15; // cc
  double AnimTimeInterval; // st7
  bool v17; // al
  bool (__thiscall *HandleBehaviorAnimEvent)(CBaseAnimating *, animevent_t *); // edx
  animevent_t event; // [esp+24h] [ebp-2Ch] BYREF
  float flStart; // [esp+40h] [ebp-10h]
  float flCycle; // [esp+44h] [ebp-Ch]
  float flEnd; // [esp+48h] [ebp-8h]
  float flCycleRate; // [esp+4Ch] [ebp-4h]

  if ( pOwner->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: pOwner) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pOwner);
  m_pStudioHdr = pOwner->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr
    && m_pStudioHdr->m_pStudioHdr != nullptr
    && CStudioHdr::SequencesAvailable(this: pOwner->m_pStudioHdr) )
  {
    v5 = m_pStudioHdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: m_pStudioHdr)
       : m_pStudioHdr->m_pStudioHdr->numlocalseq;
    m_Value = this->m_nSequence.m_Value;
    if ( m_Value < v5 )
    {
      if ( m_pStudioHdr->m_pVModel != nullptr )
      {
        v9 = CStudioHdr::pSeqdesc_Internal(this: m_pStudioHdr, i: this->m_nSequence.m_Value);
      }
      else
      {
        v7 = m_pStudioHdr->m_pStudioHdr;
        v8 = this->m_nSequence.m_Value;
        if ( m_Value < 0 || m_Value >= v7->numlocalseq )
          v8 = 0;
        v9 = (mstudioseqdesc_t *)((char *)v7 + 212 * v8 + v7->localseqindex);
      }
      if ( v9->numevents != 0 )
      {
        v10 = CBaseAnimating::GetSequenceCycleRate(this: pOwner, iSequence: this->m_nSequence.m_Value)
            * this->m_flPlaybackRate;
        v11 = !this->m_bLooping;
        flStart = this->m_flLastEventCheck;
        flCycleRate = v10;
        v12 = this->m_flCycle.m_Value;
        flEnd = v12;
        if ( v11 )
        {
          v12 = flEnd;
          if ( flEnd >= (float)(1.0
                              - (float)(CStudioHdr::pSeqdesc(this: m_pStudioHdr, iSequence: this->m_nSequence.m_Value)->fadeouttime
                                      * flCycleRate))
            || flEnd < 0.0 )
          {
            v12 = 1.01;
            this->m_bSequenceFinished = true;
            flEnd = 1.01;
          }
        }
        v13 = this->m_nSequence.m_Value;
        this->m_flLastEventCheck = v12;
        for ( i = GetAnimationEvent(
                    pstudiohdr: m_pStudioHdr,
                    sequence: v13,
                    pNPCEvent: &event,
                    flStart,
                    flEnd: v12,
                    index: 0);
              i != 0;
              i = GetAnimationEvent(
                    pstudiohdr: m_pStudioHdr,
                    sequence: this->m_nSequence.m_Value,
                    pNPCEvent: &event,
                    flStart,
                    flEnd,
                    index: i) )
        {
          event.pSource = pOwner;
          if ( flCycleRate > 0.0 )
          {
            v15 = event.cycle <= this->m_flCycle.m_Value;
            flCycle = event.cycle;
            if ( !v15 )
              flCycle = event.cycle - 1.0;
            AnimTimeInterval = CBaseAnimating::GetAnimTimeInterval(this: pOwner);
            event.eventtime = AnimTimeInterval
                            + (flCycle - this->m_flCycle.m_Value) / flCycleRate
                            + pOwner->m_flAnimTime.m_Value;
          }
          v17 = eventHandler->HandleScriptedAnimEvent(this: eventHandler, a2: &event);
          HandleBehaviorAnimEvent = eventHandler->HandleBehaviorAnimEvent;
          event.m_bHandledByScript = v17;
          if ( HandleBehaviorAnimEvent(this: eventHandler, a2: &event) )
            event.m_bHandledByScript = true;
          eventHandler->HandleAnimEvent(this: eventHandler, a2: &event);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F470
// Name: public: int CBaseAnimatingOverlay::FindGestureLayer(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimatingOverlay::FindGestureLayer(CBaseAnimatingOverlay *this, Activity activity)
{
  int m_Size; // esi
  int result; // eax
  CAnimationLayer *i; // ecx
  Activity m_nActivity; // edx

  m_Size = this->m_AnimOverlay.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_AnimOverlay.m_Memory.m_pMemory; ; ++i )
  {
    if ( (i->m_fFlags & 1) != 0 && (i->m_fFlags & 4) == 0 )
    {
      m_nActivity = i->m_nActivity;
      if ( m_nActivity != ACT_INVALID && m_nActivity == activity )
        break;
    }
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009F4C0
// Name: public: bool CBaseAnimatingOverlay::IsPlayingGesture(enum Activity)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimatingOverlay::IsPlayingGesture(CBaseAnimatingOverlay *this, Activity activity)
{
  return CBaseAnimatingOverlay::FindGestureLayer(this, activity) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1009F4E0
// Name: public: float CBaseAnimatingOverlay::GetLayerCycle(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimatingOverlay::GetLayerCycle(CBaseAnimatingOverlay *this, int iLayer)
{
  CAnimationLayer *m_pMemory; // ecx

  if ( iLayer >= 0
    && iLayer < this->m_AnimOverlay.m_Size
    && (m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory, (m_pMemory[iLayer].m_fFlags & 1) != 0) )
  {
    return m_pMemory[iLayer].m_flCycle.m_Value;
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F510
// Name: public: void CBaseAnimatingOverlay::SetLayerPlaybackRate(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerPlaybackRate(
        CBaseAnimatingOverlay *this,
        int iLayer,
        float flPlaybackRate)
{
  CAnimationLayer *m_pMemory; // ecx

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
    if ( (m_pMemory[iLayer].m_fFlags & 1) != 0 )
      m_pMemory[iLayer].m_flPlaybackRate = flPlaybackRate;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F540
// Name: public: void CBaseAnimatingOverlay::SetLayerLooping(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerLooping(CBaseAnimatingOverlay *this, int iLayer, bool bLooping)
{
  CAnimationLayer *m_pMemory; // ecx

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
    if ( (m_pMemory[iLayer].m_fFlags & 1) != 0 )
      m_pMemory[iLayer].m_bLooping = bLooping;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F570
// Name: public: void CBaseAnimatingOverlay::SetLayerNoRestore(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerNoRestore(CBaseAnimatingOverlay *this, int iLayer, bool bNoRestore)
{
  CAnimationLayer *v3; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    v3 = &this->m_AnimOverlay.m_Memory.m_pMemory[iLayer];
    if ( (v3->m_fFlags & 1) != 0 )
    {
      if ( bNoRestore )
        v3->m_fFlags |= 8u;
      else
        v3->m_fFlags &= ~8u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F5B0
// Name: public: void CBaseAnimatingOverlay::SetLayerNoEvents(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerNoEvents(CBaseAnimatingOverlay *this, int iLayer, bool bNoEvents)
{
  CAnimationLayer *v3; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    v3 = &this->m_AnimOverlay.m_Memory.m_pMemory[iLayer];
    if ( (v3->m_fFlags & 1) != 0 )
    {
      if ( bNoEvents )
        v3->m_fFlags |= 0x40u;
      else
        v3->m_fFlags &= ~0x40u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F5F0
// Name: public: int CBaseAnimatingOverlay::GetLayerSequence(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimatingOverlay::GetLayerSequence(CBaseAnimatingOverlay *this, int iLayer)
{
  CAnimationLayer *m_pMemory; // ecx

  if ( iLayer >= 0
    && iLayer < this->m_AnimOverlay.m_Size
    && (m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory, (m_pMemory[iLayer].m_fFlags & 1) != 0) )
  {
    return m_pMemory[iLayer].m_nSequence.m_Value;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F620
// Name: public: void CBaseAnimatingOverlay::RemoveLayer(int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::RemoveLayer(
        CBaseAnimatingOverlay *this,
        int iLayer,
        float flKillRate,
        float flKillDelay)
{
  CAnimationLayer *m_pMemory; // edx
  unsigned int v5; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
    v5 = iLayer;
    if ( (m_pMemory[iLayer].m_fFlags & 1) != 0 )
    {
      if ( flKillRate <= 0.0 )
        m_pMemory[v5].m_flKillRate = 100.0;
      else
        m_pMemory[v5].m_flKillRate = m_pMemory[v5].m_flWeight.m_Value / flKillRate;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flKillDelay = flKillDelay;
      this->m_AnimOverlay.m_Memory.m_pMemory[iLayer].m_fFlags |= 4u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F690
// Name: public: class CAnimationLayer __near * CBaseAnimatingOverlay::GetAnimOverlay(int)
// Source: json
//------------------------------------------------------------------------------
CAnimationLayer *__thiscall CBaseAnimatingOverlay::GetAnimOverlay(CBaseAnimatingOverlay *this, int iIndex)
{
  int v2; // eax

  v2 = this->m_AnimOverlay.m_Size - 1;
  if ( iIndex < 0 )
    return this->m_AnimOverlay.m_Memory.m_pMemory;
  if ( iIndex <= v2 )
    v2 = iIndex;
  return &this->m_AnimOverlay.m_Memory.m_pMemory[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1009F790
// Name: public: virtual void CBaseAnimatingOverlay::DispatchAnimEvents(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimatingOverlay::DispatchAnimEvents(
        CBaseAnimatingOverlay *this@<ecx>,
        animevent_t *a2@<edi>,
        CBaseAnimating *eventHandler)
{
  int v4; // ebx
  int v5; // edi
  CAnimationLayer *v6; // ecx

  CBaseAnimating::DispatchAnimEvents(this, p_event: a2, eventHandler);
  v4 = 0;
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->m_AnimOverlay.m_Memory.m_pMemory[v5];
      if ( (v6->m_fFlags & 1) != 0 && (v6->m_fFlags & 0x40) == 0 )
        CAnimationLayer::DispatchAnimEvents(this: v6, eventHandler, pOwner: this);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_AnimOverlay.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F7F0
// Name: public: void CBaseAnimatingOverlay::SetLayerDuration(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerDuration(CBaseAnimatingOverlay *this, int iLayer, float flDuration)
{
  CAnimationLayer *m_pMemory; // eax
  int v5; // edi
  int m_Value; // ebx
  CStudioHdr *m_pStudioHdr; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
    v5 = iLayer;
    if ( (m_pMemory[iLayer].m_fFlags & 1) != 0 && flDuration > 0.0 )
    {
      m_Value = m_pMemory[v5].m_nSequence.m_Value;
      if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
        CBaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flPlaybackRate = CBaseAnimating::SequenceDuration(
                                                                      this,
                                                                      pStudioHdr: m_pStudioHdr,
                                                                      iSequence: m_Value)
                                                                  / flDuration;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F870
// Name: public: float CBaseAnimatingOverlay::GetLayerDuration(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimatingOverlay::GetLayerDuration(CBaseAnimatingOverlay *this, int iLayer)
{
  int v3; // edi
  CAnimationLayer *v4; // ecx
  CAnimationLayer *v5; // ebx
  CStudioHdr *v6; // eax
  int m_Value; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int iLayera; // [esp+10h] [ebp+8h]

  if ( iLayer < 0 )
    return 0.0;
  if ( iLayer >= this->m_AnimOverlay.m_Size )
    return 0.0;
  v3 = iLayer;
  v4 = &this->m_AnimOverlay.m_Memory.m_pMemory[iLayer];
  if ( (v4->m_fFlags & 1) == 0 )
    return 0.0;
  if ( v4->m_flPlaybackRate == 0.0 )
  {
    m_Value = v4->m_nSequence.m_Value;
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    return CBaseAnimating::SequenceDuration(this, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
  }
  else
  {
    v5 = &this->m_AnimOverlay.m_Memory.m_pMemory[v3];
    iLayera = v5->m_nSequence.m_Value;
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    v6 = this->m_pStudioHdr;
    if ( v6 == nullptr || v6->m_pStudioHdr == nullptr )
      v6 = nullptr;
    return CBaseAnimating::SequenceDuration(this, pStudioHdr: v6, iSequence: iLayera)
         * (1.0 - v5->m_flCycle.m_Value)
         / this->m_AnimOverlay.m_Memory.m_pMemory[v3].m_flPlaybackRate;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FA80
// Name: public: void CAnimationLayer::Init(class CBaseAnimatingOverlay __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimationLayer::Init(CAnimationLayer *this, CBaseAnimatingOverlay *pOverlay)
{
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v4; // eax
  CBaseAnimatingOverlay *v5; // eax
  CBaseEdict *v6; // eax
  CBaseAnimatingOverlay *v7; // eax
  CBaseEdict *v8; // eax
  CBaseAnimatingOverlay *v9; // eax
  CBaseEdict *v10; // eax
  CBaseAnimatingOverlay *v11; // eax
  CBaseEdict *v12; // eax
  double curtime; // st7

  this->m_pOwnerEntity = pOverlay;
  this->m_fFlags = 0;
  if ( this->m_flWeight.m_Value != 0.0 )
  {
    m_pOwnerEntity = this->m_pOwnerEntity;
    if ( m_pOwnerEntity != nullptr )
    {
      if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
      }
      else
      {
        v4 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
        if ( v4 != nullptr )
        {
          v4->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v4)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    this->m_flWeight.m_Value = 0.0;
  }
  if ( this->m_flCycle.m_Value != 0.0 )
  {
    v5 = this->m_pOwnerEntity;
    if ( v5 != nullptr )
    {
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = &v5->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
        {
          v6->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v6)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    this->m_flCycle.m_Value = 0.0;
  }
  if ( this->m_flPrevCycle.m_Value != 0.0 )
  {
    v7 = this->m_pOwnerEntity;
    if ( v7 != nullptr )
    {
      if ( v7->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v7->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = &v7->m_Network.m_pPev->CBaseEdict;
        if ( v8 != nullptr )
        {
          v8->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v8)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    this->m_flPrevCycle.m_Value = 0.0;
  }
  this->m_bSequenceFinished = false;
  this->m_nActivity = ACT_INVALID;
  if ( this->m_nSequence.m_Value != 0 )
  {
    v9 = this->m_pOwnerEntity;
    if ( v9 != nullptr )
    {
      if ( v9->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v9->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = &v9->m_Network.m_pPev->CBaseEdict;
        if ( v10 != nullptr )
        {
          v10->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v10)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    this->m_nSequence.m_Value = 0;
  }
  this->m_nPriority = 0;
  if ( this->m_nOrder.m_Value != 15 )
  {
    v11 = this->m_pOwnerEntity;
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
    this->m_nOrder.m_Value = 15;
  }
  this->m_flKillRate = 100.0;
  this->m_flKillDelay = 0.0;
  this->m_flPlaybackRate = 1.0;
  curtime = gpGlobals->curtime;
  this->m_flLayerAnimtime = 0.0;
  this->m_flLastAccess = curtime;
  this->m_flLayerFadeOuttime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1009FC30
// Name: public: void CAnimationLayer::StudioFrameAdvance(float,class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimationLayer::StudioFrameAdvance(CAnimationLayer *this, float flInterval, CBaseAnimating *pOwner)
{
  int m_Value; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  CBaseAnimatingOverlay *v10; // eax
  CBaseEdict *v11; // eax
  float v12; // xmm0_4
  CBaseAnimatingOverlay *v13; // eax
  CBaseEdict *v14; // eax
  bool v15; // zf
  float v16; // xmm0_4
  CBaseAnimatingOverlay *v17; // eax
  CBaseEdict *v18; // eax
  CBaseAnimatingOverlay *v19; // eax
  CBaseEdict *v20; // eax
  CBaseAnimatingOverlay *v21; // eax
  CBaseEdict *v22; // eax
  float m_flBlendIn; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  CBaseAnimatingOverlay *v26; // eax
  CBaseEdict *v27; // eax
  float m_flBlendOut; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  CBaseAnimatingOverlay *v31; // eax
  CBaseEdict *v32; // eax
  float v33; // xmm1_4
  float v34; // xmm0_4
  CBaseAnimatingOverlay *v35; // eax
  CBaseEdict *v36; // eax
  CBaseAnimatingOverlay *v37; // eax
  CBaseEdict *v38; // eax
  float flCycleRate; // [esp+18h] [ebp+Ch]
  float flCycleRatea; // [esp+18h] [ebp+Ch]

  m_Value = this->m_nSequence.m_Value;
  if ( pOwner->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: pOwner) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pOwner);
  m_pStudioHdr = pOwner->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  flCycleRate = CBaseAnimating::GetSequenceCycleRate(this: pOwner, pStudioHdr: m_pStudioHdr, iSequence: m_Value);
  if ( this->m_flPrevCycle.m_Value != this->m_flCycle.m_Value )
  {
    m_pOwnerEntity = this->m_pOwnerEntity;
    if ( m_pOwnerEntity != nullptr )
    {
      if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
        {
          v7->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    this->m_flPrevCycle.m_Value = this->m_flCycle.m_Value;
  }
  v8 = this->m_flCycle.m_Value;
  flCycleRatea = (float)((float)(flCycleRate * flInterval) * this->m_flPlaybackRate) + v8;
  v9 = flCycleRatea;
  if ( v8 != flCycleRatea )
  {
    v10 = this->m_pOwnerEntity;
    if ( v10 != nullptr )
    {
      if ( v10->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v10->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = &v10->m_Network.m_pPev->CBaseEdict;
        if ( v11 != nullptr )
        {
          v11->m_fStateFlags |= 0x101u;
          v9 = flCycleRatea;
          CBaseEdict::GetChangeAccessor(this: v11)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    this->m_flCycle.m_Value = v9;
  }
  v12 = this->m_flCycle.m_Value;
  if ( v12 >= 0.0 )
  {
    if ( v12 < 1.0 )
      goto LABEL_46;
    v15 = !this->m_bLooping;
    this->m_bSequenceFinished = true;
    if ( v15 )
    {
      if ( this->m_flCycle.m_Value != 1.0 )
      {
        v19 = this->m_pOwnerEntity;
        if ( v19 != nullptr )
        {
          if ( v19->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v19->m_Network + 76) |= 1u;
          }
          else
          {
            v20 = &v19->m_Network.m_pPev->CBaseEdict;
            if ( v20 != nullptr )
            {
              v20->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v20)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        this->m_flCycle.m_Value = 1.0;
      }
      goto LABEL_46;
    }
  }
  else if ( !this->m_bLooping )
  {
    if ( v12 == 0.0 )
      goto LABEL_46;
    v13 = this->m_pOwnerEntity;
    if ( v13 != nullptr )
    {
      if ( v13->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v13->m_Network + 76) |= 1u;
        this->m_flCycle.m_Value = 0.0;
        goto LABEL_46;
      }
      v14 = &v13->m_Network.m_pPev->CBaseEdict;
      if ( v14 != nullptr )
      {
        v14->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: v14)->m_iChangeInfoSerialNumber = 0;
      }
    }
    this->m_flCycle.m_Value = 0.0;
    goto LABEL_46;
  }
  v16 = v12 - (double)(int)v12;
  if ( this->m_flCycle.m_Value != v16 )
  {
    v17 = this->m_pOwnerEntity;
    if ( v17 != nullptr )
    {
      if ( v17->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v17->m_Network + 76) |= 1u;
        this->m_flCycle.m_Value = v16;
        goto LABEL_46;
      }
      v18 = &v17->m_Network.m_pPev->CBaseEdict;
      if ( v18 != nullptr )
      {
        v18->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: v18)->m_iChangeInfoSerialNumber = 0;
      }
    }
    this->m_flCycle.m_Value = v16;
  }
LABEL_46:
  if ( this->m_flBlendIn != 0.0 || this->m_flBlendOut != 0.0 )
  {
    if ( this->m_flWeight.m_Value != 1.0 )
    {
      v21 = this->m_pOwnerEntity;
      if ( v21 != nullptr )
      {
        if ( v21->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v21->m_Network + 76) |= 1u;
        }
        else
        {
          v22 = &v21->m_Network.m_pPev->CBaseEdict;
          if ( v22 != nullptr )
          {
            v22->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v22)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      this->m_flWeight.m_Value = 1.0;
    }
    m_flBlendIn = this->m_flBlendIn;
    if ( m_flBlendIn != 0.0 )
    {
      v24 = this->m_flCycle.m_Value;
      if ( m_flBlendIn > v24 )
      {
        v25 = v24 / m_flBlendIn;
        if ( this->m_flWeight.m_Value != v25 )
        {
          v26 = this->m_pOwnerEntity;
          if ( v26 != nullptr )
          {
            if ( v26->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v26->m_Network + 76) |= 1u;
            }
            else
            {
              v27 = &v26->m_Network.m_pPev->CBaseEdict;
              if ( v27 != nullptr )
              {
                v27->m_fStateFlags |= 0x101u;
                CBaseEdict::GetChangeAccessor(this: v27)->m_iChangeInfoSerialNumber = 0;
              }
            }
          }
          this->m_flWeight.m_Value = v25;
        }
      }
    }
    m_flBlendOut = this->m_flBlendOut;
    if ( m_flBlendOut != 0.0 )
    {
      v29 = this->m_flCycle.m_Value;
      if ( v29 > (float)(1.0 - m_flBlendOut) )
      {
        v30 = (float)(1.0 - v29) / m_flBlendOut;
        if ( this->m_flWeight.m_Value != v30 )
        {
          v31 = this->m_pOwnerEntity;
          if ( v31 != nullptr )
          {
            if ( v31->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v31->m_Network + 76) |= 1u;
            }
            else
            {
              v32 = &v31->m_Network.m_pPev->CBaseEdict;
              if ( v32 != nullptr )
              {
                v32->m_fStateFlags |= 0x101u;
                CBaseEdict::GetChangeAccessor(this: v32)->m_iChangeInfoSerialNumber = 0;
              }
            }
          }
          this->m_flWeight.m_Value = v30;
        }
      }
    }
    v33 = this->m_flWeight.m_Value;
    v34 = (float)((float)(v33 * 3.0) * v33) - (float)((float)((float)(v33 * 2.0) * v33) * v33);
    if ( v33 != v34 )
    {
      v35 = this->m_pOwnerEntity;
      if ( v35 != nullptr )
      {
        if ( v35->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v35->m_Network + 76) |= 1u;
        }
        else
        {
          v36 = &v35->m_Network.m_pPev->CBaseEdict;
          if ( v36 != nullptr )
          {
            v36->m_fStateFlags |= 0x101u;
            v34 = (float)((float)(v33 * 3.0) * v33) - (float)((float)((float)(v33 * 2.0) * v33) * v33);
            CBaseEdict::GetChangeAccessor(this: v36)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      this->m_flWeight.m_Value = v34;
    }
    if ( this->m_nSequence.m_Value == 0 && this->m_flWeight.m_Value != 0.0 )
    {
      v37 = this->m_pOwnerEntity;
      if ( v37 != nullptr )
      {
        if ( v37->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v37->m_Network + 76) |= 1u;
          this->m_flWeight.m_Value = 0.0;
          return;
        }
        v38 = &v37->m_Network.m_pPev->CBaseEdict;
        if ( v38 != nullptr )
        {
          v38->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v38)->m_iChangeInfoSerialNumber = 0;
        }
      }
      this->m_flWeight.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0080
// Name: public: virtual void CBaseAnimatingOverlay::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetModel(CBaseAnimatingOverlay *this, const char *szModelName)
{
  CAnimationLayer *v3; // esi
  edict_t *m_pPev; // eax
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v6; // eax
  CBaseAnimatingOverlay *v7; // eax
  CBaseEdict *v8; // eax
  CBaseAnimatingOverlay *v9; // eax
  CBaseEdict *v10; // eax
  CBaseAnimatingOverlay *v11; // eax
  CBaseEdict *v12; // eax
  int j; // [esp+8h] [ebp-8h]
  int v14; // [esp+Ch] [ebp-4h]

  j = 0;
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    v14 = 0;
    do
    {
      v3 = &this->m_AnimOverlay.m_Memory.m_pMemory[v14];
      v3->m_pOwnerEntity = this;
      v3->m_fFlags = 0;
      if ( v3->m_flWeight.m_Value != 0.0 )
      {
        if ( this != nullptr )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
            {
              m_pPev->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v3->m_flWeight.m_Value = 0.0;
      }
      if ( v3->m_flCycle.m_Value != 0.0 )
      {
        m_pOwnerEntity = v3->m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v6 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v6 != nullptr )
            {
              v6->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v6)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v3->m_flCycle.m_Value = 0.0;
      }
      if ( v3->m_flPrevCycle.m_Value != 0.0 )
      {
        v7 = v3->m_pOwnerEntity;
        if ( v7 != nullptr )
        {
          if ( v7->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v7->m_Network + 76) |= 1u;
          }
          else
          {
            v8 = &v7->m_Network.m_pPev->CBaseEdict;
            if ( v8 != nullptr )
            {
              v8->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v8)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v3->m_flPrevCycle.m_Value = 0.0;
      }
      v3->m_bSequenceFinished = false;
      v3->m_nActivity = ACT_INVALID;
      if ( v3->m_nSequence.m_Value != 0 )
      {
        v9 = v3->m_pOwnerEntity;
        if ( v9 != nullptr )
        {
          if ( v9->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v9->m_Network + 76) |= 1u;
          }
          else
          {
            v10 = &v9->m_Network.m_pPev->CBaseEdict;
            if ( v10 != nullptr )
            {
              v10->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v10)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v3->m_nSequence.m_Value = 0;
      }
      v3->m_nPriority = 0;
      if ( v3->m_nOrder.m_Value != 15 )
      {
        v11 = v3->m_pOwnerEntity;
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
        v3->m_nOrder.m_Value = 15;
      }
      ++v14;
      v3->m_flKillRate = 100.0;
      v3->m_flKillDelay = 0.0;
      v3->m_flPlaybackRate = 1.0;
      v3->m_flLastAccess = gpGlobals->curtime;
      v3->m_flLayerAnimtime = 0.0;
      v3->m_flLayerFadeOuttime = 0.0;
      ++j;
    }
    while ( j < this->m_AnimOverlay.m_Size );
  }
  CBaseAnimating::SetModel(this, szModelName);
}

//------------------------------------------------------------------------------
// Address: 0x100A0260
// Name: public: void CBaseAnimatingOverlay::SetLayerCycle(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerCycle(CBaseAnimatingOverlay *this, int iLayer, float flCycle)
{
  CAnimationLayer *v4; // edi
  float v5; // xmm0_4
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v7; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    v4 = &this->m_AnimOverlay.m_Memory.m_pMemory[iLayer];
    if ( (v4->m_fFlags & 1) != 0 )
    {
      if ( !v4->m_bLooping )
      {
        v5 = 0.0;
        if ( flCycle >= 0.0 )
        {
          v5 = 1.0;
          if ( flCycle <= 1.0 )
            v5 = flCycle;
        }
        flCycle = v5;
      }
      if ( v4->m_flCycle.m_Value != flCycle )
      {
        m_pOwnerEntity = v4->m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v7 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v7 != nullptr )
            {
              v7->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v4->m_flCycle.m_Value = flCycle;
      }
      this->m_AnimOverlay.m_Memory.m_pMemory[iLayer].m_flLastAccess = gpGlobals->curtime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0320
// Name: public: void CBaseAnimatingOverlay::SetLayerCycle(int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerCycle(
        CBaseAnimatingOverlay *this,
        int iLayer,
        float flCycle,
        float flPrevCycle)
{
  int v5; // edi
  CAnimationLayer *v6; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v10; // eax
  CAnimationLayer *m_pMemory; // edx
  float v12; // xmm0_4
  float *p_m_Value; // esi
  CBaseAnimatingOverlay *v14; // eax
  CBaseEdict *v15; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    v5 = iLayer;
    v6 = &this->m_AnimOverlay.m_Memory.m_pMemory[iLayer];
    if ( (v6->m_fFlags & 1) != 0 )
    {
      if ( !v6->m_bLooping )
      {
        v7 = flCycle;
        if ( flCycle >= 0.0 )
        {
          if ( flCycle > 1.0 )
            v7 = 1.0;
        }
        else
        {
          v7 = 0.0;
        }
        flCycle = v7;
        v8 = flPrevCycle;
        if ( flPrevCycle >= 0.0 )
        {
          if ( flPrevCycle > 1.0 )
            v8 = 1.0;
        }
        else
        {
          v8 = 0.0;
        }
        flPrevCycle = v8;
      }
      if ( v6->m_flCycle.m_Value != flCycle )
      {
        m_pOwnerEntity = v6->m_pOwnerEntity;
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
        v6->m_flCycle.m_Value = flCycle;
      }
      m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
      v12 = flPrevCycle;
      p_m_Value = &m_pMemory[v5].m_flPrevCycle.m_Value;
      if ( *p_m_Value != flPrevCycle )
      {
        v14 = m_pMemory[v5].m_pOwnerEntity;
        if ( v14 != nullptr )
        {
          if ( v14->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v14->m_Network + 76) |= 1u;
          }
          else
          {
            v15 = &v14->m_Network.m_pPev->CBaseEdict;
            if ( v15 != nullptr )
            {
              v15->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v15)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v12 = flPrevCycle;
        *p_m_Value = flPrevCycle;
      }
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flLastEventCheck = v12;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flLastAccess = gpGlobals->curtime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0460
// Name: public: void CBaseAnimatingOverlay::SetLayerWeight(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerWeight(CBaseAnimatingOverlay *this, int iLayer, float flWeight)
{
  CAnimationLayer *v4; // edi
  float v5; // xmm0_4
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v7; // eax

  if ( iLayer >= 0 && iLayer < this->m_AnimOverlay.m_Size )
  {
    v4 = &this->m_AnimOverlay.m_Memory.m_pMemory[iLayer];
    if ( (v4->m_fFlags & 1) != 0 )
    {
      v5 = 0.0;
      if ( flWeight >= 0.0 )
      {
        v5 = 1.0;
        if ( flWeight <= 1.0 )
          v5 = flWeight;
      }
      if ( v4->m_flWeight.m_Value != v5 )
      {
        m_pOwnerEntity = v4->m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v7 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v7 != nullptr )
            {
              v7->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v7)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v4->m_flWeight.m_Value = v5;
      }
      this->m_AnimOverlay.m_Memory.m_pMemory[iLayer].m_flLastAccess = gpGlobals->curtime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0950
// Name: public: void CBaseAnimatingOverlay::SetLayerPriority(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetLayerPriority(CBaseAnimatingOverlay *this, int iLayer, int iPriority)
{
  int v3; // edi
  int m_Size; // ecx
  CAnimationLayer *m_pMemory; // edx
  CAnimationLayer *v7; // ecx
  CAnimationLayer *v8; // esi
  int v9; // ecx
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v11; // eax
  IChangeInfoAccessor *v12; // eax
  int v13; // esi
  int v14; // edx
  int v15; // ecx
  CAnimationLayer *v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // esi
  char *v20; // esi
  int v21; // edi
  int v22; // eax
  CBaseEdict *v23; // eax
  CAnimationLayer *v24; // edx
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nOrder> *p_m_nOrder; // esi
  CBaseAnimatingOverlay *v26; // eax
  CBaseEdict *v27; // eax
  int v28; // [esp+8h] [ebp-10h]
  int v29; // [esp+Ch] [ebp-Ch]
  int v30; // [esp+Ch] [ebp-Ch]
  int iNewOrder; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  v3 = 0;
  if ( iLayer >= 0 )
  {
    m_Size = this->m_AnimOverlay.m_Size;
    if ( iLayer < m_Size )
    {
      m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
      v28 = iLayer;
      if ( (m_pMemory[iLayer].m_fFlags & 1) != 0 && m_pMemory[iLayer].m_nPriority != iPriority )
      {
        i = 0;
        if ( m_Size > 0 )
        {
          do
          {
            v7 = this->m_AnimOverlay.m_Memory.m_pMemory;
            v8 = &v7[v3];
            if ( (v7[v3].m_fFlags & 1) != 0
              && v7[v3].m_nOrder.m_Value > this->m_AnimOverlay.m_Memory.m_pMemory[v28].m_nOrder.m_Value )
            {
              v9 = v8->m_nOrder.m_Value - 1;
              v29 = v9;
              m_pOwnerEntity = v8->m_pOwnerEntity;
              if ( m_pOwnerEntity != nullptr )
              {
                if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
                {
                  *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
                }
                else
                {
                  v11 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
                  if ( v11 != nullptr )
                  {
                    v11->m_fStateFlags |= 0x101u;
                    v12 = CBaseEdict::GetChangeAccessor(this: v11);
                    v9 = v29;
                    v12->m_iChangeInfoSerialNumber = 0;
                  }
                }
              }
              v8->m_nOrder.m_Value = v9;
            }
            ++v3;
            ++i;
          }
          while ( i < this->m_AnimOverlay.m_Size );
        }
        v13 = this->m_AnimOverlay.m_Size;
        v14 = 0;
        v15 = 0;
        for ( iNewOrder = 0; v15 < v13; ++v14 )
        {
          if ( v15 != iLayer )
          {
            v16 = this->m_AnimOverlay.m_Memory.m_pMemory;
            if ( (v16[v14].m_fFlags & 1) != 0 && v16[v14].m_nPriority <= iPriority )
            {
              v17 = v16[v14].m_nOrder.m_Value + 1;
              if ( iNewOrder <= v17 )
                iNewOrder = v17;
            }
          }
          ++v15;
        }
        v18 = 0;
        ia = 0;
        if ( v13 > 0 )
        {
          v19 = 0;
          v30 = 0;
          do
          {
            if ( v18 != iLayer )
            {
              v20 = (char *)this->m_AnimOverlay.m_Memory.m_pMemory + v19;
              if ( (*v20 & 1) != 0 && *((_DWORD *)v20 + 15) >= iNewOrder )
              {
                v21 = *((_DWORD *)v20 + 15) + 1;
                v22 = *((_DWORD *)v20 + 18);
                if ( v22 != 0 )
                {
                  if ( *(_BYTE *)(v22 + 84) != 0 )
                  {
                    *(_BYTE *)(v22 + 88) |= 1u;
                  }
                  else
                  {
                    v23 = *(CBaseEdict **)(v22 + 24);
                    if ( v23 != nullptr )
                    {
                      v23->m_fStateFlags |= 0x101u;
                      CBaseEdict::GetChangeAccessor(this: v23)->m_iChangeInfoSerialNumber = 0;
                      v18 = ia;
                    }
                  }
                }
                *((_DWORD *)v20 + 15) = v21;
              }
            }
            ++v18;
            v19 = v30 + 76;
            ia = v18;
            v30 += 76;
          }
          while ( v18 < this->m_AnimOverlay.m_Size );
        }
        v24 = this->m_AnimOverlay.m_Memory.m_pMemory;
        p_m_nOrder = &v24[v28].m_nOrder;
        if ( p_m_nOrder->m_Value != iNewOrder )
        {
          v26 = v24[v28].m_pOwnerEntity;
          if ( v26 != nullptr )
          {
            if ( v26->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v26->m_Network + 76) |= 1u;
            }
            else
            {
              v27 = &v26->m_Network.m_pPev->CBaseEdict;
              if ( v27 != nullptr )
              {
                v27->m_fStateFlags |= 0x101u;
                CBaseEdict::GetChangeAccessor(this: v27)->m_iChangeInfoSerialNumber = 0;
              }
            }
          }
          p_m_nOrder->m_Value = iNewOrder;
        }
        this->m_AnimOverlay.m_Memory.m_pMemory[v28].m_nPriority = iPriority;
        this->m_AnimOverlay.m_Memory.m_pMemory[v28].m_flLastAccess = gpGlobals->curtime;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0B40
// Name: public: void CBaseAnimatingOverlay::FastRemoveLayer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::FastRemoveLayer(CBaseAnimatingOverlay *this, int iLayer)
{
  int v2; // ebx
  int m_Size; // ecx
  int v5; // eax
  CAnimationLayer *m_pMemory; // eax
  CAnimationLayer *v7; // edi
  int v8; // ecx
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v10; // eax
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]
  int j; // [esp+18h] [ebp+8h]

  v2 = 0;
  if ( iLayer >= 0 )
  {
    m_Size = this->m_AnimOverlay.m_Size;
    if ( iLayer < m_Size )
    {
      v5 = 76 * iLayer;
      v12 = iLayer;
      if ( (this->m_AnimOverlay.m_Memory.m_pMemory[iLayer].m_fFlags & 1) != 0 )
      {
        j = 0;
        if ( m_Size > 0 )
        {
          do
          {
            m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
            v7 = &m_pMemory[v2];
            if ( (m_pMemory[v2].m_fFlags & 1) != 0 && m_pMemory[v2].m_nOrder.m_Value > m_pMemory[v12].m_nOrder.m_Value )
            {
              v8 = v7->m_nOrder.m_Value - 1;
              v11 = v8;
              m_pOwnerEntity = v7->m_pOwnerEntity;
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
                    v8 = v11;
                  }
                }
              }
              v7->m_nOrder.m_Value = v8;
            }
            ++v2;
            ++j;
          }
          while ( j < this->m_AnimOverlay.m_Size );
          v5 = v12 * 76;
        }
        CAnimationLayer::Init(
          this: (CAnimationLayer *)((char *)this->m_AnimOverlay.m_Memory.m_pMemory + v5),
          pOverlay: this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0C10
// Name: public: virtual void CBaseAnimatingOverlay::StudioFrameAdvance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::StudioFrameAdvance(CBaseAnimatingOverlay *this)
{
  int v2; // ebx
  float v3; // xmm1_4
  CAnimationLayer *v4; // esi
  int m_fFlags; // eax
  float m_flKillDelay; // xmm0_4
  float v7; // xmm0_4
  CBaseAnimatingOverlay *v8; // eax
  float m_Value; // xmm0_4
  float v10; // xmm0_4
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v12; // eax
  float v13; // xmm0_4
  CBaseAnimatingOverlay *v14; // eax
  CBaseEdict *v15; // eax
  const char *SequenceName; // eax
  CBaseEdict *v17; // eax
  int v18; // ebx
  int v19; // esi
  CAnimationLayer *m_pMemory; // eax
  float v21; // xmm0_4
  int v22; // edx
  float *v23; // esi
  const char *v24; // eax
  double v25; // [esp+0h] [ebp-2Ch]
  double v26; // [esp+0h] [ebp-2Ch]
  int v27; // [esp+20h] [ebp-Ch]
  int v28; // [esp+20h] [ebp-Ch]
  float flAdvance; // [esp+24h] [ebp-8h]

  flAdvance = CBaseAnimating::GetAnimTimeInterval(this);
  CBaseAnimating::StudioFrameAdvance(this);
  v2 = 0;
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    v3 = 0.0;
    v27 = 0;
    do
    {
      v4 = &this->m_AnimOverlay.m_Memory.m_pMemory[v27];
      m_fFlags = v4->m_fFlags;
      if ( (v4->m_fFlags & 1) == 0 )
      {
        if ( (m_fFlags & 0x20) != 0 )
        {
          v4->m_fFlags = m_fFlags & 0xFFFFFFDF;
        }
        else if ( v4->m_flWeight.m_Value > 0.0 )
        {
          CAnimationLayer::Init(this: v4, pOverlay: this);
LABEL_49:
          v4->m_fFlags |= 0x20u;
LABEL_50:
          v3 = 0.0;
          goto LABEL_51;
        }
        goto LABEL_51;
      }
      if ( (m_fFlags & 4) != 0 )
      {
        m_flKillDelay = v4->m_flKillDelay;
        if ( m_flKillDelay > 0.0 )
        {
          v7 = m_flKillDelay - flAdvance;
          v4->m_flKillDelay = v7;
          if ( v7 >= 0.0 )
          {
            if ( v7 > 1.0 )
              v7 = 1.0;
          }
          else
          {
            v7 = 0.0;
          }
          v4->m_flKillDelay = v7;
          goto LABEL_11;
        }
        m_Value = v4->m_flWeight.m_Value;
        if ( m_Value == 0.0 )
        {
          if ( ai_sequence_debug.m_pParent != nullptr
            && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
            && (this->m_debugOverlays & 0x1000) != 0 )
          {
            v25 = v4->m_flCycle.m_Value;
            SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: v4->m_nSequence.m_Value);
            _Msg(a1: "removing %d (%d): %s : %5.3f (%.3f)\n", v2, v4->m_nOrder.m_Value, SequenceName, v25, m_Value);
          }
          CBaseAnimatingOverlay::FastRemoveLayer(this, iLayer: v2);
          goto LABEL_49;
        }
        v10 = m_Value - (float)(v4->m_flKillRate * flAdvance);
        if ( v4->m_flWeight.m_Value != v10 )
        {
          m_pOwnerEntity = v4->m_pOwnerEntity;
          if ( m_pOwnerEntity != nullptr )
          {
            if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
            }
            else
            {
              v12 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
              if ( v12 != nullptr )
              {
                v12->m_fStateFlags |= 0x101u;
                v3 = 0.0;
                CBaseEdict::GetChangeAccessor(this: v12)->m_iChangeInfoSerialNumber = 0;
              }
            }
          }
          v4->m_flWeight.m_Value = v10;
        }
        v13 = v4->m_flWeight.m_Value;
        if ( v13 >= 0.0 )
        {
          if ( v13 <= 1.0 )
            v3 = v4->m_flWeight.m_Value;
          else
            v3 = 1.0;
        }
        if ( v4->m_flWeight.m_Value == v3 )
          goto LABEL_11;
        v14 = v4->m_pOwnerEntity;
        if ( v14 != nullptr )
        {
          if ( v14->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v14->m_Network + 76) |= 1u;
            v4->m_flWeight.m_Value = v3;
            goto LABEL_11;
          }
          v15 = &v14->m_Network.m_pPev->CBaseEdict;
          if ( v15 != nullptr )
          {
            v15->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v15)->m_iChangeInfoSerialNumber = 0;
          }
        }
        v4->m_flWeight.m_Value = v3;
      }
LABEL_11:
      CAnimationLayer::StudioFrameAdvance(this: v4, flInterval: flAdvance, pOwner: this);
      if ( !v4->m_bSequenceFinished || (v4->m_fFlags & 2) == 0 )
        goto LABEL_50;
      v3 = 0.0;
      if ( v4->m_flWeight.m_Value == 0.0 )
        goto LABEL_44;
      v8 = v4->m_pOwnerEntity;
      if ( v8 == nullptr )
        goto LABEL_43;
      if ( !v8->m_Network.m_TimerEvent.m_bRegistered )
      {
        v17 = &v8->m_Network.m_pPev->CBaseEdict;
        if ( v17 != nullptr )
        {
          v17->m_fStateFlags |= 0x101u;
          v3 = 0.0;
          CBaseEdict::GetChangeAccessor(this: v17)->m_iChangeInfoSerialNumber = 0;
        }
LABEL_43:
        v4->m_flWeight.m_Value = 0.0;
LABEL_44:
        v4->m_fFlags |= 4u;
        goto LABEL_51;
      }
      *((_BYTE *)&v8->m_Network + 76) |= 1u;
      v4->m_flWeight.m_Value = 0.0;
      v4->m_fFlags |= 4u;
LABEL_51:
      ++v27;
      ++v2;
    }
    while ( v2 < this->m_AnimOverlay.m_Size );
  }
  if ( ai_sequence_debug.m_pParent != nullptr
    && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
    && (this->m_debugOverlays & 0x1000) != 0 )
  {
    v18 = 0;
    if ( this->m_AnimOverlay.m_Size > 0 )
    {
      v19 = 0;
      v28 = 0;
      do
      {
        m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
        if ( (*((_BYTE *)&m_pMemory->m_fFlags + v19) & 1) != 0 )
        {
          v21 = *(float *)((char *)&m_pMemory->m_flWeight.m_Value + v19);
          v22 = *(int *)((char *)&m_pMemory->m_nSequence.m_Value + v19);
          v23 = (float *)((char *)&m_pMemory->m_fFlags + v19);
          v26 = v23[3];
          v24 = CBaseAnimating::GetSequenceName(this, iSequence: v22);
          _Msg(a1: " %d (%d): %s : %5.3f (%.3f)\n", v18, *((_DWORD *)v23 + 15), v24, v26, v21);
          v19 = v28;
        }
        ++v18;
        v19 += 76;
        v28 = v19;
      }
      while ( v18 < this->m_AnimOverlay.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0F40
// Name: public: virtual void CBaseAnimatingOverlay::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::OnRestore(CBaseAnimatingOverlay *this)
{
  int v1; // edi
  CAnimationLayer *m_pMemory; // ecx
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nOrder> *p_m_nOrder; // ebx
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v6; // eax
  int v7; // ebx
  int v8; // edi
  CAnimationLayer *v9; // eax
  CStudioHdr *m_pStudioHdr; // eax
  int i; // [esp+Ch] [ebp-4h]

  v1 = 0;
  for ( i = 0; i < this->m_AnimOverlay.m_Size; ++i )
  {
    this->m_AnimOverlay.m_Memory.m_pMemory[v1].m_pOwnerEntity = this;
    m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
    if ( (m_pMemory[v1].m_fFlags & 1) == 0 )
    {
      p_m_nOrder = &m_pMemory[v1].m_nOrder;
      if ( p_m_nOrder->m_Value != 15 )
      {
        m_pOwnerEntity = m_pMemory[v1].m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v6 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v6 != nullptr )
            {
              v6->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v6)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        p_m_nOrder->m_Value = 15;
      }
    }
    ++v1;
  }
  v7 = 0;
  if ( this->m_AnimOverlay.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->m_AnimOverlay.m_Memory.m_pMemory[v8];
      if ( (v9->m_fFlags & 1) != 0 && (v9->m_fFlags & 8) != 0 )
        goto LABEL_21;
      if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
        CBaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr
        && m_pStudioHdr->m_pStudioHdr != nullptr
        && !CBaseAnimating::IsValidSequence(
              this,
              iSequence: this->m_AnimOverlay.m_Memory.m_pMemory[v8].m_nSequence.m_Value) )
      {
LABEL_21:
        CBaseAnimatingOverlay::FastRemoveLayer(this, iLayer: v7);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_AnimOverlay.m_Size );
  }
  CBaseAnimating::OnRestore(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A1160
// Name: private: int CBaseAnimatingOverlay::AllocateLayer(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimatingOverlay::AllocateLayer(CBaseAnimatingOverlay *this, int iPriority)
{
  CBaseAnimatingOverlay *v2; // ebx
  int v3; // edx
  int m_Size; // edi
  int result; // eax
  CAnimationLayer *m_pMemory; // eax
  CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int> > *p_m_AnimOverlay; // esi
  int v8; // edi
  int m_nAllocationCount; // eax
  CAnimationLayer *v10; // ecx
  int v11; // eax
  int v12; // ebx
  CAnimationLayer *v13; // ecx
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v15; // eax
  int v16; // edi
  CBaseAnimatingOverlay *v17; // eax
  CBaseEdict *v18; // eax
  int v19; // edi
  int v20; // eax
  int *v21; // edi
  int v22; // ebx
  int v23; // eax
  CBaseEdict *v24; // eax
  int v25; // edi
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nOrder> *p_m_nOrder; // ebx
  CBaseAnimatingOverlay *v27; // eax
  CBaseEdict *v28; // eax
  int v29; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int ia; // [esp+10h] [ebp-10h]
  int iNewOrder; // [esp+14h] [ebp-Ch]
  int iOpenLayer; // [esp+18h] [ebp-8h]

  v2 = this;
  v3 = 0;
  m_Size = this->m_AnimOverlay.m_Size;
  result = -1;
  iNewOrder = 0;
  iOpenLayer = -1;
  i = 0;
  if ( m_Size <= 0 )
    goto LABEL_13;
  m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
  p_m_AnimOverlay = &this->m_AnimOverlay;
  do
  {
    if ( (m_pMemory->m_fFlags & 1) != 0 )
    {
      if ( m_pMemory->m_nPriority <= iPriority && iNewOrder <= m_pMemory->m_nOrder.m_Value + 1 )
        iNewOrder = m_pMemory->m_nOrder.m_Value + 1;
    }
    else if ( (m_pMemory->m_fFlags & 0x20) == 0 )
    {
      if ( iOpenLayer == -1 )
        iOpenLayer = v3;
      else
        ++i;
    }
    ++v3;
    ++m_pMemory;
  }
  while ( v3 < m_Size );
  result = -1;
  if ( iOpenLayer == -1 )
  {
LABEL_13:
    if ( m_Size >= 15 )
      return result;
    v8 = this->m_AnimOverlay.m_Size;
    m_nAllocationCount = this->m_AnimOverlay.m_Memory.m_nAllocationCount;
    p_m_AnimOverlay = &this->m_AnimOverlay;
    if ( v8 + 1 > m_nAllocationCount )
      CUtlMemory<CAnimationLayer,int>::Grow(this: &this->m_AnimOverlay.m_Memory, num: v8 - m_nAllocationCount + 1);
    ++v2->m_AnimOverlay.m_Size;
    v10 = p_m_AnimOverlay->m_Memory.m_pMemory;
    v11 = v2->m_AnimOverlay.m_Size - v8 - 1;
    v2->m_AnimOverlay.m_pElements = v2->m_AnimOverlay.m_Memory.m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 76 * v11);
    v12 = v8;
    v13 = &p_m_AnimOverlay->m_Memory.m_pMemory[v8];
    if ( v13 != nullptr )
      CAnimationLayer::Init(this: v13, pOverlay: nullptr);
    iOpenLayer = v8;
    CAnimationLayer::Init(this: &p_m_AnimOverlay->m_Memory.m_pMemory[v12], pOverlay: this);
    m_pOwnerEntity = p_m_AnimOverlay->m_Memory.m_pMemory[v12].m_pOwnerEntity;
    if ( m_pOwnerEntity != nullptr )
    {
      if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
      }
      else
      {
        v15 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
        if ( v15 != nullptr )
        {
          v15->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v15)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    v2 = this;
  }
  if ( i == 0 && v2->m_AnimOverlay.m_Size < 15 )
  {
    v16 = CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertBefore(
            this: p_m_AnimOverlay,
            elem: p_m_AnimOverlay->m_Size);
    CAnimationLayer::Init(this: &p_m_AnimOverlay->m_Memory.m_pMemory[v16], pOverlay: v2);
    v17 = p_m_AnimOverlay->m_Memory.m_pMemory[v16].m_pOwnerEntity;
    if ( v17 != nullptr )
    {
      if ( v17->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v17->m_Network + 76) |= 1u;
      }
      else
      {
        v18 = &v17->m_Network.m_pPev->CBaseEdict;
        if ( v18 != nullptr )
        {
          v18->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v18)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
  }
  v19 = 0;
  ia = 0;
  if ( v2->m_AnimOverlay.m_Size > 0 )
  {
    v29 = 0;
    do
    {
      v20 = *(int *)((char *)&p_m_AnimOverlay->m_Memory.m_pMemory->m_nOrder.m_Value + v19);
      v21 = (int *)((char *)&p_m_AnimOverlay->m_Memory.m_pMemory->m_nOrder.m_Value + v19);
      if ( v20 >= iNewOrder && v20 < 15 )
      {
        v22 = v20 + 1;
        v23 = v21[3];
        if ( v23 != 0 )
        {
          if ( *(_BYTE *)(v23 + 84) != 0 )
          {
            *(_BYTE *)(v23 + 88) |= 1u;
          }
          else
          {
            v24 = *(CBaseEdict **)(v23 + 24);
            if ( v24 != nullptr )
            {
              v24->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v24)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        *v21 = v22;
        v2 = this;
      }
      v19 = v29 + 76;
      ++ia;
      v29 += 76;
    }
    while ( ia < v2->m_AnimOverlay.m_Size );
  }
  v25 = iOpenLayer;
  p_m_AnimOverlay->m_Memory.m_pMemory[iOpenLayer].m_fFlags = 1;
  p_m_nOrder = &p_m_AnimOverlay->m_Memory.m_pMemory[iOpenLayer].m_nOrder;
  if ( p_m_nOrder->m_Value != iNewOrder )
  {
    v27 = p_m_AnimOverlay->m_Memory.m_pMemory[v25].m_pOwnerEntity;
    if ( v27 != nullptr )
    {
      if ( v27->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v27->m_Network + 76) |= 1u;
      }
      else
      {
        v28 = &v27->m_Network.m_pPev->CBaseEdict;
        if ( v28 != nullptr )
        {
          v28->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v28)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    p_m_nOrder->m_Value = iNewOrder;
  }
  p_m_AnimOverlay->m_Memory.m_pMemory[v25].m_nPriority = iPriority;
  p_m_AnimOverlay->m_Memory.m_pMemory[v25].m_flLastAccess = gpGlobals->curtime;
  return iOpenLayer;
}

//------------------------------------------------------------------------------
// Address: 0x100A13D0
// Name: public: void CBaseAnimatingOverlay::SetNumAnimOverlays(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::SetNumAnimOverlays(CBaseAnimatingOverlay *this, int num)
{
  int m_Size; // edx
  edict_t *m_pPev; // esi

  m_Size = this->m_AnimOverlay.m_Size;
  if ( m_Size >= num )
  {
    if ( m_Size <= num )
      return;
    this->m_AnimOverlay.m_Size -= m_Size - num;
    if ( !this->m_Network.m_TimerEvent.m_bRegistered )
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev == nullptr )
        return;
      goto LABEL_9;
    }
LABEL_7:
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    return;
  }
  CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>::InsertMultipleBefore(
    this: &this->m_AnimOverlay,
    elem: this->m_AnimOverlay.m_Size,
    num: num - m_Size);
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
    goto LABEL_7;
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev == nullptr )
    return;
LABEL_9:
  m_pPev->m_fStateFlags |= 0x101u;
  CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1550
// Name: public: virtual void CBaseAnimatingOverlay::GetSkeleton(class CStudioHdr __near *,class Vector __near * const,class QuaternionAligned __near * const,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimatingOverlay::GetSkeleton(
        CBaseAnimatingOverlay *this@<ecx>,
        int a2@<ebp>,
        CStudioHdr *pStudioHdr,
        Vector *pos,
        QuaternionAligned *q,
        int boneMask)
{
  void *v6; // esp
  CBaseAnimatingOverlay *v7; // esi
  signed int m_Size; // edx
  signed int v9; // ecx
  CAnimationLayer *m_pMemory; // eax
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nOrder> *p_m_nOrder; // esi
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nOrder> *v12; // eax
  int m_Value; // edi
  int v14; // edi
  int v15; // edi
  int v16; // eax
  int v17; // eax
  int v18; // edi
  signed int i; // edi
  int v20; // eax
  ikcontextikrule_t *v21; // eax
  CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> > *v22; // eax
  CIKContext v23; // [esp+20h] [ebp-10CCh] BYREF
  _DWORD v24[15]; // [esp+1098h] [ebp-54h] BYREF
  CBaseAnimatingOverlay *v25; // [esp+10D4h] [ebp-18h]
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nOrder> *v26; // [esp+10D8h] [ebp-14h]
  IBoneSetup v27; // [esp+10DCh] [ebp-10h] BYREF
  _DWORD v28[3]; // [esp+10E0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+10ECh] [ebp+0h]

  v28[0] = a2;
  v28[1] = retaddr;
  v6 = alloca(4296);
  v7 = this;
  v25 = this;
  if ( pStudioHdr != nullptr && CStudioHdr::SequencesAvailable(this: pStudioHdr) )
  {
    IBoneSetup::IBoneSetup(
      this: &v27,
      pStudioHdr,
      boneMask,
      poseParameter: v7->m_flPoseParameter.m_Value,
      pPoseDebugger: nullptr);
    IBoneSetup::InitPose(this: &v27, pos, q);
    IBoneSetup::AccumulatePose(
      this: &v27,
      pos,
      q,
      sequence: v7->m_nSequence.m_Value,
      cycle: v7->m_flCycle.m_Value,
      flWeight: 1.0,
      flTime: gpGlobals->curtime,
      pIKContext: v7->m_pIk);
    m_Size = v7->m_AnimOverlay.m_Size;
    if ( m_Size > 0 )
      memset32(v24, 15, m_Size);
    v9 = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v7->m_AnimOverlay.m_Memory.m_pMemory;
      p_m_nOrder = &m_pMemory->m_nOrder;
      v12 = &m_pMemory[1].m_nOrder;
      v26 = v12;
      do
      {
        if ( *(float *)&p_m_nOrder[-10].m_Value > 0.0 && (p_m_nOrder[-15].m_Value & 1) != 0 )
        {
          m_Value = p_m_nOrder->m_Value;
          if ( p_m_nOrder->m_Value >= 0 && m_Value < m_Size )
            v24[m_Value] = v9;
        }
        if ( *(float *)&v12[-10].m_Value > 0.0 && (p_m_nOrder[4].m_Value & 1) != 0 )
        {
          v14 = v12->m_Value;
          if ( v12->m_Value >= 0 && v14 < m_Size )
          {
            v24[v14] = v9 + 1;
            v12 = v26;
          }
        }
        if ( *(float *)&v12[9].m_Value > 0.0 && (p_m_nOrder[23].m_Value & 1) != 0 )
        {
          v15 = v12[19].m_Value;
          if ( v15 >= 0 && v15 < m_Size )
          {
            v24[v15] = v9 + 2;
            v12 = v26;
          }
        }
        if ( *(float *)&v12[28].m_Value > 0.0 && (p_m_nOrder[42].m_Value & 1) != 0 )
        {
          v16 = v12[38].m_Value;
          if ( v16 >= 0 && v16 < m_Size )
            v24[v16] = v9 + 3;
          v12 = v26;
        }
        v9 += 4;
        v12 += 76;
        p_m_nOrder += 76;
        v26 = v12;
      }
      while ( v9 < m_Size - 3 );
      v7 = v25;
    }
    if ( v9 < m_Size )
    {
      v17 = (int)&v7->m_AnimOverlay.m_Memory.m_pMemory[v9];
      do
      {
        if ( *(float *)(v17 + 20) > 0.0 && (*(_BYTE *)v17 & 1) != 0 )
        {
          v18 = *(_DWORD *)(v17 + 60);
          if ( v18 >= 0 && v18 < m_Size )
            v24[v18] = v9;
        }
        ++v9;
        v17 += 76;
      }
      while ( v9 < m_Size );
    }
    for ( i = 0; i < m_Size; ++i )
    {
      v20 = v24[i];
      if ( v20 >= 0 && v20 < m_Size )
        IBoneSetup::AccumulatePose(
          this: &v27,
          pos,
          q,
          sequence: v7->m_AnimOverlay.m_Memory.m_pMemory[v20].m_nSequence.m_Value,
          cycle: v7->m_AnimOverlay.m_Memory.m_pMemory[v20].m_flCycle.m_Value,
          flWeight: v7->m_AnimOverlay.m_Memory.m_pMemory[v20].m_flWeight.m_Value,
          flTime: gpGlobals->curtime,
          pIKContext: v7->m_pIk);
      m_Size = v7->m_AnimOverlay.m_Size;
    }
    if ( v7->m_pIk != nullptr )
    {
      CIKContext::CIKContext(this: &v23);
      if ( (v7->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)v28);
      if ( (v7->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)v28);
      CIKContext::Init(
        this: &v23,
        pStudioHdr,
        angles: &v7->m_angAbsRotation,
        pos: &v7->m_vecAbsOrigin,
        flTime: gpGlobals->curtime,
        iFramecounter: 0,
        boneMask);
      IBoneSetup::CalcAutoplaySequences(this: &v27, pos, q, flRealTime: gpGlobals->curtime, pIKContext: &v23);
      v21 = v23.m_ikLock.m_Memory.m_pMemory;
      v23.m_ikLock.m_Size = 0;
      if ( v23.m_ikLock.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v23.m_ikLock.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23.m_ikLock.m_Memory.m_pMemory);
          v21 = nullptr;
          v23.m_ikLock.m_Memory.m_pMemory = nullptr;
        }
        v23.m_ikLock.m_Memory.m_nAllocationCount = 0;
      }
      v23.m_ikLock.m_pElements = v21;
      if ( v23.m_ikLock.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v21 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
          v23.m_ikLock.m_Memory.m_pMemory = nullptr;
        }
        v23.m_ikLock.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>,int>>::RemoveAll(this: &v23.m_ikChainRule);
      v22 = v23.m_ikChainRule.m_Memory.m_pMemory;
      if ( v23.m_ikChainRule.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v23.m_ikChainRule.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23.m_ikChainRule.m_Memory.m_pMemory);
          v22 = nullptr;
          v23.m_ikChainRule.m_Memory.m_pMemory = nullptr;
        }
        v23.m_ikChainRule.m_Memory.m_nAllocationCount = 0;
      }
      v23.m_ikChainRule.m_pElements = v22;
      if ( v23.m_ikChainRule.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
    }
    else
    {
      IBoneSetup::CalcAutoplaySequences(this: &v27, pos, q, flRealTime: gpGlobals->curtime, pIKContext: nullptr);
    }
    IBoneSetup::CalcBoneAdj(this: &v27, pos, q, controllers: v7->m_flEncodedController.m_Value);
    IBoneSetup::~IBoneSetup(this: &v27);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1940
// Name: public: int CBaseAnimatingOverlay::AddLayeredSequence(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimatingOverlay::AddLayeredSequence(CBaseAnimatingOverlay *this, int sequence, int iPriority)
{
  int result; // eax
  int v5; // ebx
  CAnimationLayer *v6; // edi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v8; // eax
  CAnimationLayer *m_pMemory; // eax
  float *p_m_Value; // edi
  CBaseAnimatingOverlay *v11; // eax
  CBaseEdict *v12; // eax
  CAnimationLayer *v13; // ecx
  CNetworkVarBase<int,CAnimationLayer::NetworkVar_m_nSequence> *p_m_nSequence; // edi
  CBaseAnimatingOverlay *v15; // eax
  CBaseEdict *v16; // eax
  CAnimationLayer *v17; // eax
  float *v18; // edi
  CBaseAnimatingOverlay *v19; // eax
  CBaseEdict *v20; // eax
  CStudioHdr *m_pStudioHdr; // eax
  CAnimationLayer *v22; // edi
  CAnimationLayer *v23; // edi
  const char *SequenceName; // eax
  double v25; // [esp+14h] [ebp-1Ch]
  double m_Value; // [esp+1Ch] [ebp-14h]
  int i; // [esp+3Ch] [ebp+Ch]

  result = CBaseAnimatingOverlay::AllocateLayer(this, iPriority);
  i = result;
  if ( result >= 0 && result < this->m_AnimOverlay.m_Size )
  {
    v5 = result;
    v6 = &this->m_AnimOverlay.m_Memory.m_pMemory[result];
    if ( (v6->m_fFlags & 1) != 0 )
    {
      if ( v6->m_flCycle.m_Value != 0.0 )
      {
        m_pOwnerEntity = v6->m_pOwnerEntity;
        if ( m_pOwnerEntity != nullptr )
        {
          if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
          }
          else
          {
            v8 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
            if ( v8 != nullptr )
            {
              v8->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v8)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        v6->m_flCycle.m_Value = 0.0;
      }
      m_pMemory = this->m_AnimOverlay.m_Memory.m_pMemory;
      p_m_Value = &m_pMemory[v5].m_flPrevCycle.m_Value;
      if ( *p_m_Value != 0.0 )
      {
        v11 = m_pMemory[v5].m_pOwnerEntity;
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
        *p_m_Value = 0.0;
      }
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flPlaybackRate = 1.0;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_nActivity = ACT_INVALID;
      v13 = this->m_AnimOverlay.m_Memory.m_pMemory;
      p_m_nSequence = &v13[v5].m_nSequence;
      if ( p_m_nSequence->m_Value != sequence )
      {
        v15 = v13[v5].m_pOwnerEntity;
        if ( v15 != nullptr )
        {
          if ( v15->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v15->m_Network + 76) |= 1u;
          }
          else
          {
            v16 = &v15->m_Network.m_pPev->CBaseEdict;
            if ( v16 != nullptr )
            {
              v16->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v16)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        p_m_nSequence->m_Value = sequence;
      }
      v17 = this->m_AnimOverlay.m_Memory.m_pMemory;
      v18 = &v17[v5].m_flWeight.m_Value;
      if ( *v18 != 1.0 )
      {
        v19 = v17[v5].m_pOwnerEntity;
        if ( v19 != nullptr )
        {
          if ( v19->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v19->m_Network + 76) |= 1u;
          }
          else
          {
            v20 = &v19->m_Network.m_pPev->CBaseEdict;
            if ( v20 != nullptr )
            {
              v20->m_fStateFlags |= 0x101u;
              CBaseEdict::GetChangeAccessor(this: v20)->m_iChangeInfoSerialNumber = 0;
            }
          }
        }
        *v18 = 1.0;
      }
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flBlendIn = 0.0;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flBlendOut = 0.0;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_bSequenceFinished = false;
      this->m_AnimOverlay.m_Memory.m_pMemory[v5].m_flLastEventCheck = 0.0;
      if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
        CBaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
        m_pStudioHdr = nullptr;
      v22 = this->m_AnimOverlay.m_Memory.m_pMemory;
      v22[v5].m_bLooping = GetSequenceFlags(pstudiohdr: m_pStudioHdr, sequence) & 1;
      if ( ai_sequence_debug.m_pParent != nullptr
        && ai_sequence_debug.m_pParent->m_Value.m_nValue != 0
        && (this->m_debugOverlays & 0x1000) != 0 )
      {
        v23 = &this->m_AnimOverlay.m_Memory.m_pMemory[v5];
        m_Value = v23->m_flWeight.m_Value;
        v25 = v23->m_flCycle.m_Value;
        SequenceName = CBaseAnimating::GetSequenceName(this, iSequence: v23->m_nSequence.m_Value);
        _Msg(
          a1: "%5.3f : adding %d (%d): %s : %5.3f (%.3f)\n",
          gpGlobals->curtime,
          i,
          v23->m_nOrder.m_Value,
          SequenceName,
          v25,
          m_Value);
        return i;
      }
      else
      {
        return i;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1BE0
// Name: public: int CBaseAnimatingOverlay::AddGestureSequence(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimatingOverlay::AddGestureSequence(CBaseAnimatingOverlay *this, int sequence, bool autokill)
{
  int result; // eax
  CAnimationLayer *v5; // ecx

  result = CBaseAnimatingOverlay::AddLayeredSequence(this, sequence, iPriority: 0);
  if ( result >= 0 && result < this->m_AnimOverlay.m_Size )
  {
    v5 = &this->m_AnimOverlay.m_Memory.m_pMemory[result];
    if ( (v5->m_fFlags & 1) != 0 )
    {
      if ( autokill )
        v5->m_fFlags |= 2u;
      else
        v5->m_fFlags &= ~2u;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1C30
// Name: public: int CBaseAnimatingOverlay::AddGesture(enum Activity,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimatingOverlay::AddGesture(CBaseAnimatingOverlay *this, Activity activity, bool autokill)
{
  IMDLCache *v5; // ebx
  int v6; // eax
  const char *ActivityName; // edi
  const char *v8; // eax
  int v9; // eax
  int v10; // edi
  CAnimationLayer *v11; // eax

  if ( CBaseAnimatingOverlay::FindGestureLayer(this, activity) != -1 )
    return CBaseAnimatingOverlay::FindGestureLayer(this, activity);
  v5 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  v6 = CBaseAnimating::SelectWeightedSequence(this, activity);
  if ( v6 > 0 )
  {
    v9 = CBaseAnimatingOverlay::AddLayeredSequence(this, sequence: v6, iPriority: 0);
    v10 = v9;
    if ( v9 >= 0 && v9 < this->m_AnimOverlay.m_Size )
    {
      v11 = &this->m_AnimOverlay.m_Memory.m_pMemory[v9];
      if ( (v11->m_fFlags & 1) != 0 )
      {
        if ( autokill )
          v11->m_fFlags |= 2u;
        else
          v11->m_fFlags &= ~2u;
      }
    }
    if ( v10 != -1 )
      this->m_AnimOverlay.m_Memory.m_pMemory[v10].m_nActivity = activity;
    v5->EndLock(this: v5);
    return v10;
  }
  else
  {
    ActivityName = CAI_BaseNPC::GetActivityName(actID: activity);
    v8 = *(const char **)((int (__thiscall *)(CBaseAnimatingOverlay *, bool *))this->GetModelName)(
                           a1: this,
                           a2: &autokill);
    if ( v8 == nullptr )
      v8 = locale;
    DevMsg(a1: "CBaseAnimatingOverlay::AddGesture:  model %s missing activity %s\n", v8, ActivityName);
    v5->EndLock(this: v5);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1D20
// Name: public: void CBaseAnimatingOverlay::RestartGesture(enum Activity,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimatingOverlay::RestartGesture(
        CBaseAnimatingOverlay *this,
        Activity activity,
        bool addifmissing,
        bool autokill)
{
  int GestureLayer; // eax
  int v6; // esi
  CNetworkVarBase<float,CAnimationLayer::NetworkVar_m_flCycle> *p_m_flCycle; // edi
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v9; // eax
  CNetworkVarBase<float,CAnimationLayer::NetworkVar_m_flPrevCycle> *p_m_flPrevCycle; // edi
  CBaseAnimatingOverlay *v11; // eax
  CBaseEdict *v12; // eax

  GestureLayer = CBaseAnimatingOverlay::FindGestureLayer(this, activity);
  if ( GestureLayer == -1 )
  {
    if ( addifmissing )
      CBaseAnimatingOverlay::AddGesture(this, activity, autokill);
  }
  else
  {
    v6 = GestureLayer;
    p_m_flCycle = &this->m_AnimOverlay.m_Memory.m_pMemory[GestureLayer].m_flCycle;
    if ( p_m_flCycle->m_Value != 0.0 )
    {
      m_pOwnerEntity = this->m_AnimOverlay.m_Memory.m_pMemory[GestureLayer].m_pOwnerEntity;
      if ( m_pOwnerEntity != nullptr )
      {
        if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
        }
        else
        {
          v9 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
          if ( v9 != nullptr )
          {
            v9->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v9)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      p_m_flCycle->m_Value = 0.0;
    }
    p_m_flPrevCycle = &this->m_AnimOverlay.m_Memory.m_pMemory[v6].m_flPrevCycle;
    if ( p_m_flPrevCycle->m_Value != 0.0 )
    {
      v11 = this->m_AnimOverlay.m_Memory.m_pMemory[v6].m_pOwnerEntity;
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
      p_m_flPrevCycle->m_Value = 0.0;
    }
    this->m_AnimOverlay.m_Memory.m_pMemory[v6].m_flLastEventCheck = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF2E0
// Name: CAnimationLayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAnimationLayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAnimationLayer>(__formal: nullptr);
  CAnimationLayer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF2F0
// Name: CBaseAnimatingOverlay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseAnimatingOverlay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseAnimatingOverlay>(__formal: nullptr);
  CBaseAnimatingOverlay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF300
// Name: DT_Animationlayer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Animationlayer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Animationlayer::g_SendTable);
  return atexit(func: DT_Animationlayer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF320
// Name: DT_Animationlayer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Animationlayer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Animationlayer::ignored>();
  DT_Animationlayer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF330
// Name: DT_OverlayVars::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_OverlayVars::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_OverlayVars::g_SendTable);
  return atexit(func: DT_OverlayVars::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF350
// Name: DT_OverlayVars::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_OverlayVars::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_OverlayVars::ignored>();
  DT_OverlayVars::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF380
// Name: DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseAnimatingOverlay::g_SendTable);
  return atexit(func: DT_BaseAnimatingOverlay::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF3A0
// Name: DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseAnimatingOverlay::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseAnimatingOverlay::ignored>();
  DT_BaseAnimatingOverlay::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419730
// Name: DT_Animationlayer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Animationlayer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Animationlayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419740
// Name: DT_OverlayVars::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_OverlayVars::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_OverlayVars::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419770
// Name: DT_BaseAnimatingOverlay::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseAnimatingOverlay::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseAnimatingOverlay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100A0510
// Name: struct datamap_t __near * DataMapInit<class CAnimationLayer>(class CAnimationLayer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAnimationLayer>()
{
  CActivityDataOps *v0; // eax

  if ( (_S2_46 & 1) == 0 )
  {
    _S2_46 |= 1u;
    nameHolder_84.m_pszBase = "CAnimationLayer";
    nameHolder_84.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_84.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_84.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_84.m_Names.m_Size = 0;
    nameHolder_84.m_Names.m_pElements = nullptr;
    nameHolder_84.m_nLenBase = 15;
    atexit(func: DataMapInit_CAnimationLayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAnimationLayer::m_DataMap.baseMap = nullptr;
  if ( (_S2_46 & 2) == 0 )
  {
    _S2_46 |= 2u;
    v0 = ActivityDataOps();
    *(_QWORD *)dataDesc_81[14].flatOffset = 0;
    dataDesc_81[13].pSaveRestoreOps = v0;
    *(_QWORD *)dataDesc_81[15].flatOffset = 0;
    dataDesc_81[14].fieldType = FIELD_INTEGER;
    dataDesc_81[14].fieldSize = 1;
    dataDesc_81[15].fieldType = FIELD_INTEGER;
    *(_QWORD *)&dataDesc_81[13].td = 0;
    *(_QWORD *)&dataDesc_81[13].override_field = 0;
    *(_QWORD *)&dataDesc_81[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_81[13].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_81[16].flatOffset = 0;
    dataDesc_81[13].inputFunc = nullptr;
    dataDesc_81[14].fieldName = "m_nPriority";
    dataDesc_81[14].fieldOffset = 56;
    dataDesc_81[14].flags = 2;
    dataDesc_81[14].externalName = nullptr;
    dataDesc_81[14].pSaveRestoreOps = nullptr;
    dataDesc_81[14].inputFunc = nullptr;
    dataDesc_81[14].td = nullptr;
    dataDesc_81[14].fieldSizeInBytes = 4;
    dataDesc_81[14].override_field = nullptr;
    dataDesc_81[14].override_count = 0;
    dataDesc_81[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_81[14].flatGroup = 0;
    dataDesc_81[15].fieldName = "m_nOrder";
    dataDesc_81[15].fieldOffset = 60;
    *(_DWORD *)&dataDesc_81[15].fieldSize = 131073;
    dataDesc_81[15].externalName = nullptr;
    dataDesc_81[15].pSaveRestoreOps = nullptr;
    dataDesc_81[15].inputFunc = nullptr;
    dataDesc_81[15].td = nullptr;
    dataDesc_81[15].fieldSizeInBytes = 4;
    dataDesc_81[15].override_field = nullptr;
    dataDesc_81[15].override_count = 0;
    dataDesc_81[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_81[15].flatGroup = 0;
    dataDesc_81[16].fieldType = FIELD_FLOAT;
    dataDesc_81[16].fieldName = "m_flLastEventCheck";
    dataDesc_81[16].fieldOffset = 64;
    *(_DWORD *)&dataDesc_81[16].fieldSize = 131073;
    dataDesc_81[16].externalName = nullptr;
    dataDesc_81[16].pSaveRestoreOps = nullptr;
    dataDesc_81[16].inputFunc = nullptr;
    dataDesc_81[16].td = nullptr;
    dataDesc_81[16].fieldSizeInBytes = 4;
    dataDesc_81[16].override_field = nullptr;
    dataDesc_81[16].override_count = 0;
    dataDesc_81[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_81[16].flatGroup = 0;
    dataDesc_81[17].fieldType = FIELD_TIME;
    dataDesc_81[17].fieldName = "m_flLastAccess";
    dataDesc_81[17].fieldOffset = 68;
    *(_DWORD *)&dataDesc_81[17].fieldSize = 131073;
    dataDesc_81[17].externalName = nullptr;
    dataDesc_81[17].pSaveRestoreOps = nullptr;
    dataDesc_81[17].inputFunc = nullptr;
    dataDesc_81[17].td = nullptr;
    dataDesc_81[17].fieldSizeInBytes = 4;
    dataDesc_81[17].override_field = nullptr;
    dataDesc_81[17].override_count = 0;
    dataDesc_81[17].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_81[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_81[17].flatGroup = 0;
    dataDesc_81[18].fieldType = FIELD_FLOAT;
    dataDesc_81[18].fieldName = "m_flLayerAnimtime";
    dataDesc_81[18].fieldTolerance = 0.0;
    dataDesc_81[19].fieldTolerance = 0.0;
    dataDesc_81[18].fieldOffset = 44;
    *(_DWORD *)&dataDesc_81[18].fieldSize = 131073;
    dataDesc_81[18].externalName = nullptr;
    dataDesc_81[18].pSaveRestoreOps = nullptr;
    dataDesc_81[18].inputFunc = nullptr;
    dataDesc_81[18].td = nullptr;
    dataDesc_81[18].fieldSizeInBytes = 4;
    dataDesc_81[18].override_field = nullptr;
    dataDesc_81[18].override_count = 0;
    *(_QWORD *)dataDesc_81[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_81[18].flatGroup = 0;
    dataDesc_81[19].fieldType = FIELD_FLOAT;
    dataDesc_81[19].fieldName = "m_flLayerFadeOuttime";
    dataDesc_81[19].fieldOffset = 48;
    *(_DWORD *)&dataDesc_81[19].fieldSize = 131073;
    dataDesc_81[19].externalName = nullptr;
    dataDesc_81[19].pSaveRestoreOps = nullptr;
    dataDesc_81[19].inputFunc = nullptr;
    dataDesc_81[19].td = nullptr;
    dataDesc_81[19].fieldSizeInBytes = 4;
    dataDesc_81[19].override_field = nullptr;
    dataDesc_81[19].override_count = 0;
    *(_QWORD *)dataDesc_81[19].flatOffset = 0;
    *(_DWORD *)&dataDesc_81[19].flatGroup = 0;
  }
  CAnimationLayer::m_DataMap.dataNumFields = 19;
  CAnimationLayer::m_DataMap.dataDesc = &dataDesc_81[1];
  return &CAnimationLayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100A0870
// Name: struct datamap_t __near * DataMapInit<class CBaseAnimatingOverlay>(class CBaseAnimatingOverlay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseAnimatingOverlay>()
{
  if ( (_S3_22 & 1) == 0 )
  {
    _S3_22 |= 1u;
    nameHolder_85.m_pszBase = "CBaseAnimatingOverlay";
    nameHolder_85.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_85.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_85.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_85.m_Names.m_Size = 0;
    nameHolder_85.m_Names.m_pElements = nullptr;
    nameHolder_85.m_nLenBase = 21;
    atexit(func: DataMapInit_CBaseAnimatingOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseAnimatingOverlay::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S3_22 & 2) == 0 )
  {
    _S3_22 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>,10>::`vftable';
    }
    dataDesc_82[1].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAnimationLayer,CUtlMemory<CAnimationLayer,int>>>'::`2'::ops;
    dataDesc_82[1].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_82[1].td = 0;
    *(_QWORD *)&dataDesc_82[1].override_field = 0;
    *(_QWORD *)&dataDesc_82[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_82[1].flatOffset[1] = 0;
  }
  CBaseAnimatingOverlay::m_DataMap.dataNumFields = 1;
  CBaseAnimatingOverlay::m_DataMap.dataDesc = &dataDesc_82[1];
  return &CBaseAnimatingOverlay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FF360
// Name: _dynamic_initializer_for__g_CBaseAnimatingOverlay_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseAnimatingOverlay_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseAnimatingOverlay_ClassReg,
           pNetworkName: "CBaseAnimatingOverlay",
           pTable: &DT_BaseAnimatingOverlay::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF3B0
// Name: _dynamic_initializer_for__ai_show_hull_attacks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_show_hull_attacks__()
{
  ConVar::ConVar(this: &ai_show_hull_attacks, pName: "ai_show_hull_attacks", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_show_hull_attacks__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF3E0
// Name: _dynamic_initializer_for__ai_force_serverside_ragdoll__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_force_serverside_ragdoll__()
{
  ConVar::ConVar(this: &ai_force_serverside_ragdoll, pName: "ai_force_serverside_ragdoll", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_force_serverside_ragdoll__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF410
// Name: _dynamic_initializer_for__ai_use_visibility_cache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_use_visibility_cache__()
{
  ConVar::ConVar(this: &ai_use_visibility_cache, pName: "ai_use_visibility_cache", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_use_visibility_cache__);
}

//------------------------------------------------------------------------------
// Address: 0x10419750
// Name: _ServerClassInit_DT_OverlayVars::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_OverlayVars::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_5;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419780
// Name: _ServerClassInit_DT_BaseAnimatingOverlay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseAnimatingOverlay::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_3;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104197A0
// Name: _ServerClassInit_DT_Animationlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Animationlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_10;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104197C0
// Name: _DataMapInit_CAnimationLayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAnimationLayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_84);
}

//------------------------------------------------------------------------------
// Address: 0x104197D0
// Name: _DataMapInit_CBaseAnimatingOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseAnimatingOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_85);
}

//------------------------------------------------------------------------------
// Address: 0x104197E0
// Name: _dynamic_atexit_destructor_for__ai_show_hull_attacks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_show_hull_attacks__()
{
  ConVar::~ConVar(this: &ai_show_hull_attacks);
}

//------------------------------------------------------------------------------
// Address: 0x104197F0
// Name: _dynamic_atexit_destructor_for__ai_force_serverside_ragdoll__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_force_serverside_ragdoll__()
{
  ConVar::~ConVar(this: &ai_force_serverside_ragdoll);
}

//------------------------------------------------------------------------------
// Address: 0x10419800
// Name: _dynamic_atexit_destructor_for__ai_use_visibility_cache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_use_visibility_cache__()
{
  ConVar::~ConVar(this: &ai_use_visibility_cache);
}
