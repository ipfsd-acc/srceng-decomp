// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/dmserializerxml.cpp
// Functions: 30
// ============================================================

#include "datamodel\dmserializerxml.h"

//------------------------------------------------------------------------------
// Address: 0x0043B910
// Name: void InstallXMLSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallXMLSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_XMLSerializer);
  pFactory->AddSerializer(this: pFactory, a2: &s_XMLSerializerFlat);
}

//------------------------------------------------------------------------------
// Address: 0x0043B940
// Name: private: void CXMLSerializer::SerializeElementReference(class CUtlBuffer __near &,class CDmElementSerializationDictionary __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLSerializer::SerializeElementReference(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        CDmElementSerializationDictionary *dict,
        CDmElement *pElement)
{
  const char *v5; // edi

  if ( CDmElementSerializationDictionary::ShouldInlineElement(this: dict, pElement) )
  {
    CXMLSerializer::SaveElement(this, buf, dict, pElement, bWriteDelimiters: true);
  }
  else
  {
    v5 = AttributeTypeName(type: AT_FIRST_VALUE_TYPE);
    CUtlBuffer::Printf(this: buf, pFmt: "<%s>", v5);
    if ( pElement != nullptr )
      Serialize(buf, src: &pElement->m_Id);
    CUtlBuffer::Printf(this: buf, pFmt: "</%s>\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B9B0
// Name: private: void CXMLSerializer::SerializeArrayAttribute(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLSerializer::SerializeArrayAttribute(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        CDmAttribute *pAttribute)
{
  int v3; // ebx
  int i; // edi
  CDmAttribute *v5; // ecx

  CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&pAttribute, pAttribute);
  v3 = CDmrGenericArrayConst::Count(this: (CDmrGenericArrayConst *)&pAttribute);
  for ( i = 0; i < v3; ++i )
  {
    CUtlBuffer::PutString(this: buf, pString: "<value>");
    v5 = pAttribute;
    ++buf->m_nTab;
    CDmAttribute::SerializeElement(this: v5, nElement: i, buf);
    if ( --buf->m_nTab < 0 )
      buf->m_nTab = 0;
    CUtlBuffer::PutString(this: buf, pString: "</value>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BA30
// Name: int cstream(unsigned char __near *,int,int __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl cstream(unsigned __int8 *buf, int cBytes, int *cBytesActual, CUtlBuffer *inputData)
{
  int v4; // eax
  int UpTo; // eax

  v4 = inputData->m_nMaxPut - inputData->m_Get;
  if ( cBytes < v4 )
    v4 = cBytes;
  *cBytesActual = v4;
  UpTo = CUtlBuffer::GetUpTo(this: inputData, pMem: buf, nSize: v4);
  *cBytesActual = UpTo;
  return UpTo < cBytes;
}

//------------------------------------------------------------------------------
// Address: 0x0043BA70
// Name: private: int CXMLUnserializationState::CreateDmElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::CreateDmElement(CXMLUnserializationState *this, const char *pElementType)
{
  int NamedItem; // edi
  int v4; // ebp
  const char *v5; // edi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  int CurrentLine; // eax
  int inserted; // edi
  UniqueId_t readId; // [esp+10h] [ebp-18h] BYREF

  NamedItem = XMLParser_GetNamedItem();
  v4 = XMLParser_GetNamedItem();
  if ( NamedItem != 0 )
    v5 = *(const char **)(NamedItem + 4);
  else
    v5 = nullptr;
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pElementType, a3: v5, a4: this->m_fileid, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr )
  {
    CDmElement::MarkBeingUnserialized(this: v7, beingUnserialized: true);
    inserted = CDmElementDictionary::InsertElement(this: &this->m_ElementDict, pElement: v8);
    if ( v4 != 0 )
    {
      UniqueIdFromString(pDest: (UniqueId_t *)&readId.m_Value[4], pBuf: *(const char **)(v4 + 4), nMaxLen: 0);
      CDmElementDictionary::SetElementId(
        this: &this->m_ElementDict,
        a2: inserted,
        hDictHandle: inserted,
        newId: (const UniqueId_t *)&readId.m_Value[4],
        idConflictResolution: this->m_idConflictResolution);
    }
    return inserted;
  }
  else
  {
    CurrentLine = XMLParser_GetCurrentLine();
    _Warning(a1: "XML: (%d) Element uses unknown element type %s\n", CurrentLine, pElementType);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BB70
// Name: public: virtual char const __near * CXMLSerializer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CXMLSerializer::GetName(CXMLSerializer *this)
{
  const char *result; // eax

  result = "xml_flat";
  if ( !this->m_bFlatMode )
    return "xml";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BB90
// Name: public: virtual char const __near * CXMLSerializer::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CXMLSerializer::GetDescription(CXMLSerializer *this)
{
  const char *result; // eax

  result = "XML (flat)";
  if ( !this->m_bFlatMode )
    return "XML";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BC50
// Name: private: void CXMLUnserializationState::RecomputeTopmostElement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLUnserializationState::RecomputeTopmostElement(CXMLUnserializationState *this)
{
  int v1; // eax
  CXMLUnserializationState::ParseState_t *m_pMemory; // ebp
  CXMLUnserializationState::ParseState_t *v3; // edx

  v1 = this->m_ParseStack.m_Size - 1;
  if ( v1 < 0 )
  {
LABEL_7:
    this->m_hTopmostDictHandle = -1;
  }
  else
  {
    m_pMemory = this->m_ParseStack.m_Memory.m_pMemory;
    v3 = &m_pMemory[v1];
    while ( v3->m_Type != ELEMENT )
    {
      if ( v3->m_Type == ATTRIBUTE && (v3->m_pAttribute->m_nFlags & 0x1F) == 1 )
      {
        this->m_hTopmostDictHandle = m_pMemory[v1].m_hElement;
        return;
      }
      --v1;
      --v3;
      if ( v1 < 0 )
        goto LABEL_7;
    }
    this->m_hTopmostDictHandle = m_pMemory[v1].m_hElement;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BCC0
// Name: private: int CXMLUnserializationState::CharactersElementArrayReference(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::CharactersElementArrayReference(
        CXMLUnserializationState *this,
        const unsigned __int8 *pChars,
        unsigned int cbChars)
{
  CXMLUnserializationState::ParseState_t *v4; // edi
  UniqueId_t id; // [esp+4h] [ebp-18h] BYREF

  v4 = &this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 2];
  UniqueIdFromString(pDest: (UniqueId_t *)&id.m_Value[4], pBuf: (const char *)pChars, nMaxLen: cbChars);
  CDmElementDictionary::AddArrayAttribute(
    this: &this->m_ElementDict,
    pAttribute: v4->m_pAttribute,
    objectId: (const UniqueId_t *)&id.m_Value[4]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043BD20
// Name: private: void CXMLSerializer::SerializeElementAttribute(class CUtlBuffer __near &,class CDmElementSerializationDictionary __near &,char const __near *,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLSerializer::SerializeElementAttribute(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        CDmElementSerializationDictionary *dict,
        const char *pName,
        CDmAttribute *pAttribute)
{
  CDmaVar<enum DmElementHandle_t> *v5; // eax
  CDmElement *v6; // esi
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // [esp-8h] [ebp-120h]
  char idBuf[256]; // [esp+10h] [ebp-108h] BYREF

  *(_DWORD *)idBuf = this;
  if ( (pAttribute->m_nFlags & 0x1F) != 1
    || (v5 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: pAttribute),
        (v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v5->m_Storage.m_Handle)) == nullptr)
    || !v6->IsA(this: v6, a2: CDmElement::m_classType.m_Id) )
  {
    v6 = nullptr;
  }
  if ( CDmElementSerializationDictionary::ShouldInlineElement(this: dict, pElement: v6) )
  {
    UniqueIdToString(id: &v6->m_Id, pBuf: &idBuf[4], nMaxLen: 256);
    v9 = CUtlString::operator char const *(this: &v6->m_Name.m_Storage);
    v7 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: v6->m_Type);
    CUtlBuffer::Printf(this: buf, pFmt: "<%s type=\"%s\" name=\"%s\" id=\"%s\">\n", pName, v7, v9, &idBuf[4]);
    CXMLSerializer::SaveElement(this: *(CXMLSerializer **)idBuf, buf, dict, pElement: v6, bWriteDelimiters: false);
  }
  else
  {
    v8 = AttributeTypeName(type: AT_FIRST_VALUE_TYPE);
    CUtlBuffer::Printf(this: buf, pFmt: "<%s type=\"%s\">", pName, v8);
    if ( v6 != nullptr )
      Serialize(buf, src: &v6->m_Id);
  }
  CUtlBuffer::Printf(this: buf, pFmt: "</%s>\n", pName);
}

//------------------------------------------------------------------------------
// Address: 0x0043BE50
// Name: private: int CXMLUnserializationState::EndFileScopeElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::EndFileScopeElement(CXMLUnserializationState *this, const char *pElementName)
{
  if ( _stricmp(dst: pElementName, src: "DMXFile") != 0 )
    return 1;
  --this->m_ParseStack.m_Size;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043BE80
// Name: private: int CXMLUnserializationState::EndChildElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CXMLUnserializationState::EndChildElement@<eax>(
        CXMLUnserializationState *this@<ecx>,
        const char *a2@<edi>,
        const char *pElementType)
{
  CDmElement *Element; // eax
  const char *v6; // eax
  int CurrentLine; // eax

  if ( this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_Type == ATTRIBUTE_ELEMENT_ARRAY_REFERENCE )
  {
    --this->m_ParseStack.m_Size;
    return 0;
  }
  else
  {
    if ( this->m_hTopmostDictHandle == -1 )
      Element = nullptr;
    else
      Element = CDmElementDictionary::GetElement(this: &this->m_ElementDict, handle: this->m_hTopmostDictHandle);
    v6 = g_pDataModel->GetString(this: g_pDataModel, a2: Element->m_Type);
    if ( _stricmp(dst: pElementType, src: v6) == 0 )
    {
      --this->m_ParseStack.m_Size;
      CXMLUnserializationState::RecomputeTopmostElement(this);
      return 0;
    }
    else
    {
      CurrentLine = XMLParser_GetCurrentLine();
      _Warning(
        a1: "XML: (%d) Child element (%s) has mismatched ending element type %s\n",
        CurrentLine,
        pElementType,
        a2);
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BF20
// Name: private: int CXMLUnserializationState::CharactersElementReference(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::CharactersElementReference(
        CXMLUnserializationState *this,
        const unsigned __int8 *pChars,
        unsigned int cbChars)
{
  UniqueId_t id; // [esp+0h] [ebp-18h] BYREF

  UniqueIdFromString(pDest: (UniqueId_t *)&id.m_Value[4], pBuf: (const char *)pChars, nMaxLen: cbChars);
  CDmElementDictionary::AddAttribute(
    this: &this->m_ElementDict,
    pAttribute: this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_pAttribute,
    objectId: (const UniqueId_t *)&id.m_Value[4]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043BF80
// Name: public: int CXMLUnserializationState::EndElement(unsigned char const __near *,unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CXMLUnserializationState::EndElement@<eax>(
        CXMLUnserializationState *this@<ecx>,
        const char *a2@<edi>,
        const unsigned __int8 *uri,
        const unsigned __int8 *localName,
        const unsigned __int8 *qName)
{
  int result; // eax

  switch ( this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_Type )
  {
    case FILE_SCOPE:
      result = CXMLUnserializationState::EndFileScopeElement(this, pElementName: (const char *)qName);
      break;
    case ELEMENT:
    case ATTRIBUTE_ELEMENT_ARRAY_REFERENCE:
      result = CXMLUnserializationState::EndChildElement(this, a2, pElementType: (const char *)qName);
      break;
    case ATTRIBUTE:
    case ATTRIBUTE_ELEMENT_REFERENCE:
    case ATTRIBUTE_ARRAY_VALUE:
      --this->m_ParseStack.m_Size;
      CXMLUnserializationState::RecomputeTopmostElement(this);
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BFF0
// Name: private: void CXMLSerializer::SerializeElementArrayAttribute(class CUtlBuffer __near &,class CDmElementSerializationDictionary __near &,char const __near *,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLSerializer::SerializeElementArrayAttribute(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        CDmElementSerializationDictionary *dict,
        const char *pName,
        CDmAttribute *pAttribute)
{
  int v5; // esi
  const char *v6; // eax
  int m_nFlags; // ebp
  CDmElement *v8; // ebx
  CDmrElementArray<CDmElement> array; // [esp+8h] [ebp-Ch] BYREF
  CDmAttribute *v11; // [esp+10h] [ebp-4h]

  array.m_pStorage = (DmElementArray_t *)this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
  v5 = 0;
  if ( pAttribute != nullptr && (pAttribute->m_nFlags & 0x1F) == 0xF )
  {
    v11 = pAttribute;
    array.m_pAttribute = (CDmAttribute *)pAttribute->m_pData;
  }
  else
  {
    v11 = nullptr;
    array.m_pAttribute = nullptr;
  }
  v6 = AttributeTypeName(type: AT_FIRST_ARRAY_TYPE);
  CUtlBuffer::Printf(this: buf, pFmt: "<%s type=\"%s\">\n", pName, v6);
  ++buf->m_nTab;
  m_nFlags = array.m_pAttribute->m_nFlags;
  if ( m_nFlags > 0 )
  {
    do
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&array.m_pAttribute->m_pNext->m_pNext + v5));
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType.m_Id) )
        v8 = nullptr;
      CXMLSerializer::SerializeElementReference(this: (CXMLSerializer *)array.m_pStorage, buf, dict, pElement: v8);
      ++v5;
    }
    while ( v5 < m_nFlags );
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "</%s>\n", pName);
}

//------------------------------------------------------------------------------
// Address: 0x0043C0E0
// Name: private: bool CXMLSerializer::SerializeAttributes(class CUtlBuffer __near &,class CDmElementSerializationDictionary __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXMLSerializer::SerializeAttributes(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        CDmElementSerializationDictionary *dict,
        CDmElement *pElement)
{
  void *v4; // esp
  CDmAttribute **v5; // edi
  int v6; // esi
  KeyValues *j; // eax
  int v8; // eax
  CDmAttribute *v9; // ebx
  const char *v10; // eax
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-20h] BYREF
  CDmAttribute **ppAttributes; // [esp+Ch] [ebp-14h]
  const char *pName; // [esp+10h] [ebp-10h]
  CXMLSerializer *v19; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]

  v19 = this;
  v4 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v5 = (CDmAttribute **)v16;
  ppAttributes = (CDmAttribute **)v16;
  v6 = 0;
  for ( j = KeyValues::GetFirstSubKey(this: (KeyValues *)pElement); j != nullptr; j = (KeyValues *)j->m_iKeyName )
  {
    if ( (j->m_iValue & 0x2040) == 0 )
      v16[v6++] = j;
  }
  v8 = v6 - 1;
  i = v6 - 1;
  if ( v6 - 1 >= 0 )
  {
    while ( 1 )
    {
      v9 = v5[v8];
      v10 = g_pDataModel->GetString(this: g_pDataModel, a2: v9->m_Name.m_Id);
      v11 = v9->m_nFlags & 0x1F;
      pName = v10;
      if ( v11 == AT_FIRST_VALUE_TYPE )
      {
        CXMLSerializer::SerializeElementAttribute(this: v19, buf, dict, pName: v10, pAttribute: v9);
      }
      else if ( v11 == AT_FIRST_ARRAY_TYPE )
      {
        CXMLSerializer::SerializeElementArrayAttribute(this: v19, buf, dict, pName: v10, pAttribute: v9);
      }
      else
      {
        v12 = AttributeTypeName(type: v11);
        CUtlBuffer::Printf(this: buf, pFmt: "<%s type=\"%s\">", pName, v12);
        ++buf->m_nTab;
        if ( v11 < AT_FIRST_ARRAY_TYPE )
        {
          CDmAttribute::Serialize(this: v9, buf);
        }
        else
        {
          if ( (buf->m_Flags & 1) != 0 )
          {
            m_Put = buf->m_Put;
            if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
              CUtlBuffer::PutTabs(this: buf);
          }
          if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
          {
            buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
            ++buf->m_Put;
            CUtlBuffer::AddNullTermination(this: buf);
          }
          CXMLSerializer::SerializeArrayAttribute(this: v19, buf, pAttribute: v9);
        }
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "</%s>\n", pName);
      }
      if ( --i < 0 )
        break;
      v5 = ppAttributes;
      v8 = i;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043C270
// Name: private: bool CXMLSerializer::SaveElement(class CUtlBuffer __near &,class CDmElementSerializationDictionary __near &,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXMLSerializer::SaveElement(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        CDmElementSerializationDictionary *dict,
        CDmElement *pElement,
        bool bWriteDelimiters)
{
  const char *v6; // eax
  const char *v8; // eax
  const char *v10; // [esp-8h] [ebp-11Ch]
  char idbuf[260]; // [esp+Ch] [ebp-108h] BYREF

  if ( bWriteDelimiters )
  {
    UniqueIdToString(id: &pElement->m_Id, pBuf: &idbuf[4], nMaxLen: 256);
    v10 = CUtlString::operator char const *(this: &pElement->m_Name.m_Storage);
    v6 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: pElement->m_Type);
    CUtlBuffer::Printf(this: buf, pFmt: "<%s name=\"%s\" id=\"%s\">\n", v6, v10, &idbuf[4]);
  }
  ++buf->m_nTab;
  CXMLSerializer::SerializeAttributes(this, buf, dict, pElement);
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  if ( bWriteDelimiters )
  {
    v8 = (const char *)((int (__stdcall *)(_DWORD))g_pDataModel->GetString)(a1: pElement->m_Type);
    CUtlBuffer::Printf(this: buf, pFmt: "</%s>\n", v8);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043C360
// Name: int EndElement(void __near *,unsigned char const __near *,unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall EndElement@<eax>(
        const char *a1@<edi>,
        CXMLUnserializationState *pUserData,
        const unsigned __int8 *uri,
        const unsigned __int8 *localName,
        const unsigned __int8 *qName)
{
  return CXMLUnserializationState::EndElement(this: pUserData, a2: a1, uri, localName, qName);
}

//------------------------------------------------------------------------------
// Address: 0x0043C380
// Name: private: void CXMLUnserializationState::PushAttribute(char const __near *,class CDmAttribute __near *,int,enum CXMLUnserializationState::ParseState_t::ParseType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLUnserializationState::PushAttribute(
        CXMLUnserializationState *this,
        const char *pAttributeName,
        CDmAttribute *pAttribute,
        int hElement,
        CXMLUnserializationState::ParseState_t::ParseType_t type)
{
  CUtlStack<CXMLUnserializationState::ParseState_t,CUtlMemory<CXMLUnserializationState::ParseState_t,int> > *p_m_ParseStack; // esi
  int v7; // eax
  CXMLUnserializationState::ParseState_t *m_pMemory; // ecx
  int v9; // eax

  p_m_ParseStack = &this->m_ParseStack;
  if ( this->m_ParseStack.m_Size >= this->m_ParseStack.m_Memory.m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&this->m_ParseStack,
      num: 1);
  v7 = ++p_m_ParseStack->m_Size;
  m_pMemory = p_m_ParseStack->m_Memory.m_pMemory;
  p_m_ParseStack->m_pElements = p_m_ParseStack->m_Memory.m_pMemory;
  v9 = 4 * (3 * v7 - 3);
  *(CXMLUnserializationState::ParseState_t::ParseType_t *)((char *)&m_pMemory->m_Type + v9) = type;
  *(CDmAttribute **)((char *)&p_m_ParseStack->m_Memory.m_pMemory->m_pAttribute + v9) = pAttribute;
  *(int *)((char *)&p_m_ParseStack->m_Memory.m_pMemory->m_hElement + v9) = hElement;
  if ( hElement != -1 )
    this->m_hTopmostDictHandle = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x0043C3E0
// Name: private: void CXMLUnserializationState::PushElement(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXMLUnserializationState::PushElement(CXMLUnserializationState *this, int hElement)
{
  CUtlStack<CXMLUnserializationState::ParseState_t,CUtlMemory<CXMLUnserializationState::ParseState_t,int> > *p_m_ParseStack; // esi
  int v4; // eax
  CXMLUnserializationState::ParseState_t *m_pMemory; // ecx
  int v6; // eax

  p_m_ParseStack = &this->m_ParseStack;
  if ( this->m_ParseStack.m_Size >= this->m_ParseStack.m_Memory.m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&this->m_ParseStack,
      num: 1);
  v4 = ++p_m_ParseStack->m_Size;
  m_pMemory = p_m_ParseStack->m_Memory.m_pMemory;
  p_m_ParseStack->m_pElements = p_m_ParseStack->m_Memory.m_pMemory;
  v6 = 4 * (3 * v4 - 3);
  *(CXMLUnserializationState::ParseState_t::ParseType_t *)((char *)&m_pMemory->m_Type + v6) = ELEMENT;
  *(CDmAttribute **)((char *)&p_m_ParseStack->m_Memory.m_pMemory->m_pAttribute + v6) = nullptr;
  *(int *)((char *)&p_m_ParseStack->m_Memory.m_pMemory->m_hElement + v6) = hElement;
  this->m_hTopmostDictHandle = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x0043C440
// Name: private: int CXMLUnserializationState::StartFileScopeElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::StartFileScopeElement(
        CXMLUnserializationState *this,
        const char *pElementName)
{
  int m_Size; // ecx
  CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *p_m_ParseStack; // esi
  UtlLinkedListElem_t<IUndoElement *,int> *m_pMemory; // edx
  int v7; // eax

  if ( _stricmp(dst: pElementName, src: "DMXFile") != 0 )
    return 1;
  m_Size = this->m_ParseStack.m_Size;
  p_m_ParseStack = (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&this->m_ParseStack;
  if ( m_Size >= p_m_ParseStack->m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(this: p_m_ParseStack, num: 1);
  ++p_m_ParseStack[1].m_pMemory;
  m_pMemory = p_m_ParseStack->m_pMemory;
  v7 = (int)p_m_ParseStack[1].m_pMemory;
  p_m_ParseStack[1].m_nAllocationCount = (int)p_m_ParseStack->m_pMemory;
  m_pMemory[v7 - 1].m_Element = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043C4A0
// Name: private: int CXMLUnserializationState::StartAttributeElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::StartAttributeElement(
        CXMLUnserializationState *this,
        const char *pAttributeName,
        DmElementHandle_t pAttributeType)
{
  int CurrentLine; // eax
  const char *v6; // ebx
  DmAttributeType_t v7; // esi
  int DmElement; // ebp
  CDmElement *v9; // eax
  CDmAttribute *v10; // esi
  CDmElement *v11; // eax
  CDmElement *Element; // eax
  CDmAttribute *v13; // ebx
  int v14; // eax
  int v15; // ebp
  CUtlStack<CXMLUnserializationState::ParseState_t,CUtlMemory<CXMLUnserializationState::ParseState_t,int> > *p_m_ParseStack; // esi
  CXMLUnserializationState::ParseState_t *m_pMemory; // ecx
  int v18; // eax
  const char *v19; // [esp-14h] [ebp-18h]
  const char *v20; // [esp-10h] [ebp-14h]
  const char *v21; // [esp-4h] [ebp-8h]

  if ( this->m_hTopmostDictHandle == -1 )
  {
    v21 = (const char *)pAttributeType;
    CurrentLine = XMLParser_GetCurrentLine();
    _Warning(a1: "XML: (%d) Tried to add attribute %s outside of an element definition scope\n", CurrentLine, v21);
    return 1;
  }
  v6 = (const char *)pAttributeType;
  v7 = g_pDataModel->GetAttributeTypeForName(this: g_pDataModel, a2: (const char *)pAttributeType);
  if ( v7 != AT_UNKNOWN )
  {
    if ( this->m_hTopmostDictHandle == -1 )
      Element = nullptr;
    else
      Element = CDmElementDictionary::GetElement(this: &this->m_ElementDict, handle: this->m_hTopmostDictHandle);
    v13 = CDmElement::AddAttribute(this: Element, pAttributeName, type: v7);
    if ( v13 == nullptr )
    {
      v20 = (const char *)pAttributeType;
      v19 = pAttributeName;
      goto LABEL_19;
    }
    v15 = 3 - (v7 != AT_FIRST_VALUE_TYPE);
    p_m_ParseStack = &this->m_ParseStack;
    if ( this->m_ParseStack.m_Size >= this->m_ParseStack.m_Memory.m_nAllocationCount )
      CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&this->m_ParseStack,
        num: 1);
    ++this->m_ParseStack.m_Size;
    m_pMemory = p_m_ParseStack->m_Memory.m_pMemory;
    v18 = 3 * this->m_ParseStack.m_Size - 3;
    this->m_ParseStack.m_pElements = this->m_ParseStack.m_Memory.m_pMemory;
    v18 *= 4;
    *(CXMLUnserializationState::ParseState_t::ParseType_t *)((char *)&m_pMemory->m_Type + v18) = v15;
    *(CDmAttribute **)((char *)&p_m_ParseStack->m_Memory.m_pMemory->m_pAttribute + v18) = v13;
    *(int *)((char *)&p_m_ParseStack->m_Memory.m_pMemory->m_hElement + v18) = -1;
    return 0;
  }
  else
  {
    DmElement = CXMLUnserializationState::CreateDmElement(this, pElementType: v6);
    if ( DmElement == -1 )
      return 1;
    if ( this->m_hTopmostDictHandle == -1 )
      v9 = nullptr;
    else
      v9 = CDmElementDictionary::GetElement(this: &this->m_ElementDict, handle: this->m_hTopmostDictHandle);
    v10 = CDmElement::AddAttribute(this: v9, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( v10 == nullptr )
    {
      v20 = (const char *)pAttributeType;
      v19 = pAttributeName;
LABEL_19:
      v14 = XMLParser_GetCurrentLine();
      _Warning(a1: "XML: (%d) Attribute %s is not requested type %s\n", v14, v19, v20);
      return 1;
    }
    v11 = CDmElementDictionary::GetElement(this: &this->m_ElementDict, handle: DmElement);
    if ( v11 != nullptr )
      pAttributeType = CDmElement::GetHandle(this: v11);
    else
      pAttributeType = DMELEMENT_HANDLE_INVALID;
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: v10, value: &pAttributeType);
    CXMLUnserializationState::PushAttribute(this, pAttributeName, pAttribute: v10, hElement: DmElement, type: ATTRIBUTE);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C620
// Name: private: int CXMLUnserializationState::StartChildElement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::StartChildElement(CXMLUnserializationState *this, const char *pElementType)
{
  int m_Size; // eax
  CXMLUnserializationState::ParseState_t *m_pMemory; // ecx
  bool v5; // bl
  const char *v6; // eax
  int CurrentLine; // eax
  int v9; // eax
  CXMLUnserializationState::ParseState_t *v10; // ecx
  int v11; // eax
  int DmElement; // eax
  int v13; // ebp

  m_Size = this->m_ParseStack.m_Size;
  m_pMemory = this->m_ParseStack.m_Memory.m_pMemory;
  v5 = m_pMemory[m_Size - 1].m_Type == ATTRIBUTE
    && (m_pMemory[this->m_ParseStack.m_Size - 1].m_pAttribute->m_nFlags & 0x1F) == 0xF;
  v6 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: 1);
  if ( _stricmp(dst: pElementType, src: v6) == 0 )
  {
    if ( this->m_hTopmostDictHandle == -1 )
    {
      CurrentLine = XMLParser_GetCurrentLine();
      _Warning(a1: "XML: (%d) Child element is being defined at the root level!\n", CurrentLine);
      return 1;
    }
    if ( v5 )
    {
      if ( this->m_ParseStack.m_Size >= this->m_ParseStack.m_Memory.m_nAllocationCount )
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&this->m_ParseStack,
          num: 1);
      ++this->m_ParseStack.m_Size;
      v10 = this->m_ParseStack.m_Memory.m_pMemory;
      v11 = this->m_ParseStack.m_Size;
      this->m_ParseStack.m_pElements = v10;
      v10[v11 - 1].m_Type = ATTRIBUTE_ELEMENT_ARRAY_REFERENCE;
      return 0;
    }
    else
    {
      v9 = XMLParser_GetCurrentLine();
      _Warning(a1: "XML: (%d) Expected array element attribute\n", v9);
      return 1;
    }
  }
  else
  {
    DmElement = CXMLUnserializationState::CreateDmElement(this, pElementType);
    v13 = DmElement;
    if ( DmElement == -1 )
      return 1;
    if ( v5 )
    {
      CDmElementDictionary::AddArrayAttribute(
        this: &this->m_ElementDict,
        pAttribute: this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_pAttribute,
        hElement: DmElement);
      CXMLUnserializationState::PushElement(this, hElement: v13);
      return 0;
    }
    else
    {
      if ( this->m_hRootElement == -1 )
        this->m_hRootElement = DmElement;
      CXMLUnserializationState::PushElement(this, hElement: DmElement);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C760
// Name: public: int CXMLUnserializationState::StartElement(unsigned char const __near *,unsigned char const __near *,char const __near *,struct tagXMLVECTOR __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::StartElement(
        CXMLUnserializationState *this,
        const unsigned __int8 *uri,
        const unsigned __int8 *localName,
        const char *pElementName,
        tagXMLVECTOR *atts)
{
  int NamedItem; // eax
  int m_Size; // eax
  CXMLUnserializationState::ParseState_t *m_pMemory; // edx

  if ( this->m_ParseStack.m_Size == 0 )
    return CXMLUnserializationState::StartFileScopeElement(this, pElementName);
  NamedItem = XMLParser_GetNamedItem();
  if ( NamedItem != 0 )
    return CXMLUnserializationState::StartAttributeElement(
             this,
             pAttributeName: pElementName,
             pAttributeType: *(DmElementHandle_t *)(NamedItem + 4));
  m_Size = this->m_ParseStack.m_Size;
  m_pMemory = this->m_ParseStack.m_Memory.m_pMemory;
  if ( m_pMemory[m_Size - 1].m_Type != ATTRIBUTE || (m_pMemory[m_Size - 1].m_pAttribute->m_nFlags & 0x1F) == 0xF )
    return CXMLUnserializationState::StartChildElement(this, pElementType: pElementName);
  CXMLUnserializationState::PushAttribute(
    this,
    pAttributeName: nullptr,
    pAttribute: this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_pAttribute,
    hElement: -1,
    type: ATTRIBUTE_ARRAY_VALUE);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043C800
// Name: private: int CXMLUnserializationState::CharactersAttribute(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXMLUnserializationState::CharactersAttribute(
        CXMLUnserializationState *this,
        unsigned __int8 *pChars,
        int cbChars)
{
  char v4; // dl
  int CurrentLine; // eax
  void *v7; // esp
  int v8; // eax
  bool v9; // al
  int v10; // eax
  unsigned __int8 v11[12]; // [esp+0h] [ebp-44h] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-38h] BYREF
  CDmAttribute *pTopAttribute; // [esp+3Ch] [ebp-8h]

  v4 = this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_pAttribute->m_nFlags & 0x1F;
  pTopAttribute = this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_pAttribute;
  if ( v4 == 1 )
  {
    CurrentLine = XMLParser_GetCurrentLine();
    _Warning(
      a1: "XML (%d) : Error parsing attribute data (can't have non-attribute data in an element block)!\n",
      CurrentLine);
    return 1;
  }
  v7 = alloca(cbChars + 1);
  memcpy(dst: v11, src: pChars, count: cbChars);
  v11[cbChars] = 0;
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v11, nSize: cbChars, nFlags: 9);
  if ( (pTopAttribute->m_nFlags & 0x1Fu) < 0xF )
  {
    v9 = CDmAttribute::Unserialize(this: pTopAttribute, &buf);
  }
  else
  {
    if ( this->m_ParseStack.m_Memory.m_pMemory[this->m_ParseStack.m_Size - 1].m_Type != ATTRIBUTE_ARRAY_VALUE )
    {
      v8 = XMLParser_GetCurrentLine();
      _Warning(a1: "XML (%d) : Error parsing array attribute data!\n", v8);
      CUtlString::~CUtlString(this: &buf);
      return 1;
    }
    v9 = CDmAttribute::UnserializeElement(this: pTopAttribute, &buf);
  }
  if ( v9 )
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    v10 = XMLParser_GetCurrentLine();
    _Warning(a1: "XML (%d) : Error parsing attribute data!\n", v10);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C950
// Name: int StartElement(void __near *,unsigned char const __near *,unsigned char const __near *,unsigned char const __near *,struct tagXMLVECTOR __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl StartElement(
        CXMLUnserializationState *pUserData,
        const unsigned __int8 *uri,
        const unsigned __int8 *localName,
        const unsigned __int8 *qName,
        tagXMLVECTOR *atts)
{
  return CXMLUnserializationState::StartElement(
           this: pUserData,
           uri,
           localName,
           pElementName: (const char *)qName,
           atts);
}

//------------------------------------------------------------------------------
// Address: 0x0043C970
// Name: int Characters(void __near *,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Characters(CXMLUnserializationState *pUserData, unsigned __int8 *Chars, int cbChars)
{
  int result; // eax

  if ( pUserData->m_ParseStack.m_Size == 0 )
    return 0;
  switch ( pUserData->m_ParseStack.m_Memory.m_pMemory[pUserData->m_ParseStack.m_Size - 1].m_Type )
  {
    case ATTRIBUTE:
    case ATTRIBUTE_ARRAY_VALUE:
      result = CXMLUnserializationState::CharactersAttribute(this: pUserData, pChars: Chars, cbChars);
      break;
    case ATTRIBUTE_ELEMENT_REFERENCE:
      result = CXMLUnserializationState::CharactersElementReference(this: pUserData, pChars: Chars, cbChars);
      break;
    case ATTRIBUTE_ELEMENT_ARRAY_REFERENCE:
      result = CXMLUnserializationState::CharactersElementArrayReference(this: pUserData, pChars: Chars, cbChars);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C9E0
// Name: public: bool CXMLUnserializationState::Unserialize(enum DmFileId_t,class CUtlBuffer __near &,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CXMLUnserializationState::Unserialize(
        CXMLUnserializationState *this,
        DmFileId_t fileid,
        CUtlBuffer *buf,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  tagXMLPARSER *m_Parser; // edx
  int v8; // eax
  bool v9; // bl
  int v10; // edi
  CDmElement *Element; // eax

  *ppRoot = nullptr;
  this->m_hTopmostDictHandle = -1;
  this->m_hRootElement = -1;
  this->m_idConflictResolution = idConflictResolution;
  if ( XMLParser_Create() != 0 )
  {
    m_Parser = this->m_Parser;
    this->m_fileid = fileid;
    m_Parser->errorHandler = (void (__cdecl *)(tagXMLPARSER *))CSteamApplication::PostShutdown;
    this->m_Parser->startElementHandler = (int (__cdecl *)(void *, const unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *, tagXMLVECTOR *))StartElement;
    this->m_Parser->endElementHandler = (int (__cdecl *)(void *, const unsigned __int8 *, const unsigned __int8 *, const unsigned __int8 *))EndElement;
    this->m_Parser->charactersHandler = (int (__cdecl *)(void *, const unsigned __int8 *, int))Characters;
    this->m_Parser->UserData = this;
    v8 = XMLParser_Parse();
    v9 = v8 != 0;
    if ( v8 == 0 )
      _Warning(
        a1: "Error: %s\nLine: %d Col: %d\n",
        (const char *)this->m_Parser->ErrorString,
        this->m_Parser->ErrorLine,
        this->m_Parser->ErrorColumn);
    XMLParser_Free();
    if ( v9 )
    {
      CDmElementDictionary::HookUpElementReferences(this: &this->m_ElementDict, a2: (int)ppRoot);
      *ppRoot = CDmElementDictionary::GetElement(this: &this->m_ElementDict, handle: this->m_hRootElement);
      v10 = 0;
      do
      {
        Element = CDmElementDictionary::GetElement(this: &this->m_ElementDict, handle: v10);
        if ( Element != nullptr )
          CDmElement::MarkBeingUnserialized(this: Element, beingUnserialized: false);
        ++v10;
      }
      while ( v10 >= 0 && v10 < this->m_ElementDict.m_Dict.m_Size );
    }
    this->m_fileid = DMFILEID_INVALID;
    CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
    return v9;
  }
  else
  {
    _Warning(a1: "Error creating parser!\n");
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CB20
// Name: public: virtual bool CXMLSerializer::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXMLSerializer::Serialize(CXMLSerializer *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  int i; // esi
  CDmElement *RootElement; // eax
  CDmElementSerializationDictionary dict; // [esp+8h] [ebp-28h] BYREF

  SetSerializationDelimiter(pConv: &s_XMLCharConversion);
  CUtlBuffer::Printf(this: outBuf, pFmt: "<%s>\n\n", "DMXFile");
  CDmElementSerializationDictionary::CDmElementSerializationDictionary(this: (CDmElementSerializationDictionary *)&dict.m_Dict.m_Elements);
  CDmElementSerializationDictionary::BuildElementList(
    this: (CDmElementSerializationDictionary *)&dict.m_Dict.m_Elements,
    pElement: pRoot,
    bFlatMode: this->m_bFlatMode);
  for ( i = CDmElementSerializationDictionary::FirstRootElement(this: (CDmElementSerializationDictionary *)&dict.m_Dict.m_Elements);
        i != -1;
        i = CDmElementSerializationDictionary::NextRootElement(
              this: (CDmElementSerializationDictionary *)&dict.m_Dict.m_Elements,
              h: i) )
  {
    RootElement = CDmElementSerializationDictionary::GetRootElement(
                    this: (CDmElementSerializationDictionary *)&dict.m_Dict.m_Elements,
                    h: i);
    CXMLSerializer::SaveElement(
      this,
      buf: outBuf,
      dict: (CDmElementSerializationDictionary *)&dict.m_Dict.m_Elements,
      pElement: RootElement,
      bWriteDelimiters: true);
    CUtlBuffer::Printf(this: outBuf, pFmt: "\n");
  }
  CUtlBuffer::Printf(this: outBuf, pFmt: "</%s>\n", "DMXFile");
  SetSerializationDelimiter(pConv: nullptr);
  CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *)&dict.m_Dict.m_Elements);
  dict.m_Dict.m_LastAlloc.index = -1;
  CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Purge(this: (CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> *)&dict.m_Dict.m_Elements.m_nBlocks);
  dict.m_Dict.m_pElements = (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)-1;
  CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Purge(this: (CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> *)&dict.m_Dict.m_Elements.m_nBlocks);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043CC00
// Name: public: virtual bool CXMLSerializer::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CXMLSerializer::Unserialize(
        CXMLSerializer *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  bool v10; // bl
  CXMLUnserializationState unserializer; // [esp+Ch] [ebp-A0h] BYREF

  memset(&unserializer.m_ParseStack.m_Memory.m_nAllocationCount, 0, 20);
  CDmElementDictionary::CDmElementDictionary(this: (CDmElementDictionary *)&unserializer.m_ElementDict.m_Dict.m_Memory.m_nAllocationCount);
  if ( CXMLUnserializationState::Unserialize(
         this: (CXMLUnserializationState *)&unserializer.m_ParseStack,
         fileid,
         buf,
         idConflictResolution,
         ppRoot) )
  {
    v10 = g_pDataModel->UpdateUnserializedElements(
            this: g_pDataModel,
            a2: pSourceFormatName,
            a3: nSourceFormatVersion,
            a4: fileid,
            a5: idConflictResolution,
            a6: ppRoot);
    CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&unserializer.m_ElementDict.m_idmap.m_Buckets.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&unserializer.m_ElementDict.m_idmap.m_Buckets.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_elementsToDelete.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_ArrayAttributes.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_Attributes.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_Dict.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ParseStack.m_Memory.m_nAllocationCount);
    return v10;
  }
  else
  {
    CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&unserializer.m_ElementDict.m_idmap.m_Buckets.m_Memory.m_nAllocationCount);
    CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(this: (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)&unserializer.m_ElementDict.m_idmap.m_Buckets.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_elementsToDelete.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_ArrayAttributes.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_Attributes.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ElementDict.m_Dict.m_Memory.m_nAllocationCount);
    CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>::~CUtlVector<CDmElementDictionary::DeletionInfo_t,CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&unserializer.m_ParseStack.m_Memory.m_nAllocationCount);
    return false;
  }
}
