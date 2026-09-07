// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/choreochannel.cpp
// Functions: 22
// ============================================================

#include "game\shared\choreochannel.h"

//------------------------------------------------------------------------------
// Address: 0x004083B0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F320
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x0040F340
// Name: public: char const __near * CChoreoChannel::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoChannel::GetName(CChoreoChannel *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x0040F350
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x0040F360
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x0040F370
// Name: public: bool CChoreoChannel::GetActive(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoChannel::GetActive(CChoreoChannel *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x0040F380
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+8h] [ebp+4h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > p1a;
}

//------------------------------------------------------------------------------
// Address: 0x0040F3C0
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040F530
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F5C0
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x0040F5F0
// Name: public: void CChoreoChannel::MarkForSaveAll(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::MarkForSaveAll(CChoreoChannel *this, bool mark)
{
  int m_Size; // ebp
  int v3; // eax
  CChoreoEvent *v4; // esi

  m_Size = this->m_Events.m_Size;
  v3 = 0;
  for ( this->m_bMarkedForSave = mark; v3 < m_Size; *((_BYTE *)v4 + 376) = (mark << 6) | *((_BYTE *)v4 + 376) & 0xBF )
  {
    if ( v3 < 0 || v3 >= this->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = this->m_Events.m_Memory.m_pMemory[v3];
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FF60
// Name: public: void CChoreoChannel::RemoveAllEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::RemoveAllEvents(CChoreoChannel *this)
{
  this->m_Events.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410FD0
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411140
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  CUtlVector<CChoreoActor *,CUtlMemory<CChoreoActor *,int>>::InsertBefore(
    this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&this->m_Events,
    elem: this->m_Events.m_Size,
    src: (KeyValues **)&event);
}

//------------------------------------------------------------------------------
// Address: 0x00411160
// Name: public: class CChoreoChannel __near & CChoreoChannel::operator=(class CChoreoChannel const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::operator=(CChoreoChannel *this, const CChoreoChannel *src)
{
  const CChoreoChannel *v2; // edi
  CUtlMemory<KeyValues *,int> *p_m_Events; // esi
  CChoreoEvent *v5; // ebx
  CChoreoEvent *v6; // edi
  CChoreoScene *Scene; // eax
  CChoreoEvent *v8; // ebp
  KeyValues **m_pMemory; // edi
  int m_nAllocationCount; // eax
  KeyValues **v11; // ecx
  int v12; // eax
  bool v13; // zf
  CChoreoEvent **v14; // edi
  int v16; // [esp+8h] [ebp-8h]

  v2 = src;
  this->m_bActive = src->m_bActive;
  V_strncpy(pDest: this->m_szName, pSrc: src->m_szName, maxLen: 128);
  v16 = 0;
  if ( src->m_Events.m_Size <= 0 )
    return this;
  p_m_Events = (CUtlMemory<KeyValues *,int> *)&this->m_Events;
  while ( 1 )
  {
    v5 = v2->m_Events.m_Memory.m_pMemory[v16];
    v6 = (CChoreoEvent *)operator new(nSize: 0x17Cu);
    if ( v6 != nullptr )
    {
      Scene = CChoreoEvent::GetScene(this: v5);
      v8 = CChoreoEvent::CChoreoEvent(this: v6, scene: Scene);
    }
    else
    {
      v8 = nullptr;
    }
    CChoreoEvent::operator=(this: v8, src: v5);
    m_pMemory = p_m_Events[1].m_pMemory;
    m_nAllocationCount = p_m_Events->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Events, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Events[1].m_pMemory;
    v11 = p_m_Events->m_pMemory;
    v12 = (char *)p_m_Events[1].m_pMemory - (char *)m_pMemory - 1;
    v13 = (char *)p_m_Events[1].m_pMemory - (char *)m_pMemory == 1;
    p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
    if ( v12 >= 0 && !v13 )
      memmove(
        dst: (unsigned __int8 *)&v11[(_DWORD)m_pMemory + 1],
        src: (unsigned __int8 *)&v11[(_DWORD)m_pMemory],
        count: 4 * v12);
    v14 = (CChoreoEvent **)&p_m_Events->m_pMemory[(_DWORD)m_pMemory];
    if ( v14 != nullptr )
      *v14 = v8;
    CChoreoEvent::SetChannel(this: v8, channel: this);
    CChoreoEvent::SetActor(this: v8, actor: this->m_pActor);
    if ( ++v16 >= src->m_Events.m_Size )
      break;
    v2 = src;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004112F0
// Name: public: int CUtlMap<char const __near *,struct EventGroup,int>::Find(char const __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,EventGroup,int>::Find(
        CUtlMap<char const *,EventGroup,int> *this,
        bool (__cdecl **key)(CChoreoEvent *const *, CChoreoEvent *const *))
{
  bool (__cdecl *v2)(CChoreoEvent *const *, CChoreoEvent *const *); // edx
  int v3; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t dummyNode; // [esp+0h] [ebp-24h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  memset(&dummyNode.elem.timeSortedEvents.m_Elements.m_nAllocationCount, 0, 12);
  dummyNode.elem.timeSortedEvents.m_LastAlloc.index = 0;
  v6 = 0;
  dummyNode.elem.timeSortedEvents.m_FirstFree = -1;
  dummyNode.elem.timeSortedEvents.m_pElements = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-1;
  v2 = *key;
  dummyNode.elem.timeSortedEvents.m_Elements.m_pMemory = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)ChoreEventStartTimeLessFunc;
  dummyNode.elem.timeSortedEvents.m_LessFunc = v2;
  v3 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Find(
         this: &this->m_Tree,
         search: (const CUtlMap<char const *,EventGroup,int>::Node_t *)&dummyNode.elem);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&dummyNode.elem.timeSortedEvents.m_Elements);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00411460
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  int m_Size; // ebp
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // si
  CChoreoEvent *v6; // esi
  int Inorder; // ebp
  CChoreoEvent *v8; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v10; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-44h]
  bool (__cdecl *newend)(CChoreoEvent *const *, CChoreoEvent *const *); // [esp+4h] [ebp-40h]
  CChoreoEvent *insert; // [esp+1Ch] [ebp-28h] BYREF
  BOOL duration; // [esp+20h] [ebp-24h] BYREF
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+24h] [ebp-20h] BYREF
  int v17; // [esp+40h] [ebp-4h]

  m_Size = this->m_Events.m_Size;
  v3 = 0;
  sortedGestures.m_Elements.m_pMemory = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements.m_nAllocationCount, 0, 12);
  sortedGestures.m_FirstFree = -1;
  sortedGestures.m_LastAlloc.index = 0;
  sortedGestures.m_pElements = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-1;
  v17 = 0;
  if ( m_Size <= 0 )
    goto LABEL_11;
  do
  {
    if ( v3 < 0 || v3 >= this->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = this->m_Events.m_Memory.m_pMemory[v3];
    insert = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements,
        &insert,
        parent: (unsigned __int16 *)&sortedGestures,
        leftchild: (bool *)&duration);
      v5 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements,
             a2: (const char *)this);
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LinkToParent(
        this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements,
        i: v5,
        parent: (unsigned __int16)sortedGestures.m_LessFunc,
        isLeft: duration);
      ++sortedGestures.m_LastAlloc.index;
      if ( sortedGestures.m_Elements.m_nAllocationCount + 12 * v5 != -8 )
        *(float *)(sortedGestures.m_Elements.m_nAllocationCount + 12 * v5 + 8) = *(float *)&insert;
    }
    ++v3;
    v6 = nullptr;
  }
  while ( v3 < m_Size );
  if ( sortedGestures.m_LastAlloc.index != 0 )
  {
    Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements);
    if ( Inorder != 0xFFFF )
    {
      do
      {
        v8 = *(CChoreoEvent **)(sortedGestures.m_Elements.m_nAllocationCount + 12 * (unsigned __int16)Inorder + 8);
        if ( v6 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v6) )
        {
          sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))CChoreoEvent::FindEntryTag(this: v8, type: PLAYBACK);
          ExitTag = CChoreoEvent::FindExitTag(this: v6, type: PLAYBACK);
          v10 = ExitTag;
          if ( sortedGestures.m_LessFunc != nullptr && ExitTag != nullptr )
          {
            *(float *)&insert = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)sortedGestures.m_LessFunc);
            *(float *)&sortedGestures.m_LessFunc = v6->GetDuration(this: v6);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v10);
            *(float *)&sortedGestures.m_LessFunc = (1.0 - Percentage) * *(float *)&sortedGestures.m_LessFunc
                                                 + *(float *)&insert;
            newend = sortedGestures.m_LessFunc;
            newstart = CChoreoEvent::GetStartTime(this: v6);
            CChoreoEvent::RescaleGestureTimes(
              this: v6,
              newstart,
              newend: *(float *)&newend,
              bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v6, endtime: *(float *)&sortedGestures.m_LessFunc);
            CEventAbsoluteTag::SetAbsoluteTime(this: v10, t: *(float *)&insert);
            CChoreoEvent::PreventTagOverlap(this: v8);
            CChoreoEvent::PreventTagOverlap(this: v6);
          }
        }
        v6 = v8;
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                      this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements,
                                      i: Inorder);
      }
      while ( Inorder != 0xFFFF );
      if ( v8 != nullptr )
        CChoreoEvent::GetScene(this: v8);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements);
    if ( *(int *)&sortedGestures.m_Root >= 0 && sortedGestures.m_Elements.m_nAllocationCount != 0 )
      goto LABEL_25;
  }
  else
  {
LABEL_11:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&sortedGestures.m_Elements);
    if ( *(int *)&sortedGestures.m_Root >= 0 && sortedGestures.m_Elements.m_nAllocationCount != 0 )
