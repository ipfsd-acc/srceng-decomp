// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/animatedtextureproxy.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10008CA0
// Name: CCAnimatedTextureProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCAnimatedTextureProxyFactory()
{
  CBaseAnimatedTextureProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CBaseAnimatedTextureProxy *)MemAlloc_Alloc(nSize: 0x14u);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CBaseAnimatedTextureProxy::CBaseAnimatedTextureProxy(this: v0);
  *v1 = &CAnimatedTextureProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1042D390
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x10437030
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x1042D3C0
// Name: _dynamic_initializer_for__g_CheckNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckEventNames *dynamic_initializer_for__g_CheckNamesSingleton__()
{
  return CCheckEventNames::CCheckEventNames(this: &g_CheckNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x1042D3D0
// Name: _dynamic_initializer_for__g_CheckCCNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckCCNames *dynamic_initializer_for__g_CheckCCNamesSingleton__()
{
  return CCheckCCNames::CCheckCCNames(this: &g_CheckCCNamesSingleton);
}
