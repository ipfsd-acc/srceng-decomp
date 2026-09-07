// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/snd_wave_source.cpp
// Functions: 27
// ============================================================

#include "utils\scenemanager\snd_wave_source.h"

//------------------------------------------------------------------------------
// Address: 0x00403550
// Name: public: virtual int CAudioSourceWave::SampleRate(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::SampleRate(CAudioSourceWave *this)
{
  return this->m_rate;
}

//------------------------------------------------------------------------------
// Address: 0x00403560
// Name: public: virtual bool CAudioSourceWave::IsLooped(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAudioSourceWave::IsLooped(CAudioSourceWave *this)
{
  return this->m_loopStart >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403570
// Name: public: virtual float CAudioSourceWave::GetRunningLength(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CAudioSourceWave::GetRunningLength@<st0>(CAudioSourceWave *this@<ecx>, int a2@<esi>)
{
  if ( (double)this->m_rate <= 0.0 )
    return 0.0;
  else
    return (double)((int (__thiscall *)(CAudioSourceWave *, int))this->SampleCount)(a1: this, a2) / (double)this->m_rate;
}

//------------------------------------------------------------------------------
// Address: 0x004035B0
// Name: protected: void CAudioSourceWave::Init(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Init(CAudioSourceWave *this, char *pHeaderBuffer, unsigned int headerSize)
{
  int m_bits; // eax
  int v5; // ecx
  int v6; // eax
  char *v7; // eax

  this->m_format = *(unsigned __int16 *)pHeaderBuffer;
  this->m_bits = *((unsigned __int16 *)pHeaderBuffer + 7);
  m_bits = this->m_bits;
  this->m_rate = *((_DWORD *)pHeaderBuffer + 1);
  v5 = *((unsigned __int16 *)pHeaderBuffer + 1);
  v6 = v5 * m_bits / 8;
  this->m_channels = v5;
  this->m_sampleSize = v6;
  if ( v6 <= 0 )
    this->m_sampleSize = 1;
  if ( this->m_format != 1 )
  {
    v7 = (char *)operator new(nSize: headerSize);
    this->m_pHeader = v7;
    memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)pHeaderBuffer, count: headerSize);
    if ( this->m_format == 2 )
      this->m_sampleSize = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403630
// Name: public: virtual float CAudioSourceWave::TrueSampleSize(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAudioSourceWave::TrueSampleSize(CAudioSourceWave *this)
{
  if ( this->m_format == 2 )
    return 0.5;
  else
    return (double)this->m_sampleSize;
}

//------------------------------------------------------------------------------
// Address: 0x00403650
// Name: public: virtual int CAudioSourceWave::SampleCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceWave::SampleCount(CAudioSourceWave *this)
{
  char *m_pHeader; // ecx
  int v2; // edi
  int v3; // esi
  int v4; // edx
  int v5; // edi

  if ( this->m_format != 2 )
    return this->m_sampleCount;
  m_pHeader = this->m_pHeader;
  v2 = *((unsigned __int16 *)m_pHeader + 9);
  v3 = 7 * *((unsigned __int16 *)m_pHeader + 1) + *((unsigned __int16 *)m_pHeader + 1) * (v2 - 2) / 2;
  v4 = this->m_sampleCount % v3;
  v5 = this->m_sampleCount / v3 * v2;
  if ( v4 != 0 )
    v5 += 2 * (v4 - v3) / this->m_channels + *((unsigned __int16 *)m_pHeader + 9);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004036C0
// Name: public: void CAudioSourceWave::ConvertSamples(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ConvertSamples(CAudioSourceWave *this, char *pData, int sampleCount)
{
  int m_channels; // edx
  int i; // edi
  int j; // esi

  if ( this->m_format == 1 && this->m_bits == 8 && sampleCount > 0 )
  {
    m_channels = this->m_channels;
    for ( i = sampleCount; i != 0; --i )
    {
      for ( j = 0; j < m_channels; ++pData )
      {
        *pData += 0x80;
        m_channels = this->m_channels;
        ++j;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403700
// Name: public: virtual class CSentence __near * CAudioSourceWave::GetSentence(void)
// Source: json
//------------------------------------------------------------------------------
CSentence *__thiscall CAudioSourceWave::GetSentence(CAudioSourceWave *this)
{
  return &this->m_Sentence;
}

//------------------------------------------------------------------------------
// Address: 0x00403710
// Name: public: void CAudioSourceWave::Setup(char const __near *,int,class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::Setup(
        CAudioSourceWave *this,
        char *pFormatBuffer,
        unsigned int formatSize,
        IterateRIFF *walk)
{
  CAudioSourceWave_vtbl *v5; // edi
  unsigned int Count; // eax

  CAudioSourceWave::Init(this, pHeaderBuffer: pFormatBuffer, headerSize: formatSize);
  while ( IterateRIFF::ChunkAvailable(this: walk) )
  {
    v5 = this->__vftable;
    Count = CCurveData::GetCount(this: walk);
    v5->ParseChunk(this, a2: walk, a3: Count);
    IterateRIFF::ChunkNext(this: walk);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403760
// Name: public: CAudioSourceMemWave::CAudioSourceMemWave(void)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__thiscall CAudioSourceMemWave::CAudioSourceMemWave(CAudioSourceMemWave *this)
{
  CAudioSource::CAudioSource(this);
  this->__vftable = (CAudioSourceMemWave_vtbl *)&CAudioSourceWave::`vftable';
  CSentence::CSentence(this: &this->m_Sentence);
  this->m_format = 0;
  this->m_pHeader = nullptr;
  this->m_sampleCount = 0;
  this->m_pData = nullptr;
  this->m_loopStart = -1;
  this->m_sampleSize = 1;
  this->__vftable = (CAudioSourceMemWave_vtbl *)&CAudioSourceMemWave::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004037A0
// Name: public: virtual float CAudioSourceMemWave::GetRunningLength(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall CAudioSourceMemWave::GetRunningLength@<st0>(CAudioSourceMemWave *this@<ecx>, int a2@<esi>)
{
  if ( (double)this->m_rate <= 0.0 )
    return 0.0;
  else
    return (float)((float)((int (__thiscall *)(CAudioSourceMemWave *, int))this->SampleCount)(a1: this, a2)
                 / (float)this->m_rate);
}

//------------------------------------------------------------------------------
// Address: 0x00403800
// Name: public: void CAudioSourceMemWave::ParseDataChunk(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::ParseDataChunk(CAudioSourceMemWave *this, IterateRIFF *walk)
{
  signed int NumEvents; // edi
  char *v4; // eax
  int m_format; // eax
  int v6; // [esp-4h] [ebp-10h]

  NumEvents = CChoreoScene::GetNumEvents(this: walk);
  v4 = (char *)operator new(nSize: NumEvents);
  this->m_pData = v4;
  IterateRIFF::ChunkRead(this: walk, pOutput: v4);
  m_format = this->m_format;
  if ( m_format == 1 )
  {
    v6 = NumEvents / this->m_sampleSize;
    this->m_sampleCount = v6;
    CAudioSourceWave::ConvertSamples(this, pData: this->m_pData, sampleCount: v6);
  }
  else if ( m_format == 2 )
  {
    this->m_sampleSize = 1;
    this->m_sampleCount = NumEvents;
    this->m_bits = 16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403870
// Name: public: void __near * CAudioSourceWave::GetHeader(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAudioSourceWave::GetHeader(CAudioSourceWave *this)
{
  return this->m_pHeader;
}

//------------------------------------------------------------------------------
// Address: 0x00403880
// Name: public: virtual int CAudioSourceMemWave::GetOutputData(void __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAudioSourceMemWave::GetOutputData(
        CAudioSourceMemWave *this,
        void **pData,
        int samplePosition,
        int sampleCount,
        bool forward)
{
  int v5; // eax
  int m_loopStart; // ebx
  int m_sampleCount; // edx
  int v8; // edx
  int v9; // esi

  v5 = samplePosition;
  m_loopStart = this->m_loopStart;
  if ( m_loopStart >= 0 )
  {
    m_sampleCount = this->m_sampleCount;
    if ( samplePosition >= m_sampleCount )
    {
      v5 = samplePosition - m_loopStart;
      if ( m_sampleCount != m_loopStart )
        v5 = m_loopStart + v5 % (m_sampleCount - m_loopStart);
    }
  }
  v8 = this->m_sampleCount - v5;
  if ( forward )
  {
LABEL_8:
    if ( v8 >= 0 )
      goto LABEL_10;
    goto LABEL_9;
  }
  if ( v5 < this->m_sampleCount )
  {
    v8 = v5;
    goto LABEL_8;
  }
LABEL_9:
  v8 = 0;
LABEL_10:
  v9 = sampleCount;
  if ( sampleCount > v8 )
    v9 = v8;
  if ( v9 != 0 )
    *pData = &this->m_pData[v5 * this->m_sampleSize];
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x004038F0
// Name: class CAudioSource __near * CreateWave(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__cdecl CreateWave(const char *pName)
{
  int v2; // esi
  unsigned int v3; // edi
  unsigned int NumEvents; // eax
  CAudioSourceMemWave *v5; // eax
  CAudioSourceMemWave *v6; // esi
  char formatBuffer[1024]; // [esp+4h] [ebp-428h] BYREF
  IterateRIFF walk; // [esp+404h] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+41Ch] [ebp-10h] BYREF

  InFileRIFF::InFileRIFF(this: &riff, pFileName: pName, io: &io);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v2 = 0;
    v3 = 0;
    if ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      while ( v2 == 0 )
      {
        if ( CCurveData::GetCount(this: &walk) == 544501094 )
        {
          if ( CChoreoScene::GetNumEvents(this: &walk) <= 0x400 )
          {
            IterateRIFF::ChunkRead(this: &walk, pOutput: formatBuffer);
            NumEvents = CChoreoScene::GetNumEvents(this: &walk);
            v2 = *(unsigned __int16 *)formatBuffer;
            v3 = NumEvents;
          }
        }
        else
        {
          CCurveData::GetCount(this: &walk);
        }
        IterateRIFF::ChunkNext(this: &walk);
        if ( !IterateRIFF::ChunkAvailable(this: &walk) )
        {
          if ( v2 == 0 )
            goto LABEL_11;
          break;
        }
      }
      v5 = (CAudioSourceMemWave *)operator new(nSize: 0x74u);
      if ( v5 != nullptr )
        v6 = CAudioSourceMemWave::CAudioSourceMemWave(this: v5);
      else
        v6 = nullptr;
      CAudioSourceWave::Setup(this: v6, pFormatBuffer: formatBuffer, formatSize: v3, &walk);
      InFileRIFF::~InFileRIFF(this: &riff);
      return v6;
    }
    else
    {
LABEL_11:
      InFileRIFF::~InFileRIFF(this: &riff);
      return nullptr;
    }
  }
  else
  {
    printf(format: "Bad RIFF file type %s\n", pName);
    InFileRIFF::~InFileRIFF(this: &riff);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403A10
// Name: class CAudioSource __near * Audio_CreateMemoryWave(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAudioSourceMemWave *__cdecl Audio_CreateMemoryWave(const char *pName)
{
  return CreateWave(pName);
}

//------------------------------------------------------------------------------
// Address: 0x00403A20
// Name: public: virtual int StdIOReadBinary::open(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall StdIOReadBinary::open(StdIOReadBinary *this, const char *pFileName)
{
  return filesystem->Open(this: &filesystem->IBaseFileSystem, a2: pFileName, a3: "rb", a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00403A50
// Name: public: virtual int StdIOReadBinary::read(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall StdIOReadBinary::read(StdIOReadBinary *this, void *pOutput, int size, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)filesystem->Read(this: &filesystem->IBaseFileSystem, a2: pOutput, a3: size, a4: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: public: virtual void StdIOReadBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StdIOReadBinary::seek(StdIOReadBinary *this, void *file, int pos)
{
  if ( file != nullptr )
    filesystem->Seek(this: &filesystem->IBaseFileSystem, a2: file, a3: pos, a4: FILESYSTEM_SEEK_HEAD);
}

//------------------------------------------------------------------------------
// Address: 0x00403AB0
// Name: public: virtual unsigned int StdIOReadBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall StdIOReadBinary::tell(StdIOReadBinary *this, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)filesystem->Tell(this: &filesystem->IBaseFileSystem, a2: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403AE0
// Name: public: virtual unsigned int StdIOReadBinary::size(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall StdIOReadBinary::size(StdIOReadBinary *this, void *file)
{
  void *result; // eax

  result = file;
  if ( file != nullptr )
    return (void *)filesystem->Size_2(this: &filesystem->IBaseFileSystem, a2: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403B10
// Name: public: virtual void StdIOReadBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StdIOReadBinary::close(StdIOReadBinary *this, void *file)
{
  if ( file != nullptr )
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x00403B70
// Name: public: virtual void CAudioSourceWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseChunk(CAudioSourceWave *this, IterateRIFF *walk, int chunkName)
{
  _BYTE pOutput[20]; // [esp+4h] [ebp-18h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  if ( chunkName == 543520099 )
  {
    IterateRIFF::ChunkReadInt(this: walk);
    IterateRIFF::ChunkReadPartial(this: walk, pOutput, dataSize: 24);
    this->m_loopStart = v5;
  }
  else if ( chunkName == 1413563478 )
  {
    this->ParseSentence(this, a2: walk);
  }
  else
  {
    CCurveData::GetCount(this: walk);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403BD0
// Name: public: virtual int CWaveDataMemory::ReadSourceData(void __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWaveDataMemory::ReadSourceData(
        CWaveDataMemory *this,
        void **pData,
        int sampleIndex,
        int sampleCount,
        BOOL forward)
{
  return this->m_source->GetOutputData(this: this->m_source, a2: pData, a3: sampleIndex, a4: sampleCount, a5: forward);
}

//------------------------------------------------------------------------------
// Address: 0x00403C60
// Name: public: virtual class CAudioMixer __near * CAudioSourceMemWave::CreateMixer(void)
// Source: json
//------------------------------------------------------------------------------
CAudioMixerWave8Mono *__thiscall CAudioSourceMemWave::CreateMixer(CAudioSourceMemWave *this)
{
  CWaveData *v2; // eax

  v2 = (CWaveData *)operator new(nSize: 8u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CWaveData_vtbl *)&CWaveDataMemory::`vftable';
    v2[1].__vftable = (CWaveData_vtbl *)this;
  }
  else
  {
    v2 = nullptr;
  }
  return CreateWaveMixer(data: v2, format: this->m_format, channels: this->m_channels, bits: this->m_bits);
}

//------------------------------------------------------------------------------
// Address: 0x00403CA0
// Name: public: virtual void CAudioSourceMemWave::ParseChunk(class IterateRIFF __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceMemWave::ParseChunk(CAudioSourceMemWave *this, IterateRIFF *walk, int chunkName)
{
  if ( chunkName == 1635017060 )
    CAudioSourceMemWave::ParseDataChunk(this, walk);
  else
    CAudioSourceWave::ParseChunk(this, walk, chunkName);
}

//------------------------------------------------------------------------------
// Address: 0x00403CD0
// Name: public: virtual void CAudioSourceWave::ParseSentence(class IterateRIFF __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAudioSourceWave::ParseSentence(CAudioSourceWave *this, IterateRIFF *walk)
{
  int NumEvents; // eax
  int v4; // eax
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  NumEvents = CChoreoScene::GetNumEvents(this: walk);
  CUtlBuffer::EnsureCapacity(this: &buf, num: NumEvents);
  IterateRIFF::ChunkRead(this: walk, pOutput: buf.m_Memory.m_pMemory);
  v4 = CChoreoScene::GetNumEvents(this: walk);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v4);
  CSentence::InitFromDataChunk(this: &this->m_Sentence, data: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}
