// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importkeyvaluebase.cpp
// Functions: 14
// ============================================================

#include "dmserializers\importkeyvaluebase.h"

//------------------------------------------------------------------------------
// Address: 0x0045D100
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D160
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x0045D1F0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D280
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D310
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D3A0
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: &defaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045D440
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D490
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D4E0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D530
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = &defaultValue;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D5B0
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D600
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D650
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D6B0
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00472AE0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472B40
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x00472BD0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472C60
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472CF0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472D80
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: var);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00472E20
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472E70
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472EC0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472F10
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = var;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472F90
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472FE0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  const int *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473030
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00473090
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AF5F0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF650
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004AF6E0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF770
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (const int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF800
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF890
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AF930
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF980
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AF9D0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AFA20
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = defaultValue;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFAA0
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFAF0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFB40
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AFBA0
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104BF430
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BF490
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  char v13; // bl

  *ppRoot = nullptr;
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return 0;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 != 0 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x104BF520
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BF5B0
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = (char *)Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BF640
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        const char **pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *(float *)pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BF6D0
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: &var);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BF770
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BF7C0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             (const char **)pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BF810
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BF860
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = &var;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BF8E0
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BF930
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BF980
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BF9E0
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004958A0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: -1,
         a5: pId);
  if ( v5 != -1 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495900
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
                                      a1: g_pDataModel.u,
                                      a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x00495990
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495A20
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495AB0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495B40
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: WindowName);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pKeyName,
    a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00495BE0
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495C30
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495C80
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00495CD0
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *m_Id; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = WindowName;
      if ( !bSkipEmptryStrings || *m_Id != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", m_Id);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, m_Id);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495D50
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495DA0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495DF0
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495E50
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: v9->m_Storage.m_Handle),
                v11 = (CDmElement *)v10,
                v10 != 0)
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                     a1: g_pDataModel.u,
                     a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = (CDmElement *)v7;
              if ( v7 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                     a1: v7,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v8 = nullptr;
              }
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005194B0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00519510
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x005195A0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00519630
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005196C0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00519750
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: pDefaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005197F0
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00519840
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00519890
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005198E0
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = pDefaultValue;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00519960
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005199B0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00519A00
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00519A60
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *v2; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    v2 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElement);
    pAttribute = v2;
    if ( v2 != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = v2->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v2),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (v2->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (v2->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = v2;
            m_pData = (DmElementArray_t *)v2->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = pAttribute;
        }
        pAttribute = v2->m_pNext;
        if ( v2->m_pNext == nullptr )
          break;
        v2 = v2->m_pNext;
      }
    }
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D9AC0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: -1,
         a5: pId);
  if ( v5 != -1 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D9B20
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
                                      a1: g_pDataModel.u,
                                      a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004D9BB0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D9C40
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D9CD0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D9D60
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: pDeltaStateName);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pKeyName,
    a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D9E00
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9E50
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9EA0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9EF0
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = pDeltaStateName;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9F70
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D9FC0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DA010
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DA070
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: v9->m_Storage.m_Handle),
                v11 = (CDmElement *)v10,
                v10 != 0)
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                     a1: g_pDataModel.u,
                     a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = (CDmElement *)v7;
              if ( v7 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                     a1: v7,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v8 = nullptr;
              }
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0045EBE0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EC40
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x0045ECD0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045ED60
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (const int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EDF0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EE80
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EF20
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EF70
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EFC0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045F010
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = defaultValue;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F090
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F0E0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F130
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F190
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004606D0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460730
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  char v13; // bl

  *ppRoot = nullptr;
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return 0;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 != 0 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004607C0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460850
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = (char *)Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004608E0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460970
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: str);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460A10
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460A60
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460AB0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00460B00
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = str;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460B80
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460BD0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460C20
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  float *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = (float *)CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460C80
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x004691E0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00469240
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x20u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  v12 = v11;
  if ( v11 == nullptr )
    return 0;
  v14 = KeyValues::LoadFromBuffer(this: v11, resourceName: "dmx file", buf, pFileSystem: nullptr, pPathID: nullptr);
  if ( v14 != 0 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v12);
  KeyValues::deleteThis(this: v12);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x004692D0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<bool>(char const __near *,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<bool>(CDmElement *this, const char *pAttributeName, bool *value)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 4 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_BOOL);
  if ( v5 == nullptr )
    return nullptr;
  CDmAttribute::SetValue<bool>(this: v5, value);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00469330
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        bool *pDefault)
{
  const char *v5; // esi
  KeyValues *Key; // eax

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    LOBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    LOBYTE(pKeyName) = *pDefault;
  }
  return CDmElement::SetValue<bool>(this: pElement, pAttributeName: v5, value: (bool *)&pKeyName) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00469390
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        int *pDefault)
{
  const char *v5; // esi
  KeyValues *Key; // eax
  const char *Int; // eax

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = (char *)Int;
  return CDmElement::SetValue<int>(this: pElement, pAttributeName: v5, value: (int *)&pKeyName) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004693E0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // esi
  KeyValues *Key; // eax
  double Float; // st7

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    Float = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Float = *pDefault;
  }
  pKeyName = Float;
  return CDmElement::SetValue<float>(this: pElement, pAttributeName: v5, value: &pKeyName) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00469440
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        int nFlags,
        int *pDefault)
{
  const char *v6; // esi
  KeyValues *Key; // eax
  const char *Int; // eax
  bool result; // al
  CDmAttribute *Attribute; // eax

  v6 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValue, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
    goto LABEL_5;
  }
  if ( pDefault != nullptr )
  {
    Int = (const char *)*pDefault;
LABEL_5:
    pKeyName = (char *)Int;
    result = CDmElement::SetValue<int>(this: pElement, pAttributeName: v6, value: (int *)&pKeyName) != nullptr;
    if ( !result )
      return result;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v6);
  Attribute->m_nFlags |= nFlags;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x004694B0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        int nFlags,
        float *pDefault)
{
  const char *v6; // esi
  KeyValues *Key; // eax
  double Float; // st7
  bool result; // al
  CDmAttribute *Attribute; // eax

  v6 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValue, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Float = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
    goto LABEL_5;
  }
  if ( pDefault != nullptr )
  {
    Float = *pDefault;
LABEL_5:
    *(float *)&pKeyName = Float;
    result = CDmElement::SetValue<float>(this: pElement, pAttributeName: v6, value: (const float *)&pKeyName) != nullptr;
    if ( !result )
      return result;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v6);
  Attribute->m_nFlags |= nFlags;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00469520
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *m_pData; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
      }
      if ( (Attribute->m_nFlags & 0x1F) == 4 )
        m_pData = (CDmaVar<bool> *)Attribute->m_pData;
      else
        m_pData = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, m_pData->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004695A0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *m_pData; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (Attribute->m_nFlags & 0x1F) == 2 )
        m_pData = (CDmaVar<int> *)Attribute->m_pData;
      else
        m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, m_pData->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469630
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  double m_Storage; // st7

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      m_Storage = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469690
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        const char *pDefault)
{
  KeyValues *Key; // eax
  const char *String; // eax

  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
    return CDmElement::SetValue<char const>(this: pElement, pAttributeName: pKeyName, pValue: String) != nullptr;
  }
  String = pDefault;
  if ( pDefault != nullptr )
    return CDmElement::SetValue<char const>(this: pElement, pAttributeName: pKeyName, pValue: String) != nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004696E0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        int nFlags,
        const char *pDefault)
{
  KeyValues *Key; // eax
  const char *String; // eax
  bool result; // al
  CDmAttribute *Attribute; // eax

  Key = KeyValues::FindKey(this: pKeyValue, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
    goto LABEL_4;
  }
  String = pDefault;
  if ( pDefault != nullptr )
  {
LABEL_4:
    result = CDmElement::SetValue<char const>(this: pElement, pAttributeName: pKeyName, pValue: String) != nullptr;
    if ( !result )
      return result;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
  Attribute->m_nFlags |= nFlags;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00469740
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmElement *pElement)
{
  KeyValues *i; // ebp
  CDmAttribute *m_sValue; // eax
  int m_nFlags; // ebx
  int v5; // edi
  CDmElement *v6; // esi
  CDmaVar<enum DmElementHandle_t> *v7; // eax
  CDmElement *v8; // esi
  CDmrElementArray<CDmElement> array; // [esp+8h] [ebp-Ch] BYREF
  KeyValues *v10; // [esp+10h] [ebp-4h]

  array.m_pStorage = (DmElementArray_t *)this;
  if ( pElement != nullptr )
  {
    pElement->Resolve(this: pElement);
    for ( i = KeyValues::GetFirstSubKey(this: (KeyValues *)pElement); i != nullptr; i = (KeyValues *)i->m_iKeyName )
    {
      if ( (i->m_iValue & 0x1F) == 1 )
      {
        v7 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: (CDmAttribute *)i);
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7->m_Storage.m_Handle);
        if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType.m_Id) )
          v8 = nullptr;
        CImportKeyValueBase::RecursivelyResolveElement(this: (CImportKeyValueBase *)array.m_pStorage, pElement: v8);
      }
      else if ( (i->m_iValue & 0x1F) == 0xF )
      {
        CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
        if ( (i->m_Color[0] & 0x1F) == 0xF )
        {
          v10 = i;
          m_sValue = (CDmAttribute *)i->m_sValue;
        }
        else
        {
          v10 = nullptr;
          m_sValue = nullptr;
        }
        array.m_pAttribute = m_sValue;
        m_nFlags = m_sValue->m_nFlags;
        v5 = 0;
        if ( m_nFlags > 0 )
        {
          while ( 1 )
          {
            v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&m_sValue->m_pNext->m_pNext + v5));
            if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmElement::m_classType.m_Id) )
              v6 = nullptr;
            CImportKeyValueBase::RecursivelyResolveElement(this: (CImportKeyValueBase *)array.m_pStorage, pElement: v6);
            if ( ++v5 >= m_nFlags )
              break;
            m_sValue = array.m_pAttribute;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469860
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<CUtlString> *v7; // eax
  const char *v8; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = CDmAttribute::GetValue<CUtlString>(this: Attribute);
      v8 = CUtlString::operator char const *(this: &v7->m_Storage);
      if ( !bSkipEmptryStrings || *v8 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v8);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004698DC
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  unsigned int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter(a1: 0, a2: (unsigned int)string, a3: v14);
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(a1: (unsigned int)string, _Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00469A5D
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469A8F
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall strlwr@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char *string)
{
  char *result; // eax
  char *i; // edx
  char v5; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v5 = *i;
        if ( *i >= 65 && v5 <= 90 )
          *i = v5 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: a2);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469B00
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CPCFFixApp_vtbl *)&CPCFFixApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x00469B30
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x00469B50
// Name: _dynamic_initializer_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataModel__()
{
  CDataModel::CDataModel(this: &g_DataModel);
  return atexit(func: dynamic_atexit_destructor_for__g_DataModel__);
}

