// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/dmserializerkeyvalues.cpp
// Functions: 13
// ============================================================

#include "datamodel\dmserializerkeyvalues.h"

//------------------------------------------------------------------------------
// Address: 0x004432D0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00443300
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00443320
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_8;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_8:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004434D0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443820
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x00443830
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443910
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443940
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &defaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00443AC0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443B70
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00443CA0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00443DD0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x004625E0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00451B70
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00451BA0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00451BC0
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_17;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_17:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451D70
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004520B0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x004520C0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = var;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004521A0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004521D0
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: var);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00452350
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452400
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00452530
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00452660
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x0056FB40
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0044BF00
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0044BF30
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0044BF50
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case 1:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_16;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case 2:
$LN4_16:
      result = AT_INT;
      break;
    case 3:
      result = AT_FLOAT;
      break;
    case 4:
      result = AT_VOID;
      break;
    case 6:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C100
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044C440
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0044C450
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C530
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044C560
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0044C6E0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C790
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0044C8C0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0044C9F0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x005CF940
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F9B50
// Name: public: class KeyValues __near * vgui::Menu::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Menu::GetItemUserData(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx
  vgui::MenuItem *m_Element; // esi

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID)
    && (m_Element = m_pMemory[v3].m_Element) != nullptr
    && m_Element->IsEnabled(this: m_Element) )
  {
    return vgui::MenuItem::GetUserData(this: m_Element);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005FFDC0
// Name: public: class KeyValues __near * vgui::EditablePanel::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::EditablePanel::GetDialogVariables(vgui::EditablePanel *this)
{
  KeyValues *result; // eax
  KeyValues *v3; // eax

  result = this->m_pDialogVariables;
  if ( result == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      result = KeyValues::KeyValues(this: v3, setName: "DialogVariables");
      this->m_pDialogVariables = result;
    }
    else
    {
      this->m_pDialogVariables = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00605420
// Name: public: class KeyValues __near * vgui::ComboBox::GetActiveItemUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetActiveItemUserData(vgui::ComboBox *this)
{
  int v2; // eax

  v2 = this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00605450
// Name: public: class KeyValues __near * vgui::ComboBox::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetItemUserData(vgui::ComboBox *this, int itemID)
{
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00608780
// Name: public: virtual class KeyValues __near * vgui::ListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListPanel::GetItem(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->kv;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0060F150
// Name: public: virtual class KeyValues __near * vgui::ListViewPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListViewPanel::GetItem(vgui::ListViewPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00611EA0
// Name: public: class KeyValues __near * vgui::MenuItem::GetUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::MenuItem::GetUserData(vgui::MenuItem *this)
{
  int v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    return this->m_pUserData;
  v2 = this->m_pCascadeMenu->GetActiveItem(this: this->m_pCascadeMenu);
  return vgui::Menu::GetItemUserData(this: this->m_pCascadeMenu, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00622F20
// Name: public: virtual class KeyValues __near * vgui::TreeView::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::TreeView::GetItemData(vgui::TreeView *this, int itemIndex)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemIndex >= 0
    && itemIndex < this->m_NodeList.m_Memory.m_nAllocationCount
    && itemIndex <= this->m_NodeList.m_LastAlloc.index
    && ((m_pMemory = this->m_NodeList.m_Memory.m_pMemory, v3 = itemIndex, m_pMemory[itemIndex].m_Previous != itemIndex)
     || m_pMemory[v3].m_Next == itemIndex) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00638FA0
// Name: public: class KeyValues __near * vgui::BuildGroup::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildGroup::GetDialogVariables(vgui::BuildGroup *this)
{
  vgui::EditablePanel *v1; // eax

  v1 = (vgui::EditablePanel *)__RTDynamicCast(
                                inptr: this->m_pParentPanel,
                                VfDelta: 0,
                                SrcType: &vgui::Panel `RTTI Type Descriptor',
                                TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
                                isReference: 0);
  if ( v1 != nullptr )
    return vgui::EditablePanel::GetDialogVariables(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0063C580
// Name: public: virtual class KeyValues __near * vgui::BuildModeDialog::StoreSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildModeDialog::StoreSettings(vgui::BuildModeDialog *this)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  vgui::BuildModeDialog::PanelList *m_pPanelList; // eax
  int v5; // esi
  PanelItem_t *m_pMemory; // ecx
  PanelItem_t *v7; // eax
  const char *m_szName; // ebx
  void *m_EditPanel; // ecx
  int v10; // eax
  char buf[512]; // [esp+Ch] [ebp-208h] BYREF
  int i; // [esp+20Ch] [ebp-8h]
  KeyValues *storedSettings; // [esp+210h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = this->m_pCurrentPanel->GetName(this: this->m_pCurrentPanel);
    storedSettings = KeyValues::KeyValues(this: v2, setName: v3);
  }
  else
  {
    storedSettings = nullptr;
  }
  m_pPanelList = this->m_pPanelList;
  i = 0;
  if ( m_pPanelList->m_PanelList.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      v7 = m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      m_szName = m_pMemory[v5].m_szName;
      if ( m_pMemory[v5].m_EditPanel != nullptr )
        m_EditPanel = v7[v5].m_EditPanel;
      else
        m_EditPanel = v7[v5].m_EditButton;
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)m_EditPanel + 856))(a1: m_EditPanel, a2: buf, a3: 512);
      if ( (unsigned int)(this->m_pPanelList->m_PanelList.m_Memory.m_pMemory[v5].m_iType - 4) > 1 )
      {
        KeyValues::SetString(this: storedSettings, keyName: m_szName, value: buf);
      }
      else
      {
        v10 = atoi(nptr: buf);
        KeyValues::SetInt(this: storedSettings, keyName: m_szName, value: v10);
      }
      m_pPanelList = this->m_pPanelList;
      ++v5;
      ++i;
    }
    while ( i < m_pPanelList->m_PanelList.m_Size );
  }
  return storedSettings;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101EB170
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x101EB1A0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x101EB1C0
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case 1:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &var);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &var);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &var);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &var);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (char *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &var);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_82;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &var);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case 2:
$LN4_82:
      result = AT_INT;
      break;
    case 3:
      result = AT_FLOAT;
      break;
    case 4:
      result = AT_VOID;
      break;
    case 6:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EB370
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EB6B0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x101EB6C0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &var;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB7A0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EB7D0
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  unsigned int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &var);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = std::char_traits<char>::length(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101EB950
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBA00
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x101EBB30
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101EBC60
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x102AD500
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DDD10
// Name: public: class KeyValues __near * vgui::EditablePanel::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::EditablePanel::GetDialogVariables(vgui::EditablePanel *this)
{
  KeyValues *result; // eax
  KeyValues *v3; // eax

  result = this->m_pDialogVariables;
  if ( result == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      result = KeyValues::KeyValues(this: v3, setName: "DialogVariables");
      this->m_pDialogVariables = result;
    }
    else
    {
      this->m_pDialogVariables = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC1E0
// Name: public: class KeyValues __near * vgui::ComboBox::GetActiveItemUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetActiveItemUserData(vgui::ComboBox *this)
{
  int v2; // eax

  v2 = this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102EC210
// Name: public: class KeyValues __near * vgui::ComboBox::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetItemUserData(vgui::ComboBox *this, int itemID)
{
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x102EF530
// Name: public: virtual class KeyValues __near * vgui::ListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListPanel::GetItem(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->kv;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F5F70
// Name: public: virtual class KeyValues __near * vgui::ListViewPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListViewPanel::GetItem(vgui::ListViewPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F9180
// Name: public: class KeyValues __near * vgui::Menu::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Menu::GetItemUserData(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx
  vgui::MenuItem *m_Element; // esi

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID)
    && (m_Element = m_pMemory[v3].m_Element) != nullptr
    && m_Element->IsEnabled(this: m_Element) )
  {
    return vgui::MenuItem::GetUserData(this: m_Element);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102FD920
// Name: public: class KeyValues __near * vgui::MenuItem::GetUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::MenuItem::GetUserData(vgui::MenuItem *this)
{
  int v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    return this->m_pUserData;
  v2 = this->m_pCascadeMenu->GetActiveItem(this: this->m_pCascadeMenu);
  return vgui::Menu::GetItemUserData(this: this->m_pCascadeMenu, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10308010
// Name: public: virtual class KeyValues __near * vgui::TreeView::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::TreeView::GetItemData(vgui::TreeView *this, int itemIndex)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemIndex >= 0
    && itemIndex < this->m_NodeList.m_Memory.m_nAllocationCount
    && itemIndex <= this->m_NodeList.m_LastAlloc.index
    && ((m_pMemory = this->m_NodeList.m_Memory.m_pMemory, v3 = itemIndex, m_pMemory[itemIndex].m_Previous != itemIndex)
     || m_pMemory[v3].m_Next == itemIndex) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10327910
// Name: public: class KeyValues __near * vgui::BuildGroup::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildGroup::GetDialogVariables(vgui::BuildGroup *this)
{
  vgui::EditablePanel *v1; // eax

  v1 = (vgui::EditablePanel *)__RTDynamicCast(
                                inptr: this->m_pParentPanel,
                                VfDelta: 0,
                                SrcType: &vgui::Panel `RTTI Type Descriptor',
                                TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
                                isReference: 0);
  if ( v1 != nullptr )
    return vgui::EditablePanel::GetDialogVariables(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1032AD60
// Name: public: virtual class KeyValues __near * vgui::BuildModeDialog::StoreSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildModeDialog::StoreSettings(vgui::BuildModeDialog *this)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  vgui::BuildModeDialog::PanelList *m_pPanelList; // eax
  int v5; // esi
  PanelItem_t *m_pMemory; // ecx
  PanelItem_t *v7; // eax
  const char *m_szName; // ebx
  void *m_EditPanel; // ecx
  int v10; // eax
  char buf[512]; // [esp+Ch] [ebp-208h] BYREF
  int i; // [esp+20Ch] [ebp-8h]
  KeyValues *storedSettings; // [esp+210h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = this->m_pCurrentPanel->GetName(this: this->m_pCurrentPanel);
    storedSettings = KeyValues::KeyValues(this: v2, setName: v3);
  }
  else
  {
    storedSettings = nullptr;
  }
  m_pPanelList = this->m_pPanelList;
  i = 0;
  if ( m_pPanelList->m_PanelList.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      v7 = m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      m_szName = m_pMemory[v5].m_szName;
      if ( m_pMemory[v5].m_EditPanel != nullptr )
        m_EditPanel = v7[v5].m_EditPanel;
      else
        m_EditPanel = v7[v5].m_EditButton;
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)m_EditPanel + 856))(a1: m_EditPanel, a2: buf, a3: 512);
      if ( (unsigned int)(this->m_pPanelList->m_PanelList.m_Memory.m_pMemory[v5].m_iType - 4) > 1 )
      {
        KeyValues::SetString(this: storedSettings, keyName: m_szName, value: buf);
      }
      else
      {
        v10 = atoi(nptr: buf);
        KeyValues::SetInt(this: storedSettings, keyName: m_szName, value: v10);
      }
      m_pPanelList = this->m_pPanelList;
      ++v5;
      ++i;
    }
    while ( i < m_pPanelList->m_PanelList.m_Size );
  }
  return storedSettings;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0047C530
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0047C560
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0047C580
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: WindowName);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: WindowName);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: WindowName);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: WindowName);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: WindowName);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_18;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: WindowName);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_18:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C730
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  int v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != 15 || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case 1:
          case 6:
          case 15:
          case 19:
          case 20:
            v12 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 88))(
                                  a1: g_pDataModel.u,
                                  a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case 2:
          case 3:
          case 4:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CA70
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0047CA80
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  int v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = (CDmElement *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = WindowName;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CB60
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047CB90
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: WindowName);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, KeyValues **, KeyValues *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
        a1: g_pDataModel.u,
        a2: &pKeyValues,
        a3: pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0047CD10
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  int v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: 0);
  if ( v4 == -1 )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
                          a1: g_pDataModel.u,
                          a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047CDC0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 196))(
                       a1: g_pDataModel.u,
                       a2: Name,
                       a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0047CEF0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047D020
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00571B60
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x004FFAD0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004FFB00
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004FFB20
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDefaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDefaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDefaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDefaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDefaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_12;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDefaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_12:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004FFCD0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned __int8 *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CVTFTexture::ImageData(this: (CVTFTexture *)pElement); i != nullptr; i = *(unsigned __int8 **)i )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)i) && (i[16] & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDefaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00500010
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x00500020
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDefaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500100
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00500130
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: pDefaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005002B0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500360
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00500490
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x005005C0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x0052EDB0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004C09F0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004C0A20
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004C0A40
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_20;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_20:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C0BF0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  int v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != 15 || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case 1:
          case 6:
          case 15:
          case 19:
          case 20:
            v12 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 88))(
                                  a1: g_pDataModel.u,
                                  a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case 2:
          case 3:
          case 4:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C0F30
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x004C0F50
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  int v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = (CDmElement *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1030
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1060
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: pDeltaStateName);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, KeyValues **, KeyValues *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
        a1: g_pDataModel.u,
        a2: &pKeyValues,
        a3: pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004C11E0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  int v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: 0);
  if ( v4 == -1 )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
                          a1: g_pDataModel.u,
                          a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1290
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 196))(
                       a1: g_pDataModel.u,
                       a2: Name,
                       a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x004C13C0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004C14F0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x005BDB40
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00445120
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00445150
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00445170
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_8;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_8:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00445320
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445660
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x00445670
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445750
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445780
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00445900
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004459B0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00445AE0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00445C10
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00495110
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00447390
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004473C0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004473E0
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  char *String; // eax
  DmAttributeType_t result; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: str);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: str);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: str);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: str);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: str);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_13;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: str);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_13:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447590
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004478E0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x004478F0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = str;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004479D0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00447A00
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: str);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00447B80
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447C30
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00447D60
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00447E90
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  char v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return 0;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 != 0 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00536D00
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x0043ADB0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0043ADE0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0043AE00
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f3; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  int f4; // [esp+Ch] [ebp-8h] BYREF
  char v14; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f3, &i, &v14) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f3, &i) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f3) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            f4 = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            if ( sscanf(string: v7, format: "%d", &f4) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_2;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_2:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043AFC0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  CDmAttribute **v4; // edi
  int v5; // esi
  KeyValues *j; // eax
  int v7; // eax
  IDataModel_vtbl *v8; // edx
  int v9; // edi
  const char *m_pKeyValuesName; // ebx
  int v11; // eax
  DmAttributeType_t v12; // edi
  const char *v13; // eax
  int m_Put; // eax
  int v15; // eax
  CDmAttribute *v16; // ecx
  int v18; // eax
  int v19; // eax
  _DWORD v21[3]; // [esp+0h] [ebp-20h] BYREF
  CDmSerializerKeyValues *v22; // [esp+Ch] [ebp-14h]
  CDmAttribute **ppAttributes; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  CDmAttribute *pAttribute; // [esp+18h] [ebp-8h]

  v22 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = (CDmAttribute **)v21;
  ppAttributes = (CDmAttribute **)v21;
  v5 = 0;
  for ( j = KeyValues::GetFirstSubKey(this: (KeyValues *)pElement); j != nullptr; j = (KeyValues *)j->m_iKeyName )
  {
    if ( (j->m_iValue & 0x2040) == 0 )
      v21[v5++] = j;
  }
  v7 = v5 - 1;
  i = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->__vftable;
      pAttribute = v4[v7];
      v9 = 0;
      m_pKeyValuesName = v8->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      if ( s_pAttributeRemap[0].m_pKeyValuesName != nullptr )
      {
        v11 = 0;
        while ( _stricmp(dst: m_pKeyValuesName, src: s_pAttributeRemap[v11].m_pDmeName) != 0 )
        {
          v11 = ++v9;
          if ( s_pAttributeRemap[v9].m_pKeyValuesName == nullptr )
            goto LABEL_14;
        }
        m_pKeyValuesName = s_pAttributeRemap[v9].m_pKeyValuesName;
      }
LABEL_14:
      v12 = pAttribute->m_nFlags & 0x1F;
      if ( v12 == AT_FIRST_ARRAY_TYPE && _stricmp(dst: m_pKeyValuesName, src: "subkeys") == 0 )
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v22, buf, pSubKeys: pAttribute);
      }
      else
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", m_pKeyValuesName);
        switch ( v12 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v13 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v12);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v13);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              ++buf->m_Put;
              CUtlBuffer::AddNullTermination(this: buf);
            }
            goto LABEL_33;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: pAttribute, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              ++buf->m_Put;
              CUtlBuffer::AddNullTermination(this: buf);
            }
            v16 = pAttribute;
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v16, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
LABEL_33:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v18 = buf->m_Put;
              if ( v18 != 0 && buf->m_Memory.m_pMemory[v18 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              ++buf->m_Put;
              CUtlBuffer::AddNullTermination(this: buf);
            }
            break;
        }
        if ( (buf->m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
      }
      if ( --i < 0 )
        break;
      v7 = i;
      v4 = ppAttributes;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043B2A0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetName(CDmSerializerKeyValues *this)
{
  return "keyvalues";
}

//------------------------------------------------------------------------------
// Address: 0x0043B2B0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0043B2C0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  CDmAttribute *m_pData; // eax
  CDmElement *v5; // edi
  const char *v6; // eax
  CDmrElementArray<CDmElement> array; // [esp+8h] [ebp-Ch] BYREF
  CDmAttribute *v9; // [esp+10h] [ebp-4h]
  int c; // [esp+1Ch] [ebp+8h]

  array.m_pStorage = (DmElementArray_t *)this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    v9 = pSubKeys;
    m_pData = (CDmAttribute *)pSubKeys->m_pData;
  }
  else
  {
    v9 = nullptr;
    m_pData = nullptr;
  }
  array.m_pAttribute = m_pData;
  c = m_pData->m_nFlags;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_pData->m_pNext->m_pNext + v3));
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType.m_Id) )
      {
        v6 = CUtlString::operator char const *(this: &v5->m_Name.m_Storage);
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", v6);
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: (CDmSerializerKeyValues *)array.m_pStorage, buf, pElement: v5);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= c )
        break;
      m_pData = array.m_pAttribute;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B3A0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043B3D0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  const char *v4; // esi
  CDmElement *v6; // eax

  v4 = (const char *)g_pDataModel->CreateElement(
                       this: g_pDataModel,
                       a2: pElementType,
                       a3: pElementName,
                       a4: this->m_fileid,
                       a5: nullptr);
  pElementName = v4;
  if ( v4 == (const char *)-1 )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
      this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ElementList,
      elem: this->m_ElementList.m_Size,
      src: (CUtlSymbolTable::StringPool_t **)&pElementName);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::MarkBeingUnserialized(this: v6, beingUnserialized: true);
    return (int)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B450
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  const char *Name; // esi
  char *v6; // eax
  int v7; // esi
  AttributeRemap_t *v8; // eax
  const char *m_pKeyValuesName; // edi
  const char *v10; // eax
  DmAttributeType_t v11; // edi
  const char *v12; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // esi
  CUtlString pLowerName; // [esp+Ch] [ebp-44h] BYREF
  CUtlBuffer buf; // [esp+1Ch] [ebp-34h] BYREF
  const char *pAttributeValue; // [esp+58h] [ebp+8h]

  Name = KeyValues::GetName(this: pKeyValues);
  pAttributeValue = KeyValues::GetString(this: pKeyValues, keyName: nullptr, defaultValue: defaultValue);
  CUtlString::CUtlString(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount, pString: Name);
  v6 = CUtlString::Get(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount);
  strlwr(string: v6);
  v7 = 0;
  if ( s_pAttributeRemap[0].m_pKeyValuesName != nullptr )
  {
    v8 = s_pAttributeRemap;
    while ( 1 )
    {
      m_pKeyValuesName = v8->m_pKeyValuesName;
      v10 = CUtlString::operator char const *(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount);
      if ( _stricmp(dst: v10, src: m_pKeyValuesName) == 0 )
        break;
      ++v7;
      v8 = (AttributeRemap_t *)(8 * v7 + 4725584);
      if ( s_pAttributeRemap[v7].m_pKeyValuesName == nullptr )
        goto LABEL_7;
    }
    CUtlString::operator=(
      this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount,
      src: s_pAttributeRemap[v7].m_pDmeName);
  }
