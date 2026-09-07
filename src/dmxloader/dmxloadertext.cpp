// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmxloader/dmxloadertext.cpp
// Functions: 31
// ============================================================

#include "dmxloader\dmxloadertext.h"

//------------------------------------------------------------------------------
// Address: 0x1024E130
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 2048, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 2048, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1024E1E0
// Name: SortAttributeByName
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortAttributeByName(CDmxAttribute **p1, CDmxAttribute **p2)
{
  const char *Name; // esi
  const char *v3; // eax

  Name = CDmxAttribute::GetName(this: *p1);
  v3 = CDmxAttribute::GetName(this: *p2);
  return _V_stricmp(s1: Name, s2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1024E210
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  char *j; // eax
  char v5; // al
  _BYTE *v6; // eax
  _BYTE *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack.m_nFileLine )
  {
    for ( j = (char *)CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = (char *)CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x1024E2E0
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCharConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x1024E480
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( !IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E530
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E5F0
// Name: private: void CDmxSerializerKeyValues2::SerializeElementAttribute(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CDmxAttribute *pAttribute)
{
  CDmxElement **m_pData; // eax
  CDmxElement *v5; // esi
  const char *TypeString; // eax
  const UniqueId_t *Id; // eax

  if ( pAttribute->m_Type == AT_FIRST_VALUE_TYPE )
  {
    m_pData = (CDmxElement **)pAttribute->m_pData;
  }
  else
  {
    `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
    m_pData = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
  }
  v5 = *m_pData;
  if ( CDmxSerializationDictionary::ShouldInlineElement(this: dict, pElement: *m_pData) )
  {
    TypeString = CDmxElement::GetTypeString(this: v5);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
    if ( v5 != nullptr )
      CDmxSerializerKeyValues2::SaveElement(this, buf, dict, pElement: v5, bWriteDelimiters: false);
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  }
  else
  {
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"", off_10425694);
    if ( v5 != nullptr )
    {
      Id = CDmxElement::GetId(this: v5);
      Serialize(buf, src: Id);
    }
    CUtlBuffer::PutChar(this: buf, c: 34);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E6B0
// Name: private: void CDmxSerializerKeyValues2::SerializeArrayAttribute(class CUtlBuffer __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *pAttribute)
{
  Color i; // edi
  int m_Put; // eax
  bool v5; // sf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  nCount = CDmxAttribute::GetArrayCount(this: pAttribute);
  CUtlBuffer::PutString(this: buf, pString: "\n[\n");
  ++buf->m_nTab;
  for ( i = 0; *(_DWORD *)&i < nCount; ++*(_DWORD *)&i )
  {
    if ( pAttribute->m_Type != AT_STRING_ARRAY )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      ++buf->m_nTab;
    }
    CDmxAttribute::SerializeElement(this: pAttribute, nIndex: i, buf);
    if ( pAttribute->m_Type != AT_STRING_ARRAY )
    {
      v5 = --buf->m_nTab < 0;
      if ( v5 )
        buf->m_nTab = 0;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = buf->m_Put;
        if ( v6 != 0 && buf->m_Memory.m_pMemory[v6 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = buf->m_Put;
        if ( v7 != 0 && buf->m_Memory.m_pMemory[v7 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 44;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
    if ( (buf->m_Flags & 1) != 0 )
    {
      v8 = buf->m_Put;
      if ( v8 != 0 && buf->m_Memory.m_pMemory[v8 - buf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: buf);
    }
    if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
    {
      buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
      CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
    }
  }
  v5 = --buf->m_nTab < 0;
  if ( v5 )
    buf->m_nTab = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v9 = buf->m_Put;
    if ( v9 != 0 && buf->m_Memory.m_pMemory[v9 - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 93;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E8B0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCharConversion *v7; // eax
  CUtlCharConversion *v8; // eax
  char *v9; // eax
  CUtlCharConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = (char *)m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1024E990
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024EB30
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCharConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( !UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024EC50
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ECE0
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1024ED60
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
      this: p_m_Attributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x1024EDF0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x1024EE70
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x1024EF00
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<S3RGBA,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<S3RGBA,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( !IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: v5, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F030
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  const char *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = (const char *)GetCStringCharConversion();
    v12 = buf;
    pAttributeName = (CUtlCharConversion *)CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_10425694) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( !UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F2A0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCharConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( !UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
      return 0;
    }
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024F420
// Name: private: void CDmxSerializerKeyValues2::SerializeElementArrayAttribute(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *pAttribute)
{
  CDmxElement *v5; // edi
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int nCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *array; // [esp+24h] [ebp+10h]

  if ( pAttribute->m_Memory.m_pMemory == (CDmxElement **)15 )
  {
    array = (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)pAttribute->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    array = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\n[\n");
  ++buf->m_nTab;
  nCount = array->m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v5 = array->m_Memory.m_pMemory[i];
      if ( CDmxSerializationDictionary::ShouldInlineElement(this: dict, pElement: v5) )
      {
        TypeString = CDmxElement::GetTypeString(this: v5);
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
        if ( v5 != nullptr )
          CDmxSerializerKeyValues2::SaveElement(this, buf, dict, pElement: v5, bWriteDelimiters: false);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( !CUtlBuffer::CheckPut(this: buf, nSize: 1) )
          goto LABEL_25;
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 125;
      }
      else
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"", off_10425694);
        if ( v5 != nullptr )
        {
          Id = CDmxElement::GetId(this: v5);
          Serialize(buf, src: Id);
        }
        if ( (buf->m_Flags & 1) != 0 )
        {
          v9 = buf->m_Put;
          if ( v9 != 0 && buf->m_Memory.m_pMemory[v9 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( !CUtlBuffer::CheckPut(this: buf, nSize: 1) )
          goto LABEL_25;
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
      }
      CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
LABEL_25:
      v10 = i;
      if ( i != nCount - 1 )
      {
        if ( (buf->m_Flags & 1) != 0 )
        {
          v11 = buf->m_Put;
          if ( v11 != 0 && buf->m_Memory.m_pMemory[v11 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 44;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      if ( (buf->m_Flags & 1) != 0 )
      {
        v12 = buf->m_Put;
        if ( v12 != 0 && buf->m_Memory.m_pMemory[v12 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
      ++i;
    }
    while ( v10 + 1 < nCount );
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "]");
}

//------------------------------------------------------------------------------
// Address: 0x1024F680
// Name: private: bool CDmxSerializerKeyValues2::SerializeAttributes(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::SerializeAttributes(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CVTFTexture *pElement)
{
  int Wide; // edi
  void *v5; // esp
  CDmxAttribute **v6; // ebx
  int v7; // esi
  CDmxAttribute *v8; // ebx
  const char *Name; // eax
  int m_Type; // edi
  int m_Put; // eax
  int v12; // eax
  int v14; // eax
  unsigned __int8 m_Flags; // cl
  int v16; // eax
  int v17; // eax
  int j; // ebx
  _DWORD v20[3]; // [esp+0h] [ebp-18h] BYREF
  int nCount; // [esp+Ch] [ebp-Ch]
  CDmxAttribute **ppAttributes; // [esp+10h] [ebp-8h]
  CDmxSerializerKeyValues2 *v23; // [esp+14h] [ebp-4h]
  int i; // [esp+28h] [ebp+10h]

  v23 = this;
  Wide = vgui::Image::GetWide(this: pElement);
  nCount = Wide;
  v5 = alloca(4 * Wide);
  v6 = (CDmxAttribute **)v20;
  v7 = 0;
  for ( ppAttributes = (CDmxAttribute **)v20; v7 < Wide; ++v7 )
    v20[v7] = vgui::ImageList::GetImage(this: (vgui::ImageList *)pElement, imageIndex: v7);
  qsort(base: v20, num: Wide, width: 4u, comp: SortAttributeByName);
  i = 0;
  if ( Wide > 0 )
  {
    while ( 1 )
    {
      v8 = v6[i];
      Name = CDmxAttribute::GetName(this: v8);
      m_Type = v8->m_Type;
      if ( v8->m_Type == AT_FIRST_VALUE_TYPE )
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", Name);
      else
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\" ", Name, CDmxAttribute::s_pAttributeTypeName[m_Type]);
      switch ( m_Type )
      {
        case 1:
          CDmxSerializerKeyValues2::SerializeElementAttribute(this: v23, buf, dict, pAttribute: v8);
          break;
        case 5:
          CDmxAttribute::Serialize(this: v8, buf);
          break;
        case 15:
          CDmxSerializerKeyValues2::SerializeElementArrayAttribute(
            this: v23,
            buf,
            dict,
            pAttribute: (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v8);
          break;
        default:
          if ( m_Type < 15 )
          {
            if ( CDmxAttribute::SerializesOnMultipleLines(this: v8) )
            {
              if ( (buf->m_Flags & 1) != 0 )
              {
                m_Put = buf->m_Put;
                if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: buf);
              }
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
                CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
              }
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v12 = buf->m_Put;
              if ( v12 != 0 && buf->m_Memory.m_pMemory[v12 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
            ++buf->m_nTab;
            CDmxAttribute::Serialize(this: v8, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
          }
          else
          {
            CDmxSerializerKeyValues2::SerializeArrayAttribute(this: v23, buf, pAttribute: v8);
          }
          break;
      }
      m_Flags = buf->m_Flags;
      if ( (m_Flags & 1) != 0 )
      {
        v16 = buf->m_Put;
        if ( v16 != 0 && buf->m_Memory.m_pMemory[v16 - buf->m_nOffset - 1] == 10 )
        {
          v17 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
          for ( j = v17 - 1; j >= 0; --j )
          {
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 9;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
          }
        }
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      if ( ++i >= nCount )
        break;
      v6 = ppAttributes;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024F940
// Name: private: bool CDmxSerializerKeyValues2::SaveElement(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::SaveElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CDmxElement *pElement,
        bool bWriteDelimiters)
{
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax

  if ( bWriteDelimiters )
  {
    TypeString = CDmxElement::GetTypeString(this: pElement);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
  }
  ++buf->m_nTab;
  CUtlBuffer::PutString(this: buf, pString: "\"id\" \"elementid\" ");
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  Id = CDmxElement::GetId(this: pElement);
  Serialize(buf, src: Id);
  CUtlBuffer::PutString(this: buf, pString: "\"\n");
  CDmxSerializerKeyValues2::SerializeAttributes(this, buf, dict, (CVTFTexture *)pElement);
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  if ( bWriteDelimiters )
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024FA20
// Name: public: bool CDmxSerializerKeyValues2::Serialize(class CUtlBuffer __near &,class CDmxElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Serialize(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *outBuf,
        CDmxElement *pRoot,
        const char *pFormatName)
{
  CUtlCharConversion *CStringCharConversion; // eax
  int i; // ebx
  CDmxElement *RootElement; // edi
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax
  int v11; // eax
  UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int> *m_pMemory; // eax
  CDmxSerializationDictionary dict; // [esp+8h] [ebp-28h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+2Ch] [ebp-4h]
  bool bFlatMode; // [esp+40h] [ebp+10h]

  v15 = this;
  CStringCharConversion = GetCStringCharConversion();
  SetSerializationDelimiter(pConv: CStringCharConversion);
  SetSerializationArrayDelimiter(pDelimiter: ",");
  bFlatMode = _V_stricmp(s1: pFormatName, s2: "keyvalues2_flat") == 0;
  CDmxSerializationDictionary::CDmxSerializationDictionary(this: &dict, nElementsHint: 0);
  CDmxSerializationDictionary::BuildElementList(this: &dict, pElement: pRoot, bFlatMode);
  for ( i = CDmxSerializationDictionary::FirstRootElement(this: &dict);
        i != -1;
        i = CDmxSerializationDictionary::NextRootElement(this: &dict, h: i) )
  {
    RootElement = CDmxSerializationDictionary::GetRootElement(this: &dict, h: i);
    TypeString = CDmxElement::GetTypeString(this: RootElement);
    CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n{\n", TypeString);
    ++outBuf->m_nTab;
    CUtlBuffer::PutString(this: outBuf, pString: "\"id\" \"elementid\" ");
    if ( (outBuf->m_Flags & 1) != 0 )
    {
      m_Put = outBuf->m_Put;
      if ( m_Put != 0 && outBuf->m_Memory.m_pMemory[m_Put - outBuf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: outBuf);
    }
    if ( CUtlBuffer::CheckPut(this: outBuf, nSize: 1) )
    {
      outBuf->m_Memory.m_pMemory[outBuf->m_Put++ - outBuf->m_nOffset] = 34;
      CUtlBuffer::AddNullTermination(this: outBuf, nPut: outBuf->m_Put);
    }
    Id = CDmxElement::GetId(this: RootElement);
    Serialize(buf: outBuf, src: Id);
    CUtlBuffer::PutString(this: outBuf, pString: "\"\n");
    CDmxSerializerKeyValues2::SerializeAttributes(this: v15, buf: outBuf, &dict, pElement: (CVTFTexture *)RootElement);
    if ( --outBuf->m_nTab < 0 )
      outBuf->m_nTab = 0;
    CUtlBuffer::Printf(this: outBuf, pFmt: "}\n");
    if ( (outBuf->m_Flags & 1) != 0 )
    {
      v11 = outBuf->m_Put;
      if ( v11 != 0 && outBuf->m_Memory.m_pMemory[v11 - outBuf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: outBuf);
    }
    if ( CUtlBuffer::CheckPut(this: outBuf, nSize: 1) )
    {
      outBuf->m_Memory.m_pMemory[outBuf->m_Put++ - outBuf->m_nOffset] = 10;
      CUtlBuffer::AddNullTermination(this: outBuf, nPut: outBuf->m_Put);
    }
  }
  SetSerializationDelimiter(pConv: nullptr);
  SetSerializationArrayDelimiter(pDelimiter: nullptr);
  CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::RemoveAll(this: &dict.m_Dict);
  m_pMemory = dict.m_Dict.m_Elements.m_pMemory;
  dict.m_Dict.m_FirstFree = -1;
  if ( dict.m_Dict.m_Elements.m_nGrowSize >= 0 )
  {
    if ( dict.m_Dict.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dict.m_Dict.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      dict.m_Dict.m_Elements.m_pMemory = nullptr;
    }
    dict.m_Dict.m_Elements.m_nAllocationCount = 0;
  }
  dict.m_Dict.m_LastAlloc.index = -1;
  if ( dict.m_Dict.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024FC30
// Name: bool SerializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SerializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement *pRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxSerializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxSerializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Serialize(this: &dmxSerializer, outBuf: buf, pRoot, pFormatName: pFileName);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxSerializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxSerializer.m_ElementDict.m_Attributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxSerializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1024FCA0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        const char *pElementType,
        int *pHandle)
{
  CDmxElement *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCharConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = (CDmxElement *)DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  if ( g_KeyValues2ErrorStack.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack.m_errorStack[g_KeyValues2ErrorStack.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  }
  g_KeyValues2ErrorStack.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        --g_KeyValues2ErrorStack.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024FFA0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCharConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x102500C0
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10250180
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10320100
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x103277F0
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x10320170
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0044A2C0
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 2048, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 2048, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00674D80
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack_0.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack_0.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x00674E50
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack_0.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x00674FF0
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( !IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x006750A0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        const char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  const char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (const char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00675160
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x00675240
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        const char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006753E0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( !UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00675500
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00675590
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00675610
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_Attributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x006756A0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x00675720
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x006757B0
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<vgui::TreeNode *,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( !IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006758E0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  const char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (const char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = GetCStringCharConversion();
    v12 = buf;
    pAttributeName = CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_756194) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( !UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00675B50
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *buf,
        int hElement,
        const char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, (CUtlBuffer *)buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( !UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack_0,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack_0,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00675CD0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        const char *pElementType,
        int *pHandle)
{
  CDmxElement *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = (CDmxElement *)DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  if ( g_KeyValues2ErrorStack_0.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack_0.m_errorStack[g_KeyValues2ErrorStack_0.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  }
  g_KeyValues2ErrorStack_0.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack_0.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack_0.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        --g_KeyValues2ErrorStack_0.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  (CDmxAttribute *)buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = (CUtlCStringConversion *)pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00675FC0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x006760E0
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack_0.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x006761A0
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00681680
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006836C0
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x006816F0
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack___0()
{
  memset(&g_KeyValues2ErrorStack_0, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack_0.m_pFilename = "NULL";
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  g_KeyValues2ErrorStack_0.m_errorIndex = 0;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00681730
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00681770
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x006817B0
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x006817D0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x006817E0
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1024E160
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 2048, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 2048, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1024E240
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  char *j; // eax
  char v5; // al
  _BYTE *v6; // eax
  _BYTE *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack.m_nFileLine )
  {
    for ( j = (char *)CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = (char *)CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x1024E310
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCharConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x1024E4B0
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( !IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E560
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E620
// Name: private: void CDmxSerializerKeyValues2::SerializeElementAttribute(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CDmxAttribute *pAttribute)
{
  CDmxElement **m_pData; // eax
  CDmxElement *v5; // esi
  const char *TypeString; // eax
  const UniqueId_t *Id; // eax

  if ( pAttribute->m_Type == AT_FIRST_VALUE_TYPE )
  {
    m_pData = (CDmxElement **)pAttribute->m_pData;
  }
  else
  {
    `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
    m_pData = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
  }
  v5 = *m_pData;
  if ( CDmxSerializationDictionary::ShouldInlineElement(this: dict, pElement: *m_pData) )
  {
    TypeString = CDmxElement::GetTypeString(this: v5);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
    if ( v5 != nullptr )
      CDmxSerializerKeyValues2::SaveElement(this, buf, dict, pElement: v5, bWriteDelimiters: false);
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  }
  else
  {
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"", off_10425694);
    if ( v5 != nullptr )
    {
      Id = CDmxElement::GetId(this: v5);
      Serialize(buf, src: Id);
    }
    CUtlBuffer::PutChar(this: buf, c: 34);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E6E0
// Name: private: void CDmxSerializerKeyValues2::SerializeArrayAttribute(class CUtlBuffer __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *pAttribute)
{
  DmeTime_t v3; // edi
  int m_Put; // eax
  bool v5; // sf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  nCount = CDmxAttribute::GetArrayCount(this: pAttribute);
  CUtlBuffer::PutString(this: buf, pString: "\n[\n");
  ++buf->m_nTab;
  for ( v3.m_tms = 0; v3.m_tms < nCount; ++v3.m_tms )
  {
    if ( pAttribute->m_Type != AT_STRING_ARRAY )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      ++buf->m_nTab;
    }
    CDmxAttribute::SerializeElement(this: pAttribute, nIndex: v3, buf);
    if ( pAttribute->m_Type != AT_STRING_ARRAY )
    {
      v5 = --buf->m_nTab < 0;
      if ( v5 )
        buf->m_nTab = 0;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = buf->m_Put;
        if ( v6 != 0 && buf->m_Memory.m_pMemory[v6 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
    if ( v3.m_tms != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = buf->m_Put;
        if ( v7 != 0 && buf->m_Memory.m_pMemory[v7 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 44;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
    if ( (buf->m_Flags & 1) != 0 )
    {
      v8 = buf->m_Put;
      if ( v8 != 0 && buf->m_Memory.m_pMemory[v8 - buf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: buf);
    }
    if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
    {
      buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
      CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
    }
  }
  v5 = --buf->m_nTab < 0;
  if ( v5 )
    buf->m_nTab = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v9 = buf->m_Put;
    if ( v9 != 0 && buf->m_Memory.m_pMemory[v9 - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 93;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E8E0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCharConversion *v7; // eax
  CUtlCharConversion *v8; // eax
  char *v9; // eax
  CUtlCharConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = (char *)m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1024E9C0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024EB60
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCharConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( !UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024EC80
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ED10
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1024ED90
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
      this: p_m_Attributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x1024EE20
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x1024EEA0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x1024EF30
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<S3RGBA,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<S3RGBA,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( !IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: v5, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F060
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  const char *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = (const char *)GetCStringCharConversion();
    v12 = buf;
    pAttributeName = (CUtlCharConversion *)CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_10425694) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( !UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F2D0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCharConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( !UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
      return 0;
    }
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1024F450
// Name: private: void CDmxSerializerKeyValues2::SerializeElementArrayAttribute(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *pAttribute)
{
  CDmxElement *v5; // edi
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int nCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *array; // [esp+24h] [ebp+10h]

  if ( pAttribute->m_Memory.m_pMemory == (CDmxElement **)15 )
  {
    array = (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)pAttribute->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    array = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\n[\n");
  ++buf->m_nTab;
  nCount = array->m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v5 = array->m_Memory.m_pMemory[i];
      if ( CDmxSerializationDictionary::ShouldInlineElement(this: dict, pElement: v5) )
      {
        TypeString = CDmxElement::GetTypeString(this: v5);
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
        if ( v5 != nullptr )
          CDmxSerializerKeyValues2::SaveElement(this, buf, dict, pElement: v5, bWriteDelimiters: false);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( !CUtlBuffer::CheckPut(this: buf, nSize: 1) )
          goto LABEL_25;
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 125;
      }
      else
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"", off_10425694);
        if ( v5 != nullptr )
        {
          Id = CDmxElement::GetId(this: v5);
          Serialize(buf, src: Id);
        }
        if ( (buf->m_Flags & 1) != 0 )
        {
          v9 = buf->m_Put;
          if ( v9 != 0 && buf->m_Memory.m_pMemory[v9 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( !CUtlBuffer::CheckPut(this: buf, nSize: 1) )
          goto LABEL_25;
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
      }
      CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
LABEL_25:
      v10 = i;
      if ( i != nCount - 1 )
      {
        if ( (buf->m_Flags & 1) != 0 )
        {
          v11 = buf->m_Put;
          if ( v11 != 0 && buf->m_Memory.m_pMemory[v11 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 44;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      if ( (buf->m_Flags & 1) != 0 )
      {
        v12 = buf->m_Put;
        if ( v12 != 0 && buf->m_Memory.m_pMemory[v12 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
      ++i;
    }
    while ( v10 + 1 < nCount );
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "]");
}

//------------------------------------------------------------------------------
// Address: 0x1024F6B0
// Name: private: bool CDmxSerializerKeyValues2::SerializeAttributes(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::SerializeAttributes(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CVTFTexture *pElement)
{
  int Wide; // edi
  void *v5; // esp
  CDmxAttribute **v6; // ebx
  int v7; // esi
  CDmxAttribute *v8; // ebx
  const char *Name; // eax
  int m_Type; // edi
  int m_Put; // eax
  int v12; // eax
  int v14; // eax
  unsigned __int8 m_Flags; // cl
  int v16; // eax
  int v17; // eax
  int j; // ebx
  _DWORD v20[3]; // [esp+0h] [ebp-18h] BYREF
  int nCount; // [esp+Ch] [ebp-Ch]
  CDmxAttribute **ppAttributes; // [esp+10h] [ebp-8h]
  CDmxSerializerKeyValues2 *v23; // [esp+14h] [ebp-4h]
  int i; // [esp+28h] [ebp+10h]

  v23 = this;
  Wide = vgui::Image::GetWide(this: pElement);
  nCount = Wide;
  v5 = alloca(4 * Wide);
  v6 = (CDmxAttribute **)v20;
  v7 = 0;
  for ( ppAttributes = (CDmxAttribute **)v20; v7 < Wide; ++v7 )
    v20[v7] = vgui::ImageList::GetImage(this: (vgui::ImageList *)pElement, imageIndex: v7);
  qsort(base: v20, num: Wide, width: 4u, comp: SortAttributeByName);
  i = 0;
  if ( Wide > 0 )
  {
    while ( 1 )
    {
      v8 = v6[i];
      Name = CDmxAttribute::GetName(this: v8);
      m_Type = v8->m_Type;
      if ( v8->m_Type == AT_FIRST_VALUE_TYPE )
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", Name);
      else
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\" ", Name, CDmxAttribute::s_pAttributeTypeName[m_Type]);
      switch ( m_Type )
      {
        case 1:
          CDmxSerializerKeyValues2::SerializeElementAttribute(this: v23, buf, dict, pAttribute: v8);
          break;
        case 5:
          CDmxAttribute::Serialize(this: v8, buf);
          break;
        case 15:
          CDmxSerializerKeyValues2::SerializeElementArrayAttribute(
            this: v23,
            buf,
            dict,
            pAttribute: (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v8);
          break;
        default:
          if ( m_Type < 15 )
          {
            if ( CDmxAttribute::SerializesOnMultipleLines(this: v8) )
            {
              if ( (buf->m_Flags & 1) != 0 )
              {
                m_Put = buf->m_Put;
                if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: buf);
              }
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
                CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
              }
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v12 = buf->m_Put;
              if ( v12 != 0 && buf->m_Memory.m_pMemory[v12 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
            ++buf->m_nTab;
            CDmxAttribute::Serialize(this: v8, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
          }
          else
          {
            CDmxSerializerKeyValues2::SerializeArrayAttribute(this: v23, buf, pAttribute: v8);
          }
          break;
      }
      m_Flags = buf->m_Flags;
      if ( (m_Flags & 1) != 0 )
      {
        v16 = buf->m_Put;
        if ( v16 != 0 && buf->m_Memory.m_pMemory[v16 - buf->m_nOffset - 1] == 10 )
        {
          v17 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
          for ( j = v17 - 1; j >= 0; --j )
          {
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 9;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
          }
        }
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      if ( ++i >= nCount )
        break;
      v6 = ppAttributes;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024F970
// Name: private: bool CDmxSerializerKeyValues2::SaveElement(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::SaveElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CDmxElement *pElement,
        bool bWriteDelimiters)
{
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax

  if ( bWriteDelimiters )
  {
    TypeString = CDmxElement::GetTypeString(this: pElement);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
  }
  ++buf->m_nTab;
  CUtlBuffer::PutString(this: buf, pString: "\"id\" \"elementid\" ");
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  Id = CDmxElement::GetId(this: pElement);
  Serialize(buf, src: Id);
  CUtlBuffer::PutString(this: buf, pString: "\"\n");
  CDmxSerializerKeyValues2::SerializeAttributes(this, buf, dict, (CVTFTexture *)pElement);
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  if ( bWriteDelimiters )
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024FA50
// Name: public: bool CDmxSerializerKeyValues2::Serialize(class CUtlBuffer __near &,class CDmxElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Serialize(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *outBuf,
        CDmxElement *pRoot,
        const char *pFormatName)
{
  CUtlCharConversion *CStringCharConversion; // eax
  int i; // ebx
  CDmxElement *RootElement; // edi
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax
  int v11; // eax
  UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int> *m_pMemory; // eax
  CDmxSerializationDictionary dict; // [esp+8h] [ebp-28h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+2Ch] [ebp-4h]
  bool bFlatMode; // [esp+40h] [ebp+10h]

  v15 = this;
  CStringCharConversion = GetCStringCharConversion();
  SetSerializationDelimiter(pConv: CStringCharConversion);
  SetSerializationArrayDelimiter(pDelimiter: ",");
  bFlatMode = _V_stricmp(s1: pFormatName, s2: "keyvalues2_flat") == 0;
  CDmxSerializationDictionary::CDmxSerializationDictionary(this: &dict, nElementsHint: 0);
  CDmxSerializationDictionary::BuildElementList(this: &dict, pElement: pRoot, bFlatMode);
  for ( i = CDmxSerializationDictionary::FirstRootElement(this: &dict);
        i != -1;
        i = CDmxSerializationDictionary::NextRootElement(this: &dict, h: i) )
  {
    RootElement = CDmxSerializationDictionary::GetRootElement(this: &dict, h: i);
    TypeString = CDmxElement::GetTypeString(this: RootElement);
    CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n{\n", TypeString);
    ++outBuf->m_nTab;
    CUtlBuffer::PutString(this: outBuf, pString: "\"id\" \"elementid\" ");
    if ( (outBuf->m_Flags & 1) != 0 )
    {
      m_Put = outBuf->m_Put;
      if ( m_Put != 0 && outBuf->m_Memory.m_pMemory[m_Put - outBuf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: outBuf);
    }
    if ( CUtlBuffer::CheckPut(this: outBuf, nSize: 1) )
    {
      outBuf->m_Memory.m_pMemory[outBuf->m_Put++ - outBuf->m_nOffset] = 34;
      CUtlBuffer::AddNullTermination(this: outBuf, nPut: outBuf->m_Put);
    }
    Id = CDmxElement::GetId(this: RootElement);
    Serialize(buf: outBuf, src: Id);
    CUtlBuffer::PutString(this: outBuf, pString: "\"\n");
    CDmxSerializerKeyValues2::SerializeAttributes(this: v15, buf: outBuf, &dict, pElement: (CVTFTexture *)RootElement);
    if ( --outBuf->m_nTab < 0 )
      outBuf->m_nTab = 0;
    CUtlBuffer::Printf(this: outBuf, pFmt: "}\n");
    if ( (outBuf->m_Flags & 1) != 0 )
    {
      v11 = outBuf->m_Put;
      if ( v11 != 0 && outBuf->m_Memory.m_pMemory[v11 - outBuf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: outBuf);
    }
    if ( CUtlBuffer::CheckPut(this: outBuf, nSize: 1) )
    {
      outBuf->m_Memory.m_pMemory[outBuf->m_Put++ - outBuf->m_nOffset] = 10;
      CUtlBuffer::AddNullTermination(this: outBuf, nPut: outBuf->m_Put);
    }
  }
  SetSerializationDelimiter(pConv: nullptr);
  SetSerializationArrayDelimiter(pDelimiter: nullptr);
  CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::RemoveAll(this: &dict.m_Dict);
  m_pMemory = dict.m_Dict.m_Elements.m_pMemory;
  dict.m_Dict.m_FirstFree = -1;
  if ( dict.m_Dict.m_Elements.m_nGrowSize >= 0 )
  {
    if ( dict.m_Dict.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dict.m_Dict.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      dict.m_Dict.m_Elements.m_pMemory = nullptr;
    }
    dict.m_Dict.m_Elements.m_nAllocationCount = 0;
  }
  dict.m_Dict.m_LastAlloc.index = -1;
  if ( dict.m_Dict.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024FC60
// Name: bool SerializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SerializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement *pRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxSerializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxSerializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Serialize(this: &dmxSerializer, outBuf: buf, pRoot, pFormatName: pFileName);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxSerializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxSerializer.m_ElementDict.m_Attributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxSerializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1024FCD0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  unsigned __int8 *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCharConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: (CDmxElement *)v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  if ( g_KeyValues2ErrorStack.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack.m_errorStack[g_KeyValues2ErrorStack.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  }
  g_KeyValues2ErrorStack.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &tokenBuf);
        --g_KeyValues2ErrorStack.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024FFC0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCharConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x102500E0
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x102501A0
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1031BF90
// Name: _dynamic_initializer_for__xload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__xload_command__()
{
  ConCommand::ConCommand(
    this: &xload_command,
    pName: "xload",
    callback: xload,
    pHelpString: "Load a saved game from a console storage device.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__xload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103202D0
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10325E60
// Name: _dynamic_atexit_destructor_for__xload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xload_command__()
{
  ConCommand::~ConCommand(this: &xload_command);
}

//------------------------------------------------------------------------------
// Address: 0x103279E0
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x10320340
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104C2810
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 0x800u, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 0x800u, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x104C28C0
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack_0.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack_0.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x104C2990
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack_0.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x104C2B30
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) == 0 )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C2BE0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C2CA0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x104C2D80
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C2F20
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) == 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104C3040
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C30D0
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x104C3150
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_Attributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x104C31E0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x104C3260
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x104C32F0
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<vgui::TreeNode *,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) == 0 )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v14[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
          count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C3420
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = GetCStringCharConversion();
    v12 = buf;
    pAttributeName = CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_1077983C) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) == 0 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C3690
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, (CUtlBuffer *)buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) == 0 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack_0,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack_0,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104C3810
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  unsigned __int8 *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: (CDmxElement *)v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  if ( g_KeyValues2ErrorStack_0.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack_0.m_errorStack[g_KeyValues2ErrorStack_0.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  }
  g_KeyValues2ErrorStack_0.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack_0.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack_0.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        --g_KeyValues2ErrorStack_0.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  (CDmxAttribute *)buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = (CUtlCStringConversion *)pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C3B00
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x104C3C20
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack_0.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x104C3CE0
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x105C6980
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCB50
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x105C69F0
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack___0()
{
  memset(&g_KeyValues2ErrorStack_0, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack_0.m_pFilename = "NULL";
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  g_KeyValues2ErrorStack_0.m_errorIndex = 0;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x105C6A30
// Name: _dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__()
{
  CTextureReference::CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq);
  return atexit(func: dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCB70
// Name: _dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_pPowerOfTwoFrameBufferTexture_SheetSeq__()
{
  CTextureReference::~CTextureReference(this: &s_pPowerOfTwoFrameBufferTexture_SheetSeq);
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B2750
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 0x800u, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 0x800u, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x004B2800
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x004B28D0
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x004B2A70
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( !IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2B20
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2BE0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x004B2CC0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2E60
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( !UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2F80
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3010
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B3090
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CachedAssetInfo_t,int>::Grow(this: p_m_Attributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x004B3120
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CachedAssetInfo_t,int>::Grow(this: p_m_ArrayAttributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x004B31A0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CachedAssetInfo_t,int>::Grow(this: p_m_ArrayAttributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x004B3230
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<vgui::TreeNode *,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( !IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<unsigned long,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v14[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
          count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3360
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = GetCStringCharConversion();
    v12 = buf;
    pAttributeName = CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_4F6C2C) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( !UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B35D0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, (CUtlBuffer *)buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( !UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B3750
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  unsigned __int8 *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: (CDmxElement *)v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  if ( g_KeyValues2ErrorStack.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack.m_errorStack[g_KeyValues2ErrorStack.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  }
  g_KeyValues2ErrorStack.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        --g_KeyValues2ErrorStack.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  (CDmxAttribute *)buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = (CUtlCStringConversion *)pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3A40
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x004B3B60
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004B3C20
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004B8DF0
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x004B9570
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x004B8E60
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8EA0
// Name: _dynamic_atexit_destructor_for__r_showenvcubemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_showenvcubemap__()
{
  ConVar::~ConVar(this: &r_showenvcubemap);
}

//------------------------------------------------------------------------------
// Address: 0x004B8EB0
// Name: _dynamic_atexit_destructor_for__r_eyegloss__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyegloss__()
{
  ConVar::~ConVar(this: &r_eyegloss);
}

//------------------------------------------------------------------------------
// Address: 0x004B8EC0
// Name: _dynamic_atexit_destructor_for__r_eyemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyemove__()
{
  ConVar::~ConVar(this: &r_eyemove);
}

//------------------------------------------------------------------------------
// Address: 0x004B8ED0
// Name: _dynamic_atexit_destructor_for__r_eyeshift_x__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_x__()
{
  ConVar::~ConVar(this: &r_eyeshift_x);
}

//------------------------------------------------------------------------------
// Address: 0x004B8EE0
// Name: _dynamic_atexit_destructor_for__r_eyeshift_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_y__()
{
  ConVar::~ConVar(this: &r_eyeshift_y);
}

//------------------------------------------------------------------------------
// Address: 0x004B8EF0
// Name: _dynamic_atexit_destructor_for__r_eyeshift_z__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_z__()
{
  ConVar::~ConVar(this: &r_eyeshift_z);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F00
// Name: _dynamic_atexit_destructor_for__r_eyesize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyesize__()
{
  ConVar::~ConVar(this: &r_eyesize);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F10
// Name: _dynamic_atexit_destructor_for__mat_softwareskin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_softwareskin__()
{
  ConVar::~ConVar(this: &mat_softwareskin);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F20
// Name: _dynamic_atexit_destructor_for__r_nohw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nohw__()
{
  ConVar::~ConVar(this: &r_nohw);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F30
// Name: _dynamic_atexit_destructor_for__r_nosw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nosw__()
{
  ConVar::~ConVar(this: &r_nosw);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F40
// Name: _dynamic_atexit_destructor_for__r_teeth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_teeth__()
{
  ConVar::~ConVar(this: &r_teeth);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F50
// Name: _dynamic_atexit_destructor_for__r_drawentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawentities__()
{
  ConVar::~ConVar(this: &r_drawentities);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F60
// Name: _dynamic_atexit_destructor_for__r_flex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flex__()
{
  ConVar::~ConVar(this: &r_flex);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F70
// Name: _dynamic_atexit_destructor_for__r_eyes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyes__()
{
  ConVar::~ConVar(this: &r_eyes);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F80
// Name: _dynamic_atexit_destructor_for__r_skin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_skin__()
{
  ConVar::~ConVar(this: &r_skin);
}

//------------------------------------------------------------------------------
// Address: 0x004B8F90
// Name: _dynamic_atexit_destructor_for__r_maxmodeldecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_maxmodeldecal__()
{
  ConVar::~ConVar(this: &r_maxmodeldecal);
}

//------------------------------------------------------------------------------
// Address: 0x004B8FA0
// Name: _dynamic_atexit_destructor_for__r_modelwireframedecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_modelwireframedecal__()
{
  ConVar::~ConVar(this: &r_modelwireframedecal);
}

//------------------------------------------------------------------------------
// Address: 0x004B8FB0
// Name: _dynamic_atexit_destructor_for__mat_wireframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_wireframe__()
{
  ConVar::~ConVar(this: &mat_wireframe);
}

//------------------------------------------------------------------------------
// Address: 0x004B8FC0
// Name: _dynamic_atexit_destructor_for__mat_normals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normals__()
{
  ConVar::~ConVar(this: &mat_normals);
}

//------------------------------------------------------------------------------
// Address: 0x004B8FD0
// Name: _dynamic_atexit_destructor_for__r_eyeglintlodpixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeglintlodpixels__()
{
  ConVar::~ConVar(this: &r_eyeglintlodpixels);
}

//------------------------------------------------------------------------------
// Address: 0x004B8FE0
// Name: _dynamic_atexit_destructor_for__r_rootlod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rootlod__()
{
  ConVar::~ConVar(this: &r_rootlod);
}

//------------------------------------------------------------------------------
// Address: 0x004B8FF0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x004B9030
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CTextureReference::~CTextureReference(this: &_s_ApplicationObject.m_DefaultEnvCubemap);
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x004B9070
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x004B9080
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x004B9090
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x004B90A0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004B90B0
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x004B90F0
// Name: _dynamic_atexit_destructor_for__r_showenvcubemap___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_showenvcubemap___0()
{
  ConVar::~ConVar(this: &r_showenvcubemap_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9100
// Name: _dynamic_atexit_destructor_for__r_eyegloss___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyegloss___0()
{
  ConVar::~ConVar(this: &r_eyegloss_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9110
// Name: _dynamic_atexit_destructor_for__r_eyemove___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyemove___0()
{
  ConVar::~ConVar(this: &r_eyemove_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9120
// Name: _dynamic_atexit_destructor_for__r_eyeshift_x___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_x___0()
{
  ConVar::~ConVar(this: &r_eyeshift_x_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9130
// Name: _dynamic_atexit_destructor_for__r_eyeshift_y___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_y___0()
{
  ConVar::~ConVar(this: &r_eyeshift_y_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9140
// Name: _dynamic_atexit_destructor_for__r_eyeshift_z___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeshift_z___0()
{
  ConVar::~ConVar(this: &r_eyeshift_z_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9150
// Name: _dynamic_atexit_destructor_for__r_eyesize___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyesize___0()
{
  ConVar::~ConVar(this: &r_eyesize_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9160
// Name: _dynamic_atexit_destructor_for__mat_softwareskin___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_softwareskin___0()
{
  ConVar::~ConVar(this: &mat_softwareskin_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9170
// Name: _dynamic_atexit_destructor_for__r_nohw___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nohw___0()
{
  ConVar::~ConVar(this: &r_nohw_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9180
// Name: _dynamic_atexit_destructor_for__r_nosw___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_nosw___0()
{
  ConVar::~ConVar(this: &r_nosw_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9190
// Name: _dynamic_atexit_destructor_for__r_teeth___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_teeth___0()
{
  ConVar::~ConVar(this: &r_teeth_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B91A0
// Name: _dynamic_atexit_destructor_for__r_drawentities___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawentities___0()
{
  ConVar::~ConVar(this: &r_drawentities_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B91B0
// Name: _dynamic_atexit_destructor_for__r_flex___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flex___0()
{
  ConVar::~ConVar(this: &r_flex_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B91C0
// Name: _dynamic_atexit_destructor_for__r_eyes___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyes___0()
{
  ConVar::~ConVar(this: &r_eyes_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B91D0
// Name: _dynamic_atexit_destructor_for__r_skin___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_skin___0()
{
  ConVar::~ConVar(this: &r_skin_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B91E0
// Name: _dynamic_atexit_destructor_for__r_maxmodeldecal___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_maxmodeldecal___0()
{
  ConVar::~ConVar(this: &r_maxmodeldecal_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B91F0
// Name: _dynamic_atexit_destructor_for__r_modelwireframedecal___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_modelwireframedecal___0()
{
  ConVar::~ConVar(this: &r_modelwireframedecal_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9200
// Name: _dynamic_atexit_destructor_for__mat_normals___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normals___0()
{
  ConVar::~ConVar(this: &mat_normals_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9210
// Name: _dynamic_atexit_destructor_for__r_eyeglintlodpixels___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeglintlodpixels___0()
{
  ConVar::~ConVar(this: &r_eyeglintlodpixels_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9220
// Name: _dynamic_atexit_destructor_for__r_rootlod___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rootlod___0()
{
  ConVar::~ConVar(this: &r_rootlod_0);
}

//------------------------------------------------------------------------------
// Address: 0x004B9230
// Name: _dynamic_atexit_destructor_for__s_AssetCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_AssetCache__()
{
  CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>::~CUtlRBTree<CAssetCache::CachedAssetList_t,unsigned short,bool (__cdecl *)(CAssetCache::CachedAssetList_t const &,CAssetCache::CachedAssetList_t const &),CUtlMemory<UtlRBTreeNode_t<CAssetCache::CachedAssetList_t,unsigned short>,unsigned short>>(this: &s_AssetCache.m_CachedAssets);
  CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>::~CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int>>(this: &s_AssetCache.m_usedAssets);
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::~CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>(this: &s_AssetCache.m_ModList);
}

//------------------------------------------------------------------------------
// Address: 0x004B9290
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004B92E0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9320
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x004B9330
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x005644D0
// Name: SortAttributeByName
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortAttributeByName(CDmxAttribute **p1, CDmxAttribute **p2)
{
  const char *Name; // esi
  const char *v3; // eax

  Name = CDmxAttribute::GetName(this: *p1);
  v3 = CDmxAttribute::GetName(this: *p2);
  return _V_stricmp(s1: Name, s2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00564500
// Name: private: void CDmxSerializerKeyValues2::SerializeElementAttribute(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CDmxAttribute *pAttribute)
{
  CDmxElement **m_pData; // eax
  CDmxElement *v5; // esi
  const char *TypeString; // eax
  const UniqueId_t *Id; // eax

  if ( pAttribute->m_Type == AT_FIRST_VALUE_TYPE )
  {
    m_pData = (CDmxElement **)pAttribute->m_pData;
  }
  else
  {
    `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
    m_pData = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
  }
  v5 = *m_pData;
  if ( CDmxSerializationDictionary::ShouldInlineElement(this: dict, pElement: *m_pData) )
  {
    TypeString = CDmxElement::GetTypeString(this: v5);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
    if ( v5 != nullptr )
      CDmxSerializerKeyValues2::SaveElement(this, buf, dict, pElement: v5, bWriteDelimiters: false);
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  }
  else
  {
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"", off_5BB1C4[0]);
    if ( v5 != nullptr )
    {
      Id = CDmxElement::GetId(this: v5);
      Serialize(buf, src: Id);
    }
    CUtlBuffer::PutChar(this: buf, c: 34);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005645C0
// Name: private: void CDmxSerializerKeyValues2::SerializeArrayAttribute(class CUtlBuffer __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *pAttribute)
{
  Color i; // edi
  int m_Put; // eax
  bool v5; // sf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  nCount = CDmxAttribute::GetArrayCount(this: pAttribute);
  CUtlBuffer::PutString(this: buf, pString: "\n[\n");
  ++buf->m_nTab;
  for ( i = 0; *(_DWORD *)&i < nCount; ++*(_DWORD *)&i )
  {
    if ( pAttribute->m_Type != AT_STRING_ARRAY )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        m_Put = buf->m_Put;
        if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      ++buf->m_nTab;
    }
    CDmxAttribute::SerializeElement(this: pAttribute, nIndex: i, buf);
    if ( pAttribute->m_Type != AT_STRING_ARRAY )
    {
      v5 = --buf->m_nTab < 0;
      if ( v5 )
        buf->m_nTab = 0;
      if ( (buf->m_Flags & 1) != 0 )
      {
        v6 = buf->m_Put;
        if ( v6 != 0 && buf->m_Memory.m_pMemory[v6 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
    if ( i != nCount - 1 )
    {
      if ( (buf->m_Flags & 1) != 0 )
      {
        v7 = buf->m_Put;
        if ( v7 != 0 && buf->m_Memory.m_pMemory[v7 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 44;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
    }
    if ( (buf->m_Flags & 1) != 0 )
    {
      v8 = buf->m_Put;
      if ( v8 != 0 && buf->m_Memory.m_pMemory[v8 - buf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: buf);
    }
    if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
    {
      buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
      CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
    }
  }
  v5 = --buf->m_nTab < 0;
  if ( v5 )
    buf->m_nTab = 0;
  if ( (buf->m_Flags & 1) != 0 )
  {
    v9 = buf->m_Put;
    if ( v9 != 0 && buf->m_Memory.m_pMemory[v9 - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 93;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005647C0
// Name: private: void CDmxSerializerKeyValues2::SerializeElementArrayAttribute(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::SerializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *pAttribute)
{
  CDmxElement *v5; // edi
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int nCount; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *array; // [esp+24h] [ebp+10h]

  if ( pAttribute->m_Memory.m_pMemory == (CDmxElement **)15 )
  {
    array = (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)pAttribute->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    array = &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\n[\n");
  ++buf->m_nTab;
  nCount = array->m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v5 = array->m_Memory.m_pMemory[i];
      if ( CDmxSerializationDictionary::ShouldInlineElement(this: dict, pElement: v5) )
      {
        TypeString = CDmxElement::GetTypeString(this: v5);
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
        if ( v5 != nullptr )
          CDmxSerializerKeyValues2::SaveElement(this, buf, dict, pElement: v5, bWriteDelimiters: false);
        if ( (buf->m_Flags & 1) != 0 )
        {
          m_Put = buf->m_Put;
          if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) == 0 )
          goto LABEL_25;
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 125;
      }
      else
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"", off_5BB1C4[0]);
        if ( v5 != nullptr )
        {
          Id = CDmxElement::GetId(this: v5);
          Serialize(buf, src: Id);
        }
        if ( (buf->m_Flags & 1) != 0 )
        {
          v9 = buf->m_Put;
          if ( v9 != 0 && buf->m_Memory.m_pMemory[v9 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) == 0 )
          goto LABEL_25;
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
      }
      CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
LABEL_25:
      v10 = i;
      if ( i != nCount - 1 )
      {
        if ( (buf->m_Flags & 1) != 0 )
        {
          v11 = buf->m_Put;
          if ( v11 != 0 && buf->m_Memory.m_pMemory[v11 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 44;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      if ( (buf->m_Flags & 1) != 0 )
      {
        v12 = buf->m_Put;
        if ( v12 != 0 && buf->m_Memory.m_pMemory[v12 - buf->m_nOffset - 1] == 10 )
          CUtlBuffer::PutTabs(this: buf);
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
      }
      ++i;
    }
    while ( v10 + 1 < nCount );
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "]");
}

//------------------------------------------------------------------------------
// Address: 0x00564A20
// Name: private: bool CDmxSerializerKeyValues2::SerializeAttributes(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::SerializeAttributes(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        ConCommandBase *pElement)
{
  int Name; // edi
  void *v5; // esp
  CDmxAttribute **v6; // ebx
  int v7; // esi
  CDmxAttribute *v8; // ebx
  const char *v9; // eax
  int m_Type; // edi
  int m_Put; // eax
  int v12; // eax
  int v14; // eax
  unsigned __int8 m_Flags; // cl
  int v16; // eax
  int v17; // eax
  int j; // ebx
  _DWORD v20[3]; // [esp+0h] [ebp-18h] BYREF
  int nCount; // [esp+Ch] [ebp-Ch]
  CDmxAttribute **ppAttributes; // [esp+10h] [ebp-8h]
  CDmxSerializerKeyValues2 *v23; // [esp+14h] [ebp-4h]
  int i; // [esp+28h] [ebp+10h]

  v23 = this;
  Name = (int)ConCommandBase::GetName(this: pElement);
  nCount = Name;
  v5 = alloca(4 * Name);
  v6 = (CDmxAttribute **)v20;
  v7 = 0;
  for ( ppAttributes = (CDmxAttribute **)v20; v7 < Name; ++v7 )
    v20[v7] = CDmxElement::GetAttribute(this: (CDmxElement *)pElement, nIndex: v7);
  qsort(base: (char *)v20, num: Name, width: 4u, comp: (int (__cdecl *)(const void *, const void *))SortAttributeByName);
  i = 0;
  if ( Name > 0 )
  {
    while ( 1 )
    {
      v8 = v6[i];
      v9 = CDmxAttribute::GetName(this: v8);
      m_Type = v8->m_Type;
      if ( v8->m_Type == AT_FIRST_VALUE_TYPE )
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v9);
      else
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\" ", v9, CDmxAttribute::s_pAttributeTypeName[m_Type]);
      switch ( m_Type )
      {
        case 1:
          CDmxSerializerKeyValues2::SerializeElementAttribute(this: v23, buf, dict, pAttribute: v8);
          break;
        case 5:
          CDmxAttribute::Serialize(this: v8, buf);
          break;
        case 15:
          CDmxSerializerKeyValues2::SerializeElementArrayAttribute(
            this: v23,
            buf,
            dict,
            pAttribute: (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)v8);
          break;
        default:
          if ( m_Type < 15 )
          {
            if ( CDmxAttribute::SerializesOnMultipleLines(this: v8) )
            {
              if ( (buf->m_Flags & 1) != 0 )
              {
                m_Put = buf->m_Put;
                if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                  CUtlBuffer::PutTabs(this: buf);
              }
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
                CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
              }
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v12 = buf->m_Put;
              if ( v12 != 0 && buf->m_Memory.m_pMemory[v12 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
            ++buf->m_nTab;
            CDmxAttribute::Serialize(this: v8, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
          }
          else
          {
            CDmxSerializerKeyValues2::SerializeArrayAttribute(this: v23, buf, pAttribute: v8);
          }
          break;
      }
      m_Flags = buf->m_Flags;
      if ( (m_Flags & 1) != 0 )
      {
        v16 = buf->m_Put;
        if ( v16 != 0 && buf->m_Memory.m_pMemory[v16 - buf->m_nOffset - 1] == 10 )
        {
          v17 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
          for ( j = v17 - 1; j >= 0; --j )
          {
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 9;
              CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
            }
          }
        }
      }
      if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 10;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      if ( ++i >= nCount )
        break;
      v6 = ppAttributes;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564CE0
// Name: private: bool CDmxSerializerKeyValues2::SaveElement(class CUtlBuffer __near &,class CDmxSerializationDictionary __near &,class CDmxElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::SaveElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxSerializationDictionary *dict,
        CDmxElement *pElement,
        bool bWriteDelimiters)
{
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax

  if ( bWriteDelimiters )
  {
    TypeString = CDmxElement::GetTypeString(this: pElement);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", TypeString);
  }
  ++buf->m_nTab;
  CUtlBuffer::PutString(this: buf, pString: "\"id\" \"elementid\" ");
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
  {
    buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = 34;
    CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
  }
  Id = CDmxElement::GetId(this: pElement);
  Serialize(buf, src: Id);
  CUtlBuffer::PutString(this: buf, pString: "\"\n");
  CDmxSerializerKeyValues2::SerializeAttributes(this, buf, dict, (ConCommandBase *)pElement);
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  if ( bWriteDelimiters )
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564DC0
// Name: public: bool CDmxSerializerKeyValues2::Serialize(class CUtlBuffer __near &,class CDmxElement __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Serialize(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *outBuf,
        CDmxElement *pRoot,
        const char *pFormatName)
{
  CUtlCStringConversion *CStringCharConversion; // eax
  int i; // ebx
  CDmxElement *RootElement; // edi
  const char *TypeString; // eax
  int m_Put; // eax
  const UniqueId_t *Id; // eax
  int v11; // eax
  UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int> *m_pMemory; // eax
  CDmxSerializationDictionary dict; // [esp+8h] [ebp-28h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+2Ch] [ebp-4h]
  bool bFlatMode; // [esp+40h] [ebp+10h]

  v15 = this;
  CStringCharConversion = GetCStringCharConversion();
  SetSerializationDelimiter(pConv: CStringCharConversion);
  SetSerializationArrayDelimiter(pDelimiter: ",");
  bFlatMode = _V_stricmp(s1: pFormatName, s2: "keyvalues2_flat") == 0;
  CDmxSerializationDictionary::CDmxSerializationDictionary(this: &dict, nElementsHint: 0);
  CDmxSerializationDictionary::BuildElementList(this: &dict, pElement: pRoot, bFlatMode);
  for ( i = CDmxSerializationDictionary::FirstRootElement(this: &dict);
        i != -1;
        i = CDmxSerializationDictionary::NextRootElement(this: &dict, h: i) )
  {
    RootElement = CDmxSerializationDictionary::GetRootElement(this: &dict, h: i);
    TypeString = CDmxElement::GetTypeString(this: RootElement);
    CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n{\n", TypeString);
    ++outBuf->m_nTab;
    CUtlBuffer::PutString(this: outBuf, pString: "\"id\" \"elementid\" ");
    if ( (outBuf->m_Flags & 1) != 0 )
    {
      m_Put = outBuf->m_Put;
      if ( m_Put != 0 && outBuf->m_Memory.m_pMemory[m_Put - outBuf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: outBuf);
    }
    if ( CUtlBuffer::CheckPut(this: outBuf, nSize: 1) != 0 )
    {
      outBuf->m_Memory.m_pMemory[outBuf->m_Put++ - outBuf->m_nOffset] = 34;
      CUtlBuffer::AddNullTermination(this: outBuf, nPut: outBuf->m_Put);
    }
    Id = CDmxElement::GetId(this: RootElement);
    Serialize(buf: outBuf, src: Id);
    CUtlBuffer::PutString(this: outBuf, pString: "\"\n");
    CDmxSerializerKeyValues2::SerializeAttributes(
      this: v15,
      buf: outBuf,
      &dict,
      pElement: (ConCommandBase *)RootElement);
    if ( --outBuf->m_nTab < 0 )
      outBuf->m_nTab = 0;
    CUtlBuffer::Printf(this: outBuf, pFmt: "}\n");
    if ( (outBuf->m_Flags & 1) != 0 )
    {
      v11 = outBuf->m_Put;
      if ( v11 != 0 && outBuf->m_Memory.m_pMemory[v11 - outBuf->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: outBuf);
    }
    if ( CUtlBuffer::CheckPut(this: outBuf, nSize: 1) != 0 )
    {
      outBuf->m_Memory.m_pMemory[outBuf->m_Put++ - outBuf->m_nOffset] = 10;
      CUtlBuffer::AddNullTermination(this: outBuf, nPut: outBuf->m_Put);
    }
  }
  SetSerializationDelimiter(pConv: nullptr);
  SetSerializationArrayDelimiter(pDelimiter: nullptr);
  CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::RemoveAll(this: &dict.m_Dict);
  m_pMemory = dict.m_Dict.m_Elements.m_pMemory;
  dict.m_Dict.m_FirstFree = -1;
  if ( dict.m_Dict.m_Elements.m_nGrowSize >= 0 )
  {
    if ( dict.m_Dict.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dict.m_Dict.m_Elements.m_pMemory);
      m_pMemory = nullptr;
      dict.m_Dict.m_Elements.m_pMemory = nullptr;
    }
    dict.m_Dict.m_Elements.m_nAllocationCount = 0;
  }
  dict.m_Dict.m_LastAlloc.index = -1;
  if ( dict.m_Dict.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564FD0
// Name: bool SerializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SerializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement *pRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxSerializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxSerializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Serialize(this: &dmxSerializer, outBuf: buf, pRoot, pFormatName: pFileName);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&dmxSerializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&dmxSerializer.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&dmxSerializer);
  return v3;
}

} // namespace particle_import

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A3B70
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 0x800u, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 0x800u, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x006A3C20
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack_0.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack_0.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x006A3CF0
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack_0.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x006A3E90
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) == 0 )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A3F40
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A4000
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x006A40E0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A4280
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) == 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x006A43A0
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A4430
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x006A44B0
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_Attributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x006A4540
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x006A45C0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x006A4650
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<vgui::TreeNode *,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) == 0 )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v14[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
          count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A4780
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = GetCStringCharConversion();
    v12 = buf;
    pAttributeName = CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_79C854) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) == 0 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A49F0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, (CUtlBuffer *)buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) == 0 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack_0,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack_0,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006A4B70
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  unsigned __int8 *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: (CDmxElement *)v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  if ( g_KeyValues2ErrorStack_0.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack_0.m_errorStack[g_KeyValues2ErrorStack_0.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  }
  g_KeyValues2ErrorStack_0.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack_0.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack_0.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        --g_KeyValues2ErrorStack_0.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  (CDmxAttribute *)buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = (CUtlCStringConversion *)pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006A4E60
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x006A4F80
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack_0.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x006A5040
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x006B33F0
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6140
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x006B3460
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack___0()
{
  memset(&g_KeyValues2ErrorStack_0, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack_0.m_pFilename = "NULL";
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  g_KeyValues2ErrorStack_0.m_errorIndex = 0;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006B34A0
// Name: _WinMain_::_2_::_dynamic_atexit_destructor_for__steamApp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl WinMain_::_2_::_dynamic_atexit_destructor_for__steamApp__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &steamApp.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &steamApp.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&steamApp.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&steamApp.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&steamApp.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x006B34E0
// Name: _WinMain_::_2_::_dynamic_atexit_destructor_for__sceneViewerApp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl WinMain_::_2_::_dynamic_atexit_destructor_for__sceneViewerApp__()
{
  CTextureReference::~CTextureReference(this: &sceneViewerApp.m_DefaultEnvCubemap);
  CUtlDict<int,unsigned short>::RemoveAll(this: &sceneViewerApp.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &sceneViewerApp.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sceneViewerApp.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sceneViewerApp.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&sceneViewerApp.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x006B3520
// Name: _dynamic_atexit_destructor_for__g_ModelLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ModelLookup__()
{
  CUtlVector<modellookup_t,CUtlMemory<modellookup_t,int>>::~CUtlVector<modellookup_t,CUtlMemory<modellookup_t,int>>(this: &g_ModelLookup);
}

//------------------------------------------------------------------------------
// Address: 0x006B3530
// Name: _dynamic_atexit_destructor_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc4__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc4);
}

//------------------------------------------------------------------------------
// Address: 0x006B3540
// Name: _dynamic_atexit_destructor_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataAlloc8__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_DataAlloc8);
}

//------------------------------------------------------------------------------
// Address: 0x006B3550
// Name: _dynamic_atexit_destructor_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AttrAlloc__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_AttrAlloc);
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00524AD0
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_tag> v3; // [esp-4h] [ebp-1010h]
  char pDest[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char v5[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+1018h] [ebp+Ch] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 0x800u, pFormat: pFmt, params);
  V_snprintf(pDest: v5, maxLen: 0x800u, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v5);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x0052F290
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebp
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack_0.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack_0.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x0052F350
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v4; // esi
  int v5; // ebp
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v4 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v4 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v4 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v4] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      v5 = 5;
      break;
    case ',':
      v4 = 1;
      v5 = 4;
      break;
    case '[':
      v4 = 1;
      v5 = 2;
      break;
    case ']':
      v4 = 1;
      v5 = 3;
      break;
    case '{':
      v4 = 1;
      v5 = 0;
      break;
    case '}':
      v4 = 1;
      v5 = 1;
      break;
    default:
LABEL_13:
      v5 = -1;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v4,
    nInitialPut: v4,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v4);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v4; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack_0.m_nFileLine;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0052F4E0
// Name: public: int CDmxElementDictionary::FindElement(struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::FindElement(CDmxElementDictionary *this, const UniqueId_t *objectId)
{
  int m_Size; // ebx
  int v4; // esi
  int i; // edi

  m_Size = this->m_Dict.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; !IsUniqueIdEqual(id1: objectId, id2: &this->m_Dict.m_Memory.m_pMemory[i].m_Id); ++i )
  {
    if ( ++v4 >= m_Size )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0052F530
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // ebx
  int Element; // eax
  CDmxElement *m_pElement; // ebp
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int m_Size; // [esp+4h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      Element = CDmxElementDictionary::FindElement(
                  this,
                  objectId: (const UniqueId_t *)&this->m_Attributes.m_Memory.m_pMemory[v2].___u2);
      if ( Element == -1 )
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[Element].m_pElement;
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v2].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052F590
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  bool v10; // bl
  CDmxElement *v11; // esi
  _DWORD *m_pData; // eax

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    v10 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: &hElement);
    if ( v10 )
    {
      if ( hElement == -1 )
        v11 = nullptr;
      else
        v11 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v11;
    }
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052F650
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0052F730
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int Token; // eax
  CUtlBuffer tokenBuf; // [esp+8h] [ebp-34h] BYREF
  CDmxAttribute *pAttribute; // [esp+44h] [ebp+8h]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(
      this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount,
      growSize: 0,
      initSize: 0,
      nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          Token = CDmxSerializerKeyValues2::ReadToken(
                    this,
                    buf,
                    token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
          if ( Token == -1 || Token == 7 )
            break;
          if ( Token == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( Token != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack_0,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            Token = CDmxSerializerKeyValues2::ReadToken(
                      this,
                      buf,
                      token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
          }
          if ( Token != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  tokenBuf: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack_0,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Get >= 0 && tokenBuf.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)tokenBuf.m_Memory.m_nAllocationCount);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052F8F0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) == 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052FA70
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  bool v2; // sf
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  v2 = this->m_Dict.m_Memory.m_nGrowSize < 0;
  this->m_Dict.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  v2 = this->m_Attributes.m_Memory.m_nGrowSize < 0;
  this->m_Attributes.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  v2 = this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0;
  this->m_ArrayAttributes.m_Size = 0;
  if ( v2 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052FB00
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int> > *p_m_Attributes; // esi
  int v4; // eax

  p_m_Attributes = &this->m_Attributes;
  v4 = CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int>>::InsertBefore(
         this: &this->m_Attributes,
         elem: this->m_Attributes.m_Size);
  p_m_Attributes->m_Memory.m_pMemory[v4].m_bObjectId = true;
  p_m_Attributes->m_Memory.m_pMemory[v4].m_pAttribute = pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_Memory.m_pMemory[v4].___u2);
}

//------------------------------------------------------------------------------
// Address: 0x0052FB40
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElement *m_pElement; // ebp
  int v3; // edi
  CDmxAttribute *v4; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<S3RGBA,int> *v6; // esi
  char *v7; // eax
  int Element; // eax
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v11; // ecx
  int v12; // eax
  bool v13; // zf
  CDmxElement **v14; // eax
  int v15; // [esp+8h] [ebp-8h]
  int m_Size; // [esp+Ch] [ebp-4h]

  m_pElement = nullptr;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v3 = 0;
    v15 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v4 = *(CDmxAttribute **)((char *)&this->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v3);
      if ( v4->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v4, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v4->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v6 = (CUtlMemory<S3RGBA,int> *)v4->m_pData;
      v7 = (char *)this->m_ArrayAttributes.m_Memory.m_pMemory + v3;
      if ( v7[4] != 0 )
        Element = CDmxElementDictionary::FindElement(this, objectId: (const UniqueId_t *)(v7 + 8));
      else
        Element = *((_DWORD *)v7 + 2);
      if ( Element != -1 )
        m_pElement = this->m_Dict.m_Memory.m_pMemory[Element].m_pElement;
      m_pMemory = v6[1].m_pMemory;
      m_nAllocationCount = v6->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v6, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++v6[1].m_pMemory;
      v11 = v6->m_pMemory;
      v12 = (char *)v6[1].m_pMemory - (char *)m_pMemory - 1;
      v13 = (char *)v6[1].m_pMemory - (char *)m_pMemory == 1;
      v6[1].m_nAllocationCount = (int)v6->m_pMemory;
      if ( v12 >= 0 && !v13 )
        _V_memmove(
          dest: (unsigned __int8 *)&v11[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v11[(_DWORD)m_pMemory],
          count: 4 * v12);
      v14 = (CDmxElement **)&v6->m_pMemory[(_DWORD)m_pMemory];
      if ( v14 != nullptr )
        *v14 = m_pElement;
      v15 += 24;
      if ( --m_Size == 0 )
        break;
      v3 = v15;
      m_pElement = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052FC30
// Name: private: int CDmxSerializerKeyValues2::CreateDmxElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::CreateDmxElement(CDmxSerializerKeyValues2 *this, const char *pElementType)
{
  CDmxElement *v3; // eax
  CDmxElement *v4; // ebx
  int v5; // edi

  v3 = (CDmxElement *)DMXAlloc(size: 0x34u);
  if ( v3 != nullptr )
    v4 = CDmxElement::CDmxElement(this: v3, pType: pElementType);
  else
    v4 = nullptr;
  v5 = CUtlVector<CDmxElementDictionary::DictInfo_t,CUtlMemory<CDmxElementDictionary::DictInfo_t,int>>::InsertBefore(
         this: &this->m_ElementDict.m_Dict,
         elem: this->m_ElementDict.m_Dict.m_Size);
  this->m_ElementDict.m_Dict.m_Memory.m_pMemory[v5].m_pElement = v4;
  InvalidateUniqueId(pDest: &this->m_ElementDict.m_Dict.m_Memory.m_pMemory[v5].m_Id);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0052FC90
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v7; // eax
  CDmxAttribute *v8; // ebp
  _DWORD *m_pData; // eax
  unsigned __int8 *CStringCharConversion; // esi
  int Token; // eax
  CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int> > *v12; // esi
  unsigned int v13; // eax
  CUtlCharConversion *v14; // ebp
  CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int> > *p_m_ArrayAttributes; // esi
  int v16; // eax
  CDmxAttribute *pAttribute; // [esp+Ch] [ebp-250h]
  int hArrayElement; // [esp+10h] [ebp-24Ch]
  CUtlCharConversion *pConv; // [esp+14h] [ebp-248h] BYREF
  CUtlBuffer tokenBuf; // [esp+18h] [ebp-244h] BYREF
  UniqueId_t id; // [esp+48h] [ebp-214h] BYREF
  char elementType[256]; // [esp+58h] [ebp-204h] BYREF
  char elementId[260]; // [esp+158h] [ebp-104h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      pAttributeName);
    return 0;
  }
  CDmxElement::LockForChanges(this: m_pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
  v8 = v7;
  hArrayElement = (int)v7;
  if ( v7->m_Type != AT_FIRST_ARRAY_TYPE )
  {
    CDmxAttribute::AllocateDataMemory(this: v7, type: AT_FIRST_ARRAY_TYPE);
    m_pData = v8->m_pData;
    if ( m_pData != nullptr )
    {
      *m_pData = 0;
      m_pData[1] = 0;
      m_pData[2] = 0;
      m_pData[3] = 0;
      m_pData[4] = 0;
    }
  }
  if ( m_pElement != nullptr )
    CDmxElement::LockForChanges(this: m_pElement, bLock: false);
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = (unsigned __int8 *)GetCStringCharConversion();
  tokenBuf.m_Memory.m_pMemory = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount) == 2 )
  {
    pAttribute = nullptr;
    if ( buf->m_Error != 0 )
    {
LABEL_16:
      CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
      return 1;
    }
    while ( 1 )
    {
      Token = CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
      if ( Token == -1 || Token == 7 )
        break;
      if ( Token == 3 )
        goto LABEL_16;
      if ( (int)pAttribute > 0 )
      {
        if ( Token != 4 )
        {
          CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ',', didn't find it!");
          goto LABEL_38;
        }
        Token = CDmxSerializerKeyValues2::ReadToken(
                  this,
                  buf,
                  token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
      }
      if ( Token != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting element type, didn't find it!");
        goto LABEL_38;
      }
      CUtlBuffer::GetDelimitedString(
        this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount,
        pConv: (CUtlCharConversion *)CStringCharConversion,
        pString: &elementType[4],
        nMaxChars: 256);
      if ( _V_strcmp(s1: &elementType[4], s2: off_5C4734) != 0 )
      {
        if ( !CDmxSerializerKeyValues2::UnserializeElement(
                this,
                buf,
                pElementType: &elementType[4],
                pHandle: (int *)&pConv) )
          goto LABEL_38;
        v14 = pConv;
        p_m_ArrayAttributes = &this->m_ElementDict.m_ArrayAttributes;
        v16 = CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int>>::InsertBefore(
                this: &this->m_ElementDict.m_ArrayAttributes,
                elem: this->m_ElementDict.m_ArrayAttributes.m_Size);
        p_m_ArrayAttributes->m_Memory.m_pMemory[v16].m_bObjectId = false;
        p_m_ArrayAttributes->m_Memory.m_pMemory[v16].m_pAttribute = (CDmxAttribute *)hArrayElement;
        p_m_ArrayAttributes->m_Memory.m_pMemory[v16].m_hElement = (int)v14;
        v8 = (CDmxAttribute *)hArrayElement;
      }
      else
      {
        if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount) != 5 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack_0,
            pFmt: "Expecting element reference, didn't find it!");
          goto LABEL_38;
        }
        CUtlBuffer::GetDelimitedString(
          this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount,
          pConv: (CUtlCharConversion *)CStringCharConversion,
          pString: &elementId[4],
          nMaxChars: 256);
        if ( UniqueIdFromString(pDest: (UniqueId_t *)&id.m_Value[4], pBuf: &elementId[4], nMaxLen: 0) == 0 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack_0,
            pFmt: "Encountered invalid element ID data!");
          goto LABEL_38;
        }
        v12 = &this->m_ElementDict.m_ArrayAttributes;
        v13 = CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int>>::InsertBefore(
                this: &this->m_ElementDict.m_ArrayAttributes,
                elem: this->m_ElementDict.m_ArrayAttributes.m_Size);
        v12->m_Memory.m_pMemory[v13].m_bObjectId = true;
        v12->m_Memory.m_pMemory[v13].m_pAttribute = v8;
        CopyUniqueId(
          src: (const UniqueId_t *)&id.m_Value[4],
          pDest: (UniqueId_t *)&this->m_ElementDict.m_ArrayAttributes.m_Memory.m_pMemory[v13].___u2);
      }
      pAttribute = (CDmxAttribute *)((char *)pAttribute + 1);
      if ( buf->m_Error != 0 )
        goto LABEL_16;
      CStringCharConversion = tokenBuf.m_Memory.m_pMemory;
    }
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting ']', didn't find it!");
LABEL_38:
    CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
  }
  else
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '[', didn't find it!");
    if ( tokenBuf.m_Get >= 0 && tokenBuf.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)tokenBuf.m_Memory.m_nAllocationCount);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0052FF80
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) == 0 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack_0,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack_0,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00530100
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  CDmxAttribute *DmxElement; // ebp
  int m_errorIndex; // eax
  unsigned __int8 *CStringCharConversion; // esi
  int m_nAllocationCount; // eax
  IMemAlloc *v9; // ecx
  int Token; // eax
  DmAttributeType_t v12; // esi
  char v13; // al
  bool v14; // sf
  CUtlBuffer tokenBuf; // [esp+10h] [ebp-234h] BYREF
  char attributeName[256]; // [esp+40h] [ebp-204h] BYREF
  char attributeType[260]; // [esp+140h] [ebp-104h] BYREF

  *pHandle = -1;
  DmxElement = (CDmxAttribute *)CDmxSerializerKeyValues2::CreateDmxElement(this, pElementType);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&tokenBuf,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  if ( g_KeyValues2ErrorStack_0.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack_0.m_errorStack[g_KeyValues2ErrorStack_0.m_errorIndex].u.m_Id = (int)tokenBuf.m_Memory.m_pMemory;
    m_errorIndex = g_KeyValues2ErrorStack_0.m_errorIndex;
  }
  g_KeyValues2ErrorStack_0.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack_0.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack_0.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = (unsigned __int8 *)GetCStringCharConversion();
  tokenBuf.m_Memory.m_pMemory = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '{', didn't find it!");
LABEL_7:
    if ( tokenBuf.m_Get >= 0 )
    {
      m_nAllocationCount = tokenBuf.m_Memory.m_nAllocationCount;
      if ( tokenBuf.m_Memory.m_nAllocationCount != 0 )
      {
        v9 = _g_pMemAlloc;
LABEL_10:
        v9->Free_2(this: v9, a2: (void *)m_nAllocationCount);
      }
    }
LABEL_11:
    --g_KeyValues2ErrorStack_0.m_errorIndex;
    return 0;
  }
  if ( buf->m_Error == 0 )
  {
    while ( 1 )
    {
      Token = CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
      if ( Token == -1 || Token == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack_0, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_7;
      }
      if ( Token == 1 )
        goto LABEL_29;
      if ( Token != 5 )
        break;
      CUtlBuffer::GetDelimitedString(
        this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount,
        pConv: (CUtlCharConversion *)CStringCharConversion,
        pString: &attributeName[4],
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack_0,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          &attributeName[4]);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount);
        goto LABEL_11;
      }
      CUtlBuffer::GetDelimitedString(
        this: (CUtlBuffer *)&tokenBuf.m_Memory.m_nAllocationCount,
        pConv: (CUtlCharConversion *)CStringCharConversion,
        pString: &attributeType[4],
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: &attributeType[4]) != 0 )
      {
        v12 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v12], s2: &attributeType[4]) != 0 )
        {
          if ( ++v12 >= AT_TYPE_COUNT )
            goto LABEL_25;
        }
        if ( v12 == AT_UNKNOWN )
        {
LABEL_25:
          v13 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  hElement: (int)DmxElement,
                  pAttributeName: &attributeName[4],
                  pElementType: &attributeType[4]);
          goto LABEL_26;
        }
        if ( v12 == AT_FIRST_ARRAY_TYPE )
        {
          v13 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  hElement: (int)DmxElement,
                  pAttributeName: &attributeName[4]);
        }
        else if ( v12 < AT_FIRST_ARRAY_TYPE )
        {
          v13 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  buf,
                  hElement: (int)DmxElement,
                  pAttributeName: &attributeName[4],
                  nAttrType: v12);
        }
        else
        {
          v13 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement: DmxElement,
                  pAttributeName: &attributeName[4],
                  nAttrType: v12);
        }
LABEL_26:
        if ( v13 == 0 )
          goto LABEL_40;
        CStringCharConversion = tokenBuf.m_Memory.m_pMemory;
      }
      else if ( _V_stricmp(s1: "id", s2: &attributeName[4]) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, hElement: (int)DmxElement) == 0 )
      {
        goto LABEL_44;
      }
      if ( buf->m_Error != 0 )
        goto LABEL_29;
    }
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack_0,
      pFmt: "Expecting attribute name, didn't find it!");
LABEL_40:
    if ( tokenBuf.m_Get >= 0 )
    {
      m_nAllocationCount = tokenBuf.m_Memory.m_nAllocationCount;
      if ( tokenBuf.m_Memory.m_nAllocationCount != 0 )
      {
        v9 = _g_pMemAlloc;
        goto LABEL_10;
      }
    }
    goto LABEL_11;
  }
LABEL_29:
  v14 = tokenBuf.m_Get < 0;
  *pHandle = (int)DmxElement;
  if ( !v14 && tokenBuf.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)tokenBuf.m_Memory.m_nAllocationCount);
  --g_KeyValues2ErrorStack_0.m_errorIndex;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005303F0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  switch ( v4 )
  {
    case -1:
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    case 7:
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 1;
    case 5:
      CStringCharConversion = GetCStringCharConversion();
      v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v8 = alloca(v7);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
      v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return v9;
    default:
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack_0,
        pFmt: "Expecting element type name, didn't find it!");
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00530510
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  CDmxElement **v4; // ebp
  char v6; // bl
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax

  v4 = ppRoot;
  *ppRoot = nullptr;
  v6 = 1;
  g_KeyValues2ErrorStack_0.m_pFilename = pFileName;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  while ( buf->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pHandle: (int *)&ppRoot);
    if ( v6 == 0 || ppRoot == (CDmxElement **)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)ppRoot;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  *v4 = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v4);
    *v4 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x005305D0
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+0h] [ebp-44h] BYREF

  memset(&dmxUnserializer.m_ElementDict.m_Dict.m_Memory.m_nAllocationCount, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(
         this: (CDmxSerializerKeyValues2 *)&dmxUnserializer.m_ElementDict.m_Dict.m_Memory.m_nAllocationCount,
         pFileName,
         buf,
         ppRoot);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes.m_Memory.m_nAllocationCount);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes.m_Memory.m_nAllocationCount);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&dmxUnserializer.m_ElementDict.m_Dict.m_Memory.m_nAllocationCount);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00534DA0
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005358E0
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x00534E10
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack___0()
{
  memset(&g_KeyValues2ErrorStack_0, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack_0.m_pFilename = "NULL";
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  g_KeyValues2ErrorStack_0.m_errorIndex = 0;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00534E50
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x00534E60
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x00534E70
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00534E80
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x00534EC0
// Name: _dynamic_atexit_destructor_for__s_CPerftestGameControlsProxy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_CPerftestGameControlsProxy__()
{
  s_CPerftestGameControlsProxy.__vftable = (CPerftestGameControlsProxy_vtbl *)&IMaterialProxy::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00534ED0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00534F10
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x00534F50
// Name: _dynamic_atexit_destructor_for__s_TGARenderer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TGARenderer__()
{
  CTGARenderer::~CTGARenderer(this: &s_TGARenderer);
}

//------------------------------------------------------------------------------
// Address: 0x00534F60
// Name: _dynamic_atexit_destructor_for__ui_setmenus_hidden_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_setmenus_hidden_command__()
{
  ConCommand::~ConCommand(this: &ui_setmenus_hidden_command);
}

//------------------------------------------------------------------------------
// Address: 0x00534F70
// Name: _dynamic_atexit_destructor_for__ui_setmenu_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_setmenu_command__()
{
  ConCommand::~ConCommand(this: &ui_setmenu_command);
}

//------------------------------------------------------------------------------
// Address: 0x00534F80
// Name: _dynamic_atexit_destructor_for__s_GameUISystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameUISystemMgr__()
{
  CGameUISystemMgr::~CGameUISystemMgr(this: &s_GameUISystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x00534F90
// Name: _dynamic_atexit_destructor_for__g_FontTextureCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FontTextureCache__()
{
  CFontTextureCache::~CFontTextureCache(this: &g_FontTextureCache);
}

//------------------------------------------------------------------------------
// Address: 0x00534FA0
// Name: _dynamic_atexit_destructor_for__g_GameUISystemSurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameUISystemSurface__()
{
  g_GameUISystemSurface.__vftable = (CGameUISystemSurface_vtbl *)&CGameUISystemSurface::`vftable';
  g_GameUISystemSurface.m_CustomFontFileNames.m_Size = 0;
  g_GameUISystemSurface.m_BitmapFontFileNames.m_Size = 0;
  CUtlDict<int,int>::RemoveAll(this: &g_GameUISystemSurface.m_BitmapFontFileMapping);
  CUtlDict<int,int>::RemoveAll(this: &g_GameUISystemSurface.m_BitmapFontFileMapping);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_GameUISystemSurface.m_BitmapFontFileMapping.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_GameUISystemSurface.m_BitmapFontFileNames);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_GameUISystemSurface.m_CustomFontFileNames);
}

//------------------------------------------------------------------------------
// Address: 0x00534FF0
// Name: _dynamic_atexit_destructor_for__g_GameUISchemeManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameUISchemeManager__()
{
  CGameUISchemeManager::~CGameUISchemeManager(this: &g_GameUISchemeManager);
}

//------------------------------------------------------------------------------
// Address: 0x00535000
// Name: _dynamic_atexit_destructor_for__g_InputGameUI__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_InputGameUI__()
{
  CInputGameUI::~CInputGameUI(this: &g_InputGameUI);
}

//------------------------------------------------------------------------------
// Address: 0x00535030
// Name: _dynamic_atexit_destructor_for__g_mapScriptHandles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_mapScriptHandles__()
{
  CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameUISystem *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameUISystem *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_mapScriptHandles.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00535060
// Name: _dynamic_atexit_destructor_for__ui_script_error_path__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_script_error_path__()
{
  ConVar::~ConVar(this: &ui_script_error_path);
}

//------------------------------------------------------------------------------
// Address: 0x00535070
// Name: _dynamic_atexit_destructor_for__g_mapScriptHandles___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_mapScriptHandles___0()
{
  CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CGameGraphic *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CGameGraphic *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_mapScriptHandles_0.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00535150
// Name: _dynamic_atexit_destructor_for__ui_script_spew_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_script_spew_level__()
{
  ConVar::~ConVar(this: &ui_script_spew_level);
}

//------------------------------------------------------------------------------
// Address: 0x00535160
// Name: _dynamic_atexit_destructor_for__g_CGameUIScriptInterface_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CGameUIScriptInterface_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CGameUIScriptInterface_ScriptDesc.m_FunctionBindings);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040B120
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 0x800u, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 0x800u, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1040B1D0
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x1040B2A0
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x1040B440
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) == 0 )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B4F0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B5B0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1040B690
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B830
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) == 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1040B950
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B9E0
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1040BA60
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(this: p_m_Attributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x1040BAF0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x1040BB70
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPerfVisualBenchmark::RunInfo_t,int>::Grow(
      this: p_m_ArrayAttributes,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x1040BC00
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<vgui::TreeNode *,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) == 0 )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v14[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
          count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040BD30
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = GetCStringCharConversion();
    v12 = buf;
    pAttributeName = CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_105F4A2C) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) == 0 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040BFA0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) == 0 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040C120
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  unsigned __int8 *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: (CDmxElement *)v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  if ( g_KeyValues2ErrorStack.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack.m_errorStack[g_KeyValues2ErrorStack.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  }
  g_KeyValues2ErrorStack.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        --g_KeyValues2ErrorStack.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = (CUtlCStringConversion *)pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040C410
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x1040C530
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1040C5F0
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  bool v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1042F5C0
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104374E0
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x1042F630
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1042F670
// Name: _dynamic_atexit_destructor_for__cc_achievement_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_achievement_debug__()
{
  ConVar::~ConVar(this: &cc_achievement_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1042F680
// Name: _dynamic_atexit_destructor_for__cc_achievement_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_achievement_disable__()
{
  ConVar::~ConVar(this: &cc_achievement_disable);
}

//------------------------------------------------------------------------------
// Address: 0x1042F690
// Name: _dynamic_atexit_destructor_for__g_ActivityStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityStrings__()
{
  CStringRegistry::~CStringRegistry(this: &g_ActivityStrings);
}

//------------------------------------------------------------------------------
// Address: 0x1042F6A0
// Name: _dynamic_atexit_destructor_for__g_ActivityList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ActivityList);
}

//------------------------------------------------------------------------------
// Address: 0x1042F6B0
// Name: _dynamic_atexit_destructor_for__m_ActivityRemapDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_ActivityRemapDatabase__()
{
  CUtlDict<CActivityRemapCache,int>::RemoveAll(this: &m_ActivityRemapDatabase);
  CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>(this: &m_ActivityRemapDatabase.m_Elements.m_Tree);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103F7FA0
// Name: public: void CDmxKeyValues2ErrorStack::ReportError(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDmxKeyValues2ErrorStack::ReportError(CDmxKeyValues2ErrorStack *this, char *pFmt, ...)
{
  int i; // edi
  CUtlSymbolLarge::<unnamed_type_u> v3; // [esp-4h] [ebp-1010h]
  char v4[2048]; // [esp+Ch] [ebp-1000h] BYREF
  char pDest[2048]; // [esp+80Ch] [ebp-800h] BYREF
  va_list params; // [esp+101Ch] [ebp+10h] BYREF

  va_start(params, pFmt);
  V_vsnprintf(pDest, maxLen: 0x800u, pFormat: pFmt, params);
  V_snprintf(pDest: v4, maxLen: 0x800u, pFormat: "%s(%d) : %s\n", this->m_pFilename, this->m_nFileLine, pDest);
  _Warning(a1: v4);
  for ( i = 0; i < this->m_maxErrorIndex; ++i )
  {
    if ( this->m_errorStack[i].u.m_Id != -1 )
    {
      v3.m_Id = (int)this->m_errorStack[i].u;
      if ( i >= this->m_errorIndex )
        _Warning(a1: "(*%s*), ", v3.m_Id);
      else
        _Warning(a1: "%s, ", v3.m_Id);
    }
  }
  _Warning(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x103F8050
// Name: private: void CDmxSerializerKeyValues2::EatWhitespacesAndComments(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializerKeyValues2::EatWhitespacesAndComments(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf)
{
  int v2; // ebx
  int i; // esi
  unsigned __int8 *j; // eax
  signed __int8 v5; // al
  unsigned __int8 *v6; // eax
  unsigned __int8 *k; // eax

  v2 = buf->m_nMaxPut - buf->m_Get;
  for ( i = 0; i < v2; ++g_KeyValues2ErrorStack.m_nFileLine )
  {
    for ( j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          j != nullptr;
          j = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      v5 = *j;
      if ( v5 < 9 || v5 > 13 && v5 != 32 )
        break;
      if ( v5 == 10 )
        ++g_KeyValues2ErrorStack.m_nFileLine;
      if ( ++i >= v2 )
        break;
    }
    v6 = CUtlBuffer::PeekGet(this: buf, nMaxSize: 2, nOffset: i);
    if ( i >= v2 || v6 == nullptr || *v6 != 47 || v6[1] != 47 )
      break;
    i += 2;
    for ( k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i);
          k != nullptr;
          k = CUtlBuffer::PeekGet(this: buf, nMaxSize: 1, nOffset: i) )
    {
      if ( *k == 10 )
        break;
      if ( ++i >= v2 )
        break;
    }
  }
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: i);
}

//------------------------------------------------------------------------------
// Address: 0x103F8120
// Name: private: enum CDmxSerializerKeyValues2::TokenType_t CDmxSerializerKeyValues2::ReadToken(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializerKeyValues2::ReadToken(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, CUtlBuffer *token)
{
  int m_Get; // eax
  int v5; // esi
  CUtlCStringConversion *CStringCharConversion; // eax
  unsigned __int8 *m_pMemory; // ebx
  int i; // eax
  CDmxSerializerKeyValues2::TokenType_t t; // [esp+Ch] [ebp+8h]

  CDmxSerializerKeyValues2::EatWhitespacesAndComments(this, buf);
  if ( buf->m_Error != 0 )
    return 7;
  m_Get = buf->m_Get;
  if ( m_Get == buf->m_nMaxPut )
    return 7;
  v5 = 0;
  switch ( buf->m_Memory.m_pMemory[m_Get - buf->m_nOffset] )
  {
    case '"':
      CStringCharConversion = GetCStringCharConversion();
      v5 = CUtlBuffer::PeekDelimitedStringLength(this: buf, pConv: CStringCharConversion, bActualSize: false) - 1;
      if ( v5 <= 1 || buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset - 1 + v5] != 34 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Unexpected EOF in quoted string");
        goto LABEL_13;
      }
      t = TOKEN_DELIMITED_STRING;
      break;
    case ',':
      v5 = 1;
      t = TOKEN_COMMA;
      break;
    case '[':
      v5 = 1;
      t = TOKEN_OPEN_BRACKET;
      break;
    case ']':
      v5 = 1;
      t = TOKEN_CLOSE_BRACKET;
      break;
    case '{':
      v5 = 1;
      t = TOKEN_OPEN_BRACE;
      break;
    case '}':
      v5 = 1;
      t = TOKEN_CLOSE_BRACE;
      break;
    default:
LABEL_13:
      t = TOKEN_INVALID;
      break;
  }
  CUtlBuffer::SetExternalBuffer(
    this: token,
    pMemory: &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset],
    nSize: v5,
    nInitialPut: v5,
    nFlags: 9u);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_CURRENT, offset: v5);
  m_pMemory = token->m_Memory.m_pMemory;
  for ( i = 0; i < v5; ++i )
  {
    if ( m_pMemory[i] == 10 )
      ++g_KeyValues2ErrorStack.m_nFileLine;
  }
  return t;
}

//------------------------------------------------------------------------------
// Address: 0x103F82C0
// Name: private: void CDmxElementDictionary::HookUpElementAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementAttributes(CDmxElementDictionary *this)
{
  int v2; // esi
  int v3; // edi
  CDmxElement *m_pElement; // edi
  CDmxAttribute *m_pAttribute; // esi
  _DWORD *m_pData; // esi
  int v7; // [esp+4h] [ebp-10h]
  $8E8F103DA13F0EB73708F21B35D8AAF4 *id1; // [esp+8h] [ebp-Ch]
  int m_Size; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  if ( this->m_Attributes.m_Size > 0 )
  {
    v10 = 0;
    m_Size = this->m_Attributes.m_Size;
    do
    {
      v2 = 0;
      v7 = this->m_Dict.m_Size;
      if ( v7 <= 0 )
        goto LABEL_9;
      id1 = &this->m_Attributes.m_Memory.m_pMemory[v10].___u2;
      v3 = 0;
      while ( IsUniqueIdEqual((const UniqueId_t *)id1, id2: &this->m_Dict.m_Memory.m_pMemory[v3].m_Id) == 0 )
      {
        ++v2;
        ++v3;
        if ( v2 >= v7 )
        {
          m_pElement = nullptr;
          goto LABEL_11;
        }
      }
      if ( v2 == -1 )
LABEL_9:
        m_pElement = nullptr;
      else
        m_pElement = this->m_Dict.m_Memory.m_pMemory[v2].m_pElement;
LABEL_11:
      m_pAttribute = this->m_Attributes.m_Memory.m_pMemory[v10].m_pAttribute;
      CDmxAttribute::AllocateDataMemory(this: m_pAttribute, type: AT_FIRST_VALUE_TYPE);
      m_pData = m_pAttribute->m_pData;
      if ( m_pData != nullptr )
        *m_pData = m_pElement;
      ++v10;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8370
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementAttribute(class CUtlBuffer __near &,int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeElementAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        const char *pElementType)
{
  CDmxElement *m_pElement; // esi
  char *v7; // edi
  CDmxAttribute *v9; // edi
  CDmxElement *v10; // esi
  _DWORD *m_pData; // eax
  bool bOk_3; // [esp+1Bh] [ebp+Fh]

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v7 = pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v7);
    return false;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v9 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v7);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    bOk_3 = CDmxSerializerKeyValues2::UnserializeElement(this, buf, pElementType, pHandle: (int *)&pAttributeName);
    if ( bOk_3 )
    {
      if ( pAttributeName == (char *)-1 )
        v10 = nullptr;
      else
        v10 = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)pAttributeName].m_pElement;
      CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FIRST_VALUE_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
        *m_pData = v10;
    }
    return bOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8430
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(class CDmxAttribute __near *,enum DmAttributeType_t,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
        CDmxSerializerKeyValues2 *this,
        CDmxAttribute *pAttribute,
        DmAttributeType_t type,
        CUtlBuffer *tokenBuf)
{
  int m_nMaxPut; // esi
  void *v6; // esp
  CUtlCStringConversion *v7; // eax
  CUtlCStringConversion *v8; // eax
  unsigned __int8 *v9; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  bool v11; // al
  bool v12; // bl
  char v14[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int8 *m_pMemory; // [esp+3Ch] [ebp-4h]
  char v17; // [esp+53h] [ebp+13h]

  m_nMaxPut = tokenBuf->m_nMaxPut;
  m_pMemory = tokenBuf->m_Memory.m_pMemory;
  v6 = alloca(m_nMaxPut + 1);
  if ( type == AT_STRING || type == AT_STRING_ARRAY )
  {
    v17 = 1;
    CStringCharConversion = GetCStringCharConversion();
    SetSerializationDelimiter(pConv: CStringCharConversion);
    v9 = m_pMemory;
  }
  else
  {
    v17 = 0;
    v7 = GetCStringCharConversion();
    m_nMaxPut = CUtlBuffer::PeekDelimitedStringLength(this: tokenBuf, pConv: v7, bActualSize: true);
    v8 = GetCStringCharConversion();
    CUtlBuffer::GetDelimitedString(this: tokenBuf, pConv: v8, pString: v14, nMaxChars: m_nMaxPut + 1);
    v9 = (unsigned __int8 *)v14;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v9, nSize: m_nMaxPut, nFlags: 9u);
  if ( type >= AT_FIRST_ARRAY_TYPE )
    v11 = CDmxAttribute::UnserializeElement(this: pAttribute, type, &buf);
  else
    v11 = CDmxAttribute::Unserialize(this: pAttribute, type, &buf);
  v12 = v11;
  if ( v17 != 0 )
    SetSerializationDelimiter(pConv: nullptr);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x103F8510
// Name: private: bool CDmxSerializerKeyValues2::UnserializeArrayAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        CDmxAttribute *hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  int v8; // ebx
  int v9; // eax
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-30h] BYREF
  CDmxAttribute *pAttribute; // [esp+48h] [ebp+Ch]

  if ( hElement == (CDmxAttribute *)-1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[(_DWORD)hElement].m_pElement;
  if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
      pAttributeName);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    pAttribute = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v8 = 0;
      if ( buf->m_Error != 0 )
      {
LABEL_23:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
      else
      {
        while ( 1 )
        {
          v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          if ( v9 == -1 || v9 == 7 )
            break;
          if ( v9 == 3 )
            goto LABEL_23;
          if ( v8 > 0 )
          {
            if ( v9 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_28;
            }
            v9 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
          }
          if ( v9 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting array attribute value, didn't find it!");
            goto LABEL_28;
          }
          if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                  this,
                  pAttribute,
                  type: nAttrType,
                  &tokenBuf) )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Error reading in array attribute \"%s\" element %d",
              pAttributeName,
              v8);
            CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
            return 0;
          }
          ++v8;
          if ( buf->m_Error != 0 )
            goto LABEL_23;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_28:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F86B0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeId(class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeId(CDmxSerializerKeyValues2 *this, CUtlBuffer *buf, int hElement)
{
  CUtlCStringConversion *CStringCharConversion; // esi
  int v6; // edi
  void *v7; // esp
  CDmxElement *m_pElement; // esi
  char v9[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+4Ch] [ebp-4h]

  v12 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting quoted value for element ID, didn't find one!");
LABEL_3:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v6 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v7 = alloca(v6);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v9, nMaxChars: v6);
  if ( UniqueIdFromString(pDest: &id, pBuf: v9, nMaxLen: 0) == 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Encountered invalid element ID data!");
    goto LABEL_3;
  }
  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  CopyUniqueId(src: &id, pDest: &v12->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_Id);
  CDmxElement::SetId(this: m_pElement, &id);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F87D0
// Name: public: void CDmxElementDictionary::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::Clear(CDmxElementDictionary *this)
{
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx

  this->m_Dict.m_Size = 0;
  if ( this->m_Dict.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Dict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Dict.m_Memory.m_pMemory);
      this->m_Dict.m_Memory.m_pMemory = nullptr;
    }
    this->m_Dict.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  this->m_Attributes.m_Size = 0;
  if ( this->m_Attributes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Attributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Attributes.m_Memory.m_pMemory);
      this->m_Attributes.m_Memory.m_pMemory = nullptr;
    }
    this->m_Attributes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Attributes.m_pElements = this->m_Attributes.m_Memory.m_pMemory;
  this->m_ArrayAttributes.m_Size = 0;
  if ( this->m_ArrayAttributes.m_Memory.m_nGrowSize < 0 )
  {
    this->m_ArrayAttributes.m_pElements = this->m_ArrayAttributes.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ArrayAttributes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ArrayAttributes.m_Memory.m_pMemory);
      this->m_ArrayAttributes.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ArrayAttributes.m_Memory.m_pMemory;
    this->m_ArrayAttributes.m_Memory.m_nAllocationCount = 0;
    this->m_ArrayAttributes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8860
// Name: public: int CDmxElementDictionary::InsertElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxElementDictionary::InsertElement(CDmxElementDictionary *this, CDmxElement *pElement)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Dict.m_Memory.m_nAllocationCount;
  m_Size = this->m_Dict.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Dict.m_Size;
  m_pMemory = this->m_Dict.m_Memory.m_pMemory;
  v6 = this->m_Dict.m_Size - m_Size - 1;
  this->m_Dict.m_pElements = this->m_Dict.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 20 * v6);
  this->m_Dict.m_Memory.m_pMemory[m_Size].m_pElement = pElement;
  InvalidateUniqueId(pDest: &this->m_Dict.m_Memory.m_pMemory[m_Size].m_Id);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x103F88E0
// Name: public: void CDmxElementDictionary::AddAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_Attributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_Attributes.m_Memory.m_nAllocationCount;
  p_m_Attributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Attributes;
  m_Size = this->m_Attributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(this: p_m_Attributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Attributes[1].m_pMemory;
  m_pMemory = p_m_Attributes->m_pMemory;
  v7 = (int)p_m_Attributes[1].m_pMemory - m_Size - 1;
  p_m_Attributes[1].m_nAllocationCount = (int)p_m_Attributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_Attributes->m_pMemory[v8].m_Right) = 1;
  p_m_Attributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_Attributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x103F8970
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        int hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(this: p_m_ArrayAttributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 0;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  p_m_ArrayAttributes->m_pMemory[v8].m_Parent = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x103F89F0
// Name: public: void CDmxElementDictionary::AddArrayAttribute(class CDmxAttribute __near *,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::AddArrayAttribute(
        CDmxElementDictionary *this,
        CDmxAttribute *pAttribute,
        const UniqueId_t *objectId)
{
  int m_nAllocationCount; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *p_m_ArrayAttributes; // esi
  int m_Size; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // ecx
  int v7; // eax
  int v8; // eax

  m_nAllocationCount = this->m_ArrayAttributes.m_Memory.m_nAllocationCount;
  p_m_ArrayAttributes = (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_ArrayAttributes;
  m_Size = this->m_ArrayAttributes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bbox_t,int>::Grow(this: p_m_ArrayAttributes, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ArrayAttributes[1].m_pMemory;
  m_pMemory = p_m_ArrayAttributes->m_pMemory;
  v7 = (int)p_m_ArrayAttributes[1].m_pMemory - m_Size - 1;
  p_m_ArrayAttributes[1].m_nAllocationCount = (int)p_m_ArrayAttributes->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v7);
  v8 = m_Size;
  LOBYTE(p_m_ArrayAttributes->m_pMemory[v8].m_Right) = 1;
  p_m_ArrayAttributes->m_pMemory[v8].m_Left = (int)pAttribute;
  CopyUniqueId(src: objectId, pDest: (UniqueId_t *)&p_m_ArrayAttributes->m_pMemory[m_Size].m_Parent);
}

//------------------------------------------------------------------------------
// Address: 0x103F8A80
// Name: private: void CDmxElementDictionary::HookUpElementArrayAttributes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxElementDictionary::HookUpElementArrayAttributes(CDmxElementDictionary *this)
{
  CDmxElementDictionary *v1; // edi
  int v2; // ebx
  CDmxAttribute *v3; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<vgui::TreeNode *,int> *v5; // esi
  char *v6; // eax
  int v7; // eax
  CDmxElement *m_pElement; // ebx
  int v9; // ecx
  int v10; // edi
  int v11; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v14; // ecx
  int v15; // eax
  CDmxElement **v16; // edi
  int v17; // [esp+4h] [ebp-14h]
  UniqueId_t *id1; // [esp+8h] [ebp-10h]
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]

  v1 = this;
  if ( this->m_ArrayAttributes.m_Size > 0 )
  {
    v2 = 0;
    v20 = 0;
    m_Size = this->m_ArrayAttributes.m_Size;
    while ( 1 )
    {
      v3 = *(CDmxAttribute **)((char *)&v1->m_ArrayAttributes.m_Memory.m_pMemory->m_pAttribute + v2);
      if ( v3->m_Type != AT_FIRST_ARRAY_TYPE )
      {
        CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FIRST_ARRAY_TYPE);
        m_pData = v3->m_pData;
        if ( m_pData != nullptr )
        {
          *m_pData = 0;
          m_pData[1] = 0;
          m_pData[2] = 0;
          m_pData[3] = 0;
          m_pData[4] = 0;
        }
      }
      v5 = (CUtlMemory<vgui::TreeNode *,int> *)v3->m_pData;
      v6 = (char *)v1->m_ArrayAttributes.m_Memory.m_pMemory + v2;
      if ( v6[4] != 0 )
      {
        v9 = v1->m_Dict.m_Size;
        v10 = 0;
        v17 = v9;
        if ( v9 <= 0 )
          goto LABEL_17;
        id1 = (UniqueId_t *)(v6 + 8);
        v11 = 0;
        while ( IsUniqueIdEqual(id1, id2: &this->m_Dict.m_Memory.m_pMemory[v11].m_Id) == 0 )
        {
          ++v10;
          ++v11;
          if ( v10 >= v17 )
          {
            m_pElement = nullptr;
            goto LABEL_19;
          }
        }
        if ( v10 == -1 )
LABEL_17:
          m_pElement = nullptr;
        else
          m_pElement = this->m_Dict.m_Memory.m_pMemory[v10].m_pElement;
      }
      else
      {
        v7 = *((_DWORD *)v6 + 2);
        m_pElement = v7 == -1 ? nullptr : v1->m_Dict.m_Memory.m_pMemory[v7].m_pElement;
      }
LABEL_19:
      m_pMemory = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: v5, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v14 = v5->m_pMemory;
      v15 = (char *)v5[1].m_pMemory - (char *)m_pMemory - 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v14[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
          count: 4 * v15);
      v16 = (CDmxElement **)&v5->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = m_pElement;
      v20 += 24;
      if ( --m_Size == 0 )
        break;
      v2 = v20;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8BB0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(class CUtlBuffer __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        CUtlCharConversion *pAttributeName)
{
  CDmxElement *m_pElement; // esi
  char *v6; // ebx
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // ebx
  _DWORD *m_pData; // eax
  CUtlCStringConversion *CStringCharConversion; // eax
  CUtlBuffer *v12; // esi
  bool v13; // zf
  int v14; // eax
  char elementId[256]; // [esp+Ch] [ebp-240h] BYREF
  char elementType[256]; // [esp+10Ch] [ebp-140h] BYREF
  UniqueId_t id; // [esp+20Ch] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+21Ch] [ebp-30h] BYREF

  if ( hElement == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
  v6 = (char *)pAttributeName;
  if ( CDmxElement::HasAttribute(this: m_pElement, (const char *)pAttributeName) )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Attribute \"%s\" was defined more than once.\n",
      v6);
    return 0;
  }
  else
  {
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, pAttributeName: (CDmxAttribute *)v6);
    v9 = v8;
    if ( v8->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FIRST_ARRAY_TYPE);
      m_pData = v9->m_pData;
      if ( m_pData != nullptr )
      {
        *m_pData = 0;
        m_pData[1] = 0;
        m_pData[2] = 0;
        m_pData[3] = 0;
        m_pData[4] = 0;
      }
    }
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
    CStringCharConversion = GetCStringCharConversion();
    v12 = buf;
    pAttributeName = CStringCharConversion;
    if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 2 )
    {
      v13 = v12->m_Error == 0;
      hElement = 0;
      if ( v13 )
      {
        while ( 1 )
        {
          v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          if ( v14 == -1 || v14 == 7 )
            break;
          if ( v14 == 3 )
            goto LABEL_31;
          if ( hElement > 0 )
          {
            if ( v14 != 4 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting ',', didn't find it!");
              goto LABEL_37;
            }
            v14 = CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf);
          }
          if ( v14 != 5 )
          {
            CDmxKeyValues2ErrorStack::ReportError(
              this: &g_KeyValues2ErrorStack,
              pFmt: "Expecting element type, didn't find it!");
            goto LABEL_37;
          }
          CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementType, nMaxChars: 256);
          if ( _V_strcmp(s1: elementType, s2: off_105DBACC) != 0 )
          {
            if ( !CDmxSerializerKeyValues2::UnserializeElement(
                    this,
                    buf: v12,
                    pElementType: elementType,
                    pHandle: (int *)&buf) )
              goto LABEL_37;
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, hElement: (int)buf);
          }
          else
          {
            if ( CDmxSerializerKeyValues2::ReadToken(this, buf: v12, token: &tokenBuf) != 5 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Expecting element reference, didn't find it!");
              goto LABEL_37;
            }
            CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: pAttributeName, pString: elementId, nMaxChars: 256);
            if ( UniqueIdFromString(pDest: &id, pBuf: elementId, nMaxLen: 0) == 0 )
            {
              CDmxKeyValues2ErrorStack::ReportError(
                this: &g_KeyValues2ErrorStack,
                pFmt: "Encountered invalid element ID data!");
              goto LABEL_37;
            }
            CDmxElementDictionary::AddArrayAttribute(this: &this->m_ElementDict, pAttribute: v9, objectId: &id);
          }
          ++hElement;
          if ( v12->m_Error != 0 )
            goto LABEL_31;
        }
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting ']', didn't find it!");
LABEL_37:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 0;
      }
      else
      {
LABEL_31:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        return 1;
      }
    }
    else
    {
      CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '[', didn't find it!");
      if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F8E20
// Name: private: bool CDmxSerializerKeyValues2::UnserializeAttribute(class CUtlBuffer __near &,int,char const __near *,enum DmAttributeType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeAttribute(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int hElement,
        char *pAttributeName,
        DmAttributeType_t nAttrType)
{
  CDmxElement *m_pElement; // esi
  CDmxAttribute *v8; // ebx
  CUtlCStringConversion *CStringCharConversion; // edi
  int v10; // ebx
  void *v11; // esp
  char v12[12]; // [esp+0h] [ebp-50h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-44h] BYREF
  UniqueId_t id; // [esp+3Ch] [ebp-14h] BYREF
  CDmxSerializerKeyValues2 *v15; // [esp+4Ch] [ebp-4h]
  CDmxAttribute *pAttribute; // [esp+58h] [ebp+8h]

  v15 = this;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) == 5 )
  {
    if ( hElement == -1 )
      m_pElement = nullptr;
    else
      m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[hElement].m_pElement;
    if ( CDmxElement::HasAttribute(this: m_pElement, pAttributeName) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Encountered duplicate attribute definition for attribute \"%s\"!",
        pAttributeName);
      goto LABEL_3;
    }
    CDmxElement::LockForChanges(this: m_pElement, bLock: true);
    v8 = CDmxElement::AddAttribute(this: m_pElement, (CDmxAttribute *)pAttributeName);
    pAttribute = v8;
    if ( m_pElement != nullptr )
      CDmxElement::LockForChanges(this: m_pElement, bLock: false);
    if ( nAttrType == AT_FIRST_VALUE_TYPE )
    {
      CStringCharConversion = GetCStringCharConversion();
      v10 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
      v11 = alloca(v10);
      CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v12, nMaxChars: v10);
      if ( v12[0] != 0 )
      {
        if ( UniqueIdFromString(pDest: &id, pBuf: v12, nMaxLen: 0) == 0 )
        {
          CDmxKeyValues2ErrorStack::ReportError(
            this: &g_KeyValues2ErrorStack,
            pFmt: "Invalid format for element ID encountered for attribute \"%s\"",
            pAttributeName);
          goto LABEL_20;
        }
        CDmxElementDictionary::AddAttribute(this: &v15->m_ElementDict, pAttribute, objectId: &id);
      }
    }
    else if ( !CDmxSerializerKeyValues2::UnserializeAttributeValueFromToken(
                 this: v15,
                 pAttribute: v8,
                 type: nAttrType,
                 &tokenBuf) )
    {
      CDmxKeyValues2ErrorStack::ReportError(
        this: &g_KeyValues2ErrorStack,
        pFmt: "Error reading attribute \"%s\"",
        pAttributeName);
LABEL_20:
      CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
      return 0;
    }
    CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
    return 1;
  }
  CDmxKeyValues2ErrorStack::ReportError(
    this: &g_KeyValues2ErrorStack,
    pFmt: "Expecting quoted attribute value for attribute \"%s\", didn't find one!",
    pAttributeName);
LABEL_3:
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103F8FC0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        char *pElementType,
        int *pHandle)
{
  unsigned __int8 *v5; // eax
  CDmxElement *v7; // eax
  int m_errorIndex; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  unsigned __int8 *m_pMemory; // eax
  IMemAlloc *v11; // ecx
  int v13; // eax
  DmAttributeType_t v14; // esi
  char v15; // al
  bool v16; // sf
  char attributeType[256]; // [esp+Ch] [ebp-234h] BYREF
  char attributeName[256]; // [esp+10Ch] [ebp-134h] BYREF
  CUtlBuffer tokenBuf; // [esp+20Ch] [ebp-34h] BYREF
  CUtlCharConversion *pConv; // [esp+23Ch] [ebp-4h] BYREF
  CDmxAttribute *hElement; // [esp+24Ch] [ebp+Ch]

  *pHandle = -1;
  v5 = DMXAlloc(size: 0x34u);
  if ( v5 != nullptr )
    v7 = CDmxElement::CDmxElement(this: (CDmxElement *)v5, pType: pElementType);
  else
    v7 = nullptr;
  hElement = (CDmxAttribute *)CDmxElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v7);
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::AddString(
    this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable,
    result: (CUtlSymbolLarge *)&pConv,
    pString: pElementType);
  m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  if ( g_KeyValues2ErrorStack.m_errorIndex < 64 )
  {
    g_KeyValues2ErrorStack.m_errorStack[g_KeyValues2ErrorStack.m_errorIndex].u.m_Id = (int)pConv;
    m_errorIndex = g_KeyValues2ErrorStack.m_errorIndex;
  }
  g_KeyValues2ErrorStack.m_errorIndex = m_errorIndex + 1;
  if ( g_KeyValues2ErrorStack.m_maxErrorIndex <= m_errorIndex )
    g_KeyValues2ErrorStack.m_maxErrorIndex = m_errorIndex;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  CStringCharConversion = GetCStringCharConversion();
  pConv = CStringCharConversion;
  if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 0 )
  {
    CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '{', didn't find it!");
LABEL_10:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = tokenBuf.m_Memory.m_pMemory;
      if ( tokenBuf.m_Memory.m_pMemory != nullptr )
      {
        v11 = _g_pMemAlloc;
LABEL_13:
        v11->Free_2(this: v11, a2: m_pMemory);
      }
    }
LABEL_14:
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 0;
  }
  else
  {
    while ( buf->m_Error == 0 )
    {
      v13 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
      if ( v13 == -1 || v13 == 7 )
      {
        CDmxKeyValues2ErrorStack::ReportError(this: &g_KeyValues2ErrorStack, pFmt: "Expecting '}', didn't find it!");
        goto LABEL_10;
      }
      if ( v13 == 1 )
        break;
      if ( v13 != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute name, didn't find it!");
        goto LABEL_10;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeName,
        nMaxChars: 256);
      if ( CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf) != 5 )
      {
        CDmxKeyValues2ErrorStack::ReportError(
          this: &g_KeyValues2ErrorStack,
          pFmt: "Expecting attribute type for attribute %s, didn't find it!",
          attributeName);
LABEL_44:
        CUtlBuffer::~CUtlBuffer(this: &tokenBuf);
        --g_KeyValues2ErrorStack.m_errorIndex;
        return 0;
      }
      CUtlBuffer::GetDelimitedString(
        this: &tokenBuf,
        pConv: CStringCharConversion,
        pString: attributeType,
        nMaxChars: 256);
      if ( _V_stricmp(s1: "elementid", s2: attributeType) != 0 )
      {
        v14 = AT_UNKNOWN;
        while ( _V_stricmp(s1: CDmxAttribute::s_pAttributeTypeName[v14], s2: attributeType) != 0 )
        {
          if ( ++v14 >= AT_TYPE_COUNT )
            goto LABEL_28;
        }
        if ( v14 == AT_UNKNOWN )
        {
LABEL_28:
          v15 = CDmxSerializerKeyValues2::UnserializeElementAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  pElementType: attributeType);
          goto LABEL_29;
        }
        if ( v14 == AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeElementArrayAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: (CUtlCharConversion *)attributeName);
        }
        else if ( v14 < AT_FIRST_ARRAY_TYPE )
        {
          v15 = CDmxSerializerKeyValues2::UnserializeAttribute(
                  this,
                  buf,
                  (int)hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
        else
        {
          v15 = CDmxSerializerKeyValues2::UnserializeArrayAttribute(
                  this,
                  buf,
                  hElement,
                  pAttributeName: attributeName,
                  nAttrType: v14);
        }
LABEL_29:
        if ( v15 == 0 )
        {
          if ( tokenBuf.m_Memory.m_nGrowSize >= 0 )
          {
            m_pMemory = tokenBuf.m_Memory.m_pMemory;
            if ( tokenBuf.m_Memory.m_pMemory != nullptr )
            {
              v11 = _g_pMemAlloc;
              goto LABEL_13;
            }
          }
          goto LABEL_14;
        }
        CStringCharConversion = (CUtlCStringConversion *)pConv;
      }
      else if ( _V_stricmp(s1: "id", s2: attributeName) != 0
             || CDmxSerializerKeyValues2::UnserializeId(this, buf, (int)hElement) == 0 )
      {
        goto LABEL_44;
      }
    }
    v16 = tokenBuf.m_Memory.m_nGrowSize < 0;
    *pHandle = (int)hElement;
    if ( !v16 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    --g_KeyValues2ErrorStack.m_errorIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F92B0
// Name: private: bool CDmxSerializerKeyValues2::UnserializeElement(class CUtlBuffer __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::UnserializeElement(
        CDmxSerializerKeyValues2 *this,
        CUtlBuffer *buf,
        int *pHandle)
{
  int v4; // eax
  CUtlCStringConversion *CStringCharConversion; // esi
  int v7; // edi
  void *v8; // esp
  char v9; // bl
  char v10[12]; // [esp+0h] [ebp-40h] BYREF
  CUtlBuffer tokenBuf; // [esp+Ch] [ebp-34h] BYREF
  CDmxSerializerKeyValues2 *v12; // [esp+3Ch] [ebp-4h]

  v12 = this;
  *pHandle = -1;
  CUtlBuffer::CUtlBuffer(this: &tokenBuf, growSize: 0, initSize: 0, nFlags: 0);
  v4 = CDmxSerializerKeyValues2::ReadToken(this, buf, token: &tokenBuf);
  if ( v4 == -1 )
    goto LABEL_9;
  if ( v4 == 7 )
  {
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 1;
  }
  if ( v4 != 5 )
  {
    CDmxKeyValues2ErrorStack::ReportError(
      this: &g_KeyValues2ErrorStack,
      pFmt: "Expecting element type name, didn't find it!");
LABEL_9:
    if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
    return 0;
  }
  CStringCharConversion = GetCStringCharConversion();
  v7 = CUtlBuffer::PeekDelimitedStringLength(this: &tokenBuf, pConv: CStringCharConversion, bActualSize: true);
  v8 = alloca(v7);
  CUtlBuffer::GetDelimitedString(this: &tokenBuf, pConv: CStringCharConversion, pString: v10, nMaxChars: v7);
  v9 = CDmxSerializerKeyValues2::UnserializeElement(this: v12, buf, pElementType: v10, pHandle);
  if ( tokenBuf.m_Memory.m_nGrowSize >= 0 && tokenBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenBuf.m_Memory.m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x103F93D0
// Name: public: bool CDmxSerializerKeyValues2::Unserialize(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmxSerializerKeyValues2::Unserialize(
        CDmxSerializerKeyValues2 *this,
        const char *pFileName,
        CUtlBuffer *buf,
        CDmxElement **ppRoot)
{
  const char *v5; // ecx
  char v6; // bl
  CUtlBuffer *v7; // edi
  int m_hRoot; // eax
  CDmxElement *m_pElement; // eax
  CDmxElement **v10; // edi

  v5 = pFileName;
  *ppRoot = nullptr;
  g_KeyValues2ErrorStack.m_pFilename = v5;
  v6 = 1;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  this->m_hRoot = -1;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  v7 = buf;
  while ( v7->m_Error == 0 )
  {
    v6 = CDmxSerializerKeyValues2::UnserializeElement(this, buf: v7, pHandle: (int *)&pFileName);
    if ( v6 == 0 || pFileName == (const char *)-1 )
      break;
    if ( this->m_hRoot == -1 )
      this->m_hRoot = (int)pFileName;
  }
  CDmxElementDictionary::HookUpElementArrayAttributes(this: &this->m_ElementDict);
  CDmxElementDictionary::HookUpElementAttributes(this: &this->m_ElementDict);
  m_hRoot = this->m_hRoot;
  if ( m_hRoot == -1 )
    m_pElement = nullptr;
  else
    m_pElement = this->m_ElementDict.m_Dict.m_Memory.m_pMemory[m_hRoot].m_pElement;
  v10 = ppRoot;
  *ppRoot = m_pElement;
  CDmxElementDictionary::Clear(this: &this->m_ElementDict);
  if ( v6 == 0 )
  {
    CleanupDMX(pRoot: *v10);
    *v10 = nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x103F9490
// Name: bool UnserializeTextDMX(char const __near *,class CUtlBuffer __near &,class CDmxElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UnserializeTextDMX(const char *pFileName, CUtlBuffer *buf, CDmxElement **ppRoot)
{
  char v3; // bl
  CDmxSerializerKeyValues2 dmxUnserializer; // [esp+4h] [ebp-40h] BYREF

  memset(&dmxUnserializer, 0, 60);
  v3 = CDmxSerializerKeyValues2::Unserialize(this: &dmxUnserializer, pFileName, buf, ppRoot);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_ArrayAttributes);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer.m_ElementDict.m_Attributes);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&dmxUnserializer);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x104186D0
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10423020
// Name: _dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CUtlSymbolTableLargeBase<CNonThreadsafeTree<0>,0>::RemoveAll(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools);
  CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>::~CUtlRBTree<CUtlSymbolTableLargeBaseTreeEntry_t *,int,CTreeEntryLess<CNonThreadsafeTree<0>,0>,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int>,int>>(this: &CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x10418740
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10418780
// Name: _dynamic_atexit_destructor_for__cc_achievement_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_achievement_debug__()
{
  ConVar::~ConVar(this: &cc_achievement_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10418790
// Name: _dynamic_atexit_destructor_for__cc_achievement_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_achievement_disable__()
{
  ConVar::~ConVar(this: &cc_achievement_disable);
}

//------------------------------------------------------------------------------
// Address: 0x104187A0
// Name: _dynamic_atexit_destructor_for__g_ActivityStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityStrings__()
{
  CStringRegistry::~CStringRegistry(this: &g_ActivityStrings);
}

//------------------------------------------------------------------------------
// Address: 0x104187B0
// Name: _dynamic_atexit_destructor_for__g_ActivityList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityList__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ActivityList);
}

//------------------------------------------------------------------------------
// Address: 0x104187C0
// Name: _dynamic_atexit_destructor_for__m_ActivityRemapDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_ActivityRemapDatabase__()
{
  CUtlDict<CActivityRemapCache,int>::RemoveAll(this: &m_ActivityRemapDatabase);
  CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int,CUtlMap<char const *,CActivityRemapCache,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CActivityRemapCache,int>::Node_t,int>,int>>(this: &m_ActivityRemapDatabase.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x104187E0
// Name: _DataMapInit_CAI_AddOn__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_AddOn__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x104187F0
// Name: _dynamic_atexit_destructor_for__CAI_Agent::gm_SchedulingSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CAI_Agent::gm_SchedulingSymbols__()
{
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_Agent::gm_SchedulingSymbols.m_ConditionNamespace);
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_Agent::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::~CAI_GlobalNamespace(this: &CAI_Agent::gm_SchedulingSymbols.m_ScheduleNamespace);
}

//------------------------------------------------------------------------------
// Address: 0x10418810
// Name: _DataMapInit_CAI_Agent__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_Agent__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x10418820
// Name: _DataMapInit_AIAgentScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AIAgentScheduleState_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_1);
}

//------------------------------------------------------------------------------
// Address: 0x10418830
// Name: _DataMapInit_AIAgentSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_AIAgentSaveHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_2);
}

} // namespace server
