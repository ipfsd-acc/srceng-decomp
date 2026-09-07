// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/proxyentity.cpp
// Functions: 1
// ============================================================

#include "game\client\proxyentity.h"

//------------------------------------------------------------------------------
// Address: 0x10158890
// Name: public: virtual void CEntityMaterialProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityMaterialProxy::OnBind(CEntityMaterialProxy *this, int (__thiscall ***pRenderable)(_DWORD))
{
  int v3; // eax
  C_BaseEntity *v4; // eax

  if ( pRenderable != nullptr )
  {
    v3 = (**pRenderable)(a1: pRenderable);
    v4 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 28))(a1: v3);
    if ( v4 != nullptr )
      this->OnBind_2(this, a2: v4);
  }
}
