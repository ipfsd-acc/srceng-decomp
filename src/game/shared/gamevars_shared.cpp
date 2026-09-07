// Original: game/shared/gamevars_shared.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "game\shared\gamevars_shared.h"

// Stub: dynamic initializer for 'mp_forcecamera''
void dynamic initializer for 'mp_forcecamera''() {}

// Stub: dynamic initializer for 'mp_allowspectators''
void dynamic initializer for 'mp_allowspectators''() {}

// Stub: dynamic initializer for 'friendlyfire''
void dynamic initializer for 'friendlyfire''() {}

// Stub: dynamic initializer for 'mp_fadetoblack''
void dynamic initializer for 'mp_fadetoblack''() {}

// Stub: dynamic atexit destructor for 'mp_forcecamera''
void dynamic atexit destructor for 'mp_forcecamera''() {}

// Stub: dynamic atexit destructor for 'mp_allowspectators''
void dynamic atexit destructor for 'mp_allowspectators''() {}

// Stub: dynamic atexit destructor for 'friendlyfire''
void dynamic atexit destructor for 'friendlyfire''() {}

// Stub: dynamic atexit destructor for 'mp_fadetoblack''
void dynamic atexit destructor for 'mp_fadetoblack''() {}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10152960
// Name: void MPForceCameraCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl MPForceCameraCallback()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  CGameTrace *v1; // [esp-4h] [ebp-4h]

  if ( mp_forcecamera.m_pParent != nullptr && mp_forcecamera.m_pParent->m_Value.m_nValue > 2u )
    CCollisionProperty::TestCollision(this: (ConVar *)&mp_forcecamera.IConVar, value: 1, fContentsMask: v0, tr: v1);
}

} // namespace server