LABEL_7:
  v11 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues);
  if ( v11 != AT_UNKNOWN
    && ((v12 = CUtlString::operator char const *(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v12)) == nullptr)
      ? (v14 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v12, type: v11))
      : (v14 = v11 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v14 != nullptr) )
  {
    if ( v11 == AT_STRING )
    {
      CDmAttribute::SetValue<char const>(this: v14, pValue: pAttributeValue);
    }
    else
    {
      CUtlBuffer::CUtlBuffer(
        this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
        pBuffer: pAttributeValue,
        nSize: strlen(pAttributeValue),
        nFlags: 9);
      CDmAttribute::Unserialize(this: v14, buf: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount);
      if ( buf.m_Get >= 0 && buf.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)buf.m_Memory.m_nAllocationCount);
    }
    if ( pLowerName.m_Storage.m_nActualLength >= 0 && pLowerName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      goto LABEL_22;
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_nAllocationCount);
    if ( pLowerName.m_Storage.m_nActualLength >= 0 && pLowerName.m_Storage.m_Memory.m_nAllocationCount != 0 )
LABEL_22:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pLowerName.m_Storage.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B620
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementArray_t *v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+10h] [ebp-Ch] BYREF
  CDmAttribute *v14; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+20h] [ebp+4h]
  int iNestingLevela; // [esp+24h] [ebp+8h]

  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&subKeys.m_pAttribute);
  v14 = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( v14 == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          v14 = v10;
          subKeys.m_pAttribute = (CDmAttribute *)v10->m_pData;
        }
        else
        {
          v14 = nullptr;
          subKeys.m_pAttribute = nullptr;
        }
      }
      v11 = (DmElementArray_t *)CDmSerializerKeyValues::UnserializeElement(
                                  this,
                                  pKeyValues: i,
                                  iNestingLevel: iNestingLevela);
      if ( v11 != (DmElementArray_t *)-1 )
      {
        subKeys.m_pStorage = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&subKeys.m_pAttribute,
          src: (const DmElementHandle_t *)&subKeys);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0043B760
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmElementArray_t *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  DmElementArray_t *v4; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int m_Size; // ebx
  int j; // edi
  CDmElement *v11; // eax
  CDmrElementArray<CDmElement> subkeys; // [esp+10h] [ebp-Ch] BYREF
  CDmAttribute *v14; // [esp+18h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = (DmElementArray_t *)g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  subkeys.m_pStorage = v4;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
  else
    v6 = CDmElement::CreateAttribute(this: (CDmElement *)v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&subkeys.m_pAttribute);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    v14 = v6;
    subkeys.m_pAttribute = (CDmAttribute *)v6->m_pData;
  }
  else
  {
    v14 = nullptr;
    subkeys.m_pAttribute = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&subkeys.m_pAttribute,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  m_Size = this->m_ElementList.m_Size;
  for ( j = 0; j < m_Size; ++j )
  {
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[j]);
    CDmElement::MarkBeingUnserialized(this: v11, beingUnserialized: false);
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return subkeys.m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x0043B890
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  bool v13; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x20u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr);
  if ( v13 )
    *ppRoot = (CDmElement *)CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v11);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x00446060
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00445710
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00445740
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00445760
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_8;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_8:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00445910
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445C50
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x00445C60
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445D40
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445D70
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &defaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00445EF0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445FA0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x004460D0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00446200
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x004648A0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0044A6D0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0044A700
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0044A720
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pParentName);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pParentName);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pParentName);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pParentName);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pParentName);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_12;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pParentName);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_12:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A8D0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044AC10
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0044AC20
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pParentName;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AD00
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044AD30
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &pParentName);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0044AEB0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AF60
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0044B090
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0044B1C0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x0054B2E0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0044F410
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0044F440
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0044F460
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case 1:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_17;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case 2:
$LN4_17:
      result = AT_INT;
      break;
    case 3:
      result = AT_FLOAT;
      break;
    case 4:
      result = AT_VOID;
      break;
    case 6:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F610
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  int v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != 15 || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case 1:
          case 6:
          case 15:
          case 19:
          case 20:
            v12 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 88))(
                                  a1: g_pDataModel.u,
                                  a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case 2:
          case 3:
          case 4:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044F950
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0044F960
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  int v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = (CDmElement *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044FA40
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044FA70
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, KeyValues **, KeyValues *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
        a1: g_pDataModel.u,
        a2: &pKeyValues,
        a3: pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0044FBF0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  int v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: 0);
  if ( v4 == -1 )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
                          a1: g_pDataModel.u,
                          a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044FCA0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 196))(
                       a1: g_pDataModel.u,
                       a2: Name,
                       a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0044FDD0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0044FF00
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x005F9B60
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0061FA40
// Name: public: class KeyValues __near * vgui::EditablePanel::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::EditablePanel::GetDialogVariables(vgui::EditablePanel *this)
{
  KeyValues *result; // eax
  KeyValues *v3; // eax

  result = this->m_pDialogVariables;
  if ( result == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      result = KeyValues::KeyValues(this: v3, setName: "DialogVariables");
      this->m_pDialogVariables = result;
    }
    else
    {
      this->m_pDialogVariables = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006346A0
// Name: public: class KeyValues __near * vgui::Menu::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Menu::GetItemUserData(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // esi
  int v3; // edx
  vgui::MenuItem *m_Element; // esi

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((m_pMemory = this->m_MenuItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID)
    && (m_Element = m_pMemory[v3].m_Element) != nullptr
    && m_Element->IsEnabled(this: m_Element) )
  {
    return vgui::MenuItem::GetUserData(this: m_Element);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063CAB0
// Name: public: class KeyValues __near * vgui::ComboBox::GetActiveItemUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetActiveItemUserData(vgui::ComboBox *this)
{
  int v2; // eax

  v2 = this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0063CAE0
// Name: public: class KeyValues __near * vgui::ComboBox::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetItemUserData(vgui::ComboBox *this, int itemID)
{
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x0063FEA0
// Name: public: virtual class KeyValues __near * vgui::ListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListPanel::GetItem(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->kv;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00646870
// Name: public: virtual class KeyValues __near * vgui::ListViewPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListViewPanel::GetItem(vgui::ListViewPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((m_pMemory = this->m_DataItems.m_Memory.m_pMemory, v3 = itemID, m_pMemory[itemID].m_Previous != itemID)
     || m_pMemory[v3].m_Next == itemID) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00648AC0
// Name: public: class KeyValues __near * vgui::MenuItem::GetUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::MenuItem::GetUserData(vgui::MenuItem *this)
{
  int v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    return this->m_pUserData;
  v2 = this->m_pCascadeMenu->GetActiveItem(this: this->m_pCascadeMenu);
  return vgui::Menu::GetItemUserData(this: this->m_pCascadeMenu, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x006593A0
// Name: public: virtual class KeyValues __near * vgui::TreeView::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::TreeView::GetItemData(vgui::TreeView *this, int itemIndex)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // esi
  int v3; // edx

  if ( itemIndex >= 0
    && itemIndex < this->m_NodeList.m_Memory.m_nAllocationCount
    && itemIndex <= this->m_NodeList.m_LastAlloc.index
    && ((m_pMemory = this->m_NodeList.m_Memory.m_pMemory, v3 = itemIndex, m_pMemory[itemIndex].m_Previous != itemIndex)
     || m_pMemory[v3].m_Next == itemIndex) )
  {
    return m_pMemory[v3].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00668BA0
// Name: public: class KeyValues __near * vgui::BuildGroup::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildGroup::GetDialogVariables(vgui::BuildGroup *this)
{
  vgui::EditablePanel *v1; // eax

  v1 = (vgui::EditablePanel *)__RTDynamicCast(
                                inptr: this->m_pParentPanel,
                                VfDelta: 0,
                                SrcType: &vgui::Panel `RTTI Type Descriptor',
                                TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
                                isReference: 0);
  if ( v1 != nullptr )
    return vgui::EditablePanel::GetDialogVariables(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0066BFC0
// Name: public: virtual class KeyValues __near * vgui::BuildModeDialog::StoreSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildModeDialog::StoreSettings(vgui::BuildModeDialog *this)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  vgui::BuildModeDialog::PanelList *m_pPanelList; // eax
  int v5; // esi
  PanelItem_t *m_pMemory; // ecx
  PanelItem_t *v7; // eax
  const char *m_szName; // ebx
  void *m_EditPanel; // ecx
  int v10; // eax
  char buf[512]; // [esp+Ch] [ebp-208h] BYREF
  int i; // [esp+20Ch] [ebp-8h]
  KeyValues *storedSettings; // [esp+210h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = this->m_pCurrentPanel->GetName(this: this->m_pCurrentPanel);
    storedSettings = KeyValues::KeyValues(this: v2, setName: v3);
  }
  else
  {
    storedSettings = nullptr;
  }
  m_pPanelList = this->m_pPanelList;
  i = 0;
  if ( m_pPanelList->m_PanelList.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      m_pMemory = this->m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      v7 = m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      m_szName = m_pMemory[v5].m_szName;
      if ( m_pMemory[v5].m_EditPanel != nullptr )
        m_EditPanel = v7[v5].m_EditPanel;
      else
        m_EditPanel = v7[v5].m_EditButton;
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)m_EditPanel + 856))(a1: m_EditPanel, a2: buf, a3: 512);
      if ( (unsigned int)(this->m_pPanelList->m_PanelList.m_Memory.m_pMemory[v5].m_iType - 4) > 1 )
      {
        KeyValues::SetString(this: storedSettings, keyName: m_szName, value: buf);
      }
      else
      {
        v10 = atoi(nptr: buf);
        KeyValues::SetInt(this: storedSettings, keyName: m_szName, value: v10);
      }
      m_pPanelList = this->m_pPanelList;
      ++v5;
      ++i;
    }
    while ( i < m_pPanelList->m_PanelList.m_Size );
  }
  return storedSettings;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0044B3D0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0044B400
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0044B420
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pch);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pch);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pch);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pch);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pch);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_12;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: &pch);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_12:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B5D0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  int m_Put; // eax
  int v13; // eax
  int v14; // eax
  int v16; // eax
  unsigned __int8 m_Flags; // cl
  int v18; // eax
  int v19; // eax
  int j; // edi
  _DWORD v22[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v23; // [esp+Ch] [ebp-Ch]
  _DWORD *v24; // [esp+10h] [ebp-8h]
  int v25; // [esp+14h] [ebp-4h]
  CDmAttribute *v26; // [esp+24h] [ebp+Ch]

  v23 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v22;
  v24 = v22;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v22[v5++] = i;
  }
  v7 = v5 - 1;
  v25 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v26 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n");
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v13 = buf->m_Put;
              if ( v13 != 0 && buf->m_Memory.m_pMemory[v13 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v26, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v26, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v16 = buf->m_Put;
              if ( v16 != 0 && buf->m_Memory.m_pMemory[v16 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v18 = buf->m_Put;
          if ( v18 != 0 && buf->m_Memory.m_pMemory[v18 - buf->m_nOffset - 1] == 10 )
          {
            v19 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v19 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v23, buf, pSubKeys: v26);
      }
      if ( --v25 < 0 )
        break;
      v7 = v25;
      v4 = v24;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044B920
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0044B930
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = &pch;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BA10
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044BA40
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &pch);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n");
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0044BBC0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n");
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BC70
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0044BDA0
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0044BED0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x0054D2A0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004B9CC0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x004B9CF0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x004B9D10
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  char *String; // eax
  DmAttributeType_t result; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_20;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: pDeltaStateName);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_20:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9EC0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  int v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != 15 || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case 1:
          case 6:
          case 15:
          case 19:
          case 20:
            v12 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 88))(
                                  a1: g_pDataModel.u,
                                  a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case 2:
          case 3:
          case 4:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA200
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x004BA210
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  int v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = (CDmElement *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmElement::m_classType.u) != 0 )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = pDeltaStateName;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA2F0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004BA320
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: pDeltaStateName);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, KeyValues **, KeyValues *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
        a1: g_pDataModel.u,
        a2: &pKeyValues,
        a3: pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004BA4A0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  int v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: 0);
  if ( v4 == -1 )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
                          a1: g_pDataModel.u,
                          a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA550
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 196))(
                       a1: g_pDataModel.u,
                       a2: Name,
                       a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x004BA680
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004BA7B0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  char v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return 0;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 != 0 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x005B6A60
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00455C70
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00455CA0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00455CC0
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  char *String; // eax
  DmAttributeType_t result; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: Ptr);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: Ptr);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: Ptr);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: Ptr);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: Ptr);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_13;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: Ptr);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_13:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00455E70
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  CDmAttribute *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CDmElement::FirstAttribute(this: pElement); i != nullptr; i = i->m_pNext )
  {
    if ( !CDmAttribute::IsStandard(this: i) && (i->m_nFlags & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004561B0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x004561C0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = Ptr;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004562A0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004562D0
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  KeyValues *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: Ptr);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00456450
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456500
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00456630
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (const DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00456760
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  char v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return 0;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 != 0 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00542D60
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00464520
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469C70
// Name: public: virtual class KeyValues __near * vgui::Button::GetCommand(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Button::GetCommand(vgui::Button *this)
{
  return this->_actionMessage;
}

//------------------------------------------------------------------------------
// Address: 0x0046C4E0
// Name: public: class KeyValues __near * vgui::EditablePanel::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::EditablePanel::GetDialogVariables(vgui::EditablePanel *this)
{
  KeyValues *result; // eax
  KeyValues *v3; // eax

  result = this->m_pDialogVariables;
  if ( result == nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      result = KeyValues::KeyValues(this: v3, setName: "DialogVariables");
      this->m_pDialogVariables = result;
    }
    else
    {
      this->m_pDialogVariables = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482350
// Name: public: class KeyValues __near * vgui::ComboBox::GetActiveItemUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ComboBox::GetActiveItemUserData(vgui::ComboBox *this)
{
  int v2; // eax

  v2 = this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
  return vgui::Menu::GetItemUserData(this: this->m_pDropDown, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00485730
// Name: public: virtual class KeyValues __near * vgui::ListPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListPanel::GetItem(vgui::ListPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v2; // esi

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((v2 = &this->m_DataItems.m_Memory.m_pMemory[itemID])->m_Previous != itemID || v2->m_Next == itemID) )
  {
    return this->m_DataItems.m_Memory.m_pMemory[itemID].m_Element->kv;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BD40
// Name: public: virtual class KeyValues __near * vgui::ListViewPanel::GetItem(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::ListViewPanel::GetItem(vgui::ListViewPanel *this, int itemID)
{
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v2; // esi

  if ( itemID >= 0
    && itemID < this->m_DataItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_DataItems.m_LastAlloc.index
    && ((v2 = &this->m_DataItems.m_Memory.m_pMemory[itemID])->m_Previous != itemID || v2->m_Next == itemID) )
  {
    return this->m_DataItems.m_Memory.m_pMemory[itemID].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F020
// Name: public: class KeyValues __near * vgui::Menu::GetItemUserData(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::Menu::GetItemUserData(vgui::Menu *this, int itemID)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v2; // esi
  vgui::MenuItem *m_Element; // esi

  if ( itemID >= 0
    && itemID < this->m_MenuItems.m_Memory.m_nAllocationCount
    && itemID <= this->m_MenuItems.m_LastAlloc.index
    && ((v2 = &this->m_MenuItems.m_Memory.m_pMemory[itemID])->m_Previous != itemID || v2->m_Next == itemID)
    && (m_Element = this->m_MenuItems.m_Memory.m_pMemory[itemID].m_Element) != nullptr
    && m_Element->IsEnabled(this: m_Element) )
  {
    return vgui::MenuItem::GetUserData(this: m_Element);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493290
// Name: public: class KeyValues __near * vgui::MenuItem::GetUserData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::MenuItem::GetUserData(vgui::MenuItem *this)
{
  int v2; // eax

  if ( this->m_pCascadeMenu == nullptr )
    return this->m_pUserData;
  v2 = this->m_pCascadeMenu->GetActiveItem(this: this->m_pCascadeMenu);
  return vgui::Menu::GetItemUserData(this: this->m_pCascadeMenu, itemID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004A3700
// Name: public: virtual class KeyValues __near * vgui::TreeView::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::TreeView::GetItemData(vgui::TreeView *this, int itemIndex)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi

  if ( itemIndex >= 0
    && itemIndex < this->m_NodeList.m_Memory.m_nAllocationCount
    && itemIndex <= this->m_NodeList.m_LastAlloc.index
    && ((v2 = &this->m_NodeList.m_Memory.m_pMemory[itemIndex])->m_Previous != itemIndex || v2->m_Next == itemIndex) )
  {
    return this->m_NodeList.m_Memory.m_pMemory[itemIndex].m_Element->m_pData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AB560
// Name: public: class KeyValues __near * vgui::BuildGroup::GetDialogVariables(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildGroup::GetDialogVariables(vgui::BuildGroup *this)
{
  vgui::EditablePanel *v1; // eax

  v1 = (vgui::EditablePanel *)__RTDynamicCast(
                                inptr: this->m_pParentPanel,
                                VfDelta: 0,
                                SrcType: &vgui::Panel `RTTI Type Descriptor',
                                TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
                                isReference: 0);
  if ( v1 != nullptr )
    return vgui::EditablePanel::GetDialogVariables(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AE970
// Name: public: virtual class KeyValues __near * vgui::BuildModeDialog::StoreSettings(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall vgui::BuildModeDialog::StoreSettings(vgui::BuildModeDialog *this)
{
  KeyValues *v2; // esi
  int v3; // ebp
  const char *v4; // eax
  vgui::BuildModeDialog::PanelList *m_pPanelList; // eax
  int v6; // esi
  PanelItem_t *m_pMemory; // edx
  PanelItem_t *v8; // eax
  char *m_szName; // ebx
  void *m_EditPanel; // ecx
  int v11; // eax
  char buf[512]; // [esp+Ch] [ebp-204h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = 0;
  if ( v2 != nullptr )
  {
    v4 = this->m_pCurrentPanel->GetName(this: this->m_pCurrentPanel);
    *(_DWORD *)buf = KeyValues::KeyValues(this: v2, setName: v4);
  }
  else
  {
    *(_DWORD *)buf = 0;
  }
  m_pPanelList = this->m_pPanelList;
  if ( m_pPanelList->m_PanelList.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      m_pMemory = this->m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      v8 = m_pPanelList->m_PanelList.m_Memory.m_pMemory;
      m_szName = m_pMemory[v6].m_szName;
      if ( m_pMemory[v6].m_EditPanel != nullptr )
        m_EditPanel = v8[v6].m_EditPanel;
      else
        m_EditPanel = v8[v6].m_EditButton;
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)m_EditPanel + 856))(
        a1: m_EditPanel,
        a2: &buf[4],
        a3: 512);
      if ( (unsigned int)(this->m_pPanelList->m_PanelList.m_Memory.m_pMemory[v6].m_iType - 4) > 1 )
      {
        KeyValues::SetString(this: *(KeyValues **)buf, keyName: m_szName, value: &buf[4]);
      }
      else
      {
        v11 = atoi(nptr: &buf[4]);
        KeyValues::SetInt(this: *(KeyValues **)buf, keyName: m_szName, value: v11);
      }
      m_pPanelList = this->m_pPanelList;
      ++v3;
      ++v6;
    }
    while ( v3 < m_pPanelList->m_PanelList.m_Size );
  }
  return *(KeyValues **)buf;
}

//------------------------------------------------------------------------------
// Address: 0x00526710
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x00526740
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x00526760
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  char *String; // eax
  DmAttributeType_t result; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  char *v10; // eax
  float f3; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  int f4; // [esp+Ch] [ebp-8h] BYREF
  char v14; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case 1:
      String = (char *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f3, &i, &v14) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = (char *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f3, &i) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = (char *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f3) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            f4 = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = (char *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            if ( sscanf(string: v7, format: "%d", &f4) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_57;
            }
            v10 = (char *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case 2:
$LN4_57:
      result = AT_INT;
      break;
    case 3:
      result = AT_FLOAT;
      break;
    case 4:
      result = AT_VOID;
      break;
    case 6:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00526920
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned __int8 *i; // esi
  int v7; // eax
  int v8; // edi
  const char *v9; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v16; // eax
  int v17; // eax
  _DWORD v19[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v20; // [esp+Ch] [ebp-Ch]
  _DWORD *v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]
  CDmAttribute *v23; // [esp+24h] [ebp+Ch]

  v20 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v19;
  v21 = v19;
  v5 = 0;
  for ( i = CVTFTexture::ImageData(this: (CVTFTexture *)pElement); i != nullptr; i = *(unsigned __int8 **)i )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)i) && (i[16] & 0x40) == 0 )
      v19[v5++] = i;
  }
  v7 = v5 - 1;
  v22 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = v4[v7];
      v9 = *(const char **)(v8 + 20);
      v23 = (CDmAttribute *)v8;
      if ( v9 == (const char *)-1 )
        v9 = defaultValue;
      v10 = v9;
      if ( _V_stricmp(s1: v9, s2: "_name") == 0 )
        v10 = "name";
      v11 = *(_BYTE *)(v8 + 16) & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              ++buf->m_Put;
              CUtlBuffer::AddNullTermination(this: buf);
            }
            goto LABEL_32;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v23, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              ++buf->m_Put;
              CUtlBuffer::AddNullTermination(this: buf);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v23, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
LABEL_32:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v16 = buf->m_Put;
              if ( v16 != 0 && buf->m_Memory.m_pMemory[v16 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              ++buf->m_Put;
              CUtlBuffer::AddNullTermination(this: buf);
            }
            break;
        }
        if ( (buf->m_Flags & 1) != 0 )
        {
          v17 = buf->m_Put;
          if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
            CUtlBuffer::PutTabs(this: buf);
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          ++buf->m_Put;
          CUtlBuffer::AddNullTermination(this: buf);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v20, buf, pSubKeys: v23);
      }
      if ( --v22 < 0 )
        break;
      v7 = v22;
      v4 = v21;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00526BC0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetName(CDmSerializerKeyValues *this)
{
  return "keyvalues";
}

//------------------------------------------------------------------------------
// Address: 0x00526BD0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x00526BE0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetImportedFormat(CDmSerializerKeyValues *this)
{
  return "dmx";
}

//------------------------------------------------------------------------------
// Address: 0x00526BF0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebp
  void *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmAttribute *v10; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+20h] [ebp+8h]

  array.m_pStorage = (DmElementArray_t *)this;
  CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>(this: (CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&array.m_pAttribute);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    v10 = pSubKeys;
    m_pData = pSubKeys->m_pData;
    array.m_pAttribute = (CDmAttribute *)m_pData;
    pSubKeysa = *((CDmAttribute **)m_pData + 3);
  }
  else
  {
    m_pData = nullptr;
    v10 = nullptr;
    array.m_pAttribute = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)(*(_DWORD *)m_pData + 4 * v3));
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: (CDmSerializerKeyValues *)array.m_pStorage, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pAttribute;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00526CF0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00526D20
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  char *Name; // edi
  char *String; // ebp
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned int v12; // eax
  CUtlString pLowerName; // [esp+Ch] [ebp-44h] BYREF
  CUtlBuffer buf; // [esp+1Ch] [ebp-34h] BYREF

  Name = (char *)KeyValues::GetName(this: pKeyValues);
  String = (char *)KeyValues::GetString(this: pKeyValues, keyName: nullptr, defaultValue: defaultValue);
  CUtlString::CUtlString(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount, pString: Name);
  v6 = CUtlString::Get(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues);
  if ( v8 != AT_UNKNOWN )
  {
    v9 = CUtlString::operator char const *(this: (CUtlString *)&pLowerName.m_Storage.m_Memory.m_nAllocationCount);
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9);
    if ( Attribute != nullptr )
      v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr;
    else
      v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8);
    if ( v11 != nullptr )
    {
      if ( v8 == AT_STRING )
      {
        CDmAttribute::SetValue<char>(this: v11, pValue: String);
      }
      else
      {
        v12 = _V_strlen(str: String);
        CUtlBuffer::CUtlBuffer(
          this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount,
          pBuffer: (unsigned __int8 *)String,
          nSize: v12,
          nFlags: 9u);
        CDmAttribute::Unserialize(this: v11, buf: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount);
        CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&buf.m_Memory.m_nAllocationCount);
      }
    }
    else
    {
      _Warning(
        a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
        (const char *)pLowerName.m_Storage.m_Memory.m_nAllocationCount);
    }
    buf.m_Memory.m_pMemory = nullptr;
    if ( pLowerName.m_Storage.m_nActualLength >= 0 && pLowerName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      goto LABEL_17;
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_nAllocationCount);
    buf.m_Memory.m_pMemory = nullptr;
    if ( pLowerName.m_Storage.m_nActualLength >= 0 && pLowerName.m_Storage.m_Memory.m_nAllocationCount != 0 )
