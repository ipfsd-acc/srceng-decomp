// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/global_event_log.cpp
// Functions: 45
// ============================================================

#include "game\server\global_event_log.h"

//------------------------------------------------------------------------------
// Address: 0x10157730
// Name: public: bool CGlobalEventLine::SetStaticText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGlobalEventLine::SetStaticText(CGlobalEventLine *this, const char *pszValue)
{
  const char *v3; // edi

  v3 = pszValue;
  if ( this->m_ValueSymbol.m_Id != 0xFFFF
    && this->m_ValueSymbol.m_Id == CUtlSymbolTable::Find(
                                     this: &EventSymbols,
                                     result: (CUtlSymbol *)&pszValue + 1,
                                     pString: pszValue)->m_Id )
  {
    return 0;
  }
  this->m_ValueSymbol.m_Id = -1;
  if ( this->m_pszValue != nullptr )
  {
    free(pMem: this->m_pszValue);
    this->m_pszValue = nullptr;
  }
  this->m_bDirty = true;
  this->m_ValueSymbol = (CUtlSymbol)CUtlSymbolTable::AddString(
                                      this: &EventSymbols,
                                      result: (CUtlSymbol *)&pszValue + 1,
                                      pString: v3)->m_Id;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101577B0
// Name: public: bool CGlobalEventLine::SetVaryingText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGlobalEventLine::SetVaryingText(CGlobalEventLine *this, const char *pszValue)
{
  char *m_pszValue; // eax
  char *v5; // eax
  const char *v6; // ecx
  char *v7; // edx
  char v8; // al

  m_pszValue = this->m_pszValue;
  if ( m_pszValue != nullptr && _V_stricmp(s1: m_pszValue, s2: pszValue) == 0 )
    return 0;
  this->m_ValueSymbol.m_Id = -1;
  if ( this->m_pszValue != nullptr )
  {
    free(pMem: this->m_pszValue);
    this->m_pszValue = nullptr;
  }
  this->m_bDirty = true;
  v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pszValue) + 1);
  this->m_pszValue = v5;
  v6 = pszValue;
  v7 = v5;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
  }
  while ( v8 != 0 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157C30
// Name: public: void CGlobalEvent::Write(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEvent::Write(CGlobalEvent *this, CUtlBuffer *pBuffer)
{
  CUtlBuffer *v2; // edi
  char *v4; // esi
  int v5; // eax
  CGlobalEvent *m_pParent; // eax
  unsigned int v7; // eax
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int v9; // esi
  CGlobalEventLine *elem; // ecx
  CUtlSymbol *v11; // eax
  char *v12; // edi
  int v13; // eax
  CUtlBuffer *v14; // edi
  CGlobalEventLine *v15; // esi
  char *m_pszValue; // eax
  char *v17; // esi
  int v18; // eax
  const char *v19; // [esp+4h] [ebp-14h]
  unsigned int i; // [esp+14h] [ebp-4h]

  v2 = pBuffer;
  CUtlBuffer::Printf(this: pBuffer, pFmt: "event %u\n", this->m_nID);
  CUtlBuffer::Printf(this: pBuffer, pFmt: "{\n");
  if ( this->m_bFullUpdate )
  {
    v4 = (char *)CUtlSymbolTable::String(this: &EventSymbols, id: this->m_Name);
    strchr(string: v4, chr: 0x20u);
    if ( v5 != 0 )
      CUtlBuffer::Printf(this: pBuffer, pFmt: "\tName\t\"%s\"\n", v4);
    else
      CUtlBuffer::Printf(this: pBuffer, pFmt: "\tName\t%s\n", v4);
    m_pParent = this->m_pParent;
    if ( m_pParent != nullptr )
      CUtlBuffer::Printf(this: pBuffer, pFmt: "\tParent_ID\t%u\n", m_pParent->m_nID);
    if ( this->m_bIsHighLevel )
      CUtlBuffer::Printf(this: pBuffer, pFmt: "\tHighLevel\t1\n");
  }
  CUtlBuffer::Printf(this: pBuffer, pFmt: "\tTime\t%g\n", this->m_flTime);
  LOWORD(v7) = 0;
  i = 0;
  if ( this->m_EventLines.m_Tree.m_NumElements != 0 )
  {
    do
    {
      m_pMemory = this->m_EventLines.m_Tree.m_Elements.m_pMemory;
      v9 = (unsigned __int16)v7;
      elem = m_pMemory[(unsigned __int16)v7].m_Data.elem;
      v11 = (CUtlSymbol *)&m_pMemory[(unsigned __int16)v7];
      if ( elem->m_bDirty )
      {
        v12 = (char *)CUtlSymbolTable::String(this: &EventSymbols, id: v11[4]);
        strchr(string: v12, chr: 0x20u);
        v19 = v12;
        if ( v13 != 0 )
        {
          v14 = pBuffer;
          CUtlBuffer::Printf(this: pBuffer, pFmt: "\t\"%s\"\t", v19);
        }
        else
        {
          CUtlBuffer::Printf(this: pBuffer, pFmt: "\t%s\t", v12);
          v14 = pBuffer;
        }
        v15 = this->m_EventLines.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
        m_pszValue = v15->m_pszValue;
        if ( m_pszValue == nullptr )
          m_pszValue = (char *)CUtlSymbolTable::String(this: &EventSymbols, id: v15->m_ValueSymbol);
        v17 = m_pszValue;
        strchr(string: m_pszValue, chr: 0x20u);
        if ( v18 != 0 )
          CUtlBuffer::Printf(this: v14, pFmt: "\"%s\"\n", v17);
        else
          CUtlBuffer::Printf(this: v14, pFmt: "%s\n", v17);
        v2 = pBuffer;
      }
      v7 = i + 1;
      i = v7;
    }
    while ( v7 < this->m_EventLines.m_Tree.m_NumElements );
  }
  CUtlBuffer::Printf(this: v2, pFmt: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x10158630
// Name: public: void CGlobalEventLog::RemoveEvent(class CGlobalEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEventLog::RemoveEvent(CGlobalEventLog *this, CGlobalEvent *pEvent)
{
  int m_Size; // ecx
  int v4; // eax
  CGlobalEvent *v5; // ebx
  CGlobalEvent **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v8; // edi
  CGlobalEvent **v9; // ecx
  int v10; // eax
  CGlobalEvent **v11; // eax

  if ( CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
         this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Events,
         src: (vgui::TreeNode **)&pEvent) == 1 )
  {
    m_Size = this->m_TempEvents.m_Size;
    v4 = 0;
    v5 = pEvent;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = this->m_TempEvents.m_Memory.m_pMemory;
    while ( *m_pMemory != pEvent )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 == -1 )
    {
LABEL_8:
      m_nAllocationCount = this->m_TempEvents.m_Memory.m_nAllocationCount;
      v8 = this->m_TempEvents.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TempEvents,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_TempEvents.m_Size;
      v9 = this->m_TempEvents.m_Memory.m_pMemory;
      v10 = this->m_TempEvents.m_Size - v8 - 1;
      this->m_TempEvents.m_pElements = v9;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[v8 + 1], src: &v9[v8], count: 4 * v10);
      v11 = &this->m_TempEvents.m_Memory.m_pMemory[v8];
      if ( v11 != nullptr )
        *v11 = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158730
// Name: public: CGlobalEvent::CGlobalEvent(char const __near *,unsigned int,bool,class CGlobalEvent __near *)
// Source: json
//------------------------------------------------------------------------------
CGlobalEvent *__thiscall CGlobalEvent::CGlobalEvent(
        CGlobalEvent *this,
        const char *pszName,
        unsigned int nID,
        bool bIsHighLevel,
        CGlobalEvent *pParent)
{
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 m_Id; // dx
  unsigned int v8; // eax
  bool v9; // cl
  CGlobalEvent *v10; // edx
  const char *v12; // [esp-4h] [ebp-8h]

  this->m_Name.m_Id = -1;
  this->m_EventLines.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const CUtlSymbol *, const CUtlSymbol *))CDefOps<CUtlSymbol const>::LessFunc;
  this->m_EventLines.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_EventLines.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_EventLines.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_EventLines.m_Tree.m_Elements.m_pMemory;
  v12 = pszName;
  *(_DWORD *)&this->m_EventLines.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_EventLines.m_Tree.m_FirstFree = -1;
  this->m_EventLines.m_Tree.m_pElements = m_pMemory;
  m_Id = CUtlSymbolTable::AddString(this: &EventSymbols, result: (CUtlSymbol *)&pszName + 1, pString: v12)->m_Id;
  v8 = nID;
  v9 = bIsHighLevel;
  this->m_Name.m_Id = m_Id;
  v10 = pParent;
  this->m_nID = v8;
  this->m_bIsHighLevel = v9;
  this->m_pParent = v10;
  this->m_bFullUpdate = true;
  this->m_flTime = gpGlobals->curtime;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101587B0
// Name: public: class CGlobalEvent __near * CGlobalEventLog::CreateEvent(char const __near *,bool,class CGlobalEvent __near *)
// Source: json
//------------------------------------------------------------------------------
CGlobalEvent *__thiscall CGlobalEventLog::CreateEvent(
        CGlobalEventLog *this,
        const char *pszName,
        bool bIsHighLevel,
        CGlobalEvent *pParent)
{
  CGlobalEvent *v5; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CGlobalEvent **m_pMemory; // ecx
  int v9; // eax
  CGlobalEvent **v10; // eax
  int v11; // edi
  int v12; // eax
  CGlobalEvent **v13; // ecx
  int v14; // eax
  CGlobalEvent **v15; // eax
  CGlobalEvent *pEvent; // [esp+14h] [ebp+10h]

  v5 = (CGlobalEvent *)operator new(nSize: 0x30u);
  if ( v5 != nullptr )
    pEvent = CGlobalEvent::CGlobalEvent(this: v5, pszName, nID: this->m_nNextID, bIsHighLevel, pParent);
  else
    pEvent = nullptr;
  m_nAllocationCount = this->m_Events.m_Memory.m_nAllocationCount;
  m_Size = this->m_Events.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Events,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Events.m_Size;
  m_pMemory = this->m_Events.m_Memory.m_pMemory;
  v9 = this->m_Events.m_Size - m_Size - 1;
  this->m_Events.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Events.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = pEvent;
  v11 = this->m_DirtyEvents.m_Size;
  v12 = this->m_DirtyEvents.m_Memory.m_nAllocationCount;
  if ( v11 + 1 > v12 )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_DirtyEvents,
      num: v11 - v12 + 1);
  ++this->m_DirtyEvents.m_Size;
  v13 = this->m_DirtyEvents.m_Memory.m_pMemory;
  v14 = this->m_DirtyEvents.m_Size - v11 - 1;
  this->m_DirtyEvents.m_pElements = v13;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v11 + 1], src: &v13[v11], count: 4 * v14);
  v15 = &this->m_DirtyEvents.m_Memory.m_pMemory[v11];
  if ( v15 != nullptr )
    *v15 = pEvent;
  ++this->m_nNextID;
  return pEvent;
}

