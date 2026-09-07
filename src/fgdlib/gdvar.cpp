// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fgdlib/gdvar.cpp
// Functions: 14
// ============================================================

#include "fgdlib\gdvar.h"

//------------------------------------------------------------------------------
// Address: 0x101F4A50
// Name: public: enum trtoken_t GDinputvariable::GetStoreAsFromType(enum GDIV_TYPE)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetStoreAsFromType(GDinputvariable *this, GDIV_TYPE eType)
{
  int v2; // ecx
  unsigned int v3; // eax

  v2 = 0;
  v3 = 0;
  while ( *(InputOutputType_t *)((char *)&TypeMap[0].eType + v3) != eType )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return 2;
  }
  return *((_DWORD *)&TypeMap[1].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x101F4A90
// Name: public: enum GDIV_TYPE GDinputvariable::GetTypeFromToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetTypeFromToken(GDinputvariable *this, const char *pszToken)
{
  int v2; // edi
  unsigned int v3; // esi

  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pszToken, s2: *(const char **)((char *)&TypeMap[0].pszName + v3)) != 0 )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return -1;
  }
  return *((_DWORD *)&TypeMap[0].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x101F4AE0
// Name: public: char const __near * GDinputvariable::GetTypeText(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GDinputvariable::GetTypeText(GDinputvariable *this)
{
  GDIV_TYPE m_eType; // ecx
  int v2; // edx
  unsigned int v3; // eax

  m_eType = this->m_eType;
  v2 = 0;
  v3 = 0;
  while ( *(InputOutputType_t *)((char *)&TypeMap[0].eType + v3) != m_eType )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return "unknown";
  }
  return *((const char **)&TypeMap[0].pszName + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x101F4B20
// Name: public: void GDinputvariable::ToKeyValue(class MDkeyvalue __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::ToKeyValue(GDinputvariable *this, MDkeyvalue *pkv)
{
  char *m_szName; // eax
  char v3; // dl
  int v4; // edx
  unsigned int v5; // eax
  int v6; // eax
  char *m_szValue; // eax
  int v8; // edx
  char v9; // cl

  m_szName = this->m_szName;
  do
  {
    v3 = *m_szName;
    m_szName[(char *)pkv - this->m_szName] = *m_szName;
    ++m_szName;
  }
  while ( v3 != 0 );
  v4 = 0;
  v5 = 0;
  while ( *(InputOutputType_t *)((char *)&TypeMap[0].eType + v5) != this->m_eType )
  {
    v5 += 12;
    ++v4;
    if ( v5 >= 0x1BC )
      goto LABEL_8;
  }
  v6 = *((_DWORD *)&TypeMap[1].eType + 3 * v4);
  if ( v6 == 2 )
  {
LABEL_8:
    m_szValue = this->m_szValue;
    v8 = pkv->szValue - this->m_szValue;
    do
    {
      v9 = *m_szValue;
      m_szValue[v8] = *m_szValue;
      ++m_szValue;
    }
    while ( v9 != 0 );
    return;
  }
  if ( v6 == 1 )
    itoa(val: this->m_nValue, buf: pkv->szValue, radix: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x101F4BB0
// Name: public: static char const __near * GDinputvariable::GetVarTypeName(enum GDIV_TYPE)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GDinputvariable::GetVarTypeName(GDIV_TYPE eType)
{
  return *((const char **)&TypeMap[0].pszName + 3 * eType);
}

//------------------------------------------------------------------------------
// Address: 0x101F4C70
// Name: public: void GDinputvariable::ResetDefaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::ResetDefaults(GDinputvariable *this)
{
  int m_Size; // edx
  GDIVITEM *m_pMemory; // eax
  char *m_szDefault; // eax
  char v4; // cl

  if ( this->m_eType == ivFlags )
  {
    m_Size = this->m_Items.m_Size;
    this->m_nValue = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      do
      {
        if ( m_pMemory->bDefault != 0 )
          this->m_nValue |= m_pMemory->iValue;
        ++m_pMemory;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  else
  {
    this->m_nValue = this->m_nDefault;
    m_szDefault = this->m_szDefault;
    do
    {
      v4 = *m_szDefault;
      m_szDefault[136] = *m_szDefault;
      ++m_szDefault;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4CD0
// Name: public: char const __near * GDinputvariable::ItemStringForValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GDinputvariable::ItemStringForValue(GDinputvariable *this, const char *szValue)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  GDinputvariable *v6; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Items.m_Size;
  v3 = 0;
  v6 = this;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = 0; _V_stricmp(s1: this->m_Items.m_Memory.m_pMemory[i].szValue, s2: szValue) != 0; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
    this = v6;
  }
  return v6->m_Items.m_Memory.m_pMemory[v3].szCaption;
}

//------------------------------------------------------------------------------
// Address: 0x101F4D40
// Name: public: char const __near * GDinputvariable::ItemValueForString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GDinputvariable::ItemValueForString(GDinputvariable *this, const char *szString)
{
  int m_Size; // ebx
  int v3; // esi
  int i; // edi
  GDinputvariable *v6; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Items.m_Size;
  v3 = 0;
  v6 = this;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = 0; _V_stricmp(s1: this->m_Items.m_Memory.m_pMemory[i].szCaption, s2: szString) != 0; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
    this = v6;
  }
  return v6->m_Items.m_Memory.m_pMemory[v3].szValue;
}

//------------------------------------------------------------------------------
// Address: 0x101F4E30
// Name: public: GDinputvariable::GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::GDinputvariable(GDinputvariable *this)
{
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_szDefault[0] = 0;
  this->m_nDefault = 0;
  this->m_szValue[0] = 0;
  *(_WORD *)&this->m_bReportable = 0;
  this->m_pszDescription = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F4E70
// Name: public: GDinputvariable::GDinputvariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::GDinputvariable(
        GDinputvariable *this,
        const char *szType,
        const char *szName)
{
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_szDefault[0] = 0;
  this->m_nDefault = 0;
  this->m_szValue[0] = 0;
  *(_WORD *)&this->m_bReportable = 0;
  this->m_pszDescription = nullptr;
  this->m_eType = GDinputvariable::GetTypeFromToken(this, pszToken: szType);
  strcpy(this->m_szName, szName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F4EE0
// Name: public: GDinputvariable::~GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::~GDinputvariable(GDinputvariable *this)
{
  operator delete(p: this->m_pszDescription);
  this->m_Items.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101F4F10
// Name: public: class GDinputvariable __near & GDinputvariable::operator=(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::operator=(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // esi
  char *m_szName; // eax
  int v5; // edx
  char v6; // cl
  char *m_szLongName; // eax
  char v8; // cl
  char *m_szDefault; // eax
  char v10; // cl
  char *m_pszDescription; // eax
  int v12; // edi
  char *v13; // eax
  char *v14; // ecx
  char *v15; // edx
  char v16; // al
  int m_nAllocationCount; // eax
  char *v18; // esi
  int v19; // edi
  GDIVITEM *m_pMemory; // ecx
  int v21; // eax
  GDIVITEM *v22; // edi
  bool v23; // zf
  int m_Size; // [esp+Ch] [ebp-8h]
  int v26; // [esp+10h] [ebp-4h]

  v2 = Other;
  this->m_eType = Other->m_eType;
  m_szName = Other->m_szName;
  v5 = (char *)this - Other->m_szName;
  do
  {
    v6 = *m_szName;
    m_szName[v5 + 20] = *m_szName;
    ++m_szName;
  }
  while ( v6 != 0 );
  m_szLongName = Other->m_szLongName;
  do
  {
    v8 = *m_szLongName;
    m_szLongName[(char *)this - (char *)Other] = *m_szLongName;
    ++m_szLongName;
  }
  while ( v8 != 0 );
  m_szDefault = Other->m_szDefault;
  do
  {
    v10 = *m_szDefault;
    m_szDefault[(char *)this - (char *)Other] = *m_szDefault;
    ++m_szDefault;
  }
  while ( v10 != 0 );
  operator delete(p: this->m_pszDescription);
  m_pszDescription = Other->m_pszDescription;
  v12 = 0;
  if ( m_pszDescription != nullptr )
  {
    v13 = (char *)operator new[](nSize: strlen(m_pszDescription) + 1);
    this->m_pszDescription = v13;
    v14 = Other->m_pszDescription;
    v15 = v13;
    do
    {
      v16 = *v14;
      *v15++ = *v14++;
    }
    while ( v16 != 0 );
  }
  else
  {
    this->m_pszDescription = nullptr;
  }
  this->m_nDefault = Other->m_nDefault;
  this->m_bReportable = Other->m_bReportable;
  this->m_bReadOnly = Other->m_bReadOnly;
  this->m_Items.m_Size = 0;
  if ( Other->m_Items.m_Size > 0 )
  {
    v26 = 0;
    m_Size = Other->m_Items.m_Size;
    while ( 1 )
    {
      m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
      v18 = (char *)v2->m_Items.m_Memory.m_pMemory + v12;
      v19 = this->m_Items.m_Size;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Items.m_Memory, num: v19 - m_nAllocationCount + 1);
      ++this->m_Items.m_Size;
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      v21 = this->m_Items.m_Size - v19 - 1;
      this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(dest: &m_pMemory[v19 + 1], src: &m_pMemory[v19], count: 268 * v21);
      v22 = &this->m_Items.m_Memory.m_pMemory[v19];
      if ( v22 != nullptr )
        qmemcpy(v22, v18, sizeof(GDIVITEM));
      v12 = v26 + 268;
      v23 = m_Size-- == 1;
      v26 += 268;
      if ( v23 )
        break;
      v2 = Other;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F5090
// Name: public: int GDinputvariable::InitFromTokens(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDinputvariable::InitFromTokens(GDinputvariable *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  GDIV_TYPE TypeFromToken; // eax
  trtoken_t v6; // edi
  int StoreAsFromType; // eax
  char *m_szName; // eax
  char v9; // cl
  GDIV_TYPE v10; // eax
  unsigned __int8 *m_szDefault; // ebx
  const char *v12; // eax
  GDIV_TYPE m_eType; // eax
  GDIV_TYPE v14; // eax
  int v15; // eax
  char v16; // cl
  int v17; // eax
  int m_Size; // ecx
  int v19; // ecx
  GDIVITEM *m_pMemory; // eax
  int v21; // edx
  trtoken_t v22; // eax
  int v23; // eax
  char v24; // cl
  int v25; // eax
  char v26; // cl
  GDIVITEM ivi; // [esp+8h] [ebp-18Ch] BYREF
  char szToken[128]; // [esp+114h] [ebp-80h] BYREF

  if ( GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr) == 0
    || GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") == 0 )
  {
    return false;
  }
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( Token != OPERATOR )
  {
    TokenReader::Stuff(this: tr, eType: Token, pszToken: szToken);
  }
  else if ( strcmp(szToken, "*") == 0 )
  {
    this->m_bReportable = true;
  }
  if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: IDENT, pszExpecting: nullptr) == 0
    || GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
  {
    return false;
  }
  TypeFromToken = GDinputvariable::GetTypeFromToken(this, pszToken: szToken);
  this->m_eType = TypeFromToken;
  if ( TypeFromToken == ivBadType )
  {
    GDError(tr, error: "'%s' is not a valid variable type", szToken);
    return false;
  }
  v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
  if ( v6 == IDENT )
  {
    if ( _V_stricmp(s1: szToken, s2: "readonly") != 0
      || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128),
          this->m_bReadOnly = true,
          (v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128)) == IDENT) )
    {
      if ( _V_stricmp(s1: szToken, s2: "report") != 0 )
      {
LABEL_36:
        m_szName = this->m_szName;
        do
        {
          v9 = *m_szName;
          m_szName[65] = *m_szName;
          ++m_szName;
        }
        while ( v9 != 0 );
LABEL_38:
        if ( v6 != OPERATOR )
          goto LABEL_40;
        goto LABEL_39;
      }
      TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      this->m_bReportable = true;
      v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    }
  }
  if ( v6 != OPERATOR || _V_stricmp(s1: szToken, s2: ":") != 0 )
    goto LABEL_36;
  TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( this->m_eType == ivFlags )
  {
    GDError(tr, error: "flag sets do not have long names");
    return false;
  }
  if ( GDGetToken(tr, pszStore: this->m_szLongName, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
    return false;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    goto LABEL_40;
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR
      || _V_stricmp(s1: szToken, s2: ":") != 0 )
    {
      StoreAsFromType = GDinputvariable::GetStoreAsFromType(this, eType: this->m_eType);
      if ( StoreAsFromType == 2 )
      {
        if ( GDGetToken(tr, pszStore: this->m_szDefault, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
          return false;
      }
      else if ( StoreAsFromType == 1 )
      {
        if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
          return false;
        this->m_nDefault = atoi(nptr: szToken);
      }
      if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
        goto LABEL_40;
    }
  }
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
      return false;
    v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    goto LABEL_38;
  }
LABEL_39:
  if ( _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=") != 0 )
    {
      m_eType = this->m_eType;
      if ( m_eType == ivFlags || m_eType == ivChoices )
      {
        if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[") != 0 )
        {
          v14 = this->m_eType;
          if ( v14 == ivFlags )
          {
            while ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) == INTEGER )
            {
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr);
              sscanf(string: szToken, format: "%lu", &ivi);
              if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") == 0 )
                return false;
              if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
                return false;
              v15 = 0;
              do
              {
                v16 = szToken[v15];
                ivi.szCaption[v15++] = v16;
              }
              while ( v16 != 0 );
              if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") == 0
                || GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
              {
                return false;
              }
              v17 = atoi(nptr: szToken);
              m_Size = this->m_Items.m_Size;
              ivi.bDefault = v17 != 0;
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(this: &this->m_Items, elem: m_Size, src: &ivi);
            }
            v19 = 0;
            if ( this->m_Items.m_Size > 0 )
            {
              m_pMemory = this->m_Items.m_Memory.m_pMemory;
              v21 = this->m_Items.m_Size;
              do
              {
                if ( m_pMemory->bDefault != 0 )
                  v19 |= m_pMemory->iValue;
                ++m_pMemory;
                --v21;
              }
              while ( v21 != 0 );
            }
            this->m_nDefault = v19;
            V_snprintf(pDest: this->m_szDefault, maxLen: 129, pFormat: "%d", v19);
          }
          else if ( v14 == ivChoices )
          {
            while ( 1 )
            {
              v22 = TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0);
              if ( v22 != INTEGER && v22 != STRING )
                break;
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: v22, pszExpecting: nullptr);
              ivi.iValue = 0;
              v23 = 0;
              do
              {
                v24 = szToken[v23];
                ivi.szValue[v23++] = v24;
              }
              while ( v24 != 0 );
              if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") == 0
                || GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
              {
                return false;
              }
              v25 = 0;
              do
              {
                v26 = szToken[v25];
                ivi.szCaption[v25++] = v26;
              }
              while ( v26 != 0 );
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
                this: &this->m_Items,
                elem: this->m_Items.m_Size,
                src: &ivi);
            }
          }
          return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]") != 0;
        }
      }
      else
      {
        GDError(tr, error: "didn't expect '=' here");
      }
    }
    return false;
  }
LABEL_40:
  v10 = this->m_eType;
  if ( v10 == ivFlags )
  {
    v12 = "flags";
    goto LABEL_53;
  }
  if ( v10 == ivChoices )
  {
    v12 = "choices";
LABEL_53:
    GDError(tr, error: "no %s specified", v12);
    return false;
  }
  if ( v10 != ivBoolean )
    return true;
  this->m_eType = ivChoices;
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "1", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "Yes", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "0", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "No", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  m_szDefault = (unsigned __int8 *)this->m_szDefault;
  if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "no") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "yes") == 0 )
      strncpy(dest: m_szDefault, source: "1", count: 0x81u);
  }
  else
  {
    strncpy(dest: m_szDefault, source: "0", count: 0x81u);
  }
  if ( strcmp((const char *)m_szDefault, "0") == 0 || strcmp((const char *)m_szDefault, "1") == 0 )
    return true;
  GDError(tr, error: "boolean type specified with nonsensical default value: %s", (const char *)m_szDefault);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101F5830
