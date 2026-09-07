// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/history.cpp
// Functions: 26
// ============================================================

#include "hammer\history.h"

//------------------------------------------------------------------------------
// Address: 0x10045FF0
// Name: class CHistory __near * GetHistory(void)
// Source: json
//------------------------------------------------------------------------------
CHistory *__cdecl GetHistory()
{
  CHistory *result; // eax

  result = pCurHistory;
  if ( pCurHistory == nullptr )
    return &FakeHistory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046000
// Name: public: void CHistory::SetOpposite(int,class CHistory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::SetOpposite(CHistory *this, int bUndo, CHistory *pOpposite)
{
  this->bUndo = bUndo;
  this->Opposite = pOpposite;
}

//------------------------------------------------------------------------------
// Address: 0x10046020
// Name: public: int CHistory::IsUndoable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHistory::IsUndoable(CHistory *this)
{
  return this->CurTrack != nullptr && this->m_bActive != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10046040
// Name: public: static void CHistory::SetHistory(class CHistory __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CHistory::SetHistory(CHistory *pHistory)
{
  pCurHistory = pHistory;
}

//------------------------------------------------------------------------------
// Address: 0x10046050
// Name: public: CTrackEntry::CTrackEntry(enum CTrackEntry::TrackType_t,...)
// Source: json
//------------------------------------------------------------------------------
CTrackEntry *CTrackEntry::CTrackEntry(CTrackEntry *this, CTrackEntry::TrackType_t eType, CMapClass *a3, ...)
{
  CMapClass *v4; // eax

  this->m_eType = eType;
  this->m_bAutoDestruct = false;
  *(_WORD *)&this->m_bKeptChildren = 0;
  if ( eType != ttCopy )
  {
    if ( eType == ttDelete )
    {
      this->m_Copy.pCurrent = a3;
      this->m_Copy.pKeptObject = a3->GetParent(this: a3);
      this->m_nDataSize = 24;
      return this;
    }
    if ( eType == ttCreate )
    {
      this->m_Copy.pCurrent = a3;
      this->m_nDataSize = 24;
      return this;
    }
  }
  else
  {
    this->m_Copy.pCurrent = a3;
    v4 = a3->Copy(this: a3, a2: false);
    this->m_Copy.pKeptObject = v4;
    this->m_nDataSize = v4->GetSize(this: v4) + 24;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100460D0
// Name: public: CTrackEntry::~CTrackEntry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTrackEntry::~CTrackEntry(CTrackEntry *this)
{
  CTrackEntry::TrackType_t m_eType; // eax
  CMapClass *pKeptObject; // ecx

  if ( this->m_bAutoDestruct )
  {
    m_eType = this->m_eType;
    if ( m_eType != ttNone )
    {
      if ( m_eType == ttCopy )
      {
        if ( this->m_bUndone )
          return;
        pKeptObject = this->m_Copy.pKeptObject;
        goto LABEL_9;
      }
      if ( m_eType == ttDelete && !this->m_bUndone )
      {
        pKeptObject = this->m_Copy.pCurrent;
LABEL_9:
        if ( pKeptObject != nullptr )
          ((void (__thiscall *)(CMapClass *, int))pKeptObject->~CMapClass)(a1: pKeptObject, a2: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046110
// Name: public: void CHistoryTrack::OnRemoveVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryTrack::OnRemoveVisGroup(CHistoryTrack *this, CVisGroup *pVisGroup)
{
  int v3; // ebx
  int v4; // edi
  CTrackEntry *m_pMemory; // eax
  CTrackEntry::TrackType_t m_eType; // ecx

  v3 = 0;
  if ( this->Data.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      m_pMemory = this->Data.m_Memory.m_pMemory;
      m_eType = this->Data.m_Memory.m_pMemory[v4].m_eType;
      if ( m_eType != ttCopy )
      {
        if ( m_eType == ttDelete )
          CMapClass::RemoveVisGroup(this: m_pMemory[v4].m_Copy.pCurrent, pVisGroup);
      }
      else
      {
        CMapClass::RemoveVisGroup(this: m_pMemory[v4].m_Copy.pKeptObject, pVisGroup);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->Data.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100461C0
// Name: public: void CHistory::OnRemoveVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::OnRemoveVisGroup(CHistory *this, CVisGroup *pVisGroup)
{
  CHistoryTrack *CurTrack; // ecx
  CHistory *Opposite; // eax

  CurTrack = this->CurTrack;
  if ( CurTrack != nullptr )
    CHistoryTrack::OnRemoveVisGroup(this: CurTrack, pVisGroup);
  Opposite = this->Opposite;
  if ( Opposite != nullptr && Opposite->CurTrack != nullptr )
    CHistoryTrack::OnRemoveVisGroup(this: Opposite->CurTrack, pVisGroup);
}

//------------------------------------------------------------------------------
// Address: 0x100461F0
// Name: public: CHistory::CHistory(void)
// Source: json
//------------------------------------------------------------------------------
CHistory *__thiscall CHistory::CHistory(CHistory *this)
{
  CHistoryTrack **m_pMemory; // esi
  int v3; // esi

  this->Tracks.m_Memory.m_pMemory = nullptr;
  this->Tracks.m_Memory.m_nAllocationCount = 0;
  this->Tracks.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->Tracks.m_Memory.m_pMemory;
  this->Tracks.m_Size = 0;
  this->Tracks.m_pElements = m_pMemory;
  v3 = bFirst != 0 ? 2 : 0;
  this->Opposite = nullptr;
  this->CurTrack = nullptr;
  this->bPaused = v3;
  bFirst = 0;
  this->m_bActive = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10046300
// Name: public: void CHistoryTrack::Keep(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryTrack::Keep(CHistoryTrack *this, CMapClass *pObject, bool bKeepChildren)
{
  CHistory *Parent; // eax
  unsigned int dwKept; // edx
  unsigned int dwID; // eax
  int m_Size; // eax
  CHistory *v8; // esi
  CTrackEntry te; // [esp+4h] [ebp-24h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  Parent = this->Parent;
  if ( Parent->bPaused == 0 && Parent->m_bActive != 0 && !pObject->m_bTemporary )
  {
    dwKept = pObject->dwKept;
    dwID = this->dwID;
    if ( (dwKept & 0xFFFFFFF) == dwID )
    {
      if ( (dwKept & 0x20000000) != 0 )
        return;
    }
    else
    {
      pObject->dwKept = dwID & 0xFFFFFFF;
    }
    this->Parent->bPaused = 1;
    CTrackEntry::CTrackEntry(this: &te, eType: ttCopy, a3: pObject);
    v10 = 0;
    m_Size = this->Data.m_Size;
    te.m_bKeptChildren = bKeepChildren;
    CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(this: &this->Data, elem: m_Size, src: &te);
    this->uDataSize += te.m_nDataSize;
    v8 = this->Parent;
    te.m_bAutoDestruct = false;
    if ( v8->bPaused == 1 )
      v8->bPaused = 0;
    v10 = -1;
    CTrackEntry::~CTrackEntry(this: &te);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100463E0
// Name: public: void CHistoryTrack::KeepForDestruction(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryTrack::KeepForDestruction(CHistoryTrack *this, CMapClass *pObject)
{
  CHistory *Parent; // eax
  unsigned int dwKept; // ecx
  unsigned int dwID; // eax
  CHistory *v6; // esi
  CTrackEntry te; // [esp+4h] [ebp-24h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  Parent = this->Parent;
  if ( Parent->bPaused == 0 && Parent->m_bActive != 0 && !pObject->m_bTemporary )
  {
    dwKept = pObject->dwKept;
    dwID = this->dwID;
    if ( (dwKept & 0xFFFFFFF) == dwID )
    {
      if ( (dwKept & 0x10000000) != 0 )
        return;
      pObject->dwKept = dwKept | 0x10000000;
    }
    else
    {
      pObject->dwKept = dwID & 0xFFFFFFF | 0x10000000;
    }
    this->Parent->bPaused = 1;
    CTrackEntry::CTrackEntry(this: &te, eType: ttDelete, a3: pObject);
    v8 = 0;
    CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
      this: &this->Data,
      elem: this->Data.m_Size,
      src: &te);
    this->uDataSize += te.m_nDataSize;
    v6 = this->Parent;
    te.m_bAutoDestruct = false;
    if ( v6->bPaused == 1 )
      v6->bPaused = 0;
    v8 = -1;
    CTrackEntry::~CTrackEntry(this: &te);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100464D0
// Name: public: void CHistoryTrack::KeepNew(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryTrack::KeepNew(CHistoryTrack *this, CMapClass *pObject)
{
  CHistory *Parent; // eax
  unsigned int dwKept; // ecx
  unsigned int dwID; // eax
  CHistory *v6; // esi
  bool v7; // zf
  CTrackEntry te; // [esp+4h] [ebp-24h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  Parent = this->Parent;
  if ( Parent->bPaused == 0 && Parent->m_bActive != 0 && !pObject->m_bTemporary )
  {
    dwKept = pObject->dwKept;
    dwID = this->dwID;
    if ( (dwKept & 0xFFFFFFF) == dwID )
    {
      if ( (dwKept & 0x20000000) == 0 )
        pObject->dwKept = dwKept | 0x20000000;
    }
    else
    {
      pObject->dwKept = dwID & 0xFFFFFFF | 0x20000000;
    }
    this->Parent->bPaused = 1;
    CTrackEntry::CTrackEntry(this: &te, eType: ttCreate, a3: pObject);
    v9 = 0;
    CUtlVector<ControlInfo_t,CUtlMemory<ControlInfo_t,int>>::InsertBefore(
      this: &this->Data,
      elem: this->Data.m_Size,
      src: &te);
    this->uDataSize += te.m_nDataSize;
    v6 = this->Parent;
    v7 = v6->bPaused == 1;
    te.m_bAutoDestruct = false;
    if ( v7 )
      v6->bPaused = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100466D0
// Name: public: CHistoryTrack::~CHistoryTrack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryTrack::~CHistoryTrack(CHistoryTrack *this)
{
  int v2; // eax
  int v3; // ecx
  CUtlReferenceVector<CMapClass> *p_Selected; // edi
  int i; // ebx
  int v6; // ebx
  CUtlReference<CMapClass> **m_pMemory; // [esp-4h] [ebp-24h]
  CUtlReference<CMapClass> **v8; // [esp-4h] [ebp-24h]

  v2 = 0;
  if ( this->Data.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      this->Data.m_Memory.m_pMemory[v3].m_bAutoDestruct = this->m_bAutoDestruct;
      ++v2;
      ++v3;
    }
    while ( v2 < this->Data.m_Size );
  }
  p_Selected = &this->Selected;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &this->Selected);
  if ( this->Selected.m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->Selected.m_Memory.m_nBlocks; ++i )
      free(pMem: p_Selected->m_Memory.m_pMemory[i]);
    m_pMemory = p_Selected->m_Memory.m_pMemory;
    this->Selected.m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    p_Selected->m_Memory.m_pMemory = nullptr;
  }
  v6 = 0;
  this->Selected.m_pElements = nullptr;
  if ( p_Selected->m_Memory.m_pMemory != nullptr )
  {
    if ( this->Selected.m_Memory.m_nBlocks > 0 )
    {
      do
        free(pMem: p_Selected->m_Memory.m_pMemory[v6++]);
      while ( v6 < this->Selected.m_Memory.m_nBlocks );
    }
    v8 = p_Selected->m_Memory.m_pMemory;
    this->Selected.m_Memory.m_nBlocks = 0;
    free(pMem: v8);
    p_Selected->m_Memory.m_pMemory = nullptr;
  }
  CUtlVector<CTrackEntry,CUtlMemory<CTrackEntry,int>>::RemoveAll(this: &this->Data);
  if ( this->Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->Data.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->Data.m_Memory.m_pMemory);
      this->Data.m_Memory.m_pMemory = nullptr;
    }
    this->Data.m_Memory.m_nAllocationCount = 0;
  }
  this->Data.m_pElements = this->Data.m_Memory.m_pMemory;
  if ( this->Data.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->Data.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->Data.m_Memory.m_pMemory);
      this->Data.m_Memory.m_pMemory = nullptr;
    }
    this->Data.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046810
// Name: public: CHistoryTrack::CHistoryTrack(class CHistory __near *,class CUtlReferenceVector<class CMapClass> const __near *)
// Source: json
//------------------------------------------------------------------------------
CHistoryTrack *__thiscall CHistoryTrack::CHistoryTrack(
        CHistoryTrack *this,
        CHistory *pParent,
        const CUtlReferenceVector<CMapClass> *pSelected)
{
  CTrackEntry *m_pMemory; // eax
  CUtlReferenceVector<CMapClass> *p_Selected; // edi
  int v6; // eax

  this->Data.m_Memory.m_pMemory = nullptr;
  this->Data.m_Memory.m_nAllocationCount = 0;
  this->Data.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->Data.m_Memory.m_pMemory;
  this->Data.m_Size = 0;
  this->Data.m_pElements = m_pMemory;
  p_Selected = &this->Selected;
  this->Selected.m_Memory.m_pMemory = nullptr;
  this->Selected.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->Selected.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->Selected.m_Memory, nGrowSize: 0, nInitSize: 0);
  p_Selected->m_Size = 0;
  p_Selected->m_pElements = nullptr;
  this->Parent = pParent;
  CUtlVector<CAMSTRUCT,CUtlMemory<CAMSTRUCT,int>>::EnsureCapacity(this: &this->Data, num: 16);
  v6 = dwTrackerID;
  this->dwID = dwTrackerID;
  dwTrackerID = v6 + 1;
  this->uDataSize = 0;
  if ( pSelected != nullptr )
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
      this: &this->Selected,
      src: pSelected);
  this->m_bAutoDestruct = true;
  this->szName[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10046950
// Name: public: CHistory::~CHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::~CHistory(CHistory *this)
{
  CUtlVector<CHistoryTrack *,CUtlMemory<CHistoryTrack *,int> > *p_Tracks; // esi

  p_Tracks = &this->Tracks;
  CUtlVector<CHistoryTrack *,CUtlMemory<CHistoryTrack *,int>>::PurgeAndDeleteElements(this: &this->Tracks);
  p_Tracks->m_Size = 0;
  if ( p_Tracks->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Tracks->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Tracks->m_Memory.m_pMemory);
      p_Tracks->m_Memory.m_pMemory = nullptr;
    }
    p_Tracks->m_Memory.m_nAllocationCount = 0;
  }
  p_Tracks->m_pElements = p_Tracks->m_Memory.m_pMemory;
  if ( p_Tracks->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_Tracks->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_Tracks->m_Memory.m_pMemory);
      p_Tracks->m_Memory.m_pMemory = nullptr;
    }
    p_Tracks->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100469E0
// Name: public: void CHistory::MarkUndoPosition(class CUtlReferenceVector<class CMapClass> const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::MarkUndoPosition(
        CHistory *this,
        const CUtlReferenceVector<CMapClass> *pSelection,
        const char *pszName,
        int bFromOpposite)
{
  CHistory *Opposite; // eax
  int v6; // ebx
  CHistoryTrack *v7; // esi
  CHistoryTrack *v8; // eax
  CHistoryTrack *v9; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CHistoryTrack **m_pMemory; // ecx
  int v13; // eax
  CHistoryTrack **v14; // ebx
  const char *v15; // edx
  char *szName; // eax
  char v17; // cl
  int v18; // eax
  int v19; // ecx
  const char *v20; // eax
  CHistoryTrack *v21; // ebx
  int v22; // eax
  int i; // [esp+20h] [ebp+8h]
  const char *pszNamea; // [esp+24h] [ebp+Ch]
  int i2; // [esp+28h] [ebp+10h]

  Opposite = this->Opposite;
  v6 = 0;
  if ( Opposite != nullptr && this->bUndo != 0 && bFromOpposite == 0 )
  {
    if ( Opposite->Tracks.m_Size > 0 )
    {
      do
      {
        v7 = this->Opposite->Tracks.m_Memory.m_pMemory[v6];
        v7->m_bAutoDestruct = true;
        CHistoryTrack::~CHistoryTrack(this: v7);
        operator delete(p: v7);
        ++v6;
      }
      while ( v6 < this->Opposite->Tracks.m_Size );
    }
    this->Opposite->Tracks.m_Size = 0;
    this->Opposite->CurTrack = nullptr;
  }
  v8 = (CHistoryTrack *)operator new(nSize: 0xB8u);
  if ( v8 != nullptr )
    v9 = CHistoryTrack::CHistoryTrack(this: v8, pParent: this, pSelected: pSelection);
  else
    v9 = nullptr;
  this->CurTrack = v9;
  m_Size = this->Tracks.m_Size;
  m_nAllocationCount = this->Tracks.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&this->Tracks,
      num: m_Size - m_nAllocationCount + 1);
  ++this->Tracks.m_Size;
  m_pMemory = this->Tracks.m_Memory.m_pMemory;
  v13 = this->Tracks.m_Size - m_Size - 1;
  this->Tracks.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &this->Tracks.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = this->CurTrack;
  v15 = pszName;
  if ( pszName != nullptr )
  {
    szName = this->CurTrack->szName;
    do
    {
      v17 = *v15;
      *szName++ = *v15++;
    }
    while ( v17 != 0 );
  }
  v18 = this->Tracks.m_Size;
  if ( v18 > Options.general.iUndoLevels )
  {
    i2 = v18 - Options.general.iUndoLevels;
    v19 = v18 - Options.general.iUndoLevels;
    if ( v18 != Options.general.iUndoLevels )
    {
      v20 = nullptr;
      while ( 1 )
      {
        v21 = *(CHistoryTrack **)&v20[(unsigned int)this->Tracks.m_Memory.m_pMemory];
        --v19;
        v20 += 4;
        i = v19;
        pszNamea = v20;
        if ( v21 == this->CurTrack )
          break;
        if ( v21 != nullptr )
        {
          CHistoryTrack::~CHistoryTrack(this: v21);
          operator delete(p: v21);
          v19 = i;
          v20 = pszNamea;
        }
        if ( v19 == 0 )
          goto LABEL_28;
      }
      i2 = v19;
LABEL_28:
      while ( i2 != 0 )
      {
        --i2;
        v22 = this->Tracks.m_Size - 1;
        if ( v22 > 0 )
          _V_memmove(dest: this->Tracks.m_Memory.m_pMemory, src: this->Tracks.m_Memory.m_pMemory + 1, count: 4 * v22);
        --this->Tracks.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046B80
// Name: public: void CHistory::Keep(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::Keep(CHistory *this, CMapClass *pObject)
{
  CMapClass *i; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-84h] BYREF

  if ( this->CurTrack == nullptr )
    CHistory::MarkUndoPosition(this, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
  CHistoryTrack::Keep(this: this->CurTrack, pObject, bKeepChildren: true);
  for ( i = CMapClass::GetFirstDescendent(this: pObject, &pos);
        i != nullptr;
        i = CMapClass::GetNextDescendent(this: pObject, &pos) )
  {
    CHistoryTrack::Keep(this: this->CurTrack, pObject: i, bKeepChildren: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046BF0
// Name: public: void CHistory::KeepNoChildren(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::KeepNoChildren(CHistory *this, CMapClass *pObject)
{
  if ( this->CurTrack == nullptr )
    CHistory::MarkUndoPosition(this, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
  CHistoryTrack::Keep(this: this->CurTrack, pObject, bKeepChildren: false);
}

//------------------------------------------------------------------------------
// Address: 0x10046C20
// Name: public: void CHistory::Keep(class CUtlReferenceVector<class CMapClass> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::Keep(CHistory *this, const CUtlReferenceVector<CMapClass> *pList)
{
  const CUtlReferenceVector<CMapClass> *v2; // esi
  int v3; // ebx
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  CMapClass *v7; // esi
  CMapClass *i; // eax
  EnumChildrenPos_t pos; // [esp+Ch] [ebp-9Ch] BYREF
  CUtlReference<CMapClass> *m_pHead; // [esp+90h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v11; // [esp+94h] [ebp-14h]
  CMapClass *pObject; // [esp+98h] [ebp-10h]
  int v13; // [esp+A4h] [ebp-4h]

  v2 = pList;
  v3 = 0;
  if ( pList->m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = v2->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&v2->m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&v2->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        pObject = v2->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&v2->m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&v2->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v6 = m_pObject->m_References.m_pHead;
        if ( v6 != nullptr )
          v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v11 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v7 = pObject;
      v13 = -1;
      if ( pObject != nullptr )
      {
        if ( v11 != nullptr )
        {
          v11->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v11;
        }
        else if ( (CUtlReference<CMapClass> **)pObject->m_References.m_pHead == &m_pHead )
        {
          pObject->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v11 = nullptr;
        m_pHead = nullptr;
        pObject = nullptr;
      }
      if ( this->CurTrack == nullptr )
        CHistory::MarkUndoPosition(this, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
      CHistoryTrack::Keep(this: this->CurTrack, pObject: v7, bKeepChildren: true);
      for ( i = CMapClass::GetFirstDescendent(this: v7, &pos);
            i != nullptr;
            i = CMapClass::GetNextDescendent(this: v7, &pos) )
      {
        CHistoryTrack::Keep(this: this->CurTrack, pObject: i, bKeepChildren: true);
      }
      if ( ++v3 >= pList->m_Size )
        break;
      v2 = pList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046D60
// Name: public: void CHistory::KeepForDestruction(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::KeepForDestruction(CHistory *this, CMapClass *pObject)
{
  if ( this->CurTrack == nullptr )
    CHistory::MarkUndoPosition(this, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
  CHistoryTrack::KeepForDestruction(this: this->CurTrack, pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10046D90
// Name: public: void CHistory::KeepNew(class CMapClass __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::KeepNew(CHistory *this, CMapClass *pObject, bool bKeepChildren)
{
  CMapClass *i; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-84h] BYREF

  if ( this->CurTrack == nullptr )
    CHistory::MarkUndoPosition(this, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
  if ( bKeepChildren )
  {
    for ( i = CMapClass::GetFirstDescendent(this: pObject, &pos);
          i != nullptr;
          i = CMapClass::GetNextDescendent(this: pObject, &pos) )
    {
      CHistoryTrack::KeepNew(this: this->CurTrack, pObject: i);
    }
  }
  CHistoryTrack::KeepNew(this: this->CurTrack, pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10046E00
// Name: public: void CHistory::KeepNew(class CUtlReferenceVector<class CMapClass> const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::KeepNew(CHistory *this, const CUtlReferenceVector<CMapClass> *pList, bool bKeepChildren)
{
  int v3; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  CMapClass *v6; // esi
  CMapClass *j; // eax
  EnumChildrenPos_t pos; // [esp+8h] [ebp-A0h] BYREF
  CHistory *i; // [esp+8Ch] [ebp-1Ch]
  CUtlReference<CMapClass> *m_pHead; // [esp+90h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v11; // [esp+94h] [ebp-14h]
  CMapClass *pObject; // [esp+98h] [ebp-10h]
  int v13; // [esp+A4h] [ebp-4h]

  v3 = 0;
  for ( i = this; v3 < pList->m_Size; ++v3 )
  {
    m_pObject = pList->m_Memory.m_pMemory[v3 >> (*((int *)&pList->m_Memory + 2) >> 27)][v3
                                                                                      & ((32
                                                                                        * *((_DWORD *)&pList->m_Memory
                                                                                          + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      pObject = pList->m_Memory.m_pMemory[v3 >> (*((int *)&pList->m_Memory + 2) >> 27)][v3
                                                                                      & ((32
                                                                                        * *((_DWORD *)&pList->m_Memory
                                                                                          + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v5 = m_pObject->m_References.m_pHead;
      if ( v5 != nullptr )
        v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v11 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v6 = pObject;
    v13 = -1;
    if ( pObject != nullptr )
    {
      if ( v11 != nullptr )
      {
        v11->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v11;
      }
      else if ( (CUtlReference<CMapClass> **)pObject->m_References.m_pHead == &m_pHead )
      {
        pObject->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v11 = nullptr;
      m_pHead = nullptr;
      pObject = nullptr;
    }
    if ( i->CurTrack == nullptr )
      CHistory::MarkUndoPosition(this: i, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
    if ( bKeepChildren )
    {
      for ( j = CMapClass::GetFirstDescendent(this: v6, &pos);
            j != nullptr;
            j = CMapClass::GetNextDescendent(this: v6, &pos) )
      {
        CHistoryTrack::KeepNew(this: i->CurTrack, pObject: j);
      }
    }
    CHistoryTrack::KeepNew(this: i->CurTrack, pObject: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046F40
// Name: public: void CTrackEntry::Undo(class CHistory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTrackEntry::Undo(CTrackEntry *this, CHistory *Opposite)
{
  CTrackEntry::TrackType_t m_eType; // eax
  __int32 v4; // eax
  CMapClass *v5; // ebx
  CMapClass *v6; // ebx
  CMapClass *pCurrent; // ebx
  CMapClass *pKeptObject; // ecx

  m_eType = this->m_eType;
  if ( m_eType == ttCopy )
  {
    if ( this->m_bKeptChildren )
    {
      CHistory::Keep(this: Opposite, pObject: this->m_Copy.pCurrent);
    }
    else
    {
      pCurrent = this->m_Copy.pCurrent;
      if ( Opposite->CurTrack == nullptr )
        CHistory::MarkUndoPosition(this: Opposite, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
      CHistoryTrack::Keep(this: Opposite->CurTrack, pObject: pCurrent, bKeepChildren: false);
    }
    this->m_Copy.pCurrent->CopyFrom(this: this->m_Copy.pCurrent, a2: this->m_Copy.pKeptObject, a3: true);
    pKeptObject = this->m_Copy.pKeptObject;
    if ( pKeptObject != nullptr )
      ((void (__thiscall *)(CMapClass *, int))pKeptObject->~CMapClass)(a1: pKeptObject, a2: 1);
    this->m_Copy.pKeptObject = nullptr;
    goto LABEL_18;
  }
  v4 = m_eType - 1;
  if ( v4 != 0 )
  {
    if ( v4 == 1 )
    {
      v5 = this->m_Copy.pCurrent;
      if ( Opposite->CurTrack == nullptr )
        CHistory::MarkUndoPosition(this: Opposite, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
      CHistoryTrack::KeepForDestruction(this: Opposite->CurTrack, pObject: v5);
      CMapDoc::RemoveObjectFromWorld(this: Opposite->m_pDoc, pObject: this->m_Copy.pCurrent, bRemoveChildren: false);
      this->m_Copy.pCurrent = nullptr;
      this->m_bUndone = true;
      return;
    }
LABEL_18:
    this->m_bUndone = true;
    return;
  }
  this->m_Copy.pCurrent->m_pParent = this->m_Copy.pKeptObject;
  v6 = this->m_Copy.pCurrent;
  if ( Opposite->CurTrack == nullptr )
    CHistory::MarkUndoPosition(this: Opposite, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
  CHistoryTrack::KeepNew(this: Opposite->CurTrack, pObject: v6);
  Opposite->m_pDoc->AddObjectToWorld(this: Opposite->m_pDoc, a2: this->m_Copy.pCurrent, a3: this->m_Copy.pKeptObject);
  this->m_bUndone = true;
}

//------------------------------------------------------------------------------
// Address: 0x10047050
// Name: public: void CHistoryTrack::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryTrack::Undo(CHistoryTrack *this)
{
  int v2; // esi
  int v3; // ebx
  int v4; // ebx
  int v5; // eax
  bool *v6; // esi
  int v7; // [esp+Ch] [ebp-4h]

  v2 = this->Data.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CTrackEntry::Undo(this: &this->Data.m_Memory.m_pMemory[v3--], Opposite: this->Parent->Opposite);
      --v2;
    }
    while ( v2 >= 0 );
  }
  v4 = this->Data.m_Size - 1;
  if ( v4 >= 0 )
  {
    v5 = 24 * v4;
    v7 = 24 * v4;
    do
    {
      v6 = &this->Data.m_Memory.m_pMemory->m_bAutoDestruct + v5;
      if ( *((_DWORD *)v6 + 2) == 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 3) + 168))(a1: *((_DWORD *)v6 + 3));
        CMapClass::NotifyDependents(this: *((CMapClass **)v6 + 3), eNotifyType: Notify_Changed);
        v5 = v7;
      }
      v5 -= 24;
      --v4;
      v7 = v5;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100470D0
// Name: public: void CHistory::SetActive(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::SetActive(CHistory *this, int bActive)
{
  int i; // edi
  CHistoryTrack **m_pMemory; // eax
  CHistoryTrack *v5; // ebx

  this->m_bActive = bActive;
  if ( bActive == 0 )
  {
    for ( i = 0; i < this->Tracks.m_Size; ++i )
    {
      m_pMemory = this->Tracks.m_Memory.m_pMemory;
      v5 = m_pMemory[i];
      if ( v5 != nullptr )
      {
        CHistoryTrack::~CHistoryTrack(this: m_pMemory[i]);
        operator delete(p: v5);
      }
    }
    this->Tracks.m_Size = 0;
    CHistory::MarkUndoPosition(this, pSelection: nullptr, pszName: nullptr, bFromOpposite: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047130
// Name: public: void CHistory::Undo(class CUtlReferenceVector<class CMapClass> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistory::Undo(CHistory *this, CUtlReferenceVector<CMapClass> *pNewSelection)
{
  CHistoryTrack *CurTrack; // eax
  char *szName; // ecx
  CHistoryTrack *v5; // ecx
  CHistoryTrack *v6; // edi
  int m_Size; // eax

  CurTrack = this->CurTrack;
  szName = this->CurTrack->szName;
  if ( CurTrack == nullptr )
    szName = (char *)&var;
  CHistory::MarkUndoPosition(this: this->Opposite, pSelection: &CurTrack->Selected, pszName: szName, bFromOpposite: 1);
  --this->Tracks.m_Size;
  v5 = this->CurTrack;
  this->bPaused = 1;
  CHistoryTrack::Undo(this: v5);
  if ( this->bPaused == 1 )
    this->bPaused = 0;
  CUtlReferenceVector<CMapClass>::RemoveAll(this: pNewSelection);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::AddVectorToTail(
    this: pNewSelection,
    src: &this->CurTrack->Selected);
  v6 = this->CurTrack;
  this->uDataSize -= this->CurTrack->uDataSize;
  if ( v6 != nullptr )
  {
    CHistoryTrack::~CHistoryTrack(this: v6);
    operator delete(p: v6);
  }
  m_Size = this->Tracks.m_Size;
  if ( m_Size <= 0 )
    this->CurTrack = nullptr;
  else
    this->CurTrack = this->Tracks.m_Memory.m_pMemory[m_Size - 1];
}
