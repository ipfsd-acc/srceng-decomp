// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/game_timescale_shared.cpp
// Functions: 7
// ============================================================

#include "game\shared\game_timescale_shared.h"

//------------------------------------------------------------------------------
// Address: 0x100E00B0
// Name: private: void CGameTimescale::UpdateTimescale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameTimescale::UpdateTimescale(CGameTimescale *this)
{
  float *m_Index; // ecx
  float m_flDurationRealTimeSeconds; // xmm2_4
  float x; // xmm0_4
  long double v5; // st7
  unsigned int biasAmt; // xmm1_4
  float flInterpa; // [esp+Ch] [ebp-4h]
  float flInterp; // [esp+Ch] [ebp-4h]

  if ( !engine->IsPaused(this: engine) )
  {
    if ( this->m_flCurrentTimescale == this->m_flDesiredTimescale )
      goto LABEL_18;
    m_Index = (float *)gpGlobals.m_Index;
    if ( *(float *)(gpGlobals.m_Index + 12) < this->m_flStartBlendTime )
      goto LABEL_18;
    if ( this->m_flStartBlendRealtime == 0.0 )
    {
      this->m_flStartBlendRealtime = *(float *)gpGlobals.m_Index;
      m_Index = (float *)gpGlobals.m_Index;
    }
    m_flDurationRealTimeSeconds = this->m_flDurationRealTimeSeconds;
    x = 1.0;
    if ( m_flDurationRealTimeSeconds > 0.0 )
    {
      x = (float)(*m_Index - this->m_flStartBlendRealtime) / m_flDurationRealTimeSeconds;
      if ( x > 1.0 )
        x = 1.0;
    }
    switch ( this->m_nInterpolatorType )
    {
      case INTERPOLATOR_ACCEL:
        biasAmt = 1048576000;
        break;
      case INTERPOLATOR_DEACCEL:
        biasAmt = 1061158912;
        break;
      case INTERPOLATOR_EASE_IN_OUT:
        v5 = Gain(x, biasAmt: 0.75);
LABEL_16:
        flInterpa = v5;
        x = flInterpa;
        goto LABEL_17;
      default:
LABEL_17:
        this->m_flCurrentTimescale = (float)((float)(1.0 - x) * this->m_flStartTimescale)
                                   + (float)(this->m_flDesiredTimescale * x);
LABEL_18:
        flInterp = this->m_flCurrentTimescale;
        if ( flInterp != ((double (__thiscall *)(IVEngineClient *))engine->GetTimescale)(a1: engine) )
          ((void (__stdcall *)(_DWORD))engine->SetTimescale)(a1: LODWORD(flInterp));
        return;
    }
    v5 = Bias(x, biasAmt);
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0200
// Name: void SV_TimeScale(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_TimeScale(const CCommand *args)
{
  double v1; // st7
  float timeScale; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc == 2 )
  {
    v1 = V_atof(str: args->m_ppArgv[1]);
    timeScale = v1;
    if ( g_GameTimescale.m_flCurrentTimescale != v1
      || g_GameTimescale.m_flCurrentTimescale != ((double (__thiscall *)(IVEngineClient *))engine->GetTimescale)(a1: engine) )
    {
      g_GameTimescale.m_flDesiredTimescale = timeScale;
      g_GameTimescale.m_flCurrentTimescale = timeScale;
      g_GameTimescale.m_flDurationRealTimeSeconds = 0.0;
      g_GameTimescale.m_nInterpolatorType = INTERPOLATOR_LINEAR;
      g_GameTimescale.m_flStartBlendTime = 0.0;
      g_GameTimescale.m_flStartBlendRealtime = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E0290
// Name: public: virtual bool CGameTimescale::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameTimescale::Init(CGameTimescale *this)
{
  this->m_flDesiredTimescale = 1.0;
  this->m_flCurrentTimescale = 1.0;
  *(_QWORD *)&this->m_flDurationRealTimeSeconds = 0;
  this->m_flStartBlendTime = 0.0;
  this->m_flStartBlendRealtime = 0.0;
  ((void (__stdcall *)(int))engine->SetTimescale)(a1: 1065353216);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E02E0
// Name: public: virtual void CGameTimescale::Update(float)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CGameTimescale::Update(CGameTimescale *this, float frametime)
{
  CGameTimescale::UpdateTimescale(this);
}

//------------------------------------------------------------------------------
// Address: 0x100E02F0
// Name: public: virtual void CGameTimescale::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameTimescale::LevelShutdownPostEntity(CGameTimescale *this)
{
  this->m_flDesiredTimescale = 1.0;
  this->m_flCurrentTimescale = 1.0;
  *(_QWORD *)&this->m_flDurationRealTimeSeconds = 0;
  this->m_flStartBlendTime = 0.0;
  this->m_flStartBlendRealtime = 0.0;
  ((void (__stdcall *)(int))engine->SetTimescale)(a1: 1065353216);
}

//------------------------------------------------------------------------------
// Address: 0x100E0340
// Name: void __MsgFunc_CurrentTimescale(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_CurrentTimescale(bf_read *msg)
{
  int m_nBitsAvail; // esi
  unsigned int v3; // ecx
  const unsigned int *v4; // edx
  const unsigned int *v5; // esi
  const unsigned int *m_pDataIn; // ecx
  unsigned int m_nInBufWord; // edi
  int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  float v12; // xmm0_4
  float msga; // [esp+10h] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_nInBufWord = msg->m_nInBufWord;
    v8 = 32 - m_nBitsAvail;
    m_pBufferEnd = msg->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      msga = 0.0;
    }
    else
    {
      v10 = msg->m_nInBufWord;
      v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v8;
      LODWORD(msga) = v11 | m_nInBufWord;
      msg->m_nInBufWord = v10 >> v8;
    }
    goto LABEL_19;
  }
  v3 = msg->m_nInBufWord;
  msg->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v4 = msg->m_pDataIn;
    v5 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v4 == v5 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v4 + 1;
      msga = *(float *)&v3;
    }
    else
    {
      if ( v4 <= v5 )
      {
        msg->m_nInBufWord = *v4;
        msg->m_pDataIn = v4 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = *(float *)&v3;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msga = *(float *)&v3;
  }
LABEL_19:
  v12 = msga;
  if ( g_GameTimescale.m_flCurrentTimescale == msga )
  {
    if ( g_GameTimescale.m_flCurrentTimescale == ((double (__thiscall *)(IVEngineClient *))engine->GetTimescale)(a1: engine) )
      return;
    v12 = msga;
  }
  g_GameTimescale.m_flDesiredTimescale = v12;
  g_GameTimescale.m_flCurrentTimescale = v12;
  g_GameTimescale.m_flDurationRealTimeSeconds = 0.0;
  g_GameTimescale.m_nInterpolatorType = INTERPOLATOR_LINEAR;
  g_GameTimescale.m_flStartBlendTime = 0.0;
  g_GameTimescale.m_flStartBlendRealtime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100E04B0
// Name: void __MsgFunc_DesiredTimescale(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_DesiredTimescale(bf_read *msg)
{
  int m_nBitsAvail; // esi
  unsigned int v3; // ecx
  const unsigned int *v4; // edx
  const unsigned int *v5; // esi
  const unsigned int *m_pDataIn; // ecx
  unsigned int m_nInBufWord; // edi
  int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int v10; // esi
  unsigned int v11; // ebx
  int v12; // esi
  unsigned int v13; // ecx
  const unsigned int *v14; // edx
  const unsigned int *v15; // esi
  const unsigned int *v16; // ecx
  unsigned int v17; // edi
  int v18; // edx
  const unsigned int *v19; // esi
  unsigned int v20; // esi
  unsigned int v21; // ebx
  int v22; // ecx
  unsigned int v23; // edx
  CGameTimescale::Interpolators_e v24; // esi
  int v25; // ecx
  const unsigned int *v26; // ecx
  const unsigned int *v27; // edx
  unsigned int v28; // edx
  const unsigned int *v29; // esi
  unsigned int v30; // edi
  int v31; // edx
  const unsigned int *v32; // ecx
  unsigned int v33; // esi
  unsigned int v34; // ebx
  int v35; // esi
  unsigned int v36; // ecx
  const unsigned int *v37; // edx
  const unsigned int *v38; // esi
  const unsigned int *v39; // ecx
  unsigned int v40; // edi
  int v41; // edx
  const unsigned int *v42; // esi
  unsigned int v43; // esi
  unsigned int v44; // ebx
  float v45; // xmm0_4
  CGameTimescale::Interpolators_e v46; // [esp+Ch] [ebp-Ch]
  int v47; // [esp+10h] [ebp-8h]
  float v48; // [esp+14h] [ebp-4h]
  float msga; // [esp+20h] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pDataIn = msg->m_pDataIn;
    m_nInBufWord = msg->m_nInBufWord;
    v8 = 32 - m_nBitsAvail;
    m_pBufferEnd = msg->m_pBufferEnd;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v48 = 0.0;
    }
    else
    {
      v10 = msg->m_nInBufWord;
      v11 = (v10 & CBitBuffer::s_nMaskTable[v8]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v8;
      LODWORD(v48) = v11 | m_nInBufWord;
      msg->m_nInBufWord = v10 >> v8;
    }
    goto LABEL_19;
  }
  v3 = msg->m_nInBufWord;
  msg->m_nBitsAvail = m_nBitsAvail - 32;
  if ( m_nBitsAvail == 32 )
  {
    v4 = msg->m_pDataIn;
    v5 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v4 == v5 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v4 + 1;
      v48 = *(float *)&v3;
    }
    else
    {
      if ( v4 <= v5 )
      {
        msg->m_nInBufWord = *v4;
        msg->m_pDataIn = v4 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v48 = *(float *)&v3;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    v48 = *(float *)&v3;
  }
LABEL_19:
  v12 = msg->m_nBitsAvail;
  if ( v12 < 32 )
  {
    v16 = msg->m_pDataIn;
    v17 = msg->m_nInBufWord;
    v18 = 32 - v12;
    v19 = msg->m_pBufferEnd;
    if ( v16 == v19 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v16 > v19 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v16;
    }
    msg->m_pDataIn = v16 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v47 = 0;
    }
    else
    {
      v20 = msg->m_nInBufWord;
      v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v18;
      v47 = v21 | v17;
      msg->m_nInBufWord = v20 >> v18;
    }
    goto LABEL_37;
  }
  v13 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v12 - 32;
  if ( v12 == 32 )
  {
    v14 = msg->m_pDataIn;
    v15 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v14 == v15 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v14 + 1;
      v47 = v13;
    }
    else
    {
      if ( v14 <= v15 )
      {
        msg->m_nInBufWord = *v14;
        msg->m_pDataIn = v14 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v47 = v13;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    v47 = v13;
  }
LABEL_37:
  v22 = msg->m_nBitsAvail;
  if ( v22 < 8 )
  {
    v29 = msg->m_pBufferEnd;
    v30 = msg->m_nInBufWord;
    v31 = 8 - v22;
    v32 = msg->m_pDataIn;
    if ( v32 == v29 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v32 > v29 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v32;
    }
    msg->m_pDataIn = v32 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      v46 = INTERPOLATOR_LINEAR;
    }
    else
    {
      v33 = msg->m_nInBufWord;
      v34 = (v33 & CBitBuffer::s_nMaskTable[v31]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v31;
      v46 = v34 | v30;
      msg->m_nInBufWord = v33 >> v31;
    }
    goto LABEL_55;
  }
  v23 = msg->m_nInBufWord;
  v24 = (unsigned __int8)v23;
  v25 = v22 - 8;
  msg->m_nBitsAvail = v25;
  if ( v25 != 0 )
  {
    msg->m_nInBufWord = v23 >> 8;
    v46 = (unsigned __int8)v23;
  }
  else
  {
    v26 = msg->m_pDataIn;
    v27 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v26 == v27 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v26 + 1;
      v46 = v24;
    }
    else
    {
      if ( v26 <= v27 )
      {
        v28 = *v26;
        msg->m_pDataIn = v26 + 1;
        msg->m_nInBufWord = v28;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v46 = v24;
    }
  }
LABEL_55:
  v35 = msg->m_nBitsAvail;
  if ( v35 < 32 )
  {
    v39 = msg->m_pDataIn;
    v40 = msg->m_nInBufWord;
    v41 = 32 - v35;
    v42 = msg->m_pBufferEnd;
    if ( v39 == v42 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v39 > v42 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_70;
      }
      msg->m_nInBufWord = *v39;
    }
    msg->m_pDataIn = v39 + 1;
LABEL_70:
    if ( msg->m_bOverflow )
    {
      msga = 0.0;
    }
    else
    {
      v43 = msg->m_nInBufWord;
      v44 = (v43 & CBitBuffer::s_nMaskTable[v41]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v41;
      LODWORD(msga) = v44 | v40;
      msg->m_nInBufWord = v43 >> v41;
    }
    goto LABEL_73;
  }
  v36 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v35 - 32;
  if ( v35 == 32 )
  {
    v37 = msg->m_pDataIn;
    v38 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v37 == v38 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v37 + 1;
      msga = *(float *)&v36;
    }
    else
    {
      if ( v37 <= v38 )
      {
        msg->m_nInBufWord = *v37;
        msg->m_pDataIn = v37 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = *(float *)&v36;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msga = *(float *)&v36;
  }
LABEL_73:
  v45 = msga - *(float *)(gpGlobals.m_Index + 12);
  if ( v45 < 0.0 )
    v45 = 0.0;
  if ( g_GameTimescale.m_flDesiredTimescale != v48 )
  {
    g_GameTimescale.m_flDesiredTimescale = v48;
    LODWORD(g_GameTimescale.m_flDurationRealTimeSeconds) = v47;
    g_GameTimescale.m_nInterpolatorType = v46;
    g_GameTimescale.m_flStartBlendTime = (float)(v45 * g_GameTimescale.m_flCurrentTimescale)
                                       + *(float *)(gpGlobals.m_Index + 12);
    if ( *(float *)(gpGlobals.m_Index + 12) < g_GameTimescale.m_flStartBlendTime )
      g_GameTimescale.m_flStartBlendRealtime = 0.0;
    else
      g_GameTimescale.m_flStartBlendRealtime = *(float *)gpGlobals.m_Index;
    g_GameTimescale.m_flStartTimescale = g_GameTimescale.m_flCurrentTimescale;
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1013DC10
// Name: private: void CGameTimescale::UpdateTimescale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameTimescale::UpdateTimescale(CGameTimescale *this)
{
  CGlobalVars *v2; // ecx
  float m_flDurationRealTimeSeconds; // xmm2_4
  float x; // xmm0_4
  double v5; // st7
  float biasAmt; // xmm1_4
  float flInterpa; // [esp+Ch] [ebp-4h]
  float flInterp; // [esp+Ch] [ebp-4h]

  if ( !engine->IsPaused(this: engine) )
  {
    if ( this->m_flCurrentTimescale == this->m_flDesiredTimescale )
      goto LABEL_18;
    v2 = gpGlobals;
    if ( gpGlobals->curtime < this->m_flStartBlendTime )
      goto LABEL_18;
    if ( this->m_flStartBlendRealtime == 0.0 )
    {
      this->m_flStartBlendRealtime = gpGlobals->realtime;
      v2 = gpGlobals;
    }
    m_flDurationRealTimeSeconds = this->m_flDurationRealTimeSeconds;
    x = 1.0;
    if ( m_flDurationRealTimeSeconds > 0.0 )
    {
      x = (float)(v2->realtime - this->m_flStartBlendRealtime) / m_flDurationRealTimeSeconds;
      if ( x > 1.0 )
        x = 1.0;
    }
    switch ( this->m_nInterpolatorType )
    {
      case INTERPOLATOR_ACCEL:
        biasAmt = 0.25;
        break;
      case INTERPOLATOR_DEACCEL:
        biasAmt = 0.75;
        break;
      case INTERPOLATOR_EASE_IN_OUT:
        v5 = Gain(x, biasAmt: 0.75);
LABEL_16:
        flInterpa = v5;
        x = flInterpa;
        goto LABEL_17;
      default:
LABEL_17:
        this->m_flCurrentTimescale = (float)((float)(1.0 - x) * this->m_flStartTimescale)
                                   + (float)(this->m_flDesiredTimescale * x);
LABEL_18:
        flInterp = this->m_flCurrentTimescale;
        if ( flInterp != ((double (__thiscall *)(IVEngineServer *))engine->GetTimescale)(a1: engine) )
          ((void (__stdcall *)(_DWORD))engine->SetTimescale)(a1: LODWORD(flInterp));
        return;
    }
    v5 = Bias(x, biasAmt);
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DD60
// Name: public: virtual bool CGameTimescale::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameTimescale::Init(CGameTimescale *this)
{
  this->m_flDesiredTimescale = 1.0;
  this->m_flCurrentTimescale = 1.0;
  *(_QWORD *)&this->m_flDurationRealTimeSeconds = 0;
  this->m_flStartBlendTime = 0.0;
  this->m_flStartBlendRealtime = 0.0;
  ((void (__stdcall *)(int))engine->SetTimescale)(a1: 1065353216);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013DDB0
// Name: public: virtual void CGameTimescale::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CGameTimescale::FrameUpdatePostEntityThink(CGameTimescale *this)
{
  CGameTimescale::UpdateTimescale(this);
}

//------------------------------------------------------------------------------
// Address: 0x1013DDC0
// Name: public: virtual void CGameTimescale::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameTimescale::LevelShutdownPostEntity(CGameTimescale *this)
{
  this->m_flDesiredTimescale = 1.0;
  this->m_flCurrentTimescale = 1.0;
  *(_QWORD *)&this->m_flDurationRealTimeSeconds = 0;
  this->m_flStartBlendTime = 0.0;
  this->m_flStartBlendRealtime = 0.0;
  ((void (__stdcall *)(int))engine->SetTimescale)(a1: 1065353216);
}

//------------------------------------------------------------------------------
// Address: 0x1013DE10
// Name: public: void CGameTimescale::SetCurrentTimescale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameTimescale::SetCurrentTimescale(CGameTimescale *this, float flTimescale)
{
  float v2; // xmm0_4
  CReliableBroadcastRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  v2 = flTimescale;
  if ( this->m_flCurrentTimescale == flTimescale )
  {
    if ( this->m_flCurrentTimescale == ((double (__thiscall *)(IVEngineServer *))engine->GetTimescale)(a1: engine) )
      return;
    v2 = flTimescale;
  }
  this->m_flDesiredTimescale = v2;
  this->m_flCurrentTimescale = v2;
  *(_QWORD *)&this->m_flDurationRealTimeSeconds = 0;
  this->m_flStartBlendTime = 0.0;
  this->m_flStartBlendRealtime = 0.0;
  ((void (__stdcall *)(_DWORD))engine->SetTimescale)(a1: LODWORD(v2));
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CReliableBroadcastRecipientFilter::`vftable';
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  UserMessageBegin(&filter, messagename: "CurrentTimescale");
  MessageWriteFloat(flValue: this->m_flCurrentTimescale);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1013DEF0
// Name: void SV_TimeScale(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_TimeScale(const CCommand *args)
{
  float timeScale; // [esp+Ch] [ebp+8h]

  if ( args->m_nArgc == 2 )
  {
    timeScale = V_atof(str: args->m_ppArgv[1]);
    CGameTimescale::SetCurrentTimescale(this: &g_GameTimescale, flTimescale: timeScale);
  }
}

} // namespace server
