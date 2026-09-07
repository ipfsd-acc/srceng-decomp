// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/soundcombiner.cpp
// Functions: 207
// ============================================================

#include "public\soundcombiner.h"

//------------------------------------------------------------------------------
// Address: 0x00411F90
// Name: private: bool CSoundCombiner::InitSplicer(class IFileSystem __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::InitSplicer(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        int samplerate,
        int numchannels,
        int bitspersample)
{
  CAudioWaveOutput *v6; // eax
  OutFileRIFF *v8; // eax
  OutFileRIFF *v9; // eax
  IterateOutputRIFF *v10; // eax
  IterateOutputRIFF *v11; // eax
  int v12; // edx
  unsigned int m_nSampleRate; // ecx
  char basepath[512]; // [esp+4h] [ebp-214h] BYREF
  tWAVEFORMATEX format; // [esp+204h] [ebp-14h] BYREF

  this->m_nSampleRate = samplerate;
  this->m_nBitsPerSample = bitspersample;
  this->m_nBytesPerSample = bitspersample >> 3;
  this->m_nNumChannels = numchannels;
  v6 = (CAudioWaveOutput *)sound->GetAudioOutput(this: sound);
  this->m_pWaveOutput = v6;
  if ( v6 != nullptr )
  {
    V_ExtractFilePath(path: this->m_szOutFile, dest: basepath, destSize: 512);
    filesystem->CreateDirHierarchy(this: filesystem, a2: basepath, a3: "GAME");
    v8 = (OutFileRIFF *)operator new(nSize: 0x1Cu);
    if ( v8 != nullptr )
      v9 = OutFileRIFF::OutFileRIFF(this: v8, pFileName: this->m_szOutFile, io: &io_out);
    else
      v9 = nullptr;
    this->m_pOutRIFF = v9;
    if ( v9 != nullptr )
    {
      v10 = (IterateOutputRIFF *)operator new(nSize: 0x1Cu);
      if ( v10 != nullptr )
        v11 = IterateOutputRIFF::IterateOutputRIFF(this: v10, riff: this->m_pOutRIFF);
      else
        v11 = nullptr;
      this->m_pOutIterator = v11;
      if ( v11 != nullptr )
      {
        format.cbSize = 18;
        v12 = this->m_nNumChannels * this->m_nBytesPerSample;
        format.wFormatTag = 1;
        m_nSampleRate = this->m_nSampleRate;
        format.nAvgBytesPerSec = m_nSampleRate * v12;
        format.nChannels = this->m_nNumChannels;
        format.wBitsPerSample = this->m_nBitsPerSample;
        format.nSamplesPerSec = m_nSampleRate;
        format.nBlockAlign = 1;
        IterateOutputRIFF::ChunkWrite(this: v11, chunkname: 0x20746D66u, pOutput: &format, size: 18);
        return 1;
      }
      else
      {
        _Warning(a1: "CSoundCombiner::InitSplicer  m_pOutIterator == NULL\n");
        return 0;
      }
    }
    else
    {
      _Warning(a1: "CSoundCombiner::InitSplicer  m_pOutRIFF == NULL\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "CSoundCombiner::InitSplicer  m_pWaveOutput == NULL\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004120F0
// Name: public: virtual int StdIOWriteBinary::create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall StdIOWriteBinary::create(StdIOWriteBinary *this, const char *pFileName)
{
  return filesystem->Open(this: &filesystem->IBaseFileSystem, a2: pFileName, a3: "wb", a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00412120
// Name: public: virtual int StdIOWriteBinary::write(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StdIOWriteBinary::write(StdIOWriteBinary *this, void *pData, int size, void *file)
{
  return filesystem->Write(this: &filesystem->IBaseFileSystem, a2: pData, a3: size, a4: file);
}

//------------------------------------------------------------------------------
// Address: 0x00412140
// Name: public: virtual void StdIOWriteBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StdIOWriteBinary::close(StdIOWriteBinary *this, void *file)
{
  filesystem->Close(this: &filesystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x00412160
// Name: public: virtual void StdIOWriteBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StdIOWriteBinary::seek(StdIOWriteBinary *this, void *file, int pos)
{
  filesystem->Seek(this: &filesystem->IBaseFileSystem, a2: file, a3: pos, a4: FILESYSTEM_SEEK_HEAD);
}

//------------------------------------------------------------------------------
// Address: 0x00412190
// Name: public: virtual unsigned int StdIOWriteBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall StdIOWriteBinary::tell(StdIOWriteBinary *this, void *file)
{
  return filesystem->Tell(this: &filesystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x004121B0
// Name: private: bool CSoundCombiner::AppendWaveData(int __near &,class CAudioSource __near *,class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSoundCombiner::AppendWaveData@<al>(
        CSoundCombiner *this@<ecx>,
        int a2@<edi>,
        int *currentsample,
        CAudioSource *wave,
        CAudioMixer *mixer)
{
  CAudioWaveOutput *m_pWaveOutput; // ecx
  CAudioMixer *v7; // ebx
  CAudioMixer_vtbl *v8; // edi
  int v9; // eax
  int m_nNumChannels; // eax
  int v11; // eax
  float v12; // xmm0_4
  __int16 *v13; // ecx
  int m_nBytesPerSample; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  IterateOutputRIFF *m_pOutIterator; // ecx
  CAudioMixer_vtbl *v19; // edi
  int v20; // eax
  int v23; // [esp-4h] [ebp-28h]
  channel_s channel; // [esp+8h] [ebp-1Ch] BYREF
  __int16 samples[3]; // [esp+1Ch] [ebp-8h] BYREF
  char v26; // [esp+23h] [ebp-1h] BYREF

  m_pWaveOutput = this->m_pWaveOutput;
  *(_QWORD *)&channel.rleftvol = 0;
  channel.leftvol = 255;
  channel.rightvol = 255;
  channel.pitch = 1.0;
  m_pWaveOutput->m_audioDevice.MixBegin(this: &m_pWaveOutput->m_audioDevice);
  v7 = mixer;
  v8 = mixer->__vftable;
  v9 = ((int (__thiscall *)(CAudioSource *, int))wave->SampleRate)(a1: wave, a2: 1);
  if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, _DWORD, int, int))v8->MixDataToDevice)(
         a1: v7,
         a2: &this->m_pWaveOutput->m_audioDevice,
         a3: &channel,
         a4: *currentsample,
         a5: 1,
         a6: v9) != 0 )
  {
    while ( 1 )
    {
      CAudioDeviceSWMix::TransferBufferStereo16(
        this: &this->m_pWaveOutput->m_audioDevice,
        pOutput: samples,
        sampleCount: 1);
      *currentsample = ((int (__thiscall *)(CAudioMixer *, int))v7->GetSamplePosition)(a1: v7, a2);
      m_nNumChannels = this->m_nNumChannels;
      if ( m_nNumChannels == 1 )
        break;
      if ( m_nNumChannels == 2 )
      {
        m_nBytesPerSample = this->m_nBytesPerSample;
        if ( m_nBytesPerSample == 1 )
        {
          v15 = -127.0;
          v16 = (float)(samples[0] >> 8);
          v17 = (float)(samples[1] >> 8);
          if ( v16 >= -127.0 )
          {
            if ( v16 > 127.0 )
              v16 = 127.0;
          }
          else
          {
            v16 = -127.0;
          }
          if ( v17 >= -127.0 )
          {
            if ( v17 <= 127.0 )
              v15 = (float)(samples[1] >> 8);
            else
              v15 = 127.0;
          }
          m_pOutIterator = this->m_pOutIterator;
          HIBYTE(mixer) = (int)(float)(v16 + 127.0);
          v26 = (int)(float)(v15 + 127.0);
          IterateOutputRIFF::ChunkWriteData(this: m_pOutIterator, pOutput: (char *)&mixer + 3, size: 1);
          IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &v26, size: 1);
          goto LABEL_25;
        }
        if ( m_nBytesPerSample == 2 )
        {
          IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: samples, size: 2);
          v23 = 2;
          v13 = &samples[1];
LABEL_24:
          IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: v13, size: v23);
        }
      }
LABEL_25:
      this->m_pWaveOutput->m_audioDevice.MixBegin(this: &this->m_pWaveOutput->m_audioDevice);
      v19 = v7->__vftable;
      a2 = 1;
      v20 = wave->SampleRate(this: wave);
      if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, _DWORD, int, int))v19->MixDataToDevice)(
             a1: v7,
             a2: &this->m_pWaveOutput->m_audioDevice,
             a3: &channel,
             a4: *currentsample,
             a5: 1,
             a6: v20) == 0 )
        return 1;
    }
    v11 = this->m_nBytesPerSample;
    if ( v11 != 1 )
    {
      if ( v11 == 2 )
      {
        mixer = (CAudioMixer *)(unsigned __int16)(int)(float)((float)((float)samples[0] + (float)samples[1]) * 0.5);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &mixer, size: 2);
      }
      goto LABEL_25;
    }
    v12 = (float)((float)(samples[0] >> 8) + (float)(samples[1] >> 8)) * 0.5;
    if ( v12 >= -127.0 )
    {
      if ( v12 > 127.0 )
        v12 = 127.0;
    }
    else
    {
      v12 = -127.0;
    }
    HIBYTE(mixer) = (int)(float)(v12 + 127.0);
    v23 = 1;
    v13 = (__int16 *)((char *)&mixer + 3);
    goto LABEL_24;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412420
// Name: private: unsigned int CSoundCombiner::ComputeChecksum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSoundCombiner::ComputeChecksum(CSoundCombiner *this)
{
  int v2; // edi
  CSoundCombiner::CombinerWork *v3; // esi
  int v4; // eax
  int c; // [esp+8h] [ebp-Ch]
  unsigned int chk; // [esp+Ch] [ebp-8h] BYREF
  unsigned int crc; // [esp+10h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  v2 = 0;
  c = this->m_Work.m_Size;
  if ( c > 0 )
  {
    do
    {
      v3 = this->m_Work.m_Memory.m_pMemory[v2];
      chk = CSentence::ComputeDataCheckSum(this: &v3->sentence);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &chk, nBuffer: 4);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &v3->entry->startoffset, nBuffer: 4);
      v4 = _V_strlen(str: v3->entry->wavefile);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v3->entry, nBuffer: v4);
      ++v2;
    }
    while ( v2 < c );
  }
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x004124B0
// Name: private: bool CSoundCombiner::VerifyFilesExist(class IFileSystem __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::VerifyFilesExist(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  int v3; // edi
  CombinerEntry *v4; // esi
  int c; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = 0;
  c = info->m_Size;
  i = 0;
  if ( c <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = &info->m_Memory.m_pMemory[v3];
    if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: (const char *)v4, a3: nullptr) )
      break;
    ++v3;
    if ( ++i >= c )
      return 1;
  }
  _Warning(a1: "CSoundCombiner::VerifyFilesExist: missing file %s\n", v4->wavefile);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412520
// Name: private: bool CSoundCombiner::LoadSpliceAudioSources(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::LoadSpliceAudioSources(CSoundCombiner *this)
{
  int v1; // ebx
  CSoundCombiner::CombinerWork *v3; // edi
  CAudioSource *v4; // esi
  int v5; // eax
  int c; // [esp+Ch] [ebp-8h]
  CSoundCombiner *v7; // [esp+10h] [ebp-4h]

  v1 = 0;
  v7 = this;
  c = this->m_Work.m_Size;
  if ( c <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = this->m_Work.m_Memory.m_pMemory[v1];
    v4 = sound->LoadSound(this: sound, a2: v3->entry);
    if ( v4 == nullptr )
    {
      _Warning(a1: "CSoundCombiner::LoadSpliceAudioSources  LoadSound failed '%s'\n", v3->entry->wavefile);
      return 0;
    }
    v5 = (int)v4->CreateMixer(this: v4);
    if ( v5 == 0 )
      break;
    v3->wave = v4;
    v3->mixer = (CAudioMixer *)v5;
    v3->duration = v4->GetRunningLength(this: v4);
    if ( ++v1 >= c )
      return 1;
    this = v7;
  }
  _Warning(a1: "CSoundCombiner::LoadSpliceAudioSources  CreateMixer failed '%s'\n", v3->entry->wavefile);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004125D0
// Name: private: bool CSoundCombiner::AppendSilence(int __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::AppendSilence(CSoundCombiner *this, int *currentsample, float duration)
{
  int v4; // ebx
  int i; // edi
  int m_nNumChannels; // ecx
  __int16 v7; // ax
  int m_nBytesPerSample; // ecx
  float v9; // xmm0_4
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  IterateOutputRIFF *m_pOutIterator; // ecx
  __int16 samples[3]; // [esp+8h] [ebp-8h] BYREF
  char v16; // [esp+Fh] [ebp-1h] BYREF

  v4 = (int)(float)((float)this->m_nSampleRate * duration) - 1;
  for ( i = 0x7FFF; v4 >= 0; --v4 )
  {
    i += random->RandomInt(this: random, a2: -20, a3: 20);
    if ( i <= 32842 )
    {
      if ( i < 32692 )
        i = 32692;
    }
    else
    {
      i = 32842;
    }
    m_nNumChannels = this->m_nNumChannels;
    v7 = (int)(float)((float)i * 0.000030517578);
    samples[0] = v7;
    samples[1] = v7;
    if ( m_nNumChannels == 1 )
    {
      m_nBytesPerSample = this->m_nBytesPerSample;
      if ( m_nBytesPerSample == 1 )
      {
        v9 = (float)((float)(v7 >> 8) * 2.0) * 0.5;
        if ( v9 >= -127.0 )
        {
          if ( v9 > 127.0 )
            v9 = 127.0;
        }
        else
        {
          v9 = -127.0;
        }
        HIBYTE(duration) = (int)(float)(v9 + 127.0);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: (char *)&duration + 3, size: 1);
      }
      else if ( m_nBytesPerSample == 2 )
      {
        LODWORD(duration) = (unsigned __int16)(int)(float)((float)((float)v7 * 2.0) * 0.5);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &duration, size: 2);
      }
    }
    else if ( m_nNumChannels == 2 )
    {
      v10 = this->m_nBytesPerSample;
      if ( v10 == 1 )
      {
        v11 = (float)(v7 >> 8);
        v12 = v11;
        if ( v11 >= -127.0 )
        {
          if ( v11 > 127.0 )
            v12 = 127.0;
        }
        else
        {
          v12 = -127.0;
        }
        if ( v11 >= -127.0 )
        {
          if ( v11 > 127.0 )
            v11 = 127.0;
        }
        else
        {
          v11 = -127.0;
        }
        v16 = (int)(float)(v11 + 127.0);
        m_pOutIterator = this->m_pOutIterator;
        HIBYTE(duration) = (int)(float)(v12 + 127.0);
        IterateOutputRIFF::ChunkWriteData(this: m_pOutIterator, pOutput: (char *)&duration + 3, size: 1);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &v16, size: 1);
      }
      else if ( v10 == 2 )
      {
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: samples, size: 2);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &samples[1], size: 2);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004127B0
// Name: private: int CSoundCombiner::ComputeBestNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundCombiner::ComputeBestNumChannels(CSoundCombiner *this)
{
  int m_Size; // ebx
  int v3; // esi
  CAudioSource *wave; // ecx

  m_Size = this->m_Work.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    wave = this->m_Work.m_Memory.m_pMemory[v3]->wave;
    if ( wave->GetNumChannels(this: wave) == 2 )
      break;
    if ( ++v3 >= m_Size )
      return 1;
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x004127F0
// Name: private: void CSoundCombiner::CleanupWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundCombiner::CleanupWork(CSoundCombiner *this)
{
  int v2; // edi
  CSoundCombiner::CombinerWork *v3; // ebx
  CAudioMixer *mixer; // ecx
  CAudioSource *wave; // ebx
  CSoundCombiner::CombinerWork **m_pMemory; // ecx
  CSoundCombiner::CombinerWork *v7; // ebx
  OutFileRIFF *m_pOutRIFF; // ebx
  int c; // [esp+Ch] [ebp-4h]

  v2 = 0;
  c = this->m_Work.m_Size;
  if ( c > 0 )
  {
    do
    {
      v3 = this->m_Work.m_Memory.m_pMemory[v2];
      mixer = v3->mixer;
      if ( mixer != nullptr )
        ((void (__thiscall *)(CAudioMixer *, int))mixer->dtr_CAudioMixer)(a1: mixer, a2: 1);
      wave = v3->wave;
      if ( wave != nullptr )
        ((void (__thiscall *)(CAudioSource *, int))wave->dtr_CAudioSource)(a1: wave, a2: 1);
      m_pMemory = this->m_Work.m_Memory.m_pMemory;
      v7 = m_pMemory[v2];
      if ( v7 != nullptr )
      {
        CSentence::~CSentence(this: &m_pMemory[v2]->sentence);
        free(pMem: v7);
      }
      ++v2;
    }
    while ( v2 < c );
  }
  this->m_Work.m_Size = 0;
  free(pMem: this->m_pOutIterator);
  m_pOutRIFF = this->m_pOutRIFF;
  this->m_pOutIterator = nullptr;
  if ( m_pOutRIFF != nullptr )
  {
    OutFileRIFF::~OutFileRIFF(this: m_pOutRIFF);
    free(pMem: m_pOutRIFF);
  }
  this->m_pOutRIFF = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00412880
// Name: private: bool CSoundCombiner::PerformSplicingOnWorkItems(class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::PerformSplicingOnWorkItems(CSoundCombiner *this, IFileSystem *filesystem)
{
  int v4; // eax
  int m_Size; // ecx
  int v6; // ebx
  CSoundCombiner::CombinerWork **m_pMemory; // edx
  int v8; // edi
  float v9; // xmm0_4
  unsigned int v10; // eax
  CAudioSource *starttime; // [esp+0h] [ebp-58h]
  CAudioMixer *v12; // [esp+4h] [ebp-54h]
  CUtlBuffer buf; // [esp+14h] [ebp-44h] BYREF
  float silence_time; // [esp+44h] [ebp-14h]
  float duration; // [esp+48h] [ebp-10h]
  int c; // [esp+4Ch] [ebp-Ch]
  int currentsample; // [esp+50h] [ebp-8h] BYREF
  CSoundCombiner::CombinerWork *nextitem; // [esp+54h] [ebp-4h]
  float timeoffset; // [esp+60h] [ebp+8h]

  if ( CSoundCombiner::LoadSpliceAudioSources(this) == 0 )
    return 0;
  v4 = CSoundCombiner::ComputeBestNumChannels(this);
  if ( CSoundCombiner::InitSplicer(this, filesystem, samplerate: 44100, numchannels: v4, bitspersample: 16) == 0 )
    return 0;
  IterateOutputRIFF::ChunkStart(this: this->m_pOutIterator, chunkname: 0x61746164u);
  timeoffset = 0.0;
  CSentence::Reset(this: &this->m_Combined);
  CSentence::SetText(this: &this->m_Combined, text: defaultValue);
  m_Size = this->m_Work.m_Size;
  v6 = 0;
  c = m_Size;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_Work.m_Memory.m_pMemory;
      v8 = (int)m_pMemory[v6];
      currentsample = 0;
      nextitem = nullptr;
      if ( v6 != m_Size - 1 )
        nextitem = m_pMemory[v6 + 1];
      v12 = *(CAudioMixer **)(v8 + 84);
      starttime = *(CAudioSource **)(v8 + 80);
      duration = *(float *)(v8 + 76);
      CSoundCombiner::AppendWaveData(this, a2: v8, &currentsample, wave: starttime, mixer: v12);
      CSentence::Append(this: &this->m_Combined, starttime: timeoffset, src: (const CSentence *)v8);
      v9 = duration + timeoffset;
      timeoffset = duration + timeoffset;
      if ( nextitem != nullptr )
      {
        silence_time = nextitem->entry->startoffset - v9;
        CSoundCombiner::AppendSilence(this, &currentsample, duration: silence_time);
        timeoffset = silence_time + timeoffset;
      }
      if ( ++v6 >= c )
        break;
      m_Size = c;
    }
  }
  IterateOutputRIFF::ChunkFinish(this: this->m_pOutIterator);
  v10 = CSoundCombiner::ComputeChecksum(this);
  CSentence::SetDataCheckSum(this: &this->m_Combined, chk: v10);
  IterateOutputRIFF::ChunkStart(this: this->m_pOutIterator, chunkname: 0x54414456u);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CSentence::SaveToBuffer(this: &this->m_Combined, &buf);
  IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  IterateOutputRIFF::ChunkFinish(this: this->m_pOutIterator);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412A30
// Name: private: bool CSoundCombiner::LoadSentenceFromWavFileUsingIO(char const __near *,class CSentence __near &,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::LoadSentenceFromWavFileUsingIO(
        CSoundCombiner *this,
        const char *wavfile,
        CSentence *sentence,
        IFileReadBinary *io)
{
  char v5; // bl
  int NumEvents; // eax
  int v7; // eax
  CUtlBuffer v8; // [esp+4h] [ebp-58h] BYREF
  IterateRIFF walk; // [esp+34h] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+4Ch] [ebp-10h] BYREF

  CSentence::Reset(this: sentence);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: wavfile, io);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v5 = 0;
    while ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      if ( v5 != 0 )
        break;
      if ( CAudioSourceMemWave::GetNumChannels(this: &walk) == 1413563478 )
      {
        v5 = 1;
        CUtlBuffer::CUtlBuffer(this: &v8, growSize: 0, initSize: 0, nFlags: 1);
        NumEvents = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::EnsureCapacity(this: &v8, num: NumEvents);
        IterateRIFF::ChunkRead(this: &walk, pOutput: v8.m_Memory.m_pMemory);
        v7 = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::SeekPut(this: &v8, type: SEEK_HEAD, offset: v7);
        CSentence::InitFromDataChunk(this: sentence, data: v8.m_Memory.m_pMemory, size: v8.m_Put);
        if ( v8.m_Memory.m_nGrowSize >= 0 && v8.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8.m_Memory.m_pMemory);
      }
      IterateRIFF::ChunkNext(this: &walk);
    }
    InFileRIFF::~InFileRIFF(this: &riff);
    return 1;
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412B80
// Name: private: bool CSoundCombiner::CreateWorkList(class IFileSystem __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::CreateWorkList(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  CSentence *v3; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Work; // esi
  int m_Size; // eax
  CSentence *v6; // eax
  CSentence *v7; // edi
  unsigned int v8; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CSentence **v13; // edi
  char fullpath[260]; // [esp+Ch] [ebp-114h] BYREF
  int c; // [esp+110h] [ebp-10h]
  CSoundCombiner *v17; // [esp+114h] [ebp-Ch]
  int i; // [esp+118h] [ebp-8h]
  unsigned int v19; // [esp+11Ch] [ebp-4h]

  v3 = nullptr;
  p_m_Work = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Work;
  this->m_Work.m_Size = 0;
  m_Size = info->m_Size;
  v17 = this;
  c = m_Size;
  i = 0;
  if ( m_Size <= 0 )
    return 1;
  v19 = 0;
  while ( 1 )
  {
    v6 = (CSentence *)operator new(nSize: 0x5Cu);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CSentence::CSentence(this: v6);
      v7[1].m_Words.m_Memory.m_pMemory = nullptr;
      v7[1].m_Words.m_Memory.m_nAllocationCount = 0;
      v7[1].m_Words.m_Memory.m_nGrowSize = 0;
      v7[1].m_szText = nullptr;
      v3 = v7;
    }
    v8 = v19;
    V_strncpy(pDest: fullpath, pSrc: info->m_Memory.m_pMemory[v19 / 0x108].wavefile, maxLen: 260);
    filesystem->GetLocalPath(this: filesystem, a2: &info->m_Memory.m_pMemory->wavefile[v8], a3: fullpath, a4: 260);
    if ( CSoundCombiner::LoadSentenceFromWavFileUsingIO(this: v17, wavfile: fullpath, sentence: v3, io: &io_in) == 0 )
      break;
    v3[1].m_Words.m_Memory.m_nGrowSize = (int)&info->m_Memory.m_pMemory->wavefile[v8];
    m_pMemory = p_m_Work[1].m_pMemory;
    m_nAllocationCount = p_m_Work->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: p_m_Work, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Work[1].m_pMemory;
    v11 = p_m_Work->m_pMemory;
    v12 = (char *)p_m_Work[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Work[1].m_nAllocationCount = (int)p_m_Work->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 4 * v12);
    v13 = (CSentence **)&p_m_Work->m_pMemory[(_DWORD)m_pMemory];
    if ( v13 != nullptr )
      *v13 = v3;
    v19 += 264;
    if ( ++i >= c )
      return 1;
    v3 = nullptr;
  }
  _Warning(a1: "CSoundCombiner::CreateWorkList couldn't load %s for work item (%d)\n", fullpath, i);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412CE0