// Name: public: void GDinputvariable::Merge(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::Merge(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // eax
  int m_Size; // edi
  GDIVITEM *v5; // esi
  int v6; // eax
  GDIVITEM *v7; // ecx
  int v8; // edi
  int m_nAllocationCount; // eax
  GDIVITEM *m_pMemory; // ecx
  int v11; // eax
  GDIVITEM *v12; // edi
  int i; // [esp+4h] [ebp-10h]
  int nOurItems; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  bool bFound; // [esp+13h] [ebp-1h]

  v2 = Other;
  if ( Other->m_eType == this->m_eType )
  {
    m_Size = this->m_Items.m_Size;
    bFound = false;
    nOurItems = m_Size;
    i = 0;
    if ( Other->m_Items.m_Size > 0 )
    {
      v15 = 0;
      do
      {
        v5 = &v2->m_Items.m_Memory.m_pMemory[v15];
        v6 = 0;
        if ( m_Size <= 0 )
        {
LABEL_8:
          if ( !bFound )
          {
            v8 = this->m_Items.m_Size;
            m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
            if ( v8 + 1 > m_nAllocationCount )
              CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Items.m_Memory, num: v8 - m_nAllocationCount + 1);
            ++this->m_Items.m_Size;
            m_pMemory = this->m_Items.m_Memory.m_pMemory;
            v11 = this->m_Items.m_Size - v8 - 1;
            this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 268 * v11);
            v12 = &this->m_Items.m_Memory.m_pMemory[v8];
            if ( v12 != nullptr )
              qmemcpy(v12, v5, sizeof(GDIVITEM));
            m_Size = nOurItems;
          }
        }
        else
        {
          v7 = this->m_Items.m_Memory.m_pMemory;
          while ( v5->iValue != v7->iValue )
          {
            ++v6;
            ++v7;
            if ( v6 >= m_Size )
              goto LABEL_8;
          }
          bFound = true;
        }
        v2 = Other;
        ++v15;
        ++i;
      }
      while ( i < Other->m_Items.m_Size );
    }
  }
}

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100FB300
// Name: public: enum trtoken_t GDinputvariable::GetStoreAsFromType(enum GDIV_TYPE)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetStoreAsFromType(GDinputvariable *this, GDIV_TYPE eType)
{
  int v2; // ecx
  unsigned int v3; // eax

  v2 = 0;
  v3 = 0;
  while ( *(InputOutputType_t *)((char *)&TypeMap[0].eType + v3) != eType )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return 2;
  }
  return *((_DWORD *)&TypeMap[1].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x100FB340
// Name: public: enum GDIV_TYPE GDinputvariable::GetTypeFromToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetTypeFromToken(GDinputvariable *this, const char *pszToken)
{
  int v2; // edi
  unsigned int v3; // esi

  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pszToken, s2: *(const char **)((char *)&TypeMap[0].pszName + v3)) != 0 )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return -1;
  }
  return *((_DWORD *)&TypeMap[0].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x100FB410
// Name: public: GDinputvariable::GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::GDinputvariable(GDinputvariable *this)
{
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_szDefault[0] = 0;
  this->m_nDefault = 0;
  this->m_szValue[0] = 0;
  *(_WORD *)&this->m_bReportable = 0;
  this->m_pszDescription = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FB450
// Name: public: GDinputvariable::~GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::~GDinputvariable(GDinputvariable *this)
{
  free(pMem: this->m_pszDescription);
  this->m_Items.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>((CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100FB480
// Name: public: class GDinputvariable __near & GDinputvariable::operator=(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::operator=(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // esi
  char *m_szName; // eax
  int v5; // edx
  char v6; // cl
  char *m_szLongName; // eax
  char v8; // cl
  char *m_szDefault; // eax
  char v10; // cl
  char *m_pszDescription; // eax
  int v12; // edi
  char *v13; // eax
  char *v14; // ecx
  char *v15; // edx
  char v16; // al
  int m_nAllocationCount; // eax
  char *v18; // esi
  int v19; // edi
  GDIVITEM *m_pMemory; // ecx
  int v21; // eax
  GDIVITEM *v22; // edi
  bool v23; // zf
  int m_Size; // [esp+Ch] [ebp-8h]
  int v26; // [esp+10h] [ebp-4h]

  v2 = Other;
  this->m_eType = Other->m_eType;
  m_szName = Other->m_szName;
  v5 = (char *)this - Other->m_szName;
  do
  {
    v6 = *m_szName;
    m_szName[v5 + 20] = *m_szName;
    ++m_szName;
  }
  while ( v6 != 0 );
  m_szLongName = Other->m_szLongName;
  do
  {
    v8 = *m_szLongName;
    m_szLongName[(char *)this - (char *)Other] = *m_szLongName;
    ++m_szLongName;
  }
  while ( v8 != 0 );
  m_szDefault = Other->m_szDefault;
  do
  {
    v10 = *m_szDefault;
    m_szDefault[(char *)this - (char *)Other] = *m_szDefault;
    ++m_szDefault;
  }
  while ( v10 != 0 );
  free(pMem: this->m_pszDescription);
  m_pszDescription = Other->m_pszDescription;
  v12 = 0;
  if ( m_pszDescription != nullptr )
  {
    v13 = (char *)operator new(nSize: strlen(m_pszDescription) + 1);
    this->m_pszDescription = v13;
    v14 = Other->m_pszDescription;
    v15 = v13;
    do
    {
      v16 = *v14;
      *v15++ = *v14++;
    }
    while ( v16 != 0 );
  }
  else
  {
    this->m_pszDescription = nullptr;
  }
  this->m_nDefault = Other->m_nDefault;
  this->m_bReportable = Other->m_bReportable;
  this->m_bReadOnly = Other->m_bReadOnly;
  this->m_Items.m_Size = 0;
  if ( Other->m_Items.m_Size > 0 )
  {
    v26 = 0;
    m_Size = Other->m_Items.m_Size;
    while ( 1 )
    {
      m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
      v18 = (char *)v2->m_Items.m_Memory.m_pMemory + v12;
      v19 = this->m_Items.m_Size;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>::Grow(
          this: &this->m_Items.m_Memory,
          num: v19 - m_nAllocationCount + 1);
      ++this->m_Items.m_Size;
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      v21 = this->m_Items.m_Size - v19 - 1;
      this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[v19 + 1],
          src: (unsigned __int8 *)&m_pMemory[v19],
          count: 268 * v21);
      v22 = &this->m_Items.m_Memory.m_pMemory[v19];
      if ( v22 != nullptr )
        qmemcpy(v22, v18, sizeof(GDIVITEM));
      v12 = v26 + 268;
      v23 = m_Size-- == 1;
      v26 += 268;
      if ( v23 )
        break;
      v2 = Other;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FB600
// Name: public: int GDinputvariable::InitFromTokens(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDinputvariable::InitFromTokens(GDinputvariable *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  GDIV_TYPE TypeFromToken; // eax
  trtoken_t v6; // edi
  int StoreAsFromType; // eax
  char *m_szName; // eax
  char v9; // cl
  GDIV_TYPE v10; // eax
  unsigned __int8 *m_szDefault; // ebx
  const char *v12; // eax
  GDIV_TYPE m_eType; // eax
  GDIV_TYPE v14; // eax
  int v15; // eax
  char v16; // cl
  int v17; // eax
  int m_Size; // ecx
  int v19; // ecx
  GDIVITEM *m_pMemory; // eax
  int v21; // edx
  trtoken_t v22; // eax
  int v23; // eax
  char v24; // cl
  int v25; // eax
  char v26; // cl
  GDIVITEM ivi; // [esp+8h] [ebp-18Ch] BYREF
  char szToken[128]; // [esp+114h] [ebp-80h] BYREF

  if ( GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr) == 0
    || GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") == 0 )
  {
    return false;
  }
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( Token != OPERATOR )
  {
    TokenReader::Stuff(this: tr, eType: Token, pszToken: szToken);
  }
  else if ( strcmp(szToken, "*") == 0 )
  {
    this->m_bReportable = true;
  }
  if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: IDENT, pszExpecting: nullptr) == 0
    || GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
  {
    return false;
  }
  TypeFromToken = GDinputvariable::GetTypeFromToken(this, pszToken: szToken);
  this->m_eType = TypeFromToken;
  if ( TypeFromToken == ivBadType )
  {
    GDError(tr, error: "'%s' is not a valid variable type", szToken);
    return false;
  }
  v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
  if ( v6 == IDENT )
  {
    if ( _V_stricmp(s1: szToken, s2: "readonly") != 0
      || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128),
          this->m_bReadOnly = true,
          (v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128)) == IDENT) )
    {
      if ( _V_stricmp(s1: szToken, s2: "report") != 0 )
      {
LABEL_36:
        m_szName = this->m_szName;
        do
        {
          v9 = *m_szName;
          m_szName[65] = *m_szName;
          ++m_szName;
        }
        while ( v9 != 0 );
LABEL_38:
        if ( v6 != OPERATOR )
          goto LABEL_40;
        goto LABEL_39;
      }
      TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      this->m_bReportable = true;
      v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    }
  }
  if ( v6 != OPERATOR || _V_stricmp(s1: szToken, s2: ":") != 0 )
    goto LABEL_36;
  TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( this->m_eType == ivFlags )
  {
    GDError(tr, error: "flag sets do not have long names");
    return false;
  }
  if ( GDGetToken(tr, pszStore: this->m_szLongName, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
    return false;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    goto LABEL_40;
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR
      || _V_stricmp(s1: szToken, s2: ":") != 0 )
    {
      StoreAsFromType = GDinputvariable::GetStoreAsFromType(this, eType: this->m_eType);
      if ( StoreAsFromType == 2 )
      {
        if ( GDGetToken(tr, pszStore: this->m_szDefault, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
          return false;
      }
      else if ( StoreAsFromType == 1 )
      {
        if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
          return false;
        this->m_nDefault = atoi(nptr: szToken);
      }
      if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
        goto LABEL_40;
    }
  }
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
      return false;
    v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    goto LABEL_38;
  }
LABEL_39:
  if ( _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=") != 0 )
    {
      m_eType = this->m_eType;
      if ( m_eType == ivFlags || m_eType == ivChoices )
      {
        if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[") != 0 )
        {
          v14 = this->m_eType;
          if ( v14 == ivFlags )
          {
            while ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) == INTEGER )
            {
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr);
              sscanf(string: szToken, format: "%lu", &ivi);
              if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") == 0 )
                return false;
              if ( GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
                return false;
              v15 = 0;
              do
              {
                v16 = szToken[v15];
                ivi.szCaption[v15++] = v16;
              }
              while ( v16 != 0 );
              if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") == 0
                || GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
              {
                return false;
              }
              v17 = atoi(nptr: szToken);
              m_Size = this->m_Items.m_Size;
              ivi.bDefault = v17 != 0;
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(this: &this->m_Items, elem: m_Size, src: &ivi);
            }
            v19 = 0;
            if ( this->m_Items.m_Size > 0 )
            {
              m_pMemory = this->m_Items.m_Memory.m_pMemory;
              v21 = this->m_Items.m_Size;
              do
              {
                if ( m_pMemory->bDefault != 0 )
                  v19 |= m_pMemory->iValue;
                ++m_pMemory;
                --v21;
              }
              while ( v21 != 0 );
            }
            this->m_nDefault = v19;
            V_snprintf(pDest: this->m_szDefault, maxLen: 0x81u, pFormat: "%d", v19);
          }
          else if ( v14 == ivChoices )
          {
            while ( 1 )
            {
              v22 = TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0);
              if ( v22 != INTEGER && v22 != STRING )
                break;
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: v22, pszExpecting: nullptr);
              ivi.iValue = 0;
              v23 = 0;
              do
              {
                v24 = szToken[v23];
                ivi.szValue[v23++] = v24;
              }
              while ( v24 != 0 );
              if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") == 0
                || GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
              {
                return false;
              }
              v25 = 0;
              do
              {
                v26 = szToken[v25];
                ivi.szCaption[v25++] = v26;
              }
              while ( v26 != 0 );
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
                this: &this->m_Items,
                elem: this->m_Items.m_Size,
                src: &ivi);
            }
          }
          return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]") != 0;
        }
      }
      else
      {
        GDError(tr, error: "didn't expect '=' here");
      }
    }
    return false;
  }
