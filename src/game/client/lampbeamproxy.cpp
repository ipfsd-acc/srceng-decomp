// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/lampbeamproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\lampbeamproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1011BFE0
// Name: public: virtual void CLampBeamProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLampBeamProxy::OnBind(CLampBeamProxy *this, C_BaseEntity *pEnt)
{
  const Vector *v3; // esi
  const Vector *v4; // eax
  Vector vecLocal; // [esp+Ch] [ebp-Ch] BYREF

  if ( this->m_pFadeValue != nullptr )
  {
    v3 = CurrentViewOrigin();
    v4 = pEnt->GetAbsOrigin(this: pEnt);
    vecLocal.x = v4->x - v3->x;
    vecLocal.y = v4->y - v3->y;
    vecLocal.z = v4->z - v3->z;
    VectorNormalize(vec: &vecLocal);
    ((void (__thiscall *)(IMaterialVar *, _DWORD))this->m_pFadeValue->SetFloatValue)(
      a1: this->m_pFadeValue,
      a2: 1.0 - COERCE_FLOAT(LODWORD(vecLocal.z) & _mask__AbsFloat_));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C070
// Name: CCLampBeamProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCLampBeamProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CLampBeamProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C090
// Name: public: virtual bool CLampBeamProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLampBeamProxy::Init(CLampBeamProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  IMaterial *v3; // esi

  v3 = pMaterial;
  this->m_pFadeValue = pMaterial->FindVar(this: pMaterial, a2: "$alpha", a3: (char *)&pMaterial + 3, a4: 1);
  v3->SetMaterialVarFlag(this: v3, a2: MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY, a3: true);
  return HIBYTE(pMaterial);
}
