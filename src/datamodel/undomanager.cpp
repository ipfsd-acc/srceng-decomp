// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/undomanager.cpp
// Functions: 35
// ============================================================

#include "datamodel\undomanager.h"

//------------------------------------------------------------------------------
// Address: 0x00412020
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412030
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00412050
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004120D0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x004120E0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x004120F0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00412100
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412130
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004121D0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412210
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00412230
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412240
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004122E0
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412340
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return &defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00412500
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00412520
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return &defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00412620
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x004126D0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004127E0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412860
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004128B0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004128C0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412950
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004129F0
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1 & 2) == 0 )
    {
      _S1 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: &s_DescErrors.m_Memory,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412B50
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00412CF0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412ED0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F30
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F90
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0047EF90
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0047EFA0
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0047EFB0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0047EFC0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x0047EFD0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x0047EFE0
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0044A080
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044A090
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0044A0B0
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A130
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x0044A140
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x0044A150
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x0044A160
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A190
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A230
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A270
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044A290
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044A2A0
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044A2B0
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A310
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return var;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x0044A4D0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x0044A4F0
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return var;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0044A5F0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x0044A6A0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A7B0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044A830
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A880
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044A890
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044A920
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A9C0
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_1 & 1) == 0 )
    {
      _S1_1 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_1 & 2) == 0 )
    {
      _S1_1 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AB20
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044ACC0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> >,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AEA0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AF00
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AF60
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x005AF670
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x005AF680
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x005AF690
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x005AF6A0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005AF6E0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005AF720
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x005AF730
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x005AF750
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x005AF760
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x005AF7A0
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00417820
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417830
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00417850
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004178D0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x004178E0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x004178F0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00417900
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417930
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004179D0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A10
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00417A30
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417A40
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417A50
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417AB0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00417C00
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers,
    src: (vgui::TreeNode **)&pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00417C20
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00417CC0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x00417D70
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, (CUtlMemory<vgui::TreeNode *,int> *)&handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417E80
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00417F00
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_RedoStack);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417F50
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00417F60
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_Notifiers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (vgui::TreeNode *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00417FF0
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418090
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1 & 2) == 0 )
    {
      _S1 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<wchar_t,int>::Grow(
          this: (CUtlMemory<wchar_t,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004181F0
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00418390
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418570
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004185D0
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418630
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x006768C0
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00681840
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x00681850
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x00681860
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x00681870
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x00681880
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x00681890
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101B7DF0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B7E00
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x101B7E20
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7EA0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x101B7EB0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x101B7EC0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x101B7ED0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7F00
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7FA0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7FE0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x101B8000
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B8010
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B8020
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8080
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return &var;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x101B81D0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<CMapView2D *,CUtlMemory<CMapView2D *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers,
    src: (vgui::TreeNode *const *)&pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x101B81F0
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return &var;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101B8290
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x101B8340
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, (CUtlMemory<vgui::TreeNode *,int> *)&handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8450
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B84D0
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_RedoStack);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8520
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B8530
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_Notifiers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (vgui::TreeNode *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B85C0
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8660
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_28 & 1) == 0 )
    {
      _S1_28 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_28 & 2) == 0 )
    {
      _S1_28 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<unsigned short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B87C0
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101B8960
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2_9 & 1) == 0 )
  {
    _S2_9 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8B40
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8BA0
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8C00
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x105CBAB0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x105CBAC0
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x105CBAD0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x105CBAE0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x105CBAF0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x105CBB00
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00474B50
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00474B60
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00474B80
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474C00
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x00474C10
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x00474C20
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00474C30
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474C60
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge::<unnamed_type_u> *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = *(_DWORD *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                             a1: g_pDataModel.u,
                                             a2: &udesc,
                                             a3: v5);
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)&udesc;
      }
      else
      {
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                                         a1: g_pDataModel.u,
                                                         a2: &udesc,
                                                         a3: rdesc);
      }
      this->m_RedoDesc.u = (CUtlSymbolLarge::<unnamed_type_u>)p_udesc->m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474D00
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474D40
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00474D60
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00474D70
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00474D80
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474DE0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return WindowName;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00474F30
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00474F50
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return WindowName;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00475050
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  char sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x00475100
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  char v4; // al
  int v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    sg.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475210
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00475290
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004752E0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004752F0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00475380
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475420
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_4 & 1) == 0 )
    {
      _S1_4 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_4 & 2) == 0 )
    {
      _S1_4 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475580
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Undo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00475720
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475900
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475960
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004759C0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Redo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0059DDE0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0059DDF0
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0059DE00
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0059DDB0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x0059DDC0
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0059DE10
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0059DE50
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0059DE90
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x0059DEA0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0059DEB0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0059DEF0
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004CFA10
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CFA20
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004CFA40
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFAC0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x004CFAD0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x004CFAE0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x004CFAF0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFB20
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFBC0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFC00
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004CFC20
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CFC30
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD80
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFDE0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return pDefaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x004CFFA0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x004CFFC0
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return pDefaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004D00C0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x004D0170
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0280
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D0300
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0350
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D0360
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<S3RGBA,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_Notifiers = (CUtlMemory<S3RGBA,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (S3RGBA)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D03F0
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0490
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_3 & 1) == 0 )
    {
      _S1_3 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_3 & 2) == 0 )
    {
      _S1_3 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: &s_DescErrors.m_Memory,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D05F0
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004D0790
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2_2 & 1) == 0 )
  {
    _S2_2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = (char *)m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0970
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D09D0
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0A30
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0058B7C0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0058B7D0
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0058B7E0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0058B7F0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x0058B800
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x0058B810
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004B8DF0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8E00
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004B8E20
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8EA0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x004B8EB0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x004B8EC0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x004B8ED0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8F00
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge::<unnamed_type_u> *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = *(_DWORD *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                             a1: g_pDataModel.u,
                                             a2: &udesc,
                                             a3: v5);
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)&udesc;
      }
      else
      {
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                                         a1: g_pDataModel.u,
                                                         a2: &udesc,
                                                         a3: rdesc);
      }
      this->m_RedoDesc.u = (CUtlSymbolLarge::<unnamed_type_u>)p_udesc->m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8FA0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8FE0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004B9000
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9010
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9020
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9080
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return pDeltaStateName;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x004B9240
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x004B9260
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return pDeltaStateName;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004B9360
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  char sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x004B9410
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  char v4; // al
  int v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    sg.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9520
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B95A0
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B95F0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B9600
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9690
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9730
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_5 & 1) == 0 )
    {
      _S1_5 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_5 & 2) == 0 )
    {
      _S1_5 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9890
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Undo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9A30
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVectorAuto<s_compressed_t>,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9C10
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9C70
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9CD0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Redo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005E8D50
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x005F3050
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x005F3060
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x005F3070
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x005F3030
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x005F3080
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005F30C0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005F3100
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3110
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x005F3120
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x005F3160
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00413B60
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413B70
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00413B90
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413C10
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x00413C20
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x00413C30
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00413C40
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413C70
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413D10
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413D50
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00413D70
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413D80
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413EC0
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413F20
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x004140E0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00414100
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00414200
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x004142B0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004143C0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00414440
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414490
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004144A0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414530
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004145D0
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1 & 2) == 0 )
    {
      _S1 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: &s_DescErrors.m_Memory,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414730
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004148D0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414AB0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414B10
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414B70
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B7730
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x004B7740
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x004B7750
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x004B7760
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x004B7770
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x004B7780
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0043F6B0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043F6C0
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0043F6E0
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: str, a2: "%s%s");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F760
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x0043F770
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x0043F780
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x0043F790
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F7C0
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F860
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F8A0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0043F8C0
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043F8D0
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043F970
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F9D0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return str;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x0043FB20
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x0043FB40
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return str;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0043FC40
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x0043FCF0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FE00
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043FE80
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FED0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043FEE0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043FF70
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440010
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_0 & 2) == 0 )
    {
      _S1_0 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440170
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00440310
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004404F0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440550
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004405B0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00565310
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0056DE20
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0056DE30
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0056DE40
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0056DE00
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0056DE50
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0056DE90
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0056DED0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x0056DEE0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0056DEF0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0056DF30
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x004363E0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 108) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004363F0
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 108) ^= (*((_BYTE *)this + 108) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00436410
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  _BYTE spaces_4[129]; // [esp+4h] [ebp-884h] OVERLAPPED BYREF
  char v5; // [esp+883h] [ebp-5h]
  va_list ap; // [esp+894h] [ebp+Ch] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 108) & 2) != 0 )
  {
    _vsnprintf(string: &spaces_4[128], count: 0x7FFu, format: fmt, ap);
    v5 = 0;
    memset(dst: spaces_4, value: 0, count: 0x80u);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces_4[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: &spaces_4[128], a2: "%s%s");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004364D0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x004364E0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 108) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x004364F0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 108) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00436500
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436530
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  const char *v8; // ebp
  bool v9; // zf
  CUtlSymbol *p_m_UndoDesc; // eax

  if ( (*((_BYTE *)this + 108) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      CThreadSpinRWLock::LockForWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
      CUtlSymbolTable::AddString(this: &CUndoManager::s_UndoSymbolTable, result: (CUtlSymbol *)&udesc, pString: v5);
      CThreadSpinRWLock::UnlockWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
      v8 = rdesc;
      v9 = v5 == rdesc;
      p_m_UndoDesc = &this->m_UndoDesc;
      this->m_UndoDesc.m_Id = (unsigned __int16)udesc;
      if ( !v9 )
      {
        CThreadSpinRWLock::LockForWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
        CUtlSymbolTable::AddString(this: &CUndoManager::s_UndoSymbolTable, result: (CUtlSymbol *)&udesc, pString: v8);
        CThreadSpinRWLock::UnlockWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
        p_m_UndoDesc = (CUtlSymbol *)&udesc;
      }
      this->m_RedoDesc = (CUtlSymbol)p_m_UndoDesc->m_Id;
      *((_BYTE *)this + 108) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436600
// Name: public: unsigned short CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUndoManager::GetRedoDescInternal(CUndoManager *this, const char *context)
{
  CUtlSymbol v3; // [esp+0h] [ebp-2h] BYREF

  v3.m_Id = HIWORD(this);
  if ( this->m_nNesting > 0 )
    return this->m_RedoDesc.m_Id;
  CThreadSpinRWLock::LockForWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
  CUtlSymbolTable::AddString(this: &CUndoManager::s_UndoSymbolTable, result: &v3, pString: context);
  CThreadSpinRWLock::UnlockWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
  return v3.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00436650
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 108) ^= (*((_BYTE *)this + 108) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00436670
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00436680
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00436740
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( (*((_BYTE *)this + 108) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004367A0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x004369A0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x004369B0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool v6; // [esp+Ch] [ebp-4h]

  v6 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00436A50
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00436B60
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_UndoList.m_ElementCount = 0;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.m_Id = -1;
  this->m_RedoDesc.m_Id = -1;
  v2 = *((_BYTE *)this + 108) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 108) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00436BE0
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Notifiers);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436C30
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // ebp
  int v3; // edi
  IUndoElement *v4; // esi
  const char *v5; // eax
  void *m_nAllocationCount; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+10h] [ebp-18h] BYREF
  void *v8; // [esp+24h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    memset(&handles.m_Memory.m_nAllocationCount, 0, 16);
    v8 = nullptr;
    CDataModel::GetInvalidHandles(
      this: g_pDataModelImp,
      handles: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&handles.m_Memory.m_nAllocationCount);
    CDataModel::MarkHandlesValid(
      this: g_pDataModelImp,
      handles: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&handles.m_Memory.m_nAllocationCount);
    LOBYTE(handles.m_Memory.m_pMemory) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v4 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v5 = v4->GetDesc(this: v4);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v5);
        v4->Release(this: v4);
        ++v3;
      }
      while ( v3 < m_Size );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(
      this: g_pDataModelImp,
      handles: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&handles.m_Memory.m_nAllocationCount);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: (bool)handles.m_Memory.m_pMemory);
    m_nAllocationCount = (void *)handles.m_Memory.m_nAllocationCount;
    handles.m_pElements = nullptr;
    if ( handles.m_Size >= 0 )
    {
      if ( handles.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)handles.m_Memory.m_nAllocationCount);
        m_nAllocationCount = nullptr;
        handles.m_Memory.m_nAllocationCount = 0;
      }
      handles.m_Memory.m_nGrowSize = 0;
    }
    v8 = m_nAllocationCount;
    if ( handles.m_Size >= 0 && m_nAllocationCount != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436DE0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00436DF0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  int m_Size; // edx
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *p_m_Notifiers; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // esi

  m_Size = this->m_Notifiers.m_Size;
  p_m_Notifiers = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Notifiers;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_Memory.m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
    this: p_m_Notifiers,
    elem: m_Size,
    src: (CUtlSymbolTable::StringPool_t **)&pNotify);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00436E30
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  unsigned __int16 m_Id; // di
  const char *v3; // edi
  int m_nChainingID; // eax
  int m_Tail; // edi
  int v7; // edi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 108) & 8) != 0 )
  {
    m_Id = this->m_UndoDesc.m_Id;
    CThreadSpinRWLock::LockForRead(this: &CUndoManager::s_UndoSymbolTable.m_lock);
    v3 = CUtlSymbolTable::String(this: &CUndoManager::s_UndoSymbolTable, id: (CUtlSymbol)m_Id);
    CThreadSpinRWLock::UnlockRead(this: &CUndoManager::s_UndoSymbolTable.m_lock);
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, v3);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v7 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v7].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v7].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v7].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436EF0
// Name: public: unsigned short CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUndoManager::GetUndoDescInternal(CUndoManager *this, const char *context)
{
  const char *v2; // edi
  int v3; // eax
  CUtlSymbol v5; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
    return this->m_UndoDesc.m_Id;
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 32, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
  }
  if ( (_S1_0 & 2) == 0 )
  {
    _S1_0 |= 2u;
    s_DescErrors.m_Memory.m_pMemory = nullptr;
    s_DescErrors.m_Memory.m_nAllocationCount = 0;
    s_DescErrors.m_Memory.m_nGrowSize = 0;
    s_DescErrors.m_Size = 0;
    s_DescErrors.m_pElements = nullptr;
    atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
  }
  v2 = context;
  CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &v5, pString: context);
  v3 = 0;
  if ( s_DescErrors.m_Size <= 0 )
    goto LABEL_11;
  while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != v5.m_Id )
  {
    if ( ++v3 >= s_DescErrors.m_Size )
      goto LABEL_11;
  }
  if ( v3 == -1 )
  {
LABEL_11:
    _Warning(
      a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
      v2);
    CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
      this: &s_DescErrors,
      elem: s_DescErrors.m_Size,
      src: &v5);
  }
  CThreadSpinRWLock::LockForWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
  CUtlSymbolTable::AddString(this: &CUndoManager::s_UndoSymbolTable, result: (CUtlSymbol *)&context, pString: v2);
  CThreadSpinRWLock::UnlockWrite(this: &CUndoManager::s_UndoSymbolTable.m_lock);
  return (unsigned __int16)context;
}