LABEL_40:
  v10 = this->m_eType;
  if ( v10 == ivFlags )
  {
    v12 = "flags";
    goto LABEL_53;
  }
  if ( v10 == ivChoices )
  {
    v12 = "choices";
LABEL_53:
    GDError(tr, error: "no %s specified", v12);
    return false;
  }
  if ( v10 != ivBoolean )
    return true;
  this->m_eType = ivChoices;
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "1", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "Yes", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "0", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "No", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  m_szDefault = (unsigned __int8 *)this->m_szDefault;
  if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "no") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "yes") == 0 )
      strncpy(dest: m_szDefault, source: "1", count: 0x81u);
  }
  else
  {
    strncpy(dest: m_szDefault, source: "0", count: 0x81u);
  }
  if ( strcmp((const char *)m_szDefault, "0") == 0 || strcmp((const char *)m_szDefault, "1") == 0 )
    return true;
  GDError(tr, error: "boolean type specified with nonsensical default value: %s", (const char *)m_szDefault);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100FBDA0
// Name: public: void GDinputvariable::Merge(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::Merge(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // eax
  int m_Size; // edi
  GDIVITEM *v5; // esi
  int v6; // eax
  GDIVITEM *v7; // ecx
  int v8; // edi
  int m_nAllocationCount; // eax
  GDIVITEM *m_pMemory; // ecx
  int v11; // eax
  GDIVITEM *v12; // edi
  int i; // [esp+4h] [ebp-10h]
  int nOurItems; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  bool bFound; // [esp+13h] [ebp-1h]

  v2 = Other;
  if ( Other->m_eType == this->m_eType )
  {
    m_Size = this->m_Items.m_Size;
    bFound = false;
    nOurItems = m_Size;
    i = 0;
    if ( Other->m_Items.m_Size > 0 )
    {
      v15 = 0;
      do
      {
        v5 = &v2->m_Items.m_Memory.m_pMemory[v15];
        v6 = 0;
        if ( m_Size <= 0 )
        {
LABEL_8:
          if ( !bFound )
          {
            v8 = this->m_Items.m_Size;
            m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
            if ( v8 + 1 > m_nAllocationCount )
              CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>::Grow(
                this: &this->m_Items.m_Memory,
                num: v8 - m_nAllocationCount + 1);
            ++this->m_Items.m_Size;
            m_pMemory = this->m_Items.m_Memory.m_pMemory;
            v11 = this->m_Items.m_Size - v8 - 1;
            this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
            if ( v11 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[v8 + 1],
                src: (unsigned __int8 *)&m_pMemory[v8],
                count: 268 * v11);
            v12 = &this->m_Items.m_Memory.m_pMemory[v8];
            if ( v12 != nullptr )
              qmemcpy(v12, v5, sizeof(GDIVITEM));
            m_Size = nOurItems;
          }
        }
        else
        {
          v7 = this->m_Items.m_Memory.m_pMemory;
          while ( v5->iValue != v7->iValue )
          {
            ++v6;
            ++v7;
            if ( v6 >= m_Size )
              goto LABEL_8;
          }
          bFound = true;
        }
        v2 = Other;
        ++v15;
        ++i;
      }
      while ( i < Other->m_Items.m_Size );
    }
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00453720
// Name: public: enum trtoken_t GDinputvariable::GetStoreAsFromType(enum GDIV_TYPE)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetStoreAsFromType(GDinputvariable *this, GDIV_TYPE eType)
{
  int v2; // ecx
  unsigned int v3; // eax

  v2 = 0;
  v3 = 0;
  while ( *(InputOutputType_t *)((char *)&TypeMap[0].eType + v3) != eType )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return 2;
  }
  return *((_DWORD *)&TypeMap[1].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x00453760
// Name: public: enum GDIV_TYPE GDinputvariable::GetTypeFromToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetTypeFromToken(GDinputvariable *this, const char *pszToken)
{
  int v2; // edi
  unsigned int v3; // esi

  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pszToken, s2: *(const char **)((char *)&TypeMap[0].pszName + v3)) != 0 )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return -1;
  }
  return *((_DWORD *)&TypeMap[0].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x004538D0
// Name: public: GDinputvariable::GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::GDinputvariable(GDinputvariable *this)
{
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_szDefault[0] = 0;
  this->m_nDefault = 0;
  this->m_szValue[0] = 0;
  *(_WORD *)&this->m_bReportable = 0;
  this->m_pszDescription = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00453910
// Name: public: GDinputvariable::~GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::~GDinputvariable(GDinputvariable *this)
{
  free(pMem: this->m_pszDescription);
  this->m_Items.m_Size = 0;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00453940
// Name: public: class GDinputvariable __near & GDinputvariable::operator=(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::operator=(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // esi
  char *m_szName; // eax
  int v5; // edx
  char v6; // cl
  char *m_szLongName; // eax
  char v8; // cl
  char *m_szDefault; // eax
  char v10; // cl
  char *m_pszDescription; // eax
  int v12; // edi
  char *v13; // eax
  char *v14; // ecx
  char *v15; // edx
  char v16; // al
  int m_nAllocationCount; // eax
  char *v18; // esi
  int v19; // edi
  GDIVITEM *m_pMemory; // ecx
  int v21; // eax
  GDIVITEM *v22; // edi
  bool v23; // zf
  int m_Size; // [esp+Ch] [ebp-8h]
  int v26; // [esp+10h] [ebp-4h]

  v2 = Other;
  this->m_eType = Other->m_eType;
  m_szName = Other->m_szName;
  v5 = (char *)this - Other->m_szName;
  do
  {
    v6 = *m_szName;
    m_szName[v5 + 20] = *m_szName;
    ++m_szName;
  }
  while ( v6 != 0 );
  m_szLongName = Other->m_szLongName;
  do
  {
    v8 = *m_szLongName;
    m_szLongName[(char *)this - (char *)Other] = *m_szLongName;
    ++m_szLongName;
  }
  while ( v8 != 0 );
  m_szDefault = Other->m_szDefault;
  do
  {
    v10 = *m_szDefault;
    m_szDefault[(char *)this - (char *)Other] = *m_szDefault;
    ++m_szDefault;
  }
  while ( v10 != 0 );
  free(pMem: this->m_pszDescription);
  m_pszDescription = Other->m_pszDescription;
  v12 = 0;
  if ( m_pszDescription != nullptr )
  {
    v13 = (char *)MemAlloc_Alloc(nSize: strlen(m_pszDescription) + 1);
    this->m_pszDescription = v13;
    v14 = Other->m_pszDescription;
    v15 = v13;
    do
    {
      v16 = *v14;
      *v15++ = *v14++;
    }
    while ( v16 != 0 );
  }
  else
  {
    this->m_pszDescription = nullptr;
  }
  this->m_nDefault = Other->m_nDefault;
  this->m_bReportable = Other->m_bReportable;
  this->m_bReadOnly = Other->m_bReadOnly;
  this->m_Items.m_Size = 0;
  if ( Other->m_Items.m_Size > 0 )
  {
    v26 = 0;
    m_Size = Other->m_Items.m_Size;
    while ( 1 )
    {
      m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
      v18 = (char *)v2->m_Items.m_Memory.m_pMemory + v12;
      v19 = this->m_Items.m_Size;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Items.m_Memory, num: v19 - m_nAllocationCount + 1);
      ++this->m_Items.m_Size;
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      v21 = this->m_Items.m_Size - v19 - 1;
      this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(dest: &m_pMemory[v19 + 1], src: &m_pMemory[v19], count: 268 * v21);
      v22 = &this->m_Items.m_Memory.m_pMemory[v19];
      if ( v22 != nullptr )
        qmemcpy(v22, v18, sizeof(GDIVITEM));
      v12 = v26 + 268;
      v23 = m_Size-- == 1;
      v26 += 268;
      if ( v23 )
        break;
      v2 = Other;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00453AC0
// Name: public: int GDinputvariable::InitFromTokens(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDinputvariable::InitFromTokens(GDinputvariable *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  GDIV_TYPE TypeFromToken; // eax
  trtoken_t v6; // edi
  int StoreAsFromType; // eax
  char *m_szName; // eax
  char v9; // cl
  GDIV_TYPE v10; // eax
  unsigned __int8 *m_szDefault; // ebx
  const char *v12; // eax
  GDIV_TYPE m_eType; // eax
  GDIV_TYPE v14; // eax
  int v15; // eax
  char v16; // cl
  int v17; // eax
  int m_Size; // ecx
  int v19; // ecx
  GDIVITEM *m_pMemory; // eax
  int v21; // edx
  trtoken_t v22; // eax
  int v23; // eax
  char v24; // cl
  int v25; // eax
  char v26; // cl
  GDIVITEM ivi; // [esp+8h] [ebp-18Ch] BYREF
  char szToken[128]; // [esp+114h] [ebp-80h] BYREF

  if ( !GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr)
    || !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") )
  {
    return false;
  }
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( Token != OPERATOR )
  {
    TokenReader::Stuff(this: tr, eType: Token, pszToken: szToken);
  }
  else if ( strcmp(szToken, "*") == 0 )
  {
    this->m_bReportable = true;
  }
  if ( !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: IDENT, pszExpecting: nullptr)
    || !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") )
  {
    return false;
  }
  TypeFromToken = GDinputvariable::GetTypeFromToken(this, pszToken: szToken);
  this->m_eType = TypeFromToken;
  if ( TypeFromToken == ivBadType )
  {
    GDError(tr, error: "'%s' is not a valid variable type", szToken);
    return false;
  }
  v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
  if ( v6 == IDENT )
  {
    if ( _V_stricmp(s1: szToken, s2: "readonly") != 0
      || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128),
          this->m_bReadOnly = true,
          (v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128)) == IDENT) )
    {
      if ( _V_stricmp(s1: szToken, s2: "report") != 0 )
      {
LABEL_36:
        m_szName = this->m_szName;
        do
        {
          v9 = *m_szName;
          m_szName[65] = *m_szName;
          ++m_szName;
        }
        while ( v9 != 0 );
LABEL_38:
        if ( v6 != OPERATOR )
          goto LABEL_40;
        goto LABEL_39;
      }
      TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      this->m_bReportable = true;
      v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    }
  }
  if ( v6 != OPERATOR || _V_stricmp(s1: szToken, s2: ":") != 0 )
    goto LABEL_36;
  TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( this->m_eType == ivFlags )
  {
    GDError(tr, error: "flag sets do not have long names");
    return false;
  }
  if ( !GDGetToken(tr, pszStore: this->m_szLongName, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) )
    return false;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    goto LABEL_40;
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR
      || _V_stricmp(s1: szToken, s2: ":") != 0 )
    {
      StoreAsFromType = GDinputvariable::GetStoreAsFromType(this, eType: this->m_eType);
      if ( StoreAsFromType == 2 )
      {
        if ( !GDGetToken(tr, pszStore: this->m_szDefault, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) )
          return false;
      }
      else if ( StoreAsFromType == 1 )
      {
        if ( !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) )
          return false;
        this->m_nDefault = atoi(nptr: szToken);
      }
      if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
        goto LABEL_40;
    }
  }
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( !GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr) )
      return false;
    v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    goto LABEL_38;
  }
