// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/clipboardmanager.cpp
// Functions: 7
// ============================================================

#include "datamodel\clipboardmanager.h"

//------------------------------------------------------------------------------
// Address: 0x0043C910
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043C990
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C9F0
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043CA10
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0043CA60
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &defaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CB60
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &defaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CC90
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CUtlSymbolTableLargeBaseTreeEntry_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0044B110
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044B120
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B180
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0044B1D0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: var);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B2D0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: var);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B400
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (const studiohdr_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00445490
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004454A0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445500
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00445550
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445650
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445780
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CParticleSystemDefinition *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101E56D0
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E56E0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5760
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101E57B0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  unsigned int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &var);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = std::char_traits<char>::length(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E58B0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  unsigned int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &var);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = std::char_traits<char>::length(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E59E0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CParticleSystemDefinition *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00475B70
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00475BF0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475C50
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00475CA0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: WindowName);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475DA0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: WindowName);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475ED0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CUtlSymbolTableLargeBaseTreeEntry_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004F9FC0
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F9FD0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA030
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004FA050
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004FA0A0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: pDefaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA1A0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: pDefaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FA2D0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (S3RGBA)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &data->m_Memory, num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004B9E80
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B9E90
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9EF0
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004B9F40
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(
               this: *this->m_Data.m_Memory.m_pMemory,
               keyName: "text",
               defaultValue: pDeltaStateName);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA040
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(
               this: *this->m_Data.m_Memory.m_pMemory,
               keyName: "text",
               defaultValue: pDeltaStateName);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA170
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(this: data, elem: 0, num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CUtlSymbolTableLargeBaseTreeEntry_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0043E730
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043E740
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E7A0
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043E7C0
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0043E810
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043E910
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EA40
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CUtlSymbolTableLargeBaseTreeEntry_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00440760
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004407E0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440840
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00440890
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: str);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440990
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: str);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440AC0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (const studiohdr_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x004374D0
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004374E0
// Name: public: void CClipboardManager::EmptyClipboard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437540
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00437560
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  CClipboardManager::EmptyClipboard(this);
  CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00437570
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  KeyValues *String; // eax
  unsigned int v4; // ebp
  HWND DesktopWindow; // eax
  HGLOBAL v6; // eax
  void *v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edi

  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
    (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this,
    elem: this->m_Data.m_Size,
    src: (CUtlSymbolTable::StringPool_t **)&add);
  if ( this->m_Data.m_Size >= 0 )
  {
    String = (KeyValues *)KeyValues::GetString(
                            this: *this->m_Data.m_Memory.m_pMemory,
                            keyName: "text",
                            defaultValue: defaultValue);
    add = String;
    if ( String != nullptr && LOBYTE(String->m_iKeyName) != 0 )
    {
      v4 = strlen((const char *)String);
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v6 = GlobalAlloc(uFlags: 2u, dwBytes: v4 + 1);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v8 = (unsigned __int8 *)GlobalLock(hMem: v6);
          v9 = v8;
          if ( v8 != nullptr )
          {
            memset(dst: v8, value: 0, count: v4 + 1);
            memcpy(dst: v9, src: (unsigned __int8 *)add, count: v4);
            GlobalUnlock(hMem: v7);
            SetClipboardData(uFormat: 1u, hMem: v7);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437670
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  bool v4; // sf
  const char *String; // eax
  unsigned int v6; // ebp
  HWND DesktopWindow; // eax
  HGLOBAL v8; // eax
  void *v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // edi
  unsigned __int8 *text; // [esp+8h] [ebp+4h]

  CClipboardManager::EmptyClipboard(this);
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int>>::operator=(
    (CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)this,
    other: (const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)data);
  v4 = this->m_Data.m_Size < 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v4 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    text = (unsigned __int8 *)String;
    if ( String != nullptr && *String != 0 )
    {
      v6 = strlen(String);
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        v8 = GlobalAlloc(uFlags: 2u, dwBytes: v6 + 1);
        v9 = v8;
        if ( v8 != nullptr )
        {
          v10 = (unsigned __int8 *)GlobalLock(hMem: v8);
          v11 = v10;
          if ( v10 != nullptr )
          {
            memset(dst: v10, value: 0, count: v6 + 1);
            memcpy(dst: v11, src: text, count: v6);
            GlobalUnlock(hMem: v9);
            SetClipboardData(uFormat: 1u, hMem: v9);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437730
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *data)
{
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v4; // edi
  signed int v5; // esi
  unsigned __int8 *v6; // eax
  KeyValues *v7; // eax
  CUtlSymbolTable::StringPool_t *src; // [esp+4h] [ebp-2008h] BYREF
  unsigned __int8 dst[8192]; // [esp+8h] [ebp-2004h] BYREF

  data->m_Size = 0;
  CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int>>::operator=(
    this: data,
    other: (const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *)this);
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v4 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v5 = GlobalSize(hMem: ClipboardData);
        if ( v5 > 0 )
        {
          v6 = (unsigned __int8 *)GlobalLock(hMem: v4);
          if ( v6 != nullptr )
          {
            if ( v5 >= 0x1FFF )
              v5 = 0x1FFF;
            memcpy(dst, src: v6, count: v5);
            dst[0x1FFF] = 0;
            GlobalUnlock(hMem: v4);
            v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x20u);
            if ( v7 != nullptr )
              src = (CUtlSymbolTable::StringPool_t *)KeyValues::KeyValues(
                                                       this: v7,
                                                       setName: "ClipBoard",
                                                       firstKey: "text",
                                                       firstValue: (const char *)dst);
            else
              src = nullptr;
            CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
              this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)data,
              elem: data->m_Size,
              &src);
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0043EBE0
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043EBF0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EC50
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043EC70
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0043ECC0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &defaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EDC0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &defaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EEF0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CUtlSymbolTableLargeBaseTreeEntry_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00443E80
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443E90
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443EF0
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00443F40
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &pParentName);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444040
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &pParentName);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444170
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (const studiohdr_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00448A00
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00448A10
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448A70
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00448AC0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448BC0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448CF0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CParticleSystemDefinition *,CUtlMemory<CParticleSystemDefinition *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CParticleSystemDefinition *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00444A90
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00444AA0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444B00
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00444B50
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &pch);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444C50
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: &pch);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444D80
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (const studiohdr_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004B3260
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B32E0
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3340
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004B3390
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  char *String; // eax
  char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(
               this: *this->m_Data.m_Memory.m_pMemory,
               keyName: "text",
               defaultValue: pDeltaStateName);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3490
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  char *String; // eax
  char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(
               this: *this->m_Data.m_Memory.m_pMemory,
               keyName: "text",
               defaultValue: pDeltaStateName);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B35C0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(this: data, elem: 0, num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (CUtlSymbolTableLargeBaseTreeEntry_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0044F250
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044F260
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F2C0
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0044F310
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: Ptr);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F410
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: Ptr);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F540
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (const studiohdr_t *)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)data,
                num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00520C30
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00520C40
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebp
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520CB0
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00520CD0
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00520D20
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  const char *String; // eax
  unsigned __int8 *v4; // ebx
  KeyValues *v5; // ebp
  HWND DesktopWindow; // eax
  SIZE_T v7; // ebp
  HGLOBAL v8; // eax
  void *v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // edi

  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this,
    elem: this->m_Data.m_Size,
    src: (vgui::TreeNode **)&add);
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v4 = (unsigned __int8 *)String;
    if ( String != nullptr && *String != 0 )
    {
      v5 = (KeyValues *)_V_strlen(str: String);
      add = v5;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v7 = (SIZE_T)v5 + 1;
        v8 = GlobalAlloc(uFlags: 2u, dwBytes: v7);
        v9 = v8;
        if ( v8 != nullptr )
        {
          v10 = (unsigned __int8 *)GlobalLock(hMem: v8);
          v11 = v10;
          if ( v10 != nullptr )
          {
            _V_memset(dest: v10, fill: nullptr, count: v7);
            _V_memcpy(dest: v11, src: v4, count: (unsigned int)add);
            GlobalUnlock(hMem: v9);
            SetClipboardData(uFormat: 1u, hMem: v9);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520E20
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  bool v4; // cc
  const char *String; // eax
  unsigned __int8 *v6; // ebx
  unsigned int v7; // ebp
  HWND DesktopWindow; // eax
  SIZE_T v9; // ebp
  HGLOBAL v10; // eax
  void *v11; // esi
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // edi
  unsigned int textLen; // [esp+8h] [ebp+4h]

  CClipboardManager::EmptyClipboard(this, bClearWindowsClipboard: true);
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::operator=(this: &this->m_Data, other: data);
  v4 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v4 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v6 = (unsigned __int8 *)String;
    if ( String != nullptr && *String != 0 )
    {
      v7 = _V_strlen(str: String);
      textLen = v7;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        v9 = v7 + 1;
        v10 = GlobalAlloc(uFlags: 2u, dwBytes: v9);
        v11 = v10;
        if ( v10 != nullptr )
        {
          v12 = (unsigned __int8 *)GlobalLock(hMem: v10);
          v13 = v12;
          if ( v12 != nullptr )
          {
            _V_memset(dest: v12, fill: nullptr, count: v9);
            _V_memcpy(dest: v13, src: v6, count: textLen);
            GlobalUnlock(hMem: v11);
            SetClipboardData(uFormat: 1u, hMem: v11);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520EE0
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data)
{
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v4; // edi
  signed int v5; // esi
  unsigned __int8 *v6; // eax
  KeyValues *v7; // eax
  vgui::TreeNode *src; // [esp+4h] [ebp-2004h] BYREF
  unsigned __int8 dest[8192]; // [esp+8h] [ebp-2000h] BYREF

  data->m_Size = 0;
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::operator=(this: data, other: &this->m_Data);
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v4 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v5 = GlobalSize(hMem: ClipboardData);
        if ( v5 > 0 )
        {
          v6 = (unsigned __int8 *)GlobalLock(hMem: v4);
          if ( v6 != nullptr )
          {
            if ( v5 >= 0x1FFF )
              v5 = 0x1FFF;
            _V_memcpy(dest, src: v6, count: v5);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v4);
            v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v7 != nullptr )
              src = (vgui::TreeNode *)KeyValues::KeyValues(
                                        this: v7,
                                        setName: "ClipBoard",
                                        firstKey: "text",
                                        firstValue: (char *)dest);
            else
              src = nullptr;
            CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
              this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)data,
              elem: data->m_Size,
              &src);
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00547020
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00547030
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00547090
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005470E0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: var);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005471E0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: var);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00547310
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(this: data, elem: 0, num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (S3RGBA)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<HemiLightData_t *,int>::Grow(this: &data->m_Memory, num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10071610
// Name: public: bool CClipboardManager::HasClipboardData(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClipboardManager::HasClipboardData(CClipboardManager *this)
{
  return this->m_Data.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071620
// Name: public: void CClipboardManager::EmptyClipboard(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::EmptyClipboard(CClipboardManager *this, bool bClearWindowsClipboard)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi
  HWND DesktopWindow; // eax

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  if ( bClearWindowsClipboard )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      EmptyClipboard();
      CloseClipboard();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071680
// Name: public: CClipboardManager::CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
CClipboardManager *__thiscall CClipboardManager::CClipboardManager(CClipboardManager *this)
{
  this->m_Data.m_Memory.m_pMemory = nullptr;
  this->m_Data.m_Memory.m_nAllocationCount = 0;
  this->m_Data.m_Memory.m_nGrowSize = 0;
  this->m_Data.m_Size = 0;
  this->m_Data.m_pElements = nullptr;
  this->m_pfnCleanup = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100716A0
// Name: public: CClipboardManager::~CClipboardManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::~CClipboardManager(CClipboardManager *this)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // esi

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100716F0
// Name: public: void CClipboardManager::AddToClipboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::AddToClipboardData(CClipboardManager *this, KeyValues *add)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // edi
  const char *String; // eax
  const char *v9; // ebx
  int v10; // esi
  HWND DesktopWindow; // eax
  HGLOBAL v12; // eax
  void *v13; // esi
  void *v14; // edi
  int textLen; // [esp+10h] [ebp+8h]

  m_nAllocationCount = this->m_Data.m_Memory.m_nAllocationCount;
  m_Size = this->m_Data.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Data.m_Size;
  m_pMemory = this->m_Data.m_Memory.m_pMemory;
  v6 = this->m_Data.m_Size - m_Size - 1;
  this->m_Data.m_pElements = this->m_Data.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Data.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = add;
  if ( this->m_Data.m_Size >= 0 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v9 = String;
    if ( String != nullptr && *String != 0 )
    {
      v10 = _V_strlen(str: String);
      textLen = v10;
      DesktopWindow = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
      {
        EmptyClipboard();
        v12 = GlobalAlloc(uFlags: 2u, dwBytes: v10 + 1);
        v13 = v12;
        if ( v12 != nullptr )
        {
          v14 = GlobalLock(hMem: v12);
          if ( v14 != nullptr )
          {
            _V_memset(dest: v14, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v14, src: v9, count: textLen);
            GlobalUnlock(hMem: v13);
            SetClipboardData(uFormat: 1u, hMem: v13);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100717F0
// Name: public: void CClipboardManager::SetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &,class IClipboardCleanup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::SetClipboardData(
        CClipboardManager *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *data,
        IClipboardCleanup *pfnOptionalCleanuFunction)
{
  IClipboardCleanup *m_pfnCleanup; // ecx
  int m_Size; // ebx
  int i; // edi
  HWND DesktopWindow; // eax
  int v8; // edi
  int j; // eax
  bool v10; // cc
  const char *String; // eax
  const char *v12; // ebx
  int v13; // esi
  HWND v14; // eax
  HGLOBAL v15; // eax
  void *v16; // esi
  void *v17; // edi
  int textLen; // [esp+14h] [ebp+8h]

  m_pfnCleanup = this->m_pfnCleanup;
  if ( m_pfnCleanup != nullptr )
    m_pfnCleanup->ReleaseClipboardData(this: m_pfnCleanup, a2: &this->m_Data);
  m_Size = this->m_Data.m_Size;
  for ( i = 0; i < m_Size; ++i )
    KeyValues::deleteThis(this: this->m_Data.m_Memory.m_pMemory[i]);
  this->m_Data.m_Size = 0;
  this->m_pfnCleanup = nullptr;
  DesktopWindow = GetDesktopWindow();
  if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
  {
    EmptyClipboard();
    CloseClipboard();
  }
  v8 = data->m_Size;
  this->m_Data.m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: v8);
  for ( j = 0; j < v8; ++j )
    this->m_Data.m_Memory.m_pMemory[j] = data->m_Memory.m_pMemory[j];
  v10 = this->m_Data.m_Size <= 0;
  this->m_pfnCleanup = pfnOptionalCleanuFunction;
  if ( !v10 )
  {
    String = KeyValues::GetString(this: *this->m_Data.m_Memory.m_pMemory, keyName: "text", defaultValue: defaultValue);
    v12 = String;
    if ( String != nullptr && *String != 0 )
    {
      v13 = _V_strlen(str: String);
      textLen = v13;
      v14 = GetDesktopWindow();
      if ( OpenClipboard(hWndNewOwner: v14) )
      {
        v15 = GlobalAlloc(uFlags: 2u, dwBytes: v13 + 1);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = GlobalLock(hMem: v15);
          if ( v17 != nullptr )
          {
            _V_memset(dest: v17, fill: 0, count: textLen + 1);
            _V_memcpy(dest: v17, src: v12, count: textLen);
            GlobalUnlock(hMem: v16);
            SetClipboardData(uFormat: 1u, hMem: v16);
          }
        }
        CloseClipboard();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071920
// Name: public: void CClipboardManager::GetClipboardData(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipboardManager::GetClipboardData(
        CClipboardManager *this,
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *data)
{
  int m_Size; // edi
  int i; // eax
  HWND DesktopWindow; // eax
  HANDLE ClipboardData; // eax
  void *v7; // edi
  signed int v8; // ebx
  const void *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v15; // eax
  KeyValues **v16; // edi
  char dest[8192]; // [esp+Ch] [ebp-2000h] BYREF

  data->m_Size = 0;
  m_Size = this->m_Data.m_Size;
  data->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: data,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    data->m_Memory.m_pMemory[i] = (S3RGBA)this->m_Data.m_Memory.m_pMemory[i];
  if ( data->m_Size == 0 )
  {
    DesktopWindow = GetDesktopWindow();
    if ( OpenClipboard(hWndNewOwner: DesktopWindow) )
    {
      ClipboardData = GetClipboardData(uFormat: 1u);
      v7 = ClipboardData;
      if ( ClipboardData != nullptr )
      {
        v8 = GlobalSize(hMem: ClipboardData);
        if ( v8 > 0 )
        {
          v9 = GlobalLock(hMem: v7);
          if ( v9 != nullptr )
          {
            if ( v8 >= 0x1FFF )
              v8 = 0x1FFF;
            _V_memcpy(dest, src: v9, count: v8);
            dest[0x1FFF] = 0;
            GlobalUnlock(hMem: v7);
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "ClipBoard", firstKey: "text", firstValue: dest);
            else
              v11 = nullptr;
            v12 = data->m_Size;
            m_nAllocationCount = data->m_Memory.m_nAllocationCount;
            if ( v12 + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &data->m_Memory, num: v12 - m_nAllocationCount + 1);
            ++data->m_Size;
            m_pMemory = (KeyValues **)data->m_Memory.m_pMemory;
            v15 = data->m_Size - v12 - 1;
            data->m_pElements = data->m_Memory.m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
            v16 = (KeyValues **)&data->m_Memory.m_pMemory[v12];
            if ( v16 != nullptr )
              *v16 = v11;
          }
        }
      }
      CloseClipboard();
    }
  }
}

} // namespace vtex_dll
