// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/waterlodmaterialproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\waterlodmaterialproxy.h"

//------------------------------------------------------------------------------
// Address: 0x101AB800
// Name: public: virtual bool CWaterLODMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWaterLODMaterialProxy::Init(CWaterLODMaterialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  IMaterial *v3; // esi
  IMaterialVar *v5; // eax
  bool v6; // zf
  IMaterialVar *v8; // eax

  v3 = pMaterial;
  v5 = pMaterial->FindVar(this: pMaterial, a2: "$CHEAPWATERSTARTDISTANCE", a3: (char *)&pMaterial + 3, a4: 0);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_pCheapWaterStartDistanceVar = v5;
  if ( v6 )
    return false;
  v8 = v3->FindVar(this: v3, a2: "$CHEAPWATERENDDISTANCE", a3: (bool *)&pMaterial + 3, a4: false);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_pCheapWaterEndDistanceVar = v8;
  return !v6;
}

//------------------------------------------------------------------------------
// Address: 0x101AB860
// Name: public: virtual void CWaterLODMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaterLODMaterialProxy::OnBind(CWaterLODMaterialProxy *this, void *pC_BaseEntity)
{
  int end; // [esp+14h] [ebp-8h] BYREF
  int start; // [esp+18h] [ebp-4h] BYREF

  if ( this->m_pCheapWaterStartDistanceVar != nullptr && this->m_pCheapWaterEndDistanceVar != nullptr )
  {
    view->GetWaterLODParams(this: view, a2: (float *)&start, a3: (float *)&end);
    ((void (__stdcall *)(int))this->m_pCheapWaterStartDistanceVar->SetFloatValue)(a1: start);
    ((void (__stdcall *)(int))this->m_pCheapWaterEndDistanceVar->SetFloatValue)(a1: end);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB8C0
// Name: CCWaterLODMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCWaterLODMaterialProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CWaterLODMaterialProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  return result;
}
