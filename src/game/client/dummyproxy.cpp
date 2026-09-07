// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/dummyproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\dummyproxy.h"

//------------------------------------------------------------------------------
// Address: 0x100D08E0
// Name: public: virtual bool CDummyMaterialProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDummyMaterialProxy::Init(CDummyMaterialProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  pMaterial->GetName(this: pMaterial);
  _DevMsg(a1: 1, a2: "CDummyMaterialProxy::Init( material = \"%s\" )\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D0910
// Name: public: virtual void CDummyMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialProxy::OnBind(CDummyMaterialProxy *this, void *pC_BaseEntity)
{
  _DevMsg(a1: 1, a2: "CDummyMaterialProxy::OnBind( %p )\n");
}

//------------------------------------------------------------------------------
// Address: 0x100D0940
// Name: CCDummyMaterialProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCDummyMaterialProxyFactory()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi

  v0 = MemAlloc_Alloc(nSize: 4u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *v0 = &CDummyMaterialProxy::`vftable';
  _DevMsg(a1: 1, a2: "CDummyMaterialProxy::CDummyMaterialProxy()\n");
  return (IMaterialProxy *)v1;
}
