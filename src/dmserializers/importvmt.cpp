// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmserializers/importvmt.cpp
// Functions: 25
// ============================================================

#include "dmserializers\importvmt.h"

//------------------------------------------------------------------------------
// Address: 0x0045B120
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x0045B140
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x0045B170
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0045B280
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B3E0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: &defaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B500
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B580
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B5F0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B660
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B6D0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B740
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B7B0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045B820
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x0045B830
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x0045B840
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045B8F0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x0045BAC0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &defaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BC10
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = &defaultValue;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = &defaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = &defaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = &defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = &defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = &defaultValue;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045BFE0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = &defaultValue;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045C070
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C190
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C2F0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C380
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        DmElementHandle_t pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = CImportKeyValueBase::CreateDmElement(
                    this: v32,
                    pElementType: "DmElement",
                    pElementName: Name,
                    pId: nullptr);
      v11 = DmElement;
      if ( DmElement != nullptr )
        pElement = CDmElement::GetHandle(this: DmElement);
      else
        pElement = DMELEMENT_HANDLE_INVALID;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: &pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: (int *)&pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: &::defaultValue);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045C640
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(
        CImportVMT *this,
        DmElementHandle_t pElement,
        KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
    v10 = DmElement;
    if ( DmElement != nullptr )
      pElement = CDmElement::GetHandle(this: DmElement);
    else
      pElement = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: &pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045C790
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (DmElementHandle_t)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(
          this,
          a2: (const char *)this,
          pElement: (DmElementHandle_t)DmElement,
          pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00470B10
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x00470B30
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00470B60
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00470C70
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: var);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470DD0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: var);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470EF0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00470F70
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00470FE0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471050
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004710C0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471130
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004711A0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471210
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00471220
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00471230
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004712E0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x004714B0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: var);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471600
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  const int *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, *v4);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = var;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = var;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = var;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = var;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004719C0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = var;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00471A50
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471B70
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471CD0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00471D60
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: var);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00472020
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00472170
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A9C10
// Name: _dynamic_initializer_for__Import_LuaFunc_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Import_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Import_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Import_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9C30
// Name: _dynamic_initializer_for__ListDeltas_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ListDeltas_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ListDeltas_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ListDeltas_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9C50
// Name: _dynamic_initializer_for__DeltaCount_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__DeltaCount_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  DeltaCount_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &DeltaCount_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9C70
// Name: _dynamic_initializer_for__DeltaName_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__DeltaName_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  DeltaName_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &DeltaName_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9C90
// Name: _dynamic_initializer_for__ImportComboRules_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ImportComboRules_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ImportComboRules_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ImportComboRules_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9CB0
// Name: _dynamic_initializer_for__SetState_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SetState_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SetState_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SetState_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9CD0
// Name: _dynamic_initializer_for__ResetState_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ResetState_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ResetState_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ResetState_LuaFunc_s;
  return result;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004AD620
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x004AD640
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x004AD670
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004AD780
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case 1:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: ::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case 2:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case 3:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case 4:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AD8E0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: defaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ADA00
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADA80
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADAF0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADB60
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADBD0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADC40
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADCB0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, const int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004ADD20
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x004ADD30
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x004ADD40
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ADDF0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x004ADFC0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AE110
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = defaultValue;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = defaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = defaultValue;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004AE4D0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = defaultValue;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AE560
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE680
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE7E0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AE870
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (const DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: ::defaultValue);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004AEB30
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (const DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004AEC80
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104BD460
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x104BD480
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x104BD4B0
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = (char *)(v4 + 1);
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x104BD5C0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  char *Name; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  KeyValues *j; // esi
  char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  char *String; // [esp-4h] [ebp-10h]
  int Int; // [esp-4h] [ebp-10h]
  float Float; // [esp-4h] [ebp-10h]
  void *Ptr; // [esp-4h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = (char *)KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case 1:
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &var);
        v5 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: String);
        break;
      case 2:
        Int = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: Int);
        break;
      case 3:
        Float = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: Float);
        break;
      case 4:
        Ptr = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: Ptr);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = (char *)KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BD720
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: &var);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BD840
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BD8C0
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BD930
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BD9A0
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BDA10
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BDA80
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BDAF0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BDB60
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x104BDB70
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x104BDB80
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BDC30
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  float y; // [esp+10h] [ebp-98h] BYREF
  VMatrix temp; // [esp+1Ch] [ebp-8Ch] BYREF
  VMatrix mat; // [esp+5Ch] [ebp-4Ch] BYREF
  Vector2D scale; // [esp+9Ch] [ebp-Ch] BYREF
  Vector2D translation; // [esp+A4h] [ebp-4h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &temp.m[3][1],
         &temp.m[3][2],
         &temp.m[3][3],
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: (VMatrix *)&temp.m[3][1]);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &scale.y,
         &translation,
         &mat.m[3][1],
         &mat.m[3][2],
         &pScan,
         &mat.m[3][3],
         &scale) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: (VMatrix *)&temp.m[3][1],
    x: COERCE_FLOAT(LODWORD(scale.y) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(translation.x) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: (VMatrix *)&y, x: LODWORD(mat.m[3][1]), y: LODWORD(mat.m[3][2]), z: 1.0);
  MatrixMultiply(src1: (VMatrix *)&y, src2: (VMatrix *)&temp.m[3][1], dst: (VMatrix *)&temp.m[3][1]);
  MatrixBuildRotateZ(dst: (VMatrix *)&y, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: (VMatrix *)&y, src2: (VMatrix *)&temp.m[3][1], dst: (VMatrix *)&temp.m[3][1]);
  MatrixBuildTranslation(dst: (VMatrix *)&y, x: mat.m[3][3] + scale.y, y: scale.x + translation.x, z: 0.0);
  MatrixMultiply(src1: (VMatrix *)&y, src2: (VMatrix *)&temp.m[3][1], dst: (VMatrix *)&temp.m[3][1]);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: (VMatrix *)&temp.m[3][1]);
}

