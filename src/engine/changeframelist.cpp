// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/changeframelist.cpp
// Functions: 5
// ============================================================

#include "engine\changeframelist.h"

//------------------------------------------------------------------------------
// Address: 0x101496B0
// Name: public: virtual void CChangeFrameList::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeFrameList::Release(CChangeFrameList *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CChangeFrameList *, int))this->dtr_IChangeFrameList)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101496C0
// Name: public: virtual void CChangeFrameList::SetChangeTick(int const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeFrameList::SetChangeTick(
        CChangeFrameList *this,
        const int *pPropIndices,
        int nPropIndices,
        int iTick)
{
  int i; // eax
  int v5; // edi

  for ( i = 0; i < nPropIndices; this->m_ChangeTicks.m_Memory.m_pMemory[v5] = iTick )
    v5 = pPropIndices[i++];
}

//------------------------------------------------------------------------------
// Address: 0x101496F0
// Name: public: virtual int CChangeFrameList::GetPropsChangedAfterTick(int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChangeFrameList::GetPropsChangedAfterTick(
        CChangeFrameList *this,
        int iTick,
        int *iOutProps,
        int nMaxOutProps)
{
  int m_Size; // esi
  __int64 v5; // rax

  m_Size = this->m_ChangeTicks.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_ChangeTicks.m_Memory.m_pMemory[HIDWORD(v5)] > iTick )
      {
        iOutProps[(_DWORD)v5] = HIDWORD(v5);
        LODWORD(v5) = v5 + 1;
      }
      ++HIDWORD(v5);
    }
    while ( SHIDWORD(v5) < m_Size );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10149750
// Name: public: virtual class IChangeFrameList __near * CChangeFrameList::Copy(void)
// Source: json
//------------------------------------------------------------------------------
CChangeFrameList *__thiscall CChangeFrameList::Copy(CChangeFrameList *this)
{
  CChangeFrameList *v2; // eax
  int m_Size; // esi
  int i; // eax
  CChangeFrameList *pRet; // [esp+Ch] [ebp-4h]

  v2 = (CChangeFrameList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CChangeFrameList_vtbl *)&CChangeFrameList::`vftable';
    v2->m_ChangeTicks.m_Memory.m_pMemory = nullptr;
    v2->m_ChangeTicks.m_Memory.m_nAllocationCount = 0;
    v2->m_ChangeTicks.m_Memory.m_nGrowSize = 0;
    v2->m_ChangeTicks.m_Size = 0;
    v2->m_ChangeTicks.m_pElements = nullptr;
    pRet = v2;
  }
  else
  {
    pRet = nullptr;
  }
  m_Size = this->m_ChangeTicks.m_Size;
  pRet->m_ChangeTicks.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&pRet->m_ChangeTicks,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    pRet->m_ChangeTicks.m_Memory.m_pMemory[i] = this->m_ChangeTicks.m_Memory.m_pMemory[i];
  return pRet;
}

//------------------------------------------------------------------------------
// Address: 0x101497C0
// Name: class IChangeFrameList __near * AllocChangeFrameList(int,int)
// Source: json
//------------------------------------------------------------------------------
CChangeFrameList *__cdecl AllocChangeFrameList(int nProperties, int iCurTick)
{
  CChangeFrameList *v2; // eax
  int i; // eax
  CChangeFrameList *pRet; // [esp+Ch] [ebp-4h]

  v2 = (CChangeFrameList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CChangeFrameList_vtbl *)&CChangeFrameList::`vftable';
    v2->m_ChangeTicks.m_Memory.m_pMemory = nullptr;
    v2->m_ChangeTicks.m_Memory.m_nAllocationCount = 0;
    v2->m_ChangeTicks.m_Memory.m_nGrowSize = 0;
    v2->m_ChangeTicks.m_Size = 0;
    v2->m_ChangeTicks.m_pElements = nullptr;
    pRet = v2;
  }
  else
  {
    pRet = nullptr;
  }
  pRet->m_ChangeTicks.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&pRet->m_ChangeTicks,
    elem: 0,
    num: nProperties);
  for ( i = 0; i < nProperties; ++i )
    pRet->m_ChangeTicks.m_Memory.m_pMemory[i] = iCurTick;
  return pRet;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10149810
