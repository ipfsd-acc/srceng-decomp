// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/player_pickup.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1014D170
// Name: class Vector Pickup_DefaultPhysGunLaunchVelocity(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl Pickup_DefaultPhysGunLaunchVelocity(Vector *result, const Vector *vecForward, float flMass)
{
  result->x = vecForward->x * flMass;
  result->y = vecForward->y * flMass;
  result->z = vecForward->z * flMass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102A55B0
// Name: void Pickup_ForcePlayerToDropThisObject(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Pickup_ForcePlayerToDropThisObject()
{
  _Warning(a1: "Failing to force player to drop object.\n");
}

//------------------------------------------------------------------------------
// Address: 0x102A55C0
// Name: class Vector Pickup_DefaultPhysGunLaunchVelocity(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl Pickup_DefaultPhysGunLaunchVelocity(Vector *result, const Vector *vecForward, float flMass)
{
  result->x = vecForward->x * flMass;
  result->y = vecForward->y * flMass;
  result->z = vecForward->z * flMass;
  return result;
}

} // namespace server
