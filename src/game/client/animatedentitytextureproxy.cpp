// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/animatedentitytextureproxy.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10008BA0
// Name: CCAnimatedEntityTextureProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCAnimatedEntityTextureProxyFactory()
{
  CBaseAnimatedTextureProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CBaseAnimatedTextureProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(this: v0);
  *v1 = &CAnimatedEntityTextureProxy::`vftable';
  return (IMaterialProxy *)v1;
}
