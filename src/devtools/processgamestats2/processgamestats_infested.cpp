// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/processgamestats2/processgamestats_infested.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00405CB0
// Name: bool Infested_RecursiveProcessKeys(class CParseContext __near *,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Infested_RecursiveProcessKeys(CParseContext *pParseContext, CUtlMemory<char *,int> *vecKVStack)
{
  KeyValues *v3; // ecx
  KeyValues *FirstTrueSubKey; // ebx
  int m_pMemory; // eax
  int m_nAllocationCount; // ecx
  KeyValues **v7; // eax
  int v8; // ecx
  const char *Name; // eax
  const char *v10; // edi
  unsigned __int16 v11; // ax
  int v12; // eax
  int v13; // ecx
  KeyValues *v14; // ecx
  CUtlMap<char const *,CTable *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CDBInfo *dbInfo; // [esp+20h] [ebp+Ch]

  v3 = (KeyValues *)*vecKVStack->m_pMemory;
  dbInfo = pParseContext->pDBInfo;
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v3);
  if ( FirstTrueSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    m_pMemory = (int)vecKVStack[1].m_pMemory;
    m_nAllocationCount = vecKVStack->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<char *,int>::Grow(this: vecKVStack, num: m_pMemory - m_nAllocationCount + 1);
    ++vecKVStack[1].m_pMemory;
    v7 = (KeyValues **)vecKVStack->m_pMemory;
    v8 = (int)vecKVStack[1].m_pMemory - 1;
    vecKVStack[1].m_nAllocationCount = (int)vecKVStack->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: v7 + 1, src: v7, count: 4 * v8);
    if ( vecKVStack->m_pMemory != nullptr )
      *vecKVStack->m_pMemory = (char *)FirstTrueSubKey;
    Name = KeyValues::GetName(this: FirstTrueSubKey);
    v10 = Name;
    if ( Name != nullptr && *Name != 0 )
    {
      search.key = Name;
      v11 = CUtlRBTree<CUtlMap<char const *,CTable *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CTable *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CTable *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &dbInfo->m_mapTable.m_Tree,
              &search);
      if ( v11 != 0xFFFF )
      {
        if ( InsertRow(
               pParseContext,
               (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)vecKVStack,
               pTable: dbInfo->m_mapTable.m_Tree.m_Elements.m_pMemory[v11].m_Data.elem) == 0 )
          return 0;
        if ( _V_stricmp(s1: "asw_mission", s2: v10) == 0 )
        {
          v12 = pParseContext->mysql->InsertID(this: pParseContext->mysql);
          v13 = (int)vecKVStack[1].m_pMemory;
          if ( v13 < 2 )
          {
            printf(format: "Warning, failed to add MissionSessionID to parent keyvalues\n");
          }
          else
          {
            v14 = (KeyValues *)vecKVStack->m_pMemory[v13 - 2];
            if ( v14 != nullptr )
              KeyValues::SetInt(this: v14, keyName: "MissionSessionID", value: v12);
          }
        }
      }
    }
    if ( !Infested_RecursiveProcessKeys(
            pParseContext,
            (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)vecKVStack) )
      break;
    if ( (int)vecKVStack[1].m_pMemory - 1 > 0 )
      _V_memmove(
        dest: vecKVStack->m_pMemory,
        src: vecKVStack->m_pMemory + 1,
        count: 4 * ((int)vecKVStack[1].m_pMemory - 1));
    --vecKVStack[1].m_pMemory;
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
    if ( FirstTrueSubKey == nullptr )
      return 1;
  }
  return 0;
}
