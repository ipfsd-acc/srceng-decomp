// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fgdlib/gamedata.cpp
// Functions: 15
// ============================================================

#include "fgdlib\gamedata.h"

//------------------------------------------------------------------------------
// Address: 0x101F2E60
// Name: void GDSetMessageFunc(void (*)(int,char const __near *,...))
// Source: json
//------------------------------------------------------------------------------
void __cdecl GDSetMessageFunc(void (*pFunc)(int, const char *, ...))
{
  g_pMsgFunc = pFunc;
}

//------------------------------------------------------------------------------
// Address: 0x101F2E70
// Name: bool GDError(class TokenReader __near &,char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char GDError(TokenReader *tr, char *error, ...)
{
  void (*v2)(int, const char *, ...); // eax
  const char *v3; // eax
  char szBuf[128]; // [esp+4h] [ebp-80h] BYREF
  va_list ap; // [esp+94h] [ebp+10h] BYREF

  va_start(ap, error);
  vsprintf(string: szBuf, format: error, ap);
  v2 = g_pMsgFunc;
  if ( g_pMsgFunc != nullptr )
  {
    v3 = TokenReader::Error(this: tr, error: szBuf);
    g_pMsgFunc(a1: 1, a2: v3);
    v2 = g_pMsgFunc;
  }
  if ( tr->m_nErrorCount < 5 )
    return 1;
  if ( v2 != nullptr )
    v2(a1: 1, a2: "   - too many errors; aborting.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F2EE0
// Name: DoGetToken
// Source: json
//------------------------------------------------------------------------------
char __usercall DoGetToken@<al>(
        char **ppszStore@<eax>,
        int nSize@<ecx>,
        trtoken_t ttexpecting@<edi>,
        TokenReader *tr,
        const char *pszExpecting)
{
  char *v6; // eax
  trtoken_t Token; // eax
  const char *v9; // esi
  const char *v10; // eax

  v6 = *ppszStore;
  if ( v6 != nullptr )
    Token = TokenReader::NextToken(this: tr, pszStore: v6, nSize);
  else
    Token = TokenReader::NextTokenDynamic(this: tr, ppszStore);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  v9 = *ppszStore;
  if ( Token == ttexpecting || ttexpecting == TOKENNONE || ttexpecting == STRING && Token == INTEGER )
  {
    if ( pszExpecting == nullptr || _V_stricmp(s1: v9, s2: pszExpecting) == 0 )
      return 1;
  }
  else if ( pszExpecting == nullptr )
  {
    switch ( ttexpecting )
    {
      case INTEGER:
        v10 = "integer";
        break;
      case STRING:
        v10 = "string";
        break;
      case IDENT:
        v10 = "identifier";
        break;
      default:
        v10 = "symbol";
        break;
    }
    GDError(tr, error: "expecting %s", v10);
    return 0;
  }
  GDError(tr, error: "expecting '%s', but found '%s'", pszExpecting, v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F2FB0
// Name: bool GDGetToken(class TokenReader __near &,char __near *,int,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetToken(TokenReader *tr, char *pszStore, int nSize, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( pszStore != nullptr )
    return DoGetToken(ppszStore: &pszStore, nSize, ttexpecting, tr, pszExpecting);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F2FE0
// Name: bool GDSkipToken(class TokenReader __near &,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDSkipToken(TokenReader *tr, trtoken_t ttexpecting, const char *pszExpecting)
{
  char szDiscardBuf[129]; // [esp+4h] [ebp-88h] BYREF
  char *pszDiscardBuf; // [esp+88h] [ebp-4h] BYREF

  pszDiscardBuf = szDiscardBuf;
  return DoGetToken(ppszStore: &pszDiscardBuf, nSize: 129, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x101F3020
// Name: bool GDGetTokenDynamic(class TokenReader __near &,char __near * __near *,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetTokenDynamic(TokenReader *tr, char **ppszStore, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( ppszStore == nullptr )
    return 0;
  *ppszStore = nullptr;
  return DoGetToken(ppszStore, nSize: -1, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x101F3050
// Name: private: bool GameData::ParseMapSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseMapSize(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  char *v4; // edi
  trtoken_t v5; // eax
  int v6; // edi
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  int v9; // eax
  int v10; // ecx
  GameData *v11; // edx
  trtoken_t v12; // eax
  char pszStore[132]; // [esp+8h] [ebp-10Ch] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-88h] BYREF
  char *s1; // [esp+10Ch] [ebp-8h]
  GameData *v16; // [esp+110h] [ebp-4h]

  v16 = this;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  v4 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v4);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
  {
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v6 = atoi(nptr: szToken);
  v7 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v7 != TOKENSTRINGTOOLONG )
  {
    if ( v7 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
      return 0;
    }
    v8 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( v8 != TOKENSTRINGTOOLONG )
    {
      if ( v8 != INTEGER )
      {
        GDError(tr, error: "expecting %s", "integer");
        return 0;
      }
      v9 = atoi(nptr: szToken);
      if ( v6 != v9 )
      {
        v10 = v6;
        if ( v6 >= v9 )
          v10 = v9;
        v11 = v16;
        v16->m_nMinMapCoord = v10;
        if ( v6 > v9 )
          v9 = v6;
        v11->m_nMaxMapCoord = v9;
      }
      v12 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v12 != TOKENSTRINGTOOLONG )
      {
        if ( v12 != OPERATOR || _V_stricmp(s1: pszStore, s2: ")") != 0 )
        {
          GDError(tr, error: "expecting '%s', but found '%s'", ")", pszStore);
          return 0;
        }
        return 1;
      }
    }
  }
  GDError(tr, error: "unterminated string or string too long");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F3280
// Name: private: bool GameData::ParseGridNav(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseGridNav(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  const char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  trtoken_t v9; // eax
  int v10; // ebx
  int v11; // edi
  GameData *v12; // eax
  int v13; // edx
  int v14; // ecx
  char pszStore[132]; // [esp+8h] [ebp-110h] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-8Ch] BYREF
  GameData *v17; // [esp+10Ch] [ebp-Ch]
  int nOffsetX; // [esp+110h] [ebp-8h]
  int nEdgeSize; // [esp+114h] [ebp-4h]

  v17 = this;
  nEdgeSize = (int)pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  v3 = (const char *)nEdgeSize;
  if ( Token != OPERATOR || _V_stricmp(s1: (const char *)nEdgeSize, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v3);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_8:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
    goto LABEL_10;
  nEdgeSize = atoi(nptr: szToken);
  v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v6 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
  {
LABEL_14:
    GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
    return 0;
  }
  v7 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v7 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v7 != INTEGER )
    goto LABEL_10;
  nOffsetX = atoi(nptr: szToken);
  v8 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v8 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v8 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    goto LABEL_14;
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v9 != INTEGER )
  {
LABEL_10:
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v10 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ",") == 0 )
    return 0;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
    return 0;
  v11 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
    return 0;
  v12 = v17;
  v13 = nEdgeSize;
  v14 = nOffsetX;
  v17->m_nGridNavOffsetY = v10;
  v12->m_nTraceHeight = v11;
  v12->m_bGridNavActive = true;
  v12->m_nGridNavEdgeSize = v13;
  v12->m_nGridNavOffsetX = v14;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F3650
// Name: public: void GameData::ClearData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::ClearData(GameData *this)
{
  int m_Size; // eax
  int v3; // esi
  GDclass **m_pMemory; // ecx
  GDclass *v5; // edi
  int nCount; // [esp+8h] [ebp-4h]

  m_Size = this->m_Classes.m_Size;
  v3 = 0;
  nCount = m_Size;
  if ( m_Size <= 0 )
  {
    this->m_Classes.m_Size = 0;
  }
  else
  {
    do
    {
      m_pMemory = this->m_Classes.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr )
      {
        GDclass::~GDclass(this: m_pMemory[v3]);
        operator delete(p: v5);
        m_Size = nCount;
      }
      ++v3;
    }
    while ( v3 < m_Size );
    this->m_Classes.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F36A0
// Name: public: class GDclass __near * GameData::ClassForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::ClassForName(GameData *this, const char *pszName, int *piIndex)
{
  int v3; // edi
  GDclass **i; // esi
  GDclass *result; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Classes.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  for ( i = this->m_Classes.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( strcmp((*i)->m_szName, pszName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  if ( piIndex != nullptr )
    *piIndex = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F39A0
// Name: public: bool GameData::LoadFGDMaterialExclusions(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDMaterialExclusions(GameData *this, TokenReader *tr)
{
  TokenReader *v2; // ebx
  trtoken_t Token; // eax
  char *v6; // edi
  trtoken_t v7; // eax
  int v8; // edi
  int v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  FGDMatExlcusions_s *m_pMemory; // ecx
  int v13; // eax
  int v14; // edi
  trtoken_t v15; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  char *s1; // [esp+90h] [ebp-4h]

  v2 = tr;
  s1 = szToken;
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr: v2, error: "unterminated string or string too long");
    return 0;
  }
  v6 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", v6);
    return 0;
  }
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
  {
    do
    {
      s1 = szToken;
      v7 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 128);
      if ( v7 == TOKENSTRINGTOOLONG )
      {
        GDError(tr: v2, error: "unterminated string or string too long");
      }
      else if ( v7 == STRING || v7 == INTEGER )
      {
        v8 = 0;
        if ( this->m_FGDMaterialExclusions.m_Size <= 0 )
        {
LABEL_18:
          m_Size = this->m_FGDMaterialExclusions.m_Size;
          m_nAllocationCount = this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<FGDMatExlcusions_s,int>::Grow(
              this: &this->m_FGDMaterialExclusions.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_FGDMaterialExclusions.m_Size;
          m_pMemory = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          v13 = this->m_FGDMaterialExclusions.m_Size - m_Size - 1;
          this->m_FGDMaterialExclusions.m_pElements = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 261 * v13);
          v14 = m_Size;
          V_strncpy(
            pDest: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].szDirectory,
            pSrc: szToken,
            maxLen: 260);
          this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].bUserGenerated = false;
        }
        else
        {
          v9 = 0;
          while ( _V_stricmp(s1: szToken, s2: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v9].szDirectory) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->m_FGDMaterialExclusions.m_Size )
            {
              v2 = tr;
              goto LABEL_18;
            }
          }
          v2 = tr;
        }
      }
      else
      {
        GDError(tr: v2, error: "expecting %s", "string");
      }
    }
    while ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 128) != OPERATOR );
  }
  v15 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 129);
  if ( v15 == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  if ( v15 != OPERATOR || _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    GDError(tr: v2, error: "expecting '%s', but found '%s'", "]", szToken);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F3E60
// Name: public: bool GameData::LoadFGDAutoVisGroups(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDAutoVisGroups(GameData *this, TokenReader *tr)
{
  GameData *v3; // edi
  trtoken_t Token; // eax
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char *v8; // esi
  trtoken_t v9; // eax
  trtoken_t v10; // eax
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v12; // esi
  int m_Size; // edx
  int v14; // edi
  trtoken_t v15; // eax
  trtoken_t v16; // eax
  CUtlMemory<CCullTreeNode *,int> *v17; // esi
  CCullTreeNode **v18; // edi
  int m_nAllocationCount; // eax
  CCullTreeNode **v20; // ecx
  int v21; // eax
  char **v22; // eax
  trtoken_t v23; // eax
  trtoken_t v24; // eax
  char *v25; // [esp-Ch] [ebp-130h]
  char pszStore[132]; // [esp+Ch] [ebp-118h] BYREF
  char szToken[128]; // [esp+90h] [ebp-94h] BYREF
  char *v28; // [esp+110h] [ebp-14h]
  int v29; // [esp+114h] [ebp-10h]
  int gindex; // [esp+118h] [ebp-Ch]
  GameData *v31; // [esp+11Ch] [ebp-8h]
  char *s1; // [esp+120h] [ebp-4h]
  char *tra; // [esp+12Ch] [ebp+8h]

  v3 = this;
  v31 = this;
  gindex = 0;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    goto LABEL_3;
  }
  v8 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "=") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "=", v8);
    goto LABEL_3;
  }
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v9 != STRING && v9 != INTEGER )
  {
LABEL_16:
    GDError(tr, error: "expecting %s", "string");
    return 0;
  }
  gindex = CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
             this: &v3->m_FGDAutoVisGroups,
             elem: v3->m_FGDAutoVisGroups.m_Size);
  V_strncpy(pDest: v3->m_FGDAutoVisGroups.m_Memory.m_pMemory[gindex].szParent, pSrc: szToken, maxLen: 260);
  v10 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v10 == TOKENSTRINGTOOLONG )
  {
LABEL_46:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v10 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", pszStore);
    return 0;
  }
  while ( 1 )
  {
LABEL_3:
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      if ( v5 != TOKENSTRINGTOOLONG )
        break;
      GDError(tr, error: "unterminated string or string too long");
LABEL_5:
      v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v6 == TOKENSTRINGTOOLONG )
        goto LABEL_46;
      if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
        goto LABEL_8;
    }
    if ( v5 != STRING && v5 != INTEGER )
    {
      GDError(tr, error: "expecting %s", "string");
      goto LABEL_5;
    }
    m_pMemory = v3->m_FGDAutoVisGroups.m_Memory.m_pMemory;
    v12 = 280 * gindex;
    m_Size = m_pMemory[gindex].m_Classes.m_Size;
    s1 = (char *)(280 * gindex);
    v14 = 280
        * CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
            this: (CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *)&m_pMemory[gindex].m_Classes,
            elem: m_Size);
    v25 = &(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                        + v12))->szClass[v14];
    v29 = v14;
    V_strncpy(pDest: v25, pSrc: szToken, maxLen: 260);
    v15 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v15 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    v28 = pszStore;
    if ( v15 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", "[", v28);
      return 0;
    }
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    {
      while ( 1 )
      {
        v16 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
        if ( v16 == TOKENSTRINGTOOLONG )
          goto LABEL_46;
        if ( v16 != STRING && v16 != INTEGER )
          goto LABEL_16;
        v17 = (CUtlMemory<CCullTreeNode *,int> *)((char *)&(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                                                                        + v12))->szEntities
                                                + v14);
        tra = (char *)operator new(nSize: strlen(szToken) + 1);
        _V_strcpy(dest: tra, src: szToken);
        v18 = v17[1].m_pMemory;
        m_nAllocationCount = v17->m_nAllocationCount;
        if ( (int)v18 + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(this: v17, num: (int)v18 - m_nAllocationCount + 1);
        ++v17[1].m_pMemory;
        v20 = v17->m_pMemory;
        v21 = (char *)v17[1].m_pMemory - (char *)v18 - 1;
        v17[1].m_nAllocationCount = (int)v17->m_pMemory;
        if ( v21 > 0 )
          _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
        v22 = (char **)&v17->m_pMemory[(_DWORD)v18];
        if ( v22 != nullptr )
          *v22 = tra;
        if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) == OPERATOR )
          break;
        v12 = (int)s1;
        v14 = v29;
      }
    }
    v23 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v23 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    if ( v23 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
      goto LABEL_8;
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != STRING )
      break;
    v3 = v31;
  }
  v24 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v24 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v24 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
  {
LABEL_8:
    GDError(tr, error: "expecting '%s', but found '%s'", "]", pszStore);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F4320
// Name: public: GameData::GameData(void)
// Source: json
//------------------------------------------------------------------------------
GameData *__thiscall GameData::GameData(GameData *this)
{
  this->m_FGDMaterialExclusions.m_Memory.m_pMemory = nullptr;
  this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount = 0;
  this->m_FGDMaterialExclusions.m_Memory.m_nGrowSize = 0;
  this->m_FGDMaterialExclusions.m_Size = 0;
  this->m_FGDMaterialExclusions.m_pElements = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_pMemory = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_nAllocationCount = 0;
  this->m_FGDAutoVisGroups.m_Memory.m_nGrowSize = 0;
  this->m_FGDAutoVisGroups.m_Size = 0;
  this->m_FGDAutoVisGroups.m_pElements = nullptr;
  this->m_Classes.m_Memory.m_pMemory = nullptr;
  this->m_Classes.m_Memory.m_nAllocationCount = 0;
  this->m_Classes.m_Memory.m_nGrowSize = 0;
  this->m_Classes.m_Size = 0;
  this->m_Classes.m_pElements = nullptr;
  this->m_NodeRemap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<DmeTime_t>::LessFunc;
  this->m_NodeRemap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_NodeRemap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_NodeRemap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_NodeRemap.m_Tree.m_Root = -1;
  this->m_NodeRemap.m_Tree.m_NumElements = 0;
  this->m_NodeRemap.m_Tree.m_FirstFree = -1;
  this->m_NodeRemap.m_Tree.m_LastAlloc.index = -1;
  this->m_NodeRemap.m_Tree.m_pElements = this->m_NodeRemap.m_Tree.m_Elements.m_pMemory;
  this->m_nMaxMapCoord = 0x2000;
  this->m_nMinMapCoord = -8192;
  this->m_InstanceClass = nullptr;
  this->m_bGridNavActive = false;
  this->m_nGridNavEdgeSize = 0;
  this->m_nGridNavOffsetX = 0;
  this->m_nGridNavOffsetY = 0;
  this->m_nTraceHeight = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F43D0
// Name: public: GameData::~GameData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::~GameData(GameData *this)
{
  GameData::ClearData(this);
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_NodeRemap.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Classes);
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(this: &this->m_FGDAutoVisGroups);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101F4400
// Name: public: int GameData::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameData::Load(GameData *this, const char *pszFilename)
{
  GameData *v2; // esi
  const char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char v7; // al
  GDclass *v8; // eax
  GDclass *v9; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v12; // edi
  GDclass **m_pMemory; // ecx
  int v14; // eax
  GDclass **v15; // edi
  int v16; // edi
  int v17; // eax
  GDclass **v18; // ecx
  int v19; // eax
  GDclass **v20; // edi
  char justPath[260]; // [esp+8h] [ebp-3E0h] BYREF
  char loadFilename[260]; // [esp+10Ch] [ebp-2DCh] BYREF
  TokenReader tr; // [esp+210h] [ebp-1D8h] BYREF
  char szToken[128]; // [esp+360h] [ebp-88h] BYREF
  GameData *v25; // [esp+3E0h] [ebp-8h]
  int nExistingClassIndex; // [esp+3E4h] [ebp-4h] BYREF

  v2 = this;
  v25 = this;
  TokenReader::TokenReader(this: &tr);
  v3 = pszFilename;
  if ( GetFileAttributesA(lpFileName: pszFilename) == -1 || !TokenReader::Open(this: &tr, pszFilename) )
  {
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  if ( tr.m_nErrorCount < 5 )
  {
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
      if ( v5 == TOKENEOF )
        break;
      if ( (v5 != OPERATOR || _V_stricmp(s1: szToken, s2: "@") != 0) && GDError(&tr, error: "expected @") == 0
        || TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128) != IDENT
        && GDError(&tr, error: "expected identifier after @") == 0 )
      {
        goto LABEL_83;
      }
      if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0
        && _V_stricmp(s1: szToken, s2: "pointclass") != 0
        && _V_stricmp(s1: szToken, s2: "solidclass") != 0
        && _V_stricmp(s1: szToken, s2: "keyframeclass") != 0
        && _V_stricmp(s1: szToken, s2: "moveclass") != 0
        && _V_stricmp(s1: szToken, s2: "npcclass") != 0
        && _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
      {
        if ( _V_stricmp(s1: szToken, s2: "include") != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "mapsize") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "gridnav") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "materialexclusion") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "autovisgroup") != 0 )
                {
                  GDError(&tr, error: "unrecognized section name %s", szToken);
                  TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
                  goto LABEL_80;
                }
                v7 = GameData::LoadFGDAutoVisGroups(this: v2, &tr);
              }
              else
              {
                v7 = GameData::LoadFGDMaterialExclusions(this: v2, &tr);
              }
            }
            else
            {
              v7 = GameData::ParseGridNav(this: v2, &tr);
            }
          }
          else
          {
            v7 = GameData::ParseMapSize(this: v2, &tr);
          }
          if ( v7 == 0 )
            TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
        }
        else
        {
          nExistingClassIndex = (int)szToken;
          v6 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
          if ( v6 == TOKENSTRINGTOOLONG )
          {
            GDError(&tr, error: "unterminated string or string too long");
          }
          else if ( v6 == STRING || v6 == INTEGER )
          {
            if ( V_ExtractFilePath(path: v3, dest: justPath, destSize: 260) )
              V_snprintf(pDest: loadFilename, maxLen: 260, pFormat: "%s%s", justPath, szToken);
            else
              V_strncpy(pDest: loadFilename, pSrc: szToken, maxLen: 260);
            if ( GameData::Load(this: v2, pszFilename: loadFilename) == 0
              && GameData::Load(this: v2, pszFilename: szToken) == 0 )
            {
              GDError(&tr, error: "error including file: %s", szToken);
            }
          }
          else
          {
            GDError(&tr, error: "expecting %s", "string");
          }
        }
      }
      else
      {
        v8 = (GDclass *)operator new(nSize: 0x2D8u);
        if ( v8 != nullptr )
          v9 = GDclass::GDclass(this: v8);
        else
          v9 = nullptr;
        if ( GDclass::InitFromTokens(this: v9, &tr, pGD: v2) )
        {
          if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "pointclass") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "solidclass") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "npcclass") != 0 )
                {
                  if ( _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
                  {
                    if ( _V_stricmp(s1: szToken, s2: "moveclass") != 0 )
                    {
                      if ( _V_stricmp(s1: szToken, s2: "keyframeclass") == 0 )
                        *(_WORD *)&v9->m_bKeyFrame = 257;
                    }
                    else
                    {
                      v9->m_bMove = true;
                      v9->m_bPoint = true;
                    }
                  }
                  else
                  {
                    v9->m_bPoint = true;
                    v9->m_bFilter = true;
                  }
                }
                else
                {
                  *(_WORD *)&v9->m_bPoint = 257;
                }
              }
              else
              {
                v9->m_bSolid = true;
              }
            }
            else
            {
              v9->m_bPoint = true;
            }
          }
          else
          {
            v9->m_bBase = true;
          }
          nExistingClassIndex = 0;
          if ( GameData::ClassForName(this: v2, pszName: v9->m_szName, piIndex: &nExistingClassIndex) != nullptr )
          {
            m_Size = v2->m_Classes.m_Size;
            m_nAllocationCount = v2->m_Classes.m_Memory.m_nAllocationCount;
            v12 = nExistingClassIndex + 1;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Classes,
                num: m_Size - m_nAllocationCount + 1);
            ++v2->m_Classes.m_Size;
            m_pMemory = v2->m_Classes.m_Memory.m_pMemory;
            v14 = v2->m_Classes.m_Size - v12 - 1;
            v2->m_Classes.m_pElements = m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
            v15 = &v2->m_Classes.m_Memory.m_pMemory[v12];
            if ( v15 != nullptr )
              *v15 = v9;
            if ( v2->m_Classes.m_Size - nExistingClassIndex - 1 > 0 )
              _V_memmove(
                dest: &v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex],
                src: &v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex + 1],
                count: 4 * (v2->m_Classes.m_Size - nExistingClassIndex - 1));
            --v2->m_Classes.m_Size;
          }
          else
          {
            v16 = v2->m_Classes.m_Size;
            v17 = v2->m_Classes.m_Memory.m_nAllocationCount;
            if ( v16 + 1 > v17 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Classes,
                num: v16 - v17 + 1);
            ++v2->m_Classes.m_Size;
            v18 = v2->m_Classes.m_Memory.m_pMemory;
            v19 = v2->m_Classes.m_Size - v16 - 1;
            v2->m_Classes.m_pElements = v18;
            if ( v19 > 0 )
              _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
            v20 = &v2->m_Classes.m_Memory.m_pMemory[v16];
            if ( v20 != nullptr )
              *v20 = v9;
          }
          v2 = v25;
        }
        else
        {
          TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
          if ( v9 != nullptr )
          {
            GDclass::~GDclass(this: v9);
            operator delete(p: v9);
          }
        }
      }
