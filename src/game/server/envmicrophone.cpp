// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envmicrophone.cpp
// Functions: 19
// ============================================================

#include "game\server\envmicrophone.h"

//------------------------------------------------------------------------------
// Address: 0x1011EBB0
// Name: public: virtual struct datamap_t __near * CEnvMicrophone::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvMicrophone::GetDataDescMap(CEnvMicrophone *this)
{
  return &CEnvMicrophone::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011EBC0
// Name: public: virtual void CEnvMicrophone::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::Spawn(CEnvMicrophone *this)
{
  int m_Value; // eax
  float m_flSensitivity; // xmm0_4
  float m_flSmoothFactor; // xmm0_4
  bool v4; // zf

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & nFlags[0][0]) != 0 )
    this->m_nSoundMask |= dword_1058A0C8;
  if ( (m_Value & dword_1058A0CC) != 0 )
    this->m_nSoundMask |= dword_1058A0D0;
  if ( (m_Value & dword_1058A0D4) != 0 )
    this->m_nSoundMask |= dword_1058A0D8;
  if ( (m_Value & dword_1058A0DC) != 0 )
    this->m_nSoundMask |= dword_1058A0E0;
  if ( (m_Value & dword_1058A0E4) != 0 )
    this->m_nSoundMask |= dword_1058A0E8;
  m_flSensitivity = this->m_flSensitivity;
  if ( m_flSensitivity == 0.0 )
  {
    this->m_flSensitivity = 1.0;
  }
  else if ( m_flSensitivity > 10.0 )
  {
    this->m_flSensitivity = 10.0;
  }
  m_flSmoothFactor = this->m_flSmoothFactor;
  if ( m_flSmoothFactor >= 0.0 )
  {
    if ( m_flSmoothFactor > 0.9 )
      m_flSmoothFactor = 0.89999998;
  }
  else
  {
    m_flSmoothFactor = 0.0;
  }
  v4 = !this->m_bDisabled;
  this->m_flSmoothFactor = m_flSmoothFactor;
  if ( v4 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011ECC0
// Name: public: bool CEnvMicrophone::CanHearSound(class CSound __near *,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CEnvMicrophone::CanHearSound@<al>(
        CEnvMicrophone *this@<ecx>,
        int a2@<ebp>,
        CSound *pSound,
        float *flVolume)
{
  unsigned int m_Index; // eax
  CBaseEntityList *v6; // esi
  CBaseFilter *m_pEntity; // ecx
  unsigned int v8; // eax
  CBaseEntity *v9; // edx
  unsigned int v10; // eax
  CBaseEntity *v11; // esi
  const Vector *SoundOrigin; // eax
  float v13; // xmm1_4
  float m_flMaxRange; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // [esp-10h] [ebp-1Ch]
  _DWORD v19[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v19[0] = a2;
  v19[1] = retaddr;
  *flVolume = 0.0;
  if ( this->m_bDisabled )
    return 0;
  m_Index = this->m_hListenFilter.m_Index;
  if ( m_Index == -1 )
  {
LABEL_9:
    v6 = g_pEntityList;
    goto LABEL_10;
  }
  v6 = g_pEntityList;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v8 = pSound->m_hOwner.m_Index;
      if ( pSound->m_hOwner.m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8) )
      {
        v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
        if ( v9 != nullptr && CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: v9) )
          goto LABEL_9;
      }
      return 0;
    }
  }
