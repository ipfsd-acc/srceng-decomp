// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importtex.cpp
// Functions: 9
// ============================================================

#include "dmserializers\importtex.h"

//------------------------------------------------------------------------------
// Address: 0x0044A710
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00457BF0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x00457C10
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457CC0
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00457E20
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x00457E30
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x00457E40
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        DmElementHandle_t pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CDmElement::GetHandle(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: &pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00457F30
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = CImportTex::AddProcessor(
            this,
            pElement: (DmElementHandle_t)pTexture,
            pProcessorType: "DmeTP_ChangeColorChannels",
            pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00458490
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = CImportTex::AddProcessor(
              this,
              pElement: (DmElementHandle_t)v16,
              pProcessorType: "DmeTP_ComputeMipmaps",
              pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0046D5F0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x0046D610
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D6C0
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046D820
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x0046D830
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x0046D840
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0046D930
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DE90
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B6B50
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AA0E0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x004AA100
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AA1B0
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AA310
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x004AA320
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x004AA340
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CCodecBuffer_Block::GetBufferType(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004AA430
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AA990
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104B9FB0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x104B9FD0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  char *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = &pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = &v4[strlen(v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: (unsigned __int8 *)v4, count: v6 - v4);
  pOutbuf[v6 - v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BA080
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  char *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = &buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: &buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = &v9[strlen(v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: (unsigned __int8 *)v9, count: v12 - v9);
  v10 = v18 == 0;
  key[v12 - v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104BA1E0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x104BA1F0
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x104BA200
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CCodecBuffer_Block::GetBufferType(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x104BA2F0
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BA850
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004903A0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x004903C0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490470
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004905D0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x004905E0
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x00490600
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        DmElementHandle_t pElement,
        const char *pProcessorType,
        const char *pName)
{
  DmElementHandle_t v4; // edi
  CDmAttribute *Attribute; // esi
  int v6; // eax
  int v7; // eax
  CDmElement *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(
                       this: (CDmElement *)v4,
                       pAttributeName: "processors",
                       type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pProcessorType,
         a3: pName,
         a4: *(_DWORD *)(v4 + 56),
         a5: 0);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v6);
  v8 = (CDmElement *)v7;
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmElement::m_classType.u) != 0 )
  {
    pElement = CDmElement::GetHandle(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: &pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004906F0
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = CImportTex::AddProcessor(
            this,
            pElement: (DmElementHandle_t)pTexture,
            pProcessorType: "DmeTP_ChangeColorChannels",
            pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00490C50
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  int v13; // edx
  int v14; // eax
  int v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = *(_DWORD *)g_pDataModel.u.m_Id;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD, int, int, int))(v13 + 60))(
          a1: g_pDataModel.u,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v14);
  v16 = (CDmElement *)v15;
  if ( v15 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
         a1: v15,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v16 = nullptr;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = CImportTex::AddProcessor(
              this,
              pElement: (DmElementHandle_t)v16,
              pProcessorType: "DmeTP_ComputeMipmaps",
              pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
               a1: g_pDataModel.u,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B84D0
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00513FA0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x00513FC0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00514070
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005141D0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x005141E0
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x005141F0
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00514210
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CVTFTexture *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CVTFTexture *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CVTFTexture::MipCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00514300
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00514860
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0041D1D0
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D45A0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x004D45C0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4670
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D47D0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x004D47E0
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x004D4810
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  int v4; // edi
  CDmAttribute *Attribute; // esi
  int v6; // eax
  int v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(
                       this: (CDmElement *)v4,
                       pAttributeName: "processors",
                       type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pProcessorType,
         a3: pName,
         a4: *(_DWORD *)(v4 + 56),
         a5: 0);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmElement::m_classType.u) != 0 )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004D4900
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D4E60
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  int v13; // edx
  int v14; // eax
  int v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = *(_DWORD *)g_pDataModel.u.m_Id;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD, int, int, int))(v13 + 60))(
          a1: g_pDataModel.u,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v14);
  v16 = (CDmElement *)v15;
  if ( v15 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
         a1: v15,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v16 = nullptr;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
               a1: g_pDataModel.u,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x004596C0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x004596E0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459790
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004598F0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x00459900
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x00459910
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        DmElementHandle_t pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CCodecBuffer_Block::GetBufferType(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: &pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00459A00
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = CImportTex::AddProcessor(
            this,
            pElement: (DmElementHandle_t)pTexture,
            pProcessorType: "DmeTP_ChangeColorChannels",
            pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459F70
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = CImportTex::AddProcessor(
              this,
              pElement: (DmElementHandle_t)v16,
              pProcessorType: "DmeTP_ComputeMipmaps",
              pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045B850
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0045B1C0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x0045B1E0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045B290
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045B3F0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x0045B400
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x0045B420
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0045B510
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045BA70
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0044C120
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00459660
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x00459680
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00459730
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00459890
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x004598A0
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x004598C0
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        DmElementHandle_t pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CDmElement::GetHandle(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = DMELEMENT_HANDLE_INVALID;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: &pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004599B0
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = CImportTex::AddProcessor(
            this,
            pElement: (DmElementHandle_t)pTexture,
            pProcessorType: "DmeTP_ChangeColorChannels",
            pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00459F10
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = CImportTex::AddProcessor(
              this,
              pElement: (DmElementHandle_t)v16,
              pProcessorType: "DmeTP_ComputeMipmaps",
              pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00403B80
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045E5E0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x0045E600
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045E6B0
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045E810
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x0045E820
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x0045E830
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0045E920
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EE80
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = (CDmaVar<bool> *)CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !*CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod") )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B4720
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x004B4740
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B47F0
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B4950
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x004B4960
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x004B4980
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  int v4; // edi
  CDmAttribute *Attribute; // esi
  int v6; // eax
  int v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(
                       this: (CDmElement *)v4,
                       pAttributeName: "processors",
                       type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pProcessorType,
         a3: pName,
         a4: *(_DWORD *)(v4 + 56),
         a5: 0);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmElement::m_classType.u) != 0 )
  {
    pElement = CCodecBuffer_Block::GetBufferType(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004B4A70
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B4FD0
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  int v13; // edx
  int v14; // eax
  int v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = *(_DWORD *)g_pDataModel.u.m_Id;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD, int, int, int))(v13 + 60))(
          a1: g_pDataModel.u,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v14);
  v16 = (CDmElement *)v15;
  if ( v15 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
         a1: v15,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v16 = nullptr;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
               a1: g_pDataModel.u,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0045F190
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x0045F1B0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045F260
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045F3C0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x0045F3D0
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x0045F3F0
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0045F4E0
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045FA40
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n");
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00464160
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004CDB50
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x004CDB70
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CDC20
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004CDD80
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x004CDD90
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x004CDDA0
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  int v4; // edi
  CDmAttribute *Attribute; // esi
  int v6; // eax
  int v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(
                       this: (CDmElement *)v4,
                       pAttributeName: "processors",
                       type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pProcessorType,
         a3: pName,
         a4: *(_DWORD *)(v4 + 56),
         a5: 0);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmElement::m_classType.u) != 0 )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004CDE90
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004CE3F0
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  int v13; // edx
  int v14; // eax
  int v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = *(_DWORD *)g_pDataModel.u.m_Id;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int, _DWORD, int, int, int))(v13 + 60))(
          a1: g_pDataModel.u,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: v14);
  v16 = (CDmElement *)v15;
  if ( v15 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v15 + 16))(
         a1: v15,
         a2: CDmElement::m_classType.u) == 0 )
  {
    v16 = nullptr;
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, DmFileId_t, DmConflictResolution_t, CDmElement **))(*(_DWORD *)g_pDataModel.u.m_Id + 164))(
               a1: g_pDataModel.u,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D2960
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00455C60
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00469A30
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x00469A50
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  char *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = &pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = &v4[strlen(v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: (unsigned __int8 *)v4, count: v6 - v4);
  pOutbuf[v6 - v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00469B00
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  char *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = &buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: &buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = &v9[strlen(v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: (unsigned __int8 *)v9, count: v12 - v9);
  v10 = v18 == 0;
  key[v12 - v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00469C60
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x00469C70
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x00469C80
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpressionCalculator *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CExpressionCalculator *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CExpressionCalculator *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CExpressionCalculator::VariableCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00469D70
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046A2D0
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005612C0
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x005612E0
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00561390
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005614F0
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x00561500
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x00561510
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CVTFTexture *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CVTFTexture *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CCoreDispNode::GetCenterVertIndex(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00561600
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00561B60
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = (CDmaVar<bool> *)CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod")->m_Storage )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005894B0
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10023C00
// Name: public: virtual int CImportTex::GetCurrentVersion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CImportTex::GetCurrentVersion(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008C130
// Name: void InstallTEXImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallTEXImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportTex);
}

//------------------------------------------------------------------------------
// Address: 0x1008C150
// Name: private: char const __near * CImportTex::GetPossiblyQuotedWord(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetPossiblyQuotedWord(CImportTex *this, char *pInBuf, char *pOutbuf)
{
  int v3; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  const char *v8; // eax
  const char *result; // eax
  char bQuote_3; // [esp+13h] [ebp+Bh]

  strspn(string: (unsigned __int8 *)pInBuf, control: " \t");
  v4 = (unsigned __int8 *)&pInBuf[v3];
  bQuote_3 = 0;
  if ( *v4 == 34 )
  {
    strchr(string: ++v4, chr: 0x22u);
    v6 = v5;
    bQuote_3 = 1;
  }
  else
  {
    strchr(string: v4, chr: 0x20u);
    v6 = v7;
    if ( v7 != nullptr )
      goto LABEL_7;
    strchr(string: v4, chr: 9u);
    v6 = v8;
    if ( v8 != nullptr )
      goto LABEL_7;
    v6 = (const char *)&v4[strlen((const char *)v4)];
  }
  if ( v6 == nullptr )
    return nullptr;
LABEL_7:
  if ( v6 == (const char *)v4 )
    return nullptr;
  memcpy(dst: (unsigned __int8 *)pOutbuf, src: v4, count: v6 - (const char *)v4);
  pOutbuf[v6 - (const char *)v4] = 0;
  result = v6;
  if ( bQuote_3 != 0 )
    return v6 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008C200
// Name: private: bool CImportTex::GetKeyValueFromBuffer(class CUtlBuffer __near &,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::GetKeyValueFromBuffer(CImportTex *this, CUtlBuffer *buffer, char *key, char *val)
{
  CUtlBuffer *v4; // ebx
  int v5; // eax
  _BYTE *v6; // eax
  _BYTE *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi
  bool v10; // zf
  char *v11; // eax
  char *v12; // edi
  char *v13; // eax
  char *v14; // eax
  char buf[2048]; // [esp+Ch] [ebp-808h] BYREF
  CImportTex *v17; // [esp+80Ch] [ebp-8h]
  char v18; // [esp+813h] [ebp-1h]

  v4 = buffer;
  v5 = buffer->m_nMaxPut - buffer->m_Get;
  v17 = this;
  if ( v5 == 0 )
  {
LABEL_18:
    *val = 0;
    return 0;
  }
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: v4, pLine: buf, nMaxChars: 2048);
    strpbrk(string: (unsigned __int8 *)buf, control: "#\n\r");
    if ( v6 != nullptr )
      *v6 = 0;
    strstr(str1: (unsigned __int8 *)buf, str2: "//");
    if ( v7 != nullptr )
      *v7 = 0;
    strspn(string: (unsigned __int8 *)buf, control: " \t");
    v9 = (unsigned __int8 *)&buf[v8];
    v10 = buf[v8] == 34;
    v18 = 0;
    if ( v10 )
    {
      strchr(string: ++v9, chr: 0x22u);
      v12 = v11;
      v18 = 1;
      goto LABEL_11;
    }
    strchr(string: (unsigned __int8 *)&buf[v8], chr: 0x20u);
    v12 = v13;
    if ( v13 != nullptr )
      break;
    strchr(string: v9, chr: 9u);
    v12 = v14;
    if ( v14 != nullptr )
      break;
    v12 = (char *)&v9[strlen((const char *)v9)];
LABEL_11:
    if ( v12 != nullptr )
      break;
LABEL_17:
    if ( v4->m_nMaxPut == v4->m_Get )
      goto LABEL_18;
  }
  if ( v12 == (char *)v9 )
    goto LABEL_17;
  memcpy(dst: (unsigned __int8 *)key, src: v9, count: v12 - (char *)v9);
  v10 = v18 == 0;
  key[v12 - (char *)v9] = 0;
  if ( !v10 )
    ++v12;
  if ( v12 == nullptr )
  {
    v4 = buffer;
    goto LABEL_17;
  }
  if ( CImportTex::GetPossiblyQuotedWord(this: v17, pInBuf: v12, pOutbuf: val) != nullptr )
    return 1;
  sprintf(string: val, format: "parameter %s has no value", key);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008C360
// Name: public: virtual char const __near * CImportTex::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetName(CImportTex *this)
{
  return "tex_source1";
}

//------------------------------------------------------------------------------
// Address: 0x1008C370
// Name: public: virtual char const __near * CImportTex::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportTex::GetDescription(CImportTex *this)
{
  return "Valve Texture Configuration File";
}

//------------------------------------------------------------------------------
// Address: 0x1008C380
// Name: private: class CDmElement __near * CImportTex::AddProcessor(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CImportTex::AddProcessor(
        CImportTex *this,
        int pElement,
        const char *pProcessorType,
        const char *pName)
{
  CDmElement *v4; // edi
  CDmAttribute *Attribute; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CVTFTexture *v8; // esi
  CDmrElementArray<CDmElement> processors; // [esp+8h] [ebp-8h] BYREF

  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&processors);
  v4 = (CDmElement *)pElement;
  if ( pElement != 0
    && ((Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "processors")) != nullptr
     || (Attribute = CDmElement::CreateAttribute(this: v4, pAttributeName: "processors", type: AT_FIRST_ARRAY_TYPE),
         CDmAttribute::SetElementTypeSymbol(this: Attribute, typeSymbol: CDmElement::m_classType),
         Attribute != nullptr))
    && (Attribute->m_nFlags & 0x1F) == 0xF )
  {
    processors.m_pAttribute = Attribute;
    processors.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
  }
  else
  {
    processors.m_pAttribute = nullptr;
    processors.m_pStorage = nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pProcessorType, a3: pName, a4: v4->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = (CVTFTexture *)v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    pElement = CVTFTexture::MipCount(this: v8);
  }
  else
  {
    v8 = nullptr;
    pElement = -1;
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: &processors,
    src: (const DmElementHandle_t *)&pElement);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1008C470
// Name: private: bool CImportTex::ParseOptionKey(char const __near *,char const __near *,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportTex::ParseOptionKey(CImportTex *this, const char *pKeyName, int pKeyValue, CDmElement *pTexture)
{
  const char *v4; // ebx
  CDmElement *v6; // esi
  CDmAttribute *Attribute; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // esi
  CDmAttribute *v10; // eax
  CDmElement *v11; // esi
  CDmElement *v13; // esi
  CDmAttribute *v14; // eax
  CDmElement *v15; // esi
  CDmElement *v16; // esi
  CDmElement *v17; // esi
  CDmElement *v18; // esi
  CDmElement *v19; // esi
  CDmElement *v20; // esi
  CDmElement *v21; // esi
  CDmElement *v22; // esi
  CDmElement *v23; // esi
  CDmElement *v24; // esi
  int iValue; // [esp+Ch] [ebp-4h] BYREF

  v4 = (const char *)pKeyValue;
  iValue = atoi(nptr: (const char *)pKeyValue);
  if ( _V_stricmp(s1: pKeyName, s2: "startframe") == 0 )
  {
    v6 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "startFrame");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v6, pAttributeName: "startFrame", type: AT_INT);
      goto LABEL_68;
    }
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "endframe") == 0 )
  {
    v8 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "endFrame");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v8, pAttributeName: "endFrame", type: AT_INT);
    goto LABEL_14;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "cubemap") == 0 )
  {
    v9 = pTexture;
    pKeyValue = iValue != 0;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "textureType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v9, pAttributeName: "textureType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
LABEL_41:
    CDmAttribute::SetValue<int>(this: v10, value: &pKeyValue);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "volumetexture") == 0 )
  {
    v11 = pTexture;
    Attribute = CDmElement::FindAttribute(this: pTexture, pAttributeName: "volumeTextureDepth");
    if ( Attribute != nullptr )
      goto LABEL_15;
    Attribute = CDmElement::CreateAttribute(this: v11, pAttributeName: "volumeTextureDepth", type: AT_INT);
LABEL_14:
    if ( Attribute != nullptr )
      goto LABEL_15;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clamps") == 0 )
  {
    v13 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clamps");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v13, pAttributeName: "clamps", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampt") == 0 )
  {
    v15 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampt");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v15, pAttributeName: "clampt", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "clampu") == 0 )
  {
    v16 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "clampu");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v16, pAttributeName: "clampu", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nodebug") == 0 )
  {
    v17 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noDebugOverride");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v17, pAttributeName: "noDebugOverride", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "pointsample") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 4;
    goto LABEL_39;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "trilinear") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    v18 = pTexture;
    pKeyValue = 2;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v18, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "anisotropic") == 0 )
  {
    if ( iValue == 0 )
      return 1;
    pKeyValue = 1;
LABEL_39:
    v19 = pTexture;
    v10 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "filterType");
    if ( v10 == nullptr )
    {
      v10 = CDmElement::CreateAttribute(this: v19, pAttributeName: "filterType", type: AT_INT);
      if ( v10 == nullptr )
        return 1;
    }
    goto LABEL_41;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nomip") == 0 )
  {
    v20 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noMip");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v20, pAttributeName: "noMip", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nolod") == 0 )
  {
    v21 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noLod");
    if ( v14 != nullptr )
      goto LABEL_59;
    v14 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noLod", type: AT_BOOL);
    goto LABEL_63;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nonice") == 0 )
  {
    this->m_bNoNice = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest") == 0 )
  {
    this->m_bAlphatestMipmapping = iValue != 0;
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "alphatest_hifreq_threshhold") == 0 )
  {
    this->m_flAlphatestMipmapHiFreqThreshhold = atof(nptr: v4);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "dxt5") == 0 )
  {
    v22 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "hintDxt5Compression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v22, pAttributeName: "hintDxt5Compression", type: AT_BOOL);
      if ( v14 == nullptr )
        return 1;
    }
    goto LABEL_59;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "nocompress") == 0 )
  {
    v23 = pTexture;
    HIBYTE(pKeyValue) = iValue != 0;
    v14 = CDmElement::FindAttribute(this: pTexture, pAttributeName: "noCompression");
    if ( v14 == nullptr )
    {
      v14 = CDmElement::CreateAttribute(this: v23, pAttributeName: "noCompression", type: AT_BOOL);
LABEL_63:
      if ( v14 == nullptr )
        return 1;
    }
LABEL_59:
    CDmAttribute::SetValue<bool>(this: v14, value: (const bool *)&pKeyValue + 3);
    return 1;
  }
  if ( _V_stricmp(s1: pKeyName, s2: "numchannels") == 0 )
  {
    v24 = (CDmElement *)CImportTex::AddProcessor(
                          this,
                          pElement: (int)pTexture,
                          pProcessorType: "DmeTP_ChangeColorChannels",
                          pName: "changeColorChannels");
    Attribute = CDmElement::FindAttribute(this: v24, pAttributeName: "maxChannels");
    if ( Attribute == nullptr )
    {
      Attribute = CDmElement::CreateAttribute(this: v24, pAttributeName: "maxChannels", type: AT_INT);
LABEL_68:
      if ( Attribute != nullptr )
        goto LABEL_15;
      return 1;
    }
LABEL_15:
    CDmAttribute::SetValue<int>(this: Attribute, value: &iValue);
    return 1;
  }
  _Warning(a1: "unrecognized option in text file - %s\n", pKeyName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008C9D0
// Name: public: virtual bool CImportTex::Unserialize(class CUtlBuffer __near &,char const __near *,int,char const __near *,int,enum DmFileId_t,enum DmConflictResolution_t,class CDmElement __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CImportTex::Unserialize@<al>(
        CImportTex *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CUtlBuffer *buf,
        const char *pEncodingName,
        int nEncodingVersion,
        const char *pSourceFormatName,
        int nSourceFormatVersion,
        DmFileId_t fileid,
        DmConflictResolution_t idConflictResolution,
        CDmElement **ppRoot)
{
  IDataModel_vtbl *v13; // edx
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CDmElement *v16; // edi
  CDmAttribute *Attribute; // eax
  bool result; // al
  CDmAttribute *v19; // eax
  CDmaVar<bool> *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  char key[2048]; // [esp+0h] [ebp-1014h] BYREF
  char val[2048]; // [esp+800h] [ebp-814h] BYREF
  bool *p_m_bNoNice; // [esp+1000h] [ebp-14h]
  bool *p_m_bAlphatestMipmapping; // [esp+1004h] [ebp-10h]
  float *p_m_flAlphatestMipmapHiFreqThreshhold; // [esp+1008h] [ebp-Ch]
  CUtlSymbolLarge value; // [esp+100Ch] [ebp-8h] BYREF
  float *p_m_flAlphatestMipmapThreshhold; // [esp+1010h] [ebp-4h]

  *ppRoot = nullptr;
  this->m_bAlphatestMipmapping = false;
  p_m_bAlphatestMipmapping = &this->m_bAlphatestMipmapping;
  this->m_bNoNice = false;
  p_m_bNoNice = &this->m_bNoNice;
  this->m_flAlphatestMipmapHiFreqThreshhold = 0.0;
  p_m_flAlphatestMipmapHiFreqThreshhold = &this->m_flAlphatestMipmapHiFreqThreshhold;
  this->m_flAlphatestMipmapThreshhold = 0.0;
  v13 = g_pDataModel->__vftable;
  p_m_flAlphatestMipmapThreshhold = &this->m_flAlphatestMipmapThreshhold;
  v14 = ((int (__thiscall *)(IDataModel *, const char *, const char *, int, _DWORD, int, int, int))v13->CreateElement)(
          a1: g_pDataModel,
          a2: "DmePrecompiledTexture",
          a3: "root",
          a4: -1,
          a5: 0,
          a6: a3,
          a7: a4,
          a8: a2);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmElement::m_classType) )
    v16 = nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "__unspecified_texture");
  Attribute = CDmElement::FindAttribute(this: v16, pAttributeName: "imageFileName");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v16, pAttributeName: "imageFileName", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  while ( CImportTex::GetKeyValueFromBuffer(this, buffer: buf, key, val) != 0 )
    CImportTex::ParseOptionKey(this, pKeyName: key, pKeyValue: (int)val, pTexture: v16);
  if ( val[0] != 0 )
  {
    _Warning(a1: "Error importing txt file! %s\n", val);
    return false;
  }
  else
  {
    if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
    }
    v19 = CDmElement::FindAttribute(this: v16, pAttributeName: "noMip");
    if ( v19 != nullptr )
      v20 = (CDmaVar<bool> *)CDmAttribute::GetValue<bool>(this: v19);
    else
      v20 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
    if ( !v20->m_Storage || !*CDmElement::GetValue<bool>(this: v16, pAttributeName: "noLod") )
    {
      v21 = (CDmElement *)CImportTex::AddProcessor(
                            this,
                            pElement: (int)v16,
                            pProcessorType: "DmeTP_ComputeMipmaps",
                            pName: "computeMipmaps");
      v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "noNiceFiltering");
      if ( v22 != nullptr
        || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "noNiceFiltering", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v22, value: p_m_bNoNice);
      }
      v23 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampling");
      if ( v23 != nullptr
        || (v23 = CDmElement::CreateAttribute(this: v21, pAttributeName: "alphaTestDownsampling", type: AT_BOOL)) != nullptr )
      {
        CDmAttribute::SetValue<bool>(this: v23, value: p_m_bAlphatestMipmapping);
      }
      v24 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleThreshhold");
      if ( v24 != nullptr
        || (v24 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v24, value: p_m_flAlphatestMipmapThreshhold);
      }
      v25 = CDmElement::FindAttribute(this: v21, pAttributeName: "alphaTestDownsampleHiFreqThreshhold");
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(
                    this: v21,
                    pAttributeName: "alphaTestDownsampleHiFreqThreshhold",
                    type: AT_FLOAT)) != nullptr )
      {
        CDmAttribute::SetValue<float>(this: v25, value: p_m_flAlphatestMipmapHiFreqThreshhold);
      }
    }
    *ppRoot = v16;
    result = g_pDataModel->UpdateUnserializedElements(
               this: g_pDataModel,
               a2: pSourceFormatName,
               a3: nSourceFormatVersion,
               a4: fileid,
               a5: idConflictResolution,
               a6: ppRoot);
    if ( !result )
      *ppRoot = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100245E0
