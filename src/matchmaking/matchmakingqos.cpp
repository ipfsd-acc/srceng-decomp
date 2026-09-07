// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/matchmakingqos.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100045B0
// Name: struct MM_QOS_t MM_GetQos(void)
// Source: json
//------------------------------------------------------------------------------
MM_QOS_t *__cdecl MM_GetQos(MM_QOS_t *result)
{
  *result = s_DefaultQos.MM_QOS_t;
  return result;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x100289C0
// Name: struct MM_QOS_t MM_GetQos(void)
// Source: json
//------------------------------------------------------------------------------
MM_QOS_t *__cdecl MM_GetQos(MM_QOS_t *result)
{
  *result = s_DefaultQos.MM_QOS_t;
  return result;
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10008490
// Name: struct MM_QOS_t MM_GetQos(void)
// Source: json
//------------------------------------------------------------------------------
MM_QOS_t *__cdecl MM_GetQos(MM_QOS_t *result)
{
  *result = s_DefaultQos.MM_QOS_t;
  return result;
}

} // namespace matchmaking_ds