LABEL_39:
  if ( _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=") )
    {
      m_eType = this->m_eType;
      if ( m_eType == ivFlags || m_eType == ivChoices )
      {
        if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[") )
        {
          v14 = this->m_eType;
          if ( v14 == ivFlags )
          {
            while ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) == INTEGER )
            {
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr);
              sscanf(string: szToken, format: "%lu", &ivi);
              if ( !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") )
                return false;
              if ( !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) )
                return false;
              v15 = 0;
              do
              {
                v16 = szToken[v15];
                ivi.szCaption[v15++] = v16;
              }
              while ( v16 != 0 );
              if ( !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":")
                || !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) )
              {
                return false;
              }
              v17 = atoi(nptr: szToken);
              m_Size = this->m_Items.m_Size;
              ivi.bDefault = v17 != 0;
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(this: &this->m_Items, elem: m_Size, src: &ivi);
            }
            v19 = 0;
            if ( this->m_Items.m_Size > 0 )
            {
              m_pMemory = this->m_Items.m_Memory.m_pMemory;
              v21 = this->m_Items.m_Size;
              do
              {
                if ( m_pMemory->bDefault != 0 )
                  v19 |= m_pMemory->iValue;
                ++m_pMemory;
                --v21;
              }
              while ( v21 != 0 );
            }
            this->m_nDefault = v19;
            V_snprintf(pDest: this->m_szDefault, maxLen: 129, pFormat: "%d", v19);
          }
          else if ( v14 == ivChoices )
          {
            while ( 1 )
            {
              v22 = TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0);
              if ( v22 != INTEGER && v22 != STRING )
                break;
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: v22, pszExpecting: nullptr);
              ivi.iValue = 0;
              v23 = 0;
              do
              {
                v24 = szToken[v23];
                ivi.szValue[v23++] = v24;
              }
              while ( v24 != 0 );
              if ( !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":")
                || !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) )
              {
                return false;
              }
              v25 = 0;
              do
              {
                v26 = szToken[v25];
                ivi.szCaption[v25++] = v26;
              }
              while ( v26 != 0 );
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
                this: &this->m_Items,
                elem: this->m_Items.m_Size,
                src: &ivi);
            }
          }
          return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]");
        }
      }
      else
      {
        GDError(tr, error: "didn't expect '=' here");
      }
    }
    return false;
  }
