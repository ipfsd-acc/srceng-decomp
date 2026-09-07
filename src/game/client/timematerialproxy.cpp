// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/timematerialproxy.cpp
// Functions: 2
// ============================================================

#include "game\client\timematerialproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1017A390
// Name: public: virtual void CTimeMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTimeMaterialProxy::OnBind(CTimeMaterialProxy *this, void *pC_BaseEntity)
{
  CResultProxy::SetFloatResult(this, result: *(_DWORD *)(gpGlobals.m_Index + 12));
}

//------------------------------------------------------------------------------
// Address: 0x1017A3B0
// Name: CCTimeMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCTimeMaterialProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0xCu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CTimeMaterialProxy::`vftable';
  return (IMaterialProxy *)v1;
}
