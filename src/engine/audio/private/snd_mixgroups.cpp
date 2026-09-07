// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_mixgroups.cpp
// Functions: 39
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10032350
// Name: void MXR_SetCurrentSoundMixer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetCurrentSoundMixer(const char *szsoundmixer)
{
  int v1; // esi
  char *i; // edi

  if ( _V_stricmp(s1: szsoundmixer, s2: g_szsoundmixer_cur) != 0 )
  {
    v1 = 0;
    if ( g_csoundmixers > 0 )
    {
      for ( i = g_soundmixers[0].szsoundmixer; _V_stricmp(s1: i, s2: szsoundmixer) != 0; i += 2688 )
      {
        if ( ++v1 >= g_csoundmixers )
          return;
      }
      g_isoundmixer = v1;
      _V_strcpy(dest: g_szsoundmixer_cur, src: szsoundmixer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100323C0
// Name: char const __near * GetClientClassname(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetClientClassname(int soundsource)
{
  IClientEntity *v1; // eax
  int v2; // eax

  if ( entitylist != nullptr
    && (v1 = entitylist->GetClientEntity(this: entitylist, a2: soundsource)) != nullptr
    && (v2 = (int)v1->GetClientClass(this: &v1->IClientNetworkable)) != 0 )
  {
    return *(const char **)(v2 + 8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032400
// Name: int MXR_GetMixGroupListFromDirName(char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_GetMixGroupListFromDirName(const char *pDirname, unsigned __int8 *pList, int listMax)
{
  int v3; // esi
  int v4; // ebx
  char *szdir; // edi

  v3 = 0;
  if ( listMax > 0 )
    memset(dst: pList, value: 0xFFu, count: listMax);
  v4 = 0;
  if ( g_cgrouprules > 0 )
  {
    szdir = g_grouprules[0].szdir;
    do
    {
      if ( *szdir != 0 && _V_strstr(s1: pDirname, search: szdir) != nullptr )
      {
        pList[v3] = v4;
        if ( ++v3 >= listMax )
          break;
      }
      ++v4;
      szdir += 120;
    }
    while ( v4 < g_cgrouprules );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10032470
// Name: bool MXR_IsMusicGroup(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MXR_IsMusicGroup(int ruleIndex)
{
  return ruleIndex != 255
      && ruleIndex >= 0
      && ruleIndex < g_cgrouprules
      && V_stristr(pStr: g_grouprules[ruleIndex].szmixgroup, pSearch: "music") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100324C0
// Name: void S_SetIndexedMixGroupOfMixer(int,char const __near *,float,struct soundmixer_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetIndexedMixGroupOfMixer(int imixgroup, const char *szparam, float val, soundmixer_t *pmixer)
{
  if ( imixgroup >= 0 )
  {
    if ( _V_stricmp(s1: "vol", s2: szparam) != 0 )
    {
      if ( _V_stricmp(s1: "level", s2: szparam) != 0 )
      {
        if ( _V_stricmp(s1: "dsp", s2: szparam) != 0 )
        {
          if ( _V_stricmp(s1: "mute", s2: szparam) != 0 )
          {
            if ( _V_stricmp(s1: "solo", s2: szparam) != 0 )
            {
              if ( _V_stricmp(s1: "mix", s2: szparam) == 0 )
                pmixer->mixAmount = val;
            }
            else
            {
              pmixer->mapMixgroupidToSolo[imixgroup] = val;
            }
          }
          else
          {
            pmixer->mapMixgroupidToMute[imixgroup] = val;
          }
        }
        else
        {
          pmixer->mapMixgroupidToDsp[imixgroup] = val;
        }
      }
      else
      {
        pmixer->mapMixgroupidToLevel[imixgroup] = val;
      }
    }
    else
    {
      pmixer->mapMixgroupidToVolume[imixgroup] = val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100325C0
// Name: void S_SetMixGroupOfMixer(char const __near *,char const __near *,float,struct soundmixer_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixGroupOfMixer(const char *szgroupname, const char *szparam, float val, soundmixer_t *pmixer)
{
  grouprule_t *v4; // esi
  int v5; // [esp+0h] [ebp-4h]

  if ( szgroupname != nullptr && _V_strlen(str: szgroupname) != 0 )
  {
    v5 = 0;
    if ( g_cgrouprules > 0 )
    {
      v4 = g_grouprules;
      do
      {
        if ( V_stristr(pStr: v4->szmixgroup, pSearch: szgroupname) != nullptr )
        {
          if ( bPrintSetMixerDebug )
            DevMsg(a1: "Setting Mixer %s: MixGroup %s: %s : %f\n", pmixer->szsoundmixer, v4->szmixgroup, szparam, val);
          S_SetIndexedMixGroupOfMixer(imixgroup: v4->mixgroupid, szparam, val, pmixer);
        }
        ++v4;
        ++v5;
      }
      while ( v5 < g_cgrouprules );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032670
// Name: void S_SetMixGroupOfCurrentMixer(char const __near *,char const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixGroupOfCurrentMixer(const char *szgroupname, const char *szparam, float val)
{
  if ( g_isoundmixer >= 0 )
    S_SetMixGroupOfMixer(szgroupname, szparam, val, pmixer: &g_soundmixers[g_isoundmixer]);
}

//------------------------------------------------------------------------------
// Address: 0x100326B0
// Name: void S_SetMixGroupOfMixLayer(int,int,enum MXRMixGroupFields_t,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixGroupOfMixLayer(
        int nMixGroupIndex,
        int nMixLayerIndex,
        MXRMixGroupFields_t nMixGroupField,
        float flValue)
{
  soundmixer_t *v4; // eax

  v4 = &g_mixlayers[nMixLayerIndex];
  if ( nMixGroupIndex >= 0 )
  {
    switch ( nMixGroupField )
    {
      case MXR_MIXGROUP_VOL:
        v4->mapMixgroupidToVolume[nMixGroupIndex] = flValue;
        break;
      case MXR_MIXGROUP_LEVEL:
        v4->mapMixgroupidToLevel[nMixGroupIndex] = flValue;
        break;
      case MXR_MIXGROUP_DSP:
        v4->mapMixgroupidToDsp[nMixGroupIndex] = flValue;
        break;
      case MXR_MIXGROUP_SOLO:
        v4->mapMixgroupidToSolo[nMixGroupIndex] = flValue;
        break;
      case MXR_MIXGROUP_MUTE:
        v4->mapMixgroupidToMute[nMixGroupIndex] = flValue;
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032740
// Name: int MXR_GetMixLayerIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_GetMixLayerIndexFromName(const char *szmixlayername)
{
  int v1; // edi
  const char *v2; // esi

  v1 = 0;
  v2 = byte_1048CD04;
  while ( _V_stricmp(s1: v2, s2: szmixlayername) != 0 )
  {
    v2 += 2688;
    ++v1;
    if ( (int)v2 >= (int)g_soundmixers[0].szsoundmixer )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10032780
// Name: void S_SetMixLayerLevel(int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixLayerLevel(int index, float level)
{
  g_mixlayers[index].mixAmount = level;
}

//------------------------------------------------------------------------------
// Address: 0x100327A0
// Name: void S_SetMixLayerTriggerFactor(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixLayerTriggerFactor(int nMixLayerIndex, unsigned int nMixGroupIndex, float flFactor)
{
  layertrigger_t *v3; // eax

  v3 = &g_layertriggers[nMixLayerIndex];
  if ( nMixGroupIndex > 0x7F )
  {
    DevMsg(a1: "Error: MixGroup %i, in LayerTriggers cannot be resolved!\n", nMixGroupIndex);
  }
  else if ( v3->bistrigger[nMixGroupIndex] && v3->bhastrigger )
  {
    v3->fmixamount[nMixGroupIndex] = flFactor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100327F0
// Name: int MXR_GetMixgroupFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_GetMixgroupFromName(const char *pszgroupname)
{
  int v2; // esi
  grouprule_t *i; // edi

  if ( pszgroupname == nullptr || _V_strlen(str: pszgroupname) == 0 )
    return -1;
  v2 = 0;
  if ( g_cgrouprules <= 0 )
    return -1;
  for ( i = g_grouprules; _V_stricmp(s1: i->szmixgroup, s2: pszgroupname) != 0; ++i )
  {
    if ( ++v2 >= g_cgrouprules )
      return -1;
  }
  return g_grouprules[v2].mixgroupid;
}

//------------------------------------------------------------------------------
// Address: 0x10032860
// Name: char __near * MXR_GetGroupnameFromId(int)
// Source: json
//------------------------------------------------------------------------------
grouprule_t *__cdecl MXR_GetGroupnameFromId(int mixgroupid)
{
  grouprule_t *result; // eax
  int *i; // ecx

  result = nullptr;
  if ( mixgroupid >= 0 )
  {
    if ( g_cgrouprules <= 0 )
    {
      return nullptr;
    }
    else
    {
      for ( i = &g_grouprules[0].mixgroupid; *i != mixgroupid; i += 30 )
      {
        result = (grouprule_t *)((char *)result + 1);
        if ( (int)result >= g_cgrouprules )
          return nullptr;
      }
      return &g_grouprules[(_DWORD)result];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100328B0
// Name: void MXR_AssignGroupIds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_AssignGroupIds()
{
  grouprule_t *v0; // ebx
  int v1; // esi
  grouprule_t *v2; // edi
  int mixgroupid; // eax
  int cmixgroupid; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  cmixgroupid = 0;
  i = 0;
  if ( g_cgrouprules > 0 )
  {
    v0 = g_grouprules;
    do
    {
      if ( v0 == nullptr )
        goto LABEL_11;
      if ( _V_strlen(str: v0->szmixgroup) == 0 )
        goto LABEL_11;
      v1 = 0;
      if ( g_cgrouprules <= 0 )
        goto LABEL_11;
      v2 = g_grouprules;
      while ( _V_stricmp(s1: v2->szmixgroup, s2: v0->szmixgroup) != 0 )
      {
        ++v1;
        ++v2;
        if ( v1 >= g_cgrouprules )
          goto LABEL_11;
      }
      mixgroupid = g_grouprules[v1].mixgroupid;
      if ( mixgroupid != -1 )
      {
        v0->mixgroupid = mixgroupid;
      }
      else
      {
LABEL_11:
        v0->mixgroupid = cmixgroupid;
        g_mapMixgroupidToGrouprulesid[cmixgroupid++] = i;
      }
      ++v0;
      ++i;
    }
    while ( i < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032960
// Name: int MXR_AddClassname(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_AddClassname(const char *pName)
{
  int v1; // ecx
  int v2; // esi
  classlistelem_t *v3; // edi
  int v5; // eax
  char szclassname[32]; // [esp+Ch] [ebp-20h] BYREF

  V_strncpy(pDest: szclassname, pSrc: pName, maxLen: 32);
  v1 = g_cgroupclass;
  v2 = 0;
  if ( g_cgroupclass <= 0 )
  {
LABEL_5:
    if ( v1 < 16 )
    {
      if ( strlen(pName) <= 0x1F )
        v5 = strlen(pName);
      else
        v5 = 31;
      _V_memcpy(dest: &g_groupclasslist[v1], src: pName, count: v5);
      return g_cgroupclass++;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    v3 = g_groupclasslist;
    while ( _V_stricmp(s1: szclassname, s2: v3->szclassname) != 0 )
    {
      v1 = g_cgroupclass;
      ++v2;
      ++v3;
      if ( v2 >= g_cgroupclass )
        goto LABEL_5;
    }
    return v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032A20
// Name: MXR_PrintMixGroups
// Source: json
//------------------------------------------------------------------------------
void __usercall MXR_PrintMixGroups(soundmixer_t *pmixer@<ebx>)
{
  grouprule_t *v1; // eax
  int mixgroupid; // esi
  grouprule_t *v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = 0;
  if ( g_cgrouprules > 0 )
  {
    v1 = g_grouprules;
    v3 = g_grouprules;
    do
    {
      mixgroupid = v1->mixgroupid;
      if ( mixgroupid >= 0 && mixgroupid == v5 && pmixer->mapMixgroupidToVolume[mixgroupid] >= 0.0 )
      {
        DevMsg(a1: "%s", v1->szmixgroup);
        DevMsg(a1: "volume: %3.2f ", pmixer->mapMixgroupidToVolume[mixgroupid]);
        DevMsg(a1: "level: %3.2f ", pmixer->mapMixgroupidToLevel[mixgroupid]);
        DevMsg(a1: "dsp: %3.2f ", pmixer->mapMixgroupidToDsp[mixgroupid]);
        DevMsg(a1: "solo: %3.2f ", pmixer->mapMixgroupidToSolo[mixgroupid]);
        DevMsg(a1: "mute: %3.2f\n", pmixer->mapMixgroupidToMute[mixgroupid]);
        v1 = v3;
        ++v5;
      }
      ++v1;
      ++v4;
      v3 = v1;
    }
    while ( v4 < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032B00
// Name: MXR_ListMixers
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_ListMixers()
{
  soundmixer_t *v0; // ebx
  grouprule_t *v1; // eax
  int mixgroupid; // esi
  int v3; // [esp+4h] [ebp-10h]
  grouprule_t *v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  v3 = 0;
  if ( g_cmixlayers > 0 )
  {
    v0 = g_mixlayers;
    do
    {
      DevMsg(a1: "%s:\n", v0->szsoundmixer);
      v6 = 0;
      v5 = 0;
      if ( g_cgrouprules > 0 )
      {
        v1 = g_grouprules;
        v4 = g_grouprules;
        do
        {
          mixgroupid = v1->mixgroupid;
          if ( mixgroupid >= 0 && mixgroupid == v6 && v0->mapMixgroupidToVolume[mixgroupid] >= 0.0 )
          {
            DevMsg(a1: "%s", v1->szmixgroup);
            DevMsg(a1: "volume: %3.2f ", v0->mapMixgroupidToVolume[mixgroupid]);
            DevMsg(a1: "level: %3.2f ", v0->mapMixgroupidToLevel[mixgroupid]);
            DevMsg(a1: "dsp: %3.2f ", v0->mapMixgroupidToDsp[mixgroupid]);
            DevMsg(a1: "solo: %3.2f ", v0->mapMixgroupidToSolo[mixgroupid]);
            DevMsg(a1: "mute: %3.2f\n", v0->mapMixgroupidToMute[mixgroupid]);
            v1 = v4;
            ++v6;
          }
          ++v1;
          ++v5;
          v4 = v1;
        }
        while ( v5 < g_cgrouprules );
      }
      ++v0;
      ++v3;
    }
    while ( v3 < g_cmixlayers );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032C20
// Name: MXR_ListMixGroups
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_ListMixGroups()
{
  MXR_PrintMixGroups(pmixer: &g_soundmixers[g_isoundmixer]);
}

//------------------------------------------------------------------------------
// Address: 0x10032C40
// Name: void S_GetMixGroupOfCurrentMixer(char const __near *,struct soundmixer_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_GetMixGroupOfCurrentMixer(char *szgroupname, soundmixer_t *pmixer)
{
  grouprule_t *v2; // edi
  int mixgroupid; // eax
  float v4; // [esp+0h] [ebp-18h]
  float v5; // [esp+4h] [ebp-14h]
  float v6; // [esp+8h] [ebp-10h]
  float v7; // [esp+Ch] [ebp-Ch]
  float v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v9 = 0;
  if ( g_cgrouprules > 0 )
  {
    v2 = g_grouprules;
    do
    {
      if ( V_stristr(pStr: v2->szmixgroup, pSearch: szgroupname) != nullptr )
      {
        mixgroupid = v2->mixgroupid;
        v4 = pmixer->mapMixgroupidToVolume[mixgroupid];
        v5 = pmixer->mapMixgroupidToLevel[mixgroupid];
        v6 = pmixer->mapMixgroupidToDsp[mixgroupid];
        v7 = pmixer->mapMixgroupidToMute[mixgroupid];
        v8 = pmixer->mapMixgroupidToSolo[mixgroupid];
        DevMsg(a1: "%s:\n", v2->szmixgroup);
        DevMsg(a1: "\tVOL: %f\n\tLVL: %f\n\tDSP: %f\n\tMUTE: %f\n\tSOLO: %f\n\n", v4, v5, v6, v7, v8);
      }
      ++v2;
      ++v9;
    }
    while ( v9 < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032D10
// Name: MXR_AccumulateMasterMixLayer
// Source: json
//------------------------------------------------------------------------------
float *MXR_AccumulateMasterMixLayer()
{
  int v0; // edx
  int v1; // ecx
  float *v2; // esi
  float *result; // eax
  soundmixer_t *v4; // edi
  double v5; // st6
  int v6; // edx
  int v7; // esi
  float *mapMixgroupidToVolume; // ecx
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  double v12; // st4
  double v13; // st3
  double v14; // st6
  double v15; // st6
  double v16; // rt2
  double v17; // st3
  double v18; // st6
  double v19; // st6
  double v20; // rt0
  double v21; // rt1
  double v22; // st4
  double v23; // st6
  double v24; // rt2
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float totalAmount[128]; // [esp+0h] [ebp-208h]
  float v29; // [esp+200h] [ebp-8h]
  float amount; // [esp+204h] [ebp-4h]

  v0 = 640;
  v1 = 0;
  do
  {
    g_mastermixlayer.mapMixgroupidToVolume[v1] = 1.0;
    g_mastermixlayer.mapMixgroupidToLevel[v1] = 1.0;
    g_mastermixlayer.mapMixgroupidToDsp[v1] = 1.0;
    g_mastermixlayer.mapMixgroupidToSolo[v1] = 0.0;
    g_mastermixlayer.mapMixgroupidToMute[v1] = 0.0;
    totalAmount[v1] = 0.0;
    v2 = (float *)&unk_1048D780;
    result = (float *)((char *)&unk_1048D800 + v1 * 4);
    do
    {
      if ( *(result - 672) >= 0.0 )
        totalAmount[v1] = result[v0 - 1344] + totalAmount[v1];
      if ( *result >= 0.0 )
        totalAmount[v1] = *v2 + totalAmount[v1];
      if ( result[672] >= 0.0 )
        totalAmount[v1] = result[v0] + totalAmount[v1];
      if ( result[1344] >= 0.0 )
        totalAmount[v1] = result[v0 + 672] + totalAmount[v1];
      v2 += 2688;
      result += 2688;
    }
    while ( (int)v2 < (int)&g_soundmixers[1].mixAmount );
    --v0;
    ++v1;
  }
  while ( v0 > 512 );
  v4 = g_mixlayers;
  v5 = 0.0;
  v6 = (char *)&g_mastermixlayer.mapMixgroupidToVolume[96] - (char *)g_mixlayers;
  do
  {
    v7 = 0;
    mapMixgroupidToVolume = v4->mapMixgroupidToVolume;
    do
    {
      v9 = totalAmount[v7];
      if ( v9 > 0.0 )
      {
        v10 = *mapMixgroupidToVolume;
        v11 = (float)(v4->mixAmount / v9) * v4->mixAmount;
        amount = v11;
        v29 = v10;
        if ( v10 >= 0.0 )
        {
          v12 = amount;
          v13 = v5;
          v14 = (v29 - 1.0) * amount + *(float *)((char *)mapMixgroupidToVolume + v6 - 512);
          if ( v13 <= v14 )
          {
            v16 = v13;
            v13 = v14;
            v15 = v16;
            if ( v13 > 1.0 )
              v13 = 1.0;
          }
          else
          {
            v15 = v13;
          }
          *(float *)((char *)mapMixgroupidToVolume + v6 - 512) = v13;
          v17 = v15;
          v18 = (mapMixgroupidToVolume[128] - 1.0) * v12 + *(float *)((char *)mapMixgroupidToVolume + v6);
          if ( v17 <= v18 )
          {
            v20 = v17;
            v17 = v18;
            v19 = v20;
            if ( v17 > 1.0 )
              v17 = 1.0;
          }
          else
          {
            v19 = v17;
          }
          *(float *)((char *)mapMixgroupidToVolume + v6) = v17;
          v21 = v12 * (mapMixgroupidToVolume[256] - 1.0) + *(float *)((char *)mapMixgroupidToVolume + v6 + 512);
          v22 = v19;
          v23 = v21;
          if ( v22 <= v21 )
          {
            v24 = v22;
            v22 = v23;
            v5 = v24;
            if ( v22 > 1.0 )
              v22 = 1.0;
          }
          else
          {
            v5 = v22;
          }
          v25 = mapMixgroupidToVolume[384];
          *(float *)((char *)mapMixgroupidToVolume + v6 + 512) = v22;
          v26 = (float)(v25 * v11) + *(float *)((char *)mapMixgroupidToVolume + v6 + 1024);
          if ( v26 >= 0.0 )
          {
            if ( v26 > 1.0 )
              v26 = 1.0;
          }
          else
          {
            v26 = 0.0;
          }
          *(float *)((char *)mapMixgroupidToVolume + v6 + 1024) = v26;
          v27 = (float)(mapMixgroupidToVolume[512] * v11) + *(float *)((char *)mapMixgroupidToVolume + v6 + 1536);
          if ( v27 >= 0.0 )
          {
            if ( v27 > 1.0 )
              v27 = 1.0;
          }
          else
          {
            v27 = 0.0;
          }
          *(float *)((char *)mapMixgroupidToVolume + v6 + 1536) = v27;
        }
      }
      ++v7;
      ++mapMixgroupidToVolume;
    }
    while ( v7 < 128 );
    ++v4;
    v6 -= 2688;
  }
  while ( (int)v4 < (int)g_soundmixers );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032FA0
// Name: void MXR_UpdateAllDuckerVolumes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_UpdateAllDuckerVolumes()
{
  double v0; // st7
  int v1; // ecx
  float *p_trigger_vol; // eax
  bool v3; // bl
  int m_count; // edi
  int v5; // esi
  channel_t *v6; // edx
  float last_vol; // xmm0_4
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  soundmixer_t *v25; // edi
  bool *bistrigger; // esi
  float mixAmount; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  int v32; // eax
  float *v33; // ecx
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  int v37; // edx
  float v38; // xmm2_4
  int *p_priority; // esi
  int v40; // ebx
  int v41; // xmm0_4
  int v42; // ecx
  int *p_causes_ducking; // eax
  ConVar *m_pParent; // ebx
  int v45; // edi
  unsigned int v46; // esi
  __int16 *p_is_ducked; // ecx
  float v48; // xmm1_4
  float v49; // xmm3_4
  float m_fValue; // xmm0_4
  double v51; // st5
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  double v57; // st5
  float v58; // xmm2_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm3_4
  float v62; // xmm0_4
  double v63; // st5
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm3_4
  float v68; // xmm0_4
  double v69; // st5
  float v70; // xmm2_4
  float v71; // xmm0_4
  __int16 *v72; // ecx
  int v73; // edx
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  double v77; // st5
  float v78; // xmm2_4
  float v79; // xmm0_4
  CChannelList list; // [esp+0h] [ebp-198h] BYREF
  float delta; // [esp+188h] [ebp-10h]
  bool b_found_ducked_channel; // [esp+18Fh] [ebp-9h]
  float maxTriggerLevel; // [esp+190h] [ebp-8h]
  float ramptime; // [esp+194h] [ebp-4h]

  if ( snd_disable_mixer_duck.m_pParent == nullptr || snd_disable_mixer_duck.m_pParent->m_Value.m_nValue == 0 )
  {
    v0 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetHostTime)(a1: g_pSoundServices);
    if ( fabs(v0 - g_mxr_ducktime) >= 0.1 )
    {
      v1 = g_cgrouprules;
      g_mxr_ducktime = v0;
      if ( g_cgrouprules > 0 )
      {
        p_trigger_vol = &g_grouprules[0].trigger_vol;
        do
        {
          *(p_trigger_vol - 2) = 0.0;
          *p_trigger_vol = 0.0;
          p_trigger_vol += 30;
          --v1;
        }
        while ( v1 != 0 );
      }
      v3 = false;
      b_found_ducked_channel = false;
      CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, &list);
      m_count = list.m_count;
      v5 = 0;
      if ( list.m_count > 0 )
      {
        do
        {
          v6 = &channels[list.m_list[v5]];
          last_vol = v6->last_vol;
          if ( last_vol > 0.0 )
          {
            v8 = v6->mixgroups[0];
            if ( v8 >= 0 )
            {
              v9 = g_mapMixgroupidToGrouprulesid[v8];
              if ( g_grouprules[v9].causes_ducking != 0 )
                g_grouprules[v9].total_vol = g_grouprules[v9].total_vol + last_vol;
              v10 = g_grouprules[v9].is_ducked == 0;
              g_grouprules[v9].trigger_vol = g_grouprules[v9].trigger_vol + last_vol;
              if ( !v10 )
                v3 = true;
            }
            v11 = v6->mixgroups[1];
            if ( v11 >= 0 )
            {
              v12 = g_mapMixgroupidToGrouprulesid[v11];
              if ( g_grouprules[v12].causes_ducking != 0 )
                g_grouprules[v12].total_vol = g_grouprules[v12].total_vol + last_vol;
              g_grouprules[v12].trigger_vol = g_grouprules[v12].trigger_vol + last_vol;
              if ( g_grouprules[v12].is_ducked != 0 )
                v3 = true;
            }
            v13 = v6->mixgroups[2];
            if ( v13 >= 0 )
            {
              v14 = g_mapMixgroupidToGrouprulesid[v13];
              if ( g_grouprules[v14].causes_ducking != 0 )
                g_grouprules[v14].total_vol = g_grouprules[v14].total_vol + last_vol;
              g_grouprules[v14].trigger_vol = g_grouprules[v14].trigger_vol + last_vol;
              if ( g_grouprules[v14].is_ducked != 0 )
                v3 = true;
            }
            v15 = v6->mixgroups[3];
            if ( v15 >= 0 )
            {
              v16 = g_mapMixgroupidToGrouprulesid[v15];
              if ( g_grouprules[v16].causes_ducking != 0 )
                g_grouprules[v16].total_vol = g_grouprules[v16].total_vol + last_vol;
              g_grouprules[v16].trigger_vol = g_grouprules[v16].trigger_vol + last_vol;
              if ( g_grouprules[v16].is_ducked != 0 )
                v3 = true;
            }
            v17 = v6->mixgroups[4];
            if ( v17 >= 0 )
            {
              v18 = g_mapMixgroupidToGrouprulesid[v17];
              if ( g_grouprules[v18].causes_ducking != 0 )
                g_grouprules[v18].total_vol = g_grouprules[v18].total_vol + last_vol;
              g_grouprules[v18].trigger_vol = g_grouprules[v18].trigger_vol + last_vol;
              if ( g_grouprules[v18].is_ducked != 0 )
                v3 = true;
            }
            v19 = v6->mixgroups[5];
            if ( v19 >= 0 )
            {
              v20 = g_mapMixgroupidToGrouprulesid[v19];
              if ( g_grouprules[v20].causes_ducking != 0 )
                g_grouprules[v20].total_vol = g_grouprules[v20].total_vol + last_vol;
              g_grouprules[v20].trigger_vol = g_grouprules[v20].trigger_vol + last_vol;
              if ( g_grouprules[v20].is_ducked != 0 )
                v3 = true;
            }
            v21 = v6->mixgroups[6];
            if ( v21 >= 0 )
            {
              v22 = g_mapMixgroupidToGrouprulesid[v21];
              if ( g_grouprules[v22].causes_ducking != 0 )
                g_grouprules[v22].total_vol = g_grouprules[v22].total_vol + last_vol;
              g_grouprules[v22].trigger_vol = g_grouprules[v22].trigger_vol + last_vol;
              if ( g_grouprules[v22].is_ducked != 0 )
                v3 = true;
            }
            v23 = v6->mixgroups[7];
            if ( v23 >= 0 )
            {
              v24 = g_mapMixgroupidToGrouprulesid[v23];
              if ( g_grouprules[v24].causes_ducking != 0 )
                g_grouprules[v24].total_vol = g_grouprules[v24].total_vol + last_vol;
              g_grouprules[v24].trigger_vol = g_grouprules[v24].trigger_vol + last_vol;
              if ( g_grouprules[v24].is_ducked != 0 )
                v3 = true;
            }
          }
          ++v5;
        }
        while ( v5 < m_count );
        b_found_ducked_channel = v3;
      }
      v25 = g_mixlayers;
      bistrigger = g_layertriggers[0].bistrigger;
      do
      {
        if ( *(bistrigger - 1) )
        {
          mixAmount = v25->mixAmount;
          v28 = 0.0;
          v29 = 0.0;
          maxTriggerLevel = 0.0;
          v30 = 0.0;
          v31 = 0.0;
          v32 = 0;
          v33 = (float *)(bistrigger + 643);
          do
          {
            if ( bistrigger[v32] )
            {
              if ( v28 <= *v33 )
                v28 = *v33;
              if ( g_grouprules[g_mapMixgroupidToGrouprulesid[v32]].trigger_vol > *(v33 - 128) && v29 <= *v33 )
                v29 = *v33;
              if ( v33[128] > v30 )
                v30 = v33[128];
              v3 = b_found_ducked_channel;
              if ( v33[256] > v31 )
                v31 = v33[256];
            }
            ++v32;
            ++v33;
          }
          while ( v32 < 128 );
          maxTriggerLevel = v28;
          if ( v29 != mixAmount )
          {
            v34 = v29 <= mixAmount ? v31 : v30;
            ramptime = v34;
            if ( v34 > 0.0 )
            {
              delta = 0.1 / ramptime * maxTriggerLevel;
              v35 = delta;
              if ( mixAmount > v29 )
                v35 = -delta;
              v36 = v35 + mixAmount;
              if ( v29 > (float)(v35 + mixAmount) && v35 < 0.0 )
                v36 = v29;
              if ( v36 > v29 && v35 > 0.0 )
                v36 = v29;
              v29 = v36;
            }
          }
          v25->mixAmount = v29;
        }
        bistrigger += 2180;
        ++v25;
      }
      while ( (int)bistrigger < (int)&g_grouprules[0].szmixgroup[1] );
      if ( v3 )
      {
        v37 = g_cgrouprules;
        if ( g_cgrouprules > 0 )
        {
          v38 = g_DuckScale;
          p_priority = &g_grouprules[0].priority;
          v40 = g_cgrouprules;
          do
          {
            if ( *((_WORD *)p_priority + 2) != 0 )
            {
              v41 = 1065353216;
              if ( v38 >= 1.0 )
              {
                v42 = 0;
                p_causes_ducking = &g_grouprules[0].causes_ducking;
                while ( *(p_causes_ducking - 2) <= *p_priority
                     || *p_causes_ducking == 0
                     || *((float *)p_causes_ducking + 2) <= *((float *)p_causes_ducking + 3) )
                {
                  ++v42;
                  p_causes_ducking += 30;
                  if ( v42 >= v37 )
                    goto LABEL_93;
                }
                v41 = p_priority[3];
              }
LABEL_93:
              p_priority[7] = v41;
            }
            p_priority += 30;
            --v40;
          }
          while ( v40 != 0 );
        }
        m_pParent = snd_duckerattacktime.m_pParent;
        v45 = 0;
        if ( v37 >= 4 )
        {
          v46 = ((unsigned int)(v37 - 4) >> 2) + 1;
          p_is_ducked = &g_grouprules[0].is_ducked;
          v45 = 4 * v46;
          do
          {
            v48 = *((float *)p_is_ducked + 6);
            v49 = *((float *)p_is_ducked + 7);
            if ( *p_is_ducked != 0 && v49 != v48 )
            {
              if ( v49 <= v48 )
                m_fValue = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                m_fValue = m_pParent->m_Value.m_fValue;
              v51 = 1.0 - *((float *)p_is_ducked + 2);
              maxTriggerLevel = m_fValue;
              ramptime = v51 * (0.1 / m_fValue);
              v52 = ramptime;
              if ( v49 > v48 )
                v52 = -ramptime;
              v53 = v52 + v49;
              if ( v48 > (float)(v52 + v49) && v52 < 0.0 )
                v53 = v48;
              if ( v53 > v48 && v52 > 0.0 )
                v53 = v48;
              *((float *)p_is_ducked + 7) = v53;
            }
            v54 = *((float *)p_is_ducked + 36);
            v55 = *((float *)p_is_ducked + 37);
            if ( p_is_ducked[60] != 0 && v55 != v54 )
            {
              if ( v55 <= v54 )
                v56 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v56 = m_pParent->m_Value.m_fValue;
              v57 = 1.0 - *((float *)p_is_ducked + 32);
              maxTriggerLevel = v56;
              ramptime = v57 * (0.1 / v56);
              v58 = ramptime;
              if ( v55 > v54 )
                v58 = -ramptime;
              v59 = v58 + v55;
              if ( v54 > (float)(v58 + v55) && v58 < 0.0 )
                v59 = v54;
              if ( v59 > v54 && v58 > 0.0 )
                v59 = v54;
              *((float *)p_is_ducked + 37) = v59;
            }
            v60 = *((float *)p_is_ducked + 66);
            v61 = *((float *)p_is_ducked + 67);
            if ( p_is_ducked[120] != 0 && v61 != v60 )
            {
              if ( v61 <= v60 )
                v62 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v62 = m_pParent->m_Value.m_fValue;
              v63 = 1.0 - *((float *)p_is_ducked + 62);
              maxTriggerLevel = v62;
              ramptime = v63 * (0.1 / v62);
              v64 = ramptime;
              if ( v61 > v60 )
                v64 = -ramptime;
              v65 = v64 + v61;
              if ( v60 > (float)(v64 + v61) && v64 < 0.0 )
                v65 = v60;
              if ( v65 > v60 && v64 > 0.0 )
                v65 = v60;
              *((float *)p_is_ducked + 67) = v65;
            }
            v66 = *((float *)p_is_ducked + 96);
            v67 = *((float *)p_is_ducked + 97);
            if ( p_is_ducked[180] != 0 && v67 != v66 )
            {
              if ( v67 <= v66 )
                v68 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v68 = m_pParent->m_Value.m_fValue;
              v69 = 1.0 - *((float *)p_is_ducked + 92);
              maxTriggerLevel = v68;
              ramptime = v69 * (0.1 / v68);
              v70 = ramptime;
              if ( v67 > v66 )
                v70 = -ramptime;
              v71 = v70 + v67;
              if ( v66 > (float)(v70 + v67) && v70 < 0.0 )
                v71 = v66;
              if ( v71 > v66 && v70 > 0.0 )
                v71 = v66;
              *((float *)p_is_ducked + 97) = v71;
            }
            p_is_ducked += 240;
            --v46;
          }
          while ( v46 != 0 );
        }
        if ( v45 < v37 )
        {
          v72 = &g_grouprules[v45].is_ducked;
          v73 = v37 - v45;
          do
          {
            v74 = *((float *)v72 + 6);
            v75 = *((float *)v72 + 7);
            if ( *v72 != 0 && v75 != v74 )
            {
              if ( v75 <= v74 )
                v76 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v76 = m_pParent->m_Value.m_fValue;
              v77 = 1.0 - *((float *)v72 + 2);
              maxTriggerLevel = v76;
              ramptime = v77 * (0.1 / v76);
              v78 = ramptime;
              if ( v75 > v74 )
                v78 = -ramptime;
              v79 = v78 + v75;
              if ( v74 > (float)(v78 + v75) && v78 < 0.0 )
                v79 = v74;
              if ( v79 > v74 && v78 > 0.0 )
                v79 = v74;
              *((float *)v72 + 7) = v79;
            }
            v72 += 60;
            --v73;
          }
          while ( v73 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100337C0
// Name: int S_GetMixGroupIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl S_GetMixGroupIndex(const char *pMixGroupName)
{
  unsigned int result; // eax

  result = MXR_GetMixgroupFromName(pszgroupname: pMixGroupName);
  if ( result > 0x7F )
  {
    DevWarning(a1: "Error: MixGroup %s cannot be resolved!\n", pMixGroupName);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100337F0
// Name: void S_SetMixLayerTriggerFactor(char const __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixLayerTriggerFactor(const char *pMixLayerName, const char *pMixGroupName, float flFactor)
{
  int v3; // edi
  const char *v4; // esi
  int v5; // esi
  unsigned int MixgroupFromName; // eax
  layertrigger_t *v7; // esi

  v3 = 0;
  v4 = byte_1048CD04;
  while ( _V_stricmp(s1: v4, s2: pMixLayerName) != 0 )
  {
    v4 += 2688;
    ++v3;
    if ( (int)v4 >= (int)g_soundmixers[0].szsoundmixer )
    {
      v5 = -1;
      goto LABEL_5;
    }
  }
  v5 = v3;
LABEL_5:
  MixgroupFromName = MXR_GetMixgroupFromName(pszgroupname: pMixGroupName);
  if ( MixgroupFromName > 0x7F )
  {
    DevMsg(a1: "Error: MixGroup %s, in LayerTriggers cannot be resolved!\n", pMixGroupName);
  }
  else
  {
    v7 = &g_layertriggers[v5];
    if ( v7->bistrigger[MixgroupFromName] && v7->bhastrigger )
      v7->fmixamount[MixgroupFromName] = flFactor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033880
// Name: MXR_SetSoundMixer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetSoundMixer(const CCommand *args)
{
  const char *v1; // esi
  const char *v2; // edi
  long double v3; // st7
  float v4; // [esp-14h] [ebp-14h]

  if ( args->m_nArgc == 4 )
  {
    v1 = args->m_ppArgv[1];
    v2 = args->m_ppArgv[2];
    v3 = atof(nptr: args->m_ppArgv[3]);
    bPrintSetMixerDebug = true;
    if ( g_isoundmixer >= 0 )
    {
      v4 = v3;
      S_SetMixGroupOfMixer(szgroupname: v1, szparam: v2, val: v4, pmixer: &g_soundmixers[g_isoundmixer]);
    }
    bPrintSetMixerDebug = false;
  }
  else
  {
    DevMsg(a1: "Parameters: mix group name, [vol, mute, solo], value");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033900
// Name: MXR_SetMixLayer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetMixLayer(const CCommand *args)
{
  const char *v1; // edx
  const char *v2; // ebx
  const char *v3; // eax
  int v4; // edi
  const char *v5; // esi
  char *v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+4h] [ebp-4h]
  const char *v8; // [esp+10h] [ebp+8h]

  if ( args->m_nArgc == 5 )
  {
    v1 = args->m_ppArgv[3];
    v2 = args->m_ppArgv[2];
    v3 = args->m_ppArgv[4];
    v8 = args->m_ppArgv[1];
    v6 = (char *)v1;
    v7 = atof(nptr: v3);
    v4 = 0;
    bPrintSetMixerDebug = true;
    if ( g_cmixlayers > 0 )
    {
      v5 = byte_1048CD04;
      do
      {
        if ( _V_stricmp(s1: v5, s2: v8) == 0 )
        {
          DevMsg(a1: "Setting MixLayer %s\n", v5);
          S_SetMixGroupOfMixer(szgroupname: v2, szparam: v6, val: v7, pmixer: (soundmixer_t *)(v5 - 4));
        }
        ++v4;
        v5 += 2688;
      }
      while ( v4 < g_cmixlayers );
    }
    bPrintSetMixerDebug = false;
  }
  else
  {
    DevMsg(a1: "Parameters: mix group name, layer name, [vol, mute, solo], value, amount");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100339C0
// Name: MXR_SetMixLayerAmount
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetMixLayerAmount(const CCommand *args)
{
  const char *v1; // ebx
  int v2; // esi
  soundmixer_t *i; // edi
  float v4; // [esp+8h] [ebp+8h]

  if ( args->m_nArgc == 3 )
  {
    v1 = args->m_ppArgv[1];
    v4 = atof(nptr: args->m_ppArgv[2]);
    v2 = 0;
    if ( g_cmixlayers > 0 )
    {
      for ( i = g_mixlayers; _V_stricmp(s1: i->szsoundmixer, s2: v1) != 0; ++i )
      {
        if ( ++v2 >= g_cmixlayers )
          return;
      }
      DevMsg(a1: "Setting MixLayer %s : mix %f\n", i->szsoundmixer, v4);
      i->mixAmount = v4;
    }
  }
  else
  {
    DevMsg(a1: "Parameters: mixer name, mix amount");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033A60
// Name: MXR_SetMixLayerTriggerFactor
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetMixLayerTriggerFactor(const CCommand *args)
{
  const char *v1; // esi
  const char *v2; // edi
  float v3; // [esp-Ch] [ebp-Ch]

  if ( args->m_nArgc == 4 )
  {
    v1 = args->m_ppArgv[1];
    v2 = args->m_ppArgv[2];
    v3 = atof(nptr: args->m_ppArgv[3]);
    S_SetMixLayerTriggerFactor(pMixLayerName: v1, pMixGroupName: v2, flFactor: v3);
  }
  else
  {
    DevMsg(a1: "Parameters: mix layer name, mix group name, trigger amount");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033AB0
// Name: void MXR_GetValuesFromMixGroupIndex(struct mixervalues_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetValuesFromMixGroupIndex(mixervalues_t *mixValues, int imixgroup)
{
  soundmixer_t *v2; // ecx
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  if ( g_isoundmixer >= 0 && g_csoundmixers != 0 )
  {
    v2 = &g_soundmixers[g_isoundmixer];
    if ( v2 != nullptr && v2->mapMixgroupidToVolume[imixgroup] >= 0.0 )
    {
      v3 = v2->mapMixgroupidToLevel[imixgroup] * g_mastermixlayer.mapMixgroupidToLevel[imixgroup];
      mixValues->level = v3;
      mixValues->level = snd_mixerMasterLevel.m_pParent->m_Value.m_fValue * v3;
      v4 = v2->mapMixgroupidToDsp[imixgroup] * g_mastermixlayer.mapMixgroupidToDsp[imixgroup];
      mixValues->dsp = v4;
      mixValues->dsp = snd_mixerMasterDSP.m_pParent->m_Value.m_fValue * v4;
      v5 = g_mastermixlayer.mapMixgroupidToVolume[imixgroup] * v2->mapMixgroupidToVolume[imixgroup];
      mixValues->volume = v5;
      v6 = v2->mapMixgroupidToMute[imixgroup] <= g_mastermixlayer.mapMixgroupidToMute[imixgroup]
         ? g_mastermixlayer.mapMixgroupidToMute[imixgroup]
         : v2->mapMixgroupidToMute[imixgroup];
      v7 = (float)(1.0 - v6) * v5;
      mixValues->volume = v7;
      if ( g_soloActive > 0.0 )
      {
        v8 = v2->mapMixgroupidToSolo[imixgroup];
        if ( v8 <= g_mastermixlayer.mapMixgroupidToSolo[imixgroup] )
          v8 = g_mastermixlayer.mapMixgroupidToSolo[imixgroup];
        mixValues->volume = (float)(1.0 - (float)((float)(1.0 - (float)(v8 / g_soloActive)) * g_soloActive)) * v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033BF0
// Name: void MXR_GetVolFromMixGroup(struct channel_t __near *,struct mixervalues_t __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetVolFromMixGroup(channel_t *ch, channel_t *mixValues, mixervalues_t *plast_mixgroupid)
{
  int v3; // esi
  float v4; // xmm5_4
  int *i; // edi
  int v6; // edx
  float v7; // xmm0_4
  int v8; // eax
  int v9; // [esp-10h] [ebp-14h]

  if ( g_isoundmixer >= 0 && g_csoundmixers != 0 && &g_soundmixers[g_isoundmixer] != nullptr )
  {
    v3 = 0;
    v4 = 1.0;
    for ( i = ch->mixgroups; ; ++i )
    {
      v6 = *i;
      if ( *i >= 0 )
      {
        if ( snd_disable_mixer_duck.m_pParent != nullptr && snd_disable_mixer_duck.m_pParent->m_Value.m_nValue != 0 )
        {
          v7 = 1.0;
        }
        else
        {
          v8 = g_mapMixgroupidToGrouprulesid[v6];
          v7 = g_grouprules[v8].is_ducked != 0 ? g_grouprules[v8].duck_ramp_val : 1.0;
        }
        if ( v4 > v7 )
          v4 = v7;
        if ( g_soundmixers[g_isoundmixer].mapMixgroupidToVolume[v6] >= 0.0 )
          break;
      }
      if ( ++v3 >= 8 )
      {
        plast_mixgroupid->volume = 0.0;
        *(float *)&mixValues->guid = v4;
        return;
      }
    }
    v9 = *i;
    LODWORD(plast_mixgroupid->volume) = v6;
    MXR_GetValuesFromMixGroupIndex((mixervalues_t *)mixValues, imixgroup: v9);
    *(float *)&mixValues->guid = *(float *)&mixValues->guid * v4;
  }
  else
  {
    plast_mixgroupid->volume = 0.0;
    mixValues->guid = 1065353216;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033D10
// Name: char const __near * MXR_ParseMixGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MXR_ParseMixGroup(const char *pstart)
{
  int m_nValue; // ecx
  void (*v2)(const char *, ...); // ebx
  grouprule_t *v3; // esi
  unsigned int v4; // eax
  const char *v5; // edi
  unsigned int v6; // eax

  if ( DebugMXRParse.m_pParent != nullptr )
    m_nValue = DebugMXRParse.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v2 = DevMsg;
  v3 = &g_grouprules[g_cgrouprules];
  if ( m_nValue != 0 )
    DevMsg(a1: "MixGroup %s:\n", com_token);
  v4 = strlen(com_token);
  if ( v4 > 0x1F )
    v4 = 31;
  _V_memcpy(dest: v3, src: com_token, count: v4);
  v5 = pstart;
  v3->szmixgroup[31] = 0;
  if ( COM_TokenWaiting(buffer: pstart) != 0 )
  {
    v5 = COM_Parse(data: pstart);
    if ( com_token[0] != 0 )
    {
      v6 = strlen(com_token);
      if ( v6 > 0x1F )
        v6 = 31;
      _V_memcpy(dest: v3->szdir, src: com_token, count: v6);
      _V_strlower(start: v3->szdir);
      v2 = DevMsg;
      if ( _V_strstr(s1: v3->szdir, search: "?voice") != nullptr )
        v3->is_voice = 1;
    }
  }
  else
  {
    DevMsg(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  v3->szdir[31] = 0;
  v3->classId = -1;
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->classId = MXR_AddClassname(pName: com_token);
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
    {
      if ( _V_stricmp(s1: com_token, s2: "CHAN_STATIC") != 0 )
      {
        if ( _V_stricmp(s1: com_token, s2: "CHAN_WEAPON") != 0 )
        {
          if ( _V_stricmp(s1: com_token, s2: "CHAN_VOICE") != 0 )
          {
            if ( _V_stricmp(s1: com_token, s2: "CHAN_BODY") != 0 )
            {
              if ( _V_stricmp(s1: com_token, s2: "CHAN_ITEM") == 0 )
                v3->chantype = 3;
            }
            else
            {
              v3->chantype = 4;
            }
          }
          else
          {
            v3->chantype = 2;
          }
        }
        else
        {
          v3->chantype = 1;
        }
      }
      else
      {
        v3->chantype = 6;
      }
    }
    else
    {
      v3->chantype = -1;
    }
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->soundlevel_min = atoi(nptr: com_token);
    else
      v3->soundlevel_min = -1;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->soundlevel_max = atoi(nptr: com_token);
    else
      v3->soundlevel_max = -1;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->priority = atoi(nptr: com_token);
    else
      v3->priority = 50;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->is_ducked = atoi(nptr: com_token);
    else
      v3->is_ducked = 0;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->causes_ducking = atoi(nptr: com_token);
    else
      v3->causes_ducking = 0;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->duck_target_pct = (float)atoi(nptr: com_token) * 0.0099999998;
    else
      v3->duck_target_pct = 0.5;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->ducker_threshold = (float)atoi(nptr: com_token) * 0.0099999998;
    else
      v3->ducker_threshold = 0.5;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  ++g_cgrouprules;
  v3->duck_ramp_val = 1.0;
  v3->duck_target_vol = 1.0;
  v3->total_vol = 0.0;
  v3->trigger_vol = 0.0;
  v3->mixgroupid = -1;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10034160
// Name: char const __near * MXR_ParseSoundMixer(char const __near *,struct soundmixer_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
const char *__cdecl MXR_ParseSoundMixer(const char *pstart, soundmixer_t *pmixer)
{
  const char *v2; // ebx
  int *p_mixgroupid; // esi
  double v4; // st7
  double v5; // st6
  double v6; // rt1
  double v7; // st6
  double v8; // st7
  float v9; // xmm1_4
  double v10; // st6
  float v11; // xmm1_4
  double v12; // st6
  float v13; // xmm1_4
  double v14; // st6
  float v15; // xmm1_4
  char dest[8]; // [esp+8h] [ebp-38h] BYREF
  int m_nValue; // [esp+28h] [ebp-18h]
  float v19; // [esp+2Ch] [ebp-14h]
  float v20; // [esp+30h] [ebp-10h]
  _BYTE szgroupname[12]; // [esp+34h] [ebp-Ch] OVERLAPPED
  int szgroupname_20; // [esp+48h] [ebp+8h]

  if ( DebugMXRParse.m_pParent != nullptr )
    m_nValue = DebugMXRParse.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  _V_strcpy(dest, src: com_token);
  v2 = pstart;
  *(_DWORD *)&szgroupname[8] = 1065353216;
  *(_DWORD *)&szgroupname[4] = 1065353216;
  *(_DWORD *)szgroupname = 1065353216;
  v20 = 0.0;
  v19 = 0.0;
  if ( COM_TokenWaiting(buffer: pstart) != 0 )
  {
    v2 = COM_Parse(data: pstart);
    if ( com_token[0] != 0 )
      *(float *)&szgroupname[8] = atof(nptr: com_token);
    else
      *(_DWORD *)&szgroupname[8] = 1065353216;
  }
  else
  {
    DevMsg(a1: "Error: Parsing soundmixers.txt, soundmixer mix group values incomplete!\n");
  }
  if ( snd_soundmixer_version.m_pParent != nullptr && snd_soundmixer_version.m_pParent->m_Value.m_nValue >= 2 )
  {
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      *(float *)&szgroupname[4] = atof(nptr: com_token);
    }
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      *(float *)szgroupname = atof(nptr: com_token);
    }
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      v20 = atof(nptr: com_token);
    }
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      v19 = atof(nptr: com_token);
    }
  }
  szgroupname_20 = 0;
  if ( g_cgrouprules > 0 )
  {
    p_mixgroupid = &g_grouprules[0].mixgroupid;
    do
    {
      if ( _V_strcmp(s1: (const char *)p_mixgroupid - 32, s2: dest) == 0 )
      {
        if ( (unsigned int)*p_mixgroupid >= 0x80 )
          DevMsg(a1: "Error: MixGroup %s, in SoundMixer %s, cannot be resolved!\n", com_token, pmixer->szsoundmixer);
        if ( m_nValue != 0 )
          DevMsg(
            a1: "MixGroup %s: %f : %f : %f : %f : %f \n",
            dest,
            *(float *)&szgroupname[8],
            *(float *)&szgroupname[4],
            *(float *)szgroupname,
            v20,
            v19);
        if ( *(float *)&szgroupname[8] <= 0.0 )
        {
          v5 = 0.0;
          v4 = 0.0;
        }
        else
        {
          v4 = *(float *)&szgroupname[8];
          v5 = 0.0;
        }
        v6 = v5;
        v7 = v4;
        v8 = v6;
        v9 = *(float *)&szgroupname[4];
        pmixer->mapMixgroupidToVolume[*p_mixgroupid] = v7;
        if ( v9 <= 0.0 )
          v10 = v8;
        else
          v10 = *(float *)&szgroupname[4];
        v11 = *(float *)szgroupname;
        pmixer->mapMixgroupidToLevel[*p_mixgroupid] = v10;
        if ( v11 <= 0.0 )
          v12 = v8;
        else
          v12 = *(float *)szgroupname;
        v13 = v20;
        pmixer->mapMixgroupidToDsp[*p_mixgroupid] = v12;
        if ( v13 <= 0.0 )
          v14 = v8;
        else
          v14 = v20;
        v15 = v19;
        pmixer->mapMixgroupidToSolo[*p_mixgroupid] = v14;
        if ( v15 > 0.0 )
          v8 = v19;
        pmixer->mapMixgroupidToMute[*p_mixgroupid] = v8;
      }
      p_mixgroupid += 30;
      ++szgroupname_20;
    }
    while ( szgroupname_20 < g_cgrouprules );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100343F0
// Name: char const __near * MXR_ParseLayerTriggers(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MXR_ParseLayerTriggers(const char *pstart)
{
  int v1; // edi
  const char *v2; // esi
  layertrigger_t *v4; // edi
  const char *v5; // ebx
  unsigned int MixgroupFromName; // eax
  unsigned int v7; // esi

  if ( DebugMXRParse.m_pParent != nullptr && DebugMXRParse.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "MixLayer triggered %s:\n", com_token);
  v1 = 0;
  v2 = byte_1048CD04;
  while ( _V_stricmp(s1: v2, s2: com_token) != 0 )
  {
    v2 += 2688;
    ++v1;
    if ( (int)v2 >= (int)g_soundmixers[0].szsoundmixer )
      goto LABEL_9;
  }
  if ( v1 == -1 )
  {
LABEL_9:
    _Warning(a1: "Failed to get mix layer %s!\n", com_token);
    return pstart;
  }
  v4 = &g_layertriggers[v1];
  if ( COM_TokenWaiting(buffer: pstart) != 0 )
  {
    v5 = COM_Parse(data: pstart);
    if ( com_token[0] != 0
      && (MixgroupFromName = MXR_GetMixgroupFromName(pszgroupname: com_token),
          v7 = MixgroupFromName,
          MixgroupFromName <= 0x7F) )
    {
      v4->bistrigger[MixgroupFromName] = true;
      v4->bhastrigger = true;
      if ( COM_TokenWaiting(buffer: v5) != 0 )
      {
        v5 = COM_Parse(data: v5);
        if ( com_token[0] != 0 )
          v4->fthreshold[v7] = atof(nptr: com_token);
        if ( COM_TokenWaiting(buffer: v5) != 0 )
        {
          v5 = COM_Parse(data: v5);
          if ( com_token[0] != 0 )
            v4->fmixamount[v7] = atof(nptr: com_token);
          if ( COM_TokenWaiting(buffer: v5) != 0 )
          {
            v5 = COM_Parse(data: v5);
            if ( com_token[0] != 0 )
              v4->fattack[v7] = atof(nptr: com_token);
            if ( COM_TokenWaiting(buffer: v5) != 0 )
            {
              v5 = COM_Parse(data: v5);
              if ( com_token[0] != 0 )
                v4->frelease[v7] = atof(nptr: com_token);
            }
          }
        }
      }
      return v5;
    }
    else
    {
      DevMsg(a1: "Error: MixGroup %s, in LayerTriggers cannot be resolved!\n", com_token);
      return v5;
    }
  }
  else
  {
    DevMsg(a1: "Error: MixLayer Trigger entries require minimum 2 arguments\n");
    return pstart;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100345D0
// Name: bool MXR_LoadAllSoundMixers(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MXR_LoadAllSoundMixers()
{
  float *mapMixgroupidToLevel; // esi
  float *v1; // eax
  int i; // ecx
  float *v3; // esi
  float *v4; // eax
  int j; // ecx
  bool *bistrigger; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  char *File; // ebx
  int v11; // esi
  const char *v12; // edi
  soundmixer_t *v13; // edi
  unsigned int v14; // eax
  soundmixer_t *v15; // eax
  char szFile[264]; // [esp+Ch] [ebp-118h] BYREF
  char *pbuffer; // [esp+114h] [ebp-10h]
  const char *pstart; // [esp+118h] [ebp-Ch]
  int currentParseLevel; // [esp+11Ch] [ebp-8h]
  int parse_debug; // [esp+120h] [ebp-4h]

  g_isoundmixer = -1;
  g_szsoundmixer_cur[0] = 0;
  g_csoundmixers = 0;
  g_cmixlayers = 0;
  g_cgrouprules = 0;
  _V_memset(dest: g_soundmixers, fill: 0, count: 86016);
  _V_memset(dest: g_mixlayers, fill: 0, count: 43008);
  _V_memset(dest: g_grouprules, fill: 0, count: 17280);
  mapMixgroupidToLevel = g_soundmixers[0].mapMixgroupidToLevel;
  do
  {
    _V_strcpy(dest: (char *)mapMixgroupidToLevel - 636, src: defaultValue);
    *(mapMixgroupidToLevel - 160) = 1.0;
    v1 = mapMixgroupidToLevel;
    for ( i = 128; i != 0; --i )
    {
      *(v1 - 128) = -1.0;
      *v1 = 1.0;
      v1[128] = 1.0;
      v1[256] = 0.0;
      v1[384] = 0.0;
      ++v1;
    }
    mapMixgroupidToLevel += 672;
  }
  while ( (int)mapMixgroupidToLevel < (int)flt_104AC780 );
  v3 = (float *)&unk_1048CF80;
  do
  {
    _V_strcpy(dest: (char *)v3 - 636, src: defaultValue);
    *(v3 - 160) = 0.0;
    v4 = v3;
    for ( j = 128; j != 0; --j )
    {
      *(v4 - 128) = -1.0;
      *v4 = 1.0;
      v4[128] = 1.0;
      v4[256] = 0.0;
      v4[384] = 0.0;
      ++v4;
    }
    v3 += 672;
  }
  while ( (int)v3 < (int)g_soundmixers[0].mapMixgroupidToLevel );
  bistrigger = g_layertriggers[0].bistrigger;
  do
  {
    *(bistrigger - 1) = false;
    v7 = 0;
    v8 = bistrigger + 643;
    do
    {
      bistrigger[v7] = false;
      *(v8 - 128) = 0;
      *v8 = 1065353216;
      v8[128] = 0;
      v8[256] = 0;
      ++v7;
      ++v8;
    }
    while ( v7 < 128 );
    bistrigger += 2180;
  }
  while ( (int)bistrigger < (int)&g_grouprules[0].szmixgroup[1] );
  V_snprintf(pDest: szFile, maxLen: 260, pFormat: "scripts/soundmixers.txt");
  File = (char *)COM_LoadFile(path: szFile, usehunk: 5, pLength: nullptr);
  pbuffer = File;
  if ( File == nullptr )
  {
    _Error(a1: "MXR_LoadAllSoundMixers: unable to open '%s'\n", szFile);
    return 0;
  }
  if ( DebugMXRParse.m_pParent != nullptr )
    parse_debug = DebugMXRParse.m_pParent->m_Value.m_nValue;
  else
    parse_debug = 0;
  v11 = 0;
  currentParseLevel = 0;
  v12 = COM_Parse(data: File);
  pstart = v12;
  if ( strlen(com_token) != 0 )
  {
    while ( 1 )
    {
      if ( com_token[0] == 123 )
      {
        ++currentParseLevel;
      }
      else
      {
        if ( com_token[0] == 125 )
        {
          --currentParseLevel;
          switch ( v11 )
          {
            case 1:
              MXR_AssignGroupIds();
              v11 = 0;
              if ( parse_debug != 0 )
                DevMsg(a1: "Total Mix Groups Rules: %i\n", g_cgrouprules);
              break;
            case 3:
              ++g_csoundmixers;
              v11 = 2;
              break;
            case 2:
              v11 = 0;
              break;
            case 5:
              ++g_cmixlayers;
              v11 = 4;
              break;
            case 4:
              v11 = 0;
              if ( parse_debug != 0 )
                DevMsg(a1: "Total Mix Layers: %i\n", g_cmixlayers);
              break;
            case 6:
              v11 = 0;
              break;
            default:
              break;
          }
          goto LABEL_79;
        }
        switch ( v11 )
        {
          case 0:
            if ( _V_strcmp(s1: com_token, s2: "MixGroups") != 0 )
            {
              if ( _V_strcmp(s1: com_token, s2: "SoundMixers") != 0 )
              {
                if ( _V_strcmp(s1: com_token, s2: "MixLayers") != 0 )
                {
                  if ( _V_strcmp(s1: com_token, s2: "LayerTriggers") == 0 )
                  {
                    v11 = 6;
                    if ( parse_debug != 0 )
                      DevMsg(a1: "Parsing LayerTriggers:\n");
                  }
                }
                else
                {
                  v11 = 4;
                  if ( parse_debug != 0 )
                    DevMsg(a1: "Parsing MixLayers:\n");
                }
              }
              else
              {
                v11 = 2;
                if ( parse_debug != 0 )
                  DevMsg(a1: "Parsing SoundMixers:\n");
              }
            }
            else
            {
              v11 = 1;
              if ( parse_debug != 0 )
                DevMsg(a1: "Parsing MixGroups:\n");
            }
            break;
          case 1:
            if ( g_cgrouprules <= 144 )
              v12 = MXR_ParseMixGroup(pstart: v12);
            else
              DevMsg(a1: "Error: Too many mix groups! MixGroup %s ignored\n", com_token);
            break;
          case 6:
            v12 = MXR_ParseLayerTriggers(pstart: v12);
            break;
          case 2:
            if ( currentParseLevel < 2 )
            {
              if ( g_csoundmixers <= 32 )
              {
                v13 = &g_soundmixers[g_csoundmixers];
                if ( parse_debug != 0 )
                  DevMsg(a1: "SoundMixer %s:\n", com_token);
                v11 = 3;
                v14 = strlen(com_token);
                if ( v14 > 0x1F )
                  v14 = 31;
LABEL_63:
                _V_memcpy(dest: v13->szsoundmixer, src: com_token, count: v14);
                v12 = pstart;
                break;
              }
              DevMsg(a1: "Error: Too many sound mixers! SoundMixer %s ignored\n", com_token);
            }
            break;
          case 3:
            if ( currentParseLevel == 2 )
            {
              v15 = &g_soundmixers[g_csoundmixers];
LABEL_78:
              v12 = MXR_ParseSoundMixer(pstart: v12, pmixer: v15);
            }
            break;
          case 4:
            if ( currentParseLevel >= 2 )
              break;
            if ( g_cmixlayers > 16 )
            {
              DevMsg(a1: "Error: Too many mix layers! MixLayer %s ignored\n", com_token);
              break;
            }
            v13 = &g_mixlayers[g_cmixlayers];
            if ( parse_debug != 0 )
              DevMsg(a1: "MixLayers %s:\n", com_token);
            v11 = 5;
            v14 = strlen(com_token);
            if ( v14 > 0x1F )
              v14 = 31;
            goto LABEL_63;
          default:
            if ( currentParseLevel == 2 )
            {
              v15 = &g_mixlayers[g_cmixlayers];
              goto LABEL_78;
            }
            break;
        }
      }
LABEL_79:
      v12 = COM_Parse(data: v12);
      pstart = v12;
      if ( strlen(com_token) == 0 )
      {
        File = pbuffer;
        break;
      }
    }
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: File);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034B90
// Name: MXR_GetSoundMixer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetSoundMixer(const CCommand *args)
{
  if ( args->m_nArgc == 2 && g_isoundmixer >= 0 )
    S_GetMixGroupOfCurrentMixer(szgroupname: (char *)args->m_ppArgv[1], pmixer: &g_soundmixers[g_isoundmixer]);
}

//------------------------------------------------------------------------------
// Address: 0x10034BD0
// Name: void MXR_DebugGraphMixVolumes(struct debug_showvols_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl MXR_DebugGraphMixVolumes(debug_showvols_t *groupvols, int cgroups)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  float *p_totalvol; // esi
  double v6; // st6
  float v7; // xmm0_4
  float v8; // xmm2_4
  int v9; // eax
  int v10; // eax
  int v11; // eax
  bool v12; // zf
  double m_fValue; // [esp+4h] [ebp-138h]
  char pDest[4]; // [esp+14h] [ebp-128h] BYREF
  char text[128]; // [esp+40h] [ebp-FCh] BYREF
  _BYTE bartext_100[24]; // [esp+124h] [ebp-18h] OVERLAPPED

  v2 = 10 * (++g_debug_mxr_displaycount / 10);
  if ( g_debug_mxr_displaycount != v2 )
  {
    m_fValue = dsp_volume.m_pParent->m_Value.m_fValue;
    v3 = 96;
    v4 = 86;
    *(_DWORD *)&bartext_100[8] = 226;
    V_snprintf(pDest, maxLen: 128, pFormat: "DSP Volume: %1.2f", m_fValue);
    CDebugOverlay::AddScreenTextOverlay(
      flXPos: 0.0,
      flYPos: 0.0,
      duration: 0.0099999998,
      r: 96,
      g: 86,
      b: 226,
      a: 255,
      text: pDest);
    *(_DWORD *)&bartext_100[20] = 1020054733;
    if ( cgroups > 0 )
    {
      p_totalvol = &groupvols->totalvol;
      *(_DWORD *)bartext_100 = cgroups;
      do
      {
        v6 = *p_totalvol * g_DuckScale;
        v4 += 255
            * (((int)(((unsigned __int64)(2139062143LL * v4) >> 32) - v4) >> 7)
             + ((unsigned int)(((unsigned __int64)(2139062143LL * v4) >> 32) - v4) >> 31));
        v3 += 255
            * (((int)(((unsigned __int64)(2139062143LL * v3) >> 32) - v3) >> 7)
             + ((unsigned int)(((unsigned __int64)(2139062143LL * v3) >> 32) - v3) >> 31));
        *(_DWORD *)&bartext_100[8] += 255
                                    * (((int)(((unsigned __int64)(2139062143LL * *(int *)&bartext_100[8]) >> 32)
                                            - *(_DWORD *)&bartext_100[8]) >> 7)
                                     + ((unsigned int)(((unsigned __int64)(2139062143LL * *(int *)&bartext_100[8]) >> 32)
                                                     - *(_DWORD *)&bartext_100[8]) >> 31));
        V_snprintf(
          pDest,
          maxLen: 128,
          pFormat: "%s: %1.2f (%1.2f)",
          *((const char **)p_totalvol - 3),
          g_DuckScale * *(p_totalvol - 1),
          v6);
        CDebugOverlay::AddScreenTextOverlay(
          flXPos: 0.0,
          flYPos: *(float *)&bartext_100[20],
          duration: 0.0099999998,
          r: v3,
          g: v4,
          b: *(int *)&bartext_100[8],
          a: 255,
          text: pDest);
        v7 = *p_totalvol * g_DuckScale;
        *(float *)&bartext_100[12] = v7;
        if ( v7 >= 0.0 )
        {
          if ( v7 <= 0.7 )
            v8 = v7;
          else
            v8 = 0.69999999;
        }
        else
        {
          v8 = 0.0;
        }
        *(float *)&bartext_100[4] = v8;
        if ( v7 >= 0.0 )
        {
          if ( v7 <= 0.95 )
            *(float *)&bartext_100[16] = v7;
          else
            *(_DWORD *)&bartext_100[16] = 1064514355;
        }
        else
        {
          *(_DWORD *)&bartext_100[16] = 0;
        }
        if ( v8 > 0.0 )
        {
          _V_memset(dest: &text[84], fill: 0, count: 144);
          v9 = (int)(float)(*(float *)&bartext_100[4] * 48.0);
          if ( v9 >= 0 )
          {
            if ( v9 > 143 )
              v9 = 143;
          }
          else
          {
            v9 = 0;
          }
          _V_memset(dest: &text[84], fill: 45, count: v9);
          CDebugOverlay::AddScreenTextOverlay(
            flXPos: 0.30000001,
            flYPos: *(float *)&bartext_100[20],
            duration: 0.0099999998,
            r: 0,
            g: 255,
            b: 0,
            a: 255,
            text: &text[84]);
          v7 = *(float *)&bartext_100[12];
        }
        if ( *(float *)&bartext_100[16] > 0.7 )
        {
          _V_memset(dest: &text[84], fill: 0, count: 144);
          v10 = (int)(float)(*(float *)&bartext_100[16] * 48.0);
          if ( v10 >= 0 )
          {
            if ( v10 > 143 )
              v10 = 143;
          }
          else
          {
            v10 = 0;
          }
          _V_memset(dest: &text[84], fill: 45, count: v10);
          CDebugOverlay::AddScreenTextOverlay(
            flXPos: 0.30000001,
            flYPos: *(float *)&bartext_100[20],
            duration: 0.0099999998,
            r: 255,
            g: 255,
            b: 0,
            a: 255,
            text: &text[84]);
          v7 = *(float *)&bartext_100[12];
        }
        if ( v7 > 1.0 )
        {
          _V_memset(dest: &text[84], fill: 0, count: 144);
          v11 = (int)(float)(*(float *)&bartext_100[12] * 48.0);
          if ( v11 >= 0 )
          {
            if ( v11 > 143 )
              v11 = 143;
          }
          else
          {
            v11 = 0;
          }
          _V_memset(dest: &text[84], fill: 45, count: v11);
          CDebugOverlay::AddScreenTextOverlay(
            flXPos: 0.30000001,
            flYPos: *(float *)&bartext_100[20],
            duration: 0.0099999998,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            text: &text[84]);
        }
        p_totalvol += 4;
        v12 = (*(_DWORD *)bartext_100)-- == 1;
        *(float *)&bartext_100[20] = *(float *)&bartext_100[20] + 0.025;
      }
      while ( !v12 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034FB0
// Name: void MXR_DebugShowMixVolumes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_DebugShowMixVolumes()
{
  int v0; // esi
  soundmixer_t *v1; // eax
  debug_showvols_t *v2; // ecx
  float *mapMixgroupidToVolume; // edi
  char *v4; // ebx
  float v5; // xmm0_4
  int szmixgroup; // eax
  int *p_mixgroupid; // edx
  float v8; // xmm2_4
  int m_count; // edi
  int i; // esi
  channel_t *v11; // ecx
  float last_vol; // xmm0_4
  int last_mixgroupid; // ecx
  int v14; // eax
  int *v15; // edx
  debug_showvols_t groupvols[128]; // [esp+4h] [ebp-98Ch] BYREF
  CChannelList list; // [esp+804h] [ebp-18Ch] BYREF
  int cgroups; // [esp+98Ch] [ebp-4h]

  v0 = 0;
  if ( snd_showmixer.m_pParent != nullptr && snd_showmixer.m_pParent->m_Value.m_nValue != 0 )
  {
    cgroups = 0;
    if ( g_isoundmixer >= 0 )
    {
      v1 = &g_soundmixers[g_isoundmixer];
      v2 = groupvols;
      mapMixgroupidToVolume = v1->mapMixgroupidToVolume;
      v4 = (char *)((char *)&g_mastermixlayer - (char *)v1);
      do
      {
        v5 = *mapMixgroupidToVolume;
        if ( *mapMixgroupidToVolume >= 0.0 )
        {
          szmixgroup = 0;
          v2->mixgroupid = v0;
          if ( v0 >= 0 )
          {
            if ( g_cgrouprules <= 0 )
            {
LABEL_12:
              szmixgroup = 0;
            }
            else
            {
              p_mixgroupid = &g_grouprules[0].mixgroupid;
              while ( *p_mixgroupid != v0 )
              {
                ++szmixgroup;
                p_mixgroupid += 30;
                if ( szmixgroup >= g_cgrouprules )
                  goto LABEL_12;
              }
              szmixgroup = (int)g_grouprules[szmixgroup].szmixgroup;
            }
          }
          v8 = *(float *)((char *)mapMixgroupidToVolume + (_DWORD)v4);
          ++cgroups;
          v2->psz = (char *)szmixgroup;
          v2->totalvol = 0.0;
          v2->vol = v8 * v5;
          ++v2;
        }
        ++v0;
        ++mapMixgroupidToVolume;
      }
      while ( v0 < 128 );
      CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, &list);
      m_count = list.m_count;
      for ( i = 0; i < m_count; ++i )
      {
        v11 = &channels[list.m_list[i]];
        last_vol = v11->last_vol;
        if ( last_vol > 0.0 )
        {
          last_mixgroupid = v11->last_mixgroupid;
          v14 = 0;
          v15 = &groupvols[0].mixgroupid;
          while ( last_mixgroupid != *v15 )
          {
            ++v14;
            v15 += 4;
            if ( v14 >= 128 )
              goto LABEL_23;
          }
          groupvols[v14].totalvol = groupvols[v14].totalvol + last_vol;
        }
LABEL_23:
        ;
      }
      MXR_DebugGraphMixVolumes(groupvols, cgroups);
    }
    else
    {
      DevMsg(a1: "No sound mixer selected!");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035120
// Name: void MXR_SetSoloActive(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetSoloActive()
{
  float v0; // xmm0_4
  soundmixer_t *v1; // eax
  float *mapMixgroupidToSolo; // edx
  float *v3; // ecx

  MXR_AccumulateMasterMixLayer();
  v0 = 0.0;
  g_soloActive = 0.0;
  if ( snd_disable_mixer_solo.m_pParent == nullptr || snd_disable_mixer_solo.m_pParent->m_Value.m_nValue == 0 )
  {
    v1 = &g_soundmixers[g_isoundmixer];
    mapMixgroupidToSolo = g_mastermixlayer.mapMixgroupidToSolo;
    v3 = &v1->mapMixgroupidToSolo[1];
    do
    {
      if ( v0 <= *(v3 - 1) )
        v0 = *(v3 - 1);
      if ( v0 <= *mapMixgroupidToSolo )
        v0 = *mapMixgroupidToSolo;
      if ( v0 <= *v3 )
        v0 = *v3;
      if ( v0 <= *(float *)((char *)v3 + (char *)&g_mastermixlayer - (char *)v1) )
        v0 = *(float *)((char *)v3 + (char *)&g_mastermixlayer - (char *)v1);
      if ( v0 <= v3[1] )
        v0 = v3[1];
      if ( v0 <= *(float *)((char *)v3 + g_mastermixlayer.szsoundmixer - (char *)v1) )
        v0 = *(float *)((char *)v3 + g_mastermixlayer.szsoundmixer - (char *)v1);
      if ( v0 <= v3[2] )
        v0 = v3[2];
      if ( v0 <= *(float *)((char *)v3 + &g_mastermixlayer.szsoundmixer[4] - (char *)v1) )
        v0 = *(float *)((char *)v3 + &g_mastermixlayer.szsoundmixer[4] - (char *)v1);
      mapMixgroupidToSolo += 4;
      v3 += 4;
    }
    while ( (int)mapMixgroupidToSolo < (int)g_mastermixlayer.mapMixgroupidToMute );
    g_soloActive = v0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035200
// Name: void MXR_GetMixGroupFromSoundsource(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetMixGroupFromSoundsource(channel_t *pchan)
{
  int v2; // esi
  IClientEntity *v3; // eax
  int v4; // eax
  const char *v5; // eax
  void (*v6)(const char *, ...); // ebx
  classlistelem_t *v7; // ebx
  bool v8; // al
  CSfxTable *sfx; // ecx
  bool v10; // zf
  int v11; // eax
  int *p_classId; // esi
  char v13; // cl
  CSfxTable *v14; // eax
  int m_mixGroupCount; // edx
  int v16; // eax
  float m_flSoundLevel; // xmm0_4
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  char *m_pszString; // eax
  char pname[32]; // [esp+18h] [ebp-138h] BYREF
  char sndname[260]; // [esp+38h] [ebp-118h] BYREF
  bool classMatch[16]; // [esp+13Ch] [ebp-14h]
  int lastMixGroup; // [esp+14Ch] [ebp-4h]
  int mValues_8; // [esp+158h] [ebp+8h]
  bool mValues_11; // [esp+15Bh] [ebp+Bh]

  pchan->mixgroups[0] = -1;
  pchan->mixgroups[1] = -1;
  pchan->mixgroups[2] = -1;
  pchan->mixgroups[3] = -1;
  pchan->mixgroups[4] = -1;
  pchan->mixgroups[5] = -1;
  pchan->mixgroups[6] = -1;
  pchan->mixgroups[7] = -1;
  pchan->sfx->getname(this: pchan->sfx, a2: &pname[4], a3: 260u);
  V_FixSlashes(pname: &pname[4], separator: 47);
  v2 = 0;
  if ( entitylist != nullptr
    && (v3 = entitylist->GetClientEntity(this: entitylist, a2: pchan->soundsource)) != nullptr
    && (v4 = (int)v3->GetClientClass(this: &v3->IClientNetworkable)) != 0 )
  {
    v5 = *(const char **)(v4 + 8);
    lastMixGroup = (int)v5;
  }
  else
  {
    lastMixGroup = 0;
    v5 = nullptr;
  }
  if ( snd_showclassname.m_pParent != nullptr && snd_showclassname.m_pParent->m_Value.m_nValue == 1 && v5 != nullptr )
  {
    v6 = DevMsg;
    DevMsg(a1: "(%s:%s) \n", v5, &pname[4]);
  }
  else
  {
    v6 = DevMsg;
  }
  mValues_11 = g_pSoundServices->IsPlayer(this: g_pSoundServices, a2: pchan->soundsource);
  if ( g_cgroupclass > 0 )
  {
    v7 = g_groupclasslist;
    do
    {
      v8 = lastMixGroup != 0 && V_stristr(pStr: (const char *)lastMixGroup, pSearch: v7->szclassname) != nullptr
        || mValues_11 && _V_strcmp(s1: v7->szclassname, s2: "localPlayer") == 0;
      sndname[v2++ + 232] = v8;
      ++v7;
    }
    while ( v2 < g_cgroupclass );
    v6 = DevMsg;
  }
  sfx = pchan->sfx;
  v10 = (*((_BYTE *)sfx + 12) & 8) == 0;
  lastMixGroup = 0;
  if ( v10 )
    CSfxTable::OnNameChanged(this: sfx, pName: &pname[4]);
  v11 = 0;
  mValues_8 = 0;
  *(_DWORD *)&classMatch[12] = pchan->sfx->m_mixGroupList[0];
  *(_DWORD *)&classMatch[8] = 0;
  if ( g_cgrouprules > 0 )
  {
    p_classId = &g_grouprules[0].classId;
    do
    {
      v13 = 1;
      if ( *(_DWORD *)&classMatch[12] == v11 )
      {
        v14 = pchan->sfx;
        m_mixGroupCount = v14->m_mixGroupCount;
        ++mValues_8;
        *(_DWORD *)&classMatch[12] = 255;
        if ( mValues_8 < m_mixGroupCount )
          *(_DWORD *)&classMatch[12] = v14->m_mixGroupList[mValues_8];
      }
      else if ( *((_BYTE *)p_classId - 32) != 0 )
      {
        goto LABEL_33;
      }
      if ( *p_classId < 0 || (v13 = sndname[*p_classId + 232]) != 0 )
      {
        v16 = p_classId[1];
        if ( v16 >= 0 && pchan->entchannel != v16 )
LABEL_33:
          v13 = 0;
      }
      m_flSoundLevel = pchan->m_flSoundLevel;
      *(float *)&classMatch[4] = m_flSoundLevel;
      if ( v13 != 0 )
      {
        v18 = p_classId[2];
        if ( v18 < 0 || (float)v18 <= m_flSoundLevel )
        {
          v19 = p_classId[3];
          if ( v19 < 0 || m_flSoundLevel <= (float)v19 )
          {
            v20 = lastMixGroup;
            pchan->mixgroups[lastMixGroup] = *(p_classId - 9);
            v21 = v20 + 1;
            lastMixGroup = v21;
            if ( v21 == 1 )
            {
              if ( (snd_list.m_nFlags & 0x1000) != 0 )
              {
                m_pszString = "FCVAR_NEVER_AS_STRING";
                goto LABEL_44;
              }
              m_pszString = snd_list.m_pParent->m_Value.m_pszString;
              if ( m_pszString != nullptr && *m_pszString != 0 )
              {
LABEL_44:
                if ( V_stristr(pStr: &pname[4], pSearch: m_pszString) != nullptr )
                {
                  v6(a1: "%s", &pname[4]);
                  *(_DWORD *)&sndname[252] = 1065353216;
                  *(_DWORD *)&sndname[256] = 1065353216;
                  *(_DWORD *)classMatch = 1065353216;
                  MXR_GetVolFromMixGroup(
                    ch: pchan,
                    mixValues: (channel_t *)&sndname[252],
                    plast_mixgroupid: (mixervalues_t *)&sndname[248]);
                  if ( *((_BYTE *)p_classId - 68) != 0 )
                    v6(
                      a1: " : %s : vol: %4.2f, sndlvl: %i \n",
                      (const char *)p_classId - 68,
                      *(float *)&sndname[252],
                      (unsigned int)COERCE_UNSIGNED_INT64(*(float *)&classMatch[4]));
                }
                v21 = lastMixGroup;
              }
            }
            else if ( v21 >= 8 )
            {
              return;
            }
            if ( snd_showclassname.m_pParent != nullptr && snd_showclassname.m_pParent->m_Value.m_nValue >= 2 )
            {
              if ( v21 == 1 )
                v6(a1: "\n%s:%s: ", g_szsoundmixer_cur, &pname[4]);
              if ( *((_BYTE *)p_classId - 68) != 0 )
                v6(a1: "%s ", (const char *)p_classId - 68);
            }
          }
        }
      }
      v11 = *(_DWORD *)&classMatch[8] + 1;
      p_classId += 30;
      *(_DWORD *)&classMatch[8] = v11;
    }
    while ( v11 < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035540
// Name: void S_FlushMixers(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl S_FlushMixers()
{
  MXR_LoadAllSoundMixers();
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10032060
// Name: void MXR_SetCurrentSoundMixer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetCurrentSoundMixer(const char *szsoundmixer)
{
  int v1; // esi
  char *i; // edi

  if ( _V_stricmp(s1: szsoundmixer, s2: g_szsoundmixer_cur) != 0 )
  {
    v1 = 0;
    if ( g_csoundmixers > 0 )
    {
      for ( i = g_soundmixers[0].szsoundmixer; _V_stricmp(s1: i, s2: szsoundmixer) != 0; i += 2688 )
      {
        if ( ++v1 >= g_csoundmixers )
          return;
      }
      g_isoundmixer = v1;
      _V_strcpy(dest: g_szsoundmixer_cur, src: szsoundmixer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100320D0
// Name: char const __near * GetClientClassname(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetClientClassname(int soundsource)
{
  IClientEntity *v1; // eax
  int v2; // eax

  if ( entitylist != nullptr
    && (v1 = entitylist->GetClientEntity(this: entitylist, a2: soundsource)) != nullptr
    && (v2 = (int)v1->GetClientClass(this: &v1->IClientNetworkable)) != 0 )
  {
    return *(const char **)(v2 + 8);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032110
// Name: int MXR_GetMixGroupListFromDirName(char const __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_GetMixGroupListFromDirName(const char *pDirname, unsigned __int8 *pList, int listMax)
{
  int v3; // esi
  int v4; // ebx
  char *szdir; // edi

  v3 = 0;
  if ( listMax > 0 )
    memset(dst: pList, value: 0xFFu, count: listMax);
  v4 = 0;
  if ( g_cgrouprules > 0 )
  {
    szdir = g_grouprules[0].szdir;
    do
    {
      if ( *szdir != 0 && _V_strstr(s1: pDirname, search: szdir) != nullptr )
      {
        pList[v3] = v4;
        if ( ++v3 >= listMax )
          break;
      }
      ++v4;
      szdir += 120;
    }
    while ( v4 < g_cgrouprules );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10032180
// Name: bool MXR_IsMusicGroup(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl MXR_IsMusicGroup(int ruleIndex)
{
  return ruleIndex != 255
      && ruleIndex >= 0
      && ruleIndex < g_cgrouprules
      && V_stristr(pStr: g_grouprules[ruleIndex].szmixgroup, pSearch: "music") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100321D0
// Name: void S_SetIndexedMixGroupOfMixer(int,char const __near *,float,struct soundmixer_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetIndexedMixGroupOfMixer(int imixgroup, const char *szparam, float val, soundmixer_t *pmixer)
{
  if ( imixgroup >= 0 )
  {
    if ( _V_stricmp(s1: "vol", s2: szparam) != 0 )
    {
      if ( _V_stricmp(s1: "level", s2: szparam) != 0 )
      {
        if ( _V_stricmp(s1: "dsp", s2: szparam) != 0 )
        {
          if ( _V_stricmp(s1: "mute", s2: szparam) != 0 )
          {
            if ( _V_stricmp(s1: "solo", s2: szparam) != 0 )
            {
              if ( _V_stricmp(s1: "mix", s2: szparam) == 0 )
                pmixer->mixAmount = val;
            }
            else
            {
              pmixer->mapMixgroupidToSolo[imixgroup] = val;
            }
          }
          else
          {
            pmixer->mapMixgroupidToMute[imixgroup] = val;
          }
        }
        else
        {
          pmixer->mapMixgroupidToDsp[imixgroup] = val;
        }
      }
      else
      {
        pmixer->mapMixgroupidToLevel[imixgroup] = val;
      }
    }
    else
    {
      pmixer->mapMixgroupidToVolume[imixgroup] = val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100322D0
// Name: void S_SetMixGroupOfMixer(char const __near *,char const __near *,float,struct soundmixer_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixGroupOfMixer(const char *szgroupname, const char *szparam, float val, soundmixer_t *pmixer)
{
  grouprule_t *v4; // esi
  int i; // [esp+18h] [ebp-4h]

  if ( szgroupname != nullptr && _V_strlen(str: szgroupname) != 0 )
  {
    i = 0;
    if ( g_cgrouprules > 0 )
    {
      v4 = g_grouprules;
      do
      {
        if ( V_stristr(pStr: v4->szmixgroup, pSearch: szgroupname) != nullptr )
        {
          if ( bPrintSetMixerDebug )
            DevMsg(a1: "Setting Mixer %s: MixGroup %s: %s : %f\n", pmixer->szsoundmixer, v4->szmixgroup, szparam, val);
          S_SetIndexedMixGroupOfMixer(imixgroup: v4->mixgroupid, szparam, val, pmixer);
        }
        ++v4;
        ++i;
      }
      while ( i < g_cgrouprules );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032380
// Name: void S_SetMixGroupOfCurrentMixer(char const __near *,char const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixGroupOfCurrentMixer(const char *szgroupname, const char *szparam, float val)
{
  if ( g_isoundmixer >= 0 )
    S_SetMixGroupOfMixer(szgroupname, szparam, val, pmixer: &g_soundmixers[g_isoundmixer]);
}

//------------------------------------------------------------------------------
// Address: 0x10032450
// Name: int MXR_GetMixLayerIndexFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_GetMixLayerIndexFromName(const char *szmixlayername)
{
  int v1; // edi
  const char *v2; // esi

  v1 = 0;
  v2 = byte_1048CD04;
  while ( _V_stricmp(s1: v2, s2: szmixlayername) != 0 )
  {
    v2 += 2688;
    ++v1;
    if ( (int)v2 >= (int)g_soundmixers[0].szsoundmixer )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10032490
// Name: void S_SetMixLayerLevel(int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixLayerLevel(int index, float level)
{
  g_mixlayers[index].mixAmount = level;
}

//------------------------------------------------------------------------------
// Address: 0x100324B0
// Name: void S_SetMixLayerTriggerFactor(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixLayerTriggerFactor(int nMixLayerIndex, unsigned int nMixGroupIndex, float flFactor)
{
  layertrigger_t *v3; // eax

  v3 = &g_layertriggers[nMixLayerIndex];
  if ( nMixGroupIndex > 0x7F )
  {
    DevMsg(a1: "Error: MixGroup %i, in LayerTriggers cannot be resolved!\n", nMixGroupIndex);
  }
  else if ( v3->bistrigger[nMixGroupIndex] && v3->bhastrigger )
  {
    v3->fmixamount[nMixGroupIndex] = flFactor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032500
// Name: int MXR_GetMixgroupFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MXR_GetMixgroupFromName(const char *pszgroupname)
{
  int v2; // esi
  grouprule_t *i; // edi

  if ( pszgroupname == nullptr || _V_strlen(str: pszgroupname) == 0 )
    return -1;
  v2 = 0;
  if ( g_cgrouprules <= 0 )
    return -1;
  for ( i = g_grouprules; _V_stricmp(s1: i->szmixgroup, s2: pszgroupname) != 0; ++i )
  {
    if ( ++v2 >= g_cgrouprules )
      return -1;
  }
  return g_grouprules[v2].mixgroupid;
}

//------------------------------------------------------------------------------
// Address: 0x10032570
// Name: char __near * MXR_GetGroupnameFromId(int)
// Source: json
//------------------------------------------------------------------------------
grouprule_t *__cdecl MXR_GetGroupnameFromId(int mixgroupid)
{
  grouprule_t *result; // eax
  int *i; // ecx

  result = nullptr;
  if ( mixgroupid >= 0 )
  {
    if ( g_cgrouprules <= 0 )
    {
      return nullptr;
    }
    else
    {
      for ( i = &g_grouprules[0].mixgroupid; *i != mixgroupid; i += 30 )
      {
        result = (grouprule_t *)((char *)result + 1);
        if ( (int)result >= g_cgrouprules )
          return nullptr;
      }
      return &g_grouprules[(_DWORD)result];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032730
// Name: MXR_PrintMixGroups
// Source: json
//------------------------------------------------------------------------------
void __usercall MXR_PrintMixGroups(soundmixer_t *pmixer@<ebx>)
{
  grouprule_t *v1; // eax
  int mixgroupid; // esi
  grouprule_t *v3; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int nMixGroupId; // [esp+18h] [ebp-4h]

  nMixGroupId = 0;
  i = 0;
  if ( g_cgrouprules > 0 )
  {
    v1 = g_grouprules;
    v3 = g_grouprules;
    do
    {
      mixgroupid = v1->mixgroupid;
      if ( mixgroupid >= 0 && mixgroupid == nMixGroupId && pmixer->mapMixgroupidToVolume[mixgroupid] >= 0.0 )
      {
        DevMsg(a1: "%s", v1->szmixgroup);
        DevMsg(a1: "volume: %3.2f ", pmixer->mapMixgroupidToVolume[mixgroupid]);
        DevMsg(a1: "level: %3.2f ", pmixer->mapMixgroupidToLevel[mixgroupid]);
        DevMsg(a1: "dsp: %3.2f ", pmixer->mapMixgroupidToDsp[mixgroupid]);
        DevMsg(a1: "solo: %3.2f ", pmixer->mapMixgroupidToSolo[mixgroupid]);
        DevMsg(a1: "mute: %3.2f\n", pmixer->mapMixgroupidToMute[mixgroupid]);
        v1 = v3;
        ++nMixGroupId;
      }
      ++v1;
      ++i;
      v3 = v1;
    }
    while ( i < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032810
// Name: MXR_ListMixers
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_ListMixers()
{
  soundmixer_t *v0; // ebx
  grouprule_t *v1; // eax
  int mixgroupid; // esi
  int i; // [esp+14h] [ebp-10h]
  grouprule_t *v4; // [esp+18h] [ebp-Ch]
  int v5; // [esp+1Ch] [ebp-8h]
  int v6; // [esp+20h] [ebp-4h]

  i = 0;
  if ( g_cmixlayers > 0 )
  {
    v0 = g_mixlayers;
    do
    {
      DevMsg(a1: "%s:\n", v0->szsoundmixer);
      v6 = 0;
      v5 = 0;
      if ( g_cgrouprules > 0 )
      {
        v1 = g_grouprules;
        v4 = g_grouprules;
        do
        {
          mixgroupid = v1->mixgroupid;
          if ( mixgroupid >= 0 && mixgroupid == v6 && v0->mapMixgroupidToVolume[mixgroupid] >= 0.0 )
          {
            DevMsg(a1: "%s", v1->szmixgroup);
            DevMsg(a1: "volume: %3.2f ", v0->mapMixgroupidToVolume[mixgroupid]);
            DevMsg(a1: "level: %3.2f ", v0->mapMixgroupidToLevel[mixgroupid]);
            DevMsg(a1: "dsp: %3.2f ", v0->mapMixgroupidToDsp[mixgroupid]);
            DevMsg(a1: "solo: %3.2f ", v0->mapMixgroupidToSolo[mixgroupid]);
            DevMsg(a1: "mute: %3.2f\n", v0->mapMixgroupidToMute[mixgroupid]);
            v1 = v4;
            ++v6;
          }
          ++v1;
          ++v5;
          v4 = v1;
        }
        while ( v5 < g_cgrouprules );
      }
      ++v0;
      ++i;
    }
    while ( i < g_cmixlayers );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032930
// Name: MXR_ListMixGroups
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_ListMixGroups()
{
  MXR_PrintMixGroups(pmixer: &g_soundmixers[g_isoundmixer]);
}

//------------------------------------------------------------------------------
// Address: 0x10032950
// Name: void S_GetMixGroupOfCurrentMixer(char const __near *,struct soundmixer_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_GetMixGroupOfCurrentMixer(const char *szgroupname, soundmixer_t *pmixer)
{
  grouprule_t *v2; // edi
  int mixgroupid; // eax
  float volume; // [esp+34h] [ebp-18h]
  float level; // [esp+38h] [ebp-14h]
  float dsp; // [esp+3Ch] [ebp-10h]
  float mute; // [esp+40h] [ebp-Ch]
  float solo; // [esp+44h] [ebp-8h]
  int i; // [esp+48h] [ebp-4h]

  i = 0;
  if ( g_cgrouprules > 0 )
  {
    v2 = g_grouprules;
    do
    {
      if ( V_stristr(pStr: v2->szmixgroup, pSearch: szgroupname) != nullptr )
      {
        mixgroupid = v2->mixgroupid;
        volume = pmixer->mapMixgroupidToVolume[mixgroupid];
        level = pmixer->mapMixgroupidToLevel[mixgroupid];
        dsp = pmixer->mapMixgroupidToDsp[mixgroupid];
        mute = pmixer->mapMixgroupidToMute[mixgroupid];
        solo = pmixer->mapMixgroupidToSolo[mixgroupid];
        DevMsg(a1: "%s:\n", v2->szmixgroup);
        DevMsg(a1: "\tVOL: %f\n\tLVL: %f\n\tDSP: %f\n\tMUTE: %f\n\tSOLO: %f\n\n", volume, level, dsp, mute, solo);
      }
      ++v2;
      ++i;
    }
    while ( i < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032CC0
// Name: void MXR_UpdateAllDuckerVolumes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_UpdateAllDuckerVolumes()
{
  double v0; // st7
  int v1; // ecx
  float *p_trigger_vol; // eax
  bool v3; // bl
  int m_count; // edi
  int v5; // esi
  channel_t *v6; // edx
  float last_vol; // xmm0_4
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // edx
  int v24; // eax
  soundmixer_t *v25; // edi
  bool *bistrigger; // esi
  float mixAmount; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  int v32; // eax
  float *v33; // ecx
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  int v37; // edx
  float v38; // xmm2_4
  int *p_priority; // esi
  int v40; // ebx
  int v41; // xmm0_4
  int v42; // ecx
  int *p_causes_ducking; // eax
  ConVar *m_pParent; // ebx
  int v45; // edi
  unsigned int v46; // esi
  __int16 *p_is_ducked; // ecx
  float v48; // xmm1_4
  float v49; // xmm3_4
  float m_fValue; // xmm0_4
  double v51; // st5
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm3_4
  float v56; // xmm0_4
  double v57; // st5
  float v58; // xmm2_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm3_4
  float v62; // xmm0_4
  double v63; // st5
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm3_4
  float v68; // xmm0_4
  double v69; // st5
  float v70; // xmm2_4
  float v71; // xmm0_4
  __int16 *v72; // ecx
  int v73; // edx
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  double v77; // st5
  float v78; // xmm2_4
  float v79; // xmm0_4
  CChannelList list; // [esp+0h] [ebp-198h] BYREF
  float delta; // [esp+188h] [ebp-10h]
  bool b_found_ducked_channel; // [esp+18Fh] [ebp-9h]
  float maxTriggerLevel; // [esp+190h] [ebp-8h]
  float ramptime; // [esp+194h] [ebp-4h]

  if ( snd_disable_mixer_duck.m_pParent == nullptr || snd_disable_mixer_duck.m_pParent->m_Value.m_nValue == 0 )
  {
    v0 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetHostTime)(a1: g_pSoundServices);
    if ( fabs(v0 - g_mxr_ducktime) >= 0.1 )
    {
      v1 = g_cgrouprules;
      g_mxr_ducktime = v0;
      if ( g_cgrouprules > 0 )
      {
        p_trigger_vol = &g_grouprules[0].trigger_vol;
        do
        {
          *(p_trigger_vol - 2) = 0.0;
          *p_trigger_vol = 0.0;
          p_trigger_vol += 30;
          --v1;
        }
        while ( v1 != 0 );
      }
      v3 = false;
      b_found_ducked_channel = false;
      CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, &list);
      m_count = list.m_count;
      v5 = 0;
      if ( list.m_count > 0 )
      {
        do
        {
          v6 = &channels[list.m_list[v5]];
          last_vol = v6->last_vol;
          if ( last_vol > 0.0 )
          {
            v8 = v6->mixgroups[0];
            if ( v8 >= 0 )
            {
              v9 = g_mapMixgroupidToGrouprulesid[v8];
              if ( g_grouprules[v9].causes_ducking != 0 )
                g_grouprules[v9].total_vol = g_grouprules[v9].total_vol + last_vol;
              v10 = g_grouprules[v9].is_ducked == 0;
              g_grouprules[v9].trigger_vol = g_grouprules[v9].trigger_vol + last_vol;
              if ( !v10 )
                v3 = true;
            }
            v11 = v6->mixgroups[1];
            if ( v11 >= 0 )
            {
              v12 = g_mapMixgroupidToGrouprulesid[v11];
              if ( g_grouprules[v12].causes_ducking != 0 )
                g_grouprules[v12].total_vol = g_grouprules[v12].total_vol + last_vol;
              g_grouprules[v12].trigger_vol = g_grouprules[v12].trigger_vol + last_vol;
              if ( g_grouprules[v12].is_ducked != 0 )
                v3 = true;
            }
            v13 = v6->mixgroups[2];
            if ( v13 >= 0 )
            {
              v14 = g_mapMixgroupidToGrouprulesid[v13];
              if ( g_grouprules[v14].causes_ducking != 0 )
                g_grouprules[v14].total_vol = g_grouprules[v14].total_vol + last_vol;
              g_grouprules[v14].trigger_vol = g_grouprules[v14].trigger_vol + last_vol;
              if ( g_grouprules[v14].is_ducked != 0 )
                v3 = true;
            }
            v15 = v6->mixgroups[3];
            if ( v15 >= 0 )
            {
              v16 = g_mapMixgroupidToGrouprulesid[v15];
              if ( g_grouprules[v16].causes_ducking != 0 )
                g_grouprules[v16].total_vol = g_grouprules[v16].total_vol + last_vol;
              g_grouprules[v16].trigger_vol = g_grouprules[v16].trigger_vol + last_vol;
              if ( g_grouprules[v16].is_ducked != 0 )
                v3 = true;
            }
            v17 = v6->mixgroups[4];
            if ( v17 >= 0 )
            {
              v18 = g_mapMixgroupidToGrouprulesid[v17];
              if ( g_grouprules[v18].causes_ducking != 0 )
                g_grouprules[v18].total_vol = g_grouprules[v18].total_vol + last_vol;
              g_grouprules[v18].trigger_vol = g_grouprules[v18].trigger_vol + last_vol;
              if ( g_grouprules[v18].is_ducked != 0 )
                v3 = true;
            }
            v19 = v6->mixgroups[5];
            if ( v19 >= 0 )
            {
              v20 = g_mapMixgroupidToGrouprulesid[v19];
              if ( g_grouprules[v20].causes_ducking != 0 )
                g_grouprules[v20].total_vol = g_grouprules[v20].total_vol + last_vol;
              g_grouprules[v20].trigger_vol = g_grouprules[v20].trigger_vol + last_vol;
              if ( g_grouprules[v20].is_ducked != 0 )
                v3 = true;
            }
            v21 = v6->mixgroups[6];
            if ( v21 >= 0 )
            {
              v22 = g_mapMixgroupidToGrouprulesid[v21];
              if ( g_grouprules[v22].causes_ducking != 0 )
                g_grouprules[v22].total_vol = g_grouprules[v22].total_vol + last_vol;
              g_grouprules[v22].trigger_vol = g_grouprules[v22].trigger_vol + last_vol;
              if ( g_grouprules[v22].is_ducked != 0 )
                v3 = true;
            }
            v23 = v6->mixgroups[7];
            if ( v23 >= 0 )
            {
              v24 = g_mapMixgroupidToGrouprulesid[v23];
              if ( g_grouprules[v24].causes_ducking != 0 )
                g_grouprules[v24].total_vol = g_grouprules[v24].total_vol + last_vol;
              g_grouprules[v24].trigger_vol = g_grouprules[v24].trigger_vol + last_vol;
              if ( g_grouprules[v24].is_ducked != 0 )
                v3 = true;
            }
          }
          ++v5;
        }
        while ( v5 < m_count );
        b_found_ducked_channel = v3;
      }
      v25 = g_mixlayers;
      bistrigger = g_layertriggers[0].bistrigger;
      do
      {
        if ( *(bistrigger - 1) )
        {
          mixAmount = v25->mixAmount;
          v28 = 0.0;
          v29 = 0.0;
          maxTriggerLevel = 0.0;
          v30 = 0.0;
          v31 = 0.0;
          v32 = 0;
          v33 = (float *)(bistrigger + 643);
          do
          {
            if ( bistrigger[v32] )
            {
              if ( v28 <= *v33 )
                v28 = *v33;
              if ( g_grouprules[g_mapMixgroupidToGrouprulesid[v32]].trigger_vol > *(v33 - 128) && v29 <= *v33 )
                v29 = *v33;
              if ( v33[128] > v30 )
                v30 = v33[128];
              v3 = b_found_ducked_channel;
              if ( v33[256] > v31 )
                v31 = v33[256];
            }
            ++v32;
            ++v33;
          }
          while ( v32 < 128 );
          maxTriggerLevel = v28;
          if ( v29 != mixAmount )
          {
            v34 = v29 <= mixAmount ? v31 : v30;
            ramptime = v34;
            if ( v34 > 0.0 )
            {
              delta = 0.1 / ramptime * maxTriggerLevel;
              v35 = delta;
              if ( mixAmount > v29 )
                v35 = -delta;
              v36 = v35 + mixAmount;
              if ( v29 > (float)(v35 + mixAmount) && v35 < 0.0 )
                v36 = v29;
              if ( v36 > v29 && v35 > 0.0 )
                v36 = v29;
              v29 = v36;
            }
          }
          v25->mixAmount = v29;
        }
        bistrigger += 2180;
        ++v25;
      }
      while ( (int)bistrigger < (int)&g_grouprules[0].szmixgroup[1] );
      if ( v3 )
      {
        v37 = g_cgrouprules;
        if ( g_cgrouprules > 0 )
        {
          v38 = g_DuckScale;
          p_priority = &g_grouprules[0].priority;
          v40 = g_cgrouprules;
          do
          {
            if ( *((_WORD *)p_priority + 2) != 0 )
            {
              v41 = 1065353216;
              if ( v38 >= 1.0 )
              {
                v42 = 0;
                p_causes_ducking = &g_grouprules[0].causes_ducking;
                while ( *(p_causes_ducking - 2) <= *p_priority
                     || *p_causes_ducking == 0
                     || *((float *)p_causes_ducking + 2) <= *((float *)p_causes_ducking + 3) )
                {
                  ++v42;
                  p_causes_ducking += 30;
                  if ( v42 >= v37 )
                    goto LABEL_93;
                }
                v41 = p_priority[3];
              }
LABEL_93:
              p_priority[7] = v41;
            }
            p_priority += 30;
            --v40;
          }
          while ( v40 != 0 );
        }
        m_pParent = snd_duckerattacktime.m_pParent;
        v45 = 0;
        if ( v37 >= 4 )
        {
          v46 = ((unsigned int)(v37 - 4) >> 2) + 1;
          p_is_ducked = &g_grouprules[0].is_ducked;
          v45 = 4 * v46;
          do
          {
            v48 = *((float *)p_is_ducked + 6);
            v49 = *((float *)p_is_ducked + 7);
            if ( *p_is_ducked != 0 && v49 != v48 )
            {
              if ( v49 <= v48 )
                m_fValue = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                m_fValue = m_pParent->m_Value.m_fValue;
              v51 = 1.0 - *((float *)p_is_ducked + 2);
              maxTriggerLevel = m_fValue;
              ramptime = v51 * (0.1 / m_fValue);
              v52 = ramptime;
              if ( v49 > v48 )
                v52 = -ramptime;
              v53 = v52 + v49;
              if ( v48 > (float)(v52 + v49) && v52 < 0.0 )
                v53 = v48;
              if ( v53 > v48 && v52 > 0.0 )
                v53 = v48;
              *((float *)p_is_ducked + 7) = v53;
            }
            v54 = *((float *)p_is_ducked + 36);
            v55 = *((float *)p_is_ducked + 37);
            if ( p_is_ducked[60] != 0 && v55 != v54 )
            {
              if ( v55 <= v54 )
                v56 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v56 = m_pParent->m_Value.m_fValue;
              v57 = 1.0 - *((float *)p_is_ducked + 32);
              maxTriggerLevel = v56;
              ramptime = v57 * (0.1 / v56);
              v58 = ramptime;
              if ( v55 > v54 )
                v58 = -ramptime;
              v59 = v58 + v55;
              if ( v54 > (float)(v58 + v55) && v58 < 0.0 )
                v59 = v54;
              if ( v59 > v54 && v58 > 0.0 )
                v59 = v54;
              *((float *)p_is_ducked + 37) = v59;
            }
            v60 = *((float *)p_is_ducked + 66);
            v61 = *((float *)p_is_ducked + 67);
            if ( p_is_ducked[120] != 0 && v61 != v60 )
            {
              if ( v61 <= v60 )
                v62 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v62 = m_pParent->m_Value.m_fValue;
              v63 = 1.0 - *((float *)p_is_ducked + 62);
              maxTriggerLevel = v62;
              ramptime = v63 * (0.1 / v62);
              v64 = ramptime;
              if ( v61 > v60 )
                v64 = -ramptime;
              v65 = v64 + v61;
              if ( v60 > (float)(v64 + v61) && v64 < 0.0 )
                v65 = v60;
              if ( v65 > v60 && v64 > 0.0 )
                v65 = v60;
              *((float *)p_is_ducked + 67) = v65;
            }
            v66 = *((float *)p_is_ducked + 96);
            v67 = *((float *)p_is_ducked + 97);
            if ( p_is_ducked[180] != 0 && v67 != v66 )
            {
              if ( v67 <= v66 )
                v68 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v68 = m_pParent->m_Value.m_fValue;
              v69 = 1.0 - *((float *)p_is_ducked + 92);
              maxTriggerLevel = v68;
              ramptime = v69 * (0.1 / v68);
              v70 = ramptime;
              if ( v67 > v66 )
                v70 = -ramptime;
              v71 = v70 + v67;
              if ( v66 > (float)(v70 + v67) && v70 < 0.0 )
                v71 = v66;
              if ( v71 > v66 && v70 > 0.0 )
                v71 = v66;
              *((float *)p_is_ducked + 97) = v71;
            }
            p_is_ducked += 240;
            --v46;
          }
          while ( v46 != 0 );
        }
        if ( v45 < v37 )
        {
          v72 = &g_grouprules[v45].is_ducked;
          v73 = v37 - v45;
          do
          {
            v74 = *((float *)v72 + 6);
            v75 = *((float *)v72 + 7);
            if ( *v72 != 0 && v75 != v74 )
            {
              if ( v75 <= v74 )
                v76 = snd_duckerreleasetime.m_pParent->m_Value.m_fValue;
              else
                v76 = m_pParent->m_Value.m_fValue;
              v77 = 1.0 - *((float *)v72 + 2);
              maxTriggerLevel = v76;
              ramptime = v77 * (0.1 / v76);
              v78 = ramptime;
              if ( v75 > v74 )
                v78 = -ramptime;
              v79 = v78 + v75;
              if ( v74 > (float)(v78 + v75) && v78 < 0.0 )
                v79 = v74;
              if ( v79 > v74 && v78 > 0.0 )
                v79 = v74;
              *((float *)v72 + 7) = v79;
            }
            v72 += 60;
            --v73;
          }
          while ( v73 != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100334E0
// Name: int S_GetMixGroupIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl S_GetMixGroupIndex(const char *pMixGroupName)
{
  unsigned int result; // eax

  result = MXR_GetMixgroupFromName(pszgroupname: pMixGroupName);
  if ( result > 0x7F )
  {
    DevWarning(a1: "Error: MixGroup %s cannot be resolved!\n", pMixGroupName);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033510
// Name: void S_SetMixLayerTriggerFactor(char const __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SetMixLayerTriggerFactor(const char *pMixLayerName, const char *pMixGroupName, float flFactor)
{
  int v3; // edi
  const char *v4; // esi
  int v5; // esi
  unsigned int MixgroupFromName; // eax
  layertrigger_t *v7; // esi

  v3 = 0;
  v4 = byte_1048CD04;
  while ( _V_stricmp(s1: v4, s2: pMixLayerName) != 0 )
  {
    v4 += 2688;
    ++v3;
    if ( (int)v4 >= (int)g_soundmixers[0].szsoundmixer )
    {
      v5 = -1;
      goto LABEL_5;
    }
  }
  v5 = v3;
LABEL_5:
  MixgroupFromName = MXR_GetMixgroupFromName(pszgroupname: pMixGroupName);
  if ( MixgroupFromName > 0x7F )
  {
    DevMsg(a1: "Error: MixGroup %s, in LayerTriggers cannot be resolved!\n", pMixGroupName);
  }
  else
  {
    v7 = &g_layertriggers[v5];
    if ( v7->bistrigger[MixgroupFromName] && v7->bhastrigger )
      v7->fmixamount[MixgroupFromName] = flFactor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100335A0
// Name: MXR_SetSoundMixer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetSoundMixer(const CCommand *args)
{
  const char *v1; // esi
  const char *v2; // edi
  long double v3; // st7
  float val; // [esp+0h] [ebp-14h]

  if ( args->m_nArgc == 4 )
  {
    v1 = args->m_ppArgv[1];
    v2 = args->m_ppArgv[2];
    v3 = atof(nptr: args->m_ppArgv[3]);
    bPrintSetMixerDebug = true;
    if ( g_isoundmixer >= 0 )
    {
      val = v3;
      S_SetMixGroupOfMixer(szgroupname: v1, szparam: v2, val, pmixer: &g_soundmixers[g_isoundmixer]);
    }
    bPrintSetMixerDebug = false;
  }
  else
  {
    DevMsg(a1: "Parameters: mix group name, [vol, mute, solo], value");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033620
// Name: MXR_SetMixLayer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetMixLayer(const CCommand *args)
{
  const char *v1; // edx
  const char *v2; // ebx
  const char *v3; // eax
  int v4; // edi
  const char *v5; // esi
  char *szparam; // [esp+18h] [ebp-8h]
  float val; // [esp+1Ch] [ebp-4h]
  const char *argsa; // [esp+28h] [ebp+8h]

  if ( args->m_nArgc == 5 )
  {
    v1 = args->m_ppArgv[3];
    v2 = args->m_ppArgv[2];
    v3 = args->m_ppArgv[4];
    argsa = args->m_ppArgv[1];
    szparam = (char *)v1;
    val = atof(nptr: v3);
    v4 = 0;
    bPrintSetMixerDebug = true;
    if ( g_cmixlayers > 0 )
    {
      v5 = byte_1048CD04;
      do
      {
        if ( _V_stricmp(s1: v5, s2: argsa) == 0 )
        {
          DevMsg(a1: "Setting MixLayer %s\n", v5);
          S_SetMixGroupOfMixer(szgroupname: v2, szparam, val, pmixer: (soundmixer_t *)(v5 - 4));
        }
        ++v4;
        v5 += 2688;
      }
      while ( v4 < g_cmixlayers );
    }
    bPrintSetMixerDebug = false;
  }
  else
  {
    DevMsg(a1: "Parameters: mix group name, layer name, [vol, mute, solo], value, amount");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100336E0
// Name: MXR_SetMixLayerAmount
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetMixLayerAmount(const CCommand *args)
{
  const char *v1; // ebx
  int v2; // esi
  soundmixer_t *i; // edi
  float val; // [esp+1Ch] [ebp+8h]

  if ( args->m_nArgc == 3 )
  {
    v1 = args->m_ppArgv[1];
    val = atof(nptr: args->m_ppArgv[2]);
    v2 = 0;
    if ( g_cmixlayers > 0 )
    {
      for ( i = g_mixlayers; _V_stricmp(s1: i->szsoundmixer, s2: v1) != 0; ++i )
      {
        if ( ++v2 >= g_cmixlayers )
          return;
      }
      DevMsg(a1: "Setting MixLayer %s : mix %f\n", i->szsoundmixer, val);
      i->mixAmount = val;
    }
  }
  else
  {
    DevMsg(a1: "Parameters: mixer name, mix amount");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033780
// Name: MXR_SetMixLayerTriggerFactor
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetMixLayerTriggerFactor(const CCommand *args)
{
  const char *v1; // esi
  const char *v2; // edi
  float flFactor; // [esp+0h] [ebp-Ch]

  if ( args->m_nArgc == 4 )
  {
    v1 = args->m_ppArgv[1];
    v2 = args->m_ppArgv[2];
    flFactor = atof(nptr: args->m_ppArgv[3]);
    S_SetMixLayerTriggerFactor(pMixLayerName: v1, pMixGroupName: v2, flFactor);
  }
  else
  {
    DevMsg(a1: "Parameters: mix layer name, mix group name, trigger amount");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100337D0
// Name: void MXR_GetValuesFromMixGroupIndex(struct mixervalues_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetValuesFromMixGroupIndex(mixervalues_t *mixValues, int imixgroup)
{
  soundmixer_t *v2; // ecx
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  if ( g_isoundmixer >= 0 && g_csoundmixers != 0 )
  {
    v2 = &g_soundmixers[g_isoundmixer];
    if ( v2 != nullptr && v2->mapMixgroupidToVolume[imixgroup] >= 0.0 )
    {
      v3 = v2->mapMixgroupidToLevel[imixgroup] * g_mastermixlayer.mapMixgroupidToLevel[imixgroup];
      mixValues->level = v3;
      mixValues->level = snd_mixerMasterLevel.m_pParent->m_Value.m_fValue * v3;
      v4 = v2->mapMixgroupidToDsp[imixgroup] * g_mastermixlayer.mapMixgroupidToDsp[imixgroup];
      mixValues->dsp = v4;
      mixValues->dsp = snd_mixerMasterDSP.m_pParent->m_Value.m_fValue * v4;
      v5 = g_mastermixlayer.mapMixgroupidToVolume[imixgroup] * v2->mapMixgroupidToVolume[imixgroup];
      mixValues->volume = v5;
      v6 = v2->mapMixgroupidToMute[imixgroup] <= g_mastermixlayer.mapMixgroupidToMute[imixgroup]
         ? g_mastermixlayer.mapMixgroupidToMute[imixgroup]
         : v2->mapMixgroupidToMute[imixgroup];
      v7 = (float)(1.0 - v6) * v5;
      mixValues->volume = v7;
      if ( g_soloActive > 0.0 )
      {
        v8 = v2->mapMixgroupidToSolo[imixgroup];
        if ( v8 <= g_mastermixlayer.mapMixgroupidToSolo[imixgroup] )
          v8 = g_mastermixlayer.mapMixgroupidToSolo[imixgroup];
        mixValues->volume = (float)(1.0 - (float)((float)(1.0 - (float)(v8 / g_soloActive)) * g_soloActive)) * v7;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033910
// Name: void MXR_GetVolFromMixGroup(struct channel_t __near *,struct mixervalues_t __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetVolFromMixGroup(channel_t *ch, mixervalues_t *mixValues, int *plast_mixgroupid)
{
  int v3; // esi
  float v4; // xmm5_4
  int *i; // edi
  int v6; // edx
  float v7; // xmm0_4
  int v8; // eax
  int v9; // [esp-10h] [ebp-14h]

  if ( g_isoundmixer >= 0 && g_csoundmixers != 0 && &g_soundmixers[g_isoundmixer] != nullptr )
  {
    v3 = 0;
    v4 = 1.0;
    for ( i = ch->mixgroups; ; ++i )
    {
      v6 = *i;
      if ( *i >= 0 )
      {
        if ( snd_disable_mixer_duck.m_pParent != nullptr && snd_disable_mixer_duck.m_pParent->m_Value.m_nValue != 0 )
        {
          v7 = 1.0;
        }
        else
        {
          v8 = g_mapMixgroupidToGrouprulesid[v6];
          v7 = g_grouprules[v8].is_ducked != 0 ? g_grouprules[v8].duck_ramp_val : 1.0;
        }
        if ( v4 > v7 )
          v4 = v7;
        if ( g_soundmixers[g_isoundmixer].mapMixgroupidToVolume[v6] >= 0.0 )
          break;
      }
      if ( ++v3 >= 8 )
      {
        *plast_mixgroupid = 0;
        mixValues->volume = v4;
        return;
      }
    }
    v9 = *i;
    *plast_mixgroupid = v6;
    MXR_GetValuesFromMixGroupIndex(mixValues, imixgroup: v9);
    mixValues->volume = mixValues->volume * v4;
  }
  else
  {
    *plast_mixgroupid = 0;
    mixValues->volume = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033A20
// Name: char const __near * MXR_ParseMixGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MXR_ParseMixGroup(const char *pstart)
{
  int m_nValue; // ecx
  void (*v2)(const char *, ...); // ebx
  grouprule_t *v3; // esi
  unsigned int v4; // eax
  const char *v5; // edi
  unsigned int v6; // eax

  if ( DebugMXRParse.m_pParent != nullptr )
    m_nValue = DebugMXRParse.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v2 = DevMsg;
  v3 = &g_grouprules[g_cgrouprules];
  if ( m_nValue != 0 )
    DevMsg(a1: "MixGroup %s:\n", com_token);
  v4 = strlen(com_token);
  if ( v4 > 0x1F )
    v4 = 31;
  _V_memcpy(dest: v3, src: com_token, count: v4);
  v5 = pstart;
  v3->szmixgroup[31] = 0;
  if ( COM_TokenWaiting(buffer: pstart) != 0 )
  {
    v5 = COM_Parse(data: pstart);
    if ( com_token[0] != 0 )
    {
      v6 = strlen(com_token);
      if ( v6 > 0x1F )
        v6 = 31;
      _V_memcpy(dest: v3->szdir, src: com_token, count: v6);
      _V_strlower(start: v3->szdir);
      v2 = DevMsg;
      if ( _V_strstr(s1: v3->szdir, search: "?voice") != nullptr )
        v3->is_voice = 1;
    }
  }
  else
  {
    DevMsg(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  v3->szdir[31] = 0;
  v3->classId = -1;
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->classId = MXR_AddClassname(pName: com_token);
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
    {
      if ( _V_stricmp(s1: com_token, s2: "CHAN_STATIC") != 0 )
      {
        if ( _V_stricmp(s1: com_token, s2: "CHAN_WEAPON") != 0 )
        {
          if ( _V_stricmp(s1: com_token, s2: "CHAN_VOICE") != 0 )
          {
            if ( _V_stricmp(s1: com_token, s2: "CHAN_BODY") != 0 )
            {
              if ( _V_stricmp(s1: com_token, s2: "CHAN_ITEM") == 0 )
                v3->chantype = 3;
            }
            else
            {
              v3->chantype = 4;
            }
          }
          else
          {
            v3->chantype = 2;
          }
        }
        else
        {
          v3->chantype = 1;
        }
      }
      else
      {
        v3->chantype = 6;
      }
    }
    else
    {
      v3->chantype = -1;
    }
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->soundlevel_min = atoi(nptr: com_token);
    else
      v3->soundlevel_min = -1;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->soundlevel_max = atoi(nptr: com_token);
    else
      v3->soundlevel_max = -1;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->priority = atoi(nptr: com_token);
    else
      v3->priority = 50;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->is_ducked = atoi(nptr: com_token);
    else
      v3->is_ducked = 0;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->causes_ducking = atoi(nptr: com_token);
    else
      v3->causes_ducking = 0;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->duck_target_pct = (float)atoi(nptr: com_token) * 0.0099999998;
    else
      v3->duck_target_pct = 0.5;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  if ( COM_TokenWaiting(buffer: v5) != 0 )
  {
    v5 = COM_Parse(data: v5);
    if ( com_token[0] != 0 )
      v3->ducker_threshold = (float)atoi(nptr: com_token) * 0.0099999998;
    else
      v3->ducker_threshold = 0.5;
  }
  else
  {
    v2(a1: "Error: Parsing soundmixers.txt, mixgroup rules incomplete!\n");
  }
  ++g_cgrouprules;
  v3->duck_ramp_val = 1.0;
  v3->duck_target_vol = 1.0;
  v3->total_vol = 0.0;
  v3->trigger_vol = 0.0;
  v3->mixgroupid = -1;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10033E80
// Name: char const __near * MXR_ParseSoundMixer(char const __near *,struct soundmixer_t __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MXR_ParseSoundMixer(const char *pstart, soundmixer_t *pmixer)
{
  const char *v2; // ebx
  int *p_mixgroupid; // esi
  double v4; // st7
  double v5; // st6
  double v6; // rt1
  double v7; // st6
  double v8; // st7
  float v9; // xmm1_4
  double v10; // st6
  float v11; // xmm1_4
  double v12; // st6
  float v13; // xmm1_4
  double v14; // st6
  float v15; // xmm1_4
  char szgroupname[32]; // [esp+34h] [ebp-38h] BYREF
  int parse_debug; // [esp+54h] [ebp-18h]
  float mute; // [esp+58h] [ebp-14h]
  float solo; // [esp+5Ch] [ebp-10h]
  float dsp; // [esp+60h] [ebp-Ch]
  float level; // [esp+64h] [ebp-8h]
  float volume; // [esp+68h] [ebp-4h]
  int i; // [esp+74h] [ebp+8h]

  if ( DebugMXRParse.m_pParent != nullptr )
    parse_debug = DebugMXRParse.m_pParent->m_Value.m_nValue;
  else
    parse_debug = 0;
  _V_strcpy(dest: szgroupname, src: com_token);
  v2 = pstart;
  volume = 1.0;
  level = 1.0;
  dsp = 1.0;
  solo = 0.0;
  mute = 0.0;
  if ( COM_TokenWaiting(buffer: pstart) != 0 )
  {
    v2 = COM_Parse(data: pstart);
    if ( com_token[0] != 0 )
      volume = atof(nptr: com_token);
    else
      volume = 1.0;
  }
  else
  {
    DevMsg(a1: "Error: Parsing soundmixers.txt, soundmixer mix group values incomplete!\n");
  }
  if ( snd_soundmixer_version.m_pParent != nullptr && snd_soundmixer_version.m_pParent->m_Value.m_nValue >= 2 )
  {
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      level = atof(nptr: com_token);
    }
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      dsp = atof(nptr: com_token);
    }
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      solo = atof(nptr: com_token);
    }
    if ( COM_TokenWaiting(buffer: v2) != 0 )
    {
      v2 = COM_Parse(data: v2);
      mute = atof(nptr: com_token);
    }
  }
  i = 0;
  if ( g_cgrouprules > 0 )
  {
    p_mixgroupid = &g_grouprules[0].mixgroupid;
    do
    {
      if ( _V_strcmp(s1: (const char *)p_mixgroupid - 32, s2: szgroupname) == 0 )
      {
        if ( (unsigned int)*p_mixgroupid >= 0x80 )
          DevMsg(a1: "Error: MixGroup %s, in SoundMixer %s, cannot be resolved!\n", com_token, pmixer->szsoundmixer);
        if ( parse_debug != 0 )
          DevMsg(a1: "MixGroup %s: %f : %f : %f : %f : %f \n", szgroupname, volume, level, dsp, solo, mute);
        if ( volume <= 0.0 )
        {
          v5 = 0.0;
          v4 = 0.0;
        }
        else
        {
          v4 = volume;
          v5 = 0.0;
        }
        v6 = v5;
        v7 = v4;
        v8 = v6;
        v9 = level;
        pmixer->mapMixgroupidToVolume[*p_mixgroupid] = v7;
        if ( v9 <= 0.0 )
          v10 = v8;
        else
          v10 = level;
        v11 = dsp;
        pmixer->mapMixgroupidToLevel[*p_mixgroupid] = v10;
        if ( v11 <= 0.0 )
          v12 = v8;
        else
          v12 = dsp;
        v13 = solo;
        pmixer->mapMixgroupidToDsp[*p_mixgroupid] = v12;
        if ( v13 <= 0.0 )
          v14 = v8;
        else
          v14 = solo;
        v15 = mute;
        pmixer->mapMixgroupidToSolo[*p_mixgroupid] = v14;
        if ( v15 > 0.0 )
          v8 = mute;
        pmixer->mapMixgroupidToMute[*p_mixgroupid] = v8;
      }
      p_mixgroupid += 30;
      ++i;
    }
    while ( i < g_cgrouprules );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10034110
// Name: char const __near * MXR_ParseLayerTriggers(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MXR_ParseLayerTriggers(const char *pstart)
{
  int v1; // edi
  const char *v2; // esi
  layertrigger_t *v4; // edi
  const char *v5; // ebx
  unsigned int MixgroupFromName; // eax
  unsigned int v7; // esi

  if ( DebugMXRParse.m_pParent != nullptr && DebugMXRParse.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "MixLayer triggered %s:\n", com_token);
  v1 = 0;
  v2 = byte_1048CD04;
  while ( _V_stricmp(s1: v2, s2: com_token) != 0 )
  {
    v2 += 2688;
    ++v1;
    if ( (int)v2 >= (int)g_soundmixers[0].szsoundmixer )
      goto LABEL_9;
  }
  if ( v1 == -1 )
  {
LABEL_9:
    _Warning(a1: "Failed to get mix layer %s!\n", com_token);
    return pstart;
  }
  v4 = &g_layertriggers[v1];
  if ( COM_TokenWaiting(buffer: pstart) != 0 )
  {
    v5 = COM_Parse(data: pstart);
    if ( com_token[0] != 0
      && (MixgroupFromName = MXR_GetMixgroupFromName(pszgroupname: com_token),
          v7 = MixgroupFromName,
          MixgroupFromName <= 0x7F) )
    {
      v4->bistrigger[MixgroupFromName] = true;
      v4->bhastrigger = true;
      if ( COM_TokenWaiting(buffer: v5) != 0 )
      {
        v5 = COM_Parse(data: v5);
        if ( com_token[0] != 0 )
          v4->fthreshold[v7] = atof(nptr: com_token);
        if ( COM_TokenWaiting(buffer: v5) != 0 )
        {
          v5 = COM_Parse(data: v5);
          if ( com_token[0] != 0 )
            v4->fmixamount[v7] = atof(nptr: com_token);
          if ( COM_TokenWaiting(buffer: v5) != 0 )
          {
            v5 = COM_Parse(data: v5);
            if ( com_token[0] != 0 )
              v4->fattack[v7] = atof(nptr: com_token);
            if ( COM_TokenWaiting(buffer: v5) != 0 )
            {
              v5 = COM_Parse(data: v5);
              if ( com_token[0] != 0 )
                v4->frelease[v7] = atof(nptr: com_token);
            }
          }
        }
      }
      return v5;
    }
    else
    {
      DevMsg(a1: "Error: MixGroup %s, in LayerTriggers cannot be resolved!\n", com_token);
      return v5;
    }
  }
  else
  {
    DevMsg(a1: "Error: MixLayer Trigger entries require minimum 2 arguments\n");
    return pstart;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100342F0
// Name: bool MXR_LoadAllSoundMixers(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MXR_LoadAllSoundMixers()
{
  float *mapMixgroupidToLevel; // esi
  float *v1; // eax
  int i; // ecx
  float *v3; // esi
  float *v4; // eax
  int j; // ecx
  bool *bistrigger; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  char *File; // ebx
  int v11; // esi
  const char *v12; // edi
  soundmixer_t *v13; // edi
  unsigned int v14; // eax
  soundmixer_t *v15; // eax
  char szFile[264]; // [esp+Ch] [ebp-118h] BYREF
  char *pbuffer; // [esp+114h] [ebp-10h]
  const char *pstart; // [esp+118h] [ebp-Ch]
  int currentParseLevel; // [esp+11Ch] [ebp-8h]
  int parse_debug; // [esp+120h] [ebp-4h]

  g_isoundmixer = -1;
  g_szsoundmixer_cur[0] = 0;
  g_csoundmixers = 0;
  g_cmixlayers = 0;
  g_cgrouprules = 0;
  _V_memset(dest: g_soundmixers, fill: 0, count: 86016);
  _V_memset(dest: g_mixlayers, fill: 0, count: 43008);
  _V_memset(dest: g_grouprules, fill: 0, count: 17280);
  mapMixgroupidToLevel = g_soundmixers[0].mapMixgroupidToLevel;
  do
  {
    _V_strcpy(dest: (char *)mapMixgroupidToLevel - 636, src: defaultValue);
    *(mapMixgroupidToLevel - 160) = 1.0;
    v1 = mapMixgroupidToLevel;
    for ( i = 128; i != 0; --i )
    {
      *(v1 - 128) = -1.0;
      *v1 = 1.0;
      v1[128] = 1.0;
      v1[256] = 0.0;
      v1[384] = 0.0;
      ++v1;
    }
    mapMixgroupidToLevel += 672;
  }
  while ( (int)mapMixgroupidToLevel < (int)flt_104AC780 );
  v3 = (float *)&unk_1048CF80;
  do
  {
    _V_strcpy(dest: (char *)v3 - 636, src: defaultValue);
    *(v3 - 160) = 0.0;
    v4 = v3;
    for ( j = 128; j != 0; --j )
    {
      *(v4 - 128) = -1.0;
      *v4 = 1.0;
      v4[128] = 1.0;
      v4[256] = 0.0;
      v4[384] = 0.0;
      ++v4;
    }
    v3 += 672;
  }
  while ( (int)v3 < (int)g_soundmixers[0].mapMixgroupidToLevel );
  bistrigger = g_layertriggers[0].bistrigger;
  do
  {
    *(bistrigger - 1) = false;
    v7 = 0;
    v8 = bistrigger + 643;
    do
    {
      bistrigger[v7] = false;
      *(v8 - 128) = 0;
      *v8 = 1065353216;
      v8[128] = 0;
      v8[256] = 0;
      ++v7;
      ++v8;
    }
    while ( v7 < 128 );
    bistrigger += 2180;
  }
  while ( (int)bistrigger < (int)&g_grouprules[0].szmixgroup[1] );
  V_snprintf(pDest: szFile, maxLen: 260, pFormat: "scripts/soundmixers.txt");
  File = (char *)COM_LoadFile(path: szFile, usehunk: 5, pLength: nullptr);
  pbuffer = File;
  if ( File == nullptr )
  {
    _Error(a1: "MXR_LoadAllSoundMixers: unable to open '%s'\n", szFile);
    return 0;
  }
  if ( DebugMXRParse.m_pParent != nullptr )
    parse_debug = DebugMXRParse.m_pParent->m_Value.m_nValue;
  else
    parse_debug = 0;
  v11 = 0;
  currentParseLevel = 0;
  v12 = COM_Parse(data: File);
  pstart = v12;
  if ( strlen(com_token) != 0 )
  {
    while ( 1 )
    {
      if ( com_token[0] == 123 )
      {
        ++currentParseLevel;
      }
      else
      {
        if ( com_token[0] == 125 )
        {
          --currentParseLevel;
          switch ( v11 )
          {
            case 1:
              MXR_AssignGroupIds();
              v11 = 0;
              if ( parse_debug != 0 )
                DevMsg(a1: "Total Mix Groups Rules: %i\n", g_cgrouprules);
              break;
            case 3:
              ++g_csoundmixers;
              v11 = 2;
              break;
            case 2:
              v11 = 0;
              break;
            case 5:
              ++g_cmixlayers;
              v11 = 4;
              break;
            case 4:
              v11 = 0;
              if ( parse_debug != 0 )
                DevMsg(a1: "Total Mix Layers: %i\n", g_cmixlayers);
              break;
            case 6:
              v11 = 0;
              break;
            default:
              break;
          }
          goto LABEL_79;
        }
        switch ( v11 )
        {
          case 0:
            if ( _V_strcmp(s1: com_token, s2: "MixGroups") != 0 )
            {
              if ( _V_strcmp(s1: com_token, s2: "SoundMixers") != 0 )
              {
                if ( _V_strcmp(s1: com_token, s2: "MixLayers") != 0 )
                {
                  if ( _V_strcmp(s1: com_token, s2: "LayerTriggers") == 0 )
                  {
                    v11 = 6;
                    if ( parse_debug != 0 )
                      DevMsg(a1: "Parsing LayerTriggers:\n");
                  }
                }
                else
                {
                  v11 = 4;
                  if ( parse_debug != 0 )
                    DevMsg(a1: "Parsing MixLayers:\n");
                }
              }
              else
              {
                v11 = 2;
                if ( parse_debug != 0 )
                  DevMsg(a1: "Parsing SoundMixers:\n");
              }
            }
            else
            {
              v11 = 1;
              if ( parse_debug != 0 )
                DevMsg(a1: "Parsing MixGroups:\n");
            }
            break;
          case 1:
            if ( g_cgrouprules <= 144 )
              v12 = MXR_ParseMixGroup(pstart: v12);
            else
              DevMsg(a1: "Error: Too many mix groups! MixGroup %s ignored\n", com_token);
            break;
          case 6:
            v12 = MXR_ParseLayerTriggers(pstart: v12);
            break;
          case 2:
            if ( currentParseLevel < 2 )
            {
              if ( g_csoundmixers <= 32 )
              {
                v13 = &g_soundmixers[g_csoundmixers];
                if ( parse_debug != 0 )
                  DevMsg(a1: "SoundMixer %s:\n", com_token);
                v11 = 3;
                v14 = strlen(com_token);
                if ( v14 > 0x1F )
                  v14 = 31;
LABEL_63:
                _V_memcpy(dest: v13->szsoundmixer, src: com_token, count: v14);
                v12 = pstart;
                break;
              }
              DevMsg(a1: "Error: Too many sound mixers! SoundMixer %s ignored\n", com_token);
            }
            break;
          case 3:
            if ( currentParseLevel == 2 )
            {
              v15 = &g_soundmixers[g_csoundmixers];
LABEL_78:
              v12 = MXR_ParseSoundMixer(pstart: v12, pmixer: v15);
            }
            break;
          case 4:
            if ( currentParseLevel >= 2 )
              break;
            if ( g_cmixlayers > 16 )
            {
              DevMsg(a1: "Error: Too many mix layers! MixLayer %s ignored\n", com_token);
              break;
            }
            v13 = &g_mixlayers[g_cmixlayers];
            if ( parse_debug != 0 )
              DevMsg(a1: "MixLayers %s:\n", com_token);
            v11 = 5;
            v14 = strlen(com_token);
            if ( v14 > 0x1F )
              v14 = 31;
            goto LABEL_63;
          default:
            if ( currentParseLevel == 2 )
            {
              v15 = &g_mixlayers[g_cmixlayers];
              goto LABEL_78;
            }
            break;
        }
      }
LABEL_79:
      v12 = COM_Parse(data: v12);
      pstart = v12;
      if ( strlen(com_token) == 0 )
      {
        File = pbuffer;
        break;
      }
    }
  }
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: File);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100348B0
// Name: MXR_GetSoundMixer
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetSoundMixer(const CCommand *args)
{
  if ( args->m_nArgc == 2 && g_isoundmixer >= 0 )
    S_GetMixGroupOfCurrentMixer(szgroupname: args->m_ppArgv[1], pmixer: &g_soundmixers[g_isoundmixer]);
}

//------------------------------------------------------------------------------
// Address: 0x100348F0
// Name: void MXR_DebugGraphMixVolumes(struct debug_showvols_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_DebugGraphMixVolumes(debug_showvols_t *groupvols, int cgroups)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  float *p_totalvol; // esi
  double v6; // st6
  float v7; // xmm0_4
  float v8; // xmm2_4
  int v9; // eax
  int v10; // eax
  int v11; // eax
  bool v12; // zf
  double m_fValue; // [esp+1Ch] [ebp-138h]
  char text[128]; // [esp+2Ch] [ebp-128h] BYREF
  char bartext[144]; // [esp+ACh] [ebp-A8h] BYREF
  int v16; // [esp+13Ch] [ebp-18h]
  float vol1; // [esp+140h] [ebp-14h]
  int b; // [esp+144h] [ebp-10h]
  float vol; // [esp+148h] [ebp-Ch]
  float vol2; // [esp+14Ch] [ebp-8h]
  float flYpos; // [esp+150h] [ebp-4h]

  v2 = 10 * (++g_debug_mxr_displaycount / 10);
  if ( g_debug_mxr_displaycount != v2 )
  {
    m_fValue = dsp_volume.m_pParent->m_Value.m_fValue;
    v3 = 96;
    v4 = 86;
    b = 226;
    V_snprintf(pDest: text, maxLen: 128, pFormat: "DSP Volume: %1.2f", m_fValue);
    CDebugOverlay::AddScreenTextOverlay(
      flXPos: 0.0,
      flYPos: 0.0,
      duration: 0.0099999998,
      r: 96,
      g: 86,
      b: 226,
      a: 255,
      text);
    flYpos = 0.025;
    if ( cgroups > 0 )
    {
      p_totalvol = &groupvols->totalvol;
      v16 = cgroups;
      do
      {
        v6 = *p_totalvol * g_DuckScale;
        v4 += 255
            * (((int)(((unsigned __int64)(2139062143LL * v4) >> 32) - v4) >> 7)
             + ((unsigned int)(((unsigned __int64)(2139062143LL * v4) >> 32) - v4) >> 31));
        v3 += 255
            * (((int)(((unsigned __int64)(2139062143LL * v3) >> 32) - v3) >> 7)
             + ((unsigned int)(((unsigned __int64)(2139062143LL * v3) >> 32) - v3) >> 31));
        b += 255
           * (((int)(((unsigned __int64)(2139062143LL * b) >> 32) - b) >> 7)
            + ((unsigned int)(((unsigned __int64)(2139062143LL * b) >> 32) - b) >> 31));
        V_snprintf(
          pDest: text,
          maxLen: 128,
          pFormat: "%s: %1.2f (%1.2f)",
          *((const char **)p_totalvol - 3),
          g_DuckScale * *(p_totalvol - 1),
          v6);
        CDebugOverlay::AddScreenTextOverlay(
          flXPos: 0.0,
          flYPos: flYpos,
          duration: 0.0099999998,
          r: v3,
          g: v4,
          b,
          a: 255,
          text);
        v7 = *p_totalvol * g_DuckScale;
        vol = v7;
        if ( v7 >= 0.0 )
        {
          if ( v7 <= 0.7 )
            v8 = v7;
          else
            v8 = 0.69999999;
        }
        else
        {
          v8 = 0.0;
        }
        vol1 = v8;
        if ( v7 >= 0.0 )
        {
          if ( v7 <= 0.95 )
            vol2 = v7;
          else
            vol2 = 0.94999999;
        }
        else
        {
          vol2 = 0.0;
        }
        if ( v8 > 0.0 )
        {
          _V_memset(dest: bartext, fill: 0, count: 144);
          v9 = (int)(float)(vol1 * 48.0);
          if ( v9 >= 0 )
          {
            if ( v9 > 143 )
              v9 = 143;
          }
          else
          {
            v9 = 0;
          }
          _V_memset(dest: bartext, fill: 45, count: v9);
          CDebugOverlay::AddScreenTextOverlay(
            flXPos: 0.30000001,
            flYPos: flYpos,
            duration: 0.0099999998,
            r: 0,
            g: 255,
            b: 0,
            a: 255,
            text: bartext);
          v7 = vol;
        }
        if ( vol2 > 0.7 )
        {
          _V_memset(dest: bartext, fill: 0, count: 144);
          v10 = (int)(float)(vol2 * 48.0);
          if ( v10 >= 0 )
          {
            if ( v10 > 143 )
              v10 = 143;
          }
          else
          {
            v10 = 0;
          }
          _V_memset(dest: bartext, fill: 45, count: v10);
          CDebugOverlay::AddScreenTextOverlay(
            flXPos: 0.30000001,
            flYPos: flYpos,
            duration: 0.0099999998,
            r: 255,
            g: 255,
            b: 0,
            a: 255,
            text: bartext);
          v7 = vol;
        }
        if ( v7 > 1.0 )
        {
          _V_memset(dest: bartext, fill: 0, count: 144);
          v11 = (int)(float)(vol * 48.0);
          if ( v11 >= 0 )
          {
            if ( v11 > 143 )
              v11 = 143;
          }
          else
          {
            v11 = 0;
          }
          _V_memset(dest: bartext, fill: 45, count: v11);
          CDebugOverlay::AddScreenTextOverlay(
            flXPos: 0.30000001,
            flYPos: flYpos,
            duration: 0.0099999998,
            r: 255,
            g: 0,
            b: 0,
            a: 255,
            text: bartext);
        }
        p_totalvol += 4;
        v12 = v16-- == 1;
        flYpos = flYpos + 0.025;
      }
      while ( !v12 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034CD0
// Name: void MXR_DebugShowMixVolumes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_DebugShowMixVolumes()
{
  int v0; // esi
  soundmixer_t *v1; // eax
  debug_showvols_t *v2; // ecx
  float *mapMixgroupidToVolume; // edi
  char *v4; // ebx
  float v5; // xmm0_4
  int szmixgroup; // eax
  int *p_mixgroupid; // edx
  float v8; // xmm2_4
  int m_count; // edi
  int i; // esi
  channel_t *v11; // ecx
  float last_vol; // xmm0_4
  int last_mixgroupid; // ecx
  int v14; // eax
  int *v15; // edx
  debug_showvols_t groupvols[128]; // [esp+4h] [ebp-98Ch] BYREF
  CChannelList list; // [esp+804h] [ebp-18Ch] BYREF
  int cgroups; // [esp+98Ch] [ebp-4h]

  v0 = 0;
  if ( snd_showmixer.m_pParent != nullptr && snd_showmixer.m_pParent->m_Value.m_nValue != 0 )
  {
    cgroups = 0;
    if ( g_isoundmixer >= 0 )
    {
      v1 = &g_soundmixers[g_isoundmixer];
      v2 = groupvols;
      mapMixgroupidToVolume = v1->mapMixgroupidToVolume;
      v4 = (char *)((char *)&g_mastermixlayer - (char *)v1);
      do
      {
        v5 = *mapMixgroupidToVolume;
        if ( *mapMixgroupidToVolume >= 0.0 )
        {
          szmixgroup = 0;
          v2->mixgroupid = v0;
          if ( v0 >= 0 )
          {
            if ( g_cgrouprules <= 0 )
            {
LABEL_12:
              szmixgroup = 0;
            }
            else
            {
              p_mixgroupid = &g_grouprules[0].mixgroupid;
              while ( *p_mixgroupid != v0 )
              {
                ++szmixgroup;
                p_mixgroupid += 30;
                if ( szmixgroup >= g_cgrouprules )
                  goto LABEL_12;
              }
              szmixgroup = (int)g_grouprules[szmixgroup].szmixgroup;
            }
          }
          v8 = *(float *)((char *)mapMixgroupidToVolume + (_DWORD)v4);
          ++cgroups;
          v2->psz = (char *)szmixgroup;
          v2->totalvol = 0.0;
          v2->vol = v8 * v5;
          ++v2;
        }
        ++v0;
        ++mapMixgroupidToVolume;
      }
      while ( v0 < 128 );
      CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, &list);
      m_count = list.m_count;
      for ( i = 0; i < m_count; ++i )
      {
        v11 = &channels[list.m_list[i]];
        last_vol = v11->last_vol;
        if ( last_vol > 0.0 )
        {
          last_mixgroupid = v11->last_mixgroupid;
          v14 = 0;
          v15 = &groupvols[0].mixgroupid;
          while ( last_mixgroupid != *v15 )
          {
            ++v14;
            v15 += 4;
            if ( v14 >= 128 )
              goto LABEL_23;
          }
          groupvols[v14].totalvol = groupvols[v14].totalvol + last_vol;
        }
LABEL_23:
        ;
      }
      MXR_DebugGraphMixVolumes(groupvols, cgroups);
    }
    else
    {
      DevMsg(a1: "No sound mixer selected!");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034E40
// Name: void MXR_SetSoloActive(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_SetSoloActive()
{
  float v0; // xmm0_4
  soundmixer_t *v1; // eax
  float *mapMixgroupidToSolo; // edx
  float *v3; // ecx

  MXR_AccumulateMasterMixLayer();
  v0 = 0.0;
  g_soloActive = 0.0;
  if ( snd_disable_mixer_solo.m_pParent == nullptr || snd_disable_mixer_solo.m_pParent->m_Value.m_nValue == 0 )
  {
    v1 = &g_soundmixers[g_isoundmixer];
    mapMixgroupidToSolo = g_mastermixlayer.mapMixgroupidToSolo;
    v3 = &v1->mapMixgroupidToSolo[1];
    do
    {
      if ( v0 <= *(v3 - 1) )
        v0 = *(v3 - 1);
      if ( v0 <= *mapMixgroupidToSolo )
        v0 = *mapMixgroupidToSolo;
      if ( v0 <= *v3 )
        v0 = *v3;
      if ( v0 <= *(float *)((char *)v3 + (char *)&g_mastermixlayer - (char *)v1) )
        v0 = *(float *)((char *)v3 + (char *)&g_mastermixlayer - (char *)v1);
      if ( v0 <= v3[1] )
        v0 = v3[1];
      if ( v0 <= *(float *)((char *)v3 + g_mastermixlayer.szsoundmixer - (char *)v1) )
        v0 = *(float *)((char *)v3 + g_mastermixlayer.szsoundmixer - (char *)v1);
      if ( v0 <= v3[2] )
        v0 = v3[2];
      if ( v0 <= *(float *)((char *)v3 + &g_mastermixlayer.szsoundmixer[4] - (char *)v1) )
        v0 = *(float *)((char *)v3 + &g_mastermixlayer.szsoundmixer[4] - (char *)v1);
      mapMixgroupidToSolo += 4;
      v3 += 4;
    }
    while ( (int)mapMixgroupidToSolo < (int)g_mastermixlayer.mapMixgroupidToMute );
    g_soloActive = v0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034F20
// Name: void MXR_GetMixGroupFromSoundsource(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MXR_GetMixGroupFromSoundsource(channel_t *pchan)
{
  int v2; // esi
  IClientEntity *v3; // eax
  int v4; // eax
  const char *v5; // eax
  void (*v6)(const char *, ...); // ebx
  classlistelem_t *v7; // ebx
  bool v8; // al
  CSfxTable *sfx; // ecx
  bool v10; // zf
  int v11; // eax
  int *p_classId; // esi
  bool v13; // cl
  CSfxTable *v14; // eax
  int m_mixGroupCount; // edx
  int v16; // eax
  float m_flSoundLevel; // xmm0_4
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  char *m_pszString; // eax
  char sndname[260]; // [esp+28h] [ebp-134h] BYREF
  bool classMatch[16]; // [esp+12Ch] [ebp-30h]
  int lastMixGroup; // [esp+13Ch] [ebp-20h] BYREF
  mixervalues_t mValues; // [esp+140h] [ebp-1Ch] BYREF
  float soundlevel; // [esp+14Ch] [ebp-10h]
  int i; // [esp+150h] [ebp-Ch]
  int currentDirRule; // [esp+154h] [ebp-8h]
  int cmixgroups; // [esp+158h] [ebp-4h]
  int bIsPlayer; // [esp+164h] [ebp+8h]
  bool bIsPlayer_3; // [esp+167h] [ebp+Bh]

  pchan->mixgroups[0] = -1;
  pchan->mixgroups[1] = -1;
  pchan->mixgroups[2] = -1;
  pchan->mixgroups[3] = -1;
  pchan->mixgroups[4] = -1;
  pchan->mixgroups[5] = -1;
  pchan->mixgroups[6] = -1;
  pchan->mixgroups[7] = -1;
  pchan->sfx->getname(this: pchan->sfx, a2: sndname, a3: 260u);
  V_FixSlashes(pname: sndname, separator: 47);
  v2 = 0;
  if ( entitylist != nullptr
    && (v3 = entitylist->GetClientEntity(this: entitylist, a2: pchan->soundsource)) != nullptr
    && (v4 = (int)v3->GetClientClass(this: &v3->IClientNetworkable)) != 0 )
  {
    v5 = *(const char **)(v4 + 8);
    cmixgroups = (int)v5;
  }
  else
  {
    cmixgroups = 0;
    v5 = nullptr;
  }
  if ( snd_showclassname.m_pParent != nullptr && snd_showclassname.m_pParent->m_Value.m_nValue == 1 && v5 != nullptr )
  {
    v6 = DevMsg;
    DevMsg(a1: "(%s:%s) \n", v5, sndname);
  }
  else
  {
    v6 = DevMsg;
  }
  bIsPlayer_3 = g_pSoundServices->IsPlayer(this: g_pSoundServices, a2: pchan->soundsource);
  if ( g_cgroupclass > 0 )
  {
    v7 = g_groupclasslist;
    do
    {
      v8 = cmixgroups != 0 && V_stristr(pStr: (const char *)cmixgroups, pSearch: v7->szclassname) != nullptr
        || bIsPlayer_3 && _V_strcmp(s1: v7->szclassname, s2: "localPlayer") == 0;
      classMatch[v2++] = v8;
      ++v7;
    }
    while ( v2 < g_cgroupclass );
    v6 = DevMsg;
  }
  sfx = pchan->sfx;
  v10 = (*((_BYTE *)sfx + 12) & 8) == 0;
  cmixgroups = 0;
  if ( v10 )
    CSfxTable::OnNameChanged(this: sfx, pName: sndname);
  v11 = 0;
  bIsPlayer = 0;
  currentDirRule = pchan->sfx->m_mixGroupList[0];
  i = 0;
  if ( g_cgrouprules > 0 )
  {
    p_classId = &g_grouprules[0].classId;
    do
    {
      v13 = true;
      if ( currentDirRule == v11 )
      {
        v14 = pchan->sfx;
        m_mixGroupCount = v14->m_mixGroupCount;
        ++bIsPlayer;
        currentDirRule = 255;
        if ( bIsPlayer < m_mixGroupCount )
          currentDirRule = v14->m_mixGroupList[bIsPlayer];
      }
      else if ( *((_BYTE *)p_classId - 32) != 0 )
      {
        goto LABEL_33;
      }
      if ( *p_classId < 0 || (v13 = classMatch[*p_classId]) )
      {
        v16 = p_classId[1];
        if ( v16 >= 0 && pchan->entchannel != v16 )
LABEL_33:
          v13 = false;
      }
      m_flSoundLevel = pchan->m_flSoundLevel;
      soundlevel = m_flSoundLevel;
      if ( v13 )
      {
        v18 = p_classId[2];
        if ( v18 < 0 || (float)v18 <= m_flSoundLevel )
        {
          v19 = p_classId[3];
          if ( v19 < 0 || m_flSoundLevel <= (float)v19 )
          {
            v20 = cmixgroups;
            pchan->mixgroups[cmixgroups] = *(p_classId - 9);
            v21 = v20 + 1;
            cmixgroups = v21;
            if ( v21 == 1 )
            {
              if ( (snd_list.m_nFlags & 0x1000) != 0 )
              {
                m_pszString = "FCVAR_NEVER_AS_STRING";
                goto LABEL_44;
              }
              m_pszString = snd_list.m_pParent->m_Value.m_pszString;
              if ( m_pszString != nullptr && *m_pszString != 0 )
              {
LABEL_44:
                if ( V_stristr(pStr: sndname, pSearch: m_pszString) != nullptr )
                {
                  v6(a1: "%s", sndname);
                  mValues.volume = 1.0;
                  mValues.level = 1.0;
                  mValues.dsp = 1.0;
                  MXR_GetVolFromMixGroup(ch: pchan, mixValues: &mValues, plast_mixgroupid: &lastMixGroup);
                  if ( *((_BYTE *)p_classId - 68) != 0 )
                    v6(
                      a1: " : %s : vol: %4.2f, sndlvl: %i \n",
                      (const char *)p_classId - 68,
                      mValues.volume,
                      (unsigned int)COERCE_UNSIGNED_INT64(soundlevel));
                }
                v21 = cmixgroups;
              }
            }
            else if ( v21 >= 8 )
            {
              return;
            }
            if ( snd_showclassname.m_pParent != nullptr && snd_showclassname.m_pParent->m_Value.m_nValue >= 2 )
            {
              if ( v21 == 1 )
                v6(a1: "\n%s:%s: ", g_szsoundmixer_cur, sndname);
              if ( *((_BYTE *)p_classId - 68) != 0 )
                v6(a1: "%s ", (const char *)p_classId - 68);
            }
          }
        }
      }
      v11 = i + 1;
      p_classId += 30;
      i = v11;
    }
    while ( v11 < g_cgrouprules );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035260
// Name: void S_FlushMixers(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl S_FlushMixers()
{
  MXR_LoadAllSoundMixers();
}

} // namespace engine_xlsp
