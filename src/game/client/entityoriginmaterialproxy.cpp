// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/entityoriginmaterialproxy.cpp
// Functions: 8
// ============================================================

#include "game\client\entityoriginmaterialproxy.h"

//------------------------------------------------------------------------------
// Address: 0x100D1630
// Name: public: virtual void CEntityOriginAlyxMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityOriginAlyxMaterialProxy::OnBind(
        CEntityOriginAlyxMaterialProxy *this,
        C_BaseEntity *pC_BaseEntity)
{
  const Vector *v3; // eax

  v3 = pC_BaseEntity->GetAbsOrigin(this: pC_BaseEntity);
  ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD))this->m_pOriginVar->SetVecValue_2)(
    a1: this->m_pOriginVar,
    a2: v3->x - 15.0,
    a3: LODWORD(v3->y),
    a4: LODWORD(v3->z));
}

//------------------------------------------------------------------------------
// Address: 0x100D1680
// Name: CCEntityOriginAlyxMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEntityOriginAlyxMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CEntityOriginAlyxMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D16A0
// Name: public: virtual bool CEp1IntroVortRefractMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEp1IntroVortRefractMaterialProxy::Init(
        CEp1IntroVortRefractMaterialProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  IMaterial *v4; // ecx
  IMaterialVar *v5; // eax
  bool v6; // zf

  v4 = pMaterial;
  this->m_pMaterial = pMaterial;
  v5 = v4->FindVar(this: v4, a2: "$refractamount", a3: (bool *)&pMaterial + 3, a4: true);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_pOriginVar = v5;
  if ( !v6 )
    return 1;
  this->m_pOriginVar = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D16E0
// Name: public: virtual void CEp1IntroVortRefractMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEp1IntroVortRefractMaterialProxy::OnBind(
        CEp1IntroVortRefractMaterialProxy *this,
        C_BaseEntity *pC_BaseEntity)
{
  IMaterialVar *m_pOriginVar; // ecx
  float flTmp; // [esp+8h] [ebp-4h]

  m_pOriginVar = this->m_pOriginVar;
  if ( m_pOriginVar != nullptr )
  {
    flTmp = 1.0 - ((double (__thiscall *)(IMaterialVar *))m_pOriginVar->GetFloatValueInternal)(a1: m_pOriginVar);
    ((void (__stdcall *)(_DWORD))this->m_pOriginVar->SetFloatValue)(a1: (float)(1.0
                                                                              - (float)((float)(flTmp * flTmp)
                                                                                      * (float)(flTmp * flTmp))) * 0.25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1740
// Name: CCEp1IntroVortRefractMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEp1IntroVortRefractMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CEp1IntroVortRefractMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D1760
// Name: public: virtual bool CEntityOriginMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityOriginMaterialProxy::Init(
        CEntityOriginMaterialProxy *this,
        IMaterial *pMaterial,
        KeyValues *pKeyValues)
{
  IMaterial *v4; // ecx
  IMaterialVar *v5; // eax
  bool v6; // zf

  v4 = pMaterial;
  this->m_pMaterial = pMaterial;
  v5 = v4->FindVar(this: v4, a2: "$entityorigin", a3: (bool *)&pMaterial + 3, a4: true);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_pOriginVar = v5;
  if ( !v6 )
    return 1;
  this->m_pOriginVar = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D17A0
// Name: public: virtual void CEntityOriginMaterialProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityOriginMaterialProxy::OnBind(CEntityOriginMaterialProxy *this, C_BaseEntity *pC_BaseEntity)
{
  const Vector *v3; // eax

  v3 = pC_BaseEntity->GetAbsOrigin(this: pC_BaseEntity);
  ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD))this->m_pOriginVar->SetVecValue_2)(
    a1: this->m_pOriginVar,
    a2: LODWORD(v3->x),
    a3: LODWORD(v3->y),
    a4: LODWORD(v3->z));
}

//------------------------------------------------------------------------------
// Address: 0x100D17F0
// Name: CCEntityOriginMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCEntityOriginMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CEntityOriginMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  return result;
}