//------------------------------------------------------------------------------
// Address: 0x101588A0
// Name: public: class CGlobalEvent __near * CGlobalEventLog::CreateTempEvent(char const __near *,class CGlobalEvent __near *)
// Source: json
//------------------------------------------------------------------------------
CGlobalEvent *__thiscall CGlobalEventLog::CreateTempEvent(
        CGlobalEventLog *this,
        const char *pszName,
        CGlobalEvent *pParent)
{
  CGlobalEvent *v4; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CGlobalEvent **m_pMemory; // ecx
  int v8; // eax
  CGlobalEvent **v9; // eax
  int v10; // edi
  int v11; // eax
  CGlobalEvent **v12; // ecx
  int v13; // eax
  CGlobalEvent **v14; // eax
  CGlobalEvent *pEvent; // [esp+10h] [ebp+Ch]

  v4 = (CGlobalEvent *)operator new(nSize: 0x30u);
  if ( v4 != nullptr )
    pEvent = CGlobalEvent::CGlobalEvent(this: v4, pszName, nID: this->m_nNextID, bIsHighLevel: false, pParent);
  else
    pEvent = nullptr;
  m_nAllocationCount = this->m_TempEvents.m_Memory.m_nAllocationCount;
  m_Size = this->m_TempEvents.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TempEvents,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_TempEvents.m_Size;
  m_pMemory = this->m_TempEvents.m_Memory.m_pMemory;
  v8 = this->m_TempEvents.m_Size - m_Size - 1;
  this->m_TempEvents.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_TempEvents.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = pEvent;
  v10 = this->m_DirtyEvents.m_Size;
  v11 = this->m_DirtyEvents.m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v11 )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_DirtyEvents,
      num: v10 - v11 + 1);
  ++this->m_DirtyEvents.m_Size;
  v12 = this->m_DirtyEvents.m_Memory.m_pMemory;
  v13 = this->m_DirtyEvents.m_Size - v10 - 1;
  this->m_DirtyEvents.m_pElements = v12;
  if ( v13 > 0 )
    _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
  v14 = &this->m_DirtyEvents.m_Memory.m_pMemory[v10];
  if ( v14 != nullptr )
    *v14 = pEvent;
  ++this->m_nNextID;
  return pEvent;
}

