// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/animatedoffsettextureproxy.cpp
// Functions: 3
// ============================================================

#include "game\client\animatedoffsettextureproxy.h"

//------------------------------------------------------------------------------
// Address: 0x10008C00
// Name: CCAnimatedOffsetTextureProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCAnimatedOffsetTextureProxyFactory()
{
  CBaseAnimatedTextureProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CBaseAnimatedTextureProxy *)MemAlloc_Alloc(nSize: 0x18u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(this: v0);
  *v1 = &CAnimatedOffsetTextureProxy::`vftable';
  v1[5] = 0;
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10008C30
// Name: public: virtual float CAnimatedOffsetTextureProxy::GetAnimationStartTime(void __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAnimatedOffsetTextureProxy::GetAnimationStartTime(CAnimatedOffsetTextureProxy *this, void *pArg)
{
  return this->m_flFrameOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10008C40
// Name: public: virtual void CAnimatedOffsetTextureProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimatedOffsetTextureProxy::OnBind(CAnimatedOffsetTextureProxy *this, void *pBaseEntity)
{
  if ( pBaseEntity != nullptr )
    this->m_flFrameOffset = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)pBaseEntity + 448))(a1: pBaseEntity);
  CBaseAnimatedTextureProxy::OnBind(this, pEntity: pBaseEntity);
}