// Name: public: virtual void CChangeFrameList::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeFrameList::Release(CChangeFrameList *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CChangeFrameList *, int))this->dtr_IChangeFrameList)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10149820
// Name: public: virtual void CChangeFrameList::SetChangeTick(int const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeFrameList::SetChangeTick(
        CChangeFrameList *this,
        const int *pPropIndices,
        int nPropIndices,
        int iTick)
{
  int i; // eax
  int v5; // edi

  for ( i = 0; i < nPropIndices; this->m_ChangeTicks.m_Memory.m_pMemory[v5] = iTick )
    v5 = pPropIndices[i++];
}

//------------------------------------------------------------------------------
// Address: 0x10149850
// Name: public: virtual int CChangeFrameList::GetPropsChangedAfterTick(int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChangeFrameList::GetPropsChangedAfterTick(
        CChangeFrameList *this,
        int iTick,
        int *iOutProps,
        int nMaxOutProps)
{
  int m_Size; // esi
  __int64 v5; // rax

  m_Size = this->m_ChangeTicks.m_Size;
  v5 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      if ( this->m_ChangeTicks.m_Memory.m_pMemory[HIDWORD(v5)] > iTick )
      {
        iOutProps[(_DWORD)v5] = HIDWORD(v5);
        LODWORD(v5) = v5 + 1;
      }
      ++HIDWORD(v5);
    }
    while ( SHIDWORD(v5) < m_Size );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101498B0
// Name: public: virtual class IChangeFrameList __near * CChangeFrameList::Copy(void)
// Source: json
//------------------------------------------------------------------------------
CChangeFrameList *__thiscall CChangeFrameList::Copy(CChangeFrameList *this)
{
  CChangeFrameList *v2; // eax
  int m_Size; // esi
  int i; // eax
  CChangeFrameList *pRet; // [esp+Ch] [ebp-4h]

  v2 = (CChangeFrameList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CChangeFrameList_vtbl *)&CChangeFrameList::`vftable';
    v2->m_ChangeTicks.m_Memory.m_pMemory = nullptr;
    v2->m_ChangeTicks.m_Memory.m_nAllocationCount = 0;
    v2->m_ChangeTicks.m_Memory.m_nGrowSize = 0;
    v2->m_ChangeTicks.m_Size = 0;
    v2->m_ChangeTicks.m_pElements = nullptr;
    pRet = v2;
  }
  else
  {
    pRet = nullptr;
  }
  m_Size = this->m_ChangeTicks.m_Size;
  pRet->m_ChangeTicks.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&pRet->m_ChangeTicks,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    pRet->m_ChangeTicks.m_Memory.m_pMemory[i] = this->m_ChangeTicks.m_Memory.m_pMemory[i];
  return pRet;
}

//------------------------------------------------------------------------------
// Address: 0x10149920
// Name: class IChangeFrameList __near * AllocChangeFrameList(int,int)
// Source: json
//------------------------------------------------------------------------------
CChangeFrameList *__cdecl AllocChangeFrameList(int nProperties, int iCurTick)
{
  CChangeFrameList *v2; // eax
  int i; // eax
  CChangeFrameList *pRet; // [esp+Ch] [ebp-4h]

  v2 = (CChangeFrameList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CChangeFrameList_vtbl *)&CChangeFrameList::`vftable';
    v2->m_ChangeTicks.m_Memory.m_pMemory = nullptr;
    v2->m_ChangeTicks.m_Memory.m_nAllocationCount = 0;
    v2->m_ChangeTicks.m_Memory.m_nGrowSize = 0;
    v2->m_ChangeTicks.m_Size = 0;
    v2->m_ChangeTicks.m_pElements = nullptr;
    pRet = v2;
  }
  else
  {
    pRet = nullptr;
  }
  pRet->m_ChangeTicks.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&pRet->m_ChangeTicks,
    elem: 0,
    num: nProperties);
  for ( i = 0; i < nProperties; ++i )
    pRet->m_ChangeTicks.m_Memory.m_pMemory[i] = iCurTick;
  return pRet;
}

} // namespace engine_xlsp
