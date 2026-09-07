// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/vpanel.cpp
// Functions: 74
// ============================================================

#include "vgui2\src\vpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10008B30
// Name: public: int CUtlVector<struct vgui::IScheme::fontalias_t,class CUtlMemory<struct vgui::IScheme::fontalias_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::IScheme::fontalias_t,CUtlMemory<vgui::IScheme::fontalias_t,int>>::InsertBefore(
        CUtlVector<vgui::IScheme::fontalias_t,CUtlMemory<vgui::IScheme::fontalias_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::IScheme::fontalias_t *m_pMemory; // ecx
  int v6; // eax
  vgui::IScheme::fontalias_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::IScheme::fontalias_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 6 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    *(_DWORD *)&v7->_fontName.m_Id = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10009230
// Name: public: int CUtlVector<struct CScheme::CriticalFont_t,class CUtlMemory<struct CScheme::CriticalFont_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>::InsertBefore(
        CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CScheme::CriticalFont_t *m_pMemory; // ecx
  int v6; // eax
  CScheme::CriticalFont_t *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScheme::CriticalFont_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    CUtlString::CUtlString(this: &v7->m_FontName);
    CUtlString::CUtlString(this: &v7->m_ExplicitChars);
    *(_DWORD *)&v7->m_bPrecached = 0;
    *(_DWORD *)&v7->m_bNumbers = 0;
    *(_WORD *)&v7->m_bSkipIfAsian = 1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8C0
// Name: public: void CUtlVector<struct CScheme::CriticalFont_t,class CUtlMemory<struct CScheme::CriticalFont_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>::RemoveAll(
        CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  bool *v3; // esi
  int v4; // [esp+4h] [ebp-8h]
  CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int> > *v5; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v4 = 44 * v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory->m_bPrecached + v2;
      *((_DWORD *)v3 + 10) = 0;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( *((_DWORD *)v3 + 7) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 7));
          this = v5;
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      *((_DWORD *)v3 + 6) = 0;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( *((_DWORD *)v3 + 3) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 3));
          this = v5;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      --v1;
      v2 = v4 - 44;
      v4 -= 44;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B090
