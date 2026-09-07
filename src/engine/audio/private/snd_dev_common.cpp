// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_dev_common.cpp
// Functions: 19
// ============================================================

#include "engine\audio\private\snd_dev_common.h"

//------------------------------------------------------------------------------
// Address: 0x100058E0
// Name: public: virtual void CAudioDeviceBase::ApplyDSPEffects(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::ApplyDSPEffects(
        CAudioDeviceBase *this,
        int idsp,
        portable_samplepair_t *pbuffront,
        portable_samplepair_t *pbufrear,
        portable_samplepair_t *pbufcenter,
        int samplecount)
{
  DEBUG_StartSoundMeasure(type: 1, samplecount);
  DSP_Process(idsp, pbfront: pbuffront, pbrear: pbufrear, pbcenter: pbufcenter, sampleCount: samplecount);
  DEBUG_StopSoundMeasure(type: 1, samplecount);
}

//------------------------------------------------------------------------------
// Address: 0x10005920
// Name: public: virtual void CAudioDeviceBase::MixUpsample(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::MixUpsample(CAudioDeviceBase *this, int sampleCount, int filtertype)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int ifilter; // edi

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  ifilter = CurrentPaintbufferPtr->ifilter;
  S_MixBufferUpsample2x(
    count: sampleCount,
    pbuffer: CurrentPaintbufferPtr->pbuf,
    pfiltermem: CurrentPaintbufferPtr->fltmem[ifilter],
    cfltmem: 3,
    filtertype);
  if ( CurrentPaintbufferPtr->fsurround )
  {
    S_MixBufferUpsample2x(
      count: sampleCount,
      pbuffer: CurrentPaintbufferPtr->pbufrear,
      pfiltermem: CurrentPaintbufferPtr->fltmemrear[ifilter],
      cfltmem: 3,
      filtertype);
    if ( CurrentPaintbufferPtr->fsurround_center )
      S_MixBufferUpsample2x(
        count: sampleCount,
        pbuffer: CurrentPaintbufferPtr->pbufcenter,
        pfiltermem: CurrentPaintbufferPtr->fltmemcenter[ifilter],
        cfltmem: 3,
        filtertype);
  }
  ++CurrentPaintbufferPtr->ifilter;
}

//------------------------------------------------------------------------------
// Address: 0x100059A0
// Name: public: virtual void CAudioDeviceBase::Mix8Mono(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix8Mono(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix8MonoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        (unsigned __int8 *)pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix8MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix8MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A70
// Name: public: virtual void CAudioDeviceBase::Mix8Stereo(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix8Stereo(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix8StereoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        (unsigned __int8 *)pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix8StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix8StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005B40
// Name: public: virtual void CAudioDeviceBase::Mix16Mono(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix16Mono(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix16MonoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix16MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix16MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005C10
// Name: public: virtual void CAudioDeviceBase::Mix16Stereo(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix16Stereo(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix16StereoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix16StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix16StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D10
// Name: float clamp<float,int,int>(float const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,int>(float *val, const int *minVal, const int *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= (float)*maxVal )
    return vala;
  return (float)*maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x10005D60
