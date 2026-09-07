// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/proxyhealth.cpp
// Functions: 3
// ============================================================

#include "game\client\proxyhealth.h"

//------------------------------------------------------------------------------
// Address: 0x101195E0
// Name: public: virtual bool CProxyHealth::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CProxyHealth::Init(CProxyIsNPC *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  char result; // al

  result = CResultProxy::Init(this, pMaterial, pKeyValues);
  if ( result != 0 )
    return CFloatInput::Init(this: &this->m_Factor, pMaterial, pKeyValues, pKeyName: "scale", flDefault: 1.0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101588C0
// Name: public: virtual void CProxyHealth::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProxyHealth::OnBind(CProxyHealth *this, int (__thiscall ***pC_BaseEntity)(_DWORD))
{
  C_BaseEntity *v3; // edi
  int result; // [esp+0h] [ebp-Ch]
  float pC_BaseEntitya; // [esp+14h] [ebp+8h]

  if ( pC_BaseEntity != nullptr )
  {
    v3 = CResultProxy::BindArgToEntity(this, pArg: pC_BaseEntity);
    pC_BaseEntitya = CFloatInput::GetFloat(this: &this->m_Factor);
    *(float *)&result = C_BaseEntity::HealthFraction(this: v3) * pC_BaseEntitya;
    CResultProxy::SetFloatResult(this, result);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158900
// Name: CCProxyHealthFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCProxyHealthFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x18u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CProxyHealth::`vftable';
  return (IMaterialProxy *)v1;
}