// Name: public: CUtlVector<struct CScheme::CriticalFont_t,class CUtlMemory<struct CScheme::CriticalFont_t,int>>::~CUtlVector<struct CScheme::CriticalFont_t,class CUtlMemory<struct CScheme::CriticalFont_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>::~CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>(
        CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int> > *this)
{
  bool v2; // sf
  CScheme::CriticalFont_t *m_pMemory; // eax

  CUtlVector<CScheme::CriticalFont_t,CUtlMemory<CScheme::CriticalFont_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FA20
// Name: public: bool CUtlVector<class CChromeHTMLWindow __near *,class CUtlMemory<class CChromeHTMLWindow __near *,int>>::FindAndRemove(class CChromeHTMLWindow __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(
        CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int> > *this,
        vgui::VPanel **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::VPanel **m_pMemory; // ebx
  vgui::VPanel **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015F60
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::VPanel,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::VPanel,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::VPanel,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<vgui::VPanel,20>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100160F0
// Name: public: int CUtlVector<struct MessageItem_t,class CUtlMemory<struct MessageItem_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MessageItem_t,CUtlMemory<MessageItem_t,int>>::InsertBefore(
        CUtlVector<MessageItem_t,CUtlMemory<MessageItem_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MessageItem_t *m_pMemory; // ecx
  int v6; // eax
  MessageItem_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CSchemeManager::CachedBitmapHandle_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->_params = nullptr;
    v7->_arrivalTime = -1.0;
    v7->_messageID = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100174E0
// Name: public: vgui::VPanel::CBitFieldInfo__visible::CBitFieldInfo__visible(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel::CBitFieldInfo__visible *__thiscall vgui::VPanel::CBitFieldInfo__visible::CBitFieldInfo__visible(
        vgui::VPanel::CBitFieldInfo__visible *this)
{
  int v2; // edi
  int v4; // esi
  vgui::VPanel::CBitFieldInfo__visible *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9[108]; // [esp+0h] [ebp-70h] BYREF
  vgui::VPanel::CBitFieldInfo__visible *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  memset(dst: v9, value: 0, count: 0x58u);
  v9[74] |= 1u;
  v2 = 0;
  while ( v9[v2] == 0 )
  {
    if ( (unsigned int)++v2 >= 0x58 )
      return this;
  }
  v4 = 0;
  while ( ((1 << v4) & v9[v2]) == 0 )
  {
    if ( (unsigned int)++v4 >= 8 )
      return v10;
  }
  v5 = v10;
  v10->m_nByteOffset = v2 + v4 / 8;
  v5->m_nBitOffset = v4 & 7;
  v6 = v4 + 1;
  v7 = __ROL4__(1, v4 + 1);
  if ( (unsigned int)(v4 + 1) < 8 )
  {
    v8 = v9[v2];
    do
    {
      if ( (v8 & v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
  }
  v5->m_nBitCount = v6 - v4;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100175A0
// Name: public: vgui::VPanel::CBitFieldInfo__enabled::CBitFieldInfo__enabled(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel::CBitFieldInfo__enabled *__thiscall vgui::VPanel::CBitFieldInfo__enabled::CBitFieldInfo__enabled(
        vgui::VPanel::CBitFieldInfo__enabled *this)
{
  int v2; // edi
  int v4; // esi
  vgui::VPanel::CBitFieldInfo__enabled *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9[108]; // [esp+0h] [ebp-70h] BYREF
  vgui::VPanel::CBitFieldInfo__enabled *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  memset(dst: v9, value: 0, count: 0x58u);
  v9[74] |= 2u;
  v2 = 0;
  while ( v9[v2] == 0 )
  {
    if ( (unsigned int)++v2 >= 0x58 )
      return this;
  }
  v4 = 0;
  while ( ((1 << v4) & v9[v2]) == 0 )
  {
    if ( (unsigned int)++v4 >= 8 )
      return v10;
  }
  v5 = v10;
  v10->m_nByteOffset = v2 + v4 / 8;
  v5->m_nBitOffset = v4 & 7;
  v6 = v4 + 1;
  v7 = __ROL4__(1, v4 + 1);
  if ( (unsigned int)(v4 + 1) < 8 )
  {
    v8 = v9[v2];
    do
    {
      if ( (v8 & v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
  }
  v5->m_nBitCount = v6 - v4;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10017660
// Name: public: vgui::VPanel::CBitFieldInfo__popup::CBitFieldInfo__popup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel::CBitFieldInfo__popup *__thiscall vgui::VPanel::CBitFieldInfo__popup::CBitFieldInfo__popup(
        vgui::VPanel::CBitFieldInfo__popup *this)
{
  int v2; // edi
  int v4; // esi
  vgui::VPanel::CBitFieldInfo__popup *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9[108]; // [esp+0h] [ebp-70h] BYREF
  vgui::VPanel::CBitFieldInfo__popup *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  memset(dst: v9, value: 0, count: 0x58u);
  v9[74] |= 4u;
  v2 = 0;
  while ( v9[v2] == 0 )
  {
    if ( (unsigned int)++v2 >= 0x58 )
      return this;
  }
  v4 = 0;
  while ( ((1 << v4) & v9[v2]) == 0 )
  {
    if ( (unsigned int)++v4 >= 8 )
      return v10;
  }
  v5 = v10;
  v10->m_nByteOffset = v2 + v4 / 8;
  v5->m_nBitOffset = v4 & 7;
  v6 = v4 + 1;
  v7 = __ROL4__(1, v4 + 1);
  if ( (unsigned int)(v4 + 1) < 8 )
  {
    v8 = v9[v2];
    do
    {
      if ( (v8 & v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
  }
  v5->m_nBitCount = v6 - v4;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10017720
// Name: public: vgui::VPanel::CBitFieldInfo__mouseInput::CBitFieldInfo__mouseInput(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel::CBitFieldInfo__mouseInput *__thiscall vgui::VPanel::CBitFieldInfo__mouseInput::CBitFieldInfo__mouseInput(
        vgui::VPanel::CBitFieldInfo__mouseInput *this)
{
  int v2; // edi
  int v4; // esi
  vgui::VPanel::CBitFieldInfo__mouseInput *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9[108]; // [esp+0h] [ebp-70h] BYREF
  vgui::VPanel::CBitFieldInfo__mouseInput *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  memset(dst: v9, value: 0, count: 0x58u);
  v9[74] |= 8u;
  v2 = 0;
  while ( v9[v2] == 0 )
  {
    if ( (unsigned int)++v2 >= 0x58 )
      return this;
  }
  v4 = 0;
  while ( ((1 << v4) & v9[v2]) == 0 )
  {
    if ( (unsigned int)++v4 >= 8 )
      return v10;
  }
  v5 = v10;
  v10->m_nByteOffset = v2 + v4 / 8;
  v5->m_nBitOffset = v4 & 7;
  v6 = v4 + 1;
  v7 = __ROL4__(1, v4 + 1);
  if ( (unsigned int)(v4 + 1) < 8 )
  {
    v8 = v9[v2];
    do
    {
      if ( (v8 & v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
  }
  v5->m_nBitCount = v6 - v4;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100177E0
// Name: public: vgui::VPanel::CBitFieldInfo__kbInput::CBitFieldInfo__kbInput(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel::CBitFieldInfo__kbInput *__thiscall vgui::VPanel::CBitFieldInfo__kbInput::CBitFieldInfo__kbInput(
        vgui::VPanel::CBitFieldInfo__kbInput *this)
{
  int v2; // edi
  int v4; // esi
  vgui::VPanel::CBitFieldInfo__kbInput *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9[108]; // [esp+0h] [ebp-70h] BYREF
  vgui::VPanel::CBitFieldInfo__kbInput *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  memset(dst: v9, value: 0, count: 0x58u);
  v9[74] |= 0x10u;
  v2 = 0;
  while ( v9[v2] == 0 )
  {
    if ( (unsigned int)++v2 >= 0x58 )
      return this;
  }
  v4 = 0;
  while ( ((1 << v4) & v9[v2]) == 0 )
  {
    if ( (unsigned int)++v4 >= 8 )
      return v10;
  }
  v5 = v10;
  v10->m_nByteOffset = v2 + v4 / 8;
  v5->m_nBitOffset = v4 & 7;
  v6 = v4 + 1;
  v7 = __ROL4__(1, v4 + 1);
  if ( (unsigned int)(v4 + 1) < 8 )
  {
    v8 = v9[v2];
    do
    {
      if ( (v8 & v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
  }
  v5->m_nBitCount = v6 - v4;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100178A0
// Name: public: vgui::VPanel::CBitFieldInfo__isTopmostPopup::CBitFieldInfo__isTopmostPopup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel::CBitFieldInfo__isTopmostPopup *__thiscall vgui::VPanel::CBitFieldInfo__isTopmostPopup::CBitFieldInfo__isTopmostPopup(
        vgui::VPanel::CBitFieldInfo__isTopmostPopup *this)
{
  int v2; // edi
  int v4; // esi
  vgui::VPanel::CBitFieldInfo__isTopmostPopup *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9[108]; // [esp+0h] [ebp-70h] BYREF
  vgui::VPanel::CBitFieldInfo__isTopmostPopup *v10; // [esp+6Ch] [ebp-4h]

  v10 = this;
  memset(dst: v9, value: 0, count: 0x58u);
  v9[74] |= 0x20u;
  v2 = 0;
  while ( v9[v2] == 0 )
  {
    if ( (unsigned int)++v2 >= 0x58 )
      return this;
  }
  v4 = 0;
  while ( ((1 << v4) & v9[v2]) == 0 )
  {
    if ( (unsigned int)++v4 >= 8 )
      return v10;
  }
  v5 = v10;
  v10->m_nByteOffset = v2 + v4 / 8;
  v5->m_nBitOffset = v4 & 7;
  v6 = v4 + 1;
  v7 = __ROL4__(1, v4 + 1);
  if ( (unsigned int)(v4 + 1) < 8 )
  {
    v8 = v9[v2];
    do
    {
      if ( (v8 & v7) == 0 )
        break;
      ++v6;
      v7 = __ROL4__(v7, 1);
    }
    while ( v6 < 8 );
  }
  v5->m_nBitCount = v6 - v4;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10017960
// Name: struct DmxElementUnpackStructure_t __near * vgui::DmxElementUnpackInitvgui<class vgui::VPanel>(class vgui::VPanel __near *)
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl vgui::DmxElementUnpackInitvgui<vgui::VPanel>()
{
  vgui::VPanel::CBitFieldInfo__visible v1; // [esp+4h] [ebp-Ch] BYREF

  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    dword_1004E258 = 2;
    vgui::VPanel::CBitFieldInfo__visible::CBitFieldInfo__visible(this: &v1);
    dword_1004E25C = v1.m_nByteOffset;
    vgui::VPanel::CBitFieldInfo__visible::CBitFieldInfo__visible(this: &v1);
    dword_1004E260 = v1.m_nBitCount;
    vgui::VPanel::CBitFieldInfo__visible::CBitFieldInfo__visible(this: &v1);
    dword_1004E264 = v1.m_nBitOffset;
    dword_1004E268 = 1;
    dword_1004E26C = 0;
    dword_1004E270 = 0;
    dword_1004E274 = 0;
    dword_1004E278 = 0;
    dword_1004E27C = (int)"enabled";
    dword_1004E280 = (int)"1";
    dword_1004E284 = 2;
    vgui::VPanel::CBitFieldInfo__enabled::CBitFieldInfo__enabled(this: (vgui::VPanel::CBitFieldInfo__enabled *)&v1);
    dword_1004E288 = v1.m_nByteOffset;
    vgui::VPanel::CBitFieldInfo__enabled::CBitFieldInfo__enabled(this: (vgui::VPanel::CBitFieldInfo__enabled *)&v1);
    dword_1004E28C = v1.m_nBitCount;
    vgui::VPanel::CBitFieldInfo__enabled::CBitFieldInfo__enabled(this: (vgui::VPanel::CBitFieldInfo__enabled *)&v1);
    dword_1004E290 = v1.m_nBitOffset;
    dword_1004E294 = 1;
    dword_1004E298 = 0;
    dword_1004E29C = 0;
    dword_1004E2A0 = 0;
    dword_1004E2A4 = 0;
    dword_1004E2A8 = (int)"popup";
    dword_1004E2AC = (int)"0";
    dword_1004E2B0 = 2;
    vgui::VPanel::CBitFieldInfo__popup::CBitFieldInfo__popup(this: (vgui::VPanel::CBitFieldInfo__popup *)&v1);
    dword_1004E2B4 = v1.m_nByteOffset;
    vgui::VPanel::CBitFieldInfo__popup::CBitFieldInfo__popup(this: (vgui::VPanel::CBitFieldInfo__popup *)&v1);
    dword_1004E2B8 = v1.m_nBitCount;
    vgui::VPanel::CBitFieldInfo__popup::CBitFieldInfo__popup(this: (vgui::VPanel::CBitFieldInfo__popup *)&v1);
    dword_1004E2BC = v1.m_nBitOffset;
    dword_1004E2C0 = 1;
    dword_1004E2C4 = 0;
    dword_1004E2C8 = 0;
    dword_1004E2CC = 0;
    dword_1004E2D0 = 0;
    dword_1004E2D4 = (int)"is topmost popup";
    dword_1004E2D8 = (int)"0";
    dword_1004E2DC = 2;
    vgui::VPanel::CBitFieldInfo__isTopmostPopup::CBitFieldInfo__isTopmostPopup(this: (vgui::VPanel::CBitFieldInfo__isTopmostPopup *)&v1);
    dword_1004E2E0 = v1.m_nByteOffset;
    vgui::VPanel::CBitFieldInfo__isTopmostPopup::CBitFieldInfo__isTopmostPopup(this: (vgui::VPanel::CBitFieldInfo__isTopmostPopup *)&v1);
    dword_1004E2E4 = v1.m_nBitCount;
    vgui::VPanel::CBitFieldInfo__isTopmostPopup::CBitFieldInfo__isTopmostPopup(this: (vgui::VPanel::CBitFieldInfo__isTopmostPopup *)&v1);
    dword_1004E2E8 = v1.m_nBitOffset;
    dword_1004E2EC = 1;
    dword_1004E2F0 = 0;
    dword_1004E2F4 = 0;
    dword_1004E2F8 = 0;
    dword_1004E2FC = 0;
    dword_1004E300 = (int)"mouse input";
    dword_1004E304 = (int)"1";
    dword_1004E308 = 2;
    vgui::VPanel::CBitFieldInfo__mouseInput::CBitFieldInfo__mouseInput(this: (vgui::VPanel::CBitFieldInfo__mouseInput *)&v1);
    dword_1004E30C = v1.m_nByteOffset;
    vgui::VPanel::CBitFieldInfo__mouseInput::CBitFieldInfo__mouseInput(this: (vgui::VPanel::CBitFieldInfo__mouseInput *)&v1);
    dword_1004E310 = v1.m_nBitCount;
    vgui::VPanel::CBitFieldInfo__mouseInput::CBitFieldInfo__mouseInput(this: (vgui::VPanel::CBitFieldInfo__mouseInput *)&v1);
    dword_1004E314 = v1.m_nBitOffset;
    dword_1004E318 = 1;
    dword_1004E31C = 0;
    dword_1004E320 = 0;
    dword_1004E324 = 0;
    dword_1004E328 = 0;
    dword_1004E32C = (int)"keyboard input";
    dword_1004E330 = (int)"1";
    dword_1004E334 = 2;
    vgui::VPanel::CBitFieldInfo__kbInput::CBitFieldInfo__kbInput(this: (vgui::VPanel::CBitFieldInfo__kbInput *)&v1);
    dword_1004E338 = v1.m_nByteOffset;
    vgui::VPanel::CBitFieldInfo__kbInput::CBitFieldInfo__kbInput(this: (vgui::VPanel::CBitFieldInfo__kbInput *)&v1);
    dword_1004E33C = v1.m_nBitCount;
    vgui::VPanel::CBitFieldInfo__kbInput::CBitFieldInfo__kbInput(this: (vgui::VPanel::CBitFieldInfo__kbInput *)&v1);
    dword_1004E360 = 2;
    dword_1004E368 = 2;
    dword_1004E348 = 0;
    dword_1004E34C = 0;
    dword_1004E350 = 0;
    dword_1004E354 = 0;
    dword_1004E370 = 0;
    dword_1004E374 = 0;
    dword_1004E378 = 0;
    dword_1004E37C = 0;
    dword_1004E380 = 0;
    dword_1004E384 = 0;
    dword_1004E388 = 0;
    dword_1004E38C = 0;
    dword_1004E390 = 0;
    dword_1004E394 = 0;
    dword_1004E39C = 0;
    dword_1004E3A0 = 0;
    dword_1004E3A4 = 0;
    dword_1004E3A8 = 0;
    dword_1004E3AC = 0;
    dword_1004E340 = v1.m_nBitOffset;
    dword_1004E344 = 1;
    dword_1004E358 = (int)"zpos";
    dword_1004E35C = (int)"0";
    dword_1004E364 = 72;
    dword_1004E36C = -1;
    dword_1004E398 = -1;
  }
  return unpack;
}

//------------------------------------------------------------------------------
// Address: 0x10017C90
// Name: public: virtual void vgui::VPanel::Init(class vgui::IClientPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::Init(vgui::VPanel *this, vgui::IClientPanel *attachedClientPanel)
{
  this->_clientPanel = attachedClientPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10017CA0
// Name: public: virtual void vgui::VPanel::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetPos(vgui::VPanel *this, __int16 x, __int16 y)
{
  __int16 v4; // cx
  int py; // [esp+4h] [ebp-8h] BYREF
  int px; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_nMessageContextId == -1 )
  {
    this->_pos[0] = x;
    this->_pos[1] = y;
  }
  else if ( this->IsPopup(this) )
  {
    vgui::g_pSurface->GetAbsPosForContext(this: vgui::g_pSurface, a2: this->m_nMessageContextId, a3: &px, a4: &py);
    v4 = py + y;
    this->_pos[0] = px + x;
    this->_pos[1] = v4;
  }
  else
  {
    this->_pos[1] = y;
    this->_pos[0] = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017D20
// Name: public: virtual void vgui::VPanel::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetPos(vgui::VPanel *this, int *x, int *y)
{
  *x = this->_pos[0];
  *y = this->_pos[1];
}

//------------------------------------------------------------------------------
// Address: 0x10017D40
// Name: public: virtual void vgui::VPanel::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetSize(vgui::VPanel *this, int wide, int tall)
{
  int v3; // esi
  int v4; // edi
  int (*Client)(void); // edx
  int v6; // eax

  v3 = tall;
  v4 = wide;
  if ( wide < this->_minimumSize[0] )
    v4 = this->_minimumSize[0];
  if ( tall < this->_minimumSize[1] )
    v3 = this->_minimumSize[1];
  if ( this->_size[0] != v4 || this->_size[1] != v3 )
  {
    Client = (int (*)(void))this->Client;
    this->_size[0] = v4;
    this->_size[1] = v3;
    v6 = Client();
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 36))(a1: v6, a2: v4, a3: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017D90
// Name: public: virtual void vgui::VPanel::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetSize(vgui::VPanel *this, int *wide, int *tall)
{
  *wide = this->_size[0];
  *tall = this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x10017DB0
// Name: public: virtual void vgui::VPanel::SetMinimumSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetMinimumSize(vgui::VPanel *this, int wide, int tall)
{
  int v3; // ebx
  int v4; // edx
  int v5; // edi
  int v6; // eax

  v3 = this->_size[0];
  v4 = v3;
  v5 = this->_size[1];
  if ( v3 < wide )
    v4 = wide;
  this->_minimumSize[0] = wide;
  v6 = v5;
  if ( v5 < tall )
    v6 = tall;
  this->_minimumSize[1] = tall;
  if ( v4 != v3 || v6 != v5 )
    this->SetSize(this, a2: v4, a3: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10017E00
// Name: public: virtual void vgui::VPanel::GetMinimumSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetMinimumSize(vgui::VPanel *this, int *wide, int *tall)
{
  *wide = this->_minimumSize[0];
  *tall = this->_minimumSize[1];
}

//------------------------------------------------------------------------------
// Address: 0x10017E20
// Name: public: virtual void vgui::VPanel::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetVisible(vgui::VPanel *this, BOOL state)
{
  bool (__thiscall *IsPopup)(vgui::VPanel *); // eax

  if ( (*((_BYTE *)this + 74) & 1) != state )
  {
    vgui::g_pSurface->SetPanelVisible(this: vgui::g_pSurface, a2: (unsigned int)this, a3: state);
    IsPopup = this->IsPopup;
    *((_BYTE *)this + 74) ^= (state ^ *((_BYTE *)this + 74)) & 1;
    if ( IsPopup(this) )
      vgui::g_pSurface->CalculateMouseVisible(this: vgui::g_pSurface);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017E80
// Name: public: virtual void vgui::VPanel::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetEnabled(vgui::VPanel *this, bool state)
{
  *((_BYTE *)this + 74) ^= (*((_BYTE *)this + 74) ^ (2 * state)) & 2;
}

//------------------------------------------------------------------------------
// Address: 0x10017EA0
// Name: public: virtual bool vgui::VPanel::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsVisible(vgui::VPanel *this)
{
  return *((_BYTE *)this + 74) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017EB0
// Name: public: virtual bool vgui::VPanel::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsEnabled(vgui::VPanel *this)
{
  return (*((_BYTE *)this + 74) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10017EC0
// Name: public: virtual void vgui::VPanel::GetAbsPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetAbsPos(vgui::VPanel *this, int *x, int *y)
{
  *x = this->_absPos[0];
  *y = this->_absPos[1];
  vgui::g_pSurface->OffsetAbsPos(this: vgui::g_pSurface, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x10017EF0
// Name: public: virtual void vgui::VPanel::GetInternalAbsPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetInternalAbsPos(vgui::VPanel *this, int *x, int *y)
{
  *x = this->_absPos[0];
  *y = this->_absPos[1];
}

//------------------------------------------------------------------------------
// Address: 0x10017F10
// Name: public: virtual void vgui::VPanel::GetClipRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetClipRect(vgui::VPanel *this, int *x0, int *y0, int *x1, int *y1)
{
  *x0 = this->_clipRect[0];
  *y0 = this->_clipRect[1];
  *x1 = this->_clipRect[2];
  *y1 = this->_clipRect[3];
  vgui::g_pSurface->OffsetAbsPos(this: vgui::g_pSurface, a2: x0, a3: y0);
  vgui::g_pSurface->OffsetAbsPos(this: vgui::g_pSurface, a2: x1, a3: y1);
}

//------------------------------------------------------------------------------
// Address: 0x10017F70
// Name: public: virtual void vgui::VPanel::SetInset(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetInset(vgui::VPanel *this, __int16 left, __int16 top, __int16 right, __int16 bottom)
{
  this->_inset[0] = left;
  this->_inset[1] = top;
  this->_inset[2] = right;
  this->_inset[3] = bottom;
}

//------------------------------------------------------------------------------
// Address: 0x10017FA0
// Name: public: virtual void vgui::VPanel::GetInset(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::GetInset(vgui::VPanel *this, int *left, int *top, int *right, int *bottom)
{
  *left = this->_inset[0];
  *top = this->_inset[1];
  *right = this->_inset[2];
  *bottom = this->_inset[3];
}

//------------------------------------------------------------------------------
// Address: 0x10017FD0
// Name: public: virtual class CUtlVector<class vgui::VPanel __near *,class CUtlMemory<class vgui::VPanel __near *,int>> __near & vgui::VPanel::GetChildren(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Dar<vgui::VPanel *> *__thiscall vgui::VPanel::GetChildren(vgui::VPanel *this)
{
  return &this->_childDar;
}

//------------------------------------------------------------------------------
// Address: 0x10017FE0
// Name: public: virtual class vgui::VPanel __near * vgui::VPanel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder::backgroundtype_e __thiscall vgui::VPanel::GetParent(ImageBorder *this)
{
  return this->m_eBackgroundType;
}

//------------------------------------------------------------------------------
// Address: 0x10017FF0
// Name: public: virtual int vgui::VPanel::GetZPos(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::VPanel::GetZPos(vgui::VPanel *this)
{
  return this->_zpos;
}

//------------------------------------------------------------------------------
// Address: 0x10018000
// Name: public: virtual bool vgui::VPanel::HasParent(class vgui::VPanel __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::HasParent(vgui::VPanel *this, vgui::VPanel *potentialParent)
{
  if ( this == potentialParent )
    return true;
  if ( this->_parent != nullptr )
    return this->_parent->HasParent(this: this->_parent, a2: potentialParent);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10018030
// Name: public: virtual class vgui::SurfacePlat __near * vgui::VPanel::Plat(void)
// Source: json
//------------------------------------------------------------------------------
vgui::SurfacePlat *__thiscall vgui::VPanel::Plat(vgui::VPanel *this)
{
  return this->_plat;
}

//------------------------------------------------------------------------------
// Address: 0x10018040
// Name: public: virtual void vgui::VPanel::SetPlat(class vgui::SurfacePlat __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetPlat(vgui::VPanel *this, vgui::SurfacePlat *Plat)
{
  this->_plat = Plat;
}

//------------------------------------------------------------------------------
// Address: 0x10018050
// Name: public: virtual bool vgui::VPanel::IsPopup(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsPopup(vgui::VPanel *this)
{
  return (*((_BYTE *)this + 74) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018060
// Name: public: virtual void vgui::VPanel::SetPopup(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetPopup(vgui::VPanel *this, bool state)
{
  *((_BYTE *)this + 74) ^= (*((_BYTE *)this + 74) ^ (4 * state)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10018080
// Name: public: virtual bool vgui::VPanel::IsTopmostPopup(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsTopmostPopup(vgui::VPanel *this)
{
  return (*((_BYTE *)this + 74) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10018090
// Name: public: virtual void vgui::VPanel::SetTopmostPopup(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetTopmostPopup(vgui::VPanel *this, bool bEnable)
{
  *((_BYTE *)this + 74) ^= (*((_BYTE *)this + 74) ^ (32 * bEnable)) & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x100180B0
// Name: public: virtual bool vgui::VPanel::IsFullyVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsFullyVisible(vgui::VPanel *this)
{
  bool result; // al

  result = true;
  if ( this != nullptr )
  {
    while ( (*((_BYTE *)this + 74) & 1) != 0 )
    {
      this = this->_parent;
      if ( this == nullptr )
        return result;
    }
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100180D0
// Name: public: virtual char const __near * vgui::VPanel::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall vgui::VPanel::GetName(vgui::VPanel *this)
{
  vgui::IClientPanel *v1; // eax

  v1 = this->Client(this);
  return v1->GetName(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100180F0
// Name: public: virtual char const __near * vgui::VPanel::GetClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall vgui::VPanel::GetClassName(vgui::VPanel *this)
{
  vgui::IClientPanel *v1; // eax

  v1 = this->Client(this);
  return v1->GetClassName(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10018110
// Name: public: virtual unsigned long vgui::VPanel::GetScheme(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::VPanel::GetScheme(vgui::VPanel *this)
{
  vgui::IClientPanel *v1; // eax

  v1 = this->Client(this);
  return v1->GetScheme(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10018130
// Name: public: virtual void vgui::VPanel::SendMessage(class KeyValues __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SendMessage(vgui::VPanel *this, KeyValues *params, unsigned int ifrompanel)
{
  vgui::IClientPanel *v3; // eax

  v3 = this->Client(this);
  v3->OnMessage(this: v3, a2: params, a3: ifrompanel);
}

//------------------------------------------------------------------------------
// Address: 0x10018150
// Name: public: virtual void vgui::VPanel::SetKeyBoardInputEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetKeyBoardInputEnabled(vgui::VPanel *this, bool state)
{
  *((_BYTE *)this + 74) ^= (*((_BYTE *)this + 74) ^ (16 * state)) & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x10018170
// Name: public: virtual void vgui::VPanel::SetMouseInputEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetMouseInputEnabled(vgui::VPanel *this, bool state)
{
  *((_BYTE *)this + 74) ^= (*((_BYTE *)this + 74) ^ (8 * state)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10018190
// Name: public: virtual bool vgui::VPanel::IsKeyBoardInputEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsKeyBoardInputEnabled(vgui::VPanel *this)
{
  return (*((_BYTE *)this + 74) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100181A0
// Name: public: virtual bool vgui::VPanel::IsMouseInputEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::VPanel::IsMouseInputEnabled(vgui::VPanel *this)
{
  return (*((_BYTE *)this + 74) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100181B0
// Name: public: virtual void vgui::VPanel::SetMessageContextId(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetMessageContextId(vgui::VPanel *this, int nContextId)
{
  this->m_nMessageContextId = nContextId;
}

//------------------------------------------------------------------------------
// Address: 0x100181C0
// Name: public: virtual int vgui::VPanel::GetMessageContextId(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::VPanel::GetMessageContextId(vgui::VPanel *this)
{
  return this->m_nMessageContextId;
}

//------------------------------------------------------------------------------
// Address: 0x100181D0
// Name: public: virtual void vgui::VPanel::SetSiblingPin(class vgui::VPanel __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetSiblingPin(
        vgui::VPanel *this,
        vgui::VPanel *newSibling,
        unsigned __int8 iMyCornerToPin,
        unsigned __int8 iSiblingCornerToPinTo)
{
  this->_pinsibling = newSibling;
  this->_pinsibling_my_corner = iMyCornerToPin;
  this->_pinsibling_their_corner = iSiblingCornerToPinTo;
}

//------------------------------------------------------------------------------
// Address: 0x100181F0
// Name: public: virtual void vgui::VPanel::Solve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::Solve(vgui::VPanel *this)
{
  __int16 v2; // ax
  __int16 v3; // cx
  void (__thiscall *GetSize)(vgui::VPanel *, int *, int *); // edx
  vgui::VPanel *v5; // ebx
  bool (__thiscall *IsPopup)(vgui::VPanel *); // edx
  vgui::VPanel *pinsibling; // ecx
  unsigned __int8 pinsibling_their_corner; // cl
  int v9; // eax
  int v10; // edi
  bool v11; // zf
  __int16 v12; // dx
  int v13; // edi
  int v14; // ebx
  vgui::VPanel *v15; // ecx
  __int16 v16; // ax
  __int16 v17; // ax
  int v18; // edi
  int v19; // ebx
  __int16 v20; // ax
  __int16 v21; // ax
  int pinset[4]; // [esp+8h] [ebp-48h] BYREF
  int v23; // [esp+18h] [ebp-38h] BYREF
  int v24; // [esp+1Ch] [ebp-34h] BYREF
  int sibSize[2]; // [esp+20h] [ebp-30h] BYREF
  int baseSize[2]; // [esp+28h] [ebp-28h] BYREF
  int pabs[2]; // [esp+30h] [ebp-20h] BYREF
  int sibPos[2]; // [esp+38h] [ebp-18h] BYREF
  int v29; // [esp+40h] [ebp-10h]
  int iSign; // [esp+44h] [ebp-Ch]
  vgui::VPanel *parent; // [esp+48h] [ebp-8h]
  __int16 basePos[2]; // [esp+4Ch] [ebp-4h]

  v2 = this->_pos[0];
  v3 = this->_pos[1];
  GetSize = this->GetSize;
  basePos[0] = v2;
  basePos[1] = v3;
  GetSize(this, a2: baseSize, a3: &baseSize[1]);
  v5 = this->GetParent(this);
  IsPopup = this->IsPopup;
  parent = v5;
  if ( IsPopup(this) )
  {
    parent = (vgui::VPanel *)vgui::g_pSurface->GetEmbeddedPanel(this: vgui::g_pSurface);
    v5 = parent;
  }
  if ( v5 != nullptr )
    v5->GetAbsPos(this: v5, a2: pabs, a3: &pabs[1]);
  pinsibling = this->_pinsibling;
  if ( pinsibling != nullptr )
  {
    pinsibling->GetInternalAbsPos(this: pinsibling, a2: sibPos, a3: &sibPos[1]);
    this->_pinsibling->GetSize(this: this->_pinsibling, a2: sibSize, a3: &sibSize[1]);
    pinsibling_their_corner = this->_pinsibling_their_corner;
    v9 = 0;
    v10 = 2 * this->_pinsibling_my_corner;
    v29 = v10;
    while ( 1 )
    {
      if ( v5 != nullptr )
        sibPos[v9] -= pabs[v9];
      iSign = 1;
      if ( v9 != 0 )
      {
        if ( v9 != 1 )
          goto LABEL_20;
        if ( pinsibling_their_corner != 4 && pinsibling_their_corner != 0 )
        {
          v11 = pinsibling_their_corner == 1;
LABEL_18:
          if ( !v11 )
            goto LABEL_20;
        }
      }
      else if ( pinsibling_their_corner != 7 && pinsibling_their_corner != 0 )
      {
        v11 = pinsibling_their_corner == 2;
        goto LABEL_18;
      }
      iSign = -1;
LABEL_20:
      basePos[v9] = iSign * basePos[v9]
                  + (int)(float)((float)(int)(float)((float)((float)sibSize[v9]
                                                           * PinDeltas[2 * pinsibling_their_corner + v9])
                                                   + (float)sibPos[v9])
                               - (float)((float)baseSize[v9] * PinDeltas[v9 + v10]));
      if ( ++v9 >= 2 )
        break;
      v10 = v29;
      v5 = parent;
    }
  }
  v12 = basePos[1];
  v13 = basePos[0];
  v14 = basePos[1];
  this->_absPos[0] = basePos[0];
  v15 = parent;
  this->_absPos[1] = v12;
  memset(pinset, 0, sizeof(pinset));
  if ( v15 != nullptr )
  {
    v15->GetInset(this: v15, a2: pinset, a3: &pinset[1], a4: &pinset[2], a5: &pinset[3]);
    v13 += pinset[0] + pabs[0];
    v14 += pinset[1] + pabs[1];
    if ( v13 >= -32767 )
    {
      v16 = 0x7FFF;
      if ( v13 <= 0x7FFF )
        v16 = v13;
    }
    else
    {
      v16 = -32767;
    }
    this->_absPos[0] = v16;
    if ( v14 >= -32767 )
    {
      v17 = 0x7FFF;
      if ( v14 <= 0x7FFF )
        v17 = v14;
    }
    else
    {
      v17 = -32767;
    }
    v15 = parent;
    this->_absPos[1] = v17;
  }
  v18 = baseSize[0] + v13;
  v19 = baseSize[1] + v14;
  this->_clipRect[0] = this->_absPos[0];
  this->_clipRect[1] = this->_absPos[1];
  if ( v18 >= -32767 )
  {
    if ( v18 > 0x7FFF )
      LOWORD(v18) = 0x7FFF;
  }
  else
  {
    LOWORD(v18) = -32767;
  }
  this->_clipRect[2] = v18;
  if ( v19 >= -32767 )
  {
    if ( v19 > 0x7FFF )
      LOWORD(v19) = 0x7FFF;
  }
  else
  {
    LOWORD(v19) = -32767;
  }
  this->_clipRect[3] = v19;
  if ( v15 != nullptr && !this->IsPopup(this) )
  {
    parent->GetClipRect(this: parent, a2: &v23, a3: &v24, a4: sibSize, a5: &sibSize[1]);
    if ( this->_clipRect[0] < v23 )
      this->_clipRect[0] = v23;
    if ( this->_clipRect[1] < v24 )
      this->_clipRect[1] = v24;
    if ( this->_clipRect[2] > sibSize[0] )
      this->_clipRect[2] = LOWORD(sibSize[0]) - LOWORD(pinset[2]);
    if ( this->_clipRect[3] > sibSize[1] )
      this->_clipRect[3] = LOWORD(sibSize[1]) - LOWORD(pinset[3]);
    v20 = this->_clipRect[0];
    if ( v20 > this->_clipRect[2] )
      this->_clipRect[2] = v20;
    v21 = this->_clipRect[1];
    if ( v21 > this->_clipRect[3] )
      this->_clipRect[3] = v21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100184E0
// Name: public: virtual int vgui::VPanel::GetChildCount(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall vgui::VPanel::GetChildCount(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

//------------------------------------------------------------------------------
// Address: 0x100184F0
// Name: public: virtual class vgui::VPanel __near * vgui::VPanel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall vgui::VPanel::GetChild(vgui::VPanel *this, int index)
{
  return this->_childDar.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x10018500
// Name: public: int CUtlVector<class vgui::VPanel __near *,class CUtlMemory<class vgui::VPanel __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int>>::InsertMultipleBefore(
        CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::VPanel **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CWin32Font *,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10018570
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::VPanel::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::VPanel::GetUnpackStructure(vgui::VPanel *this)
{
  return vgui::VPanel::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x10018580
// Name: public: virtual unsigned long vgui::VPanel::GetHPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::VPanel::GetHPanel(vgui::VPanel *this)
{
  return this->_hPanel;
}

//------------------------------------------------------------------------------
// Address: 0x10018590
// Name: public: virtual void vgui::VPanel::SetHPanel(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetHPanel(vgui::VPanel *this, unsigned int hPanel)
{
  this->_hPanel = hPanel;
}

//------------------------------------------------------------------------------
// Address: 0x100185A0
// Name: public: virtual class vgui::IClientPanel __near * vgui::VPanel::Client(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IClientPanel *__thiscall vgui::VPanel::Client(vgui::VPanel *this)
{
  return this->_clientPanel;
}

//------------------------------------------------------------------------------
// Address: 0x100185B0
// Name: public: void vgui::Dar<class vgui::VPanel __near *>::InsertElementAt(class vgui::VPanel __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Dar<vgui::VPanel *>::InsertElementAt(
        vgui::Dar<vgui::VPanel *> *this,
        vgui::VPanel *elem,
        int index)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::VPanel **m_pMemory; // ecx
  int v7; // eax
  vgui::VPanel **v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow((CUtlMemory<CWin32Font *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - index - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[index + 1], src: &m_pMemory[index], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[index];
  if ( v8 != nullptr )
    *v8 = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10018610
// Name: public: vgui::VPanel::VPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall vgui::VPanel::VPanel(vgui::VPanel *this)
{
  char v2; // dl

  this->__vftable = (vgui::VPanel_vtbl *)&vgui::VPanel::`vftable';
  this->_childDar.m_Memory.m_pMemory = nullptr;
  this->_childDar.m_Memory.m_nAllocationCount = 0;
  this->_childDar.m_Memory.m_nGrowSize = 0;
  this->_childDar.m_Size = 0;
  this->_childDar.m_pElements = nullptr;
  this->_pos[1] = 0;
  this->_pos[0] = 0;
  this->_absPos[1] = 0;
  this->_absPos[0] = 0;
  this->_size[1] = 0;
  this->_size[0] = 0;
  this->_minimumSize[0] = 0;
  this->_minimumSize[1] = 0;
  this->_zpos = 0;
  this->_inset[3] = 0;
  this->_inset[2] = 0;
  this->_inset[1] = 0;
  this->_inset[0] = 0;
  this->_clipRect[3] = 0;
  this->_clipRect[2] = 0;
  this->_clipRect[1] = 0;
  this->_clipRect[0] = 0;
  v2 = *((_BYTE *)this + 74) & 0xC0 | 0x1B;
  this->_clientPanel = nullptr;
  this->_parent = nullptr;
  this->_plat = nullptr;
  this->_hPanel = -1;
  *((_BYTE *)this + 74) = v2;
  this->m_nMessageContextId = -1;
  this->_pinsibling = nullptr;
  *(_WORD *)&this->_pinsibling_my_corner = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018790
// Name: public: virtual void vgui::VPanel::SetZPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetZPos(vgui::VPanel *this, __int16 z)
{
  vgui::VPanel *v2; // edi
  vgui::VPanel *parent; // ecx
  int v4; // esi
  int i; // ebx
  vgui::VPanel *v6; // esi
  vgui::VPanel *v7; // esi
  vgui::VPanel *v8; // esi
  vgui::VPanel *v9; // esi
  int m_Size; // eax
  int v11; // edi
  vgui::VPanel *v12; // ecx
  int m_nAllocationCount; // edx
  vgui::VPanel **m_pMemory; // edx
  int v15; // eax
  vgui::VPanel *v16; // esi
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  int v20; // edx
  vgui::VPanel **v21; // edx
  int v22; // eax
  char *v23; // [esp+4h] [ebp-1Ch]
  int v24; // [esp+4h] [ebp-1Ch]
  int v25; // [esp+8h] [ebp-18h]
  vgui::VPanel *nextChild; // [esp+Ch] [ebp-14h]
  vgui::VPanel *nextChilda; // [esp+Ch] [ebp-14h]
  vgui::VPanel *prevChild; // [esp+10h] [ebp-10h]
  vgui::VPanel *prevChilda; // [esp+10h] [ebp-10h]
  vgui::VPanel *v30; // [esp+14h] [ebp-Ch]
  int v31; // [esp+18h] [ebp-8h]
  int v32; // [esp+1Ch] [ebp-4h]
  int za; // [esp+28h] [ebp+8h]

  v2 = this;
  parent = this->_parent;
  v30 = v2;
  v2->_zpos = z;
  if ( parent != nullptr )
  {
    v4 = parent->GetChildCount(this: parent);
    for ( i = 0; i < v4; ++i )
    {
      if ( v2->_parent->GetChild(this: v2->_parent, a2: i) == v2 )
        break;
    }
    if ( i != v4 )
    {
      v25 = v4 - 1;
      za = i + 1;
      v31 = i + 2;
      v32 = i;
      while ( 1 )
      {
        while ( 1 )
        {
          v6 = nullptr;
          prevChild = nullptr;
          nextChild = nullptr;
          if ( i > 0 )
          {
            prevChild = v2->_parent->GetChild(this: v2->_parent, a2: i - 1);
            v6 = prevChild;
          }
          if ( i < v25 )
            nextChild = v2->_parent->GetChild(this: v2->_parent, a2: za);
          if ( i <= 0 || v6 == nullptr || v6->_zpos <= v2->_zpos )
            break;
          v7 = v2->_parent;
          if ( v7->_childDar.m_Size < za )
            CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int>>::InsertMultipleBefore(
              this: &v7->_childDar,
              elem: v7->_childDar.m_Size,
              num: za - v7->_childDar.m_Size);
          v7->_childDar.m_Memory.m_pMemory[i] = prevChild;
          v8 = v2->_parent;
          if ( v8->_childDar.m_Size < v32 )
            CUtlVector<vgui::VPanel *,CUtlMemory<vgui::VPanel *,int>>::InsertMultipleBefore(
              this: &v8->_childDar,
              elem: v8->_childDar.m_Size,
              num: v32 - v8->_childDar.m_Size);
          v8->_childDar.m_Memory.m_pMemory[i - 1] = v2;
          --v32;
          --za;
          --i;
          --v31;
        }
        if ( i >= v25 || nextChild == nullptr || nextChild->_zpos >= v2->_zpos )
          break;
        v9 = v2->_parent;
        m_Size = v9->_childDar.m_Size;
        if ( m_Size < za )
        {
          v11 = za - m_Size;
          v12 = (vgui::VPanel *)v9->_childDar.m_Size;
          prevChilda = v12;
          if ( za != m_Size )
          {
            m_nAllocationCount = v9->_childDar.m_Memory.m_nAllocationCount;
            v23 = (char *)v12 + v11;
            if ( (int)v12 + v11 > m_nAllocationCount )
            {
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CWin32Font *,int> *)&v9->_childDar,
                num: (int)v12 + v11 - m_nAllocationCount);
              v12 = prevChilda;
            }
            v9->_childDar.m_Size += v11;
            m_pMemory = v9->_childDar.m_Memory.m_pMemory;
            v15 = v9->_childDar.m_Size - (_DWORD)v12 - v11;
            v9->_childDar.m_pElements = m_pMemory;
            if ( v15 > 0 && v11 > 0 )
              _V_memmove(dest: &m_pMemory[(_DWORD)v23], src: &m_pMemory[(_DWORD)v12], count: 4 * v15);
          }
          v2 = v30;
        }
        v9->_childDar.m_Memory.m_pMemory[i] = nextChild;
        v16 = v2->_parent;
        v17 = v16->_childDar.m_Size;
        if ( v17 < v31 )
        {
          v18 = v31 - v17;
          v19 = v16->_childDar.m_Size;
          v24 = v19;
          if ( v31 != v17 )
          {
            v20 = v16->_childDar.m_Memory.m_nAllocationCount;
            nextChilda = (vgui::VPanel *)(v19 + v18);
            if ( v19 + v18 > v20 )
            {
              CUtlMemory<int,int>::Grow(this: (CUtlMemory<CWin32Font *,int> *)&v16->_childDar, num: v18 + v19 - v20);
              v19 = v24;
            }
            v16->_childDar.m_Size += v18;
            v21 = v16->_childDar.m_Memory.m_pMemory;
            v22 = v16->_childDar.m_Size - v19 - v18;
            v16->_childDar.m_pElements = v21;
            if ( v22 > 0 && v18 > 0 )
              _V_memmove(dest: &v21[(_DWORD)nextChilda], src: &v21[v19], count: 4 * v22);
          }
          v2 = v30;
        }
        ++v32;
        ++za;
        v16->_childDar.m_Memory.m_pMemory[++i] = v2;
        ++v31;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100189B0
// Name: public: virtual void vgui::VPanel::MoveToFront(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::MoveToFront(vgui::VPanel *this)
{
  vgui::VPanel *v1; // ebx
  vgui::VPanel *parent; // eax
  int v3; // edx
  int v4; // edi
  vgui::VPanel *v5; // esi
  int m_Size; // eax
  int v7; // edi
  int v8; // edi
  int v9; // ebx
  int m_nAllocationCount; // ecx
  vgui::VPanel **m_pMemory; // ecx
  int v12; // eax
  vgui::VPanel *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // ecx
  vgui::VPanel **v18; // ecx
  int v19; // eax
  vgui::VPanel *v20; // [esp+4h] [ebp-14h]
  int v21; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v1 = this;
  vgui::g_pSurface->MovePopupToFront(this: vgui::g_pSurface, a2: (unsigned int)this);
  parent = v1->_parent;
  if ( parent != nullptr )
  {
    vgui::Dar<unsigned int>::MoveElementToEnd(
      this: (vgui::Dar<unsigned int> *)&parent->_childDar,
      elem: (unsigned int)v1);
    v3 = v1->_parent->_childDar.m_Size - 2;
    i = v3;
    if ( v3 >= 0 )
    {
      v4 = v3 + 1;
      v21 = v3 + 1;
      do
      {
        if ( v1->_parent->_childDar.m_Memory.m_pMemory[v3]->_zpos <= v1->_zpos )
          break;
        v5 = v1->_parent;
        v20 = v5->_childDar.m_Memory.m_pMemory[v3];
        m_Size = v5->_childDar.m_Size;
        v7 = v4 + 1;
        if ( m_Size < v7 )
        {
          v8 = v7 - m_Size;
          v9 = v5->_childDar.m_Size;
          if ( v8 != 0 )
          {
            m_nAllocationCount = v5->_childDar.m_Memory.m_nAllocationCount;
            if ( v9 + v8 > m_nAllocationCount )
            {
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CWin32Font *,int> *)&v5->_childDar,
                num: v8 + v9 - m_nAllocationCount);
              v3 = i;
            }
            v5->_childDar.m_Size += v8;
            m_pMemory = v5->_childDar.m_Memory.m_pMemory;
            v12 = v5->_childDar.m_Size - v9 - v8;
            v5->_childDar.m_pElements = m_pMemory;
            if ( v12 > 0 && v8 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9] + v8, src: &m_pMemory[v9], count: 4 * v12);
              v3 = i;
            }
          }
          v1 = this;
        }
        v5->_childDar.m_Memory.m_pMemory[v3 + 1] = v20;
        v13 = v1->_parent;
        v14 = v13->_childDar.m_Size;
        if ( v14 < v21 )
        {
          v15 = v21 - v14;
          v16 = v13->_childDar.m_Size;
          if ( v21 != v14 )
          {
            v17 = v13->_childDar.m_Memory.m_nAllocationCount;
            if ( v16 + v15 > v17 )
            {
              CUtlMemory<int,int>::Grow(this: (CUtlMemory<CWin32Font *,int> *)&v13->_childDar, num: v15 + v16 - v17);
              v3 = i;
            }
            v13->_childDar.m_Size += v15;
            v18 = v13->_childDar.m_Memory.m_pMemory;
            v19 = v13->_childDar.m_Size - v16 - v15;
            v13->_childDar.m_pElements = v18;
            if ( v19 > 0 && v15 > 0 )
            {
              _V_memmove(dest: &v18[v16] + v15, src: &v18[v16], count: 4 * v19);
              v3 = i;
            }
          }
          v1 = this;
        }
        v13->_childDar.m_Memory.m_pMemory[v3--] = v1;
        v4 = v21 - 1;
        i = v3;
        --v21;
      }
      while ( v3 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018B20
// Name: public: virtual void vgui::VPanel::MoveToBack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::MoveToBack(vgui::VPanel *this)
{
  vgui::VPanel *v1; // ebx
  vgui::VPanel *parent; // eax
  vgui::VPanel *v3; // eax
  int p_childDar; // ecx
  int v5; // edi
  vgui::VPanel *v6; // esi
  int m_Size; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  int m_nAllocationCount; // edx
  vgui::VPanel **m_pMemory; // edx
  int v13; // eax
  int v14; // edi
  vgui::VPanel *v15; // esi
  int v16; // eax
  int v17; // edi
  int v18; // ebx
  int v19; // ecx
  vgui::VPanel **v20; // ecx
  int v21; // eax
  vgui::VPanel *v22; // ecx
  int v23; // edi
  vgui::VPanel *v24; // [esp+4h] [ebp-18h]
  int v25; // [esp+8h] [ebp-14h]
  int v26; // [esp+Ch] [ebp-10h]
  vgui::VPanel *src; // [esp+14h] [ebp-8h] BYREF
  int v29; // [esp+18h] [ebp-4h]

  v1 = this;
  parent = this->_parent;
  if ( parent != nullptr )
  {
    src = this;
    CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(this: &parent->_childDar, &src);
    vgui::Dar<vgui::VPanel *>::InsertElementAt(this: &v1->_parent->_childDar, elem: v1, index: 0);
    v3 = v1->_parent;
    if ( v3->_childDar.m_Size > 1 )
    {
      p_childDar = 4;
      v5 = 2;
      src = (vgui::VPanel *)4;
      v29 = 2;
      do
      {
        if ( (*(vgui::VPanel **)((char *)v3->_childDar.m_Memory.m_pMemory + p_childDar))->_zpos >= v1->_zpos )
          break;
        v6 = v1->_parent;
        m_Size = v6->_childDar.m_Size;
        v8 = v5 - 1;
        v24 = *(vgui::VPanel **)((char *)v6->_childDar.m_Memory.m_pMemory + p_childDar);
        if ( m_Size < v8 )
        {
          v9 = v8 - m_Size;
          v10 = v6->_childDar.m_Size;
          v26 = v10;
          if ( v9 != 0 )
          {
            m_nAllocationCount = v6->_childDar.m_Memory.m_nAllocationCount;
            v25 = m_Size + v9;
            if ( m_Size + v9 > m_nAllocationCount )
            {
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CWin32Font *,int> *)&v6->_childDar,
                num: v9 + m_Size - m_nAllocationCount);
              v10 = v26;
            }
            v6->_childDar.m_Size += v9;
            m_pMemory = v6->_childDar.m_Memory.m_pMemory;
            v13 = v6->_childDar.m_Size - v10 - v9;
            v6->_childDar.m_pElements = m_pMemory;
            if ( v13 > 0 && v9 > 0 )
              _V_memmove(dest: &m_pMemory[v25], src: &m_pMemory[v10], count: 4 * v13);
          }
        }
        v14 = v29;
        *(vgui::VPanel **)((char *)v6->_childDar.m_Memory.m_pMemory + (unsigned int)src - 4) = v24;
        v15 = v1->_parent;
        v16 = v15->_childDar.m_Size;
        if ( v16 < v14 )
        {
          v17 = v14 - v16;
          v18 = v15->_childDar.m_Size;
          if ( v17 != 0 )
          {
            v19 = v15->_childDar.m_Memory.m_nAllocationCount;
            if ( v18 + v17 > v19 )
              CUtlMemory<int,int>::Grow(this: (CUtlMemory<CWin32Font *,int> *)&v15->_childDar, num: v17 + v18 - v19);
            v15->_childDar.m_Size += v17;
            v20 = v15->_childDar.m_Memory.m_pMemory;
            v21 = v15->_childDar.m_Size - v18 - v17;
            v15->_childDar.m_pElements = v20;
            if ( v21 > 0 && v17 > 0 )
              _V_memmove(dest: &v20[v18] + v17, src: &v20[v18], count: 4 * v21);
          }
          v1 = this;
        }
        v22 = src;
        v23 = v29;
        *(vgui::VPanel_vtbl **)((char *)&src->__vftable + (unsigned int)v15->_childDar.m_Memory.m_pMemory) = (vgui::VPanel_vtbl *)v1;
        v3 = v1->_parent;
        v5 = v23 + 1;
        p_childDar = (int)&v22->_childDar;
        v29 = v5;
        src = (vgui::VPanel *)p_childDar;
      }
      while ( v5 - 1 < v3->_childDar.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018C90
// Name: public: int vgui::Dar<class vgui::VPanel __near *>::PutElement(class vgui::VPanel __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Dar<vgui::VPanel *>::PutElement(vgui::Dar<vgui::VPanel *> *this, vgui::VPanel *elem)
{
  int m_Size; // edx
  int result; // eax
  vgui::VPanel **i; // esi

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return vgui::Dar<unsigned int>::AddElement((vgui::Dar<unsigned int> *)this, (unsigned int)elem);
  for ( i = this->m_Memory.m_pMemory; *i != elem; ++i )
  {
    if ( ++result >= m_Size )
      return vgui::Dar<unsigned int>::AddElement((vgui::Dar<unsigned int> *)this, (unsigned int)elem);
  }
  if ( result < 0 )
    return vgui::Dar<unsigned int>::AddElement((vgui::Dar<unsigned int> *)this, (unsigned int)elem);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018CD0
// Name: public: virtual void vgui::VPanel::SetParent(class vgui::VPanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::VPanel::SetParent(vgui::VPanel *this, vgui::VPanel *newParent)
{
  vgui::VPanel *v2; // edi
  vgui::VPanel *parent; // eax
  vgui::IClientPanel *v5; // eax

  v2 = newParent;
  if ( this != newParent )
  {
    parent = this->_parent;
    if ( parent != newParent )
    {
      if ( parent != nullptr )
      {
        newParent = this;
        CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(
          this: &parent->_childDar,
          src: &newParent);
        this->_parent = nullptr;
      }
      if ( v2 != nullptr )
      {
        this->_parent = v2;
        vgui::Dar<vgui::VPanel *>::PutElement(this: &v2->_childDar, elem: this);
        this->SetZPos(this, a2: this->_zpos);
        if ( this->_parent->Client(this: this->_parent) != nullptr )
        {
          v5 = this->_parent->Client(this: this->_parent);
          v5->OnChildAdded(this: v5, a2: (unsigned int)this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019070
// Name: public: virtual class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near & VPanelWrapper::GetChildren(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *__thiscall VPanelWrapper::GetChildren(
        VPanelWrapper *this,
        unsigned int vguiPanel)
{
  return (*(CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *(__thiscall **)(unsigned int))(*(_DWORD *)vguiPanel
                                                                                                 + 120))(a1: vguiPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10020530
// Name: public: void CUtlVector<class CFontAmalgam,class CUtlMemory<class CFontAmalgam,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::Purge(
        CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CFontAmalgam *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CFontAmalgam::~CFontAmalgam(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020730
// Name: public: CUtlVector<struct CFontAmalgam::TFontRange,class CUtlMemory<struct CFontAmalgam::TFontRange,int>>::~CUtlVector<struct CFontAmalgam::TFontRange,class CUtlMemory<struct CFontAmalgam::TFontRange,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(
        CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *this)
{
  bool v2; // sf
  CWin32Font **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100207A0
// Name: public: int CUtlVector<class CFontAmalgam,class CUtlMemory<class CFontAmalgam,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(
        CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFontAmalgam *m_pMemory; // ecx
  int v6; // eax
  CFontAmalgam *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CFontAmalgam,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CFontAmalgam::CFontAmalgam(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10022990
// Name: public: void CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::RemoveAll(
        CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int> > *this)
{
  int v1; // esi
  int v2; // edi
  BitmapFontTable_t *m_pMemory; // eax
  const ResourceBinding_t<CTextureBits> *m_pBinding; // edx

  v1 = this->m_Size - 1;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      m_pMemory = this->m_Memory.m_pMemory;
      m_pBinding = this->m_Memory.m_pMemory[v2].m_pTexture2.m_pBinding;
      if ( m_pBinding != nullptr )
      {
        _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
        m_pMemory[v2].m_pTexture2.m_pBinding = nullptr;
      }
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100229D0
// Name: public: CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>::~CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::~CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>(
        CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int> > *this)
{
  bool v2; // sf
  BitmapFontTable_t *m_pMemory; // eax

  CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018D50
// Name: __CreateVPanelWrapperIPanel_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
VPanelWrapper *__cdecl _CreateVPanelWrapperIPanel_interface()
{
  return &_g_VPanelWrapper_singleton;
}
