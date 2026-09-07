// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/randoverride.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101CE4A0
// Name: _rand
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall rand(IUniformRandomStream *this)
{
  return _RandomInt(this, a2: 0, a3: 0x7FFF);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CE880
// Name: _rand
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall rand(IUniformRandomStream *this)
{
  return _RandomInt(this, a2: 0, a3: 0x7FFF);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10163AB0
// Name: _rand
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall rand(IUniformRandomStream *this)
{
  return _RandomInt(this, a2: 0, a3: 0x7FFF);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101F45B0
// Name: _rand
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall rand(IUniformRandomStream *this)
{
  return _RandomInt(this, a2: 0, a3: 0x7FFF);
}

} // namespace server