LABEL_40:
  v10 = this->m_eType;
  if ( v10 == ivFlags )
  {
    v12 = "flags";
    goto LABEL_53;
  }
  if ( v10 == ivChoices )
  {
    v12 = "choices";
LABEL_53:
    GDError(tr, error: "no %s specified", v12);
    return false;
  }
  if ( v10 != ivBoolean )
    return true;
  this->m_eType = ivChoices;
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "1", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "Yes", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "0", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "No", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  m_szDefault = (unsigned __int8 *)this->m_szDefault;
  if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "no") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "yes") == 0 )
      strncpy(dest: m_szDefault, source: "1", count: 0x81u);
  }
  else
  {
    strncpy(dest: m_szDefault, source: "0", count: 0x81u);
  }
  if ( strcmp((const char *)m_szDefault, "0") == 0 || strcmp((const char *)m_szDefault, "1") == 0 )
    return true;
  GDError(tr, error: "boolean type specified with nonsensical default value: %s", (const char *)m_szDefault);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00454260
// Name: public: void GDinputvariable::Merge(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::Merge(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // eax
  int m_Size; // edi
  GDIVITEM *v5; // esi
  int v6; // eax
  GDIVITEM *v7; // ecx
  int v8; // edi
  int m_nAllocationCount; // eax
  GDIVITEM *m_pMemory; // ecx
  int v11; // eax
  GDIVITEM *v12; // edi
  int i; // [esp+4h] [ebp-10h]
  int nOurItems; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  bool bFound; // [esp+13h] [ebp-1h]

  v2 = Other;
  if ( Other->m_eType == this->m_eType )
  {
    m_Size = this->m_Items.m_Size;
    bFound = false;
    nOurItems = m_Size;
    i = 0;
    if ( Other->m_Items.m_Size > 0 )
    {
      v15 = 0;
      do
      {
        v5 = &v2->m_Items.m_Memory.m_pMemory[v15];
        v6 = 0;
        if ( m_Size <= 0 )
        {
LABEL_8:
          if ( !bFound )
          {
            v8 = this->m_Items.m_Size;
            m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
            if ( v8 + 1 > m_nAllocationCount )
              CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Items.m_Memory, num: v8 - m_nAllocationCount + 1);
            ++this->m_Items.m_Size;
            m_pMemory = this->m_Items.m_Memory.m_pMemory;
            v11 = this->m_Items.m_Size - v8 - 1;
            this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 268 * v11);
            v12 = &this->m_Items.m_Memory.m_pMemory[v8];
            if ( v12 != nullptr )
              qmemcpy(v12, v5, sizeof(GDIVITEM));
            m_Size = nOurItems;
          }
        }
        else
        {
          v7 = this->m_Items.m_Memory.m_pMemory;
          while ( v5->iValue != v7->iValue )
          {
            ++v6;
            ++v7;
            if ( v6 >= m_Size )
              goto LABEL_8;
          }
          bFound = true;
        }
        v2 = Other;
        ++v15;
        ++i;
      }
      while ( i < Other->m_Items.m_Size );
    }
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00449180
// Name: public: enum trtoken_t GDinputvariable::GetStoreAsFromType(enum GDIV_TYPE)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetStoreAsFromType(GDinputvariable *this, GDIV_TYPE eType)
{
  int v2; // ecx
  unsigned int v3; // eax

  v2 = 0;
  v3 = 0;
  while ( *(InputOutputType_t *)((char *)&TypeMap[0].eType + v3) != eType )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return 2;
  }
  return *((_DWORD *)&TypeMap[1].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x004491C0
// Name: public: enum GDIV_TYPE GDinputvariable::GetTypeFromToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDinputvariable::GetTypeFromToken(GDinputvariable *this, const char *pszToken)
{
  int v2; // edi
  unsigned int v3; // esi

  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pszToken, s2: *(const char **)((char *)&TypeMap[0].pszName + v3)) != 0 )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= 0x1BC )
      return -1;
  }
  return *((_DWORD *)&TypeMap[0].eType + 3 * v2);
}