LABEL_25:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)sortedGestures.m_Elements.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004116C0
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const char *i; // ebx
  CChoreoEvent **p_m_Data; // ebp
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  bool v10; // zf
  int v11; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // edx
  int v13; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v14; // eax
  CChoreoEvent **v15; // eax
  bool leftchild; // [esp+Fh] [ebp-5h] BYREF
  unsigned __int16 parent; // [esp+10h] [ebp-4h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  this->timeSortedEvents.m_FirstFree = -1;
  this->timeSortedEvents.m_LastAlloc.index = -1;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  for ( i = (const char *)(unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
        i != (const char *)0xFFFF;
        i = (const char *)(unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                              this: &src->timeSortedEvents,
                                              (unsigned __int16)i) )
  {
    p_m_Data = &src->timeSortedEvents.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      &parent,
      &leftchild);
    v5 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NewNode(
           this: &this->timeSortedEvents,
           a2: i);
    v6 = parent;
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v10 = parent == 0xFFFF;
    v9->m_Parent = parent;
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Tag = 0;
    if ( v10 )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v11 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      v13 = v11;
      if ( leftchild )
        m_pMemory[v13].m_Left = v7;
      else
        m_pMemory[v13].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v14 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v15 = &v14[v8].m_Data;
    if ( v15 != nullptr )
      *v15 = *p_m_Data;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004117D0
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // bp
  CChoreoEvent *const *p_m_Data; // ebx
  unsigned __int16 v6; // di
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // ecx
  bool leftchild[4]; // [esp+8h] [ebp-8h] BYREF
  unsigned __int16 parent[2]; // [esp+Ch] [ebp-4h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &this->timeSortedEvents,
          insert: p_m_Data,
          parent,
          leftchild);
        v6 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NewNode(
               this: &this->timeSortedEvents,
               a2: (const char *)p_m_Data);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::LinkToParent(
          this: &this->timeSortedEvents,
          i: v6,
          parent: parent[0],
          isLeft: leftchild[0]);
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        ++this->timeSortedEvents.m_NumElements;
        if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-8 )
          m_pMemory[v6].m_Data = *p_m_Data;
        Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: &src->timeSortedEvents,
                    i: Inorder);
        if ( Inorder == 0xFFFF )
          break;
        v2 = src;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004119E0
// Name: public: int CUtlMap<char const __near *,struct EventGroup,int>::Insert(char const __near * const __near &,struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,EventGroup,int>::Insert@<eax>(
        CUtlMap<char const *,EventGroup,int> *this@<ecx>,
        const char *a2@<edi>,
        bool (__cdecl **key)(CChoreoEvent *const *, CChoreoEvent *const *),
        const EventGroup *insert)
{
  int v5; // esi
  CUtlMap<char const *,EventGroup,int>::Node_t node; // [esp+0h] [ebp-24h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  memset(&node.elem.timeSortedEvents.m_Elements.m_nAllocationCount, 0, 12);
  node.elem.timeSortedEvents.m_LastAlloc.index = 0;
  v8 = 0;
  node.elem.timeSortedEvents.m_FirstFree = -1;
  node.elem.timeSortedEvents.m_pElements = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-1;
  node.elem.timeSortedEvents.m_LessFunc = *key;
  node.elem.timeSortedEvents.m_Elements.m_pMemory = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)ChoreEventStartTimeLessFunc;
  EventGroup::operator=(this: (EventGroup *)&node.elem.timeSortedEvents.m_Elements, src: insert);
  v5 = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::Insert(
         this: &this->m_Tree,
         a2,
         insert: (const CUtlMap<char const *,EventGroup,int>::Node_t *)&node.elem);
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&node.elem.timeSortedEvents.m_Elements);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00411A60
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  CChoreoEvent *v1; // edi
  bool (__cdecl *m_Size)(CChoreoEvent *const *, CChoreoEvent *const *); // eax
  int v3; // ebx
  CChoreoEvent *v4; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // eax
  CChoreoEvent *v6; // ecx
  CChoreoEvent::CLOSECAPTION v7; // ebp
  const char *CloseCaptionToken; // eax
  const char *v9; // esi
  int v10; // eax
  unsigned __int16 *v11; // ebx
  bool (__cdecl *v12)(CChoreoEvent *const *, CChoreoEvent *const *); // eax
  CChoreoEvent *v13; // esi
  int i; // ebp
  CChoreoEvent *v15; // esi
  double EndTime; // st7
  bool IsUsingCombinedFile; // al
  float t; // [esp+0h] [ebp-64h]
  float ta; // [esp+0h] [ebp-64h]
  CChoreoEvent *insert; // [esp+14h] [ebp-50h] BYREF
  CChoreoChannel *v21; // [esp+18h] [ebp-4Ch]
  int sortedEventInGroup; // [esp+1Ch] [ebp-48h] BYREF
  EventGroup eg; // [esp+20h] [ebp-44h] BYREF
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+3Ch] [ebp-28h] BYREF
  int v25; // [esp+60h] [ebp-4h]

  v1 = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
  m_Size = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))this->m_Events.m_Size;
  v3 = 0;
  v21 = this;
  memset(&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nAllocationCount, 0, 12);
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = 0;
  v25 = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CaselessStringLessThan;
  eg.timeSortedEvents.m_LessFunc = m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_30;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = this->m_Events.m_Memory.m_pMemory[v3];
    insert = v4;
    if ( CChoreoEvent::GetType(this: v4) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: insert);
      v6 = insert;
      v7 = CloseCaptionType;
      if ( CloseCaptionType == CC_DISABLED )
        goto LABEL_17;
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: insert);
      v9 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( v7 != CC_SLAVE )
          goto LABEL_18;
        CChoreoEvent::SetCloseCaptionType(this: insert, type: CC_MASTER);
        v6 = insert;
