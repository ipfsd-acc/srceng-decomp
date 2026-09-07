// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/functionproxy.cpp
// Functions: 10
// ============================================================

#include "game\client\functionproxy.h"

//------------------------------------------------------------------------------
// Address: 0x100D5BF0
// Name: public: bool CFloatInput::Init(class IMaterial __near *,class KeyValues __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFloatInput::Init(
        CFloatInput *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues,
        const char *pKeyName,
        float flDefault)
{
  KeyValues *v6; // ecx
  KeyValues *Key; // eax
  KeyValues *v8; // esi
  char *String; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  IMaterialVar *v13; // eax
  bool v14; // zf
  const char *v16; // [esp-4h] [ebp-110h]
  char pTemp[256]; // [esp+Ch] [ebp-100h] BYREF

  v6 = pKeyValues;
  v16 = pKeyName;
  this->m_pFloatVar = nullptr;
  Key = KeyValues::FindKey(this: v6, keyName: v16, bCreate: false);
  v8 = Key;
  if ( Key == nullptr )
  {
    this->m_flValue = flDefault;
    goto LABEL_12;
  }
  if ( KeyValues::GetDataType(this: Key, keyName: nullptr) != 1 )
  {
    this->m_flValue = KeyValues::GetFloat(this: v8, keyName: nullptr, defaultValue: 0.0);
    LOBYTE(v10) = 1;
    return v10;
  }
  String = (char *)KeyValues::GetString(this: v8, keyName: nullptr, defaultValue: prType);
  v10 = sscanf(string: String, format: "%f", &pKeyValues);
  if ( v10 != 1 )
  {
    strchr(string: String, chr: 0x5Bu);
    if ( v11 != 0 )
    {
      V_strncpy(pDest: pTemp, pSrc: String, maxLen: 256);
      strchr(string: pTemp, chr: 0x5Bu);
      *(_BYTE *)v12 = 0;
      this->m_FloatVecComp = strtol(nptr: (const char *)(v12 + 1), endptr: (char **)&flDefault, ibase: 0xAu);
      String = pTemp;
    }
    else
    {
      this->m_FloatVecComp = -1;
    }
    v13 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyName + 3, a4: 1);
    v14 = HIBYTE(pKeyName) == 0;
    this->m_pFloatVar = v13;
    if ( v14 )
    {
      LOBYTE(v10) = 0;
      return v10;
    }
LABEL_12:
    LOBYTE(v10) = 1;
    return v10;
  }
  LODWORD(this->m_flValue) = pKeyValues;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100D5D20
// Name: public: float CFloatInput::GetFloat(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFloatInput::GetFloat(CFloatInput *this)
{
  IMaterialVar *m_pFloatVar; // ecx
  IMaterialVar_vtbl *v4; // eax
  int v5; // eax
  float v[4]; // [esp+4h] [ebp-10h] BYREF

  m_pFloatVar = this->m_pFloatVar;
  if ( m_pFloatVar == nullptr )
    return this->m_flValue;
  v4 = m_pFloatVar->__vftable;
  if ( this->m_FloatVecComp < 0 )
    return ((float (*)(void))v4->GetFloatValueInternal)();
  v5 = ((int (*)(void))v4->VectorSizeInternal)();
  if ( this->m_FloatVecComp >= v5 )
    return 0.0;
  this->m_pFloatVar->GetVecValueInternal(this: this->m_pFloatVar, a2: v, a3: v5);
  return v[this->m_FloatVecComp];
}

//------------------------------------------------------------------------------
// Address: 0x100D5D80
// Name: public: virtual bool CResultProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResultProxy::Init(CResultProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  char *String; // eax
  char *v5; // esi
  int v7; // eax
  int v8; // eax
  IMaterialVar *v9; // eax
  bool v10; // zf
  char pTemp[256]; // [esp+8h] [ebp-104h] BYREF
  char *pIEnd; // [esp+108h] [ebp-4h] BYREF

  String = (char *)KeyValues::GetString(this: pKeyValues, keyName: "resultVar", defaultValue: prType);
  v5 = String;
  if ( String == nullptr )
    return 0;
  strchr(string: String, chr: 0x5Bu);
  if ( v7 != 0 )
  {
    V_strncpy(pDest: pTemp, pSrc: v5, maxLen: 256);
    strchr(string: pTemp, chr: 0x5Bu);
    *(_BYTE *)v8 = 0;
    this->m_ResultVecComp = strtol(nptr: (const char *)(v8 + 1), endptr: &pIEnd, ibase: 0xAu);
    v5 = pTemp;
  }
  else
  {
    this->m_ResultVecComp = -1;
  }
  v9 = pMaterial->FindVar(this: pMaterial, a2: v5, a3: (char *)&pKeyValues + 3, a4: 1);
  v10 = HIBYTE(pKeyValues) == 0;
  this->m_pResult = v9;
  if ( v10 )
    return 0;
  if ( _V_stricmp(s1: v5, s2: "$alpha") == 0 )
    pMaterial->SetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY, a3: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5E60