// Name: sub_100245E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100245E0(int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // eax
  double v5; // st6
  int i; // edi
  double *v7; // edx
  int v8; // esi
  double v9; // st7
  double *v10; // eax
  int v11; // ecx
  double v12; // st6
  int j; // eax
  __int16 v14; // fps
  bool v15; // c0
  char v16; // c2
  bool v17; // c3
  __int16 v18; // fps
  bool v19; // c0
  char v20; // c2
  bool v21; // c3
  int v22; // ecx
  __int16 v23; // fps
  bool v24; // c0
  char v25; // c2
  bool v26; // c3
  int result; // eax
  double *v28; // edx
  double v29; // st7
  double *v30; // ecx
  double v31; // st7
  double v32; // [esp+0h] [ebp-8h]

  v3 = a1;
  dbl_101469F8 = 0.0;
  dbl_101469E0 = 0.0;
  dbl_101469D8 = 0.0;
  dbl_101469C8 = 0.0;
  dbl_101469C0 = 0.0;
  dbl_101469B8[0] = 0.0;
  if ( a1 > 0 )
  {
    v4 = a2 + 16;
    do
    {
      v5 = *(double *)(v4 - 16) * *(double *)(v4 - 16);
      v4 += 24;
      --v3;
      dbl_101469B8[0] = v5 + dbl_101469B8[0];
      dbl_101469C0 = *(double *)(v4 - 32) * *(double *)(v4 - 40) + dbl_101469C0;
      dbl_101469C8 = *(double *)(v4 - 24) * *(double *)(v4 - 40) + dbl_101469C8;
      dbl_101469D8 = *(double *)(v4 - 32) * *(double *)(v4 - 32) + dbl_101469D8;
      dbl_101469E0 = *(double *)(v4 - 24) * *(double *)(v4 - 32) + dbl_101469E0;
      dbl_101469F8 = *(double *)(v4 - 24) * *(double *)(v4 - 24) + dbl_101469F8;
    }
    while ( v3 != 0 );
  }
  for ( i = 3; i != 0; --i )
  {
    v7 = dbl_101469B8;
    v8 = 0;
    dbl_10149D00 = dbl_101469B8[0] + dbl_101469D8 + dbl_101469F8;
    v9 = 3.5 / dbl_10149D00;
    if ( (int)dbl_101469B8 >= (int)&X )
      goto LABEL_8;
    do
    {
      v10 = v7;
      v11 = 3 - v8;
      do
      {
        v12 = v9 * *v10++;
        --v11;
        *(v10 - 1) = v12;
      }
      while ( v11 != 0 );
LABEL_8:
      v7 += 4;
      ++v8;
    }
    while ( (int)v7 < (int)&X );
    for ( j = 4; j != 0; --j )
    {
      dbl_10149F90[0] = dbl_101469B8[0] * dbl_101469B8[0] + dbl_101469C8 * dbl_101469C8 + dbl_101469C0 * dbl_101469C0;
      dbl_10149F98 = (dbl_101469B8[0] + dbl_101469D8) * dbl_101469C0 + dbl_101469C8 * dbl_101469E0;
      dbl_10149FA0 = (dbl_101469B8[0] + dbl_101469F8) * dbl_101469C8 + dbl_101469C0 * dbl_101469E0;
      dbl_10149FB0 = dbl_101469D8 * dbl_101469D8 + dbl_101469E0 * dbl_101469E0 + dbl_101469C0 * dbl_101469C0;
      dbl_10149FB8 = (dbl_101469D8 + dbl_101469F8) * dbl_101469E0 + dbl_101469C0 * dbl_101469C8;
      dbl_10149FD0 = dbl_101469F8 * dbl_101469F8 + dbl_101469E0 * dbl_101469E0 + dbl_101469C8 * dbl_101469C8;
      dbl_101469B8[0] = dbl_10149F90[0] * dbl_10149F90[0] + dbl_10149F98 * dbl_10149F98 + dbl_10149FA0 * dbl_10149FA0;
      dbl_101469C0 = (dbl_10149FB0 + dbl_10149F90[0]) * dbl_10149F98 + dbl_10149FB8 * dbl_10149FA0;
      dbl_101469C8 = (dbl_10149FD0 + dbl_10149F90[0]) * dbl_10149FA0 + dbl_10149FB8 * dbl_10149F98;
      v32 = dbl_10149FB8 * dbl_10149FB8;
      dbl_101469D8 = dbl_10149FB0 * dbl_10149FB0 + v32 + dbl_10149F98 * dbl_10149F98;
      dbl_101469E0 = (dbl_10149FD0 + dbl_10149FB0) * dbl_10149FB8 + dbl_10149FA0 * dbl_10149F98;
      dbl_101469F8 = dbl_10149FD0 * dbl_10149FD0 + v32 + dbl_10149FA0 * dbl_10149FA0;
    }
  }
  v15 = dbl_101469B8[0] < dbl_101469D8;
  v16 = 0;
  v17 = dbl_101469B8[0] == dbl_101469D8;
  if ( (v14 & 0x4100) != 0 )
  {
    v24 = dbl_101469D8 < dbl_101469F8;
    v25 = 0;
    v26 = dbl_101469D8 == dbl_101469F8;
    v22 = 1;
    if ( (v23 & 0x4100) == 0 )
      goto LABEL_17;
LABEL_16:
    v22 = 2;
    goto LABEL_17;
  }
  v19 = dbl_101469B8[0] < dbl_101469F8;
  v20 = 0;
  v21 = dbl_101469B8[0] == dbl_101469F8;
  if ( (v18 & 0x4100) != 0 )
    goto LABEL_16;
  v22 = 0;
