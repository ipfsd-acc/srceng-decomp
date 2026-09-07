// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gsystem.cpp
// Functions: 2
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gsystem.h"

//------------------------------------------------------------------------------
// Address: 0x1006A470
// Name: public: static void GSystem::Init(struct GMemoryHeap::HeapDesc const __near &,class GSysAllocBase __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GSystem::Init(
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),CFuncMemPolicyNone> *psysAlloc,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),CFuncMemPolicyNone> *a2)
{
  if ( GSystem_pSysAlloc == nullptr )
  {
    (*(void (__thiscall **)(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),CFuncMemPolicyNone> *, const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),CFuncMemPolicyNone> *))(LODWORD(a2->m_pfnProxied) + 4))(
      a1: a2,
      a2: psysAlloc);
    GSystem_pSysAlloc = a2;
    GFxAmpServer::Init(a1: 0, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A4B0
// Name: public: static void GSystem::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GSystem::Destroy(void *this)
{
  int (__cdecl *v1)(const CMaterialSystem::COnLevelShutdownFunc *, const CMaterialSystem::COnLevelShutdownFunc *); // ecx
  void *result; // eax

  if ( GSystem_pSysAlloc != nullptr )
  {
    GFxAmpServer::Uninit();
    GThread::FinishAllThreads(a1: v1);
    result = (void *)(*(int (__thiscall **)(const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialHeightClipMode_t),CFuncMemPolicyNone> *))(LODWORD(GSystem_pSysAlloc->m_pfnProxied) + 8))(a1: GSystem_pSysAlloc);
    GSystem_pSysAlloc = nullptr;
  }
  return result;
}