LABEL_80:
      if ( tr.m_nErrorCount >= 5 )
        break;
      v3 = pszFilename;
    }
  }
  if ( tr.m_nErrorCount > 0 )
  {
LABEL_83:
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  else
  {
    TokenReader::Close(this: &tr);
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 1;
  }
}

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100F5730
// Name: bool GDError(class TokenReader __near &,char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char GDError(TokenReader *tr, char *error, ...)
{
  void (*v2)(int, const char *, ...); // eax
  char *v3; // eax
  char szBuf[128]; // [esp+4h] [ebp-80h] BYREF
  va_list ap; // [esp+94h] [ebp+10h] BYREF

  va_start(ap, error);
  vsprintf(string: szBuf, format: error, ap);
  v2 = g_pMsgFunc;
  if ( g_pMsgFunc != nullptr )
  {
    v3 = TokenReader::Error(this: tr, error: szBuf);
    g_pMsgFunc(a1: 1, a2: v3);
    v2 = g_pMsgFunc;
  }
  if ( tr->m_nErrorCount < 5 )
    return 1;
  if ( v2 != nullptr )
    v2(a1: 1, a2: "   - too many errors; aborting.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F57A0
// Name: public: void GameData::BeginInstancing(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::BeginInstancing(GameData *this, int nPass)
{
  this->m_nRemapStage = nPass;
  if ( nPass == 2 )
    this->m_nNextNodeID = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F57E0
// Name: public: bool GameData::RemapNameField(char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GameData::RemapNameField(
        GameData *this,
        const char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  char *v4; // ebx
  char v5; // al

  v4 = strcpy(pszOutValue, pszInValue);
  v5 = *pszInValue;
  if ( *pszInValue != 0 && v5 != 64 && v5 != 33 )
  {
    if ( NameFixup != NAME_FIXUP_PREFIX )
    {
      if ( NameFixup == NAME_FIXUP_POSTFIX )
        sprintf(string: v4, format: "%s-%s", pszInValue, this->m_InstancePrefix);
    }
    else
    {
      sprintf(string: v4, format: "%s-%s", this->m_InstancePrefix, pszInValue);
    }
  }
  return _V_stricmp(s1: pszInValue, s2: v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F5850
// Name: public: bool GameData::RemapInstanceField(char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GameData::RemapInstanceField(
        GameData *this,
        char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  char *v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char v8; // cl
  const char *v9; // esi
  char *v10; // eax

  v4 = strcpy(pszOutValue, pszInValue);
  strchr(string: pszInValue, chr: 0x20u);
  v6 = v5;
  strchr(string: v4, chr: 0x20u);
  if ( v6 != 0 && v7 != 0 )
  {
    v8 = *(_BYTE *)(v6 + 1);
    v9 = (const char *)(v6 + 1);
    v10 = (char *)(v7 + 1);
    if ( v8 != 0 && v8 != 64 && v8 != 33 && v8 != 45 && v8 != 46 && (v8 < 48 || v8 > 57) )
    {
      if ( NameFixup != NAME_FIXUP_PREFIX )
      {
        if ( NameFixup == NAME_FIXUP_POSTFIX )
          sprintf(string: v10, format: "%s-%s", v9, this->m_InstancePrefix);
      }
      else
      {
        sprintf(string: v10, format: "%s-%s", this->m_InstancePrefix, v9);
      }
    }
  }
  return _V_stricmp(s1: pszInValue, s2: v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F5900
// Name: DoGetToken
// Source: json
//------------------------------------------------------------------------------
char __usercall DoGetToken@<al>(
        char **ppszStore@<eax>,
        int nSize@<ecx>,
        trtoken_t ttexpecting@<edi>,
        TokenReader *tr,
        const char *pszExpecting)
{
  char *v6; // eax
  trtoken_t Token; // eax
  const char *v9; // esi
  const char *v10; // eax

  v6 = *ppszStore;
  if ( v6 != nullptr )
    Token = TokenReader::NextToken(this: tr, pszStore: v6, nSize);
  else
    Token = TokenReader::NextTokenDynamic(this: tr, ppszStore);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  v9 = *ppszStore;
  if ( Token == ttexpecting || ttexpecting == TOKENNONE || ttexpecting == STRING && Token == INTEGER )
  {
    if ( pszExpecting == nullptr || _V_stricmp(s1: v9, s2: pszExpecting) == 0 )
      return 1;
  }
  else if ( pszExpecting == nullptr )
  {
    switch ( ttexpecting )
    {
      case INTEGER:
        v10 = "integer";
        break;
      case STRING:
        v10 = "string";
        break;
      case IDENT:
        v10 = "identifier";
        break;
      default:
        v10 = "symbol";
        break;
    }
    GDError(tr, error: "expecting %s", v10);
    return 0;
  }
  GDError(tr, error: "expecting '%s', but found '%s'", pszExpecting, v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F59D0
// Name: bool GDGetToken(class TokenReader __near &,char __near *,int,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetToken(TokenReader *tr, char *pszStore, int nSize, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( pszStore != nullptr )
    return DoGetToken(ppszStore: &pszStore, nSize, ttexpecting, tr, pszExpecting);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F5A00
// Name: bool GDSkipToken(class TokenReader __near &,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDSkipToken(TokenReader *tr, trtoken_t ttexpecting, const char *pszExpecting)
{
  char szDiscardBuf[129]; // [esp+4h] [ebp-88h] BYREF
  char *pszDiscardBuf; // [esp+88h] [ebp-4h] BYREF

  pszDiscardBuf = szDiscardBuf;
  return DoGetToken(ppszStore: &pszDiscardBuf, nSize: 129, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x100F5A40
// Name: bool GDGetTokenDynamic(class TokenReader __near &,char __near * __near *,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetTokenDynamic(TokenReader *tr, char **ppszStore, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( ppszStore == nullptr )
    return 0;
  *ppszStore = nullptr;
  return DoGetToken(ppszStore, nSize: -1, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x100F5A70
// Name: private: bool GameData::ParseMapSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseMapSize(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  char *v4; // edi
  trtoken_t v5; // eax
  int v6; // edi
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  int v9; // eax
  int v10; // ecx
  GameData *v11; // edx
  trtoken_t v12; // eax
  char pszStore[132]; // [esp+8h] [ebp-10Ch] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-88h] BYREF
  char *s1; // [esp+10Ch] [ebp-8h]
  GameData *v16; // [esp+110h] [ebp-4h]

  v16 = this;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  v4 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v4);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
  {
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v6 = atoi(nptr: szToken);
  v7 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v7 != TOKENSTRINGTOOLONG )
  {
    if ( v7 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
      return 0;
    }
    v8 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( v8 != TOKENSTRINGTOOLONG )
    {
      if ( v8 != INTEGER )
      {
        GDError(tr, error: "expecting %s", "integer");
        return 0;
      }
      v9 = atoi(nptr: szToken);
      if ( v6 != v9 )
      {
        v10 = v6;
        if ( v6 >= v9 )
          v10 = v9;
        v11 = v16;
        v16->m_nMinMapCoord = v10;
        if ( v6 > v9 )
          v9 = v6;
        v11->m_nMaxMapCoord = v9;
      }
      v12 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v12 != TOKENSTRINGTOOLONG )
      {
        if ( v12 != OPERATOR || _V_stricmp(s1: pszStore, s2: ")") != 0 )
        {
          GDError(tr, error: "expecting '%s', but found '%s'", ")", pszStore);
          return 0;
        }
        return 1;
      }
    }
  }
  GDError(tr, error: "unterminated string or string too long");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F5CA0
// Name: private: bool GameData::ParseGridNav(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseGridNav(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  const char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  trtoken_t v9; // eax
  int v10; // ebx
  int v11; // edi
  GameData *v12; // eax
  int v13; // edx
  int v14; // ecx
  char pszStore[132]; // [esp+8h] [ebp-110h] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-8Ch] BYREF
  GameData *v17; // [esp+10Ch] [ebp-Ch]
  int nOffsetX; // [esp+110h] [ebp-8h]
  int nEdgeSize; // [esp+114h] [ebp-4h]

  v17 = this;
  nEdgeSize = (int)pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  v3 = (const char *)nEdgeSize;
  if ( Token != OPERATOR || _V_stricmp(s1: (const char *)nEdgeSize, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v3);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_8:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
    goto LABEL_10;
  nEdgeSize = atoi(nptr: szToken);
  v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v6 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
  {
LABEL_14:
    GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
    return 0;
  }
  v7 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v7 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v7 != INTEGER )
    goto LABEL_10;
  nOffsetX = atoi(nptr: szToken);
  v8 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v8 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v8 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    goto LABEL_14;
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v9 != INTEGER )
  {
LABEL_10:
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v10 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ",") == 0 )
    return 0;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
    return 0;
  v11 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
    return 0;
  v12 = v17;
  v13 = nEdgeSize;
  v14 = nOffsetX;
  v17->m_nGridNavOffsetY = v10;
  v12->m_nTraceHeight = v11;
  v12->m_bGridNavActive = true;
  v12->m_nGridNavEdgeSize = v13;
  v12->m_nGridNavOffsetX = v14;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F6130
// Name: public: void GameData::ClearData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::ClearData(GameData *this)
{
  int m_Size; // eax
  int v3; // esi
  GDclass **m_pMemory; // ecx
  GDclass *v5; // edi
  int nCount; // [esp+8h] [ebp-4h]

  m_Size = this->m_Classes.m_Size;
  v3 = 0;
  nCount = m_Size;
  if ( m_Size <= 0 )
  {
    this->m_Classes.m_Size = 0;
  }
  else
  {
    do
    {
      m_pMemory = this->m_Classes.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr )
      {
        GDclass::~GDclass(this: m_pMemory[v3]);
        free(pMem: v5);
        m_Size = nCount;
      }
      ++v3;
    }
    while ( v3 < m_Size );
    this->m_Classes.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6180
// Name: public: class GDclass __near * GameData::ClassForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::ClassForName(GameData *this, const char *pszName, int *piIndex)
{
  int v3; // edi
  GDclass **i; // esi
  GDclass *result; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Classes.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  for ( i = this->m_Classes.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( strcmp((*i)->m_szName, pszName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  if ( piIndex != nullptr )
    *piIndex = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F61F0
// Name: public: class GDclass __near * GameData::BeginInstanceRemap(char const __near *,char const __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::BeginInstanceRemap(
        GameData *this,
        const char *pszClassName,
        const char *pszInstancePrefix,
        Vector *Origin,
        QAngle *Angle)
{
  const char *v6; // eax
  char v7; // cl
  GDclass *m_InstanceClass; // edi
  int v9; // ebx
  const char *v10; // edi
  GDclass *v11; // edi
  GDclass *v12; // eax
  GDclass *v13; // eax
  const char **v14; // edi
  GDclass *v15; // eax

  this->m_InstanceOrigin = *Origin;
  this->m_InstanceAngle = *Angle;
  AngleMatrix(angles: &this->m_InstanceAngle, position: &this->m_InstanceOrigin, matrix: &this->m_InstanceMat);
  v6 = pszInstancePrefix;
  do
  {
    v7 = *v6;
    v6[(char *)this - pszInstancePrefix + 164] = *v6;
    ++v6;
  }
  while ( v7 != 0 );
  m_InstanceClass = this->m_InstanceClass;
  v9 = 0;
  if ( m_InstanceClass != nullptr )
  {
    GDclass::~GDclass(this: this->m_InstanceClass);
    free(pMem: m_InstanceClass);
    this->m_InstanceClass = nullptr;
  }
  v10 = pszClassName;
  if ( _V_stricmp(s1: pszClassName, s2: "info_overlay_accessor") == 0 )
    v10 = "info_overlay";
  v11 = GameData::ClassForName(this, pszName: v10, piIndex: nullptr);
  if ( v11 != nullptr )
  {
    v12 = (GDclass *)operator new(nSize: 0x2D8u);
    if ( v12 != nullptr )
      v13 = GDclass::GDclass(this: v12);
    else
      v13 = nullptr;
    this->m_InstanceClass = v13;
    v13->Parent = this;
    GDclass::AddBase(this: this->m_InstanceClass, pBase: v11);
    if ( RequiredKeys[0] != nullptr )
    {
      v14 = RequiredKeys;
      do
      {
        if ( GDclass::VarForName(this: this->m_InstanceClass, pszName: *v14, piIndex: nullptr) == nullptr )
        {
          v15 = GameData::ClassForName(this, pszName: *v14, piIndex: nullptr);
          if ( v15 != nullptr )
            GDclass::AddBase(this: this->m_InstanceClass, pBase: v15);
        }
        v14 = &RequiredKeys[++v9];
      }
      while ( *v14 != nullptr );
    }
    return this->m_InstanceClass;
  }
  else
  {
    this->m_InstanceClass = nullptr;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7B10
// Name: public: bool CUtlMap<int,int,unsigned short>::IsValidIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMap<int,int,unsigned short>::IsValidIndex(
        CUtlMap<int,int,unsigned short> *this,
        unsigned __int16 i)
{
  return i < this->m_Tree.m_Elements.m_nAllocationCount
      && i <= this->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &this->m_Tree,
           i) != i;
}

//------------------------------------------------------------------------------
// Address: 0x100F7C40
// Name: public: void GameData::BeginMapInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::BeginMapInstance(GameData *this)
{
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NodeRemap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100F7C50
// Name: public: bool GameData::LoadFGDMaterialExclusions(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDMaterialExclusions(GameData *this, TokenReader *tr)
{
  TokenReader *v2; // ebx
  trtoken_t Token; // eax
  char *v6; // edi
  trtoken_t v7; // eax
  int v8; // edi
  int v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  FGDMatExlcusions_s *m_pMemory; // ecx
  int v13; // eax
  int v14; // edi
  trtoken_t v15; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  char *s1; // [esp+90h] [ebp-4h]

  v2 = tr;
  s1 = szToken;
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr: v2, error: "unterminated string or string too long");
    return 0;
  }
  v6 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", v6);
    return 0;
  }
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
  {
    do
    {
      s1 = szToken;
      v7 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 128);
      if ( v7 == TOKENSTRINGTOOLONG )
      {
        GDError(tr: v2, error: "unterminated string or string too long");
      }
      else if ( v7 == STRING || v7 == INTEGER )
      {
        v8 = 0;
        if ( this->m_FGDMaterialExclusions.m_Size <= 0 )
        {
LABEL_18:
          m_Size = this->m_FGDMaterialExclusions.m_Size;
          m_nAllocationCount = this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<FGDMatExlcusions_s,int>::Grow(
              this: &this->m_FGDMaterialExclusions.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_FGDMaterialExclusions.m_Size;
          m_pMemory = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          v13 = this->m_FGDMaterialExclusions.m_Size - m_Size - 1;
          this->m_FGDMaterialExclusions.m_pElements = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
              src: (unsigned __int8 *)&m_pMemory[m_Size],
              count: 261 * v13);
          v14 = m_Size;
          V_strncpy(
            pDest: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].szDirectory,
            pSrc: szToken,
            maxLen: 260);
          this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].bUserGenerated = false;
        }
        else
        {
          v9 = 0;
          while ( _V_stricmp(s1: szToken, s2: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v9].szDirectory) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->m_FGDMaterialExclusions.m_Size )
            {
              v2 = tr;
              goto LABEL_18;
            }
          }
          v2 = tr;
        }
      }
      else
      {
        GDError(tr: v2, error: "expecting %s", "string");
      }
    }
    while ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 128) != OPERATOR );
  }
  v15 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 129);
  if ( v15 == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  if ( v15 != OPERATOR || _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    GDError(tr: v2, error: "expecting '%s', but found '%s'", "]", szToken);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F80B0
// Name: public: bool GameData::RemapKeyValue(char const __near *,char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GameData::RemapKeyValue(GameData *this, const char *pszKey, char *pszInValue, __int64 pszOutValue)
{
  GameData *v4; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v9; // eax
  int v10; // edx
  float *p_m_Data; // esi
  unsigned __int16 v12; // cx
  int v13; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v14; // eax
  unsigned __int16 v15; // dx
  int v16; // edx
  float *v17; // esi
  unsigned __int16 v18; // cx
  int v19; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v20; // eax
  unsigned __int16 v21; // dx
  int v22; // edx
  float *v23; // esi
  unsigned __int16 v24; // cx
  int v25; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v26; // eax
  unsigned __int16 v27; // dx
  int v28; // edx
  float *v29; // esi
  unsigned __int16 v30; // cx
  int v31; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v32; // eax
  unsigned __int16 v33; // dx
  int v34; // edx
  float *v35; // esi
  unsigned __int16 v36; // cx
  int v37; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v38; // eax
  unsigned __int16 v39; // dx
  int v40; // edx
  float *v41; // esi
  unsigned __int16 v42; // cx
  int v43; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v44; // eax
  unsigned __int16 v45; // dx
  int v46; // edx
  float *v47; // esi
  unsigned __int16 v48; // cx
  int v49; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v50; // eax
  unsigned __int16 v51; // dx
  int v52; // edx
  float *v53; // esi
  unsigned __int16 v54; // cx
  int v55; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v56; // eax
  unsigned __int16 v57; // dx
  int v58; // edx
  float *v59; // esi
  unsigned __int16 v60; // cx
  int v61; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v62; // eax
  unsigned __int16 v63; // dx
  int v64; // edx
  float *v65; // esi
  unsigned __int16 v66; // cx
  int v67; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v68; // eax
  unsigned __int16 v69; // dx
  int v70; // edx
  float *v71; // esi
  unsigned __int16 v72; // cx
  int v73; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v74; // eax
  unsigned __int16 v75; // dx
  int v76; // edx
  float *v77; // esi
  GDclass *m_InstanceClass; // ecx
  GDinputvariable *v80; // eax
  const matrix3x4_t *p_m_InstanceMat; // esi
  const matrix3x4_t *v82; // esi
  unsigned __int16 v83; // ax
  int v84; // ebx
  float v85; // ebx
  matrix3x4_t out; // [esp+20h] [ebp-88h] BYREF
  matrix3x4_t matrix; // [esp+54h] [ebp-54h] BYREF
  float angles[3]; // [esp+84h] [ebp-24h] BYREF
  GameData *m_eType; // [esp+90h] [ebp-18h]
  QAngle v90; // [esp+94h] [ebp-14h] BYREF
  int v91; // [esp+A0h] [ebp-8h] BYREF
  bool v92; // [esp+A7h] [ebp-1h] BYREF
  int inAngles_4; // [esp+B0h] [ebp+8h]

  v4 = this;
  m_eType = this;
  if ( RemapOperation.m_Tree.m_NumElements == 0 )
  {
    if ( RemapOperation.m_Tree.m_LessFunc.m_LessFunc == nullptr )
      RemapOperation.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const GDIV_TYPE *, const GDIV_TYPE *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
    v90.y = 0.0;
    LODWORD(v90.z) = 2;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v5 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v6 = v91;
    v7 = v5;
    v8 = v5;
    v9 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v8];
    v9->m_Right = -1;
    v9->m_Left = -1;
    v9->m_Parent = v6;
    v9->m_Tag = 0;
    if ( v6 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v7;
    }
    else
    {
      v10 = v6;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v10].m_Left = v7;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v10].m_Right = v7;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v7);
    ++RemapOperation.m_Tree.m_NumElements;
    p_m_Data = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v8].m_Data;
    if ( p_m_Data != nullptr )
    {
      *p_m_Data = v90.y;
      p_m_Data[1] = v90.z;
    }
    LODWORD(v90.y) = 6;
    v90.z = 0.0;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v12 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v13 = v12;
    v14 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v12];
    v15 = v91;
    v14->m_Right = -1;
    v14->m_Left = -1;
    v14->m_Parent = v15;
    v14->m_Tag = 0;
    if ( v15 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v12;
    }
    else
    {
      v16 = v15;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v16].m_Left = v12;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v16].m_Right = v12;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v12);
    ++RemapOperation.m_Tree.m_NumElements;
    v17 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v13].m_Data;
    if ( v17 != nullptr )
    {
      *v17 = v90.y;
      v17[1] = v90.z;
    }
    LODWORD(v90.y) = 1;
    v90.z = 0.0;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v18 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v19 = v18;
    v20 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v18];
    v21 = v91;
    v20->m_Right = -1;
    v20->m_Left = -1;
    v20->m_Parent = v21;
    v20->m_Tag = 0;
    if ( v21 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v18;
    }
    else
    {
      v22 = v21;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v22].m_Left = v18;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v22].m_Right = v18;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v18);
    ++RemapOperation.m_Tree.m_NumElements;
    v23 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v19].m_Data;
    if ( v23 != nullptr )
    {
      *v23 = v90.y;
      v23[1] = v90.z;
    }
    LODWORD(v90.y) = 3;
    v90.z = 0.0;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v24 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v25 = v24;
    v26 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v24];
    v27 = v91;
    v26->m_Right = -1;
    v26->m_Left = -1;
    v26->m_Parent = v27;
    v26->m_Tag = 0;
    if ( v27 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v24;
    }
    else
    {
      v28 = v27;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v28].m_Left = v24;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v28].m_Right = v24;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v24);
    ++RemapOperation.m_Tree.m_NumElements;
    v29 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v25].m_Data;
    if ( v29 != nullptr )
    {
      *v29 = v90.y;
      v29[1] = v90.z;
    }
    LODWORD(v90.y) = 17;
    v90.z = 0.0;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v30 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v31 = v30;
    v32 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v30];
    v33 = v91;
    v32->m_Right = -1;
    v32->m_Left = -1;
    v32->m_Parent = v33;
    v32->m_Tag = 0;
    if ( v33 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v30;
    }
    else
    {
      v34 = v33;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v34].m_Left = v30;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v34].m_Right = v30;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v30);
    ++RemapOperation.m_Tree.m_NumElements;
    v35 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v31].m_Data;
    if ( v35 != nullptr )
    {
      *v35 = v90.y;
      v35[1] = v90.z;
    }
    LODWORD(v90.z) = 1;
    LODWORD(v90.y) = 23;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v36 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v37 = v36;
    v38 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v36];
    v39 = v91;
    v38->m_Right = -1;
    v38->m_Left = -1;
    v38->m_Parent = v39;
    v38->m_Tag = 0;
    if ( v39 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v36;
    }
    else
    {
      v40 = v39;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v40].m_Left = v36;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v40].m_Right = v36;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v36);
    ++RemapOperation.m_Tree.m_NumElements;
    v41 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v37].m_Data;
    if ( v41 != nullptr )
    {
      *v41 = v90.y;
      v41[1] = v90.z;
    }
    LODWORD(v90.z) = 1;
    LODWORD(v90.y) = 24;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v42 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v43 = v42;
    v44 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v42];
    v45 = v91;
    v44->m_Right = -1;
    v44->m_Left = -1;
    v44->m_Parent = v45;
    v44->m_Tag = 0;
    if ( v45 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v42;
    }
    else
    {
      v46 = v45;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v46].m_Left = v42;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v46].m_Right = v42;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v42);
    ++RemapOperation.m_Tree.m_NumElements;
    v47 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v43].m_Data;
    if ( v47 != nullptr )
    {
      *v47 = v90.y;
      v47[1] = v90.z;
    }
    LODWORD(v90.y) = 25;
    LODWORD(v90.z) = 2;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v48 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v49 = v48;
    v50 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v48];
    v51 = v91;
    v50->m_Right = -1;
    v50->m_Left = -1;
    v50->m_Parent = v51;
    v50->m_Tag = 0;
    if ( v51 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v48;
    }
    else
    {
      v52 = v51;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v52].m_Left = v48;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v52].m_Right = v48;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v48);
    ++RemapOperation.m_Tree.m_NumElements;
    v53 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v49].m_Data;
    if ( v53 != nullptr )
    {
      *v53 = v90.y;
      v53[1] = v90.z;
    }
    LODWORD(v90.y) = 32;
    LODWORD(v90.z) = 3;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v54 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v55 = v54;
    v56 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v54];
    v57 = v91;
    v56->m_Right = -1;
    v56->m_Left = -1;
    v56->m_Parent = v57;
    v56->m_Tag = 0;
    if ( v57 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v54;
    }
    else
    {
      v58 = v57;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v58].m_Left = v54;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v58].m_Right = v54;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v54);
    ++RemapOperation.m_Tree.m_NumElements;
    v59 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v55].m_Data;
    if ( v59 != nullptr )
    {
      *v59 = v90.y;
      v59[1] = v90.z;
    }
    LODWORD(v90.y) = 27;
    LODWORD(v90.z) = 4;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v60 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v61 = v60;
    v62 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v60];
    v63 = v91;
    v62->m_Right = -1;
    v62->m_Left = -1;
    v62->m_Parent = v63;
    v62->m_Tag = 0;
    if ( v63 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v60;
    }
    else
    {
      v64 = v63;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v64].m_Left = v60;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v64].m_Right = v60;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v60);
    ++RemapOperation.m_Tree.m_NumElements;
    v65 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v61].m_Data;
    if ( v65 != nullptr )
    {
      *v65 = v90.y;
      v65[1] = v90.z;
    }
    LODWORD(v90.y) = 36;
    LODWORD(v90.z) = 4;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v66 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v67 = v66;
    v68 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v66];
    v69 = v91;
    v68->m_Right = -1;
    v68->m_Left = -1;
    v68->m_Parent = v69;
    v68->m_Tag = 0;
    if ( v69 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v66;
    }
    else
    {
      v70 = v69;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v70].m_Left = v66;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v70].m_Right = v66;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v66);
    ++RemapOperation.m_Tree.m_NumElements;
    v71 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v67].m_Data;
    if ( v71 != nullptr )
    {
      *v71 = v90.y;
      v71[1] = v90.z;
    }
    LODWORD(v90.y) = 33;
    LODWORD(v90.z) = 5;
    v91 = 0xFFFF;
    v92 = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y,
      parent: (unsigned __int16 *)&v91,
      leftchild: &v92);
    v72 = CUtlRBTree<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short,CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ITilegenAction *,CLayoutSystem::ActionData_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v73 = v72;
    v74 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v72];
    v75 = v91;
    v74->m_Right = -1;
    v74->m_Left = -1;
    v74->m_Parent = v75;
    v74->m_Tag = 0;
    if ( v75 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v72;
    }
    else
    {
      v76 = v75;
      if ( v92 )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v76].m_Left = v72;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v76].m_Right = v72;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v72);
    ++RemapOperation.m_Tree.m_NumElements;
    v77 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v73].m_Data;
    if ( v77 != nullptr )
    {
      *v77 = v90.y;
      v77[1] = v90.z;
    }
    v4 = m_eType;
  }
  m_InstanceClass = v4->m_InstanceClass;
  if ( m_InstanceClass == nullptr )
    return false;
  v80 = GDclass::VarForName(this: m_InstanceClass, pszName: pszKey, piIndex: nullptr);
  if ( v80 == nullptr )
    return false;
  m_eType = (GameData *)v80->m_eType;
  LODWORD(v90.y) = m_eType;
  inAngles_4 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &RemapOperation.m_Tree,
                 search: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&v90.y);
  if ( inAngles_4 == 0xFFFF )
    return false;
  strcpy((char *)pszOutValue, pszInValue);
  switch ( RemapOperation.m_Tree.m_Elements.m_pMemory[(unsigned __int16)inAngles_4].m_Data.elem )
  {
    case REMAP_NAME:
      if ( v4->m_nRemapStage != 1 )
        return false;
      if ( m_eType != (GameData *)33 )
        GameData::RemapNameField(this: v4, pszInValue, (char *)pszOutValue, NameFixup: SHIDWORD(pszOutValue));
      break;
    case REMAP_POSITION:
      if ( v4->m_nRemapStage != 1 )
        return false;
      memset(&v90, 0, sizeof(v90));
      sscanf(string: pszInValue, format: "%f %f %f", &v90, &v90.y, &v90.z);
      VectorTransform(in1: &v90.x, in2: &v4->m_InstanceMat, out: angles);
      sprintf(string: (char *)pszOutValue, format: "%g %g %g", angles[0], angles[1], angles[2]);
      break;
    case REMAP_ANGLE:
      if ( v4->m_nRemapStage != 1 )
        return false;
      if ( v4->m_InstanceAngle.x != 0.0 || v4->m_InstanceAngle.y != 0.0 || v4->m_InstanceAngle.z != 0.0 )
      {
        memset(&v90, 0, sizeof(v90));
        sscanf(string: pszInValue, format: "%f %f %f", &v90, &v90.y, &v90.z);
        AngleMatrix(angles: &v90, &matrix);
        p_m_InstanceMat = &v4->m_InstanceMat;
        ConcatTransforms(in1: p_m_InstanceMat, in2: &matrix, out: (matrix3x4_t *)&out.m_flMatVal[0][1]);
        MatrixAngles(a1: (int)p_m_InstanceMat, matrix: (matrix3x4_t *)&out.m_flMatVal[0][1], angles);
        sprintf(string: (char *)pszOutValue, format: "%g %g %g", angles[0], angles[1], angles[2]);
      }
      break;
    case REMAP_ANGLE_NEGATIVE_PITCH:
      if ( v4->m_nRemapStage != 1 )
        return false;
      if ( v4->m_InstanceAngle.x != 0.0 || v4->m_InstanceAngle.y != 0.0 || v4->m_InstanceAngle.z != 0.0 )
      {
        memset(&v90, 0, sizeof(v90));
        sscanf(string: pszInValue, format: "%f", &v90);
        LODWORD(v90.x) ^= _mask__NegFloat_;
        AngleMatrix(angles: &v90, matrix: (matrix3x4_t *)&out.m_flMatVal[0][1]);
        v82 = &v4->m_InstanceMat;
        ConcatTransforms(in1: v82, in2: (matrix3x4_t *)&out.m_flMatVal[0][1], out: &matrix);
        MatrixAngles(a1: (int)v82, &matrix, angles);
        sprintf(string: (char *)pszOutValue, format: "%g", COERCE_FLOAT(LODWORD(angles[0]) ^ _mask__NegFloat_));
      }
      break;
    case REMAP_NODE:
      LODWORD(v90.y) = atoi(nptr: pszInValue);
      v83 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &v4->m_NodeRemap.m_Tree,
              search: (const CUtlMap<int,int,unsigned short>::Node_t *)&v90.y);
      v84 = v83;
      if ( CUtlMap<int,int,unsigned short>::IsValidIndex(this: &v4->m_NodeRemap, i: v83) )
      {
        v85 = *(float *)&v4->m_NodeRemap.m_Tree.m_Elements.m_pMemory[v84].m_Data.elem;
      }
      else
      {
        v85 = *(float *)&v4->m_nNextNodeID;
        v4->m_nNextNodeID = LODWORD(v85) + 1;
        LODWORD(v90.y) = atoi(nptr: pszInValue);
        v90.z = v85;
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &v4->m_NodeRemap.m_Tree,
          insert: (const CUtlMap<int,int,unsigned short>::Node_t *)&v90.y);
      }
      sprintf(string: (char *)pszOutValue, format: "%d", v85);
      break;
    case REMAP_INSTANCE_VARIABLE:
      if ( v4->m_nRemapStage != 1 )
        return false;
      GameData::RemapInstanceField(this: v4, pszInValue, (char *)pszOutValue, NameFixup: SHIDWORD(pszOutValue));
      break;
    default:
      return _V_stricmp(s1: pszInValue, s2: (const char *)pszOutValue) != 0;
  }
  return _V_stricmp(s1: pszInValue, s2: (const char *)pszOutValue) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F8DF0