// Name: XfadeSpeakerVolToMono
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
float __usercall XfadeSpeakerVolToMono@<xmm0>(
        float a1@<xmm0>,
        float scale,
        float xfade,
        float ispeaker,
        bool fmix2channels)
{
  float v5; // xmm0_4
  bool v7; // zf
  float v8; // xmm0_4
  float v9; // xmm0_4
  _BYTE v10[36]; // [esp+0h] [ebp-24h] OVERLAPPED BYREF

  if ( a1 == 4.0 )
  {
    strcpy(&v10[4], "fff?fff?fff?fff?fff?fff?");
    v5 = 0.0;
    v10[29] = 0;
    *(_WORD *)&v10[30] = 0;
    *(_DWORD *)&v10[32] = 0;
    if ( fmix2channels )
    {
      if ( ispeaker >= 0.0 )
      {
        v5 = 3.0;
        if ( ispeaker <= 3.0 )
          v5 = ispeaker;
      }
      return (float)((float)(*(float *)&v10[4 * (int)v5 + 20] - scale) * xfade) + scale;
    }
    else
    {
      if ( ispeaker >= 0.0 )
      {
        v5 = 3.0;
        if ( ispeaker <= 3.0 )
          v5 = ispeaker;
      }
      return (float)((float)(*(float *)&v10[4 * (int)v5 + 4] - scale) * xfade) + scale;
    }
  }
  else
  {
    v7 = a1 == 5.0;
    v8 = 0.89999998;
    if ( v7 )
    {
      strcpy(v10, "fff?fff?");
      v10[9] = 0;
      *(_WORD *)&v10[10] = 16128;
      *(_DWORD *)&v10[12] = 1056964608;
      *(_DWORD *)&v10[16] = 1063675494;
      v9 = ispeaker;
      if ( ispeaker >= 0.0 )
      {
        if ( ispeaker > 4.0 )
          v9 = 4.0;
      }
      else
      {
        v9 = 0.0;
      }
      v8 = *(float *)&v10[4 * (int)v9];
    }
    return (float)((float)(v8 - scale) * xfade) + scale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E90
// Name: GetSpeakerVol
// Source: json
//------------------------------------------------------------------------------
float __usercall GetSpeakerVol@<xmm0>(
        int a1@<edi>,
        int a2@<esi>,
        float a3@<xmm0>,
        float yaw_source,
        float mono,
        float yaw_speaker,
        bool fmix2channels)
{
  int v7; // xmm3_4
  long double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  double v11; // st7
  float v12; // xmm1_4
  double v13; // st7
  bool v14; // cc
  float v16; // [esp-10h] [ebp-18h]
  float v17; // [esp-4h] [ebp-Ch]
  float xfade; // [esp+4h] [ebp-4h]

  v7 = 0;
  v8 = fabs(yaw_source - yaw_speaker);
  if ( v8 <= 180.0 )
  {
    v9 = v8;
  }
  else
  {
    xfade = v8;
    v9 = 360.0 - xfade;
  }
  if ( a3 < 0.0 )
    a3 = a3 + 360.0;
  if ( a3 > 180.0 )
    a3 = 360.0 - a3;
  if ( a3 > 90.0 )
    a3 = 90.0 - (float)(a3 - 90.0);
  if ( a3 > 45.0 )
  {
    v10 = (float)((float)(a3 - 45.0) * 0.022222223) + mono;
    if ( v10 < 0.0 || (v7 = 1065353216, v10 > 1.0) )
      v10 = *(float *)&v7;
    mono = v10;
  }
  if ( a1 != 2 )
  {
    if ( v9 >= 90.0 )
      goto LABEL_35;
    if ( a1 == 4 )
    {
      v17 = 1.5;
      if ( a2 == 99 )
      {
        v12 = v9 * 0.0074074073;
LABEL_26:
        v11 = FastPow(a: v12, b: v17);
        goto LABEL_27;
      }
LABEL_25:
      v12 = v9 * 0.011111111;
      goto LABEL_26;
    }
    if ( a2 != 0 )
    {
      if ( a2 != 1 )
      {
        if ( a2 != 4 )
        {
LABEL_24:
          v17 = 1.5;
          goto LABEL_25;
        }
        if ( v9 <= 45.0 )
        {
          v11 = FastPow(a: v9 * 0.022222223, b: 1.5);
          goto LABEL_27;
        }
LABEL_35:
        v13 = 0.0;
        goto GetVolExit;
      }
      v14 = yaw_speaker <= yaw_source;
    }
    else
    {
      v14 = yaw_source <= yaw_speaker;
    }
    if ( v14 )
      goto LABEL_24;
    if ( v9 <= 75.0 )
    {
      v11 = FastPow(a: v9 * 0.013333334, b: 1.5);
      goto LABEL_27;
    }
    goto LABEL_35;
  }
  v11 = FastPow(a: v9 * 0.0055555557, b: 1.5);
LABEL_27:
  v13 = 1.0 - v11;
GetVolExit:
  v16 = v13;
  return XfadeSpeakerVolToMono((float)a1, scale: v16, xfade: mono, ispeaker: (float)a2, fmix2channels);
}

//------------------------------------------------------------------------------
// Address: 0x10006040
// Name: public: virtual void CAudioDeviceBase::SpatializeChannel(int,int __near * const,int,class Vector const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::SpatializeChannel(
        CAudioDeviceBase *this,
        int nSlot,
        int *volume,
        int master_vol,
        const Vector *sourceDir,
        float gain,
        float mono,
        int nWaveType)
{
  CAudioDeviceBase *v9; // edi
  float v10; // xmm0_4
  int v11; // xmm1_4
  float v12; // xmm0_4
  long double v13; // st7
  float v14; // xmm3_4
  float v15; // xmm0_4
  double v16; // st7
  float v18; // xmm0_4
  long double v19; // st6
  float v20; // xmm2_4
  float v21; // xmm0_4
  double v22; // st7
  float v23; // xmm0_4
  float x; // xmm2_4
  float y; // xmm4_4
  float v26; // xmm3_4
  int v27; // edx
  int v28; // ecx
  int v29; // eax
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  long double v33; // st7
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  long double v37; // st7
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  long double v42; // st7
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  long double v47; // st7
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  double v52; // st7
  double v53; // st7
  double v54; // st4
  double v55; // st6
  float v56; // xmm6_4
  float v57; // xmm3_4
  float v58; // xmm0_4
  long double v59; // st7
  float v60; // xmm2_4
  float v61; // xmm4_4
  float v62; // xmm6_4
  float v63; // xmm3_4
  float v64; // xmm0_4
  long double v65; // st7
  float v66; // xmm2_4
  float v67; // xmm4_4
  float v68; // xmm0_4
  long double v69; // st7
  float v70; // xmm0_4
  float v71; // xmm2_4
  float v72; // xmm4_4
  float v73; // xmm0_4
  long double v74; // st7
  float v75; // xmm0_4
  float v76; // xmm5_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  double v79; // st7
  long double v80; // st7
  float v81; // xmm0_4
  float v82; // xmm5_4
  float v83; // xmm0_4
  float v84; // xmm0_4
  long double v85; // st7
  float v86; // xmm0_4
  float v87; // xmm2_4
  float v88; // xmm4_4
  float v89; // xmm0_4
  long double v90; // st7
  float v91; // xmm0_4
  float v92; // xmm5_4
  float v93; // xmm2_4
  float v94; // xmm0_4
  double v95; // st7
  long double v96; // st7
  float v97; // xmm0_4
  float v98; // xmm5_4
  float v99; // xmm0_4
  double v100; // st7
  float v101; // xmm6_4
  float v102; // xmm0_4
  float v103; // xmm2_4
  long double v104; // st7
  float v105; // xmm4_4
  float v106; // xmm3_4
  float v107; // xmm2_4
  double v108; // st7
  float v109; // xmm3_4
  long double v110; // st6
  float v111; // xmm2_4
  float v112; // xmm4_4
  float v113; // xmm5_4
  float v114; // xmm2_4
  long double v115; // st6
  float v116; // xmm2_4
  float v117; // xmm5_4
  float v118; // xmm4_4
  float v119; // xmm2_4
  int v120; // eax
  int v121; // ecx
  int v122; // eax
  int v123; // eax
  float v124; // [esp-10h] [ebp-4Ch]
  float v125; // [esp-10h] [ebp-4Ch]
  float v126; // [esp-10h] [ebp-4Ch]
  QAngle yaw_source; // [esp+0h] [ebp-3Ch] BYREF
  QAngle b; // [esp+Ch] [ebp-30h] BYREF
  Vector vec; // [esp+18h] [ebp-24h] BYREF
  CAudioDeviceBase *v130; // [esp+24h] [ebp-18h]
  QAngle angles; // [esp+28h] [ebp-14h] BYREF
  Vector source2d; // [esp+34h] [ebp-8h]
  float fcscalea; // [esp+44h] [ebp+8h]
  float fcscale; // [esp+44h] [ebp+8h]
  float fcscaleb; // [esp+44h] [ebp+8h]
  float fcscalec; // [esp+44h] [ebp+8h]
  float fcscaled; // [esp+44h] [ebp+8h]
  float fcscalee; // [esp+44h] [ebp+8h]
  float fcscalef; // [esp+44h] [ebp+8h]
  float fcscaleg; // [esp+44h] [ebp+8h]
  float fcscaleh; // [esp+44h] [ebp+8h]
  float fcscalei; // [esp+44h] [ebp+8h]
  float fcscalej; // [esp+44h] [ebp+8h]
  float fcscalek; // [esp+44h] [ebp+8h]
  float fcscalel; // [esp+44h] [ebp+8h]
  float fcscalem; // [esp+44h] [ebp+8h]
  float fcscalen; // [esp+44h] [ebp+8h]
  float fcscaleo; // [esp+44h] [ebp+8h]
  float fcscalep; // [esp+44h] [ebp+8h]
  float fcscaleq; // [esp+44h] [ebp+8h]
  float fcscaler; // [esp+44h] [ebp+8h]
  float fcscales; // [esp+44h] [ebp+8h]
  float fcscalet; // [esp+44h] [ebp+8h]
  float fcscaleu; // [esp+44h] [ebp+8h]
  float fcscalev; // [esp+44h] [ebp+8h]
  float fcscalew; // [esp+44h] [ebp+8h]
  float fcscalex; // [esp+44h] [ebp+8h]
  float fcscaley; // [esp+44h] [ebp+8h]
  float fcscalez; // [esp+44h] [ebp+8h]
  float lrscaleb; // [esp+48h] [ebp+Ch]
  float lrscale; // [esp+48h] [ebp+Ch]
  float lrscalea; // [esp+48h] [ebp+Ch]
  float lrscalec; // [esp+48h] [ebp+Ch]
  float rrscale; // [esp+50h] [ebp+14h]
  float rrscalea; // [esp+50h] [ebp+14h]
  float rrscaleb; // [esp+50h] [ebp+14h]
  float v167; // [esp+58h] [ebp+1Ch]
  float v168; // [esp+58h] [ebp+1Ch]
  float v169; // [esp+58h] [ebp+1Ch]
  float v170; // [esp+58h] [ebp+1Ch]
  float v171; // [esp+58h] [ebp+1Ch]
  float v172; // [esp+5Ch] [ebp+20h]
  float v173; // [esp+5Ch] [ebp+20h]
  float v174; // [esp+5Ch] [ebp+20h]
  float v175; // [esp+5Ch] [ebp+20h]
  float v176; // [esp+5Ch] [ebp+20h]
  float v177; // [esp+5Ch] [ebp+20h]
  float v178; // [esp+5Ch] [ebp+20h]
  float v179; // [esp+5Ch] [ebp+20h]
  float v180; // [esp+5Ch] [ebp+20h]
  float v181; // [esp+5Ch] [ebp+20h]
  float v182; // [esp+5Ch] [ebp+20h]
  float v183; // [esp+5Ch] [ebp+20h]
  float v184; // [esp+5Ch] [ebp+20h]

  v9 = this;
  v130 = this;
  source2d.x = 0.0;
  source2d.y = 0.0;
  memset((void *)&angles, 0, sizeof(angles));
  *volume = 0;
  volume[1] = 0;
  volume[2] = 0;
  volume[3] = 0;
  volume[4] = 0;
  volume[5] = 0;
  VectorAngles(forward: sourceDir, angles: &b);
  rrscale = b.x;
  lrscaleb = b.y;
  vec.x = listener_right[nSlot].x;
  LODWORD(vec.y) = MEMORY[0x1043930C][3 * nSlot];
  vec.z = 0.0;
  VectorNormalize(&vec);
  VectorAngles(forward: &vec, angles: &yaw_source);
  v10 = lrscaleb - yaw_source.y;
  v11 = 0;
  lrscale = lrscaleb - yaw_source.y;
  if ( lrscale < 0.0 )
    lrscale = v10 + 360.0;
  if ( !v9->m_bSurround )
  {
    if ( !v9->m_bHeadphone )
    {
      v30 = mono;
      v31 = rrscale;
      v173 = mono;
      v32 = rrscale;
      v33 = fabs(lrscale - 45.0);
      v34 = 0.0;
      if ( v33 <= 180.0 )
      {
        v35 = v33;
      }
      else
      {
        fcscaleb = v33;
        v35 = 360.0 - fcscaleb;
      }
      if ( rrscale < 0.0 )
        v32 = rrscale + 360.0;
      if ( v32 > 180.0 )
        v32 = 360.0 - v32;
      if ( v32 > 90.0 )
        v32 = 90.0 - (float)(v32 - 90.0);
      if ( v32 > 45.0 )
      {
        v36 = (float)((float)(v32 - 45.0) * 0.022222223) + mono;
        if ( v36 >= 0.0 )
        {
          if ( v36 > 1.0 )
            v36 = 1.0;
        }
        else
        {
          v36 = 0.0;
        }
        v173 = v36;
      }
      if ( v35 < 90.0 )
      {
        v31 = rrscale;
        v30 = mono;
        fcscalec = 1.0 - FastPow(a: v35 * 0.011111111, b: 1.5);
        v34 = fcscalec;
      }
      v37 = fabs(lrscale - 135.0);
      angles.z = (float)((float)(0.89999998 - v34) * v173) + v34;
      v174 = v30;
      v38 = v31;
      v39 = 0.0;
      if ( v37 <= 180.0 )
      {
        v40 = v37;
      }
      else
      {
        fcscaled = v37;
        v40 = 360.0 - fcscaled;
      }
      if ( v31 < 0.0 )
        v38 = v31 + 360.0;
      if ( v38 > 180.0 )
        v38 = 360.0 - v38;
      if ( v38 > 90.0 )
        v38 = 90.0 - (float)(v38 - 90.0);
      if ( v38 > 45.0 )
      {
        v41 = (float)((float)(v38 - 45.0) * 0.022222223) + v30;
        if ( v41 >= 0.0 )
        {
          if ( v41 > 1.0 )
            v41 = 1.0;
        }
        else
        {
          v41 = 0.0;
        }
        v174 = v41;
      }
      if ( v40 < 90.0 )
      {
        v31 = rrscale;
        v30 = mono;
        fcscalee = 1.0 - FastPow(a: v40 * 0.011111111, b: 1.5);
        v39 = fcscalee;
      }
      v42 = fabs(lrscale - 315.0);
      source2d.y = (float)((float)(0.89999998 - v39) * v174) + v39;
      v175 = v30;
      v43 = v31;
      v44 = 0.0;
      if ( v42 <= 180.0 )
      {
        v45 = v42;
      }
      else
      {
        fcscalef = v42;
        v45 = 360.0 - fcscalef;
      }
      if ( v31 < 0.0 )
        v43 = v31 + 360.0;
      if ( v43 > 180.0 )
        v43 = 360.0 - v43;
      if ( v43 > 90.0 )
        v43 = 90.0 - (float)(v43 - 90.0);
      if ( v43 > 45.0 )
      {
        v46 = (float)((float)(v43 - 45.0) * 0.022222223) + v30;
        if ( v46 >= 0.0 )
        {
          if ( v46 > 1.0 )
            v46 = 1.0;
        }
        else
        {
          v46 = 0.0;
        }
        v175 = v46;
      }
      if ( v45 < 90.0 )
      {
        v31 = rrscale;
        v30 = mono;
        fcscaleg = 1.0 - FastPow(a: v45 * 0.011111111, b: 1.5);
        v44 = fcscaleg;
      }
      v47 = fabs(lrscale - 225.0);
      source2d.x = (float)(COERCE_FLOAT(LODWORD(v44) ^ _mask__NegFloat_) * v175) + v44;
      rrscalea = v30;
      v48 = v31;
      v49 = 0.0;
      if ( v47 <= 180.0 )
      {
        v50 = v47;
      }
      else
      {
        v168 = v47;
        v50 = 360.0 - v168;
      }
      if ( v31 < 0.0 )
        v48 = v31 + 360.0;
      if ( v48 > 180.0 )
        v48 = 360.0 - v48;
      if ( v48 > 90.0 )
        v48 = 90.0 - (float)(v48 - 90.0);
      if ( v48 > 45.0 )
      {
        v51 = (float)((float)(v48 - 45.0) * 0.022222223) + v30;
        if ( v51 >= 0.0 )
        {
          if ( v51 > 1.0 )
            v51 = 1.0;
        }
        else
        {
          v51 = 0.0;
        }
        rrscalea = v51;
      }
      if ( v50 < 90.0 )
      {
        v169 = 1.0 - FastPow(a: v50 * 0.011111111, b: 1.5);
        v49 = v169;
      }
      v52 = source2d.x * 0.75 + angles.z;
      angles.y = (float)((float)-v49 * rrscalea) + v49;
      if ( v52 >= 0.0 )
      {
        v54 = v52;
        v53 = 1.0;
        if ( v54 > 1.0 )
          v54 = 1.0;
      }
      else
      {
        v53 = 1.0;
        v54 = 0.0;
      }
      angles.z = v54;
      v55 = 0.75 * angles.y + source2d.y;
      if ( v55 >= 0.0 )
      {
        if ( v55 > v53 )
        {
          x = 0.0;
          source2d.y = v53;
          v23 = 0.0;
          goto LABEL_37;
        }
      }
      else
      {
        v55 = 0.0;
      }
      x = 0.0;
      source2d.y = v55;
      v23 = 0.0;
LABEL_37:
      y = source2d.y;
      goto SpatialExit;
    }
    v12 = rrscale;
    v13 = fabs(lrscale);
    v172 = mono;
    if ( v13 <= 180.0 )
    {
      v14 = v13;
    }
    else
    {
      fcscalea = v13;
      v14 = 360.0 - fcscalea;
    }
    if ( rrscale < 0.0 )
      v12 = rrscale + 360.0;
    if ( v12 > 180.0 )
      v12 = 360.0 - v12;
    if ( v12 > 90.0 )
      v12 = 90.0 - (float)(v12 - 90.0);
    if ( v12 > 45.0 )
    {
      v15 = (float)((float)(v12 - 45.0) * 0.022222223) + mono;
      if ( v15 >= 0.0 )
      {
        if ( v15 > 1.0 )
          v15 = 1.0;
      }
      else
      {
        v15 = 0.0;
      }
      v172 = v15;
    }
    v16 = FastPow(a: v14 * 0.0055555557, b: 1.5);
    v18 = rrscale;
    fcscale = mono;
    angles.z = 1.0 - v16 + (0.89999998 - (1.0 - v16)) * v172;
    v19 = fabs(lrscale - 180.0);
    if ( v19 <= 180.0 )
    {
      v20 = v19;
    }
    else
    {
      v167 = v19;
      v20 = 360.0 - v167;
    }
    if ( rrscale < 0.0 )
      v18 = rrscale + 360.0;
    if ( v18 > 180.0 )
      v18 = 360.0 - v18;
    if ( v18 > 90.0 )
      v18 = 90.0 - (float)(v18 - 90.0);
    if ( v18 > 45.0 )
    {
      v21 = (float)((float)(v18 - 45.0) * 0.022222223) + mono;
      if ( v21 >= 0.0 )
      {
        if ( v21 > 1.0 )
          v21 = 1.0;
      }
      else
      {
        v21 = 0.0;
      }
      fcscale = v21;
    }
    v22 = FastPow(a: v20 * 0.0055555557, b: 1.5);
    v23 = angles.y;
    source2d.y = 1.0 - v22 + (0.89999998 - (1.0 - v22)) * fcscale;
LABEL_36:
    x = source2d.x;
    goto LABEL_37;
  }
  if ( nWaveType != 40 )
  {
    if ( !v9->m_bSurroundCenter )
    {
      v56 = mono;
      v57 = rrscale;
      v176 = mono;
      v58 = rrscale;
      v59 = fabs(lrscale - 45.0);
      v60 = 0.0;
      if ( v59 <= 180.0 )
      {
        v61 = v59;
      }
      else
      {
        fcscaleh = v59;
        v61 = 360.0 - fcscaleh;
      }
      if ( rrscale < 0.0 )
        v58 = rrscale + 360.0;
      if ( v58 > 180.0 )
        v58 = 360.0 - v58;
      if ( v58 > 90.0 )
        v58 = 90.0 - (float)(v58 - 90.0);
      if ( v58 > 45.0 )
      {
        v84 = (float)((float)(v58 - 45.0) * 0.022222223) + mono;
        if ( v84 >= 0.0 )
        {
          if ( v84 > 1.0 )
            v84 = 1.0;
        }
        else
        {
          v84 = 0.0;
        }
        v176 = v84;
      }
      if ( v61 < 90.0 )
      {
        v11 = 0;
        v57 = rrscale;
        v56 = mono;
        fcscaleo = 1.0 - FastPow(a: v61 * 0.011111111, b: 1.5);
        v60 = fcscaleo;
      }
      v85 = fabs(lrscale - 135.0);
      angles.z = (float)((float)(0.89999998 - v60) * v176) + v60;
      v180 = v56;
      v86 = v57;
      v87 = 0.0;
      if ( v85 <= 180.0 )
      {
        v88 = v85;
      }
      else
      {
        fcscalep = v85;
        v88 = 360.0 - fcscalep;
      }
      if ( v57 < 0.0 )
        v86 = v57 + 360.0;
      if ( v86 > 180.0 )
        v86 = 360.0 - v86;
      if ( v86 > 90.0 )
        v86 = 90.0 - (float)(v86 - 90.0);
      if ( v86 > 45.0 )
      {
        v89 = (float)((float)(v86 - 45.0) * 0.022222223) + v56;
        if ( v89 >= 0.0 )
        {
          if ( v89 > 1.0 )
            v89 = 1.0;
        }
        else
        {
          v89 = 0.0;
        }
        v180 = v89;
      }
      if ( v88 < 90.0 )
      {
        v11 = 0;
        v57 = rrscale;
        v56 = mono;
        fcscaleq = 1.0 - FastPow(a: v88 * 0.011111111, b: 1.5);
        v87 = fcscaleq;
      }
      y = (float)((float)(0.89999998 - v87) * v180) + v87;
      v90 = fabs(lrscale - 315.0);
      source2d.y = y;
      v181 = v56;
      v91 = v57;
      v92 = 0.0;
      if ( v90 <= 180.0 )
      {
        v93 = v90;
      }
      else
      {
        fcscaler = v90;
        v93 = 360.0 - fcscaler;
      }
      if ( v57 < 0.0 )
        v91 = v57 + 360.0;
      if ( v91 > 180.0 )
        v91 = 360.0 - v91;
      if ( v91 > 90.0 )
        v91 = 90.0 - (float)(v91 - 90.0);
      if ( v91 > 45.0 )
      {
        v94 = (float)((float)(v91 - 45.0) * 0.022222223) + v56;
        if ( v94 >= 0.0 )
        {
          if ( v94 > 1.0 )
            v94 = 1.0;
        }
        else
        {
          v94 = 0.0;
        }
        v181 = v94;
      }
      if ( v93 < 90.0 )
      {
        v95 = FastPow(a: v93 * 0.011111111, b: 1.5);
        v11 = 0;
        y = source2d.y;
        v57 = rrscale;
        v56 = mono;
        fcscales = 1.0 - v95;
        v92 = fcscales;
      }
      v96 = fabs(lrscale - 225.0);
      x = (float)((float)(0.89999998 - v92) * v181) + v92;
      source2d.x = x;
      rrscaleb = v56;
      v97 = v57;
      lrscalea = 0.0;
      if ( v96 <= 180.0 )
      {
        v98 = v96;
      }
      else
      {
        v171 = v96;
        v98 = 360.0 - v171;
      }
      if ( v57 < 0.0 )
        v97 = v57 + 360.0;
      if ( v97 > 180.0 )
        v97 = 360.0 - v97;
      if ( v97 > 90.0 )
        v97 = 90.0 - (float)(v97 - 90.0);
      if ( v97 > 45.0 )
      {
        v99 = (float)((float)(v97 - 45.0) * 0.022222223) + v56;
        if ( v99 < 0.0 || (v11 = 1065353216, v99 > 1.0) )
          v99 = *(float *)&v11;
        rrscaleb = v99;
      }
      if ( v98 < 90.0 )
      {
        v100 = FastPow(a: v98 * 0.011111111, b: 1.5);
        x = source2d.x;
        y = source2d.y;
        lrscalea = 1.0 - v100;
      }
      goto LABEL_253;
    }
    v101 = mono;
    v102 = rrscale;
    v182 = mono;
    v103 = rrscale;
    v104 = fabs(lrscale - 45.0);
    v105 = 0.0;
    if ( v104 <= 180.0 )
    {
      v106 = v104;
    }
    else
    {
      fcscalet = v104;
      v106 = 360.0 - fcscalet;
    }
    if ( rrscale < 0.0 )
      v103 = rrscale + 360.0;
    if ( v103 > 180.0 )
      v103 = 360.0 - v103;
    if ( v103 > 90.0 )
      v103 = 90.0 - (float)(v103 - 90.0);
    if ( v103 > 45.0 )
    {
      v107 = (float)((float)(v103 - 45.0) * 0.022222223) + mono;
      if ( v107 >= 0.0 )
      {
        if ( v107 > 1.0 )
          v107 = 1.0;
      }
      else
      {
        v107 = 0.0;
      }
      v182 = v107;
    }
    v108 = 1.5;
    if ( v106 < 90.0 )
    {
      if ( lrscale <= 45.0 )
      {
        v109 = v106 * 0.011111111;
        goto LABEL_274;
      }
      if ( v106 <= 75.0 )
      {
        v109 = v106 * 0.013333334;
LABEL_274:
        v101 = mono;
        v102 = rrscale;
        v11 = 0;
        fcscaleu = 1.0 - FastPow(a: v109, b: 1.5);
        v108 = 1.5;
        v105 = fcscaleu;
      }
    }
    v110 = fabs(lrscale - 90.0);
    angles.z = (float)((float)(0.89999998 - v105) * v182) + v105;
    v183 = v101;
    v111 = v102;
    v112 = 0.0;
    if ( v110 <= 180.0 )
    {
      v113 = v110;
    }
    else
    {
      fcscalev = v110;
      v113 = 360.0 - fcscalev;
    }
    if ( v102 < 0.0 )
      v111 = v102 + 360.0;
    if ( v111 > 180.0 )
      v111 = 360.0 - v111;
    if ( v111 > 90.0 )
      v111 = 90.0 - (float)(v111 - 90.0);
    if ( v111 > 45.0 )
    {
      v114 = (float)((float)(v111 - 45.0) * 0.022222223) + v101;
      if ( v114 >= 0.0 )
      {
        if ( v114 > 1.0 )
          v114 = 1.0;
      }
      else
      {
        v114 = 0.0;
      }
      v183 = v114;
    }
    if ( v113 < 90.0 && v113 <= 45.0 )
    {
      v124 = v108;
      v11 = 0;
      v102 = rrscale;
      v101 = mono;
      fcscalew = 1.0 - FastPow(a: v113 * 0.022222223, b: v124);
      v112 = fcscalew;
      v108 = 1.5;
    }
    v115 = fabs(lrscale - 135.0);
    angles.x = (float)((float)(0.89999998 - v112) * v183) + v112;
    v184 = v101;
    v116 = v102;
    v117 = 0.0;
    if ( v115 <= 180.0 )
    {
      v118 = v115;
    }
    else
    {
      fcscalex = v115;
      v118 = 360.0 - fcscalex;
    }
    if ( v102 < 0.0 )
      v116 = v102 + 360.0;
    if ( v116 > 180.0 )
      v116 = 360.0 - v116;
    if ( v116 > 90.0 )
      v116 = 90.0 - (float)(v116 - 90.0);
    if ( v116 > 45.0 )
    {
      v119 = (float)((float)(v116 - 45.0) * 0.022222223) + v101;
      if ( v119 >= 0.0 )
      {
        v11 = 1065353216;
        if ( v119 <= 1.0 )
          v11 = LODWORD(v119);
      }
      v184 = *(float *)&v11;
    }
    if ( v118 < 90.0 )
    {
      if ( lrscale >= 135.0 )
      {
        v126 = v108;
        v102 = rrscale;
        fcscalez = 1.0 - FastPow(a: v118 * 0.011111111, b: v126);
        v117 = fcscalez;
      }
      else if ( v118 <= 75.0 )
      {
        v125 = v108;
        v102 = rrscale;
        fcscaley = 1.0 - FastPow(a: v118 * 0.013333334, b: v125);
        v117 = fcscaley;
      }
    }
    source2d.y = (float)((float)(0.89999998 - v117) * v184) + v117;
    GetSpeakerVol(yaw_source: lrscale, mono, yaw_speaker: 315.0, fmix2channels: 0);
    source2d.x = v102;
    v23 = rrscale;
    GetSpeakerVol(yaw_source: lrscale, mono, yaw_speaker: 225.0, fmix2channels: 0);
    v9 = v130;
    goto LABEL_36;
  }
  v62 = mono;
  v63 = rrscale;
  v177 = mono;
  v64 = rrscale;
  v65 = fabs(lrscale - 45.0);
  v66 = 0.0;
  if ( v65 <= 180.0 )
  {
    v67 = v65;
  }
  else
  {
    fcscalei = v65;
    v67 = 360.0 - fcscalei;
  }
  if ( rrscale < 0.0 )
    v64 = rrscale + 360.0;
  if ( v64 > 180.0 )
    v64 = 360.0 - v64;
  if ( v64 > 90.0 )
    v64 = 90.0 - (float)(v64 - 90.0);
  if ( v64 > 45.0 )
  {
    v68 = (float)((float)(v64 - 45.0) * 0.022222223) + mono;
    if ( v68 >= 0.0 )
    {
      if ( v68 > 1.0 )
        v68 = 1.0;
    }
    else
    {
      v68 = 0.0;
    }
    v177 = v68;
  }
  if ( v67 < 90.0 )
  {
    v11 = 0;
    v63 = rrscale;
    v62 = mono;
    fcscalej = 1.0 - FastPow(a: v67 * 0.0074074073, b: 1.5);
    v66 = fcscalej;
  }
  v69 = fabs(lrscale - 135.0);
  angles.z = (float)((float)(0.89999998 - v66) * v177) + v66;
  v178 = v62;
  v70 = v63;
  v71 = 0.0;
  if ( v69 <= 180.0 )
  {
    v72 = v69;
  }
  else
  {
    fcscalek = v69;
    v72 = 360.0 - fcscalek;
  }
  if ( v63 < 0.0 )
    v70 = v63 + 360.0;
  if ( v70 > 180.0 )
    v70 = 360.0 - v70;
  if ( v70 > 90.0 )
    v70 = 90.0 - (float)(v70 - 90.0);
  if ( v70 > 45.0 )
  {
    v73 = (float)((float)(v70 - 45.0) * 0.022222223) + v62;
    if ( v73 >= 0.0 )
    {
      if ( v73 > 1.0 )
        v73 = 1.0;
    }
    else
    {
      v73 = 0.0;
    }
    v178 = v73;
  }
  if ( v72 < 90.0 )
  {
    v11 = 0;
    v63 = rrscale;
    v62 = mono;
    fcscalel = 1.0 - FastPow(a: v72 * 0.0074074073, b: 1.5);
    v71 = fcscalel;
  }
  y = (float)((float)(0.89999998 - v71) * v178) + v71;
  v74 = fabs(lrscale - 315.0);
  source2d.y = y;
  v179 = v62;
  v75 = v63;
  v76 = 0.0;
  if ( v74 <= 180.0 )
  {
    v77 = v74;
  }
  else
  {
    fcscalem = v74;
    v77 = 360.0 - fcscalem;
  }
  if ( v63 < 0.0 )
    v75 = v63 + 360.0;
  if ( v75 > 180.0 )
    v75 = 360.0 - v75;
  if ( v75 > 90.0 )
    v75 = 90.0 - (float)(v75 - 90.0);
  if ( v75 > 45.0 )
  {
    v78 = (float)((float)(v75 - 45.0) * 0.022222223) + v62;
    if ( v78 >= 0.0 )
    {
      if ( v78 > 1.0 )
        v78 = 1.0;
    }
    else
    {
      v78 = 0.0;
    }
    v179 = v78;
  }
  if ( v77 < 90.0 )
  {
    v79 = FastPow(a: v77 * 0.0074074073, b: 1.5);
    v11 = 0;
    y = source2d.y;
    v63 = rrscale;
    v62 = mono;
    fcscalen = 1.0 - v79;
    v76 = fcscalen;
  }
  v80 = fabs(lrscale - 225.0);
  x = (float)((float)(0.89999998 - v76) * v179) + v76;
  source2d.x = x;
  rrscaleb = v62;
  v81 = v63;
  lrscalea = 0.0;
  if ( v80 <= 180.0 )
  {
    v82 = v80;
  }
  else
  {
    v170 = v80;
    v82 = 360.0 - v170;
  }
  if ( v63 < 0.0 )
    v81 = v63 + 360.0;
  if ( v81 > 180.0 )
    v81 = 360.0 - v81;
  if ( v81 > 90.0 )
    v81 = 90.0 - (float)(v81 - 90.0);
  if ( v81 > 45.0 )
  {
    v83 = (float)((float)(v81 - 45.0) * 0.022222223) + v62;
    if ( v83 < 0.0 || (v11 = 1065353216, v83 > 1.0) )
      v83 = *(float *)&v11;
    rrscaleb = v83;
  }
  if ( v82 < 90.0 )
  {
    lrscalec = 1.0 - FastPow(a: v82 * 0.0074074073, b: 1.5);
    v23 = lrscalec + (float)((float)(0.89999998 - lrscalec) * rrscaleb);
    goto LABEL_36;
  }
LABEL_253:
  v23 = lrscalea + (float)((float)(0.89999998 - lrscalea) * rrscaleb);
SpatialExit:
  v26 = (float)master_vol * gain;
  v27 = (int)(float)(v26 * angles.z);
  v28 = v27;
  v29 = (int)(float)(v26 * y);
  volume[1] = v27;
  *volume = v29;
  if ( v27 >= 0 )
  {
    if ( v27 > 255 )
      v28 = 255;
  }
  else
  {
    v28 = 0;
  }
  volume[1] = v28;
  if ( v29 >= 0 )
  {
    if ( v29 > 255 )
      v29 = 255;
  }
  else
  {
    v29 = 0;
  }
  *volume = v29;
  if ( v9->m_bSurround )
  {
    v120 = (int)(float)(v26 * x);
    v121 = (int)(float)(v26 * v23);
    volume[3] = v120;
    volume[2] = v121;
    if ( v120 >= 0 )
    {
      if ( v120 > 255 )
        v120 = 255;
    }
    else
    {
      v120 = 0;
    }
    volume[3] = v120;
    v122 = (int)(float)(v26 * v23);
    if ( v121 >= 0 )
    {
      if ( v121 > 255 )
        v122 = 255;
    }
    else
    {
      v122 = 0;
    }
    volume[2] = v122;
    if ( v9->m_bSurroundCenter )
    {
      v123 = (int)(float)(v26 * angles.x);
      volume[4] = v123;
      volume[5] = 0;
      if ( v123 >= 0 )
      {
        if ( v123 > 255 )
          v123 = 255;
        volume[4] = v123;
      }
      else
      {
        volume[4] = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007570
// Name: public: virtual void CAudioDeviceBase::SpatializeChannel(int,float __near * const,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::SpatializeChannel(
        CAudioDeviceBase *this,
        int nSlot,
        float *volume,
        const Vector *sourceDir,
        float mono,
        float flRearToStereoScale)
{
  float v8; // xmm1_4
  int v9; // xmm0_4
  float v10; // xmm1_4
  long double v11; // st7
  float v12; // xmm3_4
  float v13; // xmm1_4
  double v14; // st7
  float v16; // xmm0_4
  long double v17; // st6
  float v18; // xmm2_4
  float v19; // xmm0_4
  double v20; // st7
  float y; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  bool v24; // cc
  float z; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  long double v29; // st7
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  long double v33; // st7
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm1_4
  long double v38; // st7
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm1_4
  float v43; // xmm1_4
  long double v44; // st7
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  double v48; // st7
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  long double v53; // st7
  float v54; // xmm5_4
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm1_4
  long double v58; // st7
  float v59; // xmm1_4
  float v60; // xmm4_4
  float v61; // xmm3_4
  float v62; // xmm1_4
  long double v63; // st7
  float v64; // xmm1_4
  float v65; // xmm4_4
  float v66; // xmm6_4
  float v67; // xmm1_4
  long double v68; // st7
  float v69; // xmm3_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  double v72; // st7
  float v73; // xmm6_4
  float v74; // xmm4_4
  float v75; // xmm3_4
  float v76; // xmm1_4
  long double v77; // st7
  float v78; // xmm1_4
  float v79; // xmm4_4
  float v80; // xmm5_4
  float v81; // xmm1_4
  long double v82; // st7
  float v83; // xmm1_4
  float v84; // xmm5_4
  float v85; // xmm4_4
  float v86; // xmm1_4
  float v87; // xmm4_4
  long double v88; // st7
  float v89; // xmm1_4
  float v90; // xmm5_4
  float v91; // xmm4_4
  float v92; // xmm1_4
  long double v93; // st7
  float v94; // xmm3_4
  float v95; // xmm5_4
  float v96; // xmm2_4
  double v97; // st7
  int v98; // xmm2_4
  int v99; // xmm1_4
  float v100; // xmm1_4
  QAngle a; // [esp+0h] [ebp-38h] BYREF
  QAngle v102; // [esp+Ch] [ebp-2Ch] BYREF
  Vector vec; // [esp+18h] [ebp-20h] BYREF
  float v104; // [esp+24h] [ebp-14h]
  Vector source2d; // [esp+28h] [ebp-10h] BYREF
  float fcscale; // [esp+34h] [ebp-4h]
  float lfscaleb; // [esp+40h] [ebp+8h]
  float lfscale; // [esp+40h] [ebp+8h]
  float lfscalec; // [esp+40h] [ebp+8h]
  float lfscaled; // [esp+40h] [ebp+8h]
  float lfscalee; // [esp+40h] [ebp+8h]
  float lfscalef; // [esp+40h] [ebp+8h]
  float lfscaleg; // [esp+40h] [ebp+8h]
  float lfscaleh; // [esp+40h] [ebp+8h]
  float lfscalea; // [esp+40h] [ebp+8h]
  float lfscalei; // [esp+40h] [ebp+8h]
  float lfscalej; // [esp+40h] [ebp+8h]
  float lfscalek; // [esp+40h] [ebp+8h]
  float lfscalel; // [esp+40h] [ebp+8h]
  float lfscalem; // [esp+40h] [ebp+8h]
  float lfscalen; // [esp+40h] [ebp+8h]
  float lfscaleo; // [esp+40h] [ebp+8h]
  float lfscalep; // [esp+40h] [ebp+8h]
  float lfscaleq; // [esp+40h] [ebp+8h]
  float lfscaler; // [esp+40h] [ebp+8h]
  float lfscales; // [esp+40h] [ebp+8h]
  float lfscalet; // [esp+40h] [ebp+8h]
  float lfscaleu; // [esp+40h] [ebp+8h]
  float rfscalea; // [esp+44h] [ebp+Ch]
  float rfscale; // [esp+44h] [ebp+Ch]
  float x; // [esp+48h] [ebp+10h]
  float v132; // [esp+48h] [ebp+10h]
  float v133; // [esp+48h] [ebp+10h]
  float v134; // [esp+48h] [ebp+10h]
  float v135; // [esp+4Ch] [ebp+14h]
  float v136; // [esp+4Ch] [ebp+14h]
  float v137; // [esp+4Ch] [ebp+14h]
  float v138; // [esp+4Ch] [ebp+14h]
  float v139; // [esp+4Ch] [ebp+14h]
  float v140; // [esp+4Ch] [ebp+14h]
  float v141; // [esp+4Ch] [ebp+14h]
  float nSlota; // [esp+50h] [ebp+18h]
  float nSlotb; // [esp+50h] [ebp+18h]
  int nSlotc; // [esp+50h] [ebp+18h]
  int nSlotd; // [esp+50h] [ebp+18h]
  float nSlote; // [esp+50h] [ebp+18h]
  int nSlotf; // [esp+50h] [ebp+18h]
  int nSlotg; // [esp+50h] [ebp+18h]
  int nSloth; // [esp+50h] [ebp+18h]

  memset(&source2d, 0, sizeof(source2d));
  fcscale = 0.0;
  v104 = 0.0;
  *volume = 0.0;
  volume[1] = 0.0;
  volume[2] = 0.0;
  volume[3] = 0.0;
  volume[4] = 0.0;
  volume[5] = 0.0;
  VectorAngles(forward: sourceDir, angles: &v102);
  x = v102.x;
  rfscalea = v102.y;
  vec.x = listener_right[nSlot].x;
  LODWORD(vec.y) = MEMORY[0x1043930C][3 * nSlot];
  vec.z = 0.0;
  VectorNormalize(&vec);
  VectorAngles(forward: &vec, angles: &a);
  v8 = rfscalea - a.y;
  v9 = 0;
  rfscale = v8;
  if ( v8 < 0.0 )
    rfscale = v8 + 360.0;
  if ( !this->m_bSurround )
  {
    if ( this->m_bHeadphone )
    {
      v10 = x;
      v11 = fabs(rfscale);
      nSlota = mono;
      if ( v11 <= 180.0 )
      {
        v12 = v11;
      }
      else
      {
        lfscaleb = v11;
        v12 = 360.0 - lfscaleb;
      }
      if ( x < 0.0 )
        v10 = x + 360.0;
      if ( v10 > 180.0 )
        v10 = 360.0 - v10;
      if ( v10 > 90.0 )
        v10 = 90.0 - (float)(v10 - 90.0);
      if ( v10 > 45.0 )
      {
        v13 = (float)((float)(v10 - 45.0) * 0.022222223) + mono;
        if ( v13 >= 0.0 )
        {
          if ( v13 <= 1.0 )
            v9 = LODWORD(v13);
          else
            v9 = 1065353216;
        }
        nSlota = *(float *)&v9;
      }
      v14 = FastPow(a: v12 * 0.0055555557, b: 1.5);
      v16 = x;
      lfscale = mono;
      fcscale = 1.0 - v14 + (0.89999998 - (1.0 - v14)) * nSlota;
      v17 = fabs(rfscale - 180.0);
      if ( v17 <= 180.0 )
      {
        v18 = v17;
      }
      else
      {
        v135 = v17;
        v18 = 360.0 - v135;
      }
      if ( x < 0.0 )
        v16 = x + 360.0;
      if ( v16 > 180.0 )
        v16 = 360.0 - v16;
      if ( v16 > 90.0 )
        v16 = 90.0 - (float)(v16 - 90.0);
      if ( v16 > 45.0 )
      {
        v19 = (float)((float)(v16 - 45.0) * 0.022222223) + mono;
        if ( v19 >= 0.0 )
        {
          if ( v19 > 1.0 )
            v19 = 1.0;
        }
        else
        {
          v19 = 0.0;
        }
        lfscale = v19;
      }
      v20 = FastPow(a: v18 * 0.0055555557, b: 1.5);
      v9 = 0;
      y = source2d.y;
      v22 = source2d.x;
      source2d.z = 1.0 - v20 + (0.89999998 - (1.0 - v20)) * lfscale;
    }
    else
    {
      v26 = mono;
      v27 = x;
      source2d.x = mono;
      v28 = x;
      v29 = fabs(rfscale - 45.0);
      v30 = 0.0;
      if ( v29 <= 180.0 )
      {
        v31 = v29;
      }
      else
      {
        lfscalec = v29;
        v31 = 360.0 - lfscalec;
      }
      if ( x < 0.0 )
        v28 = x + 360.0;
      if ( v28 > 180.0 )
        v28 = 360.0 - v28;
      if ( v28 > 90.0 )
        v28 = 90.0 - (float)(v28 - 90.0);
      if ( v28 > 45.0 )
      {
        v32 = (float)((float)(v28 - 45.0) * 0.022222223) + mono;
        if ( v32 >= 0.0 )
        {
          if ( v32 > 1.0 )
            v32 = 1.0;
        }
        else
        {
          v32 = 0.0;
        }
        source2d.x = v32;
      }
      if ( v31 < 90.0 )
      {
        v9 = 0;
        v27 = x;
        v26 = mono;
        lfscaled = 1.0 - FastPow(a: v31 * 0.011111111, b: 1.5);
        v30 = lfscaled;
      }
      v33 = fabs(rfscale - 135.0);
      fcscale = (float)((float)(0.89999998 - v30) * source2d.x) + v30;
      source2d.x = v26;
      v34 = v27;
      v35 = 0.0;
      if ( v33 <= 180.0 )
      {
        v36 = v33;
      }
      else
      {
        lfscalee = v33;
        v36 = 360.0 - lfscalee;
      }
      if ( v27 < 0.0 )
        v34 = v27 + 360.0;
      if ( v34 > 180.0 )
        v34 = 360.0 - v34;
      if ( v34 > 90.0 )
        v34 = 90.0 - (float)(v34 - 90.0);
      if ( v34 > 45.0 )
      {
        v37 = (float)((float)(v34 - 45.0) * 0.022222223) + v26;
        if ( v37 >= 0.0 )
        {
          if ( v37 > 1.0 )
            v37 = 1.0;
        }
        else
        {
          v37 = 0.0;
        }
        source2d.x = v37;
      }
      if ( v36 < 90.0 )
      {
        v9 = 0;
        v27 = x;
        v26 = mono;
        lfscalef = 1.0 - FastPow(a: v36 * 0.011111111, b: 1.5);
        v35 = lfscalef;
      }
      v38 = fabs(rfscale - 315.0);
      source2d.z = (float)((float)(0.89999998 - v35) * source2d.x) + v35;
      source2d.x = v26;
      v39 = v27;
      v40 = 0.0;
      if ( v38 <= 180.0 )
      {
        v41 = v38;
      }
      else
      {
        lfscaleg = v38;
        v41 = 360.0 - lfscaleg;
      }
      if ( v27 < 0.0 )
        v39 = v27 + 360.0;
      if ( v39 > 180.0 )
        v39 = 360.0 - v39;
      if ( v39 > 90.0 )
        v39 = 90.0 - (float)(v39 - 90.0);
      if ( v39 > 45.0 )
      {
        v42 = (float)((float)(v39 - 45.0) * 0.022222223) + v26;
        if ( v42 >= 0.0 )
        {
          if ( v42 > 1.0 )
            v42 = 1.0;
        }
        else
        {
          v42 = 0.0;
        }
        source2d.x = v42;
      }
      if ( v41 < 90.0 )
      {
        v9 = 0;
        v27 = x;
        v26 = mono;
        lfscaleh = 1.0 - FastPow(a: v41 * 0.011111111, b: 1.5);
        v40 = lfscaleh;
      }
      v43 = (float)(COERCE_FLOAT(LODWORD(v40) ^ _mask__NegFloat_) * source2d.x) + v40;
      v44 = fabs(rfscale - 225.0);
      source2d.y = v43;
      v132 = v26;
      v45 = 0.0;
      if ( v44 <= 180.0 )
      {
        v46 = v44;
      }
      else
      {
        v136 = v44;
        v46 = 360.0 - v136;
      }
      if ( v27 < 0.0 )
        v27 = v27 + 360.0;
      if ( v27 > 180.0 )
        v27 = 360.0 - v27;
      if ( v27 > 90.0 )
        v27 = 90.0 - (float)(v27 - 90.0);
      if ( v27 > 45.0 )
      {
        v47 = (float)((float)(v27 - 45.0) * 0.022222223) + v26;
        if ( v47 >= 0.0 )
        {
          if ( v47 > 1.0 )
            v47 = 1.0;
          v132 = v47;
        }
        else
        {
          v132 = 0.0;
        }
      }
      if ( v46 < 90.0 )
      {
        v48 = FastPow(a: v46 * 0.011111111, b: 1.5);
        v9 = 0;
        v43 = source2d.y;
        v137 = 1.0 - v48;
        v45 = v137;
      }
      v49 = (float)(v43 * flRearToStereoScale) + fcscale;
      if ( v49 >= 0.0 )
      {
        if ( v49 <= 1.0 )
          fcscale = v49;
        else
          fcscale = 1.0;
      }
      else
      {
        fcscale = 0.0;
      }
      v50 = (float)((float)((float)(COERCE_FLOAT(LODWORD(v45) ^ _mask__NegFloat_) * v132) + v45) * flRearToStereoScale)
          + source2d.z;
      if ( v50 >= 0.0 )
      {
        if ( v50 <= 1.0 )
          source2d.z = (float)((float)((float)(COERCE_FLOAT(LODWORD(v45) ^ _mask__NegFloat_) * v132) + v45)
                             * flRearToStereoScale)
                     + source2d.z;
        else
          source2d.z = 1.0;
      }
      else
      {
        source2d.z = 0.0;
      }
      y = 0.0;
      v22 = 0.0;
    }
    goto SpatialExit_0;
  }
  v51 = x;
  v52 = x;
  v53 = fabs(rfscale - 45.0);
  lfscalea = v53;
  if ( !this->m_bSurroundCenter )
  {
    v54 = mono;
    nSlotb = mono;
    v55 = 0.0;
    if ( v53 <= 180.0 )
      v56 = v53;
    else
      v56 = 360.0 - lfscalea;
    if ( x < 0.0 )
      v52 = x + 360.0;
    if ( v52 > 180.0 )
      v52 = 360.0 - v52;
    if ( v52 > 90.0 )
      v52 = 90.0 - (float)(v52 - 90.0);
    if ( v52 > 45.0 )
    {
      v57 = (float)((float)(v52 - 45.0) * 0.022222223) + mono;
      if ( v57 >= 0.0 )
      {
        if ( v57 > 1.0 )
          v57 = 1.0;
      }
      else
      {
        v57 = 0.0;
      }
      nSlotb = v57;
    }
    if ( v56 < 90.0 )
    {
      v9 = 0;
      v51 = x;
      v54 = mono;
      lfscalei = 1.0 - FastPow(a: v56 * 0.011111111, b: 1.5);
      v55 = lfscalei;
    }
    v58 = fabs(rfscale - 135.0);
    fcscale = (float)((float)(0.89999998 - v55) * nSlotb) + v55;
    *(float *)&nSlotc = v54;
    v59 = v51;
    v60 = 0.0;
    if ( v58 <= 180.0 )
    {
      v61 = v58;
    }
    else
    {
      lfscalej = v58;
      v61 = 360.0 - lfscalej;
    }
    if ( v51 < 0.0 )
      v59 = v51 + 360.0;
    if ( v59 > 180.0 )
      v59 = 360.0 - v59;
    if ( v59 > 90.0 )
      v59 = 90.0 - (float)(v59 - 90.0);
    if ( v59 > 45.0 )
    {
      v62 = (float)((float)(v59 - 45.0) * 0.022222223) + v54;
      if ( v62 >= 0.0 )
      {
        if ( v62 > 1.0 )
          v62 = 1.0;
      }
      else
      {
        v62 = 0.0;
      }
      *(float *)&nSlotc = v62;
    }
    if ( v61 < 90.0 )
    {
      v9 = 0;
      v51 = x;
      v54 = mono;
      lfscalek = 1.0 - FastPow(a: v61 * 0.011111111, b: 1.5);
      v60 = lfscalek;
    }
    v63 = fabs(rfscale - 315.0);
    source2d.z = (float)((float)(0.89999998 - v60) * *(float *)&nSlotc) + v60;
    *(float *)&nSlotd = v54;
    v64 = v51;
    v65 = 0.0;
    if ( v63 <= 180.0 )
    {
      v66 = v63;
    }
    else
    {
      lfscalel = v63;
      v66 = 360.0 - lfscalel;
    }
    if ( v51 < 0.0 )
      v64 = v51 + 360.0;
    if ( v64 > 180.0 )
      v64 = 360.0 - v64;
    if ( v64 > 90.0 )
      v64 = 90.0 - (float)(v64 - 90.0);
    if ( v64 > 45.0 )
    {
      v67 = (float)((float)(v64 - 45.0) * 0.022222223) + v54;
      if ( v67 >= 0.0 )
      {
        if ( v67 > 1.0 )
          v67 = 1.0;
      }
      else
      {
        v67 = 0.0;
      }
      *(float *)&nSlotd = v67;
    }
    if ( v66 < 90.0 )
    {
      v9 = 0;
      v51 = x;
      v54 = mono;
      lfscalem = 1.0 - FastPow(a: v66 * 0.011111111, b: 1.5);
      v65 = lfscalem;
    }
    v68 = fabs(rfscale - 225.0);
    y = (float)((float)(0.89999998 - v65) * *(float *)&nSlotd) + v65;
    source2d.y = y;
    v133 = v54;
    v69 = 0.0;
    if ( v68 <= 180.0 )
    {
      v70 = v68;
    }
    else
    {
      v138 = v68;
      v70 = 360.0 - v138;
    }
    if ( v51 < 0.0 )
      v51 = v51 + 360.0;
    if ( v51 > 180.0 )
      v51 = 360.0 - v51;
    if ( v51 > 90.0 )
      v51 = 90.0 - (float)(v51 - 90.0);
    if ( v51 > 45.0 )
    {
      v71 = (float)((float)(v51 - 45.0) * 0.022222223) + v54;
      if ( v71 >= 0.0 )
      {
        if ( v71 > 1.0 )
          v71 = 1.0;
      }
      else
      {
        v71 = 0.0;
      }
      v133 = v71;
    }
    if ( v70 < 90.0 )
    {
      v72 = FastPow(a: v70 * 0.011111111, b: 1.5);
      v9 = 0;
      y = source2d.y;
      v139 = 1.0 - v72;
      v69 = v139;
    }
    v22 = (float)((float)(0.89999998 - v69) * v133) + v69;
    goto SpatialExit_0;
  }
  v73 = mono;
  nSlote = mono;
  v74 = 0.0;
  if ( v53 <= 180.0 )
    v75 = v53;
  else
    v75 = 360.0 - lfscalea;
  if ( x < 0.0 )
    v52 = x + 360.0;
  if ( v52 > 180.0 )
    v52 = 360.0 - v52;
  if ( v52 > 90.0 )
    v52 = 90.0 - (float)(v52 - 90.0);
  if ( v52 > 45.0 )
  {
    v76 = (float)((float)(v52 - 45.0) * 0.022222223) + mono;
    if ( v76 >= 0.0 )
    {
      if ( v76 > 1.0 )
        v76 = 1.0;
    }
    else
    {
      v76 = 0.0;
    }
    nSlote = v76;
  }
  if ( v75 < 90.0 )
  {
    if ( rfscale <= 45.0 )
    {
      v9 = 0;
      v51 = x;
      v73 = mono;
      lfscaleo = 1.0 - FastPow(a: v75 * 0.011111111, b: 1.5);
      v74 = lfscaleo;
    }
    else if ( v75 <= 75.0 )
    {
      v9 = 0;
      v51 = x;
      v73 = mono;
      lfscalen = 1.0 - FastPow(a: v75 * 0.013333334, b: 1.5);
      v74 = lfscalen;
    }
  }
  v77 = fabs(rfscale - 90.0);
  fcscale = (float)((float)(0.89999998 - v74) * nSlote) + v74;
  *(float *)&nSlotf = v73;
  v78 = v51;
  v79 = 0.0;
  if ( v77 <= 180.0 )
  {
    v80 = v77;
  }
  else
  {
    lfscalep = v77;
    v80 = 360.0 - lfscalep;
  }
  if ( v51 < 0.0 )
    v78 = v51 + 360.0;
  if ( v78 > 180.0 )
    v78 = 360.0 - v78;
  if ( v78 > 90.0 )
    v78 = 90.0 - (float)(v78 - 90.0);
  if ( v78 > 45.0 )
  {
    v81 = (float)((float)(v78 - 45.0) * 0.022222223) + v73;
    if ( v81 >= 0.0 )
    {
      if ( v81 > 1.0 )
        v81 = 1.0;
    }
    else
    {
      v81 = 0.0;
    }
    *(float *)&nSlotf = v81;
  }
  if ( v80 < 90.0 && v80 <= 45.0 )
  {
    v9 = 0;
    v51 = x;
    v73 = mono;
    lfscaleq = 1.0 - FastPow(a: v80 * 0.022222223, b: 1.5);
    v79 = lfscaleq;
  }
  v82 = fabs(rfscale - 135.0);
  v104 = (float)((float)(0.89999998 - v79) * *(float *)&nSlotf) + v79;
  *(float *)&nSlotg = v73;
  v83 = v51;
  v84 = 0.0;
  if ( v82 <= 180.0 )
  {
    v85 = v82;
  }
  else
  {
    lfscaler = v82;
    v85 = 360.0 - lfscaler;
  }
  if ( v51 < 0.0 )
    v83 = v51 + 360.0;
  if ( v83 > 180.0 )
    v83 = 360.0 - v83;
  if ( v83 > 90.0 )
    v83 = 90.0 - (float)(v83 - 90.0);
  if ( v83 > 45.0 )
  {
    v86 = (float)((float)(v83 - 45.0) * 0.022222223) + v73;
    if ( v86 >= 0.0 )
    {
      if ( v86 > 1.0 )
        v86 = 1.0;
    }
    else
    {
      v86 = 0.0;
    }
    *(float *)&nSlotg = v86;
  }
  if ( v85 < 90.0 )
  {
    if ( rfscale >= 135.0 )
    {
      v87 = v85 * 0.011111111;
      goto LABEL_245;
    }
    if ( v85 <= 75.0 )
    {
      v87 = v85 * 0.013333334;
LABEL_245:
      v73 = mono;
      v51 = x;
      v9 = 0;
      lfscales = 1.0 - FastPow(a: v87, b: 1.5);
      v84 = lfscales;
    }
  }
  v88 = fabs(rfscale - 315.0);
  source2d.z = (float)((float)(0.89999998 - v84) * *(float *)&nSlotg) + v84;
  *(float *)&nSloth = v73;
  v89 = v51;
  v90 = 0.0;
  if ( v88 <= 180.0 )
  {
    v91 = v88;
  }
  else
  {
    lfscalet = v88;
    v91 = 360.0 - lfscalet;
  }
  if ( v51 < 0.0 )
    v89 = v51 + 360.0;
  if ( v89 > 180.0 )
    v89 = 360.0 - v89;
  if ( v89 > 90.0 )
    v89 = 90.0 - (float)(v89 - 90.0);
  if ( v89 > 45.0 )
  {
    v92 = (float)((float)(v89 - 45.0) * 0.022222223) + v73;
    if ( v92 >= 0.0 )
    {
      if ( v92 > 1.0 )
        v92 = 1.0;
    }
    else
    {
      v92 = 0.0;
    }
    *(float *)&nSloth = v92;
  }
  if ( v91 < 90.0 )
  {
    v9 = 0;
    v51 = x;
    v73 = mono;
    lfscaleu = 1.0 - FastPow(a: v91 * 0.011111111, b: 1.5);
    v90 = lfscaleu;
  }
  v93 = fabs(rfscale - 225.0);
  y = (float)((float)(0.5 - v90) * *(float *)&nSloth) + v90;
  source2d.y = y;
  v134 = v73;
  v94 = 0.0;
  if ( v93 <= 180.0 )
  {
    v95 = v93;
  }
  else
  {
    v140 = v93;
    v95 = 360.0 - v140;
  }
  if ( v51 < 0.0 )
    v51 = v51 + 360.0;
  if ( v51 > 180.0 )
    v51 = 360.0 - v51;
  if ( v51 > 90.0 )
    v51 = 90.0 - (float)(v51 - 90.0);
  if ( v51 > 45.0 )
  {
    v96 = (float)((float)(v51 - 45.0) * 0.022222223) + v73;
    if ( v96 >= 0.0 )
    {
      if ( v96 > 1.0 )
        v96 = 1.0;
    }
    else
    {
      v96 = 0.0;
    }
    v134 = v96;
  }
  if ( v95 < 90.0 )
  {
    v97 = FastPow(a: v95 * 0.011111111, b: 1.5);
    v9 = 0;
    y = source2d.y;
    v141 = 1.0 - v97;
    v94 = v141;
  }
  v22 = (float)((float)(0.5 - v94) * v134) + v94;
SpatialExit_0:
  v23 = fcscale;
  v24 = fcscale >= 0.0;
  z = source2d.z;
  volume[1] = fcscale;
  *volume = z;
  if ( v24 )
  {
    if ( v23 > 1.0 )
      v23 = 1.0;
  }
  else
  {
    v23 = 0.0;
  }
  volume[1] = v23;
  if ( z >= 0.0 )
  {
    if ( z <= 1.0 )
      v98 = LODWORD(z);
    else
      v98 = 1065353216;
  }
  else
  {
    v98 = 0;
  }
  *(_DWORD *)volume = v98;
  if ( this->m_bSurround )
  {
    volume[3] = y;
    volume[2] = v22;
    if ( y >= 0.0 )
    {
      if ( y > 1.0 )
        y = 1.0;
    }
    else
    {
      y = 0.0;
    }
    volume[3] = y;
    v99 = LODWORD(v22);
    if ( v22 >= 0.0 )
    {
      if ( v22 > 1.0 )
        v99 = 1065353216;
    }
    else
    {
      v99 = 0;
    }
    *((_DWORD *)volume + 2) = v99;
    if ( this->m_bSurroundCenter )
    {
      v100 = v104;
      v24 = v104 >= 0.0;
      volume[4] = v104;
      volume[5] = 0.0;
      if ( v24 )
      {
        if ( v100 > 1.0 )
        {
          volume[4] = 1.0;
          return;
        }
        v9 = LODWORD(v100);
      }
      *((_DWORD *)volume + 4) = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100087E0
// Name: public: virtual bool CAudioDeviceBase::IsHeadphone(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioDeviceBase::IsHeadphone(CAudioDeviceBase *this)
{
  return this->m_bHeadphone;
}

//------------------------------------------------------------------------------
// Address: 0x100087F0
// Name: public: virtual __int64 CAudioDeviceNull::PaintBegin(float,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CAudioDeviceNull::PaintBegin(CAudioDeviceNull *this, float __formal, __int64 __formala, __int64 a4)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008800
// Name: public: virtual void CAudioDeviceNull::Mix16Stereo(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceNull::Mix16Stereo(
        CAudioDeviceNull *this,
        channel_t *pChannel,
        channel_t *pData,
        __int16 *outputOffset,
        int inputOffset,
        int rateScaleFix,
        unsigned int outCount,
        int timecompress)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10008810
// Name: public: virtual char const __near * CAudioDeviceNull::DeviceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioDeviceNull::DeviceName(CAudioDeviceNull *this)
{
  return "Audio Disabled";
}

//------------------------------------------------------------------------------
// Address: 0x10008820
// Name: public: virtual int CAudioDeviceNull::DeviceSampleBits(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceNull::DeviceSampleBits(CAudioDeviceNull *this)
{
  return 16;
}

//------------------------------------------------------------------------------
// Address: 0x10008830
// Name: public: virtual int CAudioDeviceNull::DeviceDmaSpeed(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceNull::DeviceDmaSpeed(CAudioDeviceNull *this)
{
  return 44100;
}

//------------------------------------------------------------------------------
// Address: 0x10008840
// Name: class IAudioDevice __near * Audio_GetNullDevice(void)
// Source: json
//------------------------------------------------------------------------------
CAudioDeviceNull *__cdecl Audio_GetNullDevice()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    nullDevice.__vftable = (CAudioDeviceNull_vtbl *)&CAudioDeviceNull::`vftable';
    atexit(func: Audio_GetNullDevice_::_2_::_dynamic_atexit_destructor_for__nullDevice__);
  }
  return &nullDevice;
}

//------------------------------------------------------------------------------
// Address: 0x102CC600
// Name: public: virtual void CAudioDeviceNull::ChannelReset(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceNull::ChannelReset(
        vgui::TreeView *this,
        int itemIndex,
        bool bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  ;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100058D0
// Name: public: virtual void CAudioDeviceBase::ApplyDSPEffects(int,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::ApplyDSPEffects(
        CAudioDeviceBase *this,
        int idsp,
        portable_samplepair_t *pbuffront,
        portable_samplepair_t *pbufrear,
        portable_samplepair_t *pbufcenter,
        int samplecount)
{
  DEBUG_StartSoundMeasure(type: 1, samplecount);
  DSP_Process(idsp, pbfront: pbuffront, pbrear: pbufrear, pbcenter: pbufcenter, sampleCount: samplecount);
  DEBUG_StopSoundMeasure(type: 1, samplecount);
}

//------------------------------------------------------------------------------
// Address: 0x10005910
// Name: public: virtual void CAudioDeviceBase::MixUpsample(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::MixUpsample(CAudioDeviceBase *this, int sampleCount, int filtertype)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int ifilter; // edi

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  ifilter = CurrentPaintbufferPtr->ifilter;
  S_MixBufferUpsample2x(
    count: sampleCount,
    pbuffer: CurrentPaintbufferPtr->pbuf,
    pfiltermem: CurrentPaintbufferPtr->fltmem[ifilter],
    cfltmem: 3,
    filtertype);
  if ( CurrentPaintbufferPtr->fsurround )
  {
    S_MixBufferUpsample2x(
      count: sampleCount,
      pbuffer: CurrentPaintbufferPtr->pbufrear,
      pfiltermem: CurrentPaintbufferPtr->fltmemrear[ifilter],
      cfltmem: 3,
      filtertype);
    if ( CurrentPaintbufferPtr->fsurround_center )
      S_MixBufferUpsample2x(
        count: sampleCount,
        pbuffer: CurrentPaintbufferPtr->pbufcenter,
        pfiltermem: CurrentPaintbufferPtr->fltmemcenter[ifilter],
        cfltmem: 3,
        filtertype);
  }
  ++CurrentPaintbufferPtr->ifilter;
}

//------------------------------------------------------------------------------
// Address: 0x10005990
// Name: public: virtual void CAudioDeviceBase::Mix8Mono(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix8Mono(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix8MonoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        (unsigned __int8 *)pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix8MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix8MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A60
// Name: public: virtual void CAudioDeviceBase::Mix8Stereo(struct channel_t __near *,char __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix8Stereo(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        char *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix8StereoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        (unsigned __int8 *)pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix8StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix8StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          (unsigned __int8 *)pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005B30
// Name: public: virtual void CAudioDeviceBase::Mix16Mono(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix16Mono(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 1) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix16MonoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix16MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix16MonoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005C00
// Name: public: virtual void CAudioDeviceBase::Mix16Stereo(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::Mix16Stereo(
        CAudioDeviceBase *this,
        channel_t *pChannel,
        __int16 *pData,
        int outputOffset,
        int inputOffset,
        unsigned int rateScaleFix,
        int outCount,
        int timecompress)
{
  paintbuffer_t *CurrentPaintbufferPtr; // esi
  int volume[12]; // [esp+4h] [ebp-30h] BYREF

  CurrentPaintbufferPtr = MIX_GetCurrentPaintbufferPtr();
  if ( MIX_ScaleChannelVolume(ppaint: CurrentPaintbufferPtr, pChannel, volume, mixchans: 2) )
  {
    if ( volume[1] != 0 || volume[0] != 0 )
      Mix16StereoWavtype(
        pChannel,
        pOutput: &CurrentPaintbufferPtr->pbuf[outputOffset],
        volume,
        pData,
        inputOffset,
        rateScaleFix,
        outCount);
    if ( CurrentPaintbufferPtr->fsurround )
    {
      if ( volume[3] != 0 || volume[2] != 0 )
        Mix16StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufrear[outputOffset],
          volume: &volume[2],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
      if ( CurrentPaintbufferPtr->fsurround_center && volume[4] != 0 )
        Mix16StereoWavtype(
          pChannel,
          pOutput: &CurrentPaintbufferPtr->pbufcenter[outputOffset],
          volume: &volume[4],
          pData,
          inputOffset,
          rateScaleFix,
          outCount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005CD0
// Name: float clamp<float,int,int>(float const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,int>(float *val, const int *minVal, const int *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= (float)*maxVal )
    return vala;
  return (float)*maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x10005D20
// Name: XfadeSpeakerVolToMono
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
float __usercall XfadeSpeakerVolToMono@<xmm0>(
        float a1@<xmm0>,
        float scale,
        float xfade,
        float ispeaker,
        bool fmix2channels)
{
  float v5; // xmm0_4
  bool v7; // zf
  float v8; // xmm0_4
  float v9; // xmm0_4
  _BYTE v10[36]; // [esp+0h] [ebp-24h] OVERLAPPED BYREF

  if ( a1 == 4.0 )
  {
    strcpy(&v10[4], "fff?fff?fff?fff?fff?fff?");
    v5 = 0.0;
    v10[29] = 0;
    *(_WORD *)&v10[30] = 0;
    *(_DWORD *)&v10[32] = 0;
    if ( fmix2channels )
    {
      if ( ispeaker >= 0.0 )
      {
        v5 = 3.0;
        if ( ispeaker <= 3.0 )
          v5 = ispeaker;
      }
      return (float)((float)(*(float *)&v10[4 * (int)v5 + 20] - scale) * xfade) + scale;
    }
    else
    {
      if ( ispeaker >= 0.0 )
      {
        v5 = 3.0;
        if ( ispeaker <= 3.0 )
          v5 = ispeaker;
      }
      return (float)((float)(*(float *)&v10[4 * (int)v5 + 4] - scale) * xfade) + scale;
    }
  }
  else
  {
    v7 = a1 == 5.0;
    v8 = 0.89999998;
    if ( v7 )
    {
      strcpy(v10, "fff?fff?");
      v10[9] = 0;
      *(_WORD *)&v10[10] = 16128;
      *(_DWORD *)&v10[12] = 1056964608;
      *(_DWORD *)&v10[16] = 1063675494;
      v9 = ispeaker;
      if ( ispeaker >= 0.0 )
      {
        if ( ispeaker > 4.0 )
          v9 = 4.0;
      }
      else
      {
        v9 = 0.0;
      }
      v8 = *(float *)&v10[4 * (int)v9];
    }
    return (float)((float)(v8 - scale) * xfade) + scale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E50
// Name: GetSpeakerVol
// Source: json
//------------------------------------------------------------------------------
float __usercall GetSpeakerVol@<xmm0>(
        int a1@<edi>,
        int a2@<esi>,
        float a3@<xmm0>,
        float yaw_source,
        float mono,
        float yaw_speaker,
        bool fmix2channels)
{
  int v7; // xmm3_4
  long double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  double v11; // st7
  float a; // xmm1_4
  double v13; // st7
  bool v14; // cc
  float v16; // [esp+0h] [ebp-18h]
  float b; // [esp+Ch] [ebp-Ch]
  float adif; // [esp+14h] [ebp-4h]

  v7 = 0;
  v8 = fabs(yaw_source - yaw_speaker);
  if ( v8 <= 180.0 )
  {
    v9 = v8;
  }
  else
  {
    adif = v8;
    v9 = 360.0 - adif;
  }
  if ( a3 < 0.0 )
    a3 = a3 + 360.0;
  if ( a3 > 180.0 )
    a3 = 360.0 - a3;
  if ( a3 > 90.0 )
    a3 = 90.0 - (float)(a3 - 90.0);
  if ( a3 > 45.0 )
  {
    v10 = (float)((float)(a3 - 45.0) * 0.022222223) + mono;
    if ( v10 < 0.0 || (v7 = 1065353216, v10 > 1.0) )
      v10 = *(float *)&v7;
    mono = v10;
  }
  if ( a1 != 2 )
  {
    if ( v9 >= 90.0 )
      goto LABEL_35;
    if ( a1 == 4 )
    {
      b = 1.5;
      if ( a2 == 99 )
      {
        a = v9 * 0.0074074073;
LABEL_26:
        v11 = FastPow(a, b);
        goto LABEL_27;
      }
LABEL_25:
      a = v9 * 0.011111111;
      goto LABEL_26;
    }
    if ( a2 != 0 )
    {
      if ( a2 != 1 )
      {
        if ( a2 != 4 )
        {
LABEL_24:
          b = 1.5;
          goto LABEL_25;
        }
        if ( v9 <= 45.0 )
        {
          v11 = FastPow(a: v9 * 0.022222223, b: 1.5);
          goto LABEL_27;
        }
LABEL_35:
        v13 = 0.0;
        goto GetVolExit;
      }
      v14 = yaw_speaker <= yaw_source;
    }
    else
    {
      v14 = yaw_source <= yaw_speaker;
    }
    if ( v14 )
      goto LABEL_24;
    if ( v9 <= 75.0 )
    {
      v11 = FastPow(a: v9 * 0.013333334, b: 1.5);
      goto LABEL_27;
    }
    goto LABEL_35;
  }
  v11 = FastPow(a: v9 * 0.0055555557, b: 1.5);
LABEL_27:
  v13 = 1.0 - v11;
GetVolExit:
  v16 = v13;
  return XfadeSpeakerVolToMono((float)a1, scale: v16, xfade: mono, ispeaker: (float)a2, fmix2channels);
}

//------------------------------------------------------------------------------
// Address: 0x10006010
// Name: public: virtual void CAudioDeviceBase::SpatializeChannel(int,int __near * const,int,class Vector const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::SpatializeChannel(
        CAudioDeviceBase *this,
        int nSlot,
        int *volume,
        int master_vol,
        const Vector *sourceDir,
        float gain,
        float mono,
        int nWaveType)
{
  CAudioDeviceBase *v9; // edi
  float v10; // xmm0_4
  int v11; // xmm1_4
  float v12; // xmm0_4
  long double v13; // st7
  float v14; // xmm3_4
  float v15; // xmm0_4
  double v16; // st7
  float v18; // xmm0_4
  long double v19; // st6
  float v20; // xmm2_4
  float v21; // xmm0_4
  double v22; // st7
  float SpeakerVol; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  int v27; // edx
  int v28; // ecx
  int v29; // eax
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  long double v33; // st7
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  long double v37; // st7
  float v38; // xmm0_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  long double v42; // st7
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  long double v47; // st7
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  double v52; // st7
  double v53; // st7
  double v54; // st4
  double v55; // st6
  float v56; // xmm6_4
  float v57; // xmm3_4
  float v58; // xmm0_4
  long double v59; // st7
  float v60; // xmm2_4
  float v61; // xmm4_4
  float v62; // xmm6_4
  float v63; // xmm3_4
  float v64; // xmm0_4
  long double v65; // st7
  float v66; // xmm2_4
  float v67; // xmm4_4
  float v68; // xmm0_4
  long double v69; // st7
  float v70; // xmm0_4
  float v71; // xmm2_4
  float v72; // xmm4_4
  float v73; // xmm0_4
  long double v74; // st7
  float v75; // xmm0_4
  float v76; // xmm5_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  double v79; // st7
  long double v80; // st7
  float v81; // xmm0_4
  float v82; // xmm5_4
  float v83; // xmm0_4
  float v84; // xmm0_4
  long double v85; // st7
  float v86; // xmm0_4
  float v87; // xmm2_4
  float v88; // xmm4_4
  float v89; // xmm0_4
  long double v90; // st7
  float v91; // xmm0_4
  float v92; // xmm5_4
  float v93; // xmm2_4
  float v94; // xmm0_4
  double v95; // st7
  long double v96; // st7
  float v97; // xmm0_4
  float v98; // xmm5_4
  float v99; // xmm0_4
  double v100; // st7
  float v101; // xmm6_4
  float v102; // xmm0_4
  float v103; // xmm2_4
  long double v104; // st7
  float v105; // xmm4_4
  float v106; // xmm3_4
  float v107; // xmm2_4
  double v108; // st7
  float a; // xmm3_4
  long double v110; // st6
  float v111; // xmm2_4
  float v112; // xmm4_4
  float v113; // xmm5_4
  float v114; // xmm2_4
  long double v115; // st6
  float v116; // xmm2_4
  float v117; // xmm5_4
  float v118; // xmm4_4
  float v119; // xmm2_4
  int v120; // eax
  int v121; // ecx
  int v122; // eax
  int v123; // eax
  float b; // [esp+Ch] [ebp-4Ch]
  float ba; // [esp+Ch] [ebp-4Ch]
  float bb; // [esp+Ch] [ebp-4Ch]
  QAngle angles2d; // [esp+1Ch] [ebp-3Ch] BYREF
  QAngle angles; // [esp+28h] [ebp-30h] BYREF
  Vector source2d; // [esp+34h] [ebp-24h] BYREF
  CAudioDeviceBase *v130; // [esp+40h] [ebp-18h]
  float fcscale; // [esp+44h] [ebp-14h]
  float lrscale; // [esp+48h] [ebp-10h]
  float rfscale; // [esp+4Ch] [ebp-Ch]
  float rrscale; // [esp+50h] [ebp-8h]
  float lfscale; // [esp+54h] [ebp-4h]
  float nSlotb; // [esp+60h] [ebp+8h]
  float nSlota; // [esp+60h] [ebp+8h]
  float nSlotc; // [esp+60h] [ebp+8h]
  float nSlotd; // [esp+60h] [ebp+8h]
  float nSlote; // [esp+60h] [ebp+8h]
  float nSlotf; // [esp+60h] [ebp+8h]
  float nSlotg; // [esp+60h] [ebp+8h]
  float nSloth; // [esp+60h] [ebp+8h]
  float nSloti; // [esp+60h] [ebp+8h]
  float nSlotj; // [esp+60h] [ebp+8h]
  float nSlotk; // [esp+60h] [ebp+8h]
  float nSlotl; // [esp+60h] [ebp+8h]
  float nSlotm; // [esp+60h] [ebp+8h]
  float nSlotn; // [esp+60h] [ebp+8h]
  float nSloto; // [esp+60h] [ebp+8h]
  float nSlotp; // [esp+60h] [ebp+8h]
  float nSlotq; // [esp+60h] [ebp+8h]
  float nSlotr; // [esp+60h] [ebp+8h]
  float nSlots; // [esp+60h] [ebp+8h]
  float nSlott; // [esp+60h] [ebp+8h]
  float nSlotu; // [esp+60h] [ebp+8h]
  float nSlotv; // [esp+60h] [ebp+8h]
  float nSlotw; // [esp+60h] [ebp+8h]
  float nSlotx; // [esp+60h] [ebp+8h]
  float nSloty; // [esp+60h] [ebp+8h]
  float nSlotz; // [esp+60h] [ebp+8h]
  float nSlotba; // [esp+60h] [ebp+8h]
  float yawb; // [esp+64h] [ebp+Ch]
  float yaw; // [esp+64h] [ebp+Ch]
  float yawa; // [esp+64h] [ebp+Ch]
  float yawc; // [esp+64h] [ebp+Ch]
  float pitch; // [esp+6Ch] [ebp+14h]
  float pitcha; // [esp+6Ch] [ebp+14h]
  float pitchb; // [esp+6Ch] [ebp+14h]
  float monoa; // [esp+74h] [ebp+1Ch]
  float monob; // [esp+74h] [ebp+1Ch]
  float monoc; // [esp+74h] [ebp+1Ch]
  float monod; // [esp+74h] [ebp+1Ch]
  float monoe; // [esp+74h] [ebp+1Ch]
  float nWaveTypea; // [esp+78h] [ebp+20h]
  float nWaveTypeb; // [esp+78h] [ebp+20h]
  int nWaveTypec; // [esp+78h] [ebp+20h]
  int nWaveTyped; // [esp+78h] [ebp+20h]
  float nWaveTypee; // [esp+78h] [ebp+20h]
  float nWaveTypef; // [esp+78h] [ebp+20h]
  int nWaveTypeg; // [esp+78h] [ebp+20h]
  int nWaveTypeh; // [esp+78h] [ebp+20h]
  int nWaveTypei; // [esp+78h] [ebp+20h]
  int nWaveTypej; // [esp+78h] [ebp+20h]
  float nWaveTypek; // [esp+78h] [ebp+20h]
  int nWaveTypel; // [esp+78h] [ebp+20h]
  int nWaveTypem; // [esp+78h] [ebp+20h]

  v9 = this;
  v130 = this;
  lrscale = 0.0;
  rrscale = 0.0;
  lfscale = 0.0;
  rfscale = 0.0;
  fcscale = 0.0;
  *volume = 0;
  volume[1] = 0;
  volume[2] = 0;
  volume[3] = 0;
  volume[4] = 0;
  volume[5] = 0;
  VectorAngles(forward: sourceDir, &angles);
  pitch = angles.x;
  yawb = angles.y;
  source2d.x = listener_right[nSlot].x;
  LODWORD(source2d.y) = dword_1043930C[3 * nSlot];
  source2d.z = 0.0;
  VectorNormalize(vec: &source2d);
  VectorAngles(forward: &source2d, angles: &angles2d);
  v10 = yawb - angles2d.y;
  v11 = 0;
  yaw = yawb - angles2d.y;
  if ( yaw < 0.0 )
    yaw = v10 + 360.0;
  if ( !v9->m_bSurround )
  {
    if ( !v9->m_bHeadphone )
    {
      v30 = mono;
      v31 = pitch;
      nWaveTypeb = mono;
      v32 = pitch;
      v33 = fabs(yaw - 45.0);
      v34 = 0.0;
      if ( v33 <= 180.0 )
      {
        v35 = v33;
      }
      else
      {
        nSlotc = v33;
        v35 = 360.0 - nSlotc;
      }
      if ( pitch < 0.0 )
        v32 = pitch + 360.0;
      if ( v32 > 180.0 )
        v32 = 360.0 - v32;
      if ( v32 > 90.0 )
        v32 = 90.0 - (float)(v32 - 90.0);
      if ( v32 > 45.0 )
      {
        v36 = (float)((float)(v32 - 45.0) * 0.022222223) + mono;
        if ( v36 >= 0.0 )
        {
          if ( v36 > 1.0 )
            v36 = 1.0;
        }
        else
        {
          v36 = 0.0;
        }
        nWaveTypeb = v36;
      }
      if ( v35 < 90.0 )
      {
        v31 = pitch;
        v30 = mono;
        nSlotd = 1.0 - FastPow(a: v35 * 0.011111111, b: 1.5);
        v34 = nSlotd;
      }
      v37 = fabs(yaw - 135.0);
      rfscale = (float)((float)(0.89999998 - v34) * nWaveTypeb) + v34;
      *(float *)&nWaveTypec = v30;
      v38 = v31;
      v39 = 0.0;
      if ( v37 <= 180.0 )
      {
        v40 = v37;
      }
      else
      {
        nSlote = v37;
        v40 = 360.0 - nSlote;
      }
      if ( v31 < 0.0 )
        v38 = v31 + 360.0;
      if ( v38 > 180.0 )
        v38 = 360.0 - v38;
      if ( v38 > 90.0 )
        v38 = 90.0 - (float)(v38 - 90.0);
      if ( v38 > 45.0 )
      {
        v41 = (float)((float)(v38 - 45.0) * 0.022222223) + v30;
        if ( v41 >= 0.0 )
        {
          if ( v41 > 1.0 )
            v41 = 1.0;
        }
        else
        {
          v41 = 0.0;
        }
        *(float *)&nWaveTypec = v41;
      }
      if ( v40 < 90.0 )
      {
        v31 = pitch;
        v30 = mono;
        nSlotf = 1.0 - FastPow(a: v40 * 0.011111111, b: 1.5);
        v39 = nSlotf;
      }
      v42 = fabs(yaw - 315.0);
      lfscale = (float)((float)(0.89999998 - v39) * *(float *)&nWaveTypec) + v39;
      *(float *)&nWaveTyped = v30;
      v43 = v31;
      v44 = 0.0;
      if ( v42 <= 180.0 )
      {
        v45 = v42;
      }
      else
      {
        nSlotg = v42;
        v45 = 360.0 - nSlotg;
      }
      if ( v31 < 0.0 )
        v43 = v31 + 360.0;
      if ( v43 > 180.0 )
        v43 = 360.0 - v43;
      if ( v43 > 90.0 )
        v43 = 90.0 - (float)(v43 - 90.0);
      if ( v43 > 45.0 )
      {
        v46 = (float)((float)(v43 - 45.0) * 0.022222223) + v30;
        if ( v46 >= 0.0 )
        {
          if ( v46 > 1.0 )
            v46 = 1.0;
        }
        else
        {
          v46 = 0.0;
        }
        *(float *)&nWaveTyped = v46;
      }
      if ( v45 < 90.0 )
      {
        v31 = pitch;
        v30 = mono;
        nSloth = 1.0 - FastPow(a: v45 * 0.011111111, b: 1.5);
        v44 = nSloth;
      }
      v47 = fabs(yaw - 225.0);
      rrscale = (float)(COERCE_FLOAT(LODWORD(v44) ^ _mask__NegFloat_) * *(float *)&nWaveTyped) + v44;
      pitcha = v30;
      v48 = v31;
      v49 = 0.0;
      if ( v47 <= 180.0 )
      {
        v50 = v47;
      }
      else
      {
        monob = v47;
        v50 = 360.0 - monob;
      }
      if ( v31 < 0.0 )
        v48 = v31 + 360.0;
      if ( v48 > 180.0 )
        v48 = 360.0 - v48;
      if ( v48 > 90.0 )
        v48 = 90.0 - (float)(v48 - 90.0);
      if ( v48 > 45.0 )
      {
        v51 = (float)((float)(v48 - 45.0) * 0.022222223) + v30;
        if ( v51 >= 0.0 )
        {
          if ( v51 > 1.0 )
            v51 = 1.0;
        }
        else
        {
          v51 = 0.0;
        }
        pitcha = v51;
      }
      if ( v50 < 90.0 )
      {
        monoc = 1.0 - FastPow(a: v50 * 0.011111111, b: 1.5);
        v49 = monoc;
      }
      v52 = rrscale * 0.75 + rfscale;
      lrscale = (float)((float)-v49 * pitcha) + v49;
      if ( v52 >= 0.0 )
      {
        v54 = v52;
        v53 = 1.0;
        if ( v54 > 1.0 )
          v54 = 1.0;
      }
      else
      {
        v53 = 1.0;
        v54 = 0.0;
      }
      rfscale = v54;
      v55 = 0.75 * lrscale + lfscale;
      if ( v55 >= 0.0 )
      {
        if ( v55 > v53 )
        {
          v24 = 0.0;
          lfscale = v53;
          SpeakerVol = 0.0;
          goto LABEL_37;
        }
      }
      else
      {
        v55 = 0.0;
      }
      v24 = 0.0;
      lfscale = v55;
      SpeakerVol = 0.0;
LABEL_37:
      v25 = lfscale;
      goto SpatialExit;
    }
    v12 = pitch;
    v13 = fabs(yaw);
    nWaveTypea = mono;
    if ( v13 <= 180.0 )
    {
      v14 = v13;
    }
    else
    {
      nSlotb = v13;
      v14 = 360.0 - nSlotb;
    }
    if ( pitch < 0.0 )
      v12 = pitch + 360.0;
    if ( v12 > 180.0 )
      v12 = 360.0 - v12;
    if ( v12 > 90.0 )
      v12 = 90.0 - (float)(v12 - 90.0);
    if ( v12 > 45.0 )
    {
      v15 = (float)((float)(v12 - 45.0) * 0.022222223) + mono;
      if ( v15 >= 0.0 )
      {
        if ( v15 > 1.0 )
          v15 = 1.0;
      }
      else
      {
        v15 = 0.0;
      }
      nWaveTypea = v15;
    }
    v16 = FastPow(a: v14 * 0.0055555557, b: 1.5);
    v18 = pitch;
    nSlota = mono;
    rfscale = 1.0 - v16 + (0.89999998 - (1.0 - v16)) * nWaveTypea;
    v19 = fabs(yaw - 180.0);
    if ( v19 <= 180.0 )
    {
      v20 = v19;
    }
    else
    {
      monoa = v19;
      v20 = 360.0 - monoa;
    }
    if ( pitch < 0.0 )
      v18 = pitch + 360.0;
    if ( v18 > 180.0 )
      v18 = 360.0 - v18;
    if ( v18 > 90.0 )
      v18 = 90.0 - (float)(v18 - 90.0);
    if ( v18 > 45.0 )
    {
      v21 = (float)((float)(v18 - 45.0) * 0.022222223) + mono;
      if ( v21 >= 0.0 )
      {
        if ( v21 > 1.0 )
          v21 = 1.0;
      }
      else
      {
        v21 = 0.0;
      }
      nSlota = v21;
    }
    v22 = FastPow(a: v20 * 0.0055555557, b: 1.5);
    SpeakerVol = lrscale;
    lfscale = 1.0 - v22 + (0.89999998 - (1.0 - v22)) * nSlota;
LABEL_36:
    v24 = rrscale;
    goto LABEL_37;
  }
  if ( nWaveType != 40 )
  {
    if ( !v9->m_bSurroundCenter )
    {
      v56 = mono;
      v57 = pitch;
      nWaveTypee = mono;
      v58 = pitch;
      v59 = fabs(yaw - 45.0);
      v60 = 0.0;
      if ( v59 <= 180.0 )
      {
        v61 = v59;
      }
      else
      {
        nSloti = v59;
        v61 = 360.0 - nSloti;
      }
      if ( pitch < 0.0 )
        v58 = pitch + 360.0;
      if ( v58 > 180.0 )
        v58 = 360.0 - v58;
      if ( v58 > 90.0 )
        v58 = 90.0 - (float)(v58 - 90.0);
      if ( v58 > 45.0 )
      {
        v84 = (float)((float)(v58 - 45.0) * 0.022222223) + mono;
        if ( v84 >= 0.0 )
        {
          if ( v84 > 1.0 )
            v84 = 1.0;
        }
        else
        {
          v84 = 0.0;
        }
        nWaveTypee = v84;
      }
      if ( v61 < 90.0 )
      {
        v11 = 0;
        v57 = pitch;
        v56 = mono;
        nSlotp = 1.0 - FastPow(a: v61 * 0.011111111, b: 1.5);
        v60 = nSlotp;
      }
      v85 = fabs(yaw - 135.0);
      rfscale = (float)((float)(0.89999998 - v60) * nWaveTypee) + v60;
      *(float *)&nWaveTypei = v56;
      v86 = v57;
      v87 = 0.0;
      if ( v85 <= 180.0 )
      {
        v88 = v85;
      }
      else
      {
        nSlotq = v85;
        v88 = 360.0 - nSlotq;
      }
      if ( v57 < 0.0 )
        v86 = v57 + 360.0;
      if ( v86 > 180.0 )
        v86 = 360.0 - v86;
      if ( v86 > 90.0 )
        v86 = 90.0 - (float)(v86 - 90.0);
      if ( v86 > 45.0 )
      {
        v89 = (float)((float)(v86 - 45.0) * 0.022222223) + v56;
        if ( v89 >= 0.0 )
        {
          if ( v89 > 1.0 )
            v89 = 1.0;
        }
        else
        {
          v89 = 0.0;
        }
        *(float *)&nWaveTypei = v89;
      }
      if ( v88 < 90.0 )
      {
        v11 = 0;
        v57 = pitch;
        v56 = mono;
        nSlotr = 1.0 - FastPow(a: v88 * 0.011111111, b: 1.5);
        v87 = nSlotr;
      }
      v25 = (float)((float)(0.89999998 - v87) * *(float *)&nWaveTypei) + v87;
      v90 = fabs(yaw - 315.0);
      lfscale = v25;
      *(float *)&nWaveTypej = v56;
      v91 = v57;
      v92 = 0.0;
      if ( v90 <= 180.0 )
      {
        v93 = v90;
      }
      else
      {
        nSlots = v90;
        v93 = 360.0 - nSlots;
      }
      if ( v57 < 0.0 )
        v91 = v57 + 360.0;
      if ( v91 > 180.0 )
        v91 = 360.0 - v91;
      if ( v91 > 90.0 )
        v91 = 90.0 - (float)(v91 - 90.0);
      if ( v91 > 45.0 )
      {
        v94 = (float)((float)(v91 - 45.0) * 0.022222223) + v56;
        if ( v94 >= 0.0 )
        {
          if ( v94 > 1.0 )
            v94 = 1.0;
        }
        else
        {
          v94 = 0.0;
        }
        *(float *)&nWaveTypej = v94;
      }
      if ( v93 < 90.0 )
      {
        v95 = FastPow(a: v93 * 0.011111111, b: 1.5);
        v11 = 0;
        v25 = lfscale;
        v57 = pitch;
        v56 = mono;
        nSlott = 1.0 - v95;
        v92 = nSlott;
      }
      v96 = fabs(yaw - 225.0);
      v24 = (float)((float)(0.89999998 - v92) * *(float *)&nWaveTypej) + v92;
      rrscale = v24;
      pitchb = v56;
      v97 = v57;
      yawa = 0.0;
      if ( v96 <= 180.0 )
      {
        v98 = v96;
      }
      else
      {
        monoe = v96;
        v98 = 360.0 - monoe;
      }
      if ( v57 < 0.0 )
        v97 = v57 + 360.0;
      if ( v97 > 180.0 )
        v97 = 360.0 - v97;
      if ( v97 > 90.0 )
        v97 = 90.0 - (float)(v97 - 90.0);
      if ( v97 > 45.0 )
      {
        v99 = (float)((float)(v97 - 45.0) * 0.022222223) + v56;
        if ( v99 < 0.0 || (v11 = 1065353216, v99 > 1.0) )
          v99 = *(float *)&v11;
        pitchb = v99;
      }
      if ( v98 < 90.0 )
      {
        v100 = FastPow(a: v98 * 0.011111111, b: 1.5);
        v24 = rrscale;
        v25 = lfscale;
        yawa = 1.0 - v100;
      }
      goto LABEL_253;
    }
    v101 = mono;
    v102 = pitch;
    nWaveTypek = mono;
    v103 = pitch;
    v104 = fabs(yaw - 45.0);
    v105 = 0.0;
    if ( v104 <= 180.0 )
    {
      v106 = v104;
    }
    else
    {
      nSlotu = v104;
      v106 = 360.0 - nSlotu;
    }
    if ( pitch < 0.0 )
      v103 = pitch + 360.0;
    if ( v103 > 180.0 )
      v103 = 360.0 - v103;
    if ( v103 > 90.0 )
      v103 = 90.0 - (float)(v103 - 90.0);
    if ( v103 > 45.0 )
    {
      v107 = (float)((float)(v103 - 45.0) * 0.022222223) + mono;
      if ( v107 >= 0.0 )
      {
        if ( v107 > 1.0 )
          v107 = 1.0;
      }
      else
      {
        v107 = 0.0;
      }
      nWaveTypek = v107;
    }
    v108 = 1.5;
    if ( v106 < 90.0 )
    {
      if ( yaw <= 45.0 )
      {
        a = v106 * 0.011111111;
        goto LABEL_274;
      }
      if ( v106 <= 75.0 )
      {
        a = v106 * 0.013333334;
LABEL_274:
        v101 = mono;
        v102 = pitch;
        v11 = 0;
        nSlotv = 1.0 - FastPow(a, b: 1.5);
        v108 = 1.5;
        v105 = nSlotv;
      }
    }
    v110 = fabs(yaw - 90.0);
    rfscale = (float)((float)(0.89999998 - v105) * nWaveTypek) + v105;
    *(float *)&nWaveTypel = v101;
    v111 = v102;
    v112 = 0.0;
    if ( v110 <= 180.0 )
    {
      v113 = v110;
    }
    else
    {
      nSlotw = v110;
      v113 = 360.0 - nSlotw;
    }
    if ( v102 < 0.0 )
      v111 = v102 + 360.0;
    if ( v111 > 180.0 )
      v111 = 360.0 - v111;
    if ( v111 > 90.0 )
      v111 = 90.0 - (float)(v111 - 90.0);
    if ( v111 > 45.0 )
    {
      v114 = (float)((float)(v111 - 45.0) * 0.022222223) + v101;
      if ( v114 >= 0.0 )
      {
        if ( v114 > 1.0 )
          v114 = 1.0;
      }
      else
      {
        v114 = 0.0;
      }
      *(float *)&nWaveTypel = v114;
    }
    if ( v113 < 90.0 && v113 <= 45.0 )
    {
      b = v108;
      v11 = 0;
      v102 = pitch;
      v101 = mono;
      nSlotx = 1.0 - FastPow(a: v113 * 0.022222223, b);
      v112 = nSlotx;
      v108 = 1.5;
    }
    v115 = fabs(yaw - 135.0);
    fcscale = (float)((float)(0.89999998 - v112) * *(float *)&nWaveTypel) + v112;
    *(float *)&nWaveTypem = v101;
    v116 = v102;
    v117 = 0.0;
    if ( v115 <= 180.0 )
    {
      v118 = v115;
    }
    else
    {
      nSloty = v115;
      v118 = 360.0 - nSloty;
    }
    if ( v102 < 0.0 )
      v116 = v102 + 360.0;
    if ( v116 > 180.0 )
      v116 = 360.0 - v116;
    if ( v116 > 90.0 )
      v116 = 90.0 - (float)(v116 - 90.0);
    if ( v116 > 45.0 )
    {
      v119 = (float)((float)(v116 - 45.0) * 0.022222223) + v101;
      if ( v119 >= 0.0 )
      {
        v11 = 1065353216;
        if ( v119 <= 1.0 )
          v11 = LODWORD(v119);
      }
      nWaveTypem = v11;
    }
    if ( v118 < 90.0 )
    {
      if ( yaw >= 135.0 )
      {
        bb = v108;
        v102 = pitch;
        nSlotba = 1.0 - FastPow(a: v118 * 0.011111111, b: bb);
        v117 = nSlotba;
      }
      else if ( v118 <= 75.0 )
      {
        ba = v108;
        v102 = pitch;
        nSlotz = 1.0 - FastPow(a: v118 * 0.013333334, b: ba);
        v117 = nSlotz;
      }
    }
    lfscale = (float)((float)(0.89999998 - v117) * *(float *)&nWaveTypem) + v117;
    rrscale = GetSpeakerVol(a1: 5, a2: 2, a3: v102, yaw_source: yaw, mono, yaw_speaker: 315.0, fmix2channels: false);
    SpeakerVol = GetSpeakerVol(a1: 5, a2: 3, a3: pitch, yaw_source: yaw, mono, yaw_speaker: 225.0, fmix2channels: false);
    v9 = v130;
    goto LABEL_36;
  }
  v62 = mono;
  v63 = pitch;
  nWaveTypef = mono;
  v64 = pitch;
  v65 = fabs(yaw - 45.0);
  v66 = 0.0;
  if ( v65 <= 180.0 )
  {
    v67 = v65;
  }
  else
  {
    nSlotj = v65;
    v67 = 360.0 - nSlotj;
  }
  if ( pitch < 0.0 )
    v64 = pitch + 360.0;
  if ( v64 > 180.0 )
    v64 = 360.0 - v64;
  if ( v64 > 90.0 )
    v64 = 90.0 - (float)(v64 - 90.0);
  if ( v64 > 45.0 )
  {
    v68 = (float)((float)(v64 - 45.0) * 0.022222223) + mono;
    if ( v68 >= 0.0 )
    {
      if ( v68 > 1.0 )
        v68 = 1.0;
    }
    else
    {
      v68 = 0.0;
    }
    nWaveTypef = v68;
  }
  if ( v67 < 90.0 )
  {
    v11 = 0;
    v63 = pitch;
    v62 = mono;
    nSlotk = 1.0 - FastPow(a: v67 * 0.0074074073, b: 1.5);
    v66 = nSlotk;
  }
  v69 = fabs(yaw - 135.0);
  rfscale = (float)((float)(0.89999998 - v66) * nWaveTypef) + v66;
  *(float *)&nWaveTypeg = v62;
  v70 = v63;
  v71 = 0.0;
  if ( v69 <= 180.0 )
  {
    v72 = v69;
  }
  else
  {
    nSlotl = v69;
    v72 = 360.0 - nSlotl;
  }
  if ( v63 < 0.0 )
    v70 = v63 + 360.0;
  if ( v70 > 180.0 )
    v70 = 360.0 - v70;
  if ( v70 > 90.0 )
    v70 = 90.0 - (float)(v70 - 90.0);
  if ( v70 > 45.0 )
  {
    v73 = (float)((float)(v70 - 45.0) * 0.022222223) + v62;
    if ( v73 >= 0.0 )
    {
      if ( v73 > 1.0 )
        v73 = 1.0;
    }
    else
    {
      v73 = 0.0;
    }
    *(float *)&nWaveTypeg = v73;
  }
  if ( v72 < 90.0 )
  {
    v11 = 0;
    v63 = pitch;
    v62 = mono;
    nSlotm = 1.0 - FastPow(a: v72 * 0.0074074073, b: 1.5);
    v71 = nSlotm;
  }
  v25 = (float)((float)(0.89999998 - v71) * *(float *)&nWaveTypeg) + v71;
  v74 = fabs(yaw - 315.0);
  lfscale = v25;
  *(float *)&nWaveTypeh = v62;
  v75 = v63;
  v76 = 0.0;
  if ( v74 <= 180.0 )
  {
    v77 = v74;
  }
  else
  {
    nSlotn = v74;
    v77 = 360.0 - nSlotn;
  }
  if ( v63 < 0.0 )
    v75 = v63 + 360.0;
  if ( v75 > 180.0 )
    v75 = 360.0 - v75;
  if ( v75 > 90.0 )
    v75 = 90.0 - (float)(v75 - 90.0);
  if ( v75 > 45.0 )
  {
    v78 = (float)((float)(v75 - 45.0) * 0.022222223) + v62;
    if ( v78 >= 0.0 )
    {
      if ( v78 > 1.0 )
        v78 = 1.0;
    }
    else
    {
      v78 = 0.0;
    }
    *(float *)&nWaveTypeh = v78;
  }
  if ( v77 < 90.0 )
  {
    v79 = FastPow(a: v77 * 0.0074074073, b: 1.5);
    v11 = 0;
    v25 = lfscale;
    v63 = pitch;
    v62 = mono;
    nSloto = 1.0 - v79;
    v76 = nSloto;
  }
  v80 = fabs(yaw - 225.0);
  v24 = (float)((float)(0.89999998 - v76) * *(float *)&nWaveTypeh) + v76;
  rrscale = v24;
  pitchb = v62;
  v81 = v63;
  yawa = 0.0;
  if ( v80 <= 180.0 )
  {
    v82 = v80;
  }
  else
  {
    monod = v80;
    v82 = 360.0 - monod;
  }
  if ( v63 < 0.0 )
    v81 = v63 + 360.0;
  if ( v81 > 180.0 )
    v81 = 360.0 - v81;
  if ( v81 > 90.0 )
    v81 = 90.0 - (float)(v81 - 90.0);
  if ( v81 > 45.0 )
  {
    v83 = (float)((float)(v81 - 45.0) * 0.022222223) + v62;
    if ( v83 < 0.0 || (v11 = 1065353216, v83 > 1.0) )
      v83 = *(float *)&v11;
    pitchb = v83;
  }
  if ( v82 < 90.0 )
  {
    yawc = 1.0 - FastPow(a: v82 * 0.0074074073, b: 1.5);
    SpeakerVol = yawc + (float)((float)(0.89999998 - yawc) * pitchb);
    goto LABEL_36;
  }
LABEL_253:
  SpeakerVol = yawa + (float)((float)(0.89999998 - yawa) * pitchb);
SpatialExit:
  v26 = (float)master_vol * gain;
  v27 = (int)(float)(v26 * rfscale);
  v28 = v27;
  v29 = (int)(float)(v26 * v25);
  volume[1] = v27;
  *volume = v29;
  if ( v27 >= 0 )
  {
    if ( v27 > 255 )
      v28 = 255;
  }
  else
  {
    v28 = 0;
  }
  volume[1] = v28;
  if ( v29 >= 0 )
  {
    if ( v29 > 255 )
      v29 = 255;
  }
  else
  {
    v29 = 0;
  }
  *volume = v29;
  if ( v9->m_bSurround )
  {
    v120 = (int)(float)(v26 * v24);
    v121 = (int)(float)(v26 * SpeakerVol);
    volume[3] = v120;
    volume[2] = v121;
    if ( v120 >= 0 )
    {
      if ( v120 > 255 )
        v120 = 255;
    }
    else
    {
      v120 = 0;
    }
    volume[3] = v120;
    v122 = (int)(float)(v26 * SpeakerVol);
    if ( v121 >= 0 )
    {
      if ( v121 > 255 )
        v122 = 255;
    }
    else
    {
      v122 = 0;
    }
    volume[2] = v122;
    if ( v9->m_bSurroundCenter )
    {
      v123 = (int)(float)(v26 * fcscale);
      volume[4] = v123;
      volume[5] = 0;
      if ( v123 >= 0 )
      {
        if ( v123 > 255 )
          v123 = 255;
        volume[4] = v123;
      }
      else
      {
        volume[4] = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007540
// Name: public: virtual void CAudioDeviceBase::SpatializeChannel(int,float __near * const,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceBase::SpatializeChannel(
        CAudioDeviceBase *this,
        int nSlot,
        float *volume,
        const Vector *sourceDir,
        float mono,
        float flRearToStereoScale)
{
  float v8; // xmm1_4
  int v9; // xmm0_4
  float v10; // xmm1_4
  long double v11; // st7
  float v12; // xmm3_4
  float v13; // xmm1_4
  double v14; // st7
  float v16; // xmm0_4
  long double v17; // st6
  float v18; // xmm2_4
  float v19; // xmm0_4
  double v20; // st7
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  bool v24; // cc
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  long double v29; // st7
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  long double v33; // st7
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm1_4
  long double v38; // st7
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm1_4
  float v43; // xmm1_4
  long double v44; // st7
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  double v48; // st7
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  long double v53; // st7
  float v54; // xmm5_4
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm1_4
  long double v58; // st7
  float v59; // xmm1_4
  float v60; // xmm4_4
  float v61; // xmm3_4
  float v62; // xmm1_4
  long double v63; // st7
  float v64; // xmm1_4
  float v65; // xmm4_4
  float v66; // xmm6_4
  float v67; // xmm1_4
  long double v68; // st7
  float v69; // xmm3_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  double v72; // st7
  float v73; // xmm6_4
  float v74; // xmm4_4
  float v75; // xmm3_4
  float v76; // xmm1_4
  long double v77; // st7
  float v78; // xmm1_4
  float v79; // xmm4_4
  float v80; // xmm5_4
  float v81; // xmm1_4
  long double v82; // st7
  float v83; // xmm1_4
  float v84; // xmm5_4
  float v85; // xmm4_4
  float v86; // xmm1_4
  float a; // xmm4_4
  long double v88; // st7
  float v89; // xmm1_4
  float v90; // xmm5_4
  float v91; // xmm4_4
  float v92; // xmm1_4
  long double v93; // st7
  float v94; // xmm3_4
  float v95; // xmm5_4
  float v96; // xmm2_4
  double v97; // st7
  int v98; // xmm2_4
  int v99; // xmm1_4
  float v100; // xmm1_4
  QAngle angles2d; // [esp+10h] [ebp-38h] BYREF
  QAngle angles; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector source2d; // [esp+28h] [ebp-20h] BYREF
  float fcscale; // [esp+34h] [ebp-14h]
  float lrscale; // [esp+38h] [ebp-10h]
  float rrscale; // [esp+3Ch] [ebp-Ch]
  float lfscale; // [esp+40h] [ebp-8h]
  float rfscale; // [esp+44h] [ebp-4h]
  float nSlotc; // [esp+50h] [ebp+8h]
  float nSlota; // [esp+50h] [ebp+8h]
  float nSlotd; // [esp+50h] [ebp+8h]
  float nSlote; // [esp+50h] [ebp+8h]
  float nSlotf; // [esp+50h] [ebp+8h]
  float nSlotg; // [esp+50h] [ebp+8h]
  float nSloth; // [esp+50h] [ebp+8h]
  float nSloti; // [esp+50h] [ebp+8h]
  int nSlotb; // [esp+50h] [ebp+8h]
  float nSlotj; // [esp+50h] [ebp+8h]
  float nSlotk; // [esp+50h] [ebp+8h]
  float nSlotl; // [esp+50h] [ebp+8h]
  float nSlotm; // [esp+50h] [ebp+8h]
  float nSlotn; // [esp+50h] [ebp+8h]
  float nSloto; // [esp+50h] [ebp+8h]
  float nSlotp; // [esp+50h] [ebp+8h]
  float nSlotq; // [esp+50h] [ebp+8h]
  float nSlotr; // [esp+50h] [ebp+8h]
  float nSlots; // [esp+50h] [ebp+8h]
  float nSlott; // [esp+50h] [ebp+8h]
  float nSlotu; // [esp+50h] [ebp+8h]
  float nSlotv; // [esp+50h] [ebp+8h]
  float yawa; // [esp+54h] [ebp+Ch]
  float yaw; // [esp+54h] [ebp+Ch]
  float pitch; // [esp+58h] [ebp+10h]
  float pitcha; // [esp+58h] [ebp+10h]
  float pitchb; // [esp+58h] [ebp+10h]
  float pitchc; // [esp+58h] [ebp+10h]
  float monoa; // [esp+5Ch] [ebp+14h]
  float monob; // [esp+5Ch] [ebp+14h]
  float monoc; // [esp+5Ch] [ebp+14h]
  float monod; // [esp+5Ch] [ebp+14h]
  float monoe; // [esp+5Ch] [ebp+14h]
  float monof; // [esp+5Ch] [ebp+14h]
  float monog; // [esp+5Ch] [ebp+14h]
  float flRearToStereoScalea; // [esp+60h] [ebp+18h]
  float flRearToStereoScaleb; // [esp+60h] [ebp+18h]
  float flRearToStereoScalec; // [esp+60h] [ebp+18h]
  float flRearToStereoScaled; // [esp+60h] [ebp+18h]
  float flRearToStereoScalee; // [esp+60h] [ebp+18h]
  float flRearToStereoScalef; // [esp+60h] [ebp+18h]
  float flRearToStereoScaleg; // [esp+60h] [ebp+18h]
  float flRearToStereoScaleh; // [esp+60h] [ebp+18h]

  lrscale = 0.0;
  rrscale = 0.0;
  lfscale = 0.0;
  rfscale = 0.0;
  fcscale = 0.0;
  *volume = 0.0;
  volume[1] = 0.0;
  volume[2] = 0.0;
  volume[3] = 0.0;
  volume[4] = 0.0;
  volume[5] = 0.0;
  VectorAngles(forward: sourceDir, &angles);
  pitch = angles.x;
  yawa = angles.y;
  source2d.x = listener_right[nSlot].x;
  LODWORD(source2d.y) = dword_1043930C[3 * nSlot];
  source2d.z = 0.0;
  VectorNormalize(vec: &source2d);
  VectorAngles(forward: &source2d, angles: &angles2d);
  v8 = yawa - angles2d.y;
  v9 = 0;
  yaw = v8;
  if ( v8 < 0.0 )
    yaw = v8 + 360.0;
  if ( !this->m_bSurround )
  {
    if ( this->m_bHeadphone )
    {
      v10 = pitch;
      v11 = fabs(yaw);
      flRearToStereoScalea = mono;
      if ( v11 <= 180.0 )
      {
        v12 = v11;
      }
      else
      {
        nSlotc = v11;
        v12 = 360.0 - nSlotc;
      }
      if ( pitch < 0.0 )
        v10 = pitch + 360.0;
      if ( v10 > 180.0 )
        v10 = 360.0 - v10;
      if ( v10 > 90.0 )
        v10 = 90.0 - (float)(v10 - 90.0);
      if ( v10 > 45.0 )
      {
        v13 = (float)((float)(v10 - 45.0) * 0.022222223) + mono;
        if ( v13 >= 0.0 )
        {
          if ( v13 <= 1.0 )
            v9 = LODWORD(v13);
          else
            v9 = 1065353216;
        }
        flRearToStereoScalea = *(float *)&v9;
      }
      v14 = FastPow(a: v12 * 0.0055555557, b: 1.5);
      v16 = pitch;
      nSlota = mono;
      rfscale = 1.0 - v14 + (0.89999998 - (1.0 - v14)) * flRearToStereoScalea;
      v17 = fabs(yaw - 180.0);
      if ( v17 <= 180.0 )
      {
        v18 = v17;
      }
      else
      {
        monoa = v17;
        v18 = 360.0 - monoa;
      }
      if ( pitch < 0.0 )
        v16 = pitch + 360.0;
      if ( v16 > 180.0 )
        v16 = 360.0 - v16;
      if ( v16 > 90.0 )
        v16 = 90.0 - (float)(v16 - 90.0);
      if ( v16 > 45.0 )
      {
        v19 = (float)((float)(v16 - 45.0) * 0.022222223) + mono;
        if ( v19 >= 0.0 )
        {
          if ( v19 > 1.0 )
            v19 = 1.0;
        }
        else
        {
          v19 = 0.0;
        }
        nSlota = v19;
      }
      v20 = FastPow(a: v18 * 0.0055555557, b: 1.5);
      v9 = 0;
      v21 = rrscale;
      v22 = lrscale;
      lfscale = 1.0 - v20 + (0.89999998 - (1.0 - v20)) * nSlota;
    }
    else
    {
      v26 = mono;
      v27 = pitch;
      lrscale = mono;
      v28 = pitch;
      v29 = fabs(yaw - 45.0);
      v30 = 0.0;
      if ( v29 <= 180.0 )
      {
        v31 = v29;
      }
      else
      {
        nSlotd = v29;
        v31 = 360.0 - nSlotd;
      }
      if ( pitch < 0.0 )
        v28 = pitch + 360.0;
      if ( v28 > 180.0 )
        v28 = 360.0 - v28;
      if ( v28 > 90.0 )
        v28 = 90.0 - (float)(v28 - 90.0);
      if ( v28 > 45.0 )
      {
        v32 = (float)((float)(v28 - 45.0) * 0.022222223) + mono;
        if ( v32 >= 0.0 )
        {
          if ( v32 > 1.0 )
            v32 = 1.0;
        }
        else
        {
          v32 = 0.0;
        }
        lrscale = v32;
      }
      if ( v31 < 90.0 )
      {
        v9 = 0;
        v27 = pitch;
        v26 = mono;
        nSlote = 1.0 - FastPow(a: v31 * 0.011111111, b: 1.5);
        v30 = nSlote;
      }
      v33 = fabs(yaw - 135.0);
      rfscale = (float)((float)(0.89999998 - v30) * lrscale) + v30;
      lrscale = v26;
      v34 = v27;
      v35 = 0.0;
      if ( v33 <= 180.0 )
      {
        v36 = v33;
      }
      else
      {
        nSlotf = v33;
        v36 = 360.0 - nSlotf;
      }
      if ( v27 < 0.0 )
        v34 = v27 + 360.0;
      if ( v34 > 180.0 )
        v34 = 360.0 - v34;
      if ( v34 > 90.0 )
        v34 = 90.0 - (float)(v34 - 90.0);
      if ( v34 > 45.0 )
      {
        v37 = (float)((float)(v34 - 45.0) * 0.022222223) + v26;
        if ( v37 >= 0.0 )
        {
          if ( v37 > 1.0 )
            v37 = 1.0;
        }
        else
        {
          v37 = 0.0;
        }
        lrscale = v37;
      }
      if ( v36 < 90.0 )
      {
        v9 = 0;
        v27 = pitch;
        v26 = mono;
        nSlotg = 1.0 - FastPow(a: v36 * 0.011111111, b: 1.5);
        v35 = nSlotg;
      }
      v38 = fabs(yaw - 315.0);
      lfscale = (float)((float)(0.89999998 - v35) * lrscale) + v35;
      lrscale = v26;
      v39 = v27;
      v40 = 0.0;
      if ( v38 <= 180.0 )
      {
        v41 = v38;
      }
      else
      {
        nSloth = v38;
        v41 = 360.0 - nSloth;
      }
      if ( v27 < 0.0 )
        v39 = v27 + 360.0;
      if ( v39 > 180.0 )
        v39 = 360.0 - v39;
      if ( v39 > 90.0 )
        v39 = 90.0 - (float)(v39 - 90.0);
      if ( v39 > 45.0 )
      {
        v42 = (float)((float)(v39 - 45.0) * 0.022222223) + v26;
        if ( v42 >= 0.0 )
        {
          if ( v42 > 1.0 )
            v42 = 1.0;
        }
        else
        {
          v42 = 0.0;
        }
        lrscale = v42;
      }
      if ( v41 < 90.0 )
      {
        v9 = 0;
        v27 = pitch;
        v26 = mono;
        nSloti = 1.0 - FastPow(a: v41 * 0.011111111, b: 1.5);
        v40 = nSloti;
      }
      v43 = (float)(COERCE_FLOAT(LODWORD(v40) ^ _mask__NegFloat_) * lrscale) + v40;
      v44 = fabs(yaw - 225.0);
      rrscale = v43;
      pitcha = v26;
      v45 = 0.0;
      if ( v44 <= 180.0 )
      {
        v46 = v44;
      }
      else
      {
        monob = v44;
        v46 = 360.0 - monob;
      }
      if ( v27 < 0.0 )
        v27 = v27 + 360.0;
      if ( v27 > 180.0 )
        v27 = 360.0 - v27;
      if ( v27 > 90.0 )
        v27 = 90.0 - (float)(v27 - 90.0);
      if ( v27 > 45.0 )
      {
        v47 = (float)((float)(v27 - 45.0) * 0.022222223) + v26;
        if ( v47 >= 0.0 )
        {
          if ( v47 > 1.0 )
            v47 = 1.0;
          pitcha = v47;
        }
        else
        {
          pitcha = 0.0;
        }
      }
      if ( v46 < 90.0 )
      {
        v48 = FastPow(a: v46 * 0.011111111, b: 1.5);
        v9 = 0;
        v43 = rrscale;
        monoc = 1.0 - v48;
        v45 = monoc;
      }
      v49 = (float)(v43 * flRearToStereoScale) + rfscale;
      if ( v49 >= 0.0 )
      {
        if ( v49 <= 1.0 )
          rfscale = v49;
        else
          rfscale = 1.0;
      }
      else
      {
        rfscale = 0.0;
      }
      v50 = (float)((float)((float)(COERCE_FLOAT(LODWORD(v45) ^ _mask__NegFloat_) * pitcha) + v45) * flRearToStereoScale)
          + lfscale;
      if ( v50 >= 0.0 )
      {
        if ( v50 <= 1.0 )
          lfscale = (float)((float)((float)(COERCE_FLOAT(LODWORD(v45) ^ _mask__NegFloat_) * pitcha) + v45)
                          * flRearToStereoScale)
                  + lfscale;
        else
          lfscale = 1.0;
      }
      else
      {
        lfscale = 0.0;
      }
      v21 = 0.0;
      v22 = 0.0;
    }
    goto SpatialExit_0;
  }
  v51 = pitch;
  v52 = pitch;
  v53 = fabs(yaw - 45.0);
  *(float *)&nSlotb = v53;
  if ( !this->m_bSurroundCenter )
  {
    v54 = mono;
    flRearToStereoScaleb = mono;
    v55 = 0.0;
    if ( v53 <= 180.0 )
      v56 = v53;
    else
      v56 = 360.0 - *(float *)&nSlotb;
    if ( pitch < 0.0 )
      v52 = pitch + 360.0;
    if ( v52 > 180.0 )
      v52 = 360.0 - v52;
    if ( v52 > 90.0 )
      v52 = 90.0 - (float)(v52 - 90.0);
    if ( v52 > 45.0 )
    {
      v57 = (float)((float)(v52 - 45.0) * 0.022222223) + mono;
      if ( v57 >= 0.0 )
      {
        if ( v57 > 1.0 )
          v57 = 1.0;
      }
      else
      {
        v57 = 0.0;
      }
      flRearToStereoScaleb = v57;
    }
    if ( v56 < 90.0 )
    {
      v9 = 0;
      v51 = pitch;
      v54 = mono;
      nSlotj = 1.0 - FastPow(a: v56 * 0.011111111, b: 1.5);
      v55 = nSlotj;
    }
    v58 = fabs(yaw - 135.0);
    rfscale = (float)((float)(0.89999998 - v55) * flRearToStereoScaleb) + v55;
    flRearToStereoScalec = v54;
    v59 = v51;
    v60 = 0.0;
    if ( v58 <= 180.0 )
    {
      v61 = v58;
    }
    else
    {
      nSlotk = v58;
      v61 = 360.0 - nSlotk;
    }
    if ( v51 < 0.0 )
      v59 = v51 + 360.0;
    if ( v59 > 180.0 )
      v59 = 360.0 - v59;
    if ( v59 > 90.0 )
      v59 = 90.0 - (float)(v59 - 90.0);
    if ( v59 > 45.0 )
    {
      v62 = (float)((float)(v59 - 45.0) * 0.022222223) + v54;
      if ( v62 >= 0.0 )
      {
        if ( v62 > 1.0 )
          v62 = 1.0;
      }
      else
      {
        v62 = 0.0;
      }
      flRearToStereoScalec = v62;
    }
    if ( v61 < 90.0 )
    {
      v9 = 0;
      v51 = pitch;
      v54 = mono;
      nSlotl = 1.0 - FastPow(a: v61 * 0.011111111, b: 1.5);
      v60 = nSlotl;
    }
    v63 = fabs(yaw - 315.0);
    lfscale = (float)((float)(0.89999998 - v60) * flRearToStereoScalec) + v60;
    flRearToStereoScaled = v54;
    v64 = v51;
    v65 = 0.0;
    if ( v63 <= 180.0 )
    {
      v66 = v63;
    }
    else
    {
      nSlotm = v63;
      v66 = 360.0 - nSlotm;
    }
    if ( v51 < 0.0 )
      v64 = v51 + 360.0;
    if ( v64 > 180.0 )
      v64 = 360.0 - v64;
    if ( v64 > 90.0 )
      v64 = 90.0 - (float)(v64 - 90.0);
    if ( v64 > 45.0 )
    {
      v67 = (float)((float)(v64 - 45.0) * 0.022222223) + v54;
      if ( v67 >= 0.0 )
      {
        if ( v67 > 1.0 )
          v67 = 1.0;
      }
      else
      {
        v67 = 0.0;
      }
      flRearToStereoScaled = v67;
    }
    if ( v66 < 90.0 )
    {
      v9 = 0;
      v51 = pitch;
      v54 = mono;
      nSlotn = 1.0 - FastPow(a: v66 * 0.011111111, b: 1.5);
      v65 = nSlotn;
    }
    v68 = fabs(yaw - 225.0);
    v21 = (float)((float)(0.89999998 - v65) * flRearToStereoScaled) + v65;
    rrscale = v21;
    pitchb = v54;
    v69 = 0.0;
    if ( v68 <= 180.0 )
    {
      v70 = v68;
    }
    else
    {
      monod = v68;
      v70 = 360.0 - monod;
    }
    if ( v51 < 0.0 )
      v51 = v51 + 360.0;
    if ( v51 > 180.0 )
      v51 = 360.0 - v51;
    if ( v51 > 90.0 )
      v51 = 90.0 - (float)(v51 - 90.0);
    if ( v51 > 45.0 )
    {
      v71 = (float)((float)(v51 - 45.0) * 0.022222223) + v54;
      if ( v71 >= 0.0 )
      {
        if ( v71 > 1.0 )
          v71 = 1.0;
      }
      else
      {
        v71 = 0.0;
      }
      pitchb = v71;
    }
    if ( v70 < 90.0 )
    {
      v72 = FastPow(a: v70 * 0.011111111, b: 1.5);
      v9 = 0;
      v21 = rrscale;
      monoe = 1.0 - v72;
      v69 = monoe;
    }
    v22 = (float)((float)(0.89999998 - v69) * pitchb) + v69;
    goto SpatialExit_0;
  }
  v73 = mono;
  flRearToStereoScalee = mono;
  v74 = 0.0;
  if ( v53 <= 180.0 )
    v75 = v53;
  else
    v75 = 360.0 - *(float *)&nSlotb;
  if ( pitch < 0.0 )
    v52 = pitch + 360.0;
  if ( v52 > 180.0 )
    v52 = 360.0 - v52;
  if ( v52 > 90.0 )
    v52 = 90.0 - (float)(v52 - 90.0);
  if ( v52 > 45.0 )
  {
    v76 = (float)((float)(v52 - 45.0) * 0.022222223) + mono;
    if ( v76 >= 0.0 )
    {
      if ( v76 > 1.0 )
        v76 = 1.0;
    }
    else
    {
      v76 = 0.0;
    }
    flRearToStereoScalee = v76;
  }
  if ( v75 < 90.0 )
  {
    if ( yaw <= 45.0 )
    {
      v9 = 0;
      v51 = pitch;
      v73 = mono;
      nSlotp = 1.0 - FastPow(a: v75 * 0.011111111, b: 1.5);
      v74 = nSlotp;
    }
    else if ( v75 <= 75.0 )
    {
      v9 = 0;
      v51 = pitch;
      v73 = mono;
      nSloto = 1.0 - FastPow(a: v75 * 0.013333334, b: 1.5);
      v74 = nSloto;
    }
  }
  v77 = fabs(yaw - 90.0);
  rfscale = (float)((float)(0.89999998 - v74) * flRearToStereoScalee) + v74;
  flRearToStereoScalef = v73;
  v78 = v51;
  v79 = 0.0;
  if ( v77 <= 180.0 )
  {
    v80 = v77;
  }
  else
  {
    nSlotq = v77;
    v80 = 360.0 - nSlotq;
  }
  if ( v51 < 0.0 )
    v78 = v51 + 360.0;
  if ( v78 > 180.0 )
    v78 = 360.0 - v78;
  if ( v78 > 90.0 )
    v78 = 90.0 - (float)(v78 - 90.0);
  if ( v78 > 45.0 )
  {
    v81 = (float)((float)(v78 - 45.0) * 0.022222223) + v73;
    if ( v81 >= 0.0 )
    {
      if ( v81 > 1.0 )
        v81 = 1.0;
    }
    else
    {
      v81 = 0.0;
    }
    flRearToStereoScalef = v81;
  }
  if ( v80 < 90.0 && v80 <= 45.0 )
  {
    v9 = 0;
    v51 = pitch;
    v73 = mono;
    nSlotr = 1.0 - FastPow(a: v80 * 0.022222223, b: 1.5);
    v79 = nSlotr;
  }
  v82 = fabs(yaw - 135.0);
  fcscale = (float)((float)(0.89999998 - v79) * flRearToStereoScalef) + v79;
  flRearToStereoScaleg = v73;
  v83 = v51;
  v84 = 0.0;
  if ( v82 <= 180.0 )
  {
    v85 = v82;
  }
  else
  {
    nSlots = v82;
    v85 = 360.0 - nSlots;
  }
  if ( v51 < 0.0 )
    v83 = v51 + 360.0;
  if ( v83 > 180.0 )
    v83 = 360.0 - v83;
  if ( v83 > 90.0 )
    v83 = 90.0 - (float)(v83 - 90.0);
  if ( v83 > 45.0 )
  {
    v86 = (float)((float)(v83 - 45.0) * 0.022222223) + v73;
    if ( v86 >= 0.0 )
    {
      if ( v86 > 1.0 )
        v86 = 1.0;
    }
    else
    {
      v86 = 0.0;
    }
    flRearToStereoScaleg = v86;
  }
  if ( v85 < 90.0 )
  {
    if ( yaw >= 135.0 )
    {
      a = v85 * 0.011111111;
      goto LABEL_245;
    }
    if ( v85 <= 75.0 )
    {
      a = v85 * 0.013333334;
LABEL_245:
      v73 = mono;
      v51 = pitch;
      v9 = 0;
      nSlott = 1.0 - FastPow(a, b: 1.5);
      v84 = nSlott;
    }
  }
  v88 = fabs(yaw - 315.0);
  lfscale = (float)((float)(0.89999998 - v84) * flRearToStereoScaleg) + v84;
  flRearToStereoScaleh = v73;
  v89 = v51;
  v90 = 0.0;
  if ( v88 <= 180.0 )
  {
    v91 = v88;
  }
  else
  {
    nSlotu = v88;
    v91 = 360.0 - nSlotu;
  }
  if ( v51 < 0.0 )
    v89 = v51 + 360.0;
  if ( v89 > 180.0 )
    v89 = 360.0 - v89;
  if ( v89 > 90.0 )
    v89 = 90.0 - (float)(v89 - 90.0);
  if ( v89 > 45.0 )
  {
    v92 = (float)((float)(v89 - 45.0) * 0.022222223) + v73;
    if ( v92 >= 0.0 )
    {
      if ( v92 > 1.0 )
        v92 = 1.0;
    }
    else
    {
      v92 = 0.0;
    }
    flRearToStereoScaleh = v92;
  }
  if ( v91 < 90.0 )
  {
    v9 = 0;
    v51 = pitch;
    v73 = mono;
    nSlotv = 1.0 - FastPow(a: v91 * 0.011111111, b: 1.5);
    v90 = nSlotv;
  }
  v93 = fabs(yaw - 225.0);
  v21 = (float)((float)(0.5 - v90) * flRearToStereoScaleh) + v90;
  rrscale = v21;
  pitchc = v73;
  v94 = 0.0;
  if ( v93 <= 180.0 )
  {
    v95 = v93;
  }
  else
  {
    monof = v93;
    v95 = 360.0 - monof;
  }
  if ( v51 < 0.0 )
    v51 = v51 + 360.0;
  if ( v51 > 180.0 )
    v51 = 360.0 - v51;
  if ( v51 > 90.0 )
    v51 = 90.0 - (float)(v51 - 90.0);
  if ( v51 > 45.0 )
  {
    v96 = (float)((float)(v51 - 45.0) * 0.022222223) + v73;
    if ( v96 >= 0.0 )
    {
      if ( v96 > 1.0 )
        v96 = 1.0;
    }
    else
    {
      v96 = 0.0;
    }
    pitchc = v96;
  }
  if ( v95 < 90.0 )
  {
    v97 = FastPow(a: v95 * 0.011111111, b: 1.5);
    v9 = 0;
    v21 = rrscale;
    monog = 1.0 - v97;
    v94 = monog;
  }
  v22 = (float)((float)(0.5 - v94) * pitchc) + v94;
SpatialExit_0:
  v23 = rfscale;
  v24 = rfscale >= 0.0;
  v25 = lfscale;
  volume[1] = rfscale;
  *volume = v25;
  if ( v24 )
  {
    if ( v23 > 1.0 )
      v23 = 1.0;
  }
  else
  {
    v23 = 0.0;
  }
  volume[1] = v23;
  if ( v25 >= 0.0 )
  {
    if ( v25 <= 1.0 )
      v98 = LODWORD(v25);
    else
      v98 = 1065353216;
  }
  else
  {
    v98 = 0;
  }
  *(_DWORD *)volume = v98;
  if ( this->m_bSurround )
  {
    volume[3] = v21;
    volume[2] = v22;
    if ( v21 >= 0.0 )
    {
      if ( v21 > 1.0 )
        v21 = 1.0;
    }
    else
    {
      v21 = 0.0;
    }
    volume[3] = v21;
    v99 = LODWORD(v22);
    if ( v22 >= 0.0 )
    {
      if ( v22 > 1.0 )
        v99 = 1065353216;
    }
    else
    {
      v99 = 0;
    }
    *((_DWORD *)volume + 2) = v99;
    if ( this->m_bSurroundCenter )
    {
      v100 = fcscale;
      v24 = fcscale >= 0.0;
      volume[4] = fcscale;
      volume[5] = 0.0;
      if ( v24 )
      {
        if ( v100 > 1.0 )
        {
          volume[4] = 1.0;
          return;
        }
        v9 = LODWORD(v100);
      }
      *((_DWORD *)volume + 4) = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100087B0
// Name: public: virtual bool CAudioDeviceBase::IsHeadphone(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioDeviceBase::IsHeadphone(CAudioDeviceBase *this)
{
  return this->m_bHeadphone;
}

//------------------------------------------------------------------------------
// Address: 0x100087C0
// Name: public: virtual __int64 CAudioDeviceNull::PaintBegin(float,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CAudioDeviceNull::PaintBegin(CAudioDeviceNull *this, float __formal, __int64 __formala, __int64 a4)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100087D0
// Name: public: virtual void CAudioDeviceNull::Mix16Stereo(struct channel_t __near *,short __near *,int,int,unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceNull::Mix16Stereo(
        CAudioDeviceNull *this,
        channel_t *pChannel,
        channel_t *pData,
        __int16 *outputOffset,
        int inputOffset,
        int rateScaleFix,
        unsigned int outCount,
        int timecompress)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1007B100
// Name: public: virtual void CAudioDeviceNull::ChannelReset(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDeviceNull::ChannelReset(
        vgui::TreeView *this,
        int itemIndex,
        bool bInsertBefore,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10090F00
// Name: public: virtual int CAudioDeviceNull::DeviceSampleBits(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDeviceNull::DeviceSampleBits(CAudioDeviceNull *this)
{
  return 16;
}

} // namespace engine_xlsp