//------------------------------------------------------------------------------
// Address: 0x00437010
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  int m_Tail; // ebx
  IUndoElement *m_Element; // ebp
  const char *v5; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v8; // eax
  char v9; // bl
  bool v10; // [esp+12h] [ebp-6h]
  bool v11; // [esp+13h] [ebp-5h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 108) & 8) != 0;
  v10 = v2;
  *((_BYTE *)this + 108) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    m_Tail = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
    v5 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v8 = &m_pMemory[m_Size - 1];
    if ( v8 != nullptr )
      *v8 = m_Element;
    v11 = m_Element->IsEndOfStream(this: m_Element);
    CUtlLinkedList<IUndoElement *,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
      this: &this->m_UndoList,
      elem: m_Tail);
    this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = m_Tail;
    v2 = v10;
  }
  while ( !v11 );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v9 = *((_BYTE *)this + 108) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 108) ^= v9 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00437140
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlVector<UndoInfo_t,CUtlMemory<UndoInfo_t,int> > *list)
{
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  bool v7; // bl
  const char *v8; // eax
  IUndoElement_vtbl *v9; // edx
  int v10; // eax
  IUndoElement_vtbl *v11; // edx
  const char *v12; // eax
  int ops; // [esp+10h] [ebp-1Ch] BYREF
  UndoInfo_t info; // [esp+14h] [ebp-18h] BYREF
  int v15; // [esp+28h] [ebp-4h]

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 32, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = this->m_UndoList.m_Tail;
  for ( *(_DWORD *)&info.terminator = 0; m_Tail != -1; m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    ++*(_DWORD *)&info.terminator;
    v5 = m_Tail;
    m_Element = m_pMemory[v5].m_Element;
    v7 = m_Element->IsEndOfStream(this: m_Element);
    v8 = m_Element->UndoDesc(this: m_Element);
    v9 = m_Element->__vftable;
    info.redo = v8;
    v10 = (int)v9->RedoDesc(this: m_Element);
    v11 = m_Element->__vftable;
    info.numoperations = v10;
    v12 = v11->GetDesc(this: m_Element);
    CUtlSymbolTable::AddString(this: &table, result: (CUtlSymbol *)&ops, pString: v12);
    info.undo = CUtlSymbolTable::String(this: &table, id: (CUtlSymbol)ops);
    LOBYTE(info.desc) = v7;
    if ( v7 )
      v15 = *(_DWORD *)&info.terminator;
    else
      v15 = 1;
    CUtlVector<UndoInfo_t,CUtlMemory<UndoInfo_t,int>>::InsertBefore(
      this: list,
      elem: list->m_Size,
      src: (const UndoInfo_t *)&info.desc);
    if ( v7 )
      *(_DWORD *)&info.terminator = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004372B0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  unsigned __int16 m_Id; // di
  bool v3; // bl
  const char *v4; // edi

  if ( (*((_BYTE *)this + 108) & 8) != 0 )
  {
    m_Id = this->m_UndoDesc.m_Id;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    CThreadSpinRWLock::LockForRead(this: &CUndoManager::s_UndoSymbolTable.m_lock);
    v4 = CUtlSymbolTable::String(this: &CUndoManager::s_UndoSymbolTable, id: (CUtlSymbol)m_Id);
    CThreadSpinRWLock::UnlockRead(this: &CUndoManager::s_UndoSymbolTable.m_lock);
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, v4);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437330
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 108) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 108) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437390
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebp
  const char *v5; // eax
  int v6; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // eax
  int m_Previous; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // eax
  IUndoElement *v11; // ecx
  char v12; // bl
  bool v13; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 108) & 8) != 0;
  *((_BYTE *)this + 108) &= ~8u;
  v13 = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    CUtlLinkedList<IUndoElement *,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::Unlink(
      this: &this->m_UndoList,
      elem: v6);
    v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
    v7->m_Next = -1;
    v7->m_Previous = this->m_UndoList.m_Tail;
    this->m_UndoList.m_Tail = v6;
    m_Previous = v7->m_Previous;
    if ( m_Previous == -1 )
      this->m_UndoList.m_Head = v6;
    else
      this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v6;
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    ++this->m_UndoList.m_ElementCount;
    v10 = &m_pMemory[v6];
    if ( v10 != nullptr )
      v10->m_Element = v4;
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v11 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      v13 = v11->IsEndOfStream(this: v11);
    }
  }
  while ( !v13 );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v12 = *((_BYTE *)this + 108) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 108) ^= v12 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046A1B0