// Name: public: bool GameData::LoadFGDAutoVisGroups(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDAutoVisGroups(GameData *this, TokenReader *tr)
{
  GameData *v3; // edi
  trtoken_t Token; // eax
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char *v8; // esi
  trtoken_t v9; // eax
  trtoken_t v10; // eax
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v12; // esi
  int m_Size; // edx
  int v14; // edi
  trtoken_t v15; // eax
  trtoken_t v16; // eax
  CUtlMemory<vgui::TreeNode *,int> *v17; // esi
  vgui::TreeNode **v18; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  char **v22; // eax
  trtoken_t v23; // eax
  trtoken_t v24; // eax
  char *v25; // [esp-Ch] [ebp-130h]
  char pszStore[132]; // [esp+Ch] [ebp-118h] BYREF
  char szToken[128]; // [esp+90h] [ebp-94h] BYREF
  char *v28; // [esp+110h] [ebp-14h]
  int v29; // [esp+114h] [ebp-10h]
  int gindex; // [esp+118h] [ebp-Ch]
  GameData *v31; // [esp+11Ch] [ebp-8h]
  char *s1; // [esp+120h] [ebp-4h]
  char *tra; // [esp+12Ch] [ebp+8h]

  v3 = this;
  v31 = this;
  gindex = 0;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    goto LABEL_3;
  }
  v8 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "=") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "=", v8);
    goto LABEL_3;
  }
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v9 != STRING && v9 != INTEGER )
  {
LABEL_16:
    GDError(tr, error: "expecting %s", "string");
    return 0;
  }
  gindex = CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
             this: &v3->m_FGDAutoVisGroups,
             elem: v3->m_FGDAutoVisGroups.m_Size);
  V_strncpy(pDest: v3->m_FGDAutoVisGroups.m_Memory.m_pMemory[gindex].szParent, pSrc: szToken, maxLen: 260);
  v10 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v10 == TOKENSTRINGTOOLONG )
  {
LABEL_46:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v10 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", pszStore);
    return 0;
  }
  while ( 1 )
  {
LABEL_3:
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      if ( v5 != TOKENSTRINGTOOLONG )
        break;
      GDError(tr, error: "unterminated string or string too long");
LABEL_5:
      v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v6 == TOKENSTRINGTOOLONG )
        goto LABEL_46;
      if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
        goto LABEL_8;
    }
    if ( v5 != STRING && v5 != INTEGER )
    {
      GDError(tr, error: "expecting %s", "string");
      goto LABEL_5;
    }
    m_pMemory = v3->m_FGDAutoVisGroups.m_Memory.m_pMemory;
    v12 = 280 * gindex;
    m_Size = m_pMemory[gindex].m_Classes.m_Size;
    s1 = (char *)(280 * gindex);
    v14 = 280
        * CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
            this: (CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *)&m_pMemory[gindex].m_Classes,
            elem: m_Size);
    v25 = &(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                        + v12))->szClass[v14];
    v29 = v14;
    V_strncpy(pDest: v25, pSrc: szToken, maxLen: 260);
    v15 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v15 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    v28 = pszStore;
    if ( v15 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", "[", v28);
      return 0;
    }
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    {
      while ( 1 )
      {
        v16 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
        if ( v16 == TOKENSTRINGTOOLONG )
          goto LABEL_46;
        if ( v16 != STRING && v16 != INTEGER )
          goto LABEL_16;
        v17 = (CUtlMemory<vgui::TreeNode *,int> *)((char *)&(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                                                                         + v12))->szEntities
                                                 + v14);
        tra = (char *)operator new(nSize: strlen(szToken) + 1);
        _V_strcpy(dest: tra, src: szToken);
        v18 = v17[1].m_pMemory;
        m_nAllocationCount = v17->m_nAllocationCount;
        if ( (int)v18 + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: v17,
            num: (int)v18 - m_nAllocationCount + 1);
        ++v17[1].m_pMemory;
        v20 = v17->m_pMemory;
        v21 = (char *)v17[1].m_pMemory - (char *)v18 - 1;
        v17[1].m_nAllocationCount = (int)v17->m_pMemory;
        if ( v21 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
            src: (unsigned __int8 *)&v20[(_DWORD)v18],
            count: 4 * v21);
        v22 = (char **)&v17->m_pMemory[(_DWORD)v18];
        if ( v22 != nullptr )
          *v22 = tra;
        if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) == OPERATOR )
          break;
        v12 = (int)s1;
        v14 = v29;
      }
    }
    v23 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v23 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    if ( v23 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
      goto LABEL_8;
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != STRING )
      break;
    v3 = v31;
  }
  v24 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v24 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v24 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
  {
LABEL_8:
    GDError(tr, error: "expecting '%s', but found '%s'", "]", pszStore);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F92B0
// Name: public: GameData::GameData(void)
// Source: json
//------------------------------------------------------------------------------
GameData *__thiscall GameData::GameData(GameData *this)
{
  this->m_FGDMaterialExclusions.m_Memory.m_pMemory = nullptr;
  this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount = 0;
  this->m_FGDMaterialExclusions.m_Memory.m_nGrowSize = 0;
  this->m_FGDMaterialExclusions.m_Size = 0;
  this->m_FGDMaterialExclusions.m_pElements = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_pMemory = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_nAllocationCount = 0;
  this->m_FGDAutoVisGroups.m_Memory.m_nGrowSize = 0;
  this->m_FGDAutoVisGroups.m_Size = 0;
  this->m_FGDAutoVisGroups.m_pElements = nullptr;
  this->m_Classes.m_Memory.m_pMemory = nullptr;
  this->m_Classes.m_Memory.m_nAllocationCount = 0;
  this->m_Classes.m_Memory.m_nGrowSize = 0;
  this->m_Classes.m_Size = 0;
  this->m_Classes.m_pElements = nullptr;
  this->m_NodeRemap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
  this->m_NodeRemap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_NodeRemap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_NodeRemap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_NodeRemap.m_Tree.m_Root = -1;
  this->m_NodeRemap.m_Tree.m_NumElements = 0;
  this->m_NodeRemap.m_Tree.m_FirstFree = -1;
  this->m_NodeRemap.m_Tree.m_LastAlloc.index = -1;
  this->m_NodeRemap.m_Tree.m_pElements = this->m_NodeRemap.m_Tree.m_Elements.m_pMemory;
  this->m_nMaxMapCoord = 0x2000;
  this->m_nMinMapCoord = -8192;
  this->m_InstanceClass = nullptr;
  this->m_bGridNavActive = false;
  this->m_nGridNavEdgeSize = 0;
  this->m_nGridNavOffsetX = 0;
  this->m_nGridNavOffsetY = 0;
  this->m_nTraceHeight = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F9360
// Name: public: GameData::~GameData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::~GameData(GameData *this)
{
  GameData::ClearData(this);
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_NodeRemap.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Classes);
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(this: &this->m_FGDAutoVisGroups);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100F9390
// Name: public: int GameData::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameData::Load(GameData *this, char *pszFilename)
{
  GameData *v2; // esi
  char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char v7; // al
  GDclass *v8; // eax
  GDclass *v9; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v12; // edi
  GDclass **m_pMemory; // ecx
  int v14; // eax
  GDclass **v15; // edi
  int v16; // edi
  int v17; // eax
  GDclass **v18; // ecx
  int v19; // eax
  GDclass **v20; // edi
  char justPath[260]; // [esp+8h] [ebp-3E0h] BYREF
  char loadFilename[260]; // [esp+10Ch] [ebp-2DCh] BYREF
  TokenReader tr; // [esp+210h] [ebp-1D8h] BYREF
  char szToken[128]; // [esp+360h] [ebp-88h] BYREF
  GameData *v25; // [esp+3E0h] [ebp-8h]
  int nExistingClassIndex; // [esp+3E4h] [ebp-4h] BYREF

  v2 = this;
  v25 = this;
  TokenReader::TokenReader(this: &tr);
  v3 = pszFilename;
  if ( GetFileAttributesA(lpFileName: pszFilename) == -1 || !TokenReader::Open(this: &tr, pszFilename) )
  {
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  if ( tr.m_nErrorCount < 5 )
  {
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
      if ( v5 == TOKENEOF )
        break;
      if ( (v5 != OPERATOR || _V_stricmp(s1: szToken, s2: "@") != 0) && GDError(&tr, error: "expected @") == 0
        || TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128) != IDENT
        && GDError(&tr, error: "expected identifier after @") == 0 )
      {
        goto LABEL_83;
      }
      if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0
        && _V_stricmp(s1: szToken, s2: "pointclass") != 0
        && _V_stricmp(s1: szToken, s2: "solidclass") != 0
        && _V_stricmp(s1: szToken, s2: "keyframeclass") != 0
        && _V_stricmp(s1: szToken, s2: "moveclass") != 0
        && _V_stricmp(s1: szToken, s2: "npcclass") != 0
        && _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
      {
        if ( _V_stricmp(s1: szToken, s2: "include") != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "mapsize") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "gridnav") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "materialexclusion") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "autovisgroup") != 0 )
                {
                  GDError(&tr, error: "unrecognized section name %s", szToken);
                  TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
                  goto LABEL_80;
                }
                v7 = GameData::LoadFGDAutoVisGroups(this: v2, &tr);
              }
              else
              {
                v7 = GameData::LoadFGDMaterialExclusions(this: v2, &tr);
              }
            }
            else
            {
              v7 = GameData::ParseGridNav(this: v2, &tr);
            }
          }
          else
          {
            v7 = GameData::ParseMapSize(this: v2, &tr);
          }
          if ( v7 == 0 )
            TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
        }
        else
        {
          nExistingClassIndex = (int)szToken;
          v6 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
          if ( v6 == TOKENSTRINGTOOLONG )
          {
            GDError(&tr, error: "unterminated string or string too long");
          }
          else if ( v6 == STRING || v6 == INTEGER )
          {
            if ( V_ExtractFilePath(path: v3, dest: justPath, destSize: 260) )
              V_snprintf(pDest: loadFilename, maxLen: 0x104u, pFormat: "%s%s", justPath, szToken);
            else
              V_strncpy(pDest: loadFilename, pSrc: szToken, maxLen: 260);
            if ( GameData::Load(this: v2, pszFilename: loadFilename) == 0
              && GameData::Load(this: v2, pszFilename: szToken) == 0 )
            {
              GDError(&tr, error: "error including file: %s", szToken);
            }
          }
          else
          {
            GDError(&tr, error: "expecting %s", "string");
          }
        }
      }
      else
      {
        v8 = (GDclass *)operator new(nSize: 0x2D8u);
        if ( v8 != nullptr )
          v9 = GDclass::GDclass(this: v8);
        else
          v9 = nullptr;
        if ( GDclass::InitFromTokens(this: v9, &tr, pGD: v2) != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "pointclass") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "solidclass") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "npcclass") != 0 )
                {
                  if ( _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
                  {
                    if ( _V_stricmp(s1: szToken, s2: "moveclass") != 0 )
                    {
                      if ( _V_stricmp(s1: szToken, s2: "keyframeclass") == 0 )
                        *(_WORD *)&v9->m_bKeyFrame = 257;
                    }
                    else
                    {
                      v9->m_bMove = true;
                      v9->m_bPoint = true;
                    }
                  }
                  else
                  {
                    v9->m_bPoint = true;
                    v9->m_bFilter = true;
                  }
                }
                else
                {
                  *(_WORD *)&v9->m_bPoint = 257;
                }
              }
              else
              {
                v9->m_bSolid = true;
              }
            }
            else
            {
              v9->m_bPoint = true;
            }
          }
          else
          {
            v9->m_bBase = true;
          }
          nExistingClassIndex = 0;
          if ( GameData::ClassForName(this: v2, pszName: v9->m_szName, piIndex: &nExistingClassIndex) != nullptr )
          {
            m_Size = v2->m_Classes.m_Size;
            m_nAllocationCount = v2->m_Classes.m_Memory.m_nAllocationCount;
            v12 = nExistingClassIndex + 1;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Classes,
                num: m_Size - m_nAllocationCount + 1);
            ++v2->m_Classes.m_Size;
            m_pMemory = v2->m_Classes.m_Memory.m_pMemory;
            v14 = v2->m_Classes.m_Size - v12 - 1;
            v2->m_Classes.m_pElements = m_pMemory;
            if ( v14 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[v12 + 1],
                src: (unsigned __int8 *)&m_pMemory[v12],
                count: 4 * v14);
            v15 = &v2->m_Classes.m_Memory.m_pMemory[v12];
            if ( v15 != nullptr )
              *v15 = v9;
            if ( v2->m_Classes.m_Size - nExistingClassIndex - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex],
                src: (unsigned __int8 *)&v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex + 1],
                count: 4 * (v2->m_Classes.m_Size - nExistingClassIndex - 1));
            --v2->m_Classes.m_Size;
          }
          else
          {
            v16 = v2->m_Classes.m_Size;
            v17 = v2->m_Classes.m_Memory.m_nAllocationCount;
            if ( v16 + 1 > v17 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Classes,
                num: v16 - v17 + 1);
            ++v2->m_Classes.m_Size;
            v18 = v2->m_Classes.m_Memory.m_pMemory;
            v19 = v2->m_Classes.m_Size - v16 - 1;
            v2->m_Classes.m_pElements = v18;
            if ( v19 > 0 )
              _V_memmove(dest: (unsigned __int8 *)&v18[v16 + 1], src: (unsigned __int8 *)&v18[v16], count: 4 * v19);
            v20 = &v2->m_Classes.m_Memory.m_pMemory[v16];
            if ( v20 != nullptr )
              *v20 = v9;
          }
          v2 = v25;
        }
        else
        {
          TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
          if ( v9 != nullptr )
          {
            GDclass::~GDclass(this: v9);
            free(pMem: v9);
          }
        }
      }
