// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/lamphaloproxy.cpp
// Functions: 2
// ============================================================

#include "game\client\lamphaloproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1011C0D0
// Name: public: virtual void CLampHaloProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLampHaloProxy::OnBind(CLampHaloProxy *this, C_BaseEntity *pEnt)
{
  const Vector *v3; // esi
  const Vector *v4; // eax
  float v5; // xmm0_4
  double v6; // xmm0_8
  Vector vecLocal; // [esp+8h] [ebp-Ch] BYREF

  if ( this->m_pFadeValue != nullptr )
  {
    v3 = CurrentViewOrigin();
    v4 = pEnt->GetAbsOrigin(this: pEnt);
    vecLocal.x = v4->x - v3->x;
    vecLocal.y = v4->y - v3->y;
    vecLocal.z = v4->z - v3->z;
    VectorNormalize(vec: &vecLocal);
    if ( COERCE_FLOAT(LODWORD(vecLocal.z) & _mask__AbsFloat_) >= 0.25 )
    {
      v6 = (float)(COERCE_FLOAT(LODWORD(vecLocal.z) & _mask__AbsFloat_) - 0.25) * 1.35;
      if ( v6 >= 1.0 )
        v6 = 1.0;
      v5 = v6;
    }
    else
    {
      v5 = 0.0;
    }
    ((void (__stdcall *)(_DWORD))this->m_pFadeValue->SetFloatValue)(a1: LODWORD(v5));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C190
// Name: CCLampHaloProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCLampHaloProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CLampHaloProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}
