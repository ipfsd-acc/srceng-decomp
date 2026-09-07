// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/cs_prediction.cpp
// Functions: 3
// ============================================================

#include "game\client\cstrike15\cs_prediction.h"

//------------------------------------------------------------------------------
// Address: 0x101C9AE0
// Name: public: virtual void CCSPrediction::SetupMove(class C_BasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPrediction::SetupMove(
        CCSPrediction *this,
        C_BasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *pHelper,
        CMoveData *move)
{
  player->AvoidPhysicsProps(this: player, a2: ucmd);
  CPrediction::SetupMove(this, player, ucmd, pHelper, move);
}

//------------------------------------------------------------------------------
// Address: 0x101C9B20
// Name: public: virtual void CCSPrediction::FinishMove(class C_BasePlayer __near *,class CUserCmd __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPrediction::FinishMove(CCSPrediction *this, C_BasePlayer *player, CUserCmd *ucmd, CMoveData *move)
{
  CPrediction::FinishMove(this, player, ucmd, move);
}

//------------------------------------------------------------------------------
// Address: 0x101C9B60
// Name: __CreateCCSPredictionIPrediction_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCSPrediction *__cdecl _CreateCCSPredictionIPrediction_interface()
{
  return &g_Prediction;
}
