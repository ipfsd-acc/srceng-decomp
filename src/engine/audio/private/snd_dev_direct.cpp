// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_dev_direct.cpp
// Functions: 28
// ============================================================

#include "engine\audio\private\snd_dev_direct.h"

//------------------------------------------------------------------------------
// Address: 0x10008870
// Name: public: virtual void CAudioDirectSound::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::Pause(CAudioDirectSound *this)
{
  if ( pDSBuf != nullptr )
    pDSBuf->Stop(this: pDSBuf);
  if ( pDSBufFL != nullptr )
    pDSBufFL->Stop(this: pDSBufFL);
  if ( pDSBufFR != nullptr )
    pDSBufFR->Stop(this: pDSBufFR);
  if ( pDSBufRL != nullptr )
    pDSBufRL->Stop(this: pDSBufRL);
  if ( pDSBufRR != nullptr )
    pDSBufRR->Stop(this: pDSBufRR);
  if ( pDSBufFC != nullptr )
    pDSBufFC->Stop(this: pDSBufFC);
}

//------------------------------------------------------------------------------
// Address: 0x100088E0
// Name: public: virtual void CAudioDirectSound::UnPause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::UnPause(CAudioDirectSound *this)
{
  if ( pDSBuf != nullptr )
    pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufFL != nullptr )
    pDSBufFL->Play(this: pDSBufFL, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufFR != nullptr )
    pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufRL != nullptr )
    pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufRR != nullptr )
    pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufFC != nullptr )
    pDSBufFC->Play(this: pDSBufFC, a2: 0, a3: 0, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10008970
// Name: public: virtual bool CAudioDirectSound::Should3DMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioDirectSound::Should3DMix(CAudioDirectSound *this)
{
  return this->m_bSurround;
}

//------------------------------------------------------------------------------
// Address: 0x10008980
// Name: GetSpeakerConfigForSurroundMode
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall GetSpeakerConfigForSurroundMode@<eax>(int surroundMode@<eax>, const char **pConfigDesc@<edx>)
{
  unsigned int result; // eax
  const char *v3; // ecx

  switch ( surroundMode )
  {
    case 0:
      result = 1;
      v3 = "headphone";
      break;
    case 4:
      result = 3;
      v3 = "quad speaker";
      break;
    case 5:
      result = 6;
      v3 = "5.1 speaker";
      break;
    case 7:
      result = 7;
      v3 = "7.1 speaker";
      break;
    default:
      result = 4;
      v3 = "stereo speaker";
      break;
  }
  if ( pConfigDesc != nullptr )
    *pConfigDesc = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100089F0
// Name: void ReleaseSurround(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseSurround()
{
  if ( pDSBuf3DFL != nullptr )
  {
    pDSBuf3DFL->Release(this: pDSBuf3DFL);
    pDSBuf3DFL = nullptr;
  }
  if ( pDSBuf3DFR != nullptr )
  {
    pDSBuf3DFR->Release(this: pDSBuf3DFR);
    pDSBuf3DFR = nullptr;
  }
  if ( pDSBuf3DRL != nullptr )
  {
    pDSBuf3DRL->Release(this: pDSBuf3DRL);
    pDSBuf3DRL = nullptr;
  }
  if ( pDSBuf3DRR != nullptr )
  {
    pDSBuf3DRR->Release(this: pDSBuf3DRR);
    pDSBuf3DRR = nullptr;
  }
  if ( pDSBufFL != nullptr )
  {
    pDSBufFL->Release(this: pDSBufFL);
    pDSBufFL = nullptr;
  }
  if ( pDSBufFR != nullptr )
  {
    pDSBufFR->Release(this: pDSBufFR);
    pDSBufFR = nullptr;
  }
  if ( pDSBufRL != nullptr )
  {
    pDSBufRL->Release(this: pDSBufRL);
    pDSBufRL = nullptr;
  }
  if ( pDSBufRR != nullptr )
  {
    pDSBufRR->Release(this: pDSBufRR);
    pDSBufRR = nullptr;
  }
  if ( pDSBufFC != nullptr )
  {
    pDSBufFC->Release(this: pDSBufFC);
    pDSBufFC = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008AD0
// Name: void DS3D_SetBufferParams(struct IDirectSound3DBuffer __near *,struct _D3DVECTOR __near *,struct _D3DVECTOR __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DS3D_SetBufferParams(IDirectSound3DBuffer *pDSBuf3D, _D3DVECTOR *pbpos, _D3DVECTOR *pbdir)
{
  float y; // ebx
  float x; // edi
  float v5; // ecx
  float z; // eax
  IDirectSound3DBuffer_vtbl *v7; // ecx
  HRESULT (__stdcall *GetAllParameters)(IDirectSound3DBuffer *, _DS3DBUFFER *); // eax
  IDirectSound3DBuffer_vtbl *v9; // edx
  HRESULT (__stdcall *SetAllParameters)(IDirectSound3DBuffer *, const _DS3DBUFFER *, unsigned int); // ecx
  _DS3DBUFFER bparm; // [esp+0h] [ebp-64h] BYREF
  _D3DVECTOR bpos; // [esp+40h] [ebp-24h]
  _D3DVECTOR bdir; // [esp+4Ch] [ebp-18h]
  _D3DVECTOR bvel; // [esp+58h] [ebp-Ch] BYREF

  y = pbpos->y;
  x = pbpos->x;
  bpos.z = pbpos->z;
  v5 = pbdir->x;
  z = pbdir->z;
  bdir.y = pbdir->y;
  bdir.x = v5;
  v7 = pDSBuf3D->__vftable;
  bdir.z = z;
  GetAllParameters = v7->GetAllParameters;
  memset(&bvel, 0, sizeof(bvel));
  bparm.dwSize = 64;
  GetAllParameters(this: pDSBuf3D, a2: &bparm);
  bparm.vPosition.z = bpos.z;
  bparm.vVelocity = bvel;
  bparm.vConeOrientation.y = bdir.y;
  bparm.vConeOrientation.x = bdir.x;
  v9 = pDSBuf3D->__vftable;
  bparm.vConeOrientation.z = bdir.z;
  SetAllParameters = v9->SetAllParameters;
  bparm.flMinDistance = 100.0;
  bparm.vPosition.x = x;
  bparm.vPosition.y = y;
  bparm.dwInsideConeAngle = 5;
  bparm.dwOutsideConeAngle = 10;
  bparm.lConeOutsideVolume = -10000;
  bparm.flMaxDistance = 1000000000.0;
  bparm.dwMode = 0;
  SetAllParameters(this: pDSBuf3D, a2: &bparm, a3: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10008BA0
// Name: public: virtual char const __near * CAudioDirectSound::DeviceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioDirectSound::DeviceName(CAudioDirectSound *this)
{
  const char *result; // eax

  if ( this->m_bSurroundCenter )
    return "5 Channel Surround";
  result = "4 Channel Surround";
  if ( !this->m_bSurround )
    return "Direct Sound";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008BC0
// Name: private: bool CAudioDirectSound::LockDSBuffer(struct IDirectSoundBuffer __near *,unsigned long __near * __near *,unsigned long __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioDirectSound::LockDSBuffer(
        CAudioDirectSound *this,
        IDirectSoundBuffer *pBuffer,
        void **pdwWriteBuffer,
        unsigned int *pdwSizeBuffer,
        const char *pBufferName,
        unsigned int lockFlags)
{
  HRESULT (__stdcall *Lock)(IDirectSoundBuffer *, unsigned int, unsigned int, void **, unsigned int *, void **, unsigned int *, unsigned int); // edx
  int v10; // eax
  int reps; // [esp+10h] [ebp+8h]

  if ( pBuffer == nullptr )
    return 0;
  Lock = pBuffer->Lock;
  reps = 0;
  v10 = Lock(
          this: pBuffer,
          a2: 0,
          a3: this->m_bufferSizeBytes,
          a4: pdwWriteBuffer,
          a5: pdwSizeBuffer,
          a6: nullptr,
          a7: nullptr,
          a8: lockFlags);
  if ( v10 == 0 )
    return 1;
  while ( 1 )
  {
    if ( v10 != -2005401450 )
    {
      _Msg(a1: "DS::Lock Sound Buffer Failed %s\n", pBufferName);
      return 0;
    }
    if ( ++reps > 10000 )
      break;
    v10 = pBuffer->Lock(
            this: pBuffer,
            a2: 0,
            a3: this->m_bufferSizeBytes,
            a4: pdwWriteBuffer,
            a5: pdwSizeBuffer,
            a6: nullptr,
            a7: nullptr,
            a8: lockFlags);
    if ( v10 == 0 )
      return 1;
  }
  _Msg(a1: "DS:: couldn't restore buffer %s\n", pBufferName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008C80
// Name: private: void CAudioDirectSound::S_TransferSurround16(struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,__int64,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::S_TransferSurround16(
        CAudioDirectSound *this,
        portable_samplepair_t *pfront,
        portable_samplepair_t *prear,
        portable_samplepair_t *pcenter,
        __int64 lpaintedtime,
        __int64 endtime,
        int cchan)
{
  int v8; // edi
  CAudioDirectSound_vtbl *v9; // eax
  int v10; // eax
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // esi
  char *v14; // ebx
  char *v15; // eax
  int *p_right; // ecx
  int v17; // edx
  int v18; // eax
  int *v19; // ecx
  __int16 *v20; // edx
  int v21; // [esp+14h] [ebp-48h]
  int v22; // [esp+1Ch] [ebp-40h]
  __int16 *snd_out_rright; // [esp+20h] [ebp-3Ch]
  __int16 *snd_out_rrighta; // [esp+20h] [ebp-3Ch]
  int sampleMonoCount; // [esp+24h] [ebp-38h]
  unsigned int dwSizeFC; // [esp+28h] [ebp-34h] BYREF
  unsigned int dwSizeRR; // [esp+2Ch] [ebp-30h] BYREF
  unsigned int dwSizeRL; // [esp+30h] [ebp-2Ch] BYREF
  unsigned int dwSizeFR; // [esp+34h] [ebp-28h] BYREF
  unsigned int dwSizeFL; // [esp+38h] [ebp-24h] BYREF
  __int16 *snd_out_fcenter; // [esp+3Ch] [ebp-20h]
  __int16 *snd_out_rleft; // [esp+40h] [ebp-1Ch]
  unsigned int *pdwWriteFC; // [esp+44h] [ebp-18h] BYREF
  unsigned int *pdwWriteRR; // [esp+48h] [ebp-14h] BYREF
  unsigned int *pdwWriteRL; // [esp+4Ch] [ebp-10h] BYREF
  unsigned int *pdwWriteFR; // [esp+50h] [ebp-Ch] BYREF
  unsigned int *pdwWriteFL; // [esp+54h] [ebp-8h] BYREF
  int *snd_cp; // [esp+58h] [ebp-4h]
  portable_samplepair_t *pcentera; // [esp+6Ch] [ebp+10h]

  pdwWriteFL = nullptr;
  pdwWriteFR = nullptr;
  pdwWriteRL = nullptr;
  pdwWriteRR = nullptr;
  dwSizeFL = 0;
  dwSizeFR = 0;
  dwSizeRL = 0;
  dwSizeRR = 0;
  pdwWriteFC = nullptr;
  dwSizeFC = 0;
  snd_out_fcenter = nullptr;
  v8 = (int)(S_GetMasterVolume() * 256.0);
  if ( CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufFL,
         pdwWriteBuffer: (void **)&pdwWriteFL,
         pdwSizeBuffer: &dwSizeFL,
         pBufferName: "FL",
         lockFlags: 0) != 0
    && CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufFR,
         pdwWriteBuffer: (void **)&pdwWriteFR,
         pdwSizeBuffer: &dwSizeFR,
         pBufferName: "FR",
         lockFlags: 0) != 0
    && CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufRL,
         pdwWriteBuffer: (void **)&pdwWriteRL,
         pdwSizeBuffer: &dwSizeRL,
         pBufferName: "RL",
         lockFlags: 0) != 0
    && CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufRR,
         pdwWriteBuffer: (void **)&pdwWriteRR,
         pdwSizeBuffer: &dwSizeRR,
         pBufferName: "RR",
         lockFlags: 0) != 0
    && (cchan != 5
     || CAudioDirectSound::LockDSBuffer(
          this,
          pBuffer: pDSBufFC,
          pdwWriteBuffer: (void **)&pdwWriteFC,
          pdwSizeBuffer: &dwSizeFC,
          pBufferName: "FC",
          lockFlags: 0) != 0) )
  {
    v9 = this->__vftable;
    snd_cp = &pcenter->left;
    v10 = v9->DeviceSampleCount(this);
    sampleMonoCount = v10;
    if ( SHIDWORD(lpaintedtime) <= SHIDWORD(endtime) )
    {
      v11 = lpaintedtime;
      if ( SHIDWORD(lpaintedtime) < SHIDWORD(endtime) || (unsigned int)lpaintedtime < (unsigned int)endtime )
      {
        while ( 1 )
        {
          v12 = (v10 - 1) & v11;
          v13 = v10 - v12;
          if ( v10 - v12 > (__int64)(endtime - __PAIR64__(HIDWORD(lpaintedtime), v11)) )
            v13 = endtime - lpaintedtime;
          v14 = (char *)pdwWriteFL + 2 * v12;
          snd_out_rleft = (__int16 *)pdwWriteRL + v12;
          v15 = (char *)pdwWriteFR + 2 * v12;
          snd_out_rright = (__int16 *)pdwWriteRR + v12;
          if ( cchan == 5 )
            snd_out_fcenter = (__int16 *)pdwWriteFC + v12;
          if ( v13 > 0 )
          {
            pcentera = pfront;
            p_right = &prear->right;
            v21 = (char *)snd_out_rleft - v15;
            v17 = v14 - v15;
            v22 = v14 - v15;
            snd_out_rrighta = (__int16 *)((char *)snd_out_rright - v15);
            snd_out_rleft = (__int16 *)v13;
            while ( 1 )
            {
              *(_WORD *)&v15[v17] = (v8 * pcentera->left) >> 8;
              *(_WORD *)v15 = (v8 * *(int *)((char *)p_right + (char *)pfront - (char *)prear)) >> 8;
              ++pcentera;
              *(_WORD *)&v15[v21] = (v8 * *(p_right - 1)) >> 8;
              *(_WORD *)&v15[(_DWORD)snd_out_rrighta] = (v8 * *p_right) >> 8;
              v15 += 2;
              p_right += 2;
              snd_out_rleft = (__int16 *)((char *)snd_out_rleft - 1);
              if ( snd_out_rleft == nullptr )
                break;
              v17 = v22;
            }
          }
          if ( cchan == 5 )
          {
            v18 = 0;
            if ( v13 > 0 )
            {
              v19 = snd_cp;
              v20 = snd_out_fcenter;
              do
              {
                v20[v18++] = (v8 * *v19) >> 8;
                v19 += 2;
              }
              while ( v18 < v13 );
            }
          }
          pfront += v13;
          prear += v13;
          snd_cp += 2 * v13;
          lpaintedtime += v13;
          if ( lpaintedtime >= endtime )
            break;
          v10 = sampleMonoCount;
          v11 = lpaintedtime;
        }
      }
    }
    pDSBufFL->Unlock(this: pDSBufFL, a2: pdwWriteFL, a3: dwSizeFL, a4: nullptr, a5: 0);
    pDSBufFR->Unlock(this: pDSBufFR, a2: pdwWriteFR, a3: dwSizeFR, a4: nullptr, a5: 0);
    pDSBufRL->Unlock(this: pDSBufRL, a2: pdwWriteRL, a3: dwSizeRL, a4: nullptr, a5: 0);
    pDSBufRR->Unlock(this: pDSBufRR, a2: pdwWriteRR, a3: dwSizeRR, a4: nullptr, a5: 0);
    if ( cchan == 5 )
      pDSBufFC->Unlock(this: pDSBufFC, a2: pdwWriteFC, a3: dwSizeFC, a4: nullptr, a5: 0);
  }
  else
  {
    S_Shutdown();
    S_Startup();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008FA0
// Name: TransferSamplesToSurroundBuffer
// Source: json
//------------------------------------------------------------------------------
void __usercall TransferSamplesToSurroundBuffer(surround_transfer_t *transfer@<esi>, int outputCount)
{
  int v2; // edi
  int v3; // eax
  int channelCount; // ecx
  int v5; // ecx
  int i; // edx
  int v7; // ecx
  int v8; // ecx
  int j; // edx
  int *snd_rp; // ecx
  int v11; // eax
  int *snd_cp; // ecx

  v2 = outputCount;
  v3 = (int)(S_GetMasterVolume() * 256.0);
  channelCount = transfer->channelCount;
  if ( channelCount == 2 )
  {
    if ( outputCount <= 0 )
      goto LABEL_15;
    v5 = 0;
    for ( i = outputCount; i != 0; --i )
    {
      *transfer->pOutput = (v3 * transfer->snd_p[v5]) >> 8;
      transfer->pOutput[1] = (v3 * transfer->snd_p[v5 + 1]) >> 8;
      transfer->pOutput += 2;
      v5 += 2;
    }
LABEL_14:
    v2 = outputCount;
    goto LABEL_15;
  }
  if ( channelCount != 4 )
  {
    if ( outputCount <= 0 )
      goto LABEL_15;
    v8 = 0;
    for ( j = outputCount; j != 0; --j )
    {
      *transfer->pOutput = (v3 * transfer->snd_p[v8]) >> 8;
      transfer->pOutput[1] = (v3 * transfer->snd_p[v8 + 1]) >> 8;
      transfer->pOutput[2] = (v3 * transfer->snd_cp[v8]) >> 8;
      transfer->pOutput[3] = 0;
      transfer->pOutput[4] = (v3 * transfer->snd_rp[v8]) >> 8;
      transfer->pOutput[5] = (v3 * transfer->snd_rp[v8 + 1]) >> 8;
      transfer->pOutput += 6;
      v8 += 2;
    }
    goto LABEL_14;
  }
  if ( outputCount > 0 )
  {
    v7 = 0;
    do
    {
      *transfer->pOutput = (v3 * transfer->snd_p[v7]) >> 8;
      transfer->pOutput[1] = (v3 * transfer->snd_p[v7 + 1]) >> 8;
      transfer->pOutput[2] = (v3 * transfer->snd_rp[v7]) >> 8;
      transfer->pOutput[3] = (v3 * transfer->snd_rp[v7 + 1]) >> 8;
      transfer->pOutput += 4;
      v7 += 2;
      --outputCount;
    }
    while ( outputCount != 0 );
  }
LABEL_15:
  snd_rp = transfer->snd_rp;
  v11 = 2 * v2;
  transfer->snd_p += 2 * v2;
  if ( snd_rp != nullptr )
    transfer->snd_rp = &snd_rp[v11];
  snd_cp = transfer->snd_cp;
  if ( snd_cp != nullptr )
    transfer->snd_cp = &snd_cp[v11];
  transfer->paintedtime += v2;
  transfer->linearCount -= v2;
}

//------------------------------------------------------------------------------
// Address: 0x10009130
// Name: private: void CAudioDirectSound::S_TransferSurround16Interleaved_FullLock(struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::S_TransferSurround16Interleaved_FullLock(
        CAudioDirectSound *this,
        const portable_samplepair_t *pfront,
        const portable_samplepair_t *prear,
        const portable_samplepair_t *pcenter,
        __int64 lpaintedtime,
        __int64 endtime)
{
  double v7; // st7
  CAudioDirectSound_vtbl *v8; // edx
  int v9; // esi
  CAudioDirectSound_vtbl *v10; // edx
  int v11; // ebx
  int v12; // eax
  unsigned int v13; // edx
  int v14; // ecx
  int v15; // edi
  const portable_samplepair_t *v16; // edx
  __int16 *v17; // eax
  int *v18; // ecx
  __int16 *v19; // eax
  int *v20; // ecx
  int v21; // ebx
  const portable_samplepair_t *v22; // edx
  int sampleMonoCount; // [esp+1Ch] [ebp-1Ch]
  unsigned int dwSize; // [esp+20h] [ebp-18h] BYREF
  __int16 *pOutput; // [esp+24h] [ebp-14h]
  int v26; // [esp+28h] [ebp-10h]
  int channelCount; // [esp+2Ch] [ebp-Ch]
  unsigned int *pdwWrite; // [esp+30h] [ebp-8h] BYREF
  int *snd_rp; // [esp+34h] [ebp-4h]
  const portable_samplepair_t *pfronta; // [esp+40h] [ebp+8h]
  const portable_samplepair_t *pfrontb; // [esp+40h] [ebp+8h]

  pdwWrite = nullptr;
  dwSize = 0;
  v7 = S_GetMasterVolume() * 256.0;
  v8 = this->__vftable;
  v9 = (int)v7;
  channelCount = this->m_bSurroundCenter + 4;
  if ( v8->DeviceChannels(this) == 2 )
    channelCount = 2;
  if ( CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBuf,
         pdwWriteBuffer: (void **)&pdwWrite,
         pdwSizeBuffer: &dwSize,
         pBufferName: "DS_INTERLEAVED",
         lockFlags: 0) != 0 )
  {
    v10 = this->__vftable;
    snd_rp = &prear->left;
    v11 = v10->DeviceSampleBytes(this);
    v12 = this->m_bufferSizeBytes / (this->DeviceChannels(this) * v11);
    pOutput = (__int16 *)pdwWrite;
    sampleMonoCount = v12;
    if ( SHIDWORD(lpaintedtime) <= SHIDWORD(endtime) )
    {
      v13 = lpaintedtime;
      if ( SHIDWORD(lpaintedtime) < SHIDWORD(endtime) || (unsigned int)lpaintedtime < (unsigned int)endtime )
      {
        while ( 1 )
        {
          v14 = (v12 - 1) & v13;
          v15 = v12 - v14;
          if ( v12 - v14 > (__int64)(endtime - __PAIR64__(HIDWORD(lpaintedtime), v13)) )
            v15 = endtime - lpaintedtime;
          if ( channelCount == 4 )
          {
            if ( v15 > 0 )
            {
              v16 = pfront;
              v17 = &pOutput[4 * v14 + 2];
              v18 = snd_rp + 1;
              v26 = v15;
              pfronta = (const portable_samplepair_t *)((char *)pfront - (char *)snd_rp);
              do
              {
                *(v17 - 2) = (v9 * v16->left) >> 8;
                *(v17 - 1) = (v9 * *(int *)((char *)v18 + (_DWORD)pfronta)) >> 8;
                *v17 = (v9 * *(v18 - 1)) >> 8;
                v17[1] = (v9 * *v18) >> 8;
                v17 += 4;
                ++v16;
                v18 += 2;
                --v26;
              }
              while ( v26 != 0 );
            }
          }
          else if ( v15 > 0 )
          {
            v19 = &pOutput[6 * v14 + 2];
            v20 = snd_rp + 1;
            v21 = (char *)pfront - (char *)pcenter;
            pfrontb = (const portable_samplepair_t *)((char *)pfront - (char *)snd_rp);
            v22 = pcenter;
            v26 = v15;
            while ( 1 )
            {
              *(v19 - 2) = (v9 * *(int *)((char *)&v22->left + v21)) >> 8;
              *(v19 - 1) = (v9 * *(int *)((char *)&pfrontb->left + (_DWORD)v20)) >> 8;
              *v19 = (v9 * v22->left) >> 8;
              v19[1] = 0;
              v19[2] = (v9 * *(v20 - 1)) >> 8;
              v19[3] = (v9 * *v20) >> 8;
              v19 += 6;
              ++v22;
              v20 += 2;
              if ( --v26 == 0 )
                break;
              v21 = (char *)pfront - (char *)pcenter;
            }
          }
          pfront += v15;
          snd_rp += 2 * v15;
          pcenter += v15;
          lpaintedtime += v15;
          if ( lpaintedtime >= endtime )
            break;
          v12 = sampleMonoCount;
          v13 = lpaintedtime;
        }
      }
    }
    pDSBuf->Unlock(this: pDSBuf, a2: pdwWrite, a3: dwSize, a4: nullptr, a5: 0);
  }
  else
  {
    S_Shutdown();
    S_Startup();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009390
// Name: public: virtual void CAudioDirectSound::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::Shutdown(CAudioDirectSound *this)
{
  IDirectSoundBuffer *v2; // eax

  ReleaseSurround();
  v2 = pDSBuf;
  if ( pDSBuf != nullptr )
  {
    pDSBuf->Stop(this: pDSBuf);
    pDSBuf->Release(this: pDSBuf);
    v2 = pDSBuf;
  }
  if ( pDSPBuf != nullptr && v2 != pDSPBuf )
    pDSPBuf->Release(this: pDSPBuf);
  if ( pDS != nullptr )
  {
    pDS->SetCooperativeLevel(this: pDS, a2: *pmainwindow, a3: 1u);
    pDS->Release(this: pDS);
  }
  pDS = nullptr;
  pDSBuf = nullptr;
  pDSPBuf = nullptr;
  if ( this->m_hInstDS != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hInstDS);
    this->m_hInstDS = nullptr;
  }
  if ( this == CAudioDirectSound::m_pSingleton )
    CAudioDirectSound::m_pSingleton = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009440
// Name: public: virtual int CAudioDirectSound::GetOutputPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDirectSound::GetOutputPosition(CAudioDirectSound *this)
{
  int m_bufferSizeBytes; // edi
  IDirectSoundBuffer *v3; // eax
  signed int m_outputBufferStartOffset; // ecx
  int v5; // edi
  unsigned int dwCurrent; // [esp+8h] [ebp-4h] BYREF

  m_bufferSizeBytes = this->m_bufferSizeBytes;
  if ( !this->m_bSurround || (v3 = pDSBufFL, this->m_isInterleaved) )
    v3 = pDSBuf;
  v3->GetCurrentPosition(this: v3, a2: &dwCurrent, a3: nullptr);
  m_outputBufferStartOffset = this->m_outputBufferStartOffset;
  if ( (int)dwCurrent <= m_outputBufferStartOffset )
    v5 = (int)(dwCurrent - m_outputBufferStartOffset + m_bufferSizeBytes) >> 1;
  else
    v5 = (int)(dwCurrent - m_outputBufferStartOffset) >> 1;
  return v5 / this->DeviceChannels(this);
}

//------------------------------------------------------------------------------
// Address: 0x100094A0
// Name: public: virtual __int64 CAudioDirectSound::PaintBegin(float,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAudioDirectSound::PaintBegin@<eax>(
        CAudioDirectSound *this@<ecx>,
        int a2@<esi>,
        float mixAheadTime,
        __int64 soundtime,
        __int64 lpaintedtime)
{
  __int64 v6; // rax
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  IDirectSoundBuffer *v10; // eax
  __int64 endtime; // [esp+8h] [ebp-Ch]
  unsigned int dwStatus; // [esp+10h] [ebp-4h] BYREF

  v6 = soundtime + (int)(float)((float)this->DeviceDmaSpeed(this) * mixAheadTime);
  endtime = v6;
  if ( v6 > lpaintedtime )
  {
    v7 = this->DeviceSampleCount(this);
    v8 = v7 / this->DeviceChannels(this);
    if ( endtime - soundtime <= v8 )
      v9 = endtime;
    else
      v9 = v8 + soundtime;
    if ( (((_BYTE)v9 - (_BYTE)lpaintedtime) & 3) != 0 )
      v9 -= ((_BYTE)v9 - (_BYTE)lpaintedtime) & 3;
    if ( !this->m_bSurround || this->m_isInterleaved )
    {
      if ( pDSBuf == nullptr )
        goto LABEL_48;
      if ( pDSBuf->GetStatus(this: pDSBuf, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBuf->Restore(this: pDSBuf);
      if ( (dwStatus & 1) != 0 )
        goto LABEL_48;
      v10 = pDSBuf;
    }
    else
    {
      if ( ((int (__stdcall *)(IDirectSoundBuffer *, unsigned int *, int))pDSBufFL->GetStatus)(
             a1: pDSBufFL,
             a2: &dwStatus,
             a3: a2) != 0 )
        _Msg(a1: "Couldn't get SURROUND FL sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufFL->Restore(this: pDSBufFL);
      if ( (dwStatus & 1) == 0 )
        pDSBufFL->Play(this: pDSBufFL, a2: 0, a3: 0, a4: 1u);
      if ( pDSBufFR->GetStatus(this: pDSBufFR, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get SURROUND FR sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufFR->Restore(this: pDSBufFR);
      if ( (dwStatus & 1) == 0 )
        pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
      if ( pDSBufRL->GetStatus(this: pDSBufRL, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get SURROUND RL sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufRL->Restore(this: pDSBufRL);
      if ( (dwStatus & 1) == 0 )
        pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
      if ( ((int (__stdcall *)(IDirectSoundBuffer *))pDSBufRR->GetStatus)(a1: pDSBufRR) != 0 )
        _Msg(a1: "Couldn't get SURROUND RR sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufRR->Restore(this: pDSBufRR);
      if ( (dwStatus & 1) == 0 )
        pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
      if ( !this->m_bSurroundCenter )
        goto LABEL_48;
      if ( pDSBufFC->GetStatus(this: pDSBufFC, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get SURROUND FC sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufFC->Restore(this: pDSBufFC);
      if ( (dwStatus & 1) != 0 )
        goto LABEL_48;
      v10 = pDSBufFC;
    }
    v10->Play(this: v10, a2: 0, a3: 0, a4: 1u);
LABEL_48:
    LODWORD(v6) = v9;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10009730
// Name: public: virtual void CAudioDirectSound::ClearBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::ClearBuffer(CAudioDirectSound *this)
{
  int v1; // ebx
  int v3; // edi
  HRESULT v4; // eax
  int v5; // edi
  HRESULT v6; // eax
  int v7; // edi
  HRESULT v8; // eax
  int v9; // edi
  HRESULT v10; // eax
  int v11; // edi
  HRESULT v12; // eax
  int v13; // edi
  HRESULT v14; // eax
  unsigned int dwSizeRR; // [esp+Ch] [ebp-30h] BYREF
  unsigned int dwSizeRL; // [esp+10h] [ebp-2Ch] BYREF
  unsigned int dwSizeFR; // [esp+14h] [ebp-28h] BYREF
  unsigned int dwSizeFL; // [esp+18h] [ebp-24h] BYREF
  unsigned int *pData; // [esp+1Ch] [ebp-20h] BYREF
  unsigned int dwSize; // [esp+20h] [ebp-1Ch] BYREF
  unsigned int dwSizeFC; // [esp+24h] [ebp-18h] BYREF
  char *pDataRR; // [esp+28h] [ebp-14h] BYREF
  char *pDataRL; // [esp+2Ch] [ebp-10h] BYREF
  char *pDataFR; // [esp+30h] [ebp-Ch] BYREF
  char *pDataFL; // [esp+34h] [ebp-8h] BYREF
  char *pDataFC; // [esp+38h] [ebp-4h] BYREF

  v1 = 0;
  dwSizeFC = 0;
  pDataFC = nullptr;
  if ( !this->m_bSurround || this->m_isInterleaved )
  {
    if ( pDSBuf != nullptr )
    {
      v13 = this->DeviceSampleBits(this) != 8 ? 0 : 128;
      if ( pDSBuf != nullptr )
      {
        v14 = pDSBuf->Lock(
                this: pDSBuf,
                a2: 0,
                a3: this->m_bufferSizeBytes,
                a4: (void **)&pData,
                a5: &dwSize,
                a6: nullptr,
                a7: nullptr,
                a8: 0);
        if ( v14 != 0 )
        {
          while ( 1 )
          {
            if ( v14 != -2005401450 )
            {
              _Msg(a1: "S_ClearBuffer: DS::Lock Sound Buffer Failed\n");
              S_Shutdown();
              return;
            }
            if ( ++v1 > 10000 )
              break;
            v14 = pDSBuf->Lock(
                    this: pDSBuf,
                    a2: 0,
                    a3: this->m_bufferSizeBytes,
                    a4: (void **)&pData,
                    a5: &dwSize,
                    a6: nullptr,
                    a7: nullptr,
                    a8: 0);
            if ( v14 == 0 )
              goto LABEL_49;
          }
          _Msg(a1: "S_ClearBuffer: DS: couldn't restore buffer\n");
          S_Shutdown();
        }
        else
        {
LABEL_49:
          _V_memset(dest: pData, fill: v13, count: dwSize);
          pDSBuf->Unlock(this: pDSBuf, a2: pData, a3: dwSize, a4: nullptr, a5: 0);
        }
      }
    }
  }
  else
  {
    v3 = 0;
    if ( pDSBufFL != nullptr || pDSBufFR != nullptr || pDSBufRL != nullptr || pDSBufRR != nullptr || pDSBufFC != nullptr )
    {
      v4 = pDSBufFL->Lock(
             this: pDSBufFL,
             a2: 0,
             a3: this->m_bufferSizeBytes,
             a4: (void **)&pDataFL,
             a5: &dwSizeFL,
             a6: nullptr,
             a7: nullptr,
             a8: 0);
      if ( v4 != 0 )
      {
        while ( 1 )
        {
          if ( v4 != -2005401450 )
          {
            _Msg(a1: "S_ClearBuffer: DS::Lock FL Sound Buffer Failed\n");
            S_Shutdown();
            return;
          }
          if ( ++v3 > 10000 )
            break;
          v4 = pDSBufFL->Lock(
                 this: pDSBufFL,
                 a2: 0,
                 a3: this->m_bufferSizeBytes,
                 a4: (void **)&pDataFL,
                 a5: &dwSizeFL,
                 a6: nullptr,
                 a7: nullptr,
                 a8: 0);
          if ( v4 == 0 )
            goto LABEL_12;
        }
        _Msg(a1: "S_ClearBuffer: DS: couldn't restore FL buffer\n");
        S_Shutdown();
      }
      else
      {
LABEL_12:
        v5 = 0;
        v6 = pDSBufFR->Lock(
               this: pDSBufFR,
               a2: 0,
               a3: this->m_bufferSizeBytes,
               a4: (void **)&pDataFR,
               a5: &dwSizeFR,
               a6: nullptr,
               a7: nullptr,
               a8: 0);
        if ( v6 != 0 )
        {
          while ( 1 )
          {
            if ( v6 != -2005401450 )
            {
              _Msg(a1: "S_ClearBuffer: DS::Lock FR Sound Buffer Failed\n");
              S_Shutdown();
              return;
            }
            if ( ++v5 > 10000 )
              break;
            v6 = pDSBufFR->Lock(
                   this: pDSBufFR,
                   a2: 0,
                   a3: this->m_bufferSizeBytes,
                   a4: (void **)&pDataFR,
                   a5: &dwSizeFR,
                   a6: nullptr,
                   a7: nullptr,
                   a8: 0);
            if ( v6 == 0 )
              goto LABEL_16;
          }
          _Msg(a1: "S_ClearBuffer: DS: couldn't restore FR buffer\n");
          S_Shutdown();
        }
        else
        {
LABEL_16:
          v7 = 0;
          v8 = pDSBufRL->Lock(
                 this: pDSBufRL,
                 a2: 0,
                 a3: this->m_bufferSizeBytes,
                 a4: (void **)&pDataRL,
                 a5: &dwSizeRL,
                 a6: nullptr,
                 a7: nullptr,
                 a8: 0);
          if ( v8 != 0 )
          {
            while ( 1 )
            {
              if ( v8 != -2005401450 )
              {
                _Msg(a1: "S_ClearBuffer: DS::Lock RL Sound Buffer Failed\n");
                S_Shutdown();
                return;
              }
              if ( ++v7 > 10000 )
                break;
              v8 = pDSBufRL->Lock(
                     this: pDSBufRL,
                     a2: 0,
                     a3: this->m_bufferSizeBytes,
                     a4: (void **)&pDataRL,
                     a5: &dwSizeRL,
                     a6: nullptr,
                     a7: nullptr,
                     a8: 0);
              if ( v8 == 0 )
                goto LABEL_20;
            }
            _Msg(a1: "S_ClearBuffer: DS: couldn't restore RL buffer\n");
            S_Shutdown();
          }
          else
          {
LABEL_20:
            v9 = 0;
            v10 = pDSBufRR->Lock(
                    this: pDSBufRR,
                    a2: 0,
                    a3: this->m_bufferSizeBytes,
                    a4: (void **)&pDataRR,
                    a5: &dwSizeRR,
                    a6: nullptr,
                    a7: nullptr,
                    a8: 0);
            if ( v10 != 0 )
            {
              while ( 1 )
              {
                if ( v10 != -2005401450 )
                {
                  _Msg(a1: "S_ClearBuffer: DS::Lock RR Sound Buffer Failed\n");
                  S_Shutdown();
                  return;
                }
                if ( ++v9 > 10000 )
                  break;
                v10 = pDSBufRR->Lock(
                        this: pDSBufRR,
                        a2: 0,
                        a3: this->m_bufferSizeBytes,
                        a4: (void **)&pDataRR,
                        a5: &dwSizeRR,
                        a6: nullptr,
                        a7: nullptr,
                        a8: 0);
                if ( v10 == 0 )
                  goto LABEL_24;
              }
              _Msg(a1: "S_ClearBuffer: DS: couldn't restore RR buffer\n");
              S_Shutdown();
            }
            else
            {
LABEL_24:
              if ( this->m_bSurroundCenter
                && (v11 = 0,
                    (v12 = pDSBufFC->Lock(
                             this: pDSBufFC,
                             a2: 0,
                             a3: this->m_bufferSizeBytes,
                             a4: (void **)&pDataFC,
                             a5: &dwSizeFC,
                             a6: nullptr,
                             a7: nullptr,
                             a8: 0)) != 0) )
              {
                while ( 1 )
                {
                  if ( v12 != -2005401450 )
                  {
                    _Msg(a1: "S_ClearBuffer: DS::Lock FC Sound Buffer Failed\n");
                    S_Shutdown();
                    return;
                  }
                  if ( ++v11 > 10000 )
                    break;
                  v12 = pDSBufFC->Lock(
                          this: pDSBufFC,
                          a2: 0,
                          a3: this->m_bufferSizeBytes,
                          a4: (void **)&pDataFC,
                          a5: &dwSizeFC,
                          a6: nullptr,
                          a7: nullptr,
                          a8: 0);
                  if ( v12 == 0 )
                    goto LABEL_29;
                }
                _Msg(a1: "S_ClearBuffer: DS: couldn't restore FC buffer\n");
                S_Shutdown();
              }
              else
              {
LABEL_29:
                _V_memset(dest: pDataFL, fill: 0, count: this->m_bufferSizeBytes);
                _V_memset(dest: pDataFR, fill: 0, count: this->m_bufferSizeBytes);
                _V_memset(dest: pDataRL, fill: 0, count: this->m_bufferSizeBytes);
                _V_memset(dest: pDataRR, fill: 0, count: this->m_bufferSizeBytes);
                if ( this->m_bSurroundCenter )
                  _V_memset(dest: pDataFC, fill: 0, count: this->m_bufferSizeBytes);
                pDSBufFL->Unlock(this: pDSBufFL, a2: pDataFL, a3: dwSizeFL, a4: nullptr, a5: 0);
                pDSBufFR->Unlock(this: pDSBufFR, a2: pDataFR, a3: dwSizeFR, a4: nullptr, a5: 0);
                pDSBufRL->Unlock(this: pDSBufRL, a2: pDataRL, a3: dwSizeRL, a4: nullptr, a5: 0);
                pDSBufRR->Unlock(this: pDSBufRR, a2: pDataRR, a3: dwSizeRR, a4: nullptr, a5: 0);
                if ( this->m_bSurroundCenter )
                  pDSBufFC->Unlock(this: pDSBufFC, a2: pDataFC, a3: dwSizeFC, a4: nullptr, a5: 0);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009C20
// Name: GetWindowsSpeakerConfig
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetWindowsSpeakerConfig()
{
  int result; // eax
  unsigned int v1; // eax
  IDirectSound *v2; // [esp-8h] [ebp-Ch]
  unsigned int speaker_config; // [esp+0h] [ebp-4h] BYREF

  if ( windows_speaker_config.m_pParent == nullptr )
    return 0;
  result = windows_speaker_config.m_pParent->m_Value.m_nValue;
  speaker_config = result;
  if ( windows_speaker_config.m_pParent->m_Value.m_nValue < 0 )
  {
    speaker_config = 4;
    v2 = pDS;
    if ( ((int (*)(void))pDS->GetSpeakerConfig)() != 0 )
    {
      v1 = speaker_config;
    }
    else
    {
      v1 = (unsigned __int8)speaker_config;
      speaker_config = (unsigned __int8)speaker_config;
    }
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&windows_speaker_config.IConVar,
      value: v1,
      a2: (unsigned int)v2,
      a3: (int)&speaker_config);
    return speaker_config;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009CC0
// Name: private: void CAudioDirectSound::DetectWindowsSpeakerSetup(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CAudioDirectSound::DetectWindowsSpeakerSetup(CAudioDirectSound *this)
{
  unsigned int WindowsSpeakerConfig; // esi

  WindowsSpeakerConfig = GetWindowsSpeakerConfig();
  switch ( WindowsSpeakerConfig )
  {
    case 1u:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 0);
      break;
    case 3u:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 4);
      break;
    case 6u:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 5);
      break;
    case 7u:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 7);
      break;
    default:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 2);
      break;
  }
  switch ( WindowsSpeakerConfig )
  {
    case 2u:
      DevMsg(a1: "DS:mono configuration detected\n");
      break;
    case 1u:
      DevMsg(a1: "DS:headphone configuration detected\n");
      break;
    case 4u:
      DevMsg(a1: "DS:stereo speaker configuration detected\n");
      break;
    case 3u:
      DevMsg(a1: "DS:quad speaker configuration detected\n");
      break;
    case 5u:
      DevMsg(a1: "DS:surround speaker configuration detected\n");
      break;
    case 6u:
      DevMsg(a1: "DS:5.1 speaker configuration detected\n");
      break;
    case 7u:
      DevMsg(a1: "DS:7.1 speaker configuration detected\n");
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009DB0
// Name: void OnSndSurroundCvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __cdecl OnSndSurroundCvarChanged(IConVar *pVar, const char *pOldString, float flOldValue)
{
  int WindowsSpeakerConfig; // esi
  int SpeakerConfigForSurroundMode; // eax
  ConVarRef var; // [esp+0h] [ebp-Ch] BYREF
  const char *speakerConfigDesc; // [esp+8h] [ebp-4h] BYREF

  if ( pDS != nullptr && flOldValue != -1.0 )
  {
    WindowsSpeakerConfig = GetWindowsSpeakerConfig();
    speakerConfigDesc = defaultValue;
    ConVarRef::ConVarRef(this: &var, pConVar: pVar);
    SpeakerConfigForSurroundMode = GetSpeakerConfigForSurroundMode(
                                     surroundMode: var.m_pConVarState->m_Value.m_nValue,
                                     pConfigDesc: &speakerConfigDesc);
    if ( SpeakerConfigForSurroundMode != WindowsSpeakerConfig )
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&windows_speaker_config.IConVar,
        value: SpeakerConfigForSurroundMode,
        a2: (unsigned int)var.m_pConVar,
        a3: (int)var.m_pConVarState);
      _Msg(a1: "Speaker configuration has been changed to %s.\n", speakerConfigDesc);
      g_pSoundServices->RestartSoundSystem(this: g_pSoundServices);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009E30
// Name: void OnSndVarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnSndVarChanged(IConVar *pVar, const char *pOldString, float flOldValue)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar: pVar);
  if ( var.m_pConVarState->m_Value.m_nValue != (int)flOldValue )
    g_pSoundServices->RestartSoundSystem(this: g_pSoundServices);
}

//------------------------------------------------------------------------------
// Address: 0x10009E70
// Name: public: virtual int CAudioDirectSound::DeviceSampleBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDirectSound::DeviceSampleBytes(CAudioDirectSound *this)
{
  return this->m_deviceSampleBits / 8;
}

//------------------------------------------------------------------------------
// Address: 0x10009EB0
// Name: private: bool CAudioDirectSound::SNDDMA_InitInterleaved(struct IDirectSound __near *,struct tWAVEFORMATEX __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioDirectSound::SNDDMA_InitInterleaved(
        CAudioDirectSound *this,
        IDirectSound *lpDS,
        tWAVEFORMATEX *lpFormat,
        unsigned int channelCount)
{
  unsigned __int16 v5; // di
  unsigned int nSamplesPerSec; // esi
  int v7; // esi
  int nChannels; // eax
  unsigned int v10; // edx
  tWAVEFORMATEX *v11; // edx
  int v12; // [esp-8h] [ebp-60h]
  WAVEFORMATEXTENSIBLE wfx; // [esp+8h] [ebp-50h] BYREF
  _DSBUFFERDESC dsbdesc; // [esp+30h] [ebp-28h] BYREF
  unsigned int dwWrite; // [esp+54h] [ebp-4h] BYREF

  memset(&wfx, 0, sizeof(wfx));
  switch ( channelCount )
  {
    case 2u:
      v5 = 2;
      wfx.dwChannelMask = 3;
      break;
    case 4u:
      v5 = 4;
      wfx.dwChannelMask = 51;
      break;
    case 6u:
      v5 = 6;
      wfx.dwChannelMask = 63;
      break;
    default:
      return 0;
  }
  wfx.Format.wFormatTag = -2;
  nSamplesPerSec = lpFormat->nSamplesPerSec;
  wfx.Format.wBitsPerSample = lpFormat->wBitsPerSample;
  wfx.Format.nBlockAlign = v5 * (wfx.Format.wBitsPerSample >> 3);
  wfx.Format.nAvgBytesPerSec = nSamplesPerSec * wfx.Format.nBlockAlign;
  wfx.Format.cbSize = 22;
  *(_DWORD *)&wfx.SubFormat.Data2 = 0x100000;
  wfx.Samples.wValidBitsPerSample = wfx.Format.wBitsPerSample;
  *(_DWORD *)&wfx.SubFormat.Data4[4] = 1905997824;
  wfx.Format.nChannels = v5;
  wfx.SubFormat.Data1 = 1;
  dsbdesc.dwBufferBytes = channelCount << 14;
  wfx.Format.nSamplesPerSec = nSamplesPerSec;
  *(_DWORD *)wfx.SubFormat.Data4 = -1442840448;
  dsbdesc.dwReserved = 0;
  memset(&dsbdesc.guid3DAlgorithm, 0, sizeof(dsbdesc.guid3DAlgorithm));
  dsbdesc.dwSize = 36;
  dsbdesc.dwFlags = 0;
  dsbdesc.lpwfxFormat = (tWAVEFORMATEX *)&wfx;
  v7 = 0;
  while ( 1 )
  {
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        dsbdesc.dwFlags = 8;
      }
      else if ( v7 == 2 )
      {
        dsbdesc.dwFlags = 0;
      }
    }
    else
    {
      dsbdesc.dwFlags = 4;
    }
    if ( snd_mute_losefocus.m_pParent == nullptr || snd_mute_losefocus.m_pParent->m_Value.m_nValue == 0 )
      dsbdesc.dwFlags |= 0x8000u;
    if ( lpDS->CreateSoundBuffer(this: lpDS, a2: &dsbdesc, a3: &pDSBuf, a4: nullptr) >= 0 )
      break;
    if ( ++v7 >= 3 )
      return 0;
  }
  channelCount = 0;
  lpFormat = nullptr;
  if ( CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBuf,
         pdwWriteBuffer: (void **)&lpFormat,
         pdwSizeBuffer: &channelCount,
         pBufferName: "DS_INTERLEAVED",
         lockFlags: 2u) == 0 )
    return 0;
  nChannels = wfx.Format.nChannels;
  v10 = wfx.Format.nSamplesPerSec;
  this->m_deviceSampleBits = wfx.Format.wBitsPerSample;
  v12 = channelCount;
  this->m_deviceDmaSpeed = v10;
  v11 = lpFormat;
  this->m_deviceChannels = nChannels;
  this->m_bufferSizeBytes = dsbdesc.dwBufferBytes;
  this->m_isInterleaved = true;
  _V_memset(dest: v11, fill: 0, count: v12);
  pDSBuf->Unlock(this: pDSBuf, a2: lpFormat, a3: channelCount, a4: nullptr, a5: 0);
  pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
  pDSBuf->Stop(this: pDSBuf);
  pDSBuf->GetCurrentPosition(this: pDSBuf, a2: &this->m_outputBufferStartOffset, a3: &dwWrite);
  pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0E0
// Name: void OnSndSurroundLegacyChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnSndSurroundLegacyChanged(IConVar *pVar)
{
  int m_nValue; // eax
  bool v2; // zf
  const char *v3; // eax
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  if ( pDS != nullptr && CAudioDirectSound::m_pSingleton != nullptr )
  {
    ConVarRef::ConVarRef(this: &var, pConVar: pVar);
    m_nValue = var.m_pConVarState->m_Value.m_nValue;
    if ( CAudioDirectSound::m_pSingleton->m_isInterleaved == (m_nValue != 0) )
    {
      v2 = m_nValue == 0;
      v3 = "enabled";
      if ( v2 )
        v3 = "disabled";
      _Msg(a1: "Legacy Surround %s.\n", v3);
      g_pSoundServices->RestartSoundSystem(this: g_pSoundServices);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A150
// Name: private: bool CAudioDirectSound::SNDDMA_InitSurround(struct IDirectSound __near *,struct tWAVEFORMATEX __near *,struct _DSBCAPS __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAudioDirectSound::SNDDMA_InitSurround@<al>(
        CAudioDirectSound *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        IDirectSound *lpDS,
        tWAVEFORMATEX *lpFormat,
        _DSBCAPS *lpdsbc,
        int cchan)
{
  IDirectSound *v7; // edi
  tWAVEFORMATEX *v9; // esi
  unsigned int nSamplesPerSec; // ecx
  unsigned int nAvgBytesPerSec; // edx
  int v12; // eax
  IDirectSound_vtbl *v13; // edx
  HRESULT (__stdcall *CreateSoundBuffer)(IDirectSound *, const _DSBUFFERDESC *, IDirectSoundBuffer **, IUnknown *); // ecx
  int v15; // ebx
  _DWORD *v16; // edi
  unsigned int v17; // ecx
  _DSBCAPS *v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // edi
  HRESULT v26; // eax
  int v27; // edi
  HRESULT v28; // eax
  int v29; // edi
  HRESULT v30; // eax
  unsigned int *p_m_outputBufferStartOffset; // esi
  int v33; // [esp+14h] [ebp-A8h]
  int v35; // [esp+18h] [ebp-A4h]
  int v36[16]; // [esp+20h] [ebp-9Ch] BYREF
  _BYTE v37[4]; // [esp+60h] [ebp-5Ch] BYREF
  _DWORD v38[2]; // [esp+64h] [ebp-58h] BYREF
  int v39; // [esp+6Ch] [ebp-50h]
  __int16 v40; // [esp+70h] [ebp-4Ch]
  __int16 v41; // [esp+72h] [ebp-4Ah]
  __int16 v42; // [esp+74h] [ebp-48h]
  int v43; // [esp+78h] [ebp-44h] BYREF
  int v44; // [esp+7Ch] [ebp-40h]
  int v45; // [esp+80h] [ebp-3Ch]
  int v46; // [esp+84h] [ebp-38h]
  _DWORD *v47; // [esp+88h] [ebp-34h]
  int v48; // [esp+8Ch] [ebp-30h]
  int v49; // [esp+90h] [ebp-2Ch]
  int v50; // [esp+94h] [ebp-28h]
  int v51; // [esp+98h] [ebp-24h]
  CAudioDirectSound *v52; // [esp+9Ch] [ebp-20h]
  _D3DVECTOR pbpos; // [esp+A0h] [ebp-1Ch] BYREF
  _D3DVECTOR pbdir; // [esp+ACh] [ebp-10h] BYREF
  unsigned __int8 *dst[2]; // [esp+B8h] [ebp-4h] BYREF

  v7 = lpDS;
  v52 = this;
  dst[0] = nullptr;
  if ( lpDS == nullptr )
    return 0;
  v9 = lpFormat;
  nSamplesPerSec = lpFormat->nSamplesPerSec;
  nAvgBytesPerSec = lpFormat->nAvgBytesPerSec;
  v38[0] = *(_DWORD *)&lpFormat->wFormatTag;
  v12 = *(_DWORD *)&lpFormat->nBlockAlign;
  v41 = HIWORD(v12);
  v40 = HIWORD(v12) >> 3;
  v39 = nAvgBytesPerSec;
  LOWORD(nAvgBytesPerSec) = lpFormat->cbSize;
  v39 = nSamplesPerSec * (HIWORD(v12) >> 3);
  v45 = 0;
  v46 = 0;
  v47 = nullptr;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v42 = nAvgBytesPerSec;
  v38[1] = nSamplesPerSec;
  HIWORD(v38[0]) = 1;
  v43 = 36;
  v44 = 16;
  if ( snd_mute_losefocus.m_pParent == nullptr || snd_mute_losefocus.m_pParent->m_Value.m_nValue == 0 )
    v44 = 32784;
  v13 = lpDS->__vftable;
  v47 = v38;
  CreateSoundBuffer = v13->CreateSoundBuffer;
  v45 = 0x4000;
  if ( CreateSoundBuffer(this: lpDS, a2: (const _DSBUFFERDESC *)&v43, a3: &pDSBufFL, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d front left failed");
LABEL_14:
    ReleaseSurround();
    return 0;
  }
  if ( v7->CreateSoundBuffer(this: v7, a2: (const _DSBUFFERDESC *)&v43, a3: &pDSBufFR, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d front right failed");
    goto LABEL_14;
  }
  if ( v7->CreateSoundBuffer(this: v7, a2: (const _DSBUFFERDESC *)&v43, a3: &pDSBufRL, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d rear left failed");
    goto LABEL_14;
  }
  if ( v7->CreateSoundBuffer(this: v7, a2: (const _DSBUFFERDESC *)&v43, a3: &pDSBufRR, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d rear right failed");
    goto LABEL_14;
  }
  v15 = cchan;
  if ( cchan == 5 && v7->CreateSoundBuffer(this: v7, a2: (const _DSBUFFERDESC *)&v43, a3: &pDSBufFC, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d front center failed");
LABEL_80:
    ReleaseSurround();
    return 0;
  }
  if ( pDSBufFL->QueryInterface(this: pDSBufFL, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DFL) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d front left failed");
    goto LABEL_80;
  }
  if ( pDSBufFR->QueryInterface(this: pDSBufFR, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DFR) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d front right failed");
    goto LABEL_80;
  }
  if ( pDSBufRL->QueryInterface(this: pDSBufRL, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DRL) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d rear left failed");
    goto LABEL_80;
  }
  if ( pDSBufRR->QueryInterface(this: pDSBufRR, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DRR) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d rear right failed");
    goto LABEL_80;
  }
  if ( v15 == 5
    && pDSBufFC->QueryInterface(this: pDSBufFC, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DFC) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d front center failed");
    goto LABEL_80;
  }
  lpFormat = nullptr;
  pDSPBuf->QueryInterface(this: pDSPBuf, a2: &IID_IDirectSound3DListener, a3: (void **)&lpFormat);
  if ( lpFormat == nullptr )
  {
    _Warning(a1: "DS: failed to get 3D listener interface.");
    goto LABEL_80;
  }
  v36[0] = 64;
  (*(void (__stdcall **)(tWAVEFORMATEX *, int *, int, int))(*(_DWORD *)&lpFormat->wFormatTag + 12))(
    a1: lpFormat,
    a2: v36,
    a3: a2,
    a4: a3);
  (*(void (__stdcall **)(tWAVEFORMATEX *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)&lpFormat->wFormatTag
                                                                                                 + 52))(
    a1: lpFormat,
    a2: 0.0,
    a3: 0.0,
    a4: 1.0,
    a5: 0.0,
    a6: 1.0,
    a7: 0.0,
    a8: 0);
  (*(void (__stdcall **)(tWAVEFORMATEX *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)&lpFormat->wFormatTag + 56))(
    a1: lpFormat,
    a2: 0.0,
    a3: 0.0,
    a4: 0.0,
    a5: 0);
  pbpos.x = -1.0;
  pbpos.y = 0.0;
  pbpos.z = 1.0;
  pbdir.x = 1.0;
  pbdir.y = 0.0;
  pbdir.z = -1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DFL, &pbpos, &pbdir);
  pbpos.x = 1.0;
  pbpos.z = 1.0;
  pbpos.y = 0.0;
  pbdir.x = -1.0;
  pbdir.y = 0.0;
  pbdir.z = -1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DFR, &pbpos, &pbdir);
  pbpos.x = -1.0;
  pbpos.z = -1.0;
  pbpos.y = 0.0;
  pbdir.x = 1.0;
  pbdir.y = 0.0;
  pbdir.z = 1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DRL, &pbpos, &pbdir);
  pbpos.x = 1.0;
  pbpos.y = 0.0;
  pbpos.z = -1.0;
  pbdir.x = -1.0;
  pbdir.y = 0.0;
  pbdir.z = 1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DRR, &pbpos, &pbdir);
  if ( v15 == 5 )
  {
    pbpos.x = 0.0;
    pbpos.y = 0.0;
    pbdir.x = 0.0;
    pbdir.y = 0.0;
    pbpos.z = 1.0;
    pbdir.z = -1.0;
    DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DFC, &pbpos, &pbdir);
  }
  (*(void (__stdcall **)(tWAVEFORMATEX *))(*(_DWORD *)&lpFormat->wFormatTag + 68))(a1: lpFormat);
  v16 = &v52->__vftable;
  v52->m_deviceChannels = 1;
  v16[3] = v9->wBitsPerSample;
  v17 = v9->nSamplesPerSec;
  v18 = lpdsbc;
  v16[5] = v17;
  v18->dwFlags = 0;
  v18->dwBufferBytes = 0;
  v18->dwUnlockTransferRate = 0;
  v18->dwPlayCpuOverhead = 0;
  v18->dwSize = 20;
  if ( ((int (__cdecl *)(IDirectSoundBuffer *))pDSBufFL->GetCaps)(a1: pDSBufFL) != 0 )
  {
    _Warning(a1: "DS:GetCaps failed for 3d sound buffer\n");
    goto LABEL_80;
  }
  ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD, _DWORD, int, int, _DSBCAPS *))pDSBufFL->Play)(
    a1: pDSBufFL,
    a2: 0,
    a3: 0,
    a4: 1,
    a5: v33,
    a6: v18);
  pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
  pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
  pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
  if ( v15 == 5 )
    pDSBufFC->Play(this: pDSBufFC, a2: 0, a3: 0, a4: 1u);
  if ( snd_firsttime )
  {
    v19 = (*(int (__thiscall **)(_DWORD *))(*v16 + 112))(a1: v16);
    v20 = (*(int (__thiscall **)(_DWORD *, int))(*v16 + 104))(a1: v16, a2: v19);
    DevMsg(a1: "   %d channel(s)\n   %d bits/sample\n   %d samples/sec\n", v15, v20, v35);
  }
  v16[6] = v18->dwBufferBytes;
  if ( v15 == 5 )
  {
    v21 = 0;
    v22 = ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, unsigned __int8 **, IDirectSound **, _DWORD))pDSBufFC->Lock)(
            a1: pDSBufFC,
            a2: 0,
            a3: v18->dwBufferBytes,
            a4: dst,
            a5: &lpDS,
            a6: 0);
    if ( v22 != 0 )
    {
      while ( 1 )
      {
        if ( v22 != -2005401450 )
        {
          _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed for FC\n");
          goto LABEL_80;
        }
        if ( ++v21 > 10000 )
          break;
        v22 = pDSBufFC->Lock(
                this: pDSBufFC,
                a2: 0,
                a3: v18->dwBufferBytes,
                a4: (void **)dst,
                a5: (unsigned int *)&lpDS,
                a6: nullptr,
                a7: nullptr,
                a8: 0);
        if ( v22 == 0 )
          goto LABEL_43;
      }
      _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer for FC\n");
      goto LABEL_80;
    }
LABEL_43:
    memset(dst: dst[0], value: 0, count: (unsigned int)lpDS);
    ((void (__stdcall *)(IDirectSoundBuffer *, unsigned __int8 *, IDirectSound *, _DWORD, _DWORD, _DWORD, _DWORD))pDSBufFC->Unlock)(
      a1: pDSBufFC,
      a2: dst[0],
      a3: lpDS,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: 0);
  }
  v23 = 0;
  v24 = ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, unsigned __int8 **, IDirectSound **, _DWORD))pDSBufFL->Lock)(
          a1: pDSBufFL,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: dst,
          a5: &lpDS,
          a6: 0);
  if ( v24 != 0 )
  {
    while ( 1 )
    {
      if ( v24 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitSurround: DS::Lock Sound Buffer Failed for 3d FL\n");
        goto LABEL_80;
      }
      if ( ++v23 > 10000 )
        break;
      v24 = pDSBufFL->Lock(
              this: pDSBufFL,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: (void **)dst,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v24 == 0 )
        goto LABEL_48;
    }
    _Warning(a1: "SNDDMA_InitSurround: DS: couldn't restore buffer for 3d FL\n");
    goto LABEL_80;
  }
LABEL_48:
  memset(dst: dst[0], value: 0, count: (unsigned int)lpDS);
  pDSBufFL->Unlock(this: pDSBufFL, a2: dst[0], a3: (unsigned int)lpDS, a4: nullptr, a5: 0);
  v25 = 0;
  v26 = pDSBufFR->Lock(
          this: pDSBufFR,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: (void **)dst,
          a5: (unsigned int *)&lpDS,
          a6: nullptr,
          a7: nullptr,
          a8: 0);
  if ( v26 != 0 )
  {
    while ( 1 )
    {
      if ( v26 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitSurround: DS::Lock Sound Buffer Failed for 3d FR\n");
        goto LABEL_80;
      }
      if ( ++v25 > 10000 )
        break;
      v26 = pDSBufFR->Lock(
              this: pDSBufFR,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: (void **)dst,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v26 == 0 )
        goto LABEL_52;
    }
    _Warning(a1: "SNDDMA_InitSurround: DS: couldn't restore buffer for FR\n");
    goto LABEL_80;
  }
LABEL_52:
  memset(dst: dst[0], value: 0, count: (unsigned int)lpDS);
  pDSBufFR->Unlock(this: pDSBufFR, a2: dst[0], a3: (unsigned int)lpDS, a4: nullptr, a5: 0);
  v27 = 0;
  v28 = pDSBufRL->Lock(
          this: pDSBufRL,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: (void **)dst,
          a5: (unsigned int *)&lpDS,
          a6: nullptr,
          a7: nullptr,
          a8: 0);
  if ( v28 != 0 )
  {
    while ( 1 )
    {
      if ( v28 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed for RL\n");
        goto LABEL_80;
      }
      if ( ++v27 > 10000 )
        break;
      v28 = pDSBufRL->Lock(
              this: pDSBufRL,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: (void **)dst,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v28 == 0 )
        goto LABEL_56;
    }
    _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer for RL\n");
    goto LABEL_80;
  }
LABEL_56:
  memset(dst: dst[0], value: 0, count: (unsigned int)lpDS);
  pDSBufRL->Unlock(this: pDSBufRL, a2: dst[0], a3: (unsigned int)lpDS, a4: nullptr, a5: 0);
  v29 = 0;
  v30 = pDSBufRR->Lock(
          this: pDSBufRR,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: (void **)dst,
          a5: (unsigned int *)&lpDS,
          a6: nullptr,
          a7: nullptr,
          a8: 0);
  if ( v30 != 0 )
  {
    while ( 1 )
    {
      if ( v30 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed for RR\n");
        goto LABEL_80;
      }
      if ( ++v29 > 10000 )
        break;
      v30 = pDSBufRR->Lock(
              this: pDSBufRR,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: (void **)dst,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v30 == 0 )
        goto LABEL_60;
    }
    _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer for RR\n");
    goto LABEL_80;
  }
LABEL_60:
  memset(dst: dst[0], value: 0, count: (unsigned int)lpDS);
  ((void (__stdcall *)(IDirectSoundBuffer *, unsigned __int8 *, IDirectSound *, _DWORD, _DWORD, _DWORD, _DWORD))pDSBufRR->Unlock)(
    a1: pDSBufRR,
    a2: dst[0],
    a3: lpDS,
    a4: 0,
    a5: 0,
    a6: 0,
    a7: 0);
  dst[0] = nullptr;
  pDSBufFL->Stop(this: pDSBufFL);
  pDSBufFR->Stop(this: pDSBufFR);
  pDSBufRL->Stop(this: pDSBufRL);
  pDSBufRR->Stop(this: pDSBufRR);
  if ( v15 == 5 )
    pDSBufFC->Stop(this: pDSBufFC);
  p_m_outputBufferStartOffset = &v52->m_outputBufferStartOffset;
  pDSBufFL->GetCurrentPosition(this: pDSBufFL, a2: &v52->m_outputBufferStartOffset, a3: (unsigned int *)v37);
  pDSBufFR->SetCurrentPosition(this: pDSBufFR, a2: *p_m_outputBufferStartOffset);
  pDSBufRL->SetCurrentPosition(this: pDSBufRL, a2: *p_m_outputBufferStartOffset);
  pDSBufRR->SetCurrentPosition(this: pDSBufRR, a2: *p_m_outputBufferStartOffset);
  if ( v15 == 5 )
    pDSBufFC->SetCurrentPosition(this: pDSBufFC, a2: *p_m_outputBufferStartOffset);
  ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD))pDSBufFL->Play)(a1: pDSBufFL, a2: 0);
  pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
  pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
  pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
  if ( v15 == 5 )
    pDSBufFC->Play(this: pDSBufFC, a2: 0, a3: 0, a4: 1u);
  if ( snd_firsttime )
    _Warning(a1: "3d surround sound initialization successful\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AAC0
// Name: private: void CAudioDirectSound::S_TransferSurround16Interleaved(struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::S_TransferSurround16Interleaved(
        CAudioDirectSound *this,
        portable_samplepair_t *pfront,
        int prear,
        portable_samplepair_t *pcenter,
        __int64 lpaintedtime,
        __int64 endtime)
{
  CAudioDirectSound_vtbl *v7; // edx
  int v8; // esi
  int v9; // eax
  int v10; // esi
  CAudioDirectSound_vtbl *v11; // edx
  int v12; // ebx
  bool v13; // zf
  int v14; // edi
  unsigned int v15; // esi
  unsigned int v16; // edi
  int v17; // ebx
  HRESULT v18; // eax
  portable_samplepair_t *v19; // eax
  surround_transfer_t transfer; // [esp+4h] [ebp-30h] BYREF
  unsigned int size0; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int size1; // [esp+30h] [ebp-4h] BYREF

  if ( pDSBuf != nullptr )
  {
    if ( snd_lockpartial.m_pParent != nullptr && snd_lockpartial.m_pParent->m_Value.m_nValue != 0 )
    {
      transfer.snd_cp = &pcenter->left;
      v7 = this->__vftable;
      transfer.snd_rp = (int *)prear;
      transfer.snd_p = &pfront->left;
      v8 = v7->DeviceSampleCount(this);
      v9 = v8 / this->DeviceChannels(this);
      v10 = lpaintedtime;
      v11 = this->__vftable;
      transfer.paintedtime = lpaintedtime;
      v12 = v9 - 1;
      transfer.linearCount = endtime - lpaintedtime;
      v13 = !this->m_bSurroundCenter;
      transfer.sampleMask = v9 - 1;
      prear = 2 * !v13 + 4;
      if ( v11->DeviceChannels(this) == 2 )
      {
        v14 = 2;
        prear = 2;
      }
      else
      {
        v14 = prear;
      }
      transfer.channelCount = v14;
      v15 = 2 * v14 * (v12 & v10);
      v16 = 2 * transfer.linearCount * v14;
      pfront = nullptr;
      pcenter = nullptr;
      v17 = 0;
      while ( 1 )
      {
        v18 = pDSBuf->Lock(
                this: pDSBuf,
                a2: v15,
                a3: v16,
                a4: (void **)&pfront,
                a5: &size0,
                a6: (void **)&pcenter,
                a7: &size1,
                a8: 0);
        if ( v18 == 0 )
          break;
        if ( v18 == -2005401450 && ++v17 < 10000 )
          continue;
        _Msg(a1: "DS::Lock Sound Buffer Failed\n");
        return;
      }
      if ( pfront != nullptr )
      {
        transfer.pOutput = (__int16 *)pfront;
        TransferSamplesToSurroundBuffer(outputCount: size0 / (2 * prear), &transfer);
      }
      v19 = pcenter;
      if ( pcenter != nullptr )
      {
        transfer.pOutput = (__int16 *)pcenter;
        TransferSamplesToSurroundBuffer(outputCount: size1 / (2 * prear), &transfer);
        v19 = pcenter;
      }
      pDSBuf->Unlock(this: pDSBuf, a2: pfront, a3: size0, a4: v19, a5: size1);
    }
    else
    {
      CAudioDirectSound::S_TransferSurround16Interleaved_FullLock(
        this,
        pfront,
        (const portable_samplepair_t *)prear,
        pcenter,
        lpaintedtime,
        endtime);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC60
// Name: class IAudioDevice __near * Audio_CreateDirectSoundDevice(void)
// Source: json
//------------------------------------------------------------------------------
CAudioDirectSound *__cdecl Audio_CreateDirectSoundDevice()
{
  CAudioDirectSound *v0; // ecx
  CAudioDirectSound *v1; // eax

  v0 = CAudioDirectSound::m_pSingleton;
  if ( CAudioDirectSound::m_pSingleton == nullptr )
  {
    v1 = (CAudioDirectSound *)MemAlloc_Alloc(nSize: 0x28u);
    if ( v1 != nullptr )
    {
      v1->__vftable = (CAudioDirectSound_vtbl *)&CAudioDirectSound::`vftable';
      v0 = v1;
    }
    else
    {
      v0 = nullptr;
    }
    CAudioDirectSound::m_pSingleton = v0;
  }
  if ( v0->Init(this: v0) )
  {
    if ( snd_firsttime )
      DevMsg(a1: "DirectSound initialized\n");
    return CAudioDirectSound::m_pSingleton;
  }
  else
  {
    DevMsg(a1: "DirectSound failed to init\n");
    if ( CAudioDirectSound::m_pSingleton != nullptr )
      ((void (__thiscall *)(CAudioDirectSound *, int))CAudioDirectSound::m_pSingleton->dtr_IAudioDevice)(
        a1: CAudioDirectSound::m_pSingleton,
        a2: 1);
    CAudioDirectSound::m_pSingleton = nullptr;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ACE0
// Name: private: enum sndinitstat CAudioDirectSound::SNDDMA_InitDirect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDirectSound::SNDDMA_InitDirect(CAudioDirectSound *this)
{
  HINSTANCE__ *LibraryA; // eax
  HRESULT (__stdcall *DirectSoundCreate)(LPCGUID, LPDIRECTSOUND *, LPUNKNOWN); // eax
  HRESULT v5; // eax
  int m_nValue; // eax
  int v7; // edi
  int v8; // eax
  int v9; // eax
  char inited; // al
  unsigned int v11; // eax
  char v12; // al
  int v13; // eax
  int wBitsPerSample; // edx
  unsigned int nSamplesPerSec; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  unsigned int dwBufferBytes; // eax
  int v20; // edi
  HRESULT v21; // eax
  int v22; // [esp-Ch] [ebp-E4h]
  int v23; // [esp-8h] [ebp-E0h]
  _DSCAPS dscaps; // [esp+8h] [ebp-D0h] BYREF
  unsigned int dwWrite; // [esp+68h] [ebp-70h] BYREF
  tWAVEFORMATEX pformat; // [esp+6Ch] [ebp-6Ch] BYREF
  _DSBUFFERDESC dsbuf; // [esp+80h] [ebp-58h] BYREF
  _DSBCAPS dsbcaps; // [esp+A4h] [ebp-34h] BYREF
  unsigned int dwSize; // [esp+B8h] [ebp-20h] BYREF
  tWAVEFORMATEX format; // [esp+BCh] [ebp-1Ch] BYREF
  void *lpData; // [esp+D0h] [ebp-8h] BYREF
  bool primary_format_set; // [esp+D7h] [ebp-1h]

  lpData = nullptr;
  primary_format_set = false;
  if ( this->m_hInstDS != nullptr )
  {
    DirectSoundCreate = (HRESULT (__stdcall *)(LPCGUID, LPDIRECTSOUND *, LPUNKNOWN))pDirectSoundCreate;
  }
  else
  {
    LibraryA = LoadLibraryA(lpLibFileName: "dsound.dll");
    this->m_hInstDS = LibraryA;
    if ( LibraryA == nullptr )
    {
      _Warning(a1: "Couldn't load dsound.dll\n");
      return 1;
    }
    DirectSoundCreate = (HRESULT (__stdcall *)(LPCGUID, LPDIRECTSOUND *, LPUNKNOWN))GetProcAddress(
                                                                                      hModule: LibraryA,
                                                                                      lpProcName: "DirectSoundCreate");
    pDirectSoundCreate = (HRESULT (__stdcall *)(_GUID *, IDirectSound **, IUnknown *))DirectSoundCreate;
    if ( DirectSoundCreate == nullptr )
    {
      _Warning(a1: "Couldn't get DS proc addr\n");
      return 1;
    }
  }
  v5 = DirectSoundCreate(pcGuidDevice: nullptr, ppDS: &pDS, pUnkOuter: nullptr);
  if ( v5 == 0 )
  {
    CAudioDirectSound::DetectWindowsSpeakerSetup(this);
    *(_WORD *)&this->m_bSurround = 0;
    this->m_bHeadphone = false;
    this->m_isInterleaved = false;
    if ( snd_surround.m_pParent != nullptr )
      m_nValue = snd_surround.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    switch ( m_nValue )
    {
      case 0:
        this->m_bHeadphone = true;
        goto LABEL_16;
      case 4:
        this->m_bSurround = true;
        v7 = 1;
        break;
      case 5:
      case 7:
        *(_WORD *)&this->m_bSurround = 257;
        v7 = 1;
        break;
      default:
LABEL_16:
        v7 = 2;
        break;
    }
    this->m_deviceChannels = v7;
    this->m_deviceSampleBits = 16;
    this->m_deviceDmaSpeed = 44100;
    _V_memset(dest: &format, fill: 0, count: 18);
    format.wBitsPerSample = this->m_deviceSampleBits;
    format.nBlockAlign = (unsigned __int16)v7 * format.wBitsPerSample / 8;
    format.wFormatTag = 1;
    format.nSamplesPerSec = this->m_deviceDmaSpeed;
    format.nChannels = v7;
    format.cbSize = 0;
    format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;
    _V_memset(dest: &dscaps, fill: 0, count: 96);
    dscaps.dwSize = 96;
    if ( pDS->GetCaps(this: pDS, a2: &dscaps) != 0 )
      _Warning(a1: "Couldn't get DS caps\n");
    if ( (dscaps.dwFlags & 0x20) != 0 )
    {
      _Warning(a1: "No DirectSound driver installed\n");
      this->Shutdown(this);
      return 1;
    }
    if ( pDS->SetCooperativeLevel(this: pDS, a2: *pmainwindow, a3: 3u) != 0 )
      goto LABEL_24;
    _V_memset(dest: (void *)&dsbuf, fill: 0, count: 36);
    dsbuf.dwSize = 36;
    dsbuf.dwFlags = 1;
    if ( snd_legacy_surround.m_pParent != nullptr && snd_legacy_surround.m_pParent->m_Value.m_nValue != 0
      || this->m_bSurround )
    {
      dsbuf.dwFlags = 17;
    }
    dsbuf.dwBufferBytes = 0;
    dsbuf.lpwfxFormat = nullptr;
    _V_memset(dest: &dsbcaps, fill: 0, count: 20);
    dsbcaps.dwSize = 20;
    v8 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-snoforceformat", a3: 0) == 0
      && pDS->CreateSoundBuffer(this: pDS, a2: &dsbuf, a3: &pDSPBuf, a4: nullptr) == 0 )
    {
      pformat = format;
      if ( pDSPBuf->SetFormat(this: pDSPBuf, a2: &pformat) != 0 )
      {
        if ( snd_firsttime )
          DevMsg(a1: "Set primary sound buffer format: no\n");
      }
      else
      {
        if ( snd_firsttime )
          DevMsg(a1: "Set primary sound buffer format: yes\n");
        primary_format_set = true;
      }
    }
    if ( !this->m_bSurround )
      goto LABEL_52;
    this->m_bSurround = false;
    if ( snd_legacy_surround.m_pParent != nullptr
      && snd_legacy_surround.m_pParent->m_Value.m_nValue != 0
      && snd_surround.m_pParent != nullptr )
    {
      v9 = snd_surround.m_pParent->m_Value.m_nValue;
      if ( v9 == 4 )
      {
        inited = CAudioDirectSound::SNDDMA_InitSurround(
                   this,
                   a2: 0,
                   a3: (int)this,
                   lpDS: pDS,
                   lpFormat: &format,
                   lpdsbc: &dsbcaps,
                   cchan: 4);
      }
      else
      {
        if ( v9 != 5 && v9 != 7 )
          goto LABEL_47;
        inited = CAudioDirectSound::SNDDMA_InitSurround(
                   this,
                   a2: 0,
                   a3: (int)this,
                   lpDS: pDS,
                   lpFormat: &format,
                   lpdsbc: &dsbcaps,
                   cchan: 5);
        this->m_bSurroundCenter = inited;
      }
      this->m_bSurround = inited;
    }
LABEL_47:
    if ( this->m_bSurround )
      goto LABEL_74;
    v11 = 6;
    if ( snd_surround.m_pParent == nullptr || snd_surround.m_pParent->m_Value.m_nValue < 5 )
      v11 = 4;
    v12 = CAudioDirectSound::SNDDMA_InitInterleaved(this, lpDS: pDS, lpFormat: &format, channelCount: v11);
    this->m_bSurround = v12;
    if ( v12 != 0 )
      goto LABEL_74;
LABEL_52:
    if ( primary_format_set
      && (v13 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 12))(a1: v13, a2: "-primarysound", a3: 0) != 0) )
    {
      if ( pDS->SetCooperativeLevel(this: pDS, a2: *pmainwindow, a3: 4u) != 0 )
      {
LABEL_24:
        _Warning(a1: "Set coop level failed\n");
LABEL_77:
        this->Shutdown(this);
        return 1;
      }
      _V_memset(dest: &dsbcaps, fill: 0, count: 20);
      dsbcaps.dwSize = 20;
      if ( pDSPBuf->GetCaps(this: pDSPBuf, a2: &dsbcaps) != 0 )
      {
        _Msg(a1: "DS:GetCaps failed\n");
        return 1;
      }
      pDSBuf = pDSPBuf;
      DevMsg(a1: "Using primary sound buffer\n");
    }
    else
    {
      _V_memset(dest: (void *)&dsbuf, fill: 0, count: 36);
      dsbuf.dwSize = 36;
      dsbuf.dwFlags = 8;
      dsbuf.dwBufferBytes = 0x10000;
      dsbuf.lpwfxFormat = &format;
      if ( snd_mute_losefocus.m_pParent == nullptr || snd_mute_losefocus.m_pParent->m_Value.m_nValue == 0 )
        dsbuf.dwFlags = 32776;
      if ( pDS->CreateSoundBuffer(this: pDS, a2: &dsbuf, a3: &pDSBuf, a4: nullptr) != 0 )
      {
        _Warning(a1: "DS:CreateSoundBuffer Failed");
        goto LABEL_77;
      }
      wBitsPerSample = format.wBitsPerSample;
      nSamplesPerSec = format.nSamplesPerSec;
      this->m_deviceChannels = format.nChannels;
      this->m_deviceSampleBits = wBitsPerSample;
      this->m_deviceDmaSpeed = nSamplesPerSec;
      _V_memset(dest: &dsbcaps, fill: 0, count: 20);
      dsbcaps.dwSize = 20;
      if ( pDSBuf->GetCaps(this: pDSBuf, a2: &dsbcaps) != 0 )
      {
        _Warning(a1: "DS:GetCaps failed\n");
        this->Shutdown(this);
        return 1;
      }
      if ( !snd_firsttime )
        goto LABEL_69;
      DevMsg(a1: "Using secondary sound buffer\n");
    }
    if ( snd_firsttime )
    {
      v16 = this->DeviceDmaSpeed(this);
      v17 = ((int (__thiscall *)(CAudioDirectSound *, int))this->DeviceSampleBits)(a1: this, a2: v16);
      v18 = ((int (__thiscall *)(CAudioDirectSound *, int))this->DeviceChannels)(a1: this, a2: v17);
      DevMsg(a1: "   %d channel(s)\n   %d bits/sample\n   %d samples/sec\n", v18, v22, v23);
    }
LABEL_69:
    dwBufferBytes = dsbcaps.dwBufferBytes;
    this->m_bufferSizeBytes = dsbcaps.dwBufferBytes;
    v20 = 0;
    v21 = pDSBuf->Lock(
            this: pDSBuf,
            a2: 0,
            a3: dwBufferBytes,
            a4: &lpData,
            a5: &dwSize,
            a6: nullptr,
            a7: nullptr,
            a8: 0);
    if ( v21 != 0 )
    {
      while ( 1 )
      {
        if ( v21 != -2005401450 )
        {
          _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed\n");
          goto LABEL_77;
        }
        if ( ++v20 > 10000 )
          break;
        v21 = pDSBuf->Lock(
                this: pDSBuf,
                a2: 0,
                a3: this->m_bufferSizeBytes,
                a4: &lpData,
                a5: &dwSize,
                a6: nullptr,
                a7: nullptr,
                a8: 0);
        if ( v21 == 0 )
          goto LABEL_73;
      }
      _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer\n");
      goto LABEL_77;
    }
LABEL_73:
    _V_memset(dest: lpData, fill: 0, count: dwSize);
    pDSBuf->Unlock(this: pDSBuf, a2: lpData, a3: dwSize, a4: nullptr, a5: 0);
    pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
    lpData = nullptr;
    pDSBuf->Stop(this: pDSBuf);
    pDSBuf->GetCurrentPosition(this: pDSBuf, a2: &this->m_outputBufferStartOffset, a3: &dwWrite);
    pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
LABEL_74:
    this->m_deviceSampleCount = this->m_bufferSizeBytes / this->DeviceSampleBytes(this);
    return 0;
  }
  if ( v5 == -2005401590 )
    return 2;
  DevMsg(a1: "DirectSound create failed\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B370
// Name: public: virtual void CAudioDirectSound::TransferSamples(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::TransferSamples(CAudioDirectSound *this, __int64 end)
{
  unsigned int v2; // ebx
  unsigned int v4; // edi
  unsigned int dwSize; // [esp+Ch] [ebp-8h] BYREF
  unsigned int *pBuffer; // [esp+10h] [ebp-4h] BYREF

  v2 = HIDWORD(g_paintedtime);
  v4 = g_paintedtime;
  if ( this->m_bSurround )
  {
    if ( this->m_isInterleaved )
      CAudioDirectSound::S_TransferSurround16Interleaved(
        this,
        pfront: g_curpaintbuffer,
        prear: g_currearpaintbuffer,
        pcenter: g_curcenterpaintbuffer,
        lpaintedtime: g_paintedtime,
        endtime: end);
    else
      CAudioDirectSound::S_TransferSurround16(
        this,
        pfront: g_curpaintbuffer,
        prear: g_currearpaintbuffer,
        pcenter: g_curcenterpaintbuffer,
        lpaintedtime: g_paintedtime,
        endtime: end,
        cchan: this->m_bSurroundCenter + 4);
  }
  else if ( snd_lockpartial.m_pParent != nullptr
         && snd_lockpartial.m_pParent->m_Value.m_nValue != 0
         && this->DeviceChannels(this) == 2
         && this->DeviceSampleBits(this) == 16
         && !SND_IsRecording() )
  {
    CAudioDirectSound::S_TransferSurround16Interleaved(
      this,
      pfront: g_curpaintbuffer,
      prear: nullptr,
      pcenter: nullptr,
      lpaintedtime: __SPAIR64__(v2, v4),
      endtime: end);
  }
  else
  {
    pBuffer = nullptr;
    dwSize = 0;
    if ( CAudioDirectSound::LockDSBuffer(
           this,
           pBuffer: pDSBuf,
           pdwWriteBuffer: &pBuffer,
           pdwSizeBuffer: &dwSize,
           pBufferName: "DS_STEREO",
           lockFlags: 0) )
    {
      if ( pBuffer != nullptr )
      {
        if ( this->DeviceChannels(this) == 2 && this->DeviceSampleBits(this) == 16 )
          S_TransferStereo16(
            pOutput: pBuffer,
            pfront: g_curpaintbuffer,
            lpaintedtime: __SPAIR64__(v2, v4),
            endtime: end);
        else
          S_TransferPaintBuffer(
            pOutput: pBuffer,
            pfront: g_curpaintbuffer,
            lpaintedtime: __SPAIR64__(v2, v4),
            endtime: end);
        pDSBuf->Unlock(this: pDSBuf, a2: pBuffer, a3: dwSize, a4: nullptr, a5: 0);
      }
    }
    else
    {
      S_Shutdown();
      S_Startup();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B510
// Name: public: virtual bool CAudioDirectSound::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioDirectSound::Init(CAudioDirectSound *this)
{
  bool v1; // zf

  v1 = !first;
  this->m_hInstDS = nullptr;
  if ( !v1 )
  {
    ConVar::InstallChangeCallback(this: &snd_surround, callback: OnSndSurroundCvarChanged, bInvoke: true);
    ConVar::InstallChangeCallback(this: &snd_legacy_surround, callback: OnSndSurroundLegacyChanged, bInvoke: true);
    ConVar::InstallChangeCallback(this: &snd_mute_losefocus, callback: OnSndVarChanged, bInvoke: true);
    first = false;
  }
  if ( CAudioDirectSound::SNDDMA_InitDirect(this) != SIS_SUCCESS )
    return 0;
  if ( g_pBIK != nullptr )
    g_pBIK->SetDirectSoundDevice(this: g_pBIK, a2: pDS);
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10008830
// Name: public: virtual void CAudioDirectSound::Pause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::Pause(CAudioDirectSound *this)
{
  if ( pDSBuf != nullptr )
    pDSBuf->Stop(this: pDSBuf);
  if ( pDSBufFL != nullptr )
    pDSBufFL->Stop(this: pDSBufFL);
  if ( pDSBufFR != nullptr )
    pDSBufFR->Stop(this: pDSBufFR);
  if ( pDSBufRL != nullptr )
    pDSBufRL->Stop(this: pDSBufRL);
  if ( pDSBufRR != nullptr )
    pDSBufRR->Stop(this: pDSBufRR);
  if ( pDSBufFC != nullptr )
    pDSBufFC->Stop(this: pDSBufFC);
}

//------------------------------------------------------------------------------
// Address: 0x100088A0
// Name: public: virtual void CAudioDirectSound::UnPause(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::UnPause(CAudioDirectSound *this)
{
  if ( pDSBuf != nullptr )
    pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufFL != nullptr )
    pDSBufFL->Play(this: pDSBufFL, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufFR != nullptr )
    pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufRL != nullptr )
    pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufRR != nullptr )
    pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
  if ( pDSBufFC != nullptr )
    pDSBufFC->Play(this: pDSBufFC, a2: 0, a3: 0, a4: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10008940
// Name: public: virtual bool CAudioDirectSound::Should3DMix(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioDirectSound::Should3DMix(CAudioDirectSound *this)
{
  return this->m_bSurround;
}

//------------------------------------------------------------------------------
// Address: 0x10008950
// Name: GetSpeakerConfigForSurroundMode
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall GetSpeakerConfigForSurroundMode@<eax>(int surroundMode@<eax>, const char **pConfigDesc@<edx>)
{
  unsigned int result; // eax
  const char *v3; // ecx

  switch ( surroundMode )
  {
    case 0:
      result = 1;
      v3 = "headphone";
      break;
    case 4:
      result = 3;
      v3 = "quad speaker";
      break;
    case 5:
      result = 6;
      v3 = "5.1 speaker";
      break;
    case 7:
      result = 7;
      v3 = "7.1 speaker";
      break;
    default:
      result = 4;
      v3 = "stereo speaker";
      break;
  }
  if ( pConfigDesc != nullptr )
    *pConfigDesc = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100089C0
// Name: void ReleaseSurround(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseSurround()
{
  if ( pDSBuf3DFL != nullptr )
  {
    pDSBuf3DFL->Release(this: pDSBuf3DFL);
    pDSBuf3DFL = nullptr;
  }
  if ( pDSBuf3DFR != nullptr )
  {
    pDSBuf3DFR->Release(this: pDSBuf3DFR);
    pDSBuf3DFR = nullptr;
  }
  if ( pDSBuf3DRL != nullptr )
  {
    pDSBuf3DRL->Release(this: pDSBuf3DRL);
    pDSBuf3DRL = nullptr;
  }
  if ( pDSBuf3DRR != nullptr )
  {
    pDSBuf3DRR->Release(this: pDSBuf3DRR);
    pDSBuf3DRR = nullptr;
  }
  if ( pDSBufFL != nullptr )
  {
    pDSBufFL->Release(this: pDSBufFL);
    pDSBufFL = nullptr;
  }
  if ( pDSBufFR != nullptr )
  {
    pDSBufFR->Release(this: pDSBufFR);
    pDSBufFR = nullptr;
  }
  if ( pDSBufRL != nullptr )
  {
    pDSBufRL->Release(this: pDSBufRL);
    pDSBufRL = nullptr;
  }
  if ( pDSBufRR != nullptr )
  {
    pDSBufRR->Release(this: pDSBufRR);
    pDSBufRR = nullptr;
  }
  if ( pDSBufFC != nullptr )
  {
    pDSBufFC->Release(this: pDSBufFC);
    pDSBufFC = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008AA0
// Name: void DS3D_SetBufferParams(struct IDirectSound3DBuffer __near *,struct _D3DVECTOR __near *,struct _D3DVECTOR __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DS3D_SetBufferParams(IDirectSound3DBuffer *pDSBuf3D, _D3DVECTOR *pbpos, _D3DVECTOR *pbdir)
{
  float y; // ebx
  float x; // edi
  float v5; // ecx
  float z; // eax
  IDirectSound3DBuffer_vtbl *v7; // ecx
  HRESULT (__stdcall *GetAllParameters)(IDirectSound3DBuffer *, _DS3DBUFFER *); // eax
  IDirectSound3DBuffer_vtbl *v9; // edx
  HRESULT (__stdcall *SetAllParameters)(IDirectSound3DBuffer *, const _DS3DBUFFER *, unsigned int); // ecx
  _DS3DBUFFER bparm; // [esp+0h] [ebp-64h] BYREF
  _D3DVECTOR bpos; // [esp+40h] [ebp-24h]
  _D3DVECTOR bdir; // [esp+4Ch] [ebp-18h]
  _D3DVECTOR bvel; // [esp+58h] [ebp-Ch] BYREF

  y = pbpos->y;
  x = pbpos->x;
  bpos.z = pbpos->z;
  v5 = pbdir->x;
  z = pbdir->z;
  bdir.y = pbdir->y;
  bdir.x = v5;
  v7 = pDSBuf3D->__vftable;
  bdir.z = z;
  GetAllParameters = v7->GetAllParameters;
  memset(&bvel, 0, sizeof(bvel));
  bparm.dwSize = 64;
  GetAllParameters(this: pDSBuf3D, a2: &bparm);
  bparm.vPosition.z = bpos.z;
  bparm.vVelocity = bvel;
  bparm.vConeOrientation.y = bdir.y;
  bparm.vConeOrientation.x = bdir.x;
  v9 = pDSBuf3D->__vftable;
  bparm.vConeOrientation.z = bdir.z;
  SetAllParameters = v9->SetAllParameters;
  bparm.flMinDistance = 100.0;
  bparm.vPosition.x = x;
  bparm.vPosition.y = y;
  bparm.dwInsideConeAngle = 5;
  bparm.dwOutsideConeAngle = 10;
  bparm.lConeOutsideVolume = -10000;
  bparm.flMaxDistance = 1000000000.0;
  bparm.dwMode = 0;
  SetAllParameters(this: pDSBuf3D, a2: &bparm, a3: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10008B70
// Name: public: virtual char const __near * CAudioDirectSound::DeviceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAudioDirectSound::DeviceName(CAudioDirectSound *this)
{
  const char *result; // eax

  if ( this->m_bSurroundCenter )
    return "5 Channel Surround";
  result = "4 Channel Surround";
  if ( !this->m_bSurround )
    return "Direct Sound";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008B90
// Name: private: bool CAudioDirectSound::LockDSBuffer(struct IDirectSoundBuffer __near *,unsigned long __near * __near *,unsigned long __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioDirectSound::LockDSBuffer(
        CAudioDirectSound *this,
        IDirectSoundBuffer *pBuffer,
        void **pdwWriteBuffer,
        unsigned int *pdwSizeBuffer,
        const char *pBufferName,
        unsigned int lockFlags)
{
  HRESULT (__stdcall *Lock)(IDirectSoundBuffer *, unsigned int, unsigned int, void **, unsigned int *, void **, unsigned int *, unsigned int); // edx
  int v10; // eax
  int reps; // [esp+10h] [ebp+8h]

  if ( pBuffer == nullptr )
    return 0;
  Lock = pBuffer->Lock;
  reps = 0;
  v10 = Lock(
          this: pBuffer,
          a2: 0,
          a3: this->m_bufferSizeBytes,
          a4: pdwWriteBuffer,
          a5: pdwSizeBuffer,
          a6: nullptr,
          a7: nullptr,
          a8: lockFlags);
  if ( v10 == 0 )
    return 1;
  while ( 1 )
  {
    if ( v10 != -2005401450 )
    {
      _Msg(a1: "DS::Lock Sound Buffer Failed %s\n", pBufferName);
      return 0;
    }
    if ( ++reps > 10000 )
      break;
    v10 = pBuffer->Lock(
            this: pBuffer,
            a2: 0,
            a3: this->m_bufferSizeBytes,
            a4: pdwWriteBuffer,
            a5: pdwSizeBuffer,
            a6: nullptr,
            a7: nullptr,
            a8: lockFlags);
    if ( v10 == 0 )
      return 1;
  }
  _Msg(a1: "DS:: couldn't restore buffer %s\n", pBufferName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008C50
// Name: private: void CAudioDirectSound::S_TransferSurround16(struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,struct portable_samplepair_t __near *,__int64,__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::S_TransferSurround16(
        CAudioDirectSound *this,
        portable_samplepair_t *pfront,
        portable_samplepair_t *prear,
        portable_samplepair_t *pcenter,
        __int64 lpaintedtime,
        __int64 endtime,
        int cchan)
{
  int v8; // edi
  CAudioDirectSound_vtbl *v9; // eax
  int v10; // eax
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // esi
  char *v14; // ebx
  char *v15; // eax
  int *p_right; // ecx
  int v17; // edx
  int v18; // eax
  int *v19; // ecx
  __int16 *v20; // edx
  int v21; // [esp+14h] [ebp-48h]
  int v22; // [esp+1Ch] [ebp-40h]
  __int16 *snd_out_rright; // [esp+20h] [ebp-3Ch]
  __int16 *snd_out_rrighta; // [esp+20h] [ebp-3Ch]
  int sampleMonoCount; // [esp+24h] [ebp-38h]
  unsigned int dwSizeFC; // [esp+28h] [ebp-34h] BYREF
  unsigned int dwSizeRR; // [esp+2Ch] [ebp-30h] BYREF
  unsigned int dwSizeRL; // [esp+30h] [ebp-2Ch] BYREF
  unsigned int dwSizeFR; // [esp+34h] [ebp-28h] BYREF
  unsigned int dwSizeFL; // [esp+38h] [ebp-24h] BYREF
  __int16 *snd_out_fcenter; // [esp+3Ch] [ebp-20h]
  __int16 *snd_out_rleft; // [esp+40h] [ebp-1Ch]
  unsigned int *pdwWriteFC; // [esp+44h] [ebp-18h] BYREF
  unsigned int *pdwWriteRR; // [esp+48h] [ebp-14h] BYREF
  unsigned int *pdwWriteRL; // [esp+4Ch] [ebp-10h] BYREF
  unsigned int *pdwWriteFR; // [esp+50h] [ebp-Ch] BYREF
  unsigned int *pdwWriteFL; // [esp+54h] [ebp-8h] BYREF
  int *snd_cp; // [esp+58h] [ebp-4h]
  portable_samplepair_t *pcentera; // [esp+6Ch] [ebp+10h]

  pdwWriteFL = nullptr;
  pdwWriteFR = nullptr;
  pdwWriteRL = nullptr;
  pdwWriteRR = nullptr;
  dwSizeFL = 0;
  dwSizeFR = 0;
  dwSizeRL = 0;
  dwSizeRR = 0;
  pdwWriteFC = nullptr;
  dwSizeFC = 0;
  snd_out_fcenter = nullptr;
  v8 = (int)(S_GetMasterVolume() * 256.0);
  if ( CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufFL,
         pdwWriteBuffer: (void **)&pdwWriteFL,
         pdwSizeBuffer: &dwSizeFL,
         pBufferName: "FL",
         lockFlags: 0) != 0
    && CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufFR,
         pdwWriteBuffer: (void **)&pdwWriteFR,
         pdwSizeBuffer: &dwSizeFR,
         pBufferName: "FR",
         lockFlags: 0) != 0
    && CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufRL,
         pdwWriteBuffer: (void **)&pdwWriteRL,
         pdwSizeBuffer: &dwSizeRL,
         pBufferName: "RL",
         lockFlags: 0) != 0
    && CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBufRR,
         pdwWriteBuffer: (void **)&pdwWriteRR,
         pdwSizeBuffer: &dwSizeRR,
         pBufferName: "RR",
         lockFlags: 0) != 0
    && (cchan != 5
     || CAudioDirectSound::LockDSBuffer(
          this,
          pBuffer: pDSBufFC,
          pdwWriteBuffer: (void **)&pdwWriteFC,
          pdwSizeBuffer: &dwSizeFC,
          pBufferName: "FC",
          lockFlags: 0) != 0) )
  {
    v9 = this->__vftable;
    snd_cp = &pcenter->left;
    v10 = v9->DeviceSampleCount(this);
    sampleMonoCount = v10;
    if ( SHIDWORD(lpaintedtime) <= SHIDWORD(endtime) )
    {
      v11 = lpaintedtime;
      if ( SHIDWORD(lpaintedtime) < SHIDWORD(endtime) || (unsigned int)lpaintedtime < (unsigned int)endtime )
      {
        while ( 1 )
        {
          v12 = (v10 - 1) & v11;
          v13 = v10 - v12;
          if ( v10 - v12 > (__int64)(endtime - __PAIR64__(HIDWORD(lpaintedtime), v11)) )
            v13 = endtime - lpaintedtime;
          v14 = (char *)pdwWriteFL + 2 * v12;
          snd_out_rleft = (__int16 *)pdwWriteRL + v12;
          v15 = (char *)pdwWriteFR + 2 * v12;
          snd_out_rright = (__int16 *)pdwWriteRR + v12;
          if ( cchan == 5 )
            snd_out_fcenter = (__int16 *)pdwWriteFC + v12;
          if ( v13 > 0 )
          {
            pcentera = pfront;
            p_right = &prear->right;
            v21 = (char *)snd_out_rleft - v15;
            v17 = v14 - v15;
            v22 = v14 - v15;
            snd_out_rrighta = (__int16 *)((char *)snd_out_rright - v15);
            snd_out_rleft = (__int16 *)v13;
            while ( 1 )
            {
              *(_WORD *)&v15[v17] = (v8 * pcentera->left) >> 8;
              *(_WORD *)v15 = (v8 * *(int *)((char *)p_right + (char *)pfront - (char *)prear)) >> 8;
              ++pcentera;
              *(_WORD *)&v15[v21] = (v8 * *(p_right - 1)) >> 8;
              *(_WORD *)&v15[(_DWORD)snd_out_rrighta] = (v8 * *p_right) >> 8;
              v15 += 2;
              p_right += 2;
              snd_out_rleft = (__int16 *)((char *)snd_out_rleft - 1);
              if ( snd_out_rleft == nullptr )
                break;
              v17 = v22;
            }
          }
          if ( cchan == 5 )
          {
            v18 = 0;
            if ( v13 > 0 )
            {
              v19 = snd_cp;
              v20 = snd_out_fcenter;
              do
              {
                v20[v18++] = (v8 * *v19) >> 8;
                v19 += 2;
              }
              while ( v18 < v13 );
            }
          }
          pfront += v13;
          prear += v13;
          snd_cp += 2 * v13;
          lpaintedtime += v13;
          if ( lpaintedtime >= endtime )
            break;
          v10 = sampleMonoCount;
          v11 = lpaintedtime;
        }
      }
    }
    pDSBufFL->Unlock(this: pDSBufFL, a2: pdwWriteFL, a3: dwSizeFL, a4: nullptr, a5: 0);
    pDSBufFR->Unlock(this: pDSBufFR, a2: pdwWriteFR, a3: dwSizeFR, a4: nullptr, a5: 0);
    pDSBufRL->Unlock(this: pDSBufRL, a2: pdwWriteRL, a3: dwSizeRL, a4: nullptr, a5: 0);
    pDSBufRR->Unlock(this: pDSBufRR, a2: pdwWriteRR, a3: dwSizeRR, a4: nullptr, a5: 0);
    if ( cchan == 5 )
      pDSBufFC->Unlock(this: pDSBufFC, a2: pdwWriteFC, a3: dwSizeFC, a4: nullptr, a5: 0);
  }
  else
  {
    S_Shutdown();
    S_Startup();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008F70
// Name: TransferSamplesToSurroundBuffer
// Source: json
//------------------------------------------------------------------------------
void __usercall TransferSamplesToSurroundBuffer(surround_transfer_t *transfer@<esi>, int outputCount)
{
  int v2; // edi
  int v3; // eax
  int channelCount; // ecx
  int v5; // ecx
  int i; // edx
  int v7; // ecx
  int v8; // ecx
  int j; // edx
  int *snd_rp; // ecx
  int v11; // eax
  int *snd_cp; // ecx

  v2 = outputCount;
  v3 = (int)(S_GetMasterVolume() * 256.0);
  channelCount = transfer->channelCount;
  if ( channelCount == 2 )
  {
    if ( outputCount <= 0 )
      goto LABEL_15;
    v5 = 0;
    for ( i = outputCount; i != 0; --i )
    {
      *transfer->pOutput = (v3 * transfer->snd_p[v5]) >> 8;
      transfer->pOutput[1] = (v3 * transfer->snd_p[v5 + 1]) >> 8;
      transfer->pOutput += 2;
      v5 += 2;
    }
LABEL_14:
    v2 = outputCount;
    goto LABEL_15;
  }
  if ( channelCount != 4 )
  {
    if ( outputCount <= 0 )
      goto LABEL_15;
    v8 = 0;
    for ( j = outputCount; j != 0; --j )
    {
      *transfer->pOutput = (v3 * transfer->snd_p[v8]) >> 8;
      transfer->pOutput[1] = (v3 * transfer->snd_p[v8 + 1]) >> 8;
      transfer->pOutput[2] = (v3 * transfer->snd_cp[v8]) >> 8;
      transfer->pOutput[3] = 0;
      transfer->pOutput[4] = (v3 * transfer->snd_rp[v8]) >> 8;
      transfer->pOutput[5] = (v3 * transfer->snd_rp[v8 + 1]) >> 8;
      transfer->pOutput += 6;
      v8 += 2;
    }
    goto LABEL_14;
  }
  if ( outputCount > 0 )
  {
    v7 = 0;
    do
    {
      *transfer->pOutput = (v3 * transfer->snd_p[v7]) >> 8;
      transfer->pOutput[1] = (v3 * transfer->snd_p[v7 + 1]) >> 8;
      transfer->pOutput[2] = (v3 * transfer->snd_rp[v7]) >> 8;
      transfer->pOutput[3] = (v3 * transfer->snd_rp[v7 + 1]) >> 8;
      transfer->pOutput += 4;
      v7 += 2;
      --outputCount;
    }
    while ( outputCount != 0 );
  }
LABEL_15:
  snd_rp = transfer->snd_rp;
  v11 = 2 * v2;
  transfer->snd_p += 2 * v2;
  if ( snd_rp != nullptr )
    transfer->snd_rp = &snd_rp[v11];
  snd_cp = transfer->snd_cp;
  if ( snd_cp != nullptr )
    transfer->snd_cp = &snd_cp[v11];
  transfer->paintedtime += v2;
  transfer->linearCount -= v2;
}

//------------------------------------------------------------------------------
// Address: 0x10009100
// Name: private: void CAudioDirectSound::S_TransferSurround16Interleaved_FullLock(struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::S_TransferSurround16Interleaved_FullLock(
        CAudioDirectSound *this,
        const portable_samplepair_t *pfront,
        const portable_samplepair_t *prear,
        const portable_samplepair_t *pcenter,
        __int64 lpaintedtime,
        __int64 endtime)
{
  double v7; // st7
  CAudioDirectSound_vtbl *v8; // edx
  int v9; // esi
  CAudioDirectSound_vtbl *v10; // edx
  int v11; // ebx
  int v12; // eax
  unsigned int v13; // edx
  int v14; // ecx
  int v15; // edi
  const portable_samplepair_t *v16; // edx
  __int16 *v17; // eax
  int *v18; // ecx
  __int16 *v19; // eax
  int *v20; // ecx
  int v21; // ebx
  const portable_samplepair_t *v22; // edx
  int sampleMonoCount; // [esp+1Ch] [ebp-1Ch]
  unsigned int dwSize; // [esp+20h] [ebp-18h] BYREF
  __int16 *pOutput; // [esp+24h] [ebp-14h]
  int v26; // [esp+28h] [ebp-10h]
  int channelCount; // [esp+2Ch] [ebp-Ch]
  unsigned int *pdwWrite; // [esp+30h] [ebp-8h] BYREF
  int *snd_rp; // [esp+34h] [ebp-4h]
  const portable_samplepair_t *pfronta; // [esp+40h] [ebp+8h]
  const portable_samplepair_t *pfrontb; // [esp+40h] [ebp+8h]

  pdwWrite = nullptr;
  dwSize = 0;
  v7 = S_GetMasterVolume() * 256.0;
  v8 = this->__vftable;
  v9 = (int)v7;
  channelCount = this->m_bSurroundCenter + 4;
  if ( v8->DeviceChannels(this) == 2 )
    channelCount = 2;
  if ( CAudioDirectSound::LockDSBuffer(
         this,
         pBuffer: pDSBuf,
         pdwWriteBuffer: (void **)&pdwWrite,
         pdwSizeBuffer: &dwSize,
         pBufferName: "DS_INTERLEAVED",
         lockFlags: 0) != 0 )
  {
    v10 = this->__vftable;
    snd_rp = &prear->left;
    v11 = v10->DeviceSampleBytes(this);
    v12 = this->m_bufferSizeBytes / (this->DeviceChannels(this) * v11);
    pOutput = (__int16 *)pdwWrite;
    sampleMonoCount = v12;
    if ( SHIDWORD(lpaintedtime) <= SHIDWORD(endtime) )
    {
      v13 = lpaintedtime;
      if ( SHIDWORD(lpaintedtime) < SHIDWORD(endtime) || (unsigned int)lpaintedtime < (unsigned int)endtime )
      {
        while ( 1 )
        {
          v14 = (v12 - 1) & v13;
          v15 = v12 - v14;
          if ( v12 - v14 > (__int64)(endtime - __PAIR64__(HIDWORD(lpaintedtime), v13)) )
            v15 = endtime - lpaintedtime;
          if ( channelCount == 4 )
          {
            if ( v15 > 0 )
            {
              v16 = pfront;
              v17 = &pOutput[4 * v14 + 2];
              v18 = snd_rp + 1;
              v26 = v15;
              pfronta = (const portable_samplepair_t *)((char *)pfront - (char *)snd_rp);
              do
              {
                *(v17 - 2) = (v9 * v16->left) >> 8;
                *(v17 - 1) = (v9 * *(int *)((char *)v18 + (_DWORD)pfronta)) >> 8;
                *v17 = (v9 * *(v18 - 1)) >> 8;
                v17[1] = (v9 * *v18) >> 8;
                v17 += 4;
                ++v16;
                v18 += 2;
                --v26;
              }
              while ( v26 != 0 );
            }
          }
          else if ( v15 > 0 )
          {
            v19 = &pOutput[6 * v14 + 2];
            v20 = snd_rp + 1;
            v21 = (char *)pfront - (char *)pcenter;
            pfrontb = (const portable_samplepair_t *)((char *)pfront - (char *)snd_rp);
            v22 = pcenter;
            v26 = v15;
            while ( 1 )
            {
              *(v19 - 2) = (v9 * *(int *)((char *)&v22->left + v21)) >> 8;
              *(v19 - 1) = (v9 * *(int *)((char *)&pfrontb->left + (_DWORD)v20)) >> 8;
              *v19 = (v9 * v22->left) >> 8;
              v19[1] = 0;
              v19[2] = (v9 * *(v20 - 1)) >> 8;
              v19[3] = (v9 * *v20) >> 8;
              v19 += 6;
              ++v22;
              v20 += 2;
              if ( --v26 == 0 )
                break;
              v21 = (char *)pfront - (char *)pcenter;
            }
          }
          pfront += v15;
          snd_rp += 2 * v15;
          pcenter += v15;
          lpaintedtime += v15;
          if ( lpaintedtime >= endtime )
            break;
          v12 = sampleMonoCount;
          v13 = lpaintedtime;
        }
      }
    }
    pDSBuf->Unlock(this: pDSBuf, a2: pdwWrite, a3: dwSize, a4: nullptr, a5: 0);
  }
  else
  {
    S_Shutdown();
    S_Startup();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009360
// Name: public: virtual void CAudioDirectSound::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::Shutdown(CAudioDirectSound *this)
{
  IDirectSoundBuffer *v2; // eax

  ReleaseSurround();
  v2 = pDSBuf;
  if ( pDSBuf != nullptr )
  {
    pDSBuf->Stop(this: pDSBuf);
    pDSBuf->Release(this: pDSBuf);
    v2 = pDSBuf;
  }
  if ( pDSPBuf != nullptr && v2 != pDSPBuf )
    pDSPBuf->Release(this: pDSPBuf);
  if ( pDS != nullptr )
  {
    pDS->SetCooperativeLevel(this: pDS, a2: *pmainwindow, a3: 1u);
    pDS->Release(this: pDS);
  }
  pDS = nullptr;
  pDSBuf = nullptr;
  pDSPBuf = nullptr;
  if ( this->m_hInstDS != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hInstDS);
    this->m_hInstDS = nullptr;
  }
  if ( this == CAudioDirectSound::m_pSingleton )
    CAudioDirectSound::m_pSingleton = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009410
// Name: public: virtual int CAudioDirectSound::GetOutputPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDirectSound::GetOutputPosition(CAudioDirectSound *this)
{
  int m_bufferSizeBytes; // edi
  IDirectSoundBuffer *v3; // eax
  signed int m_outputBufferStartOffset; // ecx
  int v5; // edi
  unsigned int dwCurrent; // [esp+8h] [ebp-4h] BYREF

  m_bufferSizeBytes = this->m_bufferSizeBytes;
  if ( !this->m_bSurround || (v3 = pDSBufFL, this->m_isInterleaved) )
    v3 = pDSBuf;
  v3->GetCurrentPosition(this: v3, a2: &dwCurrent, a3: nullptr);
  m_outputBufferStartOffset = this->m_outputBufferStartOffset;
  if ( (int)dwCurrent <= m_outputBufferStartOffset )
    v5 = (int)(dwCurrent - m_outputBufferStartOffset + m_bufferSizeBytes) >> 1;
  else
    v5 = (int)(dwCurrent - m_outputBufferStartOffset) >> 1;
  return v5 / this->DeviceChannels(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009470
// Name: public: virtual __int64 CAudioDirectSound::PaintBegin(float,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAudioDirectSound::PaintBegin@<eax>(
        CAudioDirectSound *this@<ecx>,
        int a2@<esi>,
        float mixAheadTime,
        __int64 soundtime,
        __int64 lpaintedtime)
{
  __int64 v6; // rax
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  IDirectSoundBuffer *v10; // eax
  __int64 endtime; // [esp+8h] [ebp-Ch]
  unsigned int dwStatus; // [esp+10h] [ebp-4h] BYREF

  v6 = soundtime + (int)(float)((float)this->DeviceDmaSpeed(this) * mixAheadTime);
  endtime = v6;
  if ( v6 > lpaintedtime )
  {
    v7 = this->DeviceSampleCount(this);
    v8 = v7 / this->DeviceChannels(this);
    if ( endtime - soundtime <= v8 )
      v9 = endtime;
    else
      v9 = v8 + soundtime;
    if ( (((_BYTE)v9 - (_BYTE)lpaintedtime) & 3) != 0 )
      v9 -= ((_BYTE)v9 - (_BYTE)lpaintedtime) & 3;
    if ( !this->m_bSurround || this->m_isInterleaved )
    {
      if ( pDSBuf == nullptr )
        goto LABEL_48;
      if ( pDSBuf->GetStatus(this: pDSBuf, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBuf->Restore(this: pDSBuf);
      if ( (dwStatus & 1) != 0 )
        goto LABEL_48;
      v10 = pDSBuf;
    }
    else
    {
      if ( ((int (__stdcall *)(IDirectSoundBuffer *, unsigned int *, int))pDSBufFL->GetStatus)(
             a1: pDSBufFL,
             a2: &dwStatus,
             a3: a2) != 0 )
        _Msg(a1: "Couldn't get SURROUND FL sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufFL->Restore(this: pDSBufFL);
      if ( (dwStatus & 1) == 0 )
        pDSBufFL->Play(this: pDSBufFL, a2: 0, a3: 0, a4: 1u);
      if ( pDSBufFR->GetStatus(this: pDSBufFR, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get SURROUND FR sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufFR->Restore(this: pDSBufFR);
      if ( (dwStatus & 1) == 0 )
        pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
      if ( pDSBufRL->GetStatus(this: pDSBufRL, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get SURROUND RL sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufRL->Restore(this: pDSBufRL);
      if ( (dwStatus & 1) == 0 )
        pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
      if ( ((int (__stdcall *)(IDirectSoundBuffer *))pDSBufRR->GetStatus)(a1: pDSBufRR) != 0 )
        _Msg(a1: "Couldn't get SURROUND RR sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufRR->Restore(this: pDSBufRR);
      if ( (dwStatus & 1) == 0 )
        pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
      if ( !this->m_bSurroundCenter )
        goto LABEL_48;
      if ( pDSBufFC->GetStatus(this: pDSBufFC, a2: &dwStatus) != 0 )
        _Msg(a1: "Couldn't get SURROUND FC sound buffer status\n");
      if ( (dwStatus & 2) != 0 )
        pDSBufFC->Restore(this: pDSBufFC);
      if ( (dwStatus & 1) != 0 )
        goto LABEL_48;
      v10 = pDSBufFC;
    }
    v10->Play(this: v10, a2: 0, a3: 0, a4: 1u);
LABEL_48:
    LODWORD(v6) = v9;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10009700
// Name: public: virtual void CAudioDirectSound::ClearBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::ClearBuffer(CAudioDirectSound *this)
{
  int v1; // ebx
  int v3; // edi
  HRESULT v4; // eax
  int v5; // edi
  HRESULT v6; // eax
  int v7; // edi
  HRESULT v8; // eax
  int v9; // edi
  HRESULT v10; // eax
  int v11; // edi
  HRESULT v12; // eax
  int v13; // edi
  HRESULT v14; // eax
  unsigned int dwSizeRR; // [esp+Ch] [ebp-30h] BYREF
  unsigned int dwSizeRL; // [esp+10h] [ebp-2Ch] BYREF
  unsigned int dwSizeFR; // [esp+14h] [ebp-28h] BYREF
  unsigned int dwSizeFL; // [esp+18h] [ebp-24h] BYREF
  unsigned int *pData; // [esp+1Ch] [ebp-20h] BYREF
  unsigned int dwSize; // [esp+20h] [ebp-1Ch] BYREF
  unsigned int dwSizeFC; // [esp+24h] [ebp-18h] BYREF
  char *pDataRR; // [esp+28h] [ebp-14h] BYREF
  char *pDataRL; // [esp+2Ch] [ebp-10h] BYREF
  char *pDataFR; // [esp+30h] [ebp-Ch] BYREF
  char *pDataFL; // [esp+34h] [ebp-8h] BYREF
  char *pDataFC; // [esp+38h] [ebp-4h] BYREF

  v1 = 0;
  dwSizeFC = 0;
  pDataFC = nullptr;
  if ( !this->m_bSurround || this->m_isInterleaved )
  {
    if ( pDSBuf != nullptr )
    {
      v13 = this->DeviceSampleBits(this) != 8 ? 0 : 128;
      if ( pDSBuf != nullptr )
      {
        v14 = pDSBuf->Lock(
                this: pDSBuf,
                a2: 0,
                a3: this->m_bufferSizeBytes,
                a4: (void **)&pData,
                a5: &dwSize,
                a6: nullptr,
                a7: nullptr,
                a8: 0);
        if ( v14 != 0 )
        {
          while ( 1 )
          {
            if ( v14 != -2005401450 )
            {
              _Msg(a1: "S_ClearBuffer: DS::Lock Sound Buffer Failed\n");
              S_Shutdown();
              return;
            }
            if ( ++v1 > 10000 )
              break;
            v14 = pDSBuf->Lock(
                    this: pDSBuf,
                    a2: 0,
                    a3: this->m_bufferSizeBytes,
                    a4: (void **)&pData,
                    a5: &dwSize,
                    a6: nullptr,
                    a7: nullptr,
                    a8: 0);
            if ( v14 == 0 )
              goto LABEL_49;
          }
          _Msg(a1: "S_ClearBuffer: DS: couldn't restore buffer\n");
          S_Shutdown();
        }
        else
        {
LABEL_49:
          _V_memset(dest: pData, fill: v13, count: dwSize);
          pDSBuf->Unlock(this: pDSBuf, a2: pData, a3: dwSize, a4: nullptr, a5: 0);
        }
      }
    }
  }
  else
  {
    v3 = 0;
    if ( pDSBufFL != nullptr || pDSBufFR != nullptr || pDSBufRL != nullptr || pDSBufRR != nullptr || pDSBufFC != nullptr )
    {
      v4 = pDSBufFL->Lock(
             this: pDSBufFL,
             a2: 0,
             a3: this->m_bufferSizeBytes,
             a4: (void **)&pDataFL,
             a5: &dwSizeFL,
             a6: nullptr,
             a7: nullptr,
             a8: 0);
      if ( v4 != 0 )
      {
        while ( 1 )
        {
          if ( v4 != -2005401450 )
          {
            _Msg(a1: "S_ClearBuffer: DS::Lock FL Sound Buffer Failed\n");
            S_Shutdown();
            return;
          }
          if ( ++v3 > 10000 )
            break;
          v4 = pDSBufFL->Lock(
                 this: pDSBufFL,
                 a2: 0,
                 a3: this->m_bufferSizeBytes,
                 a4: (void **)&pDataFL,
                 a5: &dwSizeFL,
                 a6: nullptr,
                 a7: nullptr,
                 a8: 0);
          if ( v4 == 0 )
            goto LABEL_12;
        }
        _Msg(a1: "S_ClearBuffer: DS: couldn't restore FL buffer\n");
        S_Shutdown();
      }
      else
      {
LABEL_12:
        v5 = 0;
        v6 = pDSBufFR->Lock(
               this: pDSBufFR,
               a2: 0,
               a3: this->m_bufferSizeBytes,
               a4: (void **)&pDataFR,
               a5: &dwSizeFR,
               a6: nullptr,
               a7: nullptr,
               a8: 0);
        if ( v6 != 0 )
        {
          while ( 1 )
          {
            if ( v6 != -2005401450 )
            {
              _Msg(a1: "S_ClearBuffer: DS::Lock FR Sound Buffer Failed\n");
              S_Shutdown();
              return;
            }
            if ( ++v5 > 10000 )
              break;
            v6 = pDSBufFR->Lock(
                   this: pDSBufFR,
                   a2: 0,
                   a3: this->m_bufferSizeBytes,
                   a4: (void **)&pDataFR,
                   a5: &dwSizeFR,
                   a6: nullptr,
                   a7: nullptr,
                   a8: 0);
            if ( v6 == 0 )
              goto LABEL_16;
          }
          _Msg(a1: "S_ClearBuffer: DS: couldn't restore FR buffer\n");
          S_Shutdown();
        }
        else
        {
LABEL_16:
          v7 = 0;
          v8 = pDSBufRL->Lock(
                 this: pDSBufRL,
                 a2: 0,
                 a3: this->m_bufferSizeBytes,
                 a4: (void **)&pDataRL,
                 a5: &dwSizeRL,
                 a6: nullptr,
                 a7: nullptr,
                 a8: 0);
          if ( v8 != 0 )
          {
            while ( 1 )
            {
              if ( v8 != -2005401450 )
              {
                _Msg(a1: "S_ClearBuffer: DS::Lock RL Sound Buffer Failed\n");
                S_Shutdown();
                return;
              }
              if ( ++v7 > 10000 )
                break;
              v8 = pDSBufRL->Lock(
                     this: pDSBufRL,
                     a2: 0,
                     a3: this->m_bufferSizeBytes,
                     a4: (void **)&pDataRL,
                     a5: &dwSizeRL,
                     a6: nullptr,
                     a7: nullptr,
                     a8: 0);
              if ( v8 == 0 )
                goto LABEL_20;
            }
            _Msg(a1: "S_ClearBuffer: DS: couldn't restore RL buffer\n");
            S_Shutdown();
          }
          else
          {
LABEL_20:
            v9 = 0;
            v10 = pDSBufRR->Lock(
                    this: pDSBufRR,
                    a2: 0,
                    a3: this->m_bufferSizeBytes,
                    a4: (void **)&pDataRR,
                    a5: &dwSizeRR,
                    a6: nullptr,
                    a7: nullptr,
                    a8: 0);
            if ( v10 != 0 )
            {
              while ( 1 )
              {
                if ( v10 != -2005401450 )
                {
                  _Msg(a1: "S_ClearBuffer: DS::Lock RR Sound Buffer Failed\n");
                  S_Shutdown();
                  return;
                }
                if ( ++v9 > 10000 )
                  break;
                v10 = pDSBufRR->Lock(
                        this: pDSBufRR,
                        a2: 0,
                        a3: this->m_bufferSizeBytes,
                        a4: (void **)&pDataRR,
                        a5: &dwSizeRR,
                        a6: nullptr,
                        a7: nullptr,
                        a8: 0);
                if ( v10 == 0 )
                  goto LABEL_24;
              }
              _Msg(a1: "S_ClearBuffer: DS: couldn't restore RR buffer\n");
              S_Shutdown();
            }
            else
            {
LABEL_24:
              if ( this->m_bSurroundCenter
                && (v11 = 0,
                    (v12 = pDSBufFC->Lock(
                             this: pDSBufFC,
                             a2: 0,
                             a3: this->m_bufferSizeBytes,
                             a4: (void **)&pDataFC,
                             a5: &dwSizeFC,
                             a6: nullptr,
                             a7: nullptr,
                             a8: 0)) != 0) )
              {
                while ( 1 )
                {
                  if ( v12 != -2005401450 )
                  {
                    _Msg(a1: "S_ClearBuffer: DS::Lock FC Sound Buffer Failed\n");
                    S_Shutdown();
                    return;
                  }
                  if ( ++v11 > 10000 )
                    break;
                  v12 = pDSBufFC->Lock(
                          this: pDSBufFC,
                          a2: 0,
                          a3: this->m_bufferSizeBytes,
                          a4: (void **)&pDataFC,
                          a5: &dwSizeFC,
                          a6: nullptr,
                          a7: nullptr,
                          a8: 0);
                  if ( v12 == 0 )
                    goto LABEL_29;
                }
                _Msg(a1: "S_ClearBuffer: DS: couldn't restore FC buffer\n");
                S_Shutdown();
              }
              else
              {
LABEL_29:
                _V_memset(dest: pDataFL, fill: 0, count: this->m_bufferSizeBytes);
                _V_memset(dest: pDataFR, fill: 0, count: this->m_bufferSizeBytes);
                _V_memset(dest: pDataRL, fill: 0, count: this->m_bufferSizeBytes);
                _V_memset(dest: pDataRR, fill: 0, count: this->m_bufferSizeBytes);
                if ( this->m_bSurroundCenter )
                  _V_memset(dest: pDataFC, fill: 0, count: this->m_bufferSizeBytes);
                pDSBufFL->Unlock(this: pDSBufFL, a2: pDataFL, a3: dwSizeFL, a4: nullptr, a5: 0);
                pDSBufFR->Unlock(this: pDSBufFR, a2: pDataFR, a3: dwSizeFR, a4: nullptr, a5: 0);
                pDSBufRL->Unlock(this: pDSBufRL, a2: pDataRL, a3: dwSizeRL, a4: nullptr, a5: 0);
                pDSBufRR->Unlock(this: pDSBufRR, a2: pDataRR, a3: dwSizeRR, a4: nullptr, a5: 0);
                if ( this->m_bSurroundCenter )
                  pDSBufFC->Unlock(this: pDSBufFC, a2: pDataFC, a3: dwSizeFC, a4: nullptr, a5: 0);
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009BF0
// Name: GetWindowsSpeakerConfig
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetWindowsSpeakerConfig()
{
  int result; // eax
  unsigned int v1; // eax
  unsigned int speaker_config; // [esp+0h] [ebp-4h] BYREF

  if ( windows_speaker_config.m_pParent == nullptr )
    return 0;
  result = windows_speaker_config.m_pParent->m_Value.m_nValue;
  speaker_config = result;
  if ( windows_speaker_config.m_pParent->m_Value.m_nValue >= 0 )
    return result;
  speaker_config = 4;
  if ( ((int (__cdecl *)(IDirectSound *, unsigned int *))pDS->GetSpeakerConfig)(a1: pDS, a2: &speaker_config) != 0 )
  {
    v1 = speaker_config;
  }
  else
  {
    v1 = (unsigned __int8)speaker_config;
    speaker_config = v1;
    if ( v1 == 8 )
    {
      speaker_config = 7;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&windows_speaker_config.IConVar, value: 7);
      return speaker_config;
    }
    if ( v1 == 9 )
    {
      speaker_config = 6;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&windows_speaker_config.IConVar, value: 6);
      return speaker_config;
    }
  }
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&windows_speaker_config.IConVar, value: v1);
  return speaker_config;
}

//------------------------------------------------------------------------------
// Address: 0x10009C90
// Name: private: void CAudioDirectSound::DetectWindowsSpeakerSetup(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CAudioDirectSound::DetectWindowsSpeakerSetup(CAudioDirectSound *this)
{
  int WindowsSpeakerConfig; // esi

  WindowsSpeakerConfig = GetWindowsSpeakerConfig();
  switch ( WindowsSpeakerConfig )
  {
    case 1:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 0);
      break;
    case 3:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 4);
      break;
    case 6:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 5);
      break;
    case 7:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 7);
      break;
    default:
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&snd_surround.IConVar, value: 2);
      break;
  }
  switch ( WindowsSpeakerConfig )
  {
    case 2:
      DevMsg(a1: "DS:mono configuration detected\n");
      break;
    case 1:
      DevMsg(a1: "DS:headphone configuration detected\n");
      break;
    case 4:
      DevMsg(a1: "DS:stereo speaker configuration detected\n");
      break;
    case 3:
      DevMsg(a1: "DS:quad speaker configuration detected\n");
      break;
    case 5:
      DevMsg(a1: "DS:surround speaker configuration detected\n");
      break;
    case 6:
      DevMsg(a1: "DS:5.1 speaker configuration detected\n");
      break;
    case 7:
      DevMsg(a1: "DS:7.1 speaker configuration detected\n");
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009D80
// Name: void OnSndSurroundCvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __cdecl OnSndSurroundCvarChanged(IConVar *pVar, const char *pOldString, float flOldValue)
{
  int WindowsSpeakerConfig; // esi
  int SpeakerConfigForSurroundMode; // eax
  ConVarRef var; // [esp+0h] [ebp-Ch] BYREF
  const char *speakerConfigDesc; // [esp+8h] [ebp-4h] BYREF

  if ( pDS != nullptr && flOldValue != -1.0 )
  {
    WindowsSpeakerConfig = GetWindowsSpeakerConfig();
    speakerConfigDesc = defaultValue;
    ConVarRef::ConVarRef(this: &var, pConVar: pVar);
    SpeakerConfigForSurroundMode = GetSpeakerConfigForSurroundMode(
                                     surroundMode: var.m_pConVarState->m_Value.m_nValue,
                                     pConfigDesc: &speakerConfigDesc);
    if ( SpeakerConfigForSurroundMode != WindowsSpeakerConfig )
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&windows_speaker_config.IConVar,
        value: SpeakerConfigForSurroundMode);
      _Msg(a1: "Speaker configuration has been changed to %s.\n", speakerConfigDesc);
      g_pSoundServices->RestartSoundSystem(this: g_pSoundServices);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009E00
// Name: void OnSndVarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnSndVarChanged(IConVar *pVar, const char *pOldString, float flOldValue)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar: pVar);
  if ( var.m_pConVarState->m_Value.m_nValue != (int)flOldValue )
    g_pSoundServices->RestartSoundSystem(this: g_pSoundServices);
}

//------------------------------------------------------------------------------
// Address: 0x1000A0A0
// Name: void OnSndSurroundLegacyChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnSndSurroundLegacyChanged(IConVar *pVar)
{
  int m_nValue; // eax
  bool v2; // zf
  const char *v3; // eax
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  if ( pDS != nullptr && CAudioDirectSound::m_pSingleton != nullptr )
  {
    ConVarRef::ConVarRef(this: &var, pConVar: pVar);
    m_nValue = var.m_pConVarState->m_Value.m_nValue;
    if ( CAudioDirectSound::m_pSingleton->m_isInterleaved == (m_nValue != 0) )
    {
      v2 = m_nValue == 0;
      v3 = "enabled";
      if ( v2 )
        v3 = "disabled";
      _Msg(a1: "Legacy Surround %s.\n", v3);
      g_pSoundServices->RestartSoundSystem(this: g_pSoundServices);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A110
// Name: private: bool CAudioDirectSound::SNDDMA_InitSurround(struct IDirectSound __near *,struct tWAVEFORMATEX __near *,struct _DSBCAPS __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CAudioDirectSound::SNDDMA_InitSurround@<al>(
        CAudioDirectSound *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        IDirectSound *lpDS,
        IDirectSound3DListener *lpFormat,
        _DSBCAPS *lpdsbc,
        int cchan)
{
  IDirectSound *v7; // edi
  tWAVEFORMATEX *v9; // esi
  unsigned int v10; // ecx
  unsigned int v11; // edx
  IDirectSound3DListener_vtbl *v12; // eax
  IDirectSound_vtbl *v13; // edx
  HRESULT (__stdcall *CreateSoundBuffer)(IDirectSound *, const _DSBUFFERDESC *, IDirectSoundBuffer **, IUnknown *); // ecx
  int v15; // ebx
  _DWORD *v16; // edi
  unsigned int nSamplesPerSec; // ecx
  _DSBCAPS *v18; // esi
  int v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // edi
  int v24; // eax
  int v25; // edi
  HRESULT v26; // eax
  int v27; // edi
  HRESULT v28; // eax
  int v29; // edi
  HRESULT v30; // eax
  unsigned int *p_m_outputBufferStartOffset; // esi
  int v33; // [esp+B4h] [ebp-A8h]
  int v35; // [esp+B8h] [ebp-A4h]
  _DS3DLISTENER lparm; // [esp+C0h] [ebp-9Ch] BYREF
  unsigned int dwWrite; // [esp+100h] [ebp-5Ch] BYREF
  tWAVEFORMATEX wvex; // [esp+104h] [ebp-58h] BYREF
  _DSBUFFERDESC dsbuf; // [esp+118h] [ebp-44h] BYREF
  CAudioDirectSound *v40; // [esp+13Ch] [ebp-20h]
  _D3DVECTOR bpos; // [esp+140h] [ebp-1Ch] BYREF
  _D3DVECTOR bdir; // [esp+14Ch] [ebp-10h] BYREF
  void *lpData; // [esp+158h] [ebp-4h] BYREF

  v7 = lpDS;
  v40 = this;
  lpData = nullptr;
  if ( lpDS == nullptr )
    return 0;
  v9 = (tWAVEFORMATEX *)lpFormat;
  v10 = (unsigned int)lpFormat[1].__vftable;
  v11 = (unsigned int)lpFormat[2].__vftable;
  *(IDirectSound3DListener *)&wvex.wFormatTag = (IDirectSound3DListener)lpFormat->__vftable;
  v12 = lpFormat[3].__vftable;
  wvex.wBitsPerSample = HIWORD(v12);
  wvex.nBlockAlign = HIWORD(v12) >> 3;
  wvex.nAvgBytesPerSec = v11;
  LOWORD(v11) = lpFormat[4].__vftable;
  wvex.nAvgBytesPerSec = v10 * (HIWORD(v12) >> 3);
  memset(&dsbuf.dwBufferBytes, 0, 28);
  wvex.cbSize = v11;
  wvex.nSamplesPerSec = v10;
  wvex.nChannels = 1;
  dsbuf.dwSize = 36;
  dsbuf.dwFlags = 16;
  if ( snd_mute_losefocus.m_pParent == nullptr || snd_mute_losefocus.m_pParent->m_Value.m_nValue == 0 )
    dsbuf.dwFlags = 32784;
  v13 = lpDS->__vftable;
  dsbuf.lpwfxFormat = &wvex;
  CreateSoundBuffer = v13->CreateSoundBuffer;
  dsbuf.dwBufferBytes = 0x4000;
  if ( CreateSoundBuffer(this: lpDS, a2: &dsbuf, a3: &pDSBufFL, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d front left failed");
LABEL_14:
    ReleaseSurround();
    return 0;
  }
  if ( v7->CreateSoundBuffer(this: v7, a2: &dsbuf, a3: &pDSBufFR, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d front right failed");
    goto LABEL_14;
  }
  if ( v7->CreateSoundBuffer(this: v7, a2: &dsbuf, a3: &pDSBufRL, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d rear left failed");
    goto LABEL_14;
  }
  if ( v7->CreateSoundBuffer(this: v7, a2: &dsbuf, a3: &pDSBufRR, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d rear right failed");
    goto LABEL_14;
  }
  v15 = cchan;
  if ( cchan == 5 && v7->CreateSoundBuffer(this: v7, a2: &dsbuf, a3: &pDSBufFC, a4: nullptr) != 0 )
  {
    _Warning(a1: "DS:CreateSoundBuffer for 3d front center failed");
LABEL_80:
    ReleaseSurround();
    return 0;
  }
  if ( pDSBufFL->QueryInterface(this: pDSBufFL, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DFL) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d front left failed");
    goto LABEL_80;
  }
  if ( pDSBufFR->QueryInterface(this: pDSBufFR, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DFR) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d front right failed");
    goto LABEL_80;
  }
  if ( pDSBufRL->QueryInterface(this: pDSBufRL, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DRL) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d rear left failed");
    goto LABEL_80;
  }
  if ( pDSBufRR->QueryInterface(this: pDSBufRR, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DRR) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d rear right failed");
    goto LABEL_80;
  }
  if ( v15 == 5
    && pDSBufFC->QueryInterface(this: pDSBufFC, a2: &IID_IDirectSound3DBufferDef, a3: (void **)&pDSBuf3DFC) != 0 )
  {
    _Warning(a1: "DS:Query 3DBuffer for 3d front center failed");
    goto LABEL_80;
  }
  lpFormat = nullptr;
  pDSPBuf->QueryInterface(this: pDSPBuf, a2: &IID_IDirectSound3DListener, a3: (void **)&lpFormat);
  if ( lpFormat == nullptr )
  {
    _Warning(a1: "DS: failed to get 3D listener interface.");
    goto LABEL_80;
  }
  lparm.dwSize = 64;
  ((void (__stdcall *)(IDirectSound3DListener *, _DS3DLISTENER *, int, int))lpFormat->GetAllParameters)(
    a1: lpFormat,
    a2: &lparm,
    a3: a2,
    a4: a3);
  ((void (__stdcall *)(IDirectSound3DListener *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))lpFormat->SetOrientation)(
    a1: lpFormat,
    a2: 0.0,
    a3: 0.0,
    a4: 1.0,
    a5: 0.0,
    a6: 1.0,
    a7: 0.0,
    a8: 0);
  ((void (__stdcall *)(IDirectSound3DListener *, _DWORD, _DWORD, _DWORD, _DWORD))lpFormat->SetPosition)(
    a1: lpFormat,
    a2: 0.0,
    a3: 0.0,
    a4: 0.0,
    a5: 0);
  bpos.x = -1.0;
  bpos.y = 0.0;
  bpos.z = 1.0;
  bdir.x = 1.0;
  bdir.y = 0.0;
  bdir.z = -1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DFL, pbpos: &bpos, pbdir: &bdir);
  bpos.x = 1.0;
  bpos.z = 1.0;
  bpos.y = 0.0;
  bdir.x = -1.0;
  bdir.y = 0.0;
  bdir.z = -1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DFR, pbpos: &bpos, pbdir: &bdir);
  bpos.x = -1.0;
  bpos.z = -1.0;
  bpos.y = 0.0;
  bdir.x = 1.0;
  bdir.y = 0.0;
  bdir.z = 1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DRL, pbpos: &bpos, pbdir: &bdir);
  bpos.x = 1.0;
  bpos.y = 0.0;
  bpos.z = -1.0;
  bdir.x = -1.0;
  bdir.y = 0.0;
  bdir.z = 1.0;
  DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DRR, pbpos: &bpos, pbdir: &bdir);
  if ( v15 == 5 )
  {
    bpos.x = 0.0;
    bpos.y = 0.0;
    bdir.x = 0.0;
    bdir.y = 0.0;
    bpos.z = 1.0;
    bdir.z = -1.0;
    DS3D_SetBufferParams(pDSBuf3D: pDSBuf3DFC, pbpos: &bpos, pbdir: &bdir);
  }
  lpFormat->CommitDeferredSettings(this: lpFormat);
  v16 = &v40->__vftable;
  v40->m_deviceChannels = 1;
  v16[3] = v9->wBitsPerSample;
  nSamplesPerSec = v9->nSamplesPerSec;
  v18 = lpdsbc;
  v16[5] = nSamplesPerSec;
  v18->dwFlags = 0;
  v18->dwBufferBytes = 0;
  v18->dwUnlockTransferRate = 0;
  v18->dwPlayCpuOverhead = 0;
  v18->dwSize = 20;
  if ( ((int (__cdecl *)(IDirectSoundBuffer *))pDSBufFL->GetCaps)(a1: pDSBufFL) != 0 )
  {
    _Warning(a1: "DS:GetCaps failed for 3d sound buffer\n");
    goto LABEL_80;
  }
  ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD, _DWORD, int, int, _DSBCAPS *))pDSBufFL->Play)(
    a1: pDSBufFL,
    a2: 0,
    a3: 0,
    a4: 1,
    a5: v33,
    a6: v18);
  pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
  pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
  pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
  if ( v15 == 5 )
    pDSBufFC->Play(this: pDSBufFC, a2: 0, a3: 0, a4: 1u);
  if ( snd_firsttime )
  {
    v19 = (*(int (__thiscall **)(_DWORD *))(*v16 + 112))(a1: v16);
    v20 = (*(int (__thiscall **)(_DWORD *, int))(*v16 + 104))(a1: v16, a2: v19);
    DevMsg(a1: "   %d channel(s)\n   %d bits/sample\n   %d samples/sec\n", v15, v20, v35);
  }
  v16[6] = v18->dwBufferBytes;
  if ( v15 == 5 )
  {
    v21 = 0;
    v22 = ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, void **, IDirectSound **, _DWORD))pDSBufFC->Lock)(
            a1: pDSBufFC,
            a2: 0,
            a3: v18->dwBufferBytes,
            a4: &lpData,
            a5: &lpDS,
            a6: 0);
    if ( v22 != 0 )
    {
      while ( 1 )
      {
        if ( v22 != -2005401450 )
        {
          _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed for FC\n");
          goto LABEL_80;
        }
        if ( ++v21 > 10000 )
          break;
        v22 = pDSBufFC->Lock(
                this: pDSBufFC,
                a2: 0,
                a3: v18->dwBufferBytes,
                a4: &lpData,
                a5: (unsigned int *)&lpDS,
                a6: nullptr,
                a7: nullptr,
                a8: 0);
        if ( v22 == 0 )
          goto LABEL_43;
      }
      _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer for FC\n");
      goto LABEL_80;
    }
LABEL_43:
    memset(dst: (unsigned __int8 *)lpData, value: 0, count: (unsigned int)lpDS);
    ((void (__stdcall *)(IDirectSoundBuffer *, void *, IDirectSound *, _DWORD, _DWORD, _DWORD, _DWORD))pDSBufFC->Unlock)(
      a1: pDSBufFC,
      a2: lpData,
      a3: lpDS,
      a4: 0,
      a5: 0,
      a6: 0,
      a7: 0);
  }
  v23 = 0;
  v24 = ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, void **, IDirectSound **, _DWORD))pDSBufFL->Lock)(
          a1: pDSBufFL,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: &lpData,
          a5: &lpDS,
          a6: 0);
  if ( v24 != 0 )
  {
    while ( 1 )
    {
      if ( v24 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitSurround: DS::Lock Sound Buffer Failed for 3d FL\n");
        goto LABEL_80;
      }
      if ( ++v23 > 10000 )
        break;
      v24 = pDSBufFL->Lock(
              this: pDSBufFL,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: &lpData,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v24 == 0 )
        goto LABEL_48;
    }
    _Warning(a1: "SNDDMA_InitSurround: DS: couldn't restore buffer for 3d FL\n");
    goto LABEL_80;
  }
LABEL_48:
  memset(dst: (unsigned __int8 *)lpData, value: 0, count: (unsigned int)lpDS);
  pDSBufFL->Unlock(this: pDSBufFL, a2: lpData, a3: (unsigned int)lpDS, a4: nullptr, a5: 0);
  v25 = 0;
  v26 = pDSBufFR->Lock(
          this: pDSBufFR,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: &lpData,
          a5: (unsigned int *)&lpDS,
          a6: nullptr,
          a7: nullptr,
          a8: 0);
  if ( v26 != 0 )
  {
    while ( 1 )
    {
      if ( v26 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitSurround: DS::Lock Sound Buffer Failed for 3d FR\n");
        goto LABEL_80;
      }
      if ( ++v25 > 10000 )
        break;
      v26 = pDSBufFR->Lock(
              this: pDSBufFR,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: &lpData,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v26 == 0 )
        goto LABEL_52;
    }
    _Warning(a1: "SNDDMA_InitSurround: DS: couldn't restore buffer for FR\n");
    goto LABEL_80;
  }
LABEL_52:
  memset(dst: (unsigned __int8 *)lpData, value: 0, count: (unsigned int)lpDS);
  pDSBufFR->Unlock(this: pDSBufFR, a2: lpData, a3: (unsigned int)lpDS, a4: nullptr, a5: 0);
  v27 = 0;
  v28 = pDSBufRL->Lock(
          this: pDSBufRL,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: &lpData,
          a5: (unsigned int *)&lpDS,
          a6: nullptr,
          a7: nullptr,
          a8: 0);
  if ( v28 != 0 )
  {
    while ( 1 )
    {
      if ( v28 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed for RL\n");
        goto LABEL_80;
      }
      if ( ++v27 > 10000 )
        break;
      v28 = pDSBufRL->Lock(
              this: pDSBufRL,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: &lpData,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v28 == 0 )
        goto LABEL_56;
    }
    _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer for RL\n");
    goto LABEL_80;
  }
LABEL_56:
  memset(dst: (unsigned __int8 *)lpData, value: 0, count: (unsigned int)lpDS);
  pDSBufRL->Unlock(this: pDSBufRL, a2: lpData, a3: (unsigned int)lpDS, a4: nullptr, a5: 0);
  v29 = 0;
  v30 = pDSBufRR->Lock(
          this: pDSBufRR,
          a2: 0,
          a3: v18->dwBufferBytes,
          a4: &lpData,
          a5: (unsigned int *)&lpDS,
          a6: nullptr,
          a7: nullptr,
          a8: 0);
  if ( v30 != 0 )
  {
    while ( 1 )
    {
      if ( v30 != -2005401450 )
      {
        _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed for RR\n");
        goto LABEL_80;
      }
      if ( ++v29 > 10000 )
        break;
      v30 = pDSBufRR->Lock(
              this: pDSBufRR,
              a2: 0,
              a3: v18->dwBufferBytes,
              a4: &lpData,
              a5: (unsigned int *)&lpDS,
              a6: nullptr,
              a7: nullptr,
              a8: 0);
      if ( v30 == 0 )
        goto LABEL_60;
    }
    _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer for RR\n");
    goto LABEL_80;
  }
LABEL_60:
  memset(dst: (unsigned __int8 *)lpData, value: 0, count: (unsigned int)lpDS);
  ((void (__stdcall *)(IDirectSoundBuffer *, void *, IDirectSound *, _DWORD, _DWORD, _DWORD, _DWORD))pDSBufRR->Unlock)(
    a1: pDSBufRR,
    a2: lpData,
    a3: lpDS,
    a4: 0,
    a5: 0,
    a6: 0,
    a7: 0);
  lpData = nullptr;
  pDSBufFL->Stop(this: pDSBufFL);
  pDSBufFR->Stop(this: pDSBufFR);
  pDSBufRL->Stop(this: pDSBufRL);
  pDSBufRR->Stop(this: pDSBufRR);
  if ( v15 == 5 )
    pDSBufFC->Stop(this: pDSBufFC);
  p_m_outputBufferStartOffset = &v40->m_outputBufferStartOffset;
  pDSBufFL->GetCurrentPosition(this: pDSBufFL, a2: &v40->m_outputBufferStartOffset, a3: &dwWrite);
  pDSBufFR->SetCurrentPosition(this: pDSBufFR, a2: *p_m_outputBufferStartOffset);
  pDSBufRL->SetCurrentPosition(this: pDSBufRL, a2: *p_m_outputBufferStartOffset);
  pDSBufRR->SetCurrentPosition(this: pDSBufRR, a2: *p_m_outputBufferStartOffset);
  if ( v15 == 5 )
    pDSBufFC->SetCurrentPosition(this: pDSBufFC, a2: *p_m_outputBufferStartOffset);
  ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD))pDSBufFL->Play)(a1: pDSBufFL, a2: 0);
  pDSBufFR->Play(this: pDSBufFR, a2: 0, a3: 0, a4: 1u);
  pDSBufRL->Play(this: pDSBufRL, a2: 0, a3: 0, a4: 1u);
  pDSBufRR->Play(this: pDSBufRR, a2: 0, a3: 0, a4: 1u);
  if ( v15 == 5 )
    pDSBufFC->Play(this: pDSBufFC, a2: 0, a3: 0, a4: 1u);
  if ( snd_firsttime )
    _Warning(a1: "3d surround sound initialization successful\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA80
// Name: private: void CAudioDirectSound::S_TransferSurround16Interleaved(struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,struct portable_samplepair_t const __near *,__int64,__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::S_TransferSurround16Interleaved(
        CAudioDirectSound *this,
        portable_samplepair_t *pfront,
        int prear,
        portable_samplepair_t *pcenter,
        __int64 lpaintedtime,
        __int64 endtime)
{
  CAudioDirectSound_vtbl *v7; // edx
  int v8; // esi
  int v9; // eax
  int v10; // esi
  CAudioDirectSound_vtbl *v11; // edx
  int v12; // ebx
  bool v13; // zf
  int v14; // edi
  unsigned int v15; // esi
  unsigned int v16; // edi
  int v17; // ebx
  HRESULT v18; // eax
  portable_samplepair_t *v19; // eax
  surround_transfer_t transfer; // [esp+4h] [ebp-30h] BYREF
  unsigned int size0; // [esp+2Ch] [ebp-8h] BYREF
  unsigned int size1; // [esp+30h] [ebp-4h] BYREF

  if ( pDSBuf != nullptr )
  {
    if ( snd_lockpartial.m_pParent != nullptr && snd_lockpartial.m_pParent->m_Value.m_nValue != 0 )
    {
      transfer.snd_cp = &pcenter->left;
      v7 = this->__vftable;
      transfer.snd_rp = (int *)prear;
      transfer.snd_p = &pfront->left;
      v8 = v7->DeviceSampleCount(this);
      v9 = v8 / this->DeviceChannels(this);
      v10 = lpaintedtime;
      v11 = this->__vftable;
      transfer.paintedtime = lpaintedtime;
      v12 = v9 - 1;
      transfer.linearCount = endtime - lpaintedtime;
      v13 = !this->m_bSurroundCenter;
      transfer.sampleMask = v9 - 1;
      prear = 2 * !v13 + 4;
      if ( v11->DeviceChannels(this) == 2 )
      {
        v14 = 2;
        prear = 2;
      }
      else
      {
        v14 = prear;
      }
      transfer.channelCount = v14;
      v15 = 2 * v14 * (v12 & v10);
      v16 = 2 * transfer.linearCount * v14;
      pfront = nullptr;
      pcenter = nullptr;
      v17 = 0;
      while ( 1 )
      {
        v18 = pDSBuf->Lock(
                this: pDSBuf,
                a2: v15,
                a3: v16,
                a4: (void **)&pfront,
                a5: &size0,
                a6: (void **)&pcenter,
                a7: &size1,
                a8: 0);
        if ( v18 == 0 )
          break;
        if ( v18 == -2005401450 && ++v17 < 10000 )
          continue;
        _Msg(a1: "DS::Lock Sound Buffer Failed\n");
        return;
      }
      if ( pfront != nullptr )
      {
        transfer.pOutput = (__int16 *)pfront;
        TransferSamplesToSurroundBuffer(&transfer, outputCount: size0 / (2 * prear));
      }
      v19 = pcenter;
      if ( pcenter != nullptr )
      {
        transfer.pOutput = (__int16 *)pcenter;
        TransferSamplesToSurroundBuffer(&transfer, outputCount: size1 / (2 * prear));
        v19 = pcenter;
      }
      pDSBuf->Unlock(this: pDSBuf, a2: pfront, a3: size0, a4: v19, a5: size1);
    }
    else
    {
      CAudioDirectSound::S_TransferSurround16Interleaved_FullLock(
        this,
        pfront,
        (const portable_samplepair_t *)prear,
        pcenter,
        lpaintedtime,
        endtime);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC20
// Name: class IAudioDevice __near * Audio_CreateDirectSoundDevice(void)
// Source: json
//------------------------------------------------------------------------------
CAudioDirectSound *__cdecl Audio_CreateDirectSoundDevice()
{
  CAudioDirectSound *v0; // ecx
  CAudioDirectSound *v1; // eax

  v0 = CAudioDirectSound::m_pSingleton;
  if ( CAudioDirectSound::m_pSingleton == nullptr )
  {
    v1 = (CAudioDirectSound *)MemAlloc_Alloc(nSize: 0x28u);
    if ( v1 != nullptr )
    {
      v1->__vftable = (CAudioDirectSound_vtbl *)&CAudioDirectSound::`vftable';
      v0 = v1;
    }
    else
    {
      v0 = nullptr;
    }
    CAudioDirectSound::m_pSingleton = v0;
  }
  if ( v0->Init(this: v0) )
  {
    if ( snd_firsttime )
      DevMsg(a1: "DirectSound initialized\n");
    return CAudioDirectSound::m_pSingleton;
  }
  else
  {
    DevMsg(a1: "DirectSound failed to init\n");
    if ( CAudioDirectSound::m_pSingleton != nullptr )
      ((void (__thiscall *)(CAudioDirectSound *, int))CAudioDirectSound::m_pSingleton->dtr_IAudioDevice)(
        a1: CAudioDirectSound::m_pSingleton,
        a2: 1);
    CAudioDirectSound::m_pSingleton = nullptr;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ACB0
// Name: private: enum sndinitstat CAudioDirectSound::SNDDMA_InitDirect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioDirectSound::SNDDMA_InitDirect(CAudioDirectSound *this)
{
  HINSTANCE__ *LibraryA; // eax
  HRESULT (__stdcall *DirectSoundCreate)(LPCGUID, LPDIRECTSOUND *, LPUNKNOWN); // eax
  HRESULT v5; // eax
  int m_nValue; // eax
  int v7; // edi
  int v8; // eax
  int v9; // eax
  char inited; // al
  int v11; // eax
  bool v12; // al
  int v13; // eax
  int wBitsPerSample; // edx
  unsigned int nSamplesPerSec; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  unsigned int dwBufferBytes; // eax
  int v20; // edi
  HRESULT v21; // eax
  int v22; // [esp-Ch] [ebp-E4h]
  int v23; // [esp-8h] [ebp-E0h]
  _DSCAPS dscaps; // [esp+8h] [ebp-D0h] BYREF
  unsigned int dwWrite; // [esp+68h] [ebp-70h] BYREF
  tWAVEFORMATEX pformat; // [esp+6Ch] [ebp-6Ch] BYREF
  _DSBUFFERDESC dsbuf; // [esp+80h] [ebp-58h] BYREF
  _DSBCAPS dsbcaps; // [esp+A4h] [ebp-34h] BYREF
  unsigned int dwSize; // [esp+B8h] [ebp-20h] BYREF
  tWAVEFORMATEX format; // [esp+BCh] [ebp-1Ch] BYREF
  void *lpData; // [esp+D0h] [ebp-8h] BYREF
  bool primary_format_set; // [esp+D7h] [ebp-1h]

  lpData = nullptr;
  primary_format_set = false;
  if ( this->m_hInstDS != nullptr )
  {
    DirectSoundCreate = (HRESULT (__stdcall *)(LPCGUID, LPDIRECTSOUND *, LPUNKNOWN))pDirectSoundCreate;
  }
  else
  {
    LibraryA = LoadLibraryA(lpLibFileName: "dsound.dll");
    this->m_hInstDS = LibraryA;
    if ( LibraryA == nullptr )
    {
      _Warning(a1: "Couldn't load dsound.dll\n");
      return 1;
    }
    DirectSoundCreate = (HRESULT (__stdcall *)(LPCGUID, LPDIRECTSOUND *, LPUNKNOWN))GetProcAddress(
                                                                                      hModule: LibraryA,
                                                                                      lpProcName: "DirectSoundCreate");
    pDirectSoundCreate = (HRESULT (__stdcall *)(_GUID *, IDirectSound **, IUnknown *))DirectSoundCreate;
    if ( DirectSoundCreate == nullptr )
    {
      _Warning(a1: "Couldn't get DS proc addr\n");
      return 1;
    }
  }
  v5 = DirectSoundCreate(pcGuidDevice: nullptr, ppDS: &pDS, pUnkOuter: nullptr);
  if ( v5 == 0 )
  {
    CAudioDirectSound::DetectWindowsSpeakerSetup(this);
    *(_WORD *)&this->m_bSurround = 0;
    this->m_bHeadphone = false;
    this->m_isInterleaved = false;
    if ( snd_surround.m_pParent != nullptr )
      m_nValue = snd_surround.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    switch ( m_nValue )
    {
      case 0:
        this->m_bHeadphone = true;
        goto LABEL_16;
      case 4:
        this->m_bSurround = true;
        v7 = 1;
        break;
      case 5:
      case 7:
        *(_WORD *)&this->m_bSurround = 257;
        v7 = 1;
        break;
      default:
LABEL_16:
        v7 = 2;
        break;
    }
    this->m_deviceChannels = v7;
    this->m_deviceSampleBits = 16;
    this->m_deviceDmaSpeed = 44100;
    _V_memset(dest: &format, fill: 0, count: 18);
    format.wBitsPerSample = this->m_deviceSampleBits;
    format.nBlockAlign = (unsigned __int16)v7 * format.wBitsPerSample / 8;
    format.wFormatTag = 1;
    format.nSamplesPerSec = this->m_deviceDmaSpeed;
    format.nChannels = v7;
    format.cbSize = 0;
    format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;
    _V_memset(dest: &dscaps, fill: 0, count: 96);
    dscaps.dwSize = 96;
    if ( pDS->GetCaps(this: pDS, a2: &dscaps) != 0 )
      _Warning(a1: "Couldn't get DS caps\n");
    if ( (dscaps.dwFlags & 0x20) != 0 )
    {
      _Warning(a1: "No DirectSound driver installed\n");
      this->Shutdown(this);
      return 1;
    }
    if ( pDS->SetCooperativeLevel(this: pDS, a2: *pmainwindow, a3: 3u) != 0 )
      goto LABEL_24;
    _V_memset(dest: (void *)&dsbuf, fill: 0, count: 36);
    dsbuf.dwSize = 36;
    dsbuf.dwFlags = 1;
    if ( snd_legacy_surround.m_pParent != nullptr && snd_legacy_surround.m_pParent->m_Value.m_nValue != 0
      || this->m_bSurround )
    {
      dsbuf.dwFlags = 17;
    }
    dsbuf.dwBufferBytes = 0;
    dsbuf.lpwfxFormat = nullptr;
    _V_memset(dest: &dsbcaps, fill: 0, count: 20);
    dsbcaps.dwSize = 20;
    v8 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-snoforceformat", a3: 0) == 0
      && pDS->CreateSoundBuffer(this: pDS, a2: &dsbuf, a3: &pDSPBuf, a4: nullptr) == 0 )
    {
      pformat = format;
      if ( pDSPBuf->SetFormat(this: pDSPBuf, a2: &pformat) != 0 )
      {
        if ( snd_firsttime )
          DevMsg(a1: "Set primary sound buffer format: no\n");
      }
      else
      {
        if ( snd_firsttime )
          DevMsg(a1: "Set primary sound buffer format: yes\n");
        primary_format_set = true;
      }
    }
    if ( !this->m_bSurround )
      goto LABEL_52;
    this->m_bSurround = false;
    if ( snd_legacy_surround.m_pParent != nullptr
      && snd_legacy_surround.m_pParent->m_Value.m_nValue != 0
      && snd_surround.m_pParent != nullptr )
    {
      v9 = snd_surround.m_pParent->m_Value.m_nValue;
      if ( v9 == 4 )
      {
        inited = CAudioDirectSound::SNDDMA_InitSurround(
                   this,
                   a2: 0,
                   a3: (int)this,
                   lpDS: pDS,
                   lpFormat: (IDirectSound3DListener *)&format,
                   lpdsbc: &dsbcaps,
                   cchan: 4);
      }
      else
      {
        if ( v9 != 5 && v9 != 7 )
          goto LABEL_47;
        inited = CAudioDirectSound::SNDDMA_InitSurround(
                   this,
                   a2: 0,
                   a3: (int)this,
                   lpDS: pDS,
                   lpFormat: (IDirectSound3DListener *)&format,
                   lpdsbc: &dsbcaps,
                   cchan: 5);
        this->m_bSurroundCenter = inited;
      }
      this->m_bSurround = inited;
    }
LABEL_47:
    if ( this->m_bSurround )
      goto LABEL_74;
    v11 = 6;
    if ( snd_surround.m_pParent == nullptr || snd_surround.m_pParent->m_Value.m_nValue < 5 )
      v11 = 4;
    v12 = CAudioDirectSound::SNDDMA_InitInterleaved(this, lpDS: pDS, lpFormat: &format, channelCount: v11);
    this->m_bSurround = v12;
    if ( v12 )
      goto LABEL_74;
LABEL_52:
    if ( primary_format_set
      && (v13 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v13 + 12))(a1: v13, a2: "-primarysound", a3: 0) != 0) )
    {
      if ( pDS->SetCooperativeLevel(this: pDS, a2: *pmainwindow, a3: 4u) != 0 )
      {
LABEL_24:
        _Warning(a1: "Set coop level failed\n");
LABEL_77:
        this->Shutdown(this);
        return 1;
      }
      _V_memset(dest: &dsbcaps, fill: 0, count: 20);
      dsbcaps.dwSize = 20;
      if ( pDSPBuf->GetCaps(this: pDSPBuf, a2: &dsbcaps) != 0 )
      {
        _Msg(a1: "DS:GetCaps failed\n");
        return 1;
      }
      pDSBuf = pDSPBuf;
      DevMsg(a1: "Using primary sound buffer\n");
    }
    else
    {
      _V_memset(dest: (void *)&dsbuf, fill: 0, count: 36);
      dsbuf.dwSize = 36;
      dsbuf.dwFlags = 8;
      dsbuf.dwBufferBytes = 0x10000;
      dsbuf.lpwfxFormat = &format;
      if ( snd_mute_losefocus.m_pParent == nullptr || snd_mute_losefocus.m_pParent->m_Value.m_nValue == 0 )
        dsbuf.dwFlags = 32776;
      if ( pDS->CreateSoundBuffer(this: pDS, a2: &dsbuf, a3: &pDSBuf, a4: nullptr) != 0 )
      {
        _Warning(a1: "DS:CreateSoundBuffer Failed");
        goto LABEL_77;
      }
      wBitsPerSample = format.wBitsPerSample;
      nSamplesPerSec = format.nSamplesPerSec;
      this->m_deviceChannels = format.nChannels;
      this->m_deviceSampleBits = wBitsPerSample;
      this->m_deviceDmaSpeed = nSamplesPerSec;
      _V_memset(dest: &dsbcaps, fill: 0, count: 20);
      dsbcaps.dwSize = 20;
      if ( pDSBuf->GetCaps(this: pDSBuf, a2: &dsbcaps) != 0 )
      {
        _Warning(a1: "DS:GetCaps failed\n");
        this->Shutdown(this);
        return 1;
      }
      if ( !snd_firsttime )
        goto LABEL_69;
      DevMsg(a1: "Using secondary sound buffer\n");
    }
    if ( snd_firsttime )
    {
      v16 = this->DeviceDmaSpeed(this);
      v17 = ((int (__thiscall *)(CAudioDirectSound *, int))this->DeviceSampleBits)(a1: this, a2: v16);
      v18 = ((int (__thiscall *)(CAudioDirectSound *, int))this->DeviceChannels)(a1: this, a2: v17);
      DevMsg(a1: "   %d channel(s)\n   %d bits/sample\n   %d samples/sec\n", v18, v22, v23);
    }
LABEL_69:
    dwBufferBytes = dsbcaps.dwBufferBytes;
    this->m_bufferSizeBytes = dsbcaps.dwBufferBytes;
    v20 = 0;
    v21 = pDSBuf->Lock(
            this: pDSBuf,
            a2: 0,
            a3: dwBufferBytes,
            a4: &lpData,
            a5: &dwSize,
            a6: nullptr,
            a7: nullptr,
            a8: 0);
    if ( v21 != 0 )
    {
      while ( 1 )
      {
        if ( v21 != -2005401450 )
        {
          _Warning(a1: "SNDDMA_InitDirect: DS::Lock Sound Buffer Failed\n");
          goto LABEL_77;
        }
        if ( ++v20 > 10000 )
          break;
        v21 = pDSBuf->Lock(
                this: pDSBuf,
                a2: 0,
                a3: this->m_bufferSizeBytes,
                a4: &lpData,
                a5: &dwSize,
                a6: nullptr,
                a7: nullptr,
                a8: 0);
        if ( v21 == 0 )
          goto LABEL_73;
      }
      _Warning(a1: "SNDDMA_InitDirect: DS: couldn't restore buffer\n");
      goto LABEL_77;
    }
LABEL_73:
    _V_memset(dest: lpData, fill: 0, count: dwSize);
    pDSBuf->Unlock(this: pDSBuf, a2: lpData, a3: dwSize, a4: nullptr, a5: 0);
    pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
    lpData = nullptr;
    pDSBuf->Stop(this: pDSBuf);
    pDSBuf->GetCurrentPosition(this: pDSBuf, a2: &this->m_outputBufferStartOffset, a3: &dwWrite);
    pDSBuf->Play(this: pDSBuf, a2: 0, a3: 0, a4: 1u);
LABEL_74:
    this->m_deviceSampleCount = this->m_bufferSizeBytes / this->DeviceSampleBytes(this);
    return 0;
  }
  if ( v5 == -2005401590 )
    return 2;
  DevMsg(a1: "DirectSound create failed\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B340
// Name: public: virtual void CAudioDirectSound::TransferSamples(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioDirectSound::TransferSamples(CAudioDirectSound *this, __int64 end)
{
  unsigned int v2; // ebx
  unsigned int v4; // edi
  unsigned int dwSize; // [esp+Ch] [ebp-8h] BYREF
  unsigned int *pBuffer; // [esp+10h] [ebp-4h] BYREF

  v2 = HIDWORD(g_paintedtime);
  v4 = g_paintedtime;
  if ( this->m_bSurround )
  {
    if ( this->m_isInterleaved )
      CAudioDirectSound::S_TransferSurround16Interleaved(
        this,
        pfront: g_curpaintbuffer,
        prear: (int)g_currearpaintbuffer,
        pcenter: g_curcenterpaintbuffer,
        lpaintedtime: g_paintedtime,
        endtime: end);
    else
      CAudioDirectSound::S_TransferSurround16(
        this,
        pfront: g_curpaintbuffer,
        prear: g_currearpaintbuffer,
        pcenter: g_curcenterpaintbuffer,
        lpaintedtime: g_paintedtime,
        endtime: end,
        cchan: this->m_bSurroundCenter + 4);
  }
  else if ( snd_lockpartial.m_pParent != nullptr
         && snd_lockpartial.m_pParent->m_Value.m_nValue != 0
         && this->DeviceChannels(this) == 2
         && this->DeviceSampleBits(this) == 16
         && !SND_IsRecording() )
  {
    CAudioDirectSound::S_TransferSurround16Interleaved(
      this,
      pfront: g_curpaintbuffer,
      prear: 0,
      pcenter: nullptr,
      lpaintedtime: __SPAIR64__(v2, v4),
      endtime: end);
  }
  else
  {
    pBuffer = nullptr;
    dwSize = 0;
    if ( CAudioDirectSound::LockDSBuffer(
           this,
           pBuffer: pDSBuf,
           pdwWriteBuffer: (void **)&pBuffer,
           pdwSizeBuffer: &dwSize,
           pBufferName: "DS_STEREO",
           lockFlags: 0) != 0 )
    {
      if ( pBuffer != nullptr )
      {
        if ( this->DeviceChannels(this) == 2 && this->DeviceSampleBits(this) == 16 )
          S_TransferStereo16(
            pOutput: pBuffer,
            pfront: g_curpaintbuffer,
            lpaintedtime: __SPAIR64__(v2, v4),
            endtime: end);
        else
          S_TransferPaintBuffer(
            pOutput: pBuffer,
            pfront: g_curpaintbuffer,
            lpaintedtime: __SPAIR64__(v2, v4),
            endtime: end);
        pDSBuf->Unlock(this: pDSBuf, a2: pBuffer, a3: dwSize, a4: nullptr, a5: 0);
      }
    }
    else
    {
      S_Shutdown();
      S_Startup();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B4E0
// Name: public: virtual bool CAudioDirectSound::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAudioDirectSound::Init(CAudioDirectSound *this)
{
  bool v1; // zf

  v1 = !first;
  this->m_hInstDS = nullptr;
  if ( !v1 )
  {
    ConVar::InstallChangeCallback(this: &snd_surround, callback: OnSndSurroundCvarChanged, bInvoke: true);
    ConVar::InstallChangeCallback(
      this: &snd_legacy_surround,
      callback: (void (__cdecl *)(IConVar *, const char *, float))OnSndSurroundLegacyChanged,
      bInvoke: true);
    ConVar::InstallChangeCallback(this: &snd_mute_losefocus, callback: OnSndVarChanged, bInvoke: true);
    first = false;
  }
  if ( CAudioDirectSound::SNDDMA_InitDirect(this) != 0 )
    return 0;
  if ( g_pBIK != nullptr )
    g_pBIK->SetDirectSoundDevice(this: g_pBIK, a2: pDS);
  return 1;
}

} // namespace engine_xlsp
