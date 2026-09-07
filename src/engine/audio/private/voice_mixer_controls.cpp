// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/voice_mixer_controls.cpp
// Functions: 9
// ============================================================

#include "engine\audio\private\voice_mixer_controls.h"

//------------------------------------------------------------------------------
// Address: 0x100564F0
// Name: public: virtual bool CMixerControls::SelectMicrophoneForWaveInput(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMixerControls::SelectMicrophoneForWaveInput(CMixerControls *this)
{
  unsigned int m_dwMicSelectMultipleItems; // ebx
  void *v3; // esp
  HMIXER__ *m_hMixer; // ecx
  unsigned int v5; // edx
  HMIXER__ *v7; // [esp-Ch] [ebp-30h]
  _DWORD v8[3]; // [esp+0h] [ebp-24h] BYREF
  tMIXERCONTROLDETAILS pmxcd; // [esp+Ch] [ebp-18h] BYREF

  if ( this->m_dwMicSelectControlID == -1 )
    return false;
  m_dwMicSelectMultipleItems = this->m_dwMicSelectMultipleItems;
  v3 = alloca(4 * m_dwMicSelectMultipleItems);
  m_hMixer = this->m_hMixer;
  pmxcd.dwControlID = this->m_dwMicSelectControlID;
  pmxcd.cMultipleItems = m_dwMicSelectMultipleItems;
  pmxcd.cbStruct = 24;
  pmxcd.cChannels = 1;
  pmxcd.cbDetails = 4;
  pmxcd.paDetails = v8;
  if ( mixerGetControlDetailsA(hmxobj: (HMIXEROBJ)m_hMixer, &pmxcd, fdwDetails: 0x80000000) != 0 )
    return false;
  if ( this->m_dwMicSelectControlType == 1879113729 )
    memset(dst: (unsigned __int8 *)v8, value: 0, count: 4 * this->m_dwMicSelectMultipleItems);
  v8[this->m_dwMicSelectIndex] = 1;
  v5 = this->m_dwMicSelectMultipleItems;
  pmxcd.dwControlID = this->m_dwMicSelectControlID;
  v7 = this->m_hMixer;
  pmxcd.cbStruct = 24;
  pmxcd.cChannels = 1;
  pmxcd.cMultipleItems = v5;
  pmxcd.cbDetails = 4;
  pmxcd.paDetails = v8;
  return mixerSetControlDetails(hmxobj: (HMIXEROBJ)v7, &pmxcd, fdwDetails: 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100565D0
// Name: private: bool CMixerControls::SetControlOption_Bool(unsigned long,unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMixerControls::SetControlOption_Bool(
        CMixerControls *this,
        unsigned int dwControlID,
        unsigned int cMultipleItems,
        tMIXERCONTROLDETAILS_BOOLEAN bValue)
{
  HMIXER__ *m_hMixer; // ecx
  tMIXERCONTROLDETAILS details; // [esp+0h] [ebp-18h] BYREF

  m_hMixer = this->m_hMixer;
  details.dwControlID = dwControlID;
  details.paDetails = &bValue;
  details.cMultipleItems = cMultipleItems;
  details.cbStruct = 24;
  details.cChannels = 1;
  details.cbDetails = 4;
  bValue.fValue = LOBYTE(bValue.fValue);
  return mixerSetControlDetails(hmxobj: (HMIXEROBJ)m_hMixer, pmxcd: &details, fdwDetails: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10056620
// Name: private: bool CMixerControls::SetControlOption_Unsigned(unsigned long,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMixerControls::SetControlOption_Unsigned(
        CMixerControls *this,
        tMIXERCONTROLDETAILS_UNSIGNED dwControlID,
        unsigned int cMultipleItems,
        unsigned int value)
{
  HMIXER__ *m_hMixer; // ecx
  tMIXERCONTROLDETAILS details; // [esp+0h] [ebp-18h] BYREF

  m_hMixer = this->m_hMixer;
  details.dwControlID = dwControlID.dwValue;
  details.paDetails = &dwControlID;
  details.cMultipleItems = cMultipleItems;
  details.cbStruct = 24;
  details.cChannels = 1;
  details.cbDetails = 4;
  dwControlID.dwValue = value;
  return mixerSetControlDetails(hmxobj: (HMIXEROBJ)m_hMixer, pmxcd: &details, fdwDetails: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10056670
// Name: private: void CMixerControls::FindMicSelectControl(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMixerControls::FindMicSelectControl(
        CMixerControls *this,
        unsigned int dwLineID,
        unsigned int nControls)
{
  void *v4; // esp
  unsigned int v5; // ecx
  int *i; // edx
  unsigned int v7; // edi
  void *v8; // esp
  unsigned int m_dwMicSelectControlID; // ecx
  unsigned int *j; // edi
  unsigned int v11; // ecx
  HMIXER__ *m_hMixer; // [esp-Ch] [ebp-D8h]
  HMIXER__ *v13; // [esp-Ch] [ebp-D8h]
  HMIXER__ *v14; // [esp-Ch] [ebp-D8h]
  _DWORD v15[2]; // [esp+0h] [ebp-CCh] BYREF
  int v16; // [esp+8h] [ebp-C4h] BYREF
  tagMIXERLINEA mxl; // [esp+Ch] [ebp-C0h] BYREF
  tMIXERCONTROLDETAILS mxcd; // [esp+B4h] [ebp-18h] BYREF
  unsigned int dwi; // [esp+D8h] [ebp+Ch]

  this->m_dwMicSelectControlID = -1;
  v4 = alloca(148 * nControls);
  m_hMixer = this->m_hMixer;
  mxcd.cbStruct = 24;
  mxcd.dwControlID = dwLineID;
  mxcd.cMultipleItems = nControls;
  mxcd.cbDetails = 148;
  mxcd.paDetails = v15;
  if ( mixerGetLineControlsA(hmxobj: (HMIXEROBJ)m_hMixer, pmxlc: (LPMIXERLINECONTROLSA)&mxcd, fdwControls: 0) == 0 )
  {
    v5 = 0;
    if ( nControls != 0 )
    {
      for ( i = &v16; *i != 1895890945 && *i != 1879113729; i += 37 )
      {
        if ( ++v5 >= nControls )
          return;
      }
      this->m_dwMicSelectControlID = v15[37 * v5 + 1];
      this->m_dwMicSelectControlType = v15[37 * v5 + 2];
      v7 = v15[37 * v5 + 4];
      this->m_dwMicSelectMultipleItems = v7;
      this->m_dwMicSelectIndex = v5;
      v8 = alloca(72 * v7);
      m_dwMicSelectControlID = this->m_dwMicSelectControlID;
      v13 = this->m_hMixer;
      mxcd.cbStruct = 24;
      mxcd.dwControlID = m_dwMicSelectControlID;
      mxcd.cChannels = 1;
      mxcd.cMultipleItems = v7;
      mxcd.cbDetails = 72;
      mxcd.paDetails = v15;
      if ( mixerGetControlDetailsA(hmxobj: (HMIXEROBJ)v13, pmxcd: &mxcd, fdwDetails: 0x80000001) == 0 )
      {
        dwi = 0;
        if ( this->m_dwMicSelectMultipleItems != 0 )
        {
          for ( j = v15; ; j += 18 )
          {
            v11 = *j;
            v14 = this->m_hMixer;
            mxl.cbStruct = 168;
            mxl.dwLineID = v11;
            if ( mixerGetLineInfoA(hmxobj: (HMIXEROBJ)v14, pmxl: &mxl, fdwInfo: 0x80000002) == 0
              && mxl.dwComponentType == 4099 )
            {
              break;
            }
            if ( ++dwi >= this->m_dwMicSelectMultipleItems )
              return;
          }
          this->m_dwMicSelectIndex = dwi;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100567F0
// Name: void ShutdownMixerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownMixerControls()
{
  if ( g_pMixerControls != nullptr )
    ((void (__thiscall *)(IMixerControls *, int))g_pMixerControls->dtr_IMixerControls)(a1: g_pMixerControls, a2: 1);
  g_pMixerControls = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10056840
// Name: public: virtual bool CMixerControls::SetValue_Float(enum IMixerControls::Control,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMixerControls::SetValue_Float(CMixerControls *this, unsigned int iControl, float flValue)
{
  unsigned int value; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  if ( iControl > 2 || !this->m_ControlInfos[iControl].m_bFound )
    return false;
  if ( iControl != 0 )
  {
    if ( iControl == 2 )
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&voice_mixer_mute.IConVar,
        value: flValue != 0.0,
        a2: value,
        a3: v6);
      return CMixerControls::SetControlOption_Bool(
               this,
               dwControlID: this->m_ControlInfos[2].m_dwControlID,
               cMultipleItems: this->m_ControlInfos[2].m_cMultipleItems,
               bValue: flValue != 0.0);
    }
    else
    {
      ConVar::SetValue(this: (ConVar *)&voice_mixer_volume.IConVar, value: flValue);
      return CMixerControls::SetControlOption_Unsigned(
               this,
               dwControlID: this->m_ControlInfos[1].m_dwControlID,
               cMultipleItems: this->m_ControlInfos[1].m_cMultipleItems,
               value: (__int64)(flValue * 65535.0));
    }
  }
  else
  {
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&voice_mixer_boost.IConVar,
      value: flValue != 0.0,
      a2: value,
      a3: v6);
    return CMixerControls::SetControlOption_Bool(
             this,
             dwControlID: this->m_ControlInfos[0].m_dwControlID,
             cMultipleItems: this->m_ControlInfos[0].m_cMultipleItems,
             bValue: flValue != 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056A50
// Name: public: virtual bool CMixerControls::GetValue_Float(enum IMixerControls::Control,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMixerControls::GetValue_Float(CMixerControls *this, IMixerControls::Control iControl, float *flValue)
{
  int m_nValue; // eax
  int v5; // eax

  if ( (unsigned int)iControl > MicMute || !this->m_ControlInfos[iControl].m_bFound )
    return 0;
  if ( iControl != 0 )
  {
    if ( iControl == MicVolume )
    {
      *flValue = voice_mixer_volume.m_pParent->m_Value.m_fValue;
      return 1;
    }
    else
    {
      if ( voice_mixer_mute.m_pParent != nullptr )
        m_nValue = voice_mixer_mute.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      *flValue = (float)(m_nValue != 0);
      return 1;
    }
  }
  else
  {
    if ( voice_mixer_boost.m_pParent != nullptr )
      v5 = voice_mixer_boost.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    *flValue = (float)(v5 != 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056C00
// Name: private: bool CMixerControls::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMixerControls::Init(CMixerControls *this)
{
  HMIXER__ *m_hMixer; // eax
  UINT_PTR *p_m_hMixer; // ebx
  signed int v4; // esi
  MMRESULT DevCapsA; // eax
  unsigned int v6; // esi
  int v7; // esi
  char *v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  tagMIXERCONTROLA *v12; // eax
  int m_nValue; // eax
  unsigned int m_dwControlID; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int m_cMultipleItems; // ecx
  double v19; // st7
  tagMIXERCONTROLA *m_pMemory; // eax
  HMIXEROBJ v21; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v22; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v23; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v24; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v25; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v26; // [esp-Ch] [ebp-26ECh]
  CUtlVector<tagMIXERCONTROLA,CUtlMemoryFixedGrowable<tagMIXERCONTROLA,64,int> > v27; // [esp+Ch] [ebp-26D4h] BYREF
  tagMIXERLINEA pmxl; // [esp+2524h] [ebp-1BCh] BYREF
  tagMIXERLINEA v29; // [esp+25CCh] [ebp-114h] BYREF
  tagMIXERCAPSA pmxcaps; // [esp+2674h] [ebp-6Ch] BYREF
  unsigned int v31; // [esp+26A4h] [ebp-3Ch]
  signed int v32; // [esp+26A8h] [ebp-38h]
  int v33; // [esp+26ACh] [ebp-34h]
  unsigned int i; // [esp+26B0h] [ebp-30h]
  unsigned int v35; // [esp+26B4h] [ebp-2Ch]
  tagMIXERLINECONTROLSA pmxlc; // [esp+26B8h] [ebp-28h] BYREF
  HMIXER__ **v37; // [esp+26D0h] [ebp-10h]
  __int64 v38; // [esp+26D4h] [ebp-Ch] BYREF
  char v39; // [esp+26DDh] [ebp-3h]
  char v40; // [esp+26DFh] [ebp-1h]

  m_hMixer = this->m_hMixer;
  p_m_hMixer = (UINT_PTR *)&this->m_hMixer;
  v37 = &this->m_hMixer;
  if ( m_hMixer != nullptr )
  {
    mixerClose(hmx: m_hMixer);
    *p_m_hMixer = 0;
  }
  *p_m_hMixer = 0;
  this->m_ControlInfos[0].m_dwControlID = 0;
  this->m_ControlInfos[0].m_cMultipleItems = 0;
  *(_DWORD *)&this->m_ControlInfos[0].m_bFound = 0;
  this->m_ControlInfos[1].m_dwControlID = 0;
  this->m_ControlInfos[1].m_cMultipleItems = 0;
  *(_DWORD *)&this->m_ControlInfos[1].m_bFound = 0;
  this->m_ControlInfos[2].m_dwControlID = 0;
  this->m_ControlInfos[2].m_cMultipleItems = 0;
  *(_DWORD *)&this->m_ControlInfos[2].m_bFound = 0;
  v40 = 0;
  v39 = 0;
  v27.m_Memory.m_pMemory = v27.m_Memory.m_pFixedMemory;
  v27.m_Memory.m_nAllocationCount = 64;
  v27.m_Memory.m_nGrowSize = -1;
  v27.m_Memory.m_nMallocGrowSize = 0;
  v27.m_Size = 0;
  v27.m_pElements = v27.m_Memory.m_pFixedMemory;
  v4 = mixerGetNumDevs() - 1;
  v32 = v4;
  if ( v4 < 0 )
    goto LABEL_35;
  do
  {
    if ( v39 != 0 )
      break;
    if ( mixerOpen(phmx: (LPHMIXER)p_m_hMixer, uMxId: v4, dwCallback: 0, dwInstance: 0, fdwOpen: 0) == 0 )
    {
      DevCapsA = mixerGetDevCapsA(uMxId: *p_m_hMixer, &pmxcaps, cbmxcaps: 0x30u);
      if ( DevCapsA == 0 )
      {
        v40 = 1;
        v35 = 0;
        if ( pmxcaps.cDestinations != 0 )
        {
          do
          {
            v21 = (HMIXEROBJ)*p_m_hMixer;
            pmxl.cbStruct = 168;
            pmxl.dwDestination = DevCapsA;
            if ( mixerGetLineInfoA(hmxobj: v21, &pmxl, fdwInfo: 0) == 0 )
            {
              if ( pmxl.dwComponentType == 7 )
                CMixerControls::FindMicSelectControl(this, dwLineID: pmxl.dwLineID, nControls: pmxl.cControls);
              v6 = 0;
              HIDWORD(v38) = pmxl.cConnections;
              for ( i = 0; v6 < HIDWORD(v38); i = v6 )
              {
                v22 = (HMIXEROBJ)*p_m_hMixer;
                v29.cbStruct = 168;
                v29.dwDestination = v35;
                v29.dwSource = v6;
                if ( mixerGetLineInfoA(hmxobj: v22, pmxl: &v29, fdwInfo: 1u) == 0 )
                {
                  v27.m_Size = 0;
                  CUtlVector<tagMIXERCONTROLA,CUtlMemoryFixedGrowable<tagMIXERCONTROLA,64,int>>::InsertMultipleBefore(
                    this: &v27,
                    elem: 0,
                    num: v29.cControls);
                  pmxlc.dwLineID = v29.dwLineID;
                  pmxlc.cControls = v29.cControls;
                  v23 = (HMIXEROBJ)*p_m_hMixer;
                  pmxlc.cbStruct = 24;
                  pmxlc.cbmxctrl = 148;
                  pmxlc.pamxctrl = v27.m_Memory.m_pMemory;
                  if ( mixerGetLineControlsA(hmxobj: v23, &pmxlc, fdwControls: 0) == 0 )
                  {
                    v31 = 0;
                    if ( v29.cControls != 0 )
                    {
                      v7 = 0;
                      v33 = 0;
                      do
                      {
                        v8 = (char *)v27.m_Memory.m_pMemory + v7;
                        if ( v29.dwComponentType == 4099 )
                        {
                          if ( *((_DWORD *)v8 + 2) == 536936449 )
                          {
                            strstr(str1: (unsigned __int8 *)v8 + 20, str2: "Gain");
                            if ( v9 != 0
                              || (strstr(str1: (unsigned __int8 *)v8 + 20, str2: "Boos"), v10 != 0)
                              || (strstr(str1: (unsigned __int8 *)v8 + 20, str2: "+20d"), v11 != 0) )
                            {
                              this->m_ControlInfos[0].m_bFound = true;
                              this->m_ControlInfos[0].m_dwControlID = *((_DWORD *)v8 + 1);
                              this->m_ControlInfos[0].m_cMultipleItems = *((_DWORD *)v8 + 4);
                            }
                          }
                          if ( pmxl.dwComponentType == 4 )
                          {
                            if ( *((_DWORD *)v8 + 2) == 536936450 )
                            {
                              this->m_ControlInfos[2].m_bFound = true;
                              this->m_ControlInfos[2].m_dwControlID = *((_DWORD *)v8 + 1);
                              this->m_ControlInfos[2].m_cMultipleItems = *((_DWORD *)v8 + 4);
                            }
                          }
                          else if ( pmxl.dwComponentType == 7 && *((_DWORD *)v8 + 2) == 1342373889 )
                          {
                            this->m_ControlInfos[1].m_bFound = true;
                            this->m_ControlInfos[1].m_dwControlID = *((_DWORD *)v8 + 1);
                            this->m_ControlInfos[1].m_cMultipleItems = *((_DWORD *)v8 + 4);
                            v39 = 1;
                          }
                        }
                        v7 = v33 + 148;
                        ++v31;
                        v33 += 148;
                      }
                      while ( v31 < v29.cControls );
                      v6 = i;
                      p_m_hMixer = (UINT_PTR *)v37;
                    }
                  }
                }
                ++v6;
              }
            }
            DevCapsA = v35 + 1;
            v35 = DevCapsA;
          }
          while ( DevCapsA < pmxcaps.cDestinations );
          v4 = v32;
        }
      }
    }
    v32 = --v4;
  }
  while ( v4 >= 0 );
  if ( v40 != 0 )
  {
    if ( this->m_ControlInfos[0].m_bFound )
    {
      if ( voice_mixer_boost.m_pParent != nullptr )
        m_nValue = voice_mixer_boost.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      m_dwControlID = this->m_ControlInfos[0].m_dwControlID;
      pmxlc.cControls = this->m_ControlInfos[0].m_cMultipleItems;
      pmxlc.dwLineID = m_dwControlID;
      pmxlc.pamxctrl = (tagMIXERCONTROLA *)((char *)&v38 + 4);
      HIDWORD(v38) = m_nValue != 0;
      v24 = (HMIXEROBJ)*v37;
      pmxlc.cbStruct = 24;
      pmxlc.dwControlID = 1;
      pmxlc.cbmxctrl = 4;
      mixerSetControlDetails(hmxobj: v24, pmxcd: (LPMIXERCONTROLDETAILS)&pmxlc, fdwDetails: 0);
    }
    if ( this->m_ControlInfos[2].m_bFound )
    {
      if ( voice_mixer_mute.m_pParent != nullptr )
        v16 = voice_mixer_mute.m_pParent->m_Value.m_nValue;
      else
        v16 = 0;
      v17 = this->m_ControlInfos[2].m_dwControlID;
      pmxlc.cControls = this->m_ControlInfos[2].m_cMultipleItems;
      pmxlc.dwLineID = v17;
      pmxlc.pamxctrl = (tagMIXERCONTROLA *)((char *)&v38 + 4);
      HIDWORD(v38) = v16 != 0;
      v25 = (HMIXEROBJ)*v37;
      pmxlc.cbStruct = 24;
      pmxlc.dwControlID = 1;
      pmxlc.cbmxctrl = 4;
      mixerSetControlDetails(hmxobj: v25, pmxcd: (LPMIXERCONTROLDETAILS)&pmxlc, fdwDetails: 0);
    }
    if ( this->m_ControlInfos[1].m_bFound )
    {
      m_cMultipleItems = this->m_ControlInfos[1].m_cMultipleItems;
      pmxlc.dwLineID = this->m_ControlInfos[1].m_dwControlID;
      v19 = voice_mixer_volume.m_pParent->m_Value.m_fValue * 65535.0;
      pmxlc.cControls = m_cMultipleItems;
      pmxlc.pamxctrl = (tagMIXERCONTROLA *)((char *)&v38 + 4);
      v38 = (__int64)v19;
      HIDWORD(v38) = (__int64)v19;
      v26 = (HMIXEROBJ)*v37;
      pmxlc.cbStruct = 24;
      pmxlc.dwControlID = 1;
      pmxlc.cbmxctrl = 4;
      mixerSetControlDetails(hmxobj: v26, pmxcd: (LPMIXERCONTROLDETAILS)&pmxlc, fdwDetails: 0);
    }
    m_pMemory = v27.m_Memory.m_pMemory;
    v27.m_Size = 0;
    if ( v27.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v27.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        v27.m_Memory.m_pMemory = nullptr;
      }
      v27.m_Memory.m_nAllocationCount = 0;
    }
    v27.m_pElements = m_pMemory;
    if ( v27.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 1;
  }
  else
  {
LABEL_35:
    if ( *p_m_hMixer != 0 )
    {
      mixerClose(hmx: (HMIXER)*p_m_hMixer);
      *p_m_hMixer = 0;
    }
    *p_m_hMixer = 0;
    this->m_ControlInfos[0].m_dwControlID = 0;
    this->m_ControlInfos[0].m_cMultipleItems = 0;
    *(_DWORD *)&this->m_ControlInfos[0].m_bFound = 0;
    this->m_ControlInfos[1].m_dwControlID = 0;
    this->m_ControlInfos[1].m_cMultipleItems = 0;
    *(_DWORD *)&this->m_ControlInfos[1].m_bFound = 0;
    this->m_ControlInfos[2].m_dwControlID = 0;
    this->m_ControlInfos[2].m_cMultipleItems = 0;
    *(_DWORD *)&this->m_ControlInfos[2].m_bFound = 0;
    v12 = v27.m_Memory.m_pMemory;
    v27.m_Size = 0;
    if ( v27.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v27.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27.m_Memory.m_pMemory);
        v12 = nullptr;
        v27.m_Memory.m_pMemory = nullptr;
      }
      v27.m_Memory.m_nAllocationCount = 0;
    }
    v27.m_pElements = v12;
    if ( v27.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057100
// Name: void InitMixerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMixerControls()
{
  CMixerControls *v0; // esi

  if ( g_pMixerControls == nullptr )
  {
    v0 = (CMixerControls *)MemAlloc_Alloc(nSize: 0x3Cu);
    if ( v0 != nullptr )
    {
      v0->__vftable = (CMixerControls_vtbl *)&CMixerControls::`vftable';
      v0->m_dwMicSelectControlID = -1;
      v0->m_hMixer = nullptr;
      v0->m_ControlInfos[0].m_dwControlID = 0;
      v0->m_ControlInfos[0].m_cMultipleItems = 0;
      *(_DWORD *)&v0->m_ControlInfos[0].m_bFound = 0;
      v0->m_ControlInfos[1].m_dwControlID = 0;
      v0->m_ControlInfos[1].m_cMultipleItems = 0;
      *(_DWORD *)&v0->m_ControlInfos[1].m_bFound = 0;
      v0->m_ControlInfos[2].m_dwControlID = 0;
      v0->m_ControlInfos[2].m_cMultipleItems = 0;
      *(_DWORD *)&v0->m_ControlInfos[2].m_bFound = 0;
      CMixerControls::Init(this: v0);
      g_pMixerControls = v0;
    }
    else
    {
      g_pMixerControls = nullptr;
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100562B0
// Name: public: virtual bool CMixerControls::SelectMicrophoneForWaveInput(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMixerControls::SelectMicrophoneForWaveInput(CMixerControls *this)
{
  unsigned int m_dwMicSelectMultipleItems; // ebx
  void *v3; // esp
  HMIXER__ *m_hMixer; // ecx
  unsigned int v5; // edx
  HMIXER__ *v7; // [esp-Ch] [ebp-30h]
  _DWORD v8[3]; // [esp+0h] [ebp-24h] BYREF
  tMIXERCONTROLDETAILS pmxcd; // [esp+Ch] [ebp-18h] BYREF

  if ( this->m_dwMicSelectControlID == -1 )
    return false;
  m_dwMicSelectMultipleItems = this->m_dwMicSelectMultipleItems;
  v3 = alloca(4 * m_dwMicSelectMultipleItems);
  m_hMixer = this->m_hMixer;
  pmxcd.dwControlID = this->m_dwMicSelectControlID;
  pmxcd.cMultipleItems = m_dwMicSelectMultipleItems;
  pmxcd.cbStruct = 24;
  pmxcd.cChannels = 1;
  pmxcd.cbDetails = 4;
  pmxcd.paDetails = v8;
  if ( mixerGetControlDetailsA(hmxobj: (HMIXEROBJ)m_hMixer, &pmxcd, fdwDetails: 0x80000000) != 0 )
    return false;
  if ( this->m_dwMicSelectControlType == 1879113729 )
    memset(dst: (unsigned __int8 *)v8, value: 0, count: 4 * this->m_dwMicSelectMultipleItems);
  v8[this->m_dwMicSelectIndex] = 1;
  v5 = this->m_dwMicSelectMultipleItems;
  pmxcd.dwControlID = this->m_dwMicSelectControlID;
  v7 = this->m_hMixer;
  pmxcd.cbStruct = 24;
  pmxcd.cChannels = 1;
  pmxcd.cMultipleItems = v5;
  pmxcd.cbDetails = 4;
  pmxcd.paDetails = v8;
  return mixerSetControlDetails(hmxobj: (HMIXEROBJ)v7, &pmxcd, fdwDetails: 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10056390
// Name: private: bool CMixerControls::SetControlOption_Bool(unsigned long,unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMixerControls::SetControlOption_Bool(
        CMixerControls *this,
        unsigned int dwControlID,
        unsigned int cMultipleItems,
        tMIXERCONTROLDETAILS_BOOLEAN bValue)
{
  HMIXER__ *m_hMixer; // ecx
  tMIXERCONTROLDETAILS details; // [esp+0h] [ebp-18h] BYREF

  m_hMixer = this->m_hMixer;
  details.dwControlID = dwControlID;
  details.paDetails = &bValue;
  details.cMultipleItems = cMultipleItems;
  details.cbStruct = 24;
  details.cChannels = 1;
  details.cbDetails = 4;
  bValue.fValue = LOBYTE(bValue.fValue);
  return mixerSetControlDetails(hmxobj: (HMIXEROBJ)m_hMixer, pmxcd: &details, fdwDetails: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100563E0
// Name: private: bool CMixerControls::SetControlOption_Unsigned(unsigned long,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMixerControls::SetControlOption_Unsigned(
        CMixerControls *this,
        tMIXERCONTROLDETAILS_UNSIGNED dwControlID,
        unsigned int cMultipleItems,
        unsigned int value)
{
  HMIXER__ *m_hMixer; // ecx
  tMIXERCONTROLDETAILS details; // [esp+0h] [ebp-18h] BYREF

  m_hMixer = this->m_hMixer;
  details.dwControlID = dwControlID.dwValue;
  details.paDetails = &dwControlID;
  details.cMultipleItems = cMultipleItems;
  details.cbStruct = 24;
  details.cChannels = 1;
  details.cbDetails = 4;
  dwControlID.dwValue = value;
  return mixerSetControlDetails(hmxobj: (HMIXEROBJ)m_hMixer, pmxcd: &details, fdwDetails: 0) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10056430
// Name: private: void CMixerControls::FindMicSelectControl(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMixerControls::FindMicSelectControl(
        CMixerControls *this,
        unsigned int dwLineID,
        unsigned int nControls)
{
  void *v4; // esp
  unsigned int v5; // ecx
  int *i; // edx
  unsigned int v7; // edi
  void *v8; // esp
  unsigned int m_dwMicSelectControlID; // ecx
  unsigned int *j; // edi
  unsigned int v11; // ecx
  HMIXER__ *m_hMixer; // [esp-Ch] [ebp-D8h]
  HMIXER__ *v13; // [esp-Ch] [ebp-D8h]
  HMIXER__ *v14; // [esp-Ch] [ebp-D8h]
  _DWORD v15[2]; // [esp+0h] [ebp-CCh] BYREF
  int v16; // [esp+8h] [ebp-C4h] BYREF
  tagMIXERLINEA mxl; // [esp+Ch] [ebp-C0h] BYREF
  tMIXERCONTROLDETAILS mxcd; // [esp+B4h] [ebp-18h] BYREF
  unsigned int dwi; // [esp+D8h] [ebp+Ch]

  this->m_dwMicSelectControlID = -1;
  v4 = alloca(148 * nControls);
  m_hMixer = this->m_hMixer;
  mxcd.cbStruct = 24;
  mxcd.dwControlID = dwLineID;
  mxcd.cMultipleItems = nControls;
  mxcd.cbDetails = 148;
  mxcd.paDetails = v15;
  if ( mixerGetLineControlsA(hmxobj: (HMIXEROBJ)m_hMixer, pmxlc: (LPMIXERLINECONTROLSA)&mxcd, fdwControls: 0) == 0 )
  {
    v5 = 0;
    if ( nControls != 0 )
    {
      for ( i = &v16; *i != 1895890945 && *i != 1879113729; i += 37 )
      {
        if ( ++v5 >= nControls )
          return;
      }
      this->m_dwMicSelectControlID = v15[37 * v5 + 1];
      this->m_dwMicSelectControlType = v15[37 * v5 + 2];
      v7 = v15[37 * v5 + 4];
      this->m_dwMicSelectMultipleItems = v7;
      this->m_dwMicSelectIndex = v5;
      v8 = alloca(72 * v7);
      m_dwMicSelectControlID = this->m_dwMicSelectControlID;
      v13 = this->m_hMixer;
      mxcd.cbStruct = 24;
      mxcd.dwControlID = m_dwMicSelectControlID;
      mxcd.cChannels = 1;
      mxcd.cMultipleItems = v7;
      mxcd.cbDetails = 72;
      mxcd.paDetails = v15;
      if ( mixerGetControlDetailsA(hmxobj: (HMIXEROBJ)v13, pmxcd: &mxcd, fdwDetails: 0x80000001) == 0 )
      {
        dwi = 0;
        if ( this->m_dwMicSelectMultipleItems != 0 )
        {
          for ( j = v15; ; j += 18 )
          {
            v11 = *j;
            v14 = this->m_hMixer;
            mxl.cbStruct = 168;
            mxl.dwLineID = v11;
            if ( mixerGetLineInfoA(hmxobj: (HMIXEROBJ)v14, pmxl: &mxl, fdwInfo: 0x80000002) == 0
              && mxl.dwComponentType == 4099 )
            {
              break;
            }
            if ( ++dwi >= this->m_dwMicSelectMultipleItems )
              return;
          }
          this->m_dwMicSelectIndex = dwi;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100565B0
// Name: void ShutdownMixerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownMixerControls()
{
  if ( g_pMixerControls != nullptr )
    ((void (__thiscall *)(IMixerControls *, int))g_pMixerControls->dtr_IMixerControls)(a1: g_pMixerControls, a2: 1);
  g_pMixerControls = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10056600
// Name: public: virtual bool CMixerControls::SetValue_Float(enum IMixerControls::Control,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMixerControls::SetValue_Float(CMixerControls *this, IMixerControls::Control iControl, float flValue)
{
  bool v4; // al
  bool v6; // al

  if ( (unsigned int)iControl > MicMute || !this->m_ControlInfos[iControl].m_bFound )
    return false;
  if ( iControl != 0 )
  {
    if ( iControl == MicMute )
    {
      v6 = flValue != 0.0;
      LOBYTE(flValue) = flValue != 0.0;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&voice_mixer_mute.IConVar, value: v6);
      return CMixerControls::SetControlOption_Bool(
               this,
               dwControlID: this->m_ControlInfos[2].m_dwControlID,
               cMultipleItems: this->m_ControlInfos[2].m_cMultipleItems,
               bValue: LODWORD(flValue));
    }
    else
    {
      ConVar::SetValue(this: (ConVar *)&voice_mixer_volume.IConVar, value: flValue);
      return CMixerControls::SetControlOption_Unsigned(
               this,
               dwControlID: (tMIXERCONTROLDETAILS_UNSIGNED)this->m_ControlInfos[1].m_dwControlID,
               cMultipleItems: this->m_ControlInfos[1].m_cMultipleItems,
               value: (__int64)(flValue * 65535.0));
    }
  }
  else
  {
    v4 = flValue != 0.0;
    LOBYTE(flValue) = flValue != 0.0;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&voice_mixer_boost.IConVar, value: v4);
    return CMixerControls::SetControlOption_Bool(
             this,
             dwControlID: this->m_ControlInfos[0].m_dwControlID,
             cMultipleItems: this->m_ControlInfos[0].m_cMultipleItems,
             bValue: LODWORD(flValue));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056810
// Name: public: virtual bool CMixerControls::GetValue_Float(enum IMixerControls::Control,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMixerControls::GetValue_Float(CMixerControls *this, IMixerControls::Control iControl, float *flValue)
{
  int m_nValue; // eax
  int v5; // eax

  if ( (unsigned int)iControl > MicMute || !this->m_ControlInfos[iControl].m_bFound )
    return 0;
  if ( iControl != 0 )
  {
    if ( iControl == MicVolume )
    {
      *flValue = voice_mixer_volume.m_pParent->m_Value.m_fValue;
      return 1;
    }
    else
    {
      if ( voice_mixer_mute.m_pParent != nullptr )
        m_nValue = voice_mixer_mute.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      *flValue = (float)(m_nValue != 0);
      return 1;
    }
  }
  else
  {
    if ( voice_mixer_boost.m_pParent != nullptr )
      v5 = voice_mixer_boost.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    *flValue = (float)(v5 != 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100569C0
// Name: private: bool CMixerControls::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMixerControls::Init(CMixerControls *this)
{
  HMIXER__ *m_hMixer; // eax
  UINT_PTR *p_m_hMixer; // ebx
  signed int v4; // esi
  MMRESULT DevCapsA; // eax
  unsigned int v6; // esi
  int v7; // esi
  char *v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  tagMIXERCONTROLA *v12; // eax
  int m_nValue; // eax
  unsigned int m_dwControlID; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int m_cMultipleItems; // ecx
  double v19; // st7
  tagMIXERCONTROLA *m_pMemory; // eax
  HMIXEROBJ v21; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v22; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v23; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v24; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v25; // [esp-Ch] [ebp-26ECh]
  HMIXEROBJ v26; // [esp-Ch] [ebp-26ECh]
  CUtlVector<tagMIXERCONTROLA,CUtlMemoryFixedGrowable<tagMIXERCONTROLA,64,int> > v27; // [esp+Ch] [ebp-26D4h] BYREF
  tagMIXERLINEA pmxl; // [esp+2524h] [ebp-1BCh] BYREF
  tagMIXERLINEA v29; // [esp+25CCh] [ebp-114h] BYREF
  tagMIXERCAPSA pmxcaps; // [esp+2674h] [ebp-6Ch] BYREF
  unsigned int v31; // [esp+26A4h] [ebp-3Ch]
  signed int v32; // [esp+26A8h] [ebp-38h]
  int v33; // [esp+26ACh] [ebp-34h]
  unsigned int i; // [esp+26B0h] [ebp-30h]
  unsigned int v35; // [esp+26B4h] [ebp-2Ch]
  tagMIXERLINECONTROLSA pmxlc; // [esp+26B8h] [ebp-28h] BYREF
  HMIXER__ **v37; // [esp+26D0h] [ebp-10h]
  __int64 v38; // [esp+26D4h] [ebp-Ch] BYREF
  char v39; // [esp+26DDh] [ebp-3h]
  char v40; // [esp+26DFh] [ebp-1h]

  m_hMixer = this->m_hMixer;
  p_m_hMixer = (UINT_PTR *)&this->m_hMixer;
  v37 = &this->m_hMixer;
  if ( m_hMixer != nullptr )
  {
    mixerClose(hmx: m_hMixer);
    *p_m_hMixer = 0;
  }
  *p_m_hMixer = 0;
  this->m_ControlInfos[0].m_dwControlID = 0;
  this->m_ControlInfos[0].m_cMultipleItems = 0;
  *(_DWORD *)&this->m_ControlInfos[0].m_bFound = 0;
  this->m_ControlInfos[1].m_dwControlID = 0;
  this->m_ControlInfos[1].m_cMultipleItems = 0;
  *(_DWORD *)&this->m_ControlInfos[1].m_bFound = 0;
  this->m_ControlInfos[2].m_dwControlID = 0;
  this->m_ControlInfos[2].m_cMultipleItems = 0;
  *(_DWORD *)&this->m_ControlInfos[2].m_bFound = 0;
  v40 = 0;
  v39 = 0;
  v27.m_Memory.m_pMemory = v27.m_Memory.m_pFixedMemory;
  v27.m_Memory.m_nAllocationCount = 64;
  v27.m_Memory.m_nGrowSize = -1;
  v27.m_Memory.m_nMallocGrowSize = 0;
  v27.m_Size = 0;
  v27.m_pElements = v27.m_Memory.m_pFixedMemory;
  v4 = mixerGetNumDevs() - 1;
  v32 = v4;
  if ( v4 < 0 )
    goto LABEL_35;
  do
  {
    if ( v39 != 0 )
      break;
    if ( mixerOpen(phmx: (LPHMIXER)p_m_hMixer, uMxId: v4, dwCallback: 0, dwInstance: 0, fdwOpen: 0) == 0 )
    {
      DevCapsA = mixerGetDevCapsA(uMxId: *p_m_hMixer, &pmxcaps, cbmxcaps: 0x30u);
      if ( DevCapsA == 0 )
      {
        v40 = 1;
        v35 = 0;
        if ( pmxcaps.cDestinations != 0 )
        {
          do
          {
            v21 = (HMIXEROBJ)*p_m_hMixer;
            pmxl.cbStruct = 168;
            pmxl.dwDestination = DevCapsA;
            if ( mixerGetLineInfoA(hmxobj: v21, &pmxl, fdwInfo: 0) == 0 )
            {
              if ( pmxl.dwComponentType == 7 )
                CMixerControls::FindMicSelectControl(this, dwLineID: pmxl.dwLineID, nControls: pmxl.cControls);
              v6 = 0;
              HIDWORD(v38) = pmxl.cConnections;
              for ( i = 0; v6 < HIDWORD(v38); i = v6 )
              {
                v22 = (HMIXEROBJ)*p_m_hMixer;
                v29.cbStruct = 168;
                v29.dwDestination = v35;
                v29.dwSource = v6;
                if ( mixerGetLineInfoA(hmxobj: v22, pmxl: &v29, fdwInfo: 1u) == 0 )
                {
                  v27.m_Size = 0;
                  CUtlVector<tagMIXERCONTROLA,CUtlMemoryFixedGrowable<tagMIXERCONTROLA,64,int>>::InsertMultipleBefore(
                    this: &v27,
                    elem: 0,
                    num: v29.cControls);
                  pmxlc.dwLineID = v29.dwLineID;
                  pmxlc.cControls = v29.cControls;
                  v23 = (HMIXEROBJ)*p_m_hMixer;
                  pmxlc.cbStruct = 24;
                  pmxlc.cbmxctrl = 148;
                  pmxlc.pamxctrl = v27.m_Memory.m_pMemory;
                  if ( mixerGetLineControlsA(hmxobj: v23, &pmxlc, fdwControls: 0) == 0 )
                  {
                    v31 = 0;
                    if ( v29.cControls != 0 )
                    {
                      v7 = 0;
                      v33 = 0;
                      do
                      {
                        v8 = (char *)v27.m_Memory.m_pMemory + v7;
                        if ( v29.dwComponentType == 4099 )
                        {
                          if ( *((_DWORD *)v8 + 2) == 536936449 )
                          {
                            strstr(str1: (unsigned __int8 *)v8 + 20, str2: "Gain");
                            if ( v9 != 0
                              || (strstr(str1: (unsigned __int8 *)v8 + 20, str2: "Boos"), v10 != 0)
                              || (strstr(str1: (unsigned __int8 *)v8 + 20, str2: "+20d"), v11 != 0) )
                            {
                              this->m_ControlInfos[0].m_bFound = true;
                              this->m_ControlInfos[0].m_dwControlID = *((_DWORD *)v8 + 1);
                              this->m_ControlInfos[0].m_cMultipleItems = *((_DWORD *)v8 + 4);
                            }
                          }
                          if ( pmxl.dwComponentType == 4 )
                          {
                            if ( *((_DWORD *)v8 + 2) == 536936450 )
                            {
                              this->m_ControlInfos[2].m_bFound = true;
                              this->m_ControlInfos[2].m_dwControlID = *((_DWORD *)v8 + 1);
                              this->m_ControlInfos[2].m_cMultipleItems = *((_DWORD *)v8 + 4);
                            }
                          }
                          else if ( pmxl.dwComponentType == 7 && *((_DWORD *)v8 + 2) == 1342373889 )
                          {
                            this->m_ControlInfos[1].m_bFound = true;
                            this->m_ControlInfos[1].m_dwControlID = *((_DWORD *)v8 + 1);
                            this->m_ControlInfos[1].m_cMultipleItems = *((_DWORD *)v8 + 4);
                            v39 = 1;
                          }
                        }
                        v7 = v33 + 148;
                        ++v31;
                        v33 += 148;
                      }
                      while ( v31 < v29.cControls );
                      v6 = i;
                      p_m_hMixer = (UINT_PTR *)v37;
                    }
                  }
                }
                ++v6;
              }
            }
            DevCapsA = v35 + 1;
            v35 = DevCapsA;
          }
          while ( DevCapsA < pmxcaps.cDestinations );
          v4 = v32;
        }
      }
    }
    v32 = --v4;
  }
  while ( v4 >= 0 );
  if ( v40 != 0 )
  {
    if ( this->m_ControlInfos[0].m_bFound )
    {
      if ( voice_mixer_boost.m_pParent != nullptr )
        m_nValue = voice_mixer_boost.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      m_dwControlID = this->m_ControlInfos[0].m_dwControlID;
      pmxlc.cControls = this->m_ControlInfos[0].m_cMultipleItems;
      pmxlc.dwLineID = m_dwControlID;
      pmxlc.pamxctrl = (tagMIXERCONTROLA *)((char *)&v38 + 4);
      HIDWORD(v38) = m_nValue != 0;
      v24 = (HMIXEROBJ)*v37;
      pmxlc.cbStruct = 24;
      pmxlc.dwControlID = 1;
      pmxlc.cbmxctrl = 4;
      mixerSetControlDetails(hmxobj: v24, pmxcd: (LPMIXERCONTROLDETAILS)&pmxlc, fdwDetails: 0);
    }
    if ( this->m_ControlInfos[2].m_bFound )
    {
      if ( voice_mixer_mute.m_pParent != nullptr )
        v16 = voice_mixer_mute.m_pParent->m_Value.m_nValue;
      else
        v16 = 0;
      v17 = this->m_ControlInfos[2].m_dwControlID;
      pmxlc.cControls = this->m_ControlInfos[2].m_cMultipleItems;
      pmxlc.dwLineID = v17;
      pmxlc.pamxctrl = (tagMIXERCONTROLA *)((char *)&v38 + 4);
      HIDWORD(v38) = v16 != 0;
      v25 = (HMIXEROBJ)*v37;
      pmxlc.cbStruct = 24;
      pmxlc.dwControlID = 1;
      pmxlc.cbmxctrl = 4;
      mixerSetControlDetails(hmxobj: v25, pmxcd: (LPMIXERCONTROLDETAILS)&pmxlc, fdwDetails: 0);
    }
    if ( this->m_ControlInfos[1].m_bFound )
    {
      m_cMultipleItems = this->m_ControlInfos[1].m_cMultipleItems;
      pmxlc.dwLineID = this->m_ControlInfos[1].m_dwControlID;
      v19 = voice_mixer_volume.m_pParent->m_Value.m_fValue * 65535.0;
      pmxlc.cControls = m_cMultipleItems;
      pmxlc.pamxctrl = (tagMIXERCONTROLA *)((char *)&v38 + 4);
      v38 = (__int64)v19;
      HIDWORD(v38) = (__int64)v19;
      v26 = (HMIXEROBJ)*v37;
      pmxlc.cbStruct = 24;
      pmxlc.dwControlID = 1;
      pmxlc.cbmxctrl = 4;
      mixerSetControlDetails(hmxobj: v26, pmxcd: (LPMIXERCONTROLDETAILS)&pmxlc, fdwDetails: 0);
    }
    m_pMemory = v27.m_Memory.m_pMemory;
    v27.m_Size = 0;
    if ( v27.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v27.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        v27.m_Memory.m_pMemory = nullptr;
      }
      v27.m_Memory.m_nAllocationCount = 0;
    }
    v27.m_pElements = m_pMemory;
    if ( v27.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 1;
  }
  else
  {
LABEL_35:
    if ( *p_m_hMixer != 0 )
    {
      mixerClose(hmx: (HMIXER)*p_m_hMixer);
      *p_m_hMixer = 0;
    }
    *p_m_hMixer = 0;
    this->m_ControlInfos[0].m_dwControlID = 0;
    this->m_ControlInfos[0].m_cMultipleItems = 0;
    *(_DWORD *)&this->m_ControlInfos[0].m_bFound = 0;
    this->m_ControlInfos[1].m_dwControlID = 0;
    this->m_ControlInfos[1].m_cMultipleItems = 0;
    *(_DWORD *)&this->m_ControlInfos[1].m_bFound = 0;
    this->m_ControlInfos[2].m_dwControlID = 0;
    this->m_ControlInfos[2].m_cMultipleItems = 0;
    *(_DWORD *)&this->m_ControlInfos[2].m_bFound = 0;
    v12 = v27.m_Memory.m_pMemory;
    v27.m_Size = 0;
    if ( v27.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v27.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27.m_Memory.m_pMemory);
        v12 = nullptr;
        v27.m_Memory.m_pMemory = nullptr;
      }
      v27.m_Memory.m_nAllocationCount = 0;
    }
    v27.m_pElements = v12;
    if ( v27.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056EC0
// Name: void InitMixerControls(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMixerControls()
{
  CMixerControls *v0; // esi

  if ( g_pMixerControls == nullptr )
  {
    v0 = (CMixerControls *)MemAlloc_Alloc(nSize: 0x3Cu);
    if ( v0 != nullptr )
    {
      v0->__vftable = (CMixerControls_vtbl *)&CMixerControls::`vftable';
      v0->m_dwMicSelectControlID = -1;
      v0->m_hMixer = nullptr;
      v0->m_ControlInfos[0].m_dwControlID = 0;
      v0->m_ControlInfos[0].m_cMultipleItems = 0;
      *(_DWORD *)&v0->m_ControlInfos[0].m_bFound = 0;
      v0->m_ControlInfos[1].m_dwControlID = 0;
      v0->m_ControlInfos[1].m_cMultipleItems = 0;
      *(_DWORD *)&v0->m_ControlInfos[1].m_bFound = 0;
      v0->m_ControlInfos[2].m_dwControlID = 0;
      v0->m_ControlInfos[2].m_cMultipleItems = 0;
      *(_DWORD *)&v0->m_ControlInfos[2].m_bFound = 0;
      CMixerControls::Init(this: v0);
      g_pMixerControls = v0;
    }
    else
    {
      g_pMixerControls = nullptr;
    }
  }
}

} // namespace engine_xlsp