LABEL_80:
      if ( tr.m_nErrorCount >= 5 )
        break;
      v3 = pszFilename;
    }
  }
  if ( tr.m_nErrorCount > 0 )
  {
LABEL_83:
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  else
  {
    TokenReader::Close(this: &tr);
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 1;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00404580
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x0044DC60
// Name: bool GDError(class TokenReader __near &,char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char GDError(TokenReader *tr, char *error, ...)
{
  void (*v2)(int, const char *, ...); // eax
  const char *v3; // eax
  char szBuf[128]; // [esp+4h] [ebp-80h] BYREF
  va_list ap; // [esp+94h] [ebp+10h] BYREF

  va_start(ap, error);
  vsprintf(string: szBuf, format: error, ap);
  v2 = g_pMsgFunc;
  if ( g_pMsgFunc != nullptr )
  {
    v3 = TokenReader::Error(this: tr, error: szBuf);
    g_pMsgFunc(a1: 1, a2: v3);
    v2 = g_pMsgFunc;
  }
  if ( tr->m_nErrorCount < 5 )
    return 1;
  if ( v2 != nullptr )
    v2(a1: 1, a2: "   - too many errors; aborting.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DCD0
// Name: public: void GameData::BeginInstancing(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::BeginInstancing(GameData *this, int nPass)
{
  this->m_nRemapStage = nPass;
  if ( nPass == 2 )
    this->m_nNextNodeID = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044DCF0
// Name: public: bool GameData::RemapNameField(char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GameData::RemapNameField(
        GameData *this,
        const char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  char *v4; // ebx
  char v5; // al

  v4 = strcpy(pszOutValue, pszInValue);
  v5 = *pszInValue;
  if ( *pszInValue != 0 && v5 != 64 && v5 != 33 )
  {
    if ( NameFixup != NAME_FIXUP_PREFIX )
    {
      if ( NameFixup == NAME_FIXUP_POSTFIX )
        sprintf(string: v4, format: "%s-%s", pszInValue, this->m_InstancePrefix);
    }
    else
    {
      sprintf(string: v4, format: "%s-%s", this->m_InstancePrefix, pszInValue);
    }
  }
  return _V_stricmp(s1: pszInValue, s2: v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DD60
// Name: public: bool GameData::RemapInstanceField(char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GameData::RemapInstanceField(
        GameData *this,
        char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  unsigned __int8 *v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char v8; // cl
  const char *v9; // esi
  char *v10; // eax

  v4 = (unsigned __int8 *)strcpy(pszOutValue, pszInValue);
  strchr(string: (unsigned __int8 *)pszInValue, chr: 0x20u);
  v6 = v5;
  strchr(string: v4, chr: 0x20u);
  if ( v6 != 0 && v7 != 0 )
  {
    v8 = *(_BYTE *)(v6 + 1);
    v9 = (const char *)(v6 + 1);
    v10 = (char *)(v7 + 1);
    if ( v8 != 0 && v8 != 64 && v8 != 33 && v8 != 45 && v8 != 46 && (v8 < 48 || v8 > 57) )
    {
      if ( NameFixup != NAME_FIXUP_PREFIX )
      {
        if ( NameFixup == NAME_FIXUP_POSTFIX )
          sprintf(string: v10, format: "%s-%s", v9, this->m_InstancePrefix);
      }
      else
      {
        sprintf(string: v10, format: "%s-%s", this->m_InstancePrefix, v9);
      }
    }
  }
  return _V_stricmp(s1: pszInValue, s2: (const char *)v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DE10
// Name: DoGetToken
// Source: json
//------------------------------------------------------------------------------
char __usercall DoGetToken@<al>(
        char **ppszStore@<eax>,
        int nSize@<ecx>,
        trtoken_t ttexpecting@<edi>,
        TokenReader *tr,
        const char *pszExpecting)
{
  char *v6; // eax
  trtoken_t Token; // eax
  const char *v9; // esi
  const char *v10; // eax

  v6 = *ppszStore;
  if ( v6 != nullptr )
    Token = TokenReader::NextToken(this: tr, pszStore: v6, nSize);
  else
    Token = TokenReader::NextTokenDynamic(this: tr, ppszStore);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  v9 = *ppszStore;
  if ( Token == ttexpecting || ttexpecting == TOKENNONE || ttexpecting == STRING && Token == INTEGER )
  {
    if ( pszExpecting == nullptr || _V_stricmp(s1: v9, s2: pszExpecting) == 0 )
      return 1;
  }
  else if ( pszExpecting == nullptr )
  {
    switch ( ttexpecting )
    {
      case INTEGER:
        v10 = "integer";
        break;
      case STRING:
        v10 = "string";
        break;
      case IDENT:
        v10 = "identifier";
        break;
      default:
        v10 = "symbol";
        break;
    }
    GDError(tr, error: "expecting %s", v10);
    return 0;
  }
  GDError(tr, error: "expecting '%s', but found '%s'", pszExpecting, v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DEE0
// Name: bool GDGetToken(class TokenReader __near &,char __near *,int,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetToken(TokenReader *tr, char *pszStore, int nSize, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( pszStore != nullptr )
    return DoGetToken(ppszStore: &pszStore, nSize, ttexpecting, tr, pszExpecting);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DF10
// Name: bool GDSkipToken(class TokenReader __near &,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDSkipToken(TokenReader *tr, trtoken_t ttexpecting, const char *pszExpecting)
{
  char szDiscardBuf[129]; // [esp+4h] [ebp-88h] BYREF
  char *pszDiscardBuf; // [esp+88h] [ebp-4h] BYREF

  pszDiscardBuf = szDiscardBuf;
  return DoGetToken(ppszStore: &pszDiscardBuf, nSize: 129, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x0044DF50
// Name: bool GDGetTokenDynamic(class TokenReader __near &,char __near * __near *,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetTokenDynamic(TokenReader *tr, char **ppszStore, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( ppszStore == nullptr )
    return 0;
  *ppszStore = nullptr;
  return DoGetToken(ppszStore, nSize: -1, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x0044DF80
// Name: private: bool GameData::ParseMapSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseMapSize(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  char *v4; // edi
  trtoken_t v5; // eax
  int v6; // edi
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  int v9; // eax
  int v10; // ecx
  GameData *v11; // edx
  trtoken_t v12; // eax
  char pszStore[132]; // [esp+8h] [ebp-10Ch] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-88h] BYREF
  char *s1; // [esp+10Ch] [ebp-8h]
  GameData *v16; // [esp+110h] [ebp-4h]

  v16 = this;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  v4 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v4);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
  {
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v6 = atoi(nptr: szToken);
  v7 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v7 != TOKENSTRINGTOOLONG )
  {
    if ( v7 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
      return 0;
    }
    v8 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( v8 != TOKENSTRINGTOOLONG )
    {
      if ( v8 != INTEGER )
      {
        GDError(tr, error: "expecting %s", "integer");
        return 0;
      }
      v9 = atoi(nptr: szToken);
      if ( v6 != v9 )
      {
        v10 = v6;
        if ( v6 >= v9 )
          v10 = v9;
        v11 = v16;
        v16->m_nMinMapCoord = v10;
        if ( v6 > v9 )
          v9 = v6;
        v11->m_nMaxMapCoord = v9;
      }
      v12 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v12 != TOKENSTRINGTOOLONG )
      {
        if ( v12 != OPERATOR || _V_stricmp(s1: pszStore, s2: ")") != 0 )
        {
          GDError(tr, error: "expecting '%s', but found '%s'", ")", pszStore);
          return 0;
        }
        return 1;
      }
    }
  }
  GDError(tr, error: "unterminated string or string too long");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044E1B0
// Name: private: bool GameData::ParseGridNav(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseGridNav(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  const char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  trtoken_t v9; // eax
  int v10; // ebx
  int v11; // edi
  GameData *v12; // eax
  int v13; // edx
  int v14; // ecx
  char pszStore[132]; // [esp+8h] [ebp-110h] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-8Ch] BYREF
  GameData *v17; // [esp+10Ch] [ebp-Ch]
  int nOffsetX; // [esp+110h] [ebp-8h]
  int nEdgeSize; // [esp+114h] [ebp-4h]

  v17 = this;
  nEdgeSize = (int)pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  v3 = (const char *)nEdgeSize;
  if ( Token != OPERATOR || _V_stricmp(s1: (const char *)nEdgeSize, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v3);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_8:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
    goto LABEL_10;
  nEdgeSize = atoi(nptr: szToken);
  v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v6 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
  {
LABEL_14:
    GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
    return 0;
  }
  v7 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v7 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v7 != INTEGER )
    goto LABEL_10;
  nOffsetX = atoi(nptr: szToken);
  v8 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v8 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v8 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    goto LABEL_14;
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v9 != INTEGER )
  {
LABEL_10:
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v10 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ",") == 0 )
    return 0;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
    return 0;
  v11 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
    return 0;
  v12 = v17;
  v13 = nEdgeSize;
  v14 = nOffsetX;
  v17->m_nGridNavOffsetY = v10;
  v12->m_nTraceHeight = v11;
  v12->m_bGridNavActive = true;
  v12->m_nGridNavEdgeSize = v13;
  v12->m_nGridNavOffsetX = v14;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044E640
// Name: public: void GameData::ClearData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::ClearData(GameData *this)
{
  int m_Size; // eax
  int v3; // esi
  GDclass **m_pMemory; // ecx
  GDclass *v5; // edi
  int nCount; // [esp+8h] [ebp-4h]

  m_Size = this->m_Classes.m_Size;
  v3 = 0;
  nCount = m_Size;
  if ( m_Size <= 0 )
  {
    this->m_Classes.m_Size = 0;
  }
  else
  {
    do
    {
      m_pMemory = this->m_Classes.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr )
      {
        GDclass::~GDclass(this: m_pMemory[v3]);
        free(pMem: v5);
        m_Size = nCount;
      }
      ++v3;
    }
    while ( v3 < m_Size );
    this->m_Classes.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E690
// Name: public: class GDclass __near * GameData::ClassForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::ClassForName(GameData *this, const char *pszName, int *piIndex)
{
  int v3; // edi
  GDclass **i; // esi
  GDclass *result; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Classes.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  for ( i = this->m_Classes.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( strcmp((*i)->m_szName, pszName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  if ( piIndex != nullptr )
    *piIndex = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044E700
// Name: public: class GDclass __near * GameData::BeginInstanceRemap(char const __near *,char const __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::BeginInstanceRemap(
        GameData *this,
        const char *pszClassName,
        const char *pszInstancePrefix,
        Vector *Origin,
        QAngle *Angle)
{
  const char *v6; // eax
  char v7; // cl
  GDclass *m_InstanceClass; // edi
  int v9; // ebx
  const char *v10; // edi
  GDclass *v11; // edi
  GDclass *v12; // eax
  GDclass *v13; // eax
  const char **v14; // edi
  GDclass *v15; // eax

  this->m_InstanceOrigin = *Origin;
  this->m_InstanceAngle = *Angle;
  AngleMatrix(angles: &this->m_InstanceAngle, position: &this->m_InstanceOrigin, matrix: &this->m_InstanceMat);
  v6 = pszInstancePrefix;
  do
  {
    v7 = *v6;
    v6[(char *)this - pszInstancePrefix + 164] = *v6;
    ++v6;
  }
  while ( v7 != 0 );
  m_InstanceClass = this->m_InstanceClass;
  v9 = 0;
  if ( m_InstanceClass != nullptr )
  {
    GDclass::~GDclass(this: this->m_InstanceClass);
    free(pMem: m_InstanceClass);
    this->m_InstanceClass = nullptr;
  }
  v10 = pszClassName;
  if ( _V_stricmp(s1: pszClassName, s2: "info_overlay_accessor") == 0 )
    v10 = "info_overlay";
  v11 = GameData::ClassForName(this, pszName: v10, piIndex: nullptr);
  if ( v11 != nullptr )
  {
    v12 = (GDclass *)MemAlloc_Alloc(nSize: 0x2D8u);
    if ( v12 != nullptr )
      v13 = GDclass::GDclass(this: v12);
    else
      v13 = nullptr;
    this->m_InstanceClass = v13;
    v13->Parent = this;
    GDclass::AddBase(this: this->m_InstanceClass, pBase: v11);
    if ( RequiredKeys[0] != nullptr )
    {
      v14 = RequiredKeys;
      do
      {
        if ( GDclass::VarForName(this: this->m_InstanceClass, pszName: *v14, piIndex: nullptr) == nullptr )
        {
          v15 = GameData::ClassForName(this, pszName: *v14, piIndex: nullptr);
          if ( v15 != nullptr )
            GDclass::AddBase(this: this->m_InstanceClass, pBase: v15);
        }
        v14 = &RequiredKeys[++v9];
      }
      while ( *v14 != nullptr );
    }
    return this->m_InstanceClass;
  }
  else
  {
    this->m_InstanceClass = nullptr;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044FF20
// Name: public: bool CUtlMap<int,int,unsigned short>::IsValidIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMap<int,int,unsigned short>::IsValidIndex(
        CUtlMap<int,int,unsigned short> *this,
        unsigned __int16 i)
{
  return i < this->m_Tree.m_Elements.m_nAllocationCount
      && i <= this->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &this->m_Tree,
           i) != i;
}

//------------------------------------------------------------------------------
// Address: 0x00450050
// Name: public: void GameData::BeginMapInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::BeginMapInstance(GameData *this)
{
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NodeRemap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00450060
// Name: public: bool GameData::LoadFGDMaterialExclusions(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDMaterialExclusions(GameData *this, TokenReader *tr)
{
  TokenReader *v2; // ebx
  trtoken_t Token; // eax
  char *v6; // edi
  trtoken_t v7; // eax
  int v8; // edi
  int v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  FGDMatExlcusions_s *m_pMemory; // ecx
  int v13; // eax
  int v14; // edi
  trtoken_t v15; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  char *s1; // [esp+90h] [ebp-4h]

  v2 = tr;
  s1 = szToken;
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr: v2, error: "unterminated string or string too long");
    return 0;
  }
  v6 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", v6);
    return 0;
  }
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
  {
    do
    {
      s1 = szToken;
      v7 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 128);
      if ( v7 == TOKENSTRINGTOOLONG )
      {
        GDError(tr: v2, error: "unterminated string or string too long");
      }
      else if ( v7 == STRING || v7 == INTEGER )
      {
        v8 = 0;
        if ( this->m_FGDMaterialExclusions.m_Size <= 0 )
        {
LABEL_18:
          m_Size = this->m_FGDMaterialExclusions.m_Size;
          m_nAllocationCount = this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<FGDMatExlcusions_s,int>::Grow(
              this: &this->m_FGDMaterialExclusions.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_FGDMaterialExclusions.m_Size;
          m_pMemory = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          v13 = this->m_FGDMaterialExclusions.m_Size - m_Size - 1;
          this->m_FGDMaterialExclusions.m_pElements = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 261 * v13);
          v14 = m_Size;
          V_strncpy(
            pDest: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].szDirectory,
            pSrc: szToken,
            maxLen: 260);
          this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].bUserGenerated = false;
        }
        else
        {
          v9 = 0;
          while ( _V_stricmp(s1: szToken, s2: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v9].szDirectory) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->m_FGDMaterialExclusions.m_Size )
            {
              v2 = tr;
              goto LABEL_18;
            }
          }
          v2 = tr;
        }
      }
      else
      {
        GDError(tr: v2, error: "expecting %s", "string");
      }
    }
    while ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 128) != OPERATOR );
  }
  v15 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 129);
  if ( v15 == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  if ( v15 != OPERATOR || _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    GDError(tr: v2, error: "expecting '%s', but found '%s'", "]", szToken);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00450430
// Name: public: bool GameData::RemapKeyValue(char const __near *,char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GameData::RemapKeyValue(
        GameData *this,
        const char *pszKey,
        char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  GameData *v5; // esi
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v10; // eax
  int v11; // edx
  float *p_m_Data; // esi
  unsigned __int16 v13; // cx
  int v14; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v15; // eax
  unsigned __int16 v16; // dx
  int v17; // edx
  float *v18; // esi
  unsigned __int16 v19; // cx
  int v20; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v21; // eax
  unsigned __int16 v22; // dx
  int v23; // edx
  float *v24; // esi
  unsigned __int16 v25; // cx
  int v26; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v27; // eax
  unsigned __int16 v28; // dx
  int v29; // edx
  float *v30; // esi
  unsigned __int16 v31; // cx
  int v32; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v33; // eax
  unsigned __int16 v34; // dx
  int v35; // edx
  float *v36; // esi
  unsigned __int16 v37; // cx
  int v38; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v39; // eax
  unsigned __int16 v40; // dx
  int v41; // edx
  float *v42; // esi
  unsigned __int16 v43; // cx
  int v44; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v45; // eax
  unsigned __int16 v46; // dx
  int v47; // edx
  float *v48; // esi
  unsigned __int16 v49; // cx
  int v50; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v51; // eax
  unsigned __int16 v52; // dx
  int v53; // edx
  float *v54; // esi
  unsigned __int16 v55; // cx
  int v56; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v57; // eax
  unsigned __int16 v58; // dx
  int v59; // edx
  float *v60; // esi
  unsigned __int16 v61; // cx
  int v62; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v63; // eax
  unsigned __int16 v64; // dx
  int v65; // edx
  float *v66; // esi
  unsigned __int16 v67; // cx
  int v68; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v69; // eax
  unsigned __int16 v70; // dx
  int v71; // edx
  float *v72; // esi
  unsigned __int16 v73; // cx
  int v74; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v75; // eax
  unsigned __int16 v76; // dx
  int v77; // edx
  float *v78; // esi
  GDclass *m_InstanceClass; // ecx
  GDinputvariable *v81; // eax
  unsigned __int16 v82; // ax
  int v83; // ebx
  float v84; // ebx
  matrix3x4_t localMatrix; // [esp+24h] [ebp-84h] BYREF
  matrix3x4_t angToWorld; // [esp+54h] [ebp-54h] BYREF
  QAngle outAngles; // [esp+84h] [ebp-24h] BYREF
  GDIV_TYPE KVType; // [esp+90h] [ebp-18h]
  QAngle inAngles; // [esp+94h] [ebp-14h] BYREF
  unsigned __int16 parent[3]; // [esp+A0h] [ebp-8h] BYREF
  bool leftchild; // [esp+A7h] [ebp-1h] BYREF
  int KVRemapIndex; // [esp+B0h] [ebp+8h]

  v5 = this;
  KVType = (GDIV_TYPE)this;
  if ( RemapOperation.m_Tree.m_NumElements == 0 )
  {
    if ( RemapOperation.m_Tree.m_LessFunc.m_LessFunc == nullptr )
      RemapOperation.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const GDIV_TYPE *, const GDIV_TYPE *))CDefOps<int>::LessFunc;
    inAngles.y = 0.0;
    LODWORD(inAngles.z) = 2;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v6 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v7 = parent[0];
    v8 = v6;
    v9 = v6;
    v10 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v9];
    v10->m_Right = -1;
    v10->m_Left = -1;
    v10->m_Parent = v7;
    v10->m_Tag = 0;
    if ( v7 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v8;
    }
    else
    {
      v11 = v7;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v11].m_Left = v8;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v11].m_Right = v8;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v8);
    ++RemapOperation.m_Tree.m_NumElements;
    p_m_Data = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v9].m_Data;
    if ( p_m_Data != nullptr )
    {
      *p_m_Data = inAngles.y;
      p_m_Data[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 6;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v13 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v14 = v13;
    v15 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v13];
    v16 = parent[0];
    v15->m_Right = -1;
    v15->m_Left = -1;
    v15->m_Parent = v16;
    v15->m_Tag = 0;
    if ( v16 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v13;
    }
    else
    {
      v17 = v16;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v17].m_Left = v13;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v17].m_Right = v13;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v13);
    ++RemapOperation.m_Tree.m_NumElements;
    v18 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v14].m_Data;
    if ( v18 != nullptr )
    {
      *v18 = inAngles.y;
      v18[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 1;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v19 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v20 = v19;
    v21 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v19];
    v22 = parent[0];
    v21->m_Right = -1;
    v21->m_Left = -1;
    v21->m_Parent = v22;
    v21->m_Tag = 0;
    if ( v22 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v19;
    }
    else
    {
      v23 = v22;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v23].m_Left = v19;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v23].m_Right = v19;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v19);
    ++RemapOperation.m_Tree.m_NumElements;
    v24 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v20].m_Data;
    if ( v24 != nullptr )
    {
      *v24 = inAngles.y;
      v24[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 3;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v25 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v26 = v25;
    v27 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v25];
    v28 = parent[0];
    v27->m_Right = -1;
    v27->m_Left = -1;
    v27->m_Parent = v28;
    v27->m_Tag = 0;
    if ( v28 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v25;
    }
    else
    {
      v29 = v28;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v29].m_Left = v25;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v29].m_Right = v25;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v25);
    ++RemapOperation.m_Tree.m_NumElements;
    v30 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v26].m_Data;
    if ( v30 != nullptr )
    {
      *v30 = inAngles.y;
      v30[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 17;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v31 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v32 = v31;
    v33 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v31];
    v34 = parent[0];
    v33->m_Right = -1;
    v33->m_Left = -1;
    v33->m_Parent = v34;
    v33->m_Tag = 0;
    if ( v34 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v31;
    }
    else
    {
      v35 = v34;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v35].m_Left = v31;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v35].m_Right = v31;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v31);
    ++RemapOperation.m_Tree.m_NumElements;
    v36 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v32].m_Data;
    if ( v36 != nullptr )
    {
      *v36 = inAngles.y;
      v36[1] = inAngles.z;
    }
    LODWORD(inAngles.z) = 1;
    LODWORD(inAngles.y) = 23;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v37 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v38 = v37;
    v39 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v37];
    v40 = parent[0];
    v39->m_Right = -1;
    v39->m_Left = -1;
    v39->m_Parent = v40;
    v39->m_Tag = 0;
    if ( v40 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v37;
    }
    else
    {
      v41 = v40;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v41].m_Left = v37;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v41].m_Right = v37;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v37);
    ++RemapOperation.m_Tree.m_NumElements;
    v42 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v38].m_Data;
    if ( v42 != nullptr )
    {
      *v42 = inAngles.y;
      v42[1] = inAngles.z;
    }
    LODWORD(inAngles.z) = 1;
    LODWORD(inAngles.y) = 24;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v43 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v44 = v43;
    v45 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v43];
    v46 = parent[0];
    v45->m_Right = -1;
    v45->m_Left = -1;
    v45->m_Parent = v46;
    v45->m_Tag = 0;
    if ( v46 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v43;
    }
    else
    {
      v47 = v46;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v47].m_Left = v43;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v47].m_Right = v43;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v43);
    ++RemapOperation.m_Tree.m_NumElements;
    v48 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v44].m_Data;
    if ( v48 != nullptr )
    {
      *v48 = inAngles.y;
      v48[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 25;
    LODWORD(inAngles.z) = 2;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v49 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v50 = v49;
    v51 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v49];
    v52 = parent[0];
    v51->m_Right = -1;
    v51->m_Left = -1;
    v51->m_Parent = v52;
    v51->m_Tag = 0;
    if ( v52 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v49;
    }
    else
    {
      v53 = v52;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v53].m_Left = v49;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v53].m_Right = v49;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v49);
    ++RemapOperation.m_Tree.m_NumElements;
    v54 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v50].m_Data;
    if ( v54 != nullptr )
    {
      *v54 = inAngles.y;
      v54[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 32;
    LODWORD(inAngles.z) = 3;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v55 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v56 = v55;
    v57 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v55];
    v58 = parent[0];
    v57->m_Right = -1;
    v57->m_Left = -1;
    v57->m_Parent = v58;
    v57->m_Tag = 0;
    if ( v58 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v55;
    }
    else
    {
      v59 = v58;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v59].m_Left = v55;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v59].m_Right = v55;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v55);
    ++RemapOperation.m_Tree.m_NumElements;
    v60 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v56].m_Data;
    if ( v60 != nullptr )
    {
      *v60 = inAngles.y;
      v60[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 27;
    LODWORD(inAngles.z) = 4;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v61 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v62 = v61;
    v63 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v61];
    v64 = parent[0];
    v63->m_Right = -1;
    v63->m_Left = -1;
    v63->m_Parent = v64;
    v63->m_Tag = 0;
    if ( v64 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v61;
    }
    else
    {
      v65 = v64;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v65].m_Left = v61;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v65].m_Right = v61;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v61);
    ++RemapOperation.m_Tree.m_NumElements;
    v66 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v62].m_Data;
    if ( v66 != nullptr )
    {
      *v66 = inAngles.y;
      v66[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 36;
    LODWORD(inAngles.z) = 4;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v67 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v68 = v67;
    v69 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v67];
    v70 = parent[0];
    v69->m_Right = -1;
    v69->m_Left = -1;
    v69->m_Parent = v70;
    v69->m_Tag = 0;
    if ( v70 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v67;
    }
    else
    {
      v71 = v70;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v71].m_Left = v67;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v71].m_Right = v67;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v67);
    ++RemapOperation.m_Tree.m_NumElements;
    v72 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v68].m_Data;
    if ( v72 != nullptr )
    {
      *v72 = inAngles.y;
      v72[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 33;
    LODWORD(inAngles.z) = 5;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v73 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v74 = v73;
    v75 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v73];
    v76 = parent[0];
    v75->m_Right = -1;
    v75->m_Left = -1;
    v75->m_Parent = v76;
    v75->m_Tag = 0;
    if ( v76 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v73;
    }
    else
    {
      v77 = v76;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v77].m_Left = v73;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v77].m_Right = v73;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v73);
    ++RemapOperation.m_Tree.m_NumElements;
    v78 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v74].m_Data;
    if ( v78 != nullptr )
    {
      *v78 = inAngles.y;
      v78[1] = inAngles.z;
    }
    v5 = (GameData *)KVType;
  }
  m_InstanceClass = v5->m_InstanceClass;
  if ( m_InstanceClass == nullptr )
    return false;
  v81 = GDclass::VarForName(this: m_InstanceClass, pszName: pszKey, piIndex: nullptr);
  if ( v81 == nullptr )
    return false;
  KVType = v81->m_eType;
  LODWORD(inAngles.y) = KVType;
  KVRemapIndex = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &RemapOperation.m_Tree,
                   search: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y);
  if ( KVRemapIndex == 0xFFFF )
    return false;
  strcpy(pszOutValue, pszInValue);
  switch ( RemapOperation.m_Tree.m_Elements.m_pMemory[(unsigned __int16)KVRemapIndex].m_Data.elem )
  {
    case REMAP_NAME:
      if ( v5->m_nRemapStage != 1 )
        return false;
      if ( KVType != ivInstanceVariable )
        GameData::RemapNameField(this: v5, pszInValue, pszOutValue, NameFixup);
      break;
    case REMAP_POSITION:
      if ( v5->m_nRemapStage != 1 )
        return false;
      memset(&inAngles, 0, sizeof(inAngles));
      sscanf(string: pszInValue, format: "%f %f %f", &inAngles, &inAngles.y, &inAngles.z);
      VectorTransform(in1: &inAngles.x, in2: &v5->m_InstanceMat, out: &outAngles.x);
      sprintf(string: pszOutValue, format: "%g %g %g", outAngles.x, outAngles.y, outAngles.z);
      break;
    case REMAP_ANGLE:
      if ( v5->m_nRemapStage != 1 )
        return false;
      if ( v5->m_InstanceAngle.x != 0.0 || v5->m_InstanceAngle.y != 0.0 || v5->m_InstanceAngle.z != 0.0 )
      {
        memset(&inAngles, 0, sizeof(inAngles));
        sscanf(string: pszInValue, format: "%f %f %f", &inAngles, &inAngles.y, &inAngles.z);
        AngleMatrix(angles: &inAngles, matrix: &angToWorld);
        ConcatTransforms(in1: &v5->m_InstanceMat, in2: &angToWorld, out: &localMatrix);
        MatrixAngles(src: (const VMatrix *)&localMatrix, vAngles: &outAngles);
        sprintf(string: pszOutValue, format: "%g %g %g", outAngles.x, outAngles.y, outAngles.z);
      }
      break;
    case REMAP_ANGLE_NEGATIVE_PITCH:
      if ( v5->m_nRemapStage != 1 )
        return false;
      if ( v5->m_InstanceAngle.x != 0.0 || v5->m_InstanceAngle.y != 0.0 || v5->m_InstanceAngle.z != 0.0 )
      {
        memset(&inAngles, 0, sizeof(inAngles));
        sscanf(string: pszInValue, format: "%f", &inAngles);
        LODWORD(inAngles.x) ^= _mask__NegFloat_;
        AngleMatrix(angles: &inAngles, matrix: &localMatrix);
        ConcatTransforms(in1: &v5->m_InstanceMat, in2: &localMatrix, out: &angToWorld);
        MatrixAngles(src: (const VMatrix *)&angToWorld, vAngles: &outAngles);
        sprintf(string: pszOutValue, format: "%g", COERCE_FLOAT(LODWORD(outAngles.x) ^ _mask__NegFloat_));
      }
      break;
    case REMAP_NODE:
      LODWORD(inAngles.y) = atoi(nptr: pszInValue);
      v82 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &v5->m_NodeRemap.m_Tree,
              search: (const CUtlMap<int,int,unsigned short>::Node_t *)&inAngles.y);
      v83 = v82;
      if ( CUtlMap<int,int,unsigned short>::IsValidIndex(this: &v5->m_NodeRemap, i: v82) )
      {
        v84 = *(float *)&v5->m_NodeRemap.m_Tree.m_Elements.m_pMemory[v83].m_Data.elem;
      }
      else
      {
        v84 = *(float *)&v5->m_nNextNodeID;
        v5->m_nNextNodeID = LODWORD(v84) + 1;
        LODWORD(inAngles.y) = atoi(nptr: pszInValue);
        inAngles.z = v84;
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &v5->m_NodeRemap.m_Tree,
          insert: (const CUtlMap<int,int,unsigned short>::Node_t *)&inAngles.y);
      }
      sprintf(string: pszOutValue, format: "%d", v84);
      break;
    case REMAP_INSTANCE_VARIABLE:
      if ( v5->m_nRemapStage != 1 )
        return false;
      GameData::RemapInstanceField(this: v5, pszInValue, pszOutValue, NameFixup);
      break;
    default:
      return _V_stricmp(s1: pszInValue, s2: pszOutValue) != 0;
  }
  return _V_stricmp(s1: pszInValue, s2: pszOutValue) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00451200