//------------------------------------------------------------------------------
// Address: 0x00469B70
// Name: _dynamic_initializer_for__g_CDmElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmElement_Helper,
           classname: "DmElement",
           pFactory: &g_CDmElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00469B90
// Name: _dynamic_initializer_for__g_CDmeElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElement_Helper,
           classname: "DmeElement",
           pFactory: &g_CDmeElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00469BB0
// Name: _dynamic_initializer_for__g_DataAlloc4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc4__()
{
  CMemoryPool::CMemoryPool(
    this: &g_DataAlloc4,
    blockSize: 0x18u,
    numElements: 4,
    growMode: 2,
    pszAllocOwner: "4-byte data pool");
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc4__);
}

//------------------------------------------------------------------------------
// Address: 0x00469BE0
// Name: _dynamic_initializer_for__g_DataAlloc8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataAlloc8__()
{
  CMemoryPool::CMemoryPool(
    this: &g_DataAlloc8,
    blockSize: 0x18u,
    numElements: 8,
    growMode: 2,
    pszAllocOwner: "8-byte data pool");
  return atexit(func: dynamic_atexit_destructor_for__g_DataAlloc8__);
}

//------------------------------------------------------------------------------
// Address: 0x00469C10
// Name: _dynamic_initializer_for__g_AttrAlloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrAlloc__()
{
  CMemoryPool::CMemoryPool(
    this: &g_AttrAlloc,
    blockSize: 0x18u,
    numElements: 32,
    growMode: 2,
    pszAllocOwner: "CDmAttribute pool");
  return atexit(func: dynamic_atexit_destructor_for__g_AttrAlloc__);
}

