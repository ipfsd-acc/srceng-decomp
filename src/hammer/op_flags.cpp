// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/op_flags.cpp
// Functions: 57
// ============================================================

#include "hammer\op_flags.h"

//------------------------------------------------------------------------------
// Address: 0x100E40B0
// Name: public: virtual struct CRuntimeClass __near * COP_Flags::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COP_Flags::GetRuntimeClass(COP_Flags *this)
{
  return &COP_Flags::classCOP_Flags;
}

//------------------------------------------------------------------------------
// Address: 0x100E40C0
// Name: public: void COP_Flags::SetEntityPage(class COP_Entity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::SetEntityPage(COP_Flags *this, COP_Entity *pPage)
{
  this->m_pEntityPage = pPage;
}

//------------------------------------------------------------------------------
// Address: 0x100E40D0
// Name: protected: void COP_Flags::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::OnSize(COP_Flags *this, unsigned int nType, unsigned int cx, int cy)
{
  CAnchorMgr::OnSize(this: &this->m_AnchorMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100E40E0
// Name: public: CCheckListBox::CCheckListBox(void)
// Source: json
//------------------------------------------------------------------------------
CCheckListBox *__thiscall CCheckListBox::CCheckListBox(CCheckListBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CCheckListBox_vtbl *)&CListBox::`vftable';
  this->__vftable = (CCheckListBox_vtbl *)&CCheckListBox::`vftable';
  this->m_cyText = 0;
  this->m_nStyle = 0;
  this->m_bEnableActiveAccessibility = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E4140
// Name: protected: virtual int COP_Flags::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COP_Flags::OnInitDialog(COP_Flags *this)
{
  CAnchorDef anchorDefs[1]; // [esp+8h] [ebp-2Ch] BYREF

  CDialog::OnInitDialog(this);
  this->m_nNumSelectedObjects = 0;
  CWnd::SubclassDlgItem(this: &this->m_CheckList, nID: 0x44Au, pParent: this);
  CCheckListBox::SetCheckStyle(this: &this->m_CheckList, nStyle: 3u);
  SendMessageA(hWnd: this->m_CheckList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  CAnchorDef::CAnchorDef(this: anchorDefs, dlgItemID: 1098, eSimpleAnchor: k_eSimpleAnchorAllSides);
  CAnchorMgr::Init(this: &this->m_AnchorMgr, hParentWnd: this->m_hWnd, pAnchors: anchorDefs, nAnchors: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E4210
// Name: protected: virtual struct AFX_MSGMAP const __near * COP_Flags::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COP_Flags::GetMessageMap(COP_Flags *this)
{
  if ( (_S1_17 & 1) == 0 )
  {
    _S1_17 |= 1u;
    dword_107308C4 = (int)COP_Flags::OnSize;
    dword_107308C8 = 0;
    dword_107308CC = 0;
    dword_107308D0 = 0;
    dword_107308D4 = 0;
    dword_107308D8 = 0;
    dword_107308DC = 0;
  }
  return (const AFX_MSGMAP *)&off_105EED14;
}

//------------------------------------------------------------------------------
// Address: 0x100E4290
// Name: public: void COP_Flags::MergeForClass(class CEditGameClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::MergeForClass(COP_Flags *this, CEditGameClass *pObj)
{
  COP_Flags *v2; // esi
  GDclass *v3; // edi
  GDinputvariable *v4; // eax
  int v5; // ecx
  GDinputvariable *v6; // ebx
  int v7; // edx
  int v8; // edi
  unsigned int iValue; // esi
  int m_Size; // eax
  CheckListItem *m_pMemory; // ecx
  __int64 v12; // xmm0_8
  int v13; // eax
  char *v14; // ecx
  __int64 currentItem; // [esp+8h] [ebp-1Ch]
  int currentItem_8; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int v19; // [esp+1Ch] [ebp-8h]

  v2 = this;
  v3 = GameData::ClassForName(this: pGD, pszName: pObj->m_szClass, piIndex: nullptr);
  if ( IsWindow(hWnd: v2->m_hWnd) )
  {
    ++v2->m_nNumSelectedObjects;
    if ( v3 != nullptr )
    {
      v4 = GDclass::VarForName(this: v3, pszName: "spawnflags", piIndex: nullptr);
      v5 = v2->m_CheckListItems.m_Size - 1;
      v6 = v4;
      i = v5;
      if ( v5 >= 0 )
      {
        v7 = 12 * v5;
        v19 = v5;
        do
        {
          v8 = 0;
          currentItem = *(_QWORD *)((char *)&v2->m_CheckListItems.m_Memory.m_pMemory->pszItemString + v7);
          currentItem_8 = *(int *)((char *)&v2->m_CheckListItems.m_Memory.m_pMemory->state + v7);
          if ( v6 != nullptr && (j = 0, v6->m_Items.m_Size > 0) )
          {
            while ( 1 )
            {
              iValue = v6->m_Items.m_Memory.m_pMemory[v8].iValue;
              if ( HIDWORD(currentItem) == iValue
                && _V_strcmp(s1: (const char *)currentItem, s2: v6->m_Items.m_Memory.m_pMemory[v8].szCaption) == 0 )
              {
                break;
              }
              ++v8;
              if ( ++j >= v6->m_Items.m_Size )
              {
                v2 = this;
                v5 = i;
                v7 = v19 * 12;
                goto LABEL_11;
              }
            }
            if ( currentItem_8 != CEditGameClass::GetSpawnFlag(this: pObj, nFlags: iValue) )
              this->m_CheckListItems.m_Memory.m_pMemory[v19].state = 2;
            v2 = this;
          }
          else
          {
LABEL_11:
            m_Size = v2->m_CheckListItems.m_Size;
            if ( m_Size > 0 )
            {
              if ( v5 != m_Size - 1 )
              {
                m_pMemory = v2->m_CheckListItems.m_Memory.m_pMemory;
                v12 = *(_QWORD *)&m_pMemory[m_Size - 1].pszItemString;
                v13 = (int)&m_pMemory[m_Size - 1];
                v14 = (char *)m_pMemory + v7;
                *(_QWORD *)v14 = v12;
                *((_DWORD *)v14 + 2) = *(_DWORD *)(v13 + 8);
              }
              --v2->m_CheckListItems.m_Size;
            }
          }
          v5 = i - 1;
          v7 = v19 * 12 - 12;
          i = v5;
          --v19;
        }
        while ( v5 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E43F0
// Name: public: void COP_Flags::CreateCheckList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::CreateCheckList(COP_Flags *this)
{
  signed int v2; // esi
  int v3; // ebx
  int newItem_8; // [esp+10h] [ebp-4h]

  SendMessageA(hWnd: this->m_CheckList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  if ( this->m_nNumSelectedObjects > 1 )
    CCheckListBox::SetCheckStyle(this: &this->m_CheckList, nStyle: 6u);
  v2 = 0;
  if ( this->m_CheckListItems.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      newItem_8 = this->m_CheckListItems.m_Memory.m_pMemory[v3].state;
      SendMessageA(
        hWnd: this->m_CheckList.m_hWnd,
        Msg: 0x181u,
        wParam: v2,
        lParam: (LPARAM)this->m_CheckListItems.m_Memory.m_pMemory[v3].pszItemString);
      CCheckListBox::SetCheck(this: &this->m_CheckList, nIndex: v2++, nCheck: newItem_8);
      ++v3;
    }
    while ( v2 < this->m_CheckListItems.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E44A0
// Name: public: void COP_Flags::OnUpdateSpawnFlags(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::OnUpdateSpawnFlags(COP_Flags *this, unsigned int value)
{
  int v3; // esi
  int v4; // ebx

  v3 = 0;
  if ( this->m_CheckListItems.m_Size > 0 )
  {
    v4 = 0;
    do
      CCheckListBox::SetCheck(
        this: &this->m_CheckList,
        nIndex: v3++,
        nCheck: (value & this->m_CheckListItems.m_Memory.m_pMemory[v4++].nItemBit) != 0);
    while ( v3 < this->m_CheckListItems.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4500
// Name: protected: virtual void COP_Flags::OnCheckListChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::OnCheckListChange(COP_Flags *this)
{
  int v2; // esi
  int v3; // ebx
  __int64 currentItem; // [esp+8h] [ebp-14h]
  unsigned int triStateMask; // [esp+14h] [ebp-8h]
  unsigned int bitsSet; // [esp+18h] [ebp-4h]

  v2 = 0;
  if ( this->m_pEntityPage != nullptr )
  {
    bitsSet = 0;
    triStateMask = 0;
    if ( this->m_CheckListItems.m_Size > 0 )
    {
      v3 = 0;
      do
      {
        currentItem = *(_QWORD *)&this->m_CheckListItems.m_Memory.m_pMemory[v3].pszItemString;
        if ( CCheckListBox::GetCheck(this: &this->m_CheckList, nIndex: v2) == 2 )
        {
          triStateMask |= HIDWORD(currentItem);
        }
        else if ( CCheckListBox::GetCheck(this: &this->m_CheckList, nIndex: v2) != 0 )
        {
          bitsSet |= HIDWORD(currentItem);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->m_CheckListItems.m_Size );
    }
    COP_Entity::OnUpdateSpawnFlags(this: this->m_pEntityPage, preserveMask: triStateMask, newValues: bitsSet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E45A0
// Name: public: virtual COP_Flags::~COP_Flags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::~COP_Flags(COP_Flags *this)
{
  CUtlVector<CheckListItem,CUtlMemory<CheckListItem,int> > *p_m_CheckListItems; // esi

  this->__vftable = (COP_Flags_vtbl *)&COP_Flags::`vftable';
  p_m_CheckListItems = &this->m_CheckListItems;
  this->m_CheckListItems.m_Size = 0;
  if ( this->m_CheckListItems.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_CheckListItems->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_CheckListItems->m_Memory.m_pMemory);
      p_m_CheckListItems->m_Memory.m_pMemory = nullptr;
    }
    p_m_CheckListItems->m_Memory.m_nAllocationCount = 0;
  }
  p_m_CheckListItems->m_pElements = p_m_CheckListItems->m_Memory.m_pMemory;
  if ( p_m_CheckListItems->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_CheckListItems->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_CheckListItems->m_Memory.m_pMemory);
      p_m_CheckListItems->m_Memory.m_pMemory = nullptr;
    }
    p_m_CheckListItems->m_Memory.m_nAllocationCount = 0;
  }
  CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>(this: (TextureWindowTexList *)&this->m_AnchorMgr);
  CListBox::~CListBox(this: &this->m_CheckList);
  this->__vftable = (COP_Flags_vtbl *)&CObjectPage::`vftable';
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E4670
// Name: public: void COP_Flags::UpdateForClass(class CEditGameClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::UpdateForClass(COP_Flags *this, CEditGameClass *pObj)
{
  COP_Flags *v2; // edi
  GDclass *v3; // ebx
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_CheckListItems; // esi
  GDinputvariable *v5; // eax
  GDinputvariable *v6; // ebx
  int v7; // edi
  GDIVITEM *v8; // eax
  bool SpawnFlag; // al
  unsigned int v10; // ebx
  int v11; // edx
  int v12; // ecx
  _DWORD *p_y; // eax
  int v14; // edi
  int m_nAllocationCount; // eax
  Vector *m_pMemory; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // [esp-Ch] [ebp-28h]
  CheckListItem newItem; // [esp+8h] [ebp-14h] BYREF
  int m_Size; // [esp+14h] [ebp-8h]
  COP_Flags *v23; // [esp+18h] [ebp-4h]

  v2 = this;
  v23 = this;
  v3 = GameData::ClassForName(this: pGD, pszName: pObj->m_szClass, piIndex: nullptr);
  if ( IsWindow(hWnd: v2->m_hWnd) )
  {
    p_m_CheckListItems = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&v2->m_CheckListItems;
    v2->m_nNumSelectedObjects = 1;
    v2->m_CheckListItems.m_Size = 0;
    if ( v3 != nullptr )
    {
      v5 = GDclass::VarForName(this: v3, pszName: "spawnflags", piIndex: nullptr);
      v6 = v5;
      if ( v5 != nullptr && v5->m_Items.m_Size > 0 )
      {
        v7 = 0;
        m_Size = v5->m_Items.m_Size;
        do
        {
          v8 = &v6->m_Items.m_Memory.m_pMemory[v7];
          newItem.nItemBit = v8->iValue;
          newItem.pszItemString = v8->szCaption;
          SpawnFlag = CEditGameClass::GetSpawnFlag(this: pObj, nFlags: newItem.nItemBit);
          v20 = p_m_CheckListItems->m_Size;
          newItem.state = SpawnFlag;
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: p_m_CheckListItems,
            elem: v20,
            src: (const Vector *)&newItem);
          ++v7;
          --m_Size;
        }
        while ( m_Size != 0 );
        v2 = v23;
      }
    }
    v10 = 1;
    for ( m_Size = 32; m_Size != 0; --m_Size )
    {
      if ( CEditGameClass::GetSpawnFlag(this: pObj, nFlags: v10) )
      {
        v11 = v2->m_CheckListItems.m_Size;
        v12 = 0;
        if ( v11 > 0 )
        {
          p_y = (_DWORD *)&p_m_CheckListItems->m_Memory.m_pMemory->y;
          do
          {
            if ( *p_y == v10 )
              break;
            ++v12;
            p_y += 3;
          }
          while ( v12 < v11 );
        }
        if ( v12 == v11 )
        {
          v14 = p_m_CheckListItems->m_Size;
          m_nAllocationCount = p_m_CheckListItems->m_Memory.m_nAllocationCount;
          newItem.nItemBit = v10;
          newItem.pszItemString = "????";
          if ( v14 + 1 > m_nAllocationCount )
            CUtlMemory<CheckListItem,int>::Grow(this: &p_m_CheckListItems->m_Memory, num: v14 - m_nAllocationCount + 1);
          ++p_m_CheckListItems->m_Size;
          m_pMemory = p_m_CheckListItems->m_Memory.m_pMemory;
          v17 = p_m_CheckListItems->m_Size - v14 - 1;
          p_m_CheckListItems->m_pElements = p_m_CheckListItems->m_Memory.m_pMemory;
          if ( v17 > 0 )
            _V_memmove(dest: &m_pMemory[v14 + 1], src: &m_pMemory[v14], count: 12 * v17);
          v18 = v14;
          v2 = v23;
          v19 = (int)&p_m_CheckListItems->m_Memory.m_pMemory[v18];
          if ( v19 != 0 )
          {
            *(_QWORD *)v19 = *(_QWORD *)&newItem.pszItemString;
            *(_DWORD *)(v19 + 8) = 1;
          }
        }
      }
      v10 = __ROL4__(v10, 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E47F0
// Name: public: COP_Flags::COP_Flags(void)
// Source: json
//------------------------------------------------------------------------------
COP_Flags *__thiscall COP_Flags::COP_Flags(COP_Flags *this)
{
  CheckListItem *m_pMemory; // ecx

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x93u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COP_Flags_vtbl *)&CObjectPage::`vftable';
  this->m_bMultiEdit = false;
  this->m_bFirstTimeActive = false;
  this->__vftable = (COP_Flags_vtbl *)&COP_Flags::`vftable';
  CWnd::CWnd(this: &this->m_CheckList);
  this->m_CheckList.__vftable = (CCheckListBox_vtbl *)&CListBox::`vftable';
  this->m_CheckList.__vftable = (CCheckListBox_vtbl *)&CCheckListBox::`vftable';
  this->m_CheckList.m_cyText = 0;
  this->m_CheckList.m_nStyle = 0;
  this->m_CheckList.m_bEnableActiveAccessibility = true;
  CAnchorMgr::CAnchorMgr(this: &this->m_AnchorMgr);
  this->m_CheckListItems.m_Memory.m_pMemory = nullptr;
  this->m_CheckListItems.m_Memory.m_nAllocationCount = 0;
  this->m_CheckListItems.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_CheckListItems.m_Memory.m_pMemory;
  this->m_CheckListItems.m_Size = 0;
  this->m_CheckListItems.m_pElements = m_pMemory;
  this->m_pEditObjectRuntimeClass = &editCEditGameClass::classeditCEditGameClass;
  this->m_nNumSelectedObjects = 0;
  this->m_pEntityPage = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100E4910
// Name: public: virtual void COP_Flags::UpdateData(int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COP_Flags::UpdateData(COP_Flags *this, int Mode, CEditGameClass *pData, bool bCanEdit)
{
  CObjectPage::UpdateData(this, Mode, pData, bCanEdit);
  if ( IsWindow(hWnd: this->m_hWnd) && pData != nullptr )
  {
    if ( Mode != 0 )
    {
      if ( Mode == 1 )
        COP_Flags::MergeForClass(this, pObj: pData);
    }
    else
    {
      COP_Flags::UpdateForClass(this, pObj: pData);
    }
    COP_Flags::CreateCheckList(this);
    CWnd::EnableWindow(this: &this->m_CheckList, bEnable: this->m_bCanEdit);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E4980
// Name: public: virtual bool COP_Flags::SaveData(enum SaveData_Reason_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COP_Flags::SaveData(COP_Flags *this, SaveData_Reason_t reason)
{
  const CUtlReferenceVector<CMapClass> *m_pObjectList; // edx
  int v5; // esi
  int v6; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v8; // ecx
  void *v9; // edx
  COP_Flags *v10; // ebx
  int v11; // edi
  int v12; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-38h]
  __int64 currentItem; // [esp+4h] [ebp-30h]
  CUtlReference<CMapClass> *m_pHead; // [esp+10h] [ebp-24h] BYREF
  CUtlReference<CMapClass> *v16; // [esp+14h] [ebp-20h]
  void *inptr; // [esp+18h] [ebp-1Ch]
  CEditGameClass *pEdit; // [esp+1Ch] [ebp-18h]
  int pos; // [esp+20h] [ebp-14h]
  COP_Flags *v20; // [esp+24h] [ebp-10h]
  int v21; // [esp+30h] [ebp-4h]

  m_hWnd = this->m_hWnd;
  v20 = this;
  if ( !IsWindow(hWnd: m_hWnd) )
    return 0;
  m_pObjectList = this->m_pObjectList;
  v5 = 0;
  v6 = 0;
  for ( pos = 0; v6 < m_pObjectList->m_Size; pos = v6 )
  {
    m_pObject = m_pObjectList->m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&m_pObjectList->m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      inptr = m_pObjectList->m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&m_pObjectList->m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&m_pObjectList->m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v8 = m_pObject->m_References.m_pHead;
      if ( v8 != nullptr )
        v8->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v16 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v9 = inptr;
    v21 = -1;
    if ( inptr != nullptr )
    {
      if ( v16 != nullptr )
      {
        v16->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v16;
      }
      else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
      {
        *((_DWORD *)inptr + 8) = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v16 = nullptr;
      m_pHead = nullptr;
      inptr = nullptr;
    }
    pEdit = (CEditGameClass *)__RTDynamicCast(
                                inptr: v9,
                                VfDelta: 0,
                                SrcType: &CMapClass `RTTI Type Descriptor',
                                TargetType: &CEditGameClass `RTTI Type Descriptor',
                                isReference: 0);
    if ( pEdit != nullptr )
    {
      v10 = v20;
      if ( v20->m_CheckListItems.m_Size > 0 )
      {
        v11 = 0;
        do
        {
          currentItem = *(_QWORD *)&v10->m_CheckListItems.m_Memory.m_pMemory[v11].pszItemString;
          if ( CCheckListBox::GetCheck(this: &v10->m_CheckList, nIndex: v5) != 2 )
          {
            v12 = CCheckListBox::GetCheck(this: &v10->m_CheckList, nIndex: v5);
            CEditGameClass::SetSpawnFlag(this: pEdit, nFlags: HIDWORD(currentItem), bSet: v12 != 0);
          }
          ++v5;
          ++v11;
        }
        while ( v5 < v10->m_CheckListItems.m_Size );
        v6 = pos;
        v5 = 0;
      }
    }
    m_pObjectList = v20->m_pObjectList;
    ++v6;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E4B30
// Name: public: static class CObject __near * COP_Flags::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COP_Flags *__stdcall COP_Flags::CreateObject()
{
  COP_Flags *v0; // eax

  v0 = (COP_Flags *)operator new(nSize: 0x174u);
  if ( v0 != nullptr )
    return COP_Flags::COP_Flags(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1035DC30
// Name: public: virtual int CCheckListBox::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::Create(
        CCheckListBox *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  if ( (dwStyle & 0x20) == 0 )
    dwStyle |= 0x10u;
  return CListBox::Create(this, dwStyle, rect, pParentWnd, nID);
}

//------------------------------------------------------------------------------
// Address: 0x1035DC45
// Name: public: void CCheckListBox::SetCheckStyle(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::SetCheckStyle(CCheckListBox *this, unsigned int nStyle)
{
  this->m_nStyle = nStyle;
}

//------------------------------------------------------------------------------
// Address: 0x1035DC54
// Name: public: int CCheckListBox::GetCheck(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::GetCheck(CCheckListBox *this, unsigned int nIndex)
{
  int v2; // eax

  v2 = this->DefWindowProcA(this, a2: 409u, a3: nIndex, a4: 0);
  if ( v2 == -1 || v2 == 0 )
    return 0;
  else
    return *(_DWORD *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x1035DC7E
// Name: public: int CCheckListBox::IsEnabled(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::IsEnabled(CCheckListBox *this, unsigned int nIndex)
{
  int v2; // eax

  v2 = this->DefWindowProcA(this, a2: 409u, a3: nIndex, a4: 0);
  if ( v2 == -1 || v2 == 0 )
    return 1;
  else
    return *(_DWORD *)(v2 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1035DCAA
// Name: public: virtual class CRect CCheckListBox::OnGetCheckPosition(class CRect,class CRect)
// Source: json
//------------------------------------------------------------------------------
CRect *__thiscall CCheckListBox::OnGetCheckPosition(
        CCheckListBox *this,
        CRect *result,
        CRect __formal,
        CRect rectCheckBox)
{
  *result = rectCheckBox;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035DCC3
// Name: protected: void CCheckListBox::PreDrawItemHelper(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::PreDrawItemHelper(CCheckListBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  unsigned int itemData; // eax

  itemData = lpDrawItemStruct->itemData;
  if ( itemData != 0 && itemData != -1 )
    lpDrawItemStruct->itemData = *(_DWORD *)(itemData + 8);
  this->DrawItem(this, a2: lpDrawItemStruct);
}

//------------------------------------------------------------------------------
// Address: 0x1035DCEA
// Name: protected: int CCheckListBox::PreCompareItem(struct tagCOMPAREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::PreCompareItem(CCheckListBox *this, tagCOMPAREITEMSTRUCT *lpCompareItemStruct)
{
  tagCOMPAREITEMSTRUCT compareItem; // [esp+8h] [ebp-20h] BYREF

  compareItem = *lpCompareItemStruct;
  if ( compareItem.itemData1 != 0 && compareItem.itemData1 != -1 )
    compareItem.itemData1 = *(_DWORD *)(compareItem.itemData1 + 8);
  if ( compareItem.itemData2 != 0 && compareItem.itemData2 != -1 )
    compareItem.itemData2 = *(_DWORD *)(compareItem.itemData2 + 8);
  return this->CompareItem(this, a2: &compareItem);
}

//------------------------------------------------------------------------------
// Address: 0x1035DD39
// Name: protected: void CCheckListBox::PreDeleteItem(struct tagDELETEITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::PreDeleteItem(CCheckListBox *this, tagDELETEITEMSTRUCT *lpDeleteItemStruct)
{
  unsigned int *itemData; // eax
  unsigned int v4; // eax
  tagDELETEITEMSTRUCT deleteItem; // [esp+Ch] [ebp-14h] BYREF

  deleteItem = *lpDeleteItemStruct;
  itemData = (unsigned int *)deleteItem.itemData;
  if ( deleteItem.itemData != 0 )
    goto LABEL_5;
  v4 = this->DefWindowProcA(this, a2: 409u, a3: deleteItem.itemID, a4: 0);
  if ( v4 != -1 )
    deleteItem.itemData = v4;
  itemData = (unsigned int *)deleteItem.itemData;
  if ( deleteItem.itemData != 0 )
  {
LABEL_5:
    if ( itemData != (unsigned int *)-1 )
    {
      deleteItem.itemData = itemData[2];
      operator delete(p: itemData);
    }
  }
  this->DeleteItem(this, a2: &deleteItem);
}

//------------------------------------------------------------------------------
// Address: 0x1035DDA2
// Name: protected: long CCheckListBox::OnLBAddString(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBAddString(CCheckListBox *this, unsigned int wParam, _DWORD *lParam)
{
  unsigned __int64 v3; // rdi
  _DWORD *v4; // eax

  HIDWORD(v3) = this;
  LODWORD(v3) = 0;
  if ( (CWnd::GetStyle(this) & 0x40) == 0 )
  {
    v4 = operator new(nSize: 0xCu);
    if ( v4 != nullptr )
    {
      *v4 = 0;
      v4[2] = 0;
      v4[1] = 1;
    }
    else
    {
      v4 = nullptr;
    }
    LODWORD(v3) = v4;
    v4[2] = lParam;
    lParam = v4;
  }
  HIDWORD(v3) = (*(int (__thiscall **)(_DWORD, int, unsigned int, _DWORD *))(*(_DWORD *)HIDWORD(v3) + 284))(
                  a1: HIDWORD(v3),
                  a2: 384,
                  a3: wParam,
                  a4: lParam);
  if ( v3 > 0xFFFFFFFF00000000uLL )
    operator delete(p: (void *)v3);
  return HIDWORD(v3);
}

//------------------------------------------------------------------------------
// Address: 0x1035DE0C
// Name: protected: long CCheckListBox::OnLBGetItemData(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBGetItemData(CCheckListBox *this, unsigned int wParam, int lParam)
{
  int result; // eax

  result = this->DefWindowProcA(this, a2: 409u, a3: wParam, a4: lParam);
  if ( result != -1 && result != 0 )
    return *(_DWORD *)(result + 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035DE34
// Name: protected: long CCheckListBox::OnLBGetText(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBGetText(CCheckListBox *this, unsigned int wParam, int lParam)
{
  int v4; // edi

  v4 = this->DefWindowProcA(this, a2: 393u, a3: wParam, a4: lParam);
  CWnd::GetStyle(this);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1035DE61
// Name: protected: long CCheckListBox::OnLBInsertString(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBInsertString(CCheckListBox *this, unsigned int wParam, _DWORD *lParam)
{
  unsigned __int64 v3; // rdi
  _DWORD *v4; // eax

  HIDWORD(v3) = this;
  LODWORD(v3) = 0;
  if ( (CWnd::GetStyle(this) & 0x40) == 0 )
  {
    v4 = operator new(nSize: 0xCu);
    if ( v4 != nullptr )
    {
      *v4 = 0;
      v4[2] = 0;
      v4[1] = 1;
    }
    else
    {
      v4 = nullptr;
    }
    LODWORD(v3) = v4;
    v4[2] = lParam;
    lParam = v4;
  }
  HIDWORD(v3) = (*(int (__thiscall **)(_DWORD, int, unsigned int, _DWORD *))(*(_DWORD *)HIDWORD(v3) + 284))(
                  a1: HIDWORD(v3),
                  a2: 385,
                  a3: wParam,
                  a4: lParam);
  if ( v3 > 0xFFFFFFFF00000000uLL )
    operator delete(p: (void *)v3);
  return HIDWORD(v3);
}

//------------------------------------------------------------------------------
// Address: 0x1035DECB
// Name: protected: long CCheckListBox::OnLBSetItemData(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBSetItemData(CCheckListBox *this, unsigned int wParam, int lParam)
{
  int v4; // eax
  int v5; // edi
  _DWORD *v6; // ebx
  _DWORD *v7; // eax

  v4 = this->DefWindowProcA(this, a2: 409u, a3: wParam, a4: 0);
  v5 = v4;
  if ( v4 != -1 )
  {
    v6 = (_DWORD *)v4;
    if ( v4 == 0 )
    {
      v7 = operator new(nSize: 0xCu);
      if ( v7 != nullptr )
      {
        *v7 = 0;
        v7[2] = 0;
        v7[1] = 1;
      }
      else
      {
        v7 = nullptr;
      }
      v6 = v7;
    }
    v6[2] = lParam;
    v5 = this->DefWindowProcA(this, a2: 410u, a3: wParam, a4: (int)v6);
    if ( v5 == -1 )
      operator delete(p: v6);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1035DF42
// Name: protected: virtual long CCheckListBox::get_accState(struct tagVARIANT,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CCheckListBox::get_accState(CCheckListBox *this, tagVARIANT varChild, tagVARIANT *pvarState)
{
  int accState; // esi
  int v4; // eax

  accState = CWnd::get_accState(this, varChild, pvarState);
  if ( accState >= 0 && pvarState->vt == 3 && varChild.decVal.Lo32 != 0 )
  {
    v4 = CCheckListBox::GetCheck(this, nIndex: varChild.decVal.Lo32 - 1);
    if ( v4 == 1 )
    {
      pvarState->decVal.Lo32 |= 0x10u;
    }
    else if ( v4 == 2 )
    {
      pvarState->decVal.Lo32 |= 0x20u;
    }
  }
  return accState;
}

//------------------------------------------------------------------------------
// Address: 0x1035DF9D
// Name: public: virtual struct CRuntimeClass __near * CCheckListBox::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CCheckListBox::GetRuntimeClass(CCheckListBox *this)
{
  return &CCheckListBox::classCCheckListBox;
}

//------------------------------------------------------------------------------
// Address: 0x1035E0A6
// Name: protected: bool CCheckListBox::PreDrawItemThemed(class CDC __near *,struct tagDRAWITEMSTRUCT __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCheckListBox::PreDrawItemThemed(
        CCheckListBox *this,
        CDC *pDC,
        tagDRAWITEMSTRUCT *drawItem,
        int nCheck,
        int cyItem)
{
  int v6; // eax
  tagSIZE size; // [esp+Ch] [ebp-50h] BYREF
  CCheckListBox *v9; // [esp+14h] [ebp-48h]
  RECT *lprcSrc; // [esp+18h] [ebp-44h]
  void *hTheme; // [esp+1Ch] [ebp-40h]
  int nState; // [esp+20h] [ebp-3Ch]
  bool bRet; // [esp+27h] [ebp-35h]
  CRect rectCheckBox; // [esp+28h] [ebp-34h] BYREF
  CRect rectItem; // [esp+38h] [ebp-24h] BYREF
  CRect rectCheck; // [esp+48h] [ebp-14h] BYREF

  v9 = this;
  bRet = false;
  if ( CThemeHelper::IsAppThemed() != 0 )
  {
    hTheme = CThemeHelper::OpenThemeData(hwnd: this->m_hWnd, pszClassList: L"Button");
    if ( hTheme != nullptr )
    {
      nState = 1;
      if ( nCheck == 1 )
      {
        nState = 5;
      }
      else if ( nCheck == 2 )
      {
        nState = 4;
      }
      if ( CThemeHelper::GetThemePartSize(
             hTheme,
             hdc: pDC->m_hDC,
             nPartId: 3,
             nStateId: nState,
             pRect: nullptr,
             eSize: TS_TRUE,
             psz: &size) >= 0 )
      {
        lprcSrc = &drawItem->rcItem;
        CopyRect(lprcDst: &rectCheck, lprcSrc: &drawItem->rcItem);
        ++rectCheck.left;
        v6 = (cyItem - size.cy) / 2;
        if ( v6 < 0 )
          v6 = 0;
        rectCheck.top += v6 + 1;
        rectCheck.bottom = size.cy + rectCheck.top;
        rectCheck.right = rectCheck.left + size.cx;
        CopyRect(lprcDst: &rectItem, lprcSrc);
        rectItem.right = rectItem.left + size.cx + 2;
        ((void (__thiscall *)(CCheckListBox *, CRect *, int, int, int, int, int, int, int, int))this->OnGetCheckPosition)(
          a1: v9,
          a2: &rectCheckBox,
          a3: rectItem.left,
          a4: rectItem.top,
          a5: rectItem.right,
          a6: rectItem.bottom,
          a7: rectCheck.left,
          a8: rectCheck.top,
          a9: rectCheck.right,
          a10: rectCheck.bottom);
        if ( CThemeHelper::DrawThemeBackground(
               hTheme,
               hdc: pDC->m_hDC,
               nPartId: 3,
               nStateId: nState,
               pRect: &rectCheckBox,
               pClipRect: nullptr) >= 0 )
        {
          lprcSrc->left += size.cx + 3;
          bRet = true;
        }
        CThemeHelper::CloseThemeData(hTheme);
      }
    }
  }
  return bRet;
}

//------------------------------------------------------------------------------
// Address: 0x1035E1F9
// Name: protected: long CCheckListBox::OnLBFindString(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBFindString(CCheckListBox *this, signed int wParam, int lParam)
{
  if ( (CWnd::GetStyle(this) & 0x40) != 0 )
    return this->DefWindowProcA(this, a2: 399u, a3: wParam, a4: lParam);
  if ( wParam == -1 )
    wParam = 0;
  while ( 1 )
  {
    if ( wParam >= SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
      return -1;
    if ( lParam == SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam, lParam: 0) )
      break;
    ++wParam;
  }
  return wParam;
}

//------------------------------------------------------------------------------
// Address: 0x1035E274
// Name: protected: long CCheckListBox::OnLBFindStringExact(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBFindStringExact(CCheckListBox *this, signed int wParam, int lParam)
{
  if ( (CWnd::GetStyle(this) & 0x42) != 0 )
    return this->DefWindowProcA(this, a2: 418u, a3: wParam, a4: lParam);
  if ( wParam == -1 )
    wParam = 0;
  while ( 1 )
  {
    if ( wParam >= SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
      return -1;
    if ( lParam == SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam, lParam: 0) )
      break;
    ++wParam;
  }
  return wParam;
}

//------------------------------------------------------------------------------
// Address: 0x1035E2EF
// Name: protected: long CCheckListBox::OnLBSelectString(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBSelectString(CCheckListBox *this, signed int wParam, int lParam)
{
  if ( (CWnd::GetStyle(this) & 0x40) != 0 )
    return this->DefWindowProcA(this, a2: 396u, a3: wParam, a4: lParam);
  if ( wParam == -1 )
    wParam = 0;
  while ( 1 )
  {
    if ( wParam >= SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
      return -1;
    if ( lParam == SendMessageA(hWnd: this->m_hWnd, Msg: 0x199u, wParam, lParam: 0) )
      break;
    ++wParam;
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x186u, wParam, lParam: 0);
  return wParam;
}

//------------------------------------------------------------------------------
// Address: 0x1035E379
// Name: protected: virtual long CCheckListBox::get_accRole(struct tagVARIANT,struct tagVARIANT __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CCheckListBox::get_accRole(CCheckListBox *this, tagVARIANT varChild, tagVARIANT *pvarRole)
{
  int v3; // esi

  v3 = 0;
  if ( varChild.lVal <= 0 || varChild.lVal > SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
    return CWnd::get_accRole(this, varChild, pvarRole);
  pvarRole->vt = 3;
  pvarRole->decVal.Lo32 = 44;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1035E3F2
// Name: protected: virtual long CCheckListBox::get_accDefaultAction(struct tagVARIANT,wchar_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CCheckListBox::get_accDefaultAction(
        CCheckListBox *this,
        tagVARIANT varChild,
        wchar_t **pszDefaultAction)
{
  int v4; // edi
  int v5; // esi
  int v6; // esi
  CAfxStringMgr *StringManager; // eax
  unsigned int v8; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+10h] [ebp-10h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  if ( varChild.lVal <= 0 || varChild.lVal > SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
    return CWnd::get_accDefaultAction(this, varChild, pszDefaultAction);
  v5 = (this->m_nStyle == 6) + 2;
  v6 = (CCheckListBox::GetCheck(this, nIndex: varChild.decVal.Lo32 - 1) + 1) % v5;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &str, pStringMgr: StringManager);
  v8 = v6 + 62177;
  v12 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: v8);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &str,
      hInstance: StringResourceHandle,
      nID: v8);
  *pszDefaultAction = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::AllocSysString(this: &str);
  ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1035E549
// Name: protected: void CCheckListBox::PreDrawItemNonThemed(class CDC __near *,struct tagDRAWITEMSTRUCT __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::PreDrawItemNonThemed(
        CCheckListBox *this,
        HDC__ *pDC,
        tagDRAWITEMSTRUCT *drawItem,
        int nCheck,
        int cyItem)
{
  HDC__ *v5; // edi
  CNoTrackObject *Data; // ebx
  HDC CompatibleDC; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  COLORREF SysColor; // edi
  BOOL v12; // eax
  CDC *v13; // esi
  DWORD Layout; // edi
  HDC__ *m_hDC; // [esp-Ch] [ebp-8Ch]
  CBrush v16; // [esp+10h] [ebp-70h] BYREF
  unsigned int dwSetLayout; // [esp+18h] [ebp-68h]
  CDC *v18; // [esp+1Ch] [ebp-64h]
  HGDIOBJ h; // [esp+20h] [ebp-60h]
  tagRECT *p_rcItem; // [esp+24h] [ebp-5Ch]
  CDC v21; // [esp+28h] [ebp-58h] BYREF
  tagDRAWITEMSTRUCT *v22; // [esp+38h] [ebp-48h]
  CWnd *v23; // [esp+3Ch] [ebp-44h]
  int x[4]; // [esp+40h] [ebp-40h] BYREF
  tagRECT rc; // [esp+50h] [ebp-30h] BYREF
  tagRECT rcDst; // [esp+60h] [ebp-20h] BYREF
  int v27; // [esp+7Ch] [ebp-4h]

  v5 = pDC;
  v23 = this;
  v18 = (CDC *)pDC;
  v22 = drawItem;
  Data = CProcessLocalObject::GetData(
           this: &_afxChecklistState,
           pfnCreateObject: CProcessLocal<_AFX_CHECKLIST_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  CDC::CDC(this: &v21);
  v27 = 0;
  if ( pDC != nullptr )
    v5 = *((HDC__ **)pDC + 1);
  CompatibleDC = CreateCompatibleDC(hdc: v5);
  if ( CDC::Attach(this: &v21, hDC: CompatibleDC) != 0 )
  {
    dwSetLayout = CDC::GetLayout(this: &v21);
    CDC::SetLayout(this: &v21, dwSetLayout: 0);
    h = SelectObject(hdc: v21.m_hDC, h: Data[1].__vftable);
    p_rcItem = &drawItem->rcItem;
    CopyRect(lprcDst: &rcDst, lprcSrc: &drawItem->rcItem);
    v8 = cyItem - (unsigned int)Data[3].__vftable;
    ++rcDst.left;
    v9 = v8 / 2;
    if ( v9 < 0 )
      v9 = 0;
    v10 = (int)Data[2].__vftable + rcDst.left;
    rcDst.top += v9 + 1;
    rcDst.right = v10;
    rcDst.bottom = (int)Data[3].__vftable + rcDst.top;
    CopyRect(lprcDst: &rc, lprcSrc: &drawItem->rcItem);
    rc.right = (int)&Data[2].dtr_CNoTrackObject + rc.left + 2;
    ((void (__thiscall *)(CWnd *, int *, int, int, int, int, int, int, int, int))v23->__vftable[1].GetTypeInfoCount)(
      a1: v23,
      a2: x,
      a3: rc.left,
      a4: rc.top,
      a5: rc.right,
      a6: rc.bottom,
      a7: rcDst.left,
      a8: rcDst.top,
      a9: rcDst.right,
      a10: rcDst.bottom);
    SysColor = GetSysColor(nIndex: 5);
    v12 = CWnd::IsWindowEnabled(this: v23) == 0
       || CCheckListBox::IsEnabled(this: (CCheckListBox *)v23, nIndex: v22->itemID) == 0;
    if ( (v22->itemState & 1) != 0 && !v12 )
      SysColor = GetSysColor(nIndex: 13);
    CBrush::CBrush(this: &v16, crColor: SysColor);
    v13 = v18;
    m_hDC = v18->m_hDC;
    LOBYTE(v27) = 1;
    FillRect(hDC: m_hDC, lprc: &rc, hbr: (HBRUSH)v16.m_hObject);
    Layout = CDC::GetLayout(this: v13);
    CDC::SetLayout(this: v13, dwSetLayout: Layout | 8);
    BitBlt(
      hdc: v13->m_hDC,
      x: x[0],
      y: x[1],
      cx: (int)Data[2].__vftable,
      cy: (int)Data[3].__vftable,
      hdcSrc: v21.m_hDC,
      x1: nCheck * (int)Data[2].__vftable,
      y1: 0,
      rop: 0xCC0020u);
    CDC::SetLayout(this: v13, dwSetLayout: Layout);
    CDC::SetLayout(this: &v21, dwSetLayout);
    SelectObject(hdc: v21.m_hDC, h);
    p_rcItem->left += (int)&Data[2].dtr_CNoTrackObject + 3;
    LOBYTE(v27) = 0;
    v16.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    CGdiObject::~CGdiObject(this: &v16);
  }
  v27 = -1;
  CDC::~CDC(this: &v21);
}

//------------------------------------------------------------------------------
// Address: 0x1035E743
// Name: protected: void CCheckListBox::PreDrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::PreDrawItem(CCheckListBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  CDC *v3; // esi
  BOOL v4; // eax
  CNoTrackObject *Data; // eax
  unsigned int *v6; // edi
  unsigned int dwMinor; // [esp+Ch] [ebp-44h] BYREF
  unsigned int oldBkColor; // [esp+10h] [ebp-40h]
  int cyItem; // [esp+14h] [ebp-3Ch]
  int nCheck; // [esp+18h] [ebp-38h]
  tagDRAWITEMSTRUCT drawItem; // [esp+1Ch] [ebp-34h] BYREF

  drawItem = *lpDrawItemStruct;
  if ( (drawItem.itemID & 0x80000000) == 0 && drawItem.itemAction != 0 )
  {
    cyItem = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A1u, wParam: drawItem.itemID, lParam: 0);
    v3 = CDC::FromHandle(hDC: drawItem.hDC);
    nCheck = GetSysColor(nIndex: 5);
    v4 = CWnd::IsWindowEnabled(this) == 0 || CCheckListBox::IsEnabled(this, nIndex: drawItem.itemID) == 0;
    if ( (drawItem.itemState & 1) != 0 && !v4 )
      nCheck = GetSysColor(nIndex: 13);
    oldBkColor = v3->SetBkColor(this: v3, a2: nCheck);
    nCheck = CCheckListBox::GetCheck(this, nIndex: drawItem.itemID);
    Data = CProcessLocalObject::GetData(
             this: &_afxChecklistState,
             pfnCreateObject: CProcessLocal<_AFX_CHECKLIST_STATE>::CreateObject);
    if ( Data == nullptr )
      AfxThrowInvalidArgException();
    v6 = (unsigned int *)&Data[4];
    if ( Data[4].__vftable == nullptr && ATL::AtlGetCommCtrlVersion(pdwMajor: v6, pdwMinor: &dwMinor) < 0 )
      *v6 = 5;
    if ( *v6 < 6 || !CCheckListBox::PreDrawItemThemed(this, pDC: v3, &drawItem, nCheck, cyItem) )
      CCheckListBox::PreDrawItemNonThemed(this, pDC: (HDC__ *)v3, &drawItem, nCheck, cyItem);
    v3->SetBkColor(this: v3, a2: oldBkColor);
  }
  CCheckListBox::PreDrawItemHelper(this, lpDrawItemStruct: &drawItem);
}

//------------------------------------------------------------------------------
// Address: 0x1035E879
// Name: protected: int CCheckListBox::CalcMinimumItemHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::CalcMinimumItemHeight(CCheckListBox *this)
{
  CNoTrackObject *Data; // edi
  CFont *Font; // eax
  CFont *v4; // ebx
  int tmHeight; // ecx
  int v6; // edi
  CClientDC v8; // [esp+10h] [ebp-5Ch] BYREF
  tagTEXTMETRICA tm; // [esp+24h] [ebp-48h] BYREF
  int v10; // [esp+68h] [ebp-4h]

  Data = CProcessLocalObject::GetData(
           this: &_afxChecklistState,
           pfnCreateObject: CProcessLocal<_AFX_CHECKLIST_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( (CWnd::GetStyle(this) & 0x50) != 0x50 )
    return (int)&Data[3].dtr_CNoTrackObject + 1;
  CClientDC::CClientDC(this: &v8, pWnd: this);
  v10 = 0;
  Font = CWnd::GetFont(this);
  v4 = CDC::SelectObject(this: &v8, pFont: Font);
  GetTextMetricsA(hdc: v8.m_hAttribDC, lptm: &tm);
  CDC::SelectObject(this: &v8, pFont: v4);
  tmHeight = tm.tmHeight;
  this->m_cyText = tm.tmHeight;
  v6 = (int)&Data[3].dtr_CNoTrackObject + 1;
  if ( v6 <= tmHeight )
    v6 = tmHeight;
  v10 = -1;
  CClientDC::~CClientDC(this: &v8);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1035E917
// Name: protected: void CCheckListBox::InvalidateCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::InvalidateCheck(CCheckListBox *this, WPARAM nIndex)
{
  CNoTrackObject *Data; // edi
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  Data = CProcessLocalObject::GetData(
           this: &_afxChecklistState,
           pfnCreateObject: CProcessLocal<_AFX_CHECKLIST_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x198u, wParam: nIndex, lParam: (LPARAM)&rect);
  rect.right = (int)&Data[2].dtr_CNoTrackObject + rect.left + 2;
  InvalidateRect(hWnd: this->m_hWnd, lpRect: &rect, bErase: false);
}

//------------------------------------------------------------------------------
// Address: 0x1035E997
// Name: protected: int CCheckListBox::CheckFromPoint(class CPoint,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::CheckFromPoint(CCheckListBox *this, CPoint point, int *bInCheck)
{
  int v4; // eax
  CNoTrackObject *Data; // [esp+10h] [ebp-20h]
  int nIndex; // [esp+14h] [ebp-1Ch]
  LRESULT i; // [esp+18h] [ebp-18h]
  signed int ia; // [esp+18h] [ebp-18h]
  CRect itemRect; // [esp+1Ch] [ebp-14h] BYREF

  nIndex = -1;
  *bInCheck = 0;
  Data = CProcessLocalObject::GetData(
           this: &_afxChecklistState,
           pfnCreateObject: CProcessLocal<_AFX_CHECKLIST_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( (CWnd::GetStyle(this) & 0x210) == 0x10 )
  {
    i = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A1u, wParam: 0, lParam: 0);
    if ( point.y < i * SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
    {
      nIndex = point.y / i + SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Eu, wParam: 0, lParam: 0);
      v4 = (int)&Data[2].dtr_CNoTrackObject + 2;
LABEL_12:
      if ( point.x < v4 )
        ++*bInCheck;
    }
  }
  else
  {
    for ( ia = SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Eu, wParam: 0, lParam: 0);
          ia < SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
          ++ia )
    {
      memset(&itemRect, 0, sizeof(itemRect));
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x198u, wParam: ia, lParam: (LPARAM)&itemRect);
      if ( PtInRect(lprc: &itemRect, pt: point.tagPOINT) )
      {
        nIndex = ia;
        v4 = (int)&Data[2].dtr_CNoTrackObject + itemRect.left + 2;
        goto LABEL_12;
      }
    }
  }
  return nIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1035EAC2
// Name: protected: int CCheckListBox::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnCreate(CCheckListBox *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  unsigned __int16 v4; // ax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    if ( (CWnd::GetStyle(this) & 0x50) == 0x50 )
    {
      v4 = CCheckListBox::CalcMinimumItemHeight(this);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A0u, wParam: 0, lParam: v4);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035EB04
// Name: protected: long CCheckListBox::OnSetFont(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnSetFont(CCheckListBox *this, unsigned int __formal, unsigned int __formala)
{
  unsigned __int16 v4; // ax

  CWnd::Default(this);
  if ( (CWnd::GetStyle(this) & 0x50) == 0x50 )
  {
    v4 = CCheckListBox::CalcMinimumItemHeight(this);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A0u, wParam: 0, lParam: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035EB3D
// Name: protected: long CCheckListBox::OnLBSetItemHeight(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnLBSetItemHeight(CCheckListBox *this, unsigned int wParam, unsigned __int16 lParam)
{
  unsigned __int16 v4; // ax

  if ( CCheckListBox::CalcMinimumItemHeight(this) <= lParam )
    v4 = lParam;
  else
    v4 = CCheckListBox::CalcMinimumItemHeight(this);
  return this->DefWindowProcA(this, a2: 416u, a3: wParam, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1035EB7A
// Name: public: void CCheckListBox::SetCheck(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::SetCheck(CCheckListBox *this, unsigned int nIndex, int nCheck)
{
  unsigned int m_nStyle; // eax
  _DWORD *v5; // eax

  if ( nCheck == 2 && ((m_nStyle = this->m_nStyle) == 2 || m_nStyle == 3) )
  {
    NotifyWinEvent(event: 0x800Au, hwnd: this->m_hWnd, idObject: -4, idChild: nIndex + 1);
  }
  else
  {
    v5 = (_DWORD *)this->DefWindowProcA(this, a2: 409u, a3: nIndex, a4: 0);
    if ( v5 != (_DWORD *)-1 )
    {
      if ( v5 == nullptr )
      {
        v5 = operator new(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          *v5 = 0;
          v5[2] = 0;
          v5[1] = 1;
        }
        else
        {
          v5 = nullptr;
        }
      }
      *v5 = nCheck;
      this->DefWindowProcA(this, a2: 410u, a3: nIndex, a4: (int)v5);
      CCheckListBox::InvalidateCheck(this, nIndex);
      NotifyWinEvent(event: 0x800Au, hwnd: this->m_hWnd, idObject: -4, idChild: nIndex + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035EC1D
// Name: public: virtual void CCheckListBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::DrawItem(CCheckListBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  tagDRAWITEMSTRUCT *v3; // edi
  CDC *v4; // esi
  signed int itemID; // eax
  DWORD SysColor; // eax
  DWORD v7; // eax
  DWORD v8; // eax
  DWORD v9; // eax
  CAfxStringMgr *StringManager; // eax
  int v11; // edx
  unsigned int oldBkColor; // [esp+10h] [ebp-20h]
  unsigned int oldTextColor; // [esp+14h] [ebp-1Ch]
  LRESULT cyItem; // [esp+18h] [ebp-18h]
  int fDisabled; // [esp+20h] [ebp-10h]
  int fDisableda; // [esp+20h] [ebp-10h]
  int fDisabledb; // [esp+20h] [ebp-10h]

  v3 = lpDrawItemStruct;
  v4 = CDC::FromHandle(hDC: lpDrawItemStruct->hDC);
  if ( v4 == nullptr )
    AfxThrowInvalidArgException();
  itemID = v3->itemID;
  if ( itemID >= 0 && (v3->itemAction & 3) != 0 )
  {
    cyItem = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1A1u, wParam: itemID, lParam: 0);
    if ( CWnd::IsWindowEnabled(this) != 0 && CCheckListBox::IsEnabled(this, nIndex: v3->itemID) != 0 )
    {
      fDisabled = 0;
      SysColor = GetSysColor(nIndex: 8);
    }
    else
    {
      fDisabled = 1;
      SysColor = 8421504;
    }
    oldTextColor = v4->SetTextColor(this: v4, a2: SysColor);
    v7 = GetSysColor(nIndex: 5);
    oldBkColor = v4->SetBkColor(this: v4, a2: v7);
    if ( fDisabled == 0 && (v3->itemState & 1) != 0 )
    {
      fDisableda = (int)v4->__vftable;
      v8 = GetSysColor(nIndex: 14);
      (*(void (__thiscall **)(CDC *, DWORD))(fDisableda + 48))(a1: v4, a2: v8);
      fDisabledb = (int)v4->__vftable;
      v9 = GetSysColor(nIndex: 13);
      (*(void (__thiscall **)(CDC *, DWORD))(fDisabledb + 44))(a1: v4, a2: v9);
    }
    if ( this->m_cyText == 0 )
      CCheckListBox::CalcMinimumItemHeight(this);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: (ATL::CSimpleStringT<char,0> *)&lpDrawItemStruct,
      pStringMgr: StringManager);
    CListBox::GetText(
      this,
      nIndex: v3->itemID,
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpDrawItemStruct);
    if ( (cyItem - this->m_cyText) / 2 >= 0 )
      v11 = (cyItem - this->m_cyText) / 2;
    else
      v11 = 0;
    v4->ExtTextOutA(
      this: v4,
      a2: v3->rcItem.left,
      a3: v11 + v3->rcItem.top,
      a4: 2u,
      a5: &v3->rcItem,
      a6: (const char *)lpDrawItemStruct,
      a7: lpDrawItemStruct[-1].rcItem.right,
      a8: nullptr);
    v4->SetTextColor(this: v4, a2: oldTextColor);
    v4->SetBkColor(this: v4, a2: oldBkColor);
    ATL::CStringData::Release(this: (ATL::CStringData *)&lpDrawItemStruct[-1].rcItem.top);
  }
  if ( (v3->itemAction & 4) != 0 )
    DrawFocusRect(hDC: v4->m_hDC, lprc: &v3->rcItem);
}

//------------------------------------------------------------------------------
// Address: 0x1035ED9A
// Name: protected: void CCheckListBox::PreMeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::PreMeasureItem(CCheckListBox *this, tagMEASUREITEMSTRUCT *lpMeasureItemStruct)
{
  int v3; // eax
  unsigned int itemHeight; // ecx
  unsigned int cyItem; // [esp+10h] [ebp-20h]
  tagMEASUREITEMSTRUCT measureItem; // [esp+14h] [ebp-1Ch] BYREF

  measureItem = *lpMeasureItemStruct;
  measureItem.itemWidth = -1;
  cyItem = CCheckListBox::CalcMinimumItemHeight(this);
  measureItem.itemHeight = cyItem;
  if ( (CWnd::GetStyle(this) & 0x20) != 0 )
  {
    v3 = this->DefWindowProcA(this, a2: 409u, a3: measureItem.itemID, a4: 0);
    measureItem.itemData = v3 != -1 ? v3 : 0;
    if ( measureItem.itemData != 0 && (v3 != -1 ? v3 : 0) != 0xFFFFFFFF )
      measureItem.itemData = *(_DWORD *)(v3 != -1 ? v3 + 8 : 8);
  }
  this->MeasureItem(this, a2: &measureItem);
  itemHeight = measureItem.itemHeight;
  if ( measureItem.itemHeight <= cyItem )
    itemHeight = cyItem;
  lpMeasureItemStruct->itemHeight = itemHeight;
  lpMeasureItemStruct->itemWidth = measureItem.itemWidth;
}

//------------------------------------------------------------------------------
// Address: 0x1035EE3C
// Name: protected: virtual int CCheckListBox::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCheckListBox::OnChildNotify(
        CCheckListBox *this,
        unsigned int message,
        unsigned int wParam,
        tagDRAWITEMSTRUCT *lParam,
        int *pResult)
{
  switch ( message )
  {
    case '+':
      CCheckListBox::PreDrawItem(this, lpDrawItemStruct: lParam);
      break;
    case ',':
      CCheckListBox::PreMeasureItem(this, lpMeasureItemStruct: (tagMEASUREITEMSTRUCT *)lParam);
      break;
    case '-':
      CCheckListBox::PreDeleteItem(this, lpDeleteItemStruct: (tagDELETEITEMSTRUCT *)lParam);
      break;
    case '9':
      *pResult = CCheckListBox::PreCompareItem(this, lpCompareItemStruct: (tagCOMPAREITEMSTRUCT *)lParam);
      break;
    default:
      return CListBox::OnChildNotify(this, message, wParam, lParam, pResult);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035EE8C
// Name: protected: void CCheckListBox::SetSelectionCheck(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::SetSelectionCheck(CCheckListBox *this, int nCheck)
{
  int v3; // ebx
  LRESULT v4; // eax
  unsigned int *v5; // edi
  CArray<int,int const &> rgiSelectedItems; // [esp+10h] [ebp-24h] BYREF
  int nSelectedItems; // [esp+24h] [ebp-10h]
  int v8; // [esp+30h] [ebp-4h]

  v3 = 0;
  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x190u, wParam: 0, lParam: 0);
  nSelectedItems = v4;
  if ( v4 > 0 )
  {
    rgiSelectedItems.__vftable = (CArray<int,int const &>_vtbl *)&CArray<int,int const &>::`vftable';
    memset(&rgiSelectedItems.m_pData, 0, 16);
    v8 = 0;
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&rgiSelectedItems,
      nNewSize: v4,
      nGrowBy: -1);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x191u, wParam: nSelectedItems, lParam: (LPARAM)rgiSelectedItems.m_pData);
    if ( nSelectedItems > 0 )
    {
      do
      {
        v5 = (unsigned int *)&rgiSelectedItems.m_pData[v3];
        if ( CCheckListBox::IsEnabled(this, nIndex: *v5) != 0 )
        {
          CCheckListBox::SetCheck(this, nIndex: *v5, nCheck);
          CCheckListBox::InvalidateCheck(this, nIndex: *v5);
        }
        ++v3;
      }
      while ( v3 < nSelectedItems );
    }
    v8 = -1;
    CArray<int,int const &>::~CArray<int,int const &>(this: &rgiSelectedItems);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035EF2D
// Name: protected: void CCheckListBox::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::OnLButtonDown(CCheckListBox *this, unsigned int nFlags, CPoint point)
{
  unsigned int v4; // ebx
  unsigned int m_nStyle; // eax
  HWND Parent; // eax
  int v7; // edi
  int v8; // eax
  HWND__ *m_hWnd; // ebx
  unsigned __int16 DlgCtrlID; // ax
  CWnd *pParent; // [esp+8h] [ebp-8h]
  int nNewCheck; // [esp+Ch] [ebp-4h] BYREF

  CWnd::SetFocus(this);
  v4 = CCheckListBox::CheckFromPoint(this, point, bInCheck: &nNewCheck);
  if ( CCheckListBox::IsEnabled(this, nIndex: v4) != 0 )
  {
    m_nStyle = this->m_nStyle;
    if ( m_nStyle == 2 || m_nStyle == 5 || nNewCheck == 0 )
    {
      CWnd::Default(this);
    }
    else
    {
      Parent = GetParent(hWnd: this->m_hWnd);
      pParent = CWnd::FromHandle(hWnd: Parent);
      v7 = (this->m_nStyle == 6) + 2;
      v8 = CCheckListBox::GetCheck(this, nIndex: v4);
      if ( v8 == v7 )
        --v8;
      nNewCheck = (v8 + 1) % v7;
      CCheckListBox::SetCheck(this, nIndex: v4, nCheck: nNewCheck);
      CCheckListBox::InvalidateCheck(this, nIndex: v4);
      if ( (CWnd::GetStyle(this) & 0x808) != 0
        && SendMessageA(hWnd: this->m_hWnd, Msg: 0x187u, wParam: v4, lParam: 0) != 0 )
      {
        CCheckListBox::SetSelectionCheck(this, nCheck: nNewCheck);
      }
      else
      {
        CWnd::Default(this);
      }
      m_hWnd = this->m_hWnd;
      DlgCtrlID = CWnd::GetDlgCtrlID(this);
      SendMessageA(hWnd: pParent->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID | 0x280000, lParam: (LPARAM)m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035F02C
// Name: protected: void CCheckListBox::OnLButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::OnLButtonDblClk(CCheckListBox *this, unsigned int nFlags, CPoint point)
{
  int bInCheck; // [esp+4h] [ebp-4h] BYREF

  CCheckListBox::CheckFromPoint(this, point, &bInCheck);
  if ( bInCheck != 0 )
    CCheckListBox::OnLButtonDown(this, nFlags, point);
  else
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035F066
// Name: protected: void CCheckListBox::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCheckListBox::OnKeyDown(CCheckListBox *this, int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
  WPARAM v5; // ebx
  HWND Parent; // eax
  unsigned int m_nStyle; // eax
  int v8; // eax
  unsigned __int16 DlgCtrlID; // ax
  int IsEnabled; // eax
  int v11; // eax
  HWND__ *m_hWnd; // ebx
  WPARAM v13; // [esp-8h] [ebp-1Ch]
  WPARAM v14; // [esp-8h] [ebp-1Ch]
  LPARAM v15; // [esp-4h] [ebp-18h]
  LRESULT bSelected; // [esp+Ch] [ebp-8h]
  CWnd *pParent; // [esp+10h] [ebp-4h]
  int nNewCheck; // [esp+1Ch] [ebp+8h]
  HWND__ *nNewCheckc; // [esp+1Ch] [ebp+8h]
  int nNewChecka; // [esp+1Ch] [ebp+8h]
  int nNewCheckb; // [esp+1Ch] [ebp+8h]

  if ( nChar != 32
    || (v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x19Fu, wParam: 0, lParam: 0),
        Parent = GetParent(hWnd: this->m_hWnd),
        pParent = CWnd::FromHandle(hWnd: Parent),
        v5 == -1)
    || (m_nStyle = this->m_nStyle) == 2
    || m_nStyle == 5 )
  {
    CWnd::Default(this);
    return;
  }
  if ( (CWnd::GetStyle(this) & 8) != 0 )
  {
    if ( CCheckListBox::IsEnabled(this, nIndex: v5) != 0 )
    {
      bSelected = SendMessageA(hWnd: this->m_hWnd, Msg: 0x187u, wParam: v5, lParam: 0);
      if ( bSelected != 0 )
      {
        nNewCheck = (this->m_nStyle == 6) + 2;
        v8 = CCheckListBox::GetCheck(this, nIndex: v5);
        if ( v8 == nNewCheck )
          --v8;
        CCheckListBox::SetCheck(this, nIndex: v5, nCheck: (v8 + 1) % nNewCheck);
        nNewCheckc = this->m_hWnd;
        DlgCtrlID = CWnd::GetDlgCtrlID(this);
        SendMessageA(hWnd: pParent->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID | 0x280000, lParam: (LPARAM)nNewCheckc);
      }
      v15 = v5;
      v13 = bSelected == 0;
      goto LABEL_14;
    }
    v15 = v5;
LABEL_13:
    v13 = 0;
LABEL_14:
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x185u, wParam: v13, lParam: v15);
    return;
  }
  IsEnabled = CCheckListBox::IsEnabled(this, nIndex: v5);
  v15 = v5;
  if ( IsEnabled == 0 )
    goto LABEL_13;
  nNewChecka = (this->m_nStyle == 6) + 2;
  v11 = CCheckListBox::GetCheck(this, nIndex: v5);
  if ( v11 == nNewChecka )
    --v11;
  nNewCheckb = (v11 + 1) % nNewChecka;
  CCheckListBox::SetCheck(this, nIndex: v5, nCheck: nNewCheckb);
  CCheckListBox::InvalidateCheck(this, nIndex: v5);
  if ( (CWnd::GetStyle(this) & 0x800) != 0 )
    CCheckListBox::SetSelectionCheck(this, nCheck: nNewCheckb);
  m_hWnd = this->m_hWnd;
  v14 = (unsigned __int16)CWnd::GetDlgCtrlID(this) | 0x280000;
  SendMessageA(hWnd: pParent->m_hWnd, Msg: 0x111u, wParam: v14, lParam: (LPARAM)m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1035F1E3
// Name: protected: virtual long CCheckListBox::accDoDefaultAction(struct tagVARIANT)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CCheckListBox::accDoDefaultAction(CCheckListBox *this, tagVARIANT varChild)
{
  int v3; // edi
  int v4; // edi
  HWND Parent; // eax
  CWnd *v6; // edi
  unsigned __int16 DlgCtrlID; // ax
  HWND__ *lParam; // [esp+Ch] [ebp-8h]
  HRESULT hr; // [esp+10h] [ebp-4h]

  hr = 0;
  if ( varChild.lVal <= 0 || varChild.lVal > SendMessageA(hWnd: this->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) )
    return CWnd::accDoDefaultAction(this, varChild);
  v3 = (this->m_nStyle == 6) + 2;
  v4 = (CCheckListBox::GetCheck(this, nIndex: varChild.decVal.Lo32 - 1) + 1) % v3;
  CCheckListBox::SetCheck(this, nIndex: varChild.decVal.Lo32 - 1, nCheck: v4);
  if ( (CWnd::GetStyle(this) & 0x808) != 0
    && SendMessageA(hWnd: this->m_hWnd, Msg: 0x187u, wParam: varChild.decVal.Lo32 - 1, lParam: 0) != 0 )
  {
    CCheckListBox::SetSelectionCheck(this, nCheck: v4);
  }
  Parent = GetParent(hWnd: this->m_hWnd);
  v6 = CWnd::FromHandle(hWnd: Parent);
  lParam = this->m_hWnd;
  DlgCtrlID = CWnd::GetDlgCtrlID(this);
  SendMessageA(hWnd: v6->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID | 0x280000, (LPARAM)lParam);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x185u, wParam: 1u, lParam: varChild.decVal.Lo32 - 1);
  return hr;
}

//------------------------------------------------------------------------------
// Address: 0x1035F2D4
// Name: protected: virtual struct AFX_MSGMAP const __near * CCheckListBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CCheckListBox::GetMessageMap(CCheckListBox *this)
{
  return &messageMap_25;
}

//------------------------------------------------------------------------------
// Address: 0x1035E4A0
// Name: public: _AFX_CHECKLIST_STATE::_AFX_CHECKLIST_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_CHECKLIST_STATE *__thiscall _AFX_CHECKLIST_STATE::_AFX_CHECKLIST_STATE(_AFX_CHECKLIST_STATE *this)
{
  HBITMAP__ *v2; // eax
  tagBITMAP bm; // [esp+10h] [ebp-2Ch] BYREF
  CBitmap bitmap; // [esp+28h] [ebp-14h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  this->__vftable = (_AFX_CHECKLIST_STATE_vtbl *)&_AFX_CHECKLIST_STATE::`vftable';
  this->m_sizeCheck.cx = 0;
  this->m_sizeCheck.cy = 0;
  bitmap.m_hObject = nullptr;
  bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  v6 = 0;
  CBitmap::LoadBitmapA(this: &bitmap, nIDResource: 0x7914u);
  GetObjectA(h: bitmap.m_hObject, c: 24, pv: &bm);
  this->m_sizeCheck.cx = bm.bmWidth / 3;
  this->m_sizeCheck.cy = bm.bmHeight;
  v2 = (HBITMAP__ *)CGdiObject::Detach(this: &bitmap);
  v6 = -1;
  this->m_hbitmapCheck = v2;
  this->m_dwVerComCtl32 = 0;
  bitmap.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &bitmap);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035E51D
// Name: public: static class CNoTrackObject __near * CProcessLocal<class _AFX_CHECKLIST_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_CHECKLIST_STATE *__stdcall CProcessLocal<_AFX_CHECKLIST_STATE>::CreateObject()
{
  _AFX_CHECKLIST_STATE *v0; // ecx
  _AFX_CHECKLIST_STATE *result; // eax

  v0 = (_AFX_CHECKLIST_STATE *)CNoTrackObject::operator new(nSize: 0x14u);
  result = nullptr;
  if ( v0 != nullptr )
    return _AFX_CHECKLIST_STATE::_AFX_CHECKLIST_STATE(this: v0);
  return result;
}