//------------------------------------------------------------------------------
// Address: 0x10158990
// Name: protected: virtual void CGlobalEventLog::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEventLog::PostInit(CGlobalEventLog *this)
{
  this->m_pGlobalEvents[0] = CGlobalEventLog::CreateEvent(this, pszName: "NPCs", bIsHighLevel: true, pParent: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101589B0
// Name: public: bool CGlobalEvent::AddValue(bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGlobalEvent::AddValue(CGlobalEvent *this, bool bVarying, const char *pszKey, const char *pszValue)
{
  unsigned __int16 m_Id; // bx
  unsigned __int16 v6; // ax
  _DWORD *v7; // eax
  CGlobalEventLine *elem; // esi
  char result; // al
  CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  m_Id = CUtlSymbolTable::AddString(this: &EventSymbols, result: (CUtlSymbol *)&pszKey + 1, pString: pszKey)->m_Id;
  search.key.m_Id = m_Id;
  v6 = CUtlRBTree<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EventLines.m_Tree,
         &search);
  if ( v6 == 0xFFFF )
  {
    v7 = operator new(nSize: 0xCu);
    elem = nullptr;
    if ( v7 != nullptr )
    {
      v7[1] = 0;
      *(_WORD *)v7 = -1;
      *((_BYTE *)v7 + 8) = 1;
      elem = (CGlobalEventLine *)v7;
    }
    search.key.m_Id = m_Id;
    search.elem = elem;
    CUtlRBTree<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
      this: &this->m_EventLines.m_Tree,
      insert: &search);
  }
  else
  {
    elem = this->m_EventLines.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
  }
  if ( bVarying )
    result = CGlobalEventLine::SetVaryingText(this: elem, pszValue);
  else
    result = CGlobalEventLine::SetStaticText(this: elem, pszValue);
  if ( result == 1 )
  {
    this->m_bDirty = true;
    this->m_flTime = gpGlobals->curtime;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158A70
// Name: public: void CGlobalEventLog::AddKeyValue(class CGlobalEvent __near *,bool,char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CGlobalEventLog::AddKeyValue(
        CGlobalEventLog *this,
        CGlobalEvent *pEvent,
        bool bVarying,
        char *pszKey,
        char *pszValueFormat,
        ...)
{
  int v5; // esi
  void *v6; // esp
  int m_Size; // ecx
  int v8; // eax
  CGlobalEvent **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v11; // edi
  CGlobalEvent **v12; // ecx
  int v13; // eax
  CGlobalEvent **v14; // eax
  char v15[12]; // [esp+0h] [ebp-Ch] BYREF
  va_list ap; // [esp+28h] [ebp+1Ch] BYREF

  va_start(ap, pszValueFormat);
  v5 = _vscprintf(format: pszValueFormat, ap) + 1;
  v6 = alloca(v5);
  V_vsnprintf(pDest: v15, maxLen: v5, pFormat: pszValueFormat, params: ap);
  if ( CGlobalEvent::AddValue(this: pEvent, bVarying, pszKey, pszValue: v15) == 1 )
  {
    m_Size = this->m_DirtyEvents.m_Size;
    v8 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = this->m_DirtyEvents.m_Memory.m_pMemory;
    while ( *m_pMemory != pEvent )
    {
      ++v8;
      ++m_pMemory;
      if ( v8 >= m_Size )
        goto LABEL_8;
    }
    if ( v8 == -1 )
    {
LABEL_8:
      m_nAllocationCount = this->m_DirtyEvents.m_Memory.m_nAllocationCount;
      v11 = this->m_DirtyEvents.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_DirtyEvents,
          num: v11 - m_nAllocationCount + 1);
      ++this->m_DirtyEvents.m_Size;
      v12 = this->m_DirtyEvents.m_Memory.m_pMemory;
      v13 = this->m_DirtyEvents.m_Size - v11 - 1;
      this->m_DirtyEvents.m_pElements = v12;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[v11 + 1], src: &v12[v11], count: 4 * v13);
      v14 = &this->m_DirtyEvents.m_Memory.m_pMemory[v11];
      if ( v14 != nullptr )
        *v14 = pEvent;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158B40
// Name: public: void CGlobalEventLog::SendUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGlobalEventLog::SendUpdate(CGlobalEventLog *this@<ecx>, int a2@<esi>)
{
  CUtlBuffer *v3; // eax
  CUtlBuffer *v4; // esi
  int v5; // edx
  CGlobalEvent *v6; // eax
  unsigned int v7; // ecx
  int v8; // eax
  CGlobalEvent *v9; // esi
  void *fh; // [esp+8h] [ebp-8h]
  void *fha; // [esp+8h] [ebp-8h]
  void *fhb; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( this->m_DirtyEvents.m_Size != 0 )
  {
    if ( global_event_log_enabled.m_pParent != nullptr && global_event_log_enabled.m_pParent->m_Value.m_nValue != 0 )
    {
      fh = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int))g_pFullFileSystem->Open)(
                     a1: &g_pFullFileSystem->IBaseFileSystem,
                     a2: "c:\\o.events",
                     a3: "a",
                     a4: 0,
                     a5: a2);
      v3 = (CUtlBuffer *)operator new(nSize: 0x30u);
      if ( v3 != nullptr )
        v4 = CUtlBuffer::CUtlBuffer(this: v3, growSize: 0, initSize: 0, nFlags: 1);
      else
        v4 = nullptr;
      v4->m_Get = 0;
      v4->m_Put = 0;
      v4->m_Error = 0;
      v4->m_nOffset = 0;
      v4->m_nMaxPut = -1;
      CUtlBuffer::AddNullTermination(this: v4, nPut: 0);
      for ( i = 0; i < this->m_DirtyEvents.m_Size; ++i )
      {
        CGlobalEvent::Write(this: this->m_DirtyEvents.m_Memory.m_pMemory[i], pBuffer: v4);
        g_pFullFileSystem->Write(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: v4->m_Memory.m_pMemory,
          a3: v4->m_Put,
          a4: fh);
        v4->m_Get = 0;
        v4->m_Put = 0;
        v4->m_Error = 0;
        v4->m_nOffset = 0;
        v4->m_nMaxPut = -1;
        CUtlBuffer::AddNullTermination(this: v4, nPut: 0);
      }
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: fh);
    }
    v5 = 0;
    for ( fha = nullptr; v5 < this->m_DirtyEvents.m_Size; fha = (void *)v5 )
    {
      v6 = this->m_DirtyEvents.m_Memory.m_pMemory[v5];
      v7 = 0;
      *(_WORD *)&v6->m_bFullUpdate = 0;
      if ( v6->m_EventLines.m_Tree.m_NumElements != 0 )
      {
        do
          v6->m_EventLines.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v7++].m_Data.elem->m_bDirty = false;
        while ( v7 < v6->m_EventLines.m_Tree.m_NumElements );
        v5 = (int)fha;
      }
      ++v5;
    }
    this->m_DirtyEvents.m_Size = 0;
    if ( this->m_DirtyEvents.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_DirtyEvents.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirtyEvents.m_Memory.m_pMemory);
        this->m_DirtyEvents.m_Memory.m_pMemory = nullptr;
      }
      this->m_DirtyEvents.m_Memory.m_nAllocationCount = 0;
    }
    v8 = 0;
    this->m_DirtyEvents.m_pElements = this->m_DirtyEvents.m_Memory.m_pMemory;
    for ( fhb = nullptr; v8 < this->m_TempEvents.m_Size; fhb = (void *)v8 )
    {
      v9 = this->m_TempEvents.m_Memory.m_pMemory[v8];
      if ( v9 != nullptr )
      {
        CUtlRBTree<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CGlobalEventLine *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &v9->m_EventLines.m_Tree);
        v9->m_EventLines.m_Tree.m_FirstFree = -1;
        if ( v9->m_EventLines.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v9->m_EventLines.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9->m_EventLines.m_Tree.m_Elements.m_pMemory);
            v9->m_EventLines.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v9->m_EventLines.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v9->m_EventLines.m_Tree.m_LastAlloc.index = -1;
        if ( v9->m_EventLines.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v9->m_EventLines.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9->m_EventLines.m_Tree.m_Elements.m_pMemory);
            v9->m_EventLines.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v9->m_EventLines.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        free(pMem: v9);
        v8 = (int)fhb;
      }
      ++v8;
    }
    this->m_TempEvents.m_Size = 0;
    if ( this->m_TempEvents.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_TempEvents.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TempEvents.m_Memory.m_pMemory);
        this->m_TempEvents.m_Memory.m_pMemory = nullptr;
      }
      this->m_TempEvents.m_Memory.m_nAllocationCount = 0;
    }
    this->m_TempEvents.m_pElements = this->m_TempEvents.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158D70
