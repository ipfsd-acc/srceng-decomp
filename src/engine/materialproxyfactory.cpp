// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/materialproxyfactory.cpp
// Functions: 3
// ============================================================

#include "engine\materialproxyfactory.h"

//------------------------------------------------------------------------------
// Address: 0x101A4470
// Name: public: virtual class IMaterialProxy __near * CMaterialProxyFactory::CreateProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CMaterialProxyFactory::CreateProxy(CMaterialProxyFactory *this, const char *proxyName)
{
  IMaterialProxy *v2; // esi

  v2 = g_ClientDLL->InstantiateMaterialProxy(this: g_ClientDLL, a2: proxyName);
  if ( toolframework->InToolMode(this: toolframework) )
  {
    if ( v2 != nullptr )
      return v2;
    v2 = toolframework->LookupProxy(this: toolframework, a2: proxyName);
  }
  if ( v2 == nullptr && !sv.m_bIsDedicated )
  {
    _ConDMsg(a1: "Can't find material proxy \"%s\"\n", proxyName);
    return nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101A44F0
// Name: public: virtual void CMaterialProxyFactory::DeleteProxy(class IMaterialProxy __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialProxyFactory::DeleteProxy(CMaterialProxyFactory *this, IMaterialProxy *pProxy)
{
  if ( pProxy != nullptr )
    pProxy->Release(this: pProxy);
}

//------------------------------------------------------------------------------
// Address: 0x101A4510
// Name: public: virtual void __near * (*CMaterialProxyFactory::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CMaterialProxyFactory::GetFactory(CMaterialProxyFactory *this))(const char *, int *)
{
  return Sys_GetFactory(pModule: g_ClientDLLModule);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A4880
// Name: public: virtual class IMaterialProxy __near * CMaterialProxyFactory::CreateProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CMaterialProxyFactory::CreateProxy(CMaterialProxyFactory *this, const char *proxyName)
{
  IMaterialProxy *v2; // esi

  v2 = g_ClientDLL->InstantiateMaterialProxy(this: g_ClientDLL, a2: proxyName);
  if ( toolframework->InToolMode(this: toolframework) )
  {
    if ( v2 != nullptr )
      return v2;
    v2 = toolframework->LookupProxy(this: toolframework, a2: proxyName);
  }
  if ( v2 == nullptr && !sv.m_bIsDedicated )
  {
    _ConDMsg(a1: "Can't find material proxy \"%s\"\n", proxyName);
    return nullptr;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101A4900
// Name: public: virtual void CMaterialProxyFactory::DeleteProxy(class IMaterialProxy __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialProxyFactory::DeleteProxy(CMaterialProxyFactory *this, IMaterialProxy *pProxy)
{
  if ( pProxy != nullptr )
    pProxy->Release(this: pProxy);
}

//------------------------------------------------------------------------------
// Address: 0x101A4920
// Name: public: virtual void __near * (*CMaterialProxyFactory::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CMaterialProxyFactory::GetFactory(CMaterialProxyFactory *this))(const char *, int *)
{
  return Sys_GetFactory(pModule: g_ClientDLLModule);
}

} // namespace engine_xlsp
