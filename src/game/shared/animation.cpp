// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/animation.cpp
// Functions: 22
// ============================================================

#include "game\shared\animation.h"

//------------------------------------------------------------------------------
// Address: 0x10008E50
// Name: void GetAttachmentLocalSpace(class CStudioHdr __near *,int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetAttachmentLocalSpace(CStudioHdr *pstudiohdr, int attachIndex, matrix3x4_t *pLocalToWorld)
{
  const mstudioattachment_t *v3; // eax

  if ( attachIndex >= 0 )
  {
    v3 = CStudioHdr::pAttachment(this: pstudiohdr, i: attachIndex);
    MatrixCopy(in: &v3->local, out: pLocalToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008E80
// Name: public: struct mstudioseqdesc_t __near & CStudioHdr::pSeqdesc(int)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall CStudioHdr::pSeqdesc(CStudioHdr *this, int iSequence)
{
  int v2; // eax
  const studiohdr_t *m_pStudioHdr; // ecx

  if ( this->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this, i: iSequence);
  v2 = iSequence;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( iSequence < 0 || iSequence >= m_pStudioHdr->numlocalseq )
    v2 = 0;
  return (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v2 + m_pStudioHdr->localseqindex);
}

//------------------------------------------------------------------------------
// Address: 0x10008EC0
// Name: public: int mstudioevent_for_client_server_t::Event(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mstudioevent_for_client_server_t::Event(mstudioevent_for_client_server_t *this)
{
  if ( (this->type & 0x400) != 0 )
    return this->_event_highword;
  else
    return *(_DWORD *)&this->_event_highword;
}

//------------------------------------------------------------------------------
// Address: 0x10008EE0
// Name: int ExtractBbox(class CStudioHdr __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ExtractBbox(CStudioHdr *pstudiohdr, int sequence, Vector *mins, Vector *maxs)
{
  int v5; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v7; // eax

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  v5 = sequence;
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v7 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: sequence);
  }
  else
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
      v5 = 0;
    v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v5 + m_pStudioHdr->localseqindex);
  }
  *mins = v7->bbmin;
  *maxs = v7->bbmax;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008F60
// Name: void SetEventIndexForSequence(struct mstudioseqdesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetEventIndexForSequence(mstudioseqdesc_t *seqdesc)
{
  int numevents; // eax
  char *v3; // esi
  const char *v4; // edi
  int v5; // eax
  int index; // [esp+4h] [ebp-4h]
  mstudioseqdesc_t *seqdesca; // [esp+10h] [ebp+8h]

  if ( seqdesc != nullptr )
  {
    numevents = seqdesc->numevents;
    if ( numevents != 0 )
    {
      seqdesc->flags |= 0x10000u;
      index = 0;
      if ( numevents > 0 )
      {
        seqdesca = nullptr;
        do
        {
          v3 = (char *)seqdesca + seqdesc->eventindex + (_DWORD)seqdesc;
          if ( v3 != nullptr && (*((_DWORD *)v3 + 2) & 0x400) != 0 )
          {
            v4 = &v3[*((_DWORD *)v3 + 19)];
            v5 = EventList_IndexForName(pszEventName: v4);
            if ( v5 == -1 )
            {
              *((_WORD *)v3 + 2) = EventList_RegisterPrivateEvent(pszEventName: v4);
            }
            else
            {
              *((_WORD *)v3 + 2) = v5;
              *((_DWORD *)v3 + 2) |= EventList_GetEventType(eventIndex: v5);
            }
          }
          seqdesca = (mstudioseqdesc_t *)((char *)seqdesca + 80);
          ++index;
        }
        while ( index < seqdesc->numevents );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008FF0
// Name: struct mstudioevent_for_client_server_t __near * GetEventIndexForSequence(struct mstudioseqdesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioevent_for_client_server_t *__cdecl GetEventIndexForSequence(mstudioseqdesc_t *seqdesc)
{
  if ( (seqdesc->flags & 0x10000) == 0 )
    SetEventIndexForSequence(seqdesc);
  return (mstudioevent_for_client_server_t *)((char *)seqdesc + seqdesc->eventindex);
}

//------------------------------------------------------------------------------
// Address: 0x10009020
// Name: int LookupActivity(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LookupActivity(CStudioHdr *pstudiohdr, const char *label)
{
  int i; // edi
  int v4; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // eax
  mstudioseqdesc_t *v7; // esi

  if ( pstudiohdr == nullptr )
    return 0;
  for ( i = 0; ; ++i )
  {
    v4 = pstudiohdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
       : pstudiohdr->m_pStudioHdr->numlocalseq;
    if ( i >= v4 )
      break;
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v7 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i);
    }
    else
    {
      m_pStudioHdr = pstudiohdr->m_pStudioHdr;
      v6 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v6 = 0;
      v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v6 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v7 + v7->szactivitynameindex, s2: label) == 0 )
      return v7->activity;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100090B0
// Name: int GetSequenceFlags(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSequenceFlags(CStudioHdr *pstudiohdr, int sequence)
{
  int NumSeq_Internal; // eax

  if ( pstudiohdr != nullptr
    && CStudioHdr::SequencesAvailable(this: pstudiohdr)
    && sequence >= 0
    && (pstudiohdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
      : (NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq),
        sequence < NumSeq_Internal) )
  {
    return CStudioHdr::pSeqdesc(this: pstudiohdr, iSequence: sequence)->flags;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009100
// Name: int FindTransitionSequence(class CStudioHdr __near *,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindTransitionSequence(CStudioHdr *pstudiohdr, int iCurrentSequence, int iGoalSequence, int *piDir)
{
  int v6; // eax
  int i; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  mstudioseqdesc_t *seqdesc; // [esp+4h] [ebp-4h]
  int iInternNode; // [esp+10h] [ebp+8h]

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return iGoalSequence;
  if ( iCurrentSequence < 0 )
    return iGoalSequence;
  v6 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( iCurrentSequence >= v6 )
    return iGoalSequence;
  i = iGoalSequence;
  if ( iGoalSequence < 0 )
    return i;
  v8 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( iGoalSequence >= v8 )
    return i;
  if ( CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence) == 0
    || CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence) == 0 )
  {
    *piDir = 1;
    return iGoalSequence;
  }
  if ( *piDir <= 0 )
    v9 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence);
  else
    v9 = CStudioHdr::ExitNode(this: pstudiohdr, iSequence: iCurrentSequence);
  v10 = v9;
  if ( v9 == CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence) )
  {
LABEL_32:
    *piDir = 1;
    return i;
  }
  v11 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence);
  iInternNode = CStudioHdr::GetTransition(this: pstudiohdr, iFrom: v10, iTo: v11);
  if ( iInternNode == 0 )
    return i;
  for ( i = 0; ; ++i )
  {
    v12 = pstudiohdr->m_pVModel != nullptr
        ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
        : pstudiohdr->m_pStudioHdr->numlocalseq;
    if ( i >= v12 )
      break;
    seqdesc = CStudioHdr::pSeqdesc(this: pstudiohdr, iSequence: i);
    if ( CStudioHdr::EntryNode(this: pstudiohdr, iSequence: i) == v10
      && CStudioHdr::ExitNode(this: pstudiohdr, iSequence: i) == iInternNode )
    {
      goto LABEL_32;
    }
    if ( seqdesc->nodeflags != 0
      && CStudioHdr::ExitNode(this: pstudiohdr, iSequence: i) == v10
      && CStudioHdr::EntryNode(this: pstudiohdr, iSequence: i) == iInternNode )
    {
      *piDir = -1;
      return i;
    }
  }
  v13 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence);
  CStudioHdr::pszNodeName(this: pstudiohdr, iNode: v13);
  CStudioHdr::pszNodeName(this: pstudiohdr, iNode: v10);
  _DevMsg(a1: 2, a2: "error in transition graph: %s to %s\n");
  return iGoalSequence;
}

