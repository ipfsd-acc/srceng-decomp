// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/misc.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10087510
// Name: void randomize(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl randomize()
{
  holdrand = _time64(timeptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10087520
// Name: unsigned long random(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl random()
{
  unsigned int result; // eax

  result = 214013 * holdrand + 2531011;
  holdrand = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10087540
// Name: bool IsWorldObject(class CMapAtom __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsWorldObject(CMapAtom *pObject)
{
  return __RTDynamicCast(
           inptr: pObject,
           VfDelta: 0,
           SrcType: &CMapAtom `RTTI Type Descriptor',
           TargetType: &CMapWorld `RTTI Type Descriptor',
           isReference: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10087570
// Name: void NotifyDuplicates(class CUtlReferenceVector<class CMapClass> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyDuplicates(const CUtlReferenceVector<CMapClass> *pList)
{
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v3; // ecx
  CMapClass *v4; // edx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v6; // [esp+8h] [ebp-18h]
  CMapClass *v7; // [esp+Ch] [ebp-14h]
  CMapClass *pobj; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  if ( bCheckDupes != 0 )
  {
    for ( i = 0; i < pList->m_Size; ++i )
    {
      m_pObject = pList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pList->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pList->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v7 = pList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pList->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pList->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v3 = m_pObject->m_References.m_pHead;
        if ( v3 != nullptr )
          v3->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v6 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v4 = v7;
      pobj = v7;
      v9 = -1;
      if ( v7 != nullptr )
      {
        if ( v6 != nullptr )
        {
          v6->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v6;
        }
        else if ( (CUtlReference<CMapClass> **)v7->m_References.m_pHead == &m_pHead )
        {
          v7->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v6 = nullptr;
        m_pHead = nullptr;
        v7 = nullptr;
      }
      if ( v4->IsMapClass(this: v4, a2: CMapSolid::__Type) != 0
        && bCheckDupes != 0
        && DoesContainDuplicates(pSolid: (CMapSolid *)pobj) != 0
        && AfxMessageBox(lpszText: "Duplicate Plane! Do you want more messages?", nType: 4u, nIDHelp: 0) == 7 )
      {
        bCheckDupes = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100876B0
// Name: int AddLeavesToListCallback(class CMapClass __near *,class CUtlReferenceVector<class CMapClass> __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddLeavesToListCallback(CMapClass *pObject, CUtlReferenceVector<CMapClass> *pList)
{
  CUtlReference<CMapClass> *m_pHead; // ecx
  CUtlReference<CMapClass> src; // [esp+4h] [ebp-18h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  if ( pObject->m_Children.m_Size == 0 )
  {
    m_pHead = pObject->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = pObject;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pObject->m_References.m_pHead = &src;
    v5 = 0;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: pList,
      elem: pList->m_Size,
      &src);
    v5 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
  }
  return 1;
}