// Name: protected: void CResultProxy::SetFloatResult(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResultProxy::SetFloatResult(CResultProxy *this, int result)
{
  IMaterialVar *m_pResult; // ecx
  IMaterialVar_vtbl *v4; // edx
  int v5; // edx
  float v[4]; // [esp+Ch] [ebp-10h] BYREF

  m_pResult = this->m_pResult;
  v4 = m_pResult->__vftable;
  if ( (*((_BYTE *)m_pResult + 28) & 0xF) == 2 )
  {
    if ( this->m_ResultVecComp < 0 )
    {
      v5 = ((int (*)(void))v4->VectorSizeInternal)();
      if ( v5 > 0 )
        memset32(v, result, v5);
      this->m_pResult->SetVecValue_4(this: this->m_pResult, a2: v, a3: v5);
    }
    else
    {
      ((void (__stdcall *)(int, int))v4->SetVecComponentValue)(a1: result, a2: this->m_ResultVecComp);
    }
  }
  else
  {
    ((void (__stdcall *)(int))v4->SetFloatValue)(a1: result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5EE0
// Name: protected: class C_BaseEntity __near * CResultProxy::BindArgToEntity(void __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CResultProxy::BindArgToEntity(CResultProxy *this, int (__thiscall ***pArg)(_DWORD))
{
  int v2; // eax

  v2 = (**pArg)(a1: pArg);
  return (*(C_BaseEntity *(__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100D5F00
// Name: public: virtual bool CFunctionProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFunctionProxy::Init(CFunctionProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  const char *String; // eax
  IMaterialVar *v6; // eax
  bool v7; // zf
  const char *v8; // eax
  IMaterialVar *v9; // eax

  v3 = pKeyValues;
  if ( CResultProxy::Init(this, pMaterial, pKeyValues) == 0 )
    return 0;
  String = KeyValues::GetString(this: v3, keyName: "srcVar1", defaultValue: prType);
  if ( String == nullptr )
    return 0;
  v6 = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 1);
  v7 = HIBYTE(pKeyValues) == 0;
  this->m_pSrc1 = v6;
  if ( v7 )
    return 0;
  v8 = KeyValues::GetString(this: v3, keyName: "srcVar2", defaultValue: prType);
  if ( v8 != nullptr && *v8 != 0 )
  {
    v9 = pMaterial->FindVar(this: pMaterial, a2: v8, a3: (char *)&pKeyValues + 3, a4: 1);
    v7 = HIBYTE(pKeyValues) == 0;
    this->m_pSrc2 = v9;
    if ( v7 )
      return 0;
  }
  else
  {
    this->m_pSrc2 = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D5FA0
// Name: protected: void CFunctionProxy::ComputeResultType(enum MaterialVarType_t __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctionProxy::ComputeResultType(CFunctionProxy *this, MaterialVarType_t *resultType, int *vecSize)
{
  MaterialVarType_t v3; // eax
  MaterialVarType_t v4; // eax
  IMaterialVar *m_pSrc2; // eax
  MaterialVarType_t v6; // eax

  v3 = *((_BYTE *)this->m_pResult + 28) & 0xF;
  *resultType = v3;
  if ( v3 == MATERIAL_VAR_TYPE_VECTOR )
  {
    if ( this->m_ResultVecComp >= 0 )
      *resultType = MATERIAL_VAR_TYPE_FLOAT;
    *vecSize = this->m_pResult->VectorSizeInternal(this: this->m_pResult);
  }
  else if ( v3 == MATERIAL_VAR_TYPE_UNDEFINED )
  {
    v4 = *((_BYTE *)this->m_pSrc1 + 28) & 0xF;
    *resultType = v4;
    if ( v4 == MATERIAL_VAR_TYPE_VECTOR )
    {
      *vecSize = this->m_pSrc1->VectorSizeInternal(this: this->m_pSrc1);
    }
    else if ( v4 == MATERIAL_VAR_TYPE_UNDEFINED )
    {
      m_pSrc2 = this->m_pSrc2;
      if ( m_pSrc2 != nullptr )
      {
        v6 = *((_BYTE *)m_pSrc2 + 28) & 0xF;
        *resultType = v6;
        if ( v6 == MATERIAL_VAR_TYPE_VECTOR )
          *vecSize = this->m_pSrc2->VectorSizeInternal(this: this->m_pSrc2);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6030
// Name: public: CResultProxy::CResultProxy(void)
// Source: json
//------------------------------------------------------------------------------
CResultProxy *__thiscall CResultProxy::CResultProxy(CResultProxy *this)
{
  this->__vftable = (CResultProxy_vtbl *)&CResultProxy::`vftable';
  this->m_pResult = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D6040
// Name: public: CFunctionProxy::CFunctionProxy(void)
// Source: json
//------------------------------------------------------------------------------
CFunctionProxy *__thiscall CFunctionProxy::CFunctionProxy(CFunctionProxy *this)
{
  this->m_pResult = nullptr;
  this->__vftable = (CFunctionProxy_vtbl *)&CFunctionProxy::`vftable';
  this->m_pSrc1 = nullptr;
  this->m_pSrc2 = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D6060
// Name: public: virtual CResultProxy::~CResultProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResultProxy::~CResultProxy(IMaterialProxy *this)
{
  this->__vftable = (IMaterialProxy_vtbl *)&IMaterialProxy::`vftable';
}