LABEL_17:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)pLowerName.m_Storage.m_Memory.m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00526ED0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  const char *v4; // esi
  CDmElement *v6; // eax

  v4 = (const char *)g_pDataModel->CreateElement(
                       this: g_pDataModel,
                       a2: pElementType,
                       a3: pElementName,
                       a4: this->m_fileid,
                       a5: nullptr);
  pElementName = v4;
  if ( v4 == (const char *)-1 )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_ElementList,
      elem: this->m_ElementList.m_Size,
      src: (vgui::TreeNode **)&pElementName);
    v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v6);
    return (int)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00526F50
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementArray_t *v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+10h] [ebp-Ch] BYREF
  CDmAttribute *v14; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+20h] [ebp+4h]
  int iNestingLevela; // [esp+24h] [ebp+8h]

  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>(this: (CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&subKeys.m_pAttribute);
  v14 = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( v14 == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          v14 = v10;
          subKeys.m_pAttribute = (CDmAttribute *)v10->m_pData;
        }
        else
        {
          v14 = nullptr;
          subKeys.m_pAttribute = nullptr;
        }
      }
      v11 = (DmElementArray_t *)CDmSerializerKeyValues::UnserializeElement(
                                  this,
                                  pKeyValues: i,
                                  iNestingLevel: iNestingLevela);
      if ( v11 != (DmElementArray_t *)-1 )
      {
        subKeys.m_pStorage = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&subKeys.m_pAttribute,
          src: (DmElementHandle_t *)&subKeys);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x00527090
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmElementArray_t *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  DmElementArray_t *m_pStorage; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int m_Size; // ebp
  int v10; // edi
  CDmElement *v11; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+10h] [ebp-Ch] BYREF
  CDmAttribute *v14; // [esp+18h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  m_pStorage = (DmElementArray_t *)g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  subkeys.m_pStorage = m_pStorage;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)m_pStorage, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
  else
    v6 = CDmElement::CreateAttribute(
           this: (CDmElement *)m_pStorage,
           pAttributeName: "subkeys",
           type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::CDmaArrayConstBase<CUtlSymbolLarge,CDmaDataExternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>(this: (CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&subkeys.m_pAttribute);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    v14 = v6;
    subkeys.m_pAttribute = (CDmAttribute *)v6->m_pData;
  }
  else
  {
    v14 = nullptr;
    subkeys.m_pAttribute = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&subkeys.m_pAttribute,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  m_Size = this->m_ElementList.m_Size;
  v10 = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v10]);
      CDmElement::EnableOnChangedCallbacks(this: v11);
      CDmElement::FinishUnserialization(this: v11);
      ++v10;
    }
    while ( v10 < m_Size );
    m_pStorage = subkeys.m_pStorage;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return m_pStorage;
}