//------------------------------------------------------------------------------
// Address: 0x104BDE00
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  char *String; // eax
  char *v10; // esi
  char pDest[4]; // [esp+Ch] [ebp-204h] BYREF
  char pParamName[512]; // [esp+10h] [ebp-200h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = (char *)KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest, pSrc: Name, maxLen: 512);
  _V_strlower(start: pDest);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pDest, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      *(_DWORD *)&pParamName[508] = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pDest, value: (int *)&pParamName[508]);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &var);
    v10 = String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName: pDest, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName: pDest, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pDest, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pDest, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104BDF60
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = &var;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = &var;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = &var;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = &var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = &var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = &var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = &var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = &var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = &var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = &var;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104BE320
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = &var;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &var;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104BE3B0
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BE4D0
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BE630
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BE6C0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *v27; // [esp+0h] [ebp-24h]
  CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > v29; // [esp+10h] [ebp-14h] BYREF
  CUtlSymbolLarge defaultValue; // [esp+18h] [ebp-Ch] BYREF
  CUtlSymbolLarge v31; // [esp+1Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+20h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: &v29);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    v29.m_pAttribute = v6;
    v29.m_pStorage = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)v6->m_pData;
  }
  else
  {
    v29.m_pAttribute = nullptr;
    v29.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&v29,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &v31,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, value: &v31);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &defaultValue);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &defaultValue);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          v27 = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, v27);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: &var);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &defaultValue, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &defaultValue);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104BE980
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104BEAD0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004938E0
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x00493900
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00493930
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00493A40
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: WindowName);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493BA0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: WindowName);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00493CC0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493D40
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493DB0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493E20
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493E90
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493F00
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493F70
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00493FE0
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00493FF0
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00494000
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004940B0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x00494280
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: WindowName);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004943D0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *m_Id; // eax
  const char *v11; // esi
  const Vector2D *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  const Color *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = WindowName;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = WindowName;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = WindowName;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = WindowName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, m_Id);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = WindowName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->_color[0],
        v18->_color[1],
        v18->_color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = WindowName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->x, v12->y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = WindowName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = WindowName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = WindowName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = WindowName;
      v23 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 88))(
                            a1: g_pDataModel.u,
                            a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00494790
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = WindowName;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = WindowName;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00494820
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = (CDmElement *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v8 = nullptr;
        }
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00494940
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = (CDmElement *)v7;
          if ( v7 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v8 = nullptr;
          }
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00494AA0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00494B30
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        DmElementHandle_t pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = CImportKeyValueBase::CreateDmElement(
                    this: v32,
                    pElementType: "DmElement",
                    pElementName: Name,
                    pId: nullptr);
      v11 = DmElement;
      if ( DmElement != nullptr )
        pElement = CDmElement::GetHandle(this: DmElement);
      else
        pElement = DMELEMENT_HANDLE_INVALID;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: &pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: (int *)&pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: WindowName);
      v25 = KeyValues::GetName(this: v16);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v30,
        a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00494DF0
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(
        CImportVMT *this,
        DmElementHandle_t pElement,
        KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
    v10 = DmElement;
    if ( DmElement != nullptr )
      pElement = CDmElement::GetHandle(this: DmElement);
    else
      pElement = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: &pElement);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
      a1: g_pDataModel.u,
      a2: &pElement,
      a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00494F40
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (DmElementHandle_t)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(
          this,
          a2: (const char *)this,
          pElement: (DmElementHandle_t)DmElement,
          pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005174E0
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x00517500
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00517530
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00517640
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: pDefaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005177A0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: pDefaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005178C0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00517940
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005179B0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00517A20
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00517A90
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00517B00
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00517B70
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00517BE0
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00517BF0
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00517C00
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00517CB0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x00517E80
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: pDefaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00517FD0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDefaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = pDefaultValue;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = pDefaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = pDefaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = pDefaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = pDefaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = pDefaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = pDefaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = pDefaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = pDefaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = pDefaultValue;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00518390
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  unsigned __int8 *v3; // esi
  const char *v4; // eax
  const char *v5; // edi

  v3 = CVTFTexture::ImageData(this: (CVTFTexture *)pRoot);
  if ( v3 == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)v3) )
    {
      v4 = *((const char **)v3 + 5);
      v5 = pDefaultValue;
      if ( v4 == (const char *)-1 )
        v4 = pDefaultValue;
      else
        v5 = *((const char **)v3 + 5);
      if ( _V_stricmp(s1: v4, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (v3[16] & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: (CDmAttribute *)v3) )
      {
        break;
      }
    }
    v3 = *(unsigned __int8 **)v3;
    if ( v3 == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00518420
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00518540
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005186A0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00518730
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CVTFTexture *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CVTFTexture *)CImportKeyValueBase::CreateDmElement(
                                   this: v32,
                                   pElementType: "DmElement",
                                   pElementName: Name,
                                   pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CVTFTexture::MipCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: pDefaultValue);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005189F0
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CVTFTexture *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CVTFTexture *)CImportKeyValueBase::CreateDmElement(
                                 this,
                                 pElementType: "DmElement",
                                 pElementName: Name,
                                 pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CVTFTexture::MipCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00518B40
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004D7AF0
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x004D7B10
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x004D7B40
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004D7C50
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: pDeltaStateName);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D7DB0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: pDeltaStateName);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D7ED0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D7F50
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D7FC0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D8030
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D80A0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D8110
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D8180
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D81F0
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x004D8200
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x004D8210
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D82C0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x004D8490
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: pDeltaStateName);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D85E0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = pDeltaStateName;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = pDeltaStateName;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = pDeltaStateName;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = pDeltaStateName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = pDeltaStateName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = pDeltaStateName;
      v23 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 88))(
                            a1: g_pDataModel.u,
                            a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D89A0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = pDeltaStateName;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D8A30
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = (CDmElement *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v8 = nullptr;
        }
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D8B50
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = (CDmElement *)v7;
          if ( v7 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v8 = nullptr;
          }
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D8CB0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D8D40
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: pDeltaStateName);
      v25 = KeyValues::GetName(this: v16);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v30,
        a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D9000
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
      a1: g_pDataModel.u,
      a2: &pElement,
      a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D9150
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0045CC10
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x0045CC30
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x0045CC60
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0045CD70
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: ::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CED0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: defaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CFF0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D070
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D0E0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D150
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D1C0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D230
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D2A0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, const int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D310
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x0045D320
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x0045D330
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D3E0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x0045D5B0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D700
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = defaultValue;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = defaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = defaultValue;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045DAC0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = defaultValue;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045DB50
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DC70
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DDD0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DE60
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        DmElementHandle_t pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = CImportKeyValueBase::CreateDmElement(
                    this: v32,
                    pElementType: "DmElement",
                    pElementName: Name,
                    pId: nullptr);
      v11 = DmElement;
      if ( DmElement != nullptr )
        pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
      else
        pElement = DMELEMENT_HANDLE_INVALID;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: &pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: (const int *)&pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: ::defaultValue);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E120
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(
        CImportVMT *this,
        DmElementHandle_t pElement,
        KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
    v10 = DmElement;
    if ( DmElement != nullptr )
      pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
    else
      pElement = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: &pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045E270
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (DmElementHandle_t)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(
          this,
          a2: (const char *)this,
          pElement: (DmElementHandle_t)DmElement,
          pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0045E6F0
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x0045E710
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x0045E740
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0045E850
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  char *Name; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  KeyValues *j; // esi
  char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = (char *)KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: str);
        v5 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = (char *)KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E9B0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: str);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EAD0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EB50
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EBC0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EC30
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045ECA0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045ED10
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045ED80
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EDF0
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x0045EE10
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x0045EE20
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045EED0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pScan)
{
  char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x0045F0A0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        *(float *)&pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: (float *)&pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: str);
    v10 = String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F1F0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  float *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = str;
      v9 = (float *)CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, *v9);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = str;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = str;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = str;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = str;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = str;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = str;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = str;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = str;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = str;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045F5B0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = str;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = str;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045F640
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045F760
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045F8C0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045F950
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        KeyValues *pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: pKeyValues);
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        *(float *)&pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: (float *)&pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: str);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045FC10
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045FD60
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00467700
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x00467720
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00467750
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  char v5; // bl
  float *v6; // ebp
  char *v7; // esi
  int v8; // edi
  char v9; // al

  v4 = pScan;
  v5 = 0;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    v5 = 1;
  v6 = vecVal;
  v7 = (char *)(v4 + 1);
  v8 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v9 = *v7;
      if ( *v7 != 32 && v9 != 9 )
        break;
      ++v7;
    }
    if ( v9 == 10 || v9 == 0 )
      break;
    if ( v9 == 93 )
      goto LABEL_22;
    if ( v9 == 125 )
      break;
    v6[v8] = strtod(nptr: v7, endptr: &pScan);
    if ( v7 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v8;
    v7 = pScan;
    if ( v8 >= 4 )
      goto LABEL_23;
  }
  if ( *v7 != 93 && *v7 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v6[v8] = 0.0;
LABEL_23:
  if ( v5 != 0 )
  {
    *v6 = *v6 * 0.0039215689;
    v6[1] = v6[1] * 0.0039215689;
    v6[2] = v6[2] * 0.0039215689;
    v6[3] = 0.0039215689 * v6[3];
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00467840
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  char *Name; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  KeyValues *j; // esi
  char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  char *defaultValue; // [esp+0h] [ebp-14h]
  int defaultValuea; // [esp+0h] [ebp-14h]
  float defaultValueb; // [esp+0h] [ebp-14h]
  void *defaultValuec; // [esp+0h] [ebp-14h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = (char *)KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: ::defaultValue);
        v5 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = (char *)KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004679A0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CImportVMT::ExpandPatchFile(CImportVMT *this@<ecx>, char *String@<ebx>, KeyValues *pKeyValues)
{
  int v3; // ebp
  const char *Name; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  KeyValues *Key; // eax
  KeyValues *v9; // eax
  int v10; // [esp+0h] [ebp-10h]

  v3 = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _stricmp(a1: (unsigned int)String, a2: (unsigned int)pKeyValues, dst: Name, src: "patch") != 0 )
      break;
    String = (char *)KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: defaultValue);
    if ( String == nullptr )
      break;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x20u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "vmt");
    else
      v6 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v7 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v7 = nullptr;
    if ( !KeyValues::LoadFromFile(this: v6, a2: v3, filesystem: v7, resourceName: String, pathID: nullptr, a6: v10) )
    {
      KeyValues::deleteThis(this: v6);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v6, src: Key, bCheckForExistence: false);
    v9 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v9 != nullptr )
      InsertKeyValues(dst: v6, src: v9, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v6);
    KeyValues::deleteThis(this: v6);
    if ( ++v3 >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467B70
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // eax

  if ( pElement == nullptr )
    return 0;
  if ( CDmElement::SetValue<float>(this: pElement, pAttributeName, value) == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  Attribute->m_nFlags |= 0x4000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467BB0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // eax

  if ( pElement == nullptr )
    return 0;
  if ( CDmElement::SetValue<Vector2D>(this: pElement, pAttributeName, value) == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  Attribute->m_nFlags |= 0x4000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467BF0
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // eax

  if ( pElement == nullptr )
    return 0;
  if ( CDmElement::SetValue<Vector>(this: pElement, pAttributeName, value) == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  Attribute->m_nFlags |= 0x4000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467C30
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // eax

  if ( pElement == nullptr )
    return 0;
  if ( CDmElement::SetValue<Vector4D>(this: pElement, pAttributeName, value) == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  Attribute->m_nFlags |= 0x4000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467C70
// Name: public: virtual char const __near * CImportVMT::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetName(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00467C80
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00467C90
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+0h] [ebp-14h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.y);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.y);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(
                 pElement,
                 pAttributeName: pParamName,
                 value: (const Vector2D *)&vecVal.y);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal.y);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: (Vector4D *)&vecVal.y);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467D50
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pScan)
{
  CDmAttribute *Attribute; // eax
  float x; // [esp+0h] [ebp-B0h]
  float xa; // [esp+0h] [ebp-B0h]
  float y; // [esp+4h] [ebp-ACh]
  float ya; // [esp+4h] [ebp-ACh]
  Vector2D center; // [esp+10h] [ebp-A0h] BYREF
  Vector2D scale; // [esp+18h] [ebp-98h] BYREF
  Vector2D translation; // [esp+20h] [ebp-90h] BYREF
  float angle; // [esp+28h] [ebp-88h] BYREF
  VMatrix mat; // [esp+2Ch] [ebp-84h] BYREF
  VMatrix temp; // [esp+6Ch] [ebp-44h] BYREF

  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3],
         &temp) != 16 )
  {
    if ( sscanf(
           string: pScan,
           format: " center %f %f scale %f %f rotate %f translate %f %f",
           &center.y,
           &scale,
           &scale.y,
           &translation,
           &mat,
           &translation.y,
           &angle) != 7 )
      return 0;
    y = -scale.x;
    x = -center.y;
    MatrixBuildTranslation(dst: (VMatrix *)&mat.m[0][1], x, y, z: 0.0);
    MatrixBuildScale(dst: (VMatrix *)&temp.m[0][1], x: scale.y, y: translation.x, z: 1.0);
    MatrixMultiply(src1: (VMatrix *)&temp.m[0][1], src2: (VMatrix *)&mat.m[0][1], dst: (VMatrix *)&mat.m[0][1]);
    MatrixBuildRotateZ(dst: (VMatrix *)&temp.m[0][1], angleDegrees: mat.m[0][0]);
    MatrixMultiply(src1: (VMatrix *)&temp.m[0][1], src2: (VMatrix *)&mat.m[0][1], dst: (VMatrix *)&mat.m[0][1]);
    ya = angle + scale.x;
    xa = translation.y + center.y;
    MatrixBuildTranslation(dst: (VMatrix *)&temp.m[0][1], x: xa, y: ya, z: 0.0);
    MatrixMultiply(src1: (VMatrix *)&temp.m[0][1], src2: (VMatrix *)&mat.m[0][1], dst: (VMatrix *)&mat.m[0][1]);
  }
  if ( pElement == nullptr
    || CDmElement::SetValue<VMatrix>(this: pElement, pAttributeName: pParamName, value: (VMatrix *)&mat.m[0][1]) == nullptr )
  {
    return 0;
  }
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName: pParamName);
  Attribute->m_nFlags |= 0x4000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467F10
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmAttribute *Attribute; // eax

  if ( pElement == nullptr )
    return 0;
  if ( CDmElement::SetValue<char const>(this: pElement, pAttributeName, pValue: value) == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  Attribute->m_nFlags |= 0x4000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00467F50
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, KeyValues *pKeyValues)
{
  char *Name; // eax
  __int32 v5; // eax
  __int32 v6; // eax
  CDmAttribute *Attribute; // eax
  char *String; // eax
  char *v10; // edi
  int value; // [esp+10h] [ebp-20Ch] BYREF
  char pParamName[512]; // [esp+14h] [ebp-208h] BYREF

  Name = (char *)KeyValues::GetName(this: pKeyValues);
  V_strncpy(pDest: &pParamName[4], pSrc: Name, maxLen: 512);
  strlwr(string: &pParamName[4]);
  v5 = KeyValues::GetDataType(this: pKeyValues, keyName: nullptr) - 1;
  if ( v5 != 0 )
  {
    v6 = v5 - 1;
    if ( v6 != 0 )
    {
      if ( v6 != 1 )
        return 0;
      *(float *)pParamName = KeyValues::GetFloat(this: pKeyValues, keyName: nullptr, defaultValue: 0.0);
      if ( pRoot == nullptr
        || CDmElement::SetValue<float>(this: pRoot, pAttributeName: &pParamName[4], value: (const float *)pParamName) == nullptr )
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: pKeyValues, keyName: nullptr, defaultValue: 0);
      if ( pRoot == nullptr )
        return 0;
      if ( CDmElement::SetValue<int>(this: pRoot, pAttributeName: &pParamName[4], &value) == nullptr )
        return 0;
    }
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: &pParamName[4]);
    Attribute->m_nFlags |= 0x4000u;
    return 1;
  }
  String = (char *)KeyValues::GetString(this: pKeyValues, keyName: nullptr, defaultValue: defaultValue);
  v10 = String;
  if ( String == nullptr || *String == 0 )
    return SetShaderParamAttribute(pElement: pRoot, pAttributeName: &pParamName[4], value: String);
  if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName: &pParamName[4], pScan: String) != 0 )
    return 1;
  if ( IsVector(v: v10) )
    return CImportVMT::CreateVectorMaterialVarFromKeyValue(
             this,
             pElement: pRoot,
             pParamName: &pParamName[4],
             pString: v10);
  else
    return SetShaderParamAttribute(pElement: pRoot, pAttributeName: &pParamName[4], value: v10);
}