// Name: private: bool CSoundCombiner::InternalCombineSoundFiles(class IFileSystem __near *,char const __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::InternalCombineSoundFiles(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        const char *outfile,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  V_strncpy(pDest: this->m_szOutFile, pSrc: outfile, maxLen: 260);
  if ( info->m_Size > 0 )
  {
    if ( CSoundCombiner::VerifyFilesExist(this, filesystem, info) != 0
      && CSoundCombiner::CreateWorkList(this, filesystem, info) != 0 )
    {
      CSoundCombiner::PerformSplicingOnWorkItems(this, filesystem);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    _Warning(a1: "CSoundCombiner::InternalCombineSoundFiles:  work item count is zero\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412D60
// Name: public: virtual bool CSoundCombiner::CombineSoundFiles(class IFileSystem __near *,char const __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::CombineSoundFiles(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        const char *outfile,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  char v5; // bl

  v5 = CSoundCombiner::InternalCombineSoundFiles(this, filesystem, outfile, info);
  CSoundCombiner::CleanupWork(this);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00412D90
// Name: public: virtual bool CSoundCombiner::IsCombinedFileChecksumValid(class IFileSystem __near *,char const __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundCombiner::IsCombinedFileChecksumValid(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        const char *outfile,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  unsigned int v5; // edi
  bool v6; // bl
  unsigned int v7; // eax
  char fullpath[260]; // [esp+Ch] [ebp-150h] BYREF
  CSentence sentence; // [esp+110h] [ebp-4Ch] BYREF

  if ( info->m_Size > 0 )
  {
    if ( CSoundCombiner::VerifyFilesExist(this, filesystem, info) != 0 )
    {
      if ( CSoundCombiner::CreateWorkList(this, filesystem, info) != 0 )
        v5 = CSoundCombiner::ComputeChecksum(this);
      else
        v5 = 0;
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    _Warning(a1: "CSoundCombiner::CheckSumWork:  work item count is zero\n");
    v5 = 0;
  }
  V_strncpy(pDest: fullpath, pSrc: outfile, maxLen: 260);
  filesystem->GetLocalPath(this: filesystem, a2: outfile, a3: fullpath, a4: 260);
  CSentence::CSentence(this: &sentence);
  v6 = false;
  if ( CSoundCombiner::LoadSentenceFromWavFileUsingIO(this, wavfile: fullpath, &sentence, io: &io_in) != 0 )
  {
    v7 = CSentence::GetDataCheckSum(this: &sentence);
    v6 = v5 == v7;
    if ( v5 != v7 )
      _Warning(a1: "  checksum computed %u, disk %u\n", v5, v7);
  }
  else
  {
    _Warning(a1: "CSoundCombiner::IsCombinedFileChecksumValid:  Unabled to load %s\n", fullpath);
  }
  CSoundCombiner::CleanupWork(this);
  CSentence::~CSentence(this: &sentence);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004E2151
// Name: __write
// Source: json
//------------------------------------------------------------------------------
int __cdecl _write(int fh, const void *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x004E2225
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (cmask == 0 ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result != 0) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E2278
// Name: __ismbblead_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead_l(unsigned __int8 tst, localeinfo_struct *plocinfo)
{
  return x_ismbbtype_l(plocinfo, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x004E2291
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x004E22A9
// Name: __mbsnbcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcpy_s(unsigned __int8 *_Arg1, unsigned int _Arg2, const unsigned __int8 *_Arg3, unsigned int _Arg4)
{
  return _mbsnbcpy_s_l(_Dst: _Arg1, _SizeInBytes: _Arg2, _Src: _Arg3, _CountInBytes: _Arg4, _LocInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E22C6
// Name: write_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char_0(_iobuf *f@<eax>, int *pnumwritten@<esi>, wchar_t ch)
{
  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr) && _fputwc_nolock(ch, str: f) == 0xFFFF )
    *pnumwritten = -1;
  else
    ++*pnumwritten;
}

//------------------------------------------------------------------------------
// Address: 0x004E22F5
// Name: write_string_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string_0(int len@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, wchar_t *string)
{
  int save_errno; // [esp+8h] [ebp-4h]

  save_errno = *_errno();
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    *_errno() = 0;
    while ( len > 0 )
    {
      --len;
      write_char_0(f, pnumwritten, ch: *string++);
      if ( *pnumwritten == -1 )
      {
        if ( *_errno() != 42 )
          break;
        write_char_0(f, pnumwritten, ch: 0x3Fu);
      }
    }
    if ( *_errno() == 0 )
      *_errno() = save_errno;
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E236E
// Name: __woutput_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _woutput_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  const wchar_t *v4; // esi
  int *v5; // edi
  bool v6; // zf
  int v8; // edx
  STATE v9; // ecx
  const wchar_t *v10; // esi
  int v11; // eax
  int v12; // eax
  _woutput_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v14; // ebx
  _woutput_l::__l2::<unnamed_type_text> v15; // edi
  _BYTE *j; // esi
  int v17; // eax
  __int16 *v18; // eax
  _woutput_l::__l2::<unnamed_type_text> v19; // ecx
  int v20; // eax
  int v21; // eax
  _WORD *v22; // esi
  __int64 v23; // rax
  int *v24; // edi
  int v25; // esi
  char *v26; // eax
  int v27; // ecx
  void (__cdecl *v28)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v29; // ebx
  void (__cdecl *v30)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v31)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v32; // ebx
  unsigned int v33; // edi
  char *i; // esi
  int v35; // eax
  int v36; // ecx
  unsigned __int64 v37; // kr08_8
  char *v38; // eax
  _BYTE *v39; // esi
  char *sz; // eax
  int v41; // ebx
  int v42; // edi
  int v43; // edi
  const char *v44; // edi
  int v45; // ebx
  int v46; // edi
  int v47; // eax
  int v48; // [esp-14h] [ebp-494h]
  int v49; // [esp-10h] [ebp-490h]
  int v50; // [esp-Ch] [ebp-48Ch]
  int v51; // [esp-8h] [ebp-488h]
  wchar_t v52; // [esp-4h] [ebp-484h]
  int padding; // [esp+10h] [ebp-470h]
  _CRT_DOUBLE tmp; // [esp+14h] [ebp-46Ch] BYREF
  int wchar; // [esp+1Ch] [ebp-464h] BYREF
  int capexp; // [esp+20h] [ebp-460h]
  STATE state; // [esp+24h] [ebp-45Ch]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-458h] BYREF
  int no_output; // [esp+38h] [ebp-448h]
  int hexadd; // [esp+3Ch] [ebp-444h]
  const wchar_t *v61; // [esp+40h] [ebp-440h]
  char *heapbuf; // [esp+44h] [ebp-43Ch]
  char tempchar[4]; // [esp+48h] [ebp-438h] BYREF
  wchar_t prefix[2]; // [esp+4Ch] [ebp-434h] BYREF
  int fldwidth; // [esp+50h] [ebp-430h]
  int bufferiswide; // [esp+54h] [ebp-42Ch]
  int prefixlen; // [esp+58h] [ebp-428h]
  _iobuf *f; // [esp+5Ch] [ebp-424h]
  int retval; // [esp+60h] [ebp-420h]
  char *v70; // [esp+64h] [ebp-41Ch]
  int charsout; // [esp+68h] [ebp-418h] BYREF
  int textlen; // [esp+6Ch] [ebp-414h]
  _woutput_l::__l2::<unnamed_type_text> text; // [esp+70h] [ebp-410h]
  int precision; // [esp+74h] [ebp-40Ch]
  int flags; // [esp+78h] [ebp-408h]
  _woutput_l::__l2::<unnamed_type_buffer> buffer; // [esp+7Ch] [ebp-404h] BYREF

  v4 = format;
  v5 = (int *)argptr;
  f = stream;
  v70 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr || format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    v6 = !_loc_update.updated;
    goto LABEL_3;
  }
  v8 = *format;
  v9 = ST_NORMAL;
  charsout = 0;
  textlen = 0;
  heapbuf = nullptr;
  retval = v8;
  if ( (_WORD)v8 == 0 )
  {
LABEL_217:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 2 )
  {
    v10 = v4 + 1;
    v61 = v10;
    if ( charsout < 0 )
      goto LABEL_217;
    if ( (unsigned __int16)(v8 - 32) > 0x58u )
      v11 = 0;
    else
      v11 = aE000[(unsigned __int16)v8] & 0xF;
    state = __lookuptable[8 * v11 + v9] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_0;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_214;
      case ST_FLAG:
        switch ( (unsigned __int16)v8 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_214;
      case ST_WIDTH:
        if ( (_WORD)v8 == 42 )
        {
          v70 = (char *)(v5 + 1);
          fldwidth = *v5;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + (unsigned __int16)v8 - 48;
        }
        goto LABEL_214;
      case ST_DOT:
        precision = 0;
        goto LABEL_214;
      case ST_PRECIS:
        if ( (_WORD)v8 == 42 )
        {
          v70 = (char *)(v5 + 1);
          precision = *v5;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + (unsigned __int16)v8 - 48;
        }
        goto LABEL_214;
      case ST_SIZE:
        switch ( (unsigned __int16)v8 )
        {
          case 'I':
            v12 = *v10;
            if ( v12 == 54 && v10[1] == 52 )
            {
              flags |= 0x8000u;
              v61 = v10 + 2;
            }
            else if ( v12 == 51 && v10[1] == 50 )
            {
              flags &= ~0x8000u;
              v61 = v10 + 2;
            }
            else if ( v12 != 100 && v12 != 105 && v12 != 111 && v12 != 117 && v12 != 120 && v12 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_0:
              bufferiswide = 1;
              write_char_0(f, pnumwritten: &charsout, ch: v8);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v10 == 108 )
            {
              flags |= 0x1000u;
              v61 = v10 + 1;
            }
            else
            {
              flags |= 0x10u;
            }
            break;
          case 'w':
            flags |= 0x800u;
            break;
          default:
            break;
        }
        goto LABEL_214;
      case ST_TYPE:
        if ( (unsigned __int16)v8 <= 0x64u )
        {
          if ( (unsigned __int16)v8 == 100 )
            goto LABEL_111;
          if ( (unsigned __int16)v8 > 0x53u )
          {
            if ( (unsigned __int16)v8 != 88 )
            {
              if ( (unsigned __int16)v8 == 90 )
              {
                v18 = (__int16 *)*v5;
                v70 = (char *)(v5 + 1);
                if ( v18 != nullptr && (v19.sz = *(char **)(v18 + 2), v19.sz != nullptr) )
                {
                  v20 = *v18;
                  text.sz = v19.sz;
                  if ( (flags & 0x800) != 0 )
                  {
                    v21 = v20 - (v20 >> 31);
                    bufferiswide = 1;
LABEL_179:
                    v20 = v21 >> 1;
                    goto LABEL_180;
                  }
                  bufferiswide = 0;
                }
                else
                {
                  text.sz = __nullstring;
                  strlen(buf: (unsigned __int8 *)__nullstring);
                }
LABEL_180:
                textlen = v20;
                goto LABEL_181;
              }
              if ( (unsigned __int16)v8 == 97 )
                goto LABEL_65;
              if ( (unsigned __int16)v8 != 99 )
                goto LABEL_181;
              goto LABEL_86;
            }
LABEL_134:
            hexadd = 7;
COMMON_HEX_0:
            retval = 16;
            if ( (flags & 0x80u) != 0 )
            {
              prefix[0] = 48;
              prefix[1] = hexadd + 81;
              prefixlen = 2;
            }
COMMON_INT_0:
            if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
            {
              v23 = *(_QWORD *)v5;
              v24 = v5 + 2;
            }
            else
            {
              v24 = v5 + 1;
              if ( (flags & 0x20) != 0 )
              {
                v70 = (char *)v24;
                if ( (flags & 0x40) != 0 )
                  LODWORD(v23) = *((__int16 *)v24 - 2);
                else
                  LODWORD(v23) = *((unsigned __int16 *)v24 - 2);
                v23 = (int)v23;
LABEL_151:
                if ( (flags & 0x40) != 0 && v23 < 0 )
                {
                  v23 = -v23;
                  flags |= 0x100u;
                }
                v32 = HIDWORD(v23);
                v33 = v23;
                if ( (flags & 0x9000) == 0 )
                  v32 = 0;
                if ( precision >= 0 )
                {
                  flags &= ~8u;
                  if ( precision > 512 )
                    precision = 512;
                }
                else
                {
                  precision = 1;
                }
                if ( (v32 | (unsigned int)v23) == 0 )
                  prefixlen = 0;
                for ( i = &buffer.sz[511]; ; --i )
                {
                  v35 = precision--;
                  if ( v35 <= 0 && (v32 | v33) == 0 )
                    break;
                  v36 = __PAIR64__(v32, v33) % retval + 48;
                  v37 = __PAIR64__(v32, v33) / retval;
                  v32 = HIDWORD(v37);
                  v33 = v37;
                  if ( v36 > 57 )
                    LOBYTE(v36) = hexadd + v36;
                  *i = v36;
                }
                v38 = (char *)((char *)&buffer.wz[255] + 1 - i);
                v39 = i + 1;
                textlen = (int)v38;
                text.sz = v39;
                if ( (flags & 0x200) != 0 && (v38 == nullptr || *v39 != 48) )
                {
                  *--text.sz = 48;
                  v20 = (int)(v38 + 1);
                  goto LABEL_180;
                }
                goto LABEL_181;
              }
              LODWORD(v23) = *(v24 - 1);
              if ( (flags & 0x40) != 0 )
                v23 = (int)v23;
              else
                HIDWORD(v23) = 0;
            }
            v70 = (char *)v24;
            goto LABEL_151;
          }
          switch ( (unsigned __int16)v8 )
          {
            case 'S':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_71:
              v14 = precision;
              if ( precision == -1 )
                v14 = 0x7FFFFFFF;
              v70 = (char *)(v5 + 1);
              v15.sz = (char *)*v5;
              text.sz = v15.sz;
              if ( (flags & 0x20) == 0 )
              {
                if ( v15.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v14 != 0 )
                {
                  --v14;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v21 = sz - text.sz;
                goto LABEL_179;
              }
              if ( v15.sz == nullptr )
                text.sz = __nullstring;
              textlen = 0;
              for ( j = text.sz; textlen < v14; ++textlen )
              {
                if ( *j == 0 )
                  break;
                if ( _isleadbyte_l(c: (unsigned __int8)*j, plocinfo: &_loc_update.localeinfo) != 0 )
                  ++j;
                ++j;
              }
              break;
            case 'A':
              goto LABEL_64;
            case 'C':
              if ( (flags & 0x830) == 0 )
                flags |= 0x20u;
LABEL_86:
              v17 = *(unsigned __int16 *)v5;
              bufferiswide = 1;
              v70 = (char *)(v5 + 1);
              wchar = v17;
              if ( (flags & 0x20) != 0 )
              {
                tempchar[0] = v17;
                tempchar[1] = 0;
                if ( _mbtowc_l(
                       pwc: (wchar_t *)&buffer,
                       s: tempchar,
                       n: _loc_update.localeinfo.locinfo->mb_cur_max,
                       plocinfo: &_loc_update.localeinfo) < 0 )
                  no_output = 1;
              }
              else
              {
                buffer.wz[0] = v17;
              }
              text.sz = (char *)&buffer;
              textlen = 1;
              break;
            case 'E':
            case 'G':
LABEL_64:
              v8 += 32;
              capexp = 1;
              retval = v8;
LABEL_65:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              textlen = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision <= 163 )
                  {
                    LOBYTE(v8) = retval;
                  }
                  else
                  {
                    v25 = precision + 349;
                    v26 = (char *)operator new(nSize: precision + 349);
                    LOBYTE(v8) = retval;
                    heapbuf = v26;
                    if ( v26 != nullptr )
                    {
                      text.sz = v26;
                      textlen = v25;
                      p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)v26;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = (_WORD)v8 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v27 = *(_DWORD *)v70;
              v70 += 8;
              HIDWORD(tmp.x) = *((_DWORD *)v70 - 1);
              v51 = capexp;
              v50 = precision;
              LODWORD(tmp.x) = v27;
              v49 = (char)v8;
              v48 = textlen;
              v28 = (void (__cdecl *)(_CRT_DOUBLE *, _woutput_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
              v28(a1: &tmp, a2: p_buffer, a3: v48, a4: v49, a5: v50, a6: v51, a7: &_loc_update);
              v29 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v30 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_51C4E4);
                v30(a1: p_buffer, a2: &_loc_update);
              }
              if ( (_WORD)retval == 103 && v29 == 0 )
              {
                v31 = (void (__cdecl *)(_woutput_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_51C4E0);
                v31(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_woutput_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: (unsigned __int8 *)p_buffer);
              goto LABEL_180;
            default:
              break;
          }
LABEL_181:
          if ( no_output != 0 )
            goto LABEL_212;
          if ( (flags & 0x40) != 0 )
          {
            if ( (flags & 0x100) != 0 )
            {
              v52 = 45;
            }
            else if ( (flags & 1) != 0 )
            {
              v52 = 43;
            }
            else
            {
              if ( (flags & 2) == 0 )
                goto LABEL_190;
              v52 = 32;
            }
            prefix[0] = v52;
            prefixlen = 1;
          }
LABEL_190:
          v41 = fldwidth - textlen - prefixlen;
          padding = v41;
          if ( (flags & 0xC) == 0 )
          {
            v42 = fldwidth - textlen - prefixlen;
            if ( v41 > 0 )
            {
              do
              {
                --v42;
                write_char_0(f, pnumwritten: &charsout, ch: 0x20u);
              }
              while ( charsout != -1 && v42 > 0 );
            }
          }
          write_string_0(len: prefixlen, f, pnumwritten: &charsout, string: prefix);
          if ( (flags & 8) != 0 && (flags & 4) == 0 )
          {
            v43 = v41;
            if ( v41 > 0 )
            {
              do
              {
                --v43;
                write_char_0(f, pnumwritten: &charsout, ch: 0x30u);
              }
              while ( charsout != -1 && v43 > 0 );
            }
          }
          if ( bufferiswide != 0 || textlen <= 0 )
          {
            write_string_0(len: textlen, f, pnumwritten: &charsout, string: text.wz);
          }
          else
          {
            v44 = text.sz;
            v45 = textlen;
            while ( 1 )
            {
              --v45;
              retval = _mbtowc_l(
                         pwc: (wchar_t *)&wchar,
                         s: v44,
                         n: _loc_update.localeinfo.locinfo->mb_cur_max,
                         plocinfo: &_loc_update.localeinfo);
              if ( retval <= 0 )
                break;
              write_char_0(f, pnumwritten: &charsout, ch: wchar);
              v44 += retval;
              if ( v45 <= 0 )
                goto LABEL_207;
            }
            charsout = -1;
          }
LABEL_207:
          if ( charsout >= 0 && (flags & 4) != 0 )
          {
            v46 = padding;
            do
            {
              if ( v46 <= 0 )
                break;
              --v46;
              write_char_0(f, pnumwritten: &charsout, ch: 0x20u);
            }
            while ( charsout != -1 );
          }
LABEL_212:
          if ( heapbuf != nullptr )
          {
            free(pMem: heapbuf);
            heapbuf = nullptr;
          }
LABEL_214:
          v4 = v61;
          v47 = *v61;
          retval = v47;
          if ( (_WORD)v47 == 0 )
            goto LABEL_217;
          v9 = state;
          v5 = (int *)v70;
          v8 = v47;
          continue;
        }
        if ( (unsigned __int16)v8 > 0x70u )
        {
          if ( (unsigned __int16)v8 != 115 )
          {
            if ( (unsigned __int16)v8 != 117 )
            {
              if ( (unsigned __int16)v8 != 120 )
                goto LABEL_181;
              hexadd = 39;
              goto COMMON_HEX_0;
            }
            goto LABEL_112;
          }
          goto LABEL_71;
        }
        if ( (unsigned __int16)v8 == 112 )
        {
          precision = 8;
          goto LABEL_134;
        }
        if ( (unsigned __int16)v8 < 0x65u )
          goto LABEL_181;
        if ( (unsigned __int16)v8 <= 0x67u )
          goto LABEL_65;
        if ( (unsigned __int16)v8 == 105 )
        {
LABEL_111:
          flags |= 0x40u;
LABEL_112:
          retval = 10;
          goto COMMON_INT_0;
        }
        if ( (unsigned __int16)v8 != 110 )
        {
          if ( (unsigned __int16)v8 != 111 )
            goto LABEL_181;
          retval = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
          goto COMMON_INT_0;
        }
        v22 = (_WORD *)*v5;
        v70 = (char *)(v5 + 1);
        if ( _get_printf_count_output() != 0 )
        {
          if ( (flags & 0x20) != 0 )
            *v22 = charsout;
          else
            *(_DWORD *)v22 = charsout;
          no_output = 1;
          goto LABEL_212;
        }
        *_errno() = 22;
        _invalid_parameter_noinfo();
        v6 = !_loc_update.updated;
LABEL_3:
        if ( !v6 )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      default:
        goto LABEL_214;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E2F32
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_error_support(
        unsigned __int64 *arg1,
        unsigned __int64 *arg2,
        unsigned __int64 *retval,
        error_types input_tag)
{
  int (__cdecl *v4)(_exception *); // eax
  double *v5; // esi
  unsigned __int64 v6; // st7
  unsigned __int64 *v7; // ecx
  double v8; // st7
  _exception exc; // [esp+0h] [ebp-28h] BYREF
  char double_zero[8]; // [esp+20h] [ebp-8h] BYREF

  memset(double_zero, 0, sizeof(double_zero));
  if ( pmatherr_set != 0 )
    v4 = (int (__cdecl *)(_exception *))DecodePointer(Ptr: _pmatherr);
  else
    v4 = _matherr;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.nam = (unsigned int)"log";
        goto LABEL_38;
      case log10_nan:
        exc.nam = (unsigned int)"log10";
        goto LABEL_38;
      case exp_nan:
        exc.nam = (unsigned int)"exp";
        goto LABEL_38;
      case atan_nan:
        exc.nam = (unsigned int)"atan";
        goto LABEL_38;
      case ceil_nan:
        exc.nam = (unsigned int)"ceil";
        goto LABEL_38;
      case floor_nan:
        exc.nam = (unsigned int)"floor";
        goto LABEL_38;
      case pow_nan:
        goto $LN36_7;
      case modf_nan:
        exc.nam = (unsigned int)"modf";
        goto LABEL_38;
      case acos_nan:
        goto $LN30_8;
      case asin_nan:
        goto $LN8_34;
      case sin_naninf:
        exc.nam = (unsigned int)"sin";
        goto LABEL_54;
      case cos_naninf:
        exc.nam = (unsigned int)"cos";
        goto LABEL_54;
      case tan_naninf:
        exc.nam = (unsigned int)"tan";
LABEL_54:
        v5 = (double *)retval;
        v8 = *(double *)arg1 * *(double *)double_zero;
        *(double *)retval = v8;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_55;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.typ = 3;
    exc.nam = (unsigned int)"exp10";
LABEL_17:
    v5 = (double *)retval;
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    exc.retval = *retval;
    if ( v4(pexcept: &exc) == 0 )
      *_errno() = 34;
    goto LABEL_57;
  }
  if ( input_tag > pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_zero_to_zero:
        *(double *)retval = 1.0;
        return;
      case pow_zero_to_negative:
        exc.typ = 2;
LABEL_16:
        exc.nam = (unsigned int)"pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36_7:
        exc.nam = (unsigned int)"pow";
        break;
      case pow_nan_to_zero:
        exc.nam = (unsigned int)"pow";
LABEL_38:
        v7 = arg1;
        v5 = (double *)retval;
        *retval = *arg1;
LABEL_24:
        exc.arg1 = *v7;
        exc.arg2 = *arg2;
        v8 = *v5;
LABEL_55:
        *(double *)&exc.retval = v8;
        exc.typ = 1;
        if ( v4(pexcept: &exc) == 0 )
          *_errno() = 33;
        goto LABEL_57;
      case acos_gt_one:
$LN30_8:
        exc.nam = (unsigned int)"acos";
        break;
      case asin_gt_one:
$LN8_34:
        exc.nam = (unsigned int)"asin";
        break;
      default:
        return;
    }
LABEL_23:
    v7 = arg1;
    v5 = (double *)retval;
    goto LABEL_24;
  }
  switch ( input_tag )
  {
    case pow_underflow:
      exc.nam = (unsigned int)"pow";
      goto LABEL_20;
    case log_zero:
      exc.typ = 2;
      exc.nam = (unsigned int)"log";
      goto LABEL_17;
    case log_negative:
      exc.nam = (unsigned int)"log";
      goto LABEL_23;
    case log10_zero:
      exc.typ = 2;
      exc.nam = (unsigned int)"log10";
      goto LABEL_17;
    case log10_negative:
      exc.nam = (unsigned int)"log10";
      goto LABEL_23;
    case exp_overflow:
      exc.typ = 3;
      exc.nam = (unsigned int)"exp";
      goto LABEL_17;
    default:
      break;
  }
  if ( input_tag != exp_underflow )
  {
    if ( input_tag != pow_overflow )
      return;
    exc.typ = 3;
    goto LABEL_16;
  }
  exc.nam = (unsigned int)"exp";
LABEL_20:
  v5 = (double *)retval;
  exc.arg1 = *arg1;
  exc.arg2 = *arg2;
  v6 = *retval;
  exc.typ = 4;
  exc.retval = v6;
  v4(pexcept: &exc);
LABEL_57:
  *v5 = *(double *)&exc.retval;
}

//------------------------------------------------------------------------------
// Address: 0x004E31FE
// Name: __floor_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _floor_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp(newctrl: newcw, _mask: 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xBu, x, savedcw: v1);
    }
    return _except1(flags: 8, opcode: 11, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
      return v4;
    }
    else
    {
      return _except1(flags: 16, opcode: 11, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E32E0
// Name: __cintrindisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp2@<eax>(double a1@<st1>, double a2@<st0>)
{
  _trandisp2(a1: a2, a2: a1);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x004E331E
// Name: __cintrindisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp1@<eax>(double a1@<st0>)
{
  _trandisp1(a1);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x004E335B
// Name: __ctrandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp2(double a1@<st1>, double a2@<st0>, unsigned __int64 parm1, unsigned __int64 parm2)
{
  _fload(parm: parm1);
  _fload(parm: parm2);
  _trandisp2(a1: a2, a2: a1);
  ctranexit();
}

//------------------------------------------------------------------------------
// Address: 0x004E339C
// Name: ctranexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ctranexit@<eax>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 712) &= ~1u;
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x004E33A3
// Name: cintrinexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall cintrinexit@<st0>(long double *a1@<ebp>, long double result@<st0>)
{
  char v2; // fps
  char v3; // al
  __int16 v4; // ax
  int v5; // ebx

  if ( __fastflag != 0 )
    return result;
  *(a1 - 90) = result;
  v3 = *((_BYTE *)a1 - 144);
  switch ( v3 )
  {
    case 0:
      goto checkinexact;
    case -1:
      if ( (*((_WORD *)a1 - 357) & 0x7FF0) != 0x7FF0 )
        goto checkinexact;
      goto haveoverflow_0;
    case -2:
      v4 = *((_WORD *)a1 - 357) & 0x7FF0;
      if ( v4 == 0 )
      {
        *(_DWORD *)((char *)a1 - 142) = 4;
        result = __FSCALE__(result, 1536.0);
        if ( fabs(result) < 2.225073858507201e-308 )
          result = result * 0.0;
        goto haveerror;
      }
      if ( v4 != 32752 )
      {
checkinexact:
        if ( (*((_WORD *)a1 - 82) & 0x20) != 0 || (v2 & 0x20) == 0 )
          return result;
        *(_DWORD *)((char *)a1 - 142) = 8;
        goto haveerror;
      }
haveoverflow_0:
      *(_DWORD *)((char *)a1 - 142) = 3;
      result = __FSCALE__(result, -1536.0);
      if ( fabs(result) > 1.797693134862316e308 )
        result = result * INFINITY;
      goto haveerror;
    default:
      break;
  }
  *(_DWORD *)((char *)a1 - 142) = v3;
haveerror:
  v5 = *((_DWORD *)a1 - 37) + 1;
  *(_DWORD *)((char *)a1 - 138) = v5;
  if ( (*(_BYTE *)(a1 - 89) & 1) == 0 )
  {
    *(_DWORD *)((char *)a1 - 134) = *((_DWORD *)a1 + 2);
    *(_DWORD *)((char *)a1 - 130) = *((_DWORD *)a1 + 3);
    if ( *(_BYTE *)(v5 + 12) != 1 )
    {
      *(_DWORD *)((char *)a1 - 126) = *((_DWORD *)a1 + 4);
      *(_DWORD *)((char *)a1 - 122) = *((_DWORD *)a1 + 5);
    }
  }
  *(long double *)((char *)a1 - 118) = result;
  _87except(
    opcode: *(char *)(*((_DWORD *)a1 - 37) + 14),
    exc: (_exception *)((char *)a1 - 142),
    pcw16: (unsigned __int16 *)a1 - 82);
  return *(long double *)((char *)a1 - 118);
}

//------------------------------------------------------------------------------
// Address: 0x004E34EA
// Name: __ctrandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp1(double a1@<st0>, unsigned __int64 parm1)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _trandisp1(a1);
  ctranexit(a1: (int)&savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x004E351D
// Name: __fload
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _fload(double parm)
{
  double tmp; // [esp+6h] [ebp-Ah]

  if ( (HIWORD(parm) & 0x7FF0) != 0x7FF0 )
    return parm;
  HIDWORD(tmp) = *(_QWORD *)&parm >> 21;
  LODWORD(tmp) = LODWORD(parm);
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x004E3560
// Name: _tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl tan(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x7F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x4E9C88);
  }
  JUMPOUT(0x4E35EF);
}

//------------------------------------------------------------------------------
// Address: 0x004E35A0
// Name: __CItan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CItan(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CItan;
  v2 = _mm_getcsr() & 0x7F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CItan_pentium4(a1);
  else
__CItan:
    _CItan_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x004E35DB
// Name: __CItan_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004E3690
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004E3725
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // eax
  wchar_t v7; // cx

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    *(const wchar_t *)((char *)v6 + (char *)_Dst - (char *)_Src) = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  result = 0;
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E3788
// Name: _wcsnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl wcsnlen(const wchar_t *wcs, unsigned int maxsize)
{
  unsigned int result; // eax

  for ( result = 0; result < maxsize; ++wcs )
  {
    if ( *wcs == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E37A8
// Name: wcstoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstoxl(const wchar_t *nptr, const wchar_t **endptr, unsigned int ibase, int flags)
{
  const wchar_t *v4; // edi
  wchar_t v6; // si
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  int v11; // eax
  const wchar_t *v12; // edi
  unsigned __int16 v13; // [esp-10h] [ebp-1Ch]
  unsigned int number; // [esp+8h] [ebp-4h]

  v4 = nptr;
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  number = 0;
  do
  {
    v6 = *v4;
    v13 = *v4++;
  }
  while ( iswctype(c: v13, mask: 8u) != 0 );
  if ( v6 == 45 )
  {
    flags |= 2u;
  }
  else if ( v6 != 43 )
  {
    goto LABEL_14;
  }
  v6 = *v4++;
LABEL_14:
  if ( ibase != 0 )
    goto LABEL_21;
  if ( _wchartodigit(ch: v6) == 0 )
  {
    v7 = *v4;
    if ( v7 != 120 && v7 != 88 )
    {
      ibase = 8;
      goto LABEL_26;
    }
    ibase = 16;
LABEL_21:
    if ( ibase == 16 && _wchartodigit(ch: v6) == 0 )
    {
      v8 = *v4;
      if ( v8 == 120 || v8 == 88 )
      {
        v6 = v4[1];
        v4 += 2;
      }
    }
    goto LABEL_26;
  }
  ibase = 10;
LABEL_26:
  v9 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v10 = _wchartodigit(ch: v6);
    if ( v10 == -1 )
    {
      if ( (v6 < 0x41u || v6 > 0x5Au) && (unsigned __int16)(v6 - 97) > 0x19u )
        break;
      v11 = v6;
      if ( (unsigned __int16)(v6 - 97) <= 0x19u )
        v11 = v6 - 32;
      v10 = v11 - 55;
    }
    if ( v10 >= ibase )
      break;
    flags |= 8u;
    if ( number < v9 || number == v9 && v10 <= 0xFFFFFFFF % ibase )
    {
      number = v10 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v6 = *v4++;
  }
  v12 = v4 - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v12 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v12;
  if ( (flags & 2) != 0 )
    return -number;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x004E396A
// Name: _wcstol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstol(const wchar_t *nptr, wchar_t **endptr, unsigned int ibase)
{
  return wcstoxl(nptr, (const wchar_t **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E3984
// Name: ___wstrgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __wstrgtold12_l(
        _LDBL12 *pld12,
        const wchar_t **p_end_ptr,
        const wchar_t *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  const wchar_t *v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  const wchar_t *v15; // edx
  char *v16; // ecx
  char *v17; // ecx
  int v18; // eax
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  char *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  _LDBL12 *v26; // ecx
  char v27; // al
  _LDBL12 *v28; // ecx
  int v29; // eax
  _LDBL12 *v30; // ebx
  __int16 v31; // ax
  __int16 v32; // si
  unsigned __int16 v33; // cx
  int v34; // eax
  _WORD *v35; // edi
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // esi
  __int16 v39; // cx
  unsigned int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // esi
  int v44; // eax
  int v45; // edi
  int v46; // eax
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-Ch] [ebp-8Ch]
  int v52; // [esp-Ch] [ebp-8Ch]
  _LDBL12 *v53; // [esp+8h] [ebp-78h]
  __int16 man_sign; // [esp+Ch] [ebp-74h]
  unsigned int result_flags; // [esp+10h] [ebp-70h]
  int found_decpoint; // [esp+14h] [ebp-6Ch]
  unsigned __int8 *found_decpointa; // [esp+14h] [ebp-6Ch]
  int pow; // [esp+18h] [ebp-68h]
  int powa; // [esp+18h] [ebp-68h]
  int exp_sign; // [esp+1Ch] [ebp-64h]
  int exp_signa; // [esp+1Ch] [ebp-64h]
  int found_exponent; // [esp+20h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+20h] [ebp-60h]
  int found_digit; // [esp+24h] [ebp-5Ch]
  int found_digita; // [esp+24h] [ebp-5Ch]
  char *manp; // [esp+28h] [ebp-58h]
  char *manpa; // [esp+28h] [ebp-58h]
  const wchar_t *savedp; // [esp+2Ch] [ebp-54h]
  int savedpa; // [esp+2Ch] [ebp-54h]
  int exp_adj; // [esp+30h] [ebp-50h]
  int exp_adja; // [esp+30h] [ebp-50h]
  unsigned int manlen; // [esp+34h] [ebp-4Ch]
  __int16 manlena; // [esp+34h] [ebp-4Ch]
  __int64 v74; // [esp+38h] [ebp-48h] BYREF
  int v75; // [esp+40h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+44h] [ebp-3Ch] BYREF
  _BYTE v77[12]; // [esp+54h] [ebp-2Ch] BYREF
  char buf[28]; // [esp+60h] [ebp-20h] BYREF

  v8 = 0;
  manp = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v10 = str;
  savedp = str;
  while ( 1 )
  {
    v11 = *v10;
    if ( v11 != 32 && v11 != 9 && v11 != 10 && v11 != 13 )
      break;
    ++v10;
  }
  while ( 2 )
  {
    v12 = *v10++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v13 = v12 - 43;
        if ( v13 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v14 = v13 - 2;
        if ( v14 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v14 != 3 )
          goto LABEL_74;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_11;
        if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v12 == 43 || v12 == 45 )
          goto LABEL_32;
        if ( v12 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v12 <= 67 || v12 > 69 && (unsigned int)(v12 - 100) > 1 )
          goto LABEL_74;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v10;
        }
        else
        {
          if ( v12 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v12 != 48 )
          {
LABEL_36:
            v15 = savedp;
            goto LABEL_81;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            v16 = manp;
            ++manlen;
            ++manp;
            *v16 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
        if ( (unsigned __int16)v12 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_45;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( (_WORD)v12 == 48 )
          {
            --exp_adj;
            LOWORD(v12) = *v10++;
          }
        }
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            v17 = manp++;
            --exp_adj;
            *v17 = v12 - 48;
          }
          LOWORD(v12) = *v10++;
        }
        v12 = (unsigned __int16)v12;
LABEL_45:
        if ( v12 != 43 && v12 != 45 )
          goto LABEL_28;
LABEL_32:
        --v10;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int16)(v12 - 48) > 9u )
          goto LABEL_36;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v10 - 2;
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v18 = v12 - 43;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 - 2;
        if ( v19 == 0 )
          goto LABEL_68;
        v20 = v19 == 3;
LABEL_66:
        if ( !v20 )
          goto LABEL_36;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int16)(v12 - 49) <= 8u )
          goto LABEL_62;
        v20 = (_WORD)v12 == 48;
        goto LABEL_66;
      case 8:
        found_exponent = 1;
        while ( (_WORD)v12 == 48 )
          LOWORD(v12) = *v10++;
        if ( (unsigned __int16)(v12 - 49) > 8u )
          goto LABEL_74;
LABEL_62:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v23 = 0;
        while ( 2 )
        {
          if ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          {
            v23 = 10 * v23 + (unsigned __int16)v12 - 48;
            if ( v23 <= 5200 )
            {
              LOWORD(v12) = *v10++;
              continue;
            }
            v23 = 5201;
          }
          break;
        }
        pow = v23;
        while ( (unsigned __int16)v12 >= 0x30u && (unsigned __int16)v12 <= 0x39u )
          LOWORD(v12) = *v10++;
LABEL_74:
        v15 = v10 - 1;
        goto LABEL_81;
      case 11:
        if ( implicit_E != 0 )
        {
          v21 = v12 - 43;
          savedp = v10 - 1;
          if ( v21 != 0 )
          {
            if ( v21 != 2 )
            {
              v15 = v10 - 1;
              goto LABEL_81;
            }
LABEL_68:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_69:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v15 = v10 - 1;
LABEL_81:
        *p_end_ptr = v15;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_177:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_178;
        }
        if ( manlen <= 0x18 )
        {
          v22 = manp;
        }
        else
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          manlen = 24;
          v22 = manp - 1;
          ++exp_adj;
        }
        if ( manlen == 0 )
          goto LABEL_177;
        while ( *--v22 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v24 = pow;
        if ( exp_sign < 0 )
          v24 = -pow;
        v25 = exp_adj + v24;
        if ( found_exponent == 0 )
          v25 += scale;
        if ( found_decpoint == 0 )
          v25 -= decpt;
        if ( v25 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_178;
        }
        if ( v25 < -5200 )
        {
          result_flags = 1;
          goto LABEL_177;
        }
        v26 = &_pow10pos[-8];
        savedpa = v25;
        if ( v25 != 0 )
        {
          if ( v25 < 0 )
          {
            savedpa = -v25;
            v26 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          if ( savedpa != 0 )
          {
            while ( 1 )
            {
              v27 = savedpa;
              savedpa >>= 3;
              v28 = v26 + 7;
              v29 = v27 & 7;
              v53 = v28;
              if ( v29 == 0 )
                goto LABEL_172;
              v30 = &v28[v29];
              if ( *(_WORD *)v30->ld12 >= 0x8000u )
              {
                v74 = *(_QWORD *)v30->ld12;
                v75 = *(_DWORD *)&v30->ld12[8];
                --*(_DWORD *)((char *)&v74 + 2);
                v30 = (_LDBL12 *)&v74;
              }
              manpa = nullptr;
              memset(v77, 0, sizeof(v77));
              v31 = *(_WORD *)&v30->ld12[10] & 0x7FFF;
              v32 = (*(_WORD *)&tmpld12.ld12[10] ^ *(_WORD *)&v30->ld12[10]) & 0x8000;
              manlena = v32;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF
                || (*(_WORD *)&v30->ld12[10] & 0x7FFF) == 0x7FFF
                || v33 > 0xBFFDu )
              {
                break;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_171:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                goto LABEL_172;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v30->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v30->ld12[4] != 0
                  || *(_DWORD *)v30->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v77[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v30->ld12[8];
                    do
                    {
                      exp_adja = 0;
                      v36 = *(unsigned __int16 *)found_exponenta * *(unsigned __int16 *)found_decpointa;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        exp_adja = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( exp_adja != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_181;
                  do
                  {
                    if ( *(int *)&v77[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v77;
                    *(_DWORD *)v77 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v77[4]);
                    v42 = *(__int64 *)&v77[4] >> 31;
                    --v39;
                    *(_DWORD *)&v77[4] = v41;
                    *(_DWORD *)&v77[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_181:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v77[0] & 1) != 0 )
                          ++manpa;
                        v44 = *(_DWORD *)&v77[8];
                        *(_DWORD *)&v77[8] >>= 1;
                        v45 = (v44 << 31) | (*(_DWORD *)&v77[4] >> 1);
                        v46 = *(__int64 *)v77 >> 1;
                        --v43;
                        *(_DWORD *)&v77[4] = v45;
                        *(_DWORD *)v77 = v46;
                      }
                      while ( v43 != 0 );
                      if ( manpa != nullptr )
                        *(_WORD *)v77 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v77 > 0x8000u || (*(_DWORD *)v77 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v77[2] == -1 )
                    {
                      *(_DWORD *)&v77[2] = 0;
                      if ( *(_DWORD *)&v77[6] == -1 )
                      {
                        *(_DWORD *)&v77[6] = 0;
                        if ( *(_WORD *)&v77[10] == 0xFFFF )
                        {
                          *(_WORD *)&v77[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v77[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v77[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v77[2];
                    }
                  }
                  if ( (unsigned __int16)v39 < 0x7FFFu )
                  {
                    *(_WORD *)tmpld12.ld12 = *(_WORD *)&v77[2];
                    *(_DWORD *)&tmpld12.ld12[2] = *(_DWORD *)&v77[4];
                    *(_DWORD *)&tmpld12.ld12[6] = *(_DWORD *)&v77[8];
                    *(_WORD *)&tmpld12.ld12[10] = manlena | v39;
                  }
                  else
                  {
                    *(_DWORD *)&tmpld12.ld12[4] = 0;
                    *(_DWORD *)tmpld12.ld12 = 0;
                    *(_DWORD *)&tmpld12.ld12[8] = manlena == 0 ? 2147450880 : -32768;
                  }
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
LABEL_172:
              if ( savedpa == 0 )
                goto LABEL_173;
              v26 = v53;
            }
            *(_DWORD *)&tmpld12.ld12[4] = 0;
            v34 = v32 == 0 ? 2147450880 : -32768;
            *(_DWORD *)tmpld12.ld12 = 0;
            goto LABEL_171;
          }
        }
LABEL_173:
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_178:
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_WORD *)pld12->ld12 = v47;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E40C4
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x004E40FD
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = (void (__cdecl *)())EncodePointer(Ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x004E410E
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void *enull)
{
  ctrlc_action = enull;
  ctrlbreak_action = (void (__cdecl *)(int))enull;
  abort_action = enull;
  term_action = (void (__cdecl *)(int))enull;
}

//------------------------------------------------------------------------------
// Address: 0x004E412C
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[12] );
  if ( result >= &pxcptacttab[12] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E4163
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))DecodePointer(Ptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x004E4170
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl raise(int signum)
{
  _tiddata *v1; // edi
  _tiddata *v2; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v5)(int); // eax
  void (__cdecl *v6)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v1 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v5 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v5 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = (void (__cdecl **)(int))&ctrlc_action;
      v5 = (void (__cdecl *)(int))ctrlc_action;
LABEL_18:
      siglock = 1;
      v6 = (void (__cdecl *)(int))DecodePointer(Ptr: v5);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter_noinfo();
        return -1;
      }
LABEL_15:
      p_XcptAction = (void (__cdecl **)(int))&abort_action;
      v5 = (void (__cdecl *)(int))abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v2 = _getptd_noexit();
  v1 = v2;
  if ( v2 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v2->_pxcptacttab)->XcptAction;
  v6 = *p_XcptAction;
LABEL_19:
  sigact = v6;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v1->_tpxcptinfoptrs;
    v1->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v1->_tfpecode;
    v1->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = 3; indx < 12; ++indx )
      *((_DWORD *)v1->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37_2;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37_2:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v1->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v1->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v1->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E4313
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004E4322
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x004E4340
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x004E4380
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E43D0
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x400000)
      && (PESection = _FindPESection(pImageBase: (unsigned __int8 *)0x400000, rva: (unsigned int)(pTarget - 0x400000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E448C
// Name: ___crtMessageBoxW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxW(const wchar_t *lpText, const wchar_t *lpCaption, unsigned int uType)
{
  HMODULE LibraryW; // eax
  HMODULE v4; // ebx
  int (__stdcall *MessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  BOOL (__stdcall *GetUserObjectInformationW)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v10)(void); // edi
  int (__stdcall *v11)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v12)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // ebx
  int v13; // eax
  int (*v14)(void); // eax
  int (__stdcall *v15)(HWND__ *); // eax
  int (__stdcall *v16)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int); // eax
  unsigned int nDummy; // [esp+Ch] [ebp-24h] BYREF
  const wchar_t *v19; // [esp+10h] [ebp-20h]
  const wchar_t *v20; // [esp+14h] [ebp-1Ch]
  void *enull; // [esp+18h] [ebp-18h]
  HWND__ *hWndParent; // [esp+1Ch] [ebp-14h]
  tagUSEROBJECTFLAGS uof; // [esp+20h] [ebp-10h] BYREF

  v19 = lpText;
  v20 = lpCaption;
  hWndParent = nullptr;
  enull = (void *)_encoded_null();
  if ( pfnMessageBox == nullptr )
  {
    LibraryW = LoadLibraryW(lpLibFileName: L"USER32.DLL");
    v4 = LibraryW;
    if ( LibraryW == nullptr )
      return 0;
    MessageBoxW = (int (__stdcall *)(HWND, LPCWSTR, LPCWSTR, UINT))GetProcAddress(
                                                                     hModule: LibraryW,
                                                                     lpProcName: "MessageBoxW");
    if ( MessageBoxW == nullptr )
      return 0;
    pfnMessageBox = EncodePointer(Ptr: MessageBoxW);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = EncodePointer(Ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = EncodePointer(Ptr: GetLastActivePopup);
    GetUserObjectInformationW = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                          hModule: v4,
                                                                                          lpProcName: "GetUserObjectInformationW");
    pfnGetUserObjectInformation = EncodePointer(Ptr: GetUserObjectInformationW);
    if ( pfnGetUserObjectInformation != nullptr )
    {
      GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                           hModule: v4,
                                                           lpProcName: "GetProcessWindowStation");
      pfnGetProcessWindowStation = EncodePointer(Ptr: GetProcessWindowStation);
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v10 = (int (*)(void))DecodePointer(Ptr: pfnGetProcessWindowStation),
        v11 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))DecodePointer(Ptr: pfnGetUserObjectInformation),
        v12 = v11,
        v10 == nullptr)
    || v11 == nullptr
    || (v13 = v10()) != 0 && v12(a1: v13, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v14 = (int (*)(void))DecodePointer(Ptr: pfnGetActiveWindow);
      if ( v14 != nullptr )
      {
        hWndParent = (HWND__ *)v14();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v15 = (int (__stdcall *)(HWND__ *))DecodePointer(Ptr: pfnGetLastActivePopup);
          if ( v15 != nullptr )
            hWndParent = (HWND__ *)v15(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    uType |= 0x200000u;
  }
  v16 = (int (__stdcall *)(HWND__ *, const wchar_t *, const wchar_t *, unsigned int))DecodePointer(Ptr: pfnMessageBox);
  if ( v16 != nullptr )
    return v16(a1: hWndParent, a2: v19, a3: v20, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E45F8
// Name: _wcscat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcscat_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  int result; // eax
  const wchar_t *v6; // ecx
  unsigned __int16 *v7; // edx
  int v8; // edx
  wchar_t v9; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v8 = (char *)v7 - (char *)_Src;
      do
      {
        v9 = *v6;
        *(const wchar_t *)((char *)v6 + v8) = *v6;
        ++v6;
        if ( v9 == 0 )
          break;
        --v3;
      }
      while ( v3 != 0 );
      result = 0;
      if ( v3 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return result;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter_noinfo();
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004E466D
// Name: _wcsncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcsncpy_s(unsigned __int16 *_Dst, unsigned int _SizeInWords, const wchar_t *_Src, unsigned int _Count)
{
  unsigned int v4; // ebx
  unsigned int v6; // edi
  int v7; // esi
  const wchar_t *v8; // ecx
  unsigned __int16 *v9; // eax
  wchar_t v10; // ax
  unsigned __int16 v11; // cx

  v4 = _Count;
  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v7 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter_noinfo();
      return v7;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInWords == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v8 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v9 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v10 = *v8;
      *(const wchar_t *)((char *)v8 + (char *)_Dst - (char *)_Src) = *v8;
      ++v8;
      if ( v10 == 0 )
        break;
      --v6;
    }
    while ( v6 != 0 );
  }
  else
  {
    do
    {
      v11 = *(unsigned __int16 *)((char *)v9 + (char *)_Src - (char *)_Dst);
      *v9++ = v11;
      if ( v11 == 0 )
        break;
      if ( --v6 == 0 )
        break;
      --v4;
    }
    while ( v4 != 0 );
    if ( v4 == 0 )
      *v9 = 0;
  }
  if ( v6 != 0 )
    return 0;
  if ( v4 != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v7 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInWords - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x004E473A
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_error_mode(int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = *(_DWORD *)&__error_mode;
      *(_DWORD *)&__error_mode = em;
      return result;
    }
    if ( em == 3 )
      return *(_DWORD *)&__error_mode;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4779
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tod(pld12: &ld12, d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E4821
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tof(pld12: &ld12, f: d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E48C9
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // ebx
  int v6; // eax
  int v7; // esi
  int v9; // edx
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  v6 = 0;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return v7;
  }
  v9 = digits;
  *buf = 0;
  if ( digits > 0 )
    v6 = digits;
  if ( sizeInBytes <= v6 + 1 )
  {
    *_errno() = 34;
    v7 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa != 0 )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v9;
    }
    while ( v9 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v9 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen(buf: (unsigned __int8 *)buf + 1);
    memmove(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)buf + 1, count: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E497C
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ebx
  int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  __int16 v7; // bx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // edx
  int v12; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 != 0 )
  {
    if ( (unsigned __int16)v3 == 2047 )
    {
      v8 = 0x7FFF;
      goto LABEL_10;
    }
    v7 = v3 + 15360;
  }
  else
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_14;
    }
    v7 = 15361;
    msb = 0;
  }
  v8 = v7;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  v12 = v5 << 11;
  while ( 1 )
  {
    *(_DWORD *)pld->ld = v12;
    *(_DWORD *)&pld->ld[4] = v11;
    if ( v11 < 0 )
      break;
    v11 = (*(_DWORD *)pld->ld >> 31) | (2 * v11);
    v12 = 2 * *(_DWORD *)pld->ld;
    --v8;
  }
  v10 = v8 | sign;
LABEL_14:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x004E4A2F
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  _LDOUBLE ld; // [esp+Ch] [ebp-30h] BYREF
  char *_Dst; // [esp+18h] [ebp-24h]
  _FloatOutStruct autofos; // [esp+1Ch] [ebp-20h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(_Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004E4AC0
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldvrm(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  int v5; // esi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  int result; // eax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v5 = v7 / (unsigned int)v6;
    v8 = (unsigned int)v5 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v5, HIDWORD(v8))
      || (HIDWORD(v8) = (a2 * (unsigned __int64)(unsigned int)v5) >> 32, v8 > a1) )
    {
      --v5;
    }
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    v5 = v4 / (unsigned int)a2;
  }
  result = v5;
  if ( v2 == 1 )
    return -v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E4B9F
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x004E4BA8
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _controlfp_s(unsigned int *_CurrentState, unsigned int newctrl, unsigned int mask)
{
  unsigned int v4; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    v4 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v4);
    else
      _control87(newctrl, mask: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E4C07
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  _iobuf *v1; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    if ( __piob[i] != nullptr )
    {
      v1 = (_iobuf *)__piob[i];
      if ( (v1->_flag & 0x83) != 0 && fclose(stream: v1) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
        free(pMem: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x004E4CA3
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isatty(int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return 0;
  }
  return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x004E4CF9
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  unsigned __int8 *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = (unsigned __int8 *)dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: v5, value: 0, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: (LPSTR)v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: v5, value: 0, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E4E4E
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E4E6B
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E4E73
// Name: __wcsnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicoll_l(
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  unsigned int v4; // ebx
  int result; // eax
  const wchar_t *v6; // esi
  unsigned int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int16 v10; // cx
  unsigned int v11; // eax
  int v12; // eax
  int *v13; // eax
  bool v14; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  v4 = count;
  if ( count == 0 )
    return 0;
  if ( _string1 == nullptr || (v6 = _string2, _string2 == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  if ( count > 0x7FFFFFFF )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v7 = _loc_update.localeinfo.locinfo->lc_handle[1];
  if ( v7 != 0 )
  {
    v12 = __crtCompareStringW(
            Locale: v7,
            dwCmpFlags: 0x1001u,
            lpString1: _string1,
            cchCount1: count,
            lpString2: _string2,
            cchCount2: count);
    if ( v12 == 0 )
    {
      v13 = _errno();
      v14 = !_loc_update.updated;
      *v13 = 22;
      if ( !v14 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    result = v12 - 2;
  }
  else
  {
    v8 = (char *)_string1 - (char *)_string2;
    do
    {
      v9 = *(const wchar_t *)((char *)v6 + v8);
      if ( v9 < 0x41 || v9 > 0x5A )
        v10 = *(const wchar_t *)((char *)v6 + v8);
      else
        v10 = v9 + 32;
      v11 = *v6;
      if ( v11 >= 0x41 && v11 <= 0x5A )
        LOWORD(v11) = v11 + 32;
      ++v6;
      --v4;
    }
    while ( v4 != 0 && v10 != 0 && v10 == (_WORD)v11 );
    result = v10 - (unsigned __int16)v11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E4F93
// Name: __wcsnicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicoll(const wchar_t *_string1, const wchar_t *_string2, unsigned int count)
{
  const wchar_t *v3; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  unsigned int v8; // eax

  if ( __locale_changed != 0 )
    return _wcsnicoll_l(_string1, _string2, count, plocinfo: nullptr);
  if ( _string1 != nullptr && (v3 = _string2, _string2 != nullptr) && count <= 0x7FFFFFFF )
  {
    v5 = (char *)_string1 - (char *)_string2;
    do
    {
      v6 = *(const wchar_t *)((char *)v3 + v5);
      if ( v6 < 0x41 || v6 > 0x5A )
        v7 = *(const wchar_t *)((char *)v3 + v5);
      else
        v7 = v6 + 32;
      v8 = *v3;
      if ( v8 >= 0x41 && v8 <= 0x5A )
        LOWORD(v8) = v8 + 32;
      ++v3;
      --count;
    }
    while ( count != 0 && v7 != 0 && v7 == (_WORD)v8 );
    return v7 - (unsigned __int16)v8;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E504D
// Name: ___mbtow_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __mbtow_environ()
{
  LPCCH *v0; // esi
  const CHAR *v1; // eax
  unsigned int v2; // eax
  unsigned __int16 *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  unsigned __int16 *wenvp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCCH *)_environ;
  wenvp = nullptr;
  v1 = *_environ;
  if ( *_environ == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: v1,
           cbMultiByte: -1,
           lpWideCharStr: nullptr,
           cchWideChar: 0);
    size = v2;
    if ( v2 == 0 )
      return -1;
    v3 = (unsigned __int16 *)calloc(count: v2, size: 2u);
    wenvp = v3;
    if ( v3 == nullptr )
      return -1;
    if ( MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: *v0,
           cbMultiByte: -1,
           lpWideCharStr: v3,
           cchWideChar: size) == 0 )
      goto LABEL_10;
    if ( __crtwsetenv(poption: &wenvp, primary: 0) < 0 )
    {
      if ( wenvp == nullptr )
        return -1;
LABEL_10:
      free(pMem: wenvp);
      return -1;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E50D4
// Name: __wsetenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wsetenvp()
{
  wchar_t *v0; // esi
  int v1; // edi
  unsigned __int16 **v3; // ebx
  wchar_t *i; // esi
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned __int16 *v7; // eax

  v0 = _wenvptr;
  v1 = 0;
  if ( _wenvptr == nullptr )
    return -1;
  while ( *v0 != 0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += wcslen(wcs: v0) + 1;
  }
  v3 = (unsigned __int16 **)calloc(count: v1 + 1, size: 4u);
  _wenviron = v3;
  if ( v3 == nullptr )
    return -1;
  for ( i = _wenvptr; ; i += v6 )
  {
    if ( *i == 0 )
    {
      free(pMem: _wenvptr);
      _wenvptr = nullptr;
      *v3 = nullptr;
      __env_initialized = 1;
      return 0;
    }
    v5 = wcslen(wcs: i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_14:
    ;
  }
  v7 = (unsigned __int16 *)calloc(count: v5 + 1, size: 2u);
  *v3 = v7;
  if ( v7 != nullptr )
  {
    if ( wcscpy_s(_Dst: v7, _SizeInWords: v6, _Src: i) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    ++v3;
    goto LABEL_14;
  }
  free(pMem: _wenviron);
  _wenviron = nullptr;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E51B0
// Name: ___crtGetEnvironmentStringsW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsW()
{
  LPWCH EnvironmentStringsW; // eax
  unsigned __int8 *v1; // esi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = (unsigned __int8 *)EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  for ( ; *EnvironmentStringsW != 0; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW != 0 );
  }
  v3 = (char *)EnvironmentStringsW - (char *)v1 + 2;
  v4 = (unsigned __int8 *)operator new(nSize: v3);
  v5 = v4;
  if ( v4 != nullptr )
    memcpy(dst: v4, src: v1, count: v3);
  FreeEnvironmentStringsW(penv: (LPWCH)v1);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004E5208
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E522F
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x004E5388
// Name: __SEH_epilog4_GS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _SEH_epilog4_GS()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004E5397
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString2,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        int cchCount2,
        UINT code_page)
{
  const char *v8; // eax
  int v9; // edi
  int v11; // ecx
  int v12; // esi
  int v13; // ecx
  const char *v14; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v17; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v19; // dl
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // esp
  wchar_t *v24; // eax
  int v25; // eax
  int v26; // ebx
  unsigned int v27; // eax
  void *v28; // esp
  WCHAR *v29; // eax
  WCHAR *v30; // edi
  _DWORD v32[3]; // [esp+0h] [ebp-38h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  LPCCH v36; // [esp+18h] [ebp-20h]
  wchar_t *wbuffer1; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  v8 = lpString1;
  v9 = cchCount1;
  lpMultiByteStr = lpString1;
  v36 = lpString2;
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v11 = cchCount1;
    while ( 1 )
    {
      --v11;
      if ( *v8 == 0 )
        break;
      ++v8;
      if ( v11 == 0 )
      {
        v11 = -1;
        break;
      }
    }
    v9 = -1 - v11 + cchCount1;
    cchCount1 = v9;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = cchCount2;
    v14 = lpString2;
    while ( 1 )
    {
      --v13;
      if ( *v14 == 0 )
        break;
      ++v14;
      if ( v13 == 0 )
      {
        v13 = -1;
        break;
      }
    }
    v12 = -1 - v13 + cchCount2;
    cchCount2 = v12;
  }
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( v9 != 0 && v12 != 0 )
    goto LABEL_44;
  if ( v9 == v12 )
    return 2;
  if ( v12 > 1 )
    return 1;
  if ( v9 > 1 )
    return 3;
  if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
    return 0;
  if ( v9 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      LeadByte = lpCPInfo.LeadByte;
      if ( lpCPInfo.LeadByte[0] != 0 )
      {
        while ( 1 )
        {
          v17 = LeadByte[1];
          if ( v17 == 0 )
            break;
          if ( (unsigned int)*lpMultiByteStr >= *LeadByte && (unsigned int)*lpMultiByteStr <= v17 )
            return 2;
          LeadByte += 2;
          if ( *LeadByte == 0 )
            return 3;
        }
      }
    }
    return 3;
  }
  if ( v12 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
      {
        v19 = i[1];
        if ( v19 == 0 )
          break;
        if ( (unsigned int)*v36 >= *i && (unsigned int)*v36 <= v19 )
          return 2;
      }
    }
    return 1;
  }
LABEL_44:
  v20 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 9u,
          lpMultiByteStr,
          cbMultiByte: v9,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v21 = v20;
  buff_size1 = v20;
  if ( v20 == 0 )
    return 0;
  if ( v20 > 0 && 0xFFFFFFE0 / v20 >= 2 )
  {
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)operator new(nSize: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_52;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v32;
      if ( v32 != nullptr )
      {
        v32[0] = 52428;
LABEL_52:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_55;
  }
  wbuffer1 = nullptr;
LABEL_55:
  if ( wbuffer1 == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr,
         cbMultiByte: cchCount1,
         lpWideCharStr: wbuffer1,
         cchWideChar: v21) != 0 )
  {
    v25 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 9u,
            lpMultiByteStr: v36,
            cbMultiByte: cchCount2,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v26 = v25;
    if ( v25 != 0 )
    {
      if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
      {
        v30 = nullptr;
LABEL_68:
        if ( v30 != nullptr )
        {
          if ( MultiByteToWideChar(
                 CodePage: code_page,
                 dwFlags: 1u,
                 lpMultiByteStr: v36,
                 cbMultiByte: cchCount2,
                 lpWideCharStr: v30,
                 cchWideChar: v26) != 0 )
            retcode = CompareStringW(
                        Locale,
                        dwCmpFlags,
                        lpString1: wbuffer1,
                        cchCount1: buff_size1,
                        lpString2: v30,
                        cchCount2: v26);
          _freea(_Memory: v30);
        }
        goto error_cleanup_0;
      }
      v27 = 2 * v25 + 8;
      if ( v27 > 0x400 )
      {
        v29 = (WCHAR *)operator new(nSize: 2 * v26 + 8);
        if ( v29 != nullptr )
        {
          *(_DWORD *)v29 = 56797;
          goto LABEL_65;
        }
      }
      else
      {
        v28 = alloca(v27);
        v29 = (WCHAR *)v32;
        if ( v32 != nullptr )
        {
          v32[0] = 52428;
LABEL_65:
          v29 += 4;
        }
      }
      v30 = v29;
      goto LABEL_68;
    }
  }
error_cleanup_0:
  _freea(_Memory: wbuffer1);
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x004E5605
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString2,
             Locale,
             dwCmpFlags,
             lpString1,
             cchCount1,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E5647
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strnicoll_l(const char *_string1, const char *_string2, unsigned int count, localeinfo_struct *plocinfo)
{
  int result; // eax
  LCID v5; // ecx
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( count == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _string1 != nullptr && _string2 != nullptr )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
LABEL_16:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    v5 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v5 != 0 )
    {
      v6 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v5,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
      if ( v6 == 0 )
      {
        *_errno() = 22;
        goto LABEL_16;
      }
      result = v6 - 2;
    }
    else
    {
      result = _strnicmp_l(dst: _string1, src: _string2, count, plocinfo: &_loc_update.localeinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E5731
// Name: __dospawn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dospawn(int mode, const char *name, char *cmdblk, char *envblk)
{
  void *hProcess; // ebx
  char *v5; // eax
  int v7; // esi
  signed int v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 *lpReserved2; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // edi
  ioinfo *v13; // eax
  char osfile; // dl
  _BYTE *v15; // ecx
  int v16; // edx
  unsigned __int8 *j; // eax
  int v18; // edi
  BOOL v19; // esi
  DWORD LastError; // edi
  _STARTUPINFOA StartupInfo; // [esp+8h] [ebp-68h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+4Ch] [ebp-24h] BYREF
  unsigned int exitcode; // [esp+5Ch] [ebp-14h] BYREF
  char *CommandLine; // [esp+60h] [ebp-10h]
  unsigned int fdwCreate; // [esp+64h] [ebp-Ch]
  int i; // [esp+68h] [ebp-8h]
  char background; // [esp+6Fh] [ebp-1h]

  hProcess = nullptr;
  fdwCreate = 0;
  background = 0;
  if ( (unsigned int)mode >= 2 )
  {
    if ( mode <= 1 )
      goto LABEL_7;
    if ( mode > 3 )
    {
      if ( mode == 4 )
      {
        background = 1;
        goto LABEL_6;
      }
LABEL_7:
      *__doserrno() = 0;
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
LABEL_6:
  v5 = cmdblk;
  CommandLine = cmdblk;
  while ( *v5 != 0 )
  {
    do
      ++v5;
    while ( *v5 != 0 );
    if ( v5[1] != 0 )
      *v5++ = 32;
  }
  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  v7 = _nhandle;
  if ( _nhandle == 0 )
    goto LABEL_47;
  v8 = _nhandle - 1;
  do
  {
    if ( __pioinfo[v8 >> 5][v8 & 0x1F].osfile != 0 )
      break;
    --v7;
    --v8;
  }
  while ( v7 != 0 );
  if ( v7 >= 0 )
  {
LABEL_47:
    if ( (unsigned int)v7 < 0x3332 )
    {
      StartupInfo.cbReserved2 = 5 * v7 + 4;
      v9 = (unsigned __int8 *)calloc(count: StartupInfo.cbReserved2, size: 1u);
      StartupInfo.lpReserved2 = v9;
      if ( v9 != nullptr )
      {
        *(_DWORD *)v9 = v7;
        lpReserved2 = StartupInfo.lpReserved2;
        v11 = StartupInfo.lpReserved2 + 4;
        v12 = &StartupInfo.lpReserved2[v7 + 4];
        i = 0;
        if ( v7 > 0 )
        {
          do
          {
            v13 = &__pioinfo[i >> 5][i & 0x1F];
            osfile = v13->osfile;
            if ( (osfile & 0x10) != 0 )
            {
              *v11 = 0;
              *(_DWORD *)v12 = -1;
            }
            else
            {
              *v11 = osfile;
              *(_DWORD *)v12 = v13->osfhnd;
            }
            ++i;
            ++v11;
            v12 += 4;
          }
          while ( i < v7 );
          lpReserved2 = StartupInfo.lpReserved2;
        }
        if ( background != 0 )
        {
          v15 = lpReserved2 + 4;
          v16 = 0;
          for ( j = &lpReserved2[v7 + 4]; ; j += 4 )
          {
            v18 = v7 >= 3 ? 3 : v7;
            if ( v16 >= v18 )
              break;
            *v15 = 0;
            *(_DWORD *)j = -1;
            ++v16;
            ++v15;
          }
          fdwCreate = 8;
        }
        *__doserrno() = 0;
        v19 = CreateProcessA(
                lpApplicationName: name,
                lpCommandLine: CommandLine,
                lpProcessAttributes: nullptr,
                lpThreadAttributes: nullptr,
                bInheritHandles: true,
                dwCreationFlags: fdwCreate,
                lpEnvironment: envblk,
                lpCurrentDirectory: nullptr,
                lpStartupInfo: &StartupInfo,
                lpProcessInformation: &ProcessInformation);
        LastError = GetLastError();
        free(pMem: StartupInfo.lpReserved2);
        if ( v19 )
        {
          if ( mode == 2 )
            _exit(code: 0);
          if ( mode != 0 )
          {
            if ( mode != 4 )
            {
              hProcess = ProcessInformation.hProcess;
              goto LABEL_42;
            }
          }
          else
          {
            WaitForSingleObject(hHandle: ProcessInformation.hProcess, dwMilliseconds: 0xFFFFFFFF);
            GetExitCodeProcess(hProcess: ProcessInformation.hProcess, lpExitCode: &exitcode);
            hProcess = (void *)exitcode;
          }
          CloseHandle(hObject: ProcessInformation.hProcess);
LABEL_42:
          CloseHandle(hObject: ProcessInformation.hThread);
          return (int)hProcess;
        }
        _dosmaperr(oserrno: LastError);
        return -1;
      }
    }
  }
  *_errno() = 12;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E5935
// Name: __cenvarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cenvarg(const char **argv, const char **envp, char **argblk, char **envblk)
{
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  char *v8; // eax
  void **v9; // esi
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // eax
  unsigned __int8 **v15; // esi
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // eax
  char *EnvironmentStringsA; // eax
  const char **v20; // edi
  char *v21; // esi
  char *v22; // esi
  char v23; // cl
  unsigned __int8 *v24; // esi
  int v25; // eax
  int v26; // ecx
  char *i; // eax
  int v28; // eax
  const unsigned __int8 **v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // eax
  char *v32; // eax
  int v33; // eax
  int v34; // eax
  char *v35; // esi
  unsigned __int8 *v36; // esi
  const char **j; // edi
  int v38; // eax
  unsigned int env_len; // [esp+Ch] [ebp-40h]
  int defined; // [esp+10h] [ebp-3Ch]
  unsigned int v41; // [esp+18h] [ebp-34h]
  unsigned int envsize; // [esp+1Ch] [ebp-30h]
  int cwd_end; // [esp+24h] [ebp-28h]
  int retval; // [esp+28h] [ebp-24h]
  int cwd_start; // [esp+30h] [ebp-1Ch]
  char *envbuf; // [esp+38h] [ebp-14h] BYREF
  char envpfx[12]; // [esp+3Ch] [ebp-10h] BYREF

  strcpy(envpfx, "SystemRoot");
  v4 = (unsigned __int8 **)argv;
  v5 = (unsigned __int8 *)*argv;
  retval = 0;
  envbuf = nullptr;
  defined = 0;
  v6 = 2;
  while ( v5 != nullptr )
  {
    strlen(buf: v5);
    ++v4;
    v6 += v7 + 1;
    v5 = *v4;
  }
  v41 = v6;
  v8 = (char *)calloc(count: v6, size: 1u);
  v9 = (void **)argblk;
  *argblk = v8;
  if ( v8 == nullptr )
  {
    *envblk = nullptr;
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: envpfx);
  if ( v11 != 0 )
  {
    if ( v11 == 22 )
      goto LABEL_8;
    goto LABEL_18;
  }
  strlen(buf: (unsigned __int8 *)envpfx);
  v13 = v12 + 2;
  envsize = v12 + 2;
  if ( envbuf != nullptr )
  {
    strlen(buf: (unsigned __int8 *)envbuf);
    envsize = v14 + v13;
  }
  if ( envp == nullptr )
  {
    *envblk = nullptr;
    goto LABEL_20;
  }
  v15 = (unsigned __int8 **)envp;
  v16 = (unsigned __int8 *)*envp;
  v17 = 2;
  while ( v16 != nullptr )
  {
    strlen(buf: v16);
    ++v15;
    v17 += v18 + 1;
    v16 = *v15;
  }
  EnvironmentStringsA = _aenvptr;
  if ( _aenvptr != nullptr
    || (EnvironmentStringsA = (char *)__crtGetEnvironmentStringsA(),
        _aenvptr = EnvironmentStringsA,
        EnvironmentStringsA != nullptr) )
  {
    cwd_start = 0;
    if ( *EnvironmentStringsA != 0 )
    {
      v23 = *EnvironmentStringsA;
      v24 = (unsigned __int8 *)EnvironmentStringsA;
      do
      {
        if ( v23 == 61 )
          break;
        strlen(buf: v24);
        v26 = cwd_start + v25 + 1;
        EnvironmentStringsA = _aenvptr;
        v24 = (unsigned __int8 *)&_aenvptr[v26];
        cwd_start = v26;
        v23 = _aenvptr[v26];
      }
      while ( v23 != 0 );
    }
    cwd_end = cwd_start;
    for ( i = &EnvironmentStringsA[cwd_start]; *i == 61 && i[1] != 0 && i[2] == 58 && i[3] == 61; i = &_aenvptr[cwd_end] )
    {
      strlen(buf: (unsigned __int8 *)i + 4);
      cwd_end += v28 + 5;
    }
    v29 = (const unsigned __int8 **)envp;
    v30 = cwd_end - cwd_start + v17;
    env_len = v30;
    while ( 1 )
    {
      if ( *v29 == nullptr )
      {
        v30 += envsize;
        goto LABEL_37;
      }
      strlen(buf: (unsigned __int8 *)envpfx);
      if ( _mbsnicmp(s1: *v29, s2: (const unsigned __int8 *)envpfx, n: v31) == 0 )
        break;
      ++v29;
    }
    defined = 1;
LABEL_37:
    v32 = (char *)calloc(count: v30, size: 1u);
    v9 = (void **)argblk;
    *envblk = v32;
    if ( v32 == nullptr )
    {
      free(pMem: *argblk);
      *argblk = nullptr;
      *_errno() = 12;
      retval = -1;
      *__doserrno() = 8;
      goto done;
    }
LABEL_20:
    v20 = argv;
    v21 = (char *)*v9;
    if ( *argv == nullptr )
    {
      v22 = v21 + 1;
      goto LABEL_44;
    }
    if ( strcpy_s(_Dst: v21, _SizeInBytes: v41, _Src: *argv) == 0 )
    {
      strlen(buf: (unsigned __int8 *)*argv);
      v22 = &v21[v33 + 1];
      v20 = argv + 1;
LABEL_44:
      while ( *v20 != nullptr )
      {
        if ( strcpy_s(_Dst: v22, _SizeInBytes: v41 + *argblk - v22, _Src: *v20) != 0 )
          goto LABEL_8;
        strlen(buf: (unsigned __int8 *)*v20);
        v35 = &v22[v34];
        ++v20;
        *v35 = 32;
        v22 = v35 + 1;
      }
      *(_WORD *)(v22 - 1) = 0;
      v36 = (unsigned __int8 *)*envblk;
      if ( envp == nullptr )
        goto LABEL_56;
      memcpy(dst: v36, src: (unsigned __int8 *)&_aenvptr[cwd_start], count: cwd_end - cwd_start);
      v36 += cwd_end - cwd_start;
      for ( j = envp; *j != nullptr; ++j )
      {
        if ( strcpy_s(_Dst: (char *)v36, _SizeInBytes: (unsigned int)&(*envblk)[env_len - (_DWORD)v36], _Src: *j) != 0 )
          goto LABEL_8;
        strlen(buf: (unsigned __int8 *)*j);
        v36 += v38 + 1;
      }
      if ( defined != 0 )
        goto LABEL_56;
      if ( strcpy_s(_Dst: (char *)v36, _SizeInBytes: envsize, _Src: envpfx) == 0
        && strcat_s(_Dst: (char *)v36, _SizeInBytes: envsize, _Src: "=") == 0
        && (envbuf == nullptr || strcat_s(_Dst: (char *)v36, _SizeInBytes: envsize, _Src: envbuf) == 0) )
      {
        v36 += envsize;
LABEL_56:
        if ( v36 != nullptr )
        {
          if ( v36 == (unsigned __int8 *)*envblk )
            *v36++ = 0;
          *v36 = 0;
        }
        goto done;
      }
    }
LABEL_8:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  v9 = (void **)argblk;
LABEL_18:
  retval = -1;
  free(pMem: *v9);
  *v9 = nullptr;
  *envblk = nullptr;
done:
  if ( _aenvptr != nullptr )
    free(pMem: _aenvptr);
  _aenvptr = nullptr;
  if ( envbuf != nullptr )
    free(pMem: envbuf);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004E5CD1
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)operator new(nSize: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x004E5D1A
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _commit(int filedes)
{
  ioinfo **v2; // edi
  int v3; // esi
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (v2 = &__pioinfo[filedes >> 5], (*(&(*v2)->osfile + (v3 = (filedes & 0x1F) << 6)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004E5DF3
// Name: __mbsnbicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  unsigned __int16 v9; // si
  unsigned __int8 v10; // dl
  int v11; // ecx
  char *v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char *v16; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  int c1; // [esp+14h] [ebp-8h]
  int c2; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _strnicmp(dst: (const char *)s1, src: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v6 = *s1;
    --n;
    ++s1;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v12 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v12[29] & 0x10) != 0 )
        v13 = (unsigned __int8)v12[285];
      else
        v13 = (unsigned __int16)c1;
      c1 = v13;
      goto LABEL_32;
    }
    if ( n == 0 )
    {
      v8 = *v5;
      v7 = (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) == 0;
      c1 = 0;
      if ( !v7 )
        goto LABEL_51;
      v9 = 0;
      goto LABEL_46;
    }
    if ( *s1 == 0 )
    {
      c1 = 0;
LABEL_32:
      v9 = c1;
      goto LABEL_33;
    }
    v10 = *s1++;
    v11 = (unsigned __int16)(v10 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v11;
    c1 = v11;
    if ( (unsigned __int16)v11 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v11 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v11 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v11 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v11;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v11;
    }
LABEL_33:
    v14 = *v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v14 + 1] & 4) == 0;
    c2 = v14;
    if ( v7 )
    {
      v16 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c2;
      if ( (v16[29] & 0x10) != 0 )
        v8 = (unsigned __int8)v16[285];
      else
        v8 = (unsigned __int16)c2;
LABEL_46:
      c2 = v8;
      goto LABEL_47;
    }
    if ( n == 0 || (--n, *v5 == 0) )
    {
      c2 = 0;
LABEL_47:
      LOWORD(v15) = c2;
      goto test;
    }
    v15 = (unsigned __int16)(*v5++ | (unsigned __int16)((_WORD)v14 << 8));
    c2 = v15;
    if ( (unsigned __int16)v15 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v15 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v15 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v15 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v15;
      }
    }
    else
    {
      LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v15;
    }
test:
    if ( (_WORD)v15 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
LABEL_51:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v15 < v9 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E5FF7
// Name: __mbsnbicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E6011
// Name: __mbsnbcmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // ebx
  const unsigned __int8 *v6; // esi
  unsigned __int16 v7; // cx
  int v8; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  if ( n == 0 )
    return 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncmp(first: (const char *)s1, last: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  v5 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v6 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v7 = *v5;
    --n;
    ++v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) == 0 )
      goto LABEL_24;
    if ( n != 0 )
    {
      if ( *v5 != 0 )
        v7 = *v5++ | (unsigned __int16)(v7 << 8);
      else
        v7 = 0;
LABEL_24:
      LOWORD(v8) = *v6++;
      if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) != 0 )
      {
        if ( n != 0 && (--n, *v6 != 0) )
          LOWORD(v8) = *v6++ | (unsigned __int16)((_WORD)v8 << 8);
        else
          LOWORD(v8) = 0;
      }
      goto test_0;
    }
    v8 = *v6;
    v7 = 0;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) != 0 )
      goto LABEL_17;
test_0:
    if ( (_WORD)v8 != v7 )
      break;
    if ( v7 == 0 || n == 0 )
    {
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v8 < v7 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E615D
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbcmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E6180
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E61A0
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E61E5
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi

  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call();
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E6269
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E628C
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x4E62A0);
}

//------------------------------------------------------------------------------
// Address: 0x004E6295
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E62B4
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x004E62C0
// Name: __CIsin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004E6488
// Name: __87except
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _87except(int a1@<ebp>, int opcode, _exception *exc, unsigned __int16 *pcw16)
{
  unsigned int v4; // ecx
  bool v5; // zf
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // [esp-Ch] [ebp-94h] BYREF
  unsigned int v13; // [esp-8h] [ebp-90h]
  int v14; // [esp-4h] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+8h] [ebp-80h]
  int v16; // [esp+7Ch] [ebp-Ch]
  void *v17; // [esp+80h] [ebp-8h]
  void *retaddr; // [esp+88h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v4 = *pcw16;
  v6 = exc->typ - 1;
  v5 = exc->typ == 1;
  v12 = v4;
  if ( v5 )
    goto LABEL_13;
  v7 = v6 - 1;
  if ( v7 == 0 )
  {
    v13 = 4;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( v8 == 0 )
  {
    v13 = 17;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( v9 == 0 )
  {
    v13 = 18;
    goto LABEL_14;
  }
  v10 = v9 - 1;
  if ( v10 == 0 )
  {
LABEL_13:
    v13 = 8;
LABEL_14:
    if ( _handle_exc(flags: v13, presult: (long double *)&exc->retval, cw: v4) == 0 )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        *(double *)((char *)&rec.Operand1 + 20) = *(double *)&exc->arg2;
        rec.Operand2.Value.Fp128Value.W[1] = rec.Operand2.Value.Fp128Value.W[1] & 0xFFFFFFE0 | 3;
      }
      else
      {
        rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
      }
      _raise_exc(
        prec: (_FPIEEE_RECORD *)&v14,
        pcw: &v12,
        flags: v13,
        opcode,
        parg1: (long double *)&exc->arg1,
        presult: (long double *)&exc->retval);
    }
    goto LABEL_21;
  }
  v11 = v10 - 2;
  if ( v11 == 0 )
  {
    exc->typ = 1;
    goto LABEL_21;
  }
  if ( v11 == 1 )
  {
    v13 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp(newctrl: v12, _mask: 0xFFFFu);
  if ( exc->typ == 8 || _matherr_flag != 0 || _matherr(pexcept: exc) == 0 )
    _set_errno_from_matherr(matherrtype: exc->typ);
}

//------------------------------------------------------------------------------
// Address: 0x004E65C7
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int bError)
{
  unsigned __int8 *v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // eax
  _DWORD v15[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h]

  v7 = nullptr;
  retval2 = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v8 = MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 8 * (bError != 0) + 1,
         lpMultiByteStr: lpSrcStr,
         cbMultiByte: cchSrc,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  v9 = v8;
  if ( v8 == 0 )
    return 0;
  if ( v8 > 0 && (unsigned int)v8 <= 0x7FFFFFF0 )
  {
    v11 = 2 * v8 + 8;
    if ( v11 > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: 2 * v9 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_12;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_12:
        v13 += 8;
      }
    }
    v7 = v13;
  }
  if ( v7 == nullptr )
    return 0;
  memset(dst: v7, value: 0, count: 2 * v9);
  v14 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 1u,
          lpMultiByteStr: lpSrcStr,
          cbMultiByte: cchSrc,
          lpWideCharStr: (LPWSTR)v7,
          cchWideChar: v9);
  if ( v14 != 0 )
    retval2 = GetStringTypeW(dwInfoType, lpSrcStr: (LPCWCH)v7, cchSrc: v14, lpCharType);
  _freea(_Memory: v7);
  return retval2;
}

//------------------------------------------------------------------------------
// Address: 0x004E66AE
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(
             plocinfo: &_loc_update.localeinfo,
             dwInfoType,
             lpSrcStr,
             cchSrc,
             lpCharType,
             code_page,
             bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E66EE
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pMem: lc_time->wday_abbr[1]);
    free(pMem: lc_time->wday_abbr[2]);
    free(pMem: lc_time->wday_abbr[3]);
    free(pMem: lc_time->wday_abbr[4]);
    free(pMem: lc_time->wday_abbr[5]);
    free(pMem: lc_time->wday_abbr[6]);
    free(pMem: lc_time->wday_abbr[0]);
    free(pMem: lc_time->wday[1]);
    free(pMem: lc_time->wday[2]);
    free(pMem: lc_time->wday[3]);
    free(pMem: lc_time->wday[4]);
    free(pMem: lc_time->wday[5]);
    free(pMem: lc_time->wday[6]);
    free(pMem: lc_time->wday[0]);
    free(pMem: lc_time->month_abbr[0]);
    free(pMem: lc_time->month_abbr[1]);
    free(pMem: lc_time->month_abbr[2]);
    free(pMem: lc_time->month_abbr[3]);
    free(pMem: lc_time->month_abbr[4]);
    free(pMem: lc_time->month_abbr[5]);
    free(pMem: lc_time->month_abbr[6]);
    free(pMem: lc_time->month_abbr[7]);
    free(pMem: lc_time->month_abbr[8]);
    free(pMem: lc_time->month_abbr[9]);
    free(pMem: lc_time->month_abbr[10]);
    free(pMem: lc_time->month_abbr[11]);
    free(pMem: lc_time->month[0]);
    free(pMem: lc_time->month[1]);
    free(pMem: lc_time->month[2]);
    free(pMem: lc_time->month[3]);
    free(pMem: lc_time->month[4]);
    free(pMem: lc_time->month[5]);
    free(pMem: lc_time->month[6]);
    free(pMem: lc_time->month[7]);
    free(pMem: lc_time->month[8]);
    free(pMem: lc_time->month[9]);
    free(pMem: lc_time->month[10]);
    free(pMem: lc_time->month[11]);
    free(pMem: lc_time->ampm[0]);
    free(pMem: lc_time->ampm[1]);
    free(pMem: lc_time->ww_sdatefmt);
    free(pMem: lc_time->ww_ldatefmt);
    free(pMem: lc_time->ww_timefmt);
    free(pMem: lc_time->_W_wday_abbr[1]);
    free(pMem: lc_time->_W_wday_abbr[2]);
    free(pMem: lc_time->_W_wday_abbr[3]);
    free(pMem: lc_time->_W_wday_abbr[4]);
    free(pMem: lc_time->_W_wday_abbr[5]);
    free(pMem: lc_time->_W_wday_abbr[6]);
    free(pMem: lc_time->_W_wday_abbr[0]);
    free(pMem: lc_time->_W_wday[1]);
    free(pMem: lc_time->_W_wday[2]);
    free(pMem: lc_time->_W_wday[3]);
    free(pMem: lc_time->_W_wday[4]);
    free(pMem: lc_time->_W_wday[5]);
    free(pMem: lc_time->_W_wday[6]);
    free(pMem: lc_time->_W_wday[0]);
    free(pMem: lc_time->_W_month_abbr[0]);
    free(pMem: lc_time->_W_month_abbr[1]);
    free(pMem: lc_time->_W_month_abbr[2]);
    free(pMem: lc_time->_W_month_abbr[3]);
    free(pMem: lc_time->_W_month_abbr[4]);
    free(pMem: lc_time->_W_month_abbr[5]);
    free(pMem: lc_time->_W_month_abbr[6]);
    free(pMem: lc_time->_W_month_abbr[7]);
    free(pMem: lc_time->_W_month_abbr[8]);
    free(pMem: lc_time->_W_month_abbr[9]);
    free(pMem: lc_time->_W_month_abbr[10]);
    free(pMem: lc_time->_W_month_abbr[11]);
    free(pMem: lc_time->_W_month[0]);
    free(pMem: lc_time->_W_month[1]);
    free(pMem: lc_time->_W_month[2]);
    free(pMem: lc_time->_W_month[3]);
    free(pMem: lc_time->_W_month[4]);
    free(pMem: lc_time->_W_month[5]);
    free(pMem: lc_time->_W_month[6]);
    free(pMem: lc_time->_W_month[7]);
    free(pMem: lc_time->_W_month[8]);
    free(pMem: lc_time->_W_month[9]);
    free(pMem: lc_time->_W_month[10]);
    free(pMem: lc_time->_W_month[11]);
    free(pMem: lc_time->_W_ampm[0]);
    free(pMem: lc_time->_W_ampm[1]);
    free(pMem: lc_time->_W_ww_sdatefmt);
    free(pMem: lc_time->_W_ww_ldatefmt);
    free(pMem: lc_time->_W_ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6A65
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  wchar_t *W_thousands_sep; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    if ( l->grouping != __lconv_c.grouping )
      free(pMem: l->grouping);
    if ( l->_W_decimal_point != __lconv_c._W_decimal_point )
      free(pMem: l->_W_decimal_point);
    W_thousands_sep = l->_W_thousands_sep;
    if ( W_thousands_sep != __lconv_c._W_thousands_sep )
      free(pMem: W_thousands_sep);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6ACE
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  wchar_t *W_negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pMem: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pMem: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pMem: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pMem: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pMem: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pMem: l->positive_sign);
    if ( l->negative_sign != __lconv_c.negative_sign )
      free(pMem: l->negative_sign);
    if ( l->_W_int_curr_symbol != __lconv_c._W_int_curr_symbol )
      free(pMem: l->_W_int_curr_symbol);
    if ( l->_W_currency_symbol != __lconv_c._W_currency_symbol )
      free(pMem: l->_W_currency_symbol);
    if ( l->_W_mon_decimal_point != __lconv_c._W_mon_decimal_point )
      free(pMem: l->_W_mon_decimal_point);
    if ( l->_W_mon_thousands_sep != __lconv_c._W_mon_thousands_sep )
      free(pMem: l->_W_mon_thousands_sep);
    if ( l->_W_positive_sign != __lconv_c._W_positive_sign )
      free(pMem: l->_W_positive_sign);
    W_negative_sign = l->_W_negative_sign;
    if ( W_negative_sign != __lconv_c._W_negative_sign )
      free(pMem: W_negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E6BCC
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // edi
  unsigned int *v9; // esi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  int v20; // edx
  unsigned int *v21; // ecx
  int v22; // esi
  int v23; // eax
  unsigned int *v24; // ebx
  bool n; // zf
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  unsigned int v29; // edi
  int ii; // ecx
  unsigned int *v31; // ecx
  unsigned int v32; // esi
  int v33; // edi
  int v34; // eax
  int v35; // edx
  int *v36; // ebx
  int v37; // edx
  unsigned int *v38; // ecx
  int v39; // eax
  int v40; // edx
  int *v41; // ebx
  int v42; // edx
  unsigned int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  unsigned int *v47; // ecx
  unsigned int v48; // ebx
  int v49; // edx
  int v50; // [esp+8h] [ebp-38h]
  char v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  int v53; // [esp+14h] [ebp-2Ch]
  int v54; // [esp+14h] [ebp-2Ch]
  char v55; // [esp+14h] [ebp-2Ch]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+14h] [ebp-2Ch]
  int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  int v60; // [esp+18h] [ebp-28h]
  int v61; // [esp+18h] [ebp-28h]
  int v62; // [esp+18h] [ebp-28h]
  int v63; // [esp+18h] [ebp-28h]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned int v66; // [esp+20h] [ebp-20h]
  int m; // [esp+20h] [ebp-20h]
  int jj; // [esp+20h] [ebp-20h]
  int k; // [esp+20h] [ebp-20h]
  int j; // [esp+20h] [ebp-20h]
  unsigned int v71; // [esp+24h] [ebp-1Ch]
  int v72; // [esp+28h] [ebp-18h]
  int v73; // [esp+2Ch] [ebp-14h]
  unsigned int v74; // [esp+30h] [ebp-10h] BYREF
  int v75; // [esp+34h] [ebp-Ch]
  int v76; // [esp+38h] [ebp-8h] BYREF

  v2 = *(_WORD *)&pld12->ld12[10];
  v50 = v2 & 0x8000;
  v74 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v75 = *(_DWORD *)&pld12->ld12[2];
  v76 = v4;
  if ( v3 != -16383 )
  {
    v65 = 0;
    v71 = v74;
    v72 = v75;
    v73 = v76;
    v8 = DoubleFormat.precision - 1;
    v53 = v3;
    v59 = DoubleFormat.precision / 32;
    v9 = &v74 + DoubleFormat.precision / 32;
    v51 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << v51) & *v9) != 0 )
    {
      v10 = DoubleFormat.precision / 32;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v74 + v59)) == 0; i; i = *(&v74 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_21;
      }
      v12 = v8 / 32;
      v65 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v74 + v8 / 32;
      v66 = v13 + *v14;
      if ( v66 >= *v14 )
      {
        v15 = v66 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v65 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v66;
        if ( v12 < 0 || v65 == 0 )
          break;
        v65 = 0;
        v14 = &v74 + v12;
        v16 = *v14 + 1;
        v66 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
    }
LABEL_21:
    *v9 &= -1 << v51;
    if ( v59 + 1 < 3 )
      memset(&v74 + v59 + 1, 0, 4 * (3 - (v59 + 1)));
    if ( v65 != 0 )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v5 = DoubleFormat.bias + v3;
          v74 &= ~0x80000000;
          v44 = DoubleFormat.exp_width / 32;
          v45 = DoubleFormat.exp_width % 32;
          v64 = 0;
          for ( j = 0; j < 3; ++j )
          {
            v58 = ~(-1 << v45) & *(&v74 + j);
            *(&v74 + j) = v64 | (*(&v74 + j) >> v45);
            v64 = v58 << (32 - v45);
          }
          v46 = 2;
          v47 = (unsigned int *)(&v76 - v44);
          do
          {
            if ( v46 < v44 )
              *(&v74 + v46) = 0;
            else
              *(&v74 + v46) = *v47;
            --v47;
            --v46;
          }
          while ( v46 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v75 = 0;
          v76 = 0;
          v74 = 0x80000000;
          v39 = DoubleFormat.exp_width / 32;
          v40 = DoubleFormat.exp_width % 32;
          v63 = 0;
          for ( k = 0; k < 3; ++k )
          {
            v41 = (int *)(&v74 + k);
            v57 = ~(-1 << v40) & *v41;
            *v41 = v63 | ((unsigned int)*v41 >> v40);
            v63 = v57 << (32 - v40);
          }
          v42 = 2;
          v43 = (unsigned int *)(&v76 - v39);
          do
          {
            if ( v42 < v39 )
              *(&v74 + v42) = 0;
            else
              *(&v74 + v42) = *v43;
            --v43;
            --v42;
          }
          while ( v42 >= 0 );
          v5 = DoubleFormat.max_exp + DoubleFormat.bias;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_78;
      }
      v74 = v71;
      v75 = v72;
      v17 = (DoubleFormat.min_exp - v53) / 32;
      v76 = v73;
      v18 = (DoubleFormat.min_exp - v53) % 32;
      v60 = 0;
      for ( m = 0; m < 3; ++m )
      {
        v19 = (int *)(&v74 + m);
        v54 = ~(-1 << v18) & *v19;
        *v19 = v60 | ((unsigned int)*v19 >> v18);
        v60 = v54 << (32 - v18);
      }
      v20 = 2;
      v21 = (unsigned int *)(&v76 - v17);
      do
      {
        if ( v20 < v17 )
          *(&v74 + v20) = 0;
        else
          *(&v74 + v20) = *v21;
        --v21;
        --v20;
      }
      while ( v20 >= 0 );
      v22 = DoubleFormat.precision - 1;
      v23 = DoubleFormat.precision / 32;
      v52 = DoubleFormat.precision / 32;
      v24 = &v74 + DoubleFormat.precision / 32;
      v55 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << v55) & *v24) != 0 )
      {
        for ( n = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v74 + v23)) == 0; n; n = *(&v74 + v23) == 0 )
        {
          if ( ++v23 >= 3 )
            goto LABEL_51;
        }
        v26 = v22 / 32;
        v61 = 0;
        v27 = 1 << (31 - v22 % 32);
        v28 = &v74 + v22 / 32;
        v29 = *v28 + v27;
        if ( v29 < *v28 || v29 < v27 )
          v61 = 1;
        *v28 = v29;
        for ( ii = v61; --v26 >= 0 && ii != 0; ii = v33 )
        {
          v31 = &v74 + v26;
          v32 = *v31 + 1;
          v33 = 0;
          if ( v32 < *v31 || *v31 == -1 )
            v33 = 1;
          *v31 = v32;
        }
      }
LABEL_51:
      *v24 &= -1 << v55;
      if ( v52 + 1 < 3 )
        memset(&v74 + v52 + 1, 0, 4 * (3 - (v52 + 1)));
      v34 = (DoubleFormat.exp_width + 1) / 32;
      v35 = (DoubleFormat.exp_width + 1) % 32;
      v62 = 0;
      for ( jj = 0; jj < 3; ++jj )
      {
        v36 = (int *)(&v74 + jj);
        v56 = ~(-1 << v35) & *v36;
        *v36 = v62 | ((unsigned int)*v36 >> v35);
        v62 = v56 << (32 - v35);
      }
      v37 = 2;
      v38 = (unsigned int *)(&v76 - v34);
      do
      {
        if ( v37 < v34 )
          *(&v74 + v37) = 0;
        else
          *(&v74 + v37) = *v38;
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    else
    {
      v74 = 0;
      v75 = 0;
      v76 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_78;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v74 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_78;
    }
  }
  v74 = 0;
  v75 = 0;
  v76 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_78:
  v48 = v74 | (v50 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v49 = v75;
    HIDWORD(d->x) = v48;
    LODWORD(d->x) = v49;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v48;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E711D
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // edi
  unsigned int *v9; // esi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  int v20; // edx
  unsigned int *v21; // ecx
  int v22; // esi
  int v23; // eax
  unsigned int *v24; // ebx
  bool n; // zf
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  unsigned int v29; // edi
  int ii; // ecx
  unsigned int *v31; // ecx
  unsigned int v32; // esi
  int v33; // edi
  int v34; // eax
  int v35; // edx
  int *v36; // ebx
  int v37; // edx
  unsigned int *v38; // ecx
  int v39; // eax
  int v40; // edx
  int *v41; // ebx
  int v42; // edx
  unsigned int *v43; // ecx
  int v44; // eax
  int v45; // edx
  int v46; // edx
  unsigned int *v47; // ecx
  float v48; // ebx
  float v49; // edx
  int v50; // [esp+8h] [ebp-38h]
  char v51; // [esp+10h] [ebp-30h]
  int v52; // [esp+10h] [ebp-30h]
  int v53; // [esp+14h] [ebp-2Ch]
  int v54; // [esp+14h] [ebp-2Ch]
  char v55; // [esp+14h] [ebp-2Ch]
  int v56; // [esp+14h] [ebp-2Ch]
  int v57; // [esp+14h] [ebp-2Ch]
  int v58; // [esp+14h] [ebp-2Ch]
  int v59; // [esp+18h] [ebp-28h]
  int v60; // [esp+18h] [ebp-28h]
  int v61; // [esp+18h] [ebp-28h]
  int v62; // [esp+18h] [ebp-28h]
  int v63; // [esp+18h] [ebp-28h]
  int v64; // [esp+18h] [ebp-28h]
  int v65; // [esp+1Ch] [ebp-24h]
  unsigned int v66; // [esp+20h] [ebp-20h]
  int m; // [esp+20h] [ebp-20h]
  int jj; // [esp+20h] [ebp-20h]
  int k; // [esp+20h] [ebp-20h]
  int j; // [esp+20h] [ebp-20h]
  unsigned int v71; // [esp+24h] [ebp-1Ch]
  float v72; // [esp+28h] [ebp-18h]
  int v73; // [esp+2Ch] [ebp-14h]
  unsigned int v74; // [esp+30h] [ebp-10h] BYREF
  float v75; // [esp+34h] [ebp-Ch]
  int v76; // [esp+38h] [ebp-8h] BYREF

  v2 = *(_WORD *)&pld12->ld12[10];
  v50 = v2 & 0x8000;
  v74 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v75 = *(float *)&pld12->ld12[2];
  v76 = v4;
  if ( v3 != -16383 )
  {
    v65 = 0;
    v71 = v74;
    v72 = v75;
    v73 = v76;
    v8 = FloatFormat.precision - 1;
    v53 = v3;
    v59 = FloatFormat.precision / 32;
    v9 = &v74 + FloatFormat.precision / 32;
    v51 = 31 - FloatFormat.precision % 32;
    if ( ((1 << v51) & *v9) != 0 )
    {
      v10 = FloatFormat.precision / 32;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v74 + v59)) == 0; i; i = *(&v74 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_21;
      }
      v12 = v8 / 32;
      v65 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v74 + v8 / 32;
      v66 = v13 + *v14;
      if ( v66 >= *v14 )
      {
        v15 = v66 < v13;
        goto LABEL_18;
      }
LABEL_19:
      v65 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = v66;
        if ( v12 < 0 || v65 == 0 )
          break;
        v65 = 0;
        v14 = &v74 + v12;
        v16 = *v14 + 1;
        v66 = v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
    }
LABEL_21:
    *v9 &= -1 << v51;
    if ( v59 + 1 < 3 )
      memset(&v74 + v59 + 1, 0, 4 * (3 - (v59 + 1)));
    if ( v65 != 0 )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v5 = FloatFormat.bias + v3;
          v74 &= ~0x80000000;
          v44 = FloatFormat.exp_width / 32;
          v45 = FloatFormat.exp_width % 32;
          v64 = 0;
          for ( j = 0; j < 3; ++j )
          {
            v58 = ~(-1 << v45) & *(&v74 + j);
            *(&v74 + j) = v64 | (*(&v74 + j) >> v45);
            v64 = v58 << (32 - v45);
          }
          v46 = 2;
          v47 = (unsigned int *)(&v76 - v44);
          do
          {
            if ( v46 < v44 )
              *(&v74 + v46) = 0;
            else
              *(&v74 + v46) = *v47;
            --v47;
            --v46;
          }
          while ( v46 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v75 = 0.0;
          v76 = 0;
          v74 = 0x80000000;
          v39 = FloatFormat.exp_width / 32;
          v40 = FloatFormat.exp_width % 32;
          v63 = 0;
          for ( k = 0; k < 3; ++k )
          {
            v41 = (int *)(&v74 + k);
            v57 = ~(-1 << v40) & *v41;
            *v41 = v63 | ((unsigned int)*v41 >> v40);
            v63 = v57 << (32 - v40);
          }
          v42 = 2;
          v43 = (unsigned int *)(&v76 - v39);
          do
          {
            if ( v42 < v39 )
              *(&v74 + v42) = 0;
            else
              *(&v74 + v42) = *v43;
            --v43;
            --v42;
          }
          while ( v42 >= 0 );
          v5 = FloatFormat.max_exp + FloatFormat.bias;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_78;
      }
      v74 = v71;
      v75 = v72;
      v17 = (FloatFormat.min_exp - v53) / 32;
      v76 = v73;
      v18 = (FloatFormat.min_exp - v53) % 32;
      v60 = 0;
      for ( m = 0; m < 3; ++m )
      {
        v19 = (int *)(&v74 + m);
        v54 = ~(-1 << v18) & *v19;
        *v19 = v60 | ((unsigned int)*v19 >> v18);
        v60 = v54 << (32 - v18);
      }
      v20 = 2;
      v21 = (unsigned int *)(&v76 - v17);
      do
      {
        if ( v20 < v17 )
          *(&v74 + v20) = 0;
        else
          *(&v74 + v20) = *v21;
        --v21;
        --v20;
      }
      while ( v20 >= 0 );
      v22 = FloatFormat.precision - 1;
      v23 = FloatFormat.precision / 32;
      v52 = FloatFormat.precision / 32;
      v24 = &v74 + FloatFormat.precision / 32;
      v55 = 31 - FloatFormat.precision % 32;
      if ( ((1 << v55) & *v24) != 0 )
      {
        for ( n = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v74 + v23)) == 0; n; n = *(&v74 + v23) == 0 )
        {
          if ( ++v23 >= 3 )
            goto LABEL_51;
        }
        v26 = v22 / 32;
        v61 = 0;
        v27 = 1 << (31 - v22 % 32);
        v28 = &v74 + v22 / 32;
        v29 = *v28 + v27;
        if ( v29 < *v28 || v29 < v27 )
          v61 = 1;
        *v28 = v29;
        for ( ii = v61; --v26 >= 0 && ii != 0; ii = v33 )
        {
          v31 = &v74 + v26;
          v32 = *v31 + 1;
          v33 = 0;
          if ( v32 < *v31 || *v31 == -1 )
            v33 = 1;
          *v31 = v32;
        }
      }
LABEL_51:
      *v24 &= -1 << v55;
      if ( v52 + 1 < 3 )
        memset(&v74 + v52 + 1, 0, 4 * (3 - (v52 + 1)));
      v34 = (FloatFormat.exp_width + 1) / 32;
      v35 = (FloatFormat.exp_width + 1) % 32;
      v62 = 0;
      for ( jj = 0; jj < 3; ++jj )
      {
        v36 = (int *)(&v74 + jj);
        v56 = ~(-1 << v35) & *v36;
        *v36 = v62 | ((unsigned int)*v36 >> v35);
        v62 = v56 << (32 - v35);
      }
      v37 = 2;
      v38 = (unsigned int *)(&v76 - v34);
      do
      {
        if ( v37 < v34 )
          *(&v74 + v37) = 0;
        else
          *(&v74 + v37) = *v38;
        --v38;
        --v37;
      }
      while ( v37 >= 0 );
    }
    else
    {
      v74 = 0;
      v75 = 0.0;
      v76 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_78;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v74 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_78;
    }
  }
  v74 = 0;
  v75 = 0.0;
  v76 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_78:
  LODWORD(v48) = v74 | (v50 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v49 = v75;
    f[1].f = v48;
    f->f = v49;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v48;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E766E
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  __int64 v4; // rcx
  _LDBL12 *v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // ebx
  int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // esi
  int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // esi
  unsigned int v17; // esi
  int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // edi
  int v21; // ecx
  int v22; // edi
  unsigned int v23; // ecx
  __int64 v24; // kr10_8
  unsigned int tmp; // [esp+Ch] [ebp-18h]
  unsigned int tmp_4; // [esp+10h] [ebp-14h]
  int tmp_8; // [esp+14h] [ebp-10h]
  int v28; // [esp+18h] [ebp-Ch]
  unsigned int v29; // [esp+1Ch] [ebp-8h]
  int v30; // [esp+1Ch] [ebp-8h]
  __int16 expn; // [esp+20h] [ebp-4h]
  _LDBL12 *ld12a; // [esp+34h] [ebp+10h]
  int ld12b; // [esp+34h] [ebp+10h]
  int ld12c; // [esp+34h] [ebp+10h]
  int ld12d; // [esp+34h] [ebp+10h]

  HIDWORD(v4) = 0;
  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  *(_DWORD *)&ld12->ld12[8] = 0;
  if ( manlen != 0 )
  {
    ld12a = nullptr;
    do
    {
      tmp = *(_DWORD *)ld12->ld12;
      __SET_PAIR__(tmp_4, v4, *(_QWORD *)ld12->ld12);
      tmp_8 = *(_DWORD *)&ld12->ld12[8];
      v5 = ld12a;
      ld12b = 0;
      v6 = HIDWORD(v4);
      v7 = v4 >> 31;
      v8 = (v6 >> 31) | (2 * (_DWORD)v5);
      v9 = __SPAIR64__(v7, 2 * *(_DWORD *)ld12->ld12) >> 31;
      v29 = v9;
      v10 = 4 * *(_DWORD *)ld12->ld12;
      v11 = (v7 >> 31) | (2 * v8);
      v12 = 5 * *(_DWORD *)ld12->ld12;
      *(_DWORD *)ld12->ld12 = v10;
      *(_DWORD *)&ld12->ld12[4] = v9;
      *(_DWORD *)&ld12->ld12[8] = v11;
      if ( v12 < v10 || v12 < tmp )
        ld12b = 1;
      *(_DWORD *)ld12->ld12 = v12;
      if ( ld12b != 0 )
      {
        ld12c = 0;
        ++v9;
        if ( v29 + 1 < v29 || v29 == -1 )
          ld12c = 1;
        *(_DWORD *)&ld12->ld12[4] = v9;
        if ( ld12c != 0 )
          *(_DWORD *)&ld12->ld12[8] = ++v11;
      }
      ld12d = 0;
      v13 = v9 + tmp_4;
      if ( v9 + tmp_4 < v9 || v13 < tmp_4 )
        ld12d = 1;
      *(_DWORD *)&ld12->ld12[4] = v13;
      if ( ld12d != 0 )
        *(_DWORD *)&ld12->ld12[8] = ++v11;
      v30 = 0;
      v14 = (v13 >> 31) | (2 * (tmp_8 + v11));
      __SET_PAIR__(v16, v15, 2LL * v12);
      HIDWORD(v4) = v16 | (2 * v13);
      *(_DWORD *)&ld12->ld12[8] = v14;
      v28 = v14;
      ld12a = (_LDBL12 *)v14;
      *(_DWORD *)ld12->ld12 = v15;
      *(_DWORD *)&ld12->ld12[4] = HIDWORD(v4);
      v17 = *manptr;
      LODWORD(v4) = v15 + v17;
      if ( v15 + v17 < v15 || (unsigned int)v4 < v17 )
        v30 = 1;
      *(_DWORD *)ld12->ld12 = v4;
      if ( v30 != 0 )
      {
        LODWORD(v4) = HIDWORD(v4) + 1;
        v18 = 0;
        if ( (unsigned int)(HIDWORD(v4) + 1) < HIDWORD(v4) || HIDWORD(v4) == -1 )
          v18 = 1;
        ++HIDWORD(v4);
        *(_DWORD *)&ld12->ld12[4] = v4;
        if ( v18 != 0 )
        {
          ld12a = (_LDBL12 *)(v28 + 1);
          *(_DWORD *)&ld12->ld12[8] = v28 + 1;
        }
      }
      --manlen;
      ++manptr;
      *(_DWORD *)&ld12->ld12[4] = HIDWORD(v4);
      *(_DWORD *)&ld12->ld12[8] = ld12a;
    }
    while ( manlen != 0 );
  }
  if ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v19 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      expn -= 16;
      v20 = HIWORD(v19);
      v19 = HIWORD(*(_DWORD *)ld12->ld12) | (v19 << 16);
      v21 = *(_DWORD *)ld12->ld12 << 16;
      *(_DWORD *)&ld12->ld12[4] = v19;
      *(_DWORD *)ld12->ld12 = v21;
    }
    while ( v20 == 0 );
    *(_DWORD *)&ld12->ld12[8] = v20;
  }
  v22 = *(_DWORD *)&ld12->ld12[8];
  if ( (v22 & 0x8000) == 0 )
  {
    v23 = *(_DWORD *)&ld12->ld12[4];
    do
    {
      --expn;
      v22 = (v23 >> 31) | (2 * v22);
      v24 = 2LL * *(unsigned int *)ld12->ld12;
      v23 = HIDWORD(v24) | (2 * v23);
      *(_DWORD *)ld12->ld12 = v24;
      *(_DWORD *)&ld12->ld12[4] = v23;
      *(_DWORD *)&ld12->ld12[8] = v22;
    }
    while ( (v22 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x004E7852
// Name: ____lc_codepage_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl ___lc_codepage_func()
{
  _tiddata *v0; // ecx
  threadlocaleinfostruct *ptlocinfo; // eax

  v0 = _getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != __ptlocinfo && (__globallocalestatus & v0->_ownlocale) == 0 )
    ptlocinfo = __updatetlocinfo();
  return ptlocinfo->lc_codepage;
}

//------------------------------------------------------------------------------
// Address: 0x004E7880
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x004E78D0
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x004E7910
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void tzset_nolock()
{
  unsigned __int8 *v0; // eax
  unsigned __int8 *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  char **v8; // edi
  const char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  negdiff = 0;
  nochange = 0;
  timezone = 0;
  daylight = 0;
  dstbias = 0;
  _lock(locknum: 7);
  ms_exc.registration.TryLevel = 0;
  tzname = __tzname();
  if ( _get_timezone(_Timezone: &timezone) != 0
    || _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 )
  {
LABEL_12:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v0 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v1 = v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pMem: lastTZ);
      lastTZ = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth != 0 )
        timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth != 0 && tzinfo.DaylightBias != 0 )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *tzname,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        **tzname = 0;
      }
      else
      {
        (*tzname)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: tzname[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        *tzname[1] = 0;
      }
      else
      {
        tzname[1][63] = 0;
      }
    }
    goto LABEL_30;
  }
  if ( lastTZ != nullptr )
  {
    strcmp(str1: v0, str2: (unsigned __int8 *)lastTZ);
    if ( v2 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pMem: lastTZ);
  }
  strlen(buf: v1);
  lastTZ = (char *)operator new(nSize: v3 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v1);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v4 + 1, _Src: (const char *)v1) != 0 )
    goto LABEL_12;
LABEL_31:
  v5 = timezone;
  *__timezone() = v5;
  v6 = daylight;
  *__daylight() = v6;
  v7 = dstbias;
  *__dstbias() = v7;
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    v8 = tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: (const char *)v1, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = (const char *)(v1 + 3);
    if ( *v9 == 45 )
    {
      negdiff = 1;
      ++v9;
    }
    timezone = 3600 * atol(nptr: v9);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 != 43 && (v10 < 48 || v10 > 57) )
        break;
      ++v9;
    }
    if ( *v9 == 58 )
    {
      v11 = atol(nptr: ++v9);
      timezone += 60 * v11;
      while ( *v9 >= 48 && *v9 <= 57 )
        ++v9;
      if ( *v9 == 58 )
      {
        v12 = atol(nptr: ++v9);
        timezone += v12;
        while ( *v9 >= 48 && *v9 <= 57 )
          ++v9;
      }
    }
    if ( negdiff != 0 )
      timezone = -timezone;
    daylight = *v9;
    if ( daylight != 0 )
    {
      if ( strncpy_s(_Dst: v8[1], _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      *v8[1] = 0;
    }
    v13 = timezone;
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E7E1A
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isindst_nolock@<eax>(tm *tb@<edi>)
{
  int result; // eax
  int tm_year; // edx
  int v3; // eax
  int v4; // ecx
  int tm_yday; // edx
  int v6; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  result = _get_daylight(_Daylight: &daylight);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( daylight != 0 )
  {
    tm_year = tb->tm_year;
    if ( tm_year != dststart.yr || tm_year != dstend.yr )
    {
      if ( tzapiused != 0 )
      {
        if ( tzinfo.DaylightDate.wYear != 0 )
          cvtdate(
            trantype: 1,
            datetype: 0,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.DaylightDate.wDay,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        else
          cvtdate(
            trantype: 1,
            datetype: 1,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: tzinfo.DaylightDate.wDay,
            dayofweek: tzinfo.DaylightDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        if ( tzinfo.StandardDate.wYear != 0 )
          cvtdate(
            trantype: 0,
            datetype: 0,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.StandardDate.wDay,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
        else
          cvtdate(
            trantype: 0,
            datetype: 1,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: tzinfo.StandardDate.wDay,
            dayofweek: tzinfo.StandardDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
      }
      else
      {
        v3 = 3;
        v4 = 2;
        endmonth = 11;
        endweek = 1;
        if ( tm_year < 107 )
        {
          v3 = 4;
          v4 = 1;
          endmonth = 10;
          endweek = 5;
        }
        cvtdate(
          trantype: 1,
          datetype: 1,
          year: tm_year,
          month: v3,
          week: v4,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
        cvtdate(
          trantype: 0,
          datetype: 1,
          year: tb->tm_year,
          month: endmonth,
          week: endweek,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
      }
    }
    tm_yday = tb->tm_yday;
    if ( dststart.yd >= dstend.yd )
    {
      if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
        return 1;
      if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
        goto LABEL_28;
    }
    else if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1;
LABEL_28:
      v6 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
      if ( tm_yday == dststart.yd )
        return v6 >= dststart.ms;
      else
        return v6 < dstend.ms;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E7FF1
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __tzset()
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock();
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8040
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isindst(tm *tb)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 6);
  retval = isindst_nolock(tb);
  _unlock(locknum: 6);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004E8081
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_daylight(int *_Daylight)
{
  if ( _Daylight != nullptr )
  {
    *_Daylight = _daylight;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E80AE
// Name: __get_dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_dstbias(int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias != nullptr )
  {
    *_Daylight_savings_bias = _dstbias;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E80DB
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_timezone(int *_Timezone)
{
  if ( _Timezone != nullptr )
  {
    *_Timezone = _timezone;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8108
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __daylight()
{
  return &_daylight;
}

//------------------------------------------------------------------------------
// Address: 0x004E810E
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dstbias()
{
  return &_dstbias;
}

//------------------------------------------------------------------------------
// Address: 0x004E8114
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __timezone()
{
  return &_timezone;
}

//------------------------------------------------------------------------------
// Address: 0x004E811A
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__cdecl __tzname()
{
  return _tzname;
}

//------------------------------------------------------------------------------
// Address: 0x004E8120
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double x)
{
  return rint(x);
}

//------------------------------------------------------------------------------
// Address: 0x004E8134
// Name: __fpclass
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fpclass(long double x)
{
  int v1; // eax
  int v2; // eax
  int v4; // ecx

  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v1 = _sptype(x) - 1;
    if ( v1 != 0 )
    {
      v2 = v1 - 1;
      if ( v2 == 0 )
        return 4;
      if ( v2 != 1 )
        return 1;
      return 2;
    }
    else
    {
      return 512;
    }
  }
  else
  {
    v4 = HIWORD(x) & 0x8000;
    if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
    {
      return v4 != 0 ? 16 : 128;
    }
    else if ( 0.0 == x )
    {
      return v4 != 0 ? 32 : 64;
    }
    else
    {
      return v4 != 0 ? 8 : 256;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E81D1
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double retval; // [esp+0h] [ebp-8h]

  retval = x;
  HIWORD(retval) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004E81FE
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x) != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E8264
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, exp: 0);
  }
  else
  {
    result = _set_exp(x, exp: 0);
    v3 = ((HIWORD(x) >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E8327
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = _fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x004E840A
// Name: _ungetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ungetc(int ch, _iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ungetc_nolock(ch, str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E8473
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *(unsigned __int8 *)s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E8589
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E85B0
// Name: __CIcos_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004E875C
// Name: __fgetwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __cdecl _fgetwc_nolock(_iobuf *stream)
{
  unsigned __int16 **v1; // esi
  ioinfo **v2; // edi
  ioinfo *v3; // eax
  bool v4; // sf
  int v5; // eax
  int v7; // eax
  ioinfo **v8; // edi
  ioinfo *v9; // eax
  unsigned int v10; // edi
  int v11; // eax
  int v12; // eax
  char mbc[4]; // [esp+Ch] [ebp-4h] BYREF

  v1 = (unsigned __int16 **)stream;
  if ( (stream->_flag & 0x40) == 0 )
  {
    if ( _fileno(stream) == -1 || _fileno(stream: (_iobuf *)v1) == -2 )
    {
      v3 = &__badioinfo;
    }
    else
    {
      v2 = &__pioinfo[_fileno(stream: (_iobuf *)v1) >> 5];
      v3 = &(*v2)[_fileno(stream: (_iobuf *)v1) & 0x1F];
    }
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0 )
    {
      v4 = (int)v1[1] - 1 < 0;
      v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
      if ( v4 )
      {
        v5 = _filbuf(str: (_iobuf *)v1);
      }
      else
      {
        v5 = *(unsigned __int8 *)*v1;
        *v1 = (unsigned __int16 *)((char *)*v1 + 1);
      }
      if ( v5 != -1 )
      {
        v4 = (int)v1[1] - 1 < 0;
        v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
        LOBYTE(stream) = v5;
        if ( v4 )
        {
          v7 = _filbuf(str: (_iobuf *)v1);
        }
        else
        {
          v7 = *(unsigned __int8 *)*v1;
          *v1 = (unsigned __int16 *)((char *)*v1 + 1);
        }
        if ( v7 != -1 )
        {
          BYTE1(stream) = v7;
          return (unsigned __int16)stream;
        }
      }
      return -1;
    }
    if ( ((_BYTE)v1[3] & 0x40) == 0 )
    {
      if ( _fileno(stream: (_iobuf *)v1) == -1 || _fileno(stream: (_iobuf *)v1) == -2 )
      {
        v9 = &__badioinfo;
      }
      else
      {
        v8 = &__pioinfo[_fileno(stream: (_iobuf *)v1) >> 5];
        v9 = &(*v8)[_fileno(stream: (_iobuf *)v1) & 0x1F];
      }
      if ( v9->osfile < 0 )
      {
        v10 = 1;
        v4 = (int)v1[1] - 1 < 0;
        v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
        if ( v4 )
        {
          v11 = _filbuf(str: (_iobuf *)v1);
        }
        else
        {
          v11 = *(unsigned __int8 *)*v1;
          *v1 = (unsigned __int16 *)((char *)*v1 + 1);
        }
        if ( v11 == -1 )
          return -1;
        mbc[0] = v11;
        if ( isleadbyte(c: (unsigned __int8)v11) != 0 )
        {
          v4 = (int)v1[1] - 1 < 0;
          v1[1] = (unsigned __int16 *)((char *)v1[1] - 1);
          if ( v4 )
          {
            v12 = _filbuf(str: (_iobuf *)v1);
          }
          else
          {
            v12 = *(unsigned __int8 *)*v1;
            *v1 = (unsigned __int16 *)((char *)*v1 + 1);
          }
          if ( v12 == -1 )
          {
            ungetc(ch: mbc[0], stream: (_iobuf *)v1);
            return -1;
          }
          mbc[1] = v12;
          v10 = 2;
        }
        if ( mbtowc(pwc: (wchar_t *)&stream, s: mbc, n: v10) != -1 )
          return (unsigned __int16)stream;
        *_errno() = 42;
        return -1;
      }
    }
  }
  v4 = (int)--v1[1] < 0;
  if ( v4 )
    return _filwbuf(str: (_iobuf *)v1);
  return *(*v1)++;
}

//------------------------------------------------------------------------------
// Address: 0x004E8907
// Name: __ungetwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _ungetwc_nolock(wchar_t ch, _iobuf *str)
{
  wchar_t v2; // bx
  int flag; // eax
  ioinfo **v4; // edi
  ioinfo *v5; // eax
  ioinfo **v6; // edi
  ioinfo *v7; // eax
  wchar_t v8; // dx
  int v9; // eax
  char *v10; // ecx
  int v11; // ecx
  char *v13; // eax
  char *ptr; // eax
  int v15; // eax
  int size; // [esp+Ch] [ebp-10h] BYREF
  char mbc[8]; // [esp+10h] [ebp-Ch] BYREF

  v2 = ch;
  if ( ch == 0xFFFF )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( (str->_flag & 0x40) != 0 )
  {
LABEL_30:
    v13 = str->_base + 2;
    if ( str->_ptr < v13 )
    {
      if ( str->_cnt != 0 || str->_bufsiz < 2u )
        return -1;
      str->_ptr = v13;
    }
    str->_ptr -= 2;
    ptr = str->_ptr;
    if ( (str->_flag & 0x40) != 0 )
    {
      if ( *(_WORD *)ptr != v2 )
      {
        str->_ptr = ptr + 2;
        return -1;
      }
    }
    else
    {
      *(_WORD *)ptr = v2;
    }
    v15 = str->_flag;
    str->_cnt += 2;
    str->_flag = v15 & 0xFFFFFFEE | 1;
    return v2;
  }
  if ( _fileno(stream: str) == -1 || _fileno(stream: str) == -2 )
  {
    v5 = &__badioinfo;
  }
  else
  {
    v4 = &__pioinfo[_fileno(stream: str) >> 5];
    v5 = &(*v4)[_fileno(stream: str) & 0x1F];
  }
  if ( v5->osfile >= 0 )
  {
    v2 = ch;
    goto LABEL_30;
  }
  if ( _fileno(stream: str) == -1 || _fileno(stream: str) == -2 )
  {
    v7 = &__badioinfo;
  }
  else
  {
    v6 = &__pioinfo[_fileno(stream: str) >> 5];
    v7 = &(*v6)[_fileno(stream: str) & 0x1F];
  }
  if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0 )
  {
    v8 = ch;
    v9 = 2;
    *(_WORD *)mbc = ch;
    size = 2;
  }
  else
  {
    if ( wctomb_s(pRetValue: &size, dst: mbc, sizeInBytes: 5u, wchar: ch) != 0 )
      return -1;
    v9 = size;
    v8 = ch;
  }
  v10 = &str->_base[v9];
  if ( str->_ptr < v10 )
  {
    if ( str->_cnt == 0 && v9 <= str->_bufsiz )
    {
      str->_ptr = v10;
      goto LABEL_25;
    }
    return -1;
  }
LABEL_25:
  v11 = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    do
      *--str->_ptr = mbc[v11--];
    while ( v11 >= 0 );
    v9 = size;
  }
  str->_cnt += v9;
  str->_flag = str->_flag & 0xFFFFFFEE | 1;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004E8AC1
// Name: __wcstombs_l_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _wcstombs_l_helper(char *s, const wchar_t *pwcs, unsigned int n, localeinfo_struct *plocinfo)
{
  const wchar_t *v4; // esi
  unsigned int result; // eax
  threadlocaleinfostruct *locinfo; // edi
  __int16 v7; // cx
  unsigned int v8; // ecx
  const wchar_t *v9; // eax
  unsigned int v10; // eax
  int v11; // edx
  int v12; // ecx
  char v13; // cl
  WCHAR v14; // cx
  const wchar_t *v15; // edx
  int retval; // [esp+Ch] [ebp-30h]
  int i; // [esp+10h] [ebp-2Ch]
  unsigned int count; // [esp+18h] [ebp-24h]
  _LocaleUpdate _loc_update; // [esp+1Ch] [ebp-20h] BYREF
  int defused; // [esp+2Ch] [ebp-10h] BYREF
  char buffer[8]; // [esp+30h] [ebp-Ch] BYREF

  v4 = pwcs;
  defused = 0;
  if ( s != nullptr && n == 0 )
    return 0;
  if ( pwcs == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( s == nullptr )
  {
    if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
    {
      v14 = *pwcs;
      result = 0;
      v15 = pwcs;
      while ( v14 != 0 )
      {
        if ( v14 > 0xFFu )
          goto LABEL_50;
        ++result;
        v14 = *++v15;
      }
      goto LABEL_12;
    }
    result = WideCharToMultiByte(
               CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
               dwFlags: 0,
               lpWideCharStr: pwcs,
               cchWideChar: -1,
               lpMultiByteStr: nullptr,
               cbMultiByte: 0,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: &defused);
    if ( result == 0 )
      goto LABEL_50;
    goto LABEL_27;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    result = 0;
    if ( n != 0 )
    {
      while ( *v4 <= 0xFFu )
      {
        s[result] = *(_BYTE *)v4;
        v7 = *v4++;
        if ( v7 != 0 && ++result < n )
          continue;
        goto LABEL_12;
      }
      goto LABEL_50;
    }
    goto LABEL_12;
  }
  if ( _loc_update.localeinfo.locinfo->mb_cur_max == 1 )
  {
    v8 = n;
    if ( n != 0 )
    {
      v9 = pwcs;
      do
      {
        if ( *v9 == 0 )
          break;
        ++v9;
        --v8;
      }
      while ( v8 != 0 );
      if ( v8 != 0 && *v9 == 0 )
        n = v9 - pwcs + 1;
    }
    result = WideCharToMultiByte(
               CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
               dwFlags: 0,
               lpWideCharStr: pwcs,
               cchWideChar: n,
               lpMultiByteStr: s,
               cbMultiByte: n,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: &defused);
    if ( result != 0 && defused == 0 )
    {
      if ( s[result - 1] != 0 )
        goto LABEL_12;
      goto LABEL_28;
    }
    goto LABEL_50;
  }
  result = WideCharToMultiByte(
             CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
             dwFlags: 0,
             lpWideCharStr: pwcs,
             cchWideChar: -1,
             lpMultiByteStr: s,
             cbMultiByte: n,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused);
  count = result;
  if ( result != 0 )
  {
LABEL_27:
    if ( defused == 0 )
    {
LABEL_28:
      --result;
LABEL_12:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
LABEL_50:
    *_errno() = 42;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
  if ( defused != 0 || GetLastError() != 122 )
    goto LABEL_50;
  if ( n != 0 )
  {
    do
    {
      v10 = WideCharToMultiByte(
              CodePage: locinfo->lc_codepage,
              dwFlags: 0,
              lpWideCharStr: v4,
              cchWideChar: 1,
              lpMultiByteStr: buffer,
              cbMultiByte: locinfo->mb_cur_max,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: &defused);
      v11 = v10;
      retval = v10;
      if ( v10 == 0 || defused != 0 || v10 > 5 )
        goto LABEL_50;
      result = count;
      if ( v11 + count > n )
        goto LABEL_12;
      v12 = 0;
      i = 0;
      if ( v11 > 0 )
      {
        do
        {
          v13 = buffer[v12];
          s[result] = v13;
          if ( v13 == 0 )
            goto LABEL_12;
          v12 = i + 1;
          ++result;
          i = v12;
          count = result;
        }
        while ( v12 < retval );
      }
      ++v4;
    }
    while ( result < n );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x004E8D28
// Name: __wcstombs_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcstombs_s_l(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        const wchar_t *src,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  int *v9; // eax
  unsigned int v10; // eax
  int v11; // [esp-4h] [ebp-14h]
  int retvalue; // [esp+Ch] [ebp-4h]

  retvalue = 0;
  if ( dst != nullptr )
  {
    if ( sizeInBytes != 0 )
      goto LABEL_3;
LABEL_15:
    v9 = _errno();
    v11 = 22;
LABEL_16:
    *v9 = v11;
    _invalid_parameter_noinfo();
    return v11;
  }
  if ( sizeInBytes != 0 )
    goto LABEL_15;
LABEL_3:
  if ( dst != nullptr )
    *dst = 0;
  if ( pConvertedChars != nullptr )
    *pConvertedChars = 0;
  v6 = n;
  if ( n > sizeInBytes )
    v6 = sizeInBytes;
  if ( v6 > 0x7FFFFFFF )
    goto LABEL_15;
  v7 = _wcstombs_l_helper(s: dst, pwcs: src, n: v6, plocinfo);
  if ( v7 == -1 )
  {
    if ( dst != nullptr )
      *dst = 0;
    return *_errno();
  }
  v10 = v7 + 1;
  if ( dst != nullptr )
  {
    if ( v10 > sizeInBytes )
    {
      if ( n != -1 )
      {
        *dst = 0;
        if ( sizeInBytes <= v10 )
        {
          v9 = _errno();
          v11 = 34;
          goto LABEL_16;
        }
      }
      v10 = sizeInBytes;
      retvalue = 80;
    }
    dst[v10 - 1] = 0;
  }
  if ( pConvertedChars != nullptr )
    *pConvertedChars = v10;
  return retvalue;
}

//------------------------------------------------------------------------------
// Address: 0x004E8DDA
// Name: _wcstombs_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstombs_s(
        unsigned int *pConvertedChars,
        char *dst,
        unsigned int sizeInBytes,
        const wchar_t *src,
        unsigned int n)
{
  return _wcstombs_s_l(pConvertedChars, dst, sizeInBytes, src, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004E8DFA
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  __int64 v2; // rax
  int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  __int64 v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  __int64 v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 1);
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2 = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 2);
  if ( (HIDWORD(v2) & (unsigned int)v2) == 0xFFFFFFFF )
    return *_errno();
  v3 = (unsigned __int64)(size - v2) >> 32;
  v4 = size - v2;
  if ( v3 >= 0 && (size >= v2 && (unsigned __int64)(size - v2) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( v20 == nullptr )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(fh: filedes, mode: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(fh: filedes, buf: v20, cnt: v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && v10 == 0 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(fh: filedes, mode: oldmode);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem: v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13 = _lseeki64_nolock(fh: filedes, pos: size, mthd: 0);
    if ( (HIDWORD(v13) & (unsigned int)v13) == 0xFFFFFFFF )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    retval = SetEndOfFile(hFile: osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16 = _lseeki64_nolock(fh: filedes, pos: place, mthd: 0);
  if ( (HIDWORD(v16) & (unsigned int)v16) == 0xFFFFFFFF )
    return *_errno();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E8FB0
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock(int fh, int mode)
{
  ioinfo **v2; // edx
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // ecx
  char v8; // dl

  v2 = &__pioinfo[fh >> 5];
  v3 = (fh & 0x1F) << 6;
  v4 = (char *)*v2 + v3;
  v5 = v4[4] & 0x80;
  v6 = (char)(2 * v4[36]) >> 1;
  if ( mode == 0x4000 )
  {
    v4[4] |= 0x80u;
    *((_BYTE *)*v2 + v3 + 36) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[4] &= ~0x80u;
  }
  else
  {
    if ( mode == 0x10000 || mode == 0x20000 )
    {
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 2;
    }
    else
    {
      if ( mode != 0x40000 )
        goto LABEL_11;
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 1;
    }
    *v7 = v8;
  }
LABEL_11:
  if ( v5 != 0 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x004E906B
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_fmode(int *pMode)
{
  if ( pMode != nullptr )
  {
    *pMode = _fmode;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9098
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  unsigned int cchWritten; // [esp+0h] [ebp-4h] BYREF

  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1
    || !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &cchWritten,
          lpReserved: nullptr) )
  {
    return -1;
  }
  else
  {
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E90DA
// Name: __mbsnbcpy_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcpy_s_l(
        unsigned __int8 *_Dst,
        unsigned int _SizeInBytes,
        const unsigned __int8 *_Src,
        unsigned int _CountInBytes,
        localeinfo_struct *_LocInfo)
{
  int result; // eax
  unsigned int v6; // ebx
  const unsigned __int8 *v7; // edi
  int v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edx
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // cl
  unsigned __int8 *v13; // edi
  unsigned __int8 *j; // ebx
  unsigned __int8 *v15; // edi
  unsigned __int8 *i; // ebx
  unsigned __int8 *k; // ebx
  int *v18; // ecx
  _LocaleUpdate _LocUpdate; // [esp+8h] [ebp-10h] BYREF

  if ( _CountInBytes != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 22;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _CountInBytes == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_LocUpdate, plocinfo: _LocInfo);
  if ( _LocUpdate.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncpy_s((char *)_Dst, _SizeInBytes, (const char *)_Src, _Count: _CountInBytes);
    goto LABEL_52;
  }
  v9 = _Dst;
  v10 = _SizeInBytes;
  if ( _CountInBytes == -1 )
  {
    do
    {
      v11 = *v7;
      *v9++ = *v7++;
      if ( v11 == 0 )
        break;
      --v10;
    }
    while ( v10 != 0 );
  }
  else
  {
    do
    {
      v12 = *v7;
      *v9++ = *v7++;
      if ( v12 == 0 )
        break;
      if ( --v10 == 0 )
        break;
      --_CountInBytes;
    }
    while ( _CountInBytes != 0 );
    if ( _CountInBytes == 0 )
      *v9++ = 0;
  }
  if ( v10 == 0 )
  {
    if ( *v7 != 0 && _CountInBytes != 1 )
    {
LABEL_31:
      if ( _CountInBytes != -1 )
      {
        *_Dst = 0;
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter_noinfo();
        if ( _LocUpdate.updated )
          _LocUpdate.ptd->_ownlocale &= ~2u;
        return v8;
      }
      if ( v6 > 1 )
      {
        v15 = &_Dst[v6 - 2];
        for ( i = v15; i >= _Dst; --i )
        {
          if ( _ismbblead_l(tst: *i, plocinfo: &_LocUpdate.localeinfo) == 0 )
            break;
        }
        if ( (((_BYTE)v15 - (_BYTE)i) & 1) != 0 )
        {
          *v15 = 0;
LABEL_40:
          if ( _LocUpdate.updated )
            _LocUpdate.ptd->_ownlocale &= ~2u;
          return 80;
        }
        v6 = _SizeInBytes;
      }
      _Dst[v6 - 1] = 0;
      goto LABEL_40;
    }
    v13 = v9 - 1;
    for ( j = v9 - 1; j >= _Dst; --j )
    {
      if ( _ismbblead_l(tst: *j, plocinfo: &_LocUpdate.localeinfo) == 0 )
        break;
    }
    if ( (((_BYTE)v13 - (_BYTE)j) & 1) == 0 )
    {
      v6 = _SizeInBytes;
      goto LABEL_31;
    }
LABEL_51:
    *v13 = 0;
    v18 = _errno();
    result = 42;
    *v18 = 42;
LABEL_52:
    if ( _LocUpdate.updated )
      _LocUpdate.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( v9 - _Dst >= 2 )
  {
    v13 = v9 - 2;
    for ( k = v9 - 2; k >= _Dst; --k )
    {
      if ( _ismbblead_l(tst: *k, plocinfo: &_LocUpdate.localeinfo) == 0 )
        break;
    }
    if ( (((_BYTE)v13 - (_BYTE)k) & 1) != 0 )
      goto LABEL_51;
  }
  if ( _LocUpdate.updated )
    _LocUpdate.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E92C2
// Name: __fputwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _fputwc_nolock(wchar_t ch, _iobuf *str)
{
  ioinfo **v2; // edi
  ioinfo *v3; // eax
  ioinfo **v4; // edi
  ioinfo *v5; // eax
  ioinfo **v6; // edi
  ioinfo *v7; // eax
  int v9; // edi
  bool v10; // sf
  int v11; // eax
  int size; // [esp+Ch] [ebp-10h] BYREF
  char mbc[8]; // [esp+10h] [ebp-Ch] BYREF

  if ( (str->_flag & 0x40) != 0
    || (_fileno(stream: str) == -1 || _fileno(stream: str) == -2
      ? (v3 = &__badioinfo)
      : (v2 = &__pioinfo[_fileno(stream: str) >> 5], v3 = &(*v2)[_fileno(stream: str) & 0x1F]),
        (*((_BYTE *)v3 + 36) & 0x7F) == 2
     || (_fileno(stream: str) == -1 || _fileno(stream: str) == -2
       ? (v5 = &__badioinfo)
       : (v4 = &__pioinfo[_fileno(stream: str) >> 5], v5 = &(*v4)[_fileno(stream: str) & 0x1F]),
         (*((_BYTE *)v5 + 36) & 0x7F) == 1
      || (_fileno(stream: str) == -1 || _fileno(stream: str) == -2
        ? (v7 = &__badioinfo)
        : (v6 = &__pioinfo[_fileno(stream: str) >> 5], v7 = &(*v6)[_fileno(stream: str) & 0x1F]),
          v7->osfile >= 0))) )
  {
    v10 = str->_cnt - 2 < 0;
    str->_cnt -= 2;
    if ( v10 )
    {
      return _flswbuf(ch, str);
    }
    else
    {
      *(_WORD *)str->_ptr = ch;
      str->_ptr += 2;
      return ch;
    }
  }
  else
  {
    if ( wctomb_s(pRetValue: &size, dst: mbc, sizeInBytes: 5u, wchar: ch) != 0 )
      return -1;
    v9 = 0;
    if ( size > 0 )
    {
      while ( 1 )
      {
        v10 = --str->_cnt < 0;
        if ( v10 )
        {
          v11 = _flsbuf(ch: mbc[v9], str);
        }
        else
        {
          *str->_ptr = mbc[v9];
          v11 = *(unsigned __int8 *)str->_ptr++;
        }
        if ( v11 == -1 )
          break;
        if ( ++v9 >= size )
          return ch;
      }
      return -1;
    }
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9449
// Name: __matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _matherr()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E944C
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
    default:
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat != 0 )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(
    dwExceptionCode: flags,
    dwExceptionFlags: 0,
    nNumberOfArguments: 1u,
    lpArguments: (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( v18 == 0 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( v19 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( v22 == 0 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( v23 == 0 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat != 0 )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}

//------------------------------------------------------------------------------
// Address: 0x004E9728
// Name: __raise_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(prec, pcw, flags, opcode, (float *)parg1, (float *)presult, isfloat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004E974B
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-14h]
  int expn; // [esp+24h] [ebp-8h] BYREF
  int flags_p; // [esp+28h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(sw: 1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(sw: 4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(sw: 8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = true;
      goto LABEL_43;
    }
    v13 = _decomp(x: *presult, pexp: &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = true;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = true;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *presult = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(sw: 0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(sw: 0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004E992F
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E995C
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode(char flags)
{
  if ( (flags & 0x20) != 0 )
    return 5;
  if ( (flags & 8) != 0 )
    return 1;
  if ( (flags & 4) != 0 )
    return 2;
  if ( (flags & 1) != 0 )
    return 3;
  return 2 * (flags & 2);
}

//------------------------------------------------------------------------------
// Address: 0x004E9990
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_51D608[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = nullptr;
      goto LABEL_5;
    }
  }
  v7 = (&off_51D60C)[2 * v6];
LABEL_5:
  if ( v7 != nullptr )
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    if ( _matherr() == 0 )
      _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
  else
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9A30
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( _matherr_flag == 0 )
    return _umatherr(type: 1, opcode, arg1: x, arg2: 0.0, retval: x, cw: savedcw);
  *_errno() = 33;
  _ctrlfp(newctrl: savedcw, _mask: 0xFFFFu);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x004E9A85
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _except1@<st0>(
        int a1@<ebp>,
        int flags,
        int opcode,
        long double arg,
        long double result,
        unsigned int cw)
{
  int v6; // eax
  int v8; // [esp+1Ch] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+28h] [ebp-80h]
  int v10; // [esp+9Ch] [ebp-Ch]
  void *v11; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  if ( !_handle_exc(flags, presult: &result, cw) )
  {
    rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
    _raise_exc_ex(
      prec: (_FPIEEE_RECORD *)&v8,
      pcw: &cw,
      flags,
      opcode,
      parg1: (float *)&arg,
      presult: (float *)&result,
      isfloat: 0);
  }
  v6 = _errcode(flags);
  if ( _matherr_flag == 0 && v6 != 0 )
    return _umatherr(type: v6, opcode, arg1: arg, arg2: 0.0, retval: result, cw);
  _set_errno_from_matherr(matherrtype: v6);
  _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004E9B4F
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9B5F
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x004E9B70
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x004E9B9B
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004E9BF3
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E9C70
// Name: __CItan_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004E9EC4
// Name: sub_4E9EC4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_4E9EC4(wchar_t a1)
{
  return _wchartodigit(ch: a1);
}

//------------------------------------------------------------------------------
// Address: 0x004E9ED0
// Name: __wchartodigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wchartodigit(wchar_t ch)
{
  int v2; // ecx
  wchar_t v3; // dx

  if ( ch < 0x30u )
    return -1;
  if ( ch < 0x3Au )
    return ch - 48;
  v2 = 65296;
  if ( ch >= 0xFF10u )
  {
    v3 = -230;
LABEL_39:
    if ( ch < v3 )
      return ch - v2;
    return -1;
  }
  v2 = 1632;
  if ( ch >= 0x660u )
  {
    if ( ch < 0x66Au )
      return ch - v2;
    v2 = 1776;
    if ( ch >= 0x6F0u )
    {
      if ( ch < 0x6FAu )
        return ch - v2;
      v2 = 2406;
      if ( ch >= 0x966u )
      {
        if ( ch < 0x970u )
          return ch - v2;
        v2 = 2534;
        if ( ch >= 0x9E6u )
        {
          if ( ch < 0x9F0u )
            return ch - v2;
          v2 = 2662;
          if ( ch >= 0xA66u )
          {
            if ( ch < 0xA70u )
              return ch - v2;
            v2 = 2790;
            if ( ch >= 0xAE6u )
            {
              if ( ch < 0xAF0u )
                return ch - v2;
              v2 = 2918;
              if ( ch >= 0xB66u )
              {
                if ( ch < 0xB70u )
                  return ch - v2;
                v2 = 3174;
                if ( ch >= 0xC66u )
                {
                  if ( ch < 0xC70u )
                    return ch - v2;
                  v2 = 3302;
                  if ( ch >= 0xCE6u )
                  {
                    if ( ch < 0xCF0u )
                      return ch - v2;
                    v2 = 3430;
                    if ( ch >= 0xD66u )
                    {
                      if ( ch < 0xD70u )
                        return ch - v2;
                      v2 = 3664;
                      if ( ch >= 0xE50u )
                      {
                        if ( ch < 0xE5Au )
                          return ch - v2;
                        v2 = 3792;
                        if ( ch >= 0xED0u )
                        {
                          if ( ch < 0xEDAu )
                            return ch - v2;
                          v2 = 3872;
                          if ( ch >= 0xF20u )
                          {
                            if ( ch < 0xF2Au )
                              return ch - v2;
                            v2 = 4160;
                            if ( ch >= 0x1040u )
                            {
                              if ( ch < 0x104Au )
                                return ch - v2;
                              v2 = 6112;
                              if ( ch >= 0x17E0u )
                              {
                                if ( ch < 0x17EAu )
                                  return ch - v2;
                                v2 = 6160;
                                if ( ch >= 0x1810u )
                                {
                                  v3 = 6170;
                                  goto LABEL_39;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA070
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  unsigned __int16 v4; // dx
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax
  int v9; // ebx
  bool v10; // zf
  char v11; // cl
  int v12; // ecx
  _LDBL12 *p_tmp12; // eax
  unsigned __int8 *v14; // esi
  __int16 v15; // cx
  unsigned __int16 v16; // di
  _WORD *v17; // esi
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  __int16 v21; // di
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 v28; // si
  int v29; // eax
  _WORD *v30; // edi
  unsigned __int8 *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  __int16 v35; // si
  unsigned int v36; // ecx
  unsigned int v37; // edx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // edi
  int v41; // ecx
  int v42; // edi
  int v43; // esi
  unsigned int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // esi
  int v48; // eax
  int v49; // ebx
  int v50; // eax
  char *man; // ebx
  unsigned int v52; // edx
  unsigned int v53; // edi
  unsigned int v54; // ecx
  int v55; // esi
  int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // edi
  int v59; // edx
  unsigned int v60; // edx
  char v61; // al
  char *v62; // ebx
  _FloatOutStruct *v63; // eax
  char v64; // bl
  unsigned __int8 *v65; // [esp+10h] [ebp-70h]
  unsigned __int8 *v66; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v67; // [esp+18h] [ebp-68h]
  __int16 sign; // [esp+20h] [ebp-60h]
  int v69; // [esp+24h] [ebp-5Ch]
  __int16 v70; // [esp+24h] [ebp-5Ch]
  __int16 v71; // [esp+28h] [ebp-58h]
  unsigned __int8 *v72; // [esp+28h] [ebp-58h]
  int v73; // [esp+2Ch] [ebp-54h]
  int v74; // [esp+2Ch] [ebp-54h]
  int v75; // [esp+30h] [ebp-50h]
  int v76; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v79; // [esp+38h] [ebp-48h]
  int v80; // [esp+38h] [ebp-48h]
  _LDBL12 *v81; // [esp+3Ch] [ebp-44h]
  int v82; // [esp+3Ch] [ebp-44h]
  int v83; // [esp+3Ch] [ebp-44h]
  unsigned int v84; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v87; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v91[12]; // [esp+70h] [ebp-10h] BYREF

  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  v4 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 8);
  *(_DWORD *)&ld12_one_tenth.ld12[8] = 1073466572;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  if ( v4 != 0 )
  {
    if ( v4 != 0x7FFF )
      goto LABEL_28;
    fos->exp = 1;
    if ( (*(_DWORD *)&ld.ld[4] != 0x80000000 || *(_DWORD *)ld.ld != 0) && (*(_DWORD *)&ld.ld[4] & 0x40000000) == 0 )
    {
      v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
      goto LABEL_25;
    }
    if ( sign != 0 && *(_DWORD *)&ld.ld[4] == -1073741824 )
    {
      if ( *(_DWORD *)ld.ld == 0 )
      {
        v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
        goto LABEL_22;
      }
    }
    else if ( *(_DWORD *)&ld.ld[4] == 0x80000000 && *(_DWORD *)ld.ld == 0 )
    {
      v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
LABEL_22:
      if ( v7 == 0 )
      {
        fos->ManLen = 5;
        return 0;
      }
LABEL_14:
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    }
    v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
LABEL_25:
    if ( v6 == 0 )
    {
      fos->ManLen = 6;
      return 0;
    }
    goto LABEL_14;
  }
  if ( *(_DWORD *)&ld.ld[4] == 0 && *(_DWORD *)ld.ld == 0 )
  {
    fos->exp = 0;
    fos->sign = sign != -32768 ? 32 : 45;
    *(_WORD *)&fos->ManLen = 12289;
    fos->man[1] = 0;
    return 1;
  }
LABEL_28:
  v8 = (77 * (HIBYTE(v4) + 2 * ld.ld[7]) + 19728 * (unsigned int)v4 - 323162868) >> 16;
  *(_WORD *)ld12.ld12 = 0;
  v9 = -v8;
  digcount = v8;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&ld.ld[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)ld.ld;
  v67 = &_pow10pos[-8];
  if ( v8 != 0 )
  {
    v10 = v8 == 0;
    if ( v8 > 0 )
    {
      v9 = v8;
      v67 = &_pow10neg[-8];
      v10 = v8 == 0;
    }
    if ( !v10 )
    {
      do
      {
        v67 += 7;
        v11 = v9;
        v9 >>= 3;
        v12 = v11 & 7;
        if ( v12 != 0 )
        {
          p_tmp12 = &v67[v12];
          v81 = p_tmp12;
          if ( *(_WORD *)p_tmp12->ld12 >= 0x8000u )
          {
            *(_DWORD *)tmp12.ld12 = *(_DWORD *)p_tmp12->ld12;
            *(_DWORD *)&tmp12.ld12[4] = *(_DWORD *)&p_tmp12->ld12[4];
            v14 = &p_tmp12->ld12[8];
            p_tmp12 = &tmp12;
            *(_DWORD *)&tmp12.ld12[8] = *(_DWORD *)v14;
            --*(_DWORD *)&tmp12.ld12[2];
            v81 = &tmp12;
          }
          v79 = 0;
          memset(v91, 0, sizeof(v91));
          v71 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000;
          v15 = *(_WORD *)&p_tmp12->ld12[10] & 0x7FFF;
          v16 = v15 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
          if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
            || (*(_WORD *)&p_tmp12->ld12[10] & 0x7FFF) == 0x7FFF
            || v16 > 0xBFFDu )
          {
            *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000u) == 0
                                     ? 2147450880
                                     : -32768;
          }
          else
          {
            if ( v16 > 0x3FBFu )
            {
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
              {
                ++v16;
                if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
                  && *(_DWORD *)&ld12.ld12[4] == 0
                  && *(_DWORD *)ld12.ld12 == 0 )
                {
                  *(_WORD *)&ld12.ld12[10] = 0;
                  continue;
                }
              }
              if ( v15 != 0
                || (++v16, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&p_tmp12->ld12[4] != 0
                || *(_DWORD *)p_tmp12->ld12 != 0 )
              {
                v73 = 0;
                v17 = &v91[4];
                for ( i = 5; i > 0; --i )
                {
                  v75 = i;
                  v65 = &ld12.ld12[2 * v73];
                  v66 = &p_tmp12->ld12[8];
                  do
                  {
                    v18 = *((_DWORD *)v17 - 1);
                    v19 = *(unsigned __int16 *)v66 * *(unsigned __int16 *)v65;
                    v69 = 0;
                    v20 = v18 + v19;
                    if ( v18 + v19 < v18 || v20 < v19 )
                      v69 = 1;
                    *((_DWORD *)v17 - 1) = v20;
                    if ( v69 != 0 )
                      ++*v17;
                    v65 += 2;
                    v66 -= 2;
                    --v75;
                  }
                  while ( v75 > 0 );
                  p_tmp12 = v81;
                  ++v17;
                  ++v73;
                }
                v21 = v16 - 16382;
                if ( v21 <= 0 )
                  goto LABEL_172;
                do
                {
                  if ( *(int *)&v91[8] < 0 )
                    break;
                  v22 = *(_DWORD *)v91;
                  *(_DWORD *)v91 *= 2;
                  v23 = *(_DWORD *)&v91[4];
                  *(_DWORD *)&v91[4] = (v22 >> 31) | (2 * *(_DWORD *)&v91[4]);
                  --v21;
                  *(_DWORD *)&v91[8] = (v23 >> 31) | (2 * *(_DWORD *)&v91[8]);
                }
                while ( v21 > 0 );
                if ( v21 <= 0 )
                {
LABEL_172:
                  if ( --v21 < 0 )
                  {
                    v24 = (unsigned __int16)-v21;
                    v21 = 0;
                    do
                    {
                      if ( (v91[0] & 1) != 0 )
                        ++v79;
                      v25 = *(_DWORD *)&v91[8];
                      *(_DWORD *)&v91[8] >>= 1;
                      v26 = __SPAIR64__(v25, *(unsigned int *)&v91[4]) >> 1;
                      v27 = *(__int64 *)v91 >> 1;
                      --v24;
                      *(_DWORD *)&v91[4] = v26;
                      *(_DWORD *)v91 = v27;
                    }
                    while ( v24 != 0 );
                    if ( v79 != 0 )
                      *(_WORD *)v91 |= 1u;
                  }
                }
                if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
                {
                  if ( *(_DWORD *)&v91[2] == -1 )
                  {
                    *(_DWORD *)&v91[2] = 0;
                    if ( *(_DWORD *)&v91[6] == -1 )
                    {
                      *(_DWORD *)&v91[6] = 0;
                      if ( *(_WORD *)&v91[10] == 0xFFFF )
                      {
                        *(_WORD *)&v91[10] = 0x8000;
                        ++v21;
                      }
                      else
                      {
                        ++*(_WORD *)&v91[10];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v91[6];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v91[2];
                  }
                }
                if ( (unsigned __int16)v21 < 0x7FFFu )
                {
                  *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
                  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
                  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
                  *(_WORD *)&ld12.ld12[10] = v71 | v21;
                }
                else
                {
                  *(_DWORD *)&ld12.ld12[4] = 0;
                  *(_DWORD *)ld12.ld12 = 0;
                  *(_DWORD *)&ld12.ld12[8] = v71 == 0 ? 2147450880 : -32768;
                }
                continue;
              }
            }
            *(_DWORD *)&ld12.ld12[8] = 0;
          }
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
        }
      }
      while ( v9 != 0 );
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] < 0x3FFFu )
    goto LABEL_134;
  ++digcount;
  v76 = 0;
  memset(v91, 0, sizeof(v91));
  v70 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
  v28 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
  if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
    || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
    || v28 > 0xBFFDu )
  {
    *(_DWORD *)&ld12.ld12[4] = 0;
    v29 = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) == 0 ? 2147450880 : -32768;
    *(_DWORD *)ld12.ld12 = 0;
  }
  else
  {
    if ( v28 > 0x3FBFu )
    {
      v29 = 0;
      if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
      {
        ++v28;
        if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && *(_DWORD *)&ld12.ld12[4] == 0 && *(_DWORD *)ld12.ld12 == 0 )
        {
          *(_WORD *)&ld12.ld12[10] = 0;
          goto LABEL_134;
        }
      }
      if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
        || (++v28, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
        || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
        || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
      {
        v74 = 0;
        v30 = &v91[4];
        for ( j = 5; j > 0; --j )
        {
          v80 = j;
          v72 = &ld12_one_tenth.ld12[8];
          v31 = &ld12.ld12[2 * v74];
          do
          {
            v82 = 0;
            v32 = *(unsigned __int16 *)v31 * *(unsigned __int16 *)v72;
            v33 = *((_DWORD *)v30 - 1);
            v34 = v33 + v32;
            if ( v33 + v32 < v33 || v34 < v32 )
              v82 = 1;
            *((_DWORD *)v30 - 1) = v34;
            if ( v82 != 0 )
              ++*v30;
            v72 -= 2;
            v31 += 2;
            --v80;
          }
          while ( v80 > 0 );
          ++v30;
          ++v74;
        }
        v35 = v28 - 16382;
        if ( v35 <= 0 )
          goto LABEL_173;
        do
        {
          if ( *(int *)&v91[8] < 0 )
            break;
          v36 = *(_DWORD *)v91;
          *(_DWORD *)v91 *= 2;
          v37 = *(_DWORD *)&v91[4];
          *(_DWORD *)&v91[4] = (v36 >> 31) | (2 * *(_DWORD *)&v91[4]);
          --v35;
          *(_DWORD *)&v91[8] = (v37 >> 31) | (2 * *(_DWORD *)&v91[8]);
        }
        while ( v35 > 0 );
        if ( v35 <= 0 )
        {
LABEL_173:
          if ( --v35 < 0 )
          {
            v38 = (unsigned __int16)-v35;
            v35 = 0;
            do
            {
              if ( (v91[0] & 1) != 0 )
                ++v76;
              v39 = *(_DWORD *)&v91[8];
              *(_DWORD *)&v91[8] >>= 1;
              v40 = __SPAIR64__(v39, *(unsigned int *)&v91[4]) >> 1;
              v41 = *(__int64 *)v91 >> 1;
              --v38;
              *(_DWORD *)&v91[4] = v40;
              *(_DWORD *)v91 = v41;
            }
            while ( v38 != 0 );
            if ( v76 != 0 )
              *(_WORD *)v91 |= 1u;
          }
        }
        if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
        {
          if ( *(_DWORD *)&v91[2] == -1 )
          {
            *(_DWORD *)&v91[2] = 0;
            if ( *(_DWORD *)&v91[6] == -1 )
            {
              *(_DWORD *)&v91[6] = 0;
              if ( *(_WORD *)&v91[10] == 0xFFFF )
              {
                *(_WORD *)&v91[10] = 0x8000;
                ++v35;
              }
              else
              {
                ++*(_WORD *)&v91[10];
              }
            }
            else
            {
              ++*(_DWORD *)&v91[6];
            }
          }
          else
          {
            ++*(_DWORD *)&v91[2];
          }
        }
        if ( (unsigned __int16)v35 < 0x7FFFu )
        {
          *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
          *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
          *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
          *(_WORD *)&ld12.ld12[10] = v70 | v35;
        }
        else
        {
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v70 == 0 ? 2147450880 : -32768;
        }
        goto LABEL_134;
      }
    }
    else
    {
      v29 = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
  *(_DWORD *)&ld12.ld12[8] = v29;
LABEL_134:
  v42 = ndigits;
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    v42 = digcount + ndigits;
    if ( v42 <= 0 )
    {
      fos->exp = 0;
      *(_WORD *)&fos->ManLen = 12289;
      fos->sign = sign != -32768 ? 32 : 45;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v42 > 21 )
    v42 = 21;
  v43 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  v83 = 8;
  do
  {
    v44 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v45 = (v44 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v46 = *(__int64 *)&ld12.ld12[4] >> 31;
    v10 = v83-- == 1;
    *(_DWORD *)&ld12.ld12[4] = v45;
    *(_DWORD *)&ld12.ld12[8] = v46;
  }
  while ( !v10 );
  if ( v43 < 0 )
  {
    v47 = (unsigned __int8)-(char)v43;
    if ( v47 != 0 )
    {
      do
      {
        v48 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v49 = (v48 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v50 = *(__int64 *)ld12.ld12 >> 1;
        --v47;
        *(_DWORD *)&ld12.ld12[4] = v49;
        *(_DWORD *)ld12.ld12 = v50;
      }
      while ( v47 > 0 );
    }
  }
  man = fos->man;
  v87 = fos->man;
  for ( digcounta = v42 + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v52 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v53 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v54 = (v52 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v55 = 2 * v54;
    v56 = (v54 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v57 = (v53 >> 31) | v55;
    v58 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v58 < *(_DWORD *)tmp12.ld12 )
    {
      v59 = 0;
      if ( v57 + 1 < v57 || v57 == -1 )
        v59 = 1;
      ++v57;
      if ( v59 != 0 )
        ++v56;
    }
    v60 = *(_DWORD *)&tmp12.ld12[4] + v57;
    v84 = *(_DWORD *)&tmp12.ld12[4] + v57;
    if ( *(_DWORD *)&tmp12.ld12[4] + v57 < v57 || v60 < *(_DWORD *)&tmp12.ld12[4] )
      ++v56;
    *(_DWORD *)ld12.ld12 = 2 * v58;
    *(_DWORD *)&ld12.ld12[8] = (v60 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v56));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v58 >> 31) | (2 * v84);
  }
  v61 = *(man - 1);
  v62 = man - 2;
  if ( v61 >= 53 )
  {
    while ( v62 >= v87 && *v62 == 57 )
      *v62-- = 48;
    v63 = fos;
    if ( v62 < v87 )
    {
      ++v62;
      ++fos->exp;
    }
    ++*v62;
  }
  else
  {
    while ( v62 >= v87 && *v62 == 48 )
      --v62;
    v63 = fos;
    if ( v62 < v87 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != -32768 ? 32 : 45;
      *v87 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v64 = (_BYTE)v62 - (_BYTE)v63 - 3;
  v63->ManLen = v64;
  v63->man[v64] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EA968
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EA9F6
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EAA96
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= 0x1000000u;
        }
        else
        {
          v18 |= 0x3000000u;
        }
      }
      else
      {
        v18 |= 0x2000000u;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EADA8
// Name: ___crtCompareStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringW(
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2)
{
  int v6; // esi
  int v7; // eax

  v6 = cchCount1;
  if ( cchCount1 > 0 )
    v6 = wcsnlen(wcs: lpString1, maxsize: cchCount1);
  v7 = cchCount2;
  if ( cchCount2 > 0 )
    v7 = wcsnlen(wcs: lpString2, maxsize: cchCount2);
  if ( v6 != 0 && v7 != 0 )
    return CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1: v6, lpString2, cchCount2: v7);
  if ( v6 == v7 )
    return 2;
  return 2 * (v6 - v7 >= 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004EAE0B
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  int v5; // edi
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAEED
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EAF40
// Name: __mbsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnicmp_l(char *s1, char *s2, unsigned int n, localeinfo_struct *plocinfo)
{
  char *v4; // edi
  char *v5; // ebx
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  __int16 v9; // si
  char *v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  char *v14; // ecx
  int v15; // ecx
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  int c1; // [esp+10h] [ebp-4h]

  if ( n == 0 )
    return;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    _strnicmp(dst: s1, src: s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v4 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  while ( 1 )
  {
    v6 = (unsigned __int8)*v4;
    --n;
    ++v4;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v10 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v10[29] & 0x10) != 0 )
        v11 = (unsigned __int8)v10[285];
      else
        v11 = (unsigned __int16)c1;
      c1 = v11;
      goto LABEL_26;
    }
    if ( *v4 == 0 )
    {
      c1 = 0;
LABEL_26:
      v9 = c1;
      goto LABEL_27;
    }
    v8 = (unsigned __int16)((unsigned __int8)*v4 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v8;
    ++v4;
    c1 = v8;
    if ( (unsigned __int16)v8 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v8 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v8 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v8 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v8;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v8;
    }
LABEL_27:
    v12 = (unsigned __int8)*v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v12 + 1] & 4) == 0;
    c1 = v12;
    if ( v7 )
    {
      v14 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v14[29] & 0x10) != 0 )
        v15 = (unsigned __int8)v14[285];
      else
        v15 = (unsigned __int16)c1;
      c1 = v15;
      goto LABEL_40;
    }
    if ( *v5 == 0 )
    {
      c1 = 0;
LABEL_40:
      LOWORD(v13) = c1;
      goto LABEL_41;
    }
    v13 = (unsigned __int16)((unsigned __int8)*v5++ | (unsigned __int16)((_WORD)v12 << 8));
    c1 = v13;
    if ( (unsigned __int16)v13 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v13 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v13 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v13 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v13) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v13;
      }
    }
    else
    {
      LOWORD(v13) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v13;
    }
LABEL_41:
    if ( (_WORD)v13 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x004EB10B
// Name: __mbsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnicmp(char *s1, char *s2, unsigned int n)
{
  _mbsnicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004EB125
// Name: __filwbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _filwbuf(_iobuf *str)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  unsigned int v4; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0xFFFF;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return 0xFFFF;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return 0xFFFF;
  }
  v2 = flag | 1;
  str->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v3 = _fileno(stream: str);
  v4 = _read(fh: v3, buf: base, cnt: bufsiz);
  str->_cnt = v4;
  if ( v4 < 2 || v4 == -1 )
  {
    str->_flag |= v4 != 0 ? 32 : 16;
    str->_cnt = 0;
    return 0xFFFF;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(stream: str) == -1 || _fileno(stream: str) == -2 )
    {
      v6 = &__badioinfo;
    }
    else
    {
      v5 = &__pioinfo[_fileno(stream: str) >> 5];
      v6 = &(*v5)[_fileno(stream: str) & 0x1F];
    }
    if ( (v6->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v7 = str->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  str->_cnt -= 2;
  result = *(unsigned __int16 *)ptr;
  str->_ptr = ptr + 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EB255
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EB274
// Name: ___termconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconout()
{
  HANDLE result; // eax

  result = _confh;
  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _confh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EB28B
// Name: __flswbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flswbuf(unsigned __int16 ch, _iobuf *str)
{
  int flag; // eax
  int v5; // eax
  unsigned int v6; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v9; // edi
  ioinfo *v10; // eax
  __int64 v11; // rax
  unsigned __int16 v12; // bx
  char mbc[4]; // [esp+4h] [ebp-4h] BYREF
  int fh; // [esp+14h] [ebp+Ch]

  fh = _fileno(stream: str);
  flag = str->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    str->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      str->_flag = flag | 0x20;
      return 0xFFFF;
    }
    str->_ptr = str->_base;
    str->_flag = flag & 0xFFFFFFFE;
  }
  v5 = str->_flag;
  str->_cnt = 0;
  *(_DWORD *)mbc = 0;
  v6 = v5 & 0xFFFFFFED | 2;
  str->_flag = v6;
  if ( (v6 & 0x10C) == 0 && (str != &__iob_func()[1] && str != &__iob_func()[2] || _isatty(fh) == 0) )
    _getbuf(str);
  if ( (str->_flag & 0x108) != 0 )
  {
    base = str->_base;
    ptr = str->_ptr;
    str->_ptr = base + 2;
    v9 = ptr - base;
    str->_cnt = str->_bufsiz - 2;
    if ( v9 <= 0 )
    {
      if ( fh == -1 || fh == -2 )
        v10 = &__badioinfo;
      else
        v10 = &__pioinfo[fh >> 5][fh & 0x1F];
      if ( (v10->osfile & 0x20) != 0 )
      {
        v11 = _lseeki64(fh, pos: 0, mthd: 2);
        if ( (HIDWORD(v11) & (unsigned int)v11) == 0xFFFFFFFF )
          goto LABEL_28;
      }
    }
    else
    {
      *(_DWORD *)mbc = _write(fh, buf: base, cnt: v9);
    }
    v12 = ch;
    *(_WORD *)str->_base = ch;
  }
  else
  {
    v9 = 2;
    v12 = ch;
    *(_WORD *)mbc = ch;
    *(_DWORD *)mbc = _write(fh, buf: mbc, cnt: 2u);
  }
  if ( *(_DWORD *)mbc != v9 )
  {
LABEL_28:
    str->_flag |= 0x20u;
    return 0xFFFF;
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x004EB400
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EB462
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x004EB470
// Name: _dynamic_initializer_for__g_FacePoserSound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FacePoserSound__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FacePoserSound__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB480
// Name: _dynamic_initializer_for__JiggleBoneDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__JiggleBoneDebug__()
{
  ConVar::ConVar(
    this: &JiggleBoneDebug,
    pName: "cl_jiggle_bone_debug",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Display physics-based 'jiggle bone' debugging information");
  return atexit(func: dynamic_atexit_destructor_for__JiggleBoneDebug__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB4B0
// Name: _dynamic_initializer_for__JiggleBoneDebugYawConstraints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__JiggleBoneDebugYawConstraints__()
{
  ConVar::ConVar(
    this: &JiggleBoneDebugYawConstraints,
    pName: "cl_jiggle_bone_debug_yaw_constraints",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Display physics-based 'jiggle bone' debugging information");
  return atexit(func: dynamic_atexit_destructor_for__JiggleBoneDebugYawConstraints__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB4E0
// Name: _dynamic_initializer_for__JiggleBoneDebugPitchConstraints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__JiggleBoneDebugPitchConstraints__()
{
  ConVar::ConVar(
    this: &JiggleBoneDebugPitchConstraints,
    pName: "cl_jiggle_bone_debug_pitch_constraints",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Display physics-based 'jiggle bone' debugging information");
  return atexit(func: dynamic_atexit_destructor_for__JiggleBoneDebugPitchConstraints__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB510
// Name: _dynamic_initializer_for__JiggleBoneInvert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__JiggleBoneInvert__()
{
  ConVar::ConVar(this: &JiggleBoneInvert, pName: "cl_jiggle_bone_invert", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__JiggleBoneInvert__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB540
// Name: _dynamic_initializer_for__JiggleBoneSanity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__JiggleBoneSanity__()
{
  ConVar::ConVar(
    this: &JiggleBoneSanity,
    pName: "cl_jiggle_bone_sanity",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Prevent jiggle bones from pointing directly away from their target in case of numerical instability.");
  return atexit(func: dynamic_atexit_destructor_for__JiggleBoneSanity__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB570
// Name: _dynamic_initializer_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_definevariable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_definevariable__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB580
// Name: _dynamic_initializer_for__g_SoundCombiner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundCombiner__()
{
  CSentence::CSentence(this: &g_SoundCombiner.m_Combined);
  g_SoundCombiner.m_pWaveOutput = nullptr;
  g_SoundCombiner.m_pOutRIFF = nullptr;
  g_SoundCombiner.m_pOutIterator = nullptr;
  g_SoundCombiner.m_szOutFile[0] = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_SoundCombiner__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB5B0
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB5E0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB610
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB630
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB680
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB690
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EB6A0
// Name: _dynamic_initializer_for__g_DrawModelResults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DrawModelResults__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DrawModelResults__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB6B0
// Name: _dynamic_initializer_for__g_studioModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_studioModel__()
{
  StudioModel::StudioModel(this: &g_studioModel);
  return atexit(func: dynamic_atexit_destructor_for__g_studioModel__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB6D0
// Name: _dynamic_initializer_for__g_viewerSettings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_viewerSettings__()
{
  _V_memset(dest: &g_viewerSettings, fill: 0, count: 3364);
}

//------------------------------------------------------------------------------
// Address: 0x004EB6F0
// Name: _dynamic_initializer_for__g_Params__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Params__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Params__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB700
// Name: _dynamic_initializer_for__g_MapEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MapEntities__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MapEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB710
// Name: _dynamic_initializer_for__g_EventPropertiesSpeakDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EventPropertiesSpeakDialog__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_EventPropertiesSpeakDialog.m_Symbols,
    growSize: 0,
    initSize: 16,
    caseInsensitive: false);
  g_EventPropertiesSpeakDialog.m_bShowAll = false;
  g_EventPropertiesSpeakDialog.m_szLastFilter[0] = 0;
  g_EventPropertiesSpeakDialog.m_Timer = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_EventPropertiesSpeakDialog__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB750
// Name: _dynamic_initializer_for__g_GlobalFlexControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GlobalFlexControllers__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GlobalFlexControllers__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB760
// Name: _dynamic_initializer_for__g_GlobalFlexControllerLookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GlobalFlexControllerLookup__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GlobalFlexControllerLookup__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB770
// Name: _dynamic_initializer_for__g_ExpressionManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionManager__()
{
  CExpression::CExpression(this: &g_ExpressionManager.m_CopyBuffer);
  g_ExpressionManager.m_pActiveClass = nullptr;
  CExpressionManager::Reset(this: &g_ExpressionManager);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionManager__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB7A0
// Name: _dynamic_initializer_for__g_ModelManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ModelManager__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB7B0
// Name: _dynamic_initializer_for__g_Tools__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Tools__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Tools__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB7C0
// Name: _dynamic_initializer_for__s_NeedRedraw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_NeedRedraw__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_NeedRedraw__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB7D0
// Name: _dynamic_initializer_for__g_WorkspaceFiles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WorkspaceFiles__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WorkspaceFiles__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB7E0
// Name: _dynamic_initializer_for__g_WaveLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WaveLoader__()
{
  CFileLoaderThread::CFileLoaderThread(this: &g_WaveLoader);
  return atexit(func: dynamic_atexit_destructor_for__g_WaveLoader__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB800
// Name: _dynamic_initializer_for__g_Random__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUniformRandomStream *dynamic_initializer_for__g_Random__()
{
  return CUniformRandomStream::CUniformRandomStream(this: &g_Random);
}

//------------------------------------------------------------------------------
// Address: 0x004EB810
// Name: _dynamic_initializer_for__g_Extractors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Extractors__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Extractors__);
}

//------------------------------------------------------------------------------
// Address: 0x004EB820
// Name: _dynamic_initializer_for__g_ProgressDialog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ProgressDialog__()
{
  CUtlString::CUtlString(this: &g_ProgressDialog.m_sTitle);
  CUtlString::CUtlString(this: &g_ProgressDialog.m_sStatus);
  g_ProgressDialog.m_flFraction = 0.0;
  *(_WORD *)&g_ProgressDialog.m_bShowCancel = 0;
  g_ProgressDialog.m_hwndDlg = nullptr;
  g_ProgressDialog.m_flStartTime = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_ProgressDialog__);
}

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00406510
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbol,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbol,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbol,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbol,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                        this: _g_pMemAlloc,
                                                                        a2: m_pMemory,
                                                                        a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbol,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406AB0
// Name: public: void CUtlMemory<class CUtlSymbol,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbol,int>::Grow(CUtlMemory<CUtlSymbol,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbol *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlSymbol *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B40
// Name: public: void CUtlMemory<struct CombinerEntry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CombinerEntry,int>::Grow(CUtlMemory<CombinerEntry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CombinerEntry *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CombinerEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CombinerEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406BE0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<int,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<int,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CChoreoEvent *,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CChoreoEvent *,int> *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CChoreoEvent *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C80
// Name: public: void CUtlMemory<struct OrderedCaption_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OrderedCaption_t,int>::Grow(CUtlMemory<OrderedCaption_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  OrderedCaption_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OrderedCaption_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (OrderedCaption_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407400
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::Find(class CUtlSymbol const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::Find(
        CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *this,
        const CUtlSymbol *src)
{
  int m_Size; // edx
  int result; // eax
  CUtlSymbol *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; i->m_Id != src->m_Id; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C060
// Name: public: int CUtlVector<struct Extractor,class CUtlMemory<struct Extractor,int>>::InsertBefore(int,struct Extractor const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Extractor,CUtlMemory<Extractor,int>>::InsertBefore(
        CUtlVector<Extractor,CUtlMemory<Extractor,int> > *this,
        int elem,
        const Extractor *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Extractor *m_pMemory; // ecx
  int v7; // eax
  Extractor *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(
      (CUtlMemory<CAppSystemGroup::Module_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040C0E0
// Name: public: int CUtlVector<struct OrderedCaption_t,class CUtlMemory<struct OrderedCaption_t,int>>::InsertBefore(int,struct OrderedCaption_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<OrderedCaption_t,CUtlMemory<OrderedCaption_t,int>>::InsertBefore(
        CUtlVector<OrderedCaption_t,CUtlMemory<OrderedCaption_t,int> > *this,
        int elem,
        const OrderedCaption_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  OrderedCaption_t *m_pMemory; // ecx
  int v7; // eax
  OrderedCaption_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<OrderedCaption_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    OrderedCaption_t::OrderedCaption_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00416BC0
// Name: public: void CUtlMemory<struct variable_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<variable_t,int>::Grow(CUtlMemory<variable_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  variable_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (variable_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (variable_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416D90
// Name: public: int CUtlVector<struct variable_t,class CUtlMemory<struct variable_t,int>>::InsertBefore(int,struct variable_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
        CUtlVector<variable_t,CUtlMemory<variable_t,int> > *this,
        int elem,
        const variable_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  variable_t *m_pMemory; // ecx
  int v7; // eax
  variable_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<variable_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00416E00
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<OrderedCaption_t,int>::Grow(
      (CUtlMemory<OrderedCaption_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417330
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  fileList_t *m_pMemory; // ecx
  int v6; // eax
  fileList_t *v7; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlSymbol,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<CEventRelativeTag,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    CUtlString::CUtlString(this: &v7->fileName);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004173A0
// Name: public: int CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  fileList_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fileList_t *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlSymbol,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<CEventRelativeTag,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlString::CUtlString(this: &v12->fileName);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00417440
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004174B0
// Name: public: void CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventRelativeTag *v3; // esi
  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417780
// Name: public: CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::~CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this)
{
  bool v2; // sf
  CEventRelativeTag *m_pMemory; // eax

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004198E0
// Name: private: bool CSoundCombiner::InitSplicer(class IFileSystem __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::InitSplicer(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        int samplerate,
        int numchannels,
        int bitspersample)
{
  CAudioWaveOutput *v6; // eax
  OutFileRIFF *v8; // eax
  OutFileRIFF *v9; // eax
  IterateOutputRIFF *v10; // eax
  IterateOutputRIFF *v11; // eax
  int v12; // edx
  unsigned int m_nSampleRate; // ecx
  char basepath[512]; // [esp+4h] [ebp-214h] BYREF
  tWAVEFORMATEX format; // [esp+204h] [ebp-14h] BYREF

  this->m_nSampleRate = samplerate;
  this->m_nBitsPerSample = bitspersample;
  this->m_nBytesPerSample = bitspersample >> 3;
  this->m_nNumChannels = numchannels;
  v6 = (CAudioWaveOutput *)sound->GetAudioOutput(this: sound);
  this->m_pWaveOutput = v6;
  if ( v6 != nullptr )
  {
    V_ExtractFilePath(path: this->m_szOutFile, dest: basepath, destSize: 512);
    filesystem->CreateDirHierarchy(this: filesystem, a2: basepath, a3: "GAME");
    v8 = (OutFileRIFF *)operator new(nSize: 0x1Cu);
    if ( v8 != nullptr )
      v9 = OutFileRIFF::OutFileRIFF(this: v8, pFileName: this->m_szOutFile, io: &io_out_0);
    else
      v9 = nullptr;
    this->m_pOutRIFF = v9;
    if ( v9 != nullptr )
    {
      v10 = (IterateOutputRIFF *)operator new(nSize: 0x1Cu);
      if ( v10 != nullptr )
        v11 = IterateOutputRIFF::IterateOutputRIFF(this: v10, riff: this->m_pOutRIFF);
      else
        v11 = nullptr;
      this->m_pOutIterator = v11;
      if ( v11 != nullptr )
      {
        format.cbSize = 18;
        v12 = this->m_nNumChannels * this->m_nBytesPerSample;
        format.wFormatTag = 1;
        m_nSampleRate = this->m_nSampleRate;
        format.nAvgBytesPerSec = m_nSampleRate * v12;
        format.nChannels = this->m_nNumChannels;
        format.wBitsPerSample = this->m_nBitsPerSample;
        format.nSamplesPerSec = m_nSampleRate;
        format.nBlockAlign = 1;
        IterateOutputRIFF::ChunkWrite(this: v11, chunkname: 0x20746D66u, pOutput: &format, size: 18);
        return 1;
      }
      else
      {
        _Warning(a1: "CSoundCombiner::InitSplicer  m_pOutIterator == NULL\n");
        return 0;
      }
    }
    else
    {
      _Warning(a1: "CSoundCombiner::InitSplicer  m_pOutRIFF == NULL\n");
      return 0;
    }
  }
  else
  {
    _Warning(a1: "CSoundCombiner::InitSplicer  m_pWaveOutput == NULL\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419A40
// Name: private: bool CSoundCombiner::AppendWaveData(int __near &,class CAudioSource __near *,class CAudioMixer __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSoundCombiner::AppendWaveData@<al>(
        CSoundCombiner *this@<ecx>,
        int a2@<edi>,
        int *currentsample,
        CAudioSource *wave,
        CAudioMixer *mixer)
{
  CAudioWaveOutput *m_pWaveOutput; // ecx
  CAudioMixer *v7; // ebx
  CAudioMixer_vtbl *v8; // edi
  int v9; // eax
  int m_nNumChannels; // eax
  int v11; // eax
  float v12; // xmm0_4
  __int16 *v13; // ecx
  int m_nBytesPerSample; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  IterateOutputRIFF *m_pOutIterator; // ecx
  CAudioMixer_vtbl *v19; // edi
  int v20; // eax
  int v23; // [esp-4h] [ebp-28h]
  channel_s channel; // [esp+8h] [ebp-1Ch] BYREF
  __int16 samples[3]; // [esp+1Ch] [ebp-8h] BYREF
  char v26; // [esp+23h] [ebp-1h] BYREF

  m_pWaveOutput = this->m_pWaveOutput;
  *(_QWORD *)&channel.rleftvol = 0;
  channel.leftvol = 255;
  channel.rightvol = 255;
  channel.pitch = 1.0;
  m_pWaveOutput->m_audioDevice.MixBegin(this: &m_pWaveOutput->m_audioDevice);
  v7 = mixer;
  v8 = mixer->__vftable;
  v9 = ((int (__thiscall *)(CAudioSource *, int))wave->SampleRate)(a1: wave, a2: 1);
  if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, _DWORD, int, int))v8->MixDataToDevice)(
         a1: v7,
         a2: &this->m_pWaveOutput->m_audioDevice,
         a3: &channel,
         a4: *currentsample,
         a5: 1,
         a6: v9) != 0 )
  {
    while ( 1 )
    {
      CAudioDeviceSWMix::TransferBufferStereo16(
        this: &this->m_pWaveOutput->m_audioDevice,
        pOutput: samples,
        sampleCount: 1);
      *currentsample = ((int (__thiscall *)(CAudioMixer *, int))v7->GetSamplePosition)(a1: v7, a2);
      m_nNumChannels = this->m_nNumChannels;
      if ( m_nNumChannels == 1 )
        break;
      if ( m_nNumChannels == 2 )
      {
        m_nBytesPerSample = this->m_nBytesPerSample;
        if ( m_nBytesPerSample == 1 )
        {
          v15 = -127.0;
          v16 = (float)(samples[0] >> 8);
          v17 = (float)(samples[1] >> 8);
          if ( v16 >= -127.0 )
          {
            if ( v16 > 127.0 )
              v16 = 127.0;
          }
          else
          {
            v16 = -127.0;
          }
          if ( v17 >= -127.0 )
          {
            if ( v17 <= 127.0 )
              v15 = (float)(samples[1] >> 8);
            else
              v15 = 127.0;
          }
          m_pOutIterator = this->m_pOutIterator;
          HIBYTE(mixer) = (int)(float)(v16 + 127.0);
          v26 = (int)(float)(v15 + 127.0);
          IterateOutputRIFF::ChunkWriteData(this: m_pOutIterator, pOutput: (char *)&mixer + 3, size: 1);
          IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &v26, size: 1);
          goto LABEL_25;
        }
        if ( m_nBytesPerSample == 2 )
        {
          IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: samples, size: 2);
          v23 = 2;
          v13 = &samples[1];
LABEL_24:
          IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: v13, size: v23);
        }
      }
LABEL_25:
      this->m_pWaveOutput->m_audioDevice.MixBegin(this: &this->m_pWaveOutput->m_audioDevice);
      v19 = v7->__vftable;
      a2 = 1;
      v20 = wave->SampleRate(this: wave);
      if ( ((unsigned __int8 (__thiscall *)(CAudioMixer *, CAudioDeviceSWMix *, channel_s *, _DWORD, int, int))v19->MixDataToDevice)(
             a1: v7,
             a2: &this->m_pWaveOutput->m_audioDevice,
             a3: &channel,
             a4: *currentsample,
             a5: 1,
             a6: v20) == 0 )
        return 1;
    }
    v11 = this->m_nBytesPerSample;
    if ( v11 != 1 )
    {
      if ( v11 == 2 )
      {
        mixer = (CAudioMixer *)(unsigned __int16)(int)(float)((float)((float)samples[0] + (float)samples[1]) * 0.5);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &mixer, size: 2);
      }
      goto LABEL_25;
    }
    v12 = (float)((float)(samples[0] >> 8) + (float)(samples[1] >> 8)) * 0.5;
    if ( v12 >= -127.0 )
    {
      if ( v12 > 127.0 )
        v12 = 127.0;
    }
    else
    {
      v12 = -127.0;
    }
    HIBYTE(mixer) = (int)(float)(v12 + 127.0);
    v23 = 1;
    v13 = (__int16 *)((char *)&mixer + 3);
    goto LABEL_24;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419CB0
// Name: private: unsigned int CSoundCombiner::ComputeChecksum(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSoundCombiner::ComputeChecksum(CSoundCombiner *this)
{
  int v2; // edi
  CSoundCombiner::CombinerWork *v3; // esi
  int v4; // eax
  int c; // [esp+8h] [ebp-Ch]
  unsigned int chk; // [esp+Ch] [ebp-8h] BYREF
  unsigned int crc; // [esp+10h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: &crc);
  v2 = 0;
  c = this->m_Work.m_Size;
  if ( c > 0 )
  {
    do
    {
      v3 = this->m_Work.m_Memory.m_pMemory[v2];
      chk = CSentence::ComputeDataCheckSum(this: &v3->sentence);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &chk, nBuffer: 4);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &v3->entry->startoffset, nBuffer: 4);
      v4 = _V_strlen(str: v3->entry->wavefile);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: v3->entry, nBuffer: v4);
      ++v2;
    }
    while ( v2 < c );
  }
  CRC32_Final(pulCRC: &crc);
  return crc;
}

//------------------------------------------------------------------------------
// Address: 0x00419D40
// Name: private: bool CSoundCombiner::VerifyFilesExist(class IFileSystem __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::VerifyFilesExist(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  int v3; // edi
  CombinerEntry *v4; // esi
  int c; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = 0;
  c = info->m_Size;
  i = 0;
  if ( c <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = &info->m_Memory.m_pMemory[v3];
    if ( !filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: (const char *)v4, a3: nullptr) )
      break;
    ++v3;
    if ( ++i >= c )
      return 1;
  }
  _Warning(a1: "CSoundCombiner::VerifyFilesExist: missing file %s\n", v4->wavefile);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419DB0
// Name: private: bool CSoundCombiner::LoadSpliceAudioSources(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::LoadSpliceAudioSources(CSoundCombiner *this)
{
  int v1; // ebx
  CSoundCombiner::CombinerWork *v3; // edi
  CAudioSource *v4; // esi
  int v5; // eax
  int c; // [esp+Ch] [ebp-8h]
  CSoundCombiner *v7; // [esp+10h] [ebp-4h]

  v1 = 0;
  v7 = this;
  c = this->m_Work.m_Size;
  if ( c <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = this->m_Work.m_Memory.m_pMemory[v1];
    v4 = sound->LoadSound(this: sound, a2: v3->entry);
    if ( v4 == nullptr )
    {
      _Warning(a1: "CSoundCombiner::LoadSpliceAudioSources  LoadSound failed '%s'\n", v3->entry->wavefile);
      return 0;
    }
    v5 = (int)v4->CreateMixer(this: v4);
    if ( v5 == 0 )
      break;
    v3->wave = v4;
    v3->mixer = (CAudioMixer *)v5;
    v3->duration = v4->GetRunningLength(this: v4);
    if ( ++v1 >= c )
      return 1;
    this = v7;
  }
  _Warning(a1: "CSoundCombiner::LoadSpliceAudioSources  CreateMixer failed '%s'\n", v3->entry->wavefile);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419E60
// Name: private: bool CSoundCombiner::AppendSilence(int __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::AppendSilence(CSoundCombiner *this, int *currentsample, float duration)
{
  int v4; // ebx
  int i; // edi
  int m_nNumChannels; // ecx
  __int16 v7; // ax
  int m_nBytesPerSample; // ecx
  float v9; // xmm0_4
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  IterateOutputRIFF *m_pOutIterator; // ecx
  __int16 samples[3]; // [esp+8h] [ebp-8h] BYREF
  char v16; // [esp+Fh] [ebp-1h] BYREF

  v4 = (int)(float)((float)this->m_nSampleRate * duration) - 1;
  for ( i = 0x7FFF; v4 >= 0; --v4 )
  {
    i += random->RandomInt(this: random, a2: -20, a3: 20);
    if ( i <= 32842 )
    {
      if ( i < 32692 )
        i = 32692;
    }
    else
    {
      i = 32842;
    }
    m_nNumChannels = this->m_nNumChannels;
    v7 = (int)(float)((float)i * 0.000030517578);
    samples[0] = v7;
    samples[1] = v7;
    if ( m_nNumChannels == 1 )
    {
      m_nBytesPerSample = this->m_nBytesPerSample;
      if ( m_nBytesPerSample == 1 )
      {
        v9 = (float)((float)(v7 >> 8) * 2.0) * 0.5;
        if ( v9 >= -127.0 )
        {
          if ( v9 > 127.0 )
            v9 = 127.0;
        }
        else
        {
          v9 = -127.0;
        }
        HIBYTE(duration) = (int)(float)(v9 + 127.0);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: (char *)&duration + 3, size: 1);
      }
      else if ( m_nBytesPerSample == 2 )
      {
        LODWORD(duration) = (unsigned __int16)(int)(float)((float)((float)v7 * 2.0) * 0.5);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &duration, size: 2);
      }
    }
    else if ( m_nNumChannels == 2 )
    {
      v10 = this->m_nBytesPerSample;
      if ( v10 == 1 )
      {
        v11 = (float)(v7 >> 8);
        v12 = v11;
        if ( v11 >= -127.0 )
        {
          if ( v11 > 127.0 )
            v12 = 127.0;
        }
        else
        {
          v12 = -127.0;
        }
        if ( v11 >= -127.0 )
        {
          if ( v11 > 127.0 )
            v11 = 127.0;
        }
        else
        {
          v11 = -127.0;
        }
        v16 = (int)(float)(v11 + 127.0);
        m_pOutIterator = this->m_pOutIterator;
        HIBYTE(duration) = (int)(float)(v12 + 127.0);
        IterateOutputRIFF::ChunkWriteData(this: m_pOutIterator, pOutput: (char *)&duration + 3, size: 1);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &v16, size: 1);
      }
      else if ( v10 == 2 )
      {
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: samples, size: 2);
        IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: &samples[1], size: 2);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A040
// Name: private: int CSoundCombiner::ComputeBestNumChannels(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundCombiner::ComputeBestNumChannels(CSoundCombiner *this)
{
  int m_Size; // ebx
  int v3; // esi
  CAudioSource *wave; // ecx

  m_Size = this->m_Work.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    wave = this->m_Work.m_Memory.m_pMemory[v3]->wave;
    if ( wave->GetNumChannels(this: wave) == 2 )
      break;
    if ( ++v3 >= m_Size )
      return 1;
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0041A080
// Name: private: void CSoundCombiner::CleanupWork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundCombiner::CleanupWork(CSoundCombiner *this)
{
  int v2; // edi
  CSoundCombiner::CombinerWork *v3; // ebx
  CAudioMixer *mixer; // ecx
  CAudioSource *wave; // ebx
  CSoundCombiner::CombinerWork **m_pMemory; // ecx
  CSoundCombiner::CombinerWork *v7; // ebx
  OutFileRIFF *m_pOutRIFF; // ebx
  int c; // [esp+Ch] [ebp-4h]

  v2 = 0;
  c = this->m_Work.m_Size;
  if ( c > 0 )
  {
    do
    {
      v3 = this->m_Work.m_Memory.m_pMemory[v2];
      mixer = v3->mixer;
      if ( mixer != nullptr )
        ((void (__thiscall *)(CAudioMixer *, int))mixer->dtr_CAudioMixer)(a1: mixer, a2: 1);
      wave = v3->wave;
      if ( wave != nullptr )
        ((void (__thiscall *)(CAudioSource *, int))wave->dtr_CAudioSource)(a1: wave, a2: 1);
      m_pMemory = this->m_Work.m_Memory.m_pMemory;
      v7 = m_pMemory[v2];
      if ( v7 != nullptr )
      {
        CSentence::~CSentence(this: &m_pMemory[v2]->sentence);
        free(pMem: v7);
      }
      ++v2;
    }
    while ( v2 < c );
  }
  this->m_Work.m_Size = 0;
  free(pMem: this->m_pOutIterator);
  m_pOutRIFF = this->m_pOutRIFF;
  this->m_pOutIterator = nullptr;
  if ( m_pOutRIFF != nullptr )
  {
    OutFileRIFF::~OutFileRIFF(this: m_pOutRIFF);
    free(pMem: m_pOutRIFF);
  }
  this->m_pOutRIFF = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041A110
// Name: private: bool CSoundCombiner::PerformSplicingOnWorkItems(class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::PerformSplicingOnWorkItems(CSoundCombiner *this, IFileSystem *filesystem)
{
  int v4; // eax
  int m_Size; // ecx
  int v6; // ebx
  CSoundCombiner::CombinerWork **m_pMemory; // edx
  int v8; // edi
  float v9; // xmm0_4
  unsigned int v10; // eax
  CAudioSource *starttime; // [esp+0h] [ebp-58h]
  CAudioMixer *v12; // [esp+4h] [ebp-54h]
  CUtlBuffer buf; // [esp+14h] [ebp-44h] BYREF
  float silence_time; // [esp+44h] [ebp-14h]
  float duration; // [esp+48h] [ebp-10h]
  int c; // [esp+4Ch] [ebp-Ch]
  int currentsample; // [esp+50h] [ebp-8h] BYREF
  CSoundCombiner::CombinerWork *nextitem; // [esp+54h] [ebp-4h]
  float timeoffset; // [esp+60h] [ebp+8h]

  if ( CSoundCombiner::LoadSpliceAudioSources(this) == 0 )
    return 0;
  v4 = CSoundCombiner::ComputeBestNumChannels(this);
  if ( CSoundCombiner::InitSplicer(this, filesystem, samplerate: 44100, numchannels: v4, bitspersample: 16) == 0 )
    return 0;
  IterateOutputRIFF::ChunkStart(this: this->m_pOutIterator, chunkname: 0x61746164u);
  timeoffset = 0.0;
  CSentence::Reset(this: &this->m_Combined);
  CSentence::SetText(this: &this->m_Combined, text: setName);
  m_Size = this->m_Work.m_Size;
  v6 = 0;
  c = m_Size;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_Work.m_Memory.m_pMemory;
      v8 = (int)m_pMemory[v6];
      currentsample = 0;
      nextitem = nullptr;
      if ( v6 != m_Size - 1 )
        nextitem = m_pMemory[v6 + 1];
      v12 = *(CAudioMixer **)(v8 + 84);
      starttime = *(CAudioSource **)(v8 + 80);
      duration = *(float *)(v8 + 76);
      CSoundCombiner::AppendWaveData(this, a2: v8, &currentsample, wave: starttime, mixer: v12);
      CSentence::Append(this: &this->m_Combined, starttime: timeoffset, src: (const CSentence *)v8);
      v9 = duration + timeoffset;
      timeoffset = duration + timeoffset;
      if ( nextitem != nullptr )
      {
        silence_time = nextitem->entry->startoffset - v9;
        CSoundCombiner::AppendSilence(this, &currentsample, duration: silence_time);
        timeoffset = silence_time + timeoffset;
      }
      if ( ++v6 >= c )
        break;
      m_Size = c;
    }
  }
  IterateOutputRIFF::ChunkFinish(this: this->m_pOutIterator);
  v10 = CSoundCombiner::ComputeChecksum(this);
  CSentence::SetDataCheckSum(this: &this->m_Combined, chk: v10);
  IterateOutputRIFF::ChunkStart(this: this->m_pOutIterator, chunkname: 0x54414456u);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CSentence::SaveToBuffer(this: &this->m_Combined, &buf);
  IterateOutputRIFF::ChunkWriteData(this: this->m_pOutIterator, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  IterateOutputRIFF::ChunkFinish(this: this->m_pOutIterator);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A2C0
// Name: private: bool CSoundCombiner::LoadSentenceFromWavFileUsingIO(char const __near *,class CSentence __near &,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::LoadSentenceFromWavFileUsingIO(
        CSoundCombiner *this,
        const char *wavfile,
        CSentence *sentence,
        IFileReadBinary *io)
{
  char v5; // bl
  int NumEvents; // eax
  int v7; // eax
  CUtlBuffer v8; // [esp+4h] [ebp-58h] BYREF
  IterateRIFF walk; // [esp+34h] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+4Ch] [ebp-10h] BYREF

  CSentence::Reset(this: sentence);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: wavfile, io);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v5 = 0;
    while ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      if ( v5 != 0 )
        break;
      if ( CAudioSourceMemWave::GetNumChannels(this: &walk) == 1413563478 )
      {
        v5 = 1;
        CUtlBuffer::CUtlBuffer(this: &v8, growSize: 0, initSize: 0, nFlags: 1);
        NumEvents = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::EnsureCapacity(this: &v8, num: NumEvents);
        IterateRIFF::ChunkRead(this: &walk, pOutput: v8.m_Memory.m_pMemory);
        v7 = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::SeekPut(this: &v8, type: SEEK_HEAD, offset: v7);
        CSentence::InitFromDataChunk(this: sentence, data: v8.m_Memory.m_pMemory, size: v8.m_Put);
        if ( v8.m_Memory.m_nGrowSize >= 0 && v8.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8.m_Memory.m_pMemory);
      }
      IterateRIFF::ChunkNext(this: &walk);
    }
    InFileRIFF::~InFileRIFF(this: &riff);
    return 1;
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A410
// Name: private: bool CSoundCombiner::CreateWorkList(class IFileSystem __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::CreateWorkList(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  CSentence *v3; // ebx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Work; // esi
  int m_Size; // eax
  CSentence *v6; // eax
  CSentence *v7; // edi
  unsigned int v8; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v11; // ecx
  int v12; // eax
  CSentence **v13; // edi
  char fullpath[260]; // [esp+Ch] [ebp-114h] BYREF
  int c; // [esp+110h] [ebp-10h]
  CSoundCombiner *v17; // [esp+114h] [ebp-Ch]
  int i; // [esp+118h] [ebp-8h]
  unsigned int v19; // [esp+11Ch] [ebp-4h]

  v3 = nullptr;
  p_m_Work = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Work;
  this->m_Work.m_Size = 0;
  m_Size = info->m_Size;
  v17 = this;
  c = m_Size;
  i = 0;
  if ( m_Size <= 0 )
    return 1;
  v19 = 0;
  while ( 1 )
  {
    v6 = (CSentence *)operator new(nSize: 0x5Cu);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CSentence::CSentence(this: v6);
      v7[1].m_Words.m_Memory.m_pMemory = nullptr;
      v7[1].m_Words.m_Memory.m_nAllocationCount = 0;
      v7[1].m_Words.m_Memory.m_nGrowSize = 0;
      v7[1].m_szText = nullptr;
      v3 = v7;
    }
    v8 = v19;
    V_strncpy(pDest: fullpath, pSrc: info->m_Memory.m_pMemory[v19 / 0x108].wavefile, maxLen: 260);
    filesystem->GetLocalPath(this: filesystem, a2: &info->m_Memory.m_pMemory->wavefile[v8], a3: fullpath, a4: 260);
    if ( CSoundCombiner::LoadSentenceFromWavFileUsingIO(this: v17, wavfile: fullpath, sentence: v3, io: &io_in_0) == 0 )
      break;
    v3[1].m_Words.m_Memory.m_nGrowSize = (int)&info->m_Memory.m_pMemory->wavefile[v8];
    m_pMemory = p_m_Work[1].m_pMemory;
    m_nAllocationCount = p_m_Work->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_Work, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++p_m_Work[1].m_pMemory;
    v11 = p_m_Work->m_pMemory;
    v12 = (char *)p_m_Work[1].m_pMemory - (char *)m_pMemory - 1;
    p_m_Work[1].m_nAllocationCount = (int)p_m_Work->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 4 * v12);
    v13 = (CSentence **)&p_m_Work->m_pMemory[(_DWORD)m_pMemory];
    if ( v13 != nullptr )
      *v13 = v3;
    v19 += 264;
    if ( ++i >= c )
      return 1;
    v3 = nullptr;
  }
  _Warning(a1: "CSoundCombiner::CreateWorkList couldn't load %s for work item (%d)\n", fullpath, i);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A570
// Name: private: bool CSoundCombiner::InternalCombineSoundFiles(class IFileSystem __near *,char const __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::InternalCombineSoundFiles(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        const char *outfile,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  V_strncpy(pDest: this->m_szOutFile, pSrc: outfile, maxLen: 260);
  if ( info->m_Size > 0 )
  {
    if ( CSoundCombiner::VerifyFilesExist(this, filesystem, info) != 0
      && CSoundCombiner::CreateWorkList(this, filesystem, info) != 0 )
    {
      CSoundCombiner::PerformSplicingOnWorkItems(this, filesystem);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    _Warning(a1: "CSoundCombiner::InternalCombineSoundFiles:  work item count is zero\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A5F0
// Name: public: virtual bool CSoundCombiner::CombineSoundFiles(class IFileSystem __near *,char const __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSoundCombiner::CombineSoundFiles(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        const char *outfile,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  char v5; // bl

  v5 = CSoundCombiner::InternalCombineSoundFiles(this, filesystem, outfile, info);
  CSoundCombiner::CleanupWork(this);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041A620
// Name: public: virtual bool CSoundCombiner::IsCombinedFileChecksumValid(class IFileSystem __near *,char const __near *,class CUtlVector<struct CombinerEntry,class CUtlMemory<struct CombinerEntry,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSoundCombiner::IsCombinedFileChecksumValid(
        CSoundCombiner *this,
        IFileSystem *filesystem,
        const char *outfile,
        CUtlVector<CombinerEntry,CUtlMemory<CombinerEntry,int> > *info)
{
  unsigned int v5; // edi
  bool v6; // bl
  unsigned int v7; // eax
  char fullpath[260]; // [esp+Ch] [ebp-150h] BYREF
  CSentence sentence; // [esp+110h] [ebp-4Ch] BYREF

  if ( info->m_Size > 0 )
  {
    if ( CSoundCombiner::VerifyFilesExist(this, filesystem, info) != 0 )
    {
      if ( CSoundCombiner::CreateWorkList(this, filesystem, info) != 0 )
        v5 = CSoundCombiner::ComputeChecksum(this);
      else
        v5 = 0;
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    _Warning(a1: "CSoundCombiner::CheckSumWork:  work item count is zero\n");
    v5 = 0;
  }
  V_strncpy(pDest: fullpath, pSrc: outfile, maxLen: 260);
  filesystem->GetLocalPath(this: filesystem, a2: outfile, a3: fullpath, a4: 260);
  CSentence::CSentence(this: &sentence);
  v6 = false;
  if ( CSoundCombiner::LoadSentenceFromWavFileUsingIO(this, wavfile: fullpath, &sentence, io: &io_in_0) != 0 )
  {
    v7 = CSentence::GetDataCheckSum(this: &sentence);
    v6 = v5 == v7;
    if ( v5 != v7 )
      _Warning(a1: "  checksum computed %u, disk %u\n", v5, v7);
  }
  else
  {
    _Warning(a1: "CSoundCombiner::IsCombinedFileChecksumValid:  Unabled to load %s\n", fullpath);
  }
  CSoundCombiner::CleanupWork(this);
  CSentence::~CSentence(this: &sentence);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE60
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B630
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B7A0
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0041BE50
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAppSystemGroup::Module_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0041D910
// Name: public: void CUtlMemory<struct CExpressionSample,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CExpressionSample,int>::Grow(CUtlMemory<CExpressionSample,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CExpressionSample *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CExpressionSample *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CExpressionSample *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DA50
// Name: public: void CUtlMemory<class CEventAbsoluteTag,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEventAbsoluteTag,int>::Grow(CUtlMemory<CEventAbsoluteTag,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEventAbsoluteTag *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Realloc_2(
                                               this: _g_pMemAlloc,
                                               a2: m_pMemory,
                                               a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CEventAbsoluteTag *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E3C0
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E430
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int,struct CExpressionSample const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem,
        const CExpressionSample *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v7; // eax
  CExpressionSample *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041E660
// Name: public: int CUtlVector<class CEventRelativeTag,class CUtlMemory<class CEventRelativeTag,int>>::InsertBefore(int,class CEventRelativeTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::InsertBefore(
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *this,
        int elem,
        const CEventRelativeTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventRelativeTag *m_pMemory; // ecx
  int v7; // eax
  CEventRelativeTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlSymbol,int>::Node_t,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041E6F0
// Name: public: int CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::InsertBefore(int,class CFlexTimingTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::InsertBefore(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this,
        int elem,
        const CFlexTimingTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFlexTimingTag *m_pMemory; // ecx
  int v7; // eax
  CFlexTimingTag *v8; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEventAbsoluteTag,int>::Grow(
      (CUtlMemory<CEventAbsoluteTag,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    CUtlString::CUtlString(this: &v8->m_Name);
    CUtlString::operator=(this: &v8->m_Name, src: &src->m_Name);
    v8->m_flPercentage = src->m_flPercentage;
    v8->m_pOwner = src->m_pOwner;
    v8->m_bLocked = src->m_bLocked;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041E790
// Name: public: int CUtlVector<class CEventAbsoluteTag,class CUtlMemory<class CEventAbsoluteTag,int>>::InsertBefore(int,class CEventAbsoluteTag const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int>>::InsertBefore(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this,
        int elem,
        const CEventAbsoluteTag *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CEventAbsoluteTag *m_pMemory; // ecx
  int v7; // eax
  CEventAbsoluteTag *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEventAbsoluteTag,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CEventAbsoluteTag::CEventAbsoluteTag(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041EB10
// Name: public: void CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll(
        CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CEventAbsoluteTag *v3; // esi
  CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F000
// Name: public: CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>::~CUtlVector<class CFlexTimingTag,class CUtlMemory<class CFlexTimingTag,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::~CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>(
        CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int> > *this)
{
  bool v2; // sf
  CFlexTimingTag *m_pMemory; // eax

  CUtlVector<CFlexTimingTag,CUtlMemory<CFlexTimingTag,int>>::RemoveAll((CUtlVector<CEventAbsoluteTag,CUtlMemory<CEventAbsoluteTag,int> > *)this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FB30
// Name: public: int CUtlVector<struct CExpressionSample,class CUtlMemory<struct CExpressionSample,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int>>::InsertBefore(
        CUtlVector<CExpressionSample,CUtlMemory<CExpressionSample,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CExpressionSample *m_pMemory; // ecx
  int v6; // eax
  CExpressionSample *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CExpressionSample,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 10 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->value = 0.0;
    v7->time = 0.0;
    *((_WORD *)v7 + 4) = 0;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004224C0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CChoreoEvent __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CChoreoEvent *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 3;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427960
// Name: public: void CUtlMemory<class CChoreoActor __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CChoreoActor *,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace localization_check