LABEL_17:
  result = 0;
  dbl_10147B08 = 1.0 / sqrt(dbl_101469B8[4 * v22]);
  if ( v22 <= 0 )
    goto LABEL_21;
  v28 = &dbl_10149F90[v22];
  do
  {
    v29 = dbl_10147B08 * *v28;
    ++result;
    v28 += 3;
    *(double *)(a3 + 8 * result - 8) = v29;
  }
  while ( result < v22 );
  if ( result < 3 )
  {
LABEL_21:
    v30 = &dbl_10149F90[2 * v22 + result + v22];
    do
    {
      v31 = dbl_10147B08 * *v30;
      ++result;
      ++v30;
      *(double *)(a3 + 8 * result - 8) = v31;
    }
    while ( result < 3 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100249E0
// Name: sub_100249E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double *__cdecl sub_100249E0(int a1, int a2, double *a3)
{
  int v3; // ebx
  int v4; // esi
  double *v5; // edi
  int v6; // ecx
  double *v7; // edx
  double v8; // st6
  double v9; // st3
  __int16 v10; // fps
  bool v11; // c0
  char v12; // c2
  bool v13; // c3
  double *result; // eax
  double *v15; // ecx
  int v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]

  v3 = a1;
  v4 = 0;
  dbl_10145EE8 = 0.0;
  if ( a1 > 0 )
  {
    v5 = (double *)(a2 + 16);
    do
    {
      v6 = v4;
      if ( v4 < v3 )
      {
        v7 = v5;
        do
        {
          v8 = *(v5 - 1) - *(v7 - 1);
          v9 = *(v5 - 2) - *(v7 - 2);
          dbl_10148168 = (*v5 - *v7) * (*v5 - *v7) + v8 * v8 + v9 * v9;
          v11 = dbl_10148168 < dbl_10145EE8;
          v12 = 0;
          v13 = dbl_10148168 == dbl_10145EE8;
          if ( (v10 & 0x4100) == 0 )
          {
            v3 = a1;
            dbl_10145EE8 = dbl_10148168;
            v16 = v4;
            v17 = v6;
          }
          ++v6;
          v7 += 3;
        }
        while ( v6 < v3 );
      }
      ++v4;
      v5 += 3;
    }
    while ( v4 < v3 );
  }
  result = (double *)(a2 + 24 * v16);
  v15 = (double *)(a2 + 24 * v17);
  dbl_10145EE8 = 1.0 / sqrt(dbl_10145EE8);
  *a3 = (*result - *v15) * dbl_10145EE8;
  a3[1] = (result[1] - v15[1]) * dbl_10145EE8;
  a3[2] = (result[2] - v15[2]) * dbl_10145EE8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024AF0
// Name: sub_10024AF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_10024AF0(signed int a1, int a2, double *a3, int a4, int a5)
{
  signed int v5; // ebx
  int v6; // edx
  double v7; // st7
  double v8; // st6
  signed int v9; // ebx
  signed int i; // ecx
  signed int v11; // edi
  signed int v12; // ecx
  signed int v13; // ebp
  signed int j; // ecx
  signed int v15; // edi
  signed int v16; // ecx
  signed int v17; // ebp
  _DWORD v18[48]; // [esp+10h] [ebp-C0h] BYREF

  v5 = 0;
  if ( a1 > 0 )
  {
    v6 = a2 + 8;
    memset32(v18, 1, a1);
    do
    {
      v7 = *(double *)(v6 + 8) * a3[2];
      v8 = *(double *)(v6 - 8) * *a3;
      ++v5;
      v6 += 24;
      *(&X + v5) = v7 + v8 + a3[1] * *(double *)(v6 - 24);
    }
    while ( v5 < a1 );
  }
  v9 = 0;
  if ( a5 != 0 )
  {
    if ( a1 > 0 )
    {
      do
      {
        for ( i = 0; i < a1; ++i )
        {
          if ( v18[i] != 0 )
            break;
        }
        v11 = i;
        v12 = i + 1;
        if ( v12 < a1 )
        {
          v13 = v11;
          do
          {
            if ( v18[v12] != 0 && dbl_10146A20[v12] <= dbl_10146A20[v13] )
            {
              v11 = v12;
              v13 = v12;
            }
            ++v12;
          }
          while ( v12 < a1 );
        }
        ++v9;
        v18[v11] = 0;
        *(_DWORD *)(a4 + 4 * v9 - 4) = v11;
      }
      while ( v9 < a1 );
    }
  }
  else if ( a1 > 0 )
  {
    do
    {
      for ( j = 0; j < a1; ++j )
      {
        if ( v18[j] != 0 )
          break;
      }
      v15 = j;
      v16 = j + 1;
      if ( v16 < a1 )
      {
        v17 = v15;
        do
        {
          if ( v18[v16] != 0 && dbl_10146A20[v16] < dbl_10146A20[v17] )
          {
            v15 = v16;
            v17 = v16;
          }
          ++v16;
        }
        while ( v16 < a1 );
      }
      ++v9;
      v18[v15] = 0;
      *(_DWORD *)(a4 + 4 * v9 - 4) = v15;
    }
    while ( v9 < a1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024C40
// Name: sub_10024C40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_10024C40(int a1, int a2, _DWORD *a3)
{
  int v3; // eax
  _DWORD *i; // edx
  _DWORD *v6; // edx

  v3 = 0;
  if ( a1 > 0 )
  {
    for ( i = a3; *(_DWORD *)((char *)i + a2 - (_DWORD)a3) == *i; ++i )
    {
      if ( ++v3 >= a1 )
        return v3 == a1;
    }
    if ( v3 < a1 )
    {
      v3 = 0;
      v6 = &a3[a1 - 1];
      do
      {
        if ( *(_DWORD *)(a2 + 4 * v3) != *v6 )
          break;
        ++v3;
        --v6;
      }
      while ( v3 < a1 );
    }
  }
  return v3 == a1;
}

//------------------------------------------------------------------------------
// Address: 0x10024CB0
// Name: sub_10024CB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_10024CB0(int *a1, int a2, int a3, int a4, int *a5, int a6, int a7)
{
  int v7; // edx
  _DWORD *v9; // ecx
  double *v10; // edi
  int v11; // edx
  int v12; // eax
  int v13; // eax
  double *v14; // eax
  int v15; // edi
  double *v16; // ebx
  int v17; // ecx
  double *v18; // esi
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double *v23; // eax
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st6
  int v29; // esi
  int v30; // ecx
  double v31; // st5
  int v32; // edi
  double v33; // st4
  double v34; // st3
  int v35; // edx
  double v36; // st2
  double *v37; // eax
  double v38; // st1
  double *v39; // eax
  int v40; // ecx
  int v41; // edx
  double v42; // st7
  double v43; // st6
  int v44; // eax
  int i; // [esp+10h] [ebp-28h]
  double *v47; // [esp+10h] [ebp-28h]
  double v48; // [esp+10h] [ebp-28h]
  double *v49; // [esp+1Ch] [ebp-1Ch]
  int v50; // [esp+1Ch] [ebp-1Ch]
  double *v51; // [esp+20h] [ebp-18h]
  int v52; // [esp+20h] [ebp-18h]
  double v53; // [esp+20h] [ebp-18h]
  int v54; // [esp+28h] [ebp-10h]
  int v55; // [esp+2Ch] [ebp-Ch]
  int v56; // [esp+30h] [ebp-8h]
  int v57; // [esp+34h] [ebp-4h]

  v7 = a2;
  if ( a2 > 0 )
  {
    v9 = &unk_10146370;
    v10 = dbl_10147FD0;
    for ( i = a2; i != 0; --i )
    {
      v11 = 0;
      do
      {
        v9 += 2;
        v12 = v11 + 2 * *a5 + *a5;
        ++v11;
        *(v9 - 2) = *(_DWORD *)(a3 + 8 * v12);
        *(v9 - 1) = *(_DWORD *)(a3 + 8 * v12 + 4);
        v13 = *a5;
        *(_DWORD *)v10 = *(_DWORD *)(a4 + 8 * *a5);
        *((_DWORD *)v10 + 1) = *(_DWORD *)(a4 + 8 * v13 + 4);
      }
      while ( v11 < 3 );
      ++a5;
      ++v10;
    }
    v7 = a2;
  }
  dbl_10147B38 = 0.0;
  dbl_10147B20 = 0.0;
  v14 = (double *)((char *)&unk_10146378 + 24 * v7);
  dbl_10146800 = 0.0;
  dbl_101467F8 = 0.0;
  dbl_101467F0 = 0.0;
  dbl_10147B40 = 0.0;
  dbl_10147B28 = 0.0;
  dbl_10146818 = 0.0;
  dbl_10146810 = 0.0;
  dbl_10146808 = 0.0;
  dbl_10147B48 = 0.0;
  dbl_10147B30 = 0.0;
  dbl_10146830 = 0.0;
  dbl_10146828 = 0.0;
  dbl_10146820 = 0.0;
  v15 = v7;
  v51 = v14;
  v49 = v14;
  while ( 1 )
  {
    v16 = v14;
    v47 = v14;
    while ( 1 )
    {
      v17 = a2;
      v18 = v14;
      while ( 1 )
      {
        v19 = -(dbl_10146820 * dbl_10146820) - dbl_10146828 * dbl_10146828 - dbl_10146830 * dbl_10146830;
        if ( dbl_10133B50 * v19 <= dbl_1014A478 * dbl_10147B30 )
        {
          dbl_1014A478 = v19;
          v16 = v47;
          dbl_10133B50 = dbl_10147B30;
          v54 = v15;
          v55 = v7;
          v56 = v17;
        }
        --v17;
        v18 -= 3;
        if ( v17 < v7 || *a1 < 3 )
          break;
        dbl_10146820 = dbl_10146820 + *(v18 - 1);
        dbl_10146828 = dbl_10146828 + *v18;
        dbl_10146830 = dbl_10146830 + v18[1];
        dbl_10147B30 = (5.0 - (dbl_10147B48 + dbl_10147B48) - dbl_10147FD0[v17]) * dbl_10147FD0[v17] + dbl_10147B30;
        dbl_10147B48 = dbl_10147B48 + dbl_10147FD0[v17];
      }
      --v7;
      v16 -= 3;
      v47 = v16;
      if ( v7 < v15 )
        break;
      dbl_10146808 = dbl_10146808 + *(v16 - 1);
      v20 = dbl_10146810 + *v16;
      dbl_10146820 = dbl_10146808;
      dbl_10146810 = v20;
      v21 = dbl_10146818 + v16[1];
      dbl_10146828 = dbl_10146810;
      dbl_10146818 = v21;
      dbl_10146830 = v21;
      dbl_10147B28 = (3.0 - (dbl_10147B40 + dbl_10147B40) - dbl_10147FD0[v7]) * dbl_10147FD0[v7] + dbl_10147B28;
      v22 = dbl_10147B40 + dbl_10147FD0[v7];
      dbl_10147B30 = dbl_10147B28;
      dbl_10147B40 = v22;
      v14 = v51;
      dbl_10147B48 = v22;
    }
    --v15;
    v23 = v49 - 3;
    v49 -= 3;
    if ( v15 < 1 )
      break;
    dbl_101467F0 = dbl_101467F0 + *(v23 - 1);
    v24 = dbl_101467F8 + *v23;
    dbl_10146808 = dbl_101467F0;
    dbl_10146820 = dbl_101467F0;
    dbl_101467F8 = v24;
    v25 = dbl_10146800 + v23[1];
    dbl_10146810 = dbl_101467F8;
    dbl_10146828 = dbl_101467F8;
    dbl_10146800 = v25;
    dbl_10146818 = v25;
    dbl_10146830 = v25;
    dbl_10147B20 = (1.0 - (dbl_10147B38 + dbl_10147B38) - dbl_10147FD0[v15]) * dbl_10147FD0[v15] + dbl_10147B20;
    v26 = dbl_10147B38 + dbl_10147FD0[v15];
    dbl_10147B28 = dbl_10147B20;
    dbl_10147B38 = v26;
    dbl_10147B30 = dbl_10147B20;
    dbl_10147B40 = v26;
    v14 = v51;
    v7 = a2;
    *(_QWORD *)&dbl_10147B48 = __PAIR64__(HIDWORD(dbl_10147B38), LODWORD(dbl_10147B40));
  }
  v57 = a2;
  v50 = (v56 != a2) + (v54 != v55) + (v55 != v56);
  if ( v50 == 1 && v56 != a2 )
  {
    if ( v55 == v56 )
    {
      v56 = a2;
    }
    else if ( v54 == v55 )
    {
      v57 = v54;
      v56 = v54;
    }
  }
  v27 = 0.0;
  v28 = 0.0;
  v29 = 0;
  v30 = 0;
  dbl_10147B48 = 0.0;
  v31 = 0.0;
  v52 = 0;
  v32 = 0;
  dbl_10146830 = 0.0;
  v33 = 0.0;
  dbl_10146828 = 0.0;
  v34 = 0.0;
  dbl_10146820 = 0.0;
  do
  {
    v35 = *(&v54 + v29);
    if ( v30 < v35 )
    {
      v36 = (double)v52;
      v37 = (double *)((char *)&unk_10146378 + 24 * v30);
      do
      {
        v38 = v36 * dbl_10147FD0[v30++];
        v37 += 3;
        v28 = v28 + v38;
        v27 = v27 + v38 * v36;
        v34 = v34 + v36 * *(v37 - 4);
        v33 = v33 + v36 * *(v37 - 3);
        v31 = v31 + v36 * *(v37 - 2);
      }
      while ( v30 < v35 );
    }
    v32 += v35 != a2;
    v52 = ++v29;
  }
  while ( v29 < 4 );
  dbl_10146820 = v34;
  dbl_10147B48 = v28;
  dbl_10146828 = v33;
  dbl_10146830 = v31;
  v39 = &dbl_10146820;
  v40 = a6 - (_DWORD)&dbl_10146820;
  v41 = a7 - (_DWORD)&dbl_10146820;
  dbl_10147B30 = v27 - v28 * v28;
  v48 = -v28;
  v53 = (double)v32 - v28;
  v42 = -(dbl_10146820 * dbl_10146820) - v33 * v33 - dbl_10146830 * dbl_10146830;
  do
  {
    v43 = v48 * *v39++;
    *(double *)((char *)v39 + v40 - 8) = v43 / dbl_10147B30;
    *(double *)((char *)v39 + v40 + 16) = v53 * *(v39 - 1) / dbl_10147B30;
    *(_DWORD *)((char *)v39 + v41 - 8) = *((_DWORD *)v39 - 2);
    *(_DWORD *)((char *)v39 + v41 - 4) = *((_DWORD *)v39 - 1);
  }
  while ( (int)v39 < (int)dbl_10146838 );
  v44 = 1;
  if ( v50 != 1 )
    v44 = v32;
  *a1 = v44;
  return v42 / dbl_10147B30;
}

//------------------------------------------------------------------------------
// Address: 0x10025350
// Name: sub_10025350
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl sub_10025350(int *a1, int a2, int a3, int a4, int *a5, int a6, int a7, int a8)
{
  int v8; // eax
  _DWORD *v10; // ecx
  double *v11; // edi
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  double *v16; // esi
  int v17; // edi
  int v18; // edx
  int j; // ecx
  double v20; // st7
  double *v21; // eax
  long double v22; // st7
  double v23; // st6
  double v24; // st5
  double v25; // st4
  double v26; // st6
  long double v27; // st5
  long double v28; // st5
  long double v29; // st6
  double *v30; // eax
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double *v34; // eax
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st6
  int v40; // esi
  int v41; // ecx
  double v42; // st5
  int v43; // ebx
  double v44; // st4
  double v45; // st3
  int v46; // edx
  double v47; // st2
  double *v48; // eax
  double v49; // st1
  int v50; // ecx
  double *v51; // eax
  int v52; // edx
  double v53; // st7
  long double v54; // st6
  double v55; // st5
  double v56; // st4
  double v57; // st5
  long double v58; // st4
  long double v59; // st4
  long double v60; // st5
  int v61; // eax
  int v63; // [esp+10h] [ebp-88h]
  long double v64; // [esp+10h] [ebp-88h]
  int i; // [esp+1Ch] [ebp-7Ch]
  double *v66; // [esp+1Ch] [ebp-7Ch]
  int v67; // [esp+20h] [ebp-78h]
  double v68; // [esp+20h] [ebp-78h]
  long double v69; // [esp+20h] [ebp-78h]
  double *v70; // [esp+2Ch] [ebp-6Ch]
  int v71; // [esp+2Ch] [ebp-6Ch]
  double *v72; // [esp+30h] [ebp-68h]
  int v73; // [esp+30h] [ebp-68h]
  double v74; // [esp+30h] [ebp-68h]
  long double v75; // [esp+38h] [ebp-60h]
  long double v76; // [esp+38h] [ebp-60h]
  double v77; // [esp+40h] [ebp-58h]
  double v78; // [esp+40h] [ebp-58h]
  long double v79; // [esp+40h] [ebp-58h]
  double v80; // [esp+48h] [ebp-50h]
  double v81; // [esp+48h] [ebp-50h]
  double v82; // [esp+50h] [ebp-48h]
  double v83; // [esp+50h] [ebp-48h]
  double v84; // [esp+58h] [ebp-40h]
  double v85; // [esp+58h] [ebp-40h]
  double v86; // [esp+60h] [ebp-38h]
  double v87; // [esp+60h] [ebp-38h]
  double v88; // [esp+68h] [ebp-30h]
  double v89; // [esp+68h] [ebp-30h]
  double v90; // [esp+68h] [ebp-30h]
  double v91; // [esp+70h] [ebp-28h]
  double v92; // [esp+70h] [ebp-28h]
  double v93; // [esp+78h] [ebp-20h]
  double v94; // [esp+78h] [ebp-20h]
  double v95; // [esp+80h] [ebp-18h]
  double v96; // [esp+80h] [ebp-18h]
  int v97; // [esp+88h] [ebp-10h]
  int v98; // [esp+8Ch] [ebp-Ch]
  int v99; // [esp+90h] [ebp-8h]
  int v100; // [esp+94h] [ebp-4h]

  v8 = a2;
  v63 = 0;
  if ( a2 > 0 )
  {
    v10 = &unk_10145A60;
    v11 = dbl_10149E10;
    for ( i = a2; i != 0; --i )
    {
      v12 = 0;
      do
      {
        v10 += 2;
        v13 = v12 + 2 * *a5 + *a5;
        ++v12;
        *(v10 - 2) = *(_DWORD *)(a3 + 8 * v13);
        *(v10 - 1) = *(_DWORD *)(a3 + 8 * v13 + 4);
        v14 = *a5;
        *(_DWORD *)v11 = *(_DWORD *)(a4 + 8 * *a5);
        *((_DWORD *)v11 + 1) = *(_DWORD *)(a4 + 8 * v14 + 4);
      }
      while ( v12 < 3 );
      ++a5;
      ++v11;
    }
    v8 = a2;
  }
  v15 = v8;
  dbl_10149FE0 = 0.0;
  v16 = (double *)((char *)&unk_10145A68 + 24 * v8);
  dbl_10149D08 = 0.0;
  dbl_10149D30 = 0.0;
  dbl_10149D28 = 0.0;
  dbl_10149D20 = 0.0;
  dbl_10149FE8 = 0.0;
  dbl_10149D10 = 0.0;
  dbl_10149D48 = 0.0;
  dbl_10149D40 = 0.0;
  dbl_10149D38 = 0.0;
  dbl_10149FF0 = 0.0;
  dbl_10149D18 = 0.0;
  dbl_10149D60 = 0.0;
  dbl_10149D58 = 0.0;
  dbl_10149D50 = 0.0;
  v67 = v8;
  v17 = a6 - (_DWORD)&dbl_10149D50;
  v72 = v16;
  v70 = v16;
  while ( 1 )
  {
    v18 = v8;
    v66 = v16;
    while ( 1 )
    {
      for ( j = v8; ; dbl_10149FF0 = dbl_10149FF0 + dbl_10149E10[j] )
      {
        v82 = -dbl_10149FF0;
        v20 = (double)v63;
        v21 = &dbl_10149D50;
        v84 = v20 - dbl_10149FF0;
        v88 = v82 * v82 + dbl_10149D18;
        v93 = v84 * v82 + dbl_10149D18;
        v95 = v84 * v84 + dbl_10149D18;
        v86 = v95 * v88;
        v77 = v20 * v20 * dbl_10149D18 * v86 * v86;
        v22 = 0.0;
        do
        {
          v23 = dbl_10149D18 * *(double *)((char *)v21 + v17);
          v24 = dbl_10149D18 * *(double *)((char *)v21 + v17 + 24);
          v25 = v82 * *v21;
          v80 = v84 * *v21;
          v64 = v23 - v25;
          v75 = v24 - v25;
          v91 = (v23 - v80) * v88;
          v26 = (v24 - v80) * v88;
          v27 = (v75 - fabs(v75) + fabs(v64) + v64) * 0.5 * v93;
          v28 = (v26 - fabs(v26 - v27) + fabs(v91 - v27) + v91) * 0.5;
          v29 = (v75 * v86 - fabs(v75 * v86 - v93 * v28) + fabs(v64 * v86 - v93 * v28) + v64 * v86) * 0.5;
          ++v21;
          v22 = v22
              + dbl_10149D18 * (v29 - v28 * v95) * (v29 - v28 * v95)
              + (v28 * v95 * v82 - v29 * v84) * (v28 * v95 * v82 - v29 * v84)
              - *(v21 - 1) * *(v21 - 1) * v77;
        }
        while ( (int)v21 < (int)dbl_10149D68 );
        v78 = dbl_10149D18 * v77;
        if ( dbl_10133B58 * v22 <= dbl_1014A480 * v78 )
        {
          dbl_1014A480 = v22;
          v15 = v67;
          dbl_10133B58 = v78;
          v97 = v67;
          v98 = v18;
          v99 = j;
        }
        --j;
        v16 -= 3;
        if ( j < v18 || *a1 < 3 )
          break;
        v63 = 3;
        dbl_10149D50 = dbl_10149D50 + *(v16 - 1);
        dbl_10149D58 = dbl_10149D58 + *v16;
        dbl_10149D60 = dbl_10149D60 + v16[1];
        dbl_10149D18 = (5.0 - (dbl_10149FF0 + dbl_10149FF0) - dbl_10149E10[j]) * dbl_10149E10[j] + dbl_10149D18;
      }
      --v18;
      v30 = v66 - 3;
      v66 -= 3;
      if ( v18 < v15 )
        break;
      v63 = 2;
      dbl_10149D38 = dbl_10149D38 + *(v30 - 1);
      v31 = dbl_10149D40 + *v30;
      dbl_10149D50 = dbl_10149D38;
      dbl_10149D40 = v31;
      v32 = dbl_10149D48 + v30[1];
      dbl_10149D58 = dbl_10149D40;
      v16 = v72;
      dbl_10149D48 = v32;
      dbl_10149D60 = v32;
      dbl_10149D10 = (3.0 - (dbl_10149FE8 + dbl_10149FE8) - dbl_10149E10[v18]) * dbl_10149E10[v18] + dbl_10149D10;
      v33 = dbl_10149FE8 + dbl_10149E10[v18];
      dbl_10149D18 = dbl_10149D10;
      dbl_10149FE8 = v33;
      dbl_10149FF0 = v33;
      v8 = a2;
    }
    --v15;
    v34 = v70 - 3;
    v67 = v15;
    v70 -= 3;
    if ( v15 < 1 )
      break;
    v16 = v72;
    v63 = 1;
    dbl_10149D20 = dbl_10149D20 + *(v34 - 1);
    v35 = dbl_10149D28 + *v34;
    dbl_10149D38 = dbl_10149D20;
    dbl_10149D50 = dbl_10149D20;
    dbl_10149D28 = v35;
    v36 = dbl_10149D30 + v34[1];
    dbl_10149D40 = dbl_10149D28;
    dbl_10149D58 = dbl_10149D28;
    dbl_10149D30 = v36;
    dbl_10149D48 = v36;
    dbl_10149D60 = v36;
    dbl_10149D08 = (1.0 - (dbl_10149FE0 + dbl_10149FE0) - dbl_10149E10[v15]) * dbl_10149E10[v15] + dbl_10149D08;
    v37 = dbl_10149FE0 + dbl_10149E10[v15];
    dbl_10149D10 = dbl_10149D08;
    dbl_10149FE0 = v37;
    dbl_10149D18 = dbl_10149D08;
    dbl_10149FF0 = v37;
    v8 = a2;
    dbl_10149FE8 = v37;
  }
  v100 = a2;
  v71 = (v97 != v98) + (v99 != a2) + (v98 != v99);
  if ( v71 == 1 && v99 != a2 )
  {
    if ( v98 == v99 )
    {
      v99 = a2;
    }
    else if ( v97 == v98 )
    {
      v100 = v97;
      v99 = v97;
    }
  }
  v38 = 0.0;
  v39 = 0.0;
  v40 = 0;
  v41 = 0;
  dbl_10149FF0 = 0.0;
  v42 = 0.0;
  v73 = 0;
  v43 = 0;
  dbl_10149D60 = 0.0;
  v44 = 0.0;
  dbl_10149D58 = 0.0;
  v45 = 0.0;
  dbl_10149D50 = 0.0;
  do
  {
    v46 = *(&v97 + v40);
    if ( v41 < v46 )
    {
      v47 = (double)v73;
      v48 = (double *)((char *)&unk_10145A68 + 24 * v41);
      do
      {
        v49 = v47 * dbl_10149E10[v41++];
        v48 += 3;
        v39 = v39 + v49;
        v38 = v38 + v49 * v47;
        v45 = v45 + v47 * *(v48 - 4);
        v44 = v44 + v47 * *(v48 - 3);
        v42 = v42 + v47 * *(v48 - 2);
      }
      while ( v41 < v46 );
    }
    v43 += v46 != a2;
    v73 = ++v40;
  }
  while ( v40 < 4 );
  dbl_10149D50 = v45;
  dbl_10149FF0 = v39;
  dbl_10149D58 = v44;
  dbl_10149D60 = v42;
  v50 = a7 + 24;
  v51 = &dbl_10149D50;
  v52 = a8 - (_DWORD)&dbl_10149D50;
  dbl_10149D18 = v38 - v39 * v39;
  v83 = -v39;
  v89 = (double)v43;
  v74 = v89 - v39;
  v87 = v83 * v83 + dbl_10149D18;
  v94 = v74 * v83 + dbl_10149D18;
  v92 = v74 * v74 + dbl_10149D18;
  v85 = v92 * v87;
  v53 = v89 * v89 * v85 * v85 * dbl_10149D18;
  v54 = 0.0;
  v90 = 1.0 / v85;
  do
  {
    v55 = dbl_10149D18 * *(double *)((char *)v51 + v17);
    v56 = dbl_10149D18 * *(double *)(a6 - a7 + v50);
    v81 = v83 * *v51;
    v68 = v74 * *v51;
    v76 = v55 - v81;
    v79 = v56 - v81;
    v96 = (v55 - v68) * v87;
    v57 = (v56 - v68) * v87;
    v58 = (v79 - fabs(v79) + fabs(v76) + v76) * 0.5 * v94;
    v59 = (v57 - fabs(v57 - v58) + fabs(v96 - v58) + v96) * 0.5;
    v69 = v59 * v92;
    v60 = (v79 * v85 - fabs(v79 * v85 - v94 * v59) + fabs(v76 * v85 - v94 * v59) + v76 * v85) * 0.5;
    ++v51;
    v50 += 8;
    v54 = v54
        + (v60 - v69) * (v60 - v69) * dbl_10149D18
        + (v69 * v83 - v60 * v74) * (v69 * v83 - v60 * v74)
        - *(v51 - 1) * *(v51 - 1) * v53;
    *(long double *)(v50 - 32) = (v90 * v60 + v81) / dbl_10149D18;
    *(long double *)(v50 - 8) = (v74 * *(v51 - 1) + v90 * v69) / dbl_10149D18;
    *(_DWORD *)((char *)v51 + v52 - 8) = *((_DWORD *)v51 - 2);
    *(_DWORD *)((char *)v51 + v52 - 4) = *((_DWORD *)v51 - 1);
  }
  while ( (int)v51 < (int)dbl_10149D68 );
  v61 = 1;
  if ( v71 != 1 )
    v61 = v43;
  *a1 = v61;
  return v54 / (v53 * dbl_10149D18);
}

//------------------------------------------------------------------------------
// Address: 0x10025D60
// Name: sub_10025D60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_10025D60(_DWORD *a1, signed int a2, double *a3, int a4, int a5, void *a6)
{
  int v6; // edx
  int v7; // edi
  int v8; // eax
  int v9; // ebx
  char v10; // si
  int v11; // edx
  int v12; // ebx
  int *v13; // edi
  int v14; // ebx
  int v15; // eax
  int v16; // esi
  double *v17; // eax
  double *v18; // eax
  __int64 v19; // rax
  int v20; // ebx
  int v21; // esi
  double *v22; // edx
  int v23; // ecx
  double *v24; // edi
  __int16 v25; // fps
  double v26; // st7
  bool v27; // c0
  char v28; // c2
  bool v29; // c3
  int v30; // eax
  bool v31; // zf
  char *v32; // eax
  double *v33; // eax
  double v34; // st7
  double v35; // st6
  unsigned __int8 v37; // c0
  unsigned __int8 v38; // c2
  double v39; // st7
  __int16 v40; // fps
  int v41; // eax
  bool v42; // cc
  double v43; // st7
  int v44; // edi
  int v45; // ecx
  int v46; // esi
  int v47; // eax
  int v48; // edx
  char *v49; // eax
  unsigned int v50; // ebx
  char v52; // [esp+17h] [ebp-59h]
  int v53; // [esp+18h] [ebp-58h]
  int v54; // [esp+18h] [ebp-58h]
  int v55; // [esp+1Ch] [ebp-54h]
  int v56; // [esp+1Ch] [ebp-54h]
  int v57; // [esp+1Ch] [ebp-54h]
  int v58; // [esp+20h] [ebp-50h]
  int v59; // [esp+20h] [ebp-50h]
  signed int v60; // [esp+20h] [ebp-50h]
  double *v61; // [esp+24h] [ebp-4Ch]
  double *v62; // [esp+28h] [ebp-48h]
  int v63; // [esp+2Ch] [ebp-44h]
  _DWORD *v64; // [esp+2Ch] [ebp-44h]
  int v65; // [esp+30h] [ebp-40h]
  int v66; // [esp+30h] [ebp-40h]
  char v67; // [esp+34h] [ebp-3Ch]
  int v68; // [esp+34h] [ebp-3Ch]
  char v69; // [esp+38h] [ebp-38h]
  _DWORD *v70; // [esp+38h] [ebp-38h]
  _DWORD *v71; // [esp+38h] [ebp-38h]
  int *v72; // [esp+3Ch] [ebp-34h]
  int v73; // [esp+40h] [ebp-30h]
  int v74; // [esp+40h] [ebp-30h]
  int v75; // [esp+44h] [ebp-2Ch] BYREF
  int v76; // [esp+48h] [ebp-28h]
  _DWORD v77[9]; // [esp+4Ch] [ebp-24h] BYREF

  if ( dword_1014A488 == 0 )
  {
    v6 = 0;
    dword_1014A488 = 1;
    v63 = 0;
    do
    {
      v7 = dword_10133B60[v6];
      v67 = v7;
      v8 = (1 << v7) - 1;
      v9 = v8;
      v73 = v8;
      v55 = v8;
      if ( v8 >= 0 )
      {
        do
        {
          v53 = v8;
          if ( v8 >= 0 )
          {
            v10 = 8 - v7;
            v69 = 8 - v7;
            v11 = (v9 >> (2 * v7 - 8)) | (v9 << (8 - v7));
            v65 = v11;
            while ( 1 )
            {
              v12 = v8 >> (2 * v7 - 8);
              v58 = 0;
              v13 = (int *)&unk_10133B6C;
              v14 = (v8 << v10) | v12;
              while ( 1 )
              {
                v15 = (v13[2] + v11 * *v13 + v14 * v13[1]) / v13[3];
                v16 = v58 + 2 * (v63 + 2 * v15 + v15) + v63 + 2 * v15 + v15;
                if ( byte_10148178[3 * v16] == 0
                  || (int)abs32((unsigned __int8)byte_1014817A[3 * v16] - (unsigned __int8)byte_10148179[3 * v16]) > (int)abs32(v14 - v65) )
                {
                  byte_10148178[3 * v16] = 1;
                  byte_10148179[3 * v16] = (_BYTE)v55 << v69;
                  byte_1014817A[3 * v16] = (_BYTE)v53 << v69;
                }
                v13 += 4;
                ++v58;
                if ( (int)v13 >= (int)&dword_10133B9C )
                  break;
                v11 = v65;
              }
              LOBYTE(v7) = v67;
              if ( --v53 < 0 )
                break;
              v11 = v65;
              v8 = v53;
              v10 = v69;
            }
            v9 = v55;
            v8 = v73;
          }
          v55 = --v9;
        }
        while ( v9 >= 0 );
        v6 = v63;
      }
      v63 = ++v6;
    }
    while ( v6 < 3 );
  }
  v54 = 0;
  if ( *a1 - 1 <= 0 )
    goto LABEL_54;
  v68 = a4 - (_DWORD)a3;
  v70 = v77;
  v17 = dbl_10148150;
  v62 = dbl_10148150;
  while ( 2 )
  {
    *(_DWORD *)v17 = 0;
    *((_DWORD *)v17 + 1) = 0;
    v18 = a3;
    v56 = 0;
    v61 = a3;
    v64 = v70;
    while ( 2 )
    {
      v19 = (__int64)floor(X: 255.0 / *(double *)((char *)v18 + v68) * *v18 + 0.5);
      v20 = v19;
      v66 = v19;
      if ( (int)v19 < 0 )
      {
        v20 = 0;
LABEL_27:
        v66 = v20;
        goto LABEL_28;
      }
      if ( (int)v19 >= 256 )
      {
        v20 = 255;
        goto LABEL_27;
      }
LABEL_28:
      v21 = 1;
      v74 = 1;
      v52 = byte_10148178[12 * v20 + 6 * v56 + 6 * v20 + 6 * v20 + 3 * v54 + 3 * v56 + 3 * v20];
      v72 = &v75;
      v22 = &dbl_10149E00;
      do
      {
        v23 = v20;
        v59 = v20;
        if ( v52 != 0 )
        {
          v24 = v61;
          v26 = (255.0 / *(double *)((char *)v61 + v68) * *v61 - (double)v66) * (double)v74;
          v27 = v26 < 0.0;
          v28 = 0;
          v29 = v26 == 0.0;
          if ( (v25 & 0x4100) != 0 )
            goto LABEL_40;
        }
        v23 = v21 + v20;
        v59 = v21 + v20;
        if ( v21 + v20 < 0 )
        {
          v23 = 0;
LABEL_35:
          v59 = v23;
          goto LABEL_36;
        }
        if ( v23 >= 256 )
        {
          v23 = 255;
          goto LABEL_35;
        }
LABEL_36:
        v30 = v54 + 2 * (v56 + 2 * v23 + v23) + v56 + 2 * v23 + v23;
        v31 = byte_10148178[3 * v30] == 0;
        v32 = &byte_10148178[3 * v30];
        if ( v31 )
        {
          do
          {
            v32 += 27 * v21;
            v23 += v21;
          }
          while ( *v32 == 0 );
          v59 = v23;
        }
        v24 = v61;
LABEL_40:
        *(_DWORD *)v22 = 0;
        *((_DWORD *)v22 + 1) = 0;
        if ( a2 > 0 )
        {
          v33 = v24;
          v34 = (double)v59;
          v60 = a2;
          do
          {
            v33 += 3;
            v31 = v60 == 1;
            v35 = v34 * *(double *)((char *)v24 + v68) - *(v33 - 3) * 255.0;
            --v60;
            *v22 = v35 * v35 + *v22;
          }
          while ( !v31 );
          v20 = v66;
        }
        ++v22;
        v21 = -v21;
        *v72++ = v23;
        v74 = v21;
      }
      while ( (int)v22 < (int)dbl_10149E10 );
      if ( (v37 | v38) != 0 )
      {
        v39 = dbl_10149E00 + *v62;
        *v64 = v75;
        *v62 = v39;
      }
      else
      {
        *v62 = dbl_10149E08 + *v62;
        if ( (v40 & 0x4100) != 0 )
        {
          v41 = v75;
          if ( (v20 & 1) == 0 )
            v41 = v76;
          *v64 = v41;
        }
        else
        {
          *v64 = v76;
        }
      }
      v42 = ++v56 < 3;
      ++v61;
      v64 += 3;
      if ( v42 )
      {
        v18 = v61;
        continue;
      }
      break;
    }
    ++v54;
    ++v62;
    ++v70;
    if ( v54 < *a1 - 1 )
    {
      v17 = v62;
      continue;
    }
    break;
  }
LABEL_54:
  if ( *a1 != 4 )
  {
    if ( *a1 != 3 )
      goto LABEL_65;
    v54 = 0;
    if ( dbl_10148150[0] <= dbl_10148158 )
      goto LABEL_65;
    goto LABEL_64;
  }
  v43 = dbl_10148150[0];
  if ( !bS3TCForce4 )
  {
    if ( dbl_10148150[0] > dbl_10148158 )
    {
      if ( dbl_10148158 > dbl_10148160 )
      {
LABEL_61:
        v54 = 2;
        goto LABEL_65;
      }
LABEL_64:
      v54 = 1;
      goto LABEL_65;
    }
    v43 = dbl_10148150[0];
  }
  if ( v43 > dbl_10148160 )
    goto LABEL_61;
  v54 = 0;
LABEL_65:
  v44 = a5;
  v45 = 0;
  v57 = 0;
  v71 = &v77[v54];
  do
  {
    v46 = v44;
    v47 = v45 + 2 * *v71 + *v71;
    v48 = 2;
    v49 = &byte_10148179[6 * v47 + 3 * v54 + 3 * v47];
    do
    {
      v46 += 12;
      v50 = (unsigned __int8)*v49++;
      --v48;
      *(_DWORD *)(v46 - 12) = v50 >> (8 - *((_BYTE *)dword_10133B60 + v44 - a5));
    }
    while ( v48 != 0 );
    v45 = v57 + 1;
    v44 += 4;
    v42 = ++v57 < 3;
    v71 += 3;
  }
  while ( v42 );
  if ( a2 > 0 )
    memset32(a6, v54 + 1, a2);
  if ( v54 != 0 )
    *a1 = v54 + 2;
  return dbl_10148150[v54];
}

//------------------------------------------------------------------------------
// Address: 0x100262B0
// Name: sub_100262B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_100262B0(int *a1, int a2, int a3, int a4, int a5, int a6, int a7, void *a8, void *a9)
{
  int *v9; // ebx
  int v10; // edi
  bool v11; // cc
  int v12; // eax
  int v13; // edi
  double *v14; // edx
  int i; // ecx
  int v16; // ebx
  double v17; // st7
  int v18; // eax
  double v19; // st7
  int v20; // eax
  int v21; // edx
  int v23; // [esp+10h] [ebp-1C8h]
  int v24; // [esp+14h] [ebp-1C4h]
  int v25; // [esp+18h] [ebp-1C0h]
  int v26; // [esp+1Ch] [ebp-1BCh]
  _DWORD v27[2]; // [esp+20h] [ebp-1B8h]
  _QWORD v28[6]; // [esp+28h] [ebp-1B0h] BYREF
  _QWORD v29[48]; // [esp+58h] [ebp-180h] BYREF
  int v30; // [esp+1E4h] [ebp+Ch]

  v9 = a1;
  v27[0] = *a1 == 4;
  dbl_10149CC0[0] = sub_10026490(a1: v27[0] + 3, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: v28, a8: v29);
  v10 = 1;
  v11 = a2 - 2 <= 0;
  v26 = 1;
  v30 = a2 - 2;
  *a1 -= 2;
  v23 = 0;
  if ( !v11 )
  {
    v12 = 0;
    v24 = 0;
    do
    {
      v25 = 0;
      if ( dword_10133B9C[v12 + *v9] > 0 )
      {
        do
        {
          v13 = 0;
          v14 = dbl_10149D68;
          do
          {
            for ( i = 0; i < 3; *(v14 - 1) = v17 * dbl_10133BB8[v18] + dbl_10133BC0[v18] * *(double *)(a7 + 8 * i + 16) )
            {
              ++v14;
              v16 = v25;
              v17 = *(double *)(a7 + 8 * i);
              v18 = 2 * (v13 + 2 * (v25 + 6 * (2 * v23 + *a1)));
              ++i;
            }
            ++v13;
          }
          while ( (int)v14 < (int)&dbl_10149D98 );
          v10 = v26;
          v27[v26] = v23;
          v19 = sub_10026490(
                  a1: v23 + 3,
                  a2: a3,
                  a3: a4,
                  a4: a5,
                  a5: a6,
                  a6: dbl_10149D68,
                  a7: &v28[3 * v26],
                  a8: &v29[24 * v26]);
          dbl_10149CC0[v26] = v19;
          if ( v19 < *((double *)&unk_10149CC8 - v26) )
          {
            v10 = 1 - v26;
            v26 = 1 - v26;
          }
          ++v25;
          v12 = v24;
        }
        while ( v16 + 1 < dword_10133B9C[v24 + *a1] );
      }
      v9 = a1;
      v12 += 3;
      v11 = ++v23 < v30;
      v24 = v12;
    }
    while ( v11 );
  }
  v20 = 1 - v10;
  if ( a3 > 0 )
    qmemcpy(a9, &v29[24 * v20], 4 * a3);
  v21 = v27[v20] + 3;
  qmemcpy(a8, &v28[3 * v20], 0x18u);
  *v9 = v21;
  return dbl_10149CC0[v20];
}

//------------------------------------------------------------------------------
// Address: 0x10026490
// Name: sub_10026490
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_10026490(int a1, int a2, int a3, double *a4, double *a5, double *a6, int a7, int a8)
{
  double *v8; // edx
  _BYTE *v9; // eax
  int *v10; // ebx
  _BYTE *v11; // esi
  int v12; // edi
  __int64 v13; // rax
  int v14; // edx
  int v15; // ecx
  __int16 v16; // fps
  double v17; // st7
  bool v18; // c0
  char v19; // c2
  bool v20; // c3
  int v21; // eax
  int v22; // edx
  int *v23; // eax
  bool v24; // cc
  int *v25; // ebx
  int *v26; // edi
  char *v27; // eax
  double *v28; // esi
  double *v29; // ecx
  int *v30; // eax
  double v31; // st7
  bool v32; // zf
  double *v33; // eax
  int v34; // ecx
  double *v35; // edx
  double v36; // st7
  double v37; // st6
  double v38; // st7
  double v39; // st7
  char *v40; // edx
  int v41; // edi
  long double v42; // st7
  char *v43; // ecx
  char *v44; // edx
  char *v45; // esi
  int v46; // ebx
  int v47; // edi
  int v48; // esi
  int v49; // ecx
  double *v50; // eax
  double v51; // st6
  double v52; // st5
  long double v53; // st6
  double v54; // st5
  int *v55; // edi
  char *v56; // eax
  double *v57; // edx
  double *v58; // esi
  int v59; // ebx
  int v60; // eax
  int v61; // ebx
  int *v62; // eax
  double v63; // st7
  double *v64; // eax
  int v65; // ecx
  double *v66; // edx
  double v67; // st7
  double v68; // st6
  double v69; // st6
  double v70; // st6
  double v71; // st7
  char *v72; // ecx
  int v73; // ecx
  long double v74; // st7
  char *v75; // edx
  char *v76; // esi
  char *v77; // edi
  int v78; // ebx
  double *v79; // ecx
  int v80; // edi
  int v81; // edx
  double *v82; // eax
  double v83; // st6
  double v84; // st5
  long double v85; // st6
  double v86; // st5
  double v87; // st4
  long double v88; // st5
  int v89; // esi
  int v90; // eax
  int v91; // edi
  int v92; // edx
  int *v93; // eax
  double result; // st7
  double *v95; // ecx
  double *v96; // edx
  int v97; // esi
  double v98; // st2
  double v99; // st6
  int v100; // edi
  double v101; // st3
  double v102; // st1
  int v103; // [esp+Ch] [ebp-ECh]
  double *v104; // [esp+Ch] [ebp-ECh]
  int v105; // [esp+Ch] [ebp-ECh]
  double *v106; // [esp+Ch] [ebp-ECh]
  double *v107; // [esp+10h] [ebp-E8h]
  int v108; // [esp+10h] [ebp-E8h]
  double *v109; // [esp+10h] [ebp-E8h]
  int v110; // [esp+10h] [ebp-E8h]
  int v111; // [esp+10h] [ebp-E8h]
  int v112; // [esp+10h] [ebp-E8h]
  _BYTE *v113; // [esp+14h] [ebp-E4h]
  int v114; // [esp+14h] [ebp-E4h]
  int v115; // [esp+14h] [ebp-E4h]
  int v116; // [esp+14h] [ebp-E4h]
  int v117; // [esp+14h] [ebp-E4h]
  int v118; // [esp+14h] [ebp-E4h]
  int v119; // [esp+18h] [ebp-E0h]
  int v120; // [esp+18h] [ebp-E0h]
  int v121; // [esp+18h] [ebp-E0h]
  double *v122; // [esp+18h] [ebp-E0h]
  double *v123; // [esp+1Ch] [ebp-DCh]
  double *v124; // [esp+1Ch] [ebp-DCh]
  char *v125; // [esp+20h] [ebp-D8h]
  int v126; // [esp+20h] [ebp-D8h]
  int v127; // [esp+20h] [ebp-D8h]
  char *v128; // [esp+20h] [ebp-D8h]
  int *v129; // [esp+24h] [ebp-D4h]
  double v130; // [esp+28h] [ebp-D0h]
  int v131; // [esp+34h] [ebp-C4h]
  _BYTE v132[4]; // [esp+38h] [ebp-C0h] BYREF
  char v133; // [esp+3Ch] [ebp-BCh] BYREF
  _BYTE v134[176]; // [esp+48h] [ebp-B0h] BYREF

  v8 = a6;
  v9 = v134;
  v123 = a6;
  v113 = v134;
  v103 = (int)&unk_100C9860;
  v125 = (char *)((char *)a5 - (char *)a6);
  do
  {
    v10 = (int *)v9;
    v107 = v8;
    v11 = v9 + 32;
    v12 = 1 << (8 - *(_DWORD *)v103);
    v119 = 2;
    v131 = 256 - v12;
    v129 = (int *)(v9 + 16);
    do
    {
      if ( *(double *)((char *)v8 + (_DWORD)v125) == 0.0 )
        X = 0.0;
      else
        X = *v107 / *(double *)((char *)v8 + (_DWORD)v125) * 255.0;
      v13 = (__int64)floor(X: X);
      HIDWORD(v13) = v13;
      if ( (int)v13 >= 0 )
      {
        if ( (int)v13 >= 256 )
          HIDWORD(v13) = v131;
      }
      else
      {
        HIDWORD(v13) = 0;
      }
      v14 = v131 & HIDWORD(v13);
      v15 = *(_DWORD *)v103;
      LODWORD(v130) = v14 + (v14 >> *(_DWORD *)v103);
      v17 = (double)SLODWORD(v130);
      v18 = v17 < X;
      v19 = 0;
      v20 = v17 == X;
      if ( (v16 & 0x4100) == 0 && v14 - v12 >= 0 )
        v14 -= v12;
      v21 = v14 + (v14 >> v15);
      *v10 = v21;
      *((_DWORD *)v11 - 12) = v21;
      if ( v14 + v12 < 256 )
        v14 += v12;
      v11 += 4;
      v10 += 5;
      v107 += 3;
      v22 = (v14 >> v15) + v14;
      v23 = v129;
      *((_DWORD *)v11 - 1) = v22;
      *v23 = v22;
      v8 = v123;
      v129 = v23 - 3;
      --v119;
    }
    while ( v119 != 0 );
    v9 = v113 + 64;
    v8 = v123 + 1;
    v24 = v103 + 4 < (int)&unk_100C986C;
    v103 += 4;
    v113 += 64;
    ++v123;
  }
  while ( v24 );
  if ( a1 == 3 )
  {
    v25 = nullptr;
    v26 = (int *)v132;
    v129 = nullptr;
    v27 = (char *)&unk_10141228;
    v28 = dbl_10146838;
    do
    {
      v104 = (double *)v27;
      v120 = 4;
      do
      {
        v29 = v28;
        v114 = 3;
        v26[2] = (*v26 + v26[1]) / 2;
        v30 = v26;
        do
        {
          v31 = (double)*v30++;
          ++v29;
          v32 = v114-- == 1;
          *(v29 - 1) = v31 * *(double *)((char *)a5 + (_DWORD)v25) * 0.00392156862745098;
        }
        while ( !v32 );
        v33 = v104;
        v34 = 0;
        if ( a2 > 0 )
        {
          v35 = (double *)((char *)v25 + a3);
          do
          {
            v36 = *v35 - *v28;
            v35 += 3;
            v37 = v36 * a4[v34];
            v33 += 3;
            ++v34;
            *(v33 - 3) = v37 * v36;
            v38 = *(v35 - 3) - v28[1];
            *(v33 - 2) = v38 * a4[v34 - 1] * v38;
            v39 = *(v35 - 3) - v28[2];
            *(v33 - 1) = v39 * a4[v34 - 1] * v39;
          }
          while ( v34 < a2 );
          v25 = v129;
        }
        v26 += 4;
        v40 = (char *)(v104 + 192);
        v28 += 4;
        v32 = v120 == 1;
        v104 += 192;
        --v120;
      }
      while ( !v32 );
      v25 += 2;
      v129 = v25;
      v27 = v40;
    }
    while ( (int)v28 < (int)dbl_101469B8 );
    v41 = 0;
    v103 = -1;
    v108 = 0;
    dbl_10145A58 = (*a5 * *a5 + a5[1] * a5[1] + a5[2] * a5[2]) * 96.0;
    do
    {
      v42 = 0.0;
      v43 = (char *)&unk_10141228 + 1536 * (v41 & 3);
      v44 = (char *)&unk_10142A28 + 1536 * ((v41 >> 2) & 3);
      v45 = (char *)&unk_10144228 + 1536 * (v41 >> 4);
      if ( a2 >= 1 )
      {
        v126 = v45 - v44;
        LODWORD(v130) = &v45[24 * a2 - 8];
        v46 = v43 - v44;
        v47 = (int)&v43[24 * a2 - 16];
        v48 = v45 - v43;
        v115 = a2;
        v49 = LODWORD(v130);
        v50 = (double *)&v44[24 * a2 - 24];
        do
        {
          v49 -= 24;
          v51 = *(double *)((char *)v50 + v46) + *(double *)((char *)v50 + v126);
          v50 -= 3;
          v47 -= 24;
          v32 = v115 == 1;
          v52 = *(double *)(v47 + v48 + 24) + v50[4];
          --v115;
          v53 = v52 + *(double *)(v47 + 24) + v51 + v50[3] - fabs(v51 + v50[3] - (v52 + *(double *)(v47 + 24)));
          v54 = v50[5] + *(double *)(v47 + 32) + *(double *)(v49 + 24);
          v42 = v42 + v53 + v54 + v54 - fabs(v54 + v54 - v53);
        }
        while ( !v32 );
        v41 = v108;
      }
      if ( v42 < dbl_10145A58 )
      {
        dbl_10145A58 = v42;
        v103 = v41;
      }
      v108 = ++v41;
    }
    while ( v41 < 64 );
  }
  else if ( a1 == 4 )
  {
    v105 = 0;
    v55 = (int *)&v133;
    v56 = (char *)&unk_10141228;
    v57 = dbl_10146838;
    do
    {
      v58 = v57;
      v109 = (double *)v56;
      v121 = 4;
      do
      {
        v59 = *(v55 - 1);
        v116 = 4;
        v60 = *v55;
        v55[1] = (*v55 + 2 * v59 + 1) / 3;
        v61 = v59 + 2 * v60 + 1;
        v62 = v55 - 1;
        v55[2] = v61 / 3;
        v57 = v58;
        do
        {
          v63 = (double)*v62++;
          ++v57;
          v32 = v116-- == 1;
          *(v57 - 1) = v63 * a5[v105] * 0.00392156862745098;
        }
        while ( !v32 );
        v64 = v109;
        v65 = 0;
        LODWORD(v130) = v57;
        if ( a2 > 0 )
        {
          v66 = (double *)(v105 * 8 + a3);
          do
          {
            v67 = *v66 - *v58;
            v66 += 3;
            v64 += 4;
            v68 = v67 * v67 * a4[v65++];
            *(v64 - 4) = v68;
            v69 = *(v66 - 3) - v58[1];
            *(v64 - 3) = v69 * v69 * a4[v65 - 1];
            v70 = *(v66 - 3) - v58[2];
            *(v64 - 2) = v70 * v70 * a4[v65 - 1];
            v71 = *(v66 - 3) - v58[3];
            *(v64 - 1) = v71 * v71 * a4[v65 - 1];
          }
          while ( v65 < a2 );
          v57 = (double *)LODWORD(v130);
        }
        v55 += 4;
        v72 = (char *)(v109 + 192);
        v32 = v121 == 1;
        v109 += 192;
        v58 = v57;
        --v121;
      }
      while ( !v32 );
      v56 = v72;
      ++v105;
    }
    while ( (int)v57 < (int)dbl_101469B8 );
    v73 = 0;
    v103 = -1;
    v110 = 0;
    dbl_10145A58 = (*a5 * *a5 + a5[1] * a5[1] + a5[2] * a5[2]) * 96.0;
    do
    {
      v74 = 0.0;
      v75 = (char *)&unk_10141228 + 1536 * (v73 & 3);
      v76 = (char *)&unk_10142A28 + 1536 * ((v73 >> 2) & 3);
      v77 = (char *)&unk_10144228 + 1536 * (v73 >> 4);
      if ( a2 >= 1 )
      {
        v127 = v77 - v76;
        LODWORD(v130) = &v77[32 * a2 - 8];
        v78 = v75 - v76;
        v79 = (double *)&v75[32 * a2 - 24];
        v80 = v77 - v75;
        v117 = a2;
        v81 = LODWORD(v130);
        v82 = (double *)&v76[32 * a2 - 32];
        do
        {
          v81 -= 32;
          v83 = *(double *)((char *)v82 + v78) + *(double *)((char *)v82 + v127);
          v82 -= 4;
          v79 -= 4;
          v32 = v117 == 1;
          v84 = *(double *)((char *)v79 + v80 + 32) + v82[5];
          --v117;
          v85 = v84 + v79[4] + v83 + v82[4] - fabs(v83 + v82[4] - (v84 + v79[4]));
          v86 = v82[6] + v79[5] + *(double *)(v81 + 24);
          v87 = v82[7] + v79[6] + *(double *)(v81 + 32);
          v88 = v87 + v86 - fabs(v86 - v87);
          v74 = v74 + v85 + v88 - fabs(v88 - v85);
        }
        while ( !v32 );
        v73 = v110;
      }
      if ( v74 < dbl_10145A58 )
      {
        dbl_10145A58 = v74;
        v103 = v73;
      }
      v110 = ++v73;
    }
    while ( v73 < 64 );
  }
  v89 = a7;
  v122 = &dbl_10146838[4 * (v103 & 3)];
  v124 = (double *)((char *)&unk_101468B8 + 32 * ((v103 >> 2) & 3));
  v128 = (char *)&unk_10146938 + 32 * (v103 >> 4);
  v90 = 0;
  v111 = 0;
  LODWORD(v130) = (char *)&unk_100C9860 - a7;
  do
  {
    v91 = 2;
    v92 = v89;
    v93 = (int *)&v132[64 * v90 + 16 * ((v103 >> (2 * v90)) & 3)];
    do
    {
      ++v93;
      v92 += 12;
      --v91;
      *(_DWORD *)(v92 - 12) = *(v93 - 1) >> (8 - *(_BYTE *)(LODWORD(v130) + v89));
    }
    while ( v91 != 0 );
    v89 += 4;
    v90 = ++v111;
  }
  while ( v111 < 3 );
  v112 = 0;
  result = 0.0;
  if ( a2 > 0 )
  {
    v106 = a4;
    v95 = v124;
    v96 = (double *)(a3 + 8);
    do
    {
      v97 = 0;
      v118 = -1;
      v98 = a5[2] * a5[2];
      v99 = *a5 * *a5 + a5[1] * a5[1] + v98 + *a5 * *a5 + a5[1] * a5[1] + v98;
      if ( a1 > 0 )
      {
        v100 = v128 - (char *)v95;
        do
        {
          v101 = *(v96 - 1) - *(double *)((char *)v95 + (char *)v122 - (char *)v124);
          v102 = v96[1] - *(double *)((char *)v95 + v100);
          v130 = ((*v96 - *v95) * (*v96 - *v95) + v101 * v101 + v102 * v102) * *v106;
          if ( v130 < v99 )
          {
            v99 = v130;
            v118 = v97;
          }
          ++v97;
          ++v95;
        }
        while ( v97 < a1 );
        v95 = v124;
      }
      v96 += 3;
      *(_DWORD *)(a8 + 4 * v112) = v118;
      result = result + v99;
      ++v112;
      ++v106;
    }
    while ( v112 < a2 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026FC0
// Name: sub_10026FC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sub_10026FC0(int a1, int a2, double *a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // edi
  int v7; // ecx
  __int16 v8; // fps
  bool v9; // c0
  char v10; // c2
  bool v11; // c3
  double v12; // st7
  int v13; // eax
  double v14; // st7
  int v15; // esi
  int v16; // edx
  int v17; // ebx
  double v18; // st7
  double v19; // st6
  int v20; // edx
  double *v21; // esi
  int i; // ecx
  int v23; // edi
  int v24; // eax
  int v25; // eax
  double v26; // st7
  double v27; // st5
  double v28; // st4
  double v29; // st4
  double v30; // st3
  double v31; // kr00_8
  long double v32; // st2
  long double v33; // st1
  long double v34; // st7
  bool v35; // zf
  int v36; // ecx
  int v37; // edx
  int v38; // eax
  int *v39; // esi
  __int16 v40; // fps
  double v41; // st7
  bool v42; // c0
  char v43; // c2
  bool v44; // c3
  int v45; // eax
  int *v46; // edx
  int v47; // edx
  int v48; // ecx
  int v49; // eax
  double v50; // st7
  double v51; // st6
  double v52; // st5
  long double v53; // st4
  long double v54; // st3
  double v55; // st7
  int *v56; // edi
  double *v57; // esi
  __int64 v58; // rax
  int v59; // ecx
  int v60; // esi
  int v61; // eax
  int v62; // edx
  int v63; // ebx
  int v64; // ecx
  int v65; // esi
  int v66; // edi
  double v67; // st7
  long double v68; // st6
  __int16 v69; // fps
  long double v70; // st5
  bool v71; // c0
  char v72; // c2
  bool v73; // c3
  double v74; // st7
  double v75; // st6
  long double v76; // [esp+18h] [ebp-110h]
  int v77; // [esp+18h] [ebp-110h]
  double v78; // [esp+18h] [ebp-110h]
  long double v79; // [esp+20h] [ebp-108h]
  double v80; // [esp+20h] [ebp-108h]
  double v81; // [esp+20h] [ebp-108h]
  int v82; // [esp+2Ch] [ebp-FCh]
  long double v83; // [esp+30h] [ebp-F8h]
  long double v84; // [esp+30h] [ebp-F8h]
  double v85; // [esp+38h] [ebp-F0h]
  double v86; // [esp+38h] [ebp-F0h]
  double v87; // [esp+38h] [ebp-F0h]
  int v88; // [esp+44h] [ebp-E4h]
  int v89; // [esp+44h] [ebp-E4h]
  long double v90; // [esp+48h] [ebp-E0h]
  long double v91; // [esp+50h] [ebp-D8h]
  double v92; // [esp+50h] [ebp-D8h]
  double v93; // [esp+58h] [ebp-D0h]
  double v94; // [esp+60h] [ebp-C8h]
  double v95; // [esp+60h] [ebp-C8h]
  double v96; // [esp+68h] [ebp-C0h]
  double v97; // [esp+68h] [ebp-C0h]
  double v98; // [esp+70h] [ebp-B8h]
  double v99; // [esp+78h] [ebp-B0h]
  int v100; // [esp+84h] [ebp-A4h]
  double v101; // [esp+88h] [ebp-A0h]
  double v102; // [esp+88h] [ebp-A0h]
  double v103; // [esp+90h] [ebp-98h]
  int v104; // [esp+98h] [ebp-90h] BYREF
  int v105; // [esp+9Ch] [ebp-8Ch]
  double v106; // [esp+B8h] [ebp-70h]
  double v107; // [esp+C0h] [ebp-68h]
  double v108; // [esp+C8h] [ebp-60h]
  double v109; // [esp+D0h] [ebp-58h]
  double v110; // [esp+D8h] [ebp-50h]
  double v111; // [esp+E0h] [ebp-48h]
  _DWORD v112[16]; // [esp+E8h] [ebp-40h] BYREF

  v5 = a2;
  v100 = 64;
  if ( a2 == 0 )
    return 0.0;
  v7 = 1;
  dbl_10147B00 = (double)a2;
  dbl_10145A28 = 1.0 / dbl_10147B00;
  dbl_10147938 = *a3;
  dbl_10147930 = dbl_10147938;
  dbl_10146BA0[0] = dbl_10147938;
  for ( *a5 = 0; v7 < a2; *a5 = 0 )
  {
    v9 = dbl_10147930 < a3[v7];
    v10 = 0;
    v11 = dbl_10147930 == a3[v7];
    if ( (v8 & 0x4100) == 0 )
      dbl_10147930 = a3[v7];
    if ( dbl_10147938 < a3[v7] )
      dbl_10147938 = a3[v7];
    v12 = dbl_10146BA0[0] + a3[v7++];
    dbl_10146BA0[0] = v12;
  }
  v13 = 0;
  for ( dbl_10146BA0[0] = dbl_10146BA0[0] * dbl_10145A28; v13 < a2; dbl_10146BA0[v13] = v14 )
    v14 = a3[v13++] - dbl_10146BA0[0];
  v15 = a1;
  dbl_10147930 = dbl_10147930 - dbl_10146BA0[0];
  v82 = a1 - 1;
  dbl_10147938 = dbl_10147938 - dbl_10146BA0[0];
  while ( 1 )
  {
    v16 = 0;
    v17 = 1;
    v88 = 0;
    if ( v82 > 0 )
    {
      v18 = (dbl_10147938 - dbl_10147930) / (double)v82;
      memset(&v104, 0, 4 * v82);
      do
      {
        v19 = (double)v88;
        v88 = ++v16;
        dbl_10147AB8[v16] = (v19 + 0.5) * v18 + dbl_10147930;
      }
      while ( v16 < v82 );
      v5 = a2;
    }
    v20 = 0;
    *((_DWORD *)&v103 + v15 + 1) = 0;
    if ( v5 > 0 )
    {
      v21 = dbl_10146BA8;
      do
      {
        for ( i = 0; i < v82; ++i )
        {
          if ( *v21 < dbl_10147AC0[i] )
            break;
        }
        ++*(&v104 + i);
        v17 = (a5[v20] == i) & (unsigned __int8)v17;
        ++v21;
        a5[v20++] = i;
      }
      while ( v20 < a2 );
      v15 = a1;
    }
    v23 = 0;
    v24 = 0;
    v89 = 0;
    if ( v15 > 0 )
    {
      do
        v23 += *(&v104 + v24++) != 0;
      while ( v24 < v15 );
      v89 = v23;
      if ( v23 == 1 )
        break;
    }
    v25 = 0;
    dbl_10147AF8 = 0.0;
    dbl_10148170 = 0.0;
    for ( dbl_10149C90 = 0.0; v25 < a2; dbl_10147AF8 = v26 * v26 + dbl_10147AF8 )
    {
      ++v25;
      dbl_10149C90 = (double)(int)a5[v25 - 1] * dbl_10146BA0[v25] + dbl_10149C90;
      dbl_10148170 = (double)(int)a5[v25 - 1] + dbl_10148170;
      v26 = (double)(int)a5[v25 - 1];
    }
    dbl_10148170 = dbl_10148170 * dbl_10145A28;
    dbl_10147AF8 = dbl_10147AF8 - dbl_10148170 * dbl_10148170 * dbl_10147B00;
    v103 = (double)a1 - 1.0;
    v27 = dbl_10147B00 * -dbl_10148170 * -dbl_10148170 + dbl_10147AF8;
    v28 = dbl_10147B00 * (v103 - dbl_10148170);
    v94 = v28 * -dbl_10148170 + dbl_10147AF8;
    v29 = v28 * (v103 - dbl_10148170) + dbl_10147AF8;
    v85 = v29 * v27;
    v106 = v103 * v103;
    v96 = v106 * dbl_10147AF8 * v85 * v85;
    v30 = -(dbl_10147AF8 * dbl_10146BA0[0]);
    v108 = 1.0 - dbl_10146BA0[0];
    v101 = dbl_10149C90 * -dbl_10148170;
    v31 = dbl_10149C90 * (v103 - dbl_10148170);
    v76 = v30 - v101;
    v79 = v108 * dbl_10147AF8 - v101;
    qword_10145A30 = *(_QWORD *)&dbl_10147930;
    v32 = (v79 - fabs(v79) + fabs(v76) + v76) * 0.5 * v94;
    qword_10145A38 = *(_QWORD *)&dbl_10147938;
    v33 = ((v108 * dbl_10147AF8 - v31) * v27
         - fabs((v108 * dbl_10147AF8 - v31) * v27 - v32)
         + fabs((v30 - v31) * v27 - v32)
         + (v30 - v31) * v27)
        * 0.5;
    v90 = v33 * v29;
    v83 = (v79 * v85 - fabs(v79 * v85 - v33 * v94) + fabs(v76 * v85 - v33 * v94) + v76 * v85) * 0.5;
    v34 = -dbl_10148170 * v90 - v83 * (v103 - dbl_10148170);
    dbl_10149DF8 = dbl_10147AF8 * (v83 - v90) * (v83 - v90)
                 + dbl_10147B00 * v34 * v34
                 - dbl_10149C90 * dbl_10149C90 * v96;
    dbl_10145EE0 = dbl_10147AF8 * v96;
    v35 = v100-- == 0;
    dbl_10147930 = (1.0 / v85 * v83 + v101) * (1.0 / dbl_10147AF8);
    dbl_10147938 = (1.0 / v85 * v90 + v31) * (1.0 / dbl_10147AF8);
    if ( v35 )
      break;
    if ( v17 != 0 )
    {
      if ( v15 > 0 )
        memset(v112, 0xFFu, 4 * v15);
      v36 = 0;
      if ( a2 > 0 )
      {
        do
        {
          v37 = a5[v36];
          v38 = v112[v37];
          v39 = &v112[v37];
          if ( v38 == -1 )
          {
            v112[v37 + 8] = v36;
            *v39 = v36;
          }
          else
          {
            v41 = dbl_10146BA8[v38];
            v42 = v41 < dbl_10146BA8[v36];
            v43 = 0;
            v44 = v41 == dbl_10146BA8[v36];
            if ( (v40 & 0x4100) == 0 )
              *v39 = v36;
            v45 = v112[v37 + 8];
            v46 = &v112[v37 + 8];
            if ( dbl_10146BA8[v45] < dbl_10146BA8[v36] )
              *v46 = v36;
          }
          ++v36;
        }
        while ( v36 < a2 );
        v15 = a1;
      }
      v47 = 0;
      v110 = dbl_10147AF8 + 1.0;
      while ( 1 )
      {
        v99 = 1.0;
        if ( v47 != 0 )
          HIDWORD(v99) = -1074790400;
        v48 = v47;
        v77 = v47;
        v107 = dbl_10145A28 * v99 + dbl_10148170;
        v111 = v110 - (dbl_10148170 * v99 + dbl_10148170 * v99) - dbl_10145A28;
        if ( v47 < v47 + v82 )
          break;
LABEL_51:
        if ( ++v47 >= 2 )
          goto LABEL_52;
      }
      while ( 1 )
      {
        v49 = *(&v104 + v48);
        if ( v49 != 0 && (v49 > 1 || v89 > 2) )
        {
          v93 = v99 * dbl_10146BA8[v112[v48 - 8 * v47 + 8]] + dbl_10149C90;
          v78 = (double)v77 * v99 + (double)v77 * v99 + v111;
          v97 = -v107;
          v95 = v103 - v107;
          v50 = v97 * v97 * dbl_10147B00 + v78;
          v51 = v95 * v97 * dbl_10147B00 + v78;
          v102 = v95 * v95 * dbl_10147B00 + v78;
          v98 = v102 * v50;
          v86 = v106 * v98 * v98 * v78;
          v52 = -(v78 * dbl_10146BA0[0]);
          v80 = v95 * v93;
          v91 = v52 - v97 * v93;
          v84 = v108 * v78 - v97 * v93;
          v109 = (v52 - v80) * v50;
          v53 = (v84 - fabs(v84) + fabs(v91) + v91) * 0.5 * v51;
          v54 = ((v108 * v78 - v80) * v50 - fabs((v108 * v78 - v80) * v50 - v53) + fabs(v109 - v53) + v109) * 0.5;
          v81 = v54 * v102;
          v92 = (v84 * v98 - fabs(v84 * v98 - v54 * v51) + fabs(v91 * v98 - v54 * v51) + v91 * v98) * 0.5;
          v55 = (v81 * v97 - v92 * v95) * (v81 * v97 - v92 * v95) * dbl_10147B00
              + (v92 - v81) * (v92 - v81) * v78
              - v86 * v93 * v93;
          v87 = v86 * v78;
          if ( v55 * dbl_10145EE0 < v87 * dbl_10149DF8 )
            break;
        }
        v77 = ++v48;
        if ( v48 >= v47 + v15 - 1 )
          goto LABEL_51;
      }
      dbl_10145EE0 = v87;
      dbl_10147930 = (v92 * (1.0 / v98) + v97 * v93) * (1.0 / v78);
      dbl_10147938 = (v81 * (1.0 / v98) + v95 * v93) * (1.0 / v78);
      dbl_10149DF8 = v55;
    }
    v5 = a2;
  }
LABEL_52:
  v56 = &v104;
  v57 = &dbl_10147930;
  do
  {
    v58 = (__int64)floor(X: (dbl_10146BA0[0] + *v57) * 255.0 + 0.5);
    *v56 = v58;
    if ( (int)v58 >= 0 )
    {
      if ( (int)v58 > 255 )
        LODWORD(v58) = 255;
    }
    else
    {
      LODWORD(v58) = 0;
    }
    *v56 = v58;
    ++v57;
    ++v56;
  }
  while ( (int)v57 < (int)&dbl_10147940 );
  v59 = 2;
  if ( a1 > 2 )
  {
    v60 = a1 - 2;
    do
    {
      v61 = (v105 * (v59++ - 1) + (a1 - 2) / 2 + v104 * v60--) / v82;
      *((_DWORD *)&v103 + v59 + 1) = v61;
    }
    while ( v59 < a1 );
  }
  v62 = v105;
  v63 = 0;
  *a4 = v104;
  a4[1] = v62;
  for ( dbl_10149FD8 = 0.0; v63 < a2; dbl_10149FD8 = (v74 - v75) * (v74 - v75) + dbl_10149FD8 )
  {
    v64 = 1;
    v65 = 0;
    if ( a1 > 1 )
    {
      v66 = 0;
      v67 = a3[v63] * 255.0;
      do
      {
        v68 = fabs((double)*(&v104 + v64) - v67);
        v70 = fabs((double)*(int *)((char *)&v104 + v66) - v67);
        v71 = v70 < v68;
        v72 = 0;
        v73 = v70 == v68;
        if ( (v69 & 0x4100) == 0 )
        {
          v65 = v64;
          v66 = 4 * v64;
        }
        ++v64;
      }
      while ( v64 < a1 );
    }
    v74 = (double)*(&v104 + v65);
    a5[v63] = v65;
    v75 = a3[v63++] * 255.0;
  }
  return dbl_10149FD8;
}

} // namespace vtex_dll