//------------------------------------------------------------------------------
// Address: 0x004680A0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeProxies(CImportVMT *this, float pElement, KeyValues *pKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v5; // esi
  KeyValues *v7; // ebp
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v14; // edi
  __int32 v15; // eax
  __int32 v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *defaultValue; // [esp+0h] [ebp-20h]
  const char *defaultValuea; // [esp+0h] [ebp-20h]
  CDmrElementArray<CDmElement> array; // [esp+14h] [ebp-Ch] BYREF
  CDmAttribute *v24; // [esp+1Ch] [ebp-4h]

  v3 = (CDmElement *)LODWORD(pElement);
  array.m_pStorage = (DmElementArray_t *)this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)LODWORD(pElement), pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v5 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
  else
    v5 = CDmElement::CreateAttribute(this: v3, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v5 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
  if ( (v5->m_nFlags & 0x1F) == 0xF )
  {
    v24 = v5;
    array.m_pAttribute = (CDmAttribute *)v5->m_pData;
  }
  else
  {
    v24 = nullptr;
    array.m_pAttribute = nullptr;
  }
  v7 = pKeyValues;
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  if ( FirstTrueSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstTrueSubKey);
    DmElement = CImportKeyValueBase::CreateDmElement(
                  this: (CImportKeyValueBase *)array.m_pStorage,
                  pElementType: "DmElement",
                  pElementName: Name,
                  pId: nullptr);
    v11 = DmElement;
    pElement = DmElement != nullptr ? COERCE_FLOAT(CDmElement::GetHandle(this: DmElement)) : NAN;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&array.m_pAttribute,
      src: (const DmElementHandle_t *)&pElement);
    v12 = KeyValues::GetName(this: v7);
    CDmElement::SetValue<char const>(this: v11, pAttributeName: "proxyType", pValue: v12);
    CDmElement::SetValue<char const>(this: v11, pAttributeName: "editorType", pValue: "vmtProxy");
    FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
    v14 = FirstValue;
    if ( FirstValue != nullptr )
      break;
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
    if ( FirstTrueSubKey == nullptr )
      return 1;
  }
  v15 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
  if ( v15 == 0 )
  {
    defaultValuea = KeyValues::GetString(this: v14, keyName: nullptr, defaultValue: ::defaultValue);
    v20 = KeyValues::GetName(this: v14);
    CDmElement::SetValue<char const>(this: v11, pAttributeName: v20, pValue: defaultValuea);
    return 1;
  }
  v16 = v15 - 1;
  if ( v16 != 0 )
  {
    if ( v16 == 1 )
    {
      pElement = KeyValues::GetFloat(this: v14, keyName: nullptr, defaultValue: 0.0);
      v18 = KeyValues::GetName(this: v14);
      CDmElement::SetValue<float>(this: v11, pAttributeName: v18, value: &pElement);
      return 1;
    }
    else
    {
      defaultValue = KeyValues::GetName(this: v14);
      v17 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v17, defaultValue);
      return 0;
    }
  }
  else
  {
    pKeyValues = (KeyValues *)KeyValues::GetInt(this: v14, keyName: nullptr, defaultValue: 0);
    v19 = KeyValues::GetName(this: v14);
    CDmElement::SetValue<int>(this: v11, pAttributeName: v19, value: (int *)&pKeyValues);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468290
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(
        CImportVMT *this,
        DmElementHandle_t pElement,
        KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v8; // esi
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v11; // edi
  KeyValues *FirstValue; // esi
  const char *v13; // eax
  CDmrElementArray<CDmElement> array; // [esp+4h] [ebp-Ch] BYREF
  CDmAttribute *v15; // [esp+Ch] [ebp-4h]

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) == 15 ? Attribute : nullptr;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<VMatrix,CDmaDataExternal<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > > *)&array.m_pAttribute);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    v15 = v6;
    array.m_pAttribute = (CDmAttribute *)v6->m_pData;
  }
  else
  {
    v15 = nullptr;
    array.m_pAttribute = nullptr;
  }
  v8 = pFallbackKeyValues;
  Name = KeyValues::GetName(this: pFallbackKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
  v11 = DmElement;
  if ( DmElement != nullptr )
    pElement = CDmElement::GetHandle(this: DmElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
    this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&array.m_pAttribute,
    src: &pElement);
  CDmElement::SetValue<char const>(this: v11, pAttributeName: "editorType", pValue: "vmtFallback");
  FirstValue = KeyValues::GetFirstValue(this: v8);
  if ( FirstValue == nullptr )
    return 1;
  while ( CImportVMT::UnserializeShaderParam(this, pRoot: v11, pKeyValues: FirstValue) != 0 )
  {
    FirstValue = KeyValues::GetNextValue(this: FirstValue);
    if ( FirstValue == nullptr )
      return 1;
  }
  v13 = KeyValues::GetName(this: FirstValue);
  _Warning(a1: "Error importing vmt shader parameter %s\n", v13);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004683C0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // eax
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v13; // eax
  const char *v14; // eax

  CImportVMT::ExpandPatchFile(this, String: (char *)this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  v4 = DmElement;
  if ( DmElement == nullptr )
    return nullptr;
  CDmElement::SetValue<char const>(this: DmElement, pAttributeName: "editorType", pValue: "vmt");
  Attribute = CDmElement::FindAttribute(this: v4, pAttributeName: "proxies");
  v7 = Attribute != nullptr
     ? ((Attribute->m_nFlags & 0x1F) == 15
      ? Attribute
      : nullptr)
     : CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: v4, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) == 15
      ? v8
      : nullptr)
     : CDmElement::CreateAttribute(this: v4, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  CDmElement::SetValue<char const>(this: v4, pAttributeName: "shader", pValue: Name);
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v4, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_14;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
    return nullptr;
  }
  else
  {
LABEL_14:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v13 = KeyValues::GetName(this: i);
      if ( _stricmp(a1: (unsigned int)this, a2: (unsigned int)i, dst: v13, src: "Proxies") == 0 )
        CImportVMT::UnserializeProxies(this, pElement: *(float *)&v4, pKeyValues: i);
      else
        CImportVMT::UnserializeFallbacks(this, pElement: (DmElementHandle_t)v4, pFallbackKeyValues: i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: v4);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468520
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  DmAttributeType_t v3; // edi
  const char *v4; // edi
  int m_Storage; // ecx
  bool result; // al
  const char *v7; // edi
  double v8; // st7
  const char *v9; // edi
  CDmaVar<CUtlString> *v10; // eax
  const char *v11; // eax
  CDmaVar<Vector2D> *v12; // edi
  const char *v13; // eax
  CDmaVar<Vector> *v14; // edi
  const char *v15; // eax
  CDmaVar<Vector4D> *v16; // edi
  const char *v17; // eax
  CDmaVar<Color> *v18; // eax
  const char *v19; // eax
  float *v20; // edi
  const char *v21; // eax
  const char *v22; // esi
  const char *v23; // eax
  int v24; // [esp+78h] [ebp-14h]
  int v25; // [esp+7Ch] [ebp-10h]
  int v26; // [esp+80h] [ebp-Ch]

  v3 = pAttribute->m_nFlags & 0x1F;
  switch ( v3 )
  {
    case AT_INT:
      v4 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      m_Storage = CDmAttribute::GetValue<int>(this: pAttribute)->m_Storage;
      goto LABEL_3;
    case AT_FLOAT:
      v7 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      v8 = CDmAttribute::GetValue<float>(this: pAttribute)->m_Storage;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v7, v8);
      result = true;
      break;
    case AT_BOOL:
      v4 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      m_Storage = CDmAttribute::GetValue<bool>(this: pAttribute)->m_Storage;
LABEL_3:
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v4, m_Storage);
      result = true;
      break;
    case AT_STRING:
      v9 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      v10 = CDmAttribute::GetValue<CUtlString>(this: pAttribute);
      v11 = CUtlString::operator char const *(this: &v10->m_Storage);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v9, v11);
      result = true;
      break;
    case AT_COLOR:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v26 = v18->m_Storage._color[2];
      v25 = v18->m_Storage._color[1];
      v24 = v18->m_Storage._color[0];
      v19 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"{ %d %d %d }\"\n", v19, v24, v25, v26);
      result = true;
      break;
    case AT_VECTOR2:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case AT_VECTOR3:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case AT_VECTOR4:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case AT_VMATRIX:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = g_pDataModel->GetString(this: g_pDataModel, a2: pAttribute->m_Name.m_Id);
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: v3);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00468870
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, KeyValues *pRoot)
{
  KeyValues *FirstSubKey; // esi
  const char *v5; // edi
  const char *v6; // eax

  FirstSubKey = KeyValues::GetFirstSubKey(this: pRoot);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    if ( (FirstSubKey->m_iValue & 0x2000) == 0 )
    {
      v5 = g_pDataModel->GetString(this: g_pDataModel, a2: LOWORD(FirstSubKey->m_pPeer));
      v6 = g_pDataModel->GetString(this: g_pDataModel, a2: LOWORD(FirstSubKey->m_pPeer));
      if ( _stricmp(a1: (unsigned int)this, a2: (unsigned int)v5, dst: v6, src: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (FirstSubKey->m_Color[0] & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: (CDmAttribute *)FirstSubKey) )
      {
        break;
      }
    }
    FirstSubKey = (KeyValues *)FirstSubKey->m_iKeyName;
    if ( FirstSubKey == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00468920
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  int v6; // ebp
  CDmElement *v7; // edi
  CDmrElementArray<CDmElement> array; // [esp+4h] [ebp-Ch] BYREF
  int nCount; // [esp+18h] [ebp+8h]

  if ( !CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
    return 1;
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
  if ( (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
    this: (CDmrElementArrayConst<CDmElement> *)&array.m_pAttribute,
    pAttribute: Attribute);
  v6 = 0;
  nCount = array.m_pAttribute->m_nFlags;
  if ( nCount <= 0 )
    return 1;
  while ( 1 )
  {
    v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&array.m_pAttribute->m_pNext->m_pNext + v6));
    if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType.m_Id) )
      v7 = nullptr;
    CImportKeyValueBase::PrintStringAttribute(
      this,
      pElement: v7,
      outBuf: buf,
      pKeyName: "shader",
      bSkipEmptryStrings: false,
      bPrintValueOnly: true);
    CUtlBuffer::Printf(this: buf, pFmt: "{\n");
    ++buf->m_nTab;
    if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot: (KeyValues *)v7) == 0 )
      break;
    if ( --buf->m_nTab < 0 )
      buf->m_nTab = 0;
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    if ( ++v6 >= nCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00468A40
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // eax
  int m_nFlags; // edi
  int v7; // ebp
  CDmElement *v8; // edi
  bool v9; // sf
  CDmrElementArray<CDmElement> array; // [esp+4h] [ebp-Ch] BYREF
  int nCount; // [esp+18h] [ebp+8h]

  if ( !CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
    return 1;
  Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
  if ( (Attribute->m_nFlags & 0x1F) != 0xF )
    return 0;
  CDmrElementArray<CDmElement>::CDmrElementArray<CDmElement>(
    this: (CDmrElementArrayConst<CDmElement> *)&array.m_pAttribute,
    pAttribute: Attribute);
  m_nFlags = array.m_pAttribute->m_nFlags;
  nCount = m_nFlags;
  if ( m_nFlags == 0 )
    return 1;
  CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  v7 = 0;
  if ( m_nFlags <= 0 )
  {
LABEL_15:
    v9 = --buf->m_nTab < 0;
    if ( v9 )
      buf->m_nTab = 0;
    CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&array.m_pAttribute->m_pNext->m_pNext + v7));
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmElement::m_classType.m_Id) )
        v8 = nullptr;
      CImportKeyValueBase::PrintStringAttribute(
        this,
        pElement: v8,
        outBuf: buf,
        pKeyName: "proxyType",
        bSkipEmptryStrings: false,
        bPrintValueOnly: true);
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot: (KeyValues *)v8) == 0 )
        return 0;
      v9 = --buf->m_nTab < 0;
      if ( v9 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
      if ( ++v7 >= nCount )
        goto LABEL_15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468BA0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, (KeyValues *)pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0045CB90
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x0045CBB0
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x0045CBE0
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0045CCF0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CE50
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: &defaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CF70
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D060
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D0D0
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D140
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D1B0
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D220
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D290
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x0045D2B0
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D360
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x0045D530
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &defaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D680
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  float *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  const Color *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = &defaultValue;
      v9 = (float *)CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, *v9);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = &defaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = &defaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = &defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->_color[0],
        v18->_color[1],
        v18->_color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = &defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = &defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = &defaultValue;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045DA40
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = &defaultValue;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &defaultValue;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045DAD0
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DBF0
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DD50
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045DDE0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        DmElementHandle_t pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = CImportKeyValueBase::CreateDmElement(
                    this: v32,
                    pElementType: "DmElement",
                    pElementName: Name,
                    pId: nullptr);
      v11 = DmElement;
      if ( DmElement != nullptr )
        pElement = CDmElement::GetHandle(this: DmElement);
      else
        pElement = DMELEMENT_HANDLE_INVALID;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: &pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: (int *)&pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: &::defaultValue);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E0A0
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(
        CImportVMT *this,
        DmElementHandle_t pElement,
        KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CDmElement *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: Name, pId: nullptr);
    v10 = DmElement;
    if ( DmElement != nullptr )
      pElement = CDmElement::GetHandle(this: DmElement);
    else
      pElement = DMELEMENT_HANDLE_INVALID;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: &pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045E1F0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (DmElementHandle_t)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(
          this,
          a2: (const char *)this,
          pElement: (DmElementHandle_t)DmElement,
          pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00461B00
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x00461B20
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00461B50
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00461C60
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &pParentName);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461DC0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: &pParentName);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461EE0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00461F60
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00461FD0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462040
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004620B0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462120
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462190
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462200
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00462210
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00462220
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004622D0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x004624A0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &pParentName);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004625F0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *m_Id; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = &pParentName;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = &pParentName;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = &pParentName;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = &pParentName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, m_Id);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = &pParentName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = &pParentName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = &pParentName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = &pParentName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = &pParentName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = &pParentName;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004629B0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = &pParentName;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pParentName;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00462A40
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462B60
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462CC0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462D50
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: &pParentName);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463010
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00463160
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004B7C70
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x004B7C90
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x004B7CC0
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004B7DD0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case 1:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: ::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case 2:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case 3:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case 4:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B7F30
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: defaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8050
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B80D0
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8140
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B81B0
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8220
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8290
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8300
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, const int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8370
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x004B8380
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x004B83A0
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8450
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x004B8620
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8770
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  float *v9; // eax
  const char *m_Id; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = defaultValue;
      v9 = (float *)CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, *v9);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = defaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, m_Id);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = defaultValue;
      v23 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 88))(
                            a1: g_pDataModel.u,
                            a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B8B30
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = defaultValue;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8BC0
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = (CDmElement *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v8 = nullptr;
        }
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8CE0
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = (CDmElement *)v7;
          if ( v7 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v8 = nullptr;
          }
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8E40
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8ED0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (const DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: ::defaultValue);
      v25 = KeyValues::GetName(this: v16);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 200))(
        a1: g_pDataModel.u,
        a2: &v30,
        a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004B9190
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CCodecBuffer_Block::GetBufferType(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (const DmElementHandle_t *)&pElement);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
      a1: g_pDataModel.u,
      a2: &pElement,
      a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B92E0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x004626C0
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x004626E0
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00462710
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n");
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n");
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00462820
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &pch);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462980
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: &pch);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462AA0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462B20
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462B90
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462C00
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462C70
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462CE0
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00462DC0
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00462DD0
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00462DE0
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00462E90
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x00463060
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: &pch);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004631B0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  const int *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  float *v9; // eax
  const char *m_Id; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, *v4);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = &pch;
      v9 = (float *)CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, *v9);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = &pch;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = &pch;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = &pch;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, m_Id);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = &pch;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = &pch;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = &pch;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = &pch;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = &pch;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: (DmAttributeType_t)(pAttribute->m_nFlags & 0x1F));
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n");
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463570
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = &pch;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = &pch;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00463600
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463720
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463880
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463910
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // edi
  CDmAttribute *v20; // eax
  const char *v21; // edi
  CDmAttribute *v22; // eax
  const char *String; // ebx
  const char *v24; // edi
  CDmAttribute *v25; // eax
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v28; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v30; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v30 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v30,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (const DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v28);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v28);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          KeyValues::GetName(this: v16);
          KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n");
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v19 = KeyValues::GetName(this: v16);
        v20 = CDmElement::FindAttribute(this: v11, pAttributeName: v19);
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v11, pAttributeName: v19, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v21 = KeyValues::GetName(this: v16);
        v22 = CDmElement::FindAttribute(this: v11, pAttributeName: v21);
        if ( v22 != nullptr
          || (v22 = CDmElement::CreateAttribute(this: v11, pAttributeName: v21, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v22, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: &pch);
      v24 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v28, a3: String);
      v25 = CDmElement::FindAttribute(this: v11, pAttributeName: v24);
      if ( v25 != nullptr
        || (v25 = CDmElement::CreateAttribute(this: v11, pAttributeName: v24, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v25, value: &v28);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463BD0
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (const DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n");
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00463D20
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n");
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D1080
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x004D10A0
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x004D10D0
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004D11E0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  char *Name; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  KeyValues *j; // esi
  char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = (char *)KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: pDeltaStateName);
        v5 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = (char *)KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1340
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: pDeltaStateName);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1460
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pElement,
    a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D14E0
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1550
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D15C0
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1630
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D16A0
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1710
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D1780
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x004D1790
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x004D17A0
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D1850
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x004D1A20
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        *(float *)&pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: (float *)&pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: pDeltaStateName);
    v10 = String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D1B70
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = pDeltaStateName;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = pDeltaStateName;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = pDeltaStateName;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = pDeltaStateName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = pDeltaStateName;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = pDeltaStateName;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = pDeltaStateName;
      v23 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 88))(
                            a1: g_pDataModel.u,
                            a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D1F30
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = pDeltaStateName;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D1FC0
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = (CDmElement *)v7;
        if ( v7 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
               a1: v7,
               a2: CDmElement::m_classType.u) == 0 )
        {
          v8 = nullptr;
        }
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D20E0
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  int v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = (CDmElement *)v7;
          if ( v7 == 0
            || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmElement::m_classType.u) == 0 )
          {
            v8 = nullptr;
          }
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2240
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D22D0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        KeyValues *pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: pKeyValues);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
        a1: g_pDataModel.u,
        a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        *(float *)&pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: (float *)&pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: pDeltaStateName);
      v25 = KeyValues::GetName(this: v16);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
        a1: g_pDataModel.u,
        a2: &v30,
        a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D2590
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
      a1: g_pDataModel.u,
      a2: &pElement,
      a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D26E0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0046CF50
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x0046CF70
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x0046CFA0
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = (char *)(v4 + 1);
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0046D0B0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  char *Name; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  KeyValues *j; // esi
  char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = (char *)KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: Ptr);
        v5 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = (char *)KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = (char *)KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D210
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: Ptr);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D330
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D3B0
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, const float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D420
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D490
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D500
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D570
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D5E0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, const int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046D650
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x0046D660
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x0046D670
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D720
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pScan)
{
  char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x0046D8F0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, KeyValues *pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = pKeyValues;
  Name = KeyValues::GetName(this: pKeyValues);
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        *(float *)&pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(
                 pElement: pRoot,
                 pAttributeName: pParamName,
                 value: (const float *)&pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: Ptr);
    v10 = String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DA40
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  float *v9; // eax
  const char *m_Id; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  const Vector *v14; // eax
  const char *v15; // esi
  const Vector4D *v16; // eax
  const char *v17; // esi
  const Color *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = Ptr;
      v9 = (float *)CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, *v9);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = Ptr;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = Ptr;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = Ptr;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, m_Id);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = Ptr;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->_color[0],
        v18->_color[1],
        v18->_color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = Ptr;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = Ptr;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f %f ]\"\n", v15, v14->x, v14->y, v14->z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = Ptr;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n", v17, v16->x, v16->y, v16->z, v16->w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = Ptr;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = Ptr;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DE00
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CDmAttribute *Attribute; // esi
  const char *m_pAsString; // eax
  const char *v5; // edi

  Attribute = CDmElement::FirstAttribute(this: pRoot);
  if ( Attribute == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: Attribute) )
    {
      m_pAsString = Attribute->m_Name.u.m_pAsString;
      v5 = Ptr;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = Ptr;
      else
        v5 = Attribute->m_Name.u.m_pAsString;
      if ( _V_stricmp(s1: m_pAsString, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (Attribute->m_nFlags & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: Attribute) )
      {
        break;
      }
    }
    Attribute = Attribute->m_pNext;
    if ( Attribute == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046DE90
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046DFB0
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046E110
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046E1A0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        KeyValues *pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                             this: v32,
                                             pElementType: "DmElement",
                                             pElementName: Name,
                                             pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CExpressionCalculator::VariableCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (const DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: pKeyValues);
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        *(float *)&pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: (const float *)&pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: Ptr);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046E460
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CExpressionCalculator *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CExpressionCalculator *)CImportKeyValueBase::CreateDmElement(
                                           this,
                                           pElementType: "DmElement",
                                           pElementName: Name,
                                           pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CExpressionCalculator::VariableCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (const DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0046E5B0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00564800
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x00564820
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x00564850
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00564AC0
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: var);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00564BE0
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564C60
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564CD0
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564D40
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564DB0
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564E20
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564E90
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00564F00
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x00564F10
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x00564F20
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00564FD0
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x005651A0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: var);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005652F0
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  const int *v4; // eax
  bool result; // al
  const char *v6; // edi
  unsigned __int8 *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *v10; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = var;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, *v4);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = var;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = var;
      v7 = (unsigned __int8 *)CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, *v7);
      result = true;
      break;
    case 5:
      v10 = (const char *)*CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute);
      if ( v10 == (const char *)-1 )
        v10 = var;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, v10);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = var;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = var;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = var;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005656B0
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  unsigned __int8 *v3; // esi
  const char *v4; // eax
  const char *v5; // edi

  v3 = CVTFTexture::ImageData(this: (CVTFTexture *)pRoot);
  if ( v3 == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)v3) )
    {
      v4 = *((const char **)v3 + 5);
      v5 = var;
      if ( v4 == (const char *)-1 )
        v4 = var;
      else
        v5 = *((const char **)v3 + 5);
      if ( _V_stricmp(s1: v4, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (v3[16] & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: (CDmAttribute *)v3) )
      {
        break;
      }
    }
    v3 = *(unsigned __int8 **)v3;
    if ( v3 == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00565740
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00565860
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005659C0
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00565A50
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CVTFTexture *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CVTFTexture *)CImportKeyValueBase::CreateDmElement(
                                   this: v32,
                                   pElementType: "DmElement",
                                   pElementName: Name,
                                   pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CCoreDispNode::GetCenterVertIndex(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: var);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00565D10
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CVTFTexture *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CVTFTexture *)CImportKeyValueBase::CreateDmElement(
                                 this,
                                 pElementType: "DmElement",
                                 pElementName: Name,
                                 pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CCoreDispNode::GetCenterVertIndex(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00565E60
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1008F650
// Name: void InstallVMTImporter(class IDataModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallVMTImporter(IDataModel *pFactory)
{
  pFactory->AddSerializer(this: pFactory, a2: &s_ImportVMT);
}

//------------------------------------------------------------------------------
// Address: 0x1008F670
// Name: IsVector
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsVector(const char *v)
{
  char v1; // al
  char v3; // cl

  v1 = *v;
  while ( v1 == 32 || v1 == 9 )
  {
    v1 = *++v;
    if ( v1 == 10 || v1 == 0 )
      return false;
  }
  v3 = *v;
  return v3 == 91 || v3 == 123;
}

//------------------------------------------------------------------------------
// Address: 0x1008F6A0
// Name: int ParseVectorFromKeyValueString(char const __near *,char const __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseVectorFromKeyValueString(
        const char *pParamName,
        char *pScan,
        const char *pMaterialName,
        float *vecVal)
{
  const char *v4; // esi
  float *v5; // ebx
  const char *v6; // esi
  int v7; // edi
  char v8; // al
  bool divideBy255; // [esp+Fh] [ebp-1h]

  v4 = pScan;
  divideBy255 = false;
  while ( *v4 == 32 || *v4 == 9 )
    ++v4;
  if ( *v4 == 123 )
    divideBy255 = true;
  v5 = vecVal;
  v6 = v4 + 1;
  v7 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *v6;
      if ( *v6 != 32 && v8 != 9 )
        break;
      ++v6;
    }
    if ( v8 == 10 || v8 == 0 )
      break;
    if ( v8 == 93 )
      goto LABEL_22;
    if ( v8 == 125 )
      break;
    v5[v7] = strtod(nptr: v6, endptr: &pScan);
    if ( v6 == pScan )
    {
      _Warning(a1: "Error in .VMT file: error parsing vector element \"%s\" in \"%s\"\n", pParamName, pMaterialName);
      return 0;
    }
    ++v7;
    v6 = pScan;
    if ( v7 >= 4 )
      goto LABEL_23;
  }
  if ( *v6 != 93 && *v6 != 125 )
    _Warning(
      a1: "Warning in .VMT file (%s): no ']' or '}' found in vector key \"%s\".\n"
      "Did you forget to surround the vector with \"s?\n",
      pMaterialName,
      pParamName);
LABEL_22:
  v5[v7] = 0.0;
LABEL_23:
  if ( divideBy255 )
  {
    *v5 = *v5 * 0.0039215689;
    v5[1] = v5[1] * 0.0039215689;
    v5[2] = v5[2] * 0.0039215689;
    v5[3] = v5[3] * 0.0039215689;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1008F7B0
// Name: void InsertKeyValues(class KeyValues __near &,class KeyValues __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InsertKeyValues(KeyValues *dst, KeyValues *src, bool bCheckForExistence)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  KeyValues *j; // esi
  const char *v10; // eax
  KeyValues *Key; // eax
  KeyValues *v12; // edi
  const char *defaultValue; // [esp+0h] [ebp-10h]
  int defaultValuea; // [esp+0h] [ebp-10h]
  float defaultValueb; // [esp+0h] [ebp-10h]
  void *defaultValuec; // [esp+0h] [ebp-10h]

  for ( i = KeyValues::GetFirstSubKey(this: src); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( bCheckForExistence )
    {
      Name = KeyValues::GetName(this: i);
      if ( KeyValues::FindKey(this: dst, keyName: Name, bCreate: false) == nullptr )
        continue;
    }
    switch ( KeyValues::GetDataType(this: i, keyName: nullptr) )
    {
      case TYPE_STRING:
        defaultValue = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: ::defaultValue);
        v5 = KeyValues::GetName(this: i);
        KeyValues::SetString(this: dst, keyName: v5, value: defaultValue);
        break;
      case TYPE_INT:
        defaultValuea = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        v6 = KeyValues::GetName(this: i);
        KeyValues::SetInt(this: dst, keyName: v6, value: defaultValuea);
        break;
      case TYPE_FLOAT:
        defaultValueb = KeyValues::GetFloat(this: i, keyName: nullptr, defaultValue: 0.0);
        v7 = KeyValues::GetName(this: i);
        KeyValues::SetFloat(this: dst, keyName: v7, value: defaultValueb);
        break;
      case TYPE_PTR:
        defaultValuec = KeyValues::GetPtr(this: i, keyName: nullptr, defaultValue: nullptr);
        v8 = KeyValues::GetName(this: i);
        KeyValues::SetPtr(this: dst, keyName: v8, value: defaultValuec);
        break;
      default:
        continue;
    }
  }
  if ( bCheckForExistence )
  {
    for ( j = KeyValues::GetFirstTrueSubKey(this: dst); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
    {
      v10 = KeyValues::GetName(this: j);
      Key = KeyValues::FindKey(this: src, keyName: v10, bCreate: false);
      v12 = Key;
      if ( Key != nullptr && KeyValues::GetDataType(this: Key, keyName: nullptr) == TYPE_NONE )
        InsertKeyValues(dst: j, src: v12, bCheckForExistence);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008F910
// Name: private: void CImportVMT::ExpandPatchFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImportVMT::ExpandPatchFile(CImportVMT *this, KeyValues *pKeyValues)
{
  const char *Name; // eax
  const char *String; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // eax
  int count; // [esp+Ch] [ebp-4h]

  count = 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: pKeyValues);
    if ( _V_stricmp(s1: Name, s2: "patch") != 0 )
      break;
    String = KeyValues::GetString(this: pKeyValues, keyName: "include", defaultValue: defaultValue);
    if ( String == nullptr )
      break;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "vmt");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v5,
            filesystem: v6,
            resourceName: String,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
    {
      KeyValues::deleteThis(this: v5);
      return;
    }
    Key = KeyValues::FindKey(this: pKeyValues, keyName: "insert", bCreate: false);
    if ( Key != nullptr )
      InsertKeyValues(dst: v5, src: Key, bCheckForExistence: false);
    v8 = KeyValues::FindKey(this: pKeyValues, keyName: "replace", bCreate: false);
    if ( v8 != nullptr )
      InsertKeyValues(dst: v5, src: v8, bCheckForExistence: true);
    KeyValues::operator=(this: pKeyValues, src: v5);
    KeyValues::deleteThis(this: v5);
    if ( ++count >= 10 )
    {
      _Warning(a1: "Infinite recursion in patch file?\n");
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008FA30
// Name: bool SetShaderParamAttribute(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute(CDmElement *pElement, const char *pAttributeName, const char *value)
{
  CDmElement *v3; // edi
  const char *v5; // ebx
  CDmAttribute *Attribute; // esi
  CDmAttribute *v7; // eax

  v3 = pElement;
  if ( pElement == nullptr )
    return 0;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: value);
  v5 = pAttributeName;
  Attribute = CDmElement::FindAttribute(this: v3, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: v3, pAttributeName: v5, type: AT_STRING);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pElement);
  v7 = CDmElement::FindAttribute(this: v3, pAttributeName: v5);
  v7->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FAB0
// Name: bool SetShaderParamAttribute<float>(class CDmElement __near *,char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<float>(CDmElement *pElement, const char *pAttributeName, float *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_FLOAT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<float>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FB20
// Name: bool SetShaderParamAttribute<class Vector2D>(class CDmElement __near *,char const __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector2D>(CDmElement *pElement, const char *pAttributeName, const Vector2D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR2);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector2D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FB90
// Name: bool SetShaderParamAttribute<class Vector>(class CDmElement __near *,char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector>(CDmElement *pElement, const char *pAttributeName, const Vector *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR3);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FC00
// Name: bool SetShaderParamAttribute<class Vector4D>(class CDmElement __near *,char const __near *,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<Vector4D>(CDmElement *pElement, const char *pAttributeName, const Vector4D *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VECTOR4);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<Vector4D>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FC70
// Name: bool SetShaderParamAttribute<class VMatrix>(class CDmElement __near *,char const __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<VMatrix>(CDmElement *pElement, const char *pAttributeName, const VMatrix *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_VMATRIX);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<VMatrix>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FCE0
// Name: bool SetShaderParamAttribute<int>(class CDmElement __near *,char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetShaderParamAttribute<int>(CDmElement *pElement, const char *pAttributeName, int *value)
{
  CDmAttribute *Attribute; // esi
  CDmAttribute *v5; // eax

  if ( pElement == nullptr )
    return 0;
  Attribute = CDmElement::FindAttribute(this: pElement, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this: pElement, pAttributeName, type: AT_INT);
    if ( Attribute == nullptr )
      return 0;
  }
  CDmAttribute::SetValue<int>(this: Attribute, value);
  v5 = CDmElement::FindAttribute(this: pElement, pAttributeName);
  v5->m_nFlags |= 0x2000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008FD50
// Name: public: virtual char const __near * CImportVMT::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetDescription(CImportVMT *this)
{
  return "Valve Material File";
}

//------------------------------------------------------------------------------
// Address: 0x1008FD60
// Name: public: virtual char const __near * CImportVMT::GetImportedFormat(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CImportVMT::GetImportedFormat(CImportVMT *this)
{
  return "vmt";
}

//------------------------------------------------------------------------------
// Address: 0x1008FD70
// Name: private: bool CImportVMT::CreateVectorMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateVectorMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        char *pString)
{
  int v4; // eax
  char result; // al
  Vector4D vecVal; // [esp+4h] [ebp-10h] BYREF

  v4 = ParseVectorFromKeyValueString(pParamName, pScan: pString, pMaterialName: this->m_pFileName, vecVal: &vecVal.x);
  if ( v4 == 0 )
    return 0;
  switch ( v4 )
  {
    case 1:
      result = SetShaderParamAttribute<float>(pElement, pAttributeName: pParamName, value: &vecVal.x);
      break;
    case 2:
      result = SetShaderParamAttribute<Vector2D>(pElement, pAttributeName: pParamName, value: (const Vector2D *)&vecVal);
      break;
    case 3:
      result = SetShaderParamAttribute<Vector>(pElement, pAttributeName: pParamName, value: (const Vector *)&vecVal);
      break;
    case 4:
      result = SetShaderParamAttribute<Vector4D>(pElement, pAttributeName: pParamName, value: &vecVal);
      break;
    default:
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008FE20
// Name: private: bool CImportVMT::CreateMatrixMaterialVarFromKeyValue(class CDmElement __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::CreateMatrixMaterialVarFromKeyValue(
        CImportVMT *this,
        CDmElement *pElement,
        const char *pParamName,
        const char *pScan)
{
  const char *v4; // esi
  VMatrix temp; // [esp+10h] [ebp-98h] BYREF
  VMatrix mat; // [esp+50h] [ebp-58h] BYREF
  Vector2D scale; // [esp+90h] [ebp-18h] BYREF
  Vector2D translation; // [esp+98h] [ebp-10h] BYREF
  Vector2D center; // [esp+A0h] [ebp-8h] BYREF

  v4 = pScan;
  if ( sscanf(
         string: pScan,
         format: " [ %f %f %f %f  %f %f %f %f  %f %f %f %f  %f %f %f %f ]",
         &mat,
         &mat.m[0][1],
         &mat.m[0][2],
         &mat.m[0][3],
         mat.m[1],
         &mat.m[1][1],
         &mat.m[1][2],
         &mat.m[1][3],
         mat.m[2],
         &mat.m[2][1],
         &mat.m[2][2],
         &mat.m[2][3],
         mat.m[3],
         &mat.m[3][1],
         &mat.m[3][2],
         &mat.m[3][3]) == 16 )
    return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
  if ( sscanf(
         string: v4,
         format: " center %f %f scale %f %f rotate %f translate %f %f",
         &center,
         &center.y,
         &scale,
         &scale.y,
         &pScan,
         &translation,
         &translation.y) != 7 )
    return 0;
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(center.x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(center.y) ^ _mask__NegFloat_),
    z: 0.0);
  MatrixBuildScale(dst: &temp, x: scale.x, y: scale.y, z: 1.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildRotateZ(dst: &temp, angleDegrees: *(float *)&pScan);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  MatrixBuildTranslation(dst: &temp, x: translation.x + center.x, y: translation.y + center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  return SetShaderParamAttribute<VMatrix>(pElement, pAttributeName: pParamName, value: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x1008FFF0
// Name: private: bool CImportVMT::UnserializeShaderParam(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeShaderParam(CImportVMT *this, CDmElement *pRoot, float pKeyValues)
{
  KeyValues *v3; // esi
  const char *Name; // eax
  __int32 v6; // eax
  __int32 v7; // eax
  const char *String; // eax
  char *v10; // esi
  char pParamName[512]; // [esp+Ch] [ebp-204h] BYREF
  int value; // [esp+20Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)LODWORD(pKeyValues);
  Name = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
  V_strncpy(pDest: pParamName, pSrc: Name, maxLen: 512);
  _V_strlower(start: pParamName);
  v6 = KeyValues::GetDataType(this: v3, keyName: nullptr) - 1;
  if ( v6 != 0 )
  {
    v7 = v6 - 1;
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        pKeyValues = KeyValues::GetFloat(this: v3, keyName: nullptr, defaultValue: 0.0);
        return SetShaderParamAttribute<float>(pElement: pRoot, pAttributeName: pParamName, value: &pKeyValues);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      value = KeyValues::GetInt(this: v3, keyName: nullptr, defaultValue: 0);
      return SetShaderParamAttribute<int>(pElement: pRoot, pAttributeName: pParamName, &value);
    }
  }
  else
  {
    String = KeyValues::GetString(this: v3, keyName: nullptr, defaultValue: defaultValue);
    v10 = (char *)String;
    if ( String != nullptr && *String != 0 )
    {
      if ( CImportVMT::CreateMatrixMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pScan: String) != 0 )
      {
        return 1;
      }
      else if ( IsVector(v: v10) )
      {
        return CImportVMT::CreateVectorMaterialVarFromKeyValue(this, pElement: pRoot, pParamName, pString: v10);
      }
      else
      {
        return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: v10);
      }
    }
    else
    {
      return SetShaderParamAttribute(pElement: pRoot, pAttributeName: pParamName, value: String);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090140
// Name: private: bool CImportVMT::SerializeShaderParameter(class CUtlBuffer __near &,class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CImportVMT::SerializeShaderParameter(CImportVMT *this, CUtlBuffer *buf, CDmAttribute *pAttribute)
{
  const char *m_pAsString; // edi
  CDmaVar<int> *v4; // eax
  bool result; // al
  const char *v6; // edi
  CDmaVar<bool> *v7; // eax
  const char *v8; // edi
  CDmaVar<float> *v9; // eax
  const char *m_Id; // eax
  const char *v11; // esi
  CDmaVar<Vector2D> *v12; // eax
  const char *v13; // esi
  CDmaVar<Vector> *v14; // eax
  const char *v15; // esi
  CDmaVar<Vector4D> *v16; // eax
  const char *v17; // esi
  CDmaVar<Color> *v18; // eax
  const char *v19; // esi
  float *v20; // eax
  const char *v21; // esi
  const char *v22; // esi
  const char *v23; // eax

  switch ( pAttribute->m_nFlags & 0x1F )
  {
    case 2:
      m_pAsString = pAttribute->m_Name.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = defaultValue;
      v4 = CDmAttribute::GetValue<int>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", m_pAsString, v4->m_Storage);
      result = true;
      break;
    case 3:
      v8 = pAttribute->m_Name.u.m_pAsString;
      if ( v8 == (const char *)-1 )
        v8 = defaultValue;
      v9 = CDmAttribute::GetValue<float>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%f\"\n", v8, v9->m_Storage);
      result = true;
      break;
    case 4:
      v6 = pAttribute->m_Name.u.m_pAsString;
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      v7 = CDmAttribute::GetValue<bool>(this: pAttribute);
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%d\"\n", v6, v7->m_Storage);
      result = true;
      break;
    case 5:
      m_Id = (const char *)CDmAttribute::GetValue<CUtlSymbolLarge>(this: pAttribute)->m_Storage.u.m_Id;
      if ( m_Id == (const char *)-1 )
        m_Id = defaultValue;
      v11 = pAttribute->m_Name.u.m_pAsString;
      if ( v11 == (const char *)-1 )
        v11 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"%s\"\n", v11, m_Id);
      result = true;
      break;
    case 8:
      v18 = CDmAttribute::GetValue<Color>(this: pAttribute);
      v19 = pAttribute->m_Name.u.m_pAsString;
      if ( v19 == (const char *)-1 )
        v19 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"{ %d %d %d }\"\n",
        v19,
        v18->m_Storage._color[0],
        v18->m_Storage._color[1],
        v18->m_Storage._color[2]);
      result = true;
      break;
    case 9:
      v12 = CDmAttribute::GetValue<Vector2D>(this: pAttribute);
      v13 = pAttribute->m_Name.u.m_pAsString;
      if ( v13 == (const char *)-1 )
        v13 = defaultValue;
      CUtlBuffer::Printf(this: buf, pFmt: "\"%s\" \"[ %f %f ]\"\n", v13, v12->m_Storage.x, v12->m_Storage.y);
      result = true;
      break;
    case 0xA:
      v14 = CDmAttribute::GetValue<Vector>(this: pAttribute);
      v15 = pAttribute->m_Name.u.m_pAsString;
      if ( v15 == (const char *)-1 )
        v15 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f ]\"\n",
        v15,
        v14->m_Storage.x,
        v14->m_Storage.y,
        v14->m_Storage.z);
      result = true;
      break;
    case 0xB:
      v16 = CDmAttribute::GetValue<Vector4D>(this: pAttribute);
      v17 = pAttribute->m_Name.u.m_pAsString;
      if ( v17 == (const char *)-1 )
        v17 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f ]\"\n",
        v17,
        v16->m_Storage.x,
        v16->m_Storage.y,
        v16->m_Storage.z,
        v16->m_Storage.w);
      result = true;
      break;
    case 0xE:
      v20 = (float *)CDmAttribute::GetValue<VMatrix>(this: pAttribute);
      v21 = pAttribute->m_Name.u.m_pAsString;
      if ( v21 == (const char *)-1 )
        v21 = defaultValue;
      CUtlBuffer::Printf(
        this: buf,
        pFmt: "\"%s\" \"[ %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ]\"\n",
        v21,
        *v20,
        v20[1],
        v20[2],
        v20[3],
        v20[4],
        v20[5],
        v20[6],
        v20[7],
        v20[8],
        v20[9],
        v20[10],
        v20[11],
        v20[12],
        v20[13],
        v20[14],
        v20[15]);
      result = true;
      break;
    default:
      v22 = pAttribute->m_Name.u.m_pAsString;
      if ( v22 == (const char *)-1 )
        v22 = defaultValue;
      v23 = g_pDataModel->GetAttributeNameForType(this: g_pDataModel, a2: pAttribute->m_nFlags & 0x1F);
      _Warning(a1: "Attempted to serialize an unsupported shader parameter type %s (%s)\n", v22, v23);
      result = false;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090500
// Name: private: bool CImportVMT::SerializeShaderParameters(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeShaderParameters(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  unsigned __int8 *v3; // esi
  const char *v4; // eax
  const char *v5; // edi

  v3 = CVTFTexture::ImageData(this: (CVTFTexture *)pRoot);
  if ( v3 == nullptr )
    return 1;
  while ( 1 )
  {
    if ( !CDmAttribute::IsStandard(this: (CDmAttribute *)v3) )
    {
      v4 = *((const char **)v3 + 5);
      v5 = defaultValue;
      if ( v4 == (const char *)-1 )
        v4 = defaultValue;
      else
        v5 = *((const char **)v3 + 5);
      if ( _V_stricmp(s1: v4, s2: "shader") != 0
        && (*v5 == 36 || *v5 == 37)
        && (v3[16] & 0x1F) != 0xF
        && !CImportVMT::SerializeShaderParameter(this, buf, pAttribute: (CDmAttribute *)v3) )
      {
        break;
      }
    }
    v3 = *(unsigned __int8 **)v3;
    if ( v3 == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10090590
// Name: private: bool CImportVMT::SerializeFallbacks(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeFallbacks(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  DmElementArray_t *m_pData; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "fallbacks", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "fallbacks");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      m_pData = (DmElementArray_t *)Attribute->m_pData;
      array.m_pStorage = m_pData;
      pRoota = (CDmElement *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
    }
    if ( (int)pRoota > 0 )
    {
      while ( 1 )
      {
        v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v3]);
        v8 = v7;
        if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
          v8 = nullptr;
        CImportKeyValueBase::PrintStringAttribute(
          this: v12,
          pElement: v8,
          outBuf: buf,
          pKeyName: "shader",
          bSkipEmptryStrings: false,
          bPrintValueOnly: true);
        CUtlBuffer::Printf(this: buf, pFmt: "{\n");
        v9 = (CImportVMT *)v12;
        ++buf->m_nTab;
        if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
          break;
        if ( --buf->m_nTab < 0 )
          buf->m_nTab = 0;
        CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        if ( ++v3 >= (int)pRoota )
          return 1;
        m_pData = array.m_pStorage;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100906B0
// Name: private: bool CImportVMT::SerializeProxies(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::SerializeProxies(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  int v3; // ebx
  CDmAttribute *Attribute; // esi
  int m_Size; // edi
  CDmElement *v7; // eax
  CDmElement *v8; // edi
  CImportVMT *v9; // ecx
  bool v10; // sf
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-Ch] BYREF
  CImportKeyValueBase *v12; // [esp+14h] [ebp-4h]
  CDmElement *pRoota; // [esp+24h] [ebp+Ch]

  v3 = 0;
  v12 = this;
  if ( CDmElement::HasAttribute(this: pRoot, pAttributeName: "proxies", type: AT_UNKNOWN) )
  {
    Attribute = CDmElement::FindAttribute(this: pRoot, pAttributeName: "proxies");
    if ( (Attribute->m_nFlags & 0x1F) != 0xF )
      return 0;
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (Attribute->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = Attribute;
      array.m_pStorage = (DmElementArray_t *)Attribute->m_pData;
      m_Size = array.m_pStorage->m_Size;
      pRoota = (CDmElement *)m_Size;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
      pRoota = nullptr;
      m_Size = 0;
    }
    if ( m_Size != 0 )
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\"Proxies\"\n");
      CUtlBuffer::Printf(this: buf, pFmt: "{\n");
      ++buf->m_nTab;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: array.m_pStorage->m_Memory.m_pMemory[v3]);
          v8 = v7;
          if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmElement::m_classType) )
            v8 = nullptr;
          CImportKeyValueBase::PrintStringAttribute(
            this: v12,
            pElement: v8,
            outBuf: buf,
            pKeyName: "proxyType",
            bSkipEmptryStrings: false,
            bPrintValueOnly: true);
          CUtlBuffer::Printf(this: buf, pFmt: "{\n");
          v9 = (CImportVMT *)v12;
          ++buf->m_nTab;
          if ( CImportVMT::SerializeShaderParameters(this: v9, buf, pRoot: v8) == 0 )
            return 0;
          v10 = --buf->m_nTab < 0;
          if ( v10 )
            buf->m_nTab = 0;
          CUtlBuffer::Printf(this: buf, pFmt: "}\n");
        }
        while ( ++v3 < (int)pRoota );
      }
      v10 = --buf->m_nTab < 0;
      if ( v10 )
        buf->m_nTab = 0;
      CUtlBuffer::Printf(this: buf, pFmt: "}\n");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090810