LABEL_17:
        CChoreoEvent::SetUsingCombinedFile(this: v6, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: insert, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: insert, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: insert, t: 0.0);
        goto LABEL_18;
      }
      sortedEventInGroup = (int)CloseCaptionToken;
      v10 = CUtlMap<char const *,EventGroup,int>::Find(
              this: (CUtlMap<char const *,EventGroup,int> *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
              key: (bool (__cdecl **)(CChoreoEvent *const *, CChoreoEvent *const *))&sortedEventInGroup);
      if ( v10 == -1 )
      {
        eg.timeSortedEvents.m_Elements.m_pMemory = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)ChoreEventStartTimeLessFunc;
        memset(&eg.timeSortedEvents.m_Elements.m_nAllocationCount, 0, 12);
        eg.timeSortedEvents.m_FirstFree = -1;
        eg.timeSortedEvents.m_LastAlloc.index = 0;
        eg.timeSortedEvents.m_pElements = (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)-1;
        validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&eg.timeSortedEvents.m_Elements,
          &insert);
        sortedEventInGroup = (int)MemAlloc_StrDup(pString: v9);
        CUtlMap<char const *,EventGroup,int>::Insert(
          this: (CUtlMap<char const *,EventGroup,int> *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
          a2: nullptr,
          key: (bool (__cdecl **)(CChoreoEvent *const *, CChoreoEvent *const *))&sortedEventInGroup,
          insert: (const EventGroup *)&eg.timeSortedEvents.m_Elements);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)&eg.timeSortedEvents.m_Elements);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(48 * v10 + validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nAllocationCount + 20),
          &insert);
      }
    }
LABEL_18:
    if ( ++v3 >= (int)eg.timeSortedEvents.m_LessFunc )
      break;
    this = v21;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree > 0 )
  {
    v11 = (unsigned __int16 *)(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nAllocationCount + 24);
    for ( insert = (CChoreoEvent *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree;
          insert != nullptr;
          insert = (CChoreoEvent *)((char *)insert - 1) )
    {
      v12 = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))v11[7];
      eg.timeSortedEvents.m_LessFunc = v12;
      if ( (unsigned int)v12 > 1 )
      {
        for ( i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(v11 - 2));
              i != 0xFFFF;
              i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                      this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(v11 - 2),
                                      i) )
        {
          v15 = *(CChoreoEvent **)(*(_DWORD *)v11 + 12 * (unsigned __int16)i + 8);
          if ( v1 != nullptr )
          {
            t = CChoreoEvent::GetEndTime(this: v15);
            CChoreoEvent::SetLastSlaveEndTime(this: v1, t);
            CChoreoEvent::SetCloseCaptionType(this: v15, type: CC_SLAVE);
            IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v1);
            CChoreoEvent::SetUsingCombinedFile(this: v15, isusing: IsUsingCombinedFile);
            CChoreoEvent::SetRequiredCombinedChecksum(this: v15, checksum: 0);
            EndTime = 0.0;
          }
          else
          {
            v1 = *(CChoreoEvent **)(*(_DWORD *)v11 + 12 * (unsigned __int16)i + 8);
            CChoreoEvent::SetCloseCaptionType(this: v15, type: CC_MASTER);
            CChoreoEvent::SetRequiredCombinedChecksum(this: v15, checksum: 0);
            CChoreoEvent::SetNumSlaves(this: v15, num: (int)eg.timeSortedEvents.m_LessFunc - 1);
            EndTime = CChoreoEvent::GetEndTime(this: v15);
          }
          ta = EndTime;
          CChoreoEvent::SetLastSlaveEndTime(this: v15, t: ta);
        }
        v1 = nullptr;
      }
      else
      {
        v13 = *(CChoreoEvent **)(*(_DWORD *)v11 + 8);
        CChoreoEvent::SetCloseCaptionType(this: v13, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v13, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v13, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v13, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v13, t: 0.0);
      }
      v11 += 24;
    }
  }