//------------------------------------------------------------------------------
// Address: 0x00469C40
// Name: _dynamic_initializer_for____s_AttrDmUnknownAttribute_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmUnknownAttribute_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<DmUnknownAttribute_t>::`vftable';
    s_pAttrInfo[0] = result;
  }
  else
  {
    s_pAttrInfo[0] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469C70
// Name: _dynamic_initializer_for____s_Attrint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<int>::`vftable';
    s_pAttrInfo[2] = result;
  }
  else
  {
    s_pAttrInfo[2] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469CA0
// Name: _dynamic_initializer_for____s_AttrArrayint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayint__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<int>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[16] = result;
  }
  else
  {
    s_pAttrInfo[16] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469CD0
// Name: _dynamic_initializer_for____s_Attrfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<float>::`vftable';
    s_pAttrInfo[3] = result;
  }
  else
  {
    s_pAttrInfo[3] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469D00
// Name: _dynamic_initializer_for____s_AttrArrayfloat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayfloat__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<float>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[17] = result;
  }
  else
  {
    s_pAttrInfo[17] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469D30
// Name: _dynamic_initializer_for____s_Attrbool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_Attrbool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<bool>::`vftable';
    s_pAttrInfo[4] = result;
  }
  else
  {
    s_pAttrInfo[4] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469D60
// Name: _dynamic_initializer_for____s_AttrArraybool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArraybool__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<bool>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[18] = result;
  }
  else
  {
    s_pAttrInfo[18] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469D90
// Name: _dynamic_initializer_for____s_AttrColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Color>::`vftable';
    s_pAttrInfo[8] = result;
  }
  else
  {
    s_pAttrInfo[8] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469DC0
// Name: _dynamic_initializer_for____s_AttrArrayColor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayColor__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Color>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[22] = result;
  }
  else
  {
    s_pAttrInfo[22] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469DF0
// Name: _dynamic_initializer_for____s_AttrVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector2D>::`vftable';
    s_pAttrInfo[9] = result;
  }
  else
  {
    s_pAttrInfo[9] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469E20
// Name: _dynamic_initializer_for____s_AttrArrayVector2D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector2D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector2D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[23] = result;
  }
  else
  {
    s_pAttrInfo[23] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469E50
// Name: _dynamic_initializer_for____s_AttrVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector>::`vftable';
    s_pAttrInfo[10] = result;
  }
  else
  {
    s_pAttrInfo[10] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469E80
// Name: _dynamic_initializer_for____s_AttrArrayVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[24] = result;
  }
  else
  {
    s_pAttrInfo[24] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469EB0
// Name: _dynamic_initializer_for____s_AttrVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Vector4D>::`vftable';
    s_pAttrInfo[11] = result;
  }
  else
  {
    s_pAttrInfo[11] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469EE0
// Name: _dynamic_initializer_for____s_AttrArrayVector4D__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVector4D__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Vector4D>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[25] = result;
  }
  else
  {
    s_pAttrInfo[25] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469F10
// Name: _dynamic_initializer_for____s_AttrQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<QAngle>::`vftable';
    s_pAttrInfo[12] = result;
  }
  else
  {
    s_pAttrInfo[12] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469F40
// Name: _dynamic_initializer_for____s_AttrArrayQAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQAngle__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<QAngle>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[26] = result;
  }
  else
  {
    s_pAttrInfo[26] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469F70
// Name: _dynamic_initializer_for____s_AttrQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<Quaternion>::`vftable';
    s_pAttrInfo[13] = result;
  }
  else
  {
    s_pAttrInfo[13] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469FA0
// Name: _dynamic_initializer_for____s_AttrArrayQuaternion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayQuaternion__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<Quaternion>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[27] = result;
  }
  else
  {
    s_pAttrInfo[27] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469FD0
// Name: _dynamic_initializer_for____s_AttrVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<VMatrix>::`vftable';
    s_pAttrInfo[14] = result;
  }
  else
  {
    s_pAttrInfo[14] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A000
// Name: _dynamic_initializer_for____s_AttrArrayVMatrix__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayVMatrix__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<VMatrix>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[28] = result;
  }
  else
  {
    s_pAttrInfo[28] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A030
// Name: _dynamic_initializer_for____s_AttrCUtlString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlString__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlString>::`vftable';
    s_pAttrInfo[5] = result;
  }
  else
  {
    s_pAttrInfo[5] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A060
// Name: _dynamic_initializer_for____s_AttrArrayCUtlString__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlString__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlString>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[19] = result;
  }
  else
  {
    s_pAttrInfo[19] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A090
// Name: _dynamic_initializer_for____s_AttrCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<CUtlBinaryBlock>::`vftable';
    s_pAttrInfo[6] = result;
  }
  else
  {
    s_pAttrInfo[6] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A0C0
// Name: _dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayCUtlBinaryBlock__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<CUtlBinaryBlock>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[20] = result;
  }
  else
  {
    s_pAttrInfo[20] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A0F0
// Name: _dynamic_initializer_for____s_AttrDmObjectId_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmObjectId_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<UniqueId_t>::`vftable';
    s_pAttrInfo[7] = result;
  }
  else
  {
    s_pAttrInfo[7] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A120
// Name: _dynamic_initializer_for____s_AttrArrayDmObjectId_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmObjectId_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<UniqueId_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[21] = result;
  }
  else
  {
    s_pAttrInfo[21] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A150
// Name: _dynamic_initializer_for____s_AttrDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 4u);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmAttributeOp<enum DmElementHandle_t>::`vftable';
    s_pAttrInfo[1] = result;
  }
  else
  {
    s_pAttrInfo[1] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046A180
// Name: _dynamic_initializer_for____s_AttrArrayDmElementHandle_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IDmAttributeOp *dynamic_initializer_for____s_AttrArrayDmElementHandle_t__()
{
  IDmAttributeOp *result; // eax

  result = (IDmAttributeOp *)operator new(nSize: 0xCu);
  if ( result != nullptr )
  {
    result->__vftable = (IDmAttributeOp_vtbl *)&CDmArrayAttributeOp<enum DmElementHandle_t>::`vftable';
    result[1].__vftable = nullptr;
    result[2].__vftable = nullptr;
    s_pAttrInfo[15] = result;
  }
  else
  {
    s_pAttrInfo[15] = nullptr;
  }
  return result;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0045EB60
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EBC0
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x0045EC50
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045ECE0
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045ED70
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EE00
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: &defaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045EEA0
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EEF0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EF40
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EFA0
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = &defaultValue;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F020
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F070
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F0C0
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  float *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = (float *)CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F120
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00463AD0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463B30
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x00463BC0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463C50
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463CE0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463D70
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: &pParentName);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463E10
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463E60
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463EB0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463F00
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *m_Id; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = &pParentName;
      if ( !bSkipEmptryStrings || *m_Id != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", m_Id);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, m_Id);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463F80
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00463FD0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464020
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464080
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B9C40
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: -1,
         a5: pId);
  if ( v5 != -1 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9CA0
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
                                      a1: g_pDataModel.u,
                                      a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004B9D30
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9DC0
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (const int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9E50
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9EE0
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pKeyName,
    a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B9F80
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9FD0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BA020
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BA070
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *m_Id; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = defaultValue;
      if ( !bSkipEmptryStrings || *m_Id != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", m_Id);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, m_Id);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA0F0
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA140
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA190
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  float *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = (float *)CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA1F0
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: v9->m_Storage.m_Handle),
                v11 = (CDmElement *)v10,
                v10 != 0)
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                     a1: g_pDataModel.u,
                     a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = (CDmElement *)v7;
              if ( v7 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                     a1: v7,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v8 = nullptr;
              }
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x004646A0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v4; // eax

  v4 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v4 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v4);
  _Warning(a1: "%s: Element uses unknown element type %s\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00464700
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x00464790
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00464820
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004648B0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00464940
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: &pch);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004649E0
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00464A30
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00464A80
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00464AD0
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *m_Id; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = &pch;
      if ( !bSkipEmptryStrings || *m_Id != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", m_Id);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, m_Id);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464B50
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464BA0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  const int *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464BF0
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  float *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = (float *)CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464C50
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D3050
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  int v5; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pElementName,
         a4: -1,
         a5: pId);
  if ( v5 != -1 )
    return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D30B0
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  char v13; // bl

  *ppRoot = nullptr;
  this->m_pFileName = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 364))(
                                      a1: g_pDataModel.u,
                                      a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return 0;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 != 0 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x004D3140
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D31D0
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = (char *)Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D3260
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D32F0
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: pDeltaStateName);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char **, char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &pKeyName,
    a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004D3390
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D33E0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3430
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D3480
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = pDeltaStateName;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3500
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3550
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D35A0
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D3600
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  int v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  int v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: v9->m_Storage.m_Handle),
                v11 = (CDmElement *)v10,
                v10 != 0)
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
                 a1: v10,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                     a1: g_pDataModel.u,
                     a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = (CDmElement *)v7;
              if ( v7 == 0
                || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                     a1: v7,
                     a2: CDmElement::m_classType.u) == 0 )
              {
                v8 = nullptr;
              }
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0046EF20
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046EF80
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  char v13; // bl

  *ppRoot = nullptr;
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return 0;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return 0;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 != 0 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x0046F010
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F0A0
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = (char *)Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (const int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F130
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F1C0
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        char *pKeyName,
        char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: Ptr);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046F260
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F2B0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F300
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        char *pKeyName,
        __int16 nFlags,
        char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F350
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *m_Id; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = Ptr;
      if ( !bSkipEmptryStrings || *m_Id != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", m_Id);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, m_Id);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F3D0
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F420
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F470
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  float *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = (float *)CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F4D0
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *Attribute; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    Attribute = CDmElement::FirstAttribute(this: (CDmElement *)pElement);
    pAttribute = Attribute;
    if ( Attribute != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = Attribute->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (Attribute->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (Attribute->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = Attribute;
            m_pData = (DmElementArray_t *)Attribute->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          Attribute = pAttribute;
        }
        pAttribute = Attribute->m_pNext;
        if ( Attribute->m_pNext == nullptr )
          break;
        Attribute = Attribute->m_pNext;
      }
    }
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005667D0
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00566830
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x005668C0
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00566950
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005669E0
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00566A70
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: var);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00566B10
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00566B60
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00566BB0
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00566C00
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *v7; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      v7 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
      if ( v7 == (const char *)-1 )
        v7 = var;
      if ( !bSkipEmptryStrings || *v7 != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", v7);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566C80
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  unsigned __int8 *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = (unsigned __int8 *)CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566CD0
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  const int *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, *v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566D20
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566D80
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *v2; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    v2 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElement);
    pAttribute = v2;
    if ( v2 != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = v2->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v2),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (v2->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (v2->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = v2;
            m_pData = (DmElementArray_t *)v2->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = pAttribute;
        }
        pAttribute = v2->m_pNext;
        if ( v2->m_pNext == nullptr )
          break;
        v2 = v2->m_pNext;
      }
    }
  }
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10091620
// Name: protected: class CDmElement __near * CImportKeyValueBase::CreateDmElement(char const __near *,char const __near *,struct UniqueId_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportKeyValueBase::CreateDmElement(
        CImportKeyValueBase *this,
        const char *pElementType,
        const char *pElementName,
        UniqueId_t *pId)
{
  DmElementHandle_t v5; // eax

  v5 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pElementType,
         a3: pElementName,
         a4: DMFILEID_INVALID,
         a5: pId);
  if ( v5 != DMELEMENT_HANDLE_INVALID )
    return g_pDataModel->GetElement(this: g_pDataModel, a2: v5);
  _Warning(a1: "%s: Element uses unknown element type %s\n", this->m_pFileName, pElementType);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10091680
// Name: public: virtual bool CImportKeyValueBase::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::Unserialize(
        CImportKeyValueBase *this,
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
  this->m_pFileName = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 == nullptr )
    return false;
  v11 = KeyValues::KeyValues(this: v10, setName: "dmx file");
  if ( v11 == nullptr )
    return false;
  v13 = KeyValues::LoadFromBuffer(
          this: v11,
          resourceName: "dmx file",
          buf,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr);
  if ( v13 )
    *ppRoot = this->UnserializeFromKeyValues(this, a2: v11);
  KeyValues::deleteThis(this: v11);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x10091710
// Name: protected: bool CImportKeyValueBase::AddBoolAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        bool *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    HIBYTE(pKeyName) = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    HIBYTE(pKeyName) = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_BOOL);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pKeyName + 3);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100917A0
// Name: protected: bool CImportKeyValueBase::AddIntAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        int *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  const char *Int; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    Int = (const char *)KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    Int = (const char *)*pDefault;
  }
  pKeyName = Int;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_INT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value: (int *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10091830
// Name: protected: bool CImportKeyValueBase::AddFloatAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        float pKeyName,
        float *pDefault)
{
  const char *v5; // edi
  KeyValues *Key; // eax
  CDmAttribute *Attribute; // esi

  v5 = (const char *)LODWORD(pKeyName);
  Key = KeyValues::FindKey(this: pKeyValues, keyName: (const char *)LODWORD(pKeyName), bCreate: false);
  if ( Key != nullptr )
  {
    pKeyName = KeyValues::GetFloat(this: Key, keyName: nullptr, defaultValue: 0.0);
  }
  else
  {
    if ( pDefault == nullptr )
      return true;
    pKeyName = *pDefault;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value: &pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100918C0
// Name: protected: bool CImportKeyValueBase::AddStringAttribute(class CDmElement __near *,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CImportKeyValueBase::AddStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValues,
        const char *pKeyName,
        const char *pDefault)
{
  const char *v5; // ebx
  KeyValues *Key; // eax
  const char *String; // eax
  CDmAttribute *Attribute; // esi

  v5 = pKeyName;
  Key = KeyValues::FindKey(this: pKeyValues, keyName: pKeyName, bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
  }
  else
  {
    String = pDefault;
    if ( pDefault == nullptr )
      return true;
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pKeyName, a3: String);
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: v5);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return false;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pKeyName);
  return Attribute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10091960
// Name: protected: bool CImportKeyValueBase::AddIntAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddIntAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        int *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddIntAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100919B0
// Name: protected: bool CImportKeyValueBase::AddFloatAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddFloatAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        float *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddFloatAttribute(
             this,
             pElement,
             pKeyValues: pKeyValue,
             pKeyName: *(float *)&pKeyName,
             pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10091A00
// Name: protected: bool CImportKeyValueBase::AddStringAttributeFlags(class CDmElement __near *,class KeyValues __near *,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportKeyValueBase::AddStringAttributeFlags(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        KeyValues *pKeyValue,
        const char *pKeyName,
        __int16 nFlags,
        const char *pDefault)
{
  bool result; // al
  CDmAttribute *Attribute; // eax

  result = CImportKeyValueBase::AddStringAttribute(this, pElement, pKeyValues: pKeyValue, pKeyName, pDefault);
  if ( result )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    Attribute->m_nFlags |= nFlags & 0xFFE0;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10091A50
// Name: protected: void CImportKeyValueBase::PrintStringAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintStringAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName,
        bool bSkipEmptryStrings,
        bool bPrintValueOnly)
{
  CDmAttribute *Attribute; // eax
  const char *m_Id; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 5 )
    {
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = defaultValue;
      if ( !bSkipEmptryStrings || *m_Id != 0 )
      {
        if ( bPrintValueOnly )
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\"\n", m_Id);
        else
          CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%s\"\n", pKeyName, m_Id);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091AD0
// Name: protected: void CImportKeyValueBase::PrintBoolAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintBoolAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<bool> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 4 )
    {
      v5 = CDmAttribute::GetValue<bool>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091B20
// Name: protected: void CImportKeyValueBase::PrintIntAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintIntAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<int> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 2 )
    {
      v5 = CDmAttribute::GetValue<int>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%d\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091B70
// Name: protected: void CImportKeyValueBase::PrintFloatAttribute(class CDmElement __near *,class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::PrintFloatAttribute(
        CImportKeyValueBase *this,
        CDmElement *pElement,
        CUtlBuffer *outBuf,
        const char *pKeyName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v5; // eax

  if ( CDmElement::HasAttribute(this: pElement, pAttributeName: pKeyName, type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pKeyName);
    if ( (Attribute->m_nFlags & 0x1F) == 3 )
    {
      v5 = CDmAttribute::GetValue<float>(this: Attribute);
      CUtlBuffer::Printf(this: outBuf, pFmt: "\"%s\" \"%.10f\"\n", pKeyName, v5->m_Storage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091BD0
// Name: protected: void CImportKeyValueBase::RecursivelyResolveElement(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportKeyValueBase::RecursivelyResolveElement(CImportKeyValueBase *this, CDmAttribute *pElement)
{
  CDmAttribute *v2; // edi
  unsigned __int16 m_nFlags; // cx
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v6; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmaVar<enum DmElementHandle_t> *v9; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v13; // [esp+14h] [ebp-4h]
  CDmAttribute *pAttribute; // [esp+20h] [ebp+8h]

  v13 = this;
  if ( pElement != nullptr )
  {
    ((void (__thiscall *)(CDmAttribute *))pElement->m_pNext->m_Handle)(a1: pElement);
    v2 = (CDmAttribute *)CVTFTexture::ImageData(this: (CVTFTexture *)pElement);
    pAttribute = v2;
    if ( v2 != nullptr )
    {
      while ( 1 )
      {
        m_nFlags = v2->m_nFlags;
        if ( (m_nFlags & 0x1F) == 1 )
        {
          if ( (m_nFlags & 0x1F) == 1
            && (v9 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v2),
                v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: v9->m_Storage.m_Handle),
                v11 = v10,
                v10 != nullptr)
            && v10->IsA(this: v10, a2: CDmElement::m_classType) )
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v11);
          }
          else
          {
            CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: nullptr);
          }
        }
        else if ( (v2->m_nFlags & 0x1F) == 0xF )
        {
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
          if ( (v2->m_nFlags & 0x1F) == 0xF )
          {
            array.m_pAttribute = v2;
            m_pData = (DmElementArray_t *)v2->m_pData;
            array.m_pStorage = m_pData;
            m_Size = m_pData->m_Size;
          }
          else
          {
            m_pData = nullptr;
            array.m_pAttribute = nullptr;
            array.m_pStorage = nullptr;
            m_Size = 0;
          }
          v6 = 0;
          if ( m_Size > 0 )
          {
            while ( 1 )
            {
              v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v6]);
              v8 = v7;
              if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
                v8 = nullptr;
              CImportKeyValueBase::RecursivelyResolveElement(this: v13, pElement: v8);
              if ( ++v6 >= m_Size )
                break;
              m_pData = array.m_pStorage;
            }
          }
          v2 = pAttribute;
        }
        pAttribute = v2->m_pNext;
        if ( v2->m_pNext == nullptr )
          break;
        v2 = v2->m_pNext;
      }
    }
  }
}

} // namespace vtex_dll
