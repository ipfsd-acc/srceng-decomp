// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/entityconnection.cpp
// Functions: 21
// ============================================================

#include "hammer\entityconnection.h"

//------------------------------------------------------------------------------
// Address: 0x10030820
// Name: public: void CEntityConnection::SetSourceName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityConnection::SetSourceName(CEntityConnection *this, const char *pszName)
{
  const char *v2; // eax

  v2 = pszName;
  if ( pszName == nullptr )
    v2 = "<<null>>";
  lstrcpynA(lpString1: this->m_szSourceEntity, lpString2: v2, iMaxLength: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10030840
// Name: public: static bool CEntityConnection::ValidateOutput(class CMapEntity const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CEntityConnection::ValidateOutput(const CMapEntity *pEntity, const char *pszOutput)
{
  bool result; // al
  GDclass *m_pClass; // ecx

  result = false;
  if ( pEntity != nullptr )
  {
    m_pClass = pEntity->m_pClass;
    if ( m_pClass == nullptr || GDclass::FindOutput(this: m_pClass, szName: pszOutput) != nullptr )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030870
// Name: public: static int CEntityConnection::CompareOutputNames(class CEntityConnection __near *,class CEntityConnection __near *,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CEntityConnection::CompareOutputNames(
        CEntityConnection *pConn1,
        CEntityConnection *pConn2,
        SortDirection_t eDirection)
{
  int result; // eax
  float m_fDelay; // xmm0_4
  float v5; // xmm1_4

  if ( eDirection != Sort_Ascending )
    result = _V_stricmp(s1: pConn2->m_szOutput, s2: pConn1->m_szOutput);
  else
    result = _V_stricmp(s1: pConn1->m_szOutput, s2: pConn2->m_szOutput);
  if ( result == 0 )
  {
    m_fDelay = pConn1->m_fDelay;
    v5 = pConn2->m_fDelay;
    if ( v5 <= m_fDelay )
      return m_fDelay > v5;
    else
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100308E0
// Name: public: static int CEntityConnection::CompareInputNames(class CEntityConnection __near *,class CEntityConnection __near *,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CEntityConnection::CompareInputNames(
        CEntityConnection *pConn1,
        CEntityConnection *pConn2,
        SortDirection_t eDirection)
{
  int result; // eax
  float m_fDelay; // xmm0_4
  float v5; // xmm1_4

  if ( eDirection != Sort_Ascending )
    result = _V_stricmp(s1: pConn2->m_szInput, s2: pConn1->m_szInput);
  else
    result = _V_stricmp(s1: pConn1->m_szInput, s2: pConn2->m_szInput);
  if ( result == 0 )
  {
    m_fDelay = pConn1->m_fDelay;
    v5 = pConn2->m_fDelay;
    if ( v5 <= m_fDelay )
      return m_fDelay > v5;
    else
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030950
// Name: public: static int CEntityConnection::CompareSourceNames(class CEntityConnection __near *,class CEntityConnection __near *,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CEntityConnection::CompareSourceNames(
        CEntityConnection *pConn1,
        CEntityConnection *pConn2,
        SortDirection_t eDirection)
{
  int result; // eax
  float m_fDelay; // xmm0_4
  float v5; // xmm1_4

  if ( eDirection != Sort_Ascending )
    result = CompareEntityNames(szName1: pConn2->m_szSourceEntity, szName2: pConn1->m_szSourceEntity);
  else
    result = CompareEntityNames(szName1: pConn1->m_szSourceEntity, szName2: pConn2->m_szSourceEntity);
  if ( result == 0 )
  {
    m_fDelay = pConn1->m_fDelay;
    v5 = pConn2->m_fDelay;
    if ( v5 <= m_fDelay )
      return m_fDelay > v5;
    else
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100309B0
// Name: public: static int CEntityConnection::CompareTargetNames(class CEntityConnection __near *,class CEntityConnection __near *,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CEntityConnection::CompareTargetNames(
        CEntityConnection *pConn1,
        CEntityConnection *pConn2,
        SortDirection_t eDirection)
{
  int result; // eax
  float m_fDelay; // xmm0_4
  float v5; // xmm1_4

  if ( eDirection != Sort_Ascending )
    result = CompareEntityNames(szName1: pConn2->m_szTargetEntity, szName2: pConn1->m_szTargetEntity);
  else
    result = CompareEntityNames(szName1: pConn1->m_szTargetEntity, szName2: pConn2->m_szTargetEntity);
  if ( result == 0 )
  {
    m_fDelay = pConn1->m_fDelay;
    v5 = pConn2->m_fDelay;
    if ( v5 <= m_fDelay )
      return m_fDelay > v5;
    else
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030A20
// Name: public: static int CEntityConnection::CompareDelays(class CEntityConnection __near *,class CEntityConnection __near *,enum SortDirection_t)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CEntityConnection::CompareDelays(
        CEntityConnection *pConn1,
        CEntityConnection *pConn2,
        SortDirection_t eDirection)
{
  float m_fDelay; // xmm0_4
  float v4; // xmm1_4
  int result; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( eDirection != Sort_Ascending )
  {
    m_fDelay = pConn2->m_fDelay;
    v4 = pConn1->m_fDelay;
  }
  else
  {
    m_fDelay = pConn1->m_fDelay;
    v4 = pConn2->m_fDelay;
  }
  if ( v4 > m_fDelay )
    return -1;
  if ( m_fDelay > v4 )
    return 1;
  result = _V_stricmp(s1: pConn1->m_szOutput, s2: pConn2->m_szOutput);
  if ( result == 0 )
  {
    v6 = pConn1->m_fDelay;
    v7 = pConn2->m_fDelay;
    if ( v7 > v6 )
      return -1;
    if ( v6 > v7 )
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030AB0
// Name: public: bool CEntityConnection::AreAnyTargetEntitiesVisible(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityConnection::AreAnyTargetEntitiesVisible(CEntityConnection *this)
{
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // esi
  int v2; // edx
  int v3; // eax
  CUtlReference<CMapEntity> **m_pMemory; // esi
  int v5; // ecx
  int v6; // edi
  CMapEntity *m_pObject; // eax
  int m_Size; // [esp+Ch] [ebp-4h]

  m_pTargetEntityList = this->m_pTargetEntityList;
  v2 = 0;
  m_Size = m_pTargetEntityList->m_Size;
  if ( m_Size <= 0 )
    return 0;
  v3 = *((_DWORD *)&m_pTargetEntityList->m_Memory + 2);
  m_pMemory = m_pTargetEntityList->m_Memory.m_pMemory;
  v5 = v3 >> 27;
  v6 = (32 * v3) >> 5;
  while ( 1 )
  {
    m_pObject = m_pMemory[v2 >> v5][v2 & v6].m_pObject;
    if ( m_pObject != nullptr && (*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0 )
      break;
    if ( ++v2 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030B20
// Name: public: static bool CEntityConnection::ValidateOutput(class CUtlReferenceVector<class CMapEntity> const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CEntityConnection::ValidateOutput(
        const CUtlReferenceVector<CMapEntity> *pEntityList,
        const char *pszOutput)
{
  int v3; // esi
  CMapEntity *m_pObject; // eax
  GDclass *m_pClass; // eax

  if ( pEntityList == nullptr )
    return 0;
  v3 = 0;
  if ( pEntityList->m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_pObject = pEntityList->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&pEntityList->m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&pEntityList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject == nullptr )
      break;
    m_pClass = m_pObject->m_pClass;
    if ( m_pClass != nullptr && GDclass::FindOutput(this: m_pClass, szName: pszOutput) == nullptr )
      break;
    if ( ++v3 >= pEntityList->m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10030B90
// Name: public: static bool CEntityConnection::ValidateTarget(class CUtlReferenceVector<class CMapEntity> const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CEntityConnection::ValidateTarget(
        const CUtlReferenceVector<CMapEntity> *pEntityList,
        bool bVisibilityCheck,
        const char *pszTarget)
{
  int v3; // esi
  CMapEntity *m_pObject; // ecx

  if ( pEntityList == nullptr || pszTarget == nullptr )
    return 0;
  if ( _V_stricmp(s1: pszTarget, s2: "!activator") == 0
    || _V_stricmp(s1: pszTarget, s2: "!caller") == 0
    || _V_stricmp(s1: pszTarget, s2: "!player") == 0
    || _V_stricmp(s1: pszTarget, s2: "!self") == 0 )
  {
    return 1;
  }
  v3 = 0;
  if ( pEntityList->m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    m_pObject = pEntityList->m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&pEntityList->m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&pEntityList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr
      && (!bVisibilityCheck || (*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0)
      && CMapEntity::NameMatches(this: m_pObject, szName: pszTarget) )
    {
      break;
    }
    if ( ++v3 >= pEntityList->m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030C60
// Name: public: static int CEntityConnection::ValidateInputConnections(class CMapEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CEntityConnection::ValidateInputConnections(CMapEntity *pEntity, bool bVisibilityCheck)
{
  CMapWorld *m_pWorld; // eax
  const CUtlReferenceVector<CMapEntity> *v4; // esi
  int v5; // edx
  CMapEntity *m_pObject; // edi
  int v7; // ebx
  const char *m_szSourceEntity; // esi
  GDclass *m_pClass; // ecx
  int nConnCount; // [esp+4h] [ebp-14h]
  GDclass *pClass; // [esp+8h] [ebp-10h]
  int pos; // [esp+Ch] [ebp-Ch]
  const CUtlReferenceVector<CMapEntity> *pAllWorldEntities; // [esp+10h] [ebp-8h]
  bool bHaveConnection; // [esp+17h] [ebp-1h]

  if ( pEntity == nullptr )
    return 0;
  if ( WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEntity->m_KeyValues, pszKey: "targetname", piIndex: nullptr) == nullptr )
    return 0;
  pClass = pEntity->m_pClass;
  if ( pClass == nullptr )
    return 0;
  pAllWorldEntities = nullptr;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
    if ( m_pWorld != nullptr )
      pAllWorldEntities = &m_pWorld->m_EntityList;
  }
  v4 = pAllWorldEntities;
  v5 = 0;
  bHaveConnection = false;
  pos = 0;
  if ( pAllWorldEntities->m_Size > 0 )
  {
    do
    {
      m_pObject = v4->m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&v4->m_Memory + 2) >> 27)][v5 & ((32 * *((_DWORD *)&v4->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr && (!bVisibilityCheck || (*((_BYTE *)&m_pObject->CMapClass + 180) & 2) != 0) )
      {
        v7 = 0;
        nConnCount = m_pObject->m_Connections.m_Size;
        if ( nConnCount > 0 )
        {
          while ( 1 )
          {
            m_szSourceEntity = m_pObject->m_Connections.m_Memory.m_pMemory[v7]->m_szSourceEntity;
            if ( m_szSourceEntity != nullptr && CMapEntity::NameMatches(this: pEntity, szName: m_szSourceEntity + 516) )
            {
              m_pClass = m_pObject->m_pClass;
              if ( m_pClass != nullptr && GDclass::FindOutput(this: m_pClass, szName: m_szSourceEntity + 260) == nullptr
                || GDclass::FindInput(this: pClass, szName: m_szSourceEntity + 776) == nullptr )
              {
                return 2;
              }
              bHaveConnection = true;
            }
            if ( ++v7 >= nConnCount )
            {
              v5 = pos;
              v4 = pAllWorldEntities;
              break;
            }
          }
        }
      }
      pos = ++v5;
    }
    while ( v5 < v4->m_Size );
    if ( bHaveConnection )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031070
// Name: public: void CEntityConnection::LinkTargetEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityConnection::LinkTargetEntities(CEntityConnection *this)
{
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // edx
  int i; // esi
  CMapEntity *m_pObject; // eax
  CMapWorld *m_pWorld; // ebx
  int j; // ebx
  CMapEntity *v7; // esi
  CUtlReference<CMapEntity> *m_pHead; // eax
  int k; // edi
  CUtlReferenceVector<CMapEntity> matches; // [esp+Ch] [ebp-2Ch] BYREF
  CUtlReference<CMapEntity> src; // [esp+20h] [ebp-18h] BYREF
  int v12; // [esp+34h] [ebp-4h]

  m_pTargetEntityList = this->m_pTargetEntityList;
  for ( i = 0; i < m_pTargetEntityList->m_Size; ++i )
  {
    m_pObject = m_pTargetEntityList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&m_pTargetEntityList->m_Memory
                                                                                + 2) >> 27)][i
                                                                                           & ((32
                                                                                             * *((_DWORD *)&m_pTargetEntityList->m_Memory
                                                                                               + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
      CEditGameClass::Upstream_Remove(this: &m_pObject->CEditGameClass, pConnection: this);
    m_pTargetEntityList = this->m_pTargetEntityList;
  }
  CUtlReferenceVector<CMapEntity>::RemoveAll(this: this->m_pTargetEntityList);
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
    if ( m_pWorld != nullptr )
    {
      memset(&matches, 0, 12);
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
        this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&matches,
        nGrowSize: 0,
        nInitSize: 0);
      matches.m_Size = 0;
      matches.m_pElements = nullptr;
      v12 = 3;
      CMapWorld::FindEntitiesByName(
        this: m_pWorld,
        Found: &matches,
        pszName: this->m_szTargetEntity,
        bVisiblesOnly: false);
      for ( j = 0; j < matches.m_Size; ++j )
      {
        v7 = matches.m_Memory.m_pMemory[j >> (*((int *)&matches.m_Memory + 2) >> 27)][j
                                                                                    & ((32
                                                                                      * *((_DWORD *)&matches.m_Memory + 2)) >> 5)].m_pObject;
        src.m_pPrev = nullptr;
        src.m_pNext = nullptr;
        src.m_pObject = v7;
        if ( v7 != nullptr )
        {
          m_pHead = v7->m_References.m_pHead;
          src.m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = &src;
          src.m_pPrev = nullptr;
          v7->m_References.m_pHead = &src;
        }
        LOBYTE(v12) = 4;
        CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::InsertBefore(
          this: this->m_pTargetEntityList,
          elem: this->m_pTargetEntityList->m_Size,
          &src);
        LOBYTE(v12) = 3;
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
        CToolEntitySprinkle::RenderTool2D(this: (vgui::TreeView *)&v7->CEditGameClass, itemIndex: (int)this);
      }
      v12 = 7;
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::RemoveAll(this: &matches);
      if ( matches.m_Memory.m_pMemory != nullptr )
      {
        for ( k = 0; k < matches.m_Memory.m_nBlocks; ++k )
          free(pMem: matches.m_Memory.m_pMemory[k]);
        matches.m_Memory.m_nBlocks = 0;
        free(pMem: matches.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100312B0
// Name: public: static bool CEntityConnection::ValidateInput(char const __near *,char const __near *,bool,class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CEntityConnection::ValidateInput(char *pszTarget, const char *pszInput, bool bVisiblesOnly, CMapDoc *pDoc)
{
  CMapDoc *v4; // edi
  CUtlReferenceVector<CMapEntity> EntityList; // [esp+4h] [ebp-20h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  if ( _V_stricmp(s1: pszTarget, s2: "!activator") == 0
    || _V_stricmp(s1: pszTarget, s2: "!caller") == 0
    || _V_stricmp(s1: pszTarget, s2: "!player") == 0
    || _V_stricmp(s1: pszTarget, s2: "!self") == 0 )
  {
    return 1;
  }
  v4 = pDoc;
  if ( pDoc == nullptr )
    v4 = CMapDoc::m_pMapDoc;
  memset(&EntityList, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)&EntityList,
    nGrowSize: 0,
    nInitSize: 0);
  EntityList.m_Size = 0;
  EntityList.m_pElements = nullptr;
  v7 = 3;
  CMapDoc::FindEntitiesByName(this: v4, Found: &EntityList, pszName: pszTarget, bVisiblesOnly);
  if ( EntityList.m_Size == 0 )
  {
    v7 = -1;
LABEL_9:
    CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &EntityList);
    return 0;
  }
  if ( !MapEntityList_HasInput(pList: &EntityList, szInput: pszInput, eType: iotInvalid) )
  {
    v7 = -1;
    goto LABEL_9;
  }
  v7 = -1;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: &EntityList);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100313E0
// Name: public: static void CEntityConnection::FindBadConnections(class CMapEntity __near *,bool,class CUtlVector<class CEntityConnection __near *,class CUtlMemory<class CEntityConnection __near *,int>> __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEntityConnection::FindBadConnections(
        CMapEntity *pEntity,
        bool bVisibilityCheck,
        CUtlMemory<CCullTreeNode *,int> *BadConnectionList,
        bool bIgnoreHiddenTargets,
        bool CheckAllDocuments)
{
  CMapEntity *v6; // edi
  int m_Size; // ecx
  CMapWorld *m_pWorld; // eax
  int v9; // eax
  CEntityConnection *v10; // ebx
  GDclass *m_pClass; // ecx
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v13; // eax
  void *v14; // eax
  CMapDoc *v15; // eax
  CMapDoc *v16; // edi
  char *m_szTargetEntity; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CEntityConnection **v20; // ecx
  int v21; // eax
  CEntityConnection **v22; // eax
  int v23; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  __POSITION *pos; // [esp+10h] [ebp-8h] BYREF
  CEntityConnection *pConnection; // [esp+14h] [ebp-4h]
  const CUtlReferenceVector<CMapEntity> *pAllWorldEntities; // [esp+28h] [ebp+10h]

  v6 = pEntity;
  BadConnectionList[1].m_pMemory = nullptr;
  if ( pEntity != nullptr )
  {
    m_Size = pEntity->m_Connections.m_Size;
    v23 = m_Size;
    if ( m_Size != 0 )
    {
      pAllWorldEntities = nullptr;
      if ( CMapDoc::m_pMapDoc != nullptr )
      {
        m_pWorld = CMapDoc::m_pMapDoc->m_pWorld;
        if ( m_pWorld != nullptr )
          pAllWorldEntities = &m_pWorld->m_EntityList;
      }
      v9 = 0;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = v6->m_Connections.m_Memory.m_pMemory[v9];
          pConnection = v10;
          if ( v10 != nullptr
            && (!bIgnoreHiddenTargets
             || v10->m_pTargetEntityList->m_Size <= 0
             || CEntityConnection::AreAnyTargetEntitiesVisible(this: v10) != 0) )
          {
            m_pClass = v6->m_pClass;
            if ( m_pClass == nullptr || GDclass::FindOutput(this: m_pClass, szName: v10->m_szOutput) != nullptr )
            {
              if ( CheckAllDocuments )
              {
                ModuleState = AfxGetModuleState();
                pos = (__POSITION *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                        + 84))(a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl);
                while ( pos != nullptr )
                {
                  v13 = AfxGetModuleState();
                  v14 = (void *)(*(int (__thiscall **)(unsigned int, __POSITION **))(*(_DWORD *)v13->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                                   + 88))(
                                  a1: v13->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                                  a2: &pos);
                  v15 = (CMapDoc *)__RTDynamicCast(
                                     inptr: v14,
                                     VfDelta: 0,
                                     SrcType: &CDocument `RTTI Type Descriptor',
                                     TargetType: &CMapDoc `RTTI Type Descriptor',
                                     isReference: 0);
                  v16 = v15;
                  if ( v15 != nullptr )
                  {
                    m_szTargetEntity = v10->m_szTargetEntity;
                    if ( CEntityConnection::ValidateTarget(
                           pEntityList: &v15->m_pWorld->m_EntityList,
                           bVisibilityCheck,
                           pszTarget: m_szTargetEntity) == 1
                      && CEntityConnection::ValidateInput(
                           pszTarget: m_szTargetEntity,
                           pszInput: pConnection->m_szInput,
                           bVisiblesOnly: true,
                           pDoc: v16) == 1 )
                    {
                      goto LABEL_31;
                    }
                    v10 = pConnection;
                  }
                }
              }
              else if ( CEntityConnection::ValidateTarget(
                          pEntityList: pAllWorldEntities,
                          bVisibilityCheck,
                          pszTarget: v10->m_szTargetEntity) == 1
                     && CEntityConnection::ValidateInput(
                          pszTarget: v10->m_szTargetEntity,
                          pszInput: v10->m_szInput,
                          bVisiblesOnly: true,
                          pDoc: nullptr) == 1 )
              {
                goto LABEL_31;
              }
            }
            m_pMemory = (int)BadConnectionList[1].m_pMemory;
            m_nAllocationCount = BadConnectionList->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CVisGroup *,int>::Grow(this: BadConnectionList, num: m_pMemory - m_nAllocationCount + 1);
            ++BadConnectionList[1].m_pMemory;
            v20 = (CEntityConnection **)BadConnectionList->m_pMemory;
            v21 = (int)BadConnectionList[1].m_pMemory - m_pMemory - 1;
            BadConnectionList[1].m_nAllocationCount = (int)BadConnectionList->m_pMemory;
            if ( v21 > 0 )
              _V_memmove(dest: &v20[m_pMemory + 1], src: &v20[m_pMemory], count: 4 * v21);
            v22 = (CEntityConnection **)&BadConnectionList->m_pMemory[m_pMemory];
            if ( v22 != nullptr )
              *v22 = v10;
          }
LABEL_31:
          v9 = i + 1;
          i = v9;
          if ( v9 >= v23 )
            return;
          v6 = pEntity;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100315E0
// Name: public: static int CEntityConnection::ValidateOutputConnections(class CMapEntity __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CEntityConnection::ValidateOutputConnections(
        CMapEntity *pEntity,
        bool bVisibilityCheck,
        bool bIgnoreHiddenTargets,
        bool CheckAllDocuments)
{
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > BadConnectionList; // [esp+4h] [ebp-20h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  if ( pEntity == nullptr || pEntity->m_Connections.m_Size == 0 )
    return 0;
  memset(&BadConnectionList, 0, sizeof(BadConnectionList));
  v6 = 1;
  CEntityConnection::FindBadConnections(
    pEntity,
    bVisibilityCheck,
    (CUtlMemory<CCullTreeNode *,int> *)&BadConnectionList,
    bIgnoreHiddenTargets,
    CheckAllDocuments);
  v6 = -1;
  if ( BadConnectionList.m_Size <= 0 )
  {
    CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&BadConnectionList);
    return 1;
  }
  else
  {
    CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&BadConnectionList);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100316A0
// Name: public: CEntityConnection::CEntityConnection(void)
// Source: json
//------------------------------------------------------------------------------
CEntityConnection *__thiscall CEntityConnection::CEntityConnection(CEntityConnection *this)
{
  CUtlReferenceVector<CMapEntity> *v2; // eax
  CUtlReferenceVector<CMapEntity> *v3; // edi
  CUtlReferenceVector<CMapEntity> *v4; // eax
  CUtlReferenceVector<CMapEntity> *v5; // edi

  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x100u);
  memset(dst: (unsigned __int8 *)this->m_szTargetEntity, value: 0, count: sizeof(this->m_szTargetEntity));
  memset(dst: (unsigned __int8 *)this->m_szOutput, value: 0, count: sizeof(this->m_szOutput));
  memset(dst: (unsigned __int8 *)this->m_szInput, value: 0, count: sizeof(this->m_szInput));
  memset(dst: (unsigned __int8 *)this->m_szParam, value: 0, count: sizeof(this->m_szParam));
  v2 = (CUtlReferenceVector<CMapEntity> *)operator new(nSize: 0x14u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->m_Memory.m_pMemory = nullptr;
    v2->m_Memory.m_nBlocks = 0;
    *((_DWORD *)&v2->m_Memory + 2) = 0;
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v2,
      nGrowSize: 0,
      nInitSize: 0);
    v3->m_Size = 0;
    v3->m_pElements = nullptr;
  }
  else
  {
    v3 = nullptr;
  }
  this->m_pSourceEntityList = v3;
  v4 = (CUtlReferenceVector<CMapEntity> *)operator new(nSize: 0x14u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_Memory.m_pMemory = nullptr;
    v4->m_Memory.m_nBlocks = 0;
    *((_DWORD *)&v4->m_Memory + 2) = 0;
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v4,
      nGrowSize: 0,
      nInitSize: 0);
    v5->m_Size = 0;
    v5->m_pElements = nullptr;
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pTargetEntityList = v5;
  this->m_nTimesToFire = -1;
  this->m_fDelay = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100317D0
// Name: public: CEntityConnection::~CEntityConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityConnection::~CEntityConnection(CEntityConnection *this)
{
  CUtlReferenceVector<CMapEntity> *m_pSourceEntityList; // ecx
  CUtlReferenceVector<CMapEntity> *v3; // edi
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // ecx
  CUtlReferenceVector<CMapEntity> *v5; // edi

  m_pSourceEntityList = this->m_pSourceEntityList;
  if ( m_pSourceEntityList != nullptr )
  {
    CUtlReferenceVector<CMapEntity>::RemoveAll(this: m_pSourceEntityList);
    v3 = this->m_pSourceEntityList;
    if ( v3 != nullptr )
    {
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: v3);
      operator delete(p: v3);
    }
    this->m_pSourceEntityList = nullptr;
  }
  m_pTargetEntityList = this->m_pTargetEntityList;
  if ( m_pTargetEntityList != nullptr )
  {
    CUtlReferenceVector<CMapEntity>::RemoveAll(this: m_pTargetEntityList);
    v5 = this->m_pTargetEntityList;
    if ( v5 != nullptr )
    {
      CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::~CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>(this: v5);
      operator delete(p: v5);
    }
    this->m_pTargetEntityList = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031880
// Name: public: void CEntityConnection::SetTargetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityConnection::SetTargetName(CEntityConnection *this, const char *pszName)
{
  const char *v2; // eax

  v2 = pszName;
  if ( pszName == nullptr )
    v2 = "<<null>>";
  lstrcpynA(lpString1: this->m_szTargetEntity, lpString2: v2, iMaxLength: 256);
  CEntityConnection::LinkTargetEntities(this);
}

//------------------------------------------------------------------------------
// Address: 0x100318C0
// Name: public: class CEntityConnection __near & CEntityConnection::operator=(class CEntityConnection const __near &)
// Source: json
//------------------------------------------------------------------------------
CEntityConnection *__thiscall CEntityConnection::operator=(CEntityConnection *this, const CEntityConnection *Other)
{
  char *v2; // esi
  char *m_szTargetEntity; // eax
  char v4; // cl
  char *m_szOutput; // eax
  char v6; // cl
  char *m_szInput; // eax
  char v8; // cl
  char *m_szParam; // eax
  char v10; // cl

  v2 = strcpy(this->m_szSourceEntity, Other->m_szSourceEntity);
  m_szTargetEntity = Other->m_szTargetEntity;
  do
  {
    v4 = *m_szTargetEntity;
    m_szTargetEntity[v2 - (char *)Other] = *m_szTargetEntity;
    ++m_szTargetEntity;
  }
  while ( v4 != 0 );
  m_szOutput = Other->m_szOutput;
  do
  {
    v6 = *m_szOutput;
    m_szOutput[v2 - (char *)Other] = *m_szOutput;
    ++m_szOutput;
  }
  while ( v6 != 0 );
  m_szInput = Other->m_szInput;
  do
  {
    v8 = *m_szInput;
    m_szInput[v2 - (char *)Other] = *m_szInput;
    ++m_szInput;
  }
  while ( v8 != 0 );
  m_szParam = Other->m_szParam;
  do
  {
    v10 = *m_szParam;
    m_szParam[v2 - (char *)Other] = *m_szParam;
    ++m_szParam;
  }
  while ( v10 != 0 );
  *((float *)v2 + 322) = Other->m_fDelay;
  *((_DWORD *)v2 + 323) = Other->m_nTimesToFire;
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::operator=(
    this: *((CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > **)v2 + 64),
    other: Other->m_pSourceEntityList);
  CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int>>::operator=(
    this: *((CUtlVector<CUtlReference<CMapEntity>,CUtlBlockMemory<CUtlReference<CMapEntity>,int> > **)v2 + 193),
    other: Other->m_pTargetEntityList);
  return (CEntityConnection *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10031980
// Name: public: static void CEntityConnection::FixBadConnections(class CMapEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEntityConnection::FixBadConnections(CMapEntity *pEntity, bool bVisibilityCheck)
{
  int v2; // edi
  CEntityConnection *v3; // ebx
  CUtlReferenceVector<CMapEntity> *m_pTargetEntityList; // esi
  CMapEntity *m_pObject; // eax
  int m_nGrowSize; // esi
  CEntityConnection **m_pMemory; // eax
  CUtlVector<CEntityConnection *,CUtlMemory<CEntityConnection *,int> > BadConnectionList; // [esp+8h] [ebp-28h] BYREF
  CEditGameClass *v9; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int v11; // [esp+2Ch] [ebp-4h]

  v2 = 0;
  memset(&BadConnectionList, 0, sizeof(BadConnectionList));
  v11 = 1;
  CEntityConnection::FindBadConnections(
    pEntity,
    bVisibilityCheck,
    (CUtlMemory<CCullTreeNode *,int> *)&BadConnectionList,
    bIgnoreHiddenTargets: false,
    CheckAllDocuments: false);
  i = 0;
  if ( BadConnectionList.m_Size > 0 )
  {
    v9 = &pEntity->CEditGameClass;
    do
    {
      v3 = BadConnectionList.m_Memory.m_pMemory[i];
      CEditGameClass::Connections_Remove(this: v9, pConnection: v3);
      m_pTargetEntityList = v3->m_pTargetEntityList;
      if ( m_pTargetEntityList != nullptr )
      {
        if ( m_pTargetEntityList->m_Size > 0 )
        {
          do
          {
            m_pObject = m_pTargetEntityList->m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&m_pTargetEntityList->m_Memory
                                                                                         + 2) >> 27)][v2 & ((32 * *((_DWORD *)&m_pTargetEntityList->m_Memory + 2)) >> 5)].m_pObject;
            if ( m_pObject != nullptr )
              CEditGameClass::Upstream_Remove(this: &m_pObject->CEditGameClass, pConnection: v3);
            ++v2;
          }
          while ( v2 < m_pTargetEntityList->m_Size );
        }
        v2 = 0;
      }
      CEntityConnection::~CEntityConnection(this: v3);
      operator delete(p: v3);
      ++i;
    }
    while ( i < BadConnectionList.m_Size );
  }
  v11 = 2;
  m_nGrowSize = BadConnectionList.m_Memory.m_nGrowSize;
  m_pMemory = BadConnectionList.m_Memory.m_pMemory;
  BadConnectionList.m_Size = 0;
  if ( BadConnectionList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( BadConnectionList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: BadConnectionList.m_Memory.m_pMemory);
      BadConnectionList.m_Memory.m_pMemory = nullptr;
      m_pMemory = nullptr;
    }
    BadConnectionList.m_Memory.m_nAllocationCount = 0;
  }
  BadConnectionList.m_pElements = m_pMemory;
  v11 = -1;
  if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
    free(pMem: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10031AC0
// Name: public: CEntityConnection::CEntityConnection(class CEntityConnection const __near &)
// Source: json
//------------------------------------------------------------------------------
CEntityConnection *__thiscall CEntityConnection::CEntityConnection(
        CEntityConnection *this,
        const CEntityConnection *Other)
{
  CUtlReferenceVector<CMapEntity> *v3; // eax
  CUtlReferenceVector<CMapEntity> *v4; // esi
  CUtlReferenceVector<CMapEntity> *v5; // eax
  CUtlReferenceVector<CMapEntity> *v6; // esi

  v3 = (CUtlReferenceVector<CMapEntity> *)operator new(nSize: 0x14u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3->m_Memory.m_pMemory = nullptr;
    v3->m_Memory.m_nBlocks = 0;
    *((_DWORD *)&v3->m_Memory + 2) = 0;
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v3,
      nGrowSize: 0,
      nInitSize: 0);
    v4->m_Size = 0;
    v4->m_pElements = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pSourceEntityList = v4;
  v5 = (CUtlReferenceVector<CMapEntity> *)operator new(nSize: 0x14u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v5->m_Memory.m_pMemory = nullptr;
    v5->m_Memory.m_nBlocks = 0;
    *((_DWORD *)&v5->m_Memory + 2) = 0;
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
      this: (CUtlBlockMemory<CUtlReference<CMapClass>,int> *)v5,
      nGrowSize: 0,
      nInitSize: 0);
    v6->m_Size = 0;
    v6->m_pElements = nullptr;
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pTargetEntityList = v6;
  CEntityConnection::operator=(this, Other);
  return this;
}
