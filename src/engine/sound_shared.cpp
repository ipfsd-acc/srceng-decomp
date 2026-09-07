// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sound_shared.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101D7F40
// Name: void DbReferenceChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DbReferenceChanged()
{
  snd_refdb_dist_mult = pow(10.0, snd_refdb.m_pParent->m_Value.m_fValue * 0.050000001);
}

//------------------------------------------------------------------------------
// Address: 0x101D7F70
// Name: float SND_GetGainFromMult(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SND_GetGainFromMult(float gain, float dist_mult, float dist)
{
  double v3; // st6
  float v4; // xmm0_4
  float v5; // xmm2_4
  float m_fValue; // xmm1_4
  float a; // [esp+0h] [ebp-4h]
  float v9; // [esp+Ch] [ebp+8h]
  float v10; // [esp+10h] [ebp+Ch]
  float v11; // [esp+10h] [ebp+Ch]
  float gaina; // [esp+14h] [ebp+10h]

  v3 = FastPow10(i: (float)((float)(dist * 0.00083333335) * snd_foliage_db_loss.m_pParent->m_Value.m_fValue) * 0.050000001)
     * (dist
      * dist_mult);
  a = v3;
  if ( v3 <= 0.1 )
    v4 = gain * 10.0;
  else
    v4 = (float)(1.0 / a) * gain;
  v5 = 0.0;
  v9 = v4;
  if ( v4 > 0.5 )
  {
    gaina = 2.5;
    if ( dist_mult != 0.0 )
    {
      v10 = __FYL2X__(
              snd_refdb_dist_mult / (dist_mult * snd_refdist.m_pParent->m_Value.m_fValue),
              0.3010299956639811952)
          * 20.0;
      v5 = v10;
    }
    if ( (float)(int)v5 > 90.0 )
      gaina = 2.5 - (float)((float)((float)((float)(int)v5 - 90.0) * 1.7) * 0.02);
    v11 = -1.0 / (FastPow(a: 0.5, b: gaina) * -0.5);
    v9 = (1.0 - 1.0 / (FastPow(a: v4, b: gaina) * v11)) * snd_gain_max.m_pParent->m_Value.m_fValue;
    v4 = v9;
  }
  m_fValue = snd_gain_min.m_pParent->m_Value.m_fValue;
  if ( m_fValue > v4 )
  {
    v9 = (float)(2.0 - (float)(m_fValue * a)) * m_fValue;
    if ( v9 <= 0.0 )
      return 0.001;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101D8120
// Name: float S_GetGainFromSoundLevel(enum soundlevel_t,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl S_GetGainFromSoundLevel(soundlevel_t soundlevel, float dist)
{
  double v3; // st7
  float v5; // [esp-8h] [ebp-Ch]
  float m_fValue; // [esp+0h] [ebp-4h]
  float gain; // [esp+Ch] [ebp+8h]
  float gaina; // [esp+Ch] [ebp+8h]

  m_fValue = snd_gain.m_pParent->m_Value.m_fValue;
  if ( soundlevel == SNDLVL_NONE )
    return m_fValue;
  gain = snd_refdist.m_pParent->m_Value.m_fValue;
  v3 = snd_refdb_dist_mult / FastPow10(i: (float)soundlevel * 0.050000001) / gain;
  gaina = v3;
  if ( gaina == 0.0 )
    return m_fValue;
  v5 = v3;
  return SND_GetGainFromMult(gain: m_fValue, dist_mult: v5, dist);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101D82C0
// Name: void DbReferenceChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DbReferenceChanged()
{
  snd_refdb_dist_mult = pow(10.0, snd_refdb.m_pParent->m_Value.m_fValue * 0.050000001);
}

//------------------------------------------------------------------------------
// Address: 0x101D82F0
// Name: float SND_GetGainFromMult(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SND_GetGainFromMult(float gain, float dist_mult, float dist)
{
  double v3; // st6
  float v4; // xmm0_4
  float v5; // xmm2_4
  float m_fValue; // xmm1_4
  float a; // [esp+0h] [ebp-4h]
  float v9; // [esp+Ch] [ebp+8h]
  float v10; // [esp+10h] [ebp+Ch]
  float v11; // [esp+10h] [ebp+Ch]
  float gaina; // [esp+14h] [ebp+10h]

  v3 = FastPow10(i: (float)((float)(dist * 0.00083333335) * snd_foliage_db_loss.m_pParent->m_Value.m_fValue) * 0.050000001)
     * (dist
      * dist_mult);
  a = v3;
  if ( v3 <= 0.1 )
    v4 = gain * 10.0;
  else
    v4 = (float)(1.0 / a) * gain;
  v5 = 0.0;
  v9 = v4;
  if ( v4 > 0.5 )
  {
    gaina = 2.5;
    if ( dist_mult != 0.0 )
    {
      v10 = __FYL2X__(
              snd_refdb_dist_mult / (dist_mult * snd_refdist.m_pParent->m_Value.m_fValue),
              0.3010299956639811952)
          * 20.0;
      v5 = v10;
    }
    if ( (float)(int)v5 > 90.0 )
      gaina = 2.5 - (float)((float)((float)((float)(int)v5 - 90.0) * 1.7) * 0.02);
    v11 = -1.0 / (FastPow(a: 0.5, b: gaina) * -0.5);
    v9 = (1.0 - 1.0 / (FastPow(a: v4, b: gaina) * v11)) * snd_gain_max.m_pParent->m_Value.m_fValue;
    v4 = v9;
  }
  m_fValue = snd_gain_min.m_pParent->m_Value.m_fValue;
  if ( m_fValue > v4 )
  {
    v9 = (float)(2.0 - (float)(m_fValue * a)) * m_fValue;
    if ( v9 <= 0.0 )
      return 0.001;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x101D84A0
// Name: float S_GetGainFromSoundLevel(enum soundlevel_t,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl S_GetGainFromSoundLevel(soundlevel_t soundlevel, float dist)
{
  double v3; // st7
  float v5; // [esp-8h] [ebp-Ch]
  float m_fValue; // [esp+0h] [ebp-4h]
  float gain; // [esp+Ch] [ebp+8h]
  float gaina; // [esp+Ch] [ebp+8h]

  m_fValue = snd_gain.m_pParent->m_Value.m_fValue;
  if ( soundlevel == SNDLVL_NONE )
    return m_fValue;
  gain = snd_refdist.m_pParent->m_Value.m_fValue;
  v3 = snd_refdb_dist_mult / FastPow10(i: (float)soundlevel * 0.050000001) / gain;
  gaina = v3;
  if ( gaina == 0.0 )
    return m_fValue;
  v5 = v3;
  return SND_GetGainFromMult(gain: m_fValue, dist_mult: v5, dist);
}

} // namespace engine_xlsp