//------------------------------------------------------------------------------
// Address: 0x005271C0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        DmElementArray_t **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  char v13; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  if ( v11 == nullptr )
    return 0;
  this->m_fileid = fileid;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 != 0 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v11);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v11);
  return v13;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0054CC80
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x0054CCB0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x0054CCD0
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_23;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: var);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_23:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0054CE80
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned __int8 *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CVTFTexture::ImageData(this: (CVTFTexture *)pElement); i != nullptr; i = *(unsigned __int8 **)i )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)i) && (i[16] & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0054D1D0
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x0054D1E0
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = var;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054D2C0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0054D2F0
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: var);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0054D470
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054D520
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x0054D650
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0054D780
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00646910
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100780B0
// Name: public: int KeyValues::GetInt(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, int keySymbol, int defaultValue)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this, keySymbol);
  if ( Key != nullptr )
    return KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x100780E0
// Name: void InstallKeyValuesSerializer(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallKeyValuesSerializer(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_DMSerializerKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10078100
// Name: private: enum DmAttributeType_t CDmSerializerKeyValues::DetermineAttributeType(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
DmAttributeType_t __thiscall CDmSerializerKeyValues::DetermineAttributeType(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  KeyValues *v2; // esi
  const char *String; // eax
  DmAttributeType_t result; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // eax
  const char *v10; // eax
  float f4; // [esp+4h] [ebp-10h] BYREF
  int i; // [esp+8h] [ebp-Ch] BYREF
  float f3; // [esp+Ch] [ebp-8h] BYREF
  float f2; // [esp+10h] [ebp-4h] BYREF

  v2 = pKeyValues;
  switch ( KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) )
  {
    case TYPE_STRING:
      String = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
      if ( sscanf(string: String, format: "%f %f %f %f", &pKeyValues, &f2, &f3, &f4) == 4 )
      {
        result = AT_VECTOR4;
      }
      else
      {
        v5 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
        if ( sscanf(string: v5, format: "%f %f %f", &pKeyValues, &f2, &f3) == 3 )
        {
          result = AT_VECTOR3;
        }
        else
        {
          v6 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
          if ( sscanf(string: v6, format: "%f %f", &pKeyValues, &f2) == 2 )
          {
            result = AT_VECTOR2;
          }
          else
          {
            i = KeyValues::GetInt(this: v2, keySymbol: 0, defaultValue: 0x7FFFFFFF);
            v7 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            if ( sscanf(string: v7, format: "%d", &i) == 1 )
            {
              v8 = (unsigned __int8 *)KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
              strchr(string: v8, chr: 0x2Eu);
              if ( v9 == 0 )
                goto $LN4_20;
            }
            v10 = KeyValues::GetString(this: v2, keyName: nullptr, defaultValue: defaultValue);
            result = sscanf(string: v10, format: "%f", &pKeyValues) != 1 ? AT_STRING : AT_FLOAT;
          }
        }
      }
      break;
    case TYPE_INT:
$LN4_20:
      result = AT_INT;
      break;
    case TYPE_FLOAT:
      result = AT_FLOAT;
      break;
    case TYPE_PTR:
      result = AT_VOID;
      break;
    case TYPE_COLOR:
      result = AT_COLOR;
      break;
    default:
      result = AT_UNKNOWN;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100782B0
// Name: private: bool CDmSerializerKeyValues::SerializeAttributes(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::SerializeAttributes(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmElement *pElement)
{
  void *v3; // esp
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned __int8 *i; // esi
  int v7; // eax
  CDmAttribute *v8; // edi
  const char *m_pAsString; // eax
  const char *v10; // ebx
  DmAttributeType_t v11; // edi
  const char *v12; // eax
  int m_Put; // eax
  int v14; // eax
  int v15; // eax
  int v17; // eax
  unsigned __int8 m_Flags; // cl
  int v19; // eax
  int v20; // eax
  int j; // edi
  _DWORD v23[3]; // [esp+0h] [ebp-18h] BYREF
  CDmSerializerKeyValues *v24; // [esp+Ch] [ebp-Ch]
  _DWORD *v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]
  CDmAttribute *v27; // [esp+24h] [ebp+Ch]

  v24 = this;
  v3 = alloca(4 * CDmElement::AttributeCount(this: pElement));
  v4 = v23;
  v25 = v23;
  v5 = 0;
  for ( i = CVTFTexture::ImageData(this: (CVTFTexture *)pElement); i != nullptr; i = *(unsigned __int8 **)i )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)i) && (i[16] & 0x40) == 0 )
      v23[v5++] = i;
  }
  v7 = v5 - 1;
  v26 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    while ( 1 )
    {
      v8 = (CDmAttribute *)v4[v7];
      m_pAsString = v8->m_Name.u.m_pAsString;
      v27 = v8;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v10 = m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "_name") == 0 )
        v10 = "name";
      v11 = v8->m_nFlags & 0x1F;
      if ( v11 != AT_FIRST_ARRAY_TYPE || _V_stricmp(s1: v10, s2: "subkeys") != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" ", v10);
        switch ( v11 )
        {
          case AT_FIRST_VALUE_TYPE:
          case AT_VOID:
          case AT_FIRST_ARRAY_TYPE:
          case AT_STRING_ARRAY:
          case AT_VOID_ARRAY:
            v12 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v11);
            _Warning(a1: "KeyValues: Can't serialize attribute of type %s into KeyValues files!\n", v12);
            if ( (buf->m_Flags & 1) != 0 )
            {
              m_Put = buf->m_Put;
              if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            if ( (buf->m_Flags & 1) != 0 )
            {
              v14 = buf->m_Put;
              if ( v14 != 0 && buf->m_Memory.m_pMemory[v14 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              goto LABEL_43;
            break;
          case AT_INT:
          case AT_FLOAT:
          case AT_BOOL:
            CDmAttribute::Serialize(this: v27, buf);
            break;
          default:
            if ( (buf->m_Flags & 1) != 0 )
            {
              v15 = buf->m_Put;
              if ( v15 != 0 && buf->m_Memory.m_pMemory[v15 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            ++buf->m_nTab;
            CDmAttribute::Serialize(this: v27, buf);
            if ( --buf->m_nTab < 0 )
              buf->m_nTab = 0;
            if ( (buf->m_Flags & 1) != 0 )
            {
              v17 = buf->m_Put;
              if ( v17 != 0 && buf->m_Memory.m_pMemory[v17 - buf->m_nOffset - 1] == 10 )
                CUtlBuffer::PutTabs(this: buf);
            }
            if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
            {
LABEL_43:
              buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 34;
              CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
            }
            break;
        }
        m_Flags = buf->m_Flags;
        if ( (m_Flags & 1) != 0 )
        {
          v19 = buf->m_Put;
          if ( v19 != 0 && buf->m_Memory.m_pMemory[v19 - buf->m_nOffset - 1] == 10 )
          {
            v20 = (m_Flags & 0x10) != 0 ? 0 : buf->m_nTab;
            for ( j = v20 - 1; j >= 0; --j )
            {
              if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
              {
                buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 9;
                CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
              }
            }
          }
        }
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) != 0 )
        {
          buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = 10;
          CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
        }
      }
      else
      {
        CDmSerializerKeyValues::SerializeSubKeys(this: v24, buf, pSubKeys: v27);
      }
      if ( --v26 < 0 )
        break;
      v7 = v26;
      v4 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078600
// Name: public: virtual char const __near * CDmSerializerKeyValues::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmSerializerKeyValues::GetDescription(CDmSerializerKeyValues *this)
{
  return "KeyValues";
}

//------------------------------------------------------------------------------
// Address: 0x10078610
// Name: private: void CDmSerializerKeyValues::SerializeSubKeys(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::SerializeSubKeys(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        CDmAttribute *pSubKeys)
{
  int v3; // ebx
  DmElementArray_t *m_pData; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // edi
  const char *m_pAsString; // eax
  CDmSerializerKeyValues *v8; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CDmSerializerKeyValues *v11; // [esp+14h] [ebp-4h]
  CDmAttribute *pSubKeysa; // [esp+24h] [ebp+Ch]

  v11 = this;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  v3 = 0;
  if ( pSubKeys != nullptr && (pSubKeys->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = pSubKeys;
    m_pData = (DmElementArray_t *)pSubKeys->m_pData;
    array.m_pStorage = m_pData;
    pSubKeysa = (CDmAttribute *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
    pSubKeysa = nullptr;
  }
  if ( (int)pSubKeysa > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmElement::m_classType) )
      {
        m_pAsString = v6->m_Name.m_Storage.u.m_pAsString;
        if ( m_pAsString == (const char *)-1 )
          m_pAsString = defaultValue;
        CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n{\n", m_pAsString);
        v8 = v11;
        ++buf->m_nTab;
        CDmSerializerKeyValues::SerializeAttributes(this: v8, buf, pElement: v6);
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      }
      if ( ++v3 >= (int)pSubKeysa )
        break;
      m_pData = array.m_pStorage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100786F0
// Name: public: virtual bool CDmSerializerKeyValues::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmSerializerKeyValues::Serialize(CDmSerializerKeyValues *this, CUtlBuffer *outBuf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax

  if ( pRoot != nullptr )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "subkeys");
    if ( Attribute != nullptr )
      CDmSerializerKeyValues::SerializeSubKeys(this, buf: outBuf, pSubKeys: Attribute);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10078720
// Name: private: void CDmSerializerKeyValues::UnserializeAttribute(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmSerializerKeyValues::UnserializeAttribute(
        CDmSerializerKeyValues *this,
        CDmElement *pElement,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // edi
  char *v6; // eax
  const char *v7; // eax
  DmAttributeType_t v8; // edi
  const char *v9; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // esi
  unsigned __int8 *v12; // edi
  int v13; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CUtlString pLowerName; // [esp+3Ch] [ebp-10h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  pKeyValues = (KeyValues *)KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
  CUtlString::CUtlString(this: &pLowerName, pString: Name);
  v6 = CUtlString::Get(this: &pLowerName);
  _V_strlower(start: v6);
  v7 = CUtlString::operator char const *(this: &pLowerName);
  if ( _V_stricmp(s1: v7, s2: "name") == 0 )
    CUtlString::operator=(this: &pLowerName, src: "_name");
  v8 = CDmSerializerKeyValues::DetermineAttributeType(this, pKeyValues: v3);
  if ( v8 != AT_UNKNOWN
    && ((v9 = CUtlString::operator char const *(this: &pLowerName),
         (Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v9)) == nullptr)
      ? (v11 = CDmElement::CreateAttribute(this: pElement, pAttributeName: v9, type: v8))
      : (v11 = v8 == (Attribute->m_nFlags & 0x1F) ? Attribute : nullptr),
        v11 != nullptr) )
  {
    if ( v8 == AT_STRING )
    {
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyValues, a3: (const char *)pKeyValues);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pKeyValues);
    }
    else
    {
      v12 = (unsigned __int8 *)pKeyValues;
      v13 = _V_strlen(str: (const char *)pKeyValues);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v12, nSize: v13, nFlags: 9u);
      CDmAttribute::Unserialize(this: v11, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(
      a1: "Dm Unserialize: Attempted to read an attribute (\"%s\") of an inappropriate type!\n",
      (const char *)pLowerName.m_Storage.m_Memory.m_pMemory);
  }
  pLowerName.m_Storage.m_nActualLength = 0;
  if ( pLowerName.m_Storage.m_Memory.m_nGrowSize >= 0 && pLowerName.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pLowerName.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100788A0
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::CreateDmElement(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmSerializerKeyValues::CreateDmElement(
        CDmSerializerKeyValues *this,
        const char *pElementType,
        const char *pElementName)
{
  DmElementHandle_t v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  DmElementHandle_t *m_pMemory; // ecx
  int v9; // eax
  DmElementHandle_t *v10; // eax
  CDmElement *v11; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: this->m_fileid,
         a5: nullptr);
  if ( v4 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "KeyValues: Element uses unknown element type %s\n", pElementType);
    return -1;
  }
  else
  {
    m_Size = this->m_ElementList.m_Size;
    m_nAllocationCount = this->m_ElementList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_ElementList,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_ElementList.m_Size;
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    v9 = this->m_ElementList.m_Size - m_Size - 1;
    this->m_ElementList.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_ElementList.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v4;
    v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
    CDmElement::DisableOnChangedCallbacks(this: v11);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078950
// Name: private: enum DmElementHandle_t CDmSerializerKeyValues::UnserializeElement(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
DmElementHandle_t __thiscall CDmSerializerKeyValues::UnserializeElement(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues,
        int iNestingLevel)
{
  const char *Name; // esi
  const char *v6; // eax
  CDmElement *v7; // ebx
  KeyValues *i; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v10; // eax
  DmElementHandle_t v11; // eax
  CDmrElementArray<CDmElement> subKeys; // [esp+Ch] [ebp-10h] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-8h] BYREF
  CDmSerializerKeyValues *v15; // [esp+18h] [ebp-4h]
  DmElementHandle_t handle; // [esp+24h] [ebp+8h]
  int iNestingLevela; // [esp+28h] [ebp+Ch]

  v15 = this;
  Name = KeyValues::GetName(this: pKeyValues);
  v6 = g_pDataModel->GetKeyValuesElementName(this: g_pDataModel, a2: Name, a3: iNestingLevel);
  if ( v6 == nullptr )
    v6 = "DmElement";
  iNestingLevela = iNestingLevel + 1;
  handle = CDmSerializerKeyValues::CreateDmElement(this, pElementType: v6, pElementName: Name);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: handle);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subKeys);
  subKeys.m_pAttribute = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      CDmSerializerKeyValues::UnserializeAttribute(this: v15, pElement: v7, pKeyValues: i);
    }
    else
    {
      if ( subKeys.m_pAttribute == nullptr )
      {
        Attribute = CDmElement::FindAttribute(this: v7, pAttributeName: "subkeys");
        if ( Attribute != nullptr )
          v10 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
        else
          v10 = CDmElement::CreateAttribute(this: v7, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
        if ( v10 != nullptr && (v10->m_nFlags & 0x1F) == 0xF )
        {
          subKeys.m_pAttribute = v10;
          subKeys.m_pStorage = (DmElementArray_t *)v10->m_pData;
        }
        else
        {
          subKeys.m_pAttribute = nullptr;
          subKeys.m_pStorage = nullptr;
        }
      }
      v11 = CDmSerializerKeyValues::UnserializeElement(this: v15, pKeyValues: i, iNestingLevel: iNestingLevela);
      if ( v11 != DMELEMENT_HANDLE_INVALID )
      {
        src = v11;
        CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
          this: &subKeys,
          &src);
      }
    }
  }
  return handle;
}

//------------------------------------------------------------------------------
// Address: 0x10078A80
// Name: private: class CDmElement __near * CDmSerializerKeyValues::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmSerializerKeyValues::UnserializeFromKeyValues(
        CDmSerializerKeyValues *this,
        KeyValues *pKeyValues)
{
  DmElementHandle_t DmElement; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  KeyValues *i; // edi
  KeyValues *v8; // eax
  int v9; // edi
  CDmElement *v10; // ebx
  CDmrElementArray<CDmElement> subkeys; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h]

  this->m_ElementList.m_Size = 0;
  DmElement = CDmSerializerKeyValues::CreateDmElement(this, pElementType: "DmElement", pElementName: "root");
  this->m_hRoot = DmElement;
  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: DmElement);
  pRoot = v4;
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "subkeys");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "subkeys", type: AT_FIRST_ARRAY_TYPE);
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&subkeys);
  if ( v6 != nullptr && (v6->m_nFlags & 0x1F) == 0xF )
  {
    subkeys.m_pAttribute = v6;
    subkeys.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    subkeys.m_pAttribute = nullptr;
    subkeys.m_pStorage = nullptr;
  }
  for ( i = pKeyValues; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    v8 = (KeyValues *)CDmSerializerKeyValues::UnserializeElement(this, pKeyValues: i, iNestingLevel: 0);
    if ( v8 != (KeyValues *)-1 )
    {
      pKeyValues = v8;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &subkeys,
        src: (DmElementHandle_t *)&pKeyValues);
    }
  }
  v9 = 0;
  pKeyValues = (KeyValues *)this->m_ElementList.m_Size;
  if ( (int)pKeyValues > 0 )
  {
    do
    {
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_ElementList.m_Memory.m_pMemory[v9]);
      CDmElement::EnableOnChangedCallbacks(this: v10);
      CDmElement::FinishUnserialization(this: v10);
      ++v9;
    }
    while ( v9 < (int)pKeyValues );
    v4 = pRoot;
  }
  CDmElementFramework::RemoveCleanElementsFromDirtyList(this: g_pDmElementFrameworkImp);
  this->m_ElementList.m_Size = 0;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10078BB0
