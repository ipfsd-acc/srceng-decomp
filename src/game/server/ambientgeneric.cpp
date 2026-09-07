// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ambientgeneric.cpp
// Functions: 30
// ============================================================

#include "game\server\ambientgeneric.h"

//------------------------------------------------------------------------------
// Address: 0x10090BF0
// Name: public: virtual struct datamap_t __near * CAmbientGeneric::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAmbientGeneric::GetDataDescMap(CAmbientGeneric *this)
{
  return &CAmbientGeneric::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090C00
// Name: public: void CAmbientGeneric::ComputeMaxAudibleDistance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::ComputeMaxAudibleDistance(CAmbientGeneric *this)
{
  soundlevel_t m_iSoundLevel; // edx
  int i; // edi
  float flMinRadius; // [esp+28h] [ebp-8h]
  float flMaxRadius; // [esp+2Ch] [ebp-4h]

  m_iSoundLevel = this->m_iSoundLevel;
  if ( m_iSoundLevel == SNDLVL_NONE || this->m_radius == 0.0 )
  {
LABEL_14:
    this->m_flMaxRadius = -1.0;
    return;
  }
  if ( ((double (__thiscall *)(IEngineSound *, soundlevel_t, _DWORD))enginesound->GetDistGainFromSoundLevel)(
         a1: enginesound,
         a2: m_iSoundLevel,
         a3: LODWORD(this->m_radius)) <= 0.00101 )
  {
    this->m_flMaxRadius = this->m_radius;
    return;
  }
  flMinRadius = this->m_radius;
  flMaxRadius = flMinRadius * 2.0;
  if ( ((double (__stdcall *)(soundlevel_t, _DWORD))enginesound->GetDistGainFromSoundLevel)(
         a1: this->m_iSoundLevel,
         a2: flMinRadius * 2.0) > 0.00101 )
  {
    while ( flMaxRadius <= 100000.0 )
    {
      flMinRadius = flMaxRadius;
      flMaxRadius = flMaxRadius * 2.0;
      if ( ((double (__stdcall *)(soundlevel_t, _DWORD))enginesound->GetDistGainFromSoundLevel)(
             a1: this->m_iSoundLevel,
             a2: LODWORD(flMaxRadius)) <= 0.00101 )
        goto LABEL_8;
    }
    goto LABEL_14;
  }
LABEL_8:
  for ( i = 3; i >= 0; --i )
  {
    if ( ((double (__stdcall *)(soundlevel_t, _DWORD))enginesound->GetDistGainFromSoundLevel)(
           a1: this->m_iSoundLevel,
           a2: (float)(flMaxRadius + flMinRadius) * 0.5) > 0.00101 )
      flMinRadius = (float)(flMaxRadius + flMinRadius) * 0.5;
    else
      flMaxRadius = (float)(flMaxRadius + flMinRadius) * 0.5;
  }
  this->m_flMaxRadius = flMaxRadius;
}

//------------------------------------------------------------------------------
// Address: 0x10090D80
// Name: public: virtual void CAmbientGeneric::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::UpdateOnRemove(CAmbientGeneric *this)
{
  if ( this->m_fActive )
    this->SendSound(this, a2: SND_STOP);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090DA0
// Name: public: void CAmbientGeneric::InputPlaySound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputPlaySound(CAmbientGeneric *this, inputdata_t *inputdata)
{
  if ( !this->m_fActive )
  {
    this->SendSound(this, a2: SND_STOP);
    this->ToggleSound(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090DD0
// Name: public: void CAmbientGeneric::InputStopSound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputStopSound(CAmbientGeneric *this, inputdata_t *inputdata)
{
  if ( this->m_fActive )
    this->ToggleSound(this);
}

//------------------------------------------------------------------------------
// Address: 0x10090DF0
// Name: public: CSoundParameters::CSoundParameters(void)
// Source: json
//------------------------------------------------------------------------------
CSoundParameters *__thiscall CSoundParameters::CSoundParameters(CSoundParameters *this)
{
  this->pitch = 100;
  this->pitchlow = 100;
  this->pitchhigh = 100;
  this->channel = 0;
  this->volume = 1.0;
  this->soundlevel = SNDLVL_NORM;
  this->soundname[0] = 0;
  this->play_to_owner_only = false;
  this->count = 0;
  this->delay_msec = 0;
  this->m_nSoundEntryVersion = 1;
  this->m_hSoundScriptHandle = -1;
  this->m_pOperatorsKV = nullptr;
  this->m_nRandomSeed = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090E50
// Name: public: void CAmbientGeneric::InputPitch(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputPitch(CAmbientGeneric *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int v3; // xmm1_4
  CAmbientGeneric_vtbl *v4; // edx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    flVal = inputdata->value.flVal;
    v3 = 0;
    if ( flVal < 0.0 || (v3 = 1132396544, flVal > 255.0) )
      flVal = *(float *)&v3;
  }
  else
  {
    flVal = 0.0;
  }
  v4 = this->__vftable;
  this->m_dpv.pitch = (int)flVal;
  ((void (__stdcall *)(int))v4->SendSound)(a1: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10090EA0
// Name: public: void CAmbientGeneric::InputVolume(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputVolume(CAmbientGeneric *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  float v3; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    flVal = inputdata->value.flVal;
    if ( flVal >= 0.0 )
    {
      if ( flVal > 10.0 )
        flVal = 10.0;
    }
    else
    {
      flVal = 0.0;
    }
  }
  else
  {
    flVal = 0.0;
  }
  v3 = flVal * 10.0;
  this->m_dpv.vol = (int)v3;
  this->m_dpv.volfrac = (int)v3 << 8;
  this->SendSound(this, a2: SND_CHANGE_VOL);
}

//------------------------------------------------------------------------------
// Address: 0x10090F00
// Name: public: void CAmbientGeneric::InputFadeIn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputFadeIn(CAmbientGeneric *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int fadein; // eax

  this->m_dpv.fadeout = 0;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  this->m_dpv.fadein = (int)flVal;
  if ( (int)flVal > 100 )
    this->m_dpv.fadein = 100;
  if ( this->m_dpv.fadein < 0 )
    this->m_dpv.fadein = 0;
  fadein = this->m_dpv.fadein;
  if ( fadein > 0 )
    this->m_dpv.fadein = 25600 / (5 * fadein);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10090F90
// Name: public: void CAmbientGeneric::InputFadeOut(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputFadeOut(CAmbientGeneric *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int fadeout; // eax

  this->m_dpv.fadein = 0;
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  this->m_dpv.fadeout = (int)flVal;
  if ( (int)flVal > 100 )
    this->m_dpv.fadeout = 100;
  if ( this->m_dpv.fadeout < 0 )
    this->m_dpv.fadeout = 0;
  fadeout = this->m_dpv.fadeout;
  if ( fadeout > 0 )
    this->m_dpv.fadeout = 25600 / (5 * fadeout);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10091020
// Name: public: virtual void CAmbientGeneric::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::Precache(CAmbientGeneric *this)
{
  const char *pszValue; // eax
  const char *v3; // edi

  pszValue = this->m_iszSound.pszValue;
  v3 = pszValue;
  if ( pszValue != nullptr && strlen(pszValue) > 1 && *v3 != 33 )
    CBaseEntity::PrecacheScriptSound(soundname: v3);
  if ( (this->m_spawnflags.m_Value & 0x10) == 0 && this->m_fLooping )
    this->m_fActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x10091080
// Name: public: void CAmbientGeneric::RampThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::RampThink(CAmbientGeneric *this)
{
  int spinup; // eax
  int pitch; // ebx
  int v4; // edi
  int pitchfrac; // ecx
  int v6; // edx
  int v7; // ecx
  int spindown; // eax
  void (__thiscall *SendSound)(CAmbientGeneric *, SoundFlags_t); // edx
  int fadein; // ecx
  int volfrac; // eax
  int v12; // edx
  int v13; // eax
  int fadeout; // ecx
  int volrun; // eax
  int volstart; // eax
  CAmbientGeneric_vtbl *v17; // edx
  void (__thiscall *v18)(CAmbientGeneric *, SoundFlags_t); // eax
  int lforate; // eax
  int v20; // ecx
  int v21; // eax
  int lfomodpitch; // eax
  int lfomodvol; // eax
  CBaseEntity *v24; // eax
  edict_t *m_pPev; // edx
  const Vector *AbsOrigin; // eax
  float vol; // [esp+0h] [ebp-30h]
  soundlevel_t m_iSoundLevel; // [esp+4h] [ebp-2Ch]
  int prev; // [esp+24h] [ebp-Ch]
  int preva; // [esp+24h] [ebp-Ch]
  const char *prevb; // [esp+24h] [ebp-Ch]
  int fChanged; // [esp+28h] [ebp-8h]
  signed int fChangeda; // [esp+28h] [ebp-8h]
  int flags; // [esp+2Ch] [ebp-4h]

  spinup = this->m_dpv.spinup;
  pitch = this->m_dpv.pitch;
  v4 = this->m_dpv.vol;
  flags = 0;
  fChanged = 0;
  if ( spinup != 0 )
    goto LABEL_7;
  if ( this->m_dpv.spindown == 0 && this->m_dpv.fadein == 0 && this->m_dpv.fadeout == 0 && this->m_dpv.lfotype == 0 )
    return;
  if ( this->m_dpv.spindown != 0 )
  {
LABEL_7:
    pitchfrac = this->m_dpv.pitchfrac;
    v6 = this->m_dpv.pitchfrac >> 8;
    if ( spinup <= 0 )
    {
      spindown = this->m_dpv.spindown;
      if ( spindown <= 0 )
      {
LABEL_12:
        pitch = this->m_dpv.pitchfrac >> 8;
        if ( pitch > this->m_dpv.pitchrun )
        {
          pitch = this->m_dpv.pitchrun;
          this->m_dpv.spinup = 0;
        }
        if ( pitch < this->m_dpv.pitchstart )
        {
          SendSound = this->SendSound;
          this->m_dpv.spindown = 0;
          SendSound(this, a2: SND_STOP);
          return;
        }
        if ( pitch <= 255 )
        {
          if ( pitch < 1 )
            pitch = 1;
        }
        else
        {
          pitch = 255;
        }
        this->m_dpv.pitch = pitch;
        flags = 2;
        fChanged = v6 != pitch;
        goto LABEL_21;
      }
      v7 = pitchfrac - spindown;
    }
    else
    {
      v7 = spinup + pitchfrac;
    }
    this->m_dpv.pitchfrac = v7;
    goto LABEL_12;
  }
LABEL_21:
  fadein = this->m_dpv.fadein;
  if ( fadein == 0 && this->m_dpv.fadeout == 0 )
    goto LABEL_37;
  volfrac = this->m_dpv.volfrac;
  v12 = volfrac >> 8;
  if ( fadein > 0 )
  {
    v13 = fadein + volfrac;
LABEL_27:
    this->m_dpv.volfrac = v13;
    goto LABEL_28;
  }
  fadeout = this->m_dpv.fadeout;
  if ( fadeout > 0 )
  {
    v13 = volfrac - fadeout;
    goto LABEL_27;
  }
LABEL_28:
  volrun = this->m_dpv.volrun;
  v4 = this->m_dpv.volfrac >> 8;
  if ( v4 > volrun )
  {
    v4 = this->m_dpv.volrun;
    this->m_dpv.volfrac = volrun << 8;
    this->m_dpv.fadein = 0;
  }
  volstart = this->m_dpv.volstart;
  if ( v4 < volstart )
  {
    v17 = this->__vftable;
    this->m_dpv.vol = volstart;
    this->m_dpv.volfrac = volstart << 8;
    v18 = v17->SendSound;
    this->m_dpv.fadeout = 0;
    v18(this, a2: SND_STOP);
    return;
  }
  if ( v4 <= 100 )
  {
    if ( v4 < 1 )
    {
      v4 = 1;
      this->m_dpv.volfrac = 256;
    }
  }
  else
  {
    v4 = 100;
    this->m_dpv.volfrac = 25600;
  }
  this->m_dpv.vol = v4;
  fChanged |= v12 != v4;
  flags |= 1u;
LABEL_37:
  if ( this->m_dpv.lfotype != 0 )
  {
    if ( this->m_dpv.lfofrac > 1879048191 )
      this->m_dpv.lfofrac = 0;
    lforate = this->m_dpv.lforate;
    this->m_dpv.lfofrac += lforate;
    v20 = this->m_dpv.lfofrac >> 8;
    if ( this->m_dpv.lfofrac >= 0 )
    {
      if ( v20 <= 255 )
      {
LABEL_45:
        if ( this->m_dpv.lfotype == 1 )
        {
          this->m_dpv.lfomult = (unsigned __int8)((v20 >= 128) - 1);
        }
        else if ( this->m_dpv.lfotype == 3 )
        {
          if ( v20 == 255 )
            this->m_dpv.lfomult = random->RandomInt(this: random, a2: 0, a3: 255);
        }
        else
        {
          this->m_dpv.lfomult = v20;
        }
        lfomodpitch = this->m_dpv.lfomodpitch;
        if ( lfomodpitch != 0 )
        {
          prev = pitch;
          pitch += lfomodpitch * (this->m_dpv.lfomult - 128) / 100;
          if ( pitch <= 255 )
          {
            if ( pitch < 1 )
              pitch = 1;
          }
          else
          {
            pitch = 255;
          }
          fChanged |= prev != pitch;
          flags |= 2u;
        }
        lfomodvol = this->m_dpv.lfomodvol;
        if ( lfomodvol != 0 )
        {
          preva = v4;
          v4 += lfomodvol * (this->m_dpv.lfomult - 128) / 100;
          if ( v4 <= 100 )
          {
            if ( v4 < 0 )
              v4 = 0;
          }
          else
          {
            v4 = 100;
          }
          fChanged |= preva != v4;
          flags |= 1u;
        }
        goto LABEL_63;
      }
      v20 = 255;
      this->m_dpv.lfofrac = 65280;
      v21 = -abs32(lforate);
    }
    else
    {
      v21 = abs32(lforate);
      this->m_dpv.lfofrac = 0;
      v20 = 0;
    }
    this->m_dpv.lforate = v21;
    goto LABEL_45;
  }
LABEL_63:
  if ( flags != 0 && fChanged != 0 )
  {
    if ( pitch == 100 )
      pitch = 101;
    v24 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hSoundSource);
    if ( v24 != nullptr )
    {
      prevb = this->m_iszSound.pszValue;
      if ( prevb == nullptr )
        prevb = locale;
      m_pPev = v24->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        fChangeda = m_pPev - gpGlobals->pEdicts;
      else
        fChangeda = 0;
      m_iSoundLevel = this->m_iSoundLevel;
      vol = (double)v4 * 0.01;
      AbsOrigin = CBaseEntity::GetAbsOrigin(this: v24);
      UTIL_EmitAmbientSound(
        entindex: fChangeda,
        vecOrigin: AbsOrigin,
        samp: prevb,
        vol,
        soundlevel: m_iSoundLevel,
        fFlags: flags,
        pitch,
        soundtime: 0.0,
        duration: nullptr);
    }
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10091490
// Name: public: void CAmbientGeneric::InitModulationParms(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InitModulationParms(CAmbientGeneric *this)
{
  int v2; // eax
  int preset; // eax
  int spindown; // eax
  int spinup; // eax
  int fadein; // eax
  int fadeout; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int fadeinsav; // eax
  int spinupsav; // eax
  int pitch; // edi
  int cspinup; // esi
  int lforate; // eax
  int v17; // eax

  v2 = 10 * this->m_iHealth.m_Value;
  this->m_dpv.volrun = v2;
  if ( v2 > 100 )
    this->m_dpv.volrun = 100;
  if ( this->m_dpv.volrun < 0 )
    this->m_dpv.volrun = 0;
  preset = this->m_dpv.preset;
  if ( preset != 0 && preset <= 27 )
  {
    qmemcpy(&this->m_dpv, &dataDesc_76[5].inputFunc + 25 * preset, sizeof(this->m_dpv));
    spindown = this->m_dpv.spindown;
    if ( spindown > 0 )
      this->m_dpv.spindown = (101 - spindown) << 6;
    spinup = this->m_dpv.spinup;
    if ( spinup > 0 )
      this->m_dpv.spinup = (101 - spinup) << 6;
    this->m_dpv.volstart *= 10;
    fadein = this->m_dpv.fadein;
    this->m_dpv.volrun *= 10;
    if ( fadein > 0 )
      this->m_dpv.fadein = (101 - fadein) << 6;
    fadeout = this->m_dpv.fadeout;
    if ( fadeout > 0 )
      this->m_dpv.fadeout = (101 - fadeout) << 6;
    v8 = this->m_dpv.fadein;
    this->m_dpv.lforate <<= 8;
    v9 = this->m_dpv.fadeout;
    this->m_dpv.fadeinsav = v8;
    v10 = this->m_dpv.spinup;
    this->m_dpv.fadeoutsav = v9;
    v11 = this->m_dpv.spindown;
    this->m_dpv.spinupsav = v10;
    this->m_dpv.spindownsav = v11;
  }
  fadeinsav = this->m_dpv.fadeinsav;
  this->m_dpv.fadein = fadeinsav;
  this->m_dpv.fadeout = 0;
  if ( fadeinsav != 0 )
    this->m_dpv.vol = this->m_dpv.volstart;
  else
    this->m_dpv.vol = this->m_dpv.volrun;
  spinupsav = this->m_dpv.spinupsav;
  this->m_dpv.spinup = spinupsav;
  this->m_dpv.spindown = 0;
  if ( spinupsav != 0 )
    this->m_dpv.pitch = this->m_dpv.pitchstart;
  else
    this->m_dpv.pitch = this->m_dpv.pitchrun;
  if ( this->m_dpv.pitch == 0 )
    this->m_dpv.pitch = 100;
  pitch = this->m_dpv.pitch;
  cspinup = this->m_dpv.cspinup;
  this->m_dpv.volfrac = this->m_dpv.vol << 8;
  lforate = this->m_dpv.lforate;
  this->m_dpv.lfofrac = 0;
  this->m_dpv.pitchfrac = pitch << 8;
  this->m_dpv.lforate = abs32(lforate);
  this->m_dpv.cspincount = 1;
  if ( cspinup != 0 )
  {
    v17 = this->m_dpv.pitchstart + (255 - this->m_dpv.pitchstart) / cspinup;
    this->m_dpv.pitchrun = v17;
    if ( v17 > 255 )
      this->m_dpv.pitchrun = 255;
  }
  if ( (this->m_dpv.spinupsav != 0
     || this->m_dpv.spindownsav != 0
     || this->m_dpv.lfotype != 0 && this->m_dpv.lfomodpitch != 0)
    && pitch == 100 )
  {
    this->m_dpv.pitch = 101;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100916E0
// Name: public: virtual void CAmbientGeneric::SendSound(enum SoundFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::SendSound(CAmbientGeneric *this, SoundFlags_t flags)
{
  unsigned int m_Index; // eax
  CBaseEntity **v4; // ecx
  CBaseEntity *v5; // edi
  signed int m_pPev; // eax
  signed int v7; // eax
  float vol; // xmm0_4
  char *szSoundFile; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  szSoundFile = (char *)this->m_iszSound.pszValue;
  if ( szSoundFile == nullptr )
    szSoundFile = (char *)locale;
  m_Index = this->m_hSoundSource.m_Index;
  if ( m_Index != -1
    && (v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (v5 = *v4, *v4 != nullptr) )
  {
    if ( flags == SND_STOP )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      m_pPev = (signed int)v5->m_Network.m_pPev;
      if ( m_pPev != 0 )
        m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
      UTIL_EmitAmbientSound(
        entindex: m_pPev,
        vecOrigin: &v5->m_vecAbsOrigin,
        samp: szSoundFile,
        vol: 0.0,
        soundlevel: SNDLVL_NONE,
        fFlags: 4,
        pitch: 0,
        soundtime: 0.0,
        duration: nullptr);
    }
    else
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      v7 = (signed int)v5->m_Network.m_pPev;
      if ( v7 != 0 )
        v7 = (signed int)(v7 - (unsigned int)gpGlobals->pEdicts) >> 4;
      vol = (double)this->m_dpv.vol * 0.01;
      UTIL_EmitAmbientSound(
        entindex: v7,
        vecOrigin: &v5->m_vecAbsOrigin,
        samp: szSoundFile,
        vol,
        soundlevel: this->m_iSoundLevel,
        fFlags: flags,
        pitch: this->m_dpv.pitch,
        soundtime: 0.0,
        duration: nullptr);
    }
  }
  else if ( flags == SND_STOP && this->m_nSoundSourceEntIndex != -1 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_EmitAmbientSound(
      entindex: this->m_nSoundSourceEntIndex,
      vecOrigin: &this->m_vecAbsOrigin,
      samp: szSoundFile,
      vol: 0.0,
      soundlevel: SNDLVL_NONE,
      fFlags: 4,
      pitch: 0,
      soundtime: 0.0,
      duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091850
// Name: public: virtual bool CAmbientGeneric::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAmbientGeneric::KeyValue(CAmbientGeneric *this, const char *szKeyName, const char *szValue)
{
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int spinup; // eax
  int v9; // eax
  int spindown; // eax
  int v11; // eax
  int v12; // eax
  int fadein; // eax
  int v14; // eax
  int fadeout; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax

  if ( szKeyName == "preset" || _V_stricmp(s1: szKeyName, s2: "preset") == 0 )
  {
    this->m_dpv.preset = atoi(nptr: szValue);
    return true;
  }
  if ( szKeyName == "pitch" || _V_stricmp(s1: szKeyName, s2: "pitch") == 0 )
  {
    v5 = atoi(nptr: szValue);
    this->m_dpv.pitchrun = v5;
    if ( v5 > 255 )
      this->m_dpv.pitchrun = 255;
    if ( this->m_dpv.pitchrun < 0 )
    {
      this->m_dpv.pitchrun = 0;
      return true;
    }
    return true;
  }
  if ( szKeyName == "pitchstart" || _V_stricmp(s1: szKeyName, s2: "pitchstart") == 0 )
  {
    v6 = atoi(nptr: szValue);
    this->m_dpv.pitchstart = v6;
    if ( v6 > 255 )
      this->m_dpv.pitchstart = 255;
    if ( this->m_dpv.pitchstart < 0 )
    {
      this->m_dpv.pitchstart = 0;
      return true;
    }
    return true;
  }
  if ( szKeyName != "spinup" && _V_stricmp(s1: szKeyName, s2: "spinup") != 0 )
  {
    if ( szKeyName != "spindown" && _V_stricmp(s1: szKeyName, s2: "spindown") != 0 )
    {
      if ( FStrEq(sz1: szKeyName, sz2: "volstart") )
      {
        v11 = atoi(nptr: szValue);
        this->m_dpv.volstart = v11;
        if ( v11 > 10 )
          this->m_dpv.volstart = 10;
        if ( this->m_dpv.volstart < 0 )
          this->m_dpv.volstart = 0;
        this->m_dpv.volstart *= 10;
        return true;
      }
      else if ( FStrEq(sz1: szKeyName, sz2: "fadein") )
      {
        v12 = atoi(nptr: szValue);
        this->m_dpv.fadein = v12;
        if ( v12 > 100 )
          this->m_dpv.fadein = 100;
        if ( this->m_dpv.fadein < 0 )
          this->m_dpv.fadein = 0;
        fadein = this->m_dpv.fadein;
        if ( fadein > 0 )
          this->m_dpv.fadein = (101 - fadein) << 6;
        this->m_dpv.fadeinsav = this->m_dpv.fadein;
        return true;
      }
      else if ( FStrEq(sz1: szKeyName, sz2: "fadeout") )
      {
        v14 = atoi(nptr: szValue);
        this->m_dpv.fadeout = v14;
        if ( v14 > 100 )
          this->m_dpv.fadeout = 100;
        if ( this->m_dpv.fadeout < 0 )
          this->m_dpv.fadeout = 0;
        fadeout = this->m_dpv.fadeout;
        if ( fadeout > 0 )
          this->m_dpv.fadeout = (101 - fadeout) << 6;
        this->m_dpv.fadeoutsav = this->m_dpv.fadeout;
        return true;
      }
      else if ( FStrEq(sz1: szKeyName, sz2: "fadeinsecs") )
      {
        v16 = atoi(nptr: szValue);
        this->m_dpv.fadein = v16;
        if ( v16 > 100 )
          this->m_dpv.fadein = 100;
        if ( this->m_dpv.fadein < 0 )
          this->m_dpv.fadein = 0;
        v17 = this->m_dpv.fadein;
        if ( v17 > 0 )
          this->m_dpv.fadein = 25600 / (5 * v17);
        this->m_dpv.fadeinsav = this->m_dpv.fadein;
        return true;
      }
      else if ( FStrEq(sz1: szKeyName, sz2: "fadeoutsecs") )
      {
        v18 = atoi(nptr: szValue);
        this->m_dpv.fadeout = v18;
        if ( v18 > 100 )
          this->m_dpv.fadeout = 100;
        if ( this->m_dpv.fadeout < 0 )
          this->m_dpv.fadeout = 0;
        v19 = this->m_dpv.fadeout;
        if ( v19 > 0 )
          this->m_dpv.fadeout = 25600 / (5 * v19);
        this->m_dpv.fadeoutsav = this->m_dpv.fadeout;
        return true;
      }
      else
      {
        if ( FStrEq(sz1: szKeyName, sz2: "lfotype") )
        {
          v20 = atoi(nptr: szValue);
          this->m_dpv.lfotype = v20;
          if ( v20 > 4 )
          {
            this->m_dpv.lfotype = 2;
            return true;
          }
          return true;
        }
        if ( FStrEq(sz1: szKeyName, sz2: "lforate") )
        {
          v21 = atoi(nptr: szValue);
          this->m_dpv.lforate = v21;
          if ( v21 > 1000 )
            this->m_dpv.lforate = 1000;
          if ( this->m_dpv.lforate < 0 )
            this->m_dpv.lforate = 0;
          this->m_dpv.lforate <<= 8;
          return true;
        }
        else
        {
          if ( FStrEq(sz1: szKeyName, sz2: "lfomodpitch") )
          {
            v22 = atoi(nptr: szValue);
            this->m_dpv.lfomodpitch = v22;
            if ( v22 > 100 )
              this->m_dpv.lfomodpitch = 100;
            if ( this->m_dpv.lfomodpitch < 0 )
            {
              this->m_dpv.lfomodpitch = 0;
              return true;
            }
            return true;
          }
          if ( FStrEq(sz1: szKeyName, sz2: "lfomodvol") )
          {
            v23 = atoi(nptr: szValue);
            this->m_dpv.lfomodvol = v23;
            if ( v23 > 100 )
              this->m_dpv.lfomodvol = 100;
            if ( this->m_dpv.lfomodvol < 0 )
            {
              this->m_dpv.lfomodvol = 0;
              return true;
            }
            return true;
          }
          if ( FStrEq(sz1: szKeyName, sz2: "cspinup") )
          {
            v24 = atoi(nptr: szValue);
            this->m_dpv.cspinup = v24;
            if ( v24 > 100 )
              this->m_dpv.cspinup = 100;
            if ( this->m_dpv.cspinup < 0 )
              this->m_dpv.cspinup = 0;
            return true;
          }
          return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
        }
      }
    }
    else
    {
      v9 = atoi(nptr: szValue);
      this->m_dpv.spindown = v9;
      if ( v9 > 100 )
        this->m_dpv.spindown = 100;
      if ( this->m_dpv.spindown < 0 )
        this->m_dpv.spindown = 0;
      spindown = this->m_dpv.spindown;
      if ( spindown > 0 )
        this->m_dpv.spindown = (101 - spindown) << 6;
      this->m_dpv.spindownsav = this->m_dpv.spindown;
      return true;
    }
  }
  else
  {
    v7 = atoi(nptr: szValue);
    this->m_dpv.spinup = v7;
    if ( v7 > 100 )
      this->m_dpv.spinup = 100;
    if ( this->m_dpv.spinup < 0 )
      this->m_dpv.spinup = 0;
    spinup = this->m_dpv.spinup;
    if ( spinup > 0 )
      this->m_dpv.spinup = (101 - spinup) << 6;
    this->m_dpv.spinupsav = this->m_dpv.spinup;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091E20
// Name: public: virtual void CAmbientGeneric::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAmbientGeneric::Spawn(CAmbientGeneric *this@<ecx>, int a2@<ebp>)
{
  __m128 m_radius_low; // xmm0
  soundlevel_t v4; // eax
  double v5; // xmm0_8
  const char *pszValue; // eax
  CAmbientGeneric_vtbl *v7; // edx
  const char *v8; // edi
  const char *DebugName; // eax
  double x; // [esp+0h] [ebp-20h]
  double y; // [esp+8h] [ebp-18h]
  double z; // [esp+10h] [ebp-10h]

  m_radius_low = (__m128)LODWORD(this->m_radius);
  v4 = SNDLVL_NONE;
  if ( m_radius_low.m128_f32[0] > 0.0 && (this->m_spawnflags.m_Value & 1) == 0 )
  {
    m_radius_low.m128_f32[0] = m_radius_low.m128_f32[0] * 0.027777778;
    __libm_sse2_log10(a1: _mm_cvtps_pd(m_radius_low));
    *(float *)&v5 = v5 * 20.0;
    v4 = (int)(float)(*(float *)&v5 + 40.0);
  }
  this->m_iSoundLevel = v4;
  CAmbientGeneric::ComputeMaxAudibleDistance(this);
  pszValue = this->m_iszSound.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( this->m_iszSound.pszValue != nullptr && strlen(pszValue) != 0 )
  {
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAmbientGeneric::RampThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    this->m_fLooping = (this->m_spawnflags.m_Value & 0x20) == 0;
    this->m_fActive = false;
    this->m_hSoundSource.m_Index = -1;
    v7 = this->__vftable;
    this->m_nSoundSourceEntIndex = -1;
    v7->Precache(this);
    CAmbientGeneric::InitModulationParms(this);
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    v8 = this->m_iClassname.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    z = this->m_vecAbsOrigin.z;
    y = this->m_vecAbsOrigin.y;
    x = this->m_vecAbsOrigin.x;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "Empty %s (%s) at %.2f, %.2f, %.2f\n", v8, DebugName, x, y, z);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091FD0
// Name: public: virtual void CAmbientGeneric::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::Activate(CAmbientGeneric *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int v5; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v13; // eax
  signed int v14; // eax
  unsigned int v15; // eax
  edict_t *m_pPev; // eax
  MapLoadType_t eLoadType; // eax
  int v18; // edi
  const char *v19; // eax
  SoundFlags_t v20; // edi
  bool v21; // al
  CSoundParameters params; // [esp+18h] [ebp-B4h] BYREF

  CBaseEntity::Activate(this);
  m_Index = this->m_hSoundSource.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    pszValue = this->m_sSourceEntName.pszValue;
    if ( pszValue != nullptr )
    {
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      this->m_hSoundSource.m_Index = EntityByName != nullptr
                                   ? EntityByName->GetRefEHandle(this: EntityByName)->m_Index
                                   : -1;
      v5 = this->m_hSoundSource.m_Index;
      if ( v5 != -1 )
      {
        v6 = (unsigned __int16)v5;
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5];
        v8 = HIWORD(v5);
        if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = &g_pEntityList->m_EntPtrArray[v9];
          if ( v10 )
            m_pEntity = v11->m_pEntity;
          else
            m_pEntity = nullptr;
          v13 = m_pEntity[6].__vftable;
          if ( v13 != nullptr )
            v14 = ((char *)v13 - (char *)gpGlobals->pEdicts) >> 4;
          else
            v14 = 0;
          this->m_nSoundSourceEntIndex = v14;
        }
      }
    }
    v15 = this->m_hSoundSource.m_Index;
    if ( v15 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber == HIWORD(v15)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity != nullptr )
    {
      if ( (this->m_spawnflags.m_Value & 1) == 0 )
      {
        this->m_iEFlags |= 0x80u;
        CBaseEntity::DispatchUpdateTransmitState(this);
      }
    }
    else
    {
      this->m_hSoundSource.m_Index = this->GetRefEHandle(this)->m_Index;
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        this->m_nSoundSourceEntIndex = m_pPev - gpGlobals->pEdicts;
      else
        this->m_nSoundSourceEntIndex = 0;
    }
  }
  if ( this->m_fActive )
  {
    eLoadType = gpGlobals->eLoadType;
    v18 = 8;
    if ( eLoadType == MapLoad_Transition
      || eLoadType == MapLoad_LoadGame
      || g_pGameRules->InRoundRestart(this: g_pGameRules) )
    {
      v18 = 0;
    }
    params.pitch = 100;
    params.pitchlow = 100;
    params.pitchhigh = 100;
    v19 = this->m_iszSound.pszValue;
    v20 = v18 | 3;
    params.channel = 0;
    params.volume = 1.0;
    params.soundlevel = SNDLVL_NORM;
    params.soundname[0] = 0;
    params.play_to_owner_only = false;
    params.count = 0;
    params.delay_msec = 0;
    params.m_nSoundEntryVersion = 1;
    params.m_hSoundScriptHandle = -1;
    params.m_pOperatorsKV = nullptr;
    params.m_nRandomSeed = -1;
    if ( v19 == nullptr )
      v19 = locale;
    CBaseEntity::GetParametersForSound(soundname: v19, &params, actormodel: nullptr);
    v21 = params.m_hSoundScriptHandle != -1 && params.m_nSoundEntryVersion > 1;
    if ( this->m_dpv.vol > 0 && (gpGlobals->eLoadType != MapLoad_LoadGame || !v21) )
      this->SendSound(this, a2: v20);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092250
// Name: public: virtual void CAmbientGeneric::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::SetTransmit(CAmbientGeneric *this, CCheckTransmitInfo *pInfo, bool bAlways)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CAmbientGeneric **v10; // eax
  CAmbientGeneric *v11; // eax
  CBaseEntity *m_pUnk; // edi
  CBaseEntity *v13; // eax
  const Vector *AbsOrigin; // esi
  const Vector *v15; // eax
  CBaseEntity *v16; // eax
  CHandle<CBaseEntity> *p_m_hSoundSource; // [esp+4h] [ebp-4h]

  m_Index = this->m_hSoundSource.m_Index;
  p_m_hSoundSource = &this->m_hSoundSource;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = (CAmbientGeneric **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = *v10;
      else
        v11 = nullptr;
      if ( v11 != this && this->m_fActive && (this->m_spawnflags.m_Value & 1) == 0 )
      {
        m_pUnk = (CBaseEntity *)pInfo->m_pClientEnt->m_pUnk;
        if ( m_pUnk != nullptr )
        {
          if ( this->m_flMaxRadius < 0.0
            || (v13 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hSoundSource),
                AbsOrigin = CBaseEntity::GetAbsOrigin(this: v13),
                v15 = CBaseEntity::GetAbsOrigin(this: m_pUnk),
                (float)(this->m_flMaxRadius * this->m_flMaxRadius) >= (float)((float)((float)((float)(v15->y - AbsOrigin->y)
                                                                                            * (float)(v15->y - AbsOrigin->y))
                                                                                    + (float)((float)(v15->x - AbsOrigin->x)
                                                                                            * (float)(v15->x - AbsOrigin->x)))
                                                                            + (float)((float)(v15->z - AbsOrigin->z)
                                                                                    * (float)(v15->z - AbsOrigin->z)))) )
          {
            v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: p_m_hSoundSource);
            v16->SetTransmit(this: v16, a2: pInfo, a3: false);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100923C0
// Name: public: virtual void CAmbientGeneric::ToggleSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::ToggleSound(CAmbientGeneric *this)
{
  int cspinup; // ebx
  int cspincount; // ecx
  int pitchstart; // edi
  int v5; // ecx
  int v6; // edi
  int v7; // edi
  edict_t *m_pPev; // ecx
  int spindownsav; // eax
  int fadeoutsav; // eax

  if ( this->m_fActive )
  {
    cspinup = this->m_dpv.cspinup;
    if ( cspinup != 0 )
    {
      cspincount = this->m_dpv.cspincount;
      if ( cspincount <= cspinup )
      {
        pitchstart = this->m_dpv.pitchstart;
        this->m_dpv.spinup = this->m_dpv.spinupsav;
        this->m_dpv.spindown = 0;
        v5 = cspincount + 1;
        this->m_dpv.cspincount = v5;
        v6 = v5 * ((255 - pitchstart) / cspinup) + pitchstart;
        this->m_dpv.pitchrun = v6;
        if ( v6 > 255 )
          this->m_dpv.pitchrun = 255;
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
      }
    }
    else
    {
      this->m_fActive = false;
      v7 = this->m_spawnflags.m_Value | 0x10;
      if ( this->m_spawnflags.m_Value != v7 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
        }
        this->m_spawnflags.m_Value = v7;
      }
      spindownsav = this->m_dpv.spindownsav;
      if ( spindownsav != 0 || this->m_dpv.fadeoutsav != 0 )
      {
        this->m_dpv.spindown = spindownsav;
        fadeoutsav = this->m_dpv.fadeoutsav;
        this->m_dpv.spinup = 0;
        this->m_dpv.fadeout = fadeoutsav;
        this->m_dpv.fadein = 0;
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
      }
      else
      {
        this->SendSound(this, a2: SND_STOP);
      }
    }
  }
  else
  {
    if ( this->m_fLooping )
      this->m_fActive = true;
    else
      this->SendSound(this, a2: SND_STOP);
    CAmbientGeneric::InitModulationParms(this);
    this->SendSound(this, a2: SND_NOFLAGS);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180FD0
// Name: public: void CAmbientGeneric::InputToggleSound(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAmbientGeneric::InputToggleSound(CAmbientGeneric *this, inputdata_t *inputdata)
{
  this->ToggleSound(this);
}

//------------------------------------------------------------------------------
// Address: 0x103FEFF0
// Name: _dynamic_initializer_for__ambient_generic__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__ambient_generic__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAmbientGeneric> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ambient_generic,
           a3: "ambient_generic");
}

//------------------------------------------------------------------------------
// Address: 0x103FF010
// Name: CAmbientGeneric_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAmbientGeneric_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAmbientGeneric>(__formal: nullptr);
  CAmbientGeneric_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404E40
// Name: _dynamic_initializer_for__generic_actor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__generic_actor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGenericActor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &generic_actor,
           a3: "generic_actor");
}

//------------------------------------------------------------------------------
// Address: 0x10092540
// Name: struct datamap_t __near * DataMapInit<class CAmbientGeneric>(class CAmbientGeneric __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAmbientGeneric>()
{
  if ( (_S2_41 & 1) == 0 )
  {
    _S2_41 |= 1u;
    nameHolder_80.m_pszBase = "CAmbientGeneric";
    nameHolder_80.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_80.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_80.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_80.m_Names.m_Size = 0;
    nameHolder_80.m_Names.m_pElements = nullptr;
    nameHolder_80.m_nLenBase = 15;
    atexit(func: DataMapInit_CAmbientGeneric__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAmbientGeneric::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_41 & 2) == 0 )
  {
    _S2_41 |= 2u;
    dataDesc_77[9].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_80,
                                 pszIdentifier: "RampThink");
    dataDesc_77[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_77[9].td = 0;
    *(_QWORD *)&dataDesc_77[9].override_field = 0;
    *(_QWORD *)&dataDesc_77[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[9].flatOffset[1] = 0;
    dataDesc_77[9].flags = 32;
    dataDesc_77[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_77[10].td = 0;
    *(_QWORD *)&dataDesc_77[10].override_field = 0;
    *(_QWORD *)&dataDesc_77[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[10].flatOffset[1] = 0;
    dataDesc_77[10].flags = 8;
    dataDesc_77[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_77[11].td = 0;
    *(_QWORD *)&dataDesc_77[11].override_field = 0;
    *(_QWORD *)&dataDesc_77[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[11].flatOffset[1] = 0;
    dataDesc_77[11].flags = 8;
    dataDesc_77[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_77[12].td = 0;
    *(_QWORD *)&dataDesc_77[12].override_field = 0;
    *(_QWORD *)&dataDesc_77[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[12].flatOffset[1] = 0;
    dataDesc_77[9].fieldOffset = 0;
    dataDesc_77[9].externalName = nullptr;
    dataDesc_77[9].pSaveRestoreOps = nullptr;
    dataDesc_77[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::RampThink;
    dataDesc_77[10].fieldType = FIELD_VOID;
    dataDesc_77[10].fieldName = "InputPlaySound";
    dataDesc_77[10].fieldOffset = 0;
    dataDesc_77[10].externalName = "PlaySound";
    dataDesc_77[10].pSaveRestoreOps = nullptr;
    dataDesc_77[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputPlaySound;
    dataDesc_77[11].fieldType = FIELD_VOID;
    dataDesc_77[11].fieldName = "InputStopSound";
    dataDesc_77[11].fieldOffset = 0;
    dataDesc_77[11].externalName = "StopSound";
    dataDesc_77[11].pSaveRestoreOps = nullptr;
    dataDesc_77[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputStopSound;
    dataDesc_77[12].fieldType = FIELD_VOID;
    dataDesc_77[12].fieldName = "InputToggleSound";
    dataDesc_77[12].fieldOffset = 0;
    dataDesc_77[12].flags = 8;
    dataDesc_77[12].externalName = "ToggleSound";
    dataDesc_77[12].pSaveRestoreOps = nullptr;
    dataDesc_77[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputToggleSound;
    dataDesc_77[13].fieldType = FIELD_FLOAT;
    dataDesc_77[13].fieldName = "InputPitch";
    dataDesc_77[13].fieldOffset = 0;
    dataDesc_77[13].fieldSize = 1;
    dataDesc_77[13].flags = 8;
    dataDesc_77[13].externalName = "Pitch";
    dataDesc_77[13].pSaveRestoreOps = nullptr;
    dataDesc_77[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputPitch;
    *(_QWORD *)&dataDesc_77[13].td = 0;
    *(_QWORD *)&dataDesc_77[13].override_field = 0;
    *(_QWORD *)&dataDesc_77[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[13].flatOffset[1] = 0;
    dataDesc_77[14].fieldType = FIELD_FLOAT;
    dataDesc_77[14].fieldName = "InputVolume";
    dataDesc_77[14].fieldOffset = 0;
    *(_QWORD *)&dataDesc_77[14].td = 0;
    *(_QWORD *)&dataDesc_77[14].override_field = 0;
    *(_QWORD *)&dataDesc_77[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[14].flatOffset[1] = 0;
    dataDesc_77[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_77[15].td = 0;
    *(_QWORD *)&dataDesc_77[15].override_field = 0;
    *(_QWORD *)&dataDesc_77[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[15].flatOffset[1] = 0;
    dataDesc_77[14].flags = 8;
    dataDesc_77[14].externalName = "Volume";
    dataDesc_77[14].pSaveRestoreOps = nullptr;
    dataDesc_77[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputVolume;
    dataDesc_77[15].fieldType = FIELD_FLOAT;
    dataDesc_77[15].fieldName = "InputFadeIn";
    dataDesc_77[15].fieldOffset = 0;
    *(_DWORD *)&dataDesc_77[15].fieldSize = 524289;
    dataDesc_77[15].externalName = "FadeIn";
    dataDesc_77[15].pSaveRestoreOps = nullptr;
    dataDesc_77[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputFadeIn;
    dataDesc_77[16].fieldType = FIELD_FLOAT;
    dataDesc_77[16].fieldName = "InputFadeOut";
    dataDesc_77[16].fieldOffset = 0;
    *(_DWORD *)&dataDesc_77[16].fieldSize = 524289;
    dataDesc_77[16].externalName = "FadeOut";
    dataDesc_77[16].pSaveRestoreOps = nullptr;
    dataDesc_77[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputFadeOut;
    *(_QWORD *)&dataDesc_77[16].td = 0;
    *(_QWORD *)&dataDesc_77[16].override_field = 0;
    *(_QWORD *)&dataDesc_77[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_77[16].flatOffset[1] = 0;
  }
  CAmbientGeneric::m_DataMap.dataNumFields = 16;
  CAmbientGeneric::m_DataMap.dataDesc = &dataDesc_77[1];
  return &CAmbientGeneric::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FF020
// Name: _dynamic_initializer_for__sv_showanimstate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_showanimstate__()
{
  ConVar::ConVar(
    this: &sv_showanimstate,
    pName: "sv_showanimstate",
    pDefaultValue: "-1",
    flags: 16386,
    pHelpString: "Show the (server) animation state for the specified entity (-1 for none).");
  return atexit(func: dynamic_atexit_destructor_for__sv_showanimstate__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF050
// Name: _dynamic_initializer_for__showanimstate_log__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showanimstate_log__()
{
  ConVar::ConVar(
    this: &showanimstate_log,
    pName: "sv_showanimstate_log",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "1 to output sv_showanimstate to Msg(). 2 to store in AnimStateServer.log. 3 for both.");
  return atexit(func: dynamic_atexit_destructor_for__showanimstate_log__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF080
// Name: _dynamic_initializer_for__showanimstate_activities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showanimstate_activities__()
{
  ConVar::ConVar(
    this: &showanimstate_activities,
    pName: "sv_showanimstate_activities",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "Show activities in the (server) animation state display.");
  return atexit(func: dynamic_atexit_destructor_for__showanimstate_activities__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF0B0
// Name: _dynamic_initializer_for__mp_feetyawrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_feetyawrate__()
{
  ConVar::ConVar(
    this: &mp_feetyawrate,
    pName: "mp_feetyawrate",
    pDefaultValue: "720",
    flags: 8194,
    pHelpString: "How many degrees per second that we can turn our feet or upper body.");
  return atexit(func: dynamic_atexit_destructor_for__mp_feetyawrate__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF0E0
// Name: _dynamic_initializer_for__mp_facefronttime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_facefronttime__()
{
  ConVar::ConVar(
    this: &mp_facefronttime,
    pName: "mp_facefronttime",
    pDefaultValue: "3",
    flags: 8194,
    pHelpString: "After this amount of time of standing in place but aiming to one side, go ahead and move feet to face upper body.");
  return atexit(func: dynamic_atexit_destructor_for__mp_facefronttime__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF110
// Name: _dynamic_initializer_for__mp_ik__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_ik__()
{
  ConVar::ConVar(
    this: &mp_ik,
    pName: "mp_ik",
    pDefaultValue: "1",
    flags: 8194,
    pHelpString: "Use IK on in-place turns.");
  return atexit(func: dynamic_atexit_destructor_for__mp_ik__);
}