LABEL_30:
  CUtlDict<EventGroup,int>::RemoveAll(this: (CUtlDict<EventGroup,int> *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> > *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nAllocationCount != 0 )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F3D0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *__thiscall CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *)&`CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x00425270
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > (double)p1a;
}

//------------------------------------------------------------------------------
// Address: 0x004564D0
// Name: public: char const __near * CChoreoChannel::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoChannel::GetName(CChoreoChannel *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x004B44E0
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004B4500
// Name: public: class CChoreoActor __near * CChoreoChannel::GetActor(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoActor *__thiscall CChoreoChannel::GetActor(CChoreoChannel *this)
{
  return this->m_pActor;
}

//------------------------------------------------------------------------------
// Address: 0x004B4510
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x004B4520
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x004B4530
// Name: public: bool CChoreoChannel::GetActive(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoChannel::GetActive(CChoreoChannel *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x004B4540
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B4650
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x004B4680
// Name: public: void CChoreoChannel::MarkForSaveAll(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::MarkForSaveAll(CChoreoChannel *this, bool mark)
{
  int m_Size; // ecx
  int v4; // eax
  CChoreoEvent *v5; // esi

  m_Size = this->m_Events.m_Size;
  v4 = 0;
  for ( this->m_bMarkedForSave = mark; v4 < m_Size; *((_BYTE *)v5 + 376) = (mark << 6) | *((_BYTE *)v5 + 376) & 0xBF )
  {
    if ( v4 < 0 || v4 >= this->m_Events.m_Size )
      v5 = nullptr;
    else
      v5 = this->m_Events.m_Memory.m_pMemory[v4];
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B4D80
// Name: public: void CChoreoChannel::RemoveEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::RemoveEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_Size; // edx
  int v4; // eax
  CChoreoEvent **i; // ecx

  m_Size = this->m_Events.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_Events.m_Memory.m_pMemory; event != *i; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &this->m_Events.m_Memory.m_pMemory[v4],
          src: &this->m_Events.m_Memory.m_pMemory[v4 + 1],
          count: 4 * (m_Size - v4 - 1));
      --this->m_Events.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B4DF0
// Name: public: void CChoreoChannel::RemoveAllEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::RemoveAllEvents(CChoreoChannel *this)
{
  this->m_Events.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5500
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B55A0
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Events; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)event;
}

//------------------------------------------------------------------------------
// Address: 0x004B5610
// Name: public: void CChoreoChannel::SaveToBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SaveToBuffer(
        CChoreoChannel *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        IChoreoStringPool *pStringPool)
{
  __int16 v5; // ax
  int m_Size; // ebx
  int i; // edi
  CChoreoEvent *v8; // ecx
  bool m_bActive; // bl
  int m_Put; // eax
  bool v11; // bl

  v5 = pStringPool->FindOrAddString(this: pStringPool, a2: this->m_szName);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%hd", v5);
  else
    CUtlBuffer::PutTypeBin<short>(this: buf, src: v5);
  m_Size = this->m_Events.m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "%hu", (unsigned __int8)m_Size);
  }
  else if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = m_Size;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  for ( i = 0; i < m_Size; ++i )
  {
    if ( i < 0 || i >= this->m_Events.m_Size )
      v8 = nullptr;
    else
      v8 = this->m_Events.m_Memory.m_pMemory[i];
    CChoreoEvent::SaveToBuffer(this: v8, buf, pScene, pStringPool);
  }
  m_bActive = this->m_bActive;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  v11 = m_bActive;
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = v11;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5740
// Name: public: class CChoreoChannel __near & CChoreoChannel::operator=(class CChoreoChannel const __near &)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::operator=(CChoreoChannel *this, const CChoreoChannel *src)
{
  const CChoreoChannel *v2; // edi
  CChoreoScene *v4; // ebx
  CChoreoEvent *v5; // edi
  CChoreoScene *SceneFPS; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoEvent **m_pMemory; // ecx
  int v10; // eax
  CChoreoEvent **v11; // edi
  int i; // [esp+Ch] [ebp-8h]
  CChoreoEvent *newEvent; // [esp+10h] [ebp-4h]

  v2 = src;
  this->m_bActive = src->m_bActive;
  V_strncpy(pDest: this->m_szName, pSrc: src->m_szName, maxLen: 128);
  i = 0;
  if ( src->m_Events.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = (CChoreoScene *)v2->m_Events.m_Memory.m_pMemory[i];
      v5 = (CChoreoEvent *)operator new(nSize: 0x17Cu);
      if ( v5 != nullptr )
      {
        SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: v4);
        newEvent = CChoreoEvent::CChoreoEvent(this: v5, scene: SceneFPS);
        CChoreoEvent::operator=(this: newEvent, src: (const CChoreoEvent *)v4);
      }
      else
      {
        newEvent = nullptr;
        CChoreoEvent::operator=(this: nullptr, src: (const CChoreoEvent *)v4);
      }
      m_Size = this->m_Events.m_Size;
      m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<IFacePoserToolWindow *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Events,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_Events.m_Size;
      m_pMemory = this->m_Events.m_Memory.m_pMemory;
      v10 = this->m_Events.m_Size - m_Size - 1;
      this->m_Events.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &this->m_Events.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = newEvent;
      CChoreoEvent::SetChannel(this: newEvent, channel: this);
      CChoreoEvent::SetActor(this: newEvent, actor: this->m_pActor);
      if ( ++i >= src->m_Events.m_Size )
        break;
      v2 = src;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B5980
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CChoreoEventWidget *,unsigned short,bool (__cdecl *)(CChoreoEventWidget * const &,CChoreoEventWidget * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEventWidget *,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoScene::GetSceneFPS(this: (CChoreoScene *)m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5C30
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CChoreoEventWidget *,unsigned short,bool (__cdecl *)(CChoreoEventWidget * const &,CChoreoEventWidget * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEventWidget *,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B5D50
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CChoreoEventWidget *,unsigned short,bool (__cdecl *)(CChoreoEventWidget * const &,CChoreoEventWidget * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEventWidget *,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B5E50
// Name: public: bool CChoreoChannel::GetSortedCombinedEventList(char const __near *,class CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoChannel::GetSortedCombinedEventList(
        CChoreoChannel *this,
        const char *cctoken,
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *events)
{
  int m_Size; // ebx
  int i; // esi
  CChoreoEvent *v6; // ecx
  const char *CloseCaptionToken; // eax
  CChoreoEvent *e; // [esp+Ch] [ebp-4h] BYREF

  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: events);
  m_Size = this->m_Events.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( i < 0 || i >= this->m_Events.m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Events.m_Memory.m_pMemory[i];
    e = v6;
    if ( CChoreoEvent::GetType(this: v6) == SPEAK
      && CChoreoEvent::GetCloseCaptionType(this: e) != CC_DISABLED
      && (CChoreoEvent::GetCloseCaptionType(this: e) != CC_MASTER || CChoreoEvent::GetNumSlaves(this: e) != 0) )
    {
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      if ( _V_stricmp(s1: CloseCaptionToken, s2: cctoken) == 0 )
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: events,
          insert: &e);
    }
  }
  return events->m_NumElements != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B61B0
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoWidget::setVisible(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoWidget::setVisible(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoWidget::setVisible(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoWidget::setVisible(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1014D9B0
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x101A75B0
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101A75D0
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x101A75E0
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > (double)p1a;
}

//------------------------------------------------------------------------------
// Address: 0x101A7620
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101A7690
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x101A91D0
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A9360
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, vgui::TreeNode *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Events; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = event;
}

//------------------------------------------------------------------------------
// Address: 0x101A9550
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float StartTime; // [esp+0h] [ebp-48h]
  float v21; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > v22; // [esp+18h] [ebp-30h] BYREF
  float v23; // [esp+34h] [ebp-14h]
  float t; // [esp+38h] [ebp-10h]
  CChoreoEvent *insert; // [esp+3Ch] [ebp-Ch] BYREF
  int decayTime; // [esp+40h] [ebp-8h] BYREF
  float entryTime; // [esp+44h] [ebp-4h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  t = *(float *)&this;
  v22.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&v22.m_Elements, 0, sizeof(v22.m_Elements));
  *(_DWORD *)&v22.m_Root = 0xFFFF;
  *(_DWORD *)&v22.m_FirstFree = -1;
  v22.m_pElements = nullptr;
  v23 = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    insert = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      decayTime = 0xFFFF;
      HIBYTE(entryTime) = 0;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &v22,
        &insert,
        parent: (unsigned __int16 *)&decayTime,
        leftchild: (bool *)&entryTime + 3);
      v5 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&v22,
             a2: (const char *)v3);
      v6 = decayTime;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = v22.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&v22.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        v22.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( HIBYTE(entryTime) != 0 )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &v22,
        elem: v7);
      ++v22.m_NumElements;
      v12 = (float *)((char *)&v22.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&insert;
      v1 = (CChoreoChannel *)LODWORD(t);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(v23) );
  if ( v22.m_NumElements != 0 )
  {
    v15 = nullptr;
    decayTime = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &v22);
    if ( decayTime != 0xFFFF )
    {
      do
      {
        m_Data = v22.m_Elements.m_pMemory[(unsigned __int16)decayTime].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          v23 = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( v23 != 0.0 && ExitTag != nullptr )
          {
            t = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(v23));
            v23 = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            v23 = (1.0 - Percentage) * v23;
            *(float *)&insert = v23 + t;
            v21 = v23 + t;
            StartTime = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(
              this: v15,
              newstart: StartTime,
              newend: v21,
              bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&insert);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        decayTime = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                        this: &v22,
                                        i: decayTime);
      }
      while ( decayTime != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &v22);
    if ( v22.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = v22.m_Elements.m_pMemory;
      if ( v22.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &v22);
    if ( v22.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = v22.m_Elements.m_pMemory;
      if ( v22.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A9800
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A9920
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short,bool (__cdecl *)(ActiveLayer_t<CUtlSymbolLarge> * const &,ActiveLayer_t<CUtlSymbolLarge> * const &),CUtlMemory<UtlRBTreeNode_t<ActiveLayer_t<CUtlSymbolLarge> *,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A9CD0
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float v17; // [esp+0h] [ebp-5Ch]
  float EndTime; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> v19; // [esp+10h] [ebp-4Ch] BYREF
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > v20; // [esp+34h] [ebp-28h] BYREF
  unsigned int v21; // [esp+50h] [ebp-Ch]
  int sortedEventInGroup; // [esp+54h] [ebp-8h]
  CChoreoEvent *insert; // [esp+58h] [ebp-4h] BYREF

  v19.m_Elements.m_Tree.m_Root = -1;
  v19.m_Elements.m_Tree.m_FirstFree = -1;
  v19.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  sortedEventInGroup = (int)this;
  memset(&v19.m_Elements.m_Tree.m_Elements, 0, sizeof(v19.m_Elements.m_Tree.m_Elements));
  v19.m_Elements.m_Tree.m_NumElements = 0;
  v19.m_Elements.m_Tree.m_pElements = nullptr;
  v19.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v21 = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &v19);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &v19.m_Elements.m_Tree);
    if ( v19.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && v19.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
      goto LABEL_38;
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    insert = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: insert);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: insert, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: insert, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: insert, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: insert, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: insert);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: insert, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: insert, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: insert, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: insert, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &v19, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&v20.m_Elements, 0, sizeof(v20.m_Elements));
        v20.m_pElements = nullptr;
        v20.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&v20.m_Root = 0xFFFF;
        *(_DWORD *)&v20.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &v20,
          &insert);
        CUtlDict<EventGroup,int>::Insert(this: &v19, pName: v6, element: (const EventGroup *)&v20);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &v20);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &v19.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          &insert);
      }
    }
LABEL_19:
    if ( ++v2 >= (int)v21 )
      break;
    this = (CChoreoChannel *)sortedEventInGroup;
  }
  if ( v19.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( v19.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&v19.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    insert = (CChoreoEvent *)&v19.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    sortedEventInGroup = v19.m_Elements.m_Tree.m_NumElements;
    do
    {
      v21 = p_m_Elements[7];
      if ( v21 > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              EndTime = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: EndTime);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: v21 - 1);
              v17 = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: v17);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&insert[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)insert;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = sortedEventInGroup-- == 1;
      insert = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &v19.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &v19.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)v19.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &v19.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &v19.m_Elements.m_Tree);
  if ( v19.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 && v19.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Elements.m_Tree.m_Elements.m_pMemory);
}

} // namespace hammer_dll

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00422430
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00422450
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x00422460
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x00422470
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > p1a;
}

//------------------------------------------------------------------------------
// Address: 0x004224B0
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00422670
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x00423DE0
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423F00
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CUtlSymbolTable::StringPool_t *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Events; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = event;
}

//------------------------------------------------------------------------------
// Address: 0x004240F0
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004243A0
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004244C0
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004245C0
// Name: public: bool CChoreoChannel::GetSortedCombinedEventList(char const __near *,class CUtlRBTree<class CChoreoEvent __near *,unsigned short,bool (*)(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoChannel::GetSortedCombinedEventList(
        CChoreoChannel *this,
        const char *cctoken,
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *events)
{
  int m_Size; // ebx
  int i; // esi
  CChoreoEvent *v6; // ecx
  const char *CloseCaptionToken; // eax
  CChoreoEvent *e; // [esp+Ch] [ebp-4h] BYREF

  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: events);
  m_Size = this->m_Events.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( i < 0 || i >= this->m_Events.m_Size )
      v6 = nullptr;
    else
      v6 = this->m_Events.m_Memory.m_pMemory[i];
    e = v6;
    if ( CChoreoEvent::GetType(this: v6) == SPEAK
      && CChoreoEvent::GetCloseCaptionType(this: e) != CC_DISABLED
      && (CChoreoEvent::GetCloseCaptionType(this: e) != CC_MASTER || CChoreoEvent::GetNumSlaves(this: e) != 0) )
    {
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      if ( _V_stricmp(s1: CloseCaptionToken, s2: cctoken) == 0 )
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: events,
          a2: (const char *)this,
          insert: &e);
    }
  }
  return events->m_NumElements != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424920
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004BF200
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x004BF220
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x004BF230
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x004BF240
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > p1a;
}

//------------------------------------------------------------------------------
// Address: 0x004BF280
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004BF390
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x004C0ED0
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1060
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Events; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<S3RGBA,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)event;
}

//------------------------------------------------------------------------------
// Address: 0x004C10D0
// Name: public: void CChoreoChannel::SaveToBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SaveToBuffer(
        CChoreoChannel *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        IChoreoStringPool *pStringPool)
{
  signed __int16 v5; // ax
  int m_Size; // ebx
  int i; // edi
  CChoreoEvent *v8; // ecx
  bool m_bActive; // bl
  int m_Put; // eax
  bool v11; // bl

  v5 = pStringPool->FindOrAddString(this: pStringPool, a2: this->m_szName);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%hd", v5);
  else
    CUtlBuffer::PutTypeBin<short>(this: buf, src: v5);
  m_Size = this->m_Events.m_Size;
  if ( (buf->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: buf, pFmt: "%hu", (unsigned __int8)m_Size);
  }
  else if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = m_Size;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  for ( i = 0; i < m_Size; ++i )
  {
    if ( i < 0 || i >= this->m_Events.m_Size )
      v8 = nullptr;
    else
      v8 = this->m_Events.m_Memory.m_pMemory[i];
    CChoreoEvent::SaveToBuffer(this: v8, buf: *(float *)&buf, pScene, pStringPool);
  }
  m_bActive = this->m_bActive;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  v11 = m_bActive;
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = v11;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1380
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1630
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1750
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1B00
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004255F0
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x00425610
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x00425620
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x00425630
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > p1a;
}

//------------------------------------------------------------------------------
// Address: 0x00425670
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00425830
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x00427470
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427600
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Events; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)event;
}

//------------------------------------------------------------------------------
// Address: 0x004277F0
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427AA0
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427BC0
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427F70
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace scenemanager

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x0040AE10
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E600
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x0040E620
// Name: public: char const __near * CChoreoChannel::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CChoreoChannel::GetName(CChoreoChannel *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x0040E630
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x0040E640
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x0040E650
// Name: public: bool CChoreoChannel::GetActive(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CChoreoChannel::GetActive(CChoreoChannel *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x0040E660
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > p1a;
}

//------------------------------------------------------------------------------
// Address: 0x0040E6A0
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040E7C0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct EventGroup,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E860
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x0040E890
// Name: public: void CChoreoChannel::MarkForSaveAll(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::MarkForSaveAll(CChoreoChannel *this, bool mark)
{
  int m_Size; // ecx
  int v4; // eax
  CChoreoEvent *v5; // esi

  m_Size = this->m_Events.m_Size;
  v4 = 0;
  for ( this->m_bMarkedForSave = mark; v4 < m_Size; *((_BYTE *)v5 + 376) = (mark << 6) | *((_BYTE *)v5 + 376) & 0xBF )
  {
    if ( v4 < 0 || v4 >= this->m_Events.m_Size )
      v5 = nullptr;
    else
      v5 = this->m_Events.m_Memory.m_pMemory[v4];
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410500
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410690
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Events; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (CUtlSymbolTable::StringPool_t *)event;
}

//------------------------------------------------------------------------------
// Address: 0x00410880
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410B30
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410C50
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00411000
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace vcdupdate

// ============================================================
// Overlay from vcd_sound_check (Missing functions)
// ============================================================
namespace vcd_sound_check {

//------------------------------------------------------------------------------
// Address: 0x0040F2F0
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x0040F310
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x0040F330
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040F440
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x00410220
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004102C0
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CUtlSymbolTable::StringPool_t *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Events; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = event;
}

//------------------------------------------------------------------------------
// Address: 0x00410440
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004106F0
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410810
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410BC0
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace vcd_sound_check

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102BEAC0
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x102BEAE0
// Name: public: void CChoreoChannel::SetActor(class CChoreoActor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActor(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x102BEAF0
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x102BEB00
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > (double)p1a;
}

//------------------------------------------------------------------------------
// Address: 0x102BEB40
// Name: public: int CChoreoChannel::GetNumEvents(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoChannel::GetNumEvents(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102BEBB0
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x102BF6B0
// Name: public: void CChoreoChannel::RemoveEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::RemoveEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_Size; // edx
  int v4; // eax
  CChoreoEvent **i; // ecx

  m_Size = this->m_Events.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_Events.m_Memory.m_pMemory; event != *i; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&this->m_Events.m_Memory.m_pMemory[v4],
          src: (unsigned __int8 *)&this->m_Events.m_Memory.m_pMemory[v4 + 1],
          count: 4 * (m_Size - v4 - 1));
      --this->m_Events.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0760
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C08F0
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Events; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)event;
}

//------------------------------------------------------------------------------
// Address: 0x102C0960
// Name: public: bool CChoreoChannel::RestoreFromBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class CChoreoActor __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoChannel::RestoreFromBuffer(
        CChoreoChannel *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        CChoreoActor *pActor,
        IChoreoStringPool *pStringPool)
{
  IChoreoStringPool_vtbl *v5; // esi
  CUtlBuffer *v6; // edi
  __int16 Short; // ax
  unsigned __int8 UnsignedShort; // al
  CChoreoEvent *v9; // ebx
  CChoreoChannel *v10; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoEvent **m_pMemory; // ecx
  int v14; // eax
  CChoreoEvent **v15; // edi
  unsigned __int8 v16; // cl
  char sz[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int numEvents; // [esp+10Ch] [ebp-Ch]
  int i; // [esp+110h] [ebp-8h]
  CChoreoChannel *channel; // [esp+114h] [ebp-4h]

  v5 = pStringPool->__vftable;
  v6 = buf;
  channel = this;
  Short = CUtlBuffer::GetShort(this: buf);
  v5->GetString(this: pStringPool, a2: Short, a3: sz, a4: 256);
  V_strncpy(pDest: channel->m_szName, pSrc: sz, maxLen: 128);
  if ( (buf->m_Flags & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
  }
  else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
  }
  else
  {
    UnsignedShort = 0;
  }
  numEvents = UnsignedShort;
  i = 0;
  if ( UnsignedShort != 0 )
  {
    while ( 1 )
    {
      v9 = CChoreoScene::AllocEvent(this: pScene);
      if ( CChoreoEvent::RestoreFromBuffer(this: v9, buf: *(float *)&v6, pScene, pStringPool) == 0 )
        return 0;
      v10 = channel;
      m_Size = channel->m_Events.m_Size;
      m_nAllocationCount = channel->m_Events.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&channel->m_Events,
          num: m_Size - m_nAllocationCount + 1);
      ++v10->m_Events.m_Size;
      m_pMemory = v10->m_Events.m_Memory.m_pMemory;
      v14 = v10->m_Events.m_Size - m_Size - 1;
      v10->m_Events.m_pElements = m_pMemory;
      if ( v14 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v14);
      v15 = &v10->m_Events.m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v9;
      CChoreoEvent::SetChannel(this: v9, channel: v10);
      CChoreoEvent::SetActor(this: v9, actor: pActor);
      v6 = buf;
      if ( ++i >= numEvents )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    if ( CUtlBuffer::CheckGet(this: v6, nSize: 1) )
      v16 = v6->m_Memory.m_pMemory[v6->m_Get++ - v6->m_nOffset];
    else
      v16 = 0;
    channel->m_bActive = v16 == 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0C70
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0F20
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C1040
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C13F0
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          a2: (const char *)v2,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10350220
// Name: public: void CChoreoChannel::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetName(CChoreoChannel *this, const char *name)
{
  V_strncpy(pDest: this->m_szName, pSrc: name, maxLen: 128);
}

//------------------------------------------------------------------------------
// Address: 0x10350240
// Name: public: void CChoreoChannel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::SetActive(CChoreoChannel *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x10350250
// Name: ChoreEventStartTimeLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChoreEventStartTimeLessFunc(CChoreoEvent **p1, CChoreoEvent **p2)
{
  CChoreoEvent *v2; // esi
  float p1a; // [esp+Ch] [ebp+8h]

  v2 = *p2;
  p1a = CChoreoEvent::GetStartTime(this: *p1);
  return CChoreoEvent::GetStartTime(this: v2) > p1a;
}

//------------------------------------------------------------------------------
// Address: 0x103502F0
// Name: public: class CChoreoEvent __near * CChoreoChannel::GetEvent(int)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall CChoreoChannel::GetEvent(CChoreoChannel *this, int event)
{
  if ( event < 0 || event >= this->m_Events.m_Size )
    return nullptr;
  else
    return this->m_Events.m_Memory.m_pMemory[event];
}

//------------------------------------------------------------------------------
// Address: 0x10351E40
// Name: public: CChoreoChannel::CChoreoChannel(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoChannel *__thiscall CChoreoChannel::CChoreoChannel(CChoreoChannel *this)
{
  this->m_Events.m_Memory.m_pMemory = nullptr;
  this->m_Events.m_Memory.m_nAllocationCount = 0;
  this->m_Events.m_Memory.m_nGrowSize = 0;
  this->m_Events.m_Size = 0;
  this->m_Events.m_pElements = nullptr;
  this->m_szName[0] = 0;
  this->m_pActor = nullptr;
  this->m_bActive = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10351FD0
// Name: public: void CChoreoChannel::AddEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::AddEvent(CChoreoChannel *this, CChoreoEvent *event)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Events; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  p_m_Events = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Events;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_Events, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Events[1].m_pMemory;
  m_pMemory = p_m_Events->m_pMemory;
  v6 = (int)p_m_Events[1].m_pMemory - m_Size - 1;
  p_m_Events[1].m_nAllocationCount = (int)p_m_Events->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_Events->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)event;
}

//------------------------------------------------------------------------------
// Address: 0x10352040
// Name: public: bool CChoreoChannel::RestoreFromBuffer(class CUtlBuffer __near &,class CChoreoScene __near *,class CChoreoActor __near *,class IChoreoStringPool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CChoreoChannel::RestoreFromBuffer(
        CChoreoChannel *this,
        CUtlBuffer *buf,
        CChoreoScene *pScene,
        CChoreoActor *pActor,
        IChoreoStringPool *pStringPool)
{
  IChoreoStringPool_vtbl *v5; // esi
  CUtlBuffer *v6; // edi
  __int16 Short; // ax
  unsigned __int8 UnsignedShort; // al
  CChoreoEvent *v9; // ebx
  CChoreoChannel *v10; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CChoreoEvent **m_pMemory; // ecx
  int v14; // eax
  CChoreoEvent **v15; // edi
  unsigned __int8 v16; // cl
  char sz[256]; // [esp+Ch] [ebp-10Ch] BYREF
  int numEvents; // [esp+10Ch] [ebp-Ch]
  int i; // [esp+110h] [ebp-8h]
  CChoreoChannel *channel; // [esp+114h] [ebp-4h]

  v5 = pStringPool->__vftable;
  v6 = buf;
  channel = this;
  Short = CUtlBuffer::GetShort(this: buf);
  v5->GetString(this: pStringPool, a2: Short, a3: sz, a4: 256);
  V_strncpy(pDest: channel->m_szName, pSrc: sz, maxLen: 128);
  if ( (buf->m_Flags & 1) != 0 )
  {
    UnsignedShort = CUtlBuffer::GetUnsignedShort(this: buf);
  }
  else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    UnsignedShort = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
  }
  else
  {
    UnsignedShort = 0;
  }
  numEvents = UnsignedShort;
  i = 0;
  if ( UnsignedShort != 0 )
  {
    while ( 1 )
    {
      v9 = CChoreoScene::AllocEvent(this: pScene);
      if ( CChoreoEvent::RestoreFromBuffer(this: v9, buf: *(float *)&v6, pScene, pStringPool) == 0 )
        return 0;
      v10 = channel;
      m_Size = channel->m_Events.m_Size;
      m_nAllocationCount = channel->m_Events.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&channel->m_Events,
          num: m_Size - m_nAllocationCount + 1);
      ++v10->m_Events.m_Size;
      m_pMemory = v10->m_Events.m_Memory.m_pMemory;
      v14 = v10->m_Events.m_Size - m_Size - 1;
      v10->m_Events.m_pElements = m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
      v15 = &v10->m_Events.m_Memory.m_pMemory[m_Size];
      if ( v15 != nullptr )
        *v15 = v9;
      CChoreoEvent::SetChannel(this: v9, channel: v10);
      CChoreoEvent::SetActor(this: v9, actor: pActor);
      v6 = buf;
      if ( ++i >= numEvents )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    if ( CUtlBuffer::CheckGet(this: v6, nSize: 1) )
      v16 = v6->m_Memory.m_pMemory[v6->m_Get++ - v6->m_nOffset];
    else
      v16 = 0;
    channel->m_bActive = v16 == 1;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10352350
// Name: public: void CChoreoChannel::ReconcileGestureTimes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileGestureTimes(CChoreoChannel *this)
{
  CChoreoChannel *v1; // esi
  CEventAbsoluteTag *m_Size; // eax
  int v3; // edi
  CChoreoEvent *v4; // ecx
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  int v10; // esi
  int v11; // edx
  float *v12; // esi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v13; // eax
  IMemAlloc *v14; // ecx
  CChoreoEvent *v15; // esi
  CChoreoEvent *m_Data; // edi
  CEventAbsoluteTag *ExitTag; // eax
  CEventAbsoluteTag *v18; // ebx
  double Percentage; // st7
  float newstart; // [esp+0h] [ebp-48h]
  float newend; // [esp+4h] [ebp-44h]
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > sortedGestures; // [esp+18h] [ebp-30h] BYREF
  float decayTime; // [esp+34h] [ebp-14h]
  float entryTime; // [esp+38h] [ebp-10h]
  CChoreoEvent *e; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h] BYREF
  bool leftchild; // [esp+47h] [ebp-1h] BYREF

  v1 = this;
  m_Size = (CEventAbsoluteTag *)this->m_Events.m_Size;
  v3 = 0;
  entryTime = *(float *)&this;
  sortedGestures.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  memset(&sortedGestures.m_Elements, 0, sizeof(sortedGestures.m_Elements));
  *(_DWORD *)&sortedGestures.m_Root = 0xFFFF;
  *(_DWORD *)&sortedGestures.m_FirstFree = -1;
  sortedGestures.m_pElements = nullptr;
  decayTime = *(float *)&m_Size;
  if ( (int)m_Size <= 0 )
    goto LABEL_17;
  do
  {
    if ( v3 < 0 || v3 >= v1->m_Events.m_Size )
      v4 = nullptr;
    else
      v4 = v1->m_Events.m_Memory.m_pMemory[v3];
    e = v4;
    if ( CChoreoEvent::GetType(this: v4) == GESTURE )
    {
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &sortedGestures,
        insert: &e,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v5 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
             this: (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)&sortedGestures,
             a2: (const char *)v3);
      v6 = i;
      v7 = v5;
      v8 = 3 * v5;
      m_pMemory = sortedGestures.m_Elements.m_pMemory;
      v10 = 4 * v8;
      *(unsigned __int16 *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Right + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Left + v10) = -1;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Tag + v10) = 0;
      *(unsigned __int16 *)((char *)&m_pMemory->m_Parent + v10) = v6;
      if ( v6 == 0xFFFF )
      {
        sortedGestures.m_Root = v7;
      }
      else
      {
        v11 = v6;
        if ( leftchild )
          m_pMemory[v11].m_Left = v7;
        else
          m_pMemory[v11].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &sortedGestures,
        elem: v7);
      ++sortedGestures.m_NumElements;
      v12 = (float *)((char *)&sortedGestures.m_Elements.m_pMemory->m_Data + v10);
      if ( v12 != nullptr )
        *v12 = *(float *)&e;
      v1 = (CChoreoChannel *)LODWORD(entryTime);
    }
    ++v3;
  }
  while ( v3 < SLODWORD(decayTime) );
  if ( sortedGestures.m_NumElements != 0 )
  {
    v15 = nullptr;
    i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &sortedGestures);
    if ( i != 0xFFFF )
    {
      do
      {
        m_Data = sortedGestures.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
        if ( v15 != nullptr && CChoreoEvent::GetSyncToFollowingGesture(this: v15) )
        {
          decayTime = COERCE_FLOAT(CChoreoEvent::FindEntryTag(this: m_Data, type: PLAYBACK));
          ExitTag = CChoreoEvent::FindExitTag(this: v15, type: PLAYBACK);
          v18 = ExitTag;
          if ( decayTime != 0.0 && ExitTag != nullptr )
          {
            entryTime = CEventAbsoluteTag::GetAbsoluteTime(this: (CEventAbsoluteTag *)LODWORD(decayTime));
            decayTime = v15->GetDuration(this: v15);
            Percentage = CEventAbsoluteTag::GetPercentage(this: v18);
            decayTime = (1.0 - Percentage) * decayTime;
            *(float *)&e = decayTime + entryTime;
            newend = decayTime + entryTime;
            newstart = CChoreoEvent::GetStartTime(this: v15);
            CChoreoEvent::RescaleGestureTimes(this: v15, newstart, newend, bMaintainAbsoluteTagPositions: true);
            CChoreoEvent::SetEndTime(this: v15, endtime: *(float *)&e);
            CEventAbsoluteTag::SetAbsoluteTime(this: v18, t: entryTime);
            CChoreoEvent::PreventTagOverlap(this: m_Data);
            CChoreoEvent::PreventTagOverlap(this: v15);
          }
        }
        v15 = m_Data;
        i = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sortedGestures,
                                i);
      }
      while ( i != 0xFFFF );
      if ( m_Data != nullptr )
        CChoreoEvent::GetScene(this: m_Data);
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
        goto LABEL_32;
      }
    }
  }
  else
  {
LABEL_17:
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &sortedGestures);
    if ( sortedGestures.m_Elements.m_nGrowSize >= 0 )
    {
      v13 = sortedGestures.m_Elements.m_pMemory;
      if ( sortedGestures.m_Elements.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_32:
        v14->Free_2(this: v14, a2: v13);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10352600
// Name: public: EventGroup::EventGroup(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::EventGroup(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v3; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+Ch] [ebp-10h]
  unsigned __int16 i; // [esp+10h] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+14h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Bh] [ebp-1h] BYREF

  this->timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
  this->timeSortedEvents.m_Elements.m_pMemory = nullptr;
  this->timeSortedEvents.m_Elements.m_nAllocationCount = 0;
  this->timeSortedEvents.m_Elements.m_nGrowSize = 0;
  this->timeSortedEvents.m_pElements = this->timeSortedEvents.m_Elements.m_pMemory;
  *(_DWORD *)&this->timeSortedEvents.m_Root = 0xFFFF;
  *(_DWORD *)&this->timeSortedEvents.m_FirstFree = -1;
  CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
  v3 = src;
  Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    p_m_Data = &v3->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &this->timeSortedEvents,
      insert: p_m_Data,
      parent,
      &leftchild);
    v5 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
           (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this,
           a2: (const char *)v3);
    v6 = parent[0];
    v7 = v5;
    v8 = v5;
    v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      this->timeSortedEvents.m_Root = v7;
    }
    else
    {
      v10 = v6;
      m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
      if ( leftchild )
        m_pMemory[v10].m_Left = v7;
      else
        m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &this->timeSortedEvents,
      elem: v7);
    v12 = this->timeSortedEvents.m_Elements.m_pMemory;
    ++this->timeSortedEvents.m_NumElements;
    v13 = &v12[v8].m_Data;
    if ( v13 != nullptr )
      *v13 = *p_m_Data;
    v3 = src;
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                this: &src->timeSortedEvents,
                i);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10352720
// Name: public: struct EventGroup __near & EventGroup::operator=(struct EventGroup const __near &)
// Source: json
//------------------------------------------------------------------------------
EventGroup *__thiscall EventGroup::operator=(EventGroup *this, const EventGroup *src)
{
  const EventGroup *v2; // edi
  unsigned __int16 Inorder; // ax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<CChoreoEvent *,unsigned short> *v12; // ecx
  _DWORD *v13; // edi
  CChoreoEvent *const *p_m_Data; // [esp+8h] [ebp-10h]
  unsigned __int16 i; // [esp+Ch] [ebp-Ch]
  unsigned __int16 parent[3]; // [esp+10h] [ebp-8h] BYREF
  bool leftchild; // [esp+17h] [ebp-1h] BYREF

  v2 = src;
  if ( this != src )
  {
    CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::RemoveAll(this: &this->timeSortedEvents);
    Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: &src->timeSortedEvents);
    for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
    {
      p_m_Data = &v2->timeSortedEvents.m_Elements.m_pMemory[Inorder].m_Data;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->timeSortedEvents,
        insert: p_m_Data,
        parent,
        &leftchild);
      v5 = CUtlRBTree<unsigned int,unsigned short,bool (__cdecl *)(unsigned int const &,unsigned int const &),CUtlMemory<UtlRBTreeNode_t<unsigned int,unsigned short>,unsigned short>>::NewNode(
             (CUtlRBTree<void *,unsigned short,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> > *)this,
             a2: (const char *)v2);
      v6 = parent[0];
      v7 = v5;
      v8 = v5;
      v9 = &this->timeSortedEvents.m_Elements.m_pMemory[v8];
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Parent = v6;
      v9->m_Tag = 0;
      if ( v6 == 0xFFFF )
      {
        this->timeSortedEvents.m_Root = v7;
      }
      else
      {
        v10 = v6;
        m_pMemory = this->timeSortedEvents.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[v10].m_Left = v7;
        else
          m_pMemory[v10].m_Right = v7;
      }
      CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->timeSortedEvents,
        elem: v7);
      v12 = this->timeSortedEvents.m_Elements.m_pMemory;
      ++this->timeSortedEvents.m_NumElements;
      v13 = &v12[v8].m_Data;
      if ( v13 != nullptr )
        *v13 = *p_m_Data;
      v2 = src;
      Inorder = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                  this: &src->timeSortedEvents,
                  i);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10352AD0
// Name: public: void CChoreoChannel::ReconcileCloseCaption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoChannel::ReconcileCloseCaption(CChoreoChannel *this)
{
  int m_Size; // eax
  int v2; // edi
  CChoreoEvent *v3; // ecx
  CChoreoEvent::CLOSECAPTION CloseCaptionType; // ebx
  const char *CloseCaptionToken; // eax
  const char *v6; // esi
  int v7; // eax
  unsigned __int16 *p_m_Elements; // esi
  CChoreoEvent *v9; // ebx
  int Inorder; // ebx
  CChoreoEvent *v11; // edi
  CChoreoEvent *v12; // esi
  bool IsUsingCombinedFile; // al
  unsigned __int16 v14; // ax
  bool v15; // zf
  UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *i; // esi
  float t; // [esp+0h] [ebp-5Ch]
  float ta; // [esp+0h] [ebp-5Ch]
  CUtlDict<EventGroup,int> validSpeakEventsGroupedByName; // [esp+10h] [ebp-4Ch] BYREF
  EventGroup eg; // [esp+34h] [ebp-28h] BYREF
  int sortedEventInGroup; // [esp+50h] [ebp-Ch]
  CChoreoChannel *m_NumElements; // [esp+54h] [ebp-8h]
  CChoreoEvent *e; // [esp+58h] [ebp-4h] BYREF

  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Root = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_FirstFree = -1;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_Size = this->m_Events.m_Size;
  v2 = 0;
  m_NumElements = this;
  memset(
    &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements,
    0,
    sizeof(validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements));
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements = 0;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_pElements = nullptr;
  validSpeakEventsGroupedByName.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  sortedEventInGroup = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_21:
    CUtlDict<EventGroup,int>::RemoveAll(this: &validSpeakEventsGroupedByName);
    CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
    if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      goto LABEL_38;
    }
    return;
  }
  while ( 1 )
  {
    if ( v2 < 0 || v2 >= this->m_Events.m_Size )
      v3 = nullptr;
    else
      v3 = this->m_Events.m_Memory.m_pMemory[v2];
    e = v3;
    if ( CChoreoEvent::GetType(this: v3) == SPEAK )
    {
      CloseCaptionType = CChoreoEvent::GetCloseCaptionType(this: e);
      if ( CloseCaptionType == CC_DISABLED )
      {
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
LABEL_18:
        CChoreoEvent::SetLastSlaveEndTime(this: e, t: 0.0);
        goto LABEL_19;
      }
      CloseCaptionToken = CChoreoEvent::GetCloseCaptionToken(this: e);
      v6 = CloseCaptionToken;
      if ( CloseCaptionToken == nullptr || *CloseCaptionToken == 0 )
      {
        if ( CloseCaptionType != CC_SLAVE )
          goto LABEL_19;
        CChoreoEvent::SetCloseCaptionType(this: e, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: e, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: e, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: e, num: 0);
        goto LABEL_18;
      }
      v7 = CUtlDict<EventGroup,int>::Find(this: &validSpeakEventsGroupedByName, pName: CloseCaptionToken);
      if ( v7 == -1 )
      {
        memset(&eg.timeSortedEvents.m_Elements, 0, sizeof(eg.timeSortedEvents.m_Elements));
        eg.timeSortedEvents.m_pElements = nullptr;
        eg.timeSortedEvents.m_LessFunc = (bool (__cdecl *)(CChoreoEvent *const *, CChoreoEvent *const *))ChoreEventStartTimeLessFunc;
        *(_DWORD *)&eg.timeSortedEvents.m_Root = 0xFFFF;
        *(_DWORD *)&eg.timeSortedEvents.m_FirstFree = -1;
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &eg.timeSortedEvents,
          insert: &e);
        CUtlDict<EventGroup,int>::Insert(this: &validSpeakEventsGroupedByName, pName: v6, element: &eg);
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::~CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>(this: &eg.timeSortedEvents);
      }
      else
      {
        CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::Insert(
          this: &validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem.timeSortedEvents,
          insert: &e);
      }
    }
LABEL_19:
    if ( ++v2 >= sortedEventInGroup )
      break;
    this = m_NumElements;
  }
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements == 0 )
    goto LABEL_21;
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements > 0 )
  {
    p_m_Elements = (unsigned __int16 *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    e = (CChoreoEvent *)&validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.timeSortedEvents.m_Elements;
    m_NumElements = (CChoreoChannel *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_NumElements;
    do
    {
      sortedEventInGroup = p_m_Elements[7];
      if ( (unsigned int)sortedEventInGroup > 1 )
      {
        Inorder = (unsigned __int16)CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)(p_m_Elements - 2));
        v11 = nullptr;
        if ( Inorder != 0xFFFF )
        {
          do
          {
            v12 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 12 * (unsigned __int16)Inorder + 8);
            if ( v11 != nullptr )
            {
              ta = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v11, t: ta);
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_SLAVE);
              IsUsingCombinedFile = CChoreoEvent::IsUsingCombinedFile(this: v11);
              CChoreoEvent::SetUsingCombinedFile(this: v12, isusing: IsUsingCombinedFile);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t: 0.0);
            }
            else
            {
              v11 = v12;
              CChoreoEvent::SetCloseCaptionType(this: v12, type: CC_MASTER);
              CChoreoEvent::SetRequiredCombinedChecksum(this: v12, checksum: 0);
              CChoreoEvent::SetNumSlaves(this: v12, num: sortedEventInGroup - 1);
              t = CChoreoEvent::GetEndTime(this: v12);
              CChoreoEvent::SetLastSlaveEndTime(this: v12, t);
            }
            v14 = CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl *)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CChoreoEvent *,unsigned short,bool (__cdecl*)(CChoreoEvent * const &,CChoreoEvent * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short> > *)((char *)&e[-1] + 376),
                    i: Inorder);
            p_m_Elements = (unsigned __int16 *)e;
            LOWORD(Inorder) = v14;
          }
          while ( v14 != 0xFFFF );
        }
      }
      else
      {
        v9 = *(CChoreoEvent **)(*(_DWORD *)p_m_Elements + 8);
        CChoreoEvent::SetCloseCaptionType(this: v9, type: CC_MASTER);
        CChoreoEvent::SetUsingCombinedFile(this: v9, isusing: false);
        CChoreoEvent::SetRequiredCombinedChecksum(this: v9, checksum: 0);
        CChoreoEvent::SetNumSlaves(this: v9, num: 0);
        CChoreoEvent::SetLastSlaveEndTime(this: v9, t: 0.0);
      }
      p_m_Elements += 24;
      v15 = m_NumElements == (CChoreoChannel *)1;
      m_NumElements = (CChoreoChannel *)((char *)m_NumElements - 1);
      e = (CChoreoEvent *)p_m_Elements;
    }
    while ( !v15 );
  }
  for ( i = (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::FirstInorder(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
        i != (UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int> *)-1;
        i = CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::NextInorder(
              this: &validSpeakEventsGroupedByName.m_Elements.m_Tree,
              (int)i) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,EventGroup,int>::Node_t,int,CUtlMap<char const *,EventGroup,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,EventGroup,int>::Node_t,int>,int>>::RemoveAll(this: &validSpeakEventsGroupedByName.m_Elements.m_Tree);
  if ( validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
LABEL_38:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: validSpeakEventsGroupedByName.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10417D40
// Name: _dynamic_initializer_for__choreo_spew_filter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__choreo_spew_filter__()
{
  ConVar::ConVar(
    this: &choreo_spew_filter,
    pName: "choreo_spew_filter",
    pDefaultValue: locale,
    flags: 0x2000,
    pHelpString: "Spew choreo. Use a sub-string or * to display all events.");
  return atexit(func: dynamic_atexit_destructor_for__choreo_spew_filter__);
}

//------------------------------------------------------------------------------
// Address: 0x10422BA0
// Name: _dynamic_atexit_destructor_for__choreo_spew_filter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__choreo_spew_filter__()
{
  ConVar::~ConVar(this: &choreo_spew_filter);
}

//------------------------------------------------------------------------------
// Address: 0x10417D70
// Name: _dynamic_initializer_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::CParticleSystemMgr(this: &s_ParticleSystemMgr);
  return atexit(func: dynamic_atexit_destructor_for__s_ParticleSystemMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10422BD0
// Name: _dynamic_atexit_destructor_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::~CParticleSystemMgr(this: &s_ParticleSystemMgr);
}

} // namespace server
