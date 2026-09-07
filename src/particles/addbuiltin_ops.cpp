// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: particles/addbuiltin_ops.cpp
// Functions: 2
// ============================================================

#include "particles\addbuiltin_ops.h"

//------------------------------------------------------------------------------
// Address: 0x10216EE0
// Name: public: void CParticleSystemMgr::AddBuiltinSimulationOperators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemMgr::AddBuiltinSimulationOperators(CParticleSystemMgr *this)
{
  if ( !s_DidAddSim )
  {
    s_DidAddSim = true;
    AddBuiltInParticleOperators();
    AddBuiltInParticleInitializers();
    AddBuiltInParticleEmitters();
    AddBuiltInParticleForceGenerators();
    AddBuiltInParticleConstraints();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216F10
// Name: public: void CParticleSystemMgr::AddBuiltinRenderingOperators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemMgr::AddBuiltinRenderingOperators(CParticleSystemMgr *this)
{
  if ( !s_DidAddRenderers )
  {
    s_DidAddRenderers = true;
    AddBuiltInParticleRenderers();
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102D9990
// Name: public: void CParticleSystemMgr::AddBuiltinSimulationOperators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemMgr::AddBuiltinSimulationOperators(CParticleSystemMgr *this)
{
  if ( !s_DidAddSim )
  {
    s_DidAddSim = true;
    AddBuiltInParticleOperators();
    AddBuiltInParticleInitializers();
    AddBuiltInParticleEmitters();
    AddBuiltInParticleForceGenerators();
    AddBuiltInParticleConstraints();
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D99C0
// Name: public: void CParticleSystemMgr::AddBuiltinRenderingOperators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystemMgr::AddBuiltinRenderingOperators(CParticleSystemMgr *this)
{
  if ( !s_DidAddRenderers )
  {
    s_DidAddRenderers = true;
    AddBuiltInParticleRenderers();
  }
}

} // namespace client
