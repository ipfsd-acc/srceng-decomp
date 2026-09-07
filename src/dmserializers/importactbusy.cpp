// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importactbusy.cpp
// Functions: 7
// ============================================================

#include "dmserializers\importactbusy.h"

//------------------------------------------------------------------------------
// Address: 0x0045CAC0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x0045CAE0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x0045CBC0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x0045CBD0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x0045CBE0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045CDD0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CDmElement::GetHandle(this: DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045CF50
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x004724A0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004724C0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x004725A0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004725B0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004725C0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004727B0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: var);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00472930
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AEFA0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004AEFD0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x004AF0B0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004AF0C0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004AF0D0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF2C0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AF440
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104BEDF0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x104BEE10
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x104BEEF0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x104BEF00
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x104BEF10
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BF100
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: &var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: &var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: &var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: &var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: &var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: &var);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BF280
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00495260
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x00495280
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00495360
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x00495370
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x00495380
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  int v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = (CDmElement *)v8;
      if ( v8 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v9 = nullptr;
      }
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00495570
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: WindowName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: WindowName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: WindowName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: WindowName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: WindowName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: WindowName);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CDmElement::GetHandle(this: DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004956F0
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &value,
      a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00518E70
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x00518E90
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00518F70
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x00518F80
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x00518F90
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDefaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00519180
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: pDefaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: pDefaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: pDefaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: pDefaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: pDefaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: pDefaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CVTFTexture::MipCount(this: (CVTFTexture *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00519300
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D9480
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004D94A0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x004D9580
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004D9590
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004D95A0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  int v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = (CDmElement *)v8;
      if ( v8 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v9 = nullptr;
      }
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D9790
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D9910
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &value,
      a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0045E5A0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x0045E5C0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x0045E6A0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x0045E6B0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x0045E6C0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E8B0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CCodecBuffer_Block::GetBufferType(this: DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EA30
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00460090
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004600B0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00460190
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004601A0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004601B0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004603A0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: str);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: str);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: str);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: str);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: str);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: str);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460520
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00466580
// Name: __wcsdup
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall _wcsdup(CImportVMT *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00468C30
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x00468C50
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00468D30
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x00468D40
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x00468D50
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  int m_nFlags; // eax
  int v7; // ebx
  CDmElement *v8; // edi
  const char *v9; // eax
  bool v10; // sf
  CDmrElementArray<CDmElement> children; // [esp+4h] [ebp-Ch] BYREF
  int nCount; // [esp+14h] [ebp+4h]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
    this: (CDmrElementArrayConst<CDmElement> *)&children.m_pAttribute,
    pAttribute: Attribute);
  m_nFlags = children.m_pAttribute->m_nFlags;
  ++buf->m_nTab;
  v7 = 0;
  for ( nCount = m_nFlags; v7 < nCount; ++v7 )
  {
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&children.m_pAttribute->m_pNext->m_pNext + v7));
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType.m_Id) )
      v8 = nullptr;
    v9 = CUtlString::operator char const *(this: &v8->m_Name.m_Storage);
    CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", v9);
    CUtlBuffer::Printf(this: buf, pFmt: "{\n");
    ++buf->m_nTab;
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "busy_anim",
      bSkipEmptryStrings: true,
      bPrintValueOnly: false);
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "entry_anim",
      bSkipEmptryStrings: true,
      bPrintValueOnly: false);
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "exit_anim",
      bSkipEmptryStrings: true,
      bPrintValueOnly: false);
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "busy_sequence",
      bSkipEmptryStrings: true,
      bPrintValueOnly: false);
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "entry_sequence",
      bSkipEmptryStrings: true,
      bPrintValueOnly: false);
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "exit_sequence",
      bSkipEmptryStrings: true,
      bPrintValueOnly: false);
    CImportKeyValueBase::PrintFloatAttribute(this, pElement: v8, outBuf: buf, pKeyName: "min_time");
    CImportKeyValueBase::PrintFloatAttribute(this, pElement: v8, outBuf: buf, pKeyName: "max_time");
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v8,
      outBuf: buf,
      pKeyName: "interrupts",
      bSkipEmptryStrings: false,
      bPrintValueOnly: false);
    v10 = --buf->m_nTab < 0;
    if ( v10 )
      buf->m_nTab = 0;
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  }
  v10 = --buf->m_nTab < 0;
  if ( v10 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00468F20
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(CImportActBusy *this, CDmAttribute *pChildren, float pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v7; // esi
  CDmrElementArray<CDmElement> children; // [esp+8h] [ebp-Ch] BYREF
  CDmAttribute *v10; // [esp+10h] [ebp-4h]

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  v7 = DmElement;
  if ( DmElement == nullptr )
    return 0;
  CDmElement::SetValue<char const>(this: DmElement, pAttributeName: "editorType", pValue: "actBusy");
  pKeyValues = 0.0;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: &pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: &pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: v7,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&children.m_pAttribute);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    v10 = pChildren;
    children.m_pAttribute = (CDmAttribute *)pChildren->m_pData;
  }
  else
  {
    v10 = nullptr;
    children.m_pAttribute = nullptr;
  }
  pChildren = (CDmAttribute *)CDmElement::GetHandle(this: v7);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&children.m_pAttribute,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00469080
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax

  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v4 = result;
  if ( result != nullptr )
  {
    CDmElement::SetValue<char const>(this: result, pAttributeName: "editorType", pValue: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "children");
    if ( Attribute != nullptr )
      v6 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
    else
      v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this, pChildren: v6, pKeyValues: *(float *)&FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_10;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_10:
        CImportKeyValueBase::RecursivelyResolveElement(this, pElement: v4);
        return v4;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0045E520
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x0045E540
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x0045E620
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x0045E630
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x0045E640
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E830
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: &defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CDmElement::GetHandle(this: DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E9B0
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00463490
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004634B0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00463590
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004635A0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004635B0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004637A0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: &pParentName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: &pParentName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: &pParentName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: &pParentName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: &pParentName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: &pParentName);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463920
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B9600
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004B9620
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x004B9700
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004B9710
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004B9720
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  int v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = (CDmElement *)v8;
      if ( v8 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v9 = nullptr;
      }
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9910
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9A90
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &value,
      a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00464050
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x00464070
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00464150
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x00464170
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x00464180
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00464370
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: &pch);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: &pch);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: &pch);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: &pch);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: &pch);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: &pch);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004644F0
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v9; // [esp+8h] [ebp-4h]

  v9 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v9, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n");
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v9, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D2A10
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x004D2A30
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x004D2B10
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x004D2B20
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x004D2B30
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  int v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = (CDmElement *)v8;
      if ( v8 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) == 0 )
      {
        v9 = nullptr;
      }
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2D20
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: pDeltaStateName);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2EA0
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &value,
      a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0046E8E0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x0046E900
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x0046E9E0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x0046E9F0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x0046EA00
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046EBF0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: Ptr);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: Ptr);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: Ptr);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: Ptr);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: Ptr);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: Ptr);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (const DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046ED70
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00566190
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x005661B0
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x00566290
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x005662A0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x005662B0
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005664A0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: var);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: var);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00566620
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10090FE0
// Name: void InstallActBusyImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallActBusyImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportActBusy);
}