//------------------------------------------------------------------------------
// Address: 0x00449330
// Name: public: GDinputvariable::GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::GDinputvariable(GDinputvariable *this)
{
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_szDefault[0] = 0;
  this->m_nDefault = 0;
  this->m_szValue[0] = 0;
  *(_WORD *)&this->m_bReportable = 0;
  this->m_pszDescription = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449370
// Name: public: GDinputvariable::~GDinputvariable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::~GDinputvariable(GDinputvariable *this)
{
  free(pMem: this->m_pszDescription);
  this->m_Items.m_Size = 0;
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>((CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004493A0
// Name: public: class GDinputvariable __near & GDinputvariable::operator=(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDinputvariable::operator=(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // esi
  char *m_szName; // eax
  int v5; // edx
  char v6; // cl
  char *m_szLongName; // eax
  char v8; // cl
  char *m_szDefault; // eax
  char v10; // cl
  char *m_pszDescription; // eax
  int v12; // edi
  char *v13; // eax
  char *v14; // ecx
  char *v15; // edx
  char v16; // al
  int m_nAllocationCount; // eax
  char *v18; // esi
  int v19; // edi
  GDIVITEM *m_pMemory; // ecx
  int v21; // eax
  GDIVITEM *v22; // edi
  bool v23; // zf
  int m_Size; // [esp+Ch] [ebp-8h]
  int v26; // [esp+10h] [ebp-4h]

  v2 = Other;
  this->m_eType = Other->m_eType;
  m_szName = Other->m_szName;
  v5 = (char *)this - Other->m_szName;
  do
  {
    v6 = *m_szName;
    m_szName[v5 + 20] = *m_szName;
    ++m_szName;
  }
  while ( v6 != 0 );
  m_szLongName = Other->m_szLongName;
  do
  {
    v8 = *m_szLongName;
    m_szLongName[(char *)this - (char *)Other] = *m_szLongName;
    ++m_szLongName;
  }
  while ( v8 != 0 );
  m_szDefault = Other->m_szDefault;
  do
  {
    v10 = *m_szDefault;
    m_szDefault[(char *)this - (char *)Other] = *m_szDefault;
    ++m_szDefault;
  }
  while ( v10 != 0 );
  free(pMem: this->m_pszDescription);
  m_pszDescription = Other->m_pszDescription;
  v12 = 0;
  if ( m_pszDescription != nullptr )
  {
    v13 = (char *)operator new(nSize: strlen(m_pszDescription) + 1);
    this->m_pszDescription = v13;
    v14 = Other->m_pszDescription;
    v15 = v13;
    do
    {
      v16 = *v14;
      *v15++ = *v14++;
    }
    while ( v16 != 0 );
  }
  else
  {
    this->m_pszDescription = nullptr;
  }
  this->m_nDefault = Other->m_nDefault;
  this->m_bReportable = Other->m_bReportable;
  this->m_bReadOnly = Other->m_bReadOnly;
  this->m_Items.m_Size = 0;
  if ( Other->m_Items.m_Size > 0 )
  {
    v26 = 0;
    m_Size = Other->m_Items.m_Size;
    while ( 1 )
    {
      m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
      v18 = (char *)v2->m_Items.m_Memory.m_pMemory + v12;
      v19 = this->m_Items.m_Size;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Items.m_Memory, num: v19 - m_nAllocationCount + 1);
      ++this->m_Items.m_Size;
      m_pMemory = this->m_Items.m_Memory.m_pMemory;
      v21 = this->m_Items.m_Size - v19 - 1;
      this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(dest: &m_pMemory[v19 + 1], src: &m_pMemory[v19], count: 268 * v21);
      v22 = &this->m_Items.m_Memory.m_pMemory[v19];
      if ( v22 != nullptr )
        qmemcpy(v22, v18, sizeof(GDIVITEM));
      v12 = v26 + 268;
      v23 = m_Size-- == 1;
      v26 += 268;
      if ( v23 )
        break;
      v2 = Other;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449520
// Name: public: int GDinputvariable::InitFromTokens(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDinputvariable::InitFromTokens(GDinputvariable *this, TokenReader *tr)
{
  trtoken_t Token; // eax
  GDIV_TYPE TypeFromToken; // eax
  trtoken_t v6; // edi
  int StoreAsFromType; // eax
  char *m_szName; // eax
  char v9; // cl
  GDIV_TYPE v10; // eax
  unsigned __int8 *m_szDefault; // ebx
  const char *v12; // eax
  GDIV_TYPE m_eType; // eax
  GDIV_TYPE v14; // eax
  int v15; // eax
  char v16; // cl
  int v17; // eax
  int m_Size; // ecx
  int v19; // ecx
  GDIVITEM *m_pMemory; // eax
  int v21; // edx
  trtoken_t v22; // eax
  int v23; // eax
  char v24; // cl
  int v25; // eax
  char v26; // cl
  GDIVITEM ivi; // [esp+8h] [ebp-18Ch] BYREF
  char szToken[128]; // [esp+114h] [ebp-80h] BYREF

  if ( !GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr)
    || !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") )
  {
    return false;
  }
  Token = TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( Token != OPERATOR )
  {
    TokenReader::Stuff(this: tr, eType: Token, pszToken: szToken);
  }
  else if ( strcmp(szToken, "*") == 0 )
  {
    this->m_bReportable = true;
  }
  if ( !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: IDENT, pszExpecting: nullptr)
    || !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ")") )
  {
    return false;
  }
  TypeFromToken = GDinputvariable::GetTypeFromToken(this, pszToken: szToken);
  this->m_eType = TypeFromToken;
  if ( TypeFromToken == ivBadType )
  {
    GDError(tr, error: "'%s' is not a valid variable type", szToken);
    return false;
  }
  v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
  if ( v6 == IDENT )
  {
    if ( _V_stricmp(s1: szToken, s2: "readonly") != 0
      || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128),
          this->m_bReadOnly = true,
          (v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128)) == IDENT) )
    {
      if ( _V_stricmp(s1: szToken, s2: "report") != 0 )
      {
LABEL_36:
        m_szName = this->m_szName;
        do
        {
          v9 = *m_szName;
          m_szName[65] = *m_szName;
          ++m_szName;
        }
        while ( v9 != 0 );
LABEL_38:
        if ( v6 != OPERATOR )
          goto LABEL_40;
        goto LABEL_39;
      }
      TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
      this->m_bReportable = true;
      v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    }
  }
  if ( v6 != OPERATOR || _V_stricmp(s1: szToken, s2: ":") != 0 )
    goto LABEL_36;
  TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
  if ( this->m_eType == ivFlags )
  {
    GDError(tr, error: "flag sets do not have long names");
    return false;
  }
  if ( !GDGetToken(tr, pszStore: this->m_szLongName, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) )
    return false;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
    goto LABEL_40;
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR
      || _V_stricmp(s1: szToken, s2: ":") != 0 )
    {
      StoreAsFromType = GDinputvariable::GetStoreAsFromType(this, eType: this->m_eType);
      if ( StoreAsFromType == 2 )
      {
        if ( !GDGetToken(tr, pszStore: this->m_szDefault, nSize: 129, ttexpecting: STRING, pszExpecting: nullptr) )
          return false;
      }
      else if ( StoreAsFromType == 1 )
      {
        if ( !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) )
          return false;
        this->m_nDefault = atoi(nptr: szToken);
      }
      if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128) != OPERATOR )
        goto LABEL_40;
    }
  }
  if ( _V_stricmp(s1: szToken, s2: ":") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 128);
    if ( !GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr) )
      return false;
    v6 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 128);
    goto LABEL_38;
  }