// Name: _dynamic_initializer_for__CUndoManager::s_UndoSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CUndoManager::s_UndoSymbolTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &CUndoManager::s_UndoSymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: false);
  CThreadSpinRWLock::CThreadSpinRWLock(this: &CUndoManager::s_UndoSymbolTable.m_lock);
  return atexit(func: dynamic_atexit_destructor_for__CUndoManager::s_UndoSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A840
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0046A850
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0046A860
// Name: _dynamic_atexit_destructor_for__CUndoManager::s_UndoSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CUndoManager::s_UndoSymbolTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &CUndoManager::s_UndoSymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x0046A870
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0046A1E0
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x80u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046A220
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2.m_ElementDict);
  s_DMSerializerKeyValues2.m_bFlatMode = false;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A240
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2Flat__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2Flat.m_ElementDict);
  s_DMSerializerKeyValues2Flat.m_bFlatMode = true;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A260
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A270
// Name: _dynamic_initializer_for__s_XMLCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_XMLCharConversion__()
{
  return CUtlCharConversion::CUtlCharConversion(
           this: &s_XMLCharConversion,
           nEscapeChar: 38,
           pDelimiter: defaultValue,
           nCount: 5,
           pArray: s_pConversionArrays_XMLCharConversion);
}

//------------------------------------------------------------------------------
// Address: 0x0046A290
// Name: _dynamic_initializer_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DmElementFramework__()
{
  CDependencyGraph::CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = nullptr;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nAllocationCount = 256;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nGrowSize = 128;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = (DmElementHandle_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 1024);
  g_DmElementFramework.m_dirtyElements.m_Size = 0;
  g_DmElementFramework.m_dirtyElements.m_pElements = g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory;
  g_DmElementFramework.m_phase = PH_EDIT;
  return atexit(func: dynamic_atexit_destructor_for__g_DmElementFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A300
// Name: _dynamic_initializer_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrNodePool__()
{
  CMemoryPool::CMemoryPool(this: &g_AttrNodePool, blockSize: 28, numElements: 1000, growMode: 1, pszAllocOwner: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A330
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  long double v0; // st7

  s_EmptyConVar.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_pszString = (char *)operator new(nSize: s_EmptyConVar.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_StringLength);
  s_EmptyConVar.m_fMinVal = 0.0;
  s_EmptyConVar.m_fMaxVal = 0.0;
  s_EmptyConVar.m_bHasMin = false;
  s_EmptyConVar.m_bHasMax = false;
  s_EmptyConVar.m_fnChangeCallback = nullptr;
  v0 = atof(nptr: s_EmptyConVar.m_pszString);
  s_EmptyConVar.m_fValue = v0;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_nValue = (int)v0;
  s_EmptyConVar.m_pszName = defaultValue;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    ((void (*)(void))s_EmptyConVar.Init)();
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A420
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A430
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A490
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A4C0
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A4D0
// Name: _dynamic_initializer_for__s_ImportSFMV9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV9__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV9, formatName: "sfm_v9", nextFormatName: "sfm_v10");
  s_ImportSFMV9.__vftable = (CImportSFMV9_vtbl *)&CImportSFMV9::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A4F0
// Name: _dynamic_initializer_for__s_ImportSFMV8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV8__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV8, formatName: "sfm_v8", nextFormatName: "sfm_v9");
  s_ImportSFMV8.__vftable = (CImportSFMV8_vtbl *)&CImportSFMV8::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A510
// Name: _dynamic_initializer_for__s_ImportSFMV7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV7__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV7, formatName: "sfm_v7", nextFormatName: "sfm_v8");
  s_ImportSFMV7.__vftable = (CImportSFMV7_vtbl *)&CImportSFMV7::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A530
// Name: _dynamic_initializer_for__s_ImportSFMV6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV6__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV6, formatName: "sfm_v6", nextFormatName: "sfm_v7");
  s_ImportSFMV6.__vftable = (CImportSFMV6_vtbl *)&CImportSFMV6::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A550
// Name: _dynamic_initializer_for__s_ImportSFMV5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV5__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV5, formatName: "sfm_v5", nextFormatName: "sfm_v6");
  s_ImportSFMV5.__vftable = (CImportSFMV5_vtbl *)&CImportSFMV5::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A570
// Name: _dynamic_initializer_for__s_ImportSFMV4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV4__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV4, formatName: "sfm_v4", nextFormatName: "sfm_v5");
  s_ImportSFMV4.__vftable = (CImportSFMV4_vtbl *)&CImportSFMV4::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A590
// Name: _dynamic_initializer_for__s_ImportSFMV3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV3__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV3, formatName: "sfm_v3", nextFormatName: "sfm_v4");
  s_ImportSFMV3.__vftable = (CImportSFMV3_vtbl *)&CImportSFMV3::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A5B0
// Name: _dynamic_initializer_for__s_ImportSFMV2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSFMBaseImporter *dynamic_initializer_for__s_ImportSFMV2__()
{
  CSFMBaseImporter *result; // eax

  result = CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportSFMV2, formatName: "sfm_v2", nextFormatName: "sfm_v3");
  s_ImportSFMV2.__vftable = (CImportSFMV2_vtbl *)&CImportSFMV2::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A5D0
// Name: _dynamic_initializer_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ImportDmxV1__()
{
  CSFMBaseImporter::CSFMBaseImporter(this: &s_ImportDmxV1, formatName: "sfm_v1", nextFormatName: "sfm_v2");
  s_ImportDmxV1.__vftable = (CImportSFMV1_vtbl *)&CImportSFMV1::`vftable';
  s_ImportDmxV1.m_fixedElements.m_Elements.m_pMemory = nullptr;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nAllocationCount = 0;
  s_ImportDmxV1.m_fixedElements.m_Elements.m_nGrowSize = 0;
  s_ImportDmxV1.m_fixedElements.m_Root = -1;
  s_ImportDmxV1.m_fixedElements.m_NumElements = 0;
  s_ImportDmxV1.m_fixedElements.m_FirstFree = -1;
  s_ImportDmxV1.m_fixedElements.m_LastAlloc.index = -1;
  s_ImportDmxV1.m_fixedElements.m_pElements = nullptr;
  s_ImportDmxV1.m_fixedElements.m_LessFunc = (bool (__cdecl *)(CDmElement *const *, CDmElement *const *))CDefOps<CDmAttribute *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__s_ImportDmxV1__);
}

//------------------------------------------------------------------------------
// Address: 0x0046A680
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0046A6B0
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0046A6E0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x0046A6F0
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CMemoryPool::~CMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x0046A700
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CMemoryPool::~CMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x0046A710
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CMemoryPool::~CMemoryPool(this: &g_AttrAlloc);
}

//------------------------------------------------------------------------------
// Address: 0x0046A880
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0046A8C0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0046A900
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x0046A910
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0046A930
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CMemoryPool::~CMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0046A940
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_pszString);
    s_EmptyConVar.m_pszString = nullptr;
  }
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0046A980
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046A9C0
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046A9D0
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0043DA50
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043DA60
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0043DA80
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DB00
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x0043DB10
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x0043DB20
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x0043DB30
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DB60
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DC00
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DC40
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0043DC60
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043DC70
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043DD10
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DD70
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return &defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x0043DF30
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x0043DF50
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return &defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0043E0C0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x0043E170
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E280
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043E300
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E350
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043E360
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043E3F0
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E490
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_0 & 2) == 0 )
    {
      _S1_0 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: &s_DescErrors.m_Memory,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E5F0
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043E790
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E970
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E9D0
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EA30
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00483F00
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x00483F10
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x00483F20
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x00483EE0
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00483F30
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x00483F70
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x00483FB0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x00483FC0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x00483FD0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x00484010
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

//------------------------------------------------------------------------------
// Address: 0x00484020
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00484070
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004840B0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x004840C0
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00442DF0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00442E00
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00442E20
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: str, a2: "%s%s");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442EA0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x00442EB0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x00442EC0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00442ED0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442F00
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442FA0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442FE0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00443000
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443010
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443020
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443080
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return &pParentName;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00443240
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00443260
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return &pParentName;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00443360
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x00443410
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443520
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004435A0
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004435F0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00443600
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443690
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443730
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_0 & 2) == 0 )
    {
      _S1_0 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443890
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00443A30
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443C10
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443C70
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443CD0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00575B90
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0057DF50
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF60
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF70
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF20
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF30
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF80
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0057DFC0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0057E000
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E010
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0057E020
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0057E060
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00447AC0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447AD0
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00447AF0
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447B70
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x00447B80
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x00447B90
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x00447BA0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447BD0
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge::<unnamed_type_u> *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = *(_DWORD *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                             a1: g_pDataModel.u,
                                             a2: &udesc,
                                             a3: v5);
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)&udesc;
      }
      else
      {
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                                         a1: g_pDataModel.u,
                                                         a2: &udesc,
                                                         a3: rdesc);
      }
      this->m_RedoDesc.u = (CUtlSymbolLarge::<unnamed_type_u>)p_udesc->m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447C70
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447CB0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00447CD0
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447CE0
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447CF0
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447D50
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00447EA0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers,
    src: (vgui::TreeNode **)&pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00447EC0
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00447EE0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  char sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  this->m_PreviousChainingID = 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x00447F90
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  char v4; // al
  int v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, (CUtlMemory<vgui::TreeNode *,int> *)&handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    sg.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004480A0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448120
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_RedoStack);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448170
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448180
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_Notifiers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (vgui::TreeNode *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00448210
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004482B0
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_1 & 1) == 0 )
    {
      _S1_1 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_1 & 2) == 0 )
    {
      _S1_1 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<wchar_t,int>::Grow(
          this: (CUtlMemory<wchar_t,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448410
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Undo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004485B0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448790
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004487F0
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448850
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Redo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006B3700
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x006B3710
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x006B3720
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x006B3730
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x006B3770
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x006B37B0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x006B37C0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x006B37D0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x006B37E0
// Name: _dynamic_atexit_destructor_for__dme_properties_maxsearchresults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dme_properties_maxsearchresults__()
{
  ConVar::~ConVar(this: &dme_properties_maxsearchresults);
}

//------------------------------------------------------------------------------
// Address: 0x006B37F0
// Name: _dynamic_atexit_destructor_for__s_AssetTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_AssetTypes__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_AssetTypes.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x006B3800
// Name: _dynamic_atexit_destructor_for__SelectionInfo_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__SelectionInfo_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &SelectionInfo_t::s_Allocator);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00443960
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443970
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00443990
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: str, a2: "%s%s");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443A10
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x00443A20
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x00443A40
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443A70
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443B10
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443B50
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00443B70
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443B80
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443C30
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443C90
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return &pch;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00443E50
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00443E70
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return &pch;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00443F70
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x00444020
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444130
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004441B0
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444200
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00444210
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004442A0
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444340
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_0 & 2) == 0 )
    {
      _S1_0 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n");
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004444A0
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00444640
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444820
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444880
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004448E0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00577B80
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0057FF30
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0057FF40
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0057FF50
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0057FF00
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x0057FF10
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0057FF60
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0057FFA0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0057FFE0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x0057FFF0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x00580000
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x00580040
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004B2240
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B2250
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x004B2270
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B22F0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x004B2300
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x004B2310
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x004B2320
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2350
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge::<unnamed_type_u> *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = *(_DWORD *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                             a1: g_pDataModel.u,
                                             a2: &udesc,
                                             a3: v5);
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)&udesc;
      }
      else
      {
        p_udesc = (CUtlSymbolLarge::<unnamed_type_u> *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                                         a1: g_pDataModel.u,
                                                         a2: &udesc,
                                                         a3: rdesc);
      }
      this->m_RedoDesc.u = (CUtlSymbolLarge::<unnamed_type_u>)p_udesc->m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B23F0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2430
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x004B2450
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B2460
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B2470
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B24D0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return pDeltaStateName;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x004B2620
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x004B2640
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return pDeltaStateName;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004B2740
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  char sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x004B27F0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  char v4; // al
  int v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    sg.m_bOldValue = v4;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v5 + 232))(a1: g_pDataModel.u, a2: 0);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
      a1: g_pDataModel.u,
      a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2900
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B2980
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B29D0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x004B29E0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2A70
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2B10
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_5 & 1) == 0 )
    {
      _S1_5 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_5 & 2) == 0 )
    {
      _S1_5 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: result,
      a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2C70
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Undo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004B2E10
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVectorAuto<s_compressed_t>,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2FF0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3050
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B30B0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                    + 460))(
    a1: g_pDataModel.u,
    a2: "CUndoManager::Redo",
    a3: 1,
    a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005E1BF0
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x005EBEF0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF00
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF10
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x005EBED0
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF20
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005EBF60
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005EBFA0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x005EBFB0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x005EBFC0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x005EC000
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0044E1C0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044E1D0
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0044E1F0
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E270
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x0044E280
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x0044E290
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x0044E2A0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E2D0
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E370
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E3B0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044E3D0
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044E3E0
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044E3F0
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E450
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return Ptr;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x0044E610
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x0044E630
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return Ptr;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0044E730
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x0044E7E0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E8F0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044E970
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E9C0
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044E9D0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_Notifiers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (CUtlSymbolTable::StringPool_t *)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044EA60
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EB00
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_0 & 1) == 0 )
    {
      _S1_0 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_0 & 2) == 0 )
    {
      _S1_0 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EC60
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_RedoStack,
        num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044EE00
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EFE0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F040
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F0A0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x005754D0
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0057D620
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x0057D630
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x0057D640
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x0057D5F0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x0057D600
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0057D650
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0057D690
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x0057D6D0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x0057D6E0
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0057D6F0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x0057D730
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0051FDB0
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051FDC0
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x0051FDE0
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char spaces[128]; // [esp+0h] [ebp-884h] BYREF
  char str[2051]; // [esp+80h] [ebp-804h] BYREF
  char v6; // [esp+883h] [ebp-1h]
  va_list ap; // [esp+890h] [ebp+Ch] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: &str[4], count: 0x7FFu, format: fmt, ap);
    v6 = 0;
    _V_memset(dest: &spaces[4], fill: nullptr, count: 0x80u);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++ + 4] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", &spaces[4], &str[4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FE80
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE90
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x0051FEA0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x0051FEB0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FEE0
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_m_UndoDesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
        p_m_UndoDesc = &this->m_UndoDesc;
      else
        p_m_UndoDesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      this->m_RedoDesc = (CUtlSymbolLarge)p_m_UndoDesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FF80
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051FFC0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x0051FFE0
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051FFF0
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x005200A0
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebp
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520110
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x005202C0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<CHitArea *,CUtlMemory<CHitArea *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers,
    src: (vgui::TreeNode **)&pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x005202D0
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x005202F0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool v6; // [esp+Ch] [ebp-4h]

  v6 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00520390
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // ebp
  int v3; // edi
  IUndoElement *v4; // esi
  const char *v5; // eax
  void *m_nAllocationCount; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+10h] [ebp-18h] BYREF
  void *v8; // [esp+24h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  if ( m_Size != 0 )
  {
    memset(&handles.m_Memory.m_nAllocationCount, 0, 16);
    v8 = nullptr;
    CDataModel::GetInvalidHandles(
      this: g_pDataModelImp,
      handles: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&handles.m_Memory.m_nAllocationCount);
    CDataModel::MarkHandlesValid(
      this: g_pDataModelImp,
      handles: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&handles.m_Memory.m_nAllocationCount);
    LOBYTE(handles.m_Memory.m_pMemory) = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v4 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v5 = v4->GetDesc(this: v4);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v5);
        v4->Release(this: v4);
        ++v3;
      }
      while ( v3 < m_Size );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(
      this: g_pDataModelImp,
      handles: (CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *)&handles.m_Memory.m_nAllocationCount);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: (bool)handles.m_Memory.m_pMemory);
    m_nAllocationCount = (void *)handles.m_Memory.m_nAllocationCount;
    handles.m_pElements = nullptr;
    if ( handles.m_Size >= 0 )
    {
      if ( handles.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)handles.m_Memory.m_nAllocationCount);
        m_nAllocationCount = nullptr;
        handles.m_Memory.m_nAllocationCount = 0;
      }
      handles.m_Memory.m_nGrowSize = 0;
    }
    v8 = m_nAllocationCount;
    if ( handles.m_Size >= 0 && m_nAllocationCount != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005204B0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00520530
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RedoStack);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll((CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520580
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x00520590
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  int m_Size; // edx
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *p_m_Notifiers; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // esi

  m_Size = this->m_Notifiers.m_Size;
  p_m_Notifiers = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Notifiers;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_Memory.m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: p_m_Notifiers,
    elem: m_Size,
    src: (vgui::TreeNode **)&pNotify);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005205D0
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520670
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        char *context)
{
  int v3; // eax
  CUtlSymbol v5; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_13 & 1) == 0 )
    {
      _S1_13 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_13 & 2) == 0 )
    {
      _S1_13 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &v5, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != v5.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&s_DescErrors,
        elem: s_DescErrors.m_Size,
        src: &v5.m_Id);
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520780
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  int m_Tail; // ebx
  IUndoElement *m_Element; // ebp
  const char *v5; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v8; // eax
  char v9; // bl
  bool v10; // [esp+12h] [ebp-6h]
  bool v11; // [esp+13h] [ebp-5h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  v10 = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    m_Tail = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
    v5 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v8 = &m_pMemory[m_Size - 1];
    if ( v8 != nullptr )
      *v8 = m_Element;
    v11 = m_Element->IsEndOfStream(this: m_Element);
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: m_Tail);
    this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = m_Tail;
    v2 = v10;
  }
  while ( !v11 );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v9 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v9 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x005208B0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlVector<UndoInfo_t,CUtlMemory<UndoInfo_t,int> > *list)
{
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  bool v7; // bl
  const char *v8; // eax
  IUndoElement_vtbl *v9; // edx
  int v10; // eax
  IUndoElement_vtbl *v11; // edx
  char *v12; // eax
  int ops; // [esp+10h] [ebp-1Ch] BYREF
  UndoInfo_t info; // [esp+14h] [ebp-18h] BYREF
  int v15; // [esp+28h] [ebp-4h]

  if ( (_S2_3 & 1) == 0 )
  {
    _S2_3 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = this->m_UndoList.m_Tail;
  for ( *(_DWORD *)&info.terminator = 0; m_Tail != -1; m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    ++*(_DWORD *)&info.terminator;
    v5 = m_Tail;
    m_Element = m_pMemory[v5].m_Element;
    v7 = m_Element->IsEndOfStream(this: m_Element);
    v8 = m_Element->UndoDesc(this: m_Element);
    v9 = m_Element->__vftable;
    info.redo = v8;
    v10 = (int)v9->RedoDesc(this: m_Element);
    v11 = m_Element->__vftable;
    info.numoperations = v10;
    v12 = (char *)v11->GetDesc(this: m_Element);
    CUtlSymbolTable::AddString(this: &table, result: (CUtlSymbol *)&ops, pString: v12);
    info.undo = CUtlSymbolTable::String(this: &table, id: (CUtlSymbol)ops);
    LOBYTE(info.desc) = v7;
    if ( v7 )
      v15 = *(_DWORD *)&info.terminator;
    else
      v15 = 1;
    CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertBefore(
      this: (CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int> > *)list,
      elem: list->m_Size,
      src: (const InputEvent_t *)&info.desc);
    if ( v7 )
      *(_DWORD *)&info.terminator = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520A30
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520A90
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520AF0
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebp
  const char *v5; // eax
  int v6; // eax
  int v7; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v11; // eax
  IUndoElement *v12; // ecx
  char v13; // bl
  bool v14; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  *((_BYTE *)this + 116) &= ~8u;
  v14 = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    v7 = v6;
    if ( v6 != -1 )
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
        elem: v6);
      v8 = &this->m_UndoList.m_Memory.m_pMemory[v7];
      v8->m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      v8->m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v7;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v7;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v7;
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v11 = &m_pMemory[v7];
      if ( v11 != nullptr )
        v11->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v12 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      v14 = v12->IsEndOfStream(this: v12);
    }
  }
  while ( !v14 );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v13 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v13 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00535770
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x00535780
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x00535790
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x005357A0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x005357E0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x00535820
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x00535830
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00535850
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x00535860
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00546000
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00546010
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x00546030
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005460B0
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x005460C0
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x005460D0
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x005460E0
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546110
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005461B0
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005461F0
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x00546210
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00546220
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00546230
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546290
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return var;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x005463E0
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x00546400
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return var;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00546500
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x005465B0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005466C0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00546740
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Notifiers);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546790
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x005467A0
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<S3RGBA,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_Notifiers = (CUtlMemory<S3RGBA,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (S3RGBA)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00546830
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005468D0
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_6 & 1) == 0 )
    {
      _S1_6 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_6 & 2) == 0 )
    {
      _S1_6 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
          this: (CUtlMemory<short,int> *)&s_DescErrors,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546A30
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00546BD0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(
        CUndoManager *this,
        CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2_2 & 1) == 0 )
  {
    _S2_2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = (char *)m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CVertVisit,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546DB0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546E10
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00546E70
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B1F80
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x006BC2D0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x006BC2E0
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x006BC2F0
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x006BC2B0
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x006BC300
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x006BC340
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs> *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x006BC380
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC390
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x006BC3A0
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x006BC3E0
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10070480
// Name: public: bool CUndoManager::IsSuppressingNotify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUndoManager::IsSuppressingNotify(CUndoManager *this)
{
  return (*((_BYTE *)this + 116) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070490
// Name: public: void CUndoManager::SetSuppressingNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetSuppressingNotify(CUndoManager *this, bool bSuppress)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (16 * bSuppress)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x100704B0
// Name: private: void CUndoManager::Trace(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CUndoManager::Trace(CUndoManager *this, const char *fmt, ...)
{
  int v2; // ecx
  int i; // eax
  char str[2048]; // [esp+4h] [ebp-880h] BYREF
  char spaces[128]; // [esp+804h] [ebp-80h] BYREF
  va_list ap; // [esp+894h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( (*((_BYTE *)this + 116) & 2) != 0 )
  {
    _vsnprintf(string: str, count: 0x7FFu, format: fmt, ap);
    str[2047] = 0;
    _V_memset(dest: spaces, fill: 0, count: 128);
    v2 = 3 * this->m_nNesting;
    for ( i = 0; i < v2; spaces[i++] = 32 )
    {
      if ( i >= 127 )
        break;
    }
    _Msg(a1: "%s%s", spaces, str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070530
// Name: public: void CUndoManager::SetUndoDepth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::SetUndoDepth(CUndoManager *this, int nMaxUndoDepth)
{
  this->m_nMaxUndoDepth = nMaxUndoDepth;
}

//------------------------------------------------------------------------------
// Address: 0x10070540
// Name: public: void CUndoManager::EnableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::EnableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x10070550
// Name: public: void CUndoManager::DisableUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::DisableUndo(CUndoManager *this)
{
  *((_BYTE *)this + 116) &= ~8u;
}

//------------------------------------------------------------------------------
// Address: 0x10070560
// Name: public: void CUndoManager::PushNotificationScope(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushNotificationScope(
        CUndoManager *this,
        const char *pReason,
        int nNotifySource,
        int nNotifyFlags)
{
  int m_nNotifyNesting; // eax

  m_nNotifyNesting = this->m_nNotifyNesting;
  this->m_nNotifyNesting = m_nNotifyNesting + 1;
  if ( m_nNotifyNesting == 0 )
  {
    this->m_pNotifyReason = pReason;
    this->m_nNotifySource = nNotifySource;
    this->m_nNotifyFlags = nNotifyFlags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070590
// Name: public: void CUndoManager::PushUndo(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushUndo(CUndoManager *this, const char *udesc, const char *rdesc, int nChainingID)
{
  const char *v5; // edi
  int m_nNesting; // eax
  int v7; // eax
  CUtlSymbolLarge *p_udesc; // eax

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    v5 = udesc;
    CUndoManager::Trace(this, fmt: "[%d] Pushing undo '%s'\n", this->m_nNesting + 1, udesc);
    m_nNesting = this->m_nNesting;
    this->m_nNesting = m_nNesting + 1;
    if ( m_nNesting == 0 )
    {
      v7 = nChainingID;
      this->m_PreviousChainingID = this->m_nChainingID;
      this->m_nChainingID = v7;
      this->m_UndoDesc.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: v5)->u.m_Id;
      if ( v5 == rdesc )
      {
        udesc = this->m_UndoDesc.u.m_pAsString;
        p_udesc = (CUtlSymbolLarge *)&udesc;
      }
      else
      {
        p_udesc = g_pDataModel->GetSymbol(this: g_pDataModel, result: &udesc, a3: rdesc);
      }
      this->m_RedoDesc = (CUtlSymbolLarge)p_udesc->u.m_Id;
      *((_BYTE *)this + 116) |= 1u;
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070630
// Name: public: class CUtlSymbolLarge CUndoManager::GetRedoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetRedoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_RedoDesc;
    return result;
  }
  else
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070670
// Name: public: void CUndoManager::TraceUndo(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::TraceUndo(CUndoManager *this, bool state)
{
  *((_BYTE *)this + 116) ^= (*((_BYTE *)this + 116) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10070690
// Name: public: bool CUndoManager::HasUndoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasUndoData(CUndoManager *this)
{
  return this->m_UndoList.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100706A0
// Name: public: bool CUndoManager::HasRedoData(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUndoManager::HasRedoData(CUndoManager *this)
{
  return this->m_RedoStack.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070740
// Name: public: void CUndoManager::PopNotificationScope(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PopNotificationScope(CUndoManager *this, bool bAbort)
{
  int m_Size; // ebx
  int i; // edi
  IDmNotify *v6; // ecx

  if ( this->m_nNotifyNesting-- == 1 )
  {
    if ( !bAbort && (*((_BYTE *)this + 116) & 0x10) == 0 && (this->m_nNotifyFlags & 0xF000) != 0 )
    {
      m_Size = this->m_Notifiers.m_Size;
      for ( i = 0; i < m_Size; ++i )
      {
        v6 = this->m_Notifiers.m_Memory.m_pMemory[i];
        v6->NotifyDataChanged(this: v6, a2: this->m_pNotifyReason, a3: this->m_nNotifySource, a4: this->m_nNotifyFlags);
      }
    }
    this->m_nNotifySource = 0;
    this->m_nNotifyFlags = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100707A0
// Name: public: char const __near * CUndoManager::UndoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::UndoDesc(CUndoManager *this)
{
  IUndoElement *m_Element; // ecx

  if ( this->m_UndoList.m_ElementCount <= 0 )
    return defaultValue;
  m_Element = this->m_UndoList.m_Memory.m_pMemory[this->m_UndoList.m_Tail].m_Element;
  return m_Element->UndoDesc(this: m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10070960
// Name: public: void CUndoManager::RemoveNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::RemoveNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlVector<IDmNotify *,CUtlMemory<IDmNotify *,int>>::FindAndRemove(this: &this->m_Notifiers, src: &pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x10070980
// Name: public: char const __near * CUndoManager::RedoDesc(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CUndoManager::RedoDesc(CUndoManager *this)
{
  IUndoElement *v2; // ecx

  if ( this->m_RedoStack.m_Size <= 0 )
    return defaultValue;
  v2 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
  return v2->RedoDesc(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10070AF0
// Name: public: void CUndoManager::WipeUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeUndo(CUndoManager *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // eax
  int v4; // esi
  const char *v5; // eax
  bool sg_4; // [esp+Ch] [ebp-4h]

  sg_4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  m_Head = this->m_UndoList.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      v5 = m_pMemory[v4].m_Element->GetDesc(this: m_pMemory[v4].m_Element);
      CUndoManager::Trace(this, fmt: "WipeUndo '%s'\n", v5);
      this->m_UndoList.m_Memory.m_pMemory[v4].m_Element->Release(this: this->m_UndoList.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      m_Head = this->m_UndoList.m_Memory.m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  this->m_PreviousChainingID = 0;
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: sg_4);
}

//------------------------------------------------------------------------------
// Address: 0x10070BA0
// Name: public: void CUndoManager::WipeRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::WipeRedo(CUndoManager *this)
{
  int m_Size; // esi
  int v3; // edi
  bool v4; // al
  IDataModel_vtbl *v5; // edx
  IUndoElement *v6; // esi
  const char *v7; // eax
  DmElementHandle_t *m_pMemory; // eax
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > handles; // [esp+Ch] [ebp-20h] BYREF
  CDisableUndoScopeGuard sg; // [esp+20h] [ebp-Ch]
  int c; // [esp+28h] [ebp-4h]

  m_Size = this->m_RedoStack.m_Size;
  v3 = 0;
  c = m_Size;
  if ( m_Size != 0 )
  {
    memset(&handles, 0, sizeof(handles));
    CDataModel::GetInvalidHandles(this: g_pDataModelImp, &handles);
    CDataModel::MarkHandlesValid(this: g_pDataModelImp, &handles);
    v4 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
    v5 = g_pDataModel->__vftable;
    sg.m_bOldValue = v4;
    v5->SetUndoEnabled(this: g_pDataModel, a2: false);
    if ( m_Size > 0 )
    {
      do
      {
        v6 = this->m_RedoStack.m_Memory.m_pMemory[v3];
        v7 = v6->GetDesc(this: v6);
        CUndoManager::Trace(this, fmt: "WipeRedo '%s'\n", v7);
        v6->Release(this: v6);
        ++v3;
      }
      while ( v3 < c );
    }
    this->m_RedoStack.m_Size = 0;
    CDataModel::MarkHandlesInvalid(this: g_pDataModelImp, &handles);
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&sg.m_bOldValue);
    m_pMemory = handles.m_Memory.m_pMemory;
    handles.m_Size = 0;
    if ( handles.m_Memory.m_nGrowSize >= 0 )
    {
      if ( handles.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: handles.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        handles.m_Memory.m_pMemory = nullptr;
      }
      handles.m_Memory.m_nAllocationCount = 0;
    }
    handles.m_pElements = m_pMemory;
    if ( handles.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070CB0
// Name: public: CUndoManager::CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
CUndoManager *__thiscall CUndoManager::CUndoManager(CUndoManager *this)
{
  char v2; // dl

  this->m_UndoList.m_Memory.m_pMemory = nullptr;
  this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  this->m_UndoList.m_Memory.m_nGrowSize = 0;
  this->m_UndoList.m_LastAlloc.index = -1;
  this->m_UndoList.m_Head = -1;
  this->m_UndoList.m_Tail = -1;
  this->m_UndoList.m_FirstFree = -1;
  this->m_UndoList.m_ElementCount = 0;
  this->m_UndoList.m_NumAlloced = 0;
  this->m_UndoList.m_pElements = this->m_UndoList.m_Memory.m_pMemory;
  this->m_RedoStack.m_Memory.m_pMemory = nullptr;
  this->m_RedoStack.m_Memory.m_nAllocationCount = 0;
  this->m_RedoStack.m_Memory.m_nGrowSize = 0;
  this->m_RedoStack.m_Size = 0;
  this->m_RedoStack.m_pElements = nullptr;
  this->m_Notifiers.m_Memory.m_pMemory = nullptr;
  this->m_Notifiers.m_Memory.m_nAllocationCount = 0;
  this->m_Notifiers.m_Memory.m_nGrowSize = 0;
  this->m_Notifiers.m_Size = 0;
  this->m_Notifiers.m_pElements = nullptr;
  this->m_nMaxUndoDepth = 4096;
  this->m_nNesting = 0;
  this->m_nNotifyNesting = 0;
  this->m_UndoDesc.u.m_Id = -1;
  this->m_RedoDesc.u.m_Id = -1;
  v2 = *((_BYTE *)this + 116) & 0xE0 | 8;
  this->m_nNotifySource = 0;
  this->m_nNotifyFlags = 0;
  this->m_nItemsAddedSinceStartOfStream = 0;
  *((_BYTE *)this + 116) = v2;
  this->m_nChainingID = 0;
  this->m_PreviousChainingID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10070D30
// Name: public: CUndoManager::~CUndoManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::~CUndoManager(CUndoManager *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Notifiers);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RedoStack);
  CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::RemoveAll(this: &this->m_UndoList);
  if ( this->m_UndoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UndoList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UndoList.m_Memory.m_pMemory);
      this->m_UndoList.m_Memory.m_pMemory = nullptr;
    }
    this->m_UndoList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070D80
// Name: public: void CUndoManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Shutdown(CUndoManager *this)
{
  CUndoManager::WipeUndo(this);
  CUndoManager::WipeRedo(this);
}

//------------------------------------------------------------------------------
// Address: 0x10070D90
// Name: public: bool CUndoManager::InstallNotificationCallback(class IDmNotify __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUndoManager::InstallNotificationCallback(CUndoManager *this, IDmNotify *pNotify)
{
  CUtlMemory<S3RGBA,int> *p_m_Notifiers; // esi
  int m_Size; // ecx
  int v4; // eax
  IDmNotify **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  p_m_Notifiers = (CUtlMemory<S3RGBA,int> *)&this->m_Notifiers;
  m_Size = this->m_Notifiers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = (IDmNotify **)p_m_Notifiers->m_pMemory;
    while ( *m_pMemory != pNotify )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    if ( v4 >= 0 )
      return 0;
  }
LABEL_5:
  m_nAllocationCount = p_m_Notifiers->m_nAllocationCount;
  v7 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Notifiers, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Notifiers[1].m_pMemory;
  v8 = p_m_Notifiers->m_pMemory;
  v9 = (int)p_m_Notifiers[1].m_pMemory - v7 - 1;
  p_m_Notifiers[1].m_nAllocationCount = (int)p_m_Notifiers->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
  v10 = &p_m_Notifiers->m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = (S3RGBA)pNotify;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070E20
// Name: public: void CUndoManager::PushRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::PushRedo(CUndoManager *this)
{
  const char *m_pAsString; // eax
  int m_nChainingID; // eax
  int m_Tail; // esi
  int v6; // esi
  IUndoElement *m_Element; // ebx

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Popping undo '%s'\n", this->m_nNesting, m_pAsString);
    if ( this->m_nNesting-- == 1 )
    {
      if ( this->m_nItemsAddedSinceStartOfStream > 0 )
      {
        CUndoManager::WipeRedo(this);
        m_nChainingID = this->m_nChainingID;
        if ( m_nChainingID != 0 && this->m_PreviousChainingID == m_nChainingID )
        {
          m_Tail = this->m_UndoList.m_Tail;
          if ( m_Tail != -1 )
          {
            while ( 1 )
            {
              v6 = m_Tail;
              m_Element = this->m_UndoList.m_Memory.m_pMemory[v6].m_Element;
              if ( m_Element != nullptr
                && m_Element->IsEndOfStream(this: this->m_UndoList.m_Memory.m_pMemory[v6].m_Element) )
              {
                break;
              }
              m_Tail = this->m_UndoList.m_Memory.m_pMemory[v6].m_Previous;
              if ( m_Tail == -1 )
              {
                this->m_nItemsAddedSinceStartOfStream = 0;
                return;
              }
            }
            m_Element->SetEndOfStream(this: m_Element, a2: false);
          }
        }
      }
      this->m_nItemsAddedSinceStartOfStream = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070EC0
// Name: public: class CUtlSymbolLarge CUndoManager::GetUndoDescInternal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CUndoManager::GetUndoDescInternal(
        CUndoManager *this,
        CUtlSymbolLarge *result,
        const char *context)
{
  int v3; // eax
  int m_Size; // eax
  int v5; // esi
  CUtlSymbol *m_pMemory; // ecx
  int v7; // eax
  CUtlSymbol *v8; // eax
  CUtlSymbol sym; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_nNesting > 0 )
  {
    result->u.m_Id = (int)this->m_UndoDesc;
    return result;
  }
  else
  {
    if ( (_S1_1 & 1) == 0 )
    {
      _S1_1 |= 1u;
      CUtlSymbolTable::CUtlSymbolTable(this: &s_DescErrorsTable, growSize: 0, initSize: 16, caseInsensitive: false);
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__);
    }
    if ( (_S1_1 & 2) == 0 )
    {
      _S1_1 |= 2u;
      s_DescErrors.m_Memory.m_pMemory = nullptr;
      s_DescErrors.m_Memory.m_nAllocationCount = 0;
      s_DescErrors.m_Memory.m_nGrowSize = 0;
      s_DescErrors.m_Size = 0;
      s_DescErrors.m_pElements = nullptr;
      atexit(func: CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__);
    }
    CUtlSymbolTable::AddString(this: &s_DescErrorsTable, result: &sym, pString: context);
    v3 = 0;
    if ( s_DescErrors.m_Size <= 0 )
      goto LABEL_11;
    while ( s_DescErrors.m_Memory.m_pMemory[v3].m_Id != sym.m_Id )
    {
      if ( ++v3 >= s_DescErrors.m_Size )
        goto LABEL_11;
    }
    if ( v3 == -1 )
    {
LABEL_11:
      _Warning(
        a1: "CUndoManager::GetUndoDescInternal:  undoable operation missing CUndoScopeGuard in application\nContext( %s )\n",
        context);
      m_Size = s_DescErrors.m_Size;
      v5 = s_DescErrors.m_Size;
      if ( s_DescErrors.m_Size + 1 > s_DescErrors.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlSymbol,int>::Grow(
          this: &s_DescErrors.m_Memory,
          num: s_DescErrors.m_Size - s_DescErrors.m_Memory.m_nAllocationCount + 1);
        m_Size = s_DescErrors.m_Size;
      }
      m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      s_DescErrors.m_Size = m_Size + 1;
      v7 = m_Size - v5;
      s_DescErrors.m_pElements = s_DescErrors.m_Memory.m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(
          dest: &s_DescErrors.m_Memory.m_pMemory[v5 + 1],
          src: &s_DescErrors.m_Memory.m_pMemory[v5],
          count: 2 * v7);
        m_pMemory = s_DescErrors.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v5];
      if ( v8 != nullptr )
        v8->m_Id = sym.m_Id;
    }
    g_pDataModel->GetSymbol(this: g_pDataModel, result, a3: context);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071020
// Name: public: void CUndoManager::Undo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Undo(CUndoManager *this)
{
  bool v2; // bl
  IUndoElement *m_Element; // ebx
  const char *v4; // eax
  IUndoElement **m_pMemory; // eax
  int m_Size; // ecx
  IUndoElement **v7; // eax
  bool v8; // al
  int v9; // ebx
  UtlLinkedListElem_t<IUndoElement *,int> *v10; // ecx
  int v11; // eax
  int m_Previous; // edi
  int *p_m_Next; // edx
  char v14; // bl
  int i; // [esp+Ch] [ebp-Ch]
  int *ia; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  bool bEndOfStream; // [esp+16h] [ebp-2h]
  bool saveEnabled; // [esp+17h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Undo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Undo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  do
  {
    if ( this->m_UndoList.m_ElementCount <= 0 )
      break;
    i = this->m_UndoList.m_Tail;
    m_Element = this->m_UndoList.m_Memory.m_pMemory[i].m_Element;
    v17 = i;
    v4 = m_Element->GetDesc(this: m_Element);
    CUndoManager::Trace(this, fmt: "  %s\n", v4);
    m_Element->Undo(this: m_Element);
    if ( this->m_RedoStack.m_Size >= this->m_RedoStack.m_Memory.m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_RedoStack, num: 1);
    ++this->m_RedoStack.m_Size;
    m_pMemory = this->m_RedoStack.m_Memory.m_pMemory;
    m_Size = this->m_RedoStack.m_Size;
    this->m_RedoStack.m_pElements = m_pMemory;
    v7 = &m_pMemory[m_Size - 1];
    if ( v7 != nullptr )
      *v7 = m_Element;
    v8 = m_Element->IsEndOfStream(this: m_Element);
    v9 = i;
    bEndOfStream = v8;
    if ( i < 0 || i >= this->m_UndoList.m_Memory.m_nAllocationCount || i > this->m_UndoList.m_LastAlloc.index )
    {
      v11 = 12 * i;
    }
    else
    {
      v10 = this->m_UndoList.m_Memory.m_pMemory;
      v11 = 12 * i;
      if ( this->m_UndoList.m_Memory.m_pMemory[v17].m_Previous != i )
      {
        m_Previous = v10[v17].m_Previous;
        ia = &v10[v17].m_Previous;
        p_m_Next = &v10[v17].m_Next;
        if ( m_Previous == -1 )
        {
          this->m_UndoList.m_Head = *p_m_Next;
        }
        else
        {
          v10[m_Previous].m_Next = *p_m_Next;
          v11 = v17 * 12;
        }
        if ( *p_m_Next == -1 )
        {
          this->m_UndoList.m_Tail = *ia;
        }
        else
        {
          this->m_UndoList.m_Memory.m_pMemory[*p_m_Next].m_Previous = *ia;
          v11 = v17 * 12;
        }
        *p_m_Next = v9;
        *ia = v9;
        --this->m_UndoList.m_ElementCount;
      }
    }
    *(int *)((char *)&this->m_UndoList.m_Memory.m_pMemory->m_Next + v11) = this->m_UndoList.m_FirstFree;
    this->m_UndoList.m_FirstFree = v9;
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v14 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v14 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100711C0
// Name: public: void CUndoManager::GetUndoInfo(class CUtlVector<struct UndoInfo_t,class CUtlMemory<struct UndoInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::GetUndoInfo(CUndoManager *this, CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *list)
{
  CUndoManager *v2; // esi
  int m_Tail; // eax
  int v5; // edi
  IUndoElement *m_Element; // esi
  const char *v7; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  UndoInfo_t *v10; // ecx
  int v11; // eax
  UndoInfo_t *v12; // eax
  __int64 info; // [esp+Ch] [ebp-20h]
  __int64 info_8; // [esp+14h] [ebp-18h]
  int info_16; // [esp+1Ch] [ebp-10h]
  int ops; // [esp+24h] [ebp-8h]
  CUtlSymbol sym; // [esp+28h] [ebp-4h] BYREF
  bool bEndOfStream_3; // [esp+37h] [ebp+Bh]

  v2 = this;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    CUtlSymbolTable::CUtlSymbolTable(this: &table, growSize: 0, initSize: 16, caseInsensitive: false);
    atexit(func: CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__);
  }
  m_Tail = v2->m_UndoList.m_Tail;
  ops = 0;
  if ( m_Tail != -1 )
  {
    while ( 1 )
    {
      ++ops;
      v5 = m_Tail;
      m_Element = v2->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Element;
      bEndOfStream_3 = m_Element->IsEndOfStream(this: m_Element);
      LODWORD(info_8) = m_Element->UndoDesc(this: m_Element);
      HIDWORD(info_8) = m_Element->RedoDesc(this: m_Element);
      v7 = m_Element->GetDesc(this: m_Element);
      CUtlSymbolTable::AddString(this: &table, result: &sym, pString: v7);
      HIDWORD(info) = CUtlSymbolTable::String(this: &table, id: sym);
      LOBYTE(info) = bEndOfStream_3;
      if ( bEndOfStream_3 )
        info_16 = ops;
      else
        info_16 = 1;
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: list,
          num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v10 = (UndoInfo_t *)list->m_pMemory;
      v11 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 20 * v11);
      v12 = (UndoInfo_t *)&list->m_pMemory[m_pMemory];
      if ( v12 != nullptr )
      {
        *(_QWORD *)&v12->terminator = info;
        *(_QWORD *)&v12->undo = info_8;
        v12->numoperations = info_16;
      }
      if ( bEndOfStream_3 )
        ops = 0;
      m_Tail = this->m_UndoList.m_Memory.m_pMemory[v5].m_Previous;
      if ( m_Tail == -1 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100713A0
// Name: public: void CUndoManager::AbortUndoableOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AbortUndoableOperation(CUndoManager *this)
{
  const char *m_pAsString; // eax
  bool v3; // bl

  if ( (*((_BYTE *)this + 116) & 8) != 0 )
  {
    m_pAsString = this->m_UndoDesc.u.m_pAsString;
    v3 = this->m_nItemsAddedSinceStartOfStream > 0;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUndoManager::Trace(this, fmt: "[%d] Aborting undo '%s'\n", this->m_nNesting, m_pAsString);
    CUndoManager::PushRedo(this);
    if ( this->m_nNesting == 0 && v3 )
    {
      CUndoManager::Undo(this);
      CUndoManager::WipeRedo(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071400
// Name: public: void CUndoManager::AddUndoElement(class IUndoElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::AddUndoElement(CUndoManager *this, IUndoElement *pElement)
{
  IUndoElement *v2; // edi
  const char *v4; // eax

  v2 = pElement;
  if ( pElement != nullptr )
  {
    ++this->m_nItemsAddedSinceStartOfStream;
    CUndoManager::WipeRedo(this);
    v4 = v2->GetDesc(this: v2);
    CUndoManager::Trace(this, fmt: "AddUndoElement '%s'\n", v4);
    CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
      this: &this->m_UndoList,
      src: &pElement);
    if ( (*((_BYTE *)this + 116) & 1) != 0 )
    {
      v2->SetEndOfStream(this: v2, a2: true);
      *((_BYTE *)this + 116) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071460
// Name: public: void CUndoManager::Redo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUndoManager::Redo(CUndoManager *this)
{
  bool v2; // bl
  int m_Size; // eax
  IUndoElement *v4; // ebx
  const char *v5; // eax
  int v6; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // ecx
  int v11; // edx
  int m_Tail; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v13; // eax
  UtlLinkedListElem_t<IUndoElement *,int> *v14; // eax
  IUndoElement *v15; // ecx
  char v16; // bl
  bool saveEnabled; // [esp+12h] [ebp-2h]
  bool bEndOfStream; // [esp+13h] [ebp-1h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CUndoManager::Redo", a3: 1, a4: 256);
  CUndoManager::Trace(this, fmt: "Redo\n======\n");
  v2 = (*((_BYTE *)this + 116) & 8) != 0;
  saveEnabled = v2;
  *((_BYTE *)this + 116) &= ~8u;
  bEndOfStream = false;
  do
  {
    if ( this->m_RedoStack.m_Size <= 0 )
      break;
    m_Size = this->m_RedoStack.m_Size;
    v4 = this->m_RedoStack.m_Memory.m_pMemory[m_Size - 1];
    this->m_RedoStack.m_Size = m_Size - 1;
    v5 = v4->GetDesc(this: v4);
    CUndoManager::Trace(this, fmt: "  %s\n", v5);
    v4->Redo(this: v4);
    v6 = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
           this: &this->m_UndoList,
           multilist: false);
    if ( v6 != -1 )
    {
      if ( v6 >= 0 && v6 < this->m_UndoList.m_Memory.m_nAllocationCount && v6 <= this->m_UndoList.m_LastAlloc.index )
      {
        v7 = &this->m_UndoList.m_Memory.m_pMemory[v6];
        if ( v7->m_Previous != v6 )
        {
          m_Previous = v7->m_Previous;
          if ( m_Previous == -1 )
            this->m_UndoList.m_Head = v7->m_Next;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Previous].m_Next = v7->m_Next;
          m_Next = v7->m_Next;
          if ( m_Next == -1 )
            this->m_UndoList.m_Tail = v7->m_Previous;
          else
            this->m_UndoList.m_Memory.m_pMemory[m_Next].m_Previous = v7->m_Previous;
          v7->m_Next = v6;
          v7->m_Previous = v6;
          --this->m_UndoList.m_ElementCount;
        }
      }
      m_pMemory = this->m_UndoList.m_Memory.m_pMemory;
      v11 = v6;
      m_pMemory[v11].m_Next = -1;
      m_Tail = this->m_UndoList.m_Tail;
      m_pMemory[v11].m_Previous = m_Tail;
      this->m_UndoList.m_Tail = v6;
      if ( m_Tail == -1 )
        this->m_UndoList.m_Head = v6;
      else
        this->m_UndoList.m_Memory.m_pMemory[m_Tail].m_Next = v6;
      v13 = this->m_UndoList.m_Memory.m_pMemory;
      ++this->m_UndoList.m_ElementCount;
      v14 = &v13[v11];
      if ( v14 != nullptr )
        v14->m_Element = v4;
    }
    if ( this->m_RedoStack.m_Size > 0 )
    {
      v15 = this->m_RedoStack.m_Memory.m_pMemory[this->m_RedoStack.m_Size - 1];
      bEndOfStream = v15->IsEndOfStream(this: v15);
    }
    v2 = saveEnabled;
  }
  while ( !bEndOfStream );
  CUndoManager::Trace(this, fmt: "======\n\n");
  v16 = *((_BYTE *)this + 116) ^ (8 * v2);
  this->m_PreviousChainingID = 0;
  *((_BYTE *)this + 116) ^= v16 & 8;
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C5150
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrorsTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_DescErrorsTable);
}

//------------------------------------------------------------------------------
// Address: 0x100C5160
// Name: _CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoInfo_::_2_::_dynamic_atexit_destructor_for__table__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &table);
}

//------------------------------------------------------------------------------
// Address: 0x100C5170
// Name: _CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUndoManager::GetUndoDescInternal_::_5_::_dynamic_atexit_destructor_for__s_DescErrors__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DescErrors);
}

//------------------------------------------------------------------------------
// Address: 0x100C5120
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x100C5130
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x100C5180
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2Flat.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2Flat.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x100C51C0
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__()
{
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: &s_DMSerializerKeyValues2.m_ElementDict.m_idmap.m_Buckets);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_elementsToDelete);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues2.m_ElementDict);
}

//------------------------------------------------------------------------------
// Address: 0x100C5200
// Name: _dynamic_atexit_destructor_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMSerializerKeyValues__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_DMSerializerKeyValues.m_ElementList);
}

//------------------------------------------------------------------------------
// Address: 0x100C5210
// Name: _dynamic_atexit_destructor_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x100C5220
// Name: _dynamic_atexit_destructor_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_OperatorNodePool);
}

//------------------------------------------------------------------------------
// Address: 0x100C5260
// Name: _dynamic_atexit_destructor_for__s_ImportDmxV1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ImportDmxV1__()
{
  CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::~CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>(this: &s_ImportDmxV1.m_fixedElements);
}

} // namespace vtex_dll