//------------------------------------------------------------------------------
// Address: 0x10091000
// Name: private: void CImportActBusy::SerializeHeader(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportActBusy::SerializeHeader(CImportActBusy *this, CUtlBuffer *buf)
{
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \"act busy name\"\t\tThis is the name that a mapmaker must specify in the hint node.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// {\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"busy_anim\"\t\t\t\"Activity Name\".\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"entry_anim\"\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"exit_anim\"\t\t\t\"Activity Name\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"busy_sequence\"\t\t\"Sequence Name\". If specified, this is used over the activity name. Specify it in the hint node.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"entry_sequence\"\t\"Sequence Name\". If specified, this is used over the entry anim.\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"exit_sequence\"\t\t\"Sequence Name\". If specified, this is used over the exit anim.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"min_time\"\t\t\t\"Minimum time to spend in this busy anim\"\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\"max_time\"\t\t\t\"Maximum time to spend in this busy anim\"\t0 = only stop when interrupted by external event\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\"interrupts\"\t\tOne of:\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_NONE\"\t\tbreak out only when time runs out. No external influence will break me out.\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// \t\t\t\t\t\t\"BA_INT_DANGER\"\t\tbreak out of this anim only if threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_PLAYER\"\t\tbreak out of this anim if I can see the player, or I'm threatened\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_AMBUSH\"\t\tsomeone please define this - I have no idea what it does\n");
  CUtlBuffer::Printf(
    this: buf,
    pFmt: "// \t\t\t\t\t\t\"BA_INT_COMBAT\"\t\tbreak out of this anim if combat occurs in my line of sight (bullet hits, grenad"
    "es, etc), -OR- the max time is reached\n");
  CUtlBuffer::Printf(this: buf, pFmt: "// }\n");
  CUtlBuffer::Printf(this: buf, pFmt: "//\n");
}

//------------------------------------------------------------------------------
// Address: 0x100910E0
// Name: public: virtual char const __near * CImportActBusy::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetName(CImportActBusy *this)
{
  return "actbusy";
}

//------------------------------------------------------------------------------
// Address: 0x100910F0
// Name: public: virtual char const __near * CImportActBusy::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportActBusy::GetDescription(CImportActBusy *this)
{
  return "ActBusy Script File";
}