LABEL_10:
  v10 = this->m_hMeasureTarget.m_Index;
  if ( v10 == -1 || v6->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
    v11 = nullptr;
  else
    v11 = (CBaseEntity *)v6->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
  if ( (v11->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)v19);
  SoundOrigin = CSound::GetSoundOrigin(this: pSound);
  v13 = SoundOrigin->y - v11->m_vecAbsOrigin.y;
  v18 = fsqrt(
          (float)((float)(v13 * v13)
                + (float)((float)(SoundOrigin->z - v11->m_vecAbsOrigin.z)
                        * (float)(SoundOrigin->z - v11->m_vecAbsOrigin.z)))
        + (float)((float)(SoundOrigin->x - v11->m_vecAbsOrigin.x) * (float)(SoundOrigin->x - v11->m_vecAbsOrigin.x)));
  if ( v18 == 0.0 )
  {
    *flVolume = 1.0;
    return 1;
  }
  m_flMaxRange = this->m_flMaxRange;
  if ( m_flMaxRange != 0.0 && v18 > m_flMaxRange )
    return 0;
  v16 = (float)pSound->m_iVolume * this->m_flSensitivity;
  if ( v16 < v18 )
    return 0;
  v17 = 1.0 - (float)(v18 / v16);
  *flVolume = v17;
  if ( v17 >= 0.0 )
  {
    if ( v17 > 1.0 )
      v17 = 1.0;
    *flVolume = v17;
    return 1;
  }
  else
  {
    *flVolume = 0.0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EEC0
// Name: public: bool CEnvMicrophone::CanHearSound(int,enum soundlevel_t,float __near &,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CEnvMicrophone::CanHearSound@<al>(
        CEnvMicrophone *this@<ecx>,
        int a2@<ebp>,
        int entindex,
        soundlevel_t soundlevel,
        float *flVolume,
        const Vector *pOrigin)
{
  CEnvMicrophone *v6; // edx
  CBaseEntity *v8; // edi
  edict_t *pEdicts; // esi
  edict_t *v10; // eax
  IServerUnknown *m_pUnk; // ecx
  int v12; // eax
  unsigned int m_Index; // eax
  CBaseFilter *m_pEntity; // ecx
  const Vector *v15; // edx
  __int128 v16; // xmm0
  unsigned int v17; // eax
  CBaseEntity *v18; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  CBaseEntity *v22; // eax
  float *v23; // eax
  float v24; // xmm1_4
  float m_flMaxRange; // xmm1_4
  float v26; // xmm0_4
  int v27; // [esp+4h] [ebp-3Ch]
  int v28; // [esp+8h] [ebp-38h]
  int v29; // [esp+Ch] [ebp-34h]
  int v30; // [esp+10h] [ebp-30h]
  __int128 v31; // [esp+14h] [ebp-2Ch]
  int v32; // [esp+24h] [ebp-1Ch]
  int v33; // [esp+28h] [ebp-18h]
  int v34; // [esp+2Ch] [ebp-14h]
  float v36; // [esp+30h] [ebp-10h]
  _DWORD v37[2]; // [esp+34h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h]

  v37[0] = a2;
  v37[1] = retaddr;
  v6 = this;
  if ( this->m_bDisabled )
  {
    *flVolume = 0.0;
    return false;
  }
  if ( (this->m_spawnflags.m_Value & 0x40) != 0 && soundlevel == SNDLVL_NONE )
    return false;
  v8 = nullptr;
  if ( entindex != 0 )
  {
    pEdicts = gpGlobals->pEdicts;
    if ( pEdicts != nullptr )
      v10 = (pEdicts[entindex].m_fStateFlags & 2) == 0 ? &pEdicts[entindex] : nullptr;
    else
      v10 = nullptr;
    if ( (v10 != nullptr || pEdicts != nullptr && (v10 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
      && (m_pUnk = v10->m_pUnk) != nullptr )
    {
      v12 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v6 = this;
    }
    else
    {
      v12 = 0;
    }
    v8 = (CBaseEntity *)v12;
  }
  m_Index = v6->m_hListenFilter.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr
      && (v8 == nullptr || !CBaseFilter::PassesFilter(this: m_pEntity, pCaller: v6, pEntity: v8)) )
    {
      *flVolume = 0.0;
      return false;
    }
  }
  v15 = pOrigin;
  LODWORD(v16) = 0;
  if ( pOrigin != nullptr )
  {
    v17 = this->m_hMeasureTarget.m_Index;
    if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
      v18 = nullptr;
    else
      v18 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
    if ( (v18->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v18, a2: (int)v37);
      v15 = pOrigin;
    }
    x = v15->x;
    y = v15->y;
    z = v15->z;
  }
  else
  {
    if ( v8 == nullptr )
      goto LABEL_36;
    v22 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hMeasureTarget);
    v18 = v22;
    if ( (v22->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v22, a2: (int)v37);
    v23 = (float *)v8->WorldSpaceCenter(this: v8);
    x = *v23;
    y = v23[1];
    z = v23[2];
  }
  v24 = (float)((float)((float)(y - v18->m_vecAbsOrigin.y) * (float)(y - v18->m_vecAbsOrigin.y))
              + (float)((float)(z - v18->m_vecAbsOrigin.z) * (float)(z - v18->m_vecAbsOrigin.z)))
      + (float)((float)(x - v18->m_vecAbsOrigin.x) * (float)(x - v18->m_vecAbsOrigin.x));
  v16 = 0;
  *(float *)&v16 = fsqrt(v24);
  v31 = v16;
LABEL_36:
  m_flMaxRange = this->m_flMaxRange;
  if ( m_flMaxRange != 0.0 && *(float *)&v16 > m_flMaxRange )
    return false;
  v36 = ((double (__stdcall *)(soundlevel_t, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))enginesound->GetDistGainFromSoundLevel)(
          a1: soundlevel,
          a2: v16,
          a3: v27,
          a4: v28,
          a5: v29,
          a6: v30,
          a7: v31,
          a8: DWORD1(v31),
          a9: DWORD2(v31),
          a10: HIDWORD(v31),
          a11: v32,
          a12: v33,
          a13: v34);
  v26 = *flVolume * v36;
  *flVolume = v26;
  return v26 > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1011F120
// Name: private: void CEnvMicrophone::SoundStopped(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::SoundStopped(CEnvMicrophone *this, const char *soundname)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  signed int v10; // eax

  m_Index = this->m_hSpeaker.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      v10 = (signed int)m_pEntity[6].__vftable;
      if ( v10 != 0 )
        v10 = (signed int)(v10 - (unsigned int)gpGlobals->pEdicts) >> 4;
      CBaseEntity::StopSound(iEntIndex: v10, iChannel: 6, pSample: soundname, bIsStoppingSpeakerSound: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F190
// Name: public: virtual void CEnvMicrophone::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::Think(CEnvMicrophone *this)
{
  int active; // eax
  float value; // xmm0_4
  char v4; // bl
  CSound *v5; // esi
  float flVal; // xmm2_4
  CEntityOutputTemplate<float,1> *p_m_SoundLevel; // ecx
  float flVolume; // [esp+14h] [ebp-8h] BYREF
  float flMaxVolume; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  active = CSoundEnt::ActiveList();
  value = 0.0;
  v4 = 0;
  flMaxVolume = 0.0;
  if ( active != -1 )
  {
    do
    {
      v5 = CSoundEnt::SoundPointerForIndex(iIndex: active);
      if ( v5 != nullptr
        && (this->m_nSoundMask & v5->m_iType) != 0
        && (flVolume = 0.0, CEnvMicrophone::CanHearSound(this, a2: (int)&savedregs, pSound: v5, &flVolume) != 0) )
      {
        value = flMaxVolume;
        if ( flVolume > flMaxVolume )
        {
          value = flVolume;
          flMaxVolume = flVolume;
          v4 = 1;
        }
      }
      else
      {
        value = flMaxVolume;
      }
      active = v5->m_iNext;
    }
    while ( active != -1 );
    if ( v4 != 0 )
    {
      COutputEvent::FireOutput(this: &this->m_OnHeardSound, pActivator: this, pCaller: this, fDelay: 0.0);
      value = flMaxVolume;
    }
  }
  flVal = this->m_SoundLevel.m_Value.flVal;
  p_m_SoundLevel = &this->m_SoundLevel;
  if ( value != flVal )
  {
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(value - flVal) & _mask__AbsFloat_) >= 0.0049999999 )
      CEntityOutputTemplate<float,1>::Set(
        this: p_m_SoundLevel,
        value: (float)((float)(1.0 - this->m_flSmoothFactor) * value) + (float)(this->m_flSmoothFactor * flVal),
        pActivator: this,
        pCaller: this);
    else
      CEntityOutputTemplate<float,1>::Set(this: p_m_SoundLevel, value, pActivator: this, pCaller: this);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011F2C0
// Name: public: static void CEnvMicrophone::OnSoundStopped(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEnvMicrophone::OnSoundStopped(const char *soundname)
{
  int v1; // edi
  CBaseEntityList *v2; // edx
  CHandle<CEnvMicrophone> *m_pMemory; // esi
  unsigned int m_Index; // eax
  unsigned int v5; // eax
  CEnvMicrophone *m_pEntity; // ecx

  if ( s_Microphones.m_Size > 0 )
  {
    v1 = s_Microphones.m_Size - 1;
    if ( s_Microphones.m_Size - 1 >= 0 )
    {
      v2 = g_pEntityList;
      m_pMemory = s_Microphones.m_Memory.m_pMemory;
      do
      {
        m_Index = m_pMemory[v1].m_Index;
        if ( m_Index != -1
          && v2->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && v2->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
        {
          v5 = m_pMemory[v1].m_Index;
          if ( v5 == -1 || v2->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
            m_pEntity = nullptr;
          else
            m_pEntity = (CEnvMicrophone *)v2->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
          CEnvMicrophone::SoundStopped(this: m_pEntity, soundname);
          m_pMemory = s_Microphones.m_Memory.m_pMemory;
          v2 = g_pEntityList;
        }
        --v1;
      }
      while ( v1 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F350
// Name: public: CEnvMicrophone::CEnvMicrophone(void)
// Source: json
//------------------------------------------------------------------------------
CEnvMicrophone *__thiscall CEnvMicrophone::CEnvMicrophone(CEnvMicrophone *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CEnvMicrophone_vtbl *)&CEnvMicrophone::`vftable';
  this->m_hMeasureTarget.m_Index = -1;
  this->m_hSpeaker.m_Index = -1;
  this->m_hListenFilter.m_Index = -1;
  this->m_SoundLevel.m_Value.iVal = 0;
  this->m_SoundLevel.m_Value.eVal.m_Index = -1;
  this->m_SoundLevel.m_Value.fieldType = FIELD_VOID;
  this->m_OnRoutedSound.m_Value.iVal = 0;
  this->m_OnRoutedSound.m_Value.eVal.m_Index = -1;
  this->m_OnRoutedSound.m_Value.fieldType = FIELD_VOID;
  this->m_OnHeardSound.m_Value.iVal = 0;
  this->m_OnHeardSound.m_Value.eVal.m_Index = -1;
  this->m_OnHeardSound.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011F3C0
// Name: public: virtual CEnvMicrophone::~CEnvMicrophone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::~CEnvMicrophone(CEnvMicrophone *this)
{
  int v2; // eax
  CHandle<CBaseEntity> src; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (CEnvMicrophone_vtbl *)&CEnvMicrophone::`vftable';
  src.m_Index = CBaseEntity::GetRefEHandle(this)->m_Index;
  v2 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&s_Microphones,
         &src);
  if ( v2 != -1 )
  {
    if ( s_Microphones.m_Size - v2 - 1 > 0 )
      _V_memmove(
        dest: &s_Microphones.m_Memory.m_pMemory[v2],
        src: &s_Microphones.m_Memory.m_pMemory[v2 + 1],
        count: 4 * (s_Microphones.m_Size - v2 - 1));
    --s_Microphones.m_Size;
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnHeardSound);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnRoutedSound);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_SoundLevel);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011F480
// Name: public: void CEnvMicrophone::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::InputDisable(CEnvMicrophone *this, inputdata_t *inputdata)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax
  signed int v11; // eax
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CEnvMicrophone *); // eax
  int v13; // eax
  CHandle<CBaseEntity> src; // [esp+Ch] [ebp-4h] BYREF

  this->m_bDisabled = true;
  m_Index = this->m_hSpeaker.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        m_pEntity = v9->m_pEntity;
      else
        m_pEntity = nullptr;
      v11 = (signed int)m_pEntity[6].__vftable;
      if ( v11 != 0 )
        v11 = (signed int)(v11 - (unsigned int)gpGlobals->pEdicts) >> 4;
      CBaseEntity::StopSound(iEntIndex: v11, iChannel: 6, pSample: this->m_szLastSound, bIsStoppingSpeakerSound: 0);
      GetRefEHandle = this->GetRefEHandle;
      this->m_szLastSound[0] = 0;
      src.m_Index = GetRefEHandle(this)->m_Index;
      v13 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
              this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&s_Microphones,
              &src);
      if ( v13 != -1 )
      {
        if ( s_Microphones.m_Size - v13 - 1 > 0 )
          _V_memmove(
            dest: &s_Microphones.m_Memory.m_pMemory[v13],
            src: &s_Microphones.m_Memory.m_pMemory[v13 + 1],
            count: 4 * (s_Microphones.m_Size - v13 - 1));
        --s_Microphones.m_Size;
      }
    }
  }
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011F600
// Name: public: void CEnvMicrophone::ActivateSpeaker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::ActivateSpeaker(CEnvMicrophone *this)
{
  int m_iSpeakerDSPPreset; // eax
  const char *pszValue; // ecx
  unsigned int m_Index; // edi
  int m_Size; // eax
  int v6; // esi
  CHandle<CEnvMicrophone> *m_pMemory; // ecx
  int v8; // eax
  CHandle<CEnvMicrophone> *v9; // eax
  ConVarRef dsp_speaker; // [esp+4h] [ebp-8h] BYREF

  if ( !this->m_bDisabled )
  {
    ConVarRef::ConVarRef(this: &dsp_speaker, pName: "dsp_speaker");
    if ( ConVarRef::IsValid(this: &dsp_speaker) )
    {
      m_iSpeakerDSPPreset = this->m_iSpeakerDSPPreset;
      if ( m_iSpeakerDSPPreset == 0 )
        m_iSpeakerDSPPreset = atoi(nptr: dsp_speaker.m_pConVarState->m_pszDefaultValue);
      pszValue = this->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      _DevMsg(a1: 2, a2: "Microphone %s set dsp_speaker to %d.\n", pszValue, m_iSpeakerDSPPreset);
      dsp_speaker.m_pConVar->SetValue_2(this: dsp_speaker.m_pConVar, a2: this->m_iSpeakerDSPPreset);
    }
  }
  if ( this->m_iszSpeakerName.pszValue != nullptr )
  {
    dsp_speaker.m_pConVarState = (ConVar *)this->GetRefEHandle(this)->m_Index;
    if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: (CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *)&s_Microphones,
           src: (CHandle<CBaseEntity> *)&dsp_speaker.m_pConVarState) == -1 )
    {
      m_Index = this->GetRefEHandle(this)->m_Index;
      m_Size = s_Microphones.m_Size;
      v6 = s_Microphones.m_Size;
      if ( s_Microphones.m_Size + 1 > s_Microphones.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&s_Microphones,
          num: s_Microphones.m_Size - s_Microphones.m_Memory.m_nAllocationCount + 1);
        m_Size = s_Microphones.m_Size;
      }
      m_pMemory = s_Microphones.m_Memory.m_pMemory;
      s_Microphones.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      s_Microphones.m_pElements = s_Microphones.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(
          dest: &s_Microphones.m_Memory.m_pMemory[v6 + 1],
          src: &s_Microphones.m_Memory.m_pMemory[v6],
          count: 4 * v8);
        m_pMemory = s_Microphones.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        v9->m_Index = m_Index;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F720
// Name: public: void CEnvMicrophone::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::InputEnable(CEnvMicrophone *this, inputdata_t *inputdata)
{
  if ( this->m_bDisabled )
  {
    this->m_bDisabled = false;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
    CEnvMicrophone::ActivateSpeaker(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F7A0
// Name: public: virtual void CEnvMicrophone::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::Activate(CEnvMicrophone *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  void *v4; // eax
  const char *v5; // eax
  CBasePlayer *v6; // eax
  unsigned int m_Index; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  IHandleEntity *v14; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_iszListenFilter.pszValue;
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
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseFilter `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
      this->m_hListenFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
    else
      this->m_hListenFilter.m_Index = -1;
  }
  v5 = this->m_target.pszValue;
  if ( v5 == nullptr )
    goto LABEL_16;
  v6 = CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: v5,
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr);
  this->m_hMeasureTarget.m_Index = v6 != nullptr ? v6->GetRefEHandle(this: v6)->m_Index : -1;
  m_Index = this->m_hMeasureTarget.m_Index;
  if ( m_Index == -1 )
    goto LABEL_16;
  v8 = (unsigned __int16)m_Index;
  v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v10 = HIWORD(m_Index);
  if ( v9->m_SerialNumber != v10 || v9->m_pEntity == nullptr )
    goto LABEL_16;
  v11 = v8;
  v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
  v13 = &g_pEntityList->m_EntPtrArray[v11];
  v14 = v12 ? v13->m_pEntity : nullptr;
  if ( v14[6].__vftable == nullptr )
LABEL_16:
    this->m_hMeasureTarget.m_Index = this->GetRefEHandle(this)->m_Index;
  CEnvMicrophone::ActivateSpeaker(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011F8A0
// Name: public: virtual void CEnvMicrophone::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::OnRestore(CEnvMicrophone *this)
{
  CBaseEntity::OnRestore(this);
  CEnvMicrophone::ActivateSpeaker(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011F8B0
// Name: public: void CEnvMicrophone::InputSetSpeakerName(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMicrophone::InputSetSpeakerName(CEnvMicrophone *this, inputdata_t *inputdata)
{
  variant_t *p_value; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType != FIELD_STRING )
  {
    inputdata = nullptr;
    p_value = (variant_t *)&inputdata;
  }
  this->m_iszSpeakerName.pszValue = (const char *)p_value->iVal;
  this->m_hSpeaker.m_Index = -1;
  CEnvMicrophone::ActivateSpeaker(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011F8F0
// Name: private: enum MicrophoneResult_t CEnvMicrophone::SoundPlayed(int,char const __near *,enum soundlevel_t,float,int,int,class Vector const __near *,float,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEnvMicrophone::SoundPlayed(
        CEnvMicrophone *this,
        int entindex,
        const char *soundname,
        soundlevel_t soundlevel,
        float flVolume,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        float soundtime,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *soundorigins)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  const char *v14; // ecx
  const char *v15; // eax
  CBaseEntity *v16; // eax
  CBaseEntity *v17; // eax
  CBaseEntity *v18; // edi
  edict_t *m_pPev; // eax
  int v20; // edi
  int v21; // ebx
  EmitSound_t ep; // [esp+10h] [ebp-68h] BYREF
  CPASAttenuationFilter filter; // [esp+58h] [ebp-20h] BYREF
  int savedregs; // [esp+78h] [ebp+0h] BYREF

  if ( this->m_bAvoidFeedback || (iFlags & 0x40) != 0 )
    return 0;
  if ( !CEnvMicrophone::CanHearSound(this, a2: (int)&savedregs, entindex, soundlevel, &flVolume, pOrigin) )
    return 0;
  if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hSpeaker) )
  {
    if ( this->m_iszSpeakerName.pszValue != nullptr )
    {
      pszValue = this->m_iszSpeakerName.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      CHandle<CBaseEntity>::operator=(this: &this->m_hSpeaker, val: EntityByName);
      if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hSpeaker) )
      {
        v14 = this->m_iszSpeakerName.pszValue;
        if ( v14 == nullptr )
          v14 = locale;
        v15 = this->m_iName.m_Value.pszValue;
        if ( v15 == nullptr )
          v15 = locale;
        _Warning(a1: "EnvMicrophone %s specifies a non-existent speaker name: %s\n", v15, v14);
        this->m_iszSpeakerName.pszValue = nullptr;
      }
    }
    if ( CHandle<CAI_BaseNPC>::operator!(this: (CHandle<CAI_BaseNPC> *)&this->m_hSpeaker) )
      return 2;
  }
  this->m_bAvoidFeedback = true;
  v16 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hSpeaker);
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v16, attenuation: 0.80000001);
  EmitSound_t::EmitSound_t(this: &ep);
  ep.m_pSoundName = soundname;
  ep.m_nPitch = iPitch;
  ep.m_nChannel = 6;
  ep.m_flVolume = flVolume;
  ep.m_SoundLevel = soundlevel;
  ep.m_nFlags = iFlags | 0x40;
  v17 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hSpeaker);
  v18 = v17;
  if ( (v17->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
  ep.m_pOrigin = &v18->m_vecAbsOrigin;
  ep.m_flSoundTime = soundtime;
  ep.m_nSpeakerEntity = entindex;
  m_pPev = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hSpeaker)->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSound(&filter, iEntIndex: (int)m_pPev, params: &ep);
  V_strncpy(pDest: this->m_szLastSound, pSrc: soundname, maxLen: 256);
  COutputEvent::FireOutput(this: &this->m_OnRoutedSound, pActivator: this, pCaller: this, fDelay: 0.0);
  v20 = 0;
  this->m_bAvoidFeedback = false;
  if ( ep.m_UtlVecSoundOrigin.m_Size > 0 )
  {
    v21 = 0;
    do
    {
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)soundorigins,
        elem: soundorigins->m_Size,
        src: (const QAngle *)&ep.m_UtlVecSoundOrigin.m_Memory.m_pMemory[v21]);
      ++v20;
      ++v21;
    }
    while ( v20 < ep.m_UtlVecSoundOrigin.m_Size );
  }
  if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    return 1;
  }
  else
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011FB50
// Name: public: static bool CEnvMicrophone::OnSoundPlayed(int,char const __near *,enum soundlevel_t,float,int,int,class Vector const __near *,float,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CEnvMicrophone::OnSoundPlayed(
        int entindex,
        const char *soundname,
        soundlevel_t soundlevel,
        float flVolume,
        int iFlags,
        int iPitch,
        const Vector *pOrigin,
        float soundtime,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *soundorigins)
{
  int v9; // esi
  unsigned int m_Index; // eax
  unsigned int v11; // eax
  CEnvMicrophone *m_pEntity; // ecx
  int v13; // eax
  int m_Size; // eax
  bool bSwallowed; // [esp+27h] [ebp-1h]

  bSwallowed = false;
  if ( s_Microphones.m_Size <= 0 )
    return false;
  v9 = s_Microphones.m_Size - 1;
  if ( s_Microphones.m_Size - 1 < 0 )
    return false;
  do
  {
    m_Index = s_Microphones.m_Memory.m_pMemory[v9].m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      v11 = s_Microphones.m_Memory.m_pMemory[v9].m_Index;
      if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CEnvMicrophone *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      v13 = CEnvMicrophone::SoundPlayed(
              this: m_pEntity,
              entindex,
              soundname,
              soundlevel,
              flVolume,
              iFlags,
              iPitch,
              pOrigin,
              soundtime,
              soundorigins);
      if ( v13 == 1 )
      {
        bSwallowed = true;
      }
      else if ( v13 == 2 )
      {
        m_Size = s_Microphones.m_Size;
        if ( s_Microphones.m_Size > 0 )
        {
          if ( v9 != s_Microphones.m_Size - 1 )
          {
            s_Microphones.m_Memory.m_pMemory[v9].m_Index = s_Microphones.m_Memory.m_pMemory[s_Microphones.m_Size - 1].m_Index;
            m_Size = s_Microphones.m_Size;
          }
          s_Microphones.m_Size = m_Size - 1;
        }
      }
    }
    --v9;
  }
  while ( v9 >= 0 );
  return bSwallowed;
}

//------------------------------------------------------------------------------
// Address: 0x10402E60
// Name: CEnvMicrophone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvMicrophone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvMicrophone>(__formal: nullptr);
  CEnvMicrophone_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011FC70
// Name: struct datamap_t __near * DataMapInit<class CEnvMicrophone>(class CEnvMicrophone __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvMicrophone>()
{
  if ( (_S2_98 & 1) == 0 )
  {
    _S2_98 |= 1u;
    nameHolder_180.m_pszBase = "CEnvMicrophone";
    nameHolder_180.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_180.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_180.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_180.m_Names.m_Size = 0;
    nameHolder_180.m_Names.m_pElements = nullptr;
    nameHolder_180.m_nLenBase = 14;
    atexit(func: DataMapInit_CEnvMicrophone__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvMicrophone::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_98 & 2) == 0 )
  {
    _S2_98 |= 2u;
    *(_QWORD *)&dataDesc_170[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_170[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_170[16].override_count = 0;
    *(_QWORD *)dataDesc_170[16].flatOffset = 0;
    dataDesc_170[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_170[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_170[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_170[17].override_count = 0;
    *(_QWORD *)dataDesc_170[17].flatOffset = 0;
    dataDesc_170[16].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_170[16].flatGroup = 0;
    dataDesc_170[17].fieldType = FIELD_CUSTOM;
    dataDesc_170[17].fieldName = "m_OnRoutedSound";
    dataDesc_170[17].fieldOffset = 924;
    dataDesc_170[17].flags = 22;
    dataDesc_170[17].externalName = "OnRoutedSound";
    dataDesc_170[17].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_170[17].flatGroup = 0;
    dataDesc_170[18].fieldType = FIELD_CUSTOM;
    dataDesc_170[18].fieldName = "m_OnHeardSound";
    dataDesc_170[18].fieldOffset = 948;
    *(_DWORD *)&dataDesc_170[18].fieldSize = 1441793;
    dataDesc_170[18].externalName = "OnHeardSound";
    dataDesc_170[18].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_170[18].inputFunc = 0;
    *(_QWORD *)&dataDesc_170[18].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_170[18].override_count = 0;
    *(_QWORD *)dataDesc_170[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_170[18].flatGroup = 0;
  }
  CEnvMicrophone::m_DataMap.dataNumFields = 18;
  CEnvMicrophone::m_DataMap.dataDesc = &dataDesc_170[1];
  return &CEnvMicrophone::m_DataMap;
}