LABEL_39:
  if ( _V_stricmp(s1: szToken, s2: "]") != 0 )
  {
    if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=") )
    {
      m_eType = this->m_eType;
      if ( m_eType == ivFlags || m_eType == ivChoices )
      {
        if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[") )
        {
          v14 = this->m_eType;
          if ( v14 == ivFlags )
          {
            while ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) == INTEGER )
            {
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr);
              sscanf(string: szToken, format: "%lu", &ivi);
              if ( !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":") )
                return false;
              if ( !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) )
                return false;
              v15 = 0;
              do
              {
                v16 = szToken[v15];
                ivi.szCaption[v15++] = v16;
              }
              while ( v16 != 0 );
              if ( !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":")
                || !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: INTEGER, pszExpecting: nullptr) )
              {
                return false;
              }
              v17 = atoi(nptr: szToken);
              m_Size = this->m_Items.m_Size;
              ivi.bDefault = v17 != 0;
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(this: &this->m_Items, elem: m_Size, src: &ivi);
            }
            v19 = 0;
            if ( this->m_Items.m_Size > 0 )
            {
              m_pMemory = this->m_Items.m_Memory.m_pMemory;
              v21 = this->m_Items.m_Size;
              do
              {
                if ( m_pMemory->bDefault != 0 )
                  v19 |= m_pMemory->iValue;
                ++m_pMemory;
                --v21;
              }
              while ( v21 != 0 );
            }
            this->m_nDefault = v19;
            V_snprintf(pDest: this->m_szDefault, maxLen: 129, pFormat: "%d", v19);
          }
          else if ( v14 == ivChoices )
          {
            while ( 1 )
            {
              v22 = TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0);
              if ( v22 != INTEGER && v22 != STRING )
                break;
              GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: v22, pszExpecting: nullptr);
              ivi.iValue = 0;
              v23 = 0;
              do
              {
                v24 = szToken[v23];
                ivi.szValue[v23++] = v24;
              }
              while ( v24 != 0 );
              if ( !GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: ":")
                || !GDGetToken(tr, pszStore: szToken, nSize: 128, ttexpecting: STRING, pszExpecting: nullptr) )
              {
                return false;
              }
              v25 = 0;
              do
              {
                v26 = szToken[v25];
                ivi.szCaption[v25++] = v26;
              }
              while ( v26 != 0 );
              CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
                this: &this->m_Items,
                elem: this->m_Items.m_Size,
                src: &ivi);
            }
          }
          return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]");
        }
      }
      else
      {
        GDError(tr, error: "didn't expect '=' here");
      }
    }
    return false;
  }