//------------------------------------------------------------------------------
// Address: 0x10091100
// Name: public: virtual bool CImportActBusy::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::Serialize(CImportActBusy *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // edi
  DmElementArray_t *m_pData; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  const char *m_pAsString; // eax
  bool v11; // sf
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp+8h]
  CDmElement *pRoota; // [esp+20h] [ebp+Ch]

  CImportActBusy::SerializeHeader(this, buf);
  CUtlBuffer::Printf(this: buf, pFmt: "\"ActBusy.txt\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "children");
  v6 = Attribute;
  if ( Attribute == nullptr || (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = v6;
    m_pData = (DmElementArray_t *)v6->m_pData;
    children.m_pStorage = m_pData;
    pRoota = (CDmElement *)m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
    pRoota = nullptr;
  }
  ++buf->m_nTab;
  i = 0;
  if ( (int)pRoota > 0 )
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[i]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType) )
        v9 = nullptr;
      m_pAsString = v9->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\"\n", m_pAsString);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_anim",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "busy_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "entry_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "exit_sequence",
        bSkipEmptryStrings: true,
        bPrintValueOnly: false);
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "min_time");
      CImportKeyValueBase::PrintFloatAttribute(this, pElement: v9, outBuf: buf, pKeyName: "max_time");
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v9,
        outBuf: buf,
        pKeyName: "interrupts",
        bSkipEmptryStrings: false,
        bPrintValueOnly: false);
      v11 = --buf->m_nTab < 0;
      if ( v11 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++i >= (int)pRoota )
        break;
      m_pData = children.m_pStorage;
    }
  }
  v11 = --buf->m_nTab < 0;
  if ( v11 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100912F0
// Name: private: bool CImportActBusy::UnserializeActBusyKey(class CDmAttribute __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportActBusy::UnserializeActBusyKey(
        CImportActBusy *this,
        CDmAttribute *pChildren,
        KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmrElementArray<CDmElement> children; // [esp+Ch] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+14h] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  if ( DmElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusy");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  pKeyValues = nullptr;
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_anim",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "busy_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "entry_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "exit_sequence",
    pDefault: defaultValue);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "min_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddFloatAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "max_time",
    pDefault: (float *)&pKeyValues);
  CImportKeyValueBase::AddStringAttribute(
    this,
    pElement: DmElement,
    pKeyValues: v3,
    pKeyName: "interrupts",
    pDefault: "BA_INT_NONE");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&children);
  if ( pChildren != nullptr && (pChildren->m_nFlags & 0x1F) == 0xF )
  {
    children.m_pAttribute = pChildren;
    children.m_pStorage = (DmElementArray_t *)pChildren->m_pData;
  }
  else
  {
    children.m_pAttribute = nullptr;
    children.m_pStorage = nullptr;
  }
  pChildren = (CDmAttribute *)CVTFTexture::MipCount(this: (CVTFTexture *)DmElement);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &children,
    src: (DmElementHandle_t *)&pChildren);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091470
// Name: public: virtual class CDmElement __near * CImportActBusy::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportActBusy::UnserializeFromKeyValues(CImportActBusy *this, KeyValues *pKeyValues)
{
  CDmElement *result; // eax
  CDmElement *v3; // edi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // ebx
  KeyValues *FirstTrueSubKey; // esi
  const char *Name; // eax
  CUtlSymbolLarge value; // [esp+4h] [ebp-8h] BYREF
  CImportActBusy *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  result = CImportKeyValueBase::CreateDmElement(
             this,
             pElementType: "DmElement",
             pElementName: "ActBusyList",
             pId: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "actBusyList");
    Attribute = CDmElement::FindAttribute(this: v3, pAttributeName: "editorType");
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
    }
    v5 = CDmElement::FindAttribute(this: v3, pAttributeName: "children");
    if ( v5 != nullptr )
      v6 = (v5->m_nFlags & 0x1F) != 15 ? nullptr : v5;
    else
      v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "children", type: AT_FIRST_ARRAY_TYPE);
    if ( v6 != nullptr )
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
      if ( FirstTrueSubKey != nullptr )
      {
        while ( CImportActBusy::UnserializeActBusyKey(this: v10, pChildren: v6, pKeyValues: FirstTrueSubKey) != 0 )
        {
          FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
          if ( FirstTrueSubKey == nullptr )
            goto LABEL_13;
        }
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "Error importing actbusy element %s\n", Name);
        return nullptr;
      }
      else
      {
LABEL_13:
        CImportKeyValueBase::RecursivelyResolveElement(this: v10, pElement: v3);
        return v3;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

} // namespace vtex_dll