// Name: protected: virtual void CGlobalEventLog::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CGlobalEventLog::FrameUpdatePostEntityThink(CGlobalEventLog *this@<ecx>, int a2@<esi>)
{
  CGlobalEventLog::SendUpdate(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10405020
// Name: _dynamic_initializer_for__global_event_log_enabled__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__global_event_log_enabled__()
{
  ConVar::ConVar(
    this: &global_event_log_enabled,
    pName: "global_event_log_enabled",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Enables the global event log system");
  return atexit(func: dynamic_atexit_destructor_for__global_event_log_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x10405970
// Name: _dynamic_initializer_for__global_set__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__global_set__()
{
  ConCommand::ConCommand(
    this: &global_set,
    pName: "global_set",
    callback: (void (__cdecl *)())CC_Global_Set,
    pHelpString: "global_set <globalname> <state>: Sets the state of the given env_global (0 = OFF, 1 = ON, 2 = DEAD).",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__global_set__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BEC0
// Name: _dynamic_atexit_destructor_for__global_event_log_enabled__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__global_event_log_enabled__()
{
  ConVar::~ConVar(this: &global_event_log_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x1041C210
// Name: _dynamic_atexit_destructor_for__global_set__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__global_set__()
{
  ConCommand::~ConCommand(this: &global_set);
}

//------------------------------------------------------------------------------
// Address: 0x10405050
// Name: _dynamic_initializer_for__gGlobalState__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gGlobalState__()
{
  CAutoGameSystem::CAutoGameSystem(this: &gGlobalState, name: "CGlobalState");
  gGlobalState.__vftable = (CGlobalState_vtbl *)&CGlobalState::`vftable';
  CUtlSymbolTable::CUtlSymbolTable(this: &gGlobalState.m_nameList, growSize: 0, initSize: 16, caseInsensitive: false);
  gGlobalState.m_disableStateUpdates = false;
  gGlobalState.m_list.m_Memory.m_pMemory = nullptr;
  gGlobalState.m_list.m_Memory.m_nAllocationCount = 0;
  gGlobalState.m_list.m_Memory.m_nGrowSize = 0;
  gGlobalState.m_list.m_Size = 0;
  gGlobalState.m_list.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__gGlobalState__);
}

//------------------------------------------------------------------------------
// Address: 0x104050B0
// Name: _dynamic_initializer_for__dump_globals_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dump_globals_command__()
{
  ConCommand::ConCommand(
    this: &dump_globals_command,
    pName: "dump_globals",
    callback: (void (__cdecl *)())dump_globals,
    pHelpString: "Dump all global entities/states",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dump_globals_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BED0
// Name: _dynamic_atexit_destructor_for__GlobalEventLog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__GlobalEventLog__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&GlobalEventLog.m_DirtyEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&GlobalEventLog.m_TempEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&GlobalEventLog.m_Events);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &GlobalEventLog);
}

//------------------------------------------------------------------------------
// Address: 0x1041BF00
// Name: _dynamic_atexit_destructor_for__dump_globals_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dump_globals_command__()
{
  ConCommand::~ConCommand(this: &dump_globals_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041C220
// Name: _DataMapInit_CLogicScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_252);
}

//------------------------------------------------------------------------------
// Address: 0x1041C230
// Name: _DataMapInit_CLogicCompareInteger__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicCompareInteger__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_253);
}

//------------------------------------------------------------------------------
// Address: 0x1041C240
// Name: _DataMapInit_CLogicRegisterActivator__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicRegisterActivator__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_254);
}

//------------------------------------------------------------------------------
// Address: 0x1041C250
// Name: _DataMapInit_CTimerEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTimerEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_255);
}

//------------------------------------------------------------------------------
// Address: 0x1041C260
// Name: _DataMapInit_CLogicLineToEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicLineToEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_256);
}

//------------------------------------------------------------------------------
// Address: 0x1041C270
// Name: _DataMapInit_CMathRemap__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMathRemap__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_257);
}

//------------------------------------------------------------------------------
// Address: 0x1041C280
// Name: _DataMapInit_CMathColorBlend__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMathColorBlend__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_258);
}

//------------------------------------------------------------------------------
// Address: 0x1041C290
// Name: _DataMapInit_CEnvGlobal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvGlobal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_259);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2A0
// Name: _DataMapInit_CMultiSource__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMultiSource__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_260);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2B0
// Name: _DataMapInit_CMathCounter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMathCounter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_261);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2C0
// Name: _DataMapInit_CLogicCase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicCase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_262);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2D0
// Name: _DataMapInit_CLogicCompare__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicCompare__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_263);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2E0
// Name: _DataMapInit_CLogicBranch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicBranch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_264);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2F0
// Name: _DataMapInit_CLogicAutosave__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicAutosave__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_265);
}

//------------------------------------------------------------------------------
// Address: 0x1041C300
// Name: _DataMapInit_CLogicActiveAutosave__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicActiveAutosave__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_266);
}

//------------------------------------------------------------------------------
// Address: 0x1041C310
// Name: _DataMapInit_CLogicCollisionPair__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicCollisionPair__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_267);
}

//------------------------------------------------------------------------------
// Address: 0x1041C320
// Name: _DataMapInit_CLogicBranchList__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicBranchList__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_268);
}

//------------------------------------------------------------------------------
// Address: 0x1041C330
// Name: _DataMapInit_CLogicRelay__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicRelay__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_269);
}

//------------------------------------------------------------------------------
// Address: 0x1041C340
// Name: _DataMapInit_CRuleEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRuleEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_270);
}

//------------------------------------------------------------------------------
// Address: 0x1041C350
// Name: _DataMapInit_CRulePointEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRulePointEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_271);
}

//------------------------------------------------------------------------------
// Address: 0x1041C360
// Name: _DataMapInit_CGameScore__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGameScore__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_272);
}

//------------------------------------------------------------------------------
// Address: 0x1041C370
// Name: _DataMapInit_CGameEnd__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGameEnd__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_273);
}

//------------------------------------------------------------------------------
// Address: 0x1041C380
// Name: _DataMapInit_CGameText__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGameText__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_274);
}

//------------------------------------------------------------------------------
// Address: 0x1041C390
// Name: _DataMapInit_CGamePlayerZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGamePlayerZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_275);
}

//------------------------------------------------------------------------------
// Address: 0x1041C3A0
// Name: _DataMapInit_CGamePlayerEquip__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGamePlayerEquip__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_276);
}