LABEL_40:
  v10 = this->m_eType;
  if ( v10 == ivFlags )
  {
    v12 = "flags";
    goto LABEL_53;
  }
  if ( v10 == ivChoices )
  {
    v12 = "choices";
LABEL_53:
    GDError(tr, error: "no %s specified", v12);
    return false;
  }
  if ( v10 != ivBoolean )
    return true;
  this->m_eType = ivChoices;
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "1", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "Yes", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  strncpy(dest: (unsigned __int8 *)ivi.szValue, source: "0", count: 0x81u);
  strncpy(dest: (unsigned __int8 *)ivi.szCaption, source: "No", count: 0x81u);
  CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
    this: &this->m_Items,
    elem: this->m_Items.m_Size,
    src: &ivi);
  m_szDefault = (unsigned __int8 *)this->m_szDefault;
  if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "no") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)m_szDefault, s2: "yes") == 0 )
      strncpy(dest: m_szDefault, source: "1", count: 0x81u);
  }
  else
  {
    strncpy(dest: m_szDefault, source: "0", count: 0x81u);
  }
  if ( strcmp((const char *)m_szDefault, "0") == 0 || strcmp((const char *)m_szDefault, "1") == 0 )
    return true;
  GDError(tr, error: "boolean type specified with nonsensical default value: %s", (const char *)m_szDefault);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00449CC0
// Name: public: void GDinputvariable::Merge(class GDinputvariable __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDinputvariable::Merge(GDinputvariable *this, GDinputvariable *Other)
{
  GDinputvariable *v2; // eax
  int m_Size; // edi
  GDIVITEM *v5; // esi
  int v6; // eax
  GDIVITEM *v7; // ecx
  int v8; // edi
  int m_nAllocationCount; // eax
  GDIVITEM *m_pMemory; // ecx
  int v11; // eax
  GDIVITEM *v12; // edi
  int i; // [esp+4h] [ebp-10h]
  int nOurItems; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  bool bFound; // [esp+13h] [ebp-1h]

  v2 = Other;
  if ( Other->m_eType == this->m_eType )
  {
    m_Size = this->m_Items.m_Size;
    bFound = false;
    nOurItems = m_Size;
    i = 0;
    if ( Other->m_Items.m_Size > 0 )
    {
      v15 = 0;
      do
      {
        v5 = &v2->m_Items.m_Memory.m_pMemory[v15];
        v6 = 0;
        if ( m_Size <= 0 )
        {
LABEL_8:
          if ( !bFound )
          {
            v8 = this->m_Items.m_Size;
            m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
            if ( v8 + 1 > m_nAllocationCount )
              CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Items.m_Memory, num: v8 - m_nAllocationCount + 1);
            ++this->m_Items.m_Size;
            m_pMemory = this->m_Items.m_Memory.m_pMemory;
            v11 = this->m_Items.m_Size - v8 - 1;
            this->m_Items.m_pElements = this->m_Items.m_Memory.m_pMemory;
            if ( v11 > 0 )
              _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 268 * v11);
            v12 = &this->m_Items.m_Memory.m_pMemory[v8];
            if ( v12 != nullptr )
              qmemcpy(v12, v5, sizeof(GDIVITEM));
            m_Size = nOurItems;
          }
        }
        else
        {
          v7 = this->m_Items.m_Memory.m_pMemory;
          while ( v5->iValue != v7->iValue )
          {
            ++v6;
            ++v7;
            if ( v6 >= m_Size )
              goto LABEL_8;
          }
          bFound = true;
        }
        v2 = Other;
        ++v15;
        ++i;
      }
      while ( i < Other->m_Items.m_Size );
    }
  }
}

} // namespace vbsp2
