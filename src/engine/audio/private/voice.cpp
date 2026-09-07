// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/voice.cpp
// Functions: 36
// ============================================================

#include "engine\audio\private\voice.h"

//------------------------------------------------------------------------------
// Address: 0x100536B0
// Name: int Voice_SamplesPerSec(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_SamplesPerSec()
{
  int rate; // [esp+0h] [ebp-4h] BYREF

  rate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(&rate);
  return rate;
}

//------------------------------------------------------------------------------
// Address: 0x100536D0
// Name: int Voice_AvgBytesPerSec(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_AvgBytesPerSec()
{
  int rate; // [esp+0h] [ebp-4h] BYREF

  rate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(&rate);
  return (rate * g_VoiceSampleFormat.wBitsPerSample) >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x10053700
// Name: void ApplyFadeToSamples(short __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyFadeToSamples(__int16 *pSamples, int nSamples, int fadeOffset, float fadeMul)
{
  int i; // eax

  for ( i = 0; i < nSamples; ++i )
    pSamples[i] = (int)(float)((float)(1.0 - (float)((float)(i + fadeOffset) * fadeMul)) * (float)pSamples[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10053760
// Name: void Voice_EndChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_EndChannel(int iChannel)
{
  CVoiceChannel *v1; // esi
  int m_iEntity; // edi
  bool m_bProximity; // zf
  vgui::PropertyPage *v4; // ecx

  v1 = &g_VoiceChannels[iChannel];
  m_iEntity = v1->m_iEntity;
  if ( v1->m_iEntity != -1 )
  {
    m_bProximity = v1->m_bProximity;
    v1->m_iEntity = -1;
    if ( m_bProximity )
      VoiceSE_EndChannel(iChannel, iEntity: m_iEntity);
    else
      VoiceSE_EndChannel(iChannel, iEntity: v1->m_nViewEntityIndex);
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: m_iEntity, a3: -1, a4: false);
    CColorBalanceUIPanel::Init(this: v4);
    v1->m_nViewEntityIndex = -1;
    v1->m_nSoundGuid = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100537E0
// Name: void Voice_EndAllChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_EndAllChannels()
{
  int v0; // ebx
  int *p_m_nViewEntityIndex; // esi
  int v2; // edi
  bool v3; // zf
  vgui::PropertyPage *v4; // ecx

  v0 = 0;
  p_m_nViewEntityIndex = &g_VoiceChannels[0].m_nViewEntityIndex;
  do
  {
    v2 = *(p_m_nViewEntityIndex - 5538);
    if ( v2 != -1 )
    {
      v3 = *((_BYTE *)p_m_nViewEntityIndex - 4) == 1;
      *(p_m_nViewEntityIndex - 5538) = -1;
      if ( v3 )
        VoiceSE_EndChannel(iChannel: v0, iEntity: v2);
      else
        VoiceSE_EndChannel(iChannel: v0, iEntity: *p_m_nViewEntityIndex);
      g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: v2, a3: -1, a4: false);
      CColorBalanceUIPanel::Init(this: v4);
      *p_m_nViewEntityIndex = -1;
      p_m_nViewEntityIndex[1] = -1;
    }
    p_m_nViewEntityIndex += 5540;
    ++v0;
  }
  while ( (int)p_m_nViewEntityIndex < (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[874] );
}

//------------------------------------------------------------------------------
// Address: 0x10053860
// Name: bool Voice_IsRecording(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Voice_IsRecording()
{
  return g_bVoiceRecording && !g_bInTweakMode;
}

//------------------------------------------------------------------------------
// Address: 0x10053880
// Name: int Voice_GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_GetChannel(int nEntity)
{
  int result; // eax
  CVoiceChannel *v2; // ecx

  result = 0;
  v2 = g_VoiceChannels;
  while ( v2->m_iEntity != nEntity )
  {
    ++v2;
    ++result;
    if ( (int)v2 >= (int)&voice_writevoices )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100538B0
// Name: double UpsampleIntoBuffer(short const __near *,int,class CCircularBuffer __near *,double,double)
// Source: json
//------------------------------------------------------------------------------
double __cdecl UpsampleIntoBuffer(
        const __int16 *pSrc,
        int nSrcSamples,
        CCircularBuffer *pBuffer,
        double startFraction,
        long double rate)
{
  double v5; // st7
  CCircularBuffer *v6; // ebx
  int v7; // esi
  double v8; // st7
  double X; // [esp+0h] [ebp-10h]
  double v11; // [esp+8h] [ebp-8h]

  X = (double)--nSrcSamples;
  v5 = startFraction;
  if ( startFraction < X )
  {
    v6 = pBuffer;
    do
    {
      v7 = (int)v5;
      nSrcSamples = pSrc[(int)v5];
      v11 = (double)nSrcSamples;
      v8 = floor(X: v5);
      nSrcSamples = pSrc[v7 + 1];
      nSrcSamples = (unsigned __int16)(int)(v11 + ((double)nSrcSamples - v11) * (startFraction - v8));
      CCircularBuffer::Write(this: v6, pData: (unsigned __int8 *)&nSrcSamples, nBytesRequested: 2);
      startFraction = startFraction + rate;
      v5 = startFraction;
    }
    while ( startFraction < X );
  }
  return startFraction - floor(X: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10053960
// Name: bool VoiceTweak_IsStillTweaking(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VoiceTweak_IsStillTweaking()
{
  return g_bInTweakMode;
}

//------------------------------------------------------------------------------
// Address: 0x10053970
// Name: void Voice_Spatialize(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_Spatialize(channel_t *channel)
{
  int v1; // eax

  if ( g_bInTweakMode
    && g_VoiceChannels[0].m_nSoundGuid == channel->guid
    && g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0) != g_VoiceChannels[0].m_nViewEntityIndex )
  {
    v1 = g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0);
    _DevMsg(
      a1: 1,
      a2: "Voice_Spatialize changing voice tweak entity from %d to %d\n",
      g_VoiceChannels[0].m_nViewEntityIndex,
      v1);
    g_VoiceChannels[0].m_nViewEntityIndex = g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0);
    channel->soundsource = g_VoiceChannels[0].m_nViewEntityIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100539F0
// Name: public: void CVoiceChannel::Init(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceChannel::Init(CVoiceChannel *this, int nEntity, float timePadding)
{
  this->m_iEntity = nEntity;
  this->m_bStarved = false;
  CCircularBuffer::Flush(this: &this->m_Buffer);
  this->m_TimePad = timePadding;
  if ( timePadding <= 0.0 )
    this->m_TimePad = 0.00000011920929;
  this->m_LastFraction = 0.999;
  this->m_LastSample = 0;
  CAutoGain::Reset(
    this: &this->m_AutoGain,
    blockSize: 128,
    maxGain: voice_maxgain.m_pParent->m_Value.m_fValue,
    avgToMaxVal: voice_avggain.m_pParent->m_Value.m_fValue,
    scale: voice_scale.m_pParent->m_Value.m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x10053A90
// Name: int Voice_GetOutputData(int,char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_GetOutputData(
        int iChannel,
        char *copyBufBytes,
        char *copyBufSize,
        int samplePosition,
        int sampleCount)
{
  CVoiceChannel *v5; // edi
  int v6; // ebx
  netadrtype_t Available; // eax
  int v8; // edx
  int v9; // kr04_4
  int v10; // esi
  __int32 v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // ebx
  char *v15; // edx

  v5 = &g_VoiceChannels[iChannel];
  v6 = (int)copyBufSize / 2;
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v5->m_Buffer);
  v8 = Available;
  if ( Available >= (int)copyBufSize / 2 )
    v8 = (int)copyBufSize / 2;
  if ( v8 >= 2 * sampleCount )
  {
    Available = 2 * sampleCount;
  }
  else if ( Available >= v6 )
  {
    Available = (int)copyBufSize / 2;
  }
  v9 = CCircularBuffer::Read(this: &v5->m_Buffer, pchDestIn: copyBufBytes, nCount: Available);
  v10 = v9 / 2;
  v11 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v5->m_Buffer) / 2;
  if ( v11 < g_nVoiceFadeSamples )
  {
    v12 = v10 + v11 - g_nVoiceFadeSamples <= 0 ? 0 : v10 + v11 - g_nVoiceFadeSamples;
    ApplyFadeToSamples(
      pSamples: (__int16 *)&copyBufBytes[2 * v12],
      nSamples: v10 - v12,
      fadeOffset: (g_nVoiceFadeSamples - v11 - v10) & ((g_nVoiceFadeSamples - v11 - v10 <= 0) - 1),
      fadeMul: g_VoiceFadeMul);
    v5 = &g_VoiceChannels[iChannel];
  }
  if ( v10 < sampleCount )
  {
    if ( sampleCount >= v6 )
      sampleCount = (int)copyBufSize / 2;
    v13 = sampleCount - v10;
    if ( v10 <= 0 )
    {
      v15 = &copyBufBytes[2 * v10];
    }
    else
    {
      v14 = v9 / 2;
      if ( v10 >= v13 )
        v14 = sampleCount - v10;
      _V_memcpy(dest: &copyBufBytes[2 * v10], src: &copyBufBytes[2 * (v10 - v14)], count: 2 * v14);
      v13 -= v14;
      if ( v13 <= 0 )
        goto LABEL_19;
      v15 = &copyBufBytes[2 * v10 + 2 * v14];
    }
    _V_memset(dest: v15, fill: 0, count: 2 * v13);
LABEL_19:
    v10 = sampleCount;
    v5 = &g_VoiceChannels[iChannel];
  }
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v5->m_Buffer) == NA_NULL )
    v5->m_bStarved = true;
  if ( voice_showchannels.m_pParent != nullptr && voice_showchannels.m_pParent->m_Value.m_nValue >= 2 )
    _Msg(a1: "Voice - mixed %d samples from channel %d\n", v10, iChannel);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)copyBufBytes);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10053C00
// Name: void Voice_OnAudioSourceShutdown(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_OnAudioSourceShutdown(int iChannel)
{
  Voice_EndChannel(iChannel);
}

//------------------------------------------------------------------------------
// Address: 0x10053C10
// Name: void Voice_LocalPlayerTalkingAck(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_LocalPlayerTalkingAck(int iSsSlot)
{
  int v1; // esi

  v1 = iSsSlot;
  if ( iSsSlot >= 0 )
  {
    if ( iSsSlot > 2 )
      v1 = 2;
  }
  else
  {
    v1 = 0;
  }
  if ( !g_bLocalPlayerTalkingAck[v1] )
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -2, a3: v1, a4: true);
  g_bLocalPlayerTalkingAck[v1] = true;
  g_LocalPlayerTalkingTimeout[v1] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10053C60
// Name: int Voice_AssignChannel(int,bool,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_AssignChannel(int nEntity, bool bProximity, float timePadding)
{
  int v4; // edi
  CVoiceChannel *v5; // eax
  CVoiceChannel *v6; // esi
  ConVar *m_pParent; // edx
  ConVar *v8; // eax

  if ( g_bInTweakMode )
    return -2;
  v4 = 0;
  v5 = g_VoiceChannels;
  while ( v5->m_iEntity != nEntity )
  {
    if ( v5->m_iEntity == -1 && v5->m_pVoiceCodec != nullptr )
    {
      v5->m_pVoiceCodec->ResetState(this: v5->m_pVoiceCodec);
      if ( v4 == -1 )
        return -1;
      v6 = &g_VoiceChannels[v4];
      v6->m_iEntity = nEntity;
      v6->m_bStarved = false;
      CCircularBuffer::Flush(this: &v6->m_Buffer);
      v6->m_TimePad = timePadding;
      if ( timePadding <= 0.0 )
        v6->m_TimePad = 0.00000011920929;
      m_pParent = voice_scale.m_pParent;
      v8 = voice_avggain.m_pParent;
      v6->m_LastFraction = 0.999;
      v6->m_LastSample = 0;
      CAutoGain::Reset(
        this: &v6->m_AutoGain,
        blockSize: 128,
        maxGain: voice_maxgain.m_pParent->m_Value.m_fValue,
        avgToMaxVal: v8->m_Value.m_fValue,
        scale: m_pParent->m_Value.m_fValue);
      v6->m_bProximity = bProximity;
      VoiceSE_StartOverdrive();
      return v4;
    }
    ++v5;
    ++v4;
    if ( (int)v5 >= (int)&voice_writevoices )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10053D70
// Name: void VoiceTweak_SetControlFloat(enum VoiceTweakControl,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceTweak_SetControlFloat(VoiceTweakControl iControl, float flValue)
{
  CVoiceChannel *v2; // esi

  if ( g_pMixerControls != nullptr )
  {
    if ( iControl != MicrophoneVolume )
    {
      if ( iControl == MicBoost )
      {
        ((void (__stdcall *)(_DWORD, _DWORD))g_pMixerControls->SetValue_Float)(a1: 0, a2: LODWORD(flValue));
      }
      else if ( iControl == OtherSpeakerScale )
      {
        ConVar::SetValue(this: (ConVar *)&voice_scale.IConVar, value: flValue);
        v2 = g_VoiceChannels;
        do
        {
          if ( v2 != nullptr && v2->m_iEntity > -1 )
            CVoiceChannel::Init(this: v2, nEntity: v2->m_iEntity, timePadding: v2->m_TimePad);
          ++v2;
        }
        while ( (int)v2 < (int)&voice_writevoices );
      }
    }
    else
    {
      ((void (__stdcall *)(int, _DWORD))g_pMixerControls->SetValue_Float)(a1: 1, a2: LODWORD(flValue));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053EB0
// Name: bool Voice_Enabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Voice_Enabled()
{
  return voice_enable.m_pParent != nullptr && voice_enable.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10053ED0
// Name: int Voice_GetCompressedData(char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall Voice_GetCompressedData@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        char *pchDest,
        int nCount,
        bool bFinal)
{
  IVoiceRecord *v6; // ecx
  int v7; // eax
  int v8; // eax
  CStatTime *v9; // ecx
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned __int8 *v14; // ecx
  int v15; // edx
  int v16; // edi
  int i; // ebx
  int v18; // eax
  float m_fValue; // xmm0_4
  long double v20; // st6
  double v22; // st7
  int v23; // edi
  signed int v24; // esi
  unsigned __int8 dst[16384]; // [esp+0h] [ebp-4010h] BYREF
  IVoiceCodec *v26; // [esp+4000h] [ebp-10h]
  long double v27; // [esp+4004h] [ebp-Ch]
  int rate; // [esp+400Ch] [ebp-4h] BYREF

  v6 = g_pVoiceRecord;
  v26 = g_pEncodeCodec;
  if ( g_pVoiceRecord != nullptr && g_pEncodeCodec != nullptr )
  {
    if ( (_S1_3 & 1) == 0 )
    {
      _S1_3 |= 1u;
      ConVarRef::ConVarRef(this: &voice_vox_0, pName: "voice_vox");
      v6 = g_pVoiceRecord;
    }
    v7 = nCount / 2;
    if ( nCount / 2 >= 0x2000 )
      v7 = 0x2000;
    v8 = ((int (__thiscall *)(IVoiceRecord *, unsigned __int8 *, int, int, int, int))v6->GetRecordedData)(
           a1: v6,
           a2: dst,
           a3: v7,
           a4: a2,
           a5: a3,
           a6: a1);
    v10 = v8;
    if ( g_pMicInputFileData != nullptr )
    {
      v27 = _Plat_FloatTime(this: v9);
      rate = g_VoiceSampleFormat.nSamplesPerSec;
      EngineTool_OverrideSampleRate(&rate);
      v11 = g_CurMicInputFileByte;
      v10 = (int)((v27 - g_MicStartTime) * (double)rate);
      v12 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      v13 = v10;
      if ( v10 >= v12 )
        v13 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      if ( v13 <= 0x2000 )
      {
        if ( v10 >= v12 )
          v10 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      }
      else
      {
        v10 = 0x2000;
      }
      memcpy(dst, src: (unsigned __int8 *)&g_pMicInputFileData[g_CurMicInputFileByte], count: 2 * v10);
      g_MicStartTime = v27;
      g_CurMicInputFileByte = 2 * v10 + v11;
    }
    else if ( v8 != 0 && voice_vox_0.m_pConVarState->m_Value.m_nValue != 0 )
    {
      v14 = dst;
      v15 = 0x4000;
      v16 = -16384;
      if ( v8 > 0 )
      {
        for ( i = v8; i != 0; --i )
        {
          v18 = *(__int16 *)v14;
          if ( v18 < v15 )
            v15 = *(__int16 *)v14;
          if ( v18 > v16 )
            v16 = *(__int16 *)v14;
          v14 += 2;
        }
      }
      m_fValue = voice_threshold.m_pParent->m_Value.m_fValue;
      if ( m_fValue <= (float)(v16 - v15) || m_fValue <= (float)v16 )
      {
        rate = SLODWORD(voice_threshold_delay.m_pParent->m_Value.m_fValue);
        v22 = _Plat_FloatTime(this: (CStatTime *)voice_threshold_delay.m_pParent);
        s_flThresholdDecayTime = v22 + *(float *)&rate;
      }
      else
      {
        v27 = s_flThresholdDecayTime;
        v20 = _Plat_FloatTime(this: (CStatTime *)(v16 - v15));
        if ( v20 > v27 )
        {
          g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -3, a3: 0, a4: false);
          return 0;
        }
      }
    }
    v23 = v26->Compress(this: v26, a2: (const char *)dst, a3: v10, a4: pchDest, a5: nCount, a6: bFinal);
    if ( g_pUncompressedFileData != nullptr )
    {
      v24 = 2 * v10;
      if ( v24 >= 0x100000 - g_nUncompressedDataBytes )
        v24 = 0x100000 - g_nUncompressedDataBytes;
      memcpy(dst: (unsigned __int8 *)&g_pUncompressedFileData[g_nUncompressedDataBytes], src: dst, count: v24);
      g_nUncompressedDataBytes += v24;
    }
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -3, a3: 0, a4: v23 > 0);
    return v23;
  }
  else
  {
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -3, a3: 0, a4: false);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054530
// Name: public: void CUtlBuffer::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::Purge(CUtlBuffer *this)
{
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = 0;
  this->m_Error = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054F20
// Name: public: CVoiceWriterData::CVoiceWriterData(class CVoiceWriterData const __near &)
// Source: json
//------------------------------------------------------------------------------
CVoiceWriterData *__thiscall CVoiceWriterData::CVoiceWriterData(CVoiceWriterData *this, const CVoiceWriterData *src)
{
  CUtlBuffer::CUtlBuffer(this: &this->m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
  this->m_pChannel = src->m_pChannel;
  this->m_nCount = src->m_nCount;
  this->m_Buffer.m_Get = 0;
  this->m_Buffer.m_Put = 0;
  this->m_Buffer.m_Error = 0;
  this->m_Buffer.m_nOffset = 0;
  this->m_Buffer.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->m_Buffer, nPut: 0);
  CUtlBuffer::Put(this: &this->m_Buffer, pMem: src->m_Buffer.m_Memory.m_pMemory, size: src->m_Buffer.m_Put);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10054F80
// Name: public: void CVoiceWriter::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceWriter::Flush(CVoiceWriter *this)
{
  CVoiceWriter *v1; // esi
  int Inorder; // edi
  UtlRBTreeNode_t<CVoiceWriterData,unsigned short> *m_pMemory; // ecx
  int v4; // eax
  int v5; // esi

  v1 = this;
  Inorder = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_VoiceWriter);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v1->m_VoiceWriter.m_Elements.m_pMemory;
      v4 = (unsigned __int16)Inorder << 6;
      v5 = (int)&m_pMemory->m_Data + v4;
      if ( *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Put + v4) > 0 )
      {
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Get + v4) = 0;
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Put + v4) = 0;
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_nOffset + v4) = 0;
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_nMaxPut + v4) = 0;
        *(&m_pMemory->m_Data.m_Buffer.m_Error + v4) = 0;
        if ( *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Memory.m_nGrowSize + v4) >= 0 )
        {
          if ( *(unsigned __int8 **)((char *)&m_pMemory->m_Data.m_Buffer.m_Memory.m_pMemory + v4) != nullptr )
          {
            _g_pMemAlloc->Free_2(
              this: _g_pMemAlloc,
              a2: *(unsigned __int8 **)((char *)&m_pMemory->m_Data.m_Buffer.m_Memory.m_pMemory + v4));
            *(_DWORD *)(v5 + 8) = 0;
          }
          *(_DWORD *)(v5 + 12) = 0;
        }
      }
      Inorder = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::NextInorder(
                  this: &this->m_VoiceWriter,
                  i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055010
// Name: public: void CVoiceWriter::Finish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceWriter::Finish(CVoiceWriter *this)
{
  CVoiceWriter *v1; // edi
  bool (__thiscall *IsConnected)(ISoundServices *); // edx
  UtlRBTreeNode_t<CVoiceWriterData,unsigned short> *m_pMemory; // ecx
  int v4; // eax
  int v5; // esi
  int v6; // edi
  const char *v7; // eax
  double v8; // st7
  char fn[260]; // [esp+4h] [ebp-214h] BYREF
  char path[260]; // [esp+108h] [ebp-110h] BYREF
  int rate; // [esp+20Ch] [ebp-Ch] BYREF
  CVoiceWriter *v12; // [esp+210h] [ebp-8h]
  int i; // [esp+214h] [ebp-4h]

  v1 = this;
  IsConnected = g_pSoundServices->IsConnected;
  v12 = this;
  if ( IsConnected(this: g_pSoundServices) )
  {
    for ( i = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_VoiceWriter);
          i != 0xFFFF;
          i = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::NextInorder(
                this: &v1->m_VoiceWriter,
                i) )
    {
      m_pMemory = v1->m_VoiceWriter.m_Elements.m_pMemory;
      v4 = (unsigned __int16)i << 6;
      v5 = (int)&m_pMemory->m_Data + v4;
      if ( *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Put + v4) > 0 )
      {
        v6 = (*(_DWORD *)v5 - (int)g_VoiceChannels) / 22160;
        v7 = g_pSoundServices->GetGameDir(this: g_pSoundServices);
        V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/voice", v7);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: path, a3: nullptr);
        v8 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetClientTime)(a1: g_pSoundServices);
        V_snprintf(
          pDest: fn,
          maxLen: 260,
          pFormat: "%s/pl%02d_slot%d-time%d.wav",
          path,
          v6,
          *(_DWORD *)(v5 + 4),
          (int)v8);
        rate = g_VoiceSampleFormat.nSamplesPerSec;
        EngineTool_OverrideSampleRate(&rate);
        WriteWaveFile(
          pFilename: fn,
          pData: *(const char **)(v5 + 8),
          nBytes: *(_DWORD *)(v5 + 24),
          wBitsPerSample: g_VoiceSampleFormat.wBitsPerSample,
          nChannels: g_VoiceSampleFormat.nChannels,
          nSamplesPerSec: rate);
        _Msg(a1: "Writing file %s\n", fn);
        ++*(_DWORD *)(v5 + 4);
        *(_DWORD *)(v5 + 20) = 0;
        *(_DWORD *)(v5 + 24) = 0;
        *(_DWORD *)(v5 + 40) = 0;
        *(_DWORD *)(v5 + 36) = 0;
        *(_BYTE *)(v5 + 28) = 0;
        if ( *(int *)(v5 + 16) >= 0 )
        {
          if ( *(_DWORD *)(v5 + 8) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v5 + 8));
            *(_DWORD *)(v5 + 8) = 0;
          }
          *(_DWORD *)(v5 + 12) = 0;
        }
        v1 = v12;
      }
    }
  }
  else
  {
    CVoiceWriter::Flush(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100551A0
// Name: bool Voice_RecordStop(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Voice_RecordStop()
{
  int rate; // [esp+4h] [ebp-4h] BYREF

  if ( g_pMicInputFileData != nullptr )
  {
    free(pMem: g_pMicInputFileData);
    g_pMicInputFileData = nullptr;
  }
  if ( g_pUncompressedFileData != nullptr )
  {
    rate = g_VoiceSampleFormat.nSamplesPerSec;
    EngineTool_OverrideSampleRate(&rate);
    WriteWaveFile(
      pFilename: g_pUncompressedDataFilename,
      pData: g_pUncompressedFileData,
      nBytes: g_nUncompressedDataBytes,
      wBitsPerSample: g_VoiceSampleFormat.wBitsPerSample,
      nChannels: g_VoiceSampleFormat.nChannels,
      nSamplesPerSec: rate);
    free(pMem: g_pUncompressedFileData);
    g_pUncompressedFileData = nullptr;
  }
  if ( g_pDecompressedFileData != nullptr )
  {
    rate = g_VoiceSampleFormat.nSamplesPerSec;
    EngineTool_OverrideSampleRate(&rate);
    WriteWaveFile(
      pFilename: g_pDecompressedDataFilename,
      pData: g_pDecompressedFileData,
      nBytes: g_nDecompressedDataBytes,
      wBitsPerSample: g_VoiceSampleFormat.wBitsPerSample,
      nChannels: g_VoiceSampleFormat.nChannels,
      nSamplesPerSec: rate);
    free(pMem: g_pDecompressedFileData);
    g_pDecompressedFileData = nullptr;
  }
  CVoiceWriter::Finish(this: &g_VoiceWriter);
  if ( g_pVoiceRecord != nullptr )
    g_pVoiceRecord->RecordStop(this: g_pVoiceRecord);
  if ( g_bVoiceRecording )
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -1, a3: 0, a4: false);
  g_bVoiceRecording = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100552C0
// Name: void VoiceTweak_EndVoiceTweakMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceTweak_EndVoiceTweakMode()
{
  if ( g_bInTweakMode )
  {
    g_bInTweakMode = false;
    Voice_RecordStop();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055360
// Name: void Voice_Deinit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_Deinit()
{
  IVoiceCodec **p_m_pVoiceCodec; // esi

  if ( g_bVoiceAtLeastPartiallyInitted && !EngineTool_SuppressDeInit() )
  {
    Voice_EndAllChannels();
    Voice_RecordStop();
    p_m_pVoiceCodec = &g_VoiceChannels[0].m_pVoiceCodec;
    do
    {
      if ( *p_m_pVoiceCodec != nullptr )
      {
        (*p_m_pVoiceCodec)->Release(this: *p_m_pVoiceCodec);
        *p_m_pVoiceCodec = nullptr;
      }
      p_m_pVoiceCodec += 5540;
    }
    while ( (int)p_m_pVoiceCodec < (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[846] );
    if ( g_pEncodeCodec != nullptr )
    {
      g_pEncodeCodec->Release(this: g_pEncodeCodec);
      g_pEncodeCodec = nullptr;
    }
    if ( g_hVoiceCodecDLL != nullptr )
    {
      FileSystem_UnloadModule(pModule: g_hVoiceCodecDLL);
      g_hVoiceCodecDLL = nullptr;
    }
    if ( g_pVoiceRecord != nullptr )
    {
      g_pVoiceRecord->Release(this: g_pVoiceRecord);
      g_pVoiceRecord = nullptr;
    }
    VoiceSE_Term();
    g_bVoiceAtLeastPartiallyInitted = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055400
// Name: bool Voice_RecordStart(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Voice_RecordStart(const char *pUncompressedFile, const char *pDecompressedFile, const char *pMicInputFile)
{
  bool result; // al
  CStatTime *v4; // ecx
  int a; // [esp+0h] [ebp-Ch] BYREF
  int b; // [esp+4h] [ebp-8h] BYREF
  int c; // [esp+8h] [ebp-4h] BYREF

  if ( g_pEncodeCodec == nullptr )
    return false;
  CVoiceWriter::Flush(this: &g_VoiceWriter);
  Voice_RecordStop();
  g_pEncodeCodec->ResetState(this: g_pEncodeCodec);
  if ( pMicInputFile != nullptr )
  {
    ReadWaveFile(
      pFilename: pMicInputFile,
      pData: &g_pMicInputFileData,
      nDataBytes: &g_nMicInputFileBytes,
      wBitsPerSample: &a,
      nChannels: &b,
      nSamplesPerSec: &c);
    g_CurMicInputFileByte = 0;
    g_MicStartTime = _Plat_FloatTime(this: v4);
  }
  if ( pUncompressedFile != nullptr )
  {
    g_pUncompressedFileData = (char *)MemAlloc_Alloc(nSize: 0x100000u);
    g_nUncompressedDataBytes = 0;
    g_pUncompressedDataFilename = pUncompressedFile;
  }
  if ( pDecompressedFile != nullptr )
  {
    g_pDecompressedFileData = (char *)MemAlloc_Alloc(nSize: 0x100000u);
    g_nDecompressedDataBytes = 0;
    g_pDecompressedDataFilename = pDecompressedFile;
  }
  result = false;
  g_bVoiceRecording = false;
  if ( g_pVoiceRecord != nullptr )
  {
    result = g_pVoiceRecord->RecordStart(this: g_pVoiceRecord);
    g_bVoiceRecording = result;
    if ( result )
    {
      g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -1, a3: 0, a4: true);
      return g_bVoiceRecording;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055740
// Name: bool Voice_Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall Voice_Init@<al>(int a1@<esi>, const char *pCodecName)
{
  IEngineVGuiInternal *v3; // eax
  IEngineVGuiInternal *v4; // eax
  IEngineVGuiInternal *v5; // eax
  IEngineVGuiInternal *v6; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *(__cdecl *v8)(const char *, int *); // ebx
  IVoiceCodec *v9; // eax
  IVoiceCodec **p_m_pVoiceCodec; // esi
  IEngineVGuiInternal *v11; // eax
  int v12; // eax
  IEngineVGuiInternal *v13; // eax
  int sampleRate; // [esp+0h] [ebp-4h] BYREF

  if ( voice_enable.m_pParent == nullptr )
    return 0;
  if ( voice_enable.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  v3 = EngineVGui();
  v3->UpdateProgressBar(this: v3, a2: PROGRESS_DEFAULT, a3: true);
  Voice_Deinit();
  g_bVoiceAtLeastPartiallyInitted = true;
  if ( !VoiceSE_Init() )
    return 0;
  v4 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *, int, int, int))v4->UpdateProgressBar)(a1: v4, a2: -1, a3: 1, a4: a1);
  sampleRate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(rate: &sampleRate);
  g_pVoiceRecord = CreateVoiceRecord_DSound(sampleRate);
  if ( g_pVoiceRecord == nullptr )
    _Msg(a1: "Unable to initialize DirectSoundCapture. You won't be able to speak to other players.");
  v5 = EngineVGui();
  v5->UpdateProgressBar(this: v5, a2: PROGRESS_DEFAULT, a3: true);
  g_hVoiceCodecDLL = FileSystem_LoadModule(path: pCodecName);
  v6 = EngineVGui();
  v6->UpdateProgressBar(this: v6, a2: PROGRESS_DEFAULT, a3: true);
  if ( g_hVoiceCodecDLL != nullptr
    && (Factory = Sys_GetFactory(pModule: g_hVoiceCodecDLL), v8 = Factory, Factory != nullptr)
    && (v9 = (IVoiceCodec *)Factory(a1: pCodecName, a2: nullptr), g_pEncodeCodec = v9, v9 != nullptr)
    && v9->Init(this: v9, a2: 4) )
  {
    p_m_pVoiceCodec = &g_VoiceChannels[0].m_pVoiceCodec;
    while ( 1 )
    {
      v11 = EngineVGui();
      v11->UpdateProgressBar(this: v11, a2: PROGRESS_DEFAULT, a3: true);
      v12 = (int)v8(a1: pCodecName, a2: nullptr);
      *p_m_pVoiceCodec = (IVoiceCodec *)v12;
      if ( v12 == 0 || (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v12 + 4))(a1: v12, a2: 4) == 0 )
        break;
      p_m_pVoiceCodec += 5540;
      if ( (int)p_m_pVoiceCodec >= (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[846] )
      {
        v13 = EngineVGui();
        v13->UpdateProgressBar(this: v13, a2: PROGRESS_DEFAULT, a3: true);
        InitMixerControls();
        if ( voice_forcemicrecord.m_pParent != nullptr
          && voice_forcemicrecord.m_pParent->m_Value.m_nValue != 0
          && g_pMixerControls != nullptr )
        {
          g_pMixerControls->SelectMicrophoneForWaveInput(this: g_pMixerControls);
        }
        return 1;
      }
    }
  }
  else
  {
    _Msg(a1: "Unable to load voice codec '%s'. Voice disabled.\n", pCodecName);
  }
  Voice_Deinit();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100558F0
// Name: int VoiceTweak_StartVoiceTweakMode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall VoiceTweak_StartVoiceTweakMode@<eax>(int a1@<esi>)
{
  char *m_pszString; // eax

  if ( g_bInTweakMode )
    return 0;
  if ( g_pMixerControls == nullptr )
  {
    if ( voice_enable.m_pParent == nullptr || voice_enable.m_pParent->m_Value.m_nValue == 0 )
      return 0;
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    Voice_Init(a1, pCodecName: m_pszString);
    if ( g_pMixerControls == nullptr )
      return 0;
  }
  Voice_EndAllChannels();
  if ( g_pEncodeCodec != nullptr )
  {
    CVoiceWriter::Flush(this: &g_VoiceWriter);
    Voice_RecordStop();
    g_pEncodeCodec->ResetState(this: g_pEncodeCodec);
    g_bVoiceRecording = false;
    if ( g_pVoiceRecord != nullptr )
    {
      g_bVoiceRecording = g_pVoiceRecord->RecordStart(this: g_pVoiceRecord);
      if ( g_bVoiceRecording )
        g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -1, a3: 0, a4: true);
    }
  }
  Voice_AssignChannel(nEntity: -500, bProximity: false, timePadding: 0.2);
  g_bInTweakMode = true;
  InitMixerControls();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100559E0
// Name: void Voice_ForceInit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Voice_ForceInit(int a1@<esi>)
{
  char *m_pszString; // eax

  if ( voice_enable.m_pParent != nullptr && voice_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      Voice_Init(a1, pCodecName: "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
      Voice_Init(a1, pCodecName: m_pszString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055A30
// Name: float VoiceTweak_GetControlFloat(enum VoiceTweakControl)
// Source: json
//------------------------------------------------------------------------------
double __usercall VoiceTweak_GetControlFloat@<st0>(int a1@<esi>, VoiceTweakControl iControl)
{
  IMixerControls *v2; // ecx
  char *m_pszString; // eax
  double result; // st7
  float flValue; // [esp+0h] [ebp-4h] BYREF

  v2 = g_pMixerControls;
  if ( g_pMixerControls == nullptr )
  {
    if ( voice_enable.m_pParent == nullptr
      || (IMixerControls *)voice_enable.m_pParent->m_Value.m_nValue == g_pMixerControls )
    {
      return 0.0;
    }
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    Voice_Init(a1, pCodecName: m_pszString);
    v2 = g_pMixerControls;
    if ( g_pMixerControls == nullptr )
      return 0.0;
  }
  if ( iControl != MicrophoneVolume )
  {
    if ( iControl == OtherSpeakerScale )
    {
      return voice_scale.m_pParent->m_Value.m_fValue;
    }
    else if ( iControl == SpeakingVolume )
    {
      return (double)g_VoiceTweakSpeakingVolume * 0.000030517578;
    }
    else
    {
      result = 1.0;
      if ( iControl == MicBoost )
      {
        flValue = 1.0;
        v2->GetValue_Float(this: v2, a2: (IMixerControls::Control)0, a3: &flValue);
        return flValue;
      }
    }
  }
  else
  {
    flValue = 1.0;
    v2->GetValue_Float(this: v2, a2: MicVolume, a3: &flValue);
    return flValue;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055AF0
// Name: bool VoiceTweak_IsControlFound(enum VoiceTweakControl)
// Source: json
//------------------------------------------------------------------------------
bool __usercall VoiceTweak_IsControlFound@<al>(int a1@<esi>, VoiceTweakControl iControl)
{
  IMixerControls *v2; // ecx
  char *m_pszString; // eax
  float fDummy; // [esp+0h] [ebp-4h] BYREF

  v2 = g_pMixerControls;
  if ( g_pMixerControls == nullptr )
  {
    if ( voice_enable.m_pParent == nullptr
      || (IMixerControls *)voice_enable.m_pParent->m_Value.m_nValue == g_pMixerControls )
    {
      return false;
    }
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    Voice_Init(a1, pCodecName: m_pszString);
    v2 = g_pMixerControls;
    if ( g_pMixerControls == nullptr )
      return false;
  }
  if ( iControl != MicrophoneVolume )
    return true;
  return v2->GetValue_Float(this: v2, a2: MicVolume, a3: &fDummy);
}

//------------------------------------------------------------------------------
// Address: 0x10055B70
// Name: void VoiceEnableCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall VoiceEnableCallback(int a1@<esi>, IConVar *var)
{
  IConVar *v2; // eax
  IConVar_vtbl *v3; // eax
  char *m_pszString; // eax

  if ( var != nullptr )
    v2 = var - 6;
  else
    v2 = nullptr;
  v3 = v2[7].__vftable;
  if ( v3 != nullptr
    && v3[1].GetName != nullptr
    && voice_enable.m_pParent != nullptr
    && voice_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      Voice_Init(a1, pCodecName: "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
      Voice_Init(a1, pCodecName: m_pszString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055CC0
// Name: public: void CVoiceWriter::AddDecompressedData(class CVoiceChannel __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceWriter::AddDecompressedData(
        CVoiceWriter *this,
        CVoiceChannel *ch,
        unsigned __int8 *data,
        unsigned int datalen)
{
  unsigned __int16 v5; // ax
  CVoiceWriterData search; // [esp+4h] [ebp-38h] BYREF

  if ( voice_writevoices.m_pParent != nullptr && voice_writevoices.m_pParent->m_Value.m_nValue != 0 )
  {
    search.m_nCount = 0;
    CUtlBuffer::CUtlBuffer(this: &search.m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
    search.m_pChannel = ch;
    v5 = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::Find(
           this: &this->m_VoiceWriter,
           &search);
    if ( v5 == 0xFFFF )
      v5 = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::Insert(
             this: &this->m_VoiceWriter,
             insert: &search);
    CUtlBuffer::Put(this: &this->m_VoiceWriter.m_Elements.m_pMemory[v5].m_Data.m_Buffer, pMem: data, size: datalen);
    if ( search.m_Buffer.m_Memory.m_nGrowSize >= 0 && search.m_Buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Buffer.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055D60
// Name: int Voice_AddIncomingData(int,char const __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Voice_AddIncomingData(
        unsigned int nChannel,
        __int64 pchData,
        int iSequenceNumber,
        bool isCompressed)
{
  CVoiceChannel *v4; // esi
  __int16 *v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  bool v9; // zf
  char startFraction[28]; // [esp+18h] [ebp-2008h] BYREF
  unsigned int count; // [esp+201Ch] [ebp-4h] BYREF

  if ( !g_bInTweakMode )
  {
    if ( nChannel <= 4 )
      goto LABEL_5;
    return 0;
  }
  if ( nChannel != -100 )
    return 0;
  nChannel = 0;
LABEL_5:
  v4 = &g_VoiceChannels[nChannel];
  if ( v4 == nullptr || isCompressed && v4->m_pVoiceCodec == nullptr )
    return 0;
  v4->m_bStarved = false;
  v5 = (__int16 *)&startFraction[4];
  if ( isCompressed )
  {
    v6 = v4->m_pVoiceCodec->Decompress(
           this: v4->m_pVoiceCodec,
           a2: (const char *)pchData,
           a3: HIDWORD(pchData),
           a4: &startFraction[4],
           a5: 0x2000);
  }
  else
  {
    v5 = (__int16 *)pchData;
    v6 = SHIDWORD(pchData) / 2;
  }
  if ( g_bInTweakMode )
  {
    v7 = 0;
    for ( g_VoiceTweakSpeakingVolume = 0; v7 < v6; ++v7 )
    {
      v8 = abs16(v5[v7]);
      if ( v8 > g_VoiceTweakSpeakingVolume )
        g_VoiceTweakSpeakingVolume = v8;
    }
    g_VoiceTweakSpeakingVolume &= 0xFE00u;
  }
  CAutoGain::ProcessSamples(this: &v4->m_AutoGain, pSamples: v5, nSamples: v6);
  count = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(rate: (int *)&count);
  v4->m_LastFraction = UpsampleIntoBuffer(
                         pSrc: v5,
                         nSrcSamples: v6,
                         pBuffer: &v4->m_Buffer,
                         startFraction: v4->m_LastFraction,
                         rate: (double)(int)count * 0.00009070294784580499);
  v9 = g_pDecompressedFileData == nullptr;
  v4->m_LastSample = *((char *)v5 + v6);
  if ( !v9 )
  {
    count = 2 * v6;
    if ( 2 * v6 >= 0x100000 - g_nDecompressedDataBytes )
      count = 0x100000 - g_nDecompressedDataBytes;
    memcpy(
      dst: (unsigned __int8 *)&g_pDecompressedFileData[g_nDecompressedDataBytes],
      src: (unsigned __int8 *)v5,
      count);
    g_nDecompressedDataBytes += count;
  }
  CVoiceWriter::AddDecompressedData(this: &g_VoiceWriter, ch: v4, data: (unsigned __int8 *)v5, datalen: 2 * v6);
  if ( voice_showincoming.m_pParent != nullptr && voice_showincoming.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Voice - %d incoming samples added to channel %d owned by entity %d\n", v6, nChannel, v4->m_iEntity);
  return nChannel;
}

//------------------------------------------------------------------------------
// Address: 0x10055F30
// Name: void Voice_UpdateVoiceTweakMode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Voice_UpdateVoiceTweakMode(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int CompressedData; // esi
  __int64 v4; // [esp-20h] [ebp-1020h]
  char timePadding[8]; // [esp+0h] [ebp-1000h] BYREF

  if ( g_bInTweakMode && g_pVoiceRecord != nullptr )
  {
    if ( g_VoiceChannels[0].m_nSoundGuid == -1 || S_IsSoundStillPlaying(guid: g_VoiceChannels[0].m_nSoundGuid) != 0 )
    {
      CompressedData = Voice_GetCompressedData(a1, a2, a3, pchDest: timePadding, nCount: 4096, bFinal: false);
      if ( CompressedData > 0 )
      {
        g_bInTweakMode = false;
        Voice_AssignChannel(nEntity: -500, bProximity: false, timePadding: 0.2);
        HIDWORD(v4) = CompressedData;
        LODWORD(v4) = timePadding;
        g_bInTweakMode = true;
        Voice_AddIncomingData(nChannel: 0xFFFFFF9C, pchData: v4, iSequenceNumber: 0, isCompressed: true);
      }
    }
    else if ( g_bInTweakMode )
    {
      g_bInTweakMode = false;
      Voice_RecordStop();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055FE0
// Name: bool Voice_Idle(float)
// Source: json
//------------------------------------------------------------------------------
char __usercall Voice_Idle@<al>(CStatTime *a1@<ecx>, int a2@<edi>, float frametime)
{
  int v3; // ebx
  CStatTime *v5; // ecx
  double v6; // st7
  int i; // esi
  float v8; // xmm0_4
  ISoundServices *v9; // ecx
  int v10; // eax
  float *p_m_TimePad; // esi
  int v12; // edi
  bool v13; // zf
  vgui::PropertyPage *v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // eax
  int started; // eax
  int v19; // edi
  CVoiceChannel *v20; // esi
  netadrtype_t Available; // eax
  int v22; // [esp+18h] [ebp-1Ch]
  char v23; // [esp+1Ch] [ebp-18h]
  float v24; // [esp+30h] [ebp-4h]
  int v25; // [esp+30h] [ebp-4h]
  float v26; // [esp+3Ch] [ebp+8h]

  v3 = 0;
  if ( voice_enable.m_pParent == nullptr || voice_enable.m_pParent->m_Value.m_nValue == 0 )
  {
    Voice_Deinit();
    return 0;
  }
  v6 = _Plat_FloatTime(this: a1) - g_fLocalPlayerTalkingLastUpdateRealTime;
  if ( frametime > v6 )
    return 0;
  v24 = v6;
  if ( (float)(frametime * 2.0) <= v24 )
    v26 = frametime * 2.0;
  else
    v26 = v6;
  g_fLocalPlayerTalkingLastUpdateRealTime = _Plat_FloatTime(this: v5);
  for ( i = 0; i < 2; ++i )
  {
    if ( g_bLocalPlayerTalkingAck[i] )
    {
      v8 = g_LocalPlayerTalkingTimeout[i] + v26;
      g_LocalPlayerTalkingTimeout[i] = v8;
      if ( v8 > 0.2 )
      {
        v9 = g_pSoundServices;
        g_bLocalPlayerTalkingAck[i] = false;
        v9->OnChangeVoiceStatus(this: v9, a2: -2, a3: i, a4: false);
      }
    }
  }
  v10 = (int)(float)(voice_fadeouttime.m_pParent->m_Value.m_fValue * 11025.0);
  if ( v10 <= 2 )
    v10 = 2;
  g_nVoiceFadeSamples = v10;
  g_VoiceFadeMul = 1.0 / (float)(v10 - 1);
  if ( g_pVoiceRecord != nullptr )
    g_pVoiceRecord->Idle(this: g_pVoiceRecord);
  Voice_UpdateVoiceTweakMode(a1: 0, a2, a3: i);
  v25 = 0;
  p_m_TimePad = &g_VoiceChannels[0].m_TimePad;
  do
  {
    if ( *((_DWORD *)p_m_TimePad - 5523) != -1 )
    {
      if ( *((_BYTE *)p_m_TimePad - 2) != 0 )
      {
        v12 = *((_DWORD *)p_m_TimePad - 5523);
        if ( v12 != -1 )
        {
          v13 = *((_BYTE *)p_m_TimePad + 56) == 1;
          *(p_m_TimePad - 5523) = NAN;
          if ( v13 )
            VoiceSE_EndChannel(iChannel: v3, iEntity: v12);
          else
            VoiceSE_EndChannel(iChannel: v3, iEntity: *((_DWORD *)p_m_TimePad + 15));
          g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: v12, a3: -1, a4: false);
          CColorBalanceUIPanel::Init(this: v14);
          p_m_TimePad[15] = NAN;
          p_m_TimePad[16] = NAN;
        }
        p_m_TimePad[16] = NAN;
      }
      else
      {
        v15 = *p_m_TimePad;
        v16 = *p_m_TimePad - v26;
        *p_m_TimePad = v16;
        if ( v15 > 0.0 && v16 <= 0.0 )
        {
          v17 = g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0);
          v23 = *((_BYTE *)p_m_TimePad + 56);
          v22 = *((_DWORD *)p_m_TimePad - 5523);
          *((_DWORD *)p_m_TimePad + 15) = v17;
          started = VoiceSE_StartChannel(iChannel: v3, iEntity: v22, bProximity: v23, nViewEntityIndex: v17);
          *((_DWORD *)p_m_TimePad + 16) = started;
          if ( started > 0 )
          {
            g_pSoundServices->OnChangeVoiceStatus(
              this: g_pSoundServices,
              a2: *((_DWORD *)p_m_TimePad - 5523),
              a3: -1,
              a4: true);
            CColorBalanceUIPanel::Init(this: *((vgui::PropertyPage **)p_m_TimePad - 5523));
          }
          else
          {
            Voice_EndChannel(iChannel: v3);
            p_m_TimePad[16] = NAN;
          }
        }
        ++v25;
      }
    }
    p_m_TimePad += 5540;
    ++v3;
  }
  while ( (int)p_m_TimePad < (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[844] );
  if ( v25 == 0 )
    VoiceSE_EndOverdrive();
  VoiceSE_Idle(frametime: v26);
  if ( voice_showchannels.m_pParent != nullptr && voice_showchannels.m_pParent->m_Value.m_nValue >= 1 )
  {
    v19 = 0;
    v20 = g_VoiceChannels;
    do
    {
      if ( v20->m_iEntity != -1 )
      {
        Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v20->m_Buffer);
        _Msg(a1: "Voice - chan %d, ent %d, bufsize: %d\n", v19, v20->m_iEntity, Available);
      }
      ++v20;
      ++v19;
    }
    while ( (int)v20 < (int)&voice_writevoices );
  }
  if ( voice_profile.m_pParent != nullptr && voice_profile.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(
      a1: "Voice - compress: %7.2fu, decompress: %7.2fu, gain: %7.2fu, upsample: %7.2fu, total: %7.2fu\n",
      (double)(g_CompressTime * 1000000.0),
      (double)(g_DecompressTime * 1000000.0),
      (double)(g_GainTime * 1000000.0),
      (double)(g_UpsampleTime * 1000000.0),
      (double)((g_DecompressTime + g_CompressTime + g_GainTime + g_UpsampleTime) * 1000000.0));
    g_UpsampleTime = 0.0;
    g_GainTime = 0.0;
    g_DecompressTime = 0.0;
    g_CompressTime = 0.0;
  }
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10053460
// Name: int Voice_SamplesPerSec(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_SamplesPerSec()
{
  int rate; // [esp+0h] [ebp-4h] BYREF

  rate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(&rate);
  return rate;
}

//------------------------------------------------------------------------------
// Address: 0x10053480
// Name: int Voice_AvgBytesPerSec(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_AvgBytesPerSec()
{
  int rate; // [esp+0h] [ebp-4h] BYREF

  rate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(&rate);
  return (rate * g_VoiceSampleFormat.wBitsPerSample) >> 3;
}

//------------------------------------------------------------------------------
// Address: 0x100534B0
// Name: void ApplyFadeToSamples(short __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyFadeToSamples(__int16 *pSamples, int nSamples, int fadeOffset, float fadeMul)
{
  int i; // eax

  for ( i = 0; i < nSamples; ++i )
    pSamples[i] = (int)(float)((float)(1.0 - (float)((float)(i + fadeOffset) * fadeMul)) * (float)pSamples[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10053510
// Name: void Voice_EndChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_EndChannel(int iChannel)
{
  CVoiceChannel *v1; // esi
  int m_iEntity; // edi
  bool m_bProximity; // zf
  vgui::PropertyPage *v4; // ecx

  v1 = &g_VoiceChannels[iChannel];
  m_iEntity = v1->m_iEntity;
  if ( v1->m_iEntity != -1 )
  {
    m_bProximity = v1->m_bProximity;
    v1->m_iEntity = -1;
    if ( m_bProximity )
      VoiceSE_EndChannel(iChannel, iEntity: m_iEntity);
    else
      VoiceSE_EndChannel(iChannel, iEntity: v1->m_nViewEntityIndex);
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: m_iEntity, a3: -1, a4: false);
    CColorBalanceUIPanel::Init(this: v4);
    v1->m_nViewEntityIndex = -1;
    v1->m_nSoundGuid = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053590
// Name: void Voice_EndAllChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_EndAllChannels()
{
  int v0; // ebx
  int *p_m_nViewEntityIndex; // esi
  int v2; // edi
  bool v3; // zf
  vgui::PropertyPage *v4; // ecx

  v0 = 0;
  p_m_nViewEntityIndex = &g_VoiceChannels[0].m_nViewEntityIndex;
  do
  {
    v2 = *(p_m_nViewEntityIndex - 5538);
    if ( v2 != -1 )
    {
      v3 = *((_BYTE *)p_m_nViewEntityIndex - 4) == 1;
      *(p_m_nViewEntityIndex - 5538) = -1;
      if ( v3 )
        VoiceSE_EndChannel(iChannel: v0, iEntity: v2);
      else
        VoiceSE_EndChannel(iChannel: v0, iEntity: *p_m_nViewEntityIndex);
      g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: v2, a3: -1, a4: false);
      CColorBalanceUIPanel::Init(this: v4);
      *p_m_nViewEntityIndex = -1;
      p_m_nViewEntityIndex[1] = -1;
    }
    p_m_nViewEntityIndex += 5540;
    ++v0;
  }
  while ( (int)p_m_nViewEntityIndex < (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[874] );
}

//------------------------------------------------------------------------------
// Address: 0x10053610
// Name: bool Voice_IsRecording(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Voice_IsRecording()
{
  return g_bVoiceRecording && !g_bInTweakMode;
}

//------------------------------------------------------------------------------
// Address: 0x10053630
// Name: int Voice_GetChannel(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_GetChannel(int nEntity)
{
  int result; // eax
  CVoiceChannel *v2; // ecx

  result = 0;
  v2 = g_VoiceChannels;
  while ( v2->m_iEntity != nEntity )
  {
    ++v2;
    ++result;
    if ( (int)v2 >= (int)&voice_writevoices )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053660
// Name: double UpsampleIntoBuffer(short const __near *,int,class CCircularBuffer __near *,double,double)
// Source: json
//------------------------------------------------------------------------------
double __cdecl UpsampleIntoBuffer(
        const __int16 *pSrc,
        int nSrcSamples,
        CCircularBuffer *pBuffer,
        double startFraction,
        long double rate)
{
  double X; // st7
  CCircularBuffer *v6; // ebx
  int v7; // esi
  double v8; // st7
  double maxFraction; // [esp+14h] [ebp-10h]
  double val1; // [esp+1Ch] [ebp-8h]

  maxFraction = (double)--nSrcSamples;
  X = startFraction;
  if ( startFraction < maxFraction )
  {
    v6 = pBuffer;
    do
    {
      v7 = (int)X;
      nSrcSamples = pSrc[(int)X];
      val1 = (double)nSrcSamples;
      v8 = floor(X);
      nSrcSamples = pSrc[v7 + 1];
      nSrcSamples = (unsigned __int16)(int)(val1 + ((double)nSrcSamples - val1) * (startFraction - v8));
      CCircularBuffer::Write(this: v6, pData: &nSrcSamples, nBytesRequested: 2);
      startFraction = startFraction + rate;
      X = startFraction;
    }
    while ( startFraction < maxFraction );
  }
  return startFraction - floor(X);
}

//------------------------------------------------------------------------------
// Address: 0x10053710
// Name: bool VoiceTweak_IsStillTweaking(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VoiceTweak_IsStillTweaking()
{
  return g_bInTweakMode;
}

//------------------------------------------------------------------------------
// Address: 0x10053720
// Name: void Voice_Spatialize(struct channel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_Spatialize(channel_t *channel)
{
  int v1; // eax

  if ( g_bInTweakMode
    && g_VoiceChannels[0].m_nSoundGuid == channel->guid
    && g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0) != g_VoiceChannels[0].m_nViewEntityIndex )
  {
    v1 = g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0);
    _DevMsg(
      a1: 1,
      a2: "Voice_Spatialize changing voice tweak entity from %d to %d\n",
      g_VoiceChannels[0].m_nViewEntityIndex,
      v1);
    g_VoiceChannels[0].m_nViewEntityIndex = g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0);
    channel->soundsource = g_VoiceChannels[0].m_nViewEntityIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100537A0
// Name: public: void CVoiceChannel::Init(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceChannel::Init(CVoiceChannel *this, int nEntity, float timePadding)
{
  this->m_iEntity = nEntity;
  this->m_bStarved = false;
  CCircularBuffer::Flush(this: &this->m_Buffer);
  this->m_TimePad = timePadding;
  if ( timePadding <= 0.0 )
    this->m_TimePad = 0.00000011920929;
  this->m_LastFraction = 0.999;
  this->m_LastSample = 0;
  CAutoGain::Reset(
    this: &this->m_AutoGain,
    blockSize: 128,
    maxGain: voice_maxgain.m_pParent->m_Value.m_fValue,
    avgToMaxVal: voice_avggain.m_pParent->m_Value.m_fValue,
    scale: voice_scale.m_pParent->m_Value.m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x10053840
// Name: int Voice_GetOutputData(int,char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_GetOutputData(
        int iChannel,
        vgui::PropertyPage *copyBufBytes,
        int copyBufSize,
        int samplePosition,
        int sampleCount)
{
  CVoiceChannel *v5; // edi
  int v6; // ebx
  netadrtype_t Available; // eax
  int v8; // edx
  int v9; // kr04_4
  int v10; // esi
  __int32 v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // ebx
  char *v15; // edx

  v5 = &g_VoiceChannels[iChannel];
  v6 = copyBufSize / 2;
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v5->m_Buffer);
  v8 = Available;
  if ( Available >= copyBufSize / 2 )
    v8 = copyBufSize / 2;
  if ( v8 >= 2 * sampleCount )
  {
    Available = 2 * sampleCount;
  }
  else if ( Available >= v6 )
  {
    Available = copyBufSize / 2;
  }
  v9 = CCircularBuffer::Read(this: &v5->m_Buffer, pchDestIn: copyBufBytes, nCount: Available);
  v10 = v9 / 2;
  v11 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v5->m_Buffer) / 2;
  if ( v11 < g_nVoiceFadeSamples )
  {
    v12 = v10 + v11 - g_nVoiceFadeSamples <= 0 ? 0 : v10 + v11 - g_nVoiceFadeSamples;
    ApplyFadeToSamples(
      pSamples: (__int16 *)copyBufBytes + v12,
      nSamples: v10 - v12,
      fadeOffset: (g_nVoiceFadeSamples - v11 - v10) & ((g_nVoiceFadeSamples - v11 - v10 <= 0) - 1),
      fadeMul: g_VoiceFadeMul);
    v5 = &g_VoiceChannels[iChannel];
  }
  if ( v10 < sampleCount )
  {
    if ( sampleCount >= v6 )
      sampleCount = copyBufSize / 2;
    v13 = sampleCount - v10;
    if ( v10 <= 0 )
    {
      v15 = (char *)copyBufBytes + 2 * v10;
    }
    else
    {
      v14 = v9 / 2;
      if ( v10 >= v13 )
        v14 = sampleCount - v10;
      _V_memcpy(dest: (char *)copyBufBytes + 2 * v10, src: (char *)copyBufBytes + 2 * (v10 - v14), count: 2 * v14);
      v13 -= v14;
      if ( v13 <= 0 )
        goto LABEL_19;
      v15 = (char *)copyBufBytes + 2 * v10 + 2 * v14;
    }
    _V_memset(dest: v15, fill: 0, count: 2 * v13);
LABEL_19:
    v10 = sampleCount;
    v5 = &g_VoiceChannels[iChannel];
  }
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v5->m_Buffer) == NA_NULL )
    v5->m_bStarved = true;
  if ( voice_showchannels.m_pParent != nullptr && voice_showchannels.m_pParent->m_Value.m_nValue >= 2 )
    _Msg(a1: "Voice - mixed %d samples from channel %d\n", v10, iChannel);
  CColorBalanceUIPanel::Init(this: copyBufBytes);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100539B0
// Name: void Voice_OnAudioSourceShutdown(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_OnAudioSourceShutdown(int iChannel)
{
  Voice_EndChannel(iChannel);
}

//------------------------------------------------------------------------------
// Address: 0x100539C0
// Name: void Voice_LocalPlayerTalkingAck(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_LocalPlayerTalkingAck(int iSsSlot)
{
  int v1; // esi

  v1 = iSsSlot;
  if ( iSsSlot >= 0 )
  {
    if ( iSsSlot > 2 )
      v1 = 2;
  }
  else
  {
    v1 = 0;
  }
  if ( !g_bLocalPlayerTalkingAck[v1] )
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -2, a3: v1, a4: true);
  g_bLocalPlayerTalkingAck[v1] = true;
  g_LocalPlayerTalkingTimeout[v1] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10053A10
// Name: int Voice_AssignChannel(int,bool,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Voice_AssignChannel(int nEntity, bool bProximity, float timePadding)
{
  int v4; // edi
  CVoiceChannel *v5; // eax
  CVoiceChannel *v6; // esi
  ConVar *m_pParent; // edx
  ConVar *v8; // eax

  if ( g_bInTweakMode )
    return -2;
  v4 = 0;
  v5 = g_VoiceChannels;
  while ( v5->m_iEntity != nEntity )
  {
    if ( v5->m_iEntity == -1 && v5->m_pVoiceCodec != nullptr )
    {
      v5->m_pVoiceCodec->ResetState(this: v5->m_pVoiceCodec);
      if ( v4 == -1 )
        return -1;
      v6 = &g_VoiceChannels[v4];
      v6->m_iEntity = nEntity;
      v6->m_bStarved = false;
      CCircularBuffer::Flush(this: &v6->m_Buffer);
      v6->m_TimePad = timePadding;
      if ( timePadding <= 0.0 )
        v6->m_TimePad = 0.00000011920929;
      m_pParent = voice_scale.m_pParent;
      v8 = voice_avggain.m_pParent;
      v6->m_LastFraction = 0.999;
      v6->m_LastSample = 0;
      CAutoGain::Reset(
        this: &v6->m_AutoGain,
        blockSize: 128,
        maxGain: voice_maxgain.m_pParent->m_Value.m_fValue,
        avgToMaxVal: v8->m_Value.m_fValue,
        scale: m_pParent->m_Value.m_fValue);
      v6->m_bProximity = bProximity;
      VoiceSE_StartOverdrive();
      return v4;
    }
    ++v5;
    ++v4;
    if ( (int)v5 >= (int)&voice_writevoices )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10053B20
// Name: void VoiceTweak_SetControlFloat(enum VoiceTweakControl,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceTweak_SetControlFloat(VoiceTweakControl iControl, float flValue)
{
  CVoiceChannel *v2; // esi

  if ( g_pMixerControls != nullptr )
  {
    if ( iControl != MicrophoneVolume )
    {
      if ( iControl == MicBoost )
      {
        ((void (__stdcall *)(_DWORD, _DWORD))g_pMixerControls->SetValue_Float)(a1: 0, a2: LODWORD(flValue));
      }
      else if ( iControl == OtherSpeakerScale )
      {
        ConVar::SetValue(this: (ConVar *)&voice_scale.IConVar, value: flValue);
        v2 = g_VoiceChannels;
        do
        {
          if ( v2 != nullptr && v2->m_iEntity > -1 )
            CVoiceChannel::Init(this: v2, nEntity: v2->m_iEntity, timePadding: v2->m_TimePad);
          ++v2;
        }
        while ( (int)v2 < (int)&voice_writevoices );
      }
    }
    else
    {
      ((void (__stdcall *)(int, _DWORD))g_pMixerControls->SetValue_Float)(a1: 1, a2: LODWORD(flValue));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053C80
// Name: int Voice_GetCompressedData(char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall Voice_GetCompressedData@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        char *pchDest,
        int nCount,
        bool bFinal)
{
  IVoiceRecord *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned __int8 *v14; // ecx
  int v15; // edx
  int v16; // edi
  int i; // ebx
  int v18; // eax
  float m_fValue; // xmm0_4
  double v20; // st6
  double v22; // st7
  int v23; // edi
  signed int v24; // esi
  unsigned __int8 dst[16384]; // [esp+0h] [ebp-4010h] BYREF
  IVoiceCodec *v26; // [esp+4000h] [ebp-10h]
  double v27; // [esp+4004h] [ebp-Ch]
  int rate; // [esp+400Ch] [ebp-4h] BYREF

  v6 = g_pVoiceRecord;
  v26 = g_pEncodeCodec;
  if ( g_pVoiceRecord != nullptr && g_pEncodeCodec != nullptr )
  {
    if ( (_S1_3 & 1) == 0 )
    {
      _S1_3 |= 1u;
      ConVarRef::ConVarRef(this: &voice_vox_0, pName: "voice_vox");
      v6 = g_pVoiceRecord;
    }
    v7 = nCount / 2;
    if ( nCount / 2 >= 0x2000 )
      v7 = 0x2000;
    v8 = ((int (__thiscall *)(IVoiceRecord *, unsigned __int8 *, int, int, int, int))v6->GetRecordedData)(
           a1: v6,
           a2: dst,
           a3: v7,
           a4: a2,
           a5: a3,
           a6: a1);
    v10 = v8;
    if ( g_pMicInputFileData != nullptr )
    {
      v27 = _Plat_FloatTime(a1: v9);
      rate = g_VoiceSampleFormat.nSamplesPerSec;
      EngineTool_OverrideSampleRate(&rate);
      v11 = g_CurMicInputFileByte;
      v10 = (int)((v27 - g_MicStartTime) * (double)rate);
      v12 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      v13 = v10;
      if ( v10 >= v12 )
        v13 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      if ( v13 <= 0x2000 )
      {
        if ( v10 >= v12 )
          v10 = (g_nMicInputFileBytes - g_CurMicInputFileByte) / 2;
      }
      else
      {
        v10 = 0x2000;
      }
      memcpy(dst, src: (unsigned __int8 *)&g_pMicInputFileData[g_CurMicInputFileByte], count: 2 * v10);
      g_MicStartTime = v27;
      g_CurMicInputFileByte = 2 * v10 + v11;
    }
    else if ( v8 != 0 && voice_vox_0.m_pConVarState->m_Value.m_nValue != 0 )
    {
      v14 = dst;
      v15 = 0x4000;
      v16 = -16384;
      if ( v8 > 0 )
      {
        for ( i = v8; i != 0; --i )
        {
          v18 = *(__int16 *)v14;
          if ( v18 < v15 )
            v15 = *(__int16 *)v14;
          if ( v18 > v16 )
            v16 = *(__int16 *)v14;
          v14 += 2;
        }
      }
      m_fValue = voice_threshold.m_pParent->m_Value.m_fValue;
      if ( m_fValue <= (float)(v16 - v15) || m_fValue <= (float)v16 )
      {
        rate = SLODWORD(voice_threshold_delay.m_pParent->m_Value.m_fValue);
        v22 = _Plat_FloatTime(a1: voice_threshold_delay.m_pParent);
        s_flThresholdDecayTime = v22 + *(float *)&rate;
      }
      else
      {
        v27 = s_flThresholdDecayTime;
        v20 = _Plat_FloatTime(a1: v16 - v15);
        if ( v20 > v27 )
        {
          g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -3, a3: 0, a4: false);
          return 0;
        }
      }
    }
    v23 = v26->Compress(this: v26, a2: (const char *)dst, a3: v10, a4: pchDest, a5: nCount, a6: bFinal);
    if ( g_pUncompressedFileData != nullptr )
    {
      v24 = 2 * v10;
      if ( v24 >= 0x100000 - g_nUncompressedDataBytes )
        v24 = 0x100000 - g_nUncompressedDataBytes;
      memcpy(dst: (unsigned __int8 *)&g_pUncompressedFileData[g_nUncompressedDataBytes], src: dst, count: v24);
      g_nUncompressedDataBytes += v24;
    }
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -3, a3: 0, a4: v23 > 0);
    return v23;
  }
  else
  {
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -3, a3: 0, a4: false);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100542E0
// Name: public: void CUtlBuffer::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::Purge(CUtlBuffer *this)
{
  this->m_Get = 0;
  this->m_Put = 0;
  this->m_nOffset = 0;
  this->m_nMaxPut = 0;
  this->m_Error = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054CD0
// Name: public: CVoiceWriterData::CVoiceWriterData(class CVoiceWriterData const __near &)
// Source: json
//------------------------------------------------------------------------------
CVoiceWriterData *__thiscall CVoiceWriterData::CVoiceWriterData(CVoiceWriterData *this, const CVoiceWriterData *src)
{
  CUtlBuffer::CUtlBuffer(this: &this->m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
  this->m_pChannel = src->m_pChannel;
  this->m_nCount = src->m_nCount;
  this->m_Buffer.m_Get = 0;
  this->m_Buffer.m_Put = 0;
  this->m_Buffer.m_Error = 0;
  this->m_Buffer.m_nOffset = 0;
  this->m_Buffer.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &this->m_Buffer, nPut: 0);
  CUtlBuffer::Put(this: &this->m_Buffer, pMem: src->m_Buffer.m_Memory.m_pMemory, size: src->m_Buffer.m_Put);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10054D30
// Name: public: void CVoiceWriter::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceWriter::Flush(CVoiceWriter *this)
{
  CVoiceWriter *v1; // esi
  int Inorder; // edi
  UtlRBTreeNode_t<CVoiceWriterData,unsigned short> *m_pMemory; // ecx
  int v4; // eax
  int v5; // esi

  v1 = this;
  Inorder = (unsigned __int16)CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_VoiceWriter);
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v1->m_VoiceWriter.m_Elements.m_pMemory;
      v4 = (unsigned __int16)Inorder << 6;
      v5 = (int)&m_pMemory->m_Data + v4;
      if ( *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Put + v4) > 0 )
      {
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Get + v4) = 0;
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Put + v4) = 0;
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_nOffset + v4) = 0;
        *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_nMaxPut + v4) = 0;
        *(&m_pMemory->m_Data.m_Buffer.m_Error + v4) = 0;
        if ( *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Memory.m_nGrowSize + v4) >= 0 )
        {
          if ( *(unsigned __int8 **)((char *)&m_pMemory->m_Data.m_Buffer.m_Memory.m_pMemory + v4) != nullptr )
          {
            _g_pMemAlloc->Free_2(
              this: _g_pMemAlloc,
              a2: *(unsigned __int8 **)((char *)&m_pMemory->m_Data.m_Buffer.m_Memory.m_pMemory + v4));
            *(_DWORD *)(v5 + 8) = 0;
          }
          *(_DWORD *)(v5 + 12) = 0;
        }
      }
      Inorder = (unsigned __int16)CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::NextInorder(
                                    this: &this->m_VoiceWriter,
                                    i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054DC0
// Name: public: void CVoiceWriter::Finish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceWriter::Finish(CVoiceWriter *this)
{
  CVoiceWriter *v1; // edi
  bool (__thiscall *IsConnected)(ISoundServices *); // edx
  UtlRBTreeNode_t<CVoiceWriterData,unsigned short> *m_pMemory; // ecx
  int v4; // eax
  int v5; // esi
  int v6; // edi
  const char *v7; // eax
  double v8; // st7
  char fn[260]; // [esp+4h] [ebp-214h] BYREF
  char path[260]; // [esp+108h] [ebp-110h] BYREF
  int rate; // [esp+20Ch] [ebp-Ch] BYREF
  CVoiceWriter *v12; // [esp+210h] [ebp-8h]
  int i; // [esp+214h] [ebp-4h]

  v1 = this;
  IsConnected = g_pSoundServices->IsConnected;
  v12 = this;
  if ( IsConnected(this: g_pSoundServices) )
  {
    for ( i = (unsigned __int16)CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_VoiceWriter);
          i != 0xFFFF;
          i = (unsigned __int16)CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::NextInorder(
                                  this: &v1->m_VoiceWriter,
                                  i) )
    {
      m_pMemory = v1->m_VoiceWriter.m_Elements.m_pMemory;
      v4 = (unsigned __int16)i << 6;
      v5 = (int)&m_pMemory->m_Data + v4;
      if ( *(int *)((char *)&m_pMemory->m_Data.m_Buffer.m_Put + v4) > 0 )
      {
        v6 = (*(_DWORD *)v5 - (int)g_VoiceChannels) / 22160;
        v7 = g_pSoundServices->GetGameDir(this: g_pSoundServices);
        V_snprintf(pDest: path, maxLen: 260, pFormat: "%s/voice", v7);
        g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: path, a3: nullptr);
        v8 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetClientTime)(a1: g_pSoundServices);
        V_snprintf(
          pDest: fn,
          maxLen: 260,
          pFormat: "%s/pl%02d_slot%d-time%d.wav",
          path,
          v6,
          *(_DWORD *)(v5 + 4),
          (int)v8);
        rate = g_VoiceSampleFormat.nSamplesPerSec;
        EngineTool_OverrideSampleRate(&rate);
        WriteWaveFile(
          pFilename: fn,
          pData: *(const char **)(v5 + 8),
          nBytes: *(_DWORD *)(v5 + 24),
          wBitsPerSample: g_VoiceSampleFormat.wBitsPerSample,
          nChannels: g_VoiceSampleFormat.nChannels,
          nSamplesPerSec: rate);
        _Msg(a1: "Writing file %s\n", fn);
        ++*(_DWORD *)(v5 + 4);
        *(_DWORD *)(v5 + 20) = 0;
        *(_DWORD *)(v5 + 24) = 0;
        *(_DWORD *)(v5 + 40) = 0;
        *(_DWORD *)(v5 + 36) = 0;
        *(_BYTE *)(v5 + 28) = 0;
        if ( *(int *)(v5 + 16) >= 0 )
        {
          if ( *(_DWORD *)(v5 + 8) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v5 + 8));
            *(_DWORD *)(v5 + 8) = 0;
          }
          *(_DWORD *)(v5 + 12) = 0;
        }
        v1 = v12;
      }
    }
  }
  else
  {
    CVoiceWriter::Flush(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054F60
// Name: bool Voice_RecordStop(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Voice_RecordStop()
{
  int rate; // [esp+4h] [ebp-4h] BYREF

  if ( g_pMicInputFileData != nullptr )
  {
    free(pMem: g_pMicInputFileData);
    g_pMicInputFileData = nullptr;
  }
  if ( g_pUncompressedFileData != nullptr )
  {
    rate = g_VoiceSampleFormat.nSamplesPerSec;
    EngineTool_OverrideSampleRate(&rate);
    WriteWaveFile(
      pFilename: g_pUncompressedDataFilename,
      pData: g_pUncompressedFileData,
      nBytes: g_nUncompressedDataBytes,
      wBitsPerSample: g_VoiceSampleFormat.wBitsPerSample,
      nChannels: g_VoiceSampleFormat.nChannels,
      nSamplesPerSec: rate);
    free(pMem: g_pUncompressedFileData);
    g_pUncompressedFileData = nullptr;
  }
  if ( g_pDecompressedFileData != nullptr )
  {
    rate = g_VoiceSampleFormat.nSamplesPerSec;
    EngineTool_OverrideSampleRate(&rate);
    WriteWaveFile(
      pFilename: g_pDecompressedDataFilename,
      pData: g_pDecompressedFileData,
      nBytes: g_nDecompressedDataBytes,
      wBitsPerSample: g_VoiceSampleFormat.wBitsPerSample,
      nChannels: g_VoiceSampleFormat.nChannels,
      nSamplesPerSec: rate);
    free(pMem: g_pDecompressedFileData);
    g_pDecompressedFileData = nullptr;
  }
  CVoiceWriter::Finish(this: &g_VoiceWriter);
  if ( g_pVoiceRecord != nullptr )
    g_pVoiceRecord->RecordStop(this: g_pVoiceRecord);
  if ( g_bVoiceRecording )
    g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -1, a3: 0, a4: false);
  g_bVoiceRecording = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055080
// Name: void VoiceTweak_EndVoiceTweakMode(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VoiceTweak_EndVoiceTweakMode()
{
  if ( g_bInTweakMode )
  {
    g_bInTweakMode = false;
    Voice_RecordStop();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055120
// Name: void Voice_Deinit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Voice_Deinit()
{
  IVoiceCodec **p_m_pVoiceCodec; // esi

  if ( g_bVoiceAtLeastPartiallyInitted && !EngineTool_SuppressDeInit() )
  {
    Voice_EndAllChannels();
    Voice_RecordStop();
    p_m_pVoiceCodec = &g_VoiceChannels[0].m_pVoiceCodec;
    do
    {
      if ( *p_m_pVoiceCodec != nullptr )
      {
        (*p_m_pVoiceCodec)->Release(this: *p_m_pVoiceCodec);
        *p_m_pVoiceCodec = nullptr;
      }
      p_m_pVoiceCodec += 5540;
    }
    while ( (int)p_m_pVoiceCodec < (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[846] );
    if ( g_pEncodeCodec != nullptr )
    {
      g_pEncodeCodec->Release(this: g_pEncodeCodec);
      g_pEncodeCodec = nullptr;
    }
    if ( g_hVoiceCodecDLL != nullptr )
    {
      FileSystem_UnloadModule(pModule: g_hVoiceCodecDLL);
      g_hVoiceCodecDLL = nullptr;
    }
    if ( g_pVoiceRecord != nullptr )
    {
      g_pVoiceRecord->Release(this: g_pVoiceRecord);
      g_pVoiceRecord = nullptr;
    }
    VoiceSE_Term();
    g_bVoiceAtLeastPartiallyInitted = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100551C0
// Name: bool Voice_RecordStart(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Voice_RecordStart(const char *pUncompressedFile, const char *pDecompressedFile, const char *pMicInputFile)
{
  bool result; // al
  int v4; // ecx
  int a; // [esp+0h] [ebp-Ch] BYREF
  int b; // [esp+4h] [ebp-8h] BYREF
  int c; // [esp+8h] [ebp-4h] BYREF

  if ( g_pEncodeCodec == nullptr )
    return false;
  CVoiceWriter::Flush(this: &g_VoiceWriter);
  Voice_RecordStop();
  g_pEncodeCodec->ResetState(this: g_pEncodeCodec);
  if ( pMicInputFile != nullptr )
  {
    ReadWaveFile(
      pFilename: pMicInputFile,
      pData: &g_pMicInputFileData,
      nDataBytes: &g_nMicInputFileBytes,
      wBitsPerSample: &a,
      nChannels: &b,
      nSamplesPerSec: &c);
    g_CurMicInputFileByte = 0;
    g_MicStartTime = _Plat_FloatTime(a1: v4);
  }
  if ( pUncompressedFile != nullptr )
  {
    g_pUncompressedFileData = (char *)MemAlloc_Alloc(nSize: 0x100000u);
    g_nUncompressedDataBytes = 0;
    g_pUncompressedDataFilename = pUncompressedFile;
  }
  if ( pDecompressedFile != nullptr )
  {
    g_pDecompressedFileData = (char *)MemAlloc_Alloc(nSize: 0x100000u);
    g_nDecompressedDataBytes = 0;
    g_pDecompressedDataFilename = pDecompressedFile;
  }
  result = false;
  g_bVoiceRecording = false;
  if ( g_pVoiceRecord != nullptr )
  {
    result = g_pVoiceRecord->RecordStart(this: g_pVoiceRecord);
    g_bVoiceRecording = result;
    if ( result )
    {
      g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -1, a3: 0, a4: true);
      return g_bVoiceRecording;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10055500
// Name: bool Voice_Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall Voice_Init@<al>(int a1@<esi>, const char *pCodecName)
{
  IEngineVGuiInternal *v3; // eax
  IEngineVGuiInternal *v4; // eax
  IEngineVGuiInternal *v5; // eax
  IEngineVGuiInternal *v6; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *(__cdecl *v8)(const char *, int *); // ebx
  IVoiceCodec *v9; // eax
  IVoiceCodec **p_m_pVoiceCodec; // esi
  IEngineVGuiInternal *v11; // eax
  int v12; // eax
  IEngineVGuiInternal *v13; // eax
  int rate; // [esp+0h] [ebp-4h] BYREF

  if ( voice_enable.m_pParent == nullptr )
    return 0;
  if ( voice_enable.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  v3 = EngineVGui();
  v3->UpdateProgressBar(this: v3, a2: PROGRESS_DEFAULT, a3: true);
  Voice_Deinit();
  g_bVoiceAtLeastPartiallyInitted = true;
  if ( !VoiceSE_Init() )
    return 0;
  v4 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *, int, int, int))v4->UpdateProgressBar)(a1: v4, a2: -1, a3: 1, a4: a1);
  rate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(&rate);
  g_pVoiceRecord = CreateVoiceRecord_DSound(sampleRate: rate);
  if ( g_pVoiceRecord == nullptr )
    _Msg(a1: "Unable to initialize DirectSoundCapture. You won't be able to speak to other players.");
  v5 = EngineVGui();
  v5->UpdateProgressBar(this: v5, a2: PROGRESS_DEFAULT, a3: true);
  g_hVoiceCodecDLL = FileSystem_LoadModule(path: pCodecName);
  v6 = EngineVGui();
  v6->UpdateProgressBar(this: v6, a2: PROGRESS_DEFAULT, a3: true);
  if ( g_hVoiceCodecDLL != nullptr
    && (Factory = Sys_GetFactory(pModule: g_hVoiceCodecDLL), v8 = Factory, Factory != nullptr)
    && (v9 = (IVoiceCodec *)Factory(a1: pCodecName, a2: nullptr), g_pEncodeCodec = v9, v9 != nullptr)
    && v9->Init(this: v9, a2: 4) )
  {
    p_m_pVoiceCodec = &g_VoiceChannels[0].m_pVoiceCodec;
    while ( 1 )
    {
      v11 = EngineVGui();
      v11->UpdateProgressBar(this: v11, a2: PROGRESS_DEFAULT, a3: true);
      v12 = (int)v8(a1: pCodecName, a2: nullptr);
      *p_m_pVoiceCodec = (IVoiceCodec *)v12;
      if ( v12 == 0 || (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v12 + 4))(a1: v12, a2: 4) == 0 )
        break;
      p_m_pVoiceCodec += 5540;
      if ( (int)p_m_pVoiceCodec >= (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[846] )
      {
        v13 = EngineVGui();
        v13->UpdateProgressBar(this: v13, a2: PROGRESS_DEFAULT, a3: true);
        InitMixerControls();
        if ( voice_forcemicrecord.m_pParent != nullptr
          && voice_forcemicrecord.m_pParent->m_Value.m_nValue != 0
          && g_pMixerControls != nullptr )
        {
          g_pMixerControls->SelectMicrophoneForWaveInput(this: g_pMixerControls);
        }
        return 1;
      }
    }
  }
  else
  {
    _Msg(a1: "Unable to load voice codec '%s'. Voice disabled.\n", pCodecName);
  }
  Voice_Deinit();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100556B0
// Name: int VoiceTweak_StartVoiceTweakMode(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall VoiceTweak_StartVoiceTweakMode@<eax>(int a1@<esi>)
{
  char *m_pszString; // eax

  if ( g_bInTweakMode )
    return 0;
  if ( g_pMixerControls == nullptr )
  {
    if ( voice_enable.m_pParent == nullptr || voice_enable.m_pParent->m_Value.m_nValue == 0 )
      return 0;
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    Voice_Init(a1, pCodecName: m_pszString);
    if ( g_pMixerControls == nullptr )
      return 0;
  }
  Voice_EndAllChannels();
  if ( g_pEncodeCodec != nullptr )
  {
    CVoiceWriter::Flush(this: &g_VoiceWriter);
    Voice_RecordStop();
    g_pEncodeCodec->ResetState(this: g_pEncodeCodec);
    g_bVoiceRecording = false;
    if ( g_pVoiceRecord != nullptr )
    {
      g_bVoiceRecording = g_pVoiceRecord->RecordStart(this: g_pVoiceRecord);
      if ( g_bVoiceRecording )
        g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: -1, a3: 0, a4: true);
    }
  }
  Voice_AssignChannel(nEntity: -500, bProximity: false, timePadding: 0.2);
  g_bInTweakMode = true;
  InitMixerControls();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100557A0
// Name: void Voice_ForceInit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Voice_ForceInit(int a1@<esi>)
{
  char *m_pszString; // eax

  if ( voice_enable.m_pParent != nullptr && voice_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      Voice_Init(a1, pCodecName: "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
      Voice_Init(a1, pCodecName: m_pszString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100557F0
// Name: float VoiceTweak_GetControlFloat(enum VoiceTweakControl)
// Source: json
//------------------------------------------------------------------------------
double __usercall VoiceTweak_GetControlFloat@<st0>(int a1@<esi>, VoiceTweakControl iControl)
{
  IMixerControls *v2; // ecx
  char *m_pszString; // eax
  double result; // st7
  float flValue; // [esp+0h] [ebp-4h] BYREF

  v2 = g_pMixerControls;
  if ( g_pMixerControls == nullptr )
  {
    if ( voice_enable.m_pParent == nullptr
      || (IMixerControls *)voice_enable.m_pParent->m_Value.m_nValue == g_pMixerControls )
    {
      return 0.0;
    }
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    Voice_Init(a1, pCodecName: m_pszString);
    v2 = g_pMixerControls;
    if ( g_pMixerControls == nullptr )
      return 0.0;
  }
  if ( iControl != MicrophoneVolume )
  {
    if ( iControl == OtherSpeakerScale )
    {
      return voice_scale.m_pParent->m_Value.m_fValue;
    }
    else if ( iControl == SpeakingVolume )
    {
      return (double)g_VoiceTweakSpeakingVolume * 0.000030517578;
    }
    else
    {
      result = 1.0;
      if ( iControl == MicBoost )
      {
        flValue = 1.0;
        v2->GetValue_Float(this: v2, a2: (IMixerControls::Control)0, a3: &flValue);
        return flValue;
      }
    }
  }
  else
  {
    flValue = 1.0;
    v2->GetValue_Float(this: v2, a2: MicVolume, a3: &flValue);
    return flValue;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100558B0
// Name: bool VoiceTweak_IsControlFound(enum VoiceTweakControl)
// Source: json
//------------------------------------------------------------------------------
bool __usercall VoiceTweak_IsControlFound@<al>(int a1@<esi>, VoiceTweakControl iControl)
{
  IMixerControls *v2; // ecx
  char *m_pszString; // eax
  float fDummy; // [esp+0h] [ebp-4h] BYREF

  v2 = g_pMixerControls;
  if ( g_pMixerControls == nullptr )
  {
    if ( voice_enable.m_pParent == nullptr
      || (IMixerControls *)voice_enable.m_pParent->m_Value.m_nValue == g_pMixerControls )
    {
      return false;
    }
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    Voice_Init(a1, pCodecName: m_pszString);
    v2 = g_pMixerControls;
    if ( g_pMixerControls == nullptr )
      return false;
  }
  if ( iControl != MicrophoneVolume )
    return true;
  return v2->GetValue_Float(this: v2, a2: MicVolume, a3: &fDummy);
}

//------------------------------------------------------------------------------
// Address: 0x10055930
// Name: void VoiceEnableCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall VoiceEnableCallback(int a1@<esi>, IConVar *var)
{
  IConVar *v2; // eax
  IConVar_vtbl *v3; // eax
  char *m_pszString; // eax

  if ( var != nullptr )
    v2 = var - 6;
  else
    v2 = nullptr;
  v3 = v2[7].__vftable;
  if ( v3 != nullptr
    && v3[1].GetName != nullptr
    && voice_enable.m_pParent != nullptr
    && voice_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (sv_voicecodec.m_nFlags & 0x1000) != 0 )
    {
      Voice_Init(a1, pCodecName: "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      m_pszString = sv_voicecodec.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
      Voice_Init(a1, pCodecName: m_pszString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055A80
// Name: public: void CVoiceWriter::AddDecompressedData(class CVoiceChannel __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoiceWriter::AddDecompressedData(
        CVoiceWriter *this,
        CVoiceChannel *ch,
        const unsigned __int8 *data,
        unsigned int datalen)
{
  unsigned __int16 v5; // ax
  CVoiceWriterData search; // [esp+4h] [ebp-38h] BYREF

  if ( voice_writevoices.m_pParent != nullptr && voice_writevoices.m_pParent->m_Value.m_nValue != 0 )
  {
    search.m_nCount = 0;
    CUtlBuffer::CUtlBuffer(this: &search.m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
    search.m_pChannel = ch;
    v5 = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::Find(
           this: &this->m_VoiceWriter,
           &search);
    if ( v5 == 0xFFFF )
      v5 = CUtlRBTree<CVoiceWriterData,unsigned short,bool (__cdecl *)(CVoiceWriterData const &,CVoiceWriterData const &),CUtlMemory<UtlRBTreeNode_t<CVoiceWriterData,unsigned short>,unsigned short>>::Insert(
             this: &this->m_VoiceWriter,
             insert: &search);
    CUtlBuffer::Put(this: &this->m_VoiceWriter.m_Elements.m_pMemory[v5].m_Data.m_Buffer, pMem: data, size: datalen);
    if ( search.m_Buffer.m_Memory.m_nGrowSize >= 0 && search.m_Buffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Buffer.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055B20
// Name: int Voice_AddIncomingData(int,char const __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Voice_AddIncomingData(
        unsigned int nChannel,
        __int64 pchData,
        int iSequenceNumber,
        bool isCompressed)
{
  CVoiceChannel *v4; // esi
  __int16 *v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  bool v9; // zf
  char pSamples[8192]; // [esp+1Ch] [ebp-2004h] BYREF
  int rate; // [esp+201Ch] [ebp-4h] BYREF

  if ( !g_bInTweakMode )
  {
    if ( nChannel <= 4 )
      goto LABEL_5;
    return 0;
  }
  if ( nChannel != -100 )
    return 0;
  nChannel = 0;
LABEL_5:
  v4 = &g_VoiceChannels[nChannel];
  if ( v4 == nullptr || isCompressed && v4->m_pVoiceCodec == nullptr )
    return 0;
  v4->m_bStarved = false;
  v5 = (__int16 *)pSamples;
  if ( isCompressed )
  {
    v6 = v4->m_pVoiceCodec->Decompress(
           this: v4->m_pVoiceCodec,
           a2: (const char *)pchData,
           a3: HIDWORD(pchData),
           a4: pSamples,
           a5: 0x2000);
  }
  else
  {
    v5 = (__int16 *)pchData;
    v6 = SHIDWORD(pchData) / 2;
  }
  if ( g_bInTweakMode )
  {
    v7 = 0;
    for ( g_VoiceTweakSpeakingVolume = 0; v7 < v6; ++v7 )
    {
      v8 = abs16(v5[v7]);
      if ( v8 > g_VoiceTweakSpeakingVolume )
        g_VoiceTweakSpeakingVolume = v8;
    }
    g_VoiceTweakSpeakingVolume &= 0xFE00u;
  }
  CAutoGain::ProcessSamples(this: &v4->m_AutoGain, pSamples: v5, nSamples: v6);
  rate = g_VoiceSampleFormat.nSamplesPerSec;
  EngineTool_OverrideSampleRate(&rate);
  v4->m_LastFraction = UpsampleIntoBuffer(
                         pSrc: v5,
                         nSrcSamples: v6,
                         pBuffer: &v4->m_Buffer,
                         startFraction: v4->m_LastFraction,
                         rate: (double)rate * 0.00009070294784580499);
  v9 = g_pDecompressedFileData == nullptr;
  v4->m_LastSample = *((char *)v5 + v6);
  if ( !v9 )
  {
    rate = 2 * v6;
    if ( 2 * v6 >= 0x100000 - g_nDecompressedDataBytes )
      rate = 0x100000 - g_nDecompressedDataBytes;
    memcpy(
      dst: (unsigned __int8 *)&g_pDecompressedFileData[g_nDecompressedDataBytes],
      src: (unsigned __int8 *)v5,
      count: rate);
    g_nDecompressedDataBytes += rate;
  }
  CVoiceWriter::AddDecompressedData(this: &g_VoiceWriter, ch: v4, data: (const unsigned __int8 *)v5, datalen: 2 * v6);
  if ( voice_showincoming.m_pParent != nullptr && voice_showincoming.m_pParent->m_Value.m_nValue != 0 )
    _Msg(a1: "Voice - %d incoming samples added to channel %d owned by entity %d\n", v6, nChannel, v4->m_iEntity);
  return nChannel;
}

//------------------------------------------------------------------------------
// Address: 0x10055CF0
// Name: void Voice_UpdateVoiceTweakMode(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Voice_UpdateVoiceTweakMode(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int CompressedData; // esi
  __int64 v4; // [esp-18h] [ebp-1020h]
  char pchDest[4096]; // [esp+8h] [ebp-1000h] BYREF

  if ( g_bInTweakMode && g_pVoiceRecord != nullptr )
  {
    if ( g_VoiceChannels[0].m_nSoundGuid == -1 || S_IsSoundStillPlaying(guid: g_VoiceChannels[0].m_nSoundGuid) != 0 )
    {
      CompressedData = Voice_GetCompressedData(a1, a2, a3, pchDest, nCount: 4096, bFinal: false);
      if ( CompressedData > 0 )
      {
        g_bInTweakMode = false;
        Voice_AssignChannel(nEntity: -500, bProximity: false, timePadding: 0.2);
        HIDWORD(v4) = CompressedData;
        LODWORD(v4) = pchDest;
        g_bInTweakMode = true;
        Voice_AddIncomingData(nChannel: 0xFFFFFF9C, pchData: v4, iSequenceNumber: 0, isCompressed: true);
      }
    }
    else if ( g_bInTweakMode )
    {
      g_bInTweakMode = false;
      Voice_RecordStop();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055DA0
// Name: bool Voice_Idle(float)
// Source: json
//------------------------------------------------------------------------------
char __usercall Voice_Idle@<al>(int a1@<ecx>, int a2@<edi>, float frametime)
{
  int v3; // ebx
  int v5; // ecx
  double v6; // st7
  int i; // esi
  float v8; // xmm0_4
  ISoundServices *v9; // ecx
  int v10; // eax
  float *p_m_TimePad; // esi
  int v12; // edi
  bool v13; // zf
  vgui::PropertyPage *v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // eax
  int started; // eax
  int v19; // edi
  CVoiceChannel *v20; // esi
  netadrtype_t Available; // eax
  int v22; // [esp+30h] [ebp-1Ch]
  char v23; // [esp+34h] [ebp-18h]
  float fTimeDiffa; // [esp+48h] [ebp-4h]
  int fTimeDiff; // [esp+48h] [ebp-4h]
  float frametimea; // [esp+54h] [ebp+8h]

  v3 = 0;
  if ( voice_enable.m_pParent == nullptr || voice_enable.m_pParent->m_Value.m_nValue == 0 )
  {
    Voice_Deinit();
    return 0;
  }
  v6 = _Plat_FloatTime(a1) - g_fLocalPlayerTalkingLastUpdateRealTime;
  if ( frametime > v6 )
    return 0;
  fTimeDiffa = v6;
  if ( (float)(frametime * 2.0) <= fTimeDiffa )
    frametimea = frametime * 2.0;
  else
    frametimea = v6;
  g_fLocalPlayerTalkingLastUpdateRealTime = _Plat_FloatTime(a1: v5);
  for ( i = 0; i < 2; ++i )
  {
    if ( g_bLocalPlayerTalkingAck[i] )
    {
      v8 = g_LocalPlayerTalkingTimeout[i] + frametimea;
      g_LocalPlayerTalkingTimeout[i] = v8;
      if ( v8 > 0.2 )
      {
        v9 = g_pSoundServices;
        g_bLocalPlayerTalkingAck[i] = false;
        v9->OnChangeVoiceStatus(this: v9, a2: -2, a3: i, a4: false);
      }
    }
  }
  v10 = (int)(float)(voice_fadeouttime.m_pParent->m_Value.m_fValue * 11025.0);
  if ( v10 <= 2 )
    v10 = 2;
  g_nVoiceFadeSamples = v10;
  g_VoiceFadeMul = 1.0 / (float)(v10 - 1);
  if ( g_pVoiceRecord != nullptr )
    g_pVoiceRecord->Idle(this: g_pVoiceRecord);
  Voice_UpdateVoiceTweakMode(a1: 0, a2, a3: i);
  fTimeDiff = 0;
  p_m_TimePad = &g_VoiceChannels[0].m_TimePad;
  do
  {
    if ( *((_DWORD *)p_m_TimePad - 5523) != -1 )
    {
      if ( *((_BYTE *)p_m_TimePad - 2) != 0 )
      {
        v12 = *((_DWORD *)p_m_TimePad - 5523);
        if ( v12 != -1 )
        {
          v13 = *((_BYTE *)p_m_TimePad + 56) == 1;
          *(p_m_TimePad - 5523) = NAN;
          if ( v13 )
            VoiceSE_EndChannel(iChannel: v3, iEntity: v12);
          else
            VoiceSE_EndChannel(iChannel: v3, iEntity: *((_DWORD *)p_m_TimePad + 15));
          g_pSoundServices->OnChangeVoiceStatus(this: g_pSoundServices, a2: v12, a3: -1, a4: false);
          CColorBalanceUIPanel::Init(this: v14);
          p_m_TimePad[15] = NAN;
          p_m_TimePad[16] = NAN;
        }
        p_m_TimePad[16] = NAN;
      }
      else
      {
        v15 = *p_m_TimePad;
        v16 = *p_m_TimePad - frametimea;
        *p_m_TimePad = v16;
        if ( v15 > 0.0 && v16 <= 0.0 )
        {
          v17 = g_pSoundServices->GetViewEntity(this: g_pSoundServices, a2: 0);
          v23 = *((_BYTE *)p_m_TimePad + 56);
          v22 = *((_DWORD *)p_m_TimePad - 5523);
          *((_DWORD *)p_m_TimePad + 15) = v17;
          started = VoiceSE_StartChannel(iChannel: v3, iEntity: v22, bProximity: v23, nViewEntityIndex: v17);
          *((_DWORD *)p_m_TimePad + 16) = started;
          if ( started > 0 )
          {
            g_pSoundServices->OnChangeVoiceStatus(
              this: g_pSoundServices,
              a2: *((_DWORD *)p_m_TimePad - 5523),
              a3: -1,
              a4: true);
            CColorBalanceUIPanel::Init(this: *((vgui::PropertyPage **)p_m_TimePad - 5523));
          }
          else
          {
            Voice_EndChannel(iChannel: v3);
            p_m_TimePad[16] = NAN;
          }
        }
        ++fTimeDiff;
      }
    }
    p_m_TimePad += 5540;
    ++v3;
  }
  while ( (int)p_m_TimePad < (int)&s_LocalNetworkBackdoor.m_EntsChangedIndices[844] );
  if ( fTimeDiff == 0 )
    VoiceSE_EndOverdrive();
  VoiceSE_Idle(frametime: frametimea);
  if ( voice_showchannels.m_pParent != nullptr && voice_showchannels.m_pParent->m_Value.m_nValue >= 1 )
  {
    v19 = 0;
    v20 = g_VoiceChannels;
    do
    {
      if ( v20->m_iEntity != -1 )
      {
        Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v20->m_Buffer);
        _Msg(a1: "Voice - chan %d, ent %d, bufsize: %d\n", v19, v20->m_iEntity, Available);
      }
      ++v20;
      ++v19;
    }
    while ( (int)v20 < (int)&voice_writevoices );
  }
  if ( voice_profile.m_pParent != nullptr && voice_profile.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(
      a1: "Voice - compress: %7.2fu, decompress: %7.2fu, gain: %7.2fu, upsample: %7.2fu, total: %7.2fu\n",
      (double)(g_CompressTime * 1000000.0),
      (double)(g_DecompressTime * 1000000.0),
      (double)(g_GainTime * 1000000.0),
      (double)(g_UpsampleTime * 1000000.0),
      (double)((g_DecompressTime + g_CompressTime + g_GainTime + g_UpsampleTime) * 1000000.0));
    g_UpsampleTime = 0.0;
    g_GainTime = 0.0;
    g_DecompressTime = 0.0;
    g_CompressTime = 0.0;
  }
  return 1;
}

} // namespace engine_xlsp