// Name: public: virtual bool CDmSerializerKeyValues::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmSerializerKeyValues::Unserialize(
        CDmSerializerKeyValues *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  bool v14; // bl

  *ppRoot = nullptr;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "keyvalues file");
  v12 = v11;
  if ( v11 == nullptr )
    return false;
  this->m_fileid = fileid;
  v14 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "keyvalues file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v14 )
    *ppRoot = CDmSerializerKeyValues::UnserializeFromKeyValues(this, pKeyValues: v12);
  this->m_fileid = DMFILEID_INVALID;
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10098DA0
// Name: public: int KeyValues::GetInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall KeyValues::GetInt(KeyValues *this, const char *keyName, int defaultValue)
{
  KeyValues *Key; // eax
  int result; // eax

  Key = KeyValues::FindKey(this, keyName, bCreate: false);
  if ( Key == nullptr )
    return defaultValue;
  switch ( Key->m_iDataType )
  {
    case 1:
      result = atoi(nptr: Key->m_sValue);
      break;
    case 3:
      result = (int)Key->m_flValue;
      break;
    case 5:
      result = _wtoi(nptr: Key->m_wsValue);
      break;
    case 7:
      result = 0;
      break;
    default:
      result = Key->m_iValue;
      break;
  }
  return result;
}

} // namespace vtex_dll