// Name: public: bool GameData::LoadFGDAutoVisGroups(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDAutoVisGroups(GameData *this, TokenReader *tr)
{
  GameData *v3; // edi
  trtoken_t Token; // eax
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char *v8; // esi
  trtoken_t v9; // eax
  trtoken_t v10; // eax
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v12; // esi
  int m_Size; // edx
  int v14; // edi
  trtoken_t v15; // eax
  trtoken_t v16; // eax
  CUtlMemory<S3RGBA,int> *v17; // esi
  S3RGBA *v18; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v20; // ecx
  int v21; // eax
  char **v22; // eax
  trtoken_t v23; // eax
  trtoken_t v24; // eax
  char *v25; // [esp-Ch] [ebp-130h]
  char pszStore[132]; // [esp+Ch] [ebp-118h] BYREF
  char szToken[128]; // [esp+90h] [ebp-94h] BYREF
  char *v28; // [esp+110h] [ebp-14h]
  int v29; // [esp+114h] [ebp-10h]
  int gindex; // [esp+118h] [ebp-Ch]
  GameData *v31; // [esp+11Ch] [ebp-8h]
  char *s1; // [esp+120h] [ebp-4h]
  char *tra; // [esp+12Ch] [ebp+8h]

  v3 = this;
  v31 = this;
  gindex = 0;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    goto LABEL_3;
  }
  v8 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "=") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "=", v8);
    goto LABEL_3;
  }
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v9 != STRING && v9 != INTEGER )
  {
LABEL_16:
    GDError(tr, error: "expecting %s", "string");
    return 0;
  }
  gindex = CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
             this: &v3->m_FGDAutoVisGroups,
             elem: v3->m_FGDAutoVisGroups.m_Size);
  V_strncpy(pDest: v3->m_FGDAutoVisGroups.m_Memory.m_pMemory[gindex].szParent, pSrc: szToken, maxLen: 260);
  v10 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v10 == TOKENSTRINGTOOLONG )
  {
LABEL_46:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v10 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", pszStore);
    return 0;
  }
  while ( 1 )
  {
LABEL_3:
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      if ( v5 != TOKENSTRINGTOOLONG )
        break;
      GDError(tr, error: "unterminated string or string too long");
LABEL_5:
      v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v6 == TOKENSTRINGTOOLONG )
        goto LABEL_46;
      if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
        goto LABEL_8;
    }
    if ( v5 != STRING && v5 != INTEGER )
    {
      GDError(tr, error: "expecting %s", "string");
      goto LABEL_5;
    }
    m_pMemory = v3->m_FGDAutoVisGroups.m_Memory.m_pMemory;
    v12 = 280 * gindex;
    m_Size = m_pMemory[gindex].m_Classes.m_Size;
    s1 = (char *)(280 * gindex);
    v14 = 280
        * CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
            this: (CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *)&m_pMemory[gindex].m_Classes,
            elem: m_Size);
    v25 = &(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                        + v12))->szClass[v14];
    v29 = v14;
    V_strncpy(pDest: v25, pSrc: szToken, maxLen: 260);
    v15 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v15 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    v28 = pszStore;
    if ( v15 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", "[", v28);
      return 0;
    }
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    {
      while ( 1 )
      {
        v16 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
        if ( v16 == TOKENSTRINGTOOLONG )
          goto LABEL_46;
        if ( v16 != STRING && v16 != INTEGER )
          goto LABEL_16;
        v17 = (CUtlMemory<S3RGBA,int> *)((char *)&(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                                                               + v12))->szEntities
                                       + v14);
        tra = (char *)MemAlloc_Alloc(nSize: strlen(szToken) + 1);
        _V_strcpy(dest: tra, src: szToken);
        v18 = v17[1].m_pMemory;
        m_nAllocationCount = v17->m_nAllocationCount;
        if ( (int)&v18->g > m_nAllocationCount )
          CUtlMemory<CClassInput *,int>::Grow(this: v17, num: (int)(&v18->g - m_nAllocationCount));
        ++v17[1].m_pMemory;
        v20 = v17->m_pMemory;
        v21 = (char *)v17[1].m_pMemory - (char *)v18 - 1;
        v17[1].m_nAllocationCount = (int)v17->m_pMemory;
        if ( v21 > 0 )
          _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
        v22 = (char **)&v17->m_pMemory[(_DWORD)v18];
        if ( v22 != nullptr )
          *v22 = tra;
        if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) == OPERATOR )
          break;
        v12 = (int)s1;
        v14 = v29;
      }
    }
    v23 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v23 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    if ( v23 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
      goto LABEL_8;
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != STRING )
      break;
    v3 = v31;
  }
  v24 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v24 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v24 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
  {
LABEL_8:
    GDError(tr, error: "expecting '%s', but found '%s'", "]", pszStore);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004516C0
// Name: public: GameData::GameData(void)
// Source: json
//------------------------------------------------------------------------------
GameData *__thiscall GameData::GameData(GameData *this)
{
  this->m_FGDMaterialExclusions.m_Memory.m_pMemory = nullptr;
  this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount = 0;
  this->m_FGDMaterialExclusions.m_Memory.m_nGrowSize = 0;
  this->m_FGDMaterialExclusions.m_Size = 0;
  this->m_FGDMaterialExclusions.m_pElements = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_pMemory = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_nAllocationCount = 0;
  this->m_FGDAutoVisGroups.m_Memory.m_nGrowSize = 0;
  this->m_FGDAutoVisGroups.m_Size = 0;
  this->m_FGDAutoVisGroups.m_pElements = nullptr;
  this->m_Classes.m_Memory.m_pMemory = nullptr;
  this->m_Classes.m_Memory.m_nAllocationCount = 0;
  this->m_Classes.m_Memory.m_nGrowSize = 0;
  this->m_Classes.m_Size = 0;
  this->m_Classes.m_pElements = nullptr;
  this->m_NodeRemap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
  this->m_NodeRemap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_NodeRemap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_NodeRemap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_NodeRemap.m_Tree.m_Root = -1;
  this->m_NodeRemap.m_Tree.m_NumElements = 0;
  this->m_NodeRemap.m_Tree.m_FirstFree = -1;
  this->m_NodeRemap.m_Tree.m_LastAlloc.index = -1;
  this->m_NodeRemap.m_Tree.m_pElements = this->m_NodeRemap.m_Tree.m_Elements.m_pMemory;
  this->m_nMaxMapCoord = 0x2000;
  this->m_nMinMapCoord = -8192;
  this->m_InstanceClass = nullptr;
  this->m_bGridNavActive = false;
  this->m_nGridNavEdgeSize = 0;
  this->m_nGridNavOffsetX = 0;
  this->m_nGridNavOffsetY = 0;
  this->m_nTraceHeight = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00451770
// Name: public: GameData::~GameData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::~GameData(GameData *this)
{
  GameData::ClearData(this);
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_NodeRemap.m_Tree);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Classes);
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(this: &this->m_FGDAutoVisGroups);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004517A0
// Name: public: int GameData::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameData::Load(GameData *this, const char *pszFilename)
{
  GameData *v2; // esi
  const char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char v7; // al
  GDclass *v8; // eax
  GDclass *v9; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v12; // edi
  GDclass **m_pMemory; // ecx
  int v14; // eax
  GDclass **v15; // edi
  int v16; // edi
  int v17; // eax
  GDclass **v18; // ecx
  int v19; // eax
  GDclass **v20; // edi
  char justPath[260]; // [esp+8h] [ebp-3E0h] BYREF
  char loadFilename[260]; // [esp+10Ch] [ebp-2DCh] BYREF
  TokenReader tr; // [esp+210h] [ebp-1D8h] BYREF
  char szToken[128]; // [esp+360h] [ebp-88h] BYREF
  GameData *v25; // [esp+3E0h] [ebp-8h]
  int nExistingClassIndex; // [esp+3E4h] [ebp-4h] BYREF

  v2 = this;
  v25 = this;
  TokenReader::TokenReader(this: &tr);
  v3 = pszFilename;
  if ( GetFileAttributesA(lpFileName: pszFilename) == -1 || !TokenReader::Open(this: &tr, pszFilename) )
  {
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  if ( tr.m_nErrorCount < 5 )
  {
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
      if ( v5 == TOKENEOF )
        break;
      if ( (v5 != OPERATOR || _V_stricmp(s1: szToken, s2: "@") != 0) && GDError(&tr, error: "expected @") == 0
        || TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128) != IDENT
        && GDError(&tr, error: "expected identifier after @") == 0 )
      {
        goto LABEL_83;
      }
      if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0
        && _V_stricmp(s1: szToken, s2: "pointclass") != 0
        && _V_stricmp(s1: szToken, s2: "solidclass") != 0
        && _V_stricmp(s1: szToken, s2: "keyframeclass") != 0
        && _V_stricmp(s1: szToken, s2: "moveclass") != 0
        && _V_stricmp(s1: szToken, s2: "npcclass") != 0
        && _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
      {
        if ( _V_stricmp(s1: szToken, s2: "include") != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "mapsize") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "gridnav") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "materialexclusion") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "autovisgroup") != 0 )
                {
                  GDError(&tr, error: "unrecognized section name %s", szToken);
                  TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
                  goto LABEL_80;
                }
                v7 = GameData::LoadFGDAutoVisGroups(this: v2, &tr);
              }
              else
              {
                v7 = GameData::LoadFGDMaterialExclusions(this: v2, &tr);
              }
            }
            else
            {
              v7 = GameData::ParseGridNav(this: v2, &tr);
            }
          }
          else
          {
            v7 = GameData::ParseMapSize(this: v2, &tr);
          }
          if ( v7 == 0 )
            TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
        }
        else
        {
          nExistingClassIndex = (int)szToken;
          v6 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
          if ( v6 == TOKENSTRINGTOOLONG )
          {
            GDError(&tr, error: "unterminated string or string too long");
          }
          else if ( v6 == STRING || v6 == INTEGER )
          {
            if ( V_ExtractFilePath(path: v3, dest: justPath, destSize: 260) )
              V_snprintf(pDest: loadFilename, maxLen: 260, pFormat: "%s%s", justPath, szToken);
            else
              V_strncpy(pDest: loadFilename, pSrc: szToken, maxLen: 260);
            if ( GameData::Load(this: v2, pszFilename: loadFilename) == 0
              && GameData::Load(this: v2, pszFilename: szToken) == 0 )
            {
              GDError(&tr, error: "error including file: %s", szToken);
            }
          }
          else
          {
            GDError(&tr, error: "expecting %s", "string");
          }
        }
      }
      else
      {
        v8 = (GDclass *)MemAlloc_Alloc(nSize: 0x2D8u);
        if ( v8 != nullptr )
          v9 = GDclass::GDclass(this: v8);
        else
          v9 = nullptr;
        if ( GDclass::InitFromTokens(this: v9, &tr, pGD: v2) != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "pointclass") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "solidclass") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "npcclass") != 0 )
                {
                  if ( _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
                  {
                    if ( _V_stricmp(s1: szToken, s2: "moveclass") != 0 )
                    {
                      if ( _V_stricmp(s1: szToken, s2: "keyframeclass") == 0 )
                        *(_WORD *)&v9->m_bKeyFrame = 257;
                    }
                    else
                    {
                      v9->m_bMove = true;
                      v9->m_bPoint = true;
                    }
                  }
                  else
                  {
                    v9->m_bPoint = true;
                    v9->m_bFilter = true;
                  }
                }
                else
                {
                  *(_WORD *)&v9->m_bPoint = 257;
                }
              }
              else
              {
                v9->m_bSolid = true;
              }
            }
            else
            {
              v9->m_bPoint = true;
            }
          }
          else
          {
            v9->m_bBase = true;
          }
          nExistingClassIndex = 0;
          if ( GameData::ClassForName(this: v2, pszName: v9->m_szName, piIndex: &nExistingClassIndex) != nullptr )
          {
            m_Size = v2->m_Classes.m_Size;
            m_nAllocationCount = v2->m_Classes.m_Memory.m_nAllocationCount;
            v12 = nExistingClassIndex + 1;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CClassInput *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&v2->m_Classes,
                num: m_Size - m_nAllocationCount + 1);
            ++v2->m_Classes.m_Size;
            m_pMemory = v2->m_Classes.m_Memory.m_pMemory;
            v14 = v2->m_Classes.m_Size - v12 - 1;
            v2->m_Classes.m_pElements = m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
            v15 = &v2->m_Classes.m_Memory.m_pMemory[v12];
            if ( v15 != nullptr )
              *v15 = v9;
            if ( v2->m_Classes.m_Size - nExistingClassIndex - 1 > 0 )
              _V_memmove(
                dest: &v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex],
                src: &v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex + 1],
                count: 4 * (v2->m_Classes.m_Size - nExistingClassIndex - 1));
            --v2->m_Classes.m_Size;
          }
          else
          {
            v16 = v2->m_Classes.m_Size;
            v17 = v2->m_Classes.m_Memory.m_nAllocationCount;
            if ( v16 + 1 > v17 )
              CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v2->m_Classes, num: v16 - v17 + 1);
            ++v2->m_Classes.m_Size;
            v18 = v2->m_Classes.m_Memory.m_pMemory;
            v19 = v2->m_Classes.m_Size - v16 - 1;
            v2->m_Classes.m_pElements = v18;
            if ( v19 > 0 )
              _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
            v20 = &v2->m_Classes.m_Memory.m_pMemory[v16];
            if ( v20 != nullptr )
              *v20 = v9;
          }
          v2 = v25;
        }
        else
        {
          TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
          if ( v9 != nullptr )
          {
            GDclass::~GDclass(this: v9);
            free(pMem: v9);
          }
        }
      }
