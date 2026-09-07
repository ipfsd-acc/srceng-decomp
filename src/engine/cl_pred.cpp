// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_pred.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1008EAF0
// Name: void CL_RunPrediction(enum PREDICTION_REASON)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RunPrediction()
{
  CClientState *BaseLocalClient; // eax
  int *v1; // esi

  BaseLocalClient = GetBaseLocalClient();
  v1 = (int *)BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState == 6
    && BaseLocalClient->m_nDeltaTick >= 0
    && !demoplayer->IsSkipping(this: demoplayer) )
  {
    g_pClientSidePrediction->Update(
      this: g_pClientSidePrediction,
      a2: v1[51],
      a3: v1[51] > 0,
      a4: v1[4755],
      a5: v1[4753] + v1[4754]);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1008E7A0
// Name: void CL_RunPrediction(enum PREDICTION_REASON)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RunPrediction()
{
  CClientState *BaseLocalClient; // eax
  int *v1; // esi

  BaseLocalClient = GetBaseLocalClient();
  v1 = (int *)BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState == 6
    && BaseLocalClient->m_nDeltaTick >= 0
    && !demoplayer->IsSkipping(this: demoplayer) )
  {
    g_pClientSidePrediction->Update(
      this: g_pClientSidePrediction,
      a2: v1[51],
      a3: v1[51] > 0,
      a4: v1[4755],
      a5: v1[4753] + v1[4754]);
  }
}

} // namespace engine_xlsp
