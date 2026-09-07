// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/timestamp_log.cpp
// Functions: 24
// ============================================================

#include "utils\xbox\vxconsole\timestamp_log.h"

//------------------------------------------------------------------------------
// Address: 0x00412F70
// Name: public: void CUtlMemory<struct _DMN_MODLOAD,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<_DMN_MODLOAD,int>::Grow(CUtlMemory<_DMN_MODLOAD,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  _DMN_MODLOAD *m_pMemory; // edx
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
    v7 = 292 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (_DMN_MODLOAD *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (_DMN_MODLOAD *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416FF0
// Name: public: void CUtlMemory<struct CacheEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CacheEntry_t,int>::Grow(CUtlMemory<CacheEntry_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CacheEntry_t *m_pMemory; // edx
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
    v7 = 156 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CacheEntry_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CacheEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417090
// Name: public: void CUtlMemory<struct xrDataCacheItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xrDataCacheItem_t,int>::Grow(CUtlMemory<xrDataCacheItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xrDataCacheItem_t *m_pMemory; // edx
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
    v7 = 340 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (xrDataCacheItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (xrDataCacheItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421710
// Name: public: void CUtlMemory<struct VProfNode_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<VProfNode_t,int>::Grow(CUtlMemory<VProfNode_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VProfNode_t *m_pMemory; // edx
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
    v7 = 112 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VProfNode_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VProfNode_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004217A0
// Name: public: void CUtlMemory<struct xrVProfNodeItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xrVProfNodeItem_t,int>::Grow(CUtlMemory<xrVProfNodeItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xrVProfNodeItem_t *m_pMemory; // edx
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
    v7 = 280 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (xrVProfNodeItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (xrVProfNodeItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422570
// Name: public: void CUtlMemory<struct SymbolInfoStructs_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<SymbolInfoStructs_t,int>::Grow(CUtlMemory<SymbolInfoStructs_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SymbolInfoStructs_t *m_pMemory; // edx
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
    v7 = 576 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SymbolInfoStructs_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SymbolInfoStructs_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004231C0
// Name: public: void CUtlMemory<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,int>::Grow(
        CUtlMemory<CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> > *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> > *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlVector<`BuildCandidateScripts'::`5'::outFile_t,CUtlMemory<`BuildCandidateScripts'::`5'::outFile_t,int> > *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423260
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424C20
// Name: public: void CUtlMemory<struct dvdimage_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<dvdimage_t,int>::Grow(CUtlMemory<dvdimage_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  dvdimage_t *m_pMemory; // edx
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
    v7 = 348 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (dvdimage_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (dvdimage_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427EB0
// Name: public: void CUtlMemory<struct fileList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<fileList_t,int>::Grow(
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
// Address: 0x0042A1E0
// Name: int TimeStampLog_CompareFunc(long,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall TimeStampLog_CompareFunc(int lParam1, int lParam2, int lParamSort)
{
  int result; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4

  result = 0;
  switch ( g_timeStampLog_sortColumn )
  {
    case 0:
      v4 = *(float *)(lParam1 + 4);
      v5 = *(float *)(lParam2 + 4);
      goto LABEL_3;
    case 1:
      v4 = *(float *)(lParam1 + 8);
      v5 = *(float *)(lParam2 + 8);
LABEL_3:
      result = (int)(float)((float)(v4 * 1000.0) - (float)(v5 * 1000.0));
      break;
    case 2:
      result = *(_DWORD *)(lParam1 + 12) - *(_DWORD *)(lParam2 + 12);
      break;
    case 3:
      result = *(_DWORD *)(lParam1 + 16) - *(_DWORD *)(lParam2 + 16);
      break;
    case 4:
      result = _V_stricmp(s1: *(const char **)(lParam1 + 148), s2: *(const char **)(lParam2 + 148));
      break;
    default:
      break;
  }
  if ( g_timeStampLog_sortDescending != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A290
// Name: void TimeStampLog_SortItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_SortItems()
{
  LRESULT v0; // edi
  int i; // esi
  WPARAM v2; // edi
  char *v3; // esi
  char v4; // al
  tagLVITEMA lvitem; // [esp+0h] [ebp-6Ch] BYREF
  tagLVCOLUMNA lvc; // [esp+3Ch] [ebp-30h] BYREF
  int j; // [esp+68h] [ebp-4h]

  if ( g_timeStampLog_hWnd != nullptr )
  {
    SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1030u, wParam: 0, lParam: (LPARAM)TimeStampLog_CompareFunc);
    memset(dst: (unsigned __int8 *)&lvitem, value: 0, count: sizeof(lvitem));
    lvitem.mask = 4;
    v0 = SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    for ( i = 0; i < v0; ++i )
    {
      lvitem.iItem = i;
      SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvitem);
      *(_DWORD *)lvitem.lParam = i;
    }
    v2 = 0;
    v3 = byte_4669E4;
    for ( j = 5; j != 0; --j )
    {
      if ( v2 == g_timeStampLog_sortColumn )
        v4 = 2 * (g_timeStampLog_sortDescending == 0) + 60;
      else
        v4 = 32;
      sprintf(string: v3, format: "%s %c", *((const char **)v3 - 3), v4);
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      lvc.mask = 4;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x101Au, wParam: v2++, lParam: (LPARAM)&lvc);
      v3 += 44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A390
// Name: void TimeStampLog_FormatItems(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_FormatItems()
{
  timeStampLogNode_t *i; // ebx
  int memory; // eax
  char *v2; // esi
  char v3; // al
  char *v4; // esi
  char v5; // al
  int deltaMemory; // eax
  const char *v7; // ecx
  char *v8; // esi
  char v9; // al
  char *v10; // esi
  char v11; // al

  for ( i = g_timeStampLog_pNodes; i != nullptr; i = i->pNext )
  {
    memory = i->memory;
    if ( g_timeStampLog_showBytes != 0 )
    {
      if ( g_timeStampLog_showBytes == 1 )
      {
        sprintf(string: i->memoryBuff, format: "%s%.2f", &defValue, (float)((float)memory * 0.0009765625));
        v4 = &i->deltaTimeBuff[31];
        do
          v5 = *++v4;
        while ( v5 != 0 );
        strcpy(v4, " K");
      }
      else if ( g_timeStampLog_showBytes == 2 )
      {
        sprintf(string: i->memoryBuff, format: "%s%.2f", &defValue, (float)((float)memory * 0.00000095367432));
        v2 = &i->deltaTimeBuff[31];
        do
          v3 = *++v2;
        while ( v3 != 0 );
        strcpy(v2, " MB");
      }
    }
    else
    {
      sprintf(string: i->memoryBuff, format: "%s%d", &defValue, memory);
    }
    deltaMemory = i->deltaMemory;
    if ( deltaMemory != 0 )
    {
      v7 = &defValue;
      if ( deltaMemory > 0 )
        v7 = "+";
      if ( g_timeStampLog_showBytes != 0 )
      {
        if ( g_timeStampLog_showBytes == 1 )
        {
          sprintf(string: i->deltaMemoryBuff, format: "%s%.2f", v7, (float)((float)deltaMemory * 0.0009765625));
          v10 = &i->memoryBuff[31];
          do
            v11 = *++v10;
          while ( v11 != 0 );
          strcpy(v10, " K");
        }
        else if ( g_timeStampLog_showBytes == 2 )
        {
          sprintf(string: i->deltaMemoryBuff, format: "%s%.2f", v7, (float)((float)deltaMemory * 0.00000095367432));
          v8 = &i->memoryBuff[31];
          do
            v9 = *++v8;
          while ( v9 != 0 );
          strcpy(v8, " MB");
        }
      }
      else
      {
        sprintf(string: i->deltaMemoryBuff, format: "%s%d", v7, deltaMemory);
      }
    }
    else
    {
      i->deltaMemoryBuff[0] = 0;
    }
  }
  TimeStampLog_SortItems();
}

//------------------------------------------------------------------------------
// Address: 0x0042A550
// Name: void TimeStampLog_AddViewItem(struct timeStampLogNode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_AddViewItem(timeStampLogNode_t *pNode)
{
  float time; // xmm0_4
  int memory; // ecx
  char *v3; // edi
  char v4; // al
  char *v5; // edi
  char v6; // al
  int deltaMemory; // eax
  const char *v8; // ecx
  char *v9; // edi
  char v10; // al
  char *v11; // edi
  char v12; // al
  LRESULT v13; // ebx
  tagLVITEMA lvi; // [esp+14h] [ebp-40h] BYREF
  int v15; // [esp+50h] [ebp-4h]

  if ( g_timeStampLog_hWnd != nullptr )
  {
    time = pNode->time;
    v15 = (int)time / 60;
    sprintf(
      string: pNode->timeBuff,
      format: "%2.2d:%2.2d:%2.2d:%3.3d",
      (int)time / 3600,
      v15 % 60,
      (int)time % 60,
      (int)(float)((float)(time - (float)(int)time) * 1000.0) % 1000);
    sprintf(string: pNode->deltaTimeBuff, format: "%.3f", pNode->deltaTime);
    memory = pNode->memory;
    if ( g_timeStampLog_showBytes != 0 )
    {
      if ( g_timeStampLog_showBytes == 1 )
      {
        sprintf(string: pNode->memoryBuff, format: "%s%.2f", &defValue, (float)((float)memory * 0.0009765625));
        v5 = &pNode->deltaTimeBuff[31];
        do
          v6 = *++v5;
        while ( v6 != 0 );
        strcpy(v5, " K");
      }
      else if ( g_timeStampLog_showBytes == 2 )
      {
        sprintf(string: pNode->memoryBuff, format: "%s%.2f", &defValue, (float)((float)memory * 0.00000095367432));
        v3 = &pNode->deltaTimeBuff[31];
        do
          v4 = *++v3;
        while ( v4 != 0 );
        strcpy(v3, " MB");
      }
    }
    else
    {
      sprintf(string: pNode->memoryBuff, format: "%s%d", &defValue, memory);
    }
    deltaMemory = pNode->deltaMemory;
    if ( deltaMemory != 0 )
    {
      v8 = &defValue;
      if ( deltaMemory > 0 )
        v8 = "+";
      if ( g_timeStampLog_showBytes != 0 )
      {
        if ( g_timeStampLog_showBytes == 1 )
        {
          sprintf(string: pNode->deltaMemoryBuff, format: "%s%.2f", v8, (float)((float)deltaMemory * 0.0009765625));
          v11 = &pNode->memoryBuff[31];
          do
            v12 = *++v11;
          while ( v12 != 0 );
          strcpy(v11, " K");
        }
        else if ( g_timeStampLog_showBytes == 2 )
        {
          sprintf(string: pNode->deltaMemoryBuff, format: "%s%.2f", v8, (float)((float)deltaMemory * 0.00000095367432));
          v9 = &pNode->memoryBuff[31];
          do
            v10 = *++v9;
          while ( v10 != 0 );
          strcpy(v9, " MB");
        }
      }
      else
      {
        sprintf(string: pNode->deltaMemoryBuff, format: "%s%d", v8, deltaMemory);
      }
    }
    else
    {
      pNode->deltaMemoryBuff[0] = 0;
    }
    v13 = SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1004u, wParam: 0, lParam: 0);
    memset(dst: (unsigned __int8 *)&lvi, value: 0, count: sizeof(lvi));
    memset(&lvi.iSubItem, 0, 12);
    lvi.mask = 13;
    lvi.iItem = v13;
    lvi.pszText = (char *)-1;
    lvi.lParam = (int)pNode;
    pNode->index = SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A7E0
// Name: void TimeStampLog_AddItem(float,float,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_AddItem(float time, float deltaTime, int memory, int deltaMemory, const char *pMessage)
{
  unsigned __int8 *v5; // esi
  const char *v6; // eax

  v5 = (unsigned __int8 *)operator new(nSize: 0x9Cu);
  memset(dst: v5, value: 0, count: 0x9Cu);
  *((_DWORD *)v5 + 3) = memory;
  v6 = pMessage;
  *((float *)v5 + 1) = time;
  *((float *)v5 + 2) = deltaTime;
  *((_DWORD *)v5 + 4) = deltaMemory;
  if ( pMessage == nullptr )
    v6 = &defValue;
  *((_DWORD *)v5 + 37) = Sys_CopyString(str: v6);
  *((_DWORD *)v5 + 38) = g_timeStampLog_pNodes;
  g_timeStampLog_pNodes = (timeStampLogNode_t *)v5;
  TimeStampLog_AddViewItem(pNode: (timeStampLogNode_t *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x0042A860
// Name: void TimeStampLog_Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_Clear()
{
  timeStampLogNode_t *v0; // esi
  timeStampLogNode_t *pNext; // edi

  if ( g_timeStampLog_hWnd != nullptr )
    SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1009u, wParam: 0, lParam: 0);
  v0 = g_timeStampLog_pNodes;
  if ( g_timeStampLog_pNodes != nullptr )
  {
    do
    {
      pNext = v0->pNext;
      Sys_Free(ptr: v0->pMessage);
      free(pMem: v0);
      v0 = pNext;
    }
    while ( pNext != nullptr );
  }
  g_timeStampLog_pNodes = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8C0
// Name: void TimeStampLog_SaveConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_SaveConfig()
{
  char buff[256]; // [esp+0h] [ebp-12Ch] BYREF
  tagWINDOWPLACEMENT wp; // [esp+100h] [ebp-2Ch] BYREF

  Sys_SetRegistryInteger(keyName: "timeStampLogSortColumn", value: g_timeStampLog_sortColumn);
  Sys_SetRegistryInteger(keyName: "timeStampLogSortDescending", value: g_timeStampLog_sortDescending);
  Sys_SetRegistryInteger(keyName: "timeStampLogShowBytes", value: g_timeStampLog_showBytes);
  memset(dst: (unsigned __int8 *)&wp, value: 0, count: sizeof(wp));
  wp.length = 44;
  GetWindowPlacement(hWnd: g_timeStampLog_hWnd, lpwndpl: &wp);
  g_timeStampLog_windowRect = wp.rcNormalPosition;
  sprintf(
    string: buff,
    format: "%d %d %d %d",
    wp.rcNormalPosition.left,
    wp.rcNormalPosition.top,
    wp.rcNormalPosition.right,
    wp.rcNormalPosition.bottom);
  Sys_SetRegistryString(keyName: "timeStampLogWindowRect", value: buff);
}

//------------------------------------------------------------------------------
// Address: 0x0042A980
// Name: void TimeStampLog_LoadConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_LoadConfig()
{
  char buff[256]; // [esp+0h] [ebp-100h] BYREF

  Sys_GetRegistryInteger(keyName: "timeStampLogSortColumn", defValue: 0, value: &g_timeStampLog_sortColumn);
  Sys_GetRegistryInteger(keyName: "timeStampLogSortDescending", defValue: 0, value: &g_timeStampLog_sortDescending);
  Sys_GetRegistryInteger(keyName: "timeStampLogShowBytes", defValue: 1, value: &g_timeStampLog_showBytes);
  Sys_GetRegistryString(keyName: "timeStampLogWindowRect", value: buff, defValue: &defValue, valueLen: 256);
  if ( sscanf(
         string: buff,
         format: "%d %d %d %d",
         &g_timeStampLog_windowRect,
         &g_timeStampLog_windowRect.top,
         &g_timeStampLog_windowRect.right,
         &g_timeStampLog_windowRect.bottom) != 4
    || g_timeStampLog_windowRect.left < 0
    || g_timeStampLog_windowRect.top < 0
    || g_timeStampLog_windowRect.right < 0
    || g_timeStampLog_windowRect.bottom < 0 )
  {
    *(_QWORD *)&g_timeStampLog_windowRect.left = 0;
    *(_QWORD *)&g_timeStampLog_windowRect.right = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AA40
// Name: void TimeStampLog_SizeWindow(struct HWND__ __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_SizeWindow(HWND__ *hwnd, int width, int height)
{
  int right; // ecx
  int bottom; // eax
  tagRECT rcClient; // [esp+0h] [ebp-10h] BYREF

  right = width;
  if ( width == 0 || (bottom = height, height == 0) )
  {
    GetClientRect(hWnd: hwnd, lpRect: &rcClient);
    right = rcClient.right;
    bottom = rcClient.bottom;
  }
  SetWindowPos(
    hWnd: g_timeStampLog_hWndListView,
    hWndInsertAfter: nullptr,
    X: 0,
    Y: 0,
    cx: right,
    cy: bottom,
    uFlags: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x0042AA90
// Name: void TimeStampLog_Open(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_Open()
{
  WPARAM v0; // edi
  unsigned int i; // esi
  int v2; // ecx
  char *v3; // edx
  timeStampLogNode_t *j; // esi
  tagLVCOLUMNA lvc; // [esp+0h] [ebp-3Ch] BYREF
  tagRECT clientRect; // [esp+2Ch] [ebp-10h] BYREF

  if ( g_timeStampLog_hWnd != nullptr )
  {
    if ( IsIconic(hWnd: g_timeStampLog_hWnd) )
      ShowWindow(hWnd: g_timeStampLog_hWnd, nCmdShow: 9);
    SetForegroundWindow(hWnd: g_timeStampLog_hWnd);
  }
  else
  {
    g_timeStampLog_hWnd = CreateWindowExA(
                            dwExStyle: 0x200u,
                            lpClassName: "TIMESTAMPLOGCLASS",
                            lpWindowName: "TimeStamp Log",
                            dwStyle: 0x80CF0000,
                            X: 0,
                            Y: 0,
                            nWidth: 600,
                            nHeight: 300,
                            hWndParent: g_hDlgMain,
                            hMenu: nullptr,
                            hInstance: g_hInstance,
                            lpParam: nullptr);
    GetClientRect(hWnd: g_timeStampLog_hWnd, lpRect: &clientRect);
    v0 = 0;
    g_timeStampLog_hWndListView = CreateWindowExA(
                                    dwExStyle: 0,
                                    lpClassName: "SysListView32",
                                    lpWindowName: &defValue,
                                    dwStyle: 0x50000001u,
                                    X: 0,
                                    Y: 0,
                                    nWidth: clientRect.right - clientRect.left,
                                    nHeight: clientRect.bottom - clientRect.top,
                                    hWndParent: g_timeStampLog_hWnd,
                                    hMenu: (HMENU)0x64,
                                    hInstance: g_hInstance,
                                    lpParam: nullptr);
    for ( i = 0; i < 55; i += 11 )
    {
      memset(dst: (unsigned __int8 *)&lvc, value: 0, count: sizeof(lvc));
      v2 = dword_4669DC[i];
      v3 = *(char **)((char *)&g_timeStampLog_Labels[0].name + i * 4);
      lvc.iSubItem = 0;
      lvc.fmt = 0;
      lvc.cx = v2;
      lvc.mask = 15;
      lvc.pszText = v3;
      SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x101Bu, wParam: v0++, lParam: (LPARAM)&lvc);
    }
    SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1001u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1026u, wParam: 0, lParam: g_backgroundColor);
    SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1024u, wParam: 0, lParam: g_textColor);
    SendMessageA(hWnd: g_timeStampLog_hWndListView, Msg: 0x1036u, wParam: 0x31u, lParam: 49);
    for ( j = g_timeStampLog_pNodes; j != nullptr; j = j->pNext )
      TimeStampLog_AddViewItem(pNode: j);
    TimeStampLog_SortItems();
    if ( g_timeStampLog_windowRect.right != 0 && g_timeStampLog_windowRect.bottom != 0 )
      MoveWindow(
        hWnd: g_timeStampLog_hWnd,
        X: g_timeStampLog_windowRect.left,
        Y: g_timeStampLog_windowRect.top,
        nWidth: g_timeStampLog_windowRect.right - g_timeStampLog_windowRect.left,
        nHeight: g_timeStampLog_windowRect.bottom - g_timeStampLog_windowRect.top,
        bRepaint: false);
    ShowWindow(hWnd: g_timeStampLog_hWnd, nCmdShow: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AC80
// Name: int rc_TimeStampLog(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_TimeStampLog(char *commandPtr)
{
  char *Token; // eax
  char *v2; // eax
  xrTimeStamp_t timeStamp; // [esp+18h] [ebp-120h] BYREF
  int retVal; // [esp+128h] [ebp-10h]
  int xboxRetVal; // [esp+12Ch] [ebp-Ch] BYREF
  int retAddr; // [esp+130h] [ebp-8h] BYREF
  int timeStampAddr; // [esp+134h] [ebp-4h] BYREF

  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &timeStampAddr);
  v2 = GetToken(ppTokenStream: &commandPtr);
  if ( *v2 == 0 )
    return -1;
  sscanf(string: v2, format: "%x", &retAddr);
  DmGetMemory(a1: timeStampAddr, a2: 272, a3: &timeStamp, a4: 0);
  LODWORD(timeStamp.time) = _byteswap_ulong(LODWORD(timeStamp.time));
  LODWORD(timeStamp.deltaTime) = _byteswap_ulong(LODWORD(timeStamp.deltaTime));
  timeStamp.memory = _byteswap_ulong(timeStamp.memory);
  timeStamp.deltaMemory = _byteswap_ulong(timeStamp.deltaMemory);
  TimeStampLog_AddItem(
    time: timeStamp.time,
    deltaTime: timeStamp.deltaTime,
    memory: timeStamp.memory,
    deltaMemory: timeStamp.deltaMemory,
    pMessage: timeStamp.messageString);
  TimeStampLog_SortItems();
  retVal = 0;
  xboxRetVal = 0;
  DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
  DebugCommand(pStrFormat: "0x%8.8x = TimeStampLog( 0x%8.8x )\n", 0, timeStampAddr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042AD90
// Name: void TimeStampLog_Export(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimeStampLog_Export()
{
  int v0; // ebx
  _iobuf *v1; // edi
  label_t *v2; // esi
  int m_Size; // esi
  int m_nAllocationCount; // edx
  timeStampLogNode_t **m_pMemory; // ebx
  int v6; // ecx
  int *v7; // ecx
  int v8; // esi
  timeStampLogNode_t *v9; // esi
  char logFilename[260]; // [esp+4h] [ebp-178h] BYREF
  tagOFNA ofn; // [esp+108h] [ebp-74h] BYREF
  CUtlVector<timeStampLogNode_t *,CUtlMemory<timeStampLogNode_t *,int> > nodeList; // [esp+160h] [ebp-1Ch] BYREF
  int v13; // [esp+174h] [ebp-8h]
  int i; // [esp+178h] [ebp-4h]

  v0 = 0;
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  ofn.hwndOwner = g_timeStampLog_hWnd;
  ofn.lpstrFile = logFilename;
  logFilename[0] = 0;
  ofn.nMaxFile = 260;
  ofn.lpstrFilter = "Excel CSV";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = nullptr;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = "c:\\";
  ofn.Flags = 2048;
  if ( GetOpenFileNameA(a1: &ofn) )
  {
    Sys_AddExtension(extension: ".csv", outpath: logFilename, outPathLen: 260, bForce: false);
    v1 = fopen(file: logFilename, mode: "wt+");
    if ( v1 != nullptr )
    {
      v2 = g_timeStampLog_Labels;
      do
      {
        fprintf(str: v1, format: "\"%s\"", v2->name);
        if ( v0 != 4 )
          fprintf(str: v1, format: ",");
        v2 = (label_t *)((char *)v2 + 44);
        ++v0;
      }
      while ( (int)v2 < (int)&vec2_invalid_26 );
      fprintf(str: v1, format: "\n");
      m_Size = 0;
      m_nAllocationCount = 0;
      m_pMemory = nullptr;
      memset(&nodeList, 0, sizeof(nodeList));
      i = (int)g_timeStampLog_pNodes;
      if ( g_timeStampLog_pNodes != nullptr )
      {
        while ( 1 )
        {
          v6 = m_Size;
          v13 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
          {
            CUtlMemory<unsigned int,int>::Grow(
              this: (CUtlMemory<unsigned int,int> *)&nodeList,
              num: m_Size - m_nAllocationCount + 1);
            m_Size = nodeList.m_Size;
            m_pMemory = nodeList.m_Memory.m_pMemory;
            v6 = v13;
          }
          nodeList.m_Size = ++m_Size;
          nodeList.m_pElements = m_pMemory;
          if ( m_Size - v6 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * (m_Size - v6 - 1));
            v6 = v13;
          }
          v7 = (int *)&m_pMemory[v6];
          if ( v7 != nullptr )
            *v7 = i;
          i = *(_DWORD *)(i + 152);
          if ( i == 0 )
            break;
          m_nAllocationCount = nodeList.m_Memory.m_nAllocationCount;
        }
      }
      v8 = m_Size - 1;
      i = v8;
      if ( v8 >= 0 )
      {
        while ( 1 )
        {
          v9 = m_pMemory[v8];
          fprintf(str: v1, format: "\"%s\"", v9->timeBuff);
          fprintf(str: v1, format: ",\"%s\"", v9->deltaTimeBuff);
          fprintf(str: v1, format: ",\"%s\"", v9->memoryBuff);
          fprintf(str: v1, format: ",\"%s\"", v9->deltaMemoryBuff);
          fprintf(str: v1, format: ",\"%s\"", v9->pMessage);
          fprintf(str: v1, format: "\n");
          if ( --i < 0 )
            break;
          v8 = i;
        }
      }
      fclose(stream: v1);
      if ( nodeList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AFB0
// Name: long TimeStampLog_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall TimeStampLog_WndProc(HWND__ *hwnd, UINT message, HMENU wParam, unsigned int lParam)
{
  int result; // eax
  int v5; // eax
  int v6; // eax

  if ( message > 0x4E )
  {
    if ( message != 273 )
    {
      if ( message == 278 )
      {
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC55Fu, uCheck: g_timeStampLog_showBytes != 0 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC562u, uCheck: g_timeStampLog_showBytes != 1 ? 0 : 8);
        CheckMenuItem(hMenu: wParam, uIDCheckItem: 0xC563u, uCheck: g_timeStampLog_showBytes != 2 ? 0 : 8);
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam <= 0xC562u )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0xC562u:
          g_timeStampLog_showBytes = 1;
          TimeStampLog_FormatItems();
          return 0;
        case 0x9CC9u:
          TimeStampLog_Export();
          return 0;
        case 0xC55Fu:
          g_timeStampLog_showBytes = 0;
          TimeStampLog_FormatItems();
          return 0;
        default:
          break;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    if ( (unsigned __int16)wParam == 50531 )
    {
      g_timeStampLog_showBytes = 2;
      TimeStampLog_FormatItems();
      return 0;
    }
    if ( (unsigned __int16)wParam == 50584 )
    {
      TimeStampLog_Clear();
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  if ( message != 78 )
  {
    if ( message != 1 )
    {
      if ( message == 2 )
      {
        TimeStampLog_SaveConfig();
        g_timeStampLog_hWnd = nullptr;
        return 0;
      }
      if ( message == 5 )
      {
        TimeStampLog_SizeWindow(hwnd, width: (unsigned __int16)lParam, height: HIWORD(lParam));
        return 0;
      }
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
    }
    return 0;
  }
  v5 = *(_DWORD *)(lParam + 8);
  if ( v5 != -150 )
  {
    if ( v5 == -108 )
    {
      if ( g_timeStampLog_sortColumn == *(_DWORD *)(lParam + 16) )
        g_timeStampLog_sortDescending ^= 1u;
      else
        g_timeStampLog_sortColumn = *(_DWORD *)(lParam + 16);
      TimeStampLog_SortItems();
      return 0;
    }
    return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  v6 = *(_DWORD *)(lParam + 44);
  switch ( *(_DWORD *)(lParam + 20) )
  {
    case 0:
      *(_DWORD *)(lParam + 32) = v6 + 20;
      result = 0;
      break;
    case 1:
      *(_DWORD *)(lParam + 32) = v6 + 52;
      result = 0;
      break;
    case 2:
      *(_DWORD *)(lParam + 32) = v6 + 84;
      result = 0;
      break;
    case 3:
      *(_DWORD *)(lParam + 32) = v6 + 116;
      result = 0;
      break;
    case 4:
      *(_DWORD *)(lParam + 32) = *(_DWORD *)(v6 + 148);
      result = 0;
      break;
    default:
      return DefWindowProcA(hWnd: hwnd, Msg: message, (WPARAM)wParam, lParam);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B1E0
// Name: bool TimeStampLog_Init(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall TimeStampLog_Init@<al>(const char *a1@<ebp>)
{
  _DWORD v2[3]; // [esp-Ch] [ebp-3Ch] BYREF
  tagWNDCLASSA wndclass; // [esp+0h] [ebp-30h]
  void *v4; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  wndclass.lpszClassName = a1;
  v4 = retaddr;
  v2[0] = 0;
  v2[1] = TimeStampLog_WndProc;
  v2[2] = 0;
  wndclass.style = 0;
  wndclass.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))g_hInstance;
  wndclass.cbClsExtra = g_hIcons;
  wndclass.cbWndExtra = (int)LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wndclass.hInstance = (HINSTANCE__ *)g_hBackgroundBrush;
  wndclass.hIcon = (HICON__ *)129;
  wndclass.hCursor = (HICON__ *)"TIMESTAMPLOGCLASS";
  if ( RegisterClassA(lpWndClass: (const WNDCLASSA *)v2) == 0 )
    return 0;
  TimeStampLog_LoadConfig();
  return 1;
}