LABEL_80:
      if ( tr.m_nErrorCount >= 5 )
        break;
      v3 = pszFilename;
    }
  }
  if ( tr.m_nErrorCount > 0 )
  {
LABEL_83:
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  else
  {
    TokenReader::Close(this: &tr);
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 1;
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x004072D0
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_47E16C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_47E16C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00407340
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_47E16C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004073A0
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_47E16C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00407410
// Name: protected: void CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::FindInsertionPosition(char const __near * const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        const char *const *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407500
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<char const *,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407600
// Name: protected: void CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00407700
// Name: protected: void CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00407800
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::Find(char const __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        const char *const *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00407900
// Name: public: void CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004079C0
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407A90
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::NextInorder(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NextInorder(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  unsigned __int16 v2; // si
  int v4; // edx
  int result; // eax
  int *v6; // ecx
  int v7; // edx
  int *v8; // ecx
  int v9; // ecx
  int *v10; // ecx

  v2 = i;
  if ( CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
         this,
         i) == 0xFFFF )
  {
    LOWORD(result) = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                       this,
                       i);
    v7 = `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    for ( result = (unsigned __int16)result; ; result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Parent )
    {
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
      v10 = (_WORD)v9 == 0xFFFF
          ? &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
          : (int *)&this->m_Elements.m_pMemory[v9];
      if ( *((_WORD *)v10 + 1) != v2 )
        break;
      v2 = result;
      if ( (_WORD)result == 0xFFFF )
        break;
      if ( (v7 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v7 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v7;
      }
    }
  }
  else
  {
    LOWORD(result) = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RightChild(
                       this,
                       i);
    v4 = `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    result = (unsigned __int16)result;
    while ( 1 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      v6 = (_WORD)result == 0xFFFF
         ? &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
      if ( *(_WORD *)v6 == 0xFFFF )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)result == 0xFFFF )
        result = (unsigned __int16)`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407C90
// Name: protected: void CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_47E16C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_47E16C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_47E16C = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_47E16C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_47E16C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_47E16C = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004082A0
// Name: public: CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::~CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::~CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408310
// Name: protected: void CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<char const *,unsigned short> *v4; // eax
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408400
// Name: public: unsigned short CUtlRBTree<char const __near *,unsigned short,bool (*)(char const __near * const __near &,char const __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<char const __near *,unsigned short>,unsigned short>>::Insert(char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<char const *,unsigned short,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short> > *this,
        const char *const *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<char const *,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<char const *,unsigned short,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<char const *,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00443500
// Name: bool GDError(class TokenReader __near &,char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char GDError(TokenReader *tr, char *error, ...)
{
  void (*v2)(int, const char *, ...); // eax
  const char *v3; // eax
  char szBuf[128]; // [esp+4h] [ebp-80h] BYREF
  va_list ap; // [esp+94h] [ebp+10h] BYREF

  va_start(ap, error);
  vsprintf(string: szBuf, format: error, ap);
  v2 = g_pMsgFunc;
  if ( g_pMsgFunc != nullptr )
  {
    v3 = TokenReader::Error(this: tr, error: szBuf);
    g_pMsgFunc(a1: 1, a2: v3);
    v2 = g_pMsgFunc;
  }
  if ( tr->m_nErrorCount < 5 )
    return 1;
  if ( v2 != nullptr )
    v2(a1: 1, a2: "   - too many errors; aborting.");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443570
// Name: public: void GameData::BeginInstancing(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::BeginInstancing(GameData *this, int nPass)
{
  this->m_nRemapStage = nPass;
  if ( nPass == 2 )
    this->m_nNextNodeID = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443590
// Name: public: bool GameData::RemapNameField(char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GameData::RemapNameField(
        GameData *this,
        const char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  char *v4; // ebx
  char v5; // al

  v4 = strcpy(pszOutValue, pszInValue);
  v5 = *pszInValue;
  if ( *pszInValue != 0 && v5 != 64 && v5 != 33 )
  {
    if ( NameFixup != NAME_FIXUP_PREFIX )
    {
      if ( NameFixup == NAME_FIXUP_POSTFIX )
        sprintf(string: v4, format: "%s-%s", pszInValue, this->m_InstancePrefix);
    }
    else
    {
      sprintf(string: v4, format: "%s-%s", this->m_InstancePrefix, pszInValue);
    }
  }
  return _V_stricmp(s1: pszInValue, s2: v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443600
// Name: public: bool GameData::RemapInstanceField(char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GameData::RemapInstanceField(
        GameData *this,
        char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  unsigned __int8 *v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char v8; // cl
  const char *v9; // esi
  char *v10; // eax

  v4 = (unsigned __int8 *)strcpy(pszOutValue, pszInValue);
  strchr(string: (unsigned __int8 *)pszInValue, chr: 0x20u);
  v6 = v5;
  strchr(string: v4, chr: 0x20u);
  if ( v6 != 0 && v7 != 0 )
  {
    v8 = *(_BYTE *)(v6 + 1);
    v9 = (const char *)(v6 + 1);
    v10 = (char *)(v7 + 1);
    if ( v8 != 0 && v8 != 64 && v8 != 33 && v8 != 45 && v8 != 46 && (v8 < 48 || v8 > 57) )
    {
      if ( NameFixup != NAME_FIXUP_PREFIX )
      {
        if ( NameFixup == NAME_FIXUP_POSTFIX )
          sprintf(string: v10, format: "%s-%s", v9, this->m_InstancePrefix);
      }
      else
      {
        sprintf(string: v10, format: "%s-%s", this->m_InstancePrefix, v9);
      }
    }
  }
  return _V_stricmp(s1: pszInValue, s2: (const char *)v4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004436B0
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x004436D0
// Name: DoGetToken
// Source: json
//------------------------------------------------------------------------------
char __usercall DoGetToken@<al>(
        char **ppszStore@<eax>,
        int nSize@<ecx>,
        trtoken_t ttexpecting@<edi>,
        TokenReader *tr,
        const char *pszExpecting)
{
  char *v6; // eax
  trtoken_t Token; // eax
  const char *v9; // esi
  const char *v10; // eax

  v6 = *ppszStore;
  if ( v6 != nullptr )
    Token = TokenReader::NextToken(this: tr, pszStore: v6, nSize);
  else
    Token = TokenReader::NextTokenDynamic(this: tr, ppszStore);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  v9 = *ppszStore;
  if ( Token == ttexpecting || ttexpecting == TOKENNONE || ttexpecting == STRING && Token == INTEGER )
  {
    if ( pszExpecting == nullptr || _V_stricmp(s1: v9, s2: pszExpecting) == 0 )
      return 1;
  }
  else if ( pszExpecting == nullptr )
  {
    switch ( ttexpecting )
    {
      case INTEGER:
        v10 = "integer";
        break;
      case STRING:
        v10 = "string";
        break;
      case IDENT:
        v10 = "identifier";
        break;
      default:
        v10 = "symbol";
        break;
    }
    GDError(tr, error: "expecting %s", v10);
    return 0;
  }
  GDError(tr, error: "expecting '%s', but found '%s'", pszExpecting, v9);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004437A0
// Name: bool GDGetToken(class TokenReader __near &,char __near *,int,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetToken(TokenReader *tr, char *pszStore, int nSize, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( pszStore != nullptr )
    return DoGetToken(ppszStore: &pszStore, nSize, ttexpecting, tr, pszExpecting);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004437D0
// Name: bool GDSkipToken(class TokenReader __near &,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDSkipToken(TokenReader *tr, trtoken_t ttexpecting, const char *pszExpecting)
{
  char szDiscardBuf[129]; // [esp+4h] [ebp-88h] BYREF
  char *pszDiscardBuf; // [esp+88h] [ebp-4h] BYREF

  pszDiscardBuf = szDiscardBuf;
  return DoGetToken(ppszStore: &pszDiscardBuf, nSize: 129, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x00443810
// Name: bool GDGetTokenDynamic(class TokenReader __near &,char __near * __near *,enum trtoken_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GDGetTokenDynamic(TokenReader *tr, char **ppszStore, trtoken_t ttexpecting, const char *pszExpecting)
{
  if ( ppszStore == nullptr )
    return 0;
  *ppszStore = nullptr;
  return DoGetToken(ppszStore, nSize: -1, ttexpecting, tr, pszExpecting);
}

//------------------------------------------------------------------------------
// Address: 0x00443840
// Name: private: bool GameData::ParseMapSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseMapSize(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  char *v4; // edi
  trtoken_t v5; // eax
  int v6; // edi
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  int v9; // eax
  int v10; // ecx
  GameData *v11; // edx
  trtoken_t v12; // eax
  char pszStore[132]; // [esp+8h] [ebp-10Ch] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-88h] BYREF
  char *s1; // [esp+10Ch] [ebp-8h]
  GameData *v16; // [esp+110h] [ebp-4h]

  v16 = this;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  v4 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v4);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
  {
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v6 = atoi(nptr: szToken);
  v7 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v7 != TOKENSTRINGTOOLONG )
  {
    if ( v7 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
      return 0;
    }
    v8 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( v8 != TOKENSTRINGTOOLONG )
    {
      if ( v8 != INTEGER )
      {
        GDError(tr, error: "expecting %s", "integer");
        return 0;
      }
      v9 = atoi(nptr: szToken);
      if ( v6 != v9 )
      {
        v10 = v6;
        if ( v6 >= v9 )
          v10 = v9;
        v11 = v16;
        v16->m_nMinMapCoord = v10;
        if ( v6 > v9 )
          v9 = v6;
        v11->m_nMaxMapCoord = v9;
      }
      v12 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v12 != TOKENSTRINGTOOLONG )
      {
        if ( v12 != OPERATOR || _V_stricmp(s1: pszStore, s2: ")") != 0 )
        {
          GDError(tr, error: "expecting '%s', but found '%s'", ")", pszStore);
          return 0;
        }
        return 1;
      }
    }
  }
  GDError(tr, error: "unterminated string or string too long");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443A70
// Name: private: bool GameData::ParseGridNav(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::ParseGridNav(GameData *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  const char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  trtoken_t v7; // eax
  trtoken_t v8; // eax
  trtoken_t v9; // eax
  int v10; // ebx
  int v11; // edi
  GameData *v12; // eax
  int v13; // edx
  int v14; // ecx
  char pszStore[132]; // [esp+8h] [ebp-110h] BYREF
  char szToken[128]; // [esp+8Ch] [ebp-8Ch] BYREF
  GameData *v17; // [esp+10Ch] [ebp-Ch]
  int nOffsetX; // [esp+110h] [ebp-8h]
  int nEdgeSize; // [esp+114h] [ebp-4h]

  v17 = this;
  nEdgeSize = (int)pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  v3 = (const char *)nEdgeSize;
  if ( Token != OPERATOR || _V_stricmp(s1: (const char *)nEdgeSize, s2: "(") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "(", v3);
    return 0;
  }
  v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v5 == TOKENSTRINGTOOLONG )
  {
LABEL_8:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v5 != INTEGER )
    goto LABEL_10;
  nEdgeSize = atoi(nptr: szToken);
  v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v6 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
  {
LABEL_14:
    GDError(tr, error: "expecting '%s', but found '%s'", ",", pszStore);
    return 0;
  }
  v7 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v7 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v7 != INTEGER )
    goto LABEL_10;
  nOffsetX = atoi(nptr: szToken);
  v8 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v8 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v8 != OPERATOR || _V_stricmp(s1: pszStore, s2: ",") != 0 )
    goto LABEL_14;
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_8;
  if ( v9 != INTEGER )
  {
LABEL_10:
    GDError(tr, error: "expecting %s", "integer");
    return 0;
  }
  v10 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ",") == 0 )
    return 0;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
    return 0;
  v11 = atoi(nptr: szToken);
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
    return 0;
  v12 = v17;
  v13 = nEdgeSize;
  v14 = nOffsetX;
  v17->m_nGridNavOffsetY = v10;
  v12->m_nTraceHeight = v11;
  v12->m_bGridNavActive = true;
  v12->m_nGridNavEdgeSize = v13;
  v12->m_nGridNavOffsetX = v14;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443E40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443EF0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48AF64 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_48AF64;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00443F50
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48AF70 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_48AF70;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00443FB0
// Name: public: void GameData::ClearData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::ClearData(GameData *this)
{
  int m_Size; // eax
  int v3; // esi
  GDclass **m_pMemory; // ecx
  GDclass *v5; // edi
  int nCount; // [esp+8h] [ebp-4h]

  m_Size = this->m_Classes.m_Size;
  v3 = 0;
  nCount = m_Size;
  if ( m_Size <= 0 )
  {
    this->m_Classes.m_Size = 0;
  }
  else
  {
    do
    {
      m_pMemory = this->m_Classes.m_Memory.m_pMemory;
      v5 = m_pMemory[v3];
      if ( v5 != nullptr )
      {
        GDclass::~GDclass(this: m_pMemory[v3]);
        free(pMem: v5);
        m_Size = nCount;
      }
      ++v3;
    }
    while ( v3 < m_Size );
    this->m_Classes.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444000
// Name: public: class GDclass __near * GameData::ClassForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::ClassForName(GameData *this, const char *pszName, int *piIndex)
{
  int v3; // edi
  GDclass **i; // esi
  GDclass *result; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Classes.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  for ( i = this->m_Classes.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( strcmp((*i)->m_szName, pszName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  if ( piIndex != nullptr )
    *piIndex = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00444070
// Name: public: class GDclass __near * GameData::BeginInstanceRemap(char const __near *,char const __near *,class Vector __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GameData::BeginInstanceRemap(
        GameData *this,
        const char *pszClassName,
        const char *pszInstancePrefix,
        Vector *Origin,
        QAngle *Angle)
{
  const char *v6; // eax
  char v7; // cl
  GDclass *m_InstanceClass; // edi
  int v9; // ebx
  const char *v10; // edi
  GDclass *v11; // edi
  GDclass *v12; // eax
  GDclass *v13; // eax
  const char **v14; // edi
  GDclass *v15; // eax

  this->m_InstanceOrigin = *Origin;
  this->m_InstanceAngle = *Angle;
  AngleMatrix(angles: &this->m_InstanceAngle, position: &this->m_InstanceOrigin, matrix: &this->m_InstanceMat);
  v6 = pszInstancePrefix;
  do
  {
    v7 = *v6;
    v6[(char *)this - pszInstancePrefix + 164] = *v6;
    ++v6;
  }
  while ( v7 != 0 );
  m_InstanceClass = this->m_InstanceClass;
  v9 = 0;
  if ( m_InstanceClass != nullptr )
  {
    GDclass::~GDclass(this: this->m_InstanceClass);
    free(pMem: m_InstanceClass);
    this->m_InstanceClass = nullptr;
  }
  v10 = pszClassName;
  if ( _V_stricmp(s1: pszClassName, s2: "info_overlay_accessor") == 0 )
    v10 = "info_overlay";
  v11 = GameData::ClassForName(this, pszName: v10, piIndex: nullptr);
  if ( v11 != nullptr )
  {
    v12 = (GDclass *)operator new(nSize: 0x2D8u);
    if ( v12 != nullptr )
      v13 = GDclass::GDclass(this: v12);
    else
      v13 = nullptr;
    this->m_InstanceClass = v13;
    v13->Parent = this;
    GDclass::AddBase(this: this->m_InstanceClass, pBase: v11);
    if ( RequiredKeys[0] != nullptr )
    {
      v14 = RequiredKeys;
      do
      {
        if ( GDclass::VarForName(this: this->m_InstanceClass, pszName: *v14, piIndex: nullptr) == nullptr )
        {
          v15 = GameData::ClassForName(this, pszName: *v14, piIndex: nullptr);
          if ( v15 != nullptr )
            GDclass::AddBase(this: this->m_InstanceClass, pBase: v15);
        }
        v14 = &RequiredKeys[++v9];
      }
      while ( *v14 != nullptr );
    }
    return this->m_InstanceClass;
  }
  else
  {
    this->m_InstanceClass = nullptr;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004441C0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48AF64 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00444220
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48AF64 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00444280
// Name: protected: void CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<int,int,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,int,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444370
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48AF70 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004443D0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_48AF70 = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00444430
// Name: protected: void CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444520
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444690
// Name: protected: void CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00444780
// Name: protected: void CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00444870
// Name: protected: void CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00444960
// Name: protected: void CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00444A50
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<int,int,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,int,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00444B50
// Name: public: void CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444C00
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[v4].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00444D00
// Name: public: void CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444DB0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF64 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF64 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF64 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF64 = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF64 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF64 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004453A0
// Name: protected: void CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_48AF70 = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF70 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF70 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_48AF70 = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF70 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_48AF70 = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445990
// Name: public: bool CUtlMap<int,int,unsigned short>::IsValidIndex(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMap<int,int,unsigned short>::IsValidIndex(
        CUtlMap<int,int,unsigned short> *this,
        unsigned __int16 i)
{
  return i < this->m_Tree.m_Elements.m_nAllocationCount
      && i <= this->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this: &this->m_Tree,
           i) != i;
}

//------------------------------------------------------------------------------
// Address: 0x004459D0
// Name: public: CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445A40
// Name: protected: void CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445AC0
// Name: public: void GameData::BeginMapInstance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::BeginMapInstance(GameData *this)
{
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NodeRemap.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00445AD0
// Name: public: bool GameData::LoadFGDMaterialExclusions(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDMaterialExclusions(GameData *this, TokenReader *tr)
{
  TokenReader *v2; // ebx
  trtoken_t Token; // eax
  char *v6; // edi
  trtoken_t v7; // eax
  int v8; // edi
  int v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  FGDMatExlcusions_s *m_pMemory; // ecx
  int v13; // eax
  int v14; // edi
  trtoken_t v15; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  char *s1; // [esp+90h] [ebp-4h]

  v2 = tr;
  s1 = szToken;
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
LABEL_2:
    GDError(tr: v2, error: "unterminated string or string too long");
    return 0;
  }
  v6 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", v6);
    return 0;
  }
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
  {
    do
    {
      s1 = szToken;
      v7 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 128);
      if ( v7 == TOKENSTRINGTOOLONG )
      {
        GDError(tr: v2, error: "unterminated string or string too long");
      }
      else if ( v7 == STRING || v7 == INTEGER )
      {
        v8 = 0;
        if ( this->m_FGDMaterialExclusions.m_Size <= 0 )
        {
LABEL_18:
          m_Size = this->m_FGDMaterialExclusions.m_Size;
          m_nAllocationCount = this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<FGDMatExlcusions_s,int>::Grow(
              this: &this->m_FGDMaterialExclusions.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_FGDMaterialExclusions.m_Size;
          m_pMemory = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          v13 = this->m_FGDMaterialExclusions.m_Size - m_Size - 1;
          this->m_FGDMaterialExclusions.m_pElements = this->m_FGDMaterialExclusions.m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 261 * v13);
          v14 = m_Size;
          V_strncpy(
            pDest: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].szDirectory,
            pSrc: szToken,
            maxLen: 260);
          this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14].bUserGenerated = false;
        }
        else
        {
          v9 = 0;
          while ( _V_stricmp(s1: szToken, s2: this->m_FGDMaterialExclusions.m_Memory.m_pMemory[v9].szDirectory) != 0 )
          {
            ++v8;
            ++v9;
            if ( v8 >= this->m_FGDMaterialExclusions.m_Size )
            {
              v2 = tr;
              goto LABEL_18;
            }
          }
          v2 = tr;
        }
      }
      else
      {
        GDError(tr: v2, error: "expecting %s", "string");
      }
    }
    while ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 128) != OPERATOR );
  }
  v15 = TokenReader::NextToken(this: v2, pszStore: szToken, nSize: 129);
  if ( v15 == TOKENSTRINGTOOLONG )
    goto LABEL_2;
  if ( v15 != OPERATOR || _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    GDError(tr: v2, error: "expecting '%s', but found '%s'", "]", szToken);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445CF0
// Name: public: CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,class CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445D60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short,class CUtlMap<int,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(struct CUtlMap<int,int,unsigned short>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,int,unsigned short>::Node_t *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode((CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short> > *)this);
  v4 = v3;
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00445EA0
// Name: public: bool GameData::RemapKeyValue(char const __near *,char const __near *,char __near *,enum GameData::TNameFixup)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GameData::RemapKeyValue(
        GameData *this,
        const char *pszKey,
        char *pszInValue,
        char *pszOutValue,
        GameData::TNameFixup NameFixup)
{
  GameData *v5; // esi
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v10; // eax
  int v11; // edx
  float *p_m_Data; // esi
  unsigned __int16 v13; // cx
  int v14; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v15; // eax
  unsigned __int16 v16; // dx
  int v17; // edx
  float *v18; // esi
  unsigned __int16 v19; // cx
  int v20; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v21; // eax
  unsigned __int16 v22; // dx
  int v23; // edx
  float *v24; // esi
  unsigned __int16 v25; // cx
  int v26; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v27; // eax
  unsigned __int16 v28; // dx
  int v29; // edx
  float *v30; // esi
  unsigned __int16 v31; // cx
  int v32; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v33; // eax
  unsigned __int16 v34; // dx
  int v35; // edx
  float *v36; // esi
  unsigned __int16 v37; // cx
  int v38; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v39; // eax
  unsigned __int16 v40; // dx
  int v41; // edx
  float *v42; // esi
  unsigned __int16 v43; // cx
  int v44; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v45; // eax
  unsigned __int16 v46; // dx
  int v47; // edx
  float *v48; // esi
  unsigned __int16 v49; // cx
  int v50; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v51; // eax
  unsigned __int16 v52; // dx
  int v53; // edx
  float *v54; // esi
  unsigned __int16 v55; // cx
  int v56; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v57; // eax
  unsigned __int16 v58; // dx
  int v59; // edx
  float *v60; // esi
  unsigned __int16 v61; // cx
  int v62; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v63; // eax
  unsigned __int16 v64; // dx
  int v65; // edx
  float *v66; // esi
  unsigned __int16 v67; // cx
  int v68; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v69; // eax
  unsigned __int16 v70; // dx
  int v71; // edx
  float *v72; // esi
  unsigned __int16 v73; // cx
  int v74; // esi
  UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short> *v75; // eax
  unsigned __int16 v76; // dx
  int v77; // edx
  float *v78; // esi
  GDclass *m_InstanceClass; // ecx
  GDinputvariable *v81; // eax
  const matrix3x4_t *p_m_InstanceMat; // esi
  const matrix3x4_t *v83; // esi
  unsigned __int16 v84; // ax
  int v85; // ebx
  float v86; // ebx
  matrix3x4_t localMatrix; // [esp+24h] [ebp-84h] BYREF
  matrix3x4_t angToWorld; // [esp+54h] [ebp-54h] BYREF
  QAngle outAngles; // [esp+84h] [ebp-24h] BYREF
  GDIV_TYPE KVType; // [esp+90h] [ebp-18h]
  QAngle inAngles; // [esp+94h] [ebp-14h] BYREF
  unsigned __int16 parent[3]; // [esp+A0h] [ebp-8h] BYREF
  bool leftchild; // [esp+A7h] [ebp-1h] BYREF
  int KVRemapIndex; // [esp+B0h] [ebp+8h]

  v5 = this;
  KVType = (GDIV_TYPE)this;
  if ( RemapOperation.m_Tree.m_NumElements == 0 )
  {
    if ( RemapOperation.m_Tree.m_LessFunc.m_LessFunc == nullptr )
      RemapOperation.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const GDIV_TYPE *, const GDIV_TYPE *))CDefOps<int>::LessFunc;
    inAngles.y = 0.0;
    LODWORD(inAngles.z) = 2;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v6 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v7 = parent[0];
    v8 = v6;
    v9 = v6;
    v10 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v9];
    v10->m_Right = -1;
    v10->m_Left = -1;
    v10->m_Parent = v7;
    v10->m_Tag = 0;
    if ( v7 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v8;
    }
    else
    {
      v11 = v7;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v11].m_Left = v8;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v11].m_Right = v8;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v8);
    ++RemapOperation.m_Tree.m_NumElements;
    p_m_Data = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v9].m_Data;
    if ( p_m_Data != nullptr )
    {
      *p_m_Data = inAngles.y;
      p_m_Data[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 6;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v13 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v14 = v13;
    v15 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v13];
    v16 = parent[0];
    v15->m_Right = -1;
    v15->m_Left = -1;
    v15->m_Parent = v16;
    v15->m_Tag = 0;
    if ( v16 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v13;
    }
    else
    {
      v17 = v16;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v17].m_Left = v13;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v17].m_Right = v13;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v13);
    ++RemapOperation.m_Tree.m_NumElements;
    v18 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v14].m_Data;
    if ( v18 != nullptr )
    {
      *v18 = inAngles.y;
      v18[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 1;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v19 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v20 = v19;
    v21 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v19];
    v22 = parent[0];
    v21->m_Right = -1;
    v21->m_Left = -1;
    v21->m_Parent = v22;
    v21->m_Tag = 0;
    if ( v22 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v19;
    }
    else
    {
      v23 = v22;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v23].m_Left = v19;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v23].m_Right = v19;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v19);
    ++RemapOperation.m_Tree.m_NumElements;
    v24 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v20].m_Data;
    if ( v24 != nullptr )
    {
      *v24 = inAngles.y;
      v24[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 3;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v25 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v26 = v25;
    v27 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v25];
    v28 = parent[0];
    v27->m_Right = -1;
    v27->m_Left = -1;
    v27->m_Parent = v28;
    v27->m_Tag = 0;
    if ( v28 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v25;
    }
    else
    {
      v29 = v28;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v29].m_Left = v25;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v29].m_Right = v25;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v25);
    ++RemapOperation.m_Tree.m_NumElements;
    v30 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v26].m_Data;
    if ( v30 != nullptr )
    {
      *v30 = inAngles.y;
      v30[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 17;
    inAngles.z = 0.0;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v31 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v32 = v31;
    v33 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v31];
    v34 = parent[0];
    v33->m_Right = -1;
    v33->m_Left = -1;
    v33->m_Parent = v34;
    v33->m_Tag = 0;
    if ( v34 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v31;
    }
    else
    {
      v35 = v34;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v35].m_Left = v31;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v35].m_Right = v31;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v31);
    ++RemapOperation.m_Tree.m_NumElements;
    v36 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v32].m_Data;
    if ( v36 != nullptr )
    {
      *v36 = inAngles.y;
      v36[1] = inAngles.z;
    }
    LODWORD(inAngles.z) = 1;
    LODWORD(inAngles.y) = 23;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v37 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v38 = v37;
    v39 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v37];
    v40 = parent[0];
    v39->m_Right = -1;
    v39->m_Left = -1;
    v39->m_Parent = v40;
    v39->m_Tag = 0;
    if ( v40 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v37;
    }
    else
    {
      v41 = v40;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v41].m_Left = v37;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v41].m_Right = v37;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v37);
    ++RemapOperation.m_Tree.m_NumElements;
    v42 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v38].m_Data;
    if ( v42 != nullptr )
    {
      *v42 = inAngles.y;
      v42[1] = inAngles.z;
    }
    LODWORD(inAngles.z) = 1;
    LODWORD(inAngles.y) = 24;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v43 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v44 = v43;
    v45 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v43];
    v46 = parent[0];
    v45->m_Right = -1;
    v45->m_Left = -1;
    v45->m_Parent = v46;
    v45->m_Tag = 0;
    if ( v46 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v43;
    }
    else
    {
      v47 = v46;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v47].m_Left = v43;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v47].m_Right = v43;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v43);
    ++RemapOperation.m_Tree.m_NumElements;
    v48 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v44].m_Data;
    if ( v48 != nullptr )
    {
      *v48 = inAngles.y;
      v48[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 25;
    LODWORD(inAngles.z) = 2;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v49 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v50 = v49;
    v51 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v49];
    v52 = parent[0];
    v51->m_Right = -1;
    v51->m_Left = -1;
    v51->m_Parent = v52;
    v51->m_Tag = 0;
    if ( v52 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v49;
    }
    else
    {
      v53 = v52;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v53].m_Left = v49;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v53].m_Right = v49;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v49);
    ++RemapOperation.m_Tree.m_NumElements;
    v54 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v50].m_Data;
    if ( v54 != nullptr )
    {
      *v54 = inAngles.y;
      v54[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 32;
    LODWORD(inAngles.z) = 3;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v55 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v56 = v55;
    v57 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v55];
    v58 = parent[0];
    v57->m_Right = -1;
    v57->m_Left = -1;
    v57->m_Parent = v58;
    v57->m_Tag = 0;
    if ( v58 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v55;
    }
    else
    {
      v59 = v58;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v59].m_Left = v55;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v59].m_Right = v55;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v55);
    ++RemapOperation.m_Tree.m_NumElements;
    v60 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v56].m_Data;
    if ( v60 != nullptr )
    {
      *v60 = inAngles.y;
      v60[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 27;
    LODWORD(inAngles.z) = 4;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v61 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v62 = v61;
    v63 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v61];
    v64 = parent[0];
    v63->m_Right = -1;
    v63->m_Left = -1;
    v63->m_Parent = v64;
    v63->m_Tag = 0;
    if ( v64 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v61;
    }
    else
    {
      v65 = v64;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v65].m_Left = v61;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v65].m_Right = v61;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v61);
    ++RemapOperation.m_Tree.m_NumElements;
    v66 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v62].m_Data;
    if ( v66 != nullptr )
    {
      *v66 = inAngles.y;
      v66[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 36;
    LODWORD(inAngles.z) = 4;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v67 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v68 = v67;
    v69 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v67];
    v70 = parent[0];
    v69->m_Right = -1;
    v69->m_Left = -1;
    v69->m_Parent = v70;
    v69->m_Tag = 0;
    if ( v70 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v67;
    }
    else
    {
      v71 = v70;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v71].m_Left = v67;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v71].m_Right = v67;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v67);
    ++RemapOperation.m_Tree.m_NumElements;
    v72 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v68].m_Data;
    if ( v72 != nullptr )
    {
      *v72 = inAngles.y;
      v72[1] = inAngles.z;
    }
    LODWORD(inAngles.y) = 33;
    LODWORD(inAngles.z) = 5;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &RemapOperation.m_Tree,
      insert: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y,
      parent,
      &leftchild);
    v73 = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &RemapOperation.m_Tree);
    v74 = v73;
    v75 = &RemapOperation.m_Tree.m_Elements.m_pMemory[v73];
    v76 = parent[0];
    v75->m_Right = -1;
    v75->m_Left = -1;
    v75->m_Parent = v76;
    v75->m_Tag = 0;
    if ( v76 == 0xFFFF )
    {
      RemapOperation.m_Tree.m_Root = v73;
    }
    else
    {
      v77 = v76;
      if ( leftchild )
        RemapOperation.m_Tree.m_Elements.m_pMemory[v77].m_Left = v73;
      else
        RemapOperation.m_Tree.m_Elements.m_pMemory[v77].m_Right = v73;
    }
    CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &RemapOperation.m_Tree,
      elem: v73);
    ++RemapOperation.m_Tree.m_NumElements;
    v78 = (float *)&RemapOperation.m_Tree.m_Elements.m_pMemory[v74].m_Data;
    if ( v78 != nullptr )
    {
      *v78 = inAngles.y;
      v78[1] = inAngles.z;
    }
    v5 = (GameData *)KVType;
  }
  m_InstanceClass = v5->m_InstanceClass;
  if ( m_InstanceClass == nullptr )
    return false;
  v81 = GDclass::VarForName(this: m_InstanceClass, pszName: pszKey, piIndex: nullptr);
  if ( v81 == nullptr )
    return false;
  KVType = v81->m_eType;
  LODWORD(inAngles.y) = KVType;
  KVRemapIndex = CUtlRBTree<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short,CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &RemapOperation.m_Tree,
                   search: (const CUtlMap<enum GDIV_TYPE,enum tRemapOperation,unsigned short>::Node_t *)&inAngles.y);
  if ( KVRemapIndex == 0xFFFF )
    return false;
  strcpy(pszOutValue, pszInValue);
  switch ( RemapOperation.m_Tree.m_Elements.m_pMemory[(unsigned __int16)KVRemapIndex].m_Data.elem )
  {
    case REMAP_NAME:
      if ( v5->m_nRemapStage != 1 )
        return false;
      if ( KVType != ivInstanceVariable )
        GameData::RemapNameField(this: v5, pszInValue, pszOutValue, NameFixup);
      break;
    case REMAP_POSITION:
      if ( v5->m_nRemapStage != 1 )
        return false;
      memset(&inAngles, 0, sizeof(inAngles));
      sscanf(string: pszInValue, format: "%f %f %f", &inAngles, &inAngles.y, &inAngles.z);
      VectorTransform(in1: &inAngles.x, in2: &v5->m_InstanceMat, out: &outAngles.x);
      sprintf(string: pszOutValue, format: "%g %g %g", outAngles.x, outAngles.y, outAngles.z);
      break;
    case REMAP_ANGLE:
      if ( v5->m_nRemapStage != 1 )
        return false;
      if ( v5->m_InstanceAngle.x != 0.0 || v5->m_InstanceAngle.y != 0.0 || v5->m_InstanceAngle.z != 0.0 )
      {
        memset(&inAngles, 0, sizeof(inAngles));
        sscanf(string: pszInValue, format: "%f %f %f", &inAngles, &inAngles.y, &inAngles.z);
        AngleMatrix(angles: &inAngles, matrix: &angToWorld);
        p_m_InstanceMat = &v5->m_InstanceMat;
        ConcatTransforms(in1: p_m_InstanceMat, in2: &angToWorld, out: &localMatrix);
        MatrixAngles(a1: (int)p_m_InstanceMat, matrix: &localMatrix, angles: &outAngles.x);
        sprintf(string: pszOutValue, format: "%g %g %g", outAngles.x, outAngles.y, outAngles.z);
      }
      break;
    case REMAP_ANGLE_NEGATIVE_PITCH:
      if ( v5->m_nRemapStage != 1 )
        return false;
      if ( v5->m_InstanceAngle.x != 0.0 || v5->m_InstanceAngle.y != 0.0 || v5->m_InstanceAngle.z != 0.0 )
      {
        memset(&inAngles, 0, sizeof(inAngles));
        sscanf(string: pszInValue, format: "%f", &inAngles);
        LODWORD(inAngles.x) ^= _mask__NegFloat_;
        AngleMatrix(angles: &inAngles, matrix: &localMatrix);
        v83 = &v5->m_InstanceMat;
        ConcatTransforms(in1: v83, in2: &localMatrix, out: &angToWorld);
        MatrixAngles(a1: (int)v83, matrix: &angToWorld, angles: &outAngles.x);
        sprintf(string: pszOutValue, format: "%g", COERCE_FLOAT(LODWORD(outAngles.x) ^ _mask__NegFloat_));
      }
      break;
    case REMAP_NODE:
      LODWORD(inAngles.y) = atoi(nptr: pszInValue);
      v84 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &v5->m_NodeRemap.m_Tree,
              search: (const CUtlMap<int,int,unsigned short>::Node_t *)&inAngles.y);
      v85 = v84;
      if ( CUtlMap<int,int,unsigned short>::IsValidIndex(this: &v5->m_NodeRemap, i: v84) )
      {
        v86 = *(float *)&v5->m_NodeRemap.m_Tree.m_Elements.m_pMemory[v85].m_Data.elem;
      }
      else
      {
        v86 = *(float *)&v5->m_nNextNodeID;
        v5->m_nNextNodeID = LODWORD(v86) + 1;
        LODWORD(inAngles.y) = atoi(nptr: pszInValue);
        inAngles.z = v86;
        CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &v5->m_NodeRemap.m_Tree,
          insert: (const CUtlMap<int,int,unsigned short>::Node_t *)&inAngles.y);
      }
      sprintf(string: pszOutValue, format: "%d", v86);
      break;
    case REMAP_INSTANCE_VARIABLE:
      if ( v5->m_nRemapStage != 1 )
        return false;
      GameData::RemapInstanceField(this: v5, pszInValue, pszOutValue, NameFixup);
      break;
    default:
      return _V_stricmp(s1: pszInValue, s2: pszOutValue) != 0;
  }
  return _V_stricmp(s1: pszInValue, s2: pszOutValue) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00446C70
// Name: public: bool GameData::LoadFGDAutoVisGroups(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameData::LoadFGDAutoVisGroups(GameData *this, TokenReader *tr)
{
  GameData *v3; // edi
  trtoken_t Token; // eax
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char *v8; // esi
  trtoken_t v9; // eax
  trtoken_t v10; // eax
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v12; // esi
  int m_Size; // edx
  int v14; // edi
  trtoken_t v15; // eax
  trtoken_t v16; // eax
  CUtlMemory<BSPCluster_t,int> *v17; // esi
  BSPCluster_t *v18; // edi
  int m_nAllocationCount; // eax
  BSPCluster_t *v20; // ecx
  int v21; // eax
  _DWORD *p_m_pLeafNode; // eax
  trtoken_t v23; // eax
  trtoken_t v24; // eax
  char *v25; // [esp-Ch] [ebp-130h]
  char pszStore[132]; // [esp+Ch] [ebp-118h] BYREF
  char szToken[128]; // [esp+90h] [ebp-94h] BYREF
  char *v28; // [esp+110h] [ebp-14h]
  int v29; // [esp+114h] [ebp-10h]
  int gindex; // [esp+118h] [ebp-Ch]
  GameData *v31; // [esp+11Ch] [ebp-8h]
  char *s1; // [esp+120h] [ebp-4h]
  char *tra; // [esp+12Ch] [ebp+8h]

  v3 = this;
  v31 = this;
  gindex = 0;
  s1 = pszStore;
  Token = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( Token == TOKENSTRINGTOOLONG )
  {
    GDError(tr, error: "unterminated string or string too long");
    goto LABEL_3;
  }
  v8 = s1;
  if ( Token != OPERATOR || _V_stricmp(s1, s2: "=") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "=", v8);
    goto LABEL_3;
  }
  v9 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( v9 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v9 != STRING && v9 != INTEGER )
  {
LABEL_16:
    GDError(tr, error: "expecting %s", "string");
    return 0;
  }
  gindex = CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
             this: &v3->m_FGDAutoVisGroups,
             elem: v3->m_FGDAutoVisGroups.m_Size);
  V_strncpy(pDest: v3->m_FGDAutoVisGroups.m_Memory.m_pMemory[gindex].szParent, pSrc: szToken, maxLen: 260);
  v10 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v10 == TOKENSTRINGTOOLONG )
  {
LABEL_46:
    GDError(tr, error: "unterminated string or string too long");
    return 0;
  }
  if ( v10 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
  {
    GDError(tr, error: "expecting '%s', but found '%s'", "[", pszStore);
    return 0;
  }
  while ( 1 )
  {
LABEL_3:
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      if ( v5 != TOKENSTRINGTOOLONG )
        break;
      GDError(tr, error: "unterminated string or string too long");
LABEL_5:
      v6 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
      if ( v6 == TOKENSTRINGTOOLONG )
        goto LABEL_46;
      if ( v6 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
        goto LABEL_8;
    }
    if ( v5 != STRING && v5 != INTEGER )
    {
      GDError(tr, error: "expecting %s", "string");
      goto LABEL_5;
    }
    m_pMemory = v3->m_FGDAutoVisGroups.m_Memory.m_pMemory;
    v12 = 280 * gindex;
    m_Size = m_pMemory[gindex].m_Classes.m_Size;
    s1 = (char *)(280 * gindex);
    v14 = 280
        * CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
            this: (CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *)&m_pMemory[gindex].m_Classes,
            elem: m_Size);
    v25 = &(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                        + v12))->szClass[v14];
    v29 = v14;
    V_strncpy(pDest: v25, pSrc: szToken, maxLen: 260);
    v15 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v15 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    v28 = pszStore;
    if ( v15 != OPERATOR || _V_stricmp(s1: pszStore, s2: "[") != 0 )
    {
      GDError(tr, error: "expecting '%s', but found '%s'", "[", v28);
      return 0;
    }
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    {
      while ( 1 )
      {
        v16 = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
        if ( v16 == TOKENSTRINGTOOLONG )
          goto LABEL_46;
        if ( v16 != STRING && v16 != INTEGER )
          goto LABEL_16;
        v17 = (CUtlMemory<BSPCluster_t,int> *)((char *)&(*(FGDVisGroupsBaseClass_s **)((char *)&v31->m_FGDAutoVisGroups.m_Memory.m_pMemory->m_Classes.m_Memory.m_pMemory
                                                                                     + v12))->szEntities
                                             + v14);
        tra = (char *)operator new(nSize: strlen(szToken) + 1);
        _V_strcpy(dest: tra, src: szToken);
        v18 = v17[1].m_pMemory;
        m_nAllocationCount = v17->m_nAllocationCount;
        if ( (int)&v18->m_pLeafNode + 1 > m_nAllocationCount )
          CUtlMemory<ColorRGBExp32,int>::Grow(this: v17, num: (int)&v18->m_pLeafNode - m_nAllocationCount + 1);
        ++v17[1].m_pMemory;
        v20 = v17->m_pMemory;
        v21 = (char *)v17[1].m_pMemory - (char *)v18 - 1;
        v17[1].m_nAllocationCount = (int)v17->m_pMemory;
        if ( v21 > 0 )
          _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
        p_m_pLeafNode = &v17->m_pMemory[(_DWORD)v18].m_pLeafNode;
        if ( p_m_pLeafNode != nullptr )
          *p_m_pLeafNode = tra;
        if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) == OPERATOR )
          break;
        v12 = (int)s1;
        v14 = v29;
      }
    }
    v23 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
    if ( v23 == TOKENSTRINGTOOLONG )
      goto LABEL_46;
    if ( v23 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
      goto LABEL_8;
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != STRING )
      break;
    v3 = v31;
  }
  v24 = TokenReader::NextToken(this: tr, pszStore, nSize: 129);
  if ( v24 == TOKENSTRINGTOOLONG )
    goto LABEL_46;
  if ( v24 != OPERATOR || _V_stricmp(s1: pszStore, s2: "]") != 0 )
  {
LABEL_8:
    GDError(tr, error: "expecting '%s', but found '%s'", "]", pszStore);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00447130
// Name: public: GameData::GameData(void)
// Source: json
//------------------------------------------------------------------------------
GameData *__thiscall GameData::GameData(GameData *this)
{
  this->m_FGDMaterialExclusions.m_Memory.m_pMemory = nullptr;
  this->m_FGDMaterialExclusions.m_Memory.m_nAllocationCount = 0;
  this->m_FGDMaterialExclusions.m_Memory.m_nGrowSize = 0;
  this->m_FGDMaterialExclusions.m_Size = 0;
  this->m_FGDMaterialExclusions.m_pElements = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_pMemory = nullptr;
  this->m_FGDAutoVisGroups.m_Memory.m_nAllocationCount = 0;
  this->m_FGDAutoVisGroups.m_Memory.m_nGrowSize = 0;
  this->m_FGDAutoVisGroups.m_Size = 0;
  this->m_FGDAutoVisGroups.m_pElements = nullptr;
  this->m_Classes.m_Memory.m_pMemory = nullptr;
  this->m_Classes.m_Memory.m_nAllocationCount = 0;
  this->m_Classes.m_Memory.m_nGrowSize = 0;
  this->m_Classes.m_Size = 0;
  this->m_Classes.m_pElements = nullptr;
  this->m_NodeRemap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
  this->m_NodeRemap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_NodeRemap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_NodeRemap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_NodeRemap.m_Tree.m_Root = -1;
  this->m_NodeRemap.m_Tree.m_NumElements = 0;
  this->m_NodeRemap.m_Tree.m_FirstFree = -1;
  this->m_NodeRemap.m_Tree.m_LastAlloc.index = -1;
  this->m_NodeRemap.m_Tree.m_pElements = this->m_NodeRemap.m_Tree.m_Elements.m_pMemory;
  this->m_nMaxMapCoord = 0x2000;
  this->m_nMinMapCoord = -8192;
  this->m_InstanceClass = nullptr;
  this->m_bGridNavActive = false;
  this->m_nGridNavEdgeSize = 0;
  this->m_nGridNavOffsetX = 0;
  this->m_nGridNavOffsetY = 0;
  this->m_nTraceHeight = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004471E0
// Name: public: GameData::~GameData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameData::~GameData(GameData *this)
{
  GameData::ClearData(this);
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_NodeRemap.m_Tree);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_Classes);
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(this: &this->m_FGDAutoVisGroups);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>((CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00447210
// Name: public: int GameData::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameData::Load(GameData *this, char *pszFilename)
{
  GameData *v2; // esi
  char *v3; // edi
  trtoken_t v5; // eax
  trtoken_t v6; // eax
  char v7; // al
  GDclass *v8; // eax
  GDclass *v9; // ebx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v12; // edi
  GDclass **m_pMemory; // ecx
  int v14; // eax
  GDclass **v15; // edi
  int v16; // edi
  int v17; // eax
  GDclass **v18; // ecx
  int v19; // eax
  GDclass **v20; // edi
  char justPath[260]; // [esp+8h] [ebp-3E0h] BYREF
  char loadFilename[260]; // [esp+10Ch] [ebp-2DCh] BYREF
  TokenReader tr; // [esp+210h] [ebp-1D8h] BYREF
  char szToken[128]; // [esp+360h] [ebp-88h] BYREF
  GameData *v25; // [esp+3E0h] [ebp-8h]
  int nExistingClassIndex; // [esp+3E4h] [ebp-4h] BYREF

  v2 = this;
  v25 = this;
  TokenReader::TokenReader(this: &tr);
  v3 = pszFilename;
  if ( GetFileAttributesA(lpFileName: pszFilename) == -1 || !TokenReader::Open(this: &tr, pszFilename) )
  {
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  if ( tr.m_nErrorCount < 5 )
  {
    while ( 1 )
    {
      v5 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
      if ( v5 == TOKENEOF )
        break;
      if ( (v5 != OPERATOR || _V_stricmp(s1: szToken, s2: "@") != 0) && GDError(&tr, error: "expected @") == 0
        || TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128) != IDENT
        && GDError(&tr, error: "expected identifier after @") == 0 )
      {
        goto LABEL_83;
      }
      if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0
        && _V_stricmp(s1: szToken, s2: "pointclass") != 0
        && _V_stricmp(s1: szToken, s2: "solidclass") != 0
        && _V_stricmp(s1: szToken, s2: "keyframeclass") != 0
        && _V_stricmp(s1: szToken, s2: "moveclass") != 0
        && _V_stricmp(s1: szToken, s2: "npcclass") != 0
        && _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
      {
        if ( _V_stricmp(s1: szToken, s2: "include") != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "mapsize") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "gridnav") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "materialexclusion") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "autovisgroup") != 0 )
                {
                  GDError(&tr, error: "unrecognized section name %s", szToken);
                  TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
                  goto LABEL_80;
                }
                v7 = GameData::LoadFGDAutoVisGroups(this: v2, &tr);
              }
              else
              {
                v7 = GameData::LoadFGDMaterialExclusions(this: v2, &tr);
              }
            }
            else
            {
              v7 = GameData::ParseGridNav(this: v2, &tr);
            }
          }
          else
          {
            v7 = GameData::ParseMapSize(this: v2, &tr);
          }
          if ( v7 == 0 )
            TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
        }
        else
        {
          nExistingClassIndex = (int)szToken;
          v6 = TokenReader::NextToken(this: &tr, pszStore: szToken, nSize: 128);
          if ( v6 == TOKENSTRINGTOOLONG )
          {
            GDError(&tr, error: "unterminated string or string too long");
          }
          else if ( v6 == STRING || v6 == INTEGER )
          {
            if ( V_ExtractFilePath(path: v3, dest: justPath, destSize: 260) )
              V_snprintf(pDest: loadFilename, maxLen: 260, pFormat: "%s%s", justPath, szToken);
            else
              V_strncpy(pDest: loadFilename, pSrc: szToken, maxLen: 260);
            if ( GameData::Load(this: v2, pszFilename: loadFilename) == 0
              && GameData::Load(this: v2, pszFilename: szToken) == 0 )
            {
              GDError(&tr, error: "error including file: %s", szToken);
            }
          }
          else
          {
            GDError(&tr, error: "expecting %s", "string");
          }
        }
      }
      else
      {
        v8 = (GDclass *)operator new(nSize: 0x2D8u);
        if ( v8 != nullptr )
          v9 = GDclass::GDclass(this: v8);
        else
          v9 = nullptr;
        if ( GDclass::InitFromTokens(this: v9, &tr, pGD: v2) != 0 )
        {
          if ( _V_stricmp(s1: szToken, s2: "baseclass") != 0 )
          {
            if ( _V_stricmp(s1: szToken, s2: "pointclass") != 0 )
            {
              if ( _V_stricmp(s1: szToken, s2: "solidclass") != 0 )
              {
                if ( _V_stricmp(s1: szToken, s2: "npcclass") != 0 )
                {
                  if ( _V_stricmp(s1: szToken, s2: "filterclass") != 0 )
                  {
                    if ( _V_stricmp(s1: szToken, s2: "moveclass") != 0 )
                    {
                      if ( _V_stricmp(s1: szToken, s2: "keyframeclass") == 0 )
                        *(_WORD *)&v9->m_bKeyFrame = 257;
                    }
                    else
                    {
                      v9->m_bMove = true;
                      v9->m_bPoint = true;
                    }
                  }
                  else
                  {
                    v9->m_bPoint = true;
                    v9->m_bFilter = true;
                  }
                }
                else
                {
                  *(_WORD *)&v9->m_bPoint = 257;
                }
              }
              else
              {
                v9->m_bSolid = true;
              }
            }
            else
            {
              v9->m_bPoint = true;
            }
          }
          else
          {
            v9->m_bBase = true;
          }
          nExistingClassIndex = 0;
          if ( GameData::ClassForName(this: v2, pszName: v9->m_szName, piIndex: &nExistingClassIndex) != nullptr )
          {
            m_Size = v2->m_Classes.m_Size;
            m_nAllocationCount = v2->m_Classes.m_Memory.m_nAllocationCount;
            v12 = nExistingClassIndex + 1;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<ColorRGBExp32,int>::Grow(
                this: (CUtlMemory<BSPCluster_t,int> *)&v2->m_Classes,
                num: m_Size - m_nAllocationCount + 1);
            ++v2->m_Classes.m_Size;
            m_pMemory = v2->m_Classes.m_Memory.m_pMemory;
            v14 = v2->m_Classes.m_Size - v12 - 1;
            v2->m_Classes.m_pElements = m_pMemory;
            if ( v14 > 0 )
              _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v14);
            v15 = &v2->m_Classes.m_Memory.m_pMemory[v12];
            if ( v15 != nullptr )
              *v15 = v9;
            if ( v2->m_Classes.m_Size - nExistingClassIndex - 1 > 0 )
              _V_memmove(
                dest: &v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex],
                src: &v2->m_Classes.m_Memory.m_pMemory[nExistingClassIndex + 1],
                count: 4 * (v2->m_Classes.m_Size - nExistingClassIndex - 1));
            --v2->m_Classes.m_Size;
          }
          else
          {
            v16 = v2->m_Classes.m_Size;
            v17 = v2->m_Classes.m_Memory.m_nAllocationCount;
            if ( v16 + 1 > v17 )
              CUtlMemory<ColorRGBExp32,int>::Grow(
                this: (CUtlMemory<BSPCluster_t,int> *)&v2->m_Classes,
                num: v16 - v17 + 1);
            ++v2->m_Classes.m_Size;
            v18 = v2->m_Classes.m_Memory.m_pMemory;
            v19 = v2->m_Classes.m_Size - v16 - 1;
            v2->m_Classes.m_pElements = v18;
            if ( v19 > 0 )
              _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
            v20 = &v2->m_Classes.m_Memory.m_pMemory[v16];
            if ( v20 != nullptr )
              *v20 = v9;
          }
          v2 = v25;
        }
        else
        {
          TokenReader::IgnoreTill(this: &tr, ttype: OPERATOR, pszToken: "@");
          if ( v9 != nullptr )
          {
            GDclass::~GDclass(this: v9);
            free(pMem: v9);
          }
        }
      }
LABEL_80:
      if ( tr.m_nErrorCount >= 5 )
        break;
      v3 = pszFilename;
    }
  }
  if ( tr.m_nErrorCount > 0 )
  {
LABEL_83:
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 0;
  }
  else
  {
    TokenReader::Close(this: &tr);
    CUtlStreamBuffer::~CUtlStreamBuffer(this: &tr.m_file);
    return 1;
  }
}

} // namespace vbsp2
