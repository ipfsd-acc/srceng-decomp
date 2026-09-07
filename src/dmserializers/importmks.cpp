// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importmks.cpp
// Functions: 20
// ============================================================

#include "dmserializers\importmks.h"

//------------------------------------------------------------------------------
// Address: 0x00449BC0
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x00458740
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x00458760
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004587A0
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00458820
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: &defaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004588D0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004589C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458AF0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458BD0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458CB0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x00458CC0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00458DF0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x00458E70
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00458FB0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004592C0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CDmElement::GetHandle(this: v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004593B0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004594C0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, DmElementHandle_t pSequenceEntry, DmElementHandle_t pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CDmElement *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CDmElement::GetHandle(this: pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CDmElement::GetHandle(this: Image);
  else
    pSequenceEntry = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: &pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(this: Image, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CDmElement::GetHandle(this: m_pCurrentSequence);
  else
    pImageName = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: &pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00459650
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(
      this: v12,
      pSequenceEntry: (DmElementHandle_t)v4,
      pImageName: (DmElementHandle_t)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CDmElement::GetHandle(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459710
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004597A0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0045FAB0
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0046E140
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0046E160
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046E1A0
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046E220
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: var) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0046E2D0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E3C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E4F0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E5D0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E6B0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x0046E6C0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046E7F0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *)&Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x0046E870
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E9B0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046ECC0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046EDB0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046EEC0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0046F050
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046F110
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F1A0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CDmMeshComp::CEdge *,CUtlMemory<CDmMeshComp::CEdge *,int> > *)&outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AAC40
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x004AAC60
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AACA0
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AAD20
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: defaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004AADD0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AAEC0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (const int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AAFF0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AB0D0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AB1B0
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x004AB1C0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x004AB1D0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AB300
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x004AB380
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AB4C0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AB7D0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AB8C0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004AB9D0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (const DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CCodecBuffer_Block::GetBufferType(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (const DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (const DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x004ABB60
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CCodecBuffer_Block::GetBufferType(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (const DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ABC20
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ABCB0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1034C6B0
// Name: public: virtual class CFrameWnd __near * CDocTemplate::CreateNewFrame(class CDocument __near *,class CFrameWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CDocTemplate::CreateNewFrame(CDocTemplate *this, CDocument *pDoc, CFrameWnd *pOther)
{
  CRuntimeClass *m_pFrameClass; // ecx
  CFrameWnd *result; // eax
  CCreateContext context; // [esp+4h] [ebp-14h] BYREF

  memset(dst: (unsigned __int8 *)&context, value: 0, count: sizeof(context));
  m_pFrameClass = this->m_pFrameClass;
  context.m_pCurrentFrame = pOther;
  context.m_pCurrentDoc = pDoc;
  context.m_pNewViewClass = this->m_pViewClass;
  context.m_pNewDocTemplate = this;
  if ( m_pFrameClass == nullptr )
    return nullptr;
  result = (CFrameWnd *)CRuntimeClass::CreateObject(this: m_pFrameClass);
  if ( result != nullptr )
    return result->LoadFrame(this: result, a2: this->m_nIDResource, a3: 13598720u, a4: nullptr, a5: &context) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104AD570
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x104BAB00
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x104BAB20
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BAB60
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104BABE0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: &var) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x104BAC90
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BAD80
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BAEB0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BAF90
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BB070
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x104BB080
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BB140
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int> > *)&Words);
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x104BB1C0
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BB300
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BB610
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BB700
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104BB810
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CCodecBuffer_Block::GetBufferType(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x104BB9A0
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CCodecBuffer_Block::GetBufferType(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BBA60
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(
        this: (CUtlMemory<CCullTreeNode *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BBAF0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        CUtlBuffer *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  _BYTE *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  char *v21; // eax
  char s1[4]; // [esp+10h] [ebp-1134h] BYREF
  char path[4]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float v25; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool v27; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine: s1, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: s1, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      _V_strstr(s1, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = s1; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              v25 = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime: v25) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&outImageNames);
                CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&outStrings);
                return false;
              }
              CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        v27 = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, value: &v27);
        }
      }
LABEL_38:
      CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CFoW_LineOccluder *,CUtlMemory<CFoW_LineOccluder *,int> > *)&outStrings);
      CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = (char *)g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest: path, pSrc: v21, maxLen: 260);
  V_SetExtension(path, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: path, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: path,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", path);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

//------------------------------------------------------------------------------
// Address: 0x1034C71B
// Name: public: class CFrameWnd __near * CDocTemplate::CreatePreviewFrame(class CWnd __near *,class CDocument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWnd *__thiscall CDocTemplate::CreatePreviewFrame(CDocTemplate *this, CWnd *pParentWnd, CDocument *pDoc)
{
  CRuntimeClass *m_pPreviewViewClass; // eax
  CRuntimeClass *m_pPreviewFrameClass; // eax
  CObject *Object; // eax
  CObject *v7; // ebx
  unsigned int m_nIDPreviewResource; // esi
  int v10; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  char *v12; // esi
  tagWNDCLASSA wndcls; // [esp+Ch] [ebp-84h] BYREF
  tagCREATESTRUCTA v14; // [esp+34h] [ebp-5Ch] BYREF
  CCreateContext context; // [esp+64h] [ebp-2Ch] BYREF
  CWnd *v16; // [esp+78h] [ebp-18h]
  CRect rectEmpty; // [esp+7Ch] [ebp-14h] BYREF

  v16 = pParentWnd;
  memset(dst: (unsigned __int8 *)&context, value: 0, count: sizeof(context));
  m_pPreviewViewClass = this->m_pPreviewViewClass;
  context.m_pCurrentFrame = nullptr;
  context.m_pCurrentDoc = pDoc;
  if ( m_pPreviewViewClass == nullptr )
    m_pPreviewViewClass = this->m_pViewClass;
  context.m_pNewViewClass = m_pPreviewViewClass;
  m_pPreviewFrameClass = this->m_pPreviewFrameClass;
  if ( m_pPreviewFrameClass == nullptr )
    m_pPreviewFrameClass = &CFrameWnd::classCFrameWnd;
  Object = CRuntimeClass::CreateObject(this: m_pPreviewFrameClass);
  v7 = Object;
  if ( Object == nullptr )
    return nullptr;
  m_nIDPreviewResource = this->m_nIDPreviewResource;
  if ( m_nIDPreviewResource != 0 )
  {
    v10 = ((int (__thiscall *)(CObject *, unsigned int, int, CWnd *, CCreateContext *))Object->__vftable[29].Serialize)(
            a1: Object,
            a2: m_nIDPreviewResource,
            a3: 1140850688,
            a4: v16,
            a5: &context);
  }
  else
  {
    memset(dst: (unsigned __int8 *)&v14, value: 0, count: sizeof(v14));
    v14.style = 1140850688;
    AfxEndDeferRegisterClass(fToRegister: 8);
    v14.lpszClass = "AfxFrameOrView100s";
    ModuleState = AfxGetModuleState();
    if ( AfxCtxGetClassInfoA(
           hInstance: ModuleState->m_hCurrentInstanceHandle,
           lpClassName: v14.lpszClass,
           lpWndClass: &wndcls) == 0 )
      return (CFrameWnd *)v7;
    v12 = AfxRegisterWndClass(
            nClassStyle: wndcls.style,
            hCursor: wndcls.hCursor,
            hbrBackground: wndcls.hbrBackground,
            hIcon: nullptr);
    memset(&rectEmpty, 0, sizeof(rectEmpty));
    SetRectEmpty(lprc: &rectEmpty);
    v10 = ((int (__thiscall *)(CObject *, char *, const char *, int, CRect *, CWnd *, _DWORD, _DWORD, CCreateContext *))v7->__vftable[29].dtr_CObject)(
            a1: v7,
            a2: v12,
            a3: &var,
            a4: v14.style,
            a5: &rectEmpty,
            a6: v16,
            a7: 0,
            a8: 0,
            a9: &context);
  }
  if ( v10 == 0 )
    return nullptr;
  return (CFrameWnd *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x1034C849
// Name: public: virtual CDocTemplate::~CDocTemplate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::~CDocTemplate(CDocTemplate *this)
{
  if ( this->m_hMenuInPlace != nullptr )
    DestroyMenu(hMenu: this->m_hMenuInPlace);
  if ( this->m_hAccelInPlace != nullptr )
    FreeResource(hResData: this->m_hAccelInPlace);
  if ( this->m_hMenuEmbedding != nullptr )
    DestroyMenu(hMenu: this->m_hMenuEmbedding);
  if ( this->m_hAccelEmbedding != nullptr )
    FreeResource(hResData: this->m_hAccelEmbedding);
  if ( this->m_hMenuInPlaceServer != nullptr )
    DestroyMenu(hMenu: this->m_hMenuInPlaceServer);
  if ( this->m_hAccelInPlaceServer != nullptr )
    FreeResource(hResData: this->m_hAccelInPlaceServer);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDocStrings.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strCLSID.m_pszData - 1);
  CCmdTarget::~CCmdTarget(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034C8BF
// Name: public: virtual enum CDocTemplate::Confidence CDocTemplate::MatchDocType(char const __near *,class CDocument __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocTemplate::MatchDocType(CDocTemplate *this, const char *lpszPathName, CDocument **rpDocMatch)
{
  CDocument **v4; // ebx
  CDocument *v5; // edi
  CAfxStringMgr *StringManager; // eax
  CDocTemplate_vtbl *v7; // eax
  const char *ExtensionA; // eax
  int v10; // [esp-4h] [ebp-24h]
  __POSITION *pos; // [esp+10h] [ebp-10h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v4 = rpDocMatch;
  *rpDocMatch = nullptr;
  pos = this->GetFirstDocPosition(this);
  if ( pos != nullptr )
  {
    while ( 1 )
    {
      v5 = this->GetNextDoc(this, a2: &pos);
      if ( AfxComparePath(lpszPath1: v5->m_strPathName.m_pszData, lpszPath2: lpszPathName) != 0 )
        break;
      if ( pos == nullptr )
        goto LABEL_4;
    }
    *v4 = v5;
    return 5;
  }
  else
  {
LABEL_4:
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: (ATL::CSimpleStringT<char,0> *)&rpDocMatch,
      pStringMgr: StringManager);
    v7 = this->__vftable;
    v12 = 0;
    if ( v7->GetDocString(
           this,
           a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&rpDocMatch,
           a3: filterExt) != 0
      && *(rpDocMatch - 3) != nullptr
      && (ExtensionA = PathFindExtensionA(pszPath: lpszPathName)) != nullptr
      && AfxComparePath(lpszPath1: ExtensionA, lpszPath2: (const char *)rpDocMatch) != 0 )
    {
      v10 = 4;
    }
    else
    {
      v10 = 3;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)rpDocMatch - 1);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034C96A
// Name: public: virtual void CDocTemplate::LoadTemplate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::LoadTemplate(CDocTemplate *this)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strDocStrings; // ecx
  HINSTANCE hInst; // [esp+Ch] [ebp-4h]
  HINSTANCE hInsta; // [esp+Ch] [ebp-4h]
  HINSTANCE hInstb; // [esp+Ch] [ebp-4h]

  p_m_strDocStrings = &this->m_strDocStrings;
  if ( *((_DWORD *)p_m_strDocStrings->m_pszData - 3) == 0 )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: p_m_strDocStrings,
      nID: this->m_nIDResource);
  if ( this->m_nIDEmbeddingResource != 0 && this->m_hMenuEmbedding == nullptr )
  {
    hInst = AfxGetModuleState()->m_hCurrentResourceHandle;
    this->m_hMenuEmbedding = LoadMenuW(hInstance: hInst, lpMenuName: (LPCWSTR)LOWORD(this->m_nIDEmbeddingResource));
    this->m_hAccelEmbedding = LoadAcceleratorsW(
                                hInstance: hInst,
                                lpTableName: (LPCWSTR)LOWORD(this->m_nIDEmbeddingResource));
  }
  if ( this->m_nIDServerResource != 0 && this->m_hMenuInPlaceServer == nullptr )
  {
    hInsta = AfxGetModuleState()->m_hCurrentResourceHandle;
    this->m_hMenuInPlaceServer = LoadMenuW(hInstance: hInsta, lpMenuName: (LPCWSTR)LOWORD(this->m_nIDServerResource));
    this->m_hAccelInPlaceServer = LoadAcceleratorsW(
                                    hInstance: hInsta,
                                    lpTableName: (LPCWSTR)LOWORD(this->m_nIDServerResource));
  }
  if ( this->m_nIDContainerResource != 0 && this->m_hMenuInPlace == nullptr )
  {
    hInstb = AfxGetModuleState()->m_hCurrentResourceHandle;
    this->m_hMenuInPlace = LoadMenuW(hInstance: hInstb, lpMenuName: (LPCWSTR)LOWORD(this->m_nIDContainerResource));
    this->m_hAccelInPlace = LoadAcceleratorsW(
                              hInstance: hInstb,
                              lpTableName: (LPCWSTR)LOWORD(this->m_nIDContainerResource));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034CA29
// Name: protected: CDocTemplate::CDocTemplate(unsigned int,struct CRuntimeClass __near *,struct CRuntimeClass __near *,struct CRuntimeClass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocTemplate *__thiscall CDocTemplate::CDocTemplate(
        CDocTemplate *this,
        unsigned int nIDResource,
        CRuntimeClass *pDocClass,
        CRuntimeClass *pFrameClass,
        CRuntimeClass *pViewClass)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v7; // eax
  CPtrList *v8; // ecx
  CPtrList *v9; // eax
  CDocManager *v10; // ecx
  CDocManager *v11; // eax

  CCmdTarget::CCmdTarget(this);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strCLSID, pStringMgr: StringManager);
  v7 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDocStrings, pStringMgr: v7);
  this->m_nIDResource = nIDResource;
  this->m_pDocClass = pDocClass;
  this->m_pFrameClass = pFrameClass;
  this->m_nIDServerResource = 0;
  this->m_nIDEmbeddingResource = 0;
  this->m_nIDContainerResource = 0;
  this->m_nIDPreviewResource = 0;
  this->m_pViewClass = pViewClass;
  this->m_pOleFrameClass = nullptr;
  this->m_pOleViewClass = nullptr;
  this->m_pPreviewFrameClass = nullptr;
  this->m_pPreviewViewClass = nullptr;
  this->m_pAttachedFactory = nullptr;
  this->m_hMenuInPlace = nullptr;
  this->m_hAccelInPlace = nullptr;
  this->m_hMenuEmbedding = nullptr;
  this->m_hAccelEmbedding = nullptr;
  this->m_hMenuInPlaceServer = nullptr;
  this->m_hAccelInPlaceServer = nullptr;
  if ( CDocManager::bStaticInit != 0 )
  {
    this->m_bAutoDelete = 0;
    if ( CDocManager::pStaticList == nullptr )
    {
      v8 = (CPtrList *)operator new(nSize: 0x1Cu);
      if ( v8 != nullptr )
        v9 = CPtrList::CPtrList(this: v8, nBlockSize: 10);
      else
        v9 = nullptr;
      CDocManager::pStaticList = v9;
    }
    if ( CDocManager::pStaticDocManager == nullptr )
    {
      v10 = (CDocManager *)operator new(nSize: 0x20u);
      if ( v10 != nullptr )
        v11 = CDocManager::CDocManager(this: v10);
      else
        v11 = nullptr;
      CDocManager::pStaticDocManager = v11;
    }
    CPtrList::AddTail(this: (CObList *)CDocManager::pStaticList, newElement: this);
  }
  else
  {
    this->m_bAutoDelete = 1;
    CDocTemplate::LoadTemplate(this);
  }
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00482400
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x00490F00
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x00490F20
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00490F60
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00490FF0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: WindowName) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004910A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491190
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004912C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004913A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491480
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x00491490
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004915C0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x00491640
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491780
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  int v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = (CDmElement *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v12 = nullptr;
        }
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00491A90
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CDmElement::GetHandle(this: v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00491B80
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  int v10; // eax
  int v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v8 = 0;
    }
    v9 = *(const char **)(v8 + 20);
    if ( v9 == (const char *)-1 )
      v9 = WindowName;
    if ( _V_stricmp(s1: pFrameName, s2: v9) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
         a1: v10,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v11;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491C90
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, DmElementHandle_t pSequenceEntry, DmElementHandle_t pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CDmElement *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CDmElement::GetHandle(this: pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CDmElement::GetHandle(this: Image);
  else
    pSequenceEntry = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: &pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(this: Image, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CDmElement::GetHandle(this: m_pCurrentSequence);
  else
    pImageName = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: &pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00491E20
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(
      this: v12,
      pSequenceEntry: (DmElementHandle_t)v4,
      pImageName: (DmElementHandle_t)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CDmElement::GetHandle(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00491EE0
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491F70
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 364))(
                        a1: g_pDataModel.u,
                        a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, const char *, CUtlBuffer **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
           a1: g_pDataModel.u,
           a2: pDest,
           a3: 0,
           a4: "tex_source1",
           a5: &buf,
           a6: 2,
           a7: 0) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return (*(bool (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
           a1: g_pDataModel.u,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00506080
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x00514B10
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x00514B30
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00514B70
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00514BF0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: pDefaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00514CA0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00514D90
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00514EC0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00514FA0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00515080
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x00515090
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005151C0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x00515240
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00515380
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00515690
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CVTFTexture::MipCount(this: (CVTFTexture *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00515780
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDefaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00515890
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CVTFTexture *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CVTFTexture::MipCount(this: (CVTFTexture *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CVTFTexture *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CVTFTexture::MipCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CVTFTexture::MipCount(this: (CVTFTexture *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00515A20
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CVTFTexture *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CVTFTexture *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CVTFTexture::MipCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00515AE0
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00515B70
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D5110
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x004D5130
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D5170
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D51F0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: pDeltaStateName) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004D52A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D5390
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D54C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D55A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D5680
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x004D5690
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x004D56A0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D57D0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x004D5850
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D5990
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  int v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = (CDmElement *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v12 = nullptr;
        }
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D5CA0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D5D90
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  int v10; // eax
  int v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v8 = 0;
    }
    v9 = *(const char **)(v8 + 20);
    if ( v9 == (const char *)-1 )
      v9 = pDeltaStateName;
    if ( _V_stricmp(s1: pFrameName, s2: v9) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
         a1: v10,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v11;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D5EA0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x004D6030
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D60F0
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6180
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 364))(
                        a1: g_pDataModel.u,
                        a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, const char *, CUtlBuffer **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
           a1: g_pDataModel.u,
           a2: pDest,
           a3: 0,
           a4: "tex_source1",
           a5: &buf,
           a6: 2,
           a7: 0) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return (*(bool (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
           a1: g_pDataModel.u,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0045A220
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0045A240
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045A280
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045A300
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: defaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0045A3B0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A4A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (const int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A5D0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A6B0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A790
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0045A7A0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x0045A7B0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045A8E0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x0045A960
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AAA0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045ADB0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CCodecBuffer_Block::GetBufferType(this: v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045AEA0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045AFB0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, DmElementHandle_t pSequenceEntry, DmElementHandle_t pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CDmElement *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (const DmElementHandle_t *)&pBitmap);
  }
  Image = CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CCodecBuffer_Block::GetBufferType(this: Image);
  else
    pSequenceEntry = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: &pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(this: Image, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CCodecBuffer_Block::GetBufferType(this: m_pCurrentSequence);
  else
    pImageName = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: &pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0045B140
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(
      this: v12,
      pSequenceEntry: (DmElementHandle_t)v4,
      pImageName: (DmElementHandle_t)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CCodecBuffer_Block::GetBufferType(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (const DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B200
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B290
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0044D380
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0045BD20
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0045BD40
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045BD80
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045BE00
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: str) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0045BEB0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BFA0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C0D0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C1B0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C290
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x0045C2A0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: word, a2: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n");
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C3D0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x0045C450
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  sequences.m_pStorage = (DmElementArray_t *)v6->m_pData;
  if ( sequences.m_pStorage->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: 2,
      a2: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n");
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: eMode, a2: "*** line error: incompatible packmode change when %d sequences already defined!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C590
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  int v22; // ecx
  CDmAttribute *v23; // esi
  CDmaVar<int> *v24; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v28; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v28 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v28->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) != 2 && CDmAttribute::IsTypeConvertable<bool>(this: v21) )
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
      v23 = CDmElement::FindAttribute(this: v28->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      LOBYTE(v22) = v23->m_nFlags & 0x1F;
      if ( (_BYTE)v22 == 2 )
      {
        v24 = (CDmaVar<int> *)v23->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v23) )
      {
        CDmAttribute::CopyDataOut<int>(this: v23, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v24 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v24 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v24->m_Storage )
      {
        _Msg(a1: v22, a2: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n");
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C8A0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C990
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = str;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045CAA0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0045CC30
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045CCF0
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CD80
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0044B630
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0045A1C0
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0045A1E0
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045A2A0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: &defaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0045A350
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A440
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A570
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A650
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A730
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x0045A740
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045A870
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x0045A8F0
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AA30
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045AD40
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CDmElement::GetHandle(this: v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045AE30
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &defaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045AF40
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, DmElementHandle_t pSequenceEntry, DmElementHandle_t pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CDmElement *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CDmElement::GetHandle(this: pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (const DmElementHandle_t *)&pBitmap);
  }
  Image = CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CDmElement::GetHandle(this: Image);
  else
    pSequenceEntry = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: &pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(this: Image, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CDmElement::GetHandle(this: m_pCurrentSequence);
  else
    pImageName = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: &pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0045B0D0
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CDmElement *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(
      this: v12,
      pSequenceEntry: (DmElementHandle_t)v4,
      pImageName: (DmElementHandle_t)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CDmElement::GetHandle(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (const DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B190
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B220
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00450610
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0045F130
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0045F150
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045F190
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045F210
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: &pParentName) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0045F2C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F3B0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F4E0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F5C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F6A0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x0045F6B0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: word, a2: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n");
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045F7E0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x0045F860
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  sequences.m_pStorage = (DmElementArray_t *)v6->m_pData;
  if ( sequences.m_pStorage->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: 2,
      a2: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n");
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: eMode, a2: "*** line error: incompatible packmode change when %d sequences already defined!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F9A0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  int v22; // ecx
  CDmAttribute *v23; // esi
  CDmaVar<int> *v24; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v28; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v28 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v28->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) != 2 && CDmAttribute::IsTypeConvertable<bool>(this: v21) )
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
      v23 = CDmElement::FindAttribute(this: v28->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      LOBYTE(v22) = v23->m_nFlags & 0x1F;
      if ( (_BYTE)v22 == 2 )
      {
        v24 = (CDmaVar<int> *)v23->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v23) )
      {
        CDmAttribute::CopyDataOut<int>(this: v23, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v24 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v24 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v24->m_Storage )
      {
        _Msg(a1: v22, a2: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n");
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045FCB0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045FDA0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pParentName;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045FEB0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00460040
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460100
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460190
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B5280
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x004B52A0
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B52E0
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5360
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: defaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004B5410
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5500
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (const int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5630
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5710
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B57F0
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x004B5800
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x004B5810
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B5940
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x004B59C0
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B5B00
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  int v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = (CDmElement *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v12 = nullptr;
        }
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B5E10
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B5F00
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  int v10; // eax
  int v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v8 = 0;
    }
    v9 = *(const char **)(v8 + 20);
    if ( v9 == (const char *)-1 )
      v9 = defaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: v9) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
         a1: v10,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v11;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B6010
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (const DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CCodecBuffer_Block::GetBufferType(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (const DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (const DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x004B61A0
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CCodecBuffer_Block::GetBufferType(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (const DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B6260
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B62F0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 364))(
                        a1: g_pDataModel.u,
                        a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, const char *, CUtlBuffer **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
           a1: g_pDataModel.u,
           a2: pDest,
           a3: 0,
           a4: "tex_source1",
           a5: &buf,
           a6: 2,
           a7: 0) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return (*(bool (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
           a1: g_pDataModel.u,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x004513E0
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0045FCF0
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0045FD10
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045FD50
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045FDD0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v2; // esi

  v2 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v2, s2: &pch) == 0 || _V_stricmp(s1: v2, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v2, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v2, s2: "-a") == 0 )
    return 2;
  _Warning(a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n");
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0045FE80
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FF70
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004600A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460180
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460260
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x00460270
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: word, a2: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n");
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004603A0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x00460420
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  sequences.m_pStorage = (DmElementArray_t *)v6->m_pData;
  if ( sequences.m_pStorage->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: 2,
      a2: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n");
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: eMode, a2: "*** line error: incompatible packmode change when %d sequences already defined!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460560
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  int v22; // ecx
  CDmAttribute *v23; // esi
  CDmaVar<int> *v24; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v28; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v28 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v28->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) != 2 && CDmAttribute::IsTypeConvertable<bool>(this: v21) )
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
      v23 = CDmElement::FindAttribute(this: v28->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      LOBYTE(v22) = v23->m_nFlags & 0x1F;
      if ( (_BYTE)v22 == 2 )
      {
        v24 = (CDmaVar<int> *)v23->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v23) )
      {
        CDmAttribute::CopyDataOut<int>(this: v23, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v24 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v24 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v24->m_Storage )
      {
        _Msg(a1: v22, a2: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n");
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460870
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460960
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &pch;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460A70
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (const DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (const DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (const DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00460C00
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (const DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00460CC0
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460D50
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n");
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n");
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004CE6A0
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x004CE6C0
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CE700
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CE780
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: pDeltaStateName) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x004CE830
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CE920
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEA50
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEB30
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  int v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: 0);
  if ( v2 == -1 )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
                         a1: g_pDataModel.u,
                         a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEC10
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x004CEC20
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x004CEC30
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CED60
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x004CEDE0
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CEF20
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  int v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = (CDmElement *)v11;
        if ( v11 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v11 + 16))(
               a1: v11,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v12 = nullptr;
        }
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CF230
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CF320
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  int v7; // eax
  int v8; // esi
  const char *v9; // eax
  int v10; // eax
  int v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
           a1: v7,
           a2: CDmElement::m_classType.u) == 0 )
    {
      v8 = 0;
    }
    v9 = *(const char **)(v8 + 20);
    if ( v9 == (const char *)-1 )
      v9 = pDeltaStateName;
    if ( _V_stricmp(s1: pFrameName, s2: v9) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
         a1: v10,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v11;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF430
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x004CF5C0
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CF680
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF710
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 364))(
                        a1: g_pDataModel.u,
                        a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, _DWORD, const char *, CUtlBuffer **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
           a1: g_pDataModel.u,
           a2: pDest,
           a3: 0,
           a4: "tex_source1",
           a5: &buf,
           a6: 2,
           a7: 0) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return (*(bool (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
           a1: g_pDataModel.u,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0045BAB0
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x0046A580
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x0046A5A0
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A5E0
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046A660
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: Ptr) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x0046A710
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A800
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (const int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A930
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046AA10
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046AAF0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x0046AB00
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046AC30
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x0046ACB0
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ADF0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B100
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B1F0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = Ptr;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0046B300
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CExpressionCalculator *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (const DmElementHandle_t *)&pBitmap);
  }
  Image = (CExpressionCalculator *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CExpressionCalculator::VariableCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (const DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (const DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x0046B490
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CExpressionCalculator *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CExpressionCalculator *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CExpressionCalculator::VariableCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (const DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046B550
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046B5E0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00561E10
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x00561E30
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00561E70
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00561EF0
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: var) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00561FA0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562090
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (const bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005621C0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005622A0
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562380
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x00562390
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x005623A0
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005624D0
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x00562550
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562690
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005629A0
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00562A90
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = var;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00562BA0
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CVTFTexture *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CVTFTexture *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CCoreDispNode::GetCenterVertIndex(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x00562D30
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CVTFTexture *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CVTFTexture *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CCoreDispNode::GetCenterVertIndex(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00562DF0
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00562E80
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outImageNames);
                CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
                return false;
              }
              CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1007E250
// Name: public: virtual char const __near * CImportMKS::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetName(CImportMKS *this)
{
  return "mks";
}

//------------------------------------------------------------------------------
// Address: 0x1008CC80
// Name: void InstallMKSImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallMKSImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportMKS);
}

//------------------------------------------------------------------------------
// Address: 0x1008CCA0
// Name: public: virtual bool CImportMKS::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::Serialize(CImportMKS *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int m_nTab; // eax

  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  m_nTab = buf->m_nTab;
  buf->m_nTab = m_nTab;
  if ( m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008CCE0
// Name: private: int CImportMKS::ParsePackingMode(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParsePackingMode(CImportMKS *this, char *word)
{
  if ( _V_stricmp(s1: word, s2: "flat") == 0 || _V_stricmp(s1: word, s2: "rgba") == 0 )
    return 1;
  if ( _V_stricmp(s1: word, s2: "rgb+a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid packmode specified, allowed values are 'rgba' or 'rgb+a'!\n",
    this->m_NumActualLinesRead);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008CD60
// Name: private: int CImportMKS::ParseSequenceType(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportMKS::ParseSequenceType(CImportMKS *this, char *word)
{
  const char *v3; // esi

  v3 = StringAfterPrefix(str: word, prefix: "sequence");
  if ( _V_stricmp(s1: v3, s2: defaultValue) == 0 || _V_stricmp(s1: v3, s2: "-rgba") == 0 )
    return 0;
  if ( _V_stricmp(s1: v3, s2: "-rgb") == 0 )
    return 1;
  if ( _V_stricmp(s1: v3, s2: "-a") == 0 )
    return 2;
  _Warning(
    a1: "*** line %d: invalid sequence type '%s', allowed 'sequence-rgba' or 'sequence-rgb' or 'sequence-a'!\n",
    this->m_NumActualLinesRead,
    word);
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1008CE10
// Name: private: class CDmElement __near * CImportMKS::CreateDmeAmalgamatedTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeAmalgamatedTexture(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeAmalgamatedTexture",
         a3: "CDmeAmalgamatedTexture",
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeAmalgamatedTexture");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "images")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "images", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "packmode")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "packmode", type: AT_INT))
         : (v9 = (v8->m_nFlags & 0x1F) != 2 ? nullptr : v8),
           v9 != nullptr && CDmElement::AddAttribute(this: v5, pAttributeName: "width", type: AT_INT) != nullptr)) )
    {
      return CDmElement::AddAttribute(this: v5, pAttributeName: "height", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CF00
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequence(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v11; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequence",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequence");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sequencenumber")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sequencenumber", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr
       && ((v8 = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp")) == nullptr
         ? (v9 = CDmElement::CreateAttribute(this: v5, pAttributeName: "clamp", type: AT_BOOL))
         : (v9 = (v8->m_nFlags & 0x1F) != 4 ? nullptr : v8),
           v9 != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "mode", type: AT_INT) != nullptr
        && CDmElement::AddAttribute(this: v5, pAttributeName: "frames", type: AT_FIRST_ARRAY_TYPE) != nullptr)) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "clamp");
      HIBYTE(pName) = 1;
      CDmAttribute::SetValue<bool>(this: Attribute, value: (bool *)&pName + 3);
      v11 = CDmElement::FindAttribute(this: v5, pAttributeName: "mode");
      pName = nullptr;
      CDmAttribute::SetValue<int>(this: v11, value: (int *)&pName);
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D030
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSequenceFrame(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSequenceFrame(CImportMKS *this, const char *pName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetSequenceFrame",
         a3: pName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetSequenceFrame");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "sheetimages")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "sheetimages", type: AT_FIRST_ARRAY_TYPE))
        : (v7 = (v6->m_nFlags & 0x1F) != 15 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "displaytime");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 3 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "displaytime", type: AT_FLOAT) != nullptr
             ? v5
             : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D110
// Name: private: class CDmElement __near * CImportMKS::CreateDmeSheetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::CreateDmeSheetImage(CImportMKS *this, const char *pImageName)
{
  DmElementHandle_t v2; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *Attribute; // eax

  v2 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: "DmeSheetImage",
         a3: pImageName,
         a4: this->m_Fileid,
         a5: nullptr);
  if ( v2 == DMELEMENT_HANDLE_INVALID )
  {
    _Warning(a1: "Element uses unknown element type %s\n", "CDmeSheetImage");
    return nullptr;
  }
  else
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2);
    v5 = v4;
    if ( v4 != nullptr
      && ((v6 = CDmElement::FindAttribute(this: v4, pAttributeName: "xcoord")) == nullptr
        ? (v7 = CDmElement::CreateAttribute(this: v5, pAttributeName: "xcoord", type: AT_INT))
        : (v7 = (v6->m_nFlags & 0x1F) != 2 ? nullptr : v6),
          v7 != nullptr) )
    {
      Attribute = CDmElement::FindAttribute(this: v5, pAttributeName: "ycoord");
      if ( Attribute != nullptr )
        return ((Attribute->m_nFlags & 0x1F) != 2 ? 0 : (unsigned int)Attribute) != 0 ? v5 : nullptr;
      else
        return CDmElement::CreateAttribute(this: v5, pAttributeName: "ycoord", type: AT_INT) != nullptr ? v5 : nullptr;
    }
    else
    {
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D1F0
// Name: public: virtual char const __near * CImportMKS::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportMKS::GetDescription(CImportMKS *this)
{
  return "Valve Make Sheet File";
}

//------------------------------------------------------------------------------
// Address: 0x1008D200
// Name: private: bool CImportMKS::ValidateSequenceType(int,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateSequenceType(CImportMKS *this, int eMode, char *word)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 1 )
  {
    if ( eMode != 0 )
    {
      _Msg(a1: "*** line error: invalid sequence type '%s', packing 'flat' allows only 'sequence-rgba'!\n", word);
      return 0;
    }
  }
  else
  {
    if ( m_pData->m_Storage != 2 )
    {
      _Warning(a1: "Invalid packing mode!");
      return 0;
    }
    if ( eMode <= 0 || eMode > 2 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008D330
// Name: ApplyMacros
// Source: json
//------------------------------------------------------------------------------
void __usercall ApplyMacros(char *in_buf@<esi>)
{
  CUtlVector<char *,CUtlMemory<char *,int> > Words; // [esp+0h] [ebp-14h] BYREF

  memset(&Words, 0, sizeof(Words));
  V_SplitString(pString: in_buf, pSeparator: " ", outStrings: &Words);
  if ( Words.m_Size == 4 && _V_stricmp(s1: *(const char **)Words.m_Memory.m_pMemory, s2: "ga_frame") == 0 )
    sprintf(
      string: in_buf,
      format: "frame %s{r=0},%s{g=a},%s{b=0},%s{a=a} %s",
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 1),
      *((const char **)Words.m_Memory.m_pMemory + 2),
      *((const char **)Words.m_Memory.m_pMemory + 3));
  CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &Words);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&Words);
}

//------------------------------------------------------------------------------
// Address: 0x1008D3B0
// Name: private: bool CImportMKS::SetPackingMode(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::SetPackingMode(CImportMKS *this, int eMode)
{
  CDmAttribute *Attribute; // ebx
  CDmaVar<int> *m_pData; // eax
  CDmElement *m_pRoot; // edi
  CDmAttribute *v6; // esi
  DmElementArray_t *v7; // esi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  int currentPackingMode; // [esp+14h] [ebp-4h]

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: Attribute, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  m_pRoot = this->m_pRoot;
  currentPackingMode = m_pData->m_Storage;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot == nullptr
    || (v6 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) == nullptr
    && (v6 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
        CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
        v6 == nullptr)
    || (v6->m_nFlags & 0x1F) != 0xF )
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
    goto LABEL_13;
  }
  sequences.m_pAttribute = v6;
  v7 = (DmElementArray_t *)v6->m_pData;
  sequences.m_pStorage = v7;
  if ( v7->m_Size == 0 )
  {
LABEL_13:
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  if ( currentPackingMode == eMode )
    return 1;
  if ( currentPackingMode == 1 && eMode == 2 )
  {
    _Msg(
      a1: "Warning changing packing mode when %d sequences already defined. This may not be serialized correctly.\n",
      v7->m_Size);
    CDmAttribute::SetValue<int>(this: Attribute, value: &eMode);
    return 1;
  }
  else
  {
    _Msg(a1: "*** line error: incompatible packmode change when %d sequences already defined!\n", v7->m_Size);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D4F0
// Name: private: bool CImportMKS::ValidateImagePacking(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::ValidateImagePacking(CImportMKS *this, CDmElement *pBitmap, char *pImageName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi
  CDmaVar<int> *m_pData; // esi
  CDmAttribute *v6; // esi
  CDmAttribute *m_pAttribute; // edx
  DmElementArray_t *m_pStorage; // esi
  int v9; // ecx
  int m_Size; // ecx
  CDmElement *v11; // eax
  CDmElement *v12; // esi
  CDmElement *v13; // edi
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // esi
  CDmaVar<int> *v16; // eax
  CDmAttribute *v17; // eax
  CDmAttribute *v18; // esi
  CDmaVar<int> *v19; // eax
  int m_Storage; // ebx
  CDmAttribute *v21; // esi
  CDmaVar<int> *v22; // esi
  int v23; // edi
  CDmAttribute *v24; // esi
  CDmaVar<int> *v25; // esi
  CDmrElementArray<CDmElement> mapsequences; // [esp+Ch] [ebp-10h] BYREF
  int sequenceNumber; // [esp+14h] [ebp-8h]
  CImportMKS *v29; // [esp+18h] [ebp-4h]
  unsigned __int16 idx; // [esp+24h] [ebp+8h]

  v29 = this;
  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "packmode");
  v4 = Attribute;
  if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
  }
  if ( (Attribute->m_nFlags & 0x1F) == 2 )
  {
    m_pData = (CDmaVar<int> *)Attribute->m_pData;
  }
  else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
  {
    CDmAttribute::CopyDataOut<int>(this: v4, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
    m_pData = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
  }
  else
  {
    m_pData = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
  }
  if ( m_pData->m_Storage == 2 )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapsequences);
    if ( pBitmap != nullptr
      && ((v6 = CDmElement::FindAttribute(this: pBitmap, pAttributeName: "mapsequences")) != nullptr
       || (v6 = CDmElement::CreateAttribute(this: pBitmap, pAttributeName: "mapsequences", type: AT_FIRST_ARRAY_TYPE),
           CDmAttribute::SetElementTypeSymbol(this: v6, typeSymbol: CDmElement::m_classType),
           v6 != nullptr))
      && (v6->m_nFlags & 0x1F) == 0xF )
    {
      m_pAttribute = v6;
      mapsequences.m_pAttribute = v6;
      m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      m_pAttribute = nullptr;
      mapsequences.m_pAttribute = nullptr;
      m_pStorage = nullptr;
    }
    mapsequences.m_pStorage = m_pStorage;
    for ( idx = 0; ; ++idx )
    {
      v9 = m_pAttribute != nullptr ? m_pStorage->m_Size : 0;
      if ( idx >= v9 )
        break;
      if ( m_pAttribute != nullptr )
        m_Size = m_pStorage->m_Size;
      else
        m_Size = 0;
      if ( idx >= m_Size )
      {
        v13 = nullptr;
      }
      else
      {
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[idx]);
        v12 = v11;
        if ( v11 == nullptr || !v11->IsA(this: v11, a2: CDmElement::m_classType) )
          v12 = nullptr;
        v13 = v12;
      }
      v14 = CDmElement::FindAttribute(this: v13, pAttributeName: "sequencenumber");
      v15 = v14;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v14->m_nFlags & 0x1F) == 2 )
      {
        v16 = (CDmaVar<int> *)v14->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v14) )
      {
        CDmAttribute::CopyDataOut<int>(this: v15, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v16 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v16 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      sequenceNumber = v16->m_Storage;
      v17 = CDmElement::FindAttribute(this: v13, pAttributeName: "mode");
      v18 = v17;
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v17->m_nFlags & 0x1F) == 2 )
      {
        v19 = (CDmaVar<int> *)v17->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v17) )
      {
        CDmAttribute::CopyDataOut<int>(this: v18, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v19 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v19 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      m_Storage = v19->m_Storage;
      v21 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "sequencenumber");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v21->m_nFlags & 0x1F) == 2 )
      {
        v22 = (CDmaVar<int> *)v21->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v21) )
      {
        CDmAttribute::CopyDataOut<int>(this: v21, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v22 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v22 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      v23 = v22->m_Storage;
      v24 = CDmElement::FindAttribute(this: v29->m_pCurrentSequence, pAttributeName: "mode");
      if ( (`CDmAttribute::GetValue<int>'::`2'::`local static guard' & 1) == 0 )
      {
        `CDmAttribute::GetValue<int>'::`2'::`local static guard' |= 1u;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_pAttribute = nullptr;
        `CDmAttribute::GetValue<int>'::`2'::defaultVal.m_Storage = 0;
      }
      if ( (v24->m_nFlags & 0x1F) == 2 )
      {
        v25 = (CDmaVar<int> *)v24->m_pData;
      }
      else if ( CDmAttribute::IsTypeConvertable<bool>(this: v24) )
      {
        CDmAttribute::CopyDataOut<int>(this: v24, value: &`CDmAttribute::GetValue<int>'::`7'::tempVal);
        v25 = (CDmaVar<int> *)&`CDmAttribute::GetValue<int>'::`7'::tempVal;
      }
      else
      {
        v25 = &`CDmAttribute::GetValue<int>'::`2'::defaultVal;
      }
      if ( m_Storage != 0 && m_Storage != v25->m_Storage )
      {
        _Msg(
          a1: "*** line error: 'rgb+a' packing cannot pack image '%s' belonging to sequences %d and %d!\n",
          pImageName,
          sequenceNumber,
          v23);
        return 0;
      }
      m_pAttribute = mapsequences.m_pAttribute;
      m_pStorage = mapsequences.m_pStorage;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008D800
// Name: private: bool CImportMKS::CreateNewSequence(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewSequence(CImportMKS *this, int mode)
{
  CDmElement *DmeSequence; // eax
  CDmAttribute *Attribute; // eax
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *v7; // eax
  CDmElement *m_pRoot; // ebx
  CDmAttribute *v9; // esi
  CDmElement *v10; // edi
  CDmrElementArray<CDmElement> sequences; // [esp+Ch] [ebp-Ch] BYREF
  DmElementHandle_t src; // [esp+14h] [ebp-4h] BYREF

  DmeSequence = CImportMKS::CreateDmeSequence(this, pName: "CDmeSheetSequence");
  this->m_pCurrentSequence = DmeSequence;
  if ( DmeSequence == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequence, pAttributeName: "sequencenumber");
  CDmAttribute::SetValue<int>(this: Attribute, value: &this->m_SequenceCount);
  m_pCurrentSequence = this->m_pCurrentSequence;
  ++this->m_SequenceCount;
  v7 = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "mode");
  CDmAttribute::SetValue<int>(this: v7, value: &mode);
  m_pRoot = this->m_pRoot;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sequences);
  if ( m_pRoot != nullptr
    && ((v9 = CDmElement::FindAttribute(this: m_pRoot, pAttributeName: "sequences")) != nullptr
     || (v9 = CDmElement::CreateAttribute(this: m_pRoot, pAttributeName: "sequences", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v9, typeSymbol: CDmElement::m_classType),
         v9 != nullptr))
    && (v9->m_nFlags & 0x1F) == 0xF )
  {
    sequences.m_pAttribute = v9;
    sequences.m_pStorage = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    sequences.m_pAttribute = nullptr;
    sequences.m_pStorage = nullptr;
  }
  v10 = this->m_pCurrentSequence;
  if ( v10 != nullptr )
    src = CVTFTexture::MipCount(this: (CVTFTexture *)v10);
  else
    src = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sequences,
    &src);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008D8F0
// Name: private: class CDmElement __near * CImportMKS::FindImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportMKS::FindImage(CImportMKS *this, const char *pFrameName)
{
  CDmAttribute *Attribute; // esi
  int v3; // edi
  DmElementArray_t *m_pData; // eax
  int m_Size; // ebx
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  const char *m_pAsString; // eax
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  CDmrElementArray<CDmElement> images; // [esp+Ch] [ebp-8h] BYREF

  Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
  v3 = 0;
  if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    images.m_pAttribute = Attribute;
    m_pData = (DmElementArray_t *)Attribute->m_pData;
    images.m_pStorage = m_pData;
    m_Size = m_pData->m_Size;
  }
  else
  {
    m_pData = nullptr;
    images.m_pAttribute = nullptr;
    images.m_pStorage = nullptr;
    m_Size = 0;
  }
  if ( m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
    v8 = v7;
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
      v8 = nullptr;
    m_pAsString = v8->m_Name.m_Storage.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: pFrameName, s2: m_pAsString) == 0 )
      break;
    if ( ++v3 >= m_Size )
      return nullptr;
    m_pData = images.m_pStorage;
  }
  v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: images.m_pStorage->m_Memory.m_pMemory[v3]);
  v11 = v10;
  if ( v10 != nullptr && v10->IsA(this: v10, a2: CDmElement::m_classType) )
    return v11;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008DA00
// Name: private: void CImportMKS::AddImage(class CDmElement __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::AddImage(CImportMKS *this, int pSequenceEntry, int pImageName)
{
  const char *v3; // edi
  CDmAttribute *Attribute; // esi
  CVTFTexture *Image; // edi
  CDmAttribute *v7; // esi
  CDmAttribute *v8; // esi
  CDmElement *m_pCurrentSequence; // ebx
  CDmrElementArray<CDmElement> mapSequences; // [esp+Ch] [ebp-1Ch] BYREF
  CDmrElementArray<CDmElement> sheetImages; // [esp+14h] [ebp-14h] BYREF
  CDmrElementArray<CDmElement> images; // [esp+1Ch] [ebp-Ch] BYREF
  CDmElement *pBitmap; // [esp+24h] [ebp-4h] BYREF

  v3 = (const char *)pImageName;
  if ( CImportMKS::FindImage(this, pFrameName: (const char *)pImageName) == nullptr )
  {
    pBitmap = CImportMKS::CreateDmeSheetImage(this, pImageName: v3);
    if ( pBitmap == nullptr )
      return;
    Attribute = CDmElement::FindAttribute(this: this->m_pRoot, pAttributeName: "images");
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&images);
    if ( Attribute != nullptr && (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      images.m_pAttribute = Attribute;
      images.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
    }
    else
    {
      images.m_pAttribute = nullptr;
      images.m_pStorage = nullptr;
    }
    pBitmap = (CDmElement *)CVTFTexture::MipCount(this: (CVTFTexture *)pBitmap);
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &images,
      src: (DmElementHandle_t *)&pBitmap);
  }
  Image = (CVTFTexture *)CImportMKS::FindImage(this, pFrameName: v3);
  v7 = CDmElement::FindAttribute(this: (CDmElement *)pSequenceEntry, pAttributeName: "sheetimages");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&sheetImages);
  if ( v7 != nullptr && (v7->m_nFlags & 0x1F) == 0xF )
  {
    sheetImages.m_pAttribute = v7;
    sheetImages.m_pStorage = (DmElementArray_t *)v7->m_pData;
  }
  else
  {
    sheetImages.m_pAttribute = nullptr;
    sheetImages.m_pStorage = nullptr;
  }
  if ( Image != nullptr )
    pSequenceEntry = CVTFTexture::MipCount(this: Image);
  else
    pSequenceEntry = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &sheetImages,
    src: (DmElementHandle_t *)&pSequenceEntry);
  if ( CImportMKS::ValidateImagePacking(this, pBitmap: (CDmElement *)Image, (char *)pImageName) == 0 )
    _Warning(a1: "Image packing validation failed!");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&mapSequences);
  if ( Image != nullptr
    && ((v8 = CDmElement::FindAttribute(this: (CDmElement *)Image, pAttributeName: "mapsequences")) != nullptr
     || (v8 = CDmElement::CreateAttribute(
                this: (CDmElement *)Image,
                pAttributeName: "mapsequences",
                type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: v8, typeSymbol: CDmElement::m_classType),
         v8 != nullptr))
    && (v8->m_nFlags & 0x1F) == 0xF )
  {
    mapSequences.m_pAttribute = v8;
    mapSequences.m_pStorage = (DmElementArray_t *)v8->m_pData;
  }
  else
  {
    mapSequences.m_pAttribute = nullptr;
    mapSequences.m_pStorage = nullptr;
  }
  m_pCurrentSequence = this->m_pCurrentSequence;
  if ( m_pCurrentSequence != nullptr )
    pImageName = CVTFTexture::MipCount(this: (CVTFTexture *)m_pCurrentSequence);
  else
    pImageName = -1;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &mapSequences,
    src: (DmElementHandle_t *)&pImageName);
}

//------------------------------------------------------------------------------
// Address: 0x1008DB90
// Name: private: bool CImportMKS::CreateNewFrame(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportMKS::CreateNewFrame(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *imageNames,
        float ftime)
{
  CDmElement *DmeSequenceFrame; // eax
  CVTFTexture *v4; // ebx
  CDmAttribute *Attribute; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v7; // edi
  int i; // esi
  CDmAttribute *v9; // esi
  DmElementArray_t *m_pData; // eax
  CDmrElementArray<CDmElement> currentFrames; // [esp+4h] [ebp-Ch] BYREF
  CImportMKS *v12; // [esp+Ch] [ebp-4h]

  v12 = this;
  DmeSequenceFrame = CImportMKS::CreateDmeSequenceFrame(this, pName: "CDmeSheetSequenceFrame");
  v4 = (CVTFTexture *)DmeSequenceFrame;
  if ( DmeSequenceFrame == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: DmeSequenceFrame, pAttributeName: "displaytime");
  CDmAttribute::SetValue<float>(this: Attribute, value: &ftime);
  v7 = imageNames;
  for ( i = 0; i < v7->m_Size; ++i )
    CImportMKS::AddImage(this: v12, pSequenceEntry: (int)v4, pImageName: (int)v7->m_Memory.m_pMemory[i]);
  v9 = CDmElement::FindAttribute(this: v12->m_pCurrentSequence, pAttributeName: "frames");
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&currentFrames);
  m_pData = nullptr;
  if ( v9 != nullptr && (v9->m_nFlags & 0x1F) == 0xF )
  {
    currentFrames.m_pAttribute = v9;
    m_pData = (DmElementArray_t *)v9->m_pData;
  }
  else
  {
    currentFrames.m_pAttribute = nullptr;
  }
  currentFrames.m_pStorage = m_pData;
  imageNames = (CUtlVector<char *,CUtlMemory<char *,int> > *)CVTFTexture::MipCount(this: v4);
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &currentFrames,
    src: (DmElementHandle_t *)&imageNames);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008DC50
// Name: private: void CImportMKS::ParseFrameImages(class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &,class CUtlVector<char __near *,class CUtlMemory<char __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportMKS::ParseFrameImages(
        CImportMKS *this,
        CUtlVector<char *,CUtlMemory<char *,int> > *words,
        CUtlVector<char *,CUtlMemory<char *,int> > *outImageNames)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // eax
  int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax
  char *fnamebuf; // [esp+10h] [ebp+Ch]

  v3 = words;
  for ( i = 0; i < words->m_Size - 2; ++i )
  {
    m_Size = outImageNames->m_Size;
    fnamebuf = v3->m_Memory.m_pMemory[i + 1];
    m_nAllocationCount = outImageNames->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)outImageNames,
        num: m_Size - m_nAllocationCount + 1);
    ++outImageNames->m_Size;
    m_pMemory = outImageNames->m_Memory.m_pMemory;
    v9 = outImageNames->m_Size - m_Size - 1;
    outImageNames->m_pElements = outImageNames->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &outImageNames->m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = fnamebuf;
    v3 = words;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DCE0
// Name: public: virtual bool CImportMKS::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportMKS::Unserialize(
        CImportMKS *this,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  DmFileId_t v9; // esi
  CDmElement *DmeAmalgamatedTexture; // eax
  CUtlBuffer *v12; // edx
  _BYTE *v13; // eax
  char *v14; // eax
  char *i; // esi
  CDmElement *m_pCurrentSequence; // ecx
  CDmAttribute *Attribute; // eax
  int v18; // eax
  int v20; // esi
  const char *v21; // eax
  char pLine[4096]; // [esp+10h] [ebp-1134h] BYREF
  char pDest[260]; // [esp+1010h] [ebp-134h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > outImageNames; // [esp+1114h] [ebp-30h] BYREF
  float ftime; // [esp+1128h] [ebp-1Ch]
  CUtlVector<char *,CUtlMemory<char *,int> > outStrings; // [esp+112Ch] [ebp-18h] BYREF
  bool value; // [esp+1140h] [ebp-4h] BYREF

  v9 = fileid;
  *ppRoot = nullptr;
  this->m_Fileid = v9;
  DmeAmalgamatedTexture = CImportMKS::CreateDmeAmalgamatedTexture(this, pName: "CDmeAmalgamatedTexture");
  this->m_pRoot = DmeAmalgamatedTexture;
  if ( DmeAmalgamatedTexture == nullptr )
    return false;
  *ppRoot = DmeAmalgamatedTexture;
  this->m_SequenceCount = 0;
  if ( CImportMKS::SetPackingMode(this, eMode: 1) == 0 )
    return false;
  v12 = buf;
  this->m_NumActualLinesRead = 0;
  if ( v12->m_Error == 0 )
  {
    while ( 1 )
    {
      CUtlBuffer::GetLine(this: buf, pLine, nMaxChars: 4096);
      ++this->m_NumActualLinesRead;
      strchr(string: (unsigned __int8 *)pLine, chr: 0xAu);
      if ( v13 != nullptr )
        *v13 = 0;
      v14 = _V_strstr(s1: pLine, search: "//");
      if ( v14 != nullptr )
        *v14 = 0;
      for ( i = pLine; *i == 32 || *i == 9; ++i )
        ;
      if ( *i == 0 )
        goto LABEL_39;
      strlwr(string: i);
      ApplyMacros(in_buf: i);
      memset(&outStrings, 0, sizeof(outStrings));
      V_SplitString(pString: i, pSeparator: " ", &outStrings);
      if ( outStrings.m_Size != 1 || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "loop") != 0 )
      {
        if ( outStrings.m_Size != 2 )
          goto LABEL_32;
        if ( _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "packmode") != 0 )
        {
          if ( outStrings.m_Size != 2
            || StringAfterPrefix(str: *(const char **)outStrings.m_Memory.m_pMemory, prefix: "sequence") == nullptr )
          {
LABEL_32:
            if ( outStrings.m_Size < 3
              || _V_stricmp(s1: *(const char **)outStrings.m_Memory.m_pMemory, s2: "frame") != 0 )
            {
              _Warning(a1: "*** line %d: Bad command \"%s\"!\n", this->m_NumActualLinesRead, i);
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
              return false;
            }
            if ( this->m_pCurrentSequence != nullptr )
            {
              ftime = atof(nptr: outStrings.m_Memory.m_pMemory[outStrings.m_Size - 1]);
              memset(&outImageNames, 0, sizeof(outImageNames));
              CImportMKS::ParseFrameImages(this, words: &outStrings, &outImageNames);
              if ( CImportMKS::CreateNewFrame(this, imageNames: &outImageNames, ftime) == 0 )
              {
                _Warning(a1: "Unable to create new frame.\n");
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outImageNames);
                CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
                return false;
              }
              CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outImageNames);
            }
            else
            {
              _Warning(a1: "Trying to add a frame when there is no current sequence.\n");
            }
            goto LABEL_38;
          }
          if ( atoi(nptr: *((const char **)outStrings.m_Memory.m_pMemory + 1)) != this->m_SequenceCount )
            _Warning(a1: "Sequence number mismatch.\n");
          v20 = CImportMKS::ParseSequenceType(this, word: *outStrings.m_Memory.m_pMemory);
          if ( v20 == 3 || CImportMKS::ValidateSequenceType(this, eMode: v20, word: *outStrings.m_Memory.m_pMemory) == 0 )
          {
            _Warning(a1: "Invalid sequence type.\n");
            goto LABEL_22;
          }
          if ( CImportMKS::CreateNewSequence(this, mode: v20) == 0 )
          {
            _Warning(a1: "Unable to create new sequence.\n");
            goto LABEL_22;
          }
        }
        else
        {
          v18 = CImportMKS::ParsePackingMode(this, word: outStrings.m_Memory.m_pMemory[1]);
          if ( v18 == 0 || CImportMKS::SetPackingMode(this, eMode: v18) == 0 )
          {
            _Warning(a1: "Unable to set packing mode.");
LABEL_22:
            CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
            return false;
          }
        }
      }
      else
      {
        value = false;
        _Warning(a1: "Attempting to set clamp when there is no current sequence!\n");
        m_pCurrentSequence = this->m_pCurrentSequence;
        if ( m_pCurrentSequence != nullptr )
        {
          Attribute = CDmElement::FindAttribute(this: m_pCurrentSequence, pAttributeName: "clamp");
          CDmAttribute::SetValue<bool>(this: Attribute, &value);
        }
      }
LABEL_38:
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &outStrings);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&outStrings);
LABEL_39:
      if ( buf->m_Error != 0 )
      {
        v9 = fileid;
        break;
      }
    }
  }
  v21 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v9);
  V_strncpy(pDest, pSrc: v21, maxLen: 260);
  V_SetExtension(path: pDest, extension: "txt", pathStringLength: 260);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) )
  {
    buf = nullptr;
    if ( g_pDataModel->RestoreFromFile(
           this: g_pDataModel,
           a2: pDest,
           a3: nullptr,
           a4: "tex_source1",
           a5: (CDmElement **)&buf,
           a6: CR_COPY_NEW,
           a7: nullptr) == 0 )
    {
      _Warning(a1: "Error reading texture compile settings file \"%s\"!\n", pDest);
      return false;
    }
    CDmElement::SetFileId(this: (CDmElement *)buf, fileid: this->m_pRoot->m_fileId, depth: TD_DEEP, bOnlyIfMatch: true);
    CDmElement::SetValue<CDmElement>(
      this: this->m_pRoot,
      pAttributeName: "textureCompileSettings",
      pElement: (DmElementHandle_t)buf,
      bCreateIfNotFound: true);
  }
  return g_pDataModel->UpdateUnserializedElements(
           this: g_pDataModel,
           a2: pSourceFormatName,
           a3: nSourceFormatVersion,
           a4: v9,
           a5: idConflictResolution,
           a6: ppRoot);
}

} // namespace vtex_dll
