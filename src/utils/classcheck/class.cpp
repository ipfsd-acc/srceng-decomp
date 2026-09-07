// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/classcheck/class.cpp
// Functions: 32
// ============================================================

#include "utils\classcheck\class.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: CClass::CClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClass *__thiscall CClass::CClass(CClass *this, const char *name)
{
  CClass *result; // eax

  result = this;
  this->m_nVarCount = 0;
  this->m_nMemberCount = 0;
  this->m_nTDCount = 0;
  this->m_nPredTDCount = 0;
  strcpy(this->m_szName, name);
  result->m_szBaseClass[0] = 0;
  result->m_pBaseClass = nullptr;
  result->m_szTypedefBaseClass[0] = 0;
  *(_WORD *)&result->m_bDerivedFromCBaseEntity = 0;
  result->m_bHasPredictionData = false;
  *(_WORD *)&result->m_bHasRecvTableData = 0;
  result->m_nClassDataSize = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401070
// Name: public: CClass::~CClass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClass::~CClass(CClass *this)
{
  int v2; // edi
  void **m_Variables; // ebx
  int v4; // edi
  void **m_Members; // ebx
  int v6; // edi
  void **m_TDFields; // ebx
  int v8; // edi
  void **m_PredTDFields; // ebx

  v2 = 0;
  if ( this->m_nVarCount > 0 )
  {
    m_Variables = (void **)this->m_Variables;
    do
    {
      free(pMem: *m_Variables);
      ++v2;
      ++m_Variables;
    }
    while ( v2 < this->m_nVarCount );
  }
  v4 = 0;
  this->m_nVarCount = 0;
  if ( this->m_nMemberCount > 0 )
  {
    m_Members = (void **)this->m_Members;
    do
    {
      free(pMem: *m_Members);
      ++v4;
      ++m_Members;
    }
    while ( v4 < this->m_nMemberCount );
  }
  v6 = 0;
  this->m_nMemberCount = 0;
  if ( this->m_nTDCount > 0 )
  {
    m_TDFields = (void **)this->m_TDFields;
    do
    {
      free(pMem: *m_TDFields);
      ++v6;
      ++m_TDFields;
    }
    while ( v6 < this->m_nTDCount );
  }
  v8 = 0;
  this->m_nTDCount = 0;
  if ( this->m_nPredTDCount <= 0 )
  {
    this->m_nPredTDCount = 0;
  }
  else
  {
    m_PredTDFields = (void **)this->m_PredTDFields;
    do
    {
      free(pMem: *m_PredTDFields);
      ++v8;
      ++m_PredTDFields;
    }
    while ( v8 < this->m_nPredTDCount );
    this->m_nPredTDCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401140
// Name: public: class CTypeDescriptionField __near * CClass::FindTD(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTypeDescriptionField *__thiscall CClass::FindTD(CClass *this, const char *name)
{
  int m_nTDCount; // ecx
  int v4; // esi
  CTypeDescriptionField **i; // edi
  CClass *v7; // [esp+Ch] [ebp-4h]

  m_nTDCount = this->m_nTDCount;
  v4 = 0;
  v7 = this;
  if ( m_nTDCount <= 0 )
    return nullptr;
  for ( i = this->m_TDFields; strcmp((*i)->m_szVariableName, name) != 0; ++i )
  {
    if ( ++v4 >= m_nTDCount )
      return nullptr;
  }
  return v7->m_TDFields[v4];
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: public: class CTypeDescriptionField __near * CClass::FindPredTD(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTypeDescriptionField *__thiscall CClass::FindPredTD(CClass *this, const char *name)
{
  int m_nPredTDCount; // ecx
  int v4; // esi
  CTypeDescriptionField **i; // edi
  CClass *v7; // [esp+Ch] [ebp-4h]

  m_nPredTDCount = this->m_nPredTDCount;
  v4 = 0;
  v7 = this;
  if ( m_nPredTDCount <= 0 )
    return nullptr;
  for ( i = this->m_PredTDFields; strcmp((*i)->m_szVariableName, name) != 0; ++i )
  {
    if ( ++v4 >= m_nPredTDCount )
      return nullptr;
  }
  return v7->m_PredTDFields[v4];
}

//------------------------------------------------------------------------------
// Address: 0x00401240
// Name: public: class CClassVariable __near * CClass::FindVar(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CClassVariable *__thiscall CClass::FindVar(CClass *this, const char *name, bool checkbaseclasses)
{
  CClass *v3; // esi
  int v4; // ebx
  const char **m_Variables; // edi

  v3 = this;
  if ( this == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = 0;
    if ( v3->m_nVarCount > 0 )
      break;
LABEL_6:
    if ( checkbaseclasses )
    {
      if ( v3->m_pBaseClass == nullptr )
        v3->m_pBaseClass = processor->FindClass(this: processor, a2: v3->m_szBaseClass);
      v3 = v3->m_pBaseClass;
      if ( v3 != nullptr )
        continue;
    }
    return nullptr;
  }
  m_Variables = (const char **)v3->m_Variables;
  while ( strcmp(*m_Variables, name) != 0 )
  {
    ++v4;
    ++m_Variables;
    if ( v4 >= v3->m_nVarCount )
      goto LABEL_6;
  }
  return v3->m_Variables[v4];
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: public: class CClassMemberFunction __near * CClass::FindMember(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClassMemberFunction *__thiscall CClass::FindMember(CClass *this, const char *name)
{
  int m_nMemberCount; // ecx
  int v4; // esi
  CClassMemberFunction **i; // edi
  CClass *v7; // [esp+Ch] [ebp-4h]

  m_nMemberCount = this->m_nMemberCount;
  v4 = 0;
  v7 = this;
  if ( m_nMemberCount <= 0 )
    return nullptr;
  for ( i = this->m_Members; strcmp((*i)->m_szName, name) != 0; ++i )
  {
    if ( ++v4 >= m_nMemberCount )
      return nullptr;
  }
  return v7->m_Members[v4];
}

//------------------------------------------------------------------------------
// Address: 0x00401370
// Name: public: class CTypeDescriptionField __near * CClass::AddTD(char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CTypeDescriptionField *__thiscall CClass::AddTD(
        CClass *this,
        const char *name,
        const char *type,
        const char *definetype,
        bool incomments)
{
  CTypeDescriptionField *result; // eax

  result = CClass::FindTD(this, name);
  if ( result == nullptr )
  {
    result = (CTypeDescriptionField *)operator new(nSize: 0x182u);
    if ( result != nullptr )
    {
      result->m_szVariableName[0] = 0;
      result->m_szType[0] = 0;
      result->m_szDefineType[0] = 0;
      *(_WORD *)&result->m_bCommentedOut = 0;
    }
    else
    {
      result = nullptr;
    }
    strcpy(result->m_szVariableName, name);
    strcpy(result->m_szType, type);
    strcpy(result->m_szDefineType, definetype);
    result->m_bCommentedOut = incomments;
    this->m_TDFields[this->m_nTDCount++] = result;
    if ( this->m_nTDCount >= 1024 )
    {
      vprint(depth: 0, fmt: "too many typedescription fields\n");
      exit(code: 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401440
// Name: public: class CTypeDescriptionField __near * CClass::AddPredTD(char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CTypeDescriptionField *__thiscall CClass::AddPredTD(
        CClass *this,
        const char *name,
        const char *type,
        const char *definetype,
        bool incomments,
        bool inrecvtable)
{
  CTypeDescriptionField *result; // eax

  result = CClass::FindPredTD(this, name);
  if ( result == nullptr )
  {
    result = (CTypeDescriptionField *)operator new(nSize: 0x182u);
    if ( result != nullptr )
    {
      result->m_szVariableName[0] = 0;
      result->m_szType[0] = 0;
      result->m_szDefineType[0] = 0;
      *(_WORD *)&result->m_bCommentedOut = 0;
    }
    else
    {
      result = nullptr;
    }
    strcpy(result->m_szVariableName, name);
    strcpy(result->m_szType, type);
    strcpy(result->m_szDefineType, definetype);
    result->m_bCommentedOut = incomments;
    result->m_bRepresentedInRecvTable = inrecvtable;
    this->m_PredTDFields[this->m_nPredTDCount++] = result;
    if ( this->m_nPredTDCount >= 1024 )
    {
      vprint(depth: 0, fmt: "too many prediction typedescription fields\n");
      exit(code: 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401520
// Name: public: class CClassVariable __near * CClass::AddVar(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClassVariable *__thiscall CClass::AddVar(CClass *this, const char *name)
{
  CClassVariable *result; // eax

  result = CClass::FindVar(this, name, checkbaseclasses: false);
  if ( result == nullptr )
  {
    result = (CClassVariable *)operator new(nSize: 0x194u);
    if ( result != nullptr )
    {
      result->m_szName[0] = 0;
      result->m_szType[0] = 0;
      result->m_Type = TPUBLIC;
      result->m_bKnownType = false;
      result->m_nTypeSize = 0;
      *(_WORD *)&result->m_bIsArray = 0;
      result->m_bInRecvTable = false;
      result->m_TypeSize = 0;
    }
    else
    {
      result = nullptr;
    }
    strcpy(result->m_szName, name);
    this->m_Variables[this->m_nVarCount++] = result;
    if ( this->m_nVarCount >= 1024 )
    {
      vprint(depth: 0, fmt: "too many variables\n");
      exit(code: 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004015D0
// Name: public: class CClassMemberFunction __near * CClass::AddMember(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClassMemberFunction *__thiscall CClass::AddMember(CClass *this, const char *name)
{
  CClassMemberFunction *result; // eax
  unsigned __int8 *v4; // eax
  CClassMemberFunction *v5; // esi

  result = CClass::FindMember(this, name);
  if ( result == nullptr )
  {
    v4 = (unsigned __int8 *)operator new(nSize: 0x104u);
    v5 = (CClassMemberFunction *)v4;
    if ( v4 != nullptr )
    {
      memset(dst: v4, value: 0, count: 0x104u);
      result = v5;
    }
    else
    {
      result = nullptr;
    }
    strcpy(result->m_szName, name);
    this->m_Members[this->m_nMemberCount++] = result;
    if ( this->m_nMemberCount >= 1024 )
    {
      vprint(depth: 0, fmt: "too many members\n");
      exit(code: 1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401660
// Name: public: void CClass::SetBaseClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClass::SetBaseClass(CClass *this, const char *name)
{
  char *m_szBaseClass; // esi

  m_szBaseClass = this->m_szBaseClass;
  if ( this->m_szBaseClass[0] != 0 )
  {
    if ( _stricmp(dst: this->m_szBaseClass, src: name) != 0 )
      vprint(depth: 0, fmt: "Base class differs for %s %s vs %s\n", this->m_szName, m_szBaseClass, name);
  }
  else
  {
    strcpy(m_szBaseClass, name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004016C0
// Name: public: void CClass::CheckChildOfBaseEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClass::CheckChildOfBaseEntity(CClass *this, const char *baseentityclass)
{
  CClass *m_pBaseClass; // esi

  this->m_bDerivedFromCBaseEntity = false;
  if ( _stricmp(dst: this->m_szName, src: baseentityclass) == 0 )
  {
    this->m_bDerivedFromCBaseEntity = true;
  }
  else
  {
    m_pBaseClass = this->m_pBaseClass;
    if ( m_pBaseClass != nullptr )
    {
      while ( !m_pBaseClass->m_bDerivedFromCBaseEntity
           && _stricmp(dst: m_pBaseClass->m_szName, src: baseentityclass) != 0 )
      {
        m_pBaseClass = m_pBaseClass->m_pBaseClass;
        if ( m_pBaseClass == nullptr )
          return;
      }
      this->m_bDerivedFromCBaseEntity = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401730
// Name: IsType
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsType@<al>(char *input@<edi>, char *test@<eax>)
{
  char *v3; // eax
  char v5; // cl

  strstr(str1: (unsigned __int8 *)input, str2: (unsigned __int8 *)test);
  return v3 != nullptr && ((v5 = v3[strlen(test)]) == 0 || v5 == 32) && (input == v3 || *(v3 - 1) == 32);
}

//------------------------------------------------------------------------------
// Address: 0x00401780
// Name: TranslateSimpleType
// Source: json
//------------------------------------------------------------------------------
const char *__usercall TranslateSimpleType@<eax>(CClassVariable *var@<eax>)
{
  unsigned __int8 *m_szType; // edi
  int v2; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 v5; // cl
  unsigned __int8 *v6; // eax
  unsigned __int8 v7; // cl

  m_szType = (unsigned __int8 *)var->m_szType;
  out[0] = 0;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "<");
  if ( v2 != 0 )
    return out;
  strstr(str1: m_szType, str2: "bool");
  if ( v4 != nullptr )
  {
    v5 = v4[4];
    if ( (v5 == 0 || v5 == 32) && (m_szType == v4 || *(v4 - 1) == 32) )
      return "FIELD_BOOLEAN";
  }
  strstr(str1: m_szType, str2: "short");
  if ( v6 != nullptr )
  {
    v7 = v6[5];
    if ( (v7 == 0 || v7 == 32) && (m_szType == v6 || *(v6 - 1) == 32) )
      return "FIELD_SHORT";
  }
  if ( IsType(input: (char *)m_szType, test: "int") )
    return "FIELD_INTEGER";
  if ( IsType(input: (char *)m_szType, test: "byte") )
    return "FIELD_CHARACTER";
  if ( IsType(input: (char *)m_szType, test: "float") )
    return "FIELD_FLOAT";
  if ( IsType(input: (char *)m_szType, test: "EHANDLE") || IsType(input: (char *)m_szType, test: "CHandle") )
    return "FIELD_EHANDLE";
  if ( IsType(input: (char *)m_szType, test: "color32") )
    return "FIELD_COLOR32";
  if ( !IsType(input: (char *)m_szType, test: "Vector") && !IsType(input: (char *)m_szType, test: "QAngle") )
  {
    if ( IsType(input: (char *)m_szType, test: "Quaternion") )
      return "FIELD_QUATERNION";
    if ( IsType(input: (char *)m_szType, test: "VMatrix") )
      return "FIELD_VMATRIX";
    if ( IsType(input: (char *)m_szType, test: "string_t") )
      return "FIELD_STRING";
    if ( !IsType(input: (char *)m_szType, test: "char") )
      return out;
    return "FIELD_CHARACTER";
  }
  return "FIELD_VECTOR";
}

//------------------------------------------------------------------------------
// Address: 0x00401900
// Name: public: void CClass::ReportTypeMismatches(class CClassVariable __near *,class CTypeDescriptionField __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClass::ReportTypeMismatches(CClass *this, CClassVariable *var, CTypeDescriptionField *td)
{
  const char *v3; // eax

  v3 = TranslateSimpleType(var);
  if ( *v3 != 0
    && !td->m_bCommentedOut
    && (strcmp(td->m_szType, "FIELD_TIME") != 0 || strcmp(v3, "FIELD_FLOAT") != 0)
    && (strcmp(td->m_szType, "FIELD_TICK") != 0 || strcmp(v3, "FIELD_INTEGER") != 0)
    && (strcmp(td->m_szType, "FIELD_MODELNAME") != 0 && strcmp(td->m_szType, "FIELD_SOUNDNAME") != 0
     || strcmp(v3, "FIELD_STRING") != 0)
    && (strcmp(td->m_szType, "FIELD_MODELINDEX") != 0 && strcmp(td->m_szType, "FIELD_MATERIALINDEX") != 0
     || strcmp(v3, "FIELD_INTEGER") != 0)
    && (strcmp(td->m_szType, "FIELD_POSITION_VECTOR") != 0 || strcmp(v3, "FIELD_VECTOR") != 0)
    && (strcmp(td->m_szType, "FIELD_VMATRIX_WORLDSPACE") != 0 || strcmp(v3, "FIELD_VMATRIX") != 0)
    && strcmp(v3, td->m_szType) != 0 )
  {
    vprint(
      depth: 0,
      fmt: "class %s has an incorrect FIELD_ type for variable '%s (%s, %s)'\n",
      this->m_szName,
      var->m_szName,
      var->m_szType,
      td->m_szType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C50
// Name: public: bool CClass::CheckForMissingTypeDescriptionFields(int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClass::CheckForMissingTypeDescriptionFields(CClass *this, int *missingcount, bool createtds)
{
  CClass *v3; // edi
  CClassVariable *v5; // ebx
  char *v6; // esi
  char v7; // al
  const char *j; // esi
  CTypeDescriptionField *TD; // eax
  const char *v10; // edi
  const char *m_szArraySize; // [esp-Ch] [ebp-28h]
  int i; // [esp+8h] [ebp-14h]
  CClassVariable **m_Variables; // [esp+Ch] [ebp-10h]
  char *dst; // [esp+10h] [ebp-Ch]
  bool bret; // [esp+1Bh] [ebp-1h]

  v3 = this;
  *missingcount = 0;
  bret = false;
  if ( !this->m_bHasSaveRestoreData )
    return false;
  i = 0;
  if ( this->m_nVarCount > 0 )
  {
    m_Variables = this->m_Variables;
    do
    {
      v5 = *m_Variables;
      dst = (*m_Variables)->m_szType;
      v6 = CC_ParseToken(data: dst);
      if ( strlen(com_token) != 0 )
      {
        while ( _stricmp(dst: com_token, src: "static") != 0 )
        {
          v6 = CC_ParseToken(data: v6);
          if ( strlen(com_token) == 0 )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        v7 = v5->m_szName[0];
        for ( j = (const char *)v5; v7 != 0; v7 = *++j )
        {
          if ( v7 != 42 )
            break;
        }
        TD = CClass::FindTD(this: v3, name: j);
        if ( TD != nullptr )
        {
          CClass::ReportTypeMismatches(this: v3, var: v5, td: TD);
        }
        else
        {
          ++*missingcount;
          bret = true;
          if ( createtds )
          {
            v10 = TranslateSimpleType(var: v5);
            vprint(depth: 0, fmt: "//\tClass %s:\n", this->m_szName);
            if ( !v5->m_bIsArray || _stricmp(dst, src: "char") == 0 && _stricmp(dst: v10, src: "FIELD_STRING") == 0 )
            {
              if ( *v10 != 0 )
                vprint(depth: 0, fmt: "\tDEFINE_FIELD( %s, %s ),\n", j, v10);
              else
                vprint(depth: 0, fmt: "\t// DEFINE_FIELD( %s, %s ),\n", j, dst);
            }
            else
            {
              m_szArraySize = v5->m_szArraySize;
              if ( *v10 != 0 )
                vprint(depth: 0, fmt: "\tDEFINE_ARRAY( %s, %s, %s ),\n", j, v10, m_szArraySize);
              else
                vprint(depth: 0, fmt: "\t// DEFINE_ARRAY( %s, %s, %s ),\n", j, dst, m_szArraySize);
            }
            v3 = this;
          }
          else
          {
            vprint(
              depth: 0,
              fmt: "class %s missing typedescription_t field for variable '%s %s'\n",
              v3->m_szName,
              dst,
              v5->m_szName);
          }
        }
      }
      ++m_Variables;
      ++i;
    }
    while ( i < v3->m_nVarCount );
  }
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x00401E30
// Name: public: bool CClass::CheckForPredictionFieldsInRecvTableNotMarkedAsSuchCorrectly(int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClass::CheckForPredictionFieldsInRecvTableNotMarkedAsSuchCorrectly(CClass *this, int *missingcount)
{
  CClassVariable *v3; // edi
  bool m_bInRecvTable; // bl
  char *v5; // esi
  char v6; // al
  const char *j; // ecx
  CTypeDescriptionField *PredTD; // eax
  CTypeDescriptionField *v9; // esi
  CClass *v10; // eax
  int i; // [esp+4h] [ebp-10h]
  CClassVariable **m_Variables; // [esp+8h] [ebp-Ch]
  bool bret; // [esp+13h] [ebp-1h]

  *missingcount = 0;
  bret = false;
  if ( !this->m_bHasPredictionData || !this->m_bHasRecvTableData )
    return false;
  i = 0;
  if ( this->m_nVarCount > 0 )
  {
    m_Variables = this->m_Variables;
    do
    {
      v3 = *m_Variables;
      m_bInRecvTable = (*m_Variables)->m_bInRecvTable;
      v5 = CC_ParseToken(data: (*m_Variables)->m_szType);
      if ( strlen(com_token) != 0 )
      {
        while ( _stricmp(dst: com_token, src: "static") != 0 )
        {
          v5 = CC_ParseToken(data: v5);
          if ( strlen(com_token) == 0 )
            goto LABEL_9;
        }
      }
      else
      {
LABEL_9:
        v6 = v3->m_szName[0];
        for ( j = (const char *)v3; v6 != 0; v6 = *++j )
        {
          if ( v6 != 42 )
            break;
        }
        PredTD = CClass::FindPredTD(this, name: j);
        v9 = PredTD;
        if ( PredTD != nullptr )
        {
          if ( strcmp(PredTD->m_szDefineType, "DEFINE_PRED_TYPEDESCRIPTION") == 0 )
          {
            v10 = processor->FindClass(this: processor, a2: v9->m_szType);
            if ( v10 != nullptr )
              bret = CClass::CheckForPredictionFieldsInRecvTableNotMarkedAsSuchCorrectly(this: v10, missingcount);
          }
          else if ( m_bInRecvTable != v9->m_bRepresentedInRecvTable )
          {
            ++*missingcount;
            bret = true;
            if ( !m_bInRecvTable || v9->m_bRepresentedInRecvTable )
              vprint(
                depth: 0,
                fmt: "%s::%s:  Field marked as FTYPEDESC_INSENDTABLE in prediction typedescription missing from RecvTable\n",
                this,
                v3);
            else
              vprint(
                depth: 0,
                fmt: "%s::%s:  Missing FTYPEDESC_INSENDTABLE flag in prediction typedescription\n",
                this,
                v3);
          }
        }
      }
      ++m_Variables;
      ++i;
    }
    while ( i < this->m_nVarCount );
  }
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x00401FE0
// Name: public: bool CClass::CheckForMissingPredictionFields(int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClass::CheckForMissingPredictionFields(CClass *this, int *missingcount, bool createtds)
{
  CClassVariable *v4; // ebx
  char *v5; // esi
  char v6; // al
  const char *j; // esi
  const char *v8; // edi
  const char *m_szArraySize; // [esp-10h] [ebp-28h]
  int i; // [esp+4h] [ebp-14h]
  CClassVariable **m_Variables; // [esp+8h] [ebp-10h]
  char *dst; // [esp+Ch] [ebp-Ch]
  bool bret; // [esp+17h] [ebp-1h]

  *missingcount = 0;
  bret = false;
  if ( !this->m_bHasPredictionData )
    return false;
  i = 0;
  if ( this->m_nVarCount > 0 )
  {
    m_Variables = this->m_Variables;
    do
    {
      v4 = *m_Variables;
      dst = (*m_Variables)->m_szType;
      v5 = CC_ParseToken(data: dst);
      if ( strlen(com_token) != 0 )
      {
        while ( _stricmp(dst: com_token, src: "static") != 0 )
        {
          v5 = CC_ParseToken(data: v5);
          if ( strlen(com_token) == 0 )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        v6 = v4->m_szName[0];
        for ( j = (const char *)v4; v6 != 0; v6 = *++j )
        {
          if ( v6 != 42 )
            break;
        }
        if ( CClass::FindPredTD(this, name: j) == nullptr )
        {
          ++*missingcount;
          bret = true;
          if ( createtds )
          {
            v8 = TranslateSimpleType(var: v4);
            vprint(depth: 0, fmt: "//\tClass %s:\n", this->m_szName);
            if ( !v4->m_bIsArray || _stricmp(dst, src: "char") == 0 && _stricmp(dst: v8, src: "FIELD_STRING") == 0 )
            {
              if ( *v8 != 0 )
                vprint(depth: 0, fmt: "\tDEFINE_FIELD( %s, %s ),\n", j, v8);
              else
                vprint(depth: 0, fmt: "\t// DEFINE_FIELD( %s, %s ),\n", j, dst);
            }
            else
            {
              m_szArraySize = v4->m_szArraySize;
              if ( *v8 != 0 )
                vprint(depth: 0, fmt: "\tDEFINE_ARRAY( %s, %s, %s ),\n", j, v8, m_szArraySize);
              else
                vprint(depth: 0, fmt: "\t// DEFINE_ARRAY( %s, %s, %s ),\n", j, dst, m_szArraySize);
            }
          }
          else
          {
            vprint(
              depth: 0,
              fmt: "class %s missing prediction typedescription_t field for variable '%s %s'\n",
              this->m_szName,
              dst,
              v4->m_szName);
          }
        }
      }
      ++m_Variables;
      ++i;
    }
    while ( i < this->m_nVarCount );
  }
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x004021C0
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x004021F0
// Name: public: bool CClass::ParseBaseClass(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClass::ParseBaseClass(CClass *this, char **input)
{
  char *v3; // eax
  char *v5; // eax
  char *m_szTypedefBaseClass; // edi

  if ( strcmp(com_token, "DECLARE_CLASS") == 0
    || strcmp(com_token, "DECLARE_CLASS_GAMEROOT") == 0
    || strcmp(com_token, "DECLARE_CLASS_NOFRIEND") == 0 )
  {
    v5 = CC_ParseToken(data: *input);
    *input = v5;
    *input = CC_ParseToken(data: v5);
    do
      *input = CC_ParseToken(data: *input);
    while ( strcmp(com_token, ",") != 0 );
    m_szTypedefBaseClass = this->m_szTypedefBaseClass;
    this->m_szTypedefBaseClass[0] = 0;
    *input = CC_ParseToken(data: *input);
    while ( 1 )
    {
      strcat(m_szTypedefBaseClass, com_token);
      *input = CC_ParseToken(data: *input);
      if ( strcmp(com_token, ")") == 0 )
        break;
      m_szTypedefBaseClass = this->m_szTypedefBaseClass;
    }
    return 1;
  }
  else if ( strcmp(com_token, "DECLARE_CLASS_NOBASE") == 0 )
  {
    v3 = CC_ParseToken(data: *input);
    *input = v3;
    *input = CC_DiscardUntilMatchingCharIncludingNesting(input: v3, pairing: "()");
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402400
// Name: public: bool CClass::ParseNestedClass(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClass::ParseNestedClass(CClass *this, char **input)
{
  CClass *v4; // edi
  char decorated[256]; // [esp+4h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: com_token, s2: "struct") != 0 && _V_stricmp(s1: com_token, s2: "class") != 0 )
    return 0;
  *input = CC_ParseToken(data: *input);
  if ( strlen(com_token) != 0 )
  {
    sprintf(string: decorated, format: "%s::%s", this->m_szName, com_token);
    v4 = processor->AddClass(this: processor, a2: decorated);
    *input = CC_ParseToken(data: *input);
    if ( _V_stricmp(s1: com_token, s2: ":") != 0 )
    {
      if ( _V_stricmp(s1: com_token, s2: "{") == 0 )
        *input = CClass::ParseClassDeclaration(this: v4, input: *input);
    }
    else
    {
      *input = CC_ParseToken(data: *input);
      if ( _V_stricmp(s1: com_token, s2: "public") == 0 )
      {
        *input = CC_ParseToken(data: *input);
        if ( strlen(com_token) != 0 )
        {
          CClass::SetBaseClass(this: v4, name: com_token);
          do
            *input = CC_ParseToken(data: *input);
          while ( strlen(com_token) != 0 && _V_stricmp(s1: com_token, s2: "{") != 0 );
          if ( _V_stricmp(s1: com_token, s2: "{") == 0 )
          {
            *input = CClass::ParseClassDeclaration(this: v4, input: *input);
            return 1;
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004025B0
// Name: public: bool CClass::ParseProtection(char __near * __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClass::ParseProtection(CClass *this, char **input, int *protection)
{
  if ( _V_stricmp(s1: com_token, s2: "public") != 0 )
  {
    if ( _V_stricmp(s1: com_token, s2: "protected") != 0 )
    {
      if ( _V_stricmp(s1: com_token, s2: "private") != 0 )
      {
        return 0;
      }
      else
      {
        *protection = 2;
        *input = CC_ParseToken(data: *input);
        return 1;
      }
    }
    else
    {
      *protection = 1;
      *input = CC_ParseToken(data: *input);
      return 1;
    }
  }
  else
  {
    *protection = 0;
    *input = CC_ParseToken(data: *input);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402660
// Name: public: void CClass::CheckForHungarianErrors(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClass::CheckForHungarianErrors(CClass *this, int *warnings)
{
  const char *v2; // edi
  char *k; // esi
  Impermissible *v4; // esi
  int v5; // eax
  int v6; // eax
  bool v7; // al
  int i; // [esp+8h] [ebp-8h]
  const char **j; // [esp+Ch] [ebp-4h]

  i = 0;
  if ( this->m_nVarCount > 0 )
  {
    for ( j = (const char **)this->m_Variables; ; ++j )
    {
      v2 = *j;
      if ( V_strncmp(s1: *j, s2: "m_", count: 2) == 0
        || V_strncmp(s1: v2, s2: "g_", count: 2) == 0
        || V_strncmp(s1: v2, s2: "s_", count: 2) == 0 )
      {
        for ( k = CC_ParseToken(data: (char *)v2 + 128); strlen(com_token) != 0; k = CC_ParseToken(data: k) )
        {
          if ( _V_stricmp(s1: com_token, s2: "static") == 0 )
            break;
        }
        v4 = g_Permissibles;
        do
        {
          v5 = _V_strlen(str: v4->prefix);
          if ( V_strncmp(s1: v2 + 2, s2: v4->prefix, count: v5) == 0 )
          {
            v6 = _V_strlen(str: v4->prefix);
            if ( isupper(c: v2[v6 + 2]) != 0 )
            {
              v7 = V_stristr(pStr: (char *)v2 + 128, pSearch: v4->mustinclude) != nullptr;
              if ( v4->required != 0 )
              {
                if ( v7 )
                  return;
              }
              else if ( !v7 )
              {
                return;
              }
              vprint(depth: 1, fmt: "%s might have wrong type %s\n", v2, v2 + 128);
              ++*warnings;
            }
          }
          ++v4;
        }
        while ( (int)v4 < (int)&vec2_invalid );
        if ( V_strncmp(s1: v2, s2: "m_f", count: 3) == 0
          && V_strncmp(s1: v2, s2: "m_fl", count: 4) != 0
          && isupper(c: v2[3]) != 0
          && V_stristr(pStr: (char *)v2 + 128, pSearch: "bool") == nullptr
          && _V_strstr(s1: v2 + 128, search: "int") == nullptr )
        {
          break;
        }
      }
      if ( ++i >= this->m_nVarCount )
        return;
    }
    vprint(depth: 1, fmt: "%s might have wrong type %s\n", v2, v2 + 128);
    ++*warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402870
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403980
// Name: void ReportMissingTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportMissingTypes()
{
  int m_NumElements; // edi
  int v1; // esi
  MissingType *p_elem; // eax
  CClass *owning_class; // ecx
  CClassVariable *var; // [esp-4h] [ebp-Ch]

  m_NumElements = missing_types.m_Elements.m_Tree.m_NumElements;
  v1 = 0;
  if ( missing_types.m_Elements.m_Tree.m_NumElements != 0 )
  {
    do
    {
      p_elem = &missing_types.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v1].m_Data.elem;
      if ( &missing_types.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v1] != (UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short> *)-12 )
      {
        owning_class = p_elem->owning_class;
        if ( p_elem->owning_class != nullptr
          && owning_class->m_bDerivedFromCBaseEntity
          && missing_types.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v1].m_Data.elem.var != nullptr )
        {
          var = missing_types.m_Elements.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v1].m_Data.elem.var;
          vprint(
            depth: 0,
            fmt: "Can't compute size of %s %s %s\n",
            owning_class->m_szName,
            var->m_szType,
            var->m_szName);
        }
      }
      ++v1;
    }
    while ( v1 < m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403AC0
// Name: void ClearMissingTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearMissingTypes()
{
  CUtlDict<MissingType,unsigned short>::RemoveAll(this: &missing_types);
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: bool IsMissingType(class CClass __near *,class CClassVariable __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsMissingType(CClass *cl, CClassVariable *var)
{
  CUtlMap<char const *,MissingType,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF

  if ( var == (CClassVariable *)-128
    || (search.key = var->m_szType,
        CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &missing_types.m_Elements.m_Tree,
          &search) == 0xFFFF) )
  {
    search.elem.owning_class = cl;
    search.elem.var = var;
    CUtlDict<MissingType,unsigned short>::Insert(this: &missing_types, pName: var->m_szType, element: &search.elem);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403BB0
// Name: GetTypeSize
// Source: json
//------------------------------------------------------------------------------
int __usercall GetTypeSize@<eax>(CClassVariable *var@<edi>, CClass *cl)
{
  int v2; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  CClass *v23; // eax
  CUtlMap<char const *,MissingType,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF

  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "<");
  if ( v2 != 0 )
  {
    if ( var == (CClassVariable *)-128
      || (search.key = var->m_szType,
          CUtlRBTree<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,MissingType,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,MissingType,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
            this: &missing_types.m_Elements.m_Tree,
            &search) == 0xFFFF) )
    {
      search.elem.owning_class = cl;
      search.elem.var = var;
      CUtlDict<MissingType,unsigned short>::Insert(this: &missing_types, pName: var->m_szType, element: &search.elem);
    }
    return 0;
  }
  strstr(str1: (unsigned __int8 *)var, str2: "*");
  if ( v4 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "bool");
  if ( v5 != 0 )
    return 1;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "int64");
  if ( v6 != 0 )
    return 8;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "short");
  if ( v7 != 0 )
    return 2;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "unsigned short");
  if ( v8 != 0 )
    return 2;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "int");
  if ( v9 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "float");
  if ( v10 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "vec_t");
  if ( v11 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "Vector");
  if ( v12 != 0 )
    return 12;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "QAngle");
  if ( v13 != 0 )
    return 12;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "vec3_t");
  if ( v14 != 0 )
    return 12;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "char");
  if ( v15 != 0 )
    return 1;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "unsigned char");
  if ( v16 != 0 )
    return 1;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "BYTE");
  if ( v17 != 0 )
    return 1;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "byte");
  if ( v18 != 0 )
    return 1;
  if ( strcmp(var->m_szType, "unsigned") == 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "long");
  if ( v19 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "color32");
  if ( v20 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "*");
  if ( v21 != 0 )
    return 4;
  strstr(str1: (unsigned __int8 *)var->m_szType, str2: "static");
  if ( v22 != 0 )
    return 0;
  v23 = processor->FindClass(this: processor, a2: var->m_szType);
  if ( v23 != nullptr )
    return v23->m_nClassDataSize;
  IsMissingType(cl, var);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403E40
// Name: public: void CClass::AddVariable(int,char __near *,char __near *,bool,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClass::AddVariable(
        CClass *this,
        CClassVariable::VARTYPE protection,
        char *type,
        char *name,
        bool array,
        char *arraysize)
{
  CClassVariable *v7; // edi
  int TypeSize; // eax

  v7 = CClass::AddVar(this, name);
  if ( v7 != nullptr )
  {
    strcpy(v7->m_szType, type);
    v7->m_Type = protection;
    TypeSize = GetTypeSize(var: v7, cl: this);
    v7->m_TypeSize = TypeSize;
    this->m_nClassDataSize += TypeSize;
    if ( array )
    {
      v7->m_bIsArray = true;
      strcpy(v7->m_szArraySize, arraysize);
    }
    else
    {
      v7->m_bIsArray = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403EC0
// Name: public: bool CClass::ParseNetworkVar(char __near * __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClass::ParseNetworkVar(CClass *this, char **input, CClassVariable::VARTYPE protection)
{
  char *v3; // eax
  unsigned int v4; // eax
  char *v5; // edi
  char v6; // cl
  char *v8; // eax
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  char *v12; // edx
  char *v13; // esi
  unsigned int v14; // eax
  char *v15; // edi
  char v16; // cl
  char *v17; // eax
  unsigned int v18; // eax
  char *v19; // edi
  char v20; // cl
  char *v21; // edi
  char v22; // al
  char *v23; // esi
  unsigned int v24; // eax
  char *v25; // edi
  char v26; // cl
  char *v27; // esi
  unsigned int v28; // eax
  char *v29; // edi
  char v30; // cl
  char *v31; // edx
  char *v32; // eax
  unsigned int v33; // eax
  char *v34; // edi
  char v35; // cl
  char *v36; // edx
  char *v37; // eax
  unsigned int v38; // eax
  char *v39; // edi
  char v40; // cl
  char *v41; // edi
  char v42; // al
  char *v43; // esi
  char *v44; // edi
  char v45; // al
  unsigned int v46; // eax
  char *v47; // edi
  char v48; // cl
  char *v49; // eax
  unsigned int v50; // eax
  char *v51; // edi
  char v52; // cl
  char *v53; // edi
  char v54; // al
  char *v55; // esi
  unsigned int v56; // eax
  char *v57; // edi
  char v58; // cl
  CClass *v59; // esi
  CClassVariable *v60; // edi
  int TypeSize; // eax
  char *v62; // [esp-10h] [ebp-398h]
  char *v63; // [esp-10h] [ebp-398h]
  char *v64; // [esp-10h] [ebp-398h]
  char v65; // [esp-1h] [ebp-389h] BYREF
  CClass::MemberVarParse_t var; // [esp+0h] [ebp-388h] BYREF
  CClass *v67; // [esp+384h] [ebp-4h]

  v67 = this;
  var.m_pType[0] = 0;
  var.m_pTypeModifier[0] = 0;
  var.m_pName[0] = 0;
  var.m_pArraySize[0] = 0;
  var.m_bArray = false;
  if ( strcmp(com_token, "CNetworkVar") == 0
    || strcmp(com_token, "CNetworkVarForDerived") == 0
    || strcmp(com_token, "CNetworkVarEmbedded") == 0 )
  {
    v49 = CC_ParseToken(data: *input);
    *input = v49;
    *input = CC_ParseToken(data: v49);
    do
    {
      v50 = strlen(com_token) + 1;
      v51 = &v65;
      do
        v52 = *++v51;
      while ( v52 != 0 );
      qmemcpy(v51, com_token, v50);
      v53 = &v65;
      do
        v54 = *++v53;
      while ( v54 != 0 );
      v64 = *input;
      strcpy(v53, " ");
      v55 = CC_ParseToken(data: v64);
      *input = v55;
    }
    while ( strcmp(com_token, ",") != 0 );
    *input = CC_ParseToken(data: v55);
    do
    {
      v56 = strlen(com_token) + 1;
      v57 = &var.m_pTypeModifier[255];
      do
        v58 = *++v57;
      while ( v58 != 0 );
      qmemcpy(v57, com_token, v56);
      *input = CC_ParseToken(data: *input);
    }
    while ( strcmp(com_token, ")") != 0 );
    v59 = v67;
    v60 = CClass::AddVar(this: v67, name: var.m_pName);
    if ( v60 != nullptr )
    {
      strcpy(v60->m_szType, var.m_pType);
      v60->m_Type = protection;
      TypeSize = GetTypeSize(var: v60, cl: v59);
      v60->m_TypeSize = TypeSize;
      v59->m_nClassDataSize += TypeSize;
      v60->m_bIsArray = false;
    }
    return 1;
  }
  else if ( strcmp(com_token, "CNetworkHandle") == 0 || strcmp(com_token, "CNetworkHandleForDerived") == 0 )
  {
    v37 = CC_ParseToken(data: *input);
    *input = v37;
    *input = CC_ParseToken(data: v37);
    strcpy(var.m_pType, "CHandle<");
    do
    {
      v38 = strlen(com_token) + 1;
      v39 = &v65;
      do
        v40 = *++v39;
      while ( v40 != 0 );
      qmemcpy(v39, com_token, v38);
      v41 = &v65;
      do
        v42 = *++v41;
      while ( v42 != 0 );
      v63 = *input;
      strcpy(v41, " ");
      v43 = CC_ParseToken(data: v63);
      *input = v43;
    }
    while ( strcmp(com_token, ",") != 0 );
    v44 = &v65;
    do
      v45 = *++v44;
    while ( v45 != 0 );
    strcpy(v44, ">");
    *input = CC_ParseToken(data: v43);
    do
    {
      v46 = strlen(com_token) + 1;
      v47 = &var.m_pTypeModifier[255];
      do
        v48 = *++v47;
      while ( v48 != 0 );
      qmemcpy(v47, com_token, v46);
      *input = CC_ParseToken(data: *input);
    }
    while ( strcmp(com_token, ")") != 0 );
    CClass::AddVariable(this: v67, protection, type: "EHANDLE", name: var.m_pName, array: false, arraysize: nullptr);
    return 1;
  }
  else if ( strcmp(com_token, "CNetworkVector") == 0
         || strcmp(com_token, "CNetworkVectorForDerived") == 0
         || strcmp(com_token, "CNetworkQAngle") == 0 )
  {
    v32 = CC_ParseToken(data: *input);
    *input = v32;
    *input = CC_ParseToken(data: v32);
    do
    {
      v33 = strlen(com_token) + 1;
      v34 = &var.m_pTypeModifier[255];
      do
        v35 = *++v34;
      while ( v35 != 0 );
      v36 = *input;
      qmemcpy(v34, com_token, v33);
      *input = CC_ParseToken(data: v36);
    }
    while ( strcmp(com_token, ")") != 0 );
    CClass::AddVariable(this: v67, protection, type: "Vector", name: var.m_pName, array: false, arraysize: nullptr);
    return 1;
  }
  else if ( strcmp(com_token, "CNetworkColor32") == 0 )
  {
    v3 = CC_ParseToken(data: *input);
    *input = v3;
    *input = CC_ParseToken(data: v3);
    do
    {
      v4 = strlen(com_token) + 1;
      v5 = &var.m_pTypeModifier[255];
      do
        v6 = *++v5;
      while ( v6 != 0 );
      qmemcpy(v5, com_token, v4);
      *input = CC_ParseToken(data: *input);
    }
    while ( strcmp(com_token, ")") != 0 );
    CClass::AddVariable(this: v67, protection, type: "color32", name: var.m_pName, array: false, arraysize: nullptr);
    return 1;
  }
  else if ( strcmp(com_token, "CNetworkString") == 0 )
  {
    v8 = CC_ParseToken(data: *input);
    *input = v8;
    *input = CC_ParseToken(data: v8);
    do
    {
      v9 = strlen(com_token) + 1;
      v10 = &var.m_pTypeModifier[255];
      do
        v11 = *++v10;
      while ( v11 != 0 );
      v12 = *input;
      qmemcpy(v10, com_token, v9);
      v13 = CC_ParseToken(data: v12);
      *input = v13;
    }
    while ( strcmp(com_token, ",") != 0 );
    *input = CC_ParseToken(data: v13);
    do
    {
      v14 = strlen(com_token) + 1;
      v15 = &var.m_pName[255];
      do
        v16 = *++v15;
      while ( v16 != 0 );
      qmemcpy(v15, com_token, v14);
      *input = CC_ParseToken(data: *input);
    }
    while ( strcmp(com_token, ")") != 0 );
    CClass::AddVariable(
      this: v67,
      protection,
      type: "char *",
      name: var.m_pName,
      array: true,
      arraysize: var.m_pArraySize);
    return 1;
  }
  else if ( strcmp(com_token, "CNetworkArray") == 0 || strcmp(com_token, "CNetworkArrayForDerived") == 0 )
  {
    v17 = CC_ParseToken(data: *input);
    *input = v17;
    *input = CC_ParseToken(data: v17);
    do
    {
      v18 = strlen(com_token) + 1;
      v19 = &v65;
      do
        v20 = *++v19;
      while ( v20 != 0 );
      qmemcpy(v19, com_token, v18);
      v21 = &v65;
      do
        v22 = *++v21;
      while ( v22 != 0 );
      v62 = *input;
      strcpy(v21, " ");
      v23 = CC_ParseToken(data: v62);
      *input = v23;
    }
    while ( strcmp(com_token, ",") != 0 );
    *input = CC_ParseToken(data: v23);
    do
    {
      v24 = strlen(com_token) + 1;
      v25 = &var.m_pTypeModifier[255];
      do
        v26 = *++v25;
      while ( v26 != 0 );
      qmemcpy(v25, com_token, v24);
      v27 = CC_ParseToken(data: *input);
      *input = v27;
    }
    while ( strcmp(com_token, ",") != 0 );
    *input = CC_ParseToken(data: v27);
    do
    {
      v28 = strlen(com_token) + 1;
      v29 = &var.m_pName[255];
      do
        v30 = *++v29;
      while ( v30 != 0 );
      v31 = *input;
      qmemcpy(v29, com_token, v28);
      *input = CC_ParseToken(data: v31);
    }
    while ( strcmp(com_token, ")") != 0 );
    CClass::AddVariable(
      this: v67,
      protection,
      type: var.m_pType,
      name: var.m_pName,
      array: true,
      arraysize: var.m_pArraySize);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404920
// Name: public: bool CClass::ParseClassMember(char __near * __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClass::ParseClassMember(CClass *this, char **input, CClassVariable::VARTYPE protection)
{
  char **v3; // ebx
  int v4; // eax
  char v5; // cl
  char *v6; // esi
  char *v7; // eax
  int v8; // edi
  char *v9; // edi
  char v10; // al
  unsigned int v11; // eax
  char *v12; // edi
  char v13; // cl
  unsigned int v14; // eax
  char *v15; // edi
  char v16; // cl
  char *v17; // edi
  char v18; // al
  int v19; // eax
  char v20; // cl
  unsigned int v21; // eax
  char *v22; // edi
  char v23; // cl
  char *v24; // edi
  char v25; // al
  int v26; // eax
  char v27; // cl
  unsigned int v28; // eax
  char *v29; // edi
  char v30; // cl
  char *v31; // edi
  char v32; // al
  int v33; // eax
  char v34; // cl
  char *v35; // edi
  char *v36; // eax
  char **v37; // eax
  char *v38; // ebx
  char **v39; // esi
  int v40; // eax
  char v41; // cl
  char *v42; // eax
  unsigned __int8 *v43; // edi
  char *v44; // eax
  char *v45; // eax
  char *v46; // eax
  int v47; // esi
  int v48; // eax
  char v49; // cl
  CClassMemberFunction *v51; // eax
  CClass::MemberVarParse_t *p_var; // ecx
  char v53; // dl
  CClass *v54; // esi
  char *v55; // eax
  char *v56; // eax
  int v57; // eax
  char v58; // cl
  char *v59; // [esp-14h] [ebp-4A8h]
  char *v60; // [esp-10h] [ebp-4A4h]
  char pfn[256]; // [esp+4h] [ebp-490h] BYREF
  CClass::MemberVarParse_t var; // [esp+104h] [ebp-390h] BYREF
  CClass *v63; // [esp+488h] [ebp-Ch]
  bool wascomma; // [esp+491h] [ebp-3h]
  bool skipvar; // [esp+492h] [ebp-2h]
  bool isfunction; // [esp+493h] [ebp-1h]

  v3 = input;
  v63 = this;
  var.m_pType[0] = 0;
  var.m_pTypeModifier[0] = 0;
  var.m_pName[0] = 0;
  var.m_pArraySize[0] = 0;
  var.m_bArray = false;
  isfunction = false;
  wascomma = false;
  skipvar = false;
  if ( CClass::ParseNetworkVar(this, input, protection) != 0 )
    return 1;
  v4 = 0;
  do
  {
    v5 = com_token[v4];
    var.m_pName[v4++] = v5;
  }
  while ( v5 != 0 );
  if ( _V_stricmp(s1: var.m_pName, s2: "SHARED_CLASSNAME") == 0 )
  {
    *v3 = CC_ParseToken(data: *v3);
    if ( _V_stricmp(s1: com_token, s2: "(") == 0 )
    {
      v6 = *v3;
      v7 = CC_DiscardUntilMatchingCharIncludingNesting(input: *v3, pairing: "()");
      *v3 = v7;
      v8 = v7 - v6;
      strncpy(dest: (unsigned __int8 *)pfn, source: (unsigned __int8 *)v6, count: v7 - v6);
      pfn[v8] = 0;
      v9 = &var.m_pTypeModifier[255];
      do
        v10 = *++v9;
      while ( v10 != 0 );
      strcpy(v9, "(");
      v11 = strlen(pfn) + 1;
      v12 = &var.m_pTypeModifier[255];
      do
        v13 = *++v12;
      while ( v13 != 0 );
      qmemcpy(v12, pfn, v11);
    }
  }
  *v3 = CC_ParseToken(data: *v3);
  if ( strlen(com_token) == 0 )
    goto LABEL_71;
  while ( _V_stricmp(s1: com_token, s2: "(") != 0 )
  {
    if ( _V_stricmp(s1: com_token, s2: "[") == 0 )
    {
      v59 = *v3;
      var.m_bArray = true;
      v43 = (unsigned __int8 *)v59;
      v44 = CC_RawParseChar(input: v59, ch: "]", breakchar: (char *)&input + 3);
      *v3 = v44;
      if ( *v44 != 0 )
      {
        do
        {
          v45 = *v3;
          if ( **v3 != 91 )
            break;
          *v3 = v45 + 1;
          v46 = CC_RawParseChar(input: v45 + 1, ch: "]", breakchar: (char *)&input + 3);
          *v3 = v46;
        }
        while ( *v46 != 0 );
      }
      v47 = *v3 - (char *)v43 - 1;
      if ( v47 > 0 )
        strncpy(dest: (unsigned __int8 *)var.m_pArraySize, source: v43, count: *v3 - (char *)v43 - 1);
      var.m_pArraySize[v47] = 0;
      goto LABEL_71;
    }
    if ( _V_stricmp(s1: com_token, s2: ";") == 0 )
      goto LABEL_71;
    if ( _V_stricmp(s1: com_token, s2: ":") != 0 )
    {
      if ( _V_stricmp(s1: com_token, s2: ",") == 0 )
      {
        wascomma = true;
        goto LABEL_71;
      }
      if ( byte_42500F[strlen(com_token)] != 60 || strcmp(var.m_pName, "operator") == 0 )
      {
        if ( _V_stricmp(s1: var.m_pName, s2: "typedef") == 0
          || _V_stricmp(s1: var.m_pName, s2: "enum") == 0
          || _V_stricmp(s1: var.m_pName, s2: "friend") == 0 )
        {
          skipvar = true;
        }
        v28 = strlen(var.m_pName) + 1;
        v29 = &pfn[255];
        do
          v30 = *++v29;
        while ( v30 != 0 );
        qmemcpy(v29, var.m_pName, v28);
        v31 = &pfn[255];
        do
          v32 = *++v31;
        while ( v32 != 0 );
        strcpy(v31, " ");
        v33 = 0;
        do
        {
          v34 = com_token[v33];
          var.m_pName[v33++] = v34;
        }
        while ( v34 != 0 );
      }
      else
      {
        do
        {
          v14 = strlen(var.m_pName) + 1;
          v15 = &pfn[255];
          do
            v16 = *++v15;
          while ( v16 != 0 );
          qmemcpy(v15, var.m_pName, v14);
          v17 = &pfn[255];
          do
            v18 = *++v17;
          while ( v18 != 0 );
          strcpy(v17, " ");
          v19 = 0;
          do
          {
            v20 = com_token[v19];
            var.m_pName[v19++] = v20;
          }
          while ( v20 != 0 );
          *v3 = CC_ParseToken(data: *v3);
        }
        while ( strlen(com_token) != 0 && strcmp(com_token, ">") != 0 );
        v21 = strlen(var.m_pName) + 1;
        v22 = &pfn[255];
        do
          v23 = *++v22;
        while ( v23 != 0 );
        qmemcpy(v22, var.m_pName, v21);
        v24 = &pfn[255];
        do
          v25 = *++v24;
        while ( v25 != 0 );
        strcpy(v24, " ");
        v26 = 0;
        do
        {
          v27 = com_token[v26];
          var.m_pName[v26++] = v27;
        }
        while ( v27 != 0 );
      }
    }
    else
    {
      *v3 = CC_ParseToken(data: *v3);
    }
    *v3 = CC_ParseToken(data: *v3);
    if ( strlen(com_token) == 0 )
      goto LABEL_71;
  }
  v35 = *v3;
  v60 = *v3;
  isfunction = true;
  v36 = CC_DiscardUntilMatchingCharIncludingNesting(input: v60, pairing: "()");
  *v3 = v36;
  *v3 = CC_ParseToken(data: v36);
  if ( _V_stricmp(s1: com_token, s2: "const") == 0 )
    *v3 = CC_ParseToken(data: *v3);
  if ( _V_stricmp(s1: com_token, s2: "{") == 0 )
  {
    *v3 = CC_DiscardUntilMatchingCharIncludingNesting(input: *v3, pairing: "{}");
    goto LABEL_71;
  }
  if ( _V_stricmp(s1: com_token, s2: "=") == 0 )
  {
    *v3 = CC_RawParseChar(input: *v3, ch: ";", breakchar: (char *)&input + 3);
    goto LABEL_71;
  }
  if ( _V_stricmp(s1: com_token, s2: "(") != 0 )
    goto LABEL_71;
  v37 = v3;
  v38 = *v3;
  *v37 = v35;
  strncpy(dest: (unsigned __int8 *)pfn, source: (unsigned __int8 *)v35, count: v38 - 2 - v35);
  pfn[v38 - 2 - v35] = 0;
  v39 = input;
  *v39 = CC_ParseToken(data: *input);
  if ( strlen(com_token) != 0 )
  {
    while ( com_token[0] != 42 )
    {
      *v39 = CC_ParseToken(data: *v39);
      if ( strlen(com_token) == 0 )
        goto LABEL_57;
    }
    goto LABEL_58;
  }
LABEL_57:
  if ( com_token[0] == 42 )
  {
LABEL_58:
    sprintf(string: var.m_pType, format: "%s (%s)", var.m_pName, pfn);
    v40 = 0;
    do
    {
      v41 = com_token[v40];
      var.m_pName[v40++] = v41;
    }
    while ( v41 != 0 );
    *v39 = v38 - 1;
  }
  if ( **v39 == 40 )
    ++*v39;
  v42 = CC_DiscardUntilMatchingCharIncludingNesting(input: *v39, pairing: "()");
  v3 = input;
  *v39 = v42;
  isfunction = false;
LABEL_71:
  v48 = &var.m_pTypeModifier[strlen(var.m_pType) - 255] - &var.m_pType[1];
  if ( v48 != 0 )
    pfn[v48 + 255] = v49;
  if ( var.m_pType[0] == 0 )
  {
    if ( strcmp(var.m_pName, "CUSTOM_SCHEDULES") == 0
      || strcmp(var.m_pName, "DEFINE_CUSTOM_SCHEDULE_PROVIDER") == 0
      || strcmp(var.m_pName, "DEFINE_CUSTOM_AI") == 0
      || strcmp(var.m_pName, "DECLARE_DATADESC") == 0
      || strcmp(var.m_pName, "DECLARE_EMBEDDED_DATADESC") == 0
      || strcmp(var.m_pName, "DECLARE_SERVERCLASS") == 0
      || strcmp(var.m_pName, "DECLARE_CLIENTCLASS") == 0
      || strcmp(var.m_pName, "DECLARE_ENTITY_PANEL") == 0
      || strcmp(var.m_pName, "DECLARE_MINIMAP_PANEL") == 0
      || strcmp(var.m_pName, "MANUALMODE_GETSET_PROP") == 0 )
    {
      return 1;
    }
    if ( strcmp(var.m_pName, "DECLARE_PREDICTABLE") == 0 || strcmp(var.m_pName, "DECLARE_EMBEDDED_PREDDESC") == 0 )
    {
      v63->m_bHasPredictionData = true;
      return 1;
    }
  }
  if ( !isfunction )
  {
    while ( 1 )
    {
      if ( skipvar )
      {
        if ( _V_stricmp(s1: var.m_pName, s2: "BaseClass") == 0 )
        {
          v54 = v63;
          if ( v63->m_szTypedefBaseClass[0] == 0 )
          {
            v55 = CC_ParseToken(data: var.m_pType);
            CC_ParseToken(data: v55);
            strcpy(v54->m_szTypedefBaseClass, com_token);
          }
        }
      }
      else
      {
        CClass::AddVariable(
          this: v63,
          protection,
          type: var.m_pType,
          name: var.m_pName,
          array: var.m_bArray,
          arraysize: var.m_pArraySize);
      }
      if ( !wascomma )
        break;
      *v3 = CC_ParseToken(data: *v3);
      if ( strlen(com_token) == 0 )
        break;
      if ( _V_stricmp(s1: com_token, s2: ":") == 0 )
      {
        v56 = CC_ParseToken(data: *v3);
        *v3 = v56;
        *v3 = CC_ParseToken(data: v56);
      }
      if ( _V_stricmp(s1: com_token, s2: ",") == 0 )
        *v3 = CC_ParseToken(data: *v3);
      if ( _V_stricmp(s1: com_token, s2: ";") == 0 )
        break;
      v57 = 0;
      do
      {
        v58 = com_token[v57];
        var.m_pName[v57++] = v58;
      }
      while ( v58 != 0 );
    }
    return 1;
  }
  v51 = CClass::AddMember(this: v63, name: var.m_pName);
  if ( v51 == nullptr )
    return 1;
  p_var = &var;
  do
  {
    v53 = p_var->m_pType[0];
    p_var->m_pType[(char *)v51 - (char *)&var + 128] = p_var->m_pType[0];
    p_var = (CClass::MemberVarParse_t *)((char *)p_var + 1);
  }
  while ( v53 != 0 );
  v51->m_Type = protection;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004053D0
// Name: public: char __near * CClass::ParseClassDeclaration(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CClass::ParseClassDeclaration(CClass *this, char *input)
{
  int v3; // edi
  char *result; // eax
  char v5; // dl
  int protection; // [esp+10h] [ebp-4h] BYREF

  v3 = 1;
  protection = 2;
  while ( 1 )
  {
    result = CC_ParseToken(data: input);
    input = result;
    if ( &com_token[strlen(com_token) + 1] == &byte_425011 )
      return result;
    if ( byte_425011 == v5 )
    {
      if ( com_token[0] == 123 )
      {
        ++v3;
      }
      else if ( com_token[0] == 125 )
      {
        --v3;
      }
    }
    if ( CClass::ParseProtection(this, &input, &protection) != 0 || _V_stricmp(s1: com_token, s2: ";") == 0 )
      goto LABEL_12;
    if ( com_token[0] == 35 )
    {
      input = CC_ParseUntilEndOfLine(input);
LABEL_12:
      if ( v3 == 0 )
        return input;
    }
    else
    {
      if ( CClass::ParseNestedClass(this, &input) != 0 || v3 != 1 )
        goto LABEL_12;
      if ( CClass::ParseBaseClass(this, &input) == 0 )
        CClass::ParseClassMember(this, &input, (CClassVariable::VARTYPE)protection);
    }
  }
}