//------------------------------------------------------------------------------
// Address: 0x100092B0
// Name: void SetBodygroup(class CStudioHdr __near *,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetBodygroup(CStudioHdr *pstudiohdr, int *body, int iGroup, int iValue)
{
  const studiohdr_t *m_pStudioHdr; // edx
  int v5; // eax
  int v6; // ebx

  if ( pstudiohdr != nullptr )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( iGroup < pstudiohdr->m_pStudioHdr->numbodyparts )
    {
      v5 = 16 * iGroup + m_pStudioHdr->bodypartindex;
      v6 = *(int *)((char *)&m_pStudioHdr->version + v5);
      if ( iValue < v6 )
        *body += *(int *)((char *)&m_pStudioHdr->checksum + v5)
               * (iValue - *body / *(int *)((char *)&m_pStudioHdr->checksum + v5) % v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009310
// Name: int FindBodygroupByName(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindBodygroupByName(CStudioHdr *pstudiohdr, const char *name)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v4; // edi
  int i; // esi

  if ( pstudiohdr == nullptr )
    return -1;
  m_pStudioHdr = pstudiohdr->m_pStudioHdr;
  v4 = 0;
  if ( pstudiohdr->m_pStudioHdr->numbodyparts <= 0 )
    return -1;
  for ( i = 0;
        V_strcasecmp(
          s1: name,
          s2: (const char *)m_pStudioHdr
        + i
        + m_pStudioHdr->bodypartindex
        + *(int *)((char *)&m_pStudioHdr->id + i + m_pStudioHdr->bodypartindex)) != 0;
        i += 16 )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( ++v4 >= pstudiohdr->m_pStudioHdr->numbodyparts )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10009370
// Name: int GetBodygroupCount(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetBodygroupCount(CStudioHdr *pstudiohdr, int iGroup)
{
  if ( pstudiohdr != nullptr && iGroup < pstudiohdr->m_pStudioHdr->numbodyparts )
    return *(int *)((char *)&pstudiohdr->m_pStudioHdr->version + 16 * iGroup + pstudiohdr->m_pStudioHdr->bodypartindex);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100093A0
// Name: int FindHitboxSetByName(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindHitboxSetByName(CStudioHdr *pstudiohdr, const char *name)
{
  const studiohdr_t *m_pStudioHdr; // eax
  int v4; // esi
  int i; // edi
  const char *v6; // ecx

  if ( pstudiohdr == nullptr )
    return -1;
  m_pStudioHdr = pstudiohdr->m_pStudioHdr;
  v4 = 0;
  if ( pstudiohdr->m_pStudioHdr->numhitboxsets <= 0 )
    return -1;
  for ( i = 0; ; i += 12 )
  {
    v6 = (char *)m_pStudioHdr + i + m_pStudioHdr->hitboxsetindex;
    if ( v6 != nullptr && _V_stricmp(s1: &v6[*(_DWORD *)v6], s2: name) == 0 )
      break;
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( ++v4 >= pstudiohdr->m_pStudioHdr->numhitboxsets )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10009400
// Name: void GetSequenceLinearMotion(class CStudioHdr __near *,int,float const __near * const,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSequenceLinearMotion(CStudioHdr *pstudiohdr, int iSequence, const float *poseParameter, Vector *pVec)
{
  int v4; // eax
  int NumSeq_Internal; // eax
  int numlocalseq; // edi
  char *v7; // eax
  QAngle vecAngles; // [esp+1Ch] [ebp-Ch] BYREF

  if ( pstudiohdr != nullptr )
  {
    if ( CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    {
      if ( iSequence < 0
        || (pstudiohdr->m_pVModel != nullptr
          ? (v4 = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
          : (v4 = pstudiohdr->m_pStudioHdr->numlocalseq),
            iSequence >= v4) )
      {
        if ( pstudiohdr->m_pVModel != nullptr )
          NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr);
        else
          NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq;
        if ( NumSeq_Internal > 0 && ++msgCount < 10 )
        {
          do
          {
            if ( pstudiohdr->m_pVModel != nullptr )
              numlocalseq = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr);
            else
              numlocalseq = pstudiohdr->m_pStudioHdr->numlocalseq;
            v7 = CStudioHdr::name(this: pstudiohdr);
            _Msg(
              a1: "Bad sequence (%i out of %i max) in GetSequenceLinearMotion() for model '%s'!\n",
              iSequence,
              numlocalseq,
              v7);
            ++msgCount;
          }
          while ( msgCount < 10 );
        }
        pVec->x = 0.0;
        pVec->y = 0.0;
        pVec->z = 0.0;
      }
      else
      {
        Studio_SeqMovement(
          pStudioHdr: pstudiohdr,
          iSequence,
          flCycleFrom: 0.0,
          flCycleTo: 1.0,
          poseParameter,
          deltaPos: pVec,
          deltaAngles: &vecAngles);
      }
    }
  }
  else
  {
    _Msg(a1: "Bad pstudiohdr in GetSequenceLinearMotion()!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009520
// Name: char const __near * GetSequenceName(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSequenceName(CStudioHdr *pstudiohdr, int iSequence)
{
  int NumSeq_Internal; // eax
  int v3; // eax
  char *v4; // ecx
  mstudioseqdesc_t *v6; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v9; // ecx
  char *v10; // eax
  int v11; // ecx
  const char *name; // eax

  if ( pstudiohdr == nullptr )
    return "Unknown";
  if ( iSequence < 0
    || (pstudiohdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
      : (NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq),
        iSequence >= NumSeq_Internal) )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    studiohdr2index = pstudiohdr->m_pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v9 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v10 = (char *)m_pStudioHdr + studiohdr2index,
                                                                    v9 != 0)
      && &v10[v9] != nullptr )
    {
      v11 = *((_DWORD *)v10 + 5);
      if ( v11 != 0 )
        name = &v10[v11];
      else
        name = nullptr;
    }
    else
    {
      name = m_pStudioHdr->name;
    }
    _Msg(a1: "Bad sequence in GetSequenceName() for model '%s'!\n", name);
    return "Unknown";
  }
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v6 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: iSequence);
    return (char *)v6 + v6->szlabelindex;
  }
  else
  {
    v3 = iSequence;
    if ( iSequence >= pstudiohdr->m_pStudioHdr->numlocalseq )
      v3 = 0;
    v4 = (char *)pstudiohdr->m_pStudioHdr + 212 * v3 + pstudiohdr->m_pStudioHdr->localseqindex;
    return &v4[*((_DWORD *)v4 + 1)];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100095E0
// Name: char const __near * GetSequenceActivityName(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSequenceActivityName(CStudioHdr *pstudiohdr, int iSequence)
{
  int NumSeq_Internal; // eax
  int v3; // eax
  char *v4; // ecx
  mstudioseqdesc_t *v6; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v9; // ecx
  char *v10; // eax
  int v11; // ecx
  const char *name; // eax

  if ( pstudiohdr == nullptr )
    return "Unknown";
  if ( iSequence < 0
    || (pstudiohdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
      : (NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq),
        iSequence >= NumSeq_Internal) )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    studiohdr2index = pstudiohdr->m_pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v9 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v10 = (char *)m_pStudioHdr + studiohdr2index,
                                                                    v9 != 0)
      && &v10[v9] != nullptr )
    {
      v11 = *((_DWORD *)v10 + 5);
      if ( v11 != 0 )
        name = &v10[v11];
      else
        name = nullptr;
    }
    else
    {
      name = m_pStudioHdr->name;
    }
    _Msg(a1: "Bad sequence in GetSequenceActivityName() for model '%s'!\n", name);
    return "Unknown";
  }
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v6 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: iSequence);
    return (char *)v6 + v6->szactivitynameindex;
  }
  else
  {
    v3 = iSequence;
    if ( iSequence >= pstudiohdr->m_pStudioHdr->numlocalseq )
      v3 = 0;
    v4 = (char *)pstudiohdr->m_pStudioHdr + 212 * v3 + pstudiohdr->m_pStudioHdr->localseqindex;
    return &v4[*((_DWORD *)v4 + 2)];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009710
// Name: void SetActivityForSequence(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetActivityForSequence(CStudioHdr *pstudiohdr, int i)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v3; // eax
  mstudioseqdesc_t *v4; // esi
  const char *SequenceActivityName; // eax
  int v6; // eax

  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v4 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i);
  }
  else
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    v3 = i;
    if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
      v3 = 0;
    v4 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v3 + m_pStudioHdr->localseqindex);
  }
  v4->flags |= 0x1000u;
  SequenceActivityName = GetSequenceActivityName(pstudiohdr, iSequence: i);
  if ( *SequenceActivityName != 0 )
  {
    v6 = ActivityList_IndexForName(pszActivityName: SequenceActivityName);
    if ( v6 == -1 )
      v4->flags &= ~0x1000u;
    else
      v4->activity = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009790
// Name: void IndexModelSequences(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IndexModelSequences(CStudioHdr *pstudiohdr)
{
  int v1; // esi
  int v2; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v4; // eax
  mstudioseqdesc_t *v5; // eax

  if ( pstudiohdr != nullptr && CStudioHdr::SequencesAvailable(this: pstudiohdr) )
  {
    v1 = 0;
    while ( 1 )
    {
      v2 = pstudiohdr->m_pVModel != nullptr
         ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
         : pstudiohdr->m_pStudioHdr->numlocalseq;
      if ( v1 >= v2 )
        break;
      SetActivityForSequence(pstudiohdr, i: v1);
      if ( pstudiohdr->m_pVModel != nullptr )
      {
        v5 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: v1);
        SetEventIndexForSequence(seqdesc: v5);
        ++v1;
      }
      else
      {
        m_pStudioHdr = pstudiohdr->m_pStudioHdr;
        v4 = v1;
        if ( v1 < 0 || v1 >= m_pStudioHdr->numlocalseq )
          v4 = 0;
        SetEventIndexForSequence(seqdesc: (mstudioseqdesc_t *)((char *)m_pStudioHdr
                                                             + 212 * v4
                                                             + m_pStudioHdr->localseqindex));
        ++v1;
      }
    }
    CStudioHdr::SetActivityListVersion(this: pstudiohdr, version: g_nActivityListVersion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009830
// Name: int GetSequenceActivity(class CStudioHdr __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSequenceActivity(CStudioHdr *pstudiohdr, int sequence, int *pweight)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v4; // eax
  mstudioseqdesc_t *v5; // ebx

  if ( pstudiohdr != nullptr && CStudioHdr::SequencesAvailable(this: pstudiohdr) )
  {
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v5 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: sequence);
    }
    else
    {
      m_pStudioHdr = pstudiohdr->m_pStudioHdr;
      v4 = sequence;
      if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
        v4 = 0;
      v5 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v4 + m_pStudioHdr->localseqindex);
    }
    if ( (v5->flags & 0x1000) == 0 )
      SetActivityForSequence(pstudiohdr, i: sequence);
    if ( pweight != nullptr )
      *pweight = v5->actweight;
    return v5->activity;
  }
  else
  {
    if ( pweight != nullptr )
      *pweight = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009900
// Name: private: int CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(class CStudioHdr __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(
        CStudioHdr::CActivityToSequenceMapping *this,
        CStudioHdr *pstudiohdr,
        int activity,
        int curSequence)
{
  int v5; // eax
  mstudioseqdesc_t *v6; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // esi
  IUniformRandomStream *v12; // ecx
  _DWORD *v13; // esi
  int v14; // eax
  const char *v15; // eax
  int v16; // eax
  IUniformRandomStream *v17; // eax
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *v18; // ecx
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *v19; // esi
  int i; // edx
  int v21; // [esp-8h] [ebp-24h]
  int v22; // [esp-4h] [ebp-20h]
  CStudioHdr::CActivityToSequenceMapping::HashValueType dummy; // [esp+Ch] [ebp-10h] BYREF

  if ( curSequence >= 0 )
  {
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v6 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: curSequence);
    }
    else
    {
      v5 = curSequence;
      if ( curSequence >= pstudiohdr->m_pStudioHdr->numlocalseq )
        v5 = 0;
      v6 = (mstudioseqdesc_t *)((char *)pstudiohdr->m_pStudioHdr + 212 * v5 + pstudiohdr->m_pStudioHdr->localseqindex);
    }
    if ( v6->activity == activity && v6->actweight < 0 )
      return curSequence;
  }
  if ( !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return -1;
  v8 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( v8 == 1 )
    return -1;
  if ( !CStudioHdr::CActivityToSequenceMapping::ValidateAgainst(this, pstudiohdr) )
  {
    if ( _executeCount < 1 )
    {
      ++_executeCount;
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        __debugbreak();
    }
    CStudioHdr::CActivityToSequenceMapping::Reinitialize(this, pstudiohdr);
  }
  if ( this->m_pSequenceTuples == nullptr )
    return -1;
  memset(&dummy.startingIdx, 0, 12);
  dummy.activityIdx = activity;
  v9 = CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::Find(
         this: &this->m_ActToSeqHash,
         src: (unsigned int)&dummy);
  v10 = HIWORD(v9);
  if ( (signed int)HIWORD(v9) >= this->m_ActToSeqHash.m_Buckets.m_Size )
    return -1;
  m_pMemory = this->m_ActToSeqHash.m_Buckets.m_Memory.m_pMemory;
  if ( (unsigned __int16)v9 >= m_pMemory[v10].m_Size )
    return -1;
  v12 = (IUniformRandomStream *)(5 * v10);
  v13 = (_DWORD *)(*((_DWORD *)&m_pMemory->m_Memory.m_pMemory + (_DWORD)v12) + 16 * (unsigned __int16)v9);
  v14 = v13[3];
  if ( v14 > 0 )
  {
    if ( v14 == 1 )
    {
      v16 = 0;
    }
    else
    {
      v17 = (IUniformRandomStream *)(v14 - 1);
      if ( C_BaseEntity::m_pPredictionPlayer != nullptr )
        v16 = SharedRandomInt(sharedname: "SelectWeightedSequence", iMinVal: 0, iMaxVal: v17, additionalSeed: 0);
      else
        v16 = _RandomInt(this: v12, a2: 0, a3: (int)v17);
    }
    v18 = &this->m_pSequenceTuples[v13[1]];
    v19 = &v18[v13[2]];
    for ( i = v18->weight; v16 >= i; i = v18->weight )
    {
      if ( v18 >= v19 )
        break;
      ++v18;
      v16 -= i;
    }
    return v18->seqnum;
  }
  else
  {
    v22 = v13[3];
    v21 = v13[2];
    v15 = ActivityList_NameForIndex(activityIndex: activity);
    _Warning(a1: "Activity %s has %d sequences with a total weight of %d!", v15, v21, v22);
    return this->m_pSequenceTuples[v13[1]].seqnum;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009AC0
// Name: int SelectWeightedSequence(class CStudioHdr __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SelectWeightedSequence(CStudioHdr *pstudiohdr, int activity, int curSequence)
{
  int NumSeq_Internal; // eax
  mstudioseqdesc_t *v5; // edi

  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    counter.m_pCounter = CVProfile::FindOrCreateCounter(
                           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                           a2: "Client SelectWeightedSequence",
                           a3: COUNTER_GROUP_DEFAULT);
    atexit(func: SelectWeightedSequence_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter.m_pCounter;
  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  if ( CStudioHdr::GetActivityListVersion(this: pstudiohdr) < g_nActivityListVersion )
    IndexModelSequences(pstudiohdr);
  if ( pstudiohdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr);
  else
    NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( NumSeq_Internal == 1 )
  {
    if ( CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    {
      if ( pstudiohdr->m_pVModel != nullptr )
        v5 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: 0);
      else
        v5 = (mstudioseqdesc_t *)((char *)pstudiohdr->m_pStudioHdr + pstudiohdr->m_pStudioHdr->localseqindex);
      if ( (v5->flags & 0x1000) == 0 )
        SetActivityForSequence(pstudiohdr, i: 0);
      return -(v5->activity != activity);
    }
    else
    {
      return -(activity != 0);
    }
  }
  else
  {
    if ( pstudiohdr->m_pActivityToSequence == nullptr )
      pstudiohdr->m_pActivityToSequence = CStudioHdr::CActivityToSequenceMapping::FindMapping(pHdr: pstudiohdr);
    return CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(
             this: pstudiohdr->m_pActivityToSequence,
             pstudiohdr,
             activity,
             curSequence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009BD0
// Name: int LookupSequence(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LookupSequence(CStudioHdr *pstudiohdr, const char *label)
{
  int i; // edi
  int v4; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // eax
  mstudioseqdesc_t *v7; // eax
  int v8; // eax

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  for ( i = 0; ; ++i )
  {
    v4 = pstudiohdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
       : pstudiohdr->m_pStudioHdr->numlocalseq;
    if ( i >= v4 )
      break;
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v7 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i);
    }
    else
    {
      m_pStudioHdr = pstudiohdr->m_pStudioHdr;
      v6 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v6 = 0;
      v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v6 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v7 + v7->szlabelindex, s2: label) == 0 )
      return i;
  }
  v8 = LookupActivity(pstudiohdr, label);
  if ( v8 == -1 )
    return -1;
  else
    return SelectWeightedSequence(pstudiohdr, activity: v8, curSequence: -1);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10092E90
// Name: void ResetEventIndexes(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetEventIndexes(CStudioHdr *pstudiohdr)
{
  if ( pstudiohdr != nullptr )
    CStudioHdr::SetEventListVersion(this: pstudiohdr, version: g_nEventListVersion - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10092EB0
// Name: void ResetActivityIndexes(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResetActivityIndexes(CStudioHdr *pstudiohdr)
{
  if ( pstudiohdr != nullptr )
    CStudioHdr::SetActivityListVersion(this: pstudiohdr, version: g_nActivityListVersion - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10092ED0
// Name: void GetAttachmentLocalSpace(class CStudioHdr __near *,int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetAttachmentLocalSpace(CStudioHdr *pstudiohdr, int attachIndex, matrix3x4_t *pLocalToWorld)
{
  const mstudioattachment_t *v3; // eax

  if ( attachIndex >= 0 )
  {
    v3 = CStudioHdr::pAttachment(this: pstudiohdr, i: attachIndex);
    MatrixCopy(in: &v3->local, out: pLocalToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092F00
// Name: public: struct mstudioseqdesc_t __near & CStudioHdr::pSeqdesc(int)
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall CStudioHdr::pSeqdesc(CStudioHdr *this, int iSequence)
{
  int v2; // eax
  const studiohdr_t *m_pStudioHdr; // ecx

  if ( this->m_pVModel != nullptr )
    return CStudioHdr::pSeqdesc_Internal(this, i: iSequence);
  v2 = iSequence;
  m_pStudioHdr = this->m_pStudioHdr;
  if ( iSequence < 0 || iSequence >= m_pStudioHdr->numlocalseq )
    v2 = 0;
  return (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v2 + m_pStudioHdr->localseqindex);
}

//------------------------------------------------------------------------------
// Address: 0x10092F40
// Name: public: void animevent_t::Event(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall animevent_t::Event(animevent_t *this, int nEvent)
{
  if ( (this->type & 0x400) != 0 )
    this->_event_lowword = nEvent;
  else
    *(_DWORD *)&this->_event_highword = nEvent;
}

//------------------------------------------------------------------------------
// Address: 0x10092F70
// Name: int ExtractBbox(class CStudioHdr __near *,int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ExtractBbox(CStudioHdr *pstudiohdr, int sequence, Vector *mins, Vector *maxs)
{
  int v5; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  mstudioseqdesc_t *v7; // eax

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  v5 = sequence;
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v7 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: sequence);
  }
  else
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
      v5 = 0;
    v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v5 + m_pStudioHdr->localseqindex);
  }
  *mins = v7->bbmin;
  *maxs = v7->bbmax;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092FF0
// Name: void SetEventIndexForSequence(struct mstudioseqdesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetEventIndexForSequence(mstudioseqdesc_t *seqdesc)
{
  int numevents; // eax
  char *v3; // esi
  const char *v4; // edi
  int v5; // eax
  int index; // [esp+4h] [ebp-4h]
  mstudioseqdesc_t *seqdesca; // [esp+10h] [ebp+8h]

  if ( seqdesc != nullptr )
  {
    numevents = seqdesc->numevents;
    if ( numevents != 0 )
    {
      seqdesc->flags |= 0x2000u;
      index = 0;
      if ( numevents > 0 )
      {
        seqdesca = nullptr;
        do
        {
          v3 = (char *)seqdesca + seqdesc->eventindex + (_DWORD)seqdesc;
          if ( v3 != nullptr && (*((_DWORD *)v3 + 2) & 0x400) != 0 )
          {
            v4 = &v3[*((_DWORD *)v3 + 19)];
            v5 = EventList_IndexForName(pszEventName: v4);
            if ( v5 == -1 )
            {
              *((_WORD *)v3 + 3) = EventList_RegisterPrivateEvent(pszEventName: v4);
            }
            else
            {
              *((_WORD *)v3 + 3) = v5;
              *((_DWORD *)v3 + 2) |= EventList_GetEventType(eventIndex: v5);
            }
          }
          seqdesca = (mstudioseqdesc_t *)((char *)seqdesca + 80);
          ++index;
        }
        while ( index < seqdesc->numevents );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093080
// Name: struct mstudioevent_for_client_server_t __near * GetEventIndexForSequence(struct mstudioseqdesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
mstudioevent_for_client_server_t *__cdecl GetEventIndexForSequence(mstudioseqdesc_t *seqdesc)
{
  if ( (seqdesc->flags & 0x2000) == 0 )
    SetEventIndexForSequence(seqdesc);
  return (mstudioevent_for_client_server_t *)((char *)seqdesc + seqdesc->eventindex);
}

//------------------------------------------------------------------------------
// Address: 0x100930B0
// Name: void GetEyePosition(class CStudioHdr __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetEyePosition(CStudioHdr *pstudiohdr, Vector *vecEyePosition)
{
  float z; // [esp+8h] [ebp-4h]

  if ( pstudiohdr != nullptr )
  {
    z = pstudiohdr->m_pStudioHdr->eyeposition.z;
    *(_QWORD *)&vecEyePosition->x = *(_QWORD *)&pstudiohdr->m_pStudioHdr->eyeposition.x;
    vecEyePosition->z = z;
  }
  else
  {
    _Warning(a1: "GetEyePosition() Can't get pstudiohdr ptr!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093110
// Name: int LookupActivity(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LookupActivity(CStudioHdr *pstudiohdr, const char *label)
{
  int i; // edi
  int v4; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // eax
  mstudioseqdesc_t *v7; // esi

  if ( pstudiohdr == nullptr )
    return 0;
  for ( i = 0; ; ++i )
  {
    v4 = pstudiohdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
       : pstudiohdr->m_pStudioHdr->numlocalseq;
    if ( i >= v4 )
      break;
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v7 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i);
    }
    else
    {
      m_pStudioHdr = pstudiohdr->m_pStudioHdr;
      v6 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v6 = 0;
      v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v6 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v7 + v7->szactivitynameindex, s2: label) == 0 )
      return v7->activity;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100931A0
// Name: int GetSequenceFlags(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSequenceFlags(CStudioHdr *pstudiohdr, int sequence)
{
  int NumSeq_Internal; // eax

  if ( pstudiohdr != nullptr
    && CStudioHdr::SequencesAvailable(this: pstudiohdr)
    && sequence >= 0
    && (pstudiohdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
      : (NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq),
        sequence < NumSeq_Internal) )
  {
    return CStudioHdr::pSeqdesc(this: pstudiohdr, iSequence: sequence)->flags;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100931F0
// Name: int GetAnimationEvent(class CStudioHdr __near *,int,struct animevent_t __near *,float,float,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAnimationEvent(
        CStudioHdr *pstudiohdr,
        int sequence,
        animevent_t *pNPCEvent,
        float flStart,
        float flEnd,
        int index)
{
  int v6; // ecx
  int v7; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  mstudioseqdesc_t *v9; // ebx
  int numevents; // eax
  int v11; // esi
  mstudioevent_for_client_server_t *EventIndexForSequence; // eax
  int v13; // edi
  mstudioevent_for_client_server_t *i; // ecx
  int type; // edx
  float cycle; // xmm0_4
  mstudioevent_for_client_server_t *v18; // edi
  int event_lowword; // eax

  if ( pstudiohdr == nullptr )
    return 0;
  v6 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  v7 = sequence;
  if ( sequence >= v6 || pNPCEvent == nullptr )
    return 0;
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v9 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: sequence);
  }
  else
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
      v7 = 0;
    v9 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v7 + m_pStudioHdr->localseqindex);
  }
  numevents = v9->numevents;
  if ( numevents == 0 )
    return 0;
  v11 = index;
  if ( index >= numevents )
    return 0;
  EventIndexForSequence = GetEventIndexForSequence(seqdesc: v9);
  v13 = v9->numevents;
  if ( index >= v13 )
    return 0;
  for ( i = &EventIndexForSequence[index]; ; ++i )
  {
    type = i->type;
    if ( (type & 0x400) == 0 )
      break;
    if ( (type & 1) != 0 )
      goto LABEL_21;
LABEL_27:
    if ( ++v11 >= v13 )
      return 0;
  }
  if ( *(int *)&i->_event_highword >= 5000 )
    goto LABEL_27;
LABEL_21:
  cycle = i->cycle;
  if ( (i->cycle < flStart || flEnd <= cycle)
    && ((v9->flags & 1) == 0 || flStart <= flEnd || cycle < flStart && flEnd <= cycle) )
  {
    goto LABEL_27;
  }
  pNPCEvent->pSource = nullptr;
  v18 = &EventIndexForSequence[v11];
  pNPCEvent->cycle = v18->cycle;
  pNPCEvent->eventtime = gpGlobals->curtime;
  pNPCEvent->type = v18->type;
  if ( (v18->type & 0x400) != 0 )
    event_lowword = v18->_event_lowword;
  else
    event_lowword = *(_DWORD *)&v18->_event_highword;
  animevent_t::Event(this: pNPCEvent, nEvent: event_lowword);
  pNPCEvent->options = v18->options;
  return v11 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10093350
// Name: int FindTransitionSequence(class CStudioHdr __near *,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindTransitionSequence(CStudioHdr *pstudiohdr, int iCurrentSequence, int iGoalSequence, int *piDir)
{
  int v6; // eax
  int i; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  const char *v15; // [esp-Ch] [ebp-14h]
  mstudioseqdesc_t *seqdesc; // [esp+4h] [ebp-4h]
  int iInternNode; // [esp+10h] [ebp+8h]

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return iGoalSequence;
  if ( iCurrentSequence < 0 )
    return iGoalSequence;
  v6 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( iCurrentSequence >= v6 )
    return iGoalSequence;
  i = iGoalSequence;
  if ( iGoalSequence < 0 )
    return i;
  v8 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( iGoalSequence >= v8 )
    return i;
  if ( CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence) == 0
    || CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence) == 0 )
  {
    *piDir = 1;
    return iGoalSequence;
  }
  if ( *piDir <= 0 )
    v9 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence);
  else
    v9 = CStudioHdr::ExitNode(this: pstudiohdr, iSequence: iCurrentSequence);
  v10 = v9;
  if ( v9 == CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence) )
  {
LABEL_32:
    *piDir = 1;
    return i;
  }
  v11 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence);
  iInternNode = CStudioHdr::GetTransition(this: pstudiohdr, iFrom: v10, iTo: v11);
  if ( iInternNode == 0 )
    return i;
  for ( i = 0; ; ++i )
  {
    v12 = pstudiohdr->m_pVModel != nullptr
        ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
        : pstudiohdr->m_pStudioHdr->numlocalseq;
    if ( i >= v12 )
      break;
    seqdesc = CStudioHdr::pSeqdesc(this: pstudiohdr, iSequence: i);
    if ( CStudioHdr::EntryNode(this: pstudiohdr, iSequence: i) == v10
      && CStudioHdr::ExitNode(this: pstudiohdr, iSequence: i) == iInternNode )
    {
      goto LABEL_32;
    }
    if ( seqdesc->nodeflags != 0
      && CStudioHdr::ExitNode(this: pstudiohdr, iSequence: i) == v10
      && CStudioHdr::EntryNode(this: pstudiohdr, iSequence: i) == iInternNode )
    {
      *piDir = -1;
      return i;
    }
  }
  v13 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence);
  v15 = CStudioHdr::pszNodeName(this: pstudiohdr, iNode: v13);
  v14 = CStudioHdr::pszNodeName(this: pstudiohdr, iNode: v10);
  _DevMsg(a1: 2, a2: "error in transition graph: %s to %s\n", v14, v15);
  return iGoalSequence;
}

//------------------------------------------------------------------------------
// Address: 0x10093500
// Name: bool GotoSequence(class CStudioHdr __near *,int,float,float,int,int __near &,float __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GotoSequence(
        CStudioHdr *pstudiohdr,
        int iCurrentSequence,
        float flCurrentCycle,
        float flCurrentRate,
        int iGoalSequence,
        int *nNextSequence,
        float *flNextCycle,
        int *iNextDir)
{
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int i; // edi
  int v16; // eax
  int v17; // eax
  const char *v18; // eax
  const char *v19; // [esp-Ch] [ebp-14h]
  mstudioseqdesc_t *seqdesc; // [esp+4h] [ebp-4h]
  int iInternNodea; // [esp+10h] [ebp+8h]
  int iInternNode; // [esp+10h] [ebp+8h]

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  if ( iCurrentSequence < 0 )
    return 0;
  v10 = pstudiohdr->m_pVModel != nullptr
      ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
      : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( iCurrentSequence >= v10 )
    return 0;
  if ( iGoalSequence < 0 )
    return 0;
  v11 = pstudiohdr->m_pVModel != nullptr
      ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
      : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( iGoalSequence >= v11 )
    return 0;
  if ( CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence) != 0
    && CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence) != 0 )
  {
    v12 = CStudioHdr::ExitNode(this: pstudiohdr, iSequence: iCurrentSequence);
    iInternNodea = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence);
    if ( iInternNodea == CStudioHdr::ExitNode(this: pstudiohdr, iSequence: iCurrentSequence) )
      goto LABEL_24;
    if ( flCurrentRate > 0.0 && flCurrentCycle >= 0.999 )
    {
      v13 = CStudioHdr::ExitNode(this: pstudiohdr, iSequence: iCurrentSequence);
LABEL_23:
      v12 = v13;
LABEL_24:
      if ( v12 == CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence)
        || (v14 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence),
            (iInternNode = CStudioHdr::GetTransition(this: pstudiohdr, iFrom: v12, iTo: v14)) == 0) )
      {
        *iNextDir = 1;
        *flNextCycle = 0.0;
        *nNextSequence = iGoalSequence;
        return 1;
      }
      for ( i = 0; ; ++i )
      {
        v16 = pstudiohdr->m_pVModel != nullptr
            ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
            : pstudiohdr->m_pStudioHdr->numlocalseq;
        if ( i >= v16 )
          break;
        seqdesc = CStudioHdr::pSeqdesc(this: pstudiohdr, iSequence: i);
        if ( CStudioHdr::EntryNode(this: pstudiohdr, iSequence: i) == v12
          && CStudioHdr::ExitNode(this: pstudiohdr, iSequence: i) == iInternNode )
        {
          *iNextDir = 1;
          *flNextCycle = 0.0;
          *nNextSequence = i;
          return 1;
        }
        if ( seqdesc->nodeflags != 0
          && CStudioHdr::ExitNode(this: pstudiohdr, iSequence: i) == v12
          && CStudioHdr::EntryNode(this: pstudiohdr, iSequence: i) == iInternNode )
        {
          *iNextDir = -1;
          *flNextCycle = 0.99900001;
          *nNextSequence = i;
          return 1;
        }
      }
      v17 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iGoalSequence);
      v19 = CStudioHdr::pszNodeName(this: pstudiohdr, iNode: v17);
      v18 = CStudioHdr::pszNodeName(this: pstudiohdr, iNode: v12);
      _DevMsg(a1: 2, a2: "error in transition graph: %s to %s\n", v18, v19);
      return 0;
    }
    if ( flCurrentRate < 0.0 && flCurrentCycle <= 0.001 )
    {
      v13 = CStudioHdr::EntryNode(this: pstudiohdr, iSequence: iCurrentSequence);
      goto LABEL_23;
    }
    return 0;
  }
  *iNextDir = 1;
  *flNextCycle = 0.0;
  *nNextSequence = iGoalSequence;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10093770