// Name: public: virtual bool CImportVMT::Serialize(class CUtlBuffer __near &,class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::Serialize(CImportVMT *this, CUtlBuffer *buf, CDmElement *pRoot)
{
  CImportKeyValueBase::PrintStringAttribute(
    this,
    pElement: pRoot,
    outBuf: buf,
    pKeyName: "shader",
    bSkipEmptryStrings: false,
    bPrintValueOnly: true);
  CUtlBuffer::Printf(this: buf, pFmt: "{\n");
  ++buf->m_nTab;
  if ( CImportVMT::SerializeShaderParameters(this, buf, pRoot) == 0
    || CImportVMT::SerializeFallbacks(this, buf, pRoot) == 0
    || CImportVMT::SerializeProxies(this, buf, pRoot) == 0 )
  {
    return 0;
  }
  if ( --buf->m_nTab < 0 )
    buf->m_nTab = 0;
  CUtlBuffer::Printf(this: buf, pFmt: "}\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100908A0
// Name: private: bool CImportVMT::UnserializeProxies(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CImportVMT::UnserializeProxies@<al>(
        CImportVMT *this@<ecx>,
        const char *a2@<ebx>,
        int pElement,
        float pKeyValues)
{
  CDmElement *v4; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  CVTFTexture *DmElement; // eax
  CDmElement *v11; // esi
  const char *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  KeyValues *FirstValue; // eax
  KeyValues *v16; // edi
  __int32 v17; // eax
  __int32 v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  CDmAttribute *v21; // eax
  const char *v22; // edi
  CDmAttribute *v23; // eax
  const char *String; // ebx
  const char *v25; // edi
  CDmAttribute *v26; // eax
  const char *defaultValue; // [esp+10h] [ebp-24h]
  CDmrElementArray<CDmElement> array; // [esp+20h] [ebp-14h] BYREF
  CUtlSymbolLarge v30; // [esp+28h] [ebp-Ch] BYREF
  CUtlSymbolLarge value; // [esp+2Ch] [ebp-8h] BYREF
  CImportKeyValueBase *v32; // [esp+30h] [ebp-4h]

  v4 = (CDmElement *)pElement;
  v32 = this;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "proxies");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v4, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 == nullptr )
    return 0;
  CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
  if ( (v6->m_nFlags & 0x1F) == 0xF )
  {
    array.m_pAttribute = v6;
    array.m_pStorage = (DmElementArray_t *)v6->m_pData;
  }
  else
  {
    array.m_pAttribute = nullptr;
    array.m_pStorage = nullptr;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: (KeyValues *)LODWORD(pKeyValues));
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      DmElement = (CVTFTexture *)CImportKeyValueBase::CreateDmElement(
                                   this: v32,
                                   pElementType: "DmElement",
                                   pElementName: Name,
                                   pId: nullptr);
      v11 = (CDmElement *)DmElement;
      if ( DmElement != nullptr )
        pElement = CVTFTexture::MipCount(this: DmElement);
      else
        pElement = -1;
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &array,
        src: (DmElementHandle_t *)&pElement);
      v12 = KeyValues::GetName(this: (KeyValues *)LODWORD(pKeyValues));
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *, const char *, const char *))g_pDataModel->GetSymbol)(
        a1: g_pDataModel,
        a2: &value,
        a3: v12,
        a4: a2);
      v13 = CDmElement::FindAttribute(this: v11, pAttributeName: "proxyType");
      if ( v13 != nullptr
        || (v13 = CDmElement::CreateAttribute(this: v11, pAttributeName: "proxyType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v13, &value);
      }
      a2 = "vmtProxy";
      ((void (__thiscall *)(IDataModel *, CUtlSymbolLarge *))g_pDataModel->GetSymbol)(a1: g_pDataModel, a2: &v30);
      v14 = CDmElement::FindAttribute(this: v11, pAttributeName: "editorType");
      if ( v14 != nullptr
        || (v14 = CDmElement::CreateAttribute(this: v11, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v14, value: &v30);
      }
      FirstValue = KeyValues::GetFirstValue(this: FirstTrueSubKey);
      v16 = FirstValue;
      if ( FirstValue != nullptr )
        break;
      FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      if ( FirstTrueSubKey == nullptr )
        return 1;
    }
    v17 = KeyValues::GetDataType(this: FirstValue, keyName: nullptr) - 1;
    if ( v17 != 0 )
    {
      v18 = v17 - 1;
      if ( v18 != 0 )
      {
        if ( v18 != 1 )
        {
          defaultValue = KeyValues::GetName(this: v16);
          v19 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(a1: "Unhandled proxy keyvalues type (proxy %s var %s)\n", v19, defaultValue);
          return 0;
        }
        pKeyValues = KeyValues::GetFloat(this: v16, keyName: nullptr, defaultValue: 0.0);
        v20 = KeyValues::GetName(this: v16);
        v21 = CDmElement::FindAttribute(this: v11, pAttributeName: v20);
        if ( v21 != nullptr
          || (v21 = CDmElement::CreateAttribute(this: v11, pAttributeName: v20, type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v21, value: &pKeyValues);
          return 1;
        }
      }
      else
      {
        pElement = KeyValues::GetInt(this: v16, keyName: nullptr, defaultValue: 0);
        v22 = KeyValues::GetName(this: v16);
        v23 = CDmElement::FindAttribute(this: v11, pAttributeName: v22);
        if ( v23 != nullptr
          || (v23 = CDmElement::CreateAttribute(this: v11, pAttributeName: v22, type: AT_INT)) != nullptr )
        {
          CDmAttribute::SetValue<int>(this: v23, value: &pElement);
          return 1;
        }
      }
    }
    else
    {
      String = KeyValues::GetString(this: v16, keyName: nullptr, defaultValue: ::defaultValue);
      v25 = KeyValues::GetName(this: v16);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: &v30, a3: String);
      v26 = CDmElement::FindAttribute(this: v11, pAttributeName: v25);
      if ( v26 != nullptr
        || (v26 = CDmElement::CreateAttribute(this: v11, pAttributeName: v25, type: AT_STRING)) != nullptr )
      {
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v26, value: &v30);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090B60
// Name: private: bool CImportVMT::UnserializeFallbacks(class CDmElement __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImportVMT::UnserializeFallbacks(CImportVMT *this, int pElement, KeyValues *pFallbackKeyValues)
{
  CDmElement *v3; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // esi
  KeyValues *v7; // esi
  const char *Name; // eax
  CVTFTexture *DmElement; // eax
  CDmElement *v10; // edi
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // esi
  const char *v14; // eax
  CDmrElementArray<CDmElement> array; // [esp+Ch] [ebp-8h] BYREF

  v3 = (CDmElement *)pElement;
  Attribute = CDmElement::FindAttribute(this: (CDmElement *)pElement, pAttributeName: "fallbacks");
  if ( Attribute != nullptr )
    v6 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v6 = CDmElement::CreateAttribute(this: v3, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v6 != nullptr )
  {
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&array);
    if ( (v6->m_nFlags & 0x1F) == 0xF )
    {
      array.m_pAttribute = v6;
      array.m_pStorage = (DmElementArray_t *)v6->m_pData;
    }
    else
    {
      array.m_pAttribute = nullptr;
      array.m_pStorage = nullptr;
    }
    v7 = pFallbackKeyValues;
    Name = KeyValues::GetName(this: pFallbackKeyValues);
    DmElement = (CVTFTexture *)CImportKeyValueBase::CreateDmElement(
                                 this,
                                 pElementType: "DmElement",
                                 pElementName: Name,
                                 pId: nullptr);
    v10 = (CDmElement *)DmElement;
    if ( DmElement != nullptr )
      pElement = CVTFTexture::MipCount(this: DmElement);
    else
      pElement = -1;
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
      this: &array,
      src: (DmElementHandle_t *)&pElement);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pElement, a3: "vmtFallback");
    v11 = CDmElement::FindAttribute(this: v10, pAttributeName: "editorType");
    if ( v11 != nullptr
      || (v11 = CDmElement::CreateAttribute(this: v10, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, value: (const CUtlSymbolLarge *)&pElement);
    }
    FirstValue = KeyValues::GetFirstValue(this: v7);
    if ( FirstValue == nullptr )
      return 1;
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: v10, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        return 1;
    }
    v14 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v14);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10090CB0
// Name: public: virtual class CDmElement __near * CImportVMT::UnserializeFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CImportVMT::UnserializeFromKeyValues(CImportVMT *this, KeyValues *pKeyValues)
{
  CDmElement *DmElement; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  const char *Name; // eax
  CDmAttribute *v11; // eax
  KeyValues *FirstValue; // edi
  KeyValues *i; // edi
  const char *v14; // eax
  const char *v15; // eax
  CUtlSymbolLarge value; // [esp+8h] [ebp-4h] BYREF

  CImportVMT::ExpandPatchFile(this, pKeyValues);
  DmElement = CImportKeyValueBase::CreateDmElement(this, pElementType: "DmElement", pElementName: "VMT", pId: nullptr);
  if ( DmElement == nullptr )
    return nullptr;
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: "vmt");
  Attribute = CDmElement::FindAttribute(this: DmElement, pAttributeName: "editorType");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "editorType", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, &value);
  }
  v6 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "proxies");
  v7 = v6 != nullptr
     ? ((v6->m_nFlags & 0x1F) != 15
      ? nullptr
      : v6)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "proxies", type: AT_FIRST_ARRAY_TYPE);
  if ( v7 == nullptr )
    return nullptr;
  v8 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "fallbacks");
  v9 = v8 != nullptr
     ? ((v8->m_nFlags & 0x1F) != 15
      ? nullptr
      : v8)
     : CDmElement::CreateAttribute(this: DmElement, pAttributeName: "fallbacks", type: AT_FIRST_ARRAY_TYPE);
  if ( v9 == nullptr )
    return nullptr;
  Name = KeyValues::GetName(this: pKeyValues);
  g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: Name);
  v11 = CDmElement::FindAttribute(this: DmElement, pAttributeName: "shader");
  if ( v11 != nullptr
    || (v11 = CDmElement::CreateAttribute(this: DmElement, pAttributeName: "shader", type: AT_STRING)) != nullptr )
  {
    CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11, &value);
  }
  FirstValue = KeyValues::GetFirstValue(this: pKeyValues);
  if ( FirstValue != nullptr )
  {
    while ( CImportVMT::UnserializeShaderParam(this, pRoot: DmElement, pKeyValues: *(float *)&FirstValue) != 0 )
    {
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
        goto LABEL_20;
    }
    v15 = KeyValues::GetName(this: FirstValue);
    _Warning(a1: "Error importing vmt shader parameter %s\n", v15);
    return nullptr;
  }
  else
  {
LABEL_20:
    for ( i = KeyValues::GetFirstTrueSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      v14 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v14, s2: "Proxies") != 0 )
        CImportVMT::UnserializeFallbacks(this, pElement: (int)DmElement, pFallbackKeyValues: i);
      else
        CImportVMT::UnserializeProxies(this, a2: (const char *)this, pElement: (int)DmElement, pKeyValues: *(float *)&i);
    }
    CImportKeyValueBase::RecursivelyResolveElement(this, pElement: DmElement);
    return DmElement;
  }
}

} // namespace vtex_dll
