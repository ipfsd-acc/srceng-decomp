// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/convarproxy.cpp
// Functions: 5
// ============================================================

#include "game\client\convarproxy.h"

//------------------------------------------------------------------------------
// Address: 0x100C5330
// Name: public: virtual bool CConVarMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CConVarMaterialProxy::Init(CConVarMaterialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  const char *String; // esi
  IMaterialVar *v6; // eax
  bool v7; // zf
  const char *v8; // eax
  bool found; // [esp+Bh] [ebp-1h] BYREF

  String = KeyValues::GetString(this: pKeyValues, keyName: "resultVar", defaultValue: prType);
  if ( String == nullptr )
    return false;
  v6 = pMaterial->FindVar(this: pMaterial, a2: String, a3: &found, a4: 1);
  v7 = !found;
  this->m_pResult = v6;
  if ( v7 )
  {
    this->m_pResult = nullptr;
    return false;
  }
  if ( _V_stricmp(s1: String, s2: "$alpha") == 0 )
    pMaterial->SetMaterialVarFlag(this: pMaterial, a2: MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY, a3: true);
  v8 = KeyValues::GetString(this: pKeyValues, keyName: "convar", defaultValue: prType);
  if ( v8 == nullptr )
    return false;
  ConVarRef::Init(this: &this->m_conVarRef, pName: v8, bIgnoreMissing: false);
  return ConVarRef::IsValid(this: (SplitScreenConVarRef *)&this->m_conVarRef);
}

//------------------------------------------------------------------------------
// Address: 0x100C53F0
// Name: public: virtual void CConVarMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConVarMaterialProxy::OnBind(CConVarMaterialProxy *this, void *__formal)
{
  IMaterialVar *m_pResult; // ecx
  int v4; // eax
  Vector4D vec; // [esp+8h] [ebp-10h] BYREF

  m_pResult = this->m_pResult;
  if ( (*((_BYTE *)m_pResult + 28) & 0xF) == 2 )
  {
    vec.x = this->m_conVarRef.m_pConVarState->m_Value.m_fValue;
    vec.y = vec.x;
    vec.z = vec.x;
    vec.w = vec.x;
    v4 = m_pResult->VectorSizeInternal(this: m_pResult);
    this->m_pResult->SetVecValue_4(this: this->m_pResult, a2: (const float *)&vec, a3: v4);
  }
  else if ( (*((_BYTE *)m_pResult + 28) & 0xF) == 4 )
  {
    m_pResult->SetIntValue(this: m_pResult, a2: this->m_conVarRef.m_pConVarState->m_Value.m_nValue);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))m_pResult->SetFloatValue)(a1: LODWORD(this->m_conVarRef.m_pConVarState->m_Value.m_fValue));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5480
// Name: CCConVarMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
ConVarRef *__cdecl CCConVarMaterialProxyFactory()
{
  ConVarRef *v0; // esi
  ConVarRef *result; // eax

  v0 = (ConVarRef *)MemAlloc_Alloc(nSize: 0x10u);
  result = nullptr;
  if ( v0 != nullptr )
  {
    v0->m_pConVar = (IConVar *)&CConVarMaterialProxy::`vftable';
    v0->m_pConVarState = nullptr;
    ConVarRef::ConVarRef(this: v0 + 1, pName: prType, bIgnoreMissing: true);
    return v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D0930
// Name: public: virtual void CConVarMaterialProxy::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConVarMaterialProxy::Release(CBaseAnimatedTextureProxy *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CBaseAnimatedTextureProxy *, int))this->dtr_IMaterialProxy)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10158AE0
// Name: public: virtual class IMaterial __near * CConVarMaterialProxy::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CConVarMaterialProxy::GetMaterial(CBaseAnimatedTextureProxy *this)
{
  return this->m_AnimatedTextureVar->GetOwningMaterial(this: this->m_AnimatedTextureVar);
}