// Name: void SetBodygroup(class CStudioHdr __near *,int __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetBodygroup(CStudioHdr *pstudiohdr, int *body, int iGroup, int iValue)
{
  const studiohdr_t *m_pStudioHdr; // edx
  int v5; // eax
  int v6; // ebx

  if ( pstudiohdr != nullptr )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( iGroup < pstudiohdr->m_pStudioHdr->numbodyparts )
    {
      v5 = 16 * iGroup + m_pStudioHdr->bodypartindex;
      v6 = *(int *)((char *)&m_pStudioHdr->version + v5);
      if ( iValue < v6 )
        *body += *(int *)((char *)&m_pStudioHdr->checksum + v5)
               * (iValue - *body / *(int *)((char *)&m_pStudioHdr->checksum + v5) % v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100937D0
// Name: int FindHitboxSetByName(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindHitboxSetByName(CStudioHdr *pstudiohdr, const char *name)
{
  const studiohdr_t *m_pStudioHdr; // eax
  int v4; // esi
  int i; // edi
  const char *v6; // ecx

  if ( pstudiohdr == nullptr )
    return -1;
  m_pStudioHdr = pstudiohdr->m_pStudioHdr;
  v4 = 0;
  if ( pstudiohdr->m_pStudioHdr->numhitboxsets <= 0 )
    return -1;
  for ( i = 0; ; i += 12 )
  {
    v6 = (char *)m_pStudioHdr + i + m_pStudioHdr->hitboxsetindex;
    if ( v6 != nullptr && _V_stricmp(s1: &v6[*(_DWORD *)v6], s2: name) == 0 )
      break;
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    if ( ++v4 >= pstudiohdr->m_pStudioHdr->numhitboxsets )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10093830
// Name: void GetSequenceLinearMotion(class CStudioHdr __near *,int,float const __near * const,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSequenceLinearMotion(CStudioHdr *pstudiohdr, int iSequence, const float *poseParameter, Vector *pVec)
{
  int v4; // eax
  int NumSeq_Internal; // eax
  int numlocalseq; // edi
  char *v7; // eax
  QAngle vecAngles; // [esp+1Ch] [ebp-Ch] BYREF

  if ( pstudiohdr != nullptr )
  {
    if ( CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    {
      if ( iSequence < 0
        || (pstudiohdr->m_pVModel != nullptr
          ? (v4 = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
          : (v4 = pstudiohdr->m_pStudioHdr->numlocalseq),
            iSequence >= v4) )
      {
        if ( pstudiohdr->m_pVModel != nullptr )
          NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr);
        else
          NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq;
        if ( NumSeq_Internal > 0 && ++msgCount < 10 )
        {
          do
          {
            if ( pstudiohdr->m_pVModel != nullptr )
              numlocalseq = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr);
            else
              numlocalseq = pstudiohdr->m_pStudioHdr->numlocalseq;
            v7 = CStudioHdr::name(this: pstudiohdr);
            _Msg(
              a1: "Bad sequence (%i out of %i max) in GetSequenceLinearMotion() for model '%s'!\n",
              iSequence,
              numlocalseq,
              v7);
            ++msgCount;
          }
          while ( msgCount < 10 );
        }
        pVec->x = 0.0;
        pVec->y = 0.0;
        pVec->z = 0.0;
      }
      else
      {
        Studio_SeqMovement(
          pStudioHdr: pstudiohdr,
          iSequence,
          flCycleFrom: 0.0,
          flCycleTo: 1.0,
          poseParameter,
          deltaPos: pVec,
          deltaAngles: &vecAngles);
      }
    }
  }
  else
  {
    _Msg(a1: "Bad pstudiohdr in GetSequenceLinearMotion()!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093950
// Name: char const __near * GetSequenceName(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSequenceName(CStudioHdr *pstudiohdr, int iSequence)
{
  int NumSeq_Internal; // eax
  int v3; // eax
  char *v4; // ecx
  mstudioseqdesc_t *v6; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v9; // ecx
  char *v10; // eax
  int v11; // ecx
  const char *name; // eax

  if ( pstudiohdr == nullptr )
    return "Unknown";
  if ( iSequence < 0
    || (pstudiohdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
      : (NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq),
        iSequence >= NumSeq_Internal) )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    studiohdr2index = pstudiohdr->m_pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v9 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v10 = (char *)m_pStudioHdr + studiohdr2index,
                                                                    v9 != 0)
      && &v10[v9] != nullptr )
    {
      v11 = *((_DWORD *)v10 + 5);
      if ( v11 != 0 )
        name = &v10[v11];
      else
        name = nullptr;
    }
    else
    {
      name = m_pStudioHdr->name;
    }
    _Msg(a1: "Bad sequence in GetSequenceName() for model '%s'!\n", name);
    return "Unknown";
  }
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v6 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: iSequence);
    return (char *)v6 + v6->szlabelindex;
  }
  else
  {
    v3 = iSequence;
    if ( iSequence >= pstudiohdr->m_pStudioHdr->numlocalseq )
      v3 = 0;
    v4 = (char *)pstudiohdr->m_pStudioHdr + 212 * v3 + pstudiohdr->m_pStudioHdr->localseqindex;
    return &v4[*((_DWORD *)v4 + 1)];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093A10
// Name: char const __near * GetSequenceActivityName(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetSequenceActivityName(CStudioHdr *pstudiohdr, int iSequence)
{
  int NumSeq_Internal; // eax
  int v3; // eax
  char *v4; // ecx
  mstudioseqdesc_t *v6; // eax
  const studiohdr_t *m_pStudioHdr; // esi
  int studiohdr2index; // eax
  int v9; // ecx
  char *v10; // eax
  int v11; // ecx
  const char *name; // eax

  if ( pstudiohdr == nullptr )
    return "Unknown";
  if ( iSequence < 0
    || (pstudiohdr->m_pVModel != nullptr
      ? (NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr))
      : (NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq),
        iSequence >= NumSeq_Internal) )
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    studiohdr2index = pstudiohdr->m_pStudioHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v9 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v10 = (char *)m_pStudioHdr + studiohdr2index,
                                                                    v9 != 0)
      && &v10[v9] != nullptr )
    {
      v11 = *((_DWORD *)v10 + 5);
      if ( v11 != 0 )
        name = &v10[v11];
      else
        name = nullptr;
    }
    else
    {
      name = m_pStudioHdr->name;
    }
    _Msg(a1: "Bad sequence in GetSequenceActivityName() for model '%s'!\n", name);
    return "Unknown";
  }
  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v6 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: iSequence);
    return (char *)v6 + v6->szactivitynameindex;
  }
  else
  {
    v3 = iSequence;
    if ( iSequence >= pstudiohdr->m_pStudioHdr->numlocalseq )
      v3 = 0;
    v4 = (char *)pstudiohdr->m_pStudioHdr + 212 * v3 + pstudiohdr->m_pStudioHdr->localseqindex;
    return &v4[*((_DWORD *)v4 + 2)];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093B40
// Name: void SetActivityForSequence(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetActivityForSequence(CStudioHdr *pstudiohdr, int i)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v3; // eax
  mstudioseqdesc_t *v4; // esi
  char *SequenceActivityName; // eax
  const char *v6; // edi
  int v7; // eax

  if ( pstudiohdr->m_pVModel != nullptr )
  {
    v4 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i);
  }
  else
  {
    m_pStudioHdr = pstudiohdr->m_pStudioHdr;
    v3 = i;
    if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
      v3 = 0;
    v4 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v3 + m_pStudioHdr->localseqindex);
  }
  v4->flags |= 0x1000u;
  SequenceActivityName = GetSequenceActivityName(pstudiohdr, iSequence: i);
  v6 = SequenceActivityName;
  if ( *SequenceActivityName != 0 )
  {
    v7 = ActivityList_IndexForName(pszActivityName: SequenceActivityName);
    if ( v7 == -1 )
      v7 = ActivityList_RegisterPrivateActivity(pszActivityName: v6);
    v4->activity = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093BC0
// Name: void IndexModelSequences(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IndexModelSequences(CStudioHdr *pstudiohdr)
{
  int v1; // esi
  int v2; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v4; // eax
  mstudioseqdesc_t *v5; // eax

  if ( pstudiohdr != nullptr && CStudioHdr::SequencesAvailable(this: pstudiohdr) )
  {
    v1 = 0;
    while ( 1 )
    {
      v2 = pstudiohdr->m_pVModel != nullptr
         ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
         : pstudiohdr->m_pStudioHdr->numlocalseq;
      if ( v1 >= v2 )
        break;
      SetActivityForSequence(pstudiohdr, i: v1);
      if ( pstudiohdr->m_pVModel != nullptr )
      {
        v5 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: v1);
        SetEventIndexForSequence(seqdesc: v5);
        ++v1;
      }
      else
      {
        m_pStudioHdr = pstudiohdr->m_pStudioHdr;
        v4 = v1;
        if ( v1 < 0 || v1 >= m_pStudioHdr->numlocalseq )
          v4 = 0;
        SetEventIndexForSequence(seqdesc: (mstudioseqdesc_t *)((char *)m_pStudioHdr
                                                             + 212 * v4
                                                             + m_pStudioHdr->localseqindex));
        ++v1;
      }
    }
    CStudioHdr::SetActivityListVersion(this: pstudiohdr, version: g_nActivityListVersion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093C60
// Name: void VerifySequenceIndex(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifySequenceIndex(CStudioHdr *pstudiohdr)
{
  if ( pstudiohdr != nullptr && CStudioHdr::GetActivityListVersion(this: pstudiohdr) < g_nActivityListVersion )
    IndexModelSequences(pstudiohdr);
}

//------------------------------------------------------------------------------
// Address: 0x10093C90
// Name: int GetSequenceActivity(class CStudioHdr __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSequenceActivity(CStudioHdr *pstudiohdr, int sequence, int *pweight)
{
  const studiohdr_t *m_pStudioHdr; // ecx
  int v4; // eax
  mstudioseqdesc_t *v5; // ebx

  if ( pstudiohdr != nullptr && CStudioHdr::SequencesAvailable(this: pstudiohdr) )
  {
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v5 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: sequence);
    }
    else
    {
      m_pStudioHdr = pstudiohdr->m_pStudioHdr;
      v4 = sequence;
      if ( sequence < 0 || sequence >= m_pStudioHdr->numlocalseq )
        v4 = 0;
      v5 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v4 + m_pStudioHdr->localseqindex);
    }
    if ( (v5->flags & 0x1000) == 0 )
      SetActivityForSequence(pstudiohdr, i: sequence);
    if ( pweight != nullptr )
      *pweight = v5->actweight;
    return v5->activity;
  }
  else
  {
    if ( pweight != nullptr )
      *pweight = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093D60
// Name: private: int CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(class CStudioHdr __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(
        CStudioHdr::CActivityToSequenceMapping *this,
        CStudioHdr *pstudiohdr,
        int activity,
        int curSequence)
{
  int v5; // eax
  mstudioseqdesc_t *v6; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *m_pMemory; // esi
  IUniformRandomStream *v12; // ecx
  _DWORD *v13; // esi
  int v14; // eax
  const char *v15; // eax
  int v16; // eax
  int v17; // eax
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *v18; // ecx
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *v19; // esi
  int i; // edx
  int v21; // [esp-8h] [ebp-24h]
  int v22; // [esp-4h] [ebp-20h]
  CStudioHdr::CActivityToSequenceMapping::HashValueType dummy; // [esp+Ch] [ebp-10h] BYREF

  if ( curSequence >= 0 )
  {
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v6 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: curSequence);
    }
    else
    {
      v5 = curSequence;
      if ( curSequence >= pstudiohdr->m_pStudioHdr->numlocalseq )
        v5 = 0;
      v6 = (mstudioseqdesc_t *)((char *)pstudiohdr->m_pStudioHdr + 212 * v5 + pstudiohdr->m_pStudioHdr->localseqindex);
    }
    if ( v6->activity == activity && v6->actweight < 0 )
      return curSequence;
  }
  if ( !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return -1;
  v8 = pstudiohdr->m_pVModel != nullptr
     ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
     : pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( v8 == 1 )
    return -1;
  if ( !CStudioHdr::CActivityToSequenceMapping::ValidateAgainst(this, pstudiohdr) )
  {
    if ( _executeCount < 1 )
    {
      ++_executeCount;
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        __debugbreak();
    }
    CStudioHdr::CActivityToSequenceMapping::Reinitialize(this, pstudiohdr);
  }
  if ( this->m_pSequenceTuples == nullptr )
    return -1;
  memset(&dummy.startingIdx, 0, 12);
  dummy.activityIdx = activity;
  v9 = CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::Find(
         this: &this->m_ActToSeqHash,
         src: &dummy);
  v10 = HIWORD(v9);
  if ( (signed int)HIWORD(v9) >= this->m_ActToSeqHash.m_Buckets.m_Size )
    return -1;
  m_pMemory = this->m_ActToSeqHash.m_Buckets.m_Memory.m_pMemory;
  if ( (unsigned __int16)v9 >= m_pMemory[v10].m_Size )
    return -1;
  v12 = (IUniformRandomStream *)(5 * v10);
  v13 = (_DWORD *)(*((_DWORD *)&m_pMemory->m_Memory.m_pMemory + (_DWORD)v12) + 16 * (unsigned __int16)v9);
  v14 = v13[3];
  if ( v14 > 0 )
  {
    if ( v14 == 1 )
    {
      v16 = 0;
    }
    else
    {
      v17 = v14 - 1;
      if ( CBaseEntity::m_pPredictionPlayer != nullptr )
        v16 = SharedRandomInt(sharedname: "SelectWeightedSequence", iMinVal: 0, iMaxVal: v17, additionalSeed: 0);
      else
        v16 = _RandomInt(this: v12, a2: 0, a3: v17);
    }
    v18 = &this->m_pSequenceTuples[v13[1]];
    v19 = &v18[v13[2]];
    for ( i = v18->weight; v16 >= i; i = v18->weight )
    {
      if ( v18 >= v19 )
        break;
      ++v18;
      v16 -= i;
    }
    return v18->seqnum;
  }
  else
  {
    v22 = v13[3];
    v21 = v13[2];
    v15 = ActivityList_NameForIndex(activityIndex: activity);
    _Warning(a1: "Activity %s has %d sequences with a total weight of %d!", v15, v21, v22);
    return this->m_pSequenceTuples[v13[1]].seqnum;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093F20
// Name: int SelectHeaviestSequence(class CStudioHdr __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SelectHeaviestSequence(CStudioHdr *pstudiohdr, int activity)
{
  CStudioHdr *v2; // edi
  int v3; // esi
  signed int v5; // ebx
  int v6; // eax
  int SequenceActivity; // eax
  signed int v8; // eax
  int seq; // [esp+8h] [ebp-4h]

  v2 = pstudiohdr;
  v3 = 0;
  if ( pstudiohdr == nullptr )
    return 0;
  if ( CStudioHdr::GetActivityListVersion(this: pstudiohdr) < g_nActivityListVersion )
    IndexModelSequences(pstudiohdr: v2);
  v5 = 0;
  seq = -1;
  pstudiohdr = nullptr;
  while ( 1 )
  {
    v6 = v2->m_pVModel != nullptr ? CStudioHdr::GetNumSeq_Internal(this: v2) : v2->m_pStudioHdr->numlocalseq;
    if ( v3 >= v6 )
      break;
    SequenceActivity = GetSequenceActivity(pstudiohdr: v2, sequence: v3, pweight: (int *)&pstudiohdr);
    if ( SequenceActivity == activity )
    {
      v8 = abs32((int)pstudiohdr);
      if ( v8 > v5 )
      {
        v5 = v8;
        seq = v3;
      }
    }
    ++v3;
  }
  return seq;
}

//------------------------------------------------------------------------------
// Address: 0x10093FB0
// Name: int SelectWeightedSequence(class CStudioHdr __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SelectWeightedSequence(CStudioHdr *pstudiohdr, int activity, int curSequence)
{
  int NumSeq_Internal; // eax
  mstudioseqdesc_t *v5; // edi

  if ( (_S2_42 & 1) == 0 )
  {
    _S2_42 |= 1u;
    counter.m_pCounter = CVProfile::FindOrCreateCounter(
                           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                           a2: "Server SelectWeightedSequence",
                           a3: COUNTER_GROUP_DEFAULT);
    atexit(func: SelectWeightedSequence_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter.m_pCounter;
  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  if ( CStudioHdr::GetActivityListVersion(this: pstudiohdr) < g_nActivityListVersion )
    IndexModelSequences(pstudiohdr);
  if ( pstudiohdr->m_pVModel != nullptr )
    NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: pstudiohdr);
  else
    NumSeq_Internal = pstudiohdr->m_pStudioHdr->numlocalseq;
  if ( NumSeq_Internal == 1 )
  {
    if ( CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    {
      if ( pstudiohdr->m_pVModel != nullptr )
        v5 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i: 0);
      else
        v5 = (mstudioseqdesc_t *)((char *)pstudiohdr->m_pStudioHdr + pstudiohdr->m_pStudioHdr->localseqindex);
      if ( (v5->flags & 0x1000) == 0 )
        SetActivityForSequence(pstudiohdr, i: 0);
      return -(v5->activity != activity);
    }
    else
    {
      return -(activity != 0);
    }
  }
  else
  {
    if ( pstudiohdr->m_pActivityToSequence == nullptr )
      pstudiohdr->m_pActivityToSequence = CStudioHdr::CActivityToSequenceMapping::FindMapping(pHdr: pstudiohdr);
    return CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(
             this: pstudiohdr->m_pActivityToSequence,
             pstudiohdr,
             activity,
             curSequence);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100940C0
// Name: int LookupSequence(class CStudioHdr __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LookupSequence(CStudioHdr *pstudiohdr, const char *label)
{
  int i; // edi
  int v4; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int v6; // eax
  mstudioseqdesc_t *v7; // eax
  int v8; // eax

  if ( pstudiohdr == nullptr || !CStudioHdr::SequencesAvailable(this: pstudiohdr) )
    return 0;
  for ( i = 0; ; ++i )
  {
    v4 = pstudiohdr->m_pVModel != nullptr
       ? CStudioHdr::GetNumSeq_Internal(this: pstudiohdr)
       : pstudiohdr->m_pStudioHdr->numlocalseq;
    if ( i >= v4 )
      break;
    if ( pstudiohdr->m_pVModel != nullptr )
    {
      v7 = CStudioHdr::pSeqdesc_Internal(this: pstudiohdr, i);
    }
    else
    {
      m_pStudioHdr = pstudiohdr->m_pStudioHdr;
      v6 = i;
      if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
        v6 = 0;
      v7 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v6 + m_pStudioHdr->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v7 + v7->szlabelindex, s2: label) == 0 )
      return i;
  }
  v8 = LookupActivity(pstudiohdr, label);
  if ( v8 == -1 )
    return -1;
  else
    return SelectWeightedSequence(pstudiohdr, activity: v8, curSequence: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10417CF0
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x10422B90
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x10417D20
// Name: _dynamic_initializer_for__g_CheckNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckEventNames *dynamic_initializer_for__g_CheckNamesSingleton__()
{
  return CCheckEventNames::CCheckEventNames(this: &g_CheckNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x10417D30
// Name: _dynamic_initializer_for__g_CheckCCNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckCCNames *dynamic_initializer_for__g_CheckCCNamesSingleton__()
{
  return CCheckCCNames::CCheckCCNames(this: &g_CheckCCNamesSingleton);
}

} // namespace server
